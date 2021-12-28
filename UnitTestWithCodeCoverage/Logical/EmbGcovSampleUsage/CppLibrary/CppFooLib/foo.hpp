#pragma once

class Foo{
	public:
	int x;
	Foo(int x);
	int getX();
	

	enum CodePath
	{
		Path1 ,
		Path2 ,
		Path3 ,
	};

	int doSomething(CodePath path)
	{
		switch(path)
		{
			case Path1:
				return 1;
			case Path2:
				return 2;
			case Path3:
				return 3;
			default:
				return 0;
		}

		return -1;
	}

};