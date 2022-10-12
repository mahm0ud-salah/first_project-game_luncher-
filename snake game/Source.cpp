#include <bits/stdc++.h>
#include <conio.h>
#define nl "\n"
#define M_S std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
using namespace std;
bool flag = true;
bool flag2 = true;
int sx = 10;
int sy = 10;
int fx = rand() % 25;
int fy = rand() % 25;
int mx = 1;
int my = 0;
int score = 0;
int  siz=1;
int f = 1;
int f2 = siz;
int x;
int ma=0;
vector<pair<int, int>>v(siz);
class player {
public:
	int x1=15,x2=20;
};
class ball {
public:
	int x= 18,y=2;
};
player one;
player tow;
ball on;
void print2()
{
	system("cls");
	cout << "###################################" << nl;
	for (int i = 1; i <= 25; i++)
	{
		for (int j = 1; j <= 35; j++)
		{
			if (on.y == 26 || on.y == 0)
				flag = false;
			else if (j == 1 || j == 35)
				cout << '#';
			else if ((i == 1 && j >= one.x1 && j <= one.x2) || (i == 25 && j >= tow.x1 && j <= tow.x2))
				cout << '@';
			else
				cout << ' ';
			if (j == on.x && i == on.y)
			{
				cout << 'O';
				j++;
			 }
		}
		cout << nl;
	}
	cout << "###################################" << nl;
}
void move2()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			one.x1--;
			one.x2--;
			break;
		case'd':
			one.x1++;
			one.x2++;
			break;
		case 'j':
			tow.x1--;
			tow.x2--;
			break;
		case'l':
			tow.x1++;
			tow.x2++;
			break;
		}
	}
}
void ballmove()
{
	if (on.x == 1)
		mx = 1;
	else if (on.x == 34)
		mx = -1;
	 if (on.y == 2){    	
		 if (on.x >= one.x1 && on.x <= one.x2)
		 {
			 if (on.x == one.x1 || on.x == one.x1 + 1)
			 {
				 mx = 1;
				 my = 1;
			 }
			 else if (on.x == one.x1 + 2 || on.x == one.x1 + 3)
				 my = 1;
			 else
			 {
				 mx = -1;
				 my = 1;
			 }
		 }
		 else
			 on.x = 0;
     }
	 else if (on.y == 24)
	 {
		 if (on.x >= tow.x1 && on.x <= tow.x2)
		 {
			 if (on.x == tow.x1 || on.x == tow.x1 + 1)
			 {
				 mx = -1;
				 my = -1;
			 }
			 else if (on.x == tow.x1 + 2 || on.x == tow.x1 + 3)
				 my = -1;
			 else
			 {
				 mx = 1;
				 my = -1;
			 }
		 }
		 else
			 on.x = 26;
	 }
	 on.x += mx;
	 on.y += my;
}
void print1()
{
	f = 1;
	f2 = siz;
	v[0].first = sx;
	v[0].second = sy;
	system("cls");
	for (int i = 1; i < siz; i++)
	{
		if (v[i].first == sx && v[i].second == sy)
		{
			flag = false;
			break;
		}
	}
	cout << "##########################"<<nl;
	for (int j = 0; j < 26; j++)
	{
		for (short i = 0; i < 24; i++)
		{
			if (i == 0)
				cout << "#";
			if (v[0].first == i && v[0].second == j)
				cout << 'O';
			else if (f<siz&&v[f].first == i && v[f].second==j)
			{
				
 				cout << 'o';
				f++;
			}
			else if (f2>1 && v[f2-1].first == i && v[f2-1].second==j)
			{
				
				cout << 'o';
				f2--;
			}
			else if (i == fx && j == fy)
				cout << '@';
			else
			{
				cout << ' ';
			}
			if (sx == fx && sy == fy)
			{
				fx = rand() % 25;
			    fy = rand() % 25;
				score += 10;
				siz++;
				v.resize(siz);
			}
		}
		cout << '#'<<nl;
	}
	cout << "##########################" << nl;
}
void move()
{
	for (int i = siz - 1; i > 0; i--)
	{
		v[i].first = v[i - 1].first;
		v[i].second = v[i - 1].second;
	}
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			sx--;
			mx = -1;
			my = 0;
			break;
		case 'd':
			sx++;
			mx = 1;
			my = 0;
			break;
		case 's':
			sy++;
			mx = 0;
			my = 1;
			break;
		case 'w':
			sy--;
			mx = 0;
			my = -1;
			break;
		}
	}
	else
	{
		sx += mx;
		sy += my;
	}
	
}
void solve()
{
	while (1)
	{
		flag = true;
		sx = 10;
		sy = 10;
		fx = rand() % 25;
		fy = rand() % 25;
		mx = 1;
		my = 0;
		score = 0;
		siz = 1;
		while (1)
		{
			print1();
			if (sx == 25 || sy == 25 || sx == -1 || sy == -1)
			{
				break;
			}
			move();
			if (!flag)
				break;
			cout << "Your Score is : " << score<<nl;
			if (score > ma)
				ma = score;
			cout << "Best Scort is : " << ma;
		}
		cout << "Game over " << nl << "Your Score is : " << score << nl<< "Best Scort is : " << ma << nl<<nl;
		cout << "press 1 to play again or press any other key to out" << nl;
		cin >> x;
		if (x != 1)
		{
			cout << "Goodbye Bro" << nl;
			break;
		}
	}
}
void solve2() {
	while (1)
	{
		on.x = 18; on.y = 2;
		one.x1 = 15;
		one.x2 = 20;
		tow.x1 = 15;
		tow.x2 = 20;
		my = 1;
		mx = 0;
		while (flag)
		{
			print2();
			move2();
			ballmove();
		}
		cout << "Game Over press 1 to play again or press any other key to out" << nl;
		cin >> x;
		if (x != 1)
		{
			cout << "Goodbye Bro" << nl;
			break;
		}
		else
			flag = true;

	}
}
void game1()
{
	flag = true;
	cout << "Snake Game 2022" << nl;
	cout << "1-start\n2-credits\n3-How to play\n";
	cout << "*****************************" << nl;
	cout << "* game controls a,s,d and w *" << nl;
	cout << "*****************************" << nl;
	cin >> x;
	if (x == 1)
	{
		solve();
	}
	else if (x == 2)
	{
		cout << "*******************************************************" << nl;
		cout << "*snake game 2022  coding by Mahmoud_Salah just that :)*\n";
		cout << "*******************************************************" << nl;
		cout << "Now\n1 - Start ? \nany key - Out ? " << nl;
		cin >> x;
		if (x == 1)
		{
			solve();
		}
		else
		{
			cout << "Goodbye Bro" << nl;
		}
	}
	else
	{
		cout << "1-don't touch walls\n2-don't touch yourself :)\n Now\n 1-Start?\nany key-Out?";
		cin >> x;
		if (x != 1)
			cout << "Goodbye Bro" << nl;
		else
		{
			solve();
		}

	}
}
void game2() {
	flag = true;
	cout << "Welcome Ball Gaeme" << nl;
	cout << "*****************************" << nl;
	cout << "1-start\n2-credits\n3-How to play\n4-Controls\n";
	cout << "*****************************" << nl;
	cin >> x;
	if (x == 1)
	{
		solve2();
	}
	else if (x == 2)
	{
		cout << "*************************************************" << nl;
		cout << "*Ball Game  coding by Mahmoud_Salah just that :)*\n";
		cout << "*************************************************" << nl;
		cout << "Now\n1 - Start ? \nany key - Out ? " << nl;
		cin >> x;
		if (x == 1)
		{
			solve2();
		}
		else
		{
			cout << "Goodbye Bro" << nl;
		}
	}
	else if (x == 3)
	{
		cout << "Try To keep Ball far from your Wall\n Now\n 1-Start?\nany key-Out?" << nl;
		cin >> x;
		if (x != 1)
			cout << "Goodbye Bro" << nl;
		else
		{
			solve2();
		}
	}
	else
	{
		cout << "Player 1 controls a,d \n Player 2 controls j,l\n Now\n 1-Start?\nany key-Out?"<<nl;
		cin >> x;
		if (x != 1)
			cout << "Goodbye Bro" << nl;
		else
		{
			solve2();
		}
	}
}
int main()
{
	M_S
		cout << "WELCOME TO M_S GAME LUNCHER v1.1 :-)" << nl;
	cout << "to Play snke game press 1" << nl << "to Play ball game (new in this update) press 2"<<nl;
	short t;
	while (flag)
	{
		cin >> t;
		switch (t)
		{
		case 1:
			game1();
			flag = false;
			break;
		case 2:
			game2();
			flag = false;
			break;
		default:
			cout << "press 1 or 2" << nl;
		}
	}
}