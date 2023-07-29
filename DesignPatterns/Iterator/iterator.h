#pragma once
#include <vector>
#include <iterator>
#include <iostream>

template <typename T, typename U = std::vector<T>>
class Iterator {
public:
	using container_type = U;
	using value_type = T;
	using it_type = typename std::vector<T>::iterator;

	Iterator(U* container) : _data_ref(container) {
		_it = _data_ref->_data.begin();
	}

	void first() {
		_it = _data_ref->_data.begin();
	}

	void last() {
		if (_data_ref->empty()) {
			std::cout << "Invalid Size.\n";
			return;
		}
		_it = std::prev(_data_ref->_data.end());
	}

	Iterator& operator++(){
		++_it;
		return *this;
	}
	
	Iterator operator++(int){
		auto temp_it = this;
		++_it;
		return *temp_it;
	}

	void next() {
		++_it;
	}

	bool is_end () const {
		return (_it == _data_ref->_data.end());
	}

	bool is_last_elem() const {
		return (_it == std::prev(_data_ref->_data.end()));
	}

	it_type current() {
		return _it;
	}

	const T& operator*() const {
		return *_it;
	}

	T& operator*(){
		return *_it;
	}

	const T* operator->() const {
		return &(*_it);
	}

	T* operator->(){
		return &(*_it);
	}

	bool operator==(const Iterator& other) const {
		return _it == other._it;
	}

	bool operator!=(const Iterator& other) const {
		return !(*this == other);
	}

private:
	U* _data_ref;
	it_type _it;
};

template <typename T>
class Container {
	friend class Iterator<T, Container>;

public:
	void add(T new_data) {
		_data.push_back(new_data);
	}

	Iterator<T, Container>* CreateIterator() {
		return new Iterator<T, Container>(this);
	}

private:
	std::vector<T> _data;
};
