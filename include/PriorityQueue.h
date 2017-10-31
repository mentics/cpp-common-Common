#pragma once

// Adapted from https://stackoverflow.com/questions/22047964/how-to-move-elements-out-of-stl-priority-queue
template <typename Type, typename Compare = std::less<Type>>
class PriorityQueue {
private:
	std::vector<Type> elements;
	Compare compare;
public:
	explicit PriorityQueue(const Compare& compare = Compare()) : compare{ compare } {}

	bool empty() {
		return elements.empty();
	}

	void push(Type element) {
		elements.push_back(std::move(element));
		std::push_heap(elements.begin(), elements.end(), compare);
	}

	const Type& top() {
		return elements.front();
	}

	Type pop() {
		std::pop_heap(elements.begin(), elements.end(), compare);
		Type result = std::move(elements.back());
		elements.pop_back();
		return std::move(result);
	}
};