#include<bits/stdc++.h>
using namespace std;
int Hash(string s)
{
    int sum=0;
    for(int i=0; i<s.length(); i++)
        sum=sum+s[i];
    return sum;
}
class SymbolInfo
{
private:
    string type;
    string name;
    SymbolInfo* next;
    int x,y;
public:
    SymbolInfo();
    SymbolInfo(string,string);
    string get_type();
    void set_type(string);
    string get_name();
    void set_name(string);
    SymbolInfo* get_next();
    void set_next(SymbolInfo*);
    void printSymbol();
    ~SymbolInfo();
};
SymbolInfo::SymbolInfo()
{
    type="";
    name="";
    next=NULL;
}
SymbolInfo::SymbolInfo(string t,string n)
{
    type=t;
    name=n;
}
string SymbolInfo::get_type()
{
    return type;
}
string SymbolInfo::get_name()
{
    return name;
}
void SymbolInfo::set_type(string t)
{
    type=t;
}
void SymbolInfo::set_name(string n)
{
    name=n;
}
SymbolInfo* SymbolInfo::get_next()
{
    return this->next;
}
void SymbolInfo::set_next(SymbolInfo *n)
{
    next=n;
}
void SymbolInfo::printSymbol()
{
    cout<<"< "<<name<<" : "<<type<<"> ";
}

SymbolInfo::~SymbolInfo()
{
    //delete next;
    type.clear();
    name.clear();

}

class ScopeTable
{
private:

    SymbolInfo** table;
    ScopeTable* parentScope;
    string id;
    int n;
public:
    ScopeTable(int);
    bool insertSymbol(string,string);
    bool deleteSymbol(string);
    SymbolInfo* lookupSymbol(string);
    void printScopeTable();
    void set_id(string);
    string get_id();
    void set_parent(ScopeTable*);
    ScopeTable* get_parent();
    ~ScopeTable();
};
ScopeTable::ScopeTable(int n)
{
    this->n=n;
    parentScope=NULL;
    table = new SymbolInfo*[n];
    for(int i=0; i<n; i++)
        table[i]=NULL;
}
void ScopeTable::set_id(string id)
{
    if(parentScope!=NULL)
        this->id=parentScope->get_id()+"."+id;
    else
        this->id=id;
}
string ScopeTable::get_id()
{
    return this->id;
}
void ScopeTable::set_parent(ScopeTable* s)
{
    parentScope=s;
}
ScopeTable* ScopeTable::get_parent()
{
    return parentScope;
}
bool ScopeTable::insertSymbol(string typ,string name)
{
    int index=Hash(name)%n;
    SymbolInfo* temp;
    SymbolInfo *prev=NULL;
    temp=table[index];
    int pos=0;
    if(temp==NULL)
    {
        //cout<<"Inserted in ScopeTable# "<<this->id;
        SymbolInfo* s=new SymbolInfo();
        s->set_name(name);
        s->set_type(typ);
        table[index]=s;
        //cout<<" at position "<<index<<", "<<pos<<endl;
        return true;
    }
    while(temp!=NULL)
    {
        pos++;
        if(name==temp->get_name())
        {
            //temp->printSymbol();
            //cout<<name<<" already exists in current ScopeTable"<<endl;
            return false;
        }
        prev=temp;
        temp=temp->get_next();
    }


    //cout<<"Inserted in ScopeTable# "<<this->id;
    SymbolInfo* s=new SymbolInfo();
    s->set_name(name);
    s->set_type(typ);
    prev->set_next(s);
    //cout<<" at position "<<index<<", "<<pos<<endl;
    return true;
}

SymbolInfo* ScopeTable::lookupSymbol(string name)
{
    int index=Hash(name)%n;
    SymbolInfo* temp;
    temp=table[index];
    int pos=0;
    while(temp!=NULL)
    {
        if(name==temp->get_name())
        {
            //cout<<"Found in ScopeTable# "<<this->get_id()<<" at position "<<index<<", "<<pos<<endl;
            return temp;
        }
        pos++;
        temp=temp->get_next();

    }

    return NULL;

}
bool ScopeTable::deleteSymbol(string name)
{
    int index=Hash(name)%n;
    SymbolInfo* temp=lookupSymbol(name);

    int pos=0;
    if(temp==NULL)
    {
        cout<<"Not Found"<<endl;
        return false;
    }

    else
    {
        temp=table[index];
        if(name==temp->get_name())
        {

            table[index]=temp->get_next();
            cout<<"Deleted Entry "<<index<<", "<<pos;
            delete temp;
            return true;
        }

        while(temp->get_next()!=NULL)
        {
            if(name==temp->get_next()->get_name())
            {
                pos++;
                SymbolInfo* next=temp->get_next();
                temp->set_next(next->get_next());
                cout<<"Deleted Entry "<<index<<", "<<pos;
                delete next;
                return true;
            }
            temp=temp->get_next();
        }
    }
    return true;
}
void ScopeTable::printScopeTable()
{
    cout<<"ScopeTable # "<<id<<endl;
    for(int i=0; i<n; i++)
    {

        SymbolInfo* temp=table[i];
        if(temp!=NULL)
        {
        cout<<" "<<i<<" --> ";
        while(temp!=NULL)
        {
            temp->printSymbol();
            temp=temp->get_next();
        }
        cout<<endl;

    }
    }
}

