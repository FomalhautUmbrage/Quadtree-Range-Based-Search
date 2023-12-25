#include "Quad.h"
#include "illegal_exception.h"
int main()
{
	Quad* quad = nullptr;
	string  command;
	while (true)
	{
		cin >> command;
		try {
			if (command == "INIT") {
				Point startp, endp;
				int m;
				cin >> m >> startp >> endp;
				if (startp.getX() < endp.getX() && startp.getY() < endp.getY()) {
					quad = new Quad(startp, endp, m);
					cout << "success" << endl;
				}
				else {
					throw illegal_exception("illegal argument");
				}

			}
			else if (command == "INSERT") {
				Point p;
				cin >> p;
				if (quad != nullptr) {
					bool oper = quad->insertPoint(p);
					cout << (oper ? "success" : "failure") << endl;
				}
			}
			else if (command == "SEARCH") {
				Point p;
				double d;
				cin >> p >> d;
				if (quad != nullptr) {
					bool oper = quad->searchPoint(p, d);
					cout << (oper ? "point exists" : "no point exists") << endl;
				}
			}
			else if (command == "NEAREST") {
				Point p, fp;
				cin >> p;
				if (quad != nullptr) {
					bool oper = quad->nearestPoint(p, fp);
					if (oper) {
						cout << fp << endl;
					}
					else {
						cout << "no point exists" << endl;
					}
				}
			}
			else if (command == "RANGE") {
				Point startp, endp;
				int count = 0;
				cin >> startp >> endp;
				if (startp.getX() < endp.getX() && startp.getY() < endp.getY()) {
					if (quad != nullptr) {
						Point* fps = quad->range(startp, endp, count);
						if (count == 0) {
							cout << "no points within range" << endl;
						}
						else {
							for (int i = 0; i < count; i++) {
								cout << fps[i];
								if (i != count - 1) {
									cout << " ";
								}
								else {
									cout << endl;
								}
							}
							delete[] fps;
						}
					}
				}
				else {
					throw illegal_exception("illegal argument");
				}
				
			}
			else if (command == "NUM") {
				cout << quad->num() << endl;
			}
			else if (command == "EXIT") {
				break;
			}
		}
		catch (const illegal_exception& e) {
			cout << e.what() << endl;
		}		
	}
	if (quad != nullptr)
		delete quad;
	return 0;
}