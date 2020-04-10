#include <iostream>
using namespace std;
/*
template<class _Tx>
	struct _Get_function_impl;
*/  
#define _GET_FUNCTION_IMPL(CALL_OPT, X1, X2, X3) \
template<class _Ret, \
	class... _Types> \
	struct _Get_function_impl<_Ret CALL_OPT (_Types...)> \
	{	/* determine type from argument list */ \
	typedef _Func_class<_Ret, _Types...> type; \
	};


int main() {
}


