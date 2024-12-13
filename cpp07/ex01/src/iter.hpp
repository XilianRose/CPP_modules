#pragma once

template <typename T>
void	iter(T * address, size_t length, void (*f)(T &)){
	if (!address || !f || length <= 0)
		return;
	for (size_t i = 0; i < length; i++){
		f(address[i]);
	}
}
