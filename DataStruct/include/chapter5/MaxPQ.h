#pragma once

namespace Chapter5
{
	template <class T>
	class MaxPQ 
	{
	public:
		virtual ~MaxPQ() {}
		virtual bool IsEmpty() const = false;
		virtual const T& Top() const = 0;
		virtual void Push(const T&) = 0;
		virtual void Pop() = 0;
	};
}