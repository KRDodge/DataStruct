#pragma once

namespace Chapter9
{
	template <class T>
	class DEPQ 
	{
	public:
		virtual const T& GetMin() const = 0;
		virtual const T& GetMax() const = 0;
		virtual void Insert(const T&) const = 0;
		virtual void DeleteMin() const = 0;
		virtual void DeleteMax() const = 0;
	};
}
