#pragma once

template <typename T>
void	iter(T * address, int length, void (*f)(void *)){
	if (!address || !f || length <= 0)
		return;
	for (int i = 0; i < length; i++){
		f(address + i);
	}
}

//what parameteres should be passed to f? void * or T *?