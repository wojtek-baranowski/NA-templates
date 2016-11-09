#pragma once

#include <cstddef>
#include <utility>

template<typename T>
class container_wrapper
{
	private:
		T _value;	

	public: 

		container_wrapper() = default;
		container_wrapper (T arg): _value(std::move(arg))
	{

	} 
		container_wrapper(const container_wrapper &) = default;
		container_wrapper(container_wrapper &&) = default;
		container_wrapper & operator=(const container_wrapper &) = default;
		container_wrapper & operator=(container_wrapper &&) = default;

		std::size_t size() const
	{
			return _value.size();
	}

};

