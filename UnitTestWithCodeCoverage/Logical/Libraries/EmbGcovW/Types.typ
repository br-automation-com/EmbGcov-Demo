
TYPE
	EmbGcovWriteTyp : 	STRUCT  (*Structure for the information passed by Gcov to save all. *)
		pFileName : UDINT;
		fileNameSize : UDINT;
		pRemovePath : UDINT;
		removePathSize : UDINT;
		pData : UDINT;
		dataSize : UDINT;
		totalBufferSize : UDINT;
	END_STRUCT;
END_TYPE
