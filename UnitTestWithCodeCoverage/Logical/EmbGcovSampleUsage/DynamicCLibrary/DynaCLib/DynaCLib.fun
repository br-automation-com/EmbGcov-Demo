
{REDUND_ERROR} {REDUND_UNREPLICABLE} FUNCTION_BLOCK DynamicCLibFooFub (*Dynamic C Library Foo Function block*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		Enable : {REDUND_UNREPLICABLE} BOOL;
		DoSomething : {REDUND_UNREPLICABLE} BOOL;
	END_VAR
	VAR_OUTPUT
		Out : {REDUND_UNREPLICABLE} BOOL;
	END_VAR
	VAR
		InternalState : {REDUND_UNREPLICABLE} DINT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION DynamicCLibGcovSaveEmb : BOOL (*Sample function to store the data when using a real target*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
END_FUNCTION

{REDUND_ERROR} FUNCTION DynamicCLibGcovSave : BOOL (*Sample function to store the data when using an ARSIM target*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
END_FUNCTION
