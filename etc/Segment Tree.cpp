#define MAXN 100007
#define ls l, m, rt << 1
#define rs m + 1, r, rt << 1 | 1  // "<<1|1" <=> "/2+1"

int Sum[MAXN << 2], Add[MAXN << 2];
int A[MAXN], n;

void PushUp(int rt) { Sum[rt] = Sum[rt << 1] + Sum[rt << 1 | 1]; }

void Build(int l, int r, int rt) {
  // l,r当前节点表示的区间, rt当前节点编号
  if (l == r) {
    Sum[rt] = A[l];
    return;
  }
  int m = (l + r) >> 1;
  Build(l, m, rt << 1);
  Build(m + 1, r, rt << 1 | 1);
  PushUp(rt);
}

void Update(int L, int C, int l, int r, int rt) {
  // A[L]+=C
  if (l == r) {
    Sum[rt] += C;
    return;
  }
  int m = (l + r) >> 1;
  if (L <= m) {
    Update(L, C, l, m, rt << 1);
  } else {
    Update(L, C, m + 1, r, rt << 1 | 1);
  }
  PushUp(rt);
}

void PushDown(int rt, int ln, int rn) {
  // ln, rn 左子树，右子树的数字数量
  if (Add[rt]) {
    Add[rt << 1] += Add[rt];
    Add[rt << 1 | 1] += Add[rt];
    Sum[rt << 1] += Add[rt] * ln;
    Sum[rt << 1 | 1] += Add[rt] * rn;
    Add[rt] = 0;
  }
}

int Query(int L, int R, int l, int r, int rt) {
  // L, R表示操作区间， l，r表示当前区间，rt节点编号
  if (L <= l && r <= R) {
    return Sum[rt];
  }
  int m = (l + r) >> 1;
  PushDown(rt, m - l + 1, r - m);

  int ANS = 0;
  if (L <= m) ANS += Query(L, R, l, m, rt << 1);
  if (R >= m) ANS += Query(L, R, m + 1, r, rt << 1 | 1);
  return ANS;
}
