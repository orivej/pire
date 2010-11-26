/*
 * align.h -- functions for positioning streams and memory pointers
 *            to word boundaries
 *
 * Copyright (c) 2007-2010, Dmitry Prokoptsev <dprokoptsev@gmail.com>,
 *                          Alexander Gololobov <agololobov@gmail.com>
 *
 * This file is part of Pire, the Perl Incompatible
 * Regular Expressions library.
 *
 * Pire is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Pire is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser Public License for more details.
 * You should have received a copy of the GNU Lesser Public License
 * along with Pire.  If not, see <http://www.gnu.org/licenses>.
 */


#ifndef PIRE_ALIGN_H
#define PIRE_ALIGN_H

#include "stub/stl.h"
#include "stub/saveload.h"
#include "sse.h"

namespace Pire {
	
	namespace Impl {

		template<class T>
		inline T AlignUp(T t, size_t bound)
		{
			return (T) (((size_t) t + (bound-1)) & ~(bound-1));
		}

		template<class T>
		inline T AlignDown(T t, size_t bound)
		{
			return (T) ((size_t) t & ~(bound-1));
		}
		
		inline void AlignSave(yostream* s, size_t size)
		{
			size_t tail = AlignUp(size, sizeof(MaxSizeWord)) - size;
			if (tail) {
				static const char buf[sizeof(MaxSizeWord)] = {0};
				SaveArray(s, buf, tail);
			}
		}

		inline void AlignLoad(yistream* s, size_t size)
		{
			size_t tail = AlignUp(size, sizeof(MaxSizeWord)) - size;
			if (tail) {
				char buf[sizeof(MaxSizeWord)];
				LoadArray(s, buf, tail);
			}
		}
		
		template<class T>
		inline void AlignedSaveArray(yostream* s, const T* array, size_t count)
		{
			SaveArray(s, array, count);
			AlignSave(s, sizeof(*array) * count);
		}

		template<class T>
		inline void AlignedLoadArray(yistream* s, T* array, size_t count)
		{
			LoadArray(s, array, count);
			AlignLoad(s, sizeof(*array) * count);
		}

		template<class T>
		inline bool IsAligned(T t, size_t bound)
		{
			return ((size_t) t & (bound-1)) == 0;
		}
		
		inline const void* AlignPtr(const size_t*& p, size_t& size)
		{
			if (!IsAligned(p, sizeof(MaxSizeWord))) {
				const size_t* next = AlignUp(p, sizeof(MaxSizeWord));
				if (next > p+size)
					throw Error("EOF reached in NPire::Impl::align");
				size -= (next - p);
				p = next;
			}
			return (const void*) p;
		}

	}
	
}

#endif
