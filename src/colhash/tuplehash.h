/*
 * Copyright (c) 2012-2016, Nic McDonald
 * All rights reserved.
 *
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
#ifndef COLHASH_TUPLEHASH_H_
#define COLHASH_TUPLEHASH_H_

#include <tuple>

namespace std {

template <typename A, typename B>
struct hash<std::tuple<A, B> > {
  size_t operator()(const std::tuple<A, B>& t) const {
    std::hash<A> ah;
    std::hash<B> bh;
    size_t a = ah(std::get<0>(t));
    size_t b = bh(std::get<1>(t));
    size_t z = 0xdeadbeef;
    z ^= a + 0x9e3779b9 + (z << 6) + (z >> 2);
    z ^= b + 0x9e3779b9 + (z << 6) + (z >> 2);
    return z;
  }
};

template <typename A, typename B, typename C>
struct hash<std::tuple<A, B, C> > {
  size_t operator()(const std::tuple<A, B, C>& t) const {
    std::hash<A> ah;
    std::hash<B> bh;
    std::hash<C> ch;
    size_t a = ah(std::get<0>(t));
    size_t b = bh(std::get<1>(t));
    size_t c = ch(std::get<2>(t));
    size_t z = 0xdeadbeef;
    z ^= a + 0x9e3779b9 + (z << 6) + (z >> 2);
    z ^= b + 0x9e3779b9 + (z << 6) + (z >> 2);
    z ^= c + 0x9e3779b9 + (z << 6) + (z >> 2);
    return z;
  }
};

template <typename A, typename B, typename C, typename D>
struct hash<std::tuple<A, B, C, D> > {
  size_t operator()(const std::tuple<A, B, C, D>& t) const {
    std::hash<A> ah;
    std::hash<B> bh;
    std::hash<C> ch;
    std::hash<D> dh;
    size_t a = ah(std::get<0>(t));
    size_t b = bh(std::get<1>(t));
    size_t c = ch(std::get<2>(t));
    size_t d = dh(std::get<3>(t));
    size_t z = 0xdeadbeef;
    z ^= a + 0x9e3779b9 + (z << 6) + (z >> 2);
    z ^= b + 0x9e3779b9 + (z << 6) + (z >> 2);
    z ^= c + 0x9e3779b9 + (z << 6) + (z >> 2);
    z ^= d + 0x9e3779b9 + (z << 6) + (z >> 2);
    return z;
  }
};

template <typename A, typename B, typename C, typename D, typename E>
struct hash<std::tuple<A, B, C, D, E> > {
  size_t operator()(const std::tuple<A, B, C, D, E>& t) const {
    std::hash<A> ah;
    std::hash<B> bh;
    std::hash<C> ch;
    std::hash<D> dh;
    std::hash<E> eh;
    size_t a = ah(std::get<0>(t));
    size_t b = bh(std::get<1>(t));
    size_t c = ch(std::get<2>(t));
    size_t d = dh(std::get<3>(t));
    size_t e = eh(std::get<4>(t));
    size_t z = 0xdeadbeef;
    z ^= a + 0x9e3779b9 + (z << 6) + (z >> 2);
    z ^= b + 0x9e3779b9 + (z << 6) + (z >> 2);
    z ^= c + 0x9e3779b9 + (z << 6) + (z >> 2);
    z ^= d + 0x9e3779b9 + (z << 6) + (z >> 2);
    z ^= e + 0x9e3779b9 + (z << 6) + (z >> 2);
    return z;
  }
};

template <typename A, typename B, typename C, typename D, typename E,
          typename F>
struct hash<std::tuple<A, B, C, D, E, F> > {
  size_t operator()(const std::tuple<A, B, C, D, E, F>& t) const {
    std::hash<A> ah;
    std::hash<B> bh;
    std::hash<C> ch;
    std::hash<D> dh;
    std::hash<E> eh;
    std::hash<F> fh;
    size_t a = ah(std::get<0>(t));
    size_t b = bh(std::get<1>(t));
    size_t c = ch(std::get<2>(t));
    size_t d = dh(std::get<3>(t));
    size_t e = eh(std::get<4>(t));
    size_t f = fh(std::get<5>(t));
    size_t z = 0xdeadbeef;
    z ^= a + 0x9e3779b9 + (z << 6) + (z >> 2);
    z ^= b + 0x9e3779b9 + (z << 6) + (z >> 2);
    z ^= c + 0x9e3779b9 + (z << 6) + (z >> 2);
    z ^= d + 0x9e3779b9 + (z << 6) + (z >> 2);
    z ^= e + 0x9e3779b9 + (z << 6) + (z >> 2);
    z ^= f + 0x9e3779b9 + (z << 6) + (z >> 2);
    return z;
  }
};

template <typename A, typename B, typename C, typename D, typename E,
          typename F, typename G>
struct hash<std::tuple<A, B, C, D, E, F, G> > {
  size_t operator()(const std::tuple<A, B, C, D, E, F, G>& t) const {
    std::hash<A> ah;
    std::hash<B> bh;
    std::hash<C> ch;
    std::hash<D> dh;
    std::hash<E> eh;
    std::hash<F> fh;
    std::hash<G> gh;
    size_t a = ah(std::get<0>(t));
    size_t b = bh(std::get<1>(t));
    size_t c = ch(std::get<2>(t));
    size_t d = dh(std::get<3>(t));
    size_t e = eh(std::get<4>(t));
    size_t f = fh(std::get<5>(t));
    size_t g = gh(std::get<6>(t));
    size_t z = 0xdeadbeef;
    z ^= a + 0x9e3779b9 + (z << 6) + (z >> 2);
    z ^= b + 0x9e3779b9 + (z << 6) + (z >> 2);
    z ^= c + 0x9e3779b9 + (z << 6) + (z >> 2);
    z ^= d + 0x9e3779b9 + (z << 6) + (z >> 2);
    z ^= e + 0x9e3779b9 + (z << 6) + (z >> 2);
    z ^= f + 0x9e3779b9 + (z << 6) + (z >> 2);
    z ^= g + 0x9e3779b9 + (z << 6) + (z >> 2);
    return z;
  }
};

}  // namespace std

#endif  // COLHASH_TUPLEHASH_H_
