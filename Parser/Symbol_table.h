#include<bits/stdc++.h>
using namespace std;
class param
{
private:
string p_type;
string p_name;
public:
 param(string t,string n)
{
    p_type=t;
    p_name=n;
}
string get_ptype()
{
    return p_type;
}
string get_pname()
{
    return p_name;
}
~param()
{
    //delete next;
    p_type.clear();
    p_name.clear();

} 
};
class SymbolInfo
{
private:
    string type;
    string name;
    SymbolInfo* next;
    string data_type;
    int size;
    vector<param*> param_list;
    
public:
SymbolInfo()
{
    type="";
    name="";
    next=NULL;
    
    data_type="";
}
SymbolInfo(string t,string n)
{
    type=n;
    name=t;
    size=-1;
    next=NULL;
    
    data_type="";
    
}
SymbolInfo(string t,string n,string d)
{
    type=n;
    name=t;
    size=-1;
    data_type=d;
    next=NULL;
    
    
}
SymbolInfo(string t,string n,string d,int s)
{
    type=n;
    name=t;
    size=s;
    data_type=d;
    next=NULL;
    
    
}
string get_type()
{
    return type;
}
string get_name()
{
    return name;
}
void set_type(string t)
{
    type=t;
}
string get_dType()
{
   return data_type;
}
void set_name(string n)
{
    name=n;
    return;
}
void set_dType(string n)
{
    data_type=n;
    return;
}
SymbolInfo* get_next()
{
    return this->next;
}
void set_next(SymbolInfo *n)
{
    next=n;
}
void printSymbol()
{
    cout<<"< "<<name<<" : "<<type<<"> ";
}
int get_varSize()
{
 	return size;
}
void set_varSize(int n)
{
    size=n;
    return;
}
void addParam(string param_type, string param_name) {
        param* p=new param(param_type,param_name);
        param_list.push_back(p);
        return ;
        }
 param* getParam(int index) const {
        return param_list[index];
    }
 int get_listSize() {
        /* basically for function */
        return param_list.size();
    }
~SymbolInfo()
{
    //delete next;
    type.clear();
    name.clear();
    data_type.clear();
    param_list.clear();

} 
};

class ScopeTable
{
private:

    SymbolInfo** table;
    ScopeTable* parentScope;
    string id;
    int n;
public:
 int Hash(string s)
{
    int sum=0;
    for(int i=0; i<s.length(); i++)
        sum=sum+s[i];
    return sum;
}
ScopeTable(int n)
{
    this->n=n;
    parentScope=NULL;
    table = new SymbolInfo*[n];
    for(int i=0; i<n; i++)
        table[i]=NULL;
}
void set_id(string id)
{
    if(parentScope!=NULL)
        this->id=parentScope->get_id()+"."+id;
    else
        this->id=id;
}
string get_id()
{
    return this->id;
}
void set_parent(ScopeTable* s)
{
    parentScope=s;
}
ScopeTable* get_parent()
{
    return parentScope;
}
bool insertSymbol(SymbolInfo* s)
{
    int index=Hash(s->get_name())%n;
    SymbolInfo* temp;
    SymbolInfo *prev=NULL;
    temp=table[index];
    int pos=0;
    if(temp==NULL)
    {
        //cout<<"Inserted in ScopeTable# "<<this->id;
        table[index]=s;
        //cout<<" at position "<<index<<", "<<pos<<endl;
        return true;
    }
    while(temp!=NULL)
    {
        pos++;
        if(s->get_name()==temp->get_name())
        {
            //temp->printSymbol();
            //cout<<name<<" already exists in current ScopeTable"<<endl;
            return false;
        }
        prev=temp;
        temp=temp->get_next();
    }


    //cout<<"Inserted in ScopeTable# "<<this->id;
    prev->set_next(s);
    //cout<<" at position "<<index<<", "<<pos<<endl;
    return true;
}

SymbolInfo* lookupSymbol(string name)
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
bool deleteSymbol(string name)
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
void printScopeTable()
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

~ScopeTable()
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
};

class SymbolTable
{
private:
    ScopeTable* current;
    int pos;
    int n;
    bool ex;
    //string curr_id;
public:
    
SymbolTable(int n)
{
    this->n=n;
    pos=0;
    ex=false;
    current=new ScopeTable(n);
    current->set_id("1");
}
void enterScope()
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
    return;

}
void exitScope()
{
    //int sum=0;
    if(current->get_parent()==NULL)
    {
        cout<<"Can't exit."<<endl;
        return;
    }
    cout<<"ScopeTable with id "<<current->get_id()<<" removed"<<endl;
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
    return;


}

bool insert_symbol(SymbolInfo* s)
{
    if(current->insertSymbol(s))
        return true;
    else
        return false;
}
bool remove_symbol(string name)
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
SymbolInfo* lookup_symbol(string name)
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
    //cout<<"Not found"<<endl;
    return NULL;
}
void print_current()
{
    current->printScopeTable();

}
void print_all()
{
    ScopeTable* temp=current;
    while(temp!=NULL)
    {
        temp->printScopeTable();
        cout<<endl;
        temp=temp->get_parent();
    }
}
~SymbolTable()
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

};

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
