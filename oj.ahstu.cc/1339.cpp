struct gird {
  int x, y;
};
struct Knight {
  Knight(int m, int n);
  ~Knight() {};
  void out();
  int m, n;
  grid *b66, *b68, *b88, *b810, *b108, *b1010, *b1012, *b1210, **link;
  int pos(int x, int y, int col);
  void step(int m, int n, int **a, int **b);
  void build(int m, int n, int offx, int offy, int col, grid *b);
  void base(int mm, int nn, int offx, int offy);
  bool comp(int mm, int nn, int offx, int offy);
};
Knight::Knight(int mm, int nn) {
  int i, j, **a;
  m = mm, n = nn;
  b66 = new grid[36], b68 = new grid[48];
  b86 = new grid[48], b88 = new grid[64];
  b108 = new grid[80], b1010 = new grid[100];
  b1012 = new grid[120], b1210 = new grid[120];
  Make2DArray(link, m, n);
  Make2DArray(a, 10, 12);
}