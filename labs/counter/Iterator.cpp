// Counter::Iterator Member Functions
	Counter::Iterator::Iterator(Node* c){
		current = c;
		if(current != nullptr){
		k = current->key;
		v = current->value;
		}
		else{
		k = "";
		v = 0;
		}
	}

    const std::string& Counter::Iterator::key() const{
    	return k;
    }
    int Counter::Iterator::value() const{
    	return v;
    }

    void Counter::Iterator::operator ++ (){
		current = current->next;
		if(current != nullptr){
		k = current->key;
		v = current->value;
		}
		else{
		k = "";
		v = 0;
		}
    }
    bool Counter::Iterator::operator == (const Counter::Iterator& other) const{
    	return current == other.current;
    }
    bool Counter::Iterator::operator != (const Counter::Iterator& other) const{
    	return current != other.current;
    }

