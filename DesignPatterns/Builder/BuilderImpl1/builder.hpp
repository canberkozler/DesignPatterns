#ifndef BUILDER_HPP_
#define BUILDER_HPP_

class IBuilder {
public:
	virtual ~IBuilder() = default;
	virtual void BuildPartA() = 0;
	virtual void BuildPartB() = 0;
	virtual void BuildPartC() = 0;
};

#endif