/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * - Neither the name of prim nor the names of its contributors may be used to
 * endorse or promote products derived from this software without specific prior
 * written permission.
 *
 * See the NOTICE file distributed with this work for additional information
 * regarding copyright ownership.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include <gtest/gtest.h>

#include <random>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "colhash/tuplehash.h"

typedef std::uint64_t u64;

TEST(TupleHash, useInUnorderedSet) {
  std::unordered_set<std::tuple<int, double, char> > elements;
  elements.insert(std::make_tuple(89, 90.1, 'c'));
  ASSERT_EQ(elements.count(std::make_tuple(89, 90.1, 'c')), 1u);
}

TEST(TupleHash, useInUnorderedMap) {
  std::unordered_map<std::tuple<int, double, char>, int > elements;
  elements.insert(std::make_pair(std::make_tuple(89, 90.1, 'c'), 123));
  ASSERT_EQ(elements.count(std::make_tuple(89, 90.1, 'c')), 1u);
}

TEST(TupleHash, distribution) {
  std::mt19937_64 prng;
  std::uniform_int_distribution<u64> dist;
  std::hash<std::tuple<u64, u64, u64> > hasher;

  for (u64 t = 0; t < 100; t++) {
    // setup
    u64 r = dist(prng) % 100;
    std::vector<u64> counts(4, 0);

    // hashing and counting
    for (u64 a = 0; a < 1000000; a++) {
      u64 s = dist(prng) % 256;
      u64 d = dist(prng) % 256;
      size_t h = hasher(std::make_tuple(s, d, r)) % 4;
      counts.at(h)++;
    }

    // checking
    double average = 0.0;
    for (u64 c : counts) {
      average += c;
    }
    average /= counts.size();
    for (u64 c : counts) {
      double abs_ratio = std::abs(static_cast<double>(c) / average - 1.0);
      // printf("%lu: %f\n", t, abs_ratio); fflush(stdout);
      ASSERT_LE(abs_ratio, 0.01);
    }
  }
}

TEST(TupleHash, reproducable) {
  std::mt19937_64 prng;
  std::uniform_int_distribution<u64> dist;
  std::hash<std::tuple<u64, u64, u64> > hasher;

  std::unordered_map<std::tuple<u64, u64, u64>, size_t> cache;
  for (u64 z = 0; z < 10000000; z++) {
    u64 a = dist(prng) % 32;
    u64 b = dist(prng) % 32;
    u64 c = dist(prng) % 32;
    auto t = std::make_tuple(a, b, c);
    size_t h = hasher(t);
    if (cache.find(t) == cache.end()) {
      cache[t] = h;
    } else {
      ASSERT_EQ(cache.at(t), h);
    }
  }
  ASSERT_EQ(cache.size(), 32768);
}