ScopeTable::~ScopeTable()
{
    for(int i=0; i<n; i++)
    {
        SymbolInfo* temp = table[i];
        SymbolInfo* next = NULL;

        while (temp != NULL)
        {
            next = temp->get_next();
            delete temp;
            temp = next;
        }
    }
    delete [] table;
    id.clear();

}
class SymbolTable
{
private:
    ScopeTable* current;
    int pos;
    int n;
    bool ex;
    //string curr_id;
public:
    SymbolTable(int);
    void enterScope();
    void exitScope();
    bool insert_symbol(string,string);
    bool remove_symbol(string);
    SymbolInfo* lookup_symbol(string);
    void print_current();
    void print_all();
    ~SymbolTable();


};
SymbolTable::SymbolTable(int n)
{
    this->n=n;
    pos=0;
    ex=false;
    current=new ScopeTable(n);
    current->set_id("1");
}
void SymbolTable::enterScope()
{
    pos++;
    ostringstream str1;
    str1 << pos;
    ScopeTable* sc=new ScopeTable(n);
    sc->set_parent(current);
    if(ex)
        sc->set_id(str1.str());
    else
        sc->set_id("1");
    current=sc;
    //cout<<"New ScopeTable with id "<<current->get_id()<<" created"<<endl;
    ex=false;

}
void SymbolTable::exitScope()
{
    //int sum=0;
    if(current->get_parent()==NULL)
    {
        cout<<"Can't exit."<<endl;
        return;
    }
    //cout<<"ScopeTable with id "<<current->get_id()<<" removed"<<endl;
    string id=current->get_id();
    string p;
    for(int i=id.length()-1; i>=0; i--)
    {
        if(id.at(i)=='.')
            break;
        p.push_back(id.at(i)) ;
    }
    reverse(p.begin(),p.end());
    pos=stoi(p);
    ex=true;
    ScopeTable* temp=current;
    current=current->get_parent();
    delete temp;


}

bool SymbolTable::insert_symbol(string typ, string name)
{
    if(current->insertSymbol(typ,name))
        return true;
    else
        return false;
}
bool SymbolTable::remove_symbol(string name)
{
    if(current->deleteSymbol(name))
    {
        cout<<" from current ScopeTable"<<endl;
        return true;
    }

    else
    {
        cout<<name<<" not found"<<endl;
        return false;
    }

}
SymbolInfo* SymbolTable::lookup_symbol(string name)
{
    ScopeTable* temp=current;
    while(temp!=NULL)
    {
        SymbolInfo* si=temp->lookupSymbol(name);
        if(si!=NULL)
        {
            return si;
        }

        temp=temp->get_parent();
    }
    cout<<"Not found"<<endl;
    return NULL;
}
void SymbolTable::print_current()
{
    current->printScopeTable();

}
void SymbolTable::print_all()
{
    ScopeTable* temp=current;
    while(temp!=NULL)
    {
        temp->printScopeTable();
        cout<<endl;
        temp=temp->get_parent();
    }
}
SymbolTable::~SymbolTable()
{
    //delete current;
    ScopeTable* temp=current;
    ScopeTable* p;
    while(temp->get_parent()!=NULL)
    {
        p=temp->get_parent();
        delete temp;
        temp=p;
    }
    delete temp;
    delete p;

}
/*
int main()
{
    ifstream file;
    // FILE *file2;
    file.open("input0.txt");
    //freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    int n;
    file>>n;

    SymbolTable* st=new SymbolTable(n);
    while(!file.eof())
    {
        char ch;
        file>>ch;
        if(ch=='I')
        {
            string typ,name;
            file>>name>>typ;
            cout<<ch<<" "<<name<<" "<<typ<<endl;
            cout<<endl;
            st->insert_symbol(typ,name);
            cout<<endl;

        }
        else if(ch=='D')
        {
            string name;
            file>>name;
            cout<<ch<<" "<<name<<endl;
            cout<<endl;
            st->remove_symbol(name);
            cout<<endl;
        }
        else if(ch=='L')
        {
            string name;
            file>>name;
            cout<<ch<<" "<<name<<endl;
            cout<<endl;
            st->lookup_symbol(name);
            cout<<endl;
        }
        else if(ch=='S')
        {
            cout<<ch<<endl;
            st->enterScope();
            cout<<endl;
        }
        else if(ch=='E')
        {
            cout<<ch<<endl;
            cout<<endl;
            st->exitScope();
            cout<<endl;
        }
        else if(ch=='P')
        {
            char ch1;
            file>>ch1;
            if(ch1=='A')
            {
                cout<<ch<<" "<<ch1<<endl;
                cout<<endl;
                st->print_all();
                cout<<endl;
            }

            else if(ch1=='C')
            {
                cout<<ch<<" "<<ch1<<endl;
                cout<<endl;
                st->print_current();
                cout<<endl;

            }

            else
                cout<<" Command NOT found"<<endl;
        }

        else
            cout<<" Command NOT found"<<endl;


    }

}
*/
