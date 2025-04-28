#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<string>
#include<windows.h>
#include<ctime>
#include<conio.h>
using namespace std;
class  que
{
public:
    que(string n) :next(nullptr), request(n) {}
    que* next;
    string request;
};
class questruct
{
    que* front;
    que* rear;
public:
    questruct() :front(nullptr), rear(nullptr) {}
    void enque(string n)
    {
        que* ne = new que(n);
        if (front == nullptr)
        {
            front = rear = ne;
        }
        else
        {
            rear->next = ne;
            rear = rear->next;
        }
    }
    bool empty()
    {
        if (front == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string deque()
    {
        if (front == nullptr)
        {
            return "";
        }
        else
        {
            string y;
            que* temp = front;
            y = temp->request;
            front = front->next;
            delete temp;
            return y;
        }
        return "";
    }
    void display()
    {
        que* temp = front;
        if (!temp)
        {
            cout << "list is empty" << endl;
            return;
        }
        while (temp)
        {
            cout << temp->request << endl;
            temp = temp->next;
        }
    }
    ~questruct()
    {
        que* temp = front;
        while (temp)
        {
            front = front->next;
            delete temp;
            temp = front;
        }
    }
};
class stack
{
public:
    stack* next;
    string message;
    stack(string s) :message(s), next(nullptr) {}
};
class stackstruct
{
    stack* top;
public:
    stackstruct() :top(nullptr) {}
    bool empty()
    {
        if (top == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void insert(string s)
    {
        stack* n = new stack(s);
        if (empty())
        {
            top = n;
            return;
        }
        else
        {
            n->next = top;
            top = n;
            return;
        }
    }
    void peek()
    {
        if (!empty())
        {
            cout << top->message << endl;
        }
        else
        {
            cout << "Inbox is empty" << endl;
        }
    }
    void display()
    {
        stack* temp = top;
        if (empty())
        {
            cout << "Inbox is empty" << endl;
            return;
        }
        while (temp)
        {
            cout << temp->message << endl;
            temp = temp->next;
        }
    }
    void pop()
    {
        if (empty())
        {
            cout << "Inbox is empty" << endl;
            return;
        }
        stack* temp = top;
        top = top->next;
        delete temp;
    }
    ~stackstruct()
    {
        stack* temp = top;
        
        while (temp)
        {
            top = top->next;
            delete temp;
            temp = top;
        }
    }
};
class posts
{
public:
    string date_time;
    string name;
    string context;
    posts* next;
    posts() :next(nullptr) {}
};
class poststack
{
    posts* top;
public:
    poststack() :top(nullptr) {}
    bool empty()
    {
        if (top == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void insert(posts s)
    {
        posts* n = new posts();
        n->context = s.context;
        n->date_time = s.date_time;
        n->name = s.name;
        if (empty())
        {
            top = n;
            return;
        }
        else
        {
            n->next = top;
            top = n;
            return;
        }
    }
    void display()
    {
        cout << "Post:" << endl;
        posts* temp = top;
        if (empty())
        {
            cout << "No post available" << endl;
            return;
        }
        while (temp)
        {
            cout << "User id" << endl;
            cout << temp->name << endl;
            cout << "Post Content:" << endl;
            cout << temp->context << endl;
            cout << "Date and Time:" << endl;
            cout << temp->date_time << endl;
            temp = temp->next;
        }
    }
    void pop()
    {
        if (empty())
        {
            cout << "NO Post available" << endl;
            return;
        }
        posts* temp = top;
        top = top->next;
        delete temp;
    }
    ~poststack()
    {
        posts* temp = top;
        while (temp)
        {
            top = top->next;
            delete temp;
            temp = top;
        }
    }
};
class edge
{
public:
    string relation;
    string status;
    stackstruct* mess;
    questruct realtime;
    edge() :mess(nullptr) {}
};
class node
{
public:
    string name;
    string security;
    string Password;
    string City;
    posts post;
    string Last_login;
    node(string n, string c, string p, string s)
    {
        City = c;
        name = n;
        Password = p;
        security = s;
        Last_login = "";

    }
};
class users
{
public:

    questruct quereq;
    questruct notification;
    edge ed;
    node* no;
    users* next;
    poststack myfeed;
    poststack folwrpost;
    string* sugg;
    int sc;
public:
    users() : no(nullptr), next(nullptr),sugg(nullptr),sc(0) {}
  
};

class searchname
{
public:
    searchname(string d) :data(d), left(nullptr), right(nullptr) {}
    string data;
    searchname* left, * right;
};
class bst
{
    searchname* root;
public:
    bst() :root(nullptr) {}
    void insert(string d)
    {
        searchname* n = new searchname(d);
        if (!root)
        {
            root = n;
            return;
        }
        else
        {
            searchname* temp = root;
            while (temp)
            {
                if (d < temp->data) 
                {
                    if (!temp->left)
                    {
                        temp->left = n;
                        return;

                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else if (d > temp->data)
                {
                    if (!temp->right)
                    {
                        temp->right = n;
                        return;

                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
                else
                {
                    cout << "duplicate value" << endl;
                    return;
                }
            }
        }
    }
    void inorder(searchname* root)
    {
        if (!root)
        {
            return;
        }
        else
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
    void up(string k, string n, searchname* root)
    {
        if (!root)
        {
            return;
        }
        if (root->data == k)
        {
            root->data = n;
            return;
        }
        else if (k < root->data)
        {
            up(k,n,root->left);
        }
        else
        {
            up(k,n,root->right);
        }
    }
    void update(string k,string n)
    {
        up(k, n, root);
    }
    void se()
    {
        cout << "Enter name of user that you want to Search" << endl;
        string k;
        cin.ignore();
        getline(cin,k);
        bool p=search(root, k);
        if (!p)
        {
        
            cout << "Not Found" << endl;
        
        }
    }
    bool search(searchname* root, string k)
    {
        if (!root)
        {
            return false;
        }
        if (root->data == k)
        {
            cout << "Found"<<endl;
            return true;
        }
        else if (k < root->data)
        {
            search(root->left, k);
        }

        else if (k > root->data)
        {
            search(root->right, k);
        }
        return false;
    }
    void display()
    {
        inorder(root);
    }
};
class graph
{
    users** list;
    users* login;
    int count;
public:
    graph() : list(nullptr), count(0), login(nullptr) {}
    bst b;
    bool loggedin()
    {
        string n, p;
        cout << "Enter Your Name" << endl;
        cin.ignore();
        getline(cin, n);
        cout << "Enter Your Password" << endl;
        getline(cin, p);
        int co = 0;
        bool name = false;
        for (int i = 0; i < count; i++)
        {
            if (list[i]->no->name != n && list[i]->no->Password != p)
            {
                name = true;
            }
            else
            {
                name = false;
                break;
            }
        }
        if (name)
        {
            cout << "no account exist for this name and password" << endl;
            return false;
        }
        else
        {

            for (int i = 0; i < count; i++)
            {
                if (list[i]->no->name == n && list[i]->no->Password == p)
                {
                    co = i;
                    login = list[i];
                    cout << login->no->Last_login;
                    return true;
                }

            }
            name = false;
            for (int i = 0; i < count; i++)
            {
                if (list[i]->no->name == n)
                {
                    name = true;
                }

            }
            if (!name)
            {
                cout << "Invalid username" << endl;
                return false;
            }
            else
            {
                cout << "Invalid Password" << endl;
                cout << "forgotten password" << endl;
                cout << "yes/no" << endl;
                string y;
                cin >> y;
                string s;
                if (y == "yes")
                {
                    cout << "Enter security answer" << endl;
                    cin.ignore();
                    getline(cin, s);
                    if (s == list[co]->no->security)
                    {
                        cout << "your answer is right" << endl;
                        cout << "Enter new password" << endl;
                        bool flag;
                        do
                        {
                           flag = true;
                            getline(cin, p);
                            for (int i = 0; i < count; i++)
                            {
                                if (list[i]->no->Password == p)
                                {
                                    cout << "Account already exists with this password! Enter a unique password" << endl;
                                    flag = false;
                                    break;
                                }
                            }
                        } while (!flag);
                        list[co]->no->Password = p;
                        login = list[co];
                        cout << "your password is update" << endl;
                        cout << login->no->Last_login;
                        return true;
                    }
                    cout << "wrong security answer" << endl;
                    return false;
                }
            }
        }
        return false;

    }
    bool signup()
    {
        string n, c, p, s;
        bool flag;
        cin.ignore();
        do
        {
            flag = true;
            cout << "Enter Your Name: ";
            getline(cin, n);
            if (n == "")
            {
                flag = false;
            }
            for (int i = 0; i < count; i++)
            {
                if (list[i]->no->name == n)
                {
                    cout << "Account already exists with this name! Enter a unique name"<<endl;
                    flag = false;
                    break;
                }
            }
        } while (!flag);
        do
        {
            flag = true;
            cout << "Enter Your City: ";
            getline(cin, c);
            if (c == "")
            {
                flag = false;
            }
        } while (!flag);

        do
        {
            flag = true;
            cout << "Enter Your Password: ";
            getline(cin, p);
            if (p == "")
            {
                flag = false;
            }

            for (int i = 0; i < count; i++)
            {
                if (list[i]->no->Password == p)
                {
                    cout << "Account already exists with this password! Enter a unique password"<<endl;
                    flag = false;
                    break;
                }
            }
        } while (!flag);
        do
        {
            flag = true;
            cout << "A Security Question in case of forgotten Password"<<endl;
            cout << "What is Your Favorite Dish? "<<endl;
            getline(cin, s);
            if (s == "")
            {
                flag = false;
            }

            for (int i = 0; i < count; i++)
            {
                if (list[i]->no->security == s)
                {
                    cout << "Account already exists with this security answer! Enter a unique answer"<<endl;
                    flag = false;
                    break;
                }
            }
        } while (!flag);
        b.insert(n);
        addusers(n, c, p, s);
        return true;
    }

    void logout()
    {
        if (login == nullptr)
        {
            cout << "No user is logged in" << endl;
            return;
        }
        login->no->Last_login = "last login at ";
        time_t now = time(0);
        string t = ctime(&now);
        login->no->Last_login += t;
        cout << "Logged out successfully " << endl;
        cout << t << endl;
        login = nullptr;

    }
    void addusers(string n, string c, string p, string s)
    {
        users* u = new users();
        u->no = new node(n, c, p, s);
        users** newlist = new users * [count + 1];
        for (int i = 0; i < count; i++)
        {
            newlist[i] = list[i];
        }
        newlist[count] = u;
        login = newlist[count];
        delete[] list;
        list = newlist;
        count++;
        cout << "Your Account has been created" << endl;
    }
    void addedge(string n, string m)
    {
        int k = index(n);
        int l = index(m);
        if (k == -1 || l == -1)
        {
            cout << " One or both users not found" << endl;
            return;
        }
        users* io = new users();
        io->no = new node(list[l]->no->name, list[l]->no->City, list[l]->no->Password, list[l]->no->security);
        io->ed.relation = "Friend";
        io->ed.status = "Pending";
        io->next = list[k]->next;
        list[k]->next = io;
    }
    int index(string n)
    {
        for (int i = 0; i < count; i++)
        {
            if (list[i]->no->name == n)
            {
                return i;
            }
        }
        return -1;
    }
    void sendreq()
    {
        if (!login)
        {
            return;
        }
        else
        {
            users* rec = nullptr;
            cout << "Enter a name of Person you want to send a request " << endl;
            string s;
            cin.ignore();
            users* temp = nullptr;
            getline(cin, s);
            if (login->no->name == s)
            {
                cout << "You cannot follow to yourself" << endl;
                return;
            }
            for (int i = 0; i < count; i++)
            {
                if (list[i]->no->name == login->no->name)
                {
                    temp = list[i];
                    break;
                }
            }
            while (temp)
            {
                if (temp->no->name == s && temp->ed.status == "Pending")
                {
                    cout << "already Friend request send" << endl;
                    return;
                }
                else if (temp->no->name == s && temp->ed.status == "Active")
                {
                    cout << "Already You Follow " << s << endl;
                    return;

                }
                else
                {
                    temp = temp->next;
                }
            }
            int k = index(s);
            if (k != -1)
            {
                rec = list[k];
                if (rec)
                {
                    rec->quereq.enque(login->no->name);
                    addedge(login->no->name, s);
                    cout << "Request send to " << s << endl;
                    string o;
                    o = login->no->name;
                    o += " Send a request to you";
                    rec->notification.enque(o);
                    return;
                }
            }
            else
            {
                cout << s << " Name account doesn't exist" << endl;
                return;
            }
        }
        return;

    }
    void acceptreq()
    {
        if (!login)
        {
            return;
        }

        else
        {
            cout << "For all request accept Press Z or Press P to accept old request" << endl;
            char k;
            cin >> k;
            if (k == 'p' || k == 'P')
            {

                string j = login->quereq.deque();
                if (j != "")
                {
                    int k = index(j);
                    users* temp = list[k]->next;
                    while (temp->no->name != login->no->name)
                    {
                        temp = temp->next;
                    }
                    temp->ed.status = "Active";
                    string o;
                    o = temp->no->name;
                    o += " Accept your request";
                    temp = list[k];
                    temp->notification.enque(o);
                    o = "You  Accept the request of ";
                    o += j;
                    login->notification.enque(o);
                    cout << "You  Accept the request of " << j << endl;
                    cout << j << " is following you" << endl;
                }
                else
                {
                    cout << "No request in que" << endl;
                    return;
                }
                bool flag = false;
                users* temp = login->next;
                while (temp)
                {
                    if (temp->no->name == j)
                    {
                        flag = true;
                    }
                    temp = temp->next;
                }
                if (!flag)
                {
                    users* rec = nullptr;
                    for (int i = 0; i < count; i++)
                    {
                        if (list[i]->no->name == j)
                        {
                            rec = list[i];
                            break;
                        }
                    }
                    string k;
                    cout << "for follow back (Press y)" << endl;
                    cin >> k;
                    if (k == "y" || k == "Y")
                    {
                        addedge(login->no->name, j);
                        cout << "Now You send a request to " << j << endl;
                        if (rec)
                        {
                            rec->quereq.enque(login->no->name);
                            string o = login->no->name;
                            o += "  send a request to you";
                            rec->notification.enque(o);
                        }

                    }
                    else
                    {
                        cout << "You don't want to send a request" << endl;
                    }
                }
            }
            else if (k == 'Z' || k == 'z')
            {
                if (login->quereq.empty())
                {
                    cout << "No request in que" << endl;
                    return;     
                }
                while (!(login->quereq.empty())) 
                {
                    string j = login->quereq.deque();
                    if (j != "")
                    {
                        int k = index(j);
                            users* temp = list[k]->next;
                            while (temp->no->name != login->no->name)
                            {
                                temp = temp->next;
                            }
                            temp->ed.status = "Active";
                            string o;
                            o = temp->no->name;
                            o += " Accept your request";
                            temp = list[k];
                            temp->notification.enque(o);
                            o = "You  Accept the request of ";
                            o += j;
                            login->notification.enque(o);
                            cout << "You  Accept the request of " << j << endl;
                            cout << j << " is following you" << endl;  
                    }
                    bool flag = false;
                    users* temp = login->next;
                    while (temp)
                    {
                        if (temp->no->name == j)
                        {
                            flag = true;
                        }
                        temp = temp->next;
                    }
                    if (!flag)
                    {
                        users* rec = nullptr;
                        for (int i = 0; i < count; i++)
                        {
                            if (list[i]->no->name == j)
                            {
                                rec = list[i];
                                break;
                            }
                        }
                        string k;
                        cout << "for follow back (Press y)" << endl;
                        cin >> k;
                        if (k == "y" || k == "Y")
                        {
                            addedge(login->no->name, j);
                            cout << "Now You send a request to " << j << endl;
                            if (rec)
                            {
                                rec->quereq.enque(login->no->name);
                                string o = login->no->name;
                                o += "  send a request to you";
                                rec->notification.enque(o);
                            }

                        }
                        else
                        {
                            cout << "You don't want to send a request" << endl;
                        }
                    }
                    else
                    {
                        cout << "You already follow   " << j << endl;
                    }
                }
            }
            else
            {
                cout << "invalid input" << endl;
                return;
            }

        }
    }
    void declinereq()
    {
        if (!login)
        {
            return;
        }
        string j = login->quereq.deque();
        if (j != "") {
            int k = index(j);
            if (k != -1)
            {
                users* temp = list[k]->next;
                users* pre = list[k];

                while (temp->no->name != login->no->name)
                {
                    pre = temp;
                    temp = temp->next;
                }
                pre->next = temp->next;
                delete temp;

                if (j != "")
                {
                    cout << "You decline the follow request of " << j << endl;
                }
                users* rec = list[k];
                string o = login->no->name;
                o += "  decline your follow request";
                rec->notification.enque(o);
            }
        }
        else
        {
            cout << "No request in que" << endl;
        }

    }
    void viewreq()
    {

        if (!login)
        {
            return;
        }
        cout << "Following Request are" << endl;
        login->quereq.display();
    }
    void blocked()
    {

        if (!login)
        {
            return;
        }
        cout << "FOLLOWERS LIST ARE:" << endl;
        cout << "Name" << endl;
        for (int i = 0; i < count; i++)
        {
            bool flag = false;
            users* temp = list[i]->next;
            if (!temp)
            {
                cout << "FOLLOWERS LIST ARE EMPTY" << endl;
                return;
            }
            while (temp)
            {
                if (temp->no->name == login->no->name && temp->ed.status != "Pending")
                {
                    flag = true;
                }
                temp = temp->next;
            }
            if (flag)
            {
                cout << list[i]->no->name << endl;
            }
        }
        cout << "Enter a name of any of your Follower  that You may  want to block " << endl;
        string s;
        cin.ignore();
        getline(cin, s);
        int k = index(s);
        if (k != -1) {
            users* temp = list[k]->next;
            while (temp && temp->no->name != login->no->name)
            {
                temp = temp->next;
            }
            if (temp && temp->no->name == login->no->name)
            {
                temp->ed.status = "Blocked";
                cout << "You Blocked " << s << endl;
                string o;
                temp = list[k];
                o = login->no->name;
                o += " Blocked you";
                temp->notification.enque(o);

            }
            else
            {
                cout << "You cannot blocked beacuse " << s << "  deosnot follow you" << endl;
            }
        }
        else
        {
            cout << "You cannot blocked beacuse " << s << " name account deosnot exist" << endl;
        }
    }
    void display()
    {

        if (!login)
        {
            return;
        }
        cout << "********************************" << endl;
        cout << "YOUR DETAILS: " << endl;
        cout << "NAME: " << login->no->name << endl;
        cout << "CITY: " << login->no->City << endl;
        users* temp = login->next;
        if (!temp)
        {
            cout << "following list are empty" << endl;
        }
        else
        {
            cout << "YOUR FOLLOWING LIST ARE: " << endl;
            cout << "Name\tRelation\tStatus " << endl;
            while (temp)
            {
                cout << temp->no->name << "\t" << temp->ed.relation
                    << "\t\t" << temp->ed.status << endl;
                temp = temp->next;
            }
        }
        cout << "FOLLOWERS LIST ARE:" << endl;
        cout << "Name" << endl;
        bool all = false;
        for (int i = 0; i < count; i++)
        {
            bool flag = false;
            users* temp = list[i]->next;
            while (temp && temp->ed.status != "Pending")
            {
                if (temp->no->name == login->no->name)
                {
                    flag = true;
                }
                temp = temp->next;
            }
            if (flag)
            {
                all = true;
                cout << list[i]->no->name << endl;
            }
        }
        if (!all)
        {
            cout << "Followers list are empty" << endl;
        }
        cout << endl;
        cout << "BLOCKED CONTACTS ARE:" << endl;
        cout << "Name" << endl;
        all = false;
        for (int i = 0; i < count; i++)
        {
            bool flag = false;
            users* temp = list[i]->next;
            while (temp)
            {
                if (temp->no->name == login->no->name && temp->ed.status == "Blocked")
                {
                    flag = true;
                }
                temp = temp->next;
            }
            if (flag)
            {
                all = true;
                cout << list[i]->no->name << endl;
            }
        }
        if (!all)
        {
            cout << "NO Blocked Contact" << endl;
        }
        cout << "********************************" << endl;
        cout << endl;

    }
    void displaynotification()
    {

        if (!login)
        {
            return;
        }
        login->notification.display();
    }
    void deletenotification()
    {

        if (!login)
        {
            return;
        }
        if (!login->notification.empty()) 
        {
            cout << "Press Y to Delete all notification or Press P to delete First notification" << endl;
            char c;
            cin >> c;
            if (c == 'Y' || c == 'y')
            {
                if (!login->notification.empty())
                {
                    login->notification.~questruct();
                    cout << "All Notifications deleted" << endl;
                }
                else
                {
                    cout << "List is Empty" << endl;
                }
            }
            else if (c == 'p' || c == 'P')
            {
                if (!login->notification.empty()) {
                    login->notification.deque();
                    cout << "Notification deleted" << endl;

                }
                else
                {
                    cout << "List is Empty" << endl;
                }

            }
            else
            {
                cout << "invalid input";
            }
        }
        else
        {
            cout << "NO notification in queue" << endl;
        }
    }
    void updateprofile()
    {
        if (!login)
        {
           return;
        }
        string n, c, p, s;
        string old = login->no->name;
        bool flag;
        do
        {
            flag = true;
            cout << "Enter A new Name: ";
            cin.ignore();
            getline(cin, n);
            for (int i = 0; i < count; i++)
            {
                if (list[i]->no->name == n)
                {
                    cout << "Account already exists with this name! Enter a unique name" << endl;
                    flag = false;
                    break;
                }
            }
        } while (!flag);
        b.update(old, n);
        do
        {
            flag = true;
            cout << "Enter Your City: ";
            getline(cin, c);
            if (c == "")
            {
                flag = false;
            }
        } while (!flag);
        do
        {
            flag = true;
            cout << "Enter new Password: ";
            getline(cin, p);
            for (int i = 0; i < count; i++)
            {
                if (list[i]->no->Password == p)
                {
                    cout << "Account already exists with this password! Enter a unique password" << endl;
                    flag = false;
                    break;
                }
            }
        } while (!flag);
        do
        {
            flag = true;
            cout << "Enter A new Security Answer " << endl;
            cout << "What is Your Favorite Dish? " << endl;
            getline(cin, s);
            for (int i = 0; i < count; i++)
            {
                if (list[i]->no->security == s)
                {
                    cout << "Account already exists with this security answer! Enter a unique answer" << endl;
                    flag = false;
                    break;
                }
            }
        } while (!flag);
        login->no->City = c;
        login->no->name= n;
        login->no->Password = p;
        login->no->security= s;
    }
    void sendmessage()
    {
        stackstruct* rec = nullptr;
        if (!login)
        {
            return;
        }
        string s, m, t;
        m = login->no->name;
        m += ": ";
        cin.ignore();
        cout << "Enter name of a person you want to send a message" << endl;
        getline(cin, s);
        int k = index(s);
        if (k != -1)
        {
            bool mine = false;
            bool him = false;
            users* temp = login->next;
            while (temp)
            {
                if (temp && temp->no->name == s && temp->ed.status == "Blocked")
                {
                    cout << s << "Blocked You so you cannt send message to " << s << endl;
                    return;
                }
                if (temp && temp->no->name == s && temp->ed.status == "Active")
                {
                    mine = true;
                }
                temp = temp->next;
            }
            temp = list[k]->next;
            while (temp)
            {
                if (temp && temp->no->name == login->no->name && temp->ed.status == "Blocked")
                {
                    cout <<" You Blocked "<<list[k]->no->name<<" so you cannt send message " << endl;
                    return;
                }
                if (temp && temp->no->name == login->no->name && temp->ed.status == "Active")
                {
                    him = true;
                }
                temp = temp->next;
            }
            if (mine && him)
            {
                temp = list[k]->next;
                while (temp)
                {
                    if (temp && temp->no->name == login->no->name && temp->ed.status == "Active" && temp->ed.mess == nullptr)
                    {
                        temp->ed.mess = new stackstruct();
                        rec = temp->ed.mess;
                    }
                    temp = temp->next;
                }
                temp = login->next;
                while (temp)
                {
                    if (temp && temp->no->name == s && temp->ed.status == "Active" && temp->ed.mess == nullptr)
                    {
                        temp->ed.mess = rec;
                    }
                    temp = temp->next;
                }
                cout << "Enter a message that you want to send" << endl;
                getline(cin, t);
                m += t;
                string o = login->no->name;
                temp = login->next;
                while (temp && temp->no->name != s)
                {
                    temp = temp->next;
                }
                if (temp)
                {
                    temp->ed.mess->insert(m);
                    cout << "Message send" << endl;
                }
                o += " send a message to you";
                temp = list[k];
                if (temp)
                {
                    temp->notification.enque(o);
                }
                if (list[k]) 
                {
                    temp = list[k]->next;
                }
                while (temp && temp->no->name!=login->no->name)
                {
                    temp = temp->next;
                }
                if (temp)
                {
                    temp->ed.realtime.enque(m);
                    cout << "Enque in real time " << endl;
                }
            }

            else
            {
                cout << s << " is not your friend." << " So You cannot send message to " << s << endl;
                return;
            }
        }
        else
        {
            cout << "User not Found" << endl;
        }
    }
    void displaymessage()
    {

        if (!login)
        {
            return;
        }
        string n;
        cout << "Enter name of person for display your chat with him" << endl;
        cin.ignore();
        getline(cin, n);
        int k = index(n);
        if (k != -1) {
            users* temp = login->next;
            while (temp && temp->no->name != n)
            {
                temp = temp->next;
            }
            if (temp && temp->ed.mess)
            {
                if (!temp->ed.mess->empty())
                {
                    cout << "Press Y to Display all chat or Press P to display Top message" << endl;
                    char c;
                    cin >> c;
                    if (c == 'Y' || c == 'y')
                    {
                        temp->ed.mess->display();
                        if (!temp->ed.realtime.empty())
                        {
                           temp->ed.realtime.~questruct();
                            cout << "message deque" << endl;
                        }
                    }
                    else if (c == 'p' || c == 'P')
                    {
                        temp->ed.mess->peek();

                        if (!temp->ed.realtime.empty())
                        {
                            string k = temp->ed.realtime.deque();
                            cout << "message deque from real time" << endl;
                        }
                    }
                    else
                    {
                        cout << "invalid input";
                    }
                }
                else
                {
                    cout << "No chat avialable" << endl;
                }
            }
            else
            {
                cout << n << " is not your friend" << endl;
            }
        }
        else
        {
            cout<<"user nor found" << endl;
        }
    }
    void deletemessage()
    {
        users* temp = login->next;
        if (!login)
        {
            return;
        }
        string n;
        cout << "Enter name of person for delete your chat with him" << endl;
        cin.ignore();
        getline(cin, n);
        int k = index(n);
        if (k != -1) {
            cout << "Press Y to Delete all message  or Press P to delete Top message" << endl;
            char c;
            cin >> c;
            if (c == 'Y' || c == 'y')
            {
                while (temp && temp->no->name != n)
                {
                    temp = temp->next;
                }
                if (temp && temp->ed.mess)
                {
                    if (!temp->ed.mess->empty()) {
                        temp->ed.mess->~stackstruct();
                    }
                    else
                    {
                        cout << "No chat available" << endl;
                    }
                }
                else
                {
                    cout << n<<" Is not your friend" << endl;

                }
            }
            else if (c == 'p' || c == 'P')
            {
                while (temp && temp->no->name != n)
                {
                    temp = temp->next;
                }
                if (temp && temp->ed.mess)
                {

                    if (!temp->ed.mess->empty())
                    {
                        temp->ed.mess->pop();
                    }
                    else
                    {
                        cout << "No chat available" << endl;
                    }

                }
                else
                {
                    cout << n << " Is not your friend" << endl;

                }
            }
            else
            {
                cout << "invalid input";
            }
        }
        else
        {
            cout << "user not found" << endl;
        }
    }
    void addpost()
    {
        if (!login)
        {
            return;
        }
        else
        {
            string s;
            cout << "Enter post content " << endl;
            cin.ignore();
            getline(cin, s);
            login->no->post.context = s;
            login->no->post.name = login->no->name;
            time_t now = time(0);
            string t = ctime(&now);
            login->no->post.date_time = t;
            login->myfeed.insert(login->no->post);
            users* temp = login->next;
            if (!temp)
            {
                return;
            }
            else
            {
                while (temp)
                {
                    for (int i = 0; i < count; i++)
                    {
                        if (temp->no->name == list[i]->no->name && temp->ed.status == "Active")
                        {
                            list[i]->folwrpost.insert(login->no->post);
                            string o = login->no->name;
                            o += " Added a Post";
                            list[i]->notification.enque(o);
                        }
                    }
                    temp = temp->next;
                }
            }

        }
    }
    void newfeed()
    {
        if (!login)
        {
            return;
        }

        else
        {
            login->myfeed.display();

        }
    }
    void displaypost()
    {
        if (!login)
        {
            return;
        }
        else
        {
            login->folwrpost.display();
        }
    
    }
    void deletepost()
    {
        if (!login)
        {
            return;
        }
        else
        {
            char p;
            cout << "Enter m for delete your own post " << endl;
            cin >> p;
            if (p == 'M' || p == 'm') 
            {
                cout << "Press Y to Delete all Post or Press P to delete Top Post" << endl;
                char c;
                cin >> c;
                
                if (c == 'Y' || c == 'y')
                {
                    if (!login->myfeed.empty())
                    {
                        login->myfeed.~poststack();
                    }
                    else
                    {
                        cout << "No Post Available" << endl;
                    }
                }
                else if (c == 'p' || c == 'P')
                {
                    if (!login->myfeed.empty()) 
                    {
                        login->myfeed.pop();
                    }

                   else
                   {
                    cout << "No Post Available" << endl;
                   }
                }
                else
                {
                    cout << "invalid input";
                }
            }
            
            else
            {
                cout << "invalid input";
            }
        }
    }
    void stringsugg(string n)
    {
        if (!login || login->sc < 0)
        {
            return;
        }
        string* newlist = new string[login->sc + 1];
        for (int i = 0; i <= login->sc; i++)
        {
            newlist[i] = "";
        }
        for (int i = 0; i < login->sc; i++)
        {
            newlist[i] = login->sugg[i];
        }
        newlist[login->sc] = n;
        login->sc++;
        delete[] login->sugg;
        login->sugg = newlist;
    }
    bool compare(string n)
    {
        if (!login)
        {
            return false;
        }
        if (login->sc == 0 || login->sugg == nullptr)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < login->sc; i++)
            {
                if (login->sugg[i] == n)
                {
                    return true;
                }
            }
        }
        return false;
    }

    void suggestion()
    {
        if (!login)
        {
            return;
        }
        users* temp = login->next;
        while (temp)
        {
            users* rec = nullptr;
            for (int i = 0; i < count; i++)
            {
                if (list[i]->no->name == temp->no->name)
                {
                    rec = list[i]->next;

                }
            }
            while (rec)
            {
                users* ano = login->next;
                bool flag = false;
                while (ano)
                {
                    if (rec->no->name == ano->no->name)
                    {
                        flag = true;
                    }
                    ano = ano->next;
                }
                bool klp = compare(rec->no->name);
                if (!klp && !flag && rec->no->name != login->no->name)
                {
                    stringsugg(rec->no->name);
                }
                rec = rec->next;
            }
            temp = temp->next;
        }
    }
    void displaysuggesstion()
    {
        if (!login)
        {
            return;
        }
        suggestion();
        if (login->sc==0)
        {
            cout << "List are empty" << endl;
            return;
        }
        cout << "suggestion list are" << endl;
        for (int i = 0; i < login->sc; i++)
        {
           cout<< login->sugg[i] << endl;
        }
        login->sc = 0;
        login->sugg = nullptr;
    }
};

void intro()
{
    cout << "\n\n\n";
    cout << " \t\t\tL      OOOOO  AAAAA  DDDD   III  N   N  GGGGG  " << endl;
    cout << " \t\t\tL      O   O  A   A  D   D   I   NN  N  G      " << endl;
    cout << " \t\t\tL      O   O  AAAAA  D   D   I   N N N  G  GG  " << endl;
    cout << " \t\t\tL      O   O  A   A  D   D   I   N  NN  G   G  " << endl;
    cout << " \t\t\tLLLLL  OOOOO  A   A  DDDD   III  N   N  GGGGG  " << endl;
    cout << "\t\t";
    for (int i = 0; i < 60; i++)
    {
        {
            Sleep(50);
            cout << "\033[1;32m" << "." << "\033[0m";
        }
    }
    Sleep(1500);
    system("cls");

    cout << endl; cout << "\n\n";
    cout << "W     W  EEEEE   L       CCCCC  OOOOO  M   M  EEEEE       TTTTT  OOOOO     M   M  I  N   N  I     I N   N  SSSSS  TTTTT  AAAAA  GGGGG  RRRRR  AAAAA  M   M" << endl;
    cout << "W     W  E       L      C       O   O  MM MM  E             T    O   O     MM MM  I  NN  N  I     I NN  N  S        T    A   A  G      R   R  A   A  MM MM" << endl;
    cout << "W  W  W  EEEE    L      C       O   O  M M M  EEEE          T    O   O     M M M  I  N N N  I     I N N N  SSS      T    AAAAA  G  GG  RRRR   AAAAA  M M M" << endl;
    cout << " W W W   E       L      C       O   O  M   M  E             T    O   O     M   M  I  N  NN  I     I N  NN      S    T    A   A  G   G  R  R   A   A  M   M" << endl;
    cout << "  W W    EEEEE   LLLLL   CCCCC  OOOOO  M   M  EEEEE         T    OOOOO     M   M  I  N   N  I     I N   N  SSSSS    T    A   A  GGGGG  R   R  A   A  M   M" << endl;
    Sleep(1500);
    system("cls");

    cout << endl;
    cout << " DDDDD   EEEEE  SSSSS  III  GGGGG  N   N  EEEEE  DDDDD     BBBBB   Y   Y   :::" << endl;
    cout << " D   D   E      S       I   G      NN  N  E      D   D     B   B    Y Y    :::" << endl;
    cout << " D   D   EEEE   SSSSS   I   G  GG  N N N  EEEE   D   D     BBBBB     Y        " << endl;
    cout << " D   D   E          S   I   G   G  N  NN  E      D   D     B   B    Y      :::" << endl;
    cout << " DDDDD   EEEEE  SSSSS  III  GGGGG  N   N  EEEEE  DDDDD     BBBBB   Y       ::: " << endl;
    cout << endl;
    cout << " SSSSS  H   H   AAAAA  H   H   ZZZZZ   AAAAA  III  N   N" << endl;
    cout << " S      H   H   A   A  H   H      Z    A   A   I   NN  N" << endl;
    cout << " SSSSS  HHHHH   AAAAA  HHHHH     Z     AAAAA   I   N N N" << endl;
    cout << "     S  H   H   A   A  H   H    Z      A   A   I   N  NN" << endl;
    cout << " SSSSS  H   H   A   A  H   H   ZZZZZ   A   A  III  N   N" << endl;
    cout << endl;
    cout << " ZZZZZ  EEEEE  SSSSS  H   H   AAAAA  N   N" << endl;
    cout << "    Z   E      S      H   H   A   A  NN  N" << endl;
    cout << "   Z    EEEE   SSSSS  HHHHH   AAAAA  N N N" << endl;
    cout << "  Z     E          S  H   H   A   A  N  NN" << endl;
    cout << " ZZZZZ  EEEEE  SSSSS  H   H   A   A  N   N" << endl;
    cout << "\n\n";
}
void menu(graph g)
{
    cout << "Press Enter to View Menu" << endl;
    char c = _getch();
    if (c == 13)
    {
        int choice=0;
        bool running = true;
        while (running)
        {
            system("cls");
            cout << "--- Menu ---" << endl;
            cout << "1.  Send Friend Request" << endl;
            cout << "2.  Accept Friend Request" << endl;
            cout << "3.  Decline Friend Request" << endl;
            cout << "4.  View Friend Request" << endl;
            cout << "5.  Blocked any Follower" << endl;
            cout << "6.  Display Account Details" << endl;
            cout << "7.  Edit Profile Details" << endl;
            cout << "8.  Check Notifications" << endl;
            cout << "9.  Delete Notifications" << endl;
            cout << "10. Send message" << endl;
            cout << "11. View Message" << endl;
            cout << "12. Delete Message" << endl;
            cout << "13. Add Post" << endl;
            cout << "14. View Follower Post" << endl;
            cout << "15. NewsFeed" << endl;
            cout << "16. Delete Post" << endl;
            cout << "17. Search user" << endl;
            cout << "18. Suggestions  " << endl;
            cout << "19. Logout" << endl;
            cout << "Enter your choice: ";
            while (!(cin >> choice))
            {
                cin.clear();
                cin.ignore();
                cout << "Invalid Input! Please Enter Integer" << endl;
            }
            system("cls");
            switch (choice)
            {
            case 1:
                g.sendreq();
                system("pause");
                break;
            case 2:
                g.acceptreq();
                system("pause");
                break;
            case 3:
                g.declinereq();
                system("pause");
                break;
            case 4:
                g.viewreq();
                system("pause");
                break;
            case 5:
                g.blocked();
                system("pause");
                break;
            case 6:
                g.display();
                system("pause");
                break;
            case 7:
                g.updateprofile();
                system("pause");
                break;
            case 8:
                g.displaynotification();
                system("pause");
                break;
            case 9:
                g.deletenotification();
                system("pause");
                break;
            case 10:
                g.sendmessage();
                system("pause");
                break;
            case 11:
                g.displaymessage();
                system("pause");
                break;
            case 12:
                g.deletemessage();
                system("pause");
                break;
            case 13:
                g.addpost();
                system("pause");
                break;
            case 14:
                g.displaypost();
                system("pause");
                break;
            case 15:
                g.newfeed();
                system("pause");
                break;
            case 16:
                g.deletepost();
                system("pause");
                break;
            case 17:
                g.b.se();
                system("pause");
                break;
            case 18:
                g.displaysuggesstion();
                system("pause");
                break;
            case 19:
                g.logout();
                running = false;
                break;
            default:
                cout << "Invalid choice! Please try again" << endl;
            }
        }
    }
}
int main()
{
    intro();
    Sleep(1000);
    cout << "Press Enter to View Menu" << endl;
    char c=_getch();
    if(c==13)
    {
        graph g;
        bool exit = true;
        do 
        {
            system("cls");
            cout << "1.  Signup" << endl;
            cout << "2.  Login" << endl;
            cout << "3.  Exit " << endl;
            bool flag;
            int choice=0;
            while (!(cin >> choice))
            {
                cin.clear();
                cin.ignore();
                cout << "Invalid Input! Please Enter Integer" << endl;
            }
            switch (choice)
            {
            case 1:
                system("cls");
                flag = g.signup();
                system("pause");
                break;
            case 2:
                system("cls");
                flag = g.loggedin();
                if (!flag)
                {
                    cout << "Your account has not logged in." << endl;
                }
                else
                {
                    cout << "Your account has successfully logged in." << endl;
                    menu(g);
                }
                system("pause");
                break;
            case 3:
                exit = false;
                break;
            default:
                cout << "Invalid Input" << endl;
                break;
            }
        } while (exit);
    }
    system("pause");
    return 0;
}