#include <iostream>
#include <grand_child.h>
#include <vector>

struct Data
{
};

int main()
{
	const auto data = Data{};
	auto& os = std::cout;
	const auto serializer = kiste::raw{os};
	auto sample = test::GrandChild(data, os, serializer);

	sample.render();
}