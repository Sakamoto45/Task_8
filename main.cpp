#include "Tree.hpp"

// using namespace std;

// 1 add
// 2 pop
// 3 show
// 4 amount negative weight
// 5 exit

int main()
{
	cout << "1 add" << endl << "2 pop" << endl << "3 show" << endl << "4 amount negative weight" << endl << "5 exit" << endl;

	Tree a;
	for (int i = 0; i < (rand() % 6 + 5); i++) {
		a.add(rand() % 10, &a.tree);
	}
	int b;
	cout << "waiting command << ";
	cin >> b;

	while (b != 5) {
		switch (b) {
		case 1:
			cout << "waiting item to add << ";
			cin >> b;
			a.add(b, &a.tree);
			break;
		case 2:
			cout << "waiting item to pop << ";
			cin >> b;
			a.tree = a.pop(b, (a.tree));
			break;
		case 3:
			a.show(a.tree, 0);
			break;
		case 4:
			cout << "amount negative weight = " << a.anw(a.tree) << endl;
			break;
		default:
			break;
		}
		cout << "waiting command << ";
		cin >> b;
	}

	return 0;
}