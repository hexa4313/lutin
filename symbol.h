class Symbol {
  protected:
    int ident;
  public:
    Symbol(int id) : ident(id) {}
    virtual ~Symbol() {}
    void print();
    operator int() const { return ident; }
};
