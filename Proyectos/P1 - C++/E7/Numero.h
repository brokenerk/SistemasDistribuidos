#ifndef NUMERO_H_
#define NUMERO_H_

class Numero {
	private:
		int num;
		bool primo;
	public:
		Numero(int = 0, bool = true);
		int getNum();
		bool getPrimo();
		void setPrimo(bool primo);
};
#endif