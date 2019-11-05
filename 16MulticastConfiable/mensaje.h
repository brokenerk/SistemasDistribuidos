#define TAM_MAX_DATA 65000
// Definicion del formato de mensaje
struct mensaje{
	int idMessage;
	char arguments[TAM_MAX_DATA];
};