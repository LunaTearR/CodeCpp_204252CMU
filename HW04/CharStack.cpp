class CharStack {

private:
  int counttop;
  int Max_stack;
  char chartop;
  char stackitem[];

public: 
  CharStack() { // constructor
    counttop = -1;
    Max_stack = 20;
    stackitem[Max_stack];
  }

  void push(char new_item) {
    counttop++;
    stackitem[counttop] = new_item;
  }

  char pop() {
    if (isEmpty()){
      return false;
    }
    else {
      chartop = stackitem[counttop];
      counttop--;
      return chartop;
    }
  }

  char top() {
    if (isEmpty()){
      return false;
    }
    else {
      chartop = stackitem[counttop];
      return chartop;
    }
  }

  bool isEmpty() const {
    return counttop < 0;
  }
};
