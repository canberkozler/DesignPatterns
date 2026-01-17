#pragma once
#include <memory>
#include <string>


class Car {
public:
	Car(const std::string& color, double length, double width, int doors, bool sunroof)
		: m_color(color), m_length(length), m_width(width), m_doors(doors), m_sunroof(sunroof) {
	}
	class Builder {
	public:
		using CarPtr = std::unique_ptr<Car>;

		CarPtr build() {
			return std::make_unique<Car>(m_color, m_length, m_width, m_doors, m_sunroof);
		}
		Builder& color(const std::string& color) {
			m_color = color;
			return *this;
		}
		Builder& size(double length, double width) {
			m_length = length;
			m_width = width;
			return *this;
		}
		Builder& doors(int doors) {
			m_doors = doors;
			return *this;
		}
		Builder& sunroof(bool has_sunroof) {
			m_sunroof = has_sunroof;
			return *this;
		}
	private:
		std::string m_color{"grey"};
		double m_length;
		double m_width;
		int m_doors{ 4 };
		bool m_sunroof{ false };
	};

private:
	std::string m_color;
	double m_length;
	double m_width;
	int m_doors;
	bool m_sunroof;
};