#ifndef __MEMORYPOOL__H
#define __MEMORYPOOL__H

#include <list>
#include <array>


template<typename T>
class Object
{
	public:
		Object()
			: isUsing_(false)
		{}
		~Object(){}
	public:
		bool isUsing();
		void setIsUsing(bool value)
		{ isUsing_ = value;}
		const T& object()const
		{ 
			return object_; 
		}
	private:
		T object_;
		bool isUsing_;
};

template<typename T, std::size_t N = 512>
class MemoryPool
{
	public:
		MemoryPool()
		{
			Chunk chunk;
			l_.push_back(chunk);
		}	

		~MemoryPool() {}
	private:
			typedef std::array<Object<T>, N> Chunk;
			std::list<Chunk> l_;
	private:
			T* find(const Chunk& chunk)
			{
				for(auto o : chunk)
					if (!o.isUsing())
					{
						o.setIsUsing(true);
						return &o.object();
					}
				return NULL;
			}
	public:
			T* construct()
			{
				for(auto chunk : l_)
				{
					auto p = find(chunk);
					if (p)
						return p;
				}
				Chunk chunk;
				auto p = &chunk[0].object();
				chunk[0].setIsUsing(true);
				l_.push_back(Chunk());
				return p;
			}
			void destruct(T* value)
			{
				for(auto chunk : l_)
					for(auto o : chunk)
						if (o.object() == *value)
							o.setIsUsing(false);
			}
};
#endif//__MEMORYPOOL__H
