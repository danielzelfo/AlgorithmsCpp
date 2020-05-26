#pragma once
//A Lower Comparator
template <typename E>
class Lower {
public:
	bool operator()(const E p, const E q) const
	{
		return p < q;
	}
};

//A Higher Comparator
template <typename E>
class Higher {
public:
	bool operator()(const E p, const E q) const
	{
		return p > q;
	}
};