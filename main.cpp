#include <iostream>

std::string makeFlag(std::string s)
{
	std::string _b;
	std::string a;
	std::string _b2;
	a   = s.at(5);
	_b2 = s.at(2);

	for(int s_ = 0; s_ < s.length(); s_++) {
		std::string b = _b2.substr(_b2.length() - s_) + _b2.substr(s_);
		if (s_ >= 3) {
			_b = _b2 + s.at(s_ - 3);
		} else {
			_b = _b2 + s.at(s.length() - (3 - s_));
		}
		if (s_ >= _b.length()) {
			_b2 = _b + s.at(s_ - _b.length());
		} else if (s.length() >= _b.length() - s_) {
			_b2 = _b + s.at(s.length() - (_b.length() - s_));
		} else {
			_b2 = _b + s.at(s.length() - ((_b.length() - s_) - s.length()));
		}
		a = a + b.at((((s.length() + _b2.length()) * s_) + _b2.length()) % b.length());
	}
	return a.substr(0, 2) + s.at(3) + a.at(3) + "0" + a.substr(5, 7);
}

auto main() -> int
{
	std::string seed{"1dndr@"};

	std::cout << makeFlag(seed);

	return 0;
}