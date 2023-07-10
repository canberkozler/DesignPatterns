#include "subject.h"

int main() {
	auto channel = std::make_unique<Subject>();
	auto subscriber = std::make_unique<Subscriber>();

	channel->add(std::move(subscriber));
	channel->AdvanceAndUpdateAll();
	channel->AdvanceAndUpdateAll();
	channel->AdvanceAndUpdateAll();
	channel->AdvanceAndUpdateAll();
	channel->AdvanceAndUpdateAll();

	auto subscriber2 = std::make_unique<Subscriber>();
	channel->add(std::move(subscriber2));

	channel->AdvanceAndUpdateAll();
	channel->AdvanceAndUpdateAll();
	channel->AdvanceAndUpdateAll();
	channel->AdvanceAndUpdateAll();
	channel->AdvanceAndUpdateAll();
}