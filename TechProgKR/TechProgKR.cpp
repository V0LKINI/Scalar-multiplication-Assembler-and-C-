#include <iostream>

long DotProduct(short a[], short b[], unsigned long n)
{
	_asm {
		push edi
		push esi
		mov edi, a
		mov esi, b
		mov ecx, n
		mov ebx, 0
		f_loop:
		lodsw
			imul word ptr[edi]
			shl edx, 16
			mov dx, ax
			add edi, 2
			add ebx, edx
			jo overflow
			loop f_loop
			mov eax, ebx
			loop the_end
			overflow :
		mov eax, 0
			the_end :
			pop esi
			pop edi
	}
}

int main() {
	unsigned long n = 3;
	short int a[3] = { 5, 100, -10 };
	short int b[3] = { 1, 2, 3 };
	std::cout << DotProduct(a, b, n) << ' ' << std::endl;
}