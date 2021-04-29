# include <iostream>;
# include <iostream>;
# include <fstream>;
# include <iomanip>;
using namespace std;
struct PROG {
	PROG* prev = NULL;
	string name;
	int lines;
	float time_call;
	float time_indy;
	PROG* next = NULL;
};
struct List {
private:
	PROG* start = NULL;
	PROG* end = NULL;
public:
	int GetSize() {
		int count = 0;
		while (start != NULL) {
			count++;
			start = start->next;
		}
		return count;
	}
	void CreatList() {
	p:
		system("cls");
		int count = 0;
		cout << "Введите количество элементов: ";
		cin >> count;
		if (count < 1) {
			cout << "Количество єлементов должно быть больше 0!" << endl;
			goto p;
		}
		start = new PROG();
		end = start;
		for (int i = 0; i < count; i++) {
			cout << endl << "Введите название программы : ";
			cin >> end->name;
			cout << endl << "Количество строк кода: ";
			cin >> end->lines;
			cout << endl << "Время использования на SGI Callenge(сек): ";
			cin >> end->time_call;
			cout << endl << "Время использования на SGL Indy(сек): ";
			cin >> end->time_indy;
			if (i != count - 1) {
				end->next = new PROG();
				end->next->prev = end;
				end = end->next;
			}
		}

		system("cls");
		cout << "Данные успешно введены! " << endl;
		system("pause");
	}
	void PrintStart() {
		PROG* cur = start;
		system("cls");
		cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "| Время виполнения некоторых программ, которые применяют параллельные алгоритмы                                       |" << endl;
		cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "|  №   | Название программы | Количество строк кода | Время исп. на SGI callenge (сек) | Время исп. на SGI Indy (сек) |" << endl;
		cout << "|------|--------------------|-----------------------|----------------------------------|------------------------------|" << endl;
		int i = 0;
		while (cur != NULL) {

			cout << "| " << setw(3) << i++ << ". |" << setw(10) << cur->name << setw(11) << "|" << setw(11) << cur->lines << setw(13) << "|" << setw(18) << cur->time_call << setw(17) << "|" << setw(15) << cur->time_indy << setw(16) << "|" << endl;
			cur = cur->next;
		}
		cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "| Примечание: SGI Callenge-ЦП R1000 196 MHz, 1/024 MB RAM SGI Indy-ЦП MIPS R4600 134 MHz, 64 MB RAM                   |" << endl;
		cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
		system("pause");
	}
	void PrintEnd() {
		PROG* cur = end;
		system("cls");
		cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "| Время виполнения некоторых программ, которые применяют параллельные алгоритмы                                       |" << endl;
		cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "|  №   | Название программы | Количество строк кода | Время исп. на SGI callenge (сек) | Время исп. на SGI Indy (сек) |" << endl;
		cout << "|------|--------------------|-----------------------|----------------------------------|------------------------------|" << endl;
		int i = 0;
		while (cur != NULL) {

			cout << "| " << setw(3) << i++ << ". |" << setw(10) << cur->name << setw(11) << "|" << setw(11) << cur->lines << setw(13) << "|" << setw(18) << cur->time_call << setw(17) << "|" << setw(15) << cur->time_indy << setw(16) << "|" << endl;
			cur = cur->prev;
		}
		cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
		cout << "| Примечание: SGI Callenge-ЦП R1000 196 MHz, 1/024 MB RAM SGI Indy-ЦП MIPS R4600 134 MHz, 64 MB RAM                   |" << endl;
		cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
		system("pause");
	}
	void SearchStart() {
		int count = GetSize();
		int n = 0;
	k:
		system("cls");
		cout << "Поиск:" << endl;
		cout << "1.По номеру." << endl;
		cout << "2.По названию." << endl;
		cout << "3.По \"Количеству строк\"" << endl;
		cout << "4.По \"Время исп. на SGI callenge (сек)\"" << endl;
		cout << "5.По \"Время исп. на SGI Indy (сек)\"" << endl;
		cout << "0.Выход." << endl;
		cout << "Ввод: ";
		cin >> n;
		cout << endl;
		int m = 0;
		int colv = 0;
		float time = 0;
		string outp;
		PROG** TEMP = new PROG * [count];
		int temp = 0;
		PROG* cur = start;
		switch (n) {
		case 1:
		g:
			system("cls");
			cout << "Введите номер  элемента который хотите найти: ";
			cin >> m;
			if (m < 0 || m >= count) {
				cout << "Некоректно введеный номер!";
				goto g;
			}
			cur = start;
			for (int i = 0; i < m; i++) {
				cur = cur->next;
			}
			system("cls");
			cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
			cout << "| Время виполнения некоторых программ, которые применяют параллельные алгоритмы                                       |" << endl;
			cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
			cout << "|  №   | Название программы | Количество строк кода | Время исп. на SGI callenge (сек) | Время исп. на SGI Indy (сек) |" << endl;
			cout << "|------|--------------------|-----------------------|----------------------------------|------------------------------|" << endl;
			cout << "| " << setw(3) << m << ". |" << setw(10) << cur->name << setw(11) << "|" << setw(11) << cur->lines << setw(13) << "|" << setw(18) << cur->time_call << setw(17) << "|" << setw(15) << cur->time_indy << setw(16) << "|" << endl;
			cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
			cout << "| Примечание: SGI Callenge-ЦП R1000 196 MHz, 1/024 MB RAM SGI Indy-ЦП MIPS R4600 134 MHz, 64 MB RAM                   |" << endl;
			cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
			system("pause");
			return;
			break;
		case 2:
			system("cls");
			cout << "Введите название программы: ";
			cin >> outp;
			cur = start;
			while (cur != NULL) {
				if (outp == cur->name)
					TEMP[temp++] = cur;
				cur = cur->next;
			}
			break;
		case 3:
			system("cls");
			cout << "Введите  \"Количествo строк\": ";
			cin >> colv;

			while (cur != NULL) {
				if (colv == cur->lines)
					TEMP[temp++] = cur;
				cur = cur->next;
			}
			break;
		case 4:
			system("cls");
			cout << "Введите  \"Время исп. на SGI callenge (сек)\": ";
			cin >> time;
			while (cur != NULL) {
				if (time == cur->time_call)
					TEMP[temp++] = cur;
				cur = cur->next;
			}
			break;
		case 5:
			system("cls");
			cout << "Введите  \"Время исп. на SGI Indy (сек)\": ";
			cin >> time;
			while (cur != NULL) {
				if (time == cur->time_indy)
					TEMP[temp++] = cur;
				cur = cur->next;
			}
			break;
		case 0:
			return;
		default:
			cout << "Неверное значение." << endl;
			break;
			goto g;
		}
		if (temp == 0)
			cout << "Элементов с заданым значением не найдено!" << endl;
		else {
			cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
			cout << "|  №   | Название программы | Количество строк кода | Время исп. на SGI callenge (сек) | Время исп. на SGI Indy (сек) |" << endl;
			cout << "|------|--------------------|-----------------------|----------------------------------|------------------------------|" << endl;

			for (int i = 0; i < temp; i++)
				cout << "| " << setw(3) << i << ". |" << setw(10) << cur->name << setw(11) << "|" << setw(11) << cur->lines << setw(13) << "|" << setw(18) << cur->time_call << setw(17) << "|" << setw(15) << cur->time_indy << setw(16) << "|" << endl;
			cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
		}
		system("pause");
		return;
	}
	void SearchEnd() {
		int count = GetSize();
		int n = 0;
	k:
		system("cls");
		cout << "Поиск:" << endl;
		cout << "1.По номеру." << endl;
		cout << "2.По названию." << endl;
		cout << "3.По \"Количеству строк\"" << endl;
		cout << "4.По \"Время исп. на SGI callenge (сек)\"" << endl;
		cout << "5.По \"Время исп. на SGI Indy (сек)\"" << endl;
		cout << "0.Выход." << endl;
		cout << "Ввод: ";
		cin >> n;
		cout << endl;
		int m = 0;
		int colv = 0;
		float time = 0;
		string outp;
		PROG** TEMP = new PROG * [count];
		int temp = 0;
		PROG* cur = end;
		switch (n) {
		case 1:
		g:
			system("cls");
			cout << "Введите номер  элемента который хотите найти: ";
			cin >> m;
			if (m < 0 || m >= count) {
				cout << "Некоректно введеный номер!";
				goto g;
			}
			cur = end;
			for (int i = 0; i < m; i++) {
				cur = cur->prev;
			}
			system("cls");
			cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
			cout << "| Время виполнения некоторых программ, которые применяют параллельные алгоритмы                                       |" << endl;
			cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
			cout << "|  №   | Название программы | Количество строк кода | Время исп. на SGI callenge (сек) | Время исп. на SGI Indy (сек) |" << endl;
			cout << "|------|--------------------|-----------------------|----------------------------------|------------------------------|" << endl;
			cout << "| " << setw(3) << m << ". |" << setw(10) << cur->name << setw(11) << "|" << setw(11) << cur->lines << setw(13) << "|" << setw(18) << cur->time_call << setw(17) << "|" << setw(15) << cur->time_indy << setw(16) << "|" << endl;
			cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
			cout << "| Примечание: SGI Callenge-ЦП R1000 196 MHz, 1/024 MB RAM SGI Indy-ЦП MIPS R4600 134 MHz, 64 MB RAM                   |" << endl;
			cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
			system("pause");
			return;
			break;
		case 2:
			system("cls");
			cout << "Введите название программы: ";
			cin >> outp;
			cur = end;
			while (cur != NULL) {
				if (outp == cur->name)
					TEMP[temp++] = cur;
				cur = cur->prev;
			}
			break;
		case 3:
			system("cls");
			cout << "Введите  \"Количествo строк\": ";
			cin >> colv;

			while (cur != NULL) {
				if (colv == cur->lines)
					TEMP[temp++] = cur;
				cur = cur->prev;
			}
			break;
		case 4:
			system("cls");
			cout << "Введите  \"Время исп. на SGI callenge (сек)\": ";
			cin >> time;
			while (cur != NULL) {
				if (time == cur->time_call)
					TEMP[temp++] = cur;
				cur = cur->prev;
			}
			break;
		case 5:
			system("cls");
			cout << "Введите  \"Время исп. на SGI Indy (сек)\": ";
			cin >> time;
			while (cur != NULL) {
				if (time == cur->time_indy)
					TEMP[temp++] = cur;
				cur = cur->prev;
			}
			break;
		case 0:
			return;
		default:
			cout << "Неверное значение." << endl;
			break;
			goto g;
		}
		if (temp == 0)
			cout << "Элементов с заданым значением не найдено!" << endl;
		else {
			cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
			cout << "|  №   | Название программы | Количество строк кода | Время исп. на SGI callenge (сек) | Время исп. на SGI Indy (сек) |" << endl;
			cout << "|------|--------------------|-----------------------|----------------------------------|------------------------------|" << endl;

			for (int i = 0; i < temp; i++)
				cout << "| " << setw(3) << i << ". |" << setw(10) << cur->name << setw(11) << "|" << setw(11) << cur->lines << setw(13) << "|" << setw(18) << cur->time_call << setw(17) << "|" << setw(15) << cur->time_indy << setw(16) << "|" << endl;
			cout << "|---------------------------------------------------------------------------------------------------------------------|" << endl;
		}
		system("pause");
		return;
	}
	void Adding() {
		PROG* cur = start;
		int count = GetSize();
		int n = 0;
	h:
		system("cls");
		cout << "Введите номер добавляемого элемента: ";
		cin >> n;
		cout << endl;
		if (n > (count) || n < 0) {
			system("cls");
			cout << "Неверно введен номер элемента!" << endl;
			system("pause");
			goto h;
		}
		for (int i = 0; i < n - 1; i++) {
			cur = cur->next;
		}
		PROG* temp = new PROG();
		cout << endl << "Введите название программы : ";
		cin >> temp->name;
		cout << endl << "Количество строк кода: ";
		cin >> temp->lines;
		cout << endl << "Время использования на SGI Callenge(сек): ";
		cin >> temp->time_call;
		cout << endl << "Время использования на SGL Indy(сек): ";
		cin >> temp->time_indy;
		if (n == count) {
			end->next = temp;
			end = temp;
		}
		else if (n == 0) {
			start->prev = temp;
			temp->next = start;
			start = temp;
		}
		else {
			PROG* cur = start;
			for (int i = 0; i < n - 1; i++) {
				cur = cur->next;
			}
			temp->prev = cur->prev;
			temp->next = cur->next;
			cur->next->prev = temp;
			cur->next = temp;

		}
		system("cls");
		cout << "Элемент успешно добавлен! " << endl;
		system("pause");
		return;
	}
	void Deleting() {
		PROG* cur = start;
		int count = GetSize();
		int n = 0;
	h:
		system("cls");
		cout << "Введите номер удаляемого элемента: ";
		cin >> n;
		cout << endl;
		if (n > (count - 1) || n < 0) {
			cout << "Неверно введен номер элемента!" << endl;
			goto h;
		}
		if (n == 0)
			start = start->next;
		else {
			for (int i = 0; i < n - 1; i++) {
				cur = cur->next;
			}
			cur->next = cur->next->next;
		}
		system("cls");
		cout << "Элемент успешно удален! " << endl;
		system("pause");
		return;
	}
	void PrintFile() {
		ofstream fout("Output.txt");
		PROG* cur = start;
		while (cur != NULL) {
			fout << "  " << cur->name << "  " << cur->lines << "  " << cur->time_call << "  " << cur->time_indy << "  " << endl;
			cur = cur->next;
		}
		system("cls");
		cout << "Данные успешно выведены в файл \"Output.txt\"." << endl;
		system("PAUSE");
	}
	void ReadFile() {
		start = new PROG();
		end = NULL;
		ifstream fin("MasStruct.txt");
		while (!fin.eof()) {
			if (end == NULL)
				end = start;
			else {
				end->next = new PROG();
				end->next->prev = end;
				end = end->next;
			}
			fin >> end->name;
			fin >> end->lines;
			fin >> end->time_call;
			fin >> end->time_indy;
		}
		system("cls");
		cout << "Данные успешно выведены из файла \"MasStruct.txt\"!" << endl;
		system("PAUSE");
	}
	void Sorting() {
		int n = 0;
	k:
		system("cls");
		cout << "Сортировка:" << endl;
		cout << "1.По названию." << endl;
		cout << "2.По \"Количеству строк\"" << endl;
		cout << "3.По \"Время исп. на SGI callenge (сек)\"" << endl;
		cout << "4.По \"Время исп. на SGI Indy (сек)\"" << endl;
		cout << "0.Выход." << endl;
		cin >> n;
		int p = 0;
		bool vse = false;
		PROG* cur;
		switch (n) {
		case 1:
			vse = true;
			while (vse) {
				vse = false;
				cur = start;
				if (strcmp(cur->name.c_str(), cur->next->name.c_str()) == 1) {
					PROG* temp = cur->next;
					cur->next = cur->next->next;
					temp->next->prev = cur;
					temp->prev = cur->prev;
					cur->prev = temp;
					temp->next = cur;
					start = temp;
					vse = true;
				}
				while (cur->next->next != NULL) {
					if (strcmp(cur->next->name.c_str(), cur->next->next->name.c_str()) == 1) {
						PROG* temp = cur->next->next;
						if (temp->next != NULL)
							temp->next->prev = temp->prev;
						cur->next->prev = temp;
						temp->prev = cur;
						cur->next->next = temp->next;
						temp->next = cur->next;
						cur->next = temp;
						vse = true;
					}
					cur = cur->next;
				}
				end = cur->next;
			}
			system("cls");
			cout << "Данные успешно отсортированы." << endl;
			system("PAUSE");
			break;
		case 2:
		p1:
			system("cls");
			cout << "1.Сортировать по возрастанию." << endl << "2.По убыванию." << endl << "0.Выход" << endl << "Ввод: ";
			cin >> p;
			switch (p) {
			case 1:
				vse = true;
				while (vse) {
					vse = false;
					cur = start;
					if (cur->lines > cur->next->lines) {
						PROG* temp = cur->next;
						cur->next = cur->next->next;
						temp->next->prev = cur;
						temp->prev = cur->prev;
						cur->prev = temp;
						temp->next = cur;
						start = temp;
						vse = true;
					}
					while (cur->next->next != NULL) {
						if (cur->next->lines > cur->next->next->lines) {
							PROG* temp = cur->next->next;
							if (temp->next != NULL)
								temp->next->prev = temp->prev;
							cur->next->prev = temp;
							temp->prev = cur;
							cur->next->next = temp->next;
							temp->next = cur->next;
							cur->next = temp;
							vse = true;
						}
						cur = cur->next;
					}
					end = cur->next;
				}
				break;
			case 2:
				vse = true;
				while (vse) {
					vse = false;
					cur = start;
					if (cur->lines < cur->next->lines) {
						PROG* temp = cur->next;
						cur->next = cur->next->next;
						temp->next->prev = cur;
						temp->prev = cur->prev;
						cur->prev = temp;
						temp->next = cur;
						start = temp;
						vse = true;
					}
					while (cur->next->next != NULL) {
						if (cur->next->lines < cur->next->next->lines) {
							PROG* temp = cur->next->next;
							if (temp->next != NULL)
								temp->next->prev = temp->prev;
							cur->next->prev = temp;
							temp->prev = cur;
							cur->next->next = temp->next;
							temp->next = cur->next;
							cur->next = temp;
							vse = true;
						}
						cur = cur->next;
					}
					end = cur->next;
				}
				break;
			case 0:
				goto k;
				break;
			default:
				cout << "Неверное значение." << endl;
				break;
				goto p1;
			}
			system("cls");
			cout << "Данные успешно отсортированы." << endl;
			system("PAUSE");
			break;
		case 3:
		p2:
			system("cls");
			cout << "1.Сортировать по возрастанию." << endl << "2.По убыванию." << endl << "0.Выход" << endl << "Ввод: ";
			cin >> p;
			switch (p) {
			case 1:
				vse = true;
				while (vse) {
					vse = false;
					cur = start;
					if (cur->time_call > cur->next->time_call) {
						PROG* temp = cur->next;
						cur->next = cur->next->next;
						temp->next->prev = cur;
						temp->prev = cur->prev;
						cur->prev = temp;
						temp->next = cur;
						start = temp;
						vse = true;
					}
					while (cur->next->next != NULL) {
						if (cur->next->time_call > cur->next->next->time_call) {
							PROG* temp = cur->next->next;
							if (temp->next != NULL)
								temp->next->prev = temp->prev;
							cur->next->prev = temp;
							temp->prev = cur;
							cur->next->next = temp->next;
							temp->next = cur->next;
							cur->next = temp;
							vse = true;
						}
						cur = cur->next;
					}
					end = cur->next;
				}
				break;
			case 2:
				vse = true;
				while (vse) {
					vse = false;
					cur = start;
					if (cur->time_call < cur->next->time_call) {
						PROG* temp = cur->next;
						cur->next = cur->next->next;
						temp->next->prev = cur;
						temp->prev = cur->prev;
						cur->prev = temp;
						temp->next = cur;
						start = temp;
						vse = true;
					}
					while (cur->next->next != NULL) {
						if (cur->next->time_call < cur->next->next->time_call) {
							PROG* temp = cur->next->next;
							if (temp->next != NULL)
								temp->next->prev = temp->prev;
							cur->next->prev = temp;
							temp->prev = cur;
							cur->next->next = temp->next;
							temp->next = cur->next;
							cur->next = temp;
							vse = true;
						}
						cur = cur->next;
					}
					end = cur->next;
				}
				break;
			case 0:
				goto k;
				break;
			default:
				cout << "Неверное значение." << endl;
				break;
				goto p2;
			}
			system("cls");
			cout << "Данные успешно отсортированы." << endl;
			system("PAUSE");
			break;
		case 4:
		p3:
			system("cls");
			cout << "1.Сортировать по возрастанию." << endl << "2.По убыванию." << endl << "0.Выход" << endl << "Ввод: ";
			cin >> p;
			switch (p) {
			case 1:
				vse = true;
				while (vse) {
					vse = false;
					cur = start;
					if (cur->time_indy > cur->next->time_indy) {
						PROG* temp = cur->next;
						cur->next = cur->next->next;
						temp->next->prev = cur;
						temp->prev = cur->prev;
						cur->prev = temp;
						temp->next = cur;
						start = temp;
						vse = true;
					}
					while (cur->next->next != NULL) {
						if (cur->next->time_indy > cur->next->next->time_indy) {
							PROG* temp = cur->next->next;
							if (temp->next != NULL)
								temp->next->prev = temp->prev;
							cur->next->prev = temp;
							temp->prev = cur;
							cur->next->next = temp->next;
							temp->next = cur->next;
							cur->next = temp;
							vse = true;
						}
						cur = cur->next;
					}
					end = cur->next;
				}
				break;
			case 2:
				vse = true;
				while (vse) {
					vse = false;
					cur = start;
					if (cur->time_indy < cur->next->time_indy) {
						PROG* temp = cur->next;
						cur->next = cur->next->next;
						temp->next->prev = cur;
						temp->prev = cur->prev;
						cur->prev = temp;
						temp->next = cur;
						start = temp;
						vse = true;
					}
					while (cur->next->next != NULL) {
						if (cur->next->time_indy < cur->next->next->time_indy) {
							PROG* temp = cur->next->next;
							if (temp->next != NULL)
								temp->next->prev = temp->prev;
							cur->next->prev = temp;
							temp->prev = cur;
							cur->next->next = temp->next;
							temp->next = cur->next;
							cur->next = temp;
							vse = true;
						}
						cur = cur->next;
					}
					end = cur->next;
				}
				break;
			case 0:
				goto k;
				break;
			default:
				system("cls");
				cout << "Неверное значение." << endl;
				system("PAUSE");
				break;
				goto p3;
			}
			system("cls");
			cout << "Данные успешно отсортированы." << endl;
			system("PAUSE");
			break;
		case 0:
			return;
			break;
		default:
			cout << "Неверное значение." << endl;
			break;
			goto k;
		}
	}

};
int main() {
	setlocale(LC_ALL, "RUSSIAN");
	List* list = NULL;
	int count = 0;
dd:
	int n = 0;
	system("cls");
	cout << "Меню: " << endl;
	cout << "1.Создание списка." << endl;
	cout << "2.Печать списка с начала." << endl;
	cout << "3.Печать списка с конца." << endl;
	cout << "4.Поиск по критерию с начала списка." << endl;
	cout << "5.Поиск по критерию с конца списка." << endl;
	cout << "6.Добавление элемента." << endl;
	cout << "7.Удаление  любого элемента." << endl;
	cout << "8.Сортировка." << endl;
	cout << "9.Запись нового списка в файл." << endl;
	cout << "10.Печать нового списка из файла." << endl;
	cout << "11. Выход из программы." << endl;
	cin >> n;
	switch (n) {
	case 1:
		list = new List();
		list->CreatList();
		break;
	case 2:
		if (list == NULL) {
			system("cls");
			cout << "Необходимо ввести данные элементов!" << endl;
			system("pause");
			goto dd;
		}
		list->PrintStart();
		break;
	case 3:
		if (list == NULL) {
			system("cls");
			cout << "Необходимо ввести данные элементов!" << endl;
			system("pause");
			goto dd;
		}
		list->PrintEnd();
		break;
	case 4:
		if (list == NULL) {
			system("cls");
			cout << "Необходимо ввести данные элементов!" << endl;
			system("pause");
			goto dd;
		}
		list->SearchStart();
		break;
	case 5:
		if (list == NULL) {
			system("cls");
			cout << "Необходимо ввести данные элементов!" << endl;
			system("pause");
			goto dd;
		}
		list->SearchEnd();
		break;
	case 6:
		if (list == NULL) {
			system("cls");
			cout << "Необходимо ввести данные элементов!" << endl;
			system("pause");
			goto dd;
		}
		list->Adding();
		break;
	case 7:
		if (list == NULL) {
			system("cls");
			cout << "Необходимо ввести данные элементов!" << endl;
			system("pause");
			goto dd;
		}
		list->Deleting();
		break;
	case 8:
		if (list == NULL) {
			system("cls");
			cout << "Необходимо ввести данные элементов!" << endl;
			system("pause");
			goto dd;
		}
		list->Sorting();
		break;
	case 9:
		if (list == NULL) {
			system("cls");
			cout << "Необходимо ввести данные элементов!" << endl;
			system("pause");
			goto dd;
		}
		list->PrintFile();
		break;
	case 10:
		list = new List();
		list->ReadFile();
		break;
	case 11:
		return 0;
		break;
	default:
		cout << "Неверное значение";
		goto dd;
		break;
	}
	goto dd;
}
