#ifndef DIRECTOR_HPP_
#define DIRECTOR_HPP_

class IBuilder;

class Director {
public:
	Director(IBuilder* pbuilder);
	void construct();

private:
	IBuilder* p_builder;
};

#endif