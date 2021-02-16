#include "sail.h"
#include "rts.h"
#include "elf.h"

// struct ut
struct zut {uint64_t zut_chunk_0;};

static void COPY(zut)(struct zut *rop, const struct zut op) {rop->zut_chunk_0 = op.zut_chunk_0;}

static bool EQUAL(zut)(struct zut op1, struct zut op2) {return EQUAL(fbits)(op1.zut_chunk_0, op2.zut_chunk_0);}

// enum uop
enum zuop { zLUI, zAUIPC };

static bool eq_zuop(enum zuop op1, enum zuop op2) { return op1 == op2; }

static enum zuop UNDEFINED(zuop)(unit u) { return zLUI; }

// struct st
struct zst {uint64_t zst_chunk_0;};

static void COPY(zst)(struct zst *rop, const struct zst op) {rop->zst_chunk_0 = op.zst_chunk_0;}

static bool EQUAL(zst)(struct zst op1, struct zst op2) {return EQUAL(fbits)(op1.zst_chunk_0, op2.zst_chunk_0);}

// enum sop
enum zsop { zSW };

static bool eq_zsop(enum zsop op1, enum zsop op2) { return op1 == op2; }

static enum zsop UNDEFINED(zsop)(unit u) { return zSW; }

// struct rt
struct zrt {uint64_t zrt_chunk_0;};

static void COPY(zrt)(struct zrt *rop, const struct zrt op) {rop->zrt_chunk_0 = op.zrt_chunk_0;}

static bool EQUAL(zrt)(struct zrt op1, struct zrt op2) {return EQUAL(fbits)(op1.zrt_chunk_0, op2.zrt_chunk_0);}

// enum rop
enum zrop { zADD, zAND, zOR, zXOR, zMUL, zDIV, zREM };

static bool eq_zrop(enum zrop op1, enum zrop op2) { return op1 == op2; }

static enum zrop UNDEFINED(zrop)(unit u) { return zADD; }

// struct jt
struct zjt {uint64_t zjt_chunk_0;};

static void COPY(zjt)(struct zjt *rop, const struct zjt op) {rop->zjt_chunk_0 = op.zjt_chunk_0;}

static bool EQUAL(zjt)(struct zjt op1, struct zjt op2) {return EQUAL(fbits)(op1.zjt_chunk_0, op2.zjt_chunk_0);}

// enum jop
enum zjop { zJAL };

static bool eq_zjop(enum zjop op1, enum zjop op2) { return op1 == op2; }

static enum zjop UNDEFINED(zjop)(unit u) { return zJAL; }

// struct it
struct zit {uint64_t zit_chunk_0;};

static void COPY(zit)(struct zit *rop, const struct zit op) {rop->zit_chunk_0 = op.zit_chunk_0;}

static bool EQUAL(zit)(struct zit op1, struct zit op2) {return EQUAL(fbits)(op1.zit_chunk_0, op2.zit_chunk_0);}

// enum iop
enum ziop { zADDI, zSLTI, zANDI, zORI, zXORI, zJALR, zLW };

static bool eq_ziop(enum ziop op1, enum ziop op2) { return op1 == op2; }

static enum ziop UNDEFINED(ziop)(unit u) { return zADDI; }

// struct bt
struct zbt {uint64_t zbt_chunk_0;};

static void COPY(zbt)(struct zbt *rop, const struct zbt op) {rop->zbt_chunk_0 = op.zbt_chunk_0;}

static bool EQUAL(zbt)(struct zbt op1, struct zbt op2) {return EQUAL(fbits)(op1.zbt_chunk_0, op2.zbt_chunk_0);}

// enum bop
enum zbop { zBEQ, zBNE };

static bool eq_zbop(enum zbop op1, enum zbop op2) { return op1 == op2; }

static enum zbop UNDEFINED(zbop)(unit u) { return zBEQ; }

// struct tuple_(%bv1, %bv10, %bv1, %bv8, %bv5, %enum zjop)
struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv8zCz0z5bv5zCz0z5enumz0zzjopz9 {
  uint64_t ztup0;
  uint64_t ztup1;
  uint64_t ztup2;
  uint64_t ztup3;
  uint64_t ztup4;
  enum zjop ztup5;
};

static void COPY(ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv8zCz0z5bv5zCz0z5enumz0zzjopz9)(struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv8zCz0z5bv5zCz0z5enumz0zzjopz9 *rop, const struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv8zCz0z5bv5zCz0z5enumz0zzjopz9 op) {
  rop->ztup0 = op.ztup0;
  rop->ztup1 = op.ztup1;
  rop->ztup2 = op.ztup2;
  rop->ztup3 = op.ztup3;
  rop->ztup4 = op.ztup4;
  rop->ztup5 = op.ztup5;
}

static bool EQUAL(ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv8zCz0z5bv5zCz0z5enumz0zzjopz9)(struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv8zCz0z5bv5zCz0z5enumz0zzjopz9 op1, struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv8zCz0z5bv5zCz0z5enumz0zzjopz9 op2) {
  return EQUAL(fbits)(op1.ztup0, op2.ztup0) && EQUAL(fbits)(op1.ztup1, op2.ztup1) && EQUAL(fbits)(op1.ztup2, op2.ztup2) && EQUAL(fbits)(op1.ztup3, op2.ztup3) && EQUAL(fbits)(op1.ztup4, op2.ztup4) && EQUAL(zjop)(op1.ztup5, op2.ztup5);
}


// struct tuple_(%bv1, %bv6, %bv5, %bv5, %bv4, %bv1, %enum zbop)
struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 {
  uint64_t ztup0;
  uint64_t ztup1;
  uint64_t ztup2;
  uint64_t ztup3;
  uint64_t ztup4;
  uint64_t ztup5;
  enum zbop ztup6;
};

static void COPY(ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9)(struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 *rop, const struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 op) {
  rop->ztup0 = op.ztup0;
  rop->ztup1 = op.ztup1;
  rop->ztup2 = op.ztup2;
  rop->ztup3 = op.ztup3;
  rop->ztup4 = op.ztup4;
  rop->ztup5 = op.ztup5;
  rop->ztup6 = op.ztup6;
}

static bool EQUAL(ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9)(struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 op1, struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 op2) {
  return EQUAL(fbits)(op1.ztup0, op2.ztup0) && EQUAL(fbits)(op1.ztup1, op2.ztup1) && EQUAL(fbits)(op1.ztup2, op2.ztup2) && EQUAL(fbits)(op1.ztup3, op2.ztup3) && EQUAL(fbits)(op1.ztup4, op2.ztup4) && EQUAL(fbits)(op1.ztup5, op2.ztup5) && EQUAL(zbop)(op1.ztup6, op2.ztup6);
}


// struct tuple_(%bv12, %bv5, %bv5, %enum ziop)
struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 {
  uint64_t ztup0;
  uint64_t ztup1;
  uint64_t ztup2;
  enum ziop ztup3;
};

static void COPY(ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9)(struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 *rop, const struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 op) {
  rop->ztup0 = op.ztup0;
  rop->ztup1 = op.ztup1;
  rop->ztup2 = op.ztup2;
  rop->ztup3 = op.ztup3;
}

static bool EQUAL(ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9)(struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 op1, struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 op2) {
  return EQUAL(fbits)(op1.ztup0, op2.ztup0) && EQUAL(fbits)(op1.ztup1, op2.ztup1) && EQUAL(fbits)(op1.ztup2, op2.ztup2) && EQUAL(ziop)(op1.ztup3, op2.ztup3);
}


// struct tuple_(%bv20, %bv5, %enum zuop)
struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 {
  uint64_t ztup0;
  uint64_t ztup1;
  enum zuop ztup2;
};

static void COPY(ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9)(struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 *rop, const struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 op) {
  rop->ztup0 = op.ztup0;
  rop->ztup1 = op.ztup1;
  rop->ztup2 = op.ztup2;
}

static bool EQUAL(ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9)(struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 op1, struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 op2) {
  return EQUAL(fbits)(op1.ztup0, op2.ztup0) && EQUAL(fbits)(op1.ztup1, op2.ztup1) && EQUAL(zuop)(op1.ztup2, op2.ztup2);
}


// struct tuple_(%bv5, %bv5, %bv5, %enum zrop)
struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 {
  uint64_t ztup0;
  uint64_t ztup1;
  uint64_t ztup2;
  enum zrop ztup3;
};

static void COPY(ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9)(struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 *rop, const struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 op) {
  rop->ztup0 = op.ztup0;
  rop->ztup1 = op.ztup1;
  rop->ztup2 = op.ztup2;
  rop->ztup3 = op.ztup3;
}

static bool EQUAL(ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9)(struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 op1, struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 op2) {
  return EQUAL(fbits)(op1.ztup0, op2.ztup0) && EQUAL(fbits)(op1.ztup1, op2.ztup1) && EQUAL(fbits)(op1.ztup2, op2.ztup2) && EQUAL(zrop)(op1.ztup3, op2.ztup3);
}


// struct tuple_(%bv7, %bv5, %bv5, %bv5, %enum zsop)
struct ztuple_z8z5bv7zCz0z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzsopz9 {
  uint64_t ztup0;
  uint64_t ztup1;
  uint64_t ztup2;
  uint64_t ztup3;
  enum zsop ztup4;
};

static void COPY(ztuple_z8z5bv7zCz0z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzsopz9)(struct ztuple_z8z5bv7zCz0z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzsopz9 *rop, const struct ztuple_z8z5bv7zCz0z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzsopz9 op) {
  rop->ztup0 = op.ztup0;
  rop->ztup1 = op.ztup1;
  rop->ztup2 = op.ztup2;
  rop->ztup3 = op.ztup3;
  rop->ztup4 = op.ztup4;
}

static bool EQUAL(ztuple_z8z5bv7zCz0z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzsopz9)(struct ztuple_z8z5bv7zCz0z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzsopz9 op1, struct ztuple_z8z5bv7zCz0z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzsopz9 op2) {
  return EQUAL(fbits)(op1.ztup0, op2.ztup0) && EQUAL(fbits)(op1.ztup1, op2.ztup1) && EQUAL(fbits)(op1.ztup2, op2.ztup2) && EQUAL(fbits)(op1.ztup3, op2.ztup3) && EQUAL(zsop)(op1.ztup4, op2.ztup4);
}

// union ast
enum kind_zast { Kind_zBTYPE, Kind_zITYPE, Kind_zJTYPE, Kind_zRTYPE, Kind_zSTYPE, Kind_zUTYPE };

struct zast {
  enum kind_zast kind;
  union {
    struct { struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 zBTYPE; };
    struct { struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zITYPE; };
    struct { struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv8zCz0z5bv5zCz0z5enumz0zzjopz9 zJTYPE; };
    struct { struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zRTYPE; };
    struct { struct ztuple_z8z5bv7zCz0z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzsopz9 zSTYPE; };
    struct { struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 zUTYPE; };
  };
};

static void CREATE(zast)(struct zast *op)
{
  op->kind = Kind_zBTYPE;
  
}

static void RECREATE(zast)(struct zast *op) {}

static void KILL(zast)(struct zast *op)
{
  if (op->kind == Kind_zBTYPE) {
    /* do nothing */
  } else if (op->kind == Kind_zITYPE) {
    /* do nothing */
  } else if (op->kind == Kind_zJTYPE) {
    /* do nothing */
  } else if (op->kind == Kind_zRTYPE) {
    /* do nothing */
  } else if (op->kind == Kind_zSTYPE) {
    /* do nothing */
  } else if (op->kind == Kind_zUTYPE){
    /* do nothing */
  };
}

static void COPY(zast)(struct zast *rop, struct zast op)
{
  if (rop->kind == Kind_zBTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zITYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zJTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zRTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zSTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zUTYPE){
    /* do nothing */
  };
  rop->kind = op.kind;
  if (op.kind == Kind_zBTYPE) {
    rop->zBTYPE = op.zBTYPE;
  } else if (op.kind == Kind_zITYPE) {
    rop->zITYPE = op.zITYPE;
  } else if (op.kind == Kind_zJTYPE) {
    rop->zJTYPE = op.zJTYPE;
  } else if (op.kind == Kind_zRTYPE) {
    rop->zRTYPE = op.zRTYPE;
  } else if (op.kind == Kind_zSTYPE) {
    rop->zSTYPE = op.zSTYPE;
  } else if (op.kind == Kind_zUTYPE){
    rop->zUTYPE = op.zUTYPE;
  }
}

static bool EQUAL(zast)(struct zast op1, struct zast op2) {
  if (op1.kind == Kind_zBTYPE && op2.kind == Kind_zBTYPE) {
  
  return EQUAL(ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9)(op1.zBTYPE, op2.zBTYPE);
  } else if (op1.kind == Kind_zITYPE && op2.kind == Kind_zITYPE) {
    return EQUAL(ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9)(op1.zITYPE, op2.zITYPE);
  } else if (op1.kind == Kind_zJTYPE && op2.kind == Kind_zJTYPE) {
    return EQUAL(ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv8zCz0z5bv5zCz0z5enumz0zzjopz9)(op1.zJTYPE, op2.zJTYPE);
  } else if (op1.kind == Kind_zRTYPE && op2.kind == Kind_zRTYPE) {
    return EQUAL(ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9)(op1.zRTYPE, op2.zRTYPE);
  } else if (op1.kind == Kind_zSTYPE && op2.kind == Kind_zSTYPE) {
    return EQUAL(ztuple_z8z5bv7zCz0z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzsopz9)(op1.zSTYPE, op2.zSTYPE);
  } else if (op1.kind == Kind_zUTYPE && op2.kind == Kind_zUTYPE) {
    return EQUAL(ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9)(op1.zUTYPE, op2.zUTYPE);
  } else return false;
}

static void zBTYPE(struct zast *rop, struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 op)
{
  if (rop->kind == Kind_zBTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zITYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zJTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zRTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zSTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zUTYPE){
    /* do nothing */
  }
  rop->kind = Kind_zBTYPE;
  rop->zBTYPE = op;
}

static void zITYPE(struct zast *rop, struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 op)
{
  if (rop->kind == Kind_zBTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zITYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zJTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zRTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zSTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zUTYPE){
    /* do nothing */
  }
  rop->kind = Kind_zITYPE;
  rop->zITYPE = op;
}

static void zJTYPE(struct zast *rop, struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv8zCz0z5bv5zCz0z5enumz0zzjopz9 op)
{
  if (rop->kind == Kind_zBTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zITYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zJTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zRTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zSTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zUTYPE){
    /* do nothing */
  }
  rop->kind = Kind_zJTYPE;
  rop->zJTYPE = op;
}

static void zRTYPE(struct zast *rop, struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 op)
{
  if (rop->kind == Kind_zBTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zITYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zJTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zRTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zSTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zUTYPE){
    /* do nothing */
  }
  rop->kind = Kind_zRTYPE;
  rop->zRTYPE = op;
}

static void zSTYPE(struct zast *rop, struct ztuple_z8z5bv7zCz0z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzsopz9 op)
{
  if (rop->kind == Kind_zBTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zITYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zJTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zRTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zSTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zUTYPE){
    /* do nothing */
  }
  rop->kind = Kind_zSTYPE;
  rop->zSTYPE = op;
}

static void zUTYPE(struct zast *rop, struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 op)
{
  if (rop->kind == Kind_zBTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zITYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zJTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zRTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zSTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zUTYPE){
    /* do nothing */
  }
  rop->kind = Kind_zUTYPE;
  rop->zUTYPE = op;
}






// union option
enum kind_zoption { Kind_zNone, Kind_zSomez3z5unionz0zzast };

struct zoption {
  enum kind_zoption kind;
  union {
    struct { unit zNone; };
    struct { struct zast zSomez3z5unionz0zzast; };
  };
};

static void CREATE(zoption)(struct zoption *op)
{
  op->kind = Kind_zNone;
  
}

static void RECREATE(zoption)(struct zoption *op) {}

static void KILL(zoption)(struct zoption *op)
{
  if (op->kind == Kind_zNone) {
    /* do nothing */
  } else if (op->kind == Kind_zSomez3z5unionz0zzast){
    KILL(zast)(&op->zSomez3z5unionz0zzast);
  };
}

static void COPY(zoption)(struct zoption *rop, struct zoption op)
{
  if (rop->kind == Kind_zNone) {
    /* do nothing */
  } else if (rop->kind == Kind_zSomez3z5unionz0zzast){
    KILL(zast)(&rop->zSomez3z5unionz0zzast);
  };
  rop->kind = op.kind;
  if (op.kind == Kind_zNone) {
    rop->zNone = op.zNone;
  } else if (op.kind == Kind_zSomez3z5unionz0zzast){
    CREATE(zast)(&rop->zSomez3z5unionz0zzast); COPY(zast)(&rop->zSomez3z5unionz0zzast, op.zSomez3z5unionz0zzast);
  }
}

static bool EQUAL(zoption)(struct zoption op1, struct zoption op2) {
  if (op1.kind == Kind_zNone && op2.kind == Kind_zNone) {
    return EQUAL(unit)(op1.zNone, op2.zNone);
  } else if (op1.kind == Kind_zSomez3z5unionz0zzast && op2.kind == Kind_zSomez3z5unionz0zzast) {
    return EQUAL(zast)(op1.zSomez3z5unionz0zzast, op2.zSomez3z5unionz0zzast);
  } else return false;
}

static void zNone(struct zoption *rop, unit op)
{
  if (rop->kind == Kind_zNone) {
    /* do nothing */
  } else if (rop->kind == Kind_zSomez3z5unionz0zzast){
    KILL(zast)(&rop->zSomez3z5unionz0zzast);
  }
  rop->kind = Kind_zNone;
  rop->zNone = op;
}

static void zSomez3z5unionz0zzast(struct zoption *rop, struct zast op)
{
  if (rop->kind == Kind_zNone) {
    /* do nothing */
  } else if (rop->kind == Kind_zSomez3z5unionz0zzast){
    KILL(zast)(&rop->zSomez3z5unionz0zzast);
  }
  rop->kind = Kind_zSomez3z5unionz0zzast;
  CREATE(zast)(&rop->zSomez3z5unionz0zzast);
  COPY(zast)(&rop->zSomez3z5unionz0zzast, op);
  
}









































// register zero
uint64_t zzzero;

// register ra
uint64_t zra;

// register sp
uint64_t zsp;

// register gp
uint64_t zgp;

// register a0
uint64_t za0;

// register a1
uint64_t za1;

// register a2
uint64_t za2;

// register a3
uint64_t za3;

struct zz5vecz8z6z8z5bv32z9z9 {
  size_t len;
  uint64_t* *data;
};
typedef struct zz5vecz8z6z8z5bv32z9z9 zz5vecz8z6z8z5bv32z9z9;

static void CREATE(zz5vecz8z6z8z5bv32z9z9)(zz5vecz8z6z8z5bv32z9z9 *rop) {
  rop->len = 0;
  rop->data = NULL;
}

static void KILL(zz5vecz8z6z8z5bv32z9z9)(zz5vecz8z6z8z5bv32z9z9 *rop) {
  if (rop->data != NULL) sail_free(rop->data);
}

static void undefined_vector_zz5vecz8z6z8z5bv32z9z9(zz5vecz8z6z8z5bv32z9z9 *rop, sail_int len, uint64_t* elem) {
  rop->len = sail_int_get_ui(len);
  rop->data = sail_malloc((rop->len) * sizeof(uint64_t*));
  for (int i = 0; i < (rop->len); i++) {
    (rop->data)[i] = elem;
  }
}

static uint64_t* vector_access_zz5vecz8z6z8z5bv32z9z9(zz5vecz8z6z8z5bv32z9z9 op, sail_int n) {
  int m = sail_int_get_ui(n);
  return op.data[m];
}

static void COPY(zz5vecz8z6z8z5bv32z9z9)(zz5vecz8z6z8z5bv32z9z9 *rop, zz5vecz8z6z8z5bv32z9z9 op) {
  KILL(zz5vecz8z6z8z5bv32z9z9)(rop);
  rop->len = op.len;
  rop->data = sail_malloc((rop->len) * sizeof(uint64_t*));
  for (int i = 0; i < op.len; i++) {
    (rop->data)[i] = op.data[i];
  }
}

static void vector_update_zz5vecz8z6z8z5bv32z9z9(zz5vecz8z6z8z5bv32z9z9 *rop, zz5vecz8z6z8z5bv32z9z9 op, sail_int n, uint64_t* elem) {
  int m = sail_int_get_ui(n);
  if (rop->data == op.data) {
    rop->data[m] = elem;
  } else {
    COPY(zz5vecz8z6z8z5bv32z9z9)(rop, op);
    rop->data[m] = elem;
  }
}

static void internal_vector_update_zz5vecz8z6z8z5bv32z9z9(zz5vecz8z6z8z5bv32z9z9 *rop, zz5vecz8z6z8z5bv32z9z9 op, const int64_t n, uint64_t* elem) {
  rop->data[n] = elem;
}

static void internal_vector_init_zz5vecz8z6z8z5bv32z9z9(zz5vecz8z6z8z5bv32z9z9 *rop, const int64_t len) {
  rop->len = len;
  rop->data = sail_malloc(len * sizeof(uint64_t*));
}

zz5vecz8z6z8z5bv32z9z9 zX;
static void create_letbind_0(void) {    CREATE(zz5vecz8z6z8z5bv32z9z9)(&zX);


  zz5vecz8z6z8z5bv32z9z9 zgsz31;
  CREATE(zz5vecz8z6z8z5bv32z9z9)(&zgsz31);
  zz5vecz8z6z8z5bv32z9z9 zgsz30;
  CREATE(zz5vecz8z6z8z5bv32z9z9)(&zgsz30);
  internal_vector_init_zz5vecz8z6z8z5bv32z9z9(&zgsz30, INT64_C(8));
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz30, zgsz30, INT64_C(0), &zzzero);
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz30, zgsz30, INT64_C(1), &zra);
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz30, zgsz30, INT64_C(2), &zsp);
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz30, zgsz30, INT64_C(3), &zgp);
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz30, zgsz30, INT64_C(4), &za0);
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz30, zgsz30, INT64_C(5), &za1);
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz30, zgsz30, INT64_C(6), &za2);
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz30, zgsz30, INT64_C(7), &za3);
  COPY(zz5vecz8z6z8z5bv32z9z9)(&zgsz31, zgsz30);
  KILL(zz5vecz8z6z8z5bv32z9z9)(&zgsz30);
  COPY(zz5vecz8z6z8z5bv32z9z9)(&zX, zgsz31);
  KILL(zz5vecz8z6z8z5bv32z9z9)(&zgsz31);
let_end_0: ;
}
static void kill_letbind_0(void) {    KILL(zz5vecz8z6z8z5bv32z9z9)(&zX);
}






void zdecode(struct zoption *rop, uint64_t);






unit zexecute(struct zast);


















void zdecode(struct zoption *zcbz30, uint64_t zmergez3var)
{
  __label__ case_3, case_4, case_5, case_6, case_7, case_8, case_9, case_10, case_11, case_12, case_13, case_14, case_15, case_16, case_17, case_18, case_19, case_20, case_21, case_22, finish_match_2, end_function_23, end_block_exception_24, end_function_55;

  struct zoption zgsz32;
  CREATE(zoption)(&zgsz32);
  {
    uint64_t zv__0;
    zv__0 = zmergez3var;
    bool zgaz33;
    {
      uint64_t zgaz31;
      {
        lbits zgsz33;
        CREATE(lbits)(&zgsz33);
        CONVERT_OF(lbits, fbits)(&zgsz33, zv__0, UINT64_C(32) , true);
        sail_int zgsz34;
        CREATE(sail_int)(&zgsz34);
        CONVERT_OF(sail_int, mach_int)(&zgsz34, INT64_C(31));
        sail_int zgsz35;
        CREATE(sail_int)(&zgsz35);
        CONVERT_OF(sail_int, mach_int)(&zgsz35, INT64_C(25));
        lbits zgsz36;
        CREATE(lbits)(&zgsz36);
        vector_subrange_lbits(&zgsz36, zgsz33, zgsz34, zgsz35);
        zgaz31 = CONVERT_OF(fbits, lbits)(zgsz36, true);
        KILL(lbits)(&zgsz36);
        KILL(sail_int)(&zgsz35);
        KILL(sail_int)(&zgsz34);
        KILL(lbits)(&zgsz33);
      }
      {
        lbits zgsz38;
        CREATE(lbits)(&zgsz38);
        CONVERT_OF(lbits, fbits)(&zgsz38, UINT64_C(0b0000000), UINT64_C(7) , true);
        lbits zgsz37;
        CREATE(lbits)(&zgsz37);
        CONVERT_OF(lbits, fbits)(&zgsz37, zgaz31, UINT64_C(7) , true);
        zgaz33 = eq_bits(zgsz37, zgsz38);
        KILL(lbits)(&zgsz38);
        KILL(lbits)(&zgsz37);
      }
    
    }
    bool zgsz313;
    if (zgaz33) {
    uint64_t zgaz32;
    {
      lbits zgsz39;
      CREATE(lbits)(&zgsz39);
      CONVERT_OF(lbits, fbits)(&zgsz39, zv__0, UINT64_C(32) , true);
      sail_int zgsz310;
      CREATE(sail_int)(&zgsz310);
      CONVERT_OF(sail_int, mach_int)(&zgsz310, INT64_C(6));
      sail_int zgsz311;
      CREATE(sail_int)(&zgsz311);
      CONVERT_OF(sail_int, mach_int)(&zgsz311, INT64_C(0));
      lbits zgsz312;
      CREATE(lbits)(&zgsz312);
      vector_subrange_lbits(&zgsz312, zgsz39, zgsz310, zgsz311);
      zgaz32 = CONVERT_OF(fbits, lbits)(zgsz312, true);
      KILL(lbits)(&zgsz312);
      KILL(sail_int)(&zgsz311);
      KILL(sail_int)(&zgsz310);
      KILL(lbits)(&zgsz39);
    }
    {
      lbits zgsz315;
      CREATE(lbits)(&zgsz315);
      CONVERT_OF(lbits, fbits)(&zgsz315, UINT64_C(0b0110011), UINT64_C(7) , true);
      lbits zgsz314;
      CREATE(lbits)(&zgsz314);
      CONVERT_OF(lbits, fbits)(&zgsz314, zgaz32, UINT64_C(7) , true);
      zgsz313 = eq_bits(zgsz314, zgsz315);
      KILL(lbits)(&zgsz315);
      KILL(lbits)(&zgsz314);
    }
  
    } else {  zgsz313 = false;  }
    bool zgsz329;
    zgsz329 = zgsz313;
  
    if (!(zgsz329)) {
  
    goto case_3;
    }
    uint64_t zrs2;
    {
      lbits zgsz316;
      CREATE(lbits)(&zgsz316);
      CONVERT_OF(lbits, fbits)(&zgsz316, zv__0, UINT64_C(32) , true);
      sail_int zgsz317;
      CREATE(sail_int)(&zgsz317);
      CONVERT_OF(sail_int, mach_int)(&zgsz317, INT64_C(24));
      sail_int zgsz318;
      CREATE(sail_int)(&zgsz318);
      CONVERT_OF(sail_int, mach_int)(&zgsz318, INT64_C(20));
      lbits zgsz319;
      CREATE(lbits)(&zgsz319);
      vector_subrange_lbits(&zgsz319, zgsz316, zgsz317, zgsz318);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz319, true);
      KILL(lbits)(&zgsz319);
      KILL(sail_int)(&zgsz318);
      KILL(sail_int)(&zgsz317);
      KILL(lbits)(&zgsz316);
    }
    uint64_t zrs1;
    {
      lbits zgsz320;
      CREATE(lbits)(&zgsz320);
      CONVERT_OF(lbits, fbits)(&zgsz320, zv__0, UINT64_C(32) , true);
      sail_int zgsz321;
      CREATE(sail_int)(&zgsz321);
      CONVERT_OF(sail_int, mach_int)(&zgsz321, INT64_C(19));
      sail_int zgsz322;
      CREATE(sail_int)(&zgsz322);
      CONVERT_OF(sail_int, mach_int)(&zgsz322, INT64_C(15));
      lbits zgsz323;
      CREATE(lbits)(&zgsz323);
      vector_subrange_lbits(&zgsz323, zgsz320, zgsz321, zgsz322);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz323, true);
      KILL(lbits)(&zgsz323);
      KILL(sail_int)(&zgsz322);
      KILL(sail_int)(&zgsz321);
      KILL(lbits)(&zgsz320);
    }
    uint64_t zrd;
    {
      lbits zgsz324;
      CREATE(lbits)(&zgsz324);
      CONVERT_OF(lbits, fbits)(&zgsz324, zv__0, UINT64_C(32) , true);
      sail_int zgsz325;
      CREATE(sail_int)(&zgsz325);
      CONVERT_OF(sail_int, mach_int)(&zgsz325, INT64_C(11));
      sail_int zgsz326;
      CREATE(sail_int)(&zgsz326);
      CONVERT_OF(sail_int, mach_int)(&zgsz326, INT64_C(7));
      lbits zgsz327;
      CREATE(lbits)(&zgsz327);
      vector_subrange_lbits(&zgsz327, zgsz324, zgsz325, zgsz326);
      zrd = CONVERT_OF(fbits, lbits)(zgsz327, true);
      KILL(lbits)(&zgsz327);
      KILL(sail_int)(&zgsz326);
      KILL(sail_int)(&zgsz325);
      KILL(lbits)(&zgsz324);
    }
    struct zast zgaz30;
    CREATE(zast)(&zgaz30);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz328;
      zgsz328.ztup0 = zrs2;
      zgsz328.ztup1 = zrs1;
      zgsz328.ztup2 = zrd;
      zgsz328.ztup3 = zADD;
      zRTYPE(&zgaz30, zgsz328);
    
    }
    {
      struct zast zgsz3578;
      CREATE(zast)(&zgsz3578);
      COPY(zast)(&zgsz3578, zgaz30);
      zSomez3z5unionz0zzast(&zgsz32, zgsz3578);
      KILL(zast)(&zgsz3578);
    }
    KILL(zast)(&zgaz30);
  
  
  
  
    goto finish_match_2;
  }
case_3: ;
  {
    uint64_t zv__3;
    zv__3 = zmergez3var;
    bool zgaz37;
    {
      uint64_t zgaz35;
      {
        lbits zgsz330;
        CREATE(lbits)(&zgsz330);
        CONVERT_OF(lbits, fbits)(&zgsz330, zv__3, UINT64_C(32) , true);
        sail_int zgsz331;
        CREATE(sail_int)(&zgsz331);
        CONVERT_OF(sail_int, mach_int)(&zgsz331, INT64_C(31));
        sail_int zgsz332;
        CREATE(sail_int)(&zgsz332);
        CONVERT_OF(sail_int, mach_int)(&zgsz332, INT64_C(25));
        lbits zgsz333;
        CREATE(lbits)(&zgsz333);
        vector_subrange_lbits(&zgsz333, zgsz330, zgsz331, zgsz332);
        zgaz35 = CONVERT_OF(fbits, lbits)(zgsz333, true);
        KILL(lbits)(&zgsz333);
        KILL(sail_int)(&zgsz332);
        KILL(sail_int)(&zgsz331);
        KILL(lbits)(&zgsz330);
      }
      {
        lbits zgsz335;
        CREATE(lbits)(&zgsz335);
        CONVERT_OF(lbits, fbits)(&zgsz335, UINT64_C(0b0000000), UINT64_C(7) , true);
        lbits zgsz334;
        CREATE(lbits)(&zgsz334);
        CONVERT_OF(lbits, fbits)(&zgsz334, zgaz35, UINT64_C(7) , true);
        zgaz37 = eq_bits(zgsz334, zgsz335);
        KILL(lbits)(&zgsz335);
        KILL(lbits)(&zgsz334);
      }
    
    }
    bool zgsz340;
    if (zgaz37) {
    uint64_t zgaz36;
    {
      lbits zgsz336;
      CREATE(lbits)(&zgsz336);
      CONVERT_OF(lbits, fbits)(&zgsz336, zv__3, UINT64_C(32) , true);
      sail_int zgsz337;
      CREATE(sail_int)(&zgsz337);
      CONVERT_OF(sail_int, mach_int)(&zgsz337, INT64_C(6));
      sail_int zgsz338;
      CREATE(sail_int)(&zgsz338);
      CONVERT_OF(sail_int, mach_int)(&zgsz338, INT64_C(0));
      lbits zgsz339;
      CREATE(lbits)(&zgsz339);
      vector_subrange_lbits(&zgsz339, zgsz336, zgsz337, zgsz338);
      zgaz36 = CONVERT_OF(fbits, lbits)(zgsz339, true);
      KILL(lbits)(&zgsz339);
      KILL(sail_int)(&zgsz338);
      KILL(sail_int)(&zgsz337);
      KILL(lbits)(&zgsz336);
    }
    {
      lbits zgsz342;
      CREATE(lbits)(&zgsz342);
      CONVERT_OF(lbits, fbits)(&zgsz342, UINT64_C(0b0110011), UINT64_C(7) , true);
      lbits zgsz341;
      CREATE(lbits)(&zgsz341);
      CONVERT_OF(lbits, fbits)(&zgsz341, zgaz36, UINT64_C(7) , true);
      zgsz340 = eq_bits(zgsz341, zgsz342);
      KILL(lbits)(&zgsz342);
      KILL(lbits)(&zgsz341);
    }
  
    } else {  zgsz340 = false;  }
    bool zgsz356;
    zgsz356 = zgsz340;
  
    if (!(zgsz356)) {
  
    goto case_4;
    }
    uint64_t zrs2;
    {
      lbits zgsz343;
      CREATE(lbits)(&zgsz343);
      CONVERT_OF(lbits, fbits)(&zgsz343, zv__3, UINT64_C(32) , true);
      sail_int zgsz344;
      CREATE(sail_int)(&zgsz344);
      CONVERT_OF(sail_int, mach_int)(&zgsz344, INT64_C(24));
      sail_int zgsz345;
      CREATE(sail_int)(&zgsz345);
      CONVERT_OF(sail_int, mach_int)(&zgsz345, INT64_C(20));
      lbits zgsz346;
      CREATE(lbits)(&zgsz346);
      vector_subrange_lbits(&zgsz346, zgsz343, zgsz344, zgsz345);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz346, true);
      KILL(lbits)(&zgsz346);
      KILL(sail_int)(&zgsz345);
      KILL(sail_int)(&zgsz344);
      KILL(lbits)(&zgsz343);
    }
    uint64_t zrs1;
    {
      lbits zgsz347;
      CREATE(lbits)(&zgsz347);
      CONVERT_OF(lbits, fbits)(&zgsz347, zv__3, UINT64_C(32) , true);
      sail_int zgsz348;
      CREATE(sail_int)(&zgsz348);
      CONVERT_OF(sail_int, mach_int)(&zgsz348, INT64_C(19));
      sail_int zgsz349;
      CREATE(sail_int)(&zgsz349);
      CONVERT_OF(sail_int, mach_int)(&zgsz349, INT64_C(15));
      lbits zgsz350;
      CREATE(lbits)(&zgsz350);
      vector_subrange_lbits(&zgsz350, zgsz347, zgsz348, zgsz349);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz350, true);
      KILL(lbits)(&zgsz350);
      KILL(sail_int)(&zgsz349);
      KILL(sail_int)(&zgsz348);
      KILL(lbits)(&zgsz347);
    }
    uint64_t zrd;
    {
      lbits zgsz351;
      CREATE(lbits)(&zgsz351);
      CONVERT_OF(lbits, fbits)(&zgsz351, zv__3, UINT64_C(32) , true);
      sail_int zgsz352;
      CREATE(sail_int)(&zgsz352);
      CONVERT_OF(sail_int, mach_int)(&zgsz352, INT64_C(11));
      sail_int zgsz353;
      CREATE(sail_int)(&zgsz353);
      CONVERT_OF(sail_int, mach_int)(&zgsz353, INT64_C(7));
      lbits zgsz354;
      CREATE(lbits)(&zgsz354);
      vector_subrange_lbits(&zgsz354, zgsz351, zgsz352, zgsz353);
      zrd = CONVERT_OF(fbits, lbits)(zgsz354, true);
      KILL(lbits)(&zgsz354);
      KILL(sail_int)(&zgsz353);
      KILL(sail_int)(&zgsz352);
      KILL(lbits)(&zgsz351);
    }
    struct zast zgaz34;
    CREATE(zast)(&zgaz34);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz355;
      zgsz355.ztup0 = zrs2;
      zgsz355.ztup1 = zrs1;
      zgsz355.ztup2 = zrd;
      zgsz355.ztup3 = zAND;
      zRTYPE(&zgaz34, zgsz355);
    
    }
    {
      struct zast zgsz3579;
      CREATE(zast)(&zgsz3579);
      COPY(zast)(&zgsz3579, zgaz34);
      zSomez3z5unionz0zzast(&zgsz32, zgsz3579);
      KILL(zast)(&zgsz3579);
    }
    KILL(zast)(&zgaz34);
  
  
  
  
    goto finish_match_2;
  }
case_4: ;
  {
    uint64_t zv__6;
    zv__6 = zmergez3var;
    bool zgaz311;
    {
      uint64_t zgaz39;
      {
        lbits zgsz357;
        CREATE(lbits)(&zgsz357);
        CONVERT_OF(lbits, fbits)(&zgsz357, zv__6, UINT64_C(32) , true);
        sail_int zgsz358;
        CREATE(sail_int)(&zgsz358);
        CONVERT_OF(sail_int, mach_int)(&zgsz358, INT64_C(31));
        sail_int zgsz359;
        CREATE(sail_int)(&zgsz359);
        CONVERT_OF(sail_int, mach_int)(&zgsz359, INT64_C(25));
        lbits zgsz360;
        CREATE(lbits)(&zgsz360);
        vector_subrange_lbits(&zgsz360, zgsz357, zgsz358, zgsz359);
        zgaz39 = CONVERT_OF(fbits, lbits)(zgsz360, true);
        KILL(lbits)(&zgsz360);
        KILL(sail_int)(&zgsz359);
        KILL(sail_int)(&zgsz358);
        KILL(lbits)(&zgsz357);
      }
      {
        lbits zgsz362;
        CREATE(lbits)(&zgsz362);
        CONVERT_OF(lbits, fbits)(&zgsz362, UINT64_C(0b0000000), UINT64_C(7) , true);
        lbits zgsz361;
        CREATE(lbits)(&zgsz361);
        CONVERT_OF(lbits, fbits)(&zgsz361, zgaz39, UINT64_C(7) , true);
        zgaz311 = eq_bits(zgsz361, zgsz362);
        KILL(lbits)(&zgsz362);
        KILL(lbits)(&zgsz361);
      }
    
    }
    bool zgsz367;
    if (zgaz311) {
    uint64_t zgaz310;
    {
      lbits zgsz363;
      CREATE(lbits)(&zgsz363);
      CONVERT_OF(lbits, fbits)(&zgsz363, zv__6, UINT64_C(32) , true);
      sail_int zgsz364;
      CREATE(sail_int)(&zgsz364);
      CONVERT_OF(sail_int, mach_int)(&zgsz364, INT64_C(6));
      sail_int zgsz365;
      CREATE(sail_int)(&zgsz365);
      CONVERT_OF(sail_int, mach_int)(&zgsz365, INT64_C(0));
      lbits zgsz366;
      CREATE(lbits)(&zgsz366);
      vector_subrange_lbits(&zgsz366, zgsz363, zgsz364, zgsz365);
      zgaz310 = CONVERT_OF(fbits, lbits)(zgsz366, true);
      KILL(lbits)(&zgsz366);
      KILL(sail_int)(&zgsz365);
      KILL(sail_int)(&zgsz364);
      KILL(lbits)(&zgsz363);
    }
    {
      lbits zgsz369;
      CREATE(lbits)(&zgsz369);
      CONVERT_OF(lbits, fbits)(&zgsz369, UINT64_C(0b0110011), UINT64_C(7) , true);
      lbits zgsz368;
      CREATE(lbits)(&zgsz368);
      CONVERT_OF(lbits, fbits)(&zgsz368, zgaz310, UINT64_C(7) , true);
      zgsz367 = eq_bits(zgsz368, zgsz369);
      KILL(lbits)(&zgsz369);
      KILL(lbits)(&zgsz368);
    }
  
    } else {  zgsz367 = false;  }
    bool zgsz383;
    zgsz383 = zgsz367;
  
    if (!(zgsz383)) {
  
    goto case_5;
    }
    uint64_t zrs2;
    {
      lbits zgsz370;
      CREATE(lbits)(&zgsz370);
      CONVERT_OF(lbits, fbits)(&zgsz370, zv__6, UINT64_C(32) , true);
      sail_int zgsz371;
      CREATE(sail_int)(&zgsz371);
      CONVERT_OF(sail_int, mach_int)(&zgsz371, INT64_C(24));
      sail_int zgsz372;
      CREATE(sail_int)(&zgsz372);
      CONVERT_OF(sail_int, mach_int)(&zgsz372, INT64_C(20));
      lbits zgsz373;
      CREATE(lbits)(&zgsz373);
      vector_subrange_lbits(&zgsz373, zgsz370, zgsz371, zgsz372);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz373, true);
      KILL(lbits)(&zgsz373);
      KILL(sail_int)(&zgsz372);
      KILL(sail_int)(&zgsz371);
      KILL(lbits)(&zgsz370);
    }
    uint64_t zrs1;
    {
      lbits zgsz374;
      CREATE(lbits)(&zgsz374);
      CONVERT_OF(lbits, fbits)(&zgsz374, zv__6, UINT64_C(32) , true);
      sail_int zgsz375;
      CREATE(sail_int)(&zgsz375);
      CONVERT_OF(sail_int, mach_int)(&zgsz375, INT64_C(19));
      sail_int zgsz376;
      CREATE(sail_int)(&zgsz376);
      CONVERT_OF(sail_int, mach_int)(&zgsz376, INT64_C(15));
      lbits zgsz377;
      CREATE(lbits)(&zgsz377);
      vector_subrange_lbits(&zgsz377, zgsz374, zgsz375, zgsz376);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz377, true);
      KILL(lbits)(&zgsz377);
      KILL(sail_int)(&zgsz376);
      KILL(sail_int)(&zgsz375);
      KILL(lbits)(&zgsz374);
    }
    uint64_t zrd;
    {
      lbits zgsz378;
      CREATE(lbits)(&zgsz378);
      CONVERT_OF(lbits, fbits)(&zgsz378, zv__6, UINT64_C(32) , true);
      sail_int zgsz379;
      CREATE(sail_int)(&zgsz379);
      CONVERT_OF(sail_int, mach_int)(&zgsz379, INT64_C(11));
      sail_int zgsz380;
      CREATE(sail_int)(&zgsz380);
      CONVERT_OF(sail_int, mach_int)(&zgsz380, INT64_C(7));
      lbits zgsz381;
      CREATE(lbits)(&zgsz381);
      vector_subrange_lbits(&zgsz381, zgsz378, zgsz379, zgsz380);
      zrd = CONVERT_OF(fbits, lbits)(zgsz381, true);
      KILL(lbits)(&zgsz381);
      KILL(sail_int)(&zgsz380);
      KILL(sail_int)(&zgsz379);
      KILL(lbits)(&zgsz378);
    }
    struct zast zgaz38;
    CREATE(zast)(&zgaz38);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz382;
      zgsz382.ztup0 = zrs2;
      zgsz382.ztup1 = zrs1;
      zgsz382.ztup2 = zrd;
      zgsz382.ztup3 = zOR;
      zRTYPE(&zgaz38, zgsz382);
    
    }
    {
      struct zast zgsz3580;
      CREATE(zast)(&zgsz3580);
      COPY(zast)(&zgsz3580, zgaz38);
      zSomez3z5unionz0zzast(&zgsz32, zgsz3580);
      KILL(zast)(&zgsz3580);
    }
    KILL(zast)(&zgaz38);
  
  
  
  
    goto finish_match_2;
  }
case_5: ;
  {
    uint64_t zv__9;
    zv__9 = zmergez3var;
    bool zgaz315;
    {
      uint64_t zgaz313;
      {
        lbits zgsz384;
        CREATE(lbits)(&zgsz384);
        CONVERT_OF(lbits, fbits)(&zgsz384, zv__9, UINT64_C(32) , true);
        sail_int zgsz385;
        CREATE(sail_int)(&zgsz385);
        CONVERT_OF(sail_int, mach_int)(&zgsz385, INT64_C(31));
        sail_int zgsz386;
        CREATE(sail_int)(&zgsz386);
        CONVERT_OF(sail_int, mach_int)(&zgsz386, INT64_C(25));
        lbits zgsz387;
        CREATE(lbits)(&zgsz387);
        vector_subrange_lbits(&zgsz387, zgsz384, zgsz385, zgsz386);
        zgaz313 = CONVERT_OF(fbits, lbits)(zgsz387, true);
        KILL(lbits)(&zgsz387);
        KILL(sail_int)(&zgsz386);
        KILL(sail_int)(&zgsz385);
        KILL(lbits)(&zgsz384);
      }
      {
        lbits zgsz389;
        CREATE(lbits)(&zgsz389);
        CONVERT_OF(lbits, fbits)(&zgsz389, UINT64_C(0b0000000), UINT64_C(7) , true);
        lbits zgsz388;
        CREATE(lbits)(&zgsz388);
        CONVERT_OF(lbits, fbits)(&zgsz388, zgaz313, UINT64_C(7) , true);
        zgaz315 = eq_bits(zgsz388, zgsz389);
        KILL(lbits)(&zgsz389);
        KILL(lbits)(&zgsz388);
      }
    
    }
    bool zgsz394;
    if (zgaz315) {
    uint64_t zgaz314;
    {
      lbits zgsz390;
      CREATE(lbits)(&zgsz390);
      CONVERT_OF(lbits, fbits)(&zgsz390, zv__9, UINT64_C(32) , true);
      sail_int zgsz391;
      CREATE(sail_int)(&zgsz391);
      CONVERT_OF(sail_int, mach_int)(&zgsz391, INT64_C(6));
      sail_int zgsz392;
      CREATE(sail_int)(&zgsz392);
      CONVERT_OF(sail_int, mach_int)(&zgsz392, INT64_C(0));
      lbits zgsz393;
      CREATE(lbits)(&zgsz393);
      vector_subrange_lbits(&zgsz393, zgsz390, zgsz391, zgsz392);
      zgaz314 = CONVERT_OF(fbits, lbits)(zgsz393, true);
      KILL(lbits)(&zgsz393);
      KILL(sail_int)(&zgsz392);
      KILL(sail_int)(&zgsz391);
      KILL(lbits)(&zgsz390);
    }
    {
      lbits zgsz396;
      CREATE(lbits)(&zgsz396);
      CONVERT_OF(lbits, fbits)(&zgsz396, UINT64_C(0b0110011), UINT64_C(7) , true);
      lbits zgsz395;
      CREATE(lbits)(&zgsz395);
      CONVERT_OF(lbits, fbits)(&zgsz395, zgaz314, UINT64_C(7) , true);
      zgsz394 = eq_bits(zgsz395, zgsz396);
      KILL(lbits)(&zgsz396);
      KILL(lbits)(&zgsz395);
    }
  
    } else {  zgsz394 = false;  }
    bool zgsz3110;
    zgsz3110 = zgsz394;
  
    if (!(zgsz3110)) {
  
    goto case_6;
    }
    uint64_t zrs2;
    {
      lbits zgsz397;
      CREATE(lbits)(&zgsz397);
      CONVERT_OF(lbits, fbits)(&zgsz397, zv__9, UINT64_C(32) , true);
      sail_int zgsz398;
      CREATE(sail_int)(&zgsz398);
      CONVERT_OF(sail_int, mach_int)(&zgsz398, INT64_C(24));
      sail_int zgsz399;
      CREATE(sail_int)(&zgsz399);
      CONVERT_OF(sail_int, mach_int)(&zgsz399, INT64_C(20));
      lbits zgsz3100;
      CREATE(lbits)(&zgsz3100);
      vector_subrange_lbits(&zgsz3100, zgsz397, zgsz398, zgsz399);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz3100, true);
      KILL(lbits)(&zgsz3100);
      KILL(sail_int)(&zgsz399);
      KILL(sail_int)(&zgsz398);
      KILL(lbits)(&zgsz397);
    }
    uint64_t zrs1;
    {
      lbits zgsz3101;
      CREATE(lbits)(&zgsz3101);
      CONVERT_OF(lbits, fbits)(&zgsz3101, zv__9, UINT64_C(32) , true);
      sail_int zgsz3102;
      CREATE(sail_int)(&zgsz3102);
      CONVERT_OF(sail_int, mach_int)(&zgsz3102, INT64_C(19));
      sail_int zgsz3103;
      CREATE(sail_int)(&zgsz3103);
      CONVERT_OF(sail_int, mach_int)(&zgsz3103, INT64_C(15));
      lbits zgsz3104;
      CREATE(lbits)(&zgsz3104);
      vector_subrange_lbits(&zgsz3104, zgsz3101, zgsz3102, zgsz3103);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3104, true);
      KILL(lbits)(&zgsz3104);
      KILL(sail_int)(&zgsz3103);
      KILL(sail_int)(&zgsz3102);
      KILL(lbits)(&zgsz3101);
    }
    uint64_t zrd;
    {
      lbits zgsz3105;
      CREATE(lbits)(&zgsz3105);
      CONVERT_OF(lbits, fbits)(&zgsz3105, zv__9, UINT64_C(32) , true);
      sail_int zgsz3106;
      CREATE(sail_int)(&zgsz3106);
      CONVERT_OF(sail_int, mach_int)(&zgsz3106, INT64_C(11));
      sail_int zgsz3107;
      CREATE(sail_int)(&zgsz3107);
      CONVERT_OF(sail_int, mach_int)(&zgsz3107, INT64_C(7));
      lbits zgsz3108;
      CREATE(lbits)(&zgsz3108);
      vector_subrange_lbits(&zgsz3108, zgsz3105, zgsz3106, zgsz3107);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3108, true);
      KILL(lbits)(&zgsz3108);
      KILL(sail_int)(&zgsz3107);
      KILL(sail_int)(&zgsz3106);
      KILL(lbits)(&zgsz3105);
    }
    struct zast zgaz312;
    CREATE(zast)(&zgaz312);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3109;
      zgsz3109.ztup0 = zrs2;
      zgsz3109.ztup1 = zrs1;
      zgsz3109.ztup2 = zrd;
      zgsz3109.ztup3 = zXOR;
      zRTYPE(&zgaz312, zgsz3109);
    
    }
    {
      struct zast zgsz3581;
      CREATE(zast)(&zgsz3581);
      COPY(zast)(&zgsz3581, zgaz312);
      zSomez3z5unionz0zzast(&zgsz32, zgsz3581);
      KILL(zast)(&zgsz3581);
    }
    KILL(zast)(&zgaz312);
  
  
  
  
    goto finish_match_2;
  }
case_6: ;
  {
    uint64_t zv__12;
    zv__12 = zmergez3var;
    bool zgaz319;
    {
      uint64_t zgaz317;
      {
        lbits zgsz3111;
        CREATE(lbits)(&zgsz3111);
        CONVERT_OF(lbits, fbits)(&zgsz3111, zv__12, UINT64_C(32) , true);
        sail_int zgsz3112;
        CREATE(sail_int)(&zgsz3112);
        CONVERT_OF(sail_int, mach_int)(&zgsz3112, INT64_C(31));
        sail_int zgsz3113;
        CREATE(sail_int)(&zgsz3113);
        CONVERT_OF(sail_int, mach_int)(&zgsz3113, INT64_C(25));
        lbits zgsz3114;
        CREATE(lbits)(&zgsz3114);
        vector_subrange_lbits(&zgsz3114, zgsz3111, zgsz3112, zgsz3113);
        zgaz317 = CONVERT_OF(fbits, lbits)(zgsz3114, true);
        KILL(lbits)(&zgsz3114);
        KILL(sail_int)(&zgsz3113);
        KILL(sail_int)(&zgsz3112);
        KILL(lbits)(&zgsz3111);
      }
      {
        lbits zgsz3116;
        CREATE(lbits)(&zgsz3116);
        CONVERT_OF(lbits, fbits)(&zgsz3116, UINT64_C(0b0000001), UINT64_C(7) , true);
        lbits zgsz3115;
        CREATE(lbits)(&zgsz3115);
        CONVERT_OF(lbits, fbits)(&zgsz3115, zgaz317, UINT64_C(7) , true);
        zgaz319 = eq_bits(zgsz3115, zgsz3116);
        KILL(lbits)(&zgsz3116);
        KILL(lbits)(&zgsz3115);
      }
    
    }
    bool zgsz3121;
    if (zgaz319) {
    uint64_t zgaz318;
    {
      lbits zgsz3117;
      CREATE(lbits)(&zgsz3117);
      CONVERT_OF(lbits, fbits)(&zgsz3117, zv__12, UINT64_C(32) , true);
      sail_int zgsz3118;
      CREATE(sail_int)(&zgsz3118);
      CONVERT_OF(sail_int, mach_int)(&zgsz3118, INT64_C(6));
      sail_int zgsz3119;
      CREATE(sail_int)(&zgsz3119);
      CONVERT_OF(sail_int, mach_int)(&zgsz3119, INT64_C(0));
      lbits zgsz3120;
      CREATE(lbits)(&zgsz3120);
      vector_subrange_lbits(&zgsz3120, zgsz3117, zgsz3118, zgsz3119);
      zgaz318 = CONVERT_OF(fbits, lbits)(zgsz3120, true);
      KILL(lbits)(&zgsz3120);
      KILL(sail_int)(&zgsz3119);
      KILL(sail_int)(&zgsz3118);
      KILL(lbits)(&zgsz3117);
    }
    {
      lbits zgsz3123;
      CREATE(lbits)(&zgsz3123);
      CONVERT_OF(lbits, fbits)(&zgsz3123, UINT64_C(0b0110011), UINT64_C(7) , true);
      lbits zgsz3122;
      CREATE(lbits)(&zgsz3122);
      CONVERT_OF(lbits, fbits)(&zgsz3122, zgaz318, UINT64_C(7) , true);
      zgsz3121 = eq_bits(zgsz3122, zgsz3123);
      KILL(lbits)(&zgsz3123);
      KILL(lbits)(&zgsz3122);
    }
  
    } else {  zgsz3121 = false;  }
    bool zgsz3137;
    zgsz3137 = zgsz3121;
  
    if (!(zgsz3137)) {
  
    goto case_7;
    }
    uint64_t zrs2;
    {
      lbits zgsz3124;
      CREATE(lbits)(&zgsz3124);
      CONVERT_OF(lbits, fbits)(&zgsz3124, zv__12, UINT64_C(32) , true);
      sail_int zgsz3125;
      CREATE(sail_int)(&zgsz3125);
      CONVERT_OF(sail_int, mach_int)(&zgsz3125, INT64_C(24));
      sail_int zgsz3126;
      CREATE(sail_int)(&zgsz3126);
      CONVERT_OF(sail_int, mach_int)(&zgsz3126, INT64_C(20));
      lbits zgsz3127;
      CREATE(lbits)(&zgsz3127);
      vector_subrange_lbits(&zgsz3127, zgsz3124, zgsz3125, zgsz3126);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz3127, true);
      KILL(lbits)(&zgsz3127);
      KILL(sail_int)(&zgsz3126);
      KILL(sail_int)(&zgsz3125);
      KILL(lbits)(&zgsz3124);
    }
    uint64_t zrs1;
    {
      lbits zgsz3128;
      CREATE(lbits)(&zgsz3128);
      CONVERT_OF(lbits, fbits)(&zgsz3128, zv__12, UINT64_C(32) , true);
      sail_int zgsz3129;
      CREATE(sail_int)(&zgsz3129);
      CONVERT_OF(sail_int, mach_int)(&zgsz3129, INT64_C(19));
      sail_int zgsz3130;
      CREATE(sail_int)(&zgsz3130);
      CONVERT_OF(sail_int, mach_int)(&zgsz3130, INT64_C(15));
      lbits zgsz3131;
      CREATE(lbits)(&zgsz3131);
      vector_subrange_lbits(&zgsz3131, zgsz3128, zgsz3129, zgsz3130);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3131, true);
      KILL(lbits)(&zgsz3131);
      KILL(sail_int)(&zgsz3130);
      KILL(sail_int)(&zgsz3129);
      KILL(lbits)(&zgsz3128);
    }
    uint64_t zrd;
    {
      lbits zgsz3132;
      CREATE(lbits)(&zgsz3132);
      CONVERT_OF(lbits, fbits)(&zgsz3132, zv__12, UINT64_C(32) , true);
      sail_int zgsz3133;
      CREATE(sail_int)(&zgsz3133);
      CONVERT_OF(sail_int, mach_int)(&zgsz3133, INT64_C(11));
      sail_int zgsz3134;
      CREATE(sail_int)(&zgsz3134);
      CONVERT_OF(sail_int, mach_int)(&zgsz3134, INT64_C(7));
      lbits zgsz3135;
      CREATE(lbits)(&zgsz3135);
      vector_subrange_lbits(&zgsz3135, zgsz3132, zgsz3133, zgsz3134);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3135, true);
      KILL(lbits)(&zgsz3135);
      KILL(sail_int)(&zgsz3134);
      KILL(sail_int)(&zgsz3133);
      KILL(lbits)(&zgsz3132);
    }
    struct zast zgaz316;
    CREATE(zast)(&zgaz316);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3136;
      zgsz3136.ztup0 = zrs2;
      zgsz3136.ztup1 = zrs1;
      zgsz3136.ztup2 = zrd;
      zgsz3136.ztup3 = zMUL;
      zRTYPE(&zgaz316, zgsz3136);
    
    }
    {
      struct zast zgsz3582;
      CREATE(zast)(&zgsz3582);
      COPY(zast)(&zgsz3582, zgaz316);
      zSomez3z5unionz0zzast(&zgsz32, zgsz3582);
      KILL(zast)(&zgsz3582);
    }
    KILL(zast)(&zgaz316);
  
  
  
  
    goto finish_match_2;
  }
case_7: ;
  {
    uint64_t zv__15;
    zv__15 = zmergez3var;
    bool zgaz323;
    {
      uint64_t zgaz321;
      {
        lbits zgsz3138;
        CREATE(lbits)(&zgsz3138);
        CONVERT_OF(lbits, fbits)(&zgsz3138, zv__15, UINT64_C(32) , true);
        sail_int zgsz3139;
        CREATE(sail_int)(&zgsz3139);
        CONVERT_OF(sail_int, mach_int)(&zgsz3139, INT64_C(31));
        sail_int zgsz3140;
        CREATE(sail_int)(&zgsz3140);
        CONVERT_OF(sail_int, mach_int)(&zgsz3140, INT64_C(25));
        lbits zgsz3141;
        CREATE(lbits)(&zgsz3141);
        vector_subrange_lbits(&zgsz3141, zgsz3138, zgsz3139, zgsz3140);
        zgaz321 = CONVERT_OF(fbits, lbits)(zgsz3141, true);
        KILL(lbits)(&zgsz3141);
        KILL(sail_int)(&zgsz3140);
        KILL(sail_int)(&zgsz3139);
        KILL(lbits)(&zgsz3138);
      }
      {
        lbits zgsz3143;
        CREATE(lbits)(&zgsz3143);
        CONVERT_OF(lbits, fbits)(&zgsz3143, UINT64_C(0b0000001), UINT64_C(7) , true);
        lbits zgsz3142;
        CREATE(lbits)(&zgsz3142);
        CONVERT_OF(lbits, fbits)(&zgsz3142, zgaz321, UINT64_C(7) , true);
        zgaz323 = eq_bits(zgsz3142, zgsz3143);
        KILL(lbits)(&zgsz3143);
        KILL(lbits)(&zgsz3142);
      }
    
    }
    bool zgsz3148;
    if (zgaz323) {
    uint64_t zgaz322;
    {
      lbits zgsz3144;
      CREATE(lbits)(&zgsz3144);
      CONVERT_OF(lbits, fbits)(&zgsz3144, zv__15, UINT64_C(32) , true);
      sail_int zgsz3145;
      CREATE(sail_int)(&zgsz3145);
      CONVERT_OF(sail_int, mach_int)(&zgsz3145, INT64_C(6));
      sail_int zgsz3146;
      CREATE(sail_int)(&zgsz3146);
      CONVERT_OF(sail_int, mach_int)(&zgsz3146, INT64_C(0));
      lbits zgsz3147;
      CREATE(lbits)(&zgsz3147);
      vector_subrange_lbits(&zgsz3147, zgsz3144, zgsz3145, zgsz3146);
      zgaz322 = CONVERT_OF(fbits, lbits)(zgsz3147, true);
      KILL(lbits)(&zgsz3147);
      KILL(sail_int)(&zgsz3146);
      KILL(sail_int)(&zgsz3145);
      KILL(lbits)(&zgsz3144);
    }
    {
      lbits zgsz3150;
      CREATE(lbits)(&zgsz3150);
      CONVERT_OF(lbits, fbits)(&zgsz3150, UINT64_C(0b0110011), UINT64_C(7) , true);
      lbits zgsz3149;
      CREATE(lbits)(&zgsz3149);
      CONVERT_OF(lbits, fbits)(&zgsz3149, zgaz322, UINT64_C(7) , true);
      zgsz3148 = eq_bits(zgsz3149, zgsz3150);
      KILL(lbits)(&zgsz3150);
      KILL(lbits)(&zgsz3149);
    }
  
    } else {  zgsz3148 = false;  }
    bool zgsz3164;
    zgsz3164 = zgsz3148;
  
    if (!(zgsz3164)) {
  
    goto case_8;
    }
    uint64_t zrs2;
    {
      lbits zgsz3151;
      CREATE(lbits)(&zgsz3151);
      CONVERT_OF(lbits, fbits)(&zgsz3151, zv__15, UINT64_C(32) , true);
      sail_int zgsz3152;
      CREATE(sail_int)(&zgsz3152);
      CONVERT_OF(sail_int, mach_int)(&zgsz3152, INT64_C(24));
      sail_int zgsz3153;
      CREATE(sail_int)(&zgsz3153);
      CONVERT_OF(sail_int, mach_int)(&zgsz3153, INT64_C(20));
      lbits zgsz3154;
      CREATE(lbits)(&zgsz3154);
      vector_subrange_lbits(&zgsz3154, zgsz3151, zgsz3152, zgsz3153);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz3154, true);
      KILL(lbits)(&zgsz3154);
      KILL(sail_int)(&zgsz3153);
      KILL(sail_int)(&zgsz3152);
      KILL(lbits)(&zgsz3151);
    }
    uint64_t zrs1;
    {
      lbits zgsz3155;
      CREATE(lbits)(&zgsz3155);
      CONVERT_OF(lbits, fbits)(&zgsz3155, zv__15, UINT64_C(32) , true);
      sail_int zgsz3156;
      CREATE(sail_int)(&zgsz3156);
      CONVERT_OF(sail_int, mach_int)(&zgsz3156, INT64_C(19));
      sail_int zgsz3157;
      CREATE(sail_int)(&zgsz3157);
      CONVERT_OF(sail_int, mach_int)(&zgsz3157, INT64_C(15));
      lbits zgsz3158;
      CREATE(lbits)(&zgsz3158);
      vector_subrange_lbits(&zgsz3158, zgsz3155, zgsz3156, zgsz3157);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3158, true);
      KILL(lbits)(&zgsz3158);
      KILL(sail_int)(&zgsz3157);
      KILL(sail_int)(&zgsz3156);
      KILL(lbits)(&zgsz3155);
    }
    uint64_t zrd;
    {
      lbits zgsz3159;
      CREATE(lbits)(&zgsz3159);
      CONVERT_OF(lbits, fbits)(&zgsz3159, zv__15, UINT64_C(32) , true);
      sail_int zgsz3160;
      CREATE(sail_int)(&zgsz3160);
      CONVERT_OF(sail_int, mach_int)(&zgsz3160, INT64_C(11));
      sail_int zgsz3161;
      CREATE(sail_int)(&zgsz3161);
      CONVERT_OF(sail_int, mach_int)(&zgsz3161, INT64_C(7));
      lbits zgsz3162;
      CREATE(lbits)(&zgsz3162);
      vector_subrange_lbits(&zgsz3162, zgsz3159, zgsz3160, zgsz3161);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3162, true);
      KILL(lbits)(&zgsz3162);
      KILL(sail_int)(&zgsz3161);
      KILL(sail_int)(&zgsz3160);
      KILL(lbits)(&zgsz3159);
    }
    struct zast zgaz320;
    CREATE(zast)(&zgaz320);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3163;
      zgsz3163.ztup0 = zrs2;
      zgsz3163.ztup1 = zrs1;
      zgsz3163.ztup2 = zrd;
      zgsz3163.ztup3 = zDIV;
      zRTYPE(&zgaz320, zgsz3163);
    
    }
    {
      struct zast zgsz3583;
      CREATE(zast)(&zgsz3583);
      COPY(zast)(&zgsz3583, zgaz320);
      zSomez3z5unionz0zzast(&zgsz32, zgsz3583);
      KILL(zast)(&zgsz3583);
    }
    KILL(zast)(&zgaz320);
  
  
  
  
    goto finish_match_2;
  }
case_8: ;
  {
    uint64_t zv__18;
    zv__18 = zmergez3var;
    bool zgaz327;
    {
      uint64_t zgaz325;
      {
        lbits zgsz3165;
        CREATE(lbits)(&zgsz3165);
        CONVERT_OF(lbits, fbits)(&zgsz3165, zv__18, UINT64_C(32) , true);
        sail_int zgsz3166;
        CREATE(sail_int)(&zgsz3166);
        CONVERT_OF(sail_int, mach_int)(&zgsz3166, INT64_C(31));
        sail_int zgsz3167;
        CREATE(sail_int)(&zgsz3167);
        CONVERT_OF(sail_int, mach_int)(&zgsz3167, INT64_C(25));
        lbits zgsz3168;
        CREATE(lbits)(&zgsz3168);
        vector_subrange_lbits(&zgsz3168, zgsz3165, zgsz3166, zgsz3167);
        zgaz325 = CONVERT_OF(fbits, lbits)(zgsz3168, true);
        KILL(lbits)(&zgsz3168);
        KILL(sail_int)(&zgsz3167);
        KILL(sail_int)(&zgsz3166);
        KILL(lbits)(&zgsz3165);
      }
      {
        lbits zgsz3170;
        CREATE(lbits)(&zgsz3170);
        CONVERT_OF(lbits, fbits)(&zgsz3170, UINT64_C(0b0000001), UINT64_C(7) , true);
        lbits zgsz3169;
        CREATE(lbits)(&zgsz3169);
        CONVERT_OF(lbits, fbits)(&zgsz3169, zgaz325, UINT64_C(7) , true);
        zgaz327 = eq_bits(zgsz3169, zgsz3170);
        KILL(lbits)(&zgsz3170);
        KILL(lbits)(&zgsz3169);
      }
    
    }
    bool zgsz3175;
    if (zgaz327) {
    uint64_t zgaz326;
    {
      lbits zgsz3171;
      CREATE(lbits)(&zgsz3171);
      CONVERT_OF(lbits, fbits)(&zgsz3171, zv__18, UINT64_C(32) , true);
      sail_int zgsz3172;
      CREATE(sail_int)(&zgsz3172);
      CONVERT_OF(sail_int, mach_int)(&zgsz3172, INT64_C(6));
      sail_int zgsz3173;
      CREATE(sail_int)(&zgsz3173);
      CONVERT_OF(sail_int, mach_int)(&zgsz3173, INT64_C(0));
      lbits zgsz3174;
      CREATE(lbits)(&zgsz3174);
      vector_subrange_lbits(&zgsz3174, zgsz3171, zgsz3172, zgsz3173);
      zgaz326 = CONVERT_OF(fbits, lbits)(zgsz3174, true);
      KILL(lbits)(&zgsz3174);
      KILL(sail_int)(&zgsz3173);
      KILL(sail_int)(&zgsz3172);
      KILL(lbits)(&zgsz3171);
    }
    {
      lbits zgsz3177;
      CREATE(lbits)(&zgsz3177);
      CONVERT_OF(lbits, fbits)(&zgsz3177, UINT64_C(0b0110011), UINT64_C(7) , true);
      lbits zgsz3176;
      CREATE(lbits)(&zgsz3176);
      CONVERT_OF(lbits, fbits)(&zgsz3176, zgaz326, UINT64_C(7) , true);
      zgsz3175 = eq_bits(zgsz3176, zgsz3177);
      KILL(lbits)(&zgsz3177);
      KILL(lbits)(&zgsz3176);
    }
  
    } else {  zgsz3175 = false;  }
    bool zgsz3191;
    zgsz3191 = zgsz3175;
  
    if (!(zgsz3191)) {
  
    goto case_9;
    }
    uint64_t zrs2;
    {
      lbits zgsz3178;
      CREATE(lbits)(&zgsz3178);
      CONVERT_OF(lbits, fbits)(&zgsz3178, zv__18, UINT64_C(32) , true);
      sail_int zgsz3179;
      CREATE(sail_int)(&zgsz3179);
      CONVERT_OF(sail_int, mach_int)(&zgsz3179, INT64_C(24));
      sail_int zgsz3180;
      CREATE(sail_int)(&zgsz3180);
      CONVERT_OF(sail_int, mach_int)(&zgsz3180, INT64_C(20));
      lbits zgsz3181;
      CREATE(lbits)(&zgsz3181);
      vector_subrange_lbits(&zgsz3181, zgsz3178, zgsz3179, zgsz3180);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz3181, true);
      KILL(lbits)(&zgsz3181);
      KILL(sail_int)(&zgsz3180);
      KILL(sail_int)(&zgsz3179);
      KILL(lbits)(&zgsz3178);
    }
    uint64_t zrs1;
    {
      lbits zgsz3182;
      CREATE(lbits)(&zgsz3182);
      CONVERT_OF(lbits, fbits)(&zgsz3182, zv__18, UINT64_C(32) , true);
      sail_int zgsz3183;
      CREATE(sail_int)(&zgsz3183);
      CONVERT_OF(sail_int, mach_int)(&zgsz3183, INT64_C(19));
      sail_int zgsz3184;
      CREATE(sail_int)(&zgsz3184);
      CONVERT_OF(sail_int, mach_int)(&zgsz3184, INT64_C(15));
      lbits zgsz3185;
      CREATE(lbits)(&zgsz3185);
      vector_subrange_lbits(&zgsz3185, zgsz3182, zgsz3183, zgsz3184);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3185, true);
      KILL(lbits)(&zgsz3185);
      KILL(sail_int)(&zgsz3184);
      KILL(sail_int)(&zgsz3183);
      KILL(lbits)(&zgsz3182);
    }
    uint64_t zrd;
    {
      lbits zgsz3186;
      CREATE(lbits)(&zgsz3186);
      CONVERT_OF(lbits, fbits)(&zgsz3186, zv__18, UINT64_C(32) , true);
      sail_int zgsz3187;
      CREATE(sail_int)(&zgsz3187);
      CONVERT_OF(sail_int, mach_int)(&zgsz3187, INT64_C(11));
      sail_int zgsz3188;
      CREATE(sail_int)(&zgsz3188);
      CONVERT_OF(sail_int, mach_int)(&zgsz3188, INT64_C(7));
      lbits zgsz3189;
      CREATE(lbits)(&zgsz3189);
      vector_subrange_lbits(&zgsz3189, zgsz3186, zgsz3187, zgsz3188);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3189, true);
      KILL(lbits)(&zgsz3189);
      KILL(sail_int)(&zgsz3188);
      KILL(sail_int)(&zgsz3187);
      KILL(lbits)(&zgsz3186);
    }
    struct zast zgaz324;
    CREATE(zast)(&zgaz324);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3190;
      zgsz3190.ztup0 = zrs2;
      zgsz3190.ztup1 = zrs1;
      zgsz3190.ztup2 = zrd;
      zgsz3190.ztup3 = zREM;
      zRTYPE(&zgaz324, zgsz3190);
    
    }
    {
      struct zast zgsz3584;
      CREATE(zast)(&zgsz3584);
      COPY(zast)(&zgsz3584, zgaz324);
      zSomez3z5unionz0zzast(&zgsz32, zgsz3584);
      KILL(zast)(&zgsz3584);
    }
    KILL(zast)(&zgaz324);
  
  
  
  
    goto finish_match_2;
  }
case_9: ;
  {
    uint64_t zv__21;
    zv__21 = zmergez3var;
    uint64_t zgaz329;
    {
      lbits zgsz3192;
      CREATE(lbits)(&zgsz3192);
      CONVERT_OF(lbits, fbits)(&zgsz3192, zv__21, UINT64_C(32) , true);
      sail_int zgsz3193;
      CREATE(sail_int)(&zgsz3193);
      CONVERT_OF(sail_int, mach_int)(&zgsz3193, INT64_C(6));
      sail_int zgsz3194;
      CREATE(sail_int)(&zgsz3194);
      CONVERT_OF(sail_int, mach_int)(&zgsz3194, INT64_C(0));
      lbits zgsz3195;
      CREATE(lbits)(&zgsz3195);
      vector_subrange_lbits(&zgsz3195, zgsz3192, zgsz3193, zgsz3194);
      zgaz329 = CONVERT_OF(fbits, lbits)(zgsz3195, true);
      KILL(lbits)(&zgsz3195);
      KILL(sail_int)(&zgsz3194);
      KILL(sail_int)(&zgsz3193);
      KILL(lbits)(&zgsz3192);
    }
    bool zgsz3213;
    {
      lbits zgsz3215;
      CREATE(lbits)(&zgsz3215);
      CONVERT_OF(lbits, fbits)(&zgsz3215, UINT64_C(0b0010011), UINT64_C(7) , true);
      lbits zgsz3214;
      CREATE(lbits)(&zgsz3214);
      CONVERT_OF(lbits, fbits)(&zgsz3214, zgaz329, UINT64_C(7) , true);
      zgsz3213 = eq_bits(zgsz3214, zgsz3215);
      KILL(lbits)(&zgsz3215);
      KILL(lbits)(&zgsz3214);
    }
  
    if (!(zgsz3213)) {
  
    goto case_10;
    }
    uint64_t zimm;
    {
      lbits zgsz3196;
      CREATE(lbits)(&zgsz3196);
      CONVERT_OF(lbits, fbits)(&zgsz3196, zv__21, UINT64_C(32) , true);
      sail_int zgsz3197;
      CREATE(sail_int)(&zgsz3197);
      CONVERT_OF(sail_int, mach_int)(&zgsz3197, INT64_C(31));
      sail_int zgsz3198;
      CREATE(sail_int)(&zgsz3198);
      CONVERT_OF(sail_int, mach_int)(&zgsz3198, INT64_C(20));
      lbits zgsz3199;
      CREATE(lbits)(&zgsz3199);
      vector_subrange_lbits(&zgsz3199, zgsz3196, zgsz3197, zgsz3198);
      zimm = CONVERT_OF(fbits, lbits)(zgsz3199, true);
      KILL(lbits)(&zgsz3199);
      KILL(sail_int)(&zgsz3198);
      KILL(sail_int)(&zgsz3197);
      KILL(lbits)(&zgsz3196);
    }
    uint64_t zrs1;
    {
      lbits zgsz3200;
      CREATE(lbits)(&zgsz3200);
      CONVERT_OF(lbits, fbits)(&zgsz3200, zv__21, UINT64_C(32) , true);
      sail_int zgsz3201;
      CREATE(sail_int)(&zgsz3201);
      CONVERT_OF(sail_int, mach_int)(&zgsz3201, INT64_C(19));
      sail_int zgsz3202;
      CREATE(sail_int)(&zgsz3202);
      CONVERT_OF(sail_int, mach_int)(&zgsz3202, INT64_C(15));
      lbits zgsz3203;
      CREATE(lbits)(&zgsz3203);
      vector_subrange_lbits(&zgsz3203, zgsz3200, zgsz3201, zgsz3202);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3203, true);
      KILL(lbits)(&zgsz3203);
      KILL(sail_int)(&zgsz3202);
      KILL(sail_int)(&zgsz3201);
      KILL(lbits)(&zgsz3200);
    }
    uint64_t zrd;
    {
      lbits zgsz3204;
      CREATE(lbits)(&zgsz3204);
      CONVERT_OF(lbits, fbits)(&zgsz3204, zv__21, UINT64_C(32) , true);
      sail_int zgsz3205;
      CREATE(sail_int)(&zgsz3205);
      CONVERT_OF(sail_int, mach_int)(&zgsz3205, INT64_C(11));
      sail_int zgsz3206;
      CREATE(sail_int)(&zgsz3206);
      CONVERT_OF(sail_int, mach_int)(&zgsz3206, INT64_C(7));
      lbits zgsz3207;
      CREATE(lbits)(&zgsz3207);
      vector_subrange_lbits(&zgsz3207, zgsz3204, zgsz3205, zgsz3206);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3207, true);
      KILL(lbits)(&zgsz3207);
      KILL(sail_int)(&zgsz3206);
      KILL(sail_int)(&zgsz3205);
      KILL(lbits)(&zgsz3204);
    }
    uint64_t zimmshadowz30;
    {
      lbits zgsz3208;
      CREATE(lbits)(&zgsz3208);
      CONVERT_OF(lbits, fbits)(&zgsz3208, zv__21, UINT64_C(32) , true);
      sail_int zgsz3209;
      CREATE(sail_int)(&zgsz3209);
      CONVERT_OF(sail_int, mach_int)(&zgsz3209, INT64_C(31));
      sail_int zgsz3210;
      CREATE(sail_int)(&zgsz3210);
      CONVERT_OF(sail_int, mach_int)(&zgsz3210, INT64_C(20));
      lbits zgsz3211;
      CREATE(lbits)(&zgsz3211);
      vector_subrange_lbits(&zgsz3211, zgsz3208, zgsz3209, zgsz3210);
      zimmshadowz30 = CONVERT_OF(fbits, lbits)(zgsz3211, true);
      KILL(lbits)(&zgsz3211);
      KILL(sail_int)(&zgsz3210);
      KILL(sail_int)(&zgsz3209);
      KILL(lbits)(&zgsz3208);
    }
    struct zast zgaz328;
    CREATE(zast)(&zgaz328);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3212;
      zgsz3212.ztup0 = zimmshadowz30;
      zgsz3212.ztup1 = zrs1;
      zgsz3212.ztup2 = zrd;
      zgsz3212.ztup3 = zADDI;
      zITYPE(&zgaz328, zgsz3212);
    
    }
    {
      struct zast zgsz3585;
      CREATE(zast)(&zgsz3585);
      COPY(zast)(&zgsz3585, zgaz328);
      zSomez3z5unionz0zzast(&zgsz32, zgsz3585);
      KILL(zast)(&zgsz3585);
    }
    KILL(zast)(&zgaz328);
  
  
  
  
  
    goto finish_match_2;
  }
case_10: ;
  {
    uint64_t zv__23;
    zv__23 = zmergez3var;
    uint64_t zgaz331;
    {
      lbits zgsz3216;
      CREATE(lbits)(&zgsz3216);
      CONVERT_OF(lbits, fbits)(&zgsz3216, zv__23, UINT64_C(32) , true);
      sail_int zgsz3217;
      CREATE(sail_int)(&zgsz3217);
      CONVERT_OF(sail_int, mach_int)(&zgsz3217, INT64_C(6));
      sail_int zgsz3218;
      CREATE(sail_int)(&zgsz3218);
      CONVERT_OF(sail_int, mach_int)(&zgsz3218, INT64_C(0));
      lbits zgsz3219;
      CREATE(lbits)(&zgsz3219);
      vector_subrange_lbits(&zgsz3219, zgsz3216, zgsz3217, zgsz3218);
      zgaz331 = CONVERT_OF(fbits, lbits)(zgsz3219, true);
      KILL(lbits)(&zgsz3219);
      KILL(sail_int)(&zgsz3218);
      KILL(sail_int)(&zgsz3217);
      KILL(lbits)(&zgsz3216);
    }
    bool zgsz3237;
    {
      lbits zgsz3239;
      CREATE(lbits)(&zgsz3239);
      CONVERT_OF(lbits, fbits)(&zgsz3239, UINT64_C(0b0010011), UINT64_C(7) , true);
      lbits zgsz3238;
      CREATE(lbits)(&zgsz3238);
      CONVERT_OF(lbits, fbits)(&zgsz3238, zgaz331, UINT64_C(7) , true);
      zgsz3237 = eq_bits(zgsz3238, zgsz3239);
      KILL(lbits)(&zgsz3239);
      KILL(lbits)(&zgsz3238);
    }
  
    if (!(zgsz3237)) {
  
    goto case_11;
    }
    uint64_t zimm;
    {
      lbits zgsz3220;
      CREATE(lbits)(&zgsz3220);
      CONVERT_OF(lbits, fbits)(&zgsz3220, zv__23, UINT64_C(32) , true);
      sail_int zgsz3221;
      CREATE(sail_int)(&zgsz3221);
      CONVERT_OF(sail_int, mach_int)(&zgsz3221, INT64_C(31));
      sail_int zgsz3222;
      CREATE(sail_int)(&zgsz3222);
      CONVERT_OF(sail_int, mach_int)(&zgsz3222, INT64_C(20));
      lbits zgsz3223;
      CREATE(lbits)(&zgsz3223);
      vector_subrange_lbits(&zgsz3223, zgsz3220, zgsz3221, zgsz3222);
      zimm = CONVERT_OF(fbits, lbits)(zgsz3223, true);
      KILL(lbits)(&zgsz3223);
      KILL(sail_int)(&zgsz3222);
      KILL(sail_int)(&zgsz3221);
      KILL(lbits)(&zgsz3220);
    }
    uint64_t zrs1;
    {
      lbits zgsz3224;
      CREATE(lbits)(&zgsz3224);
      CONVERT_OF(lbits, fbits)(&zgsz3224, zv__23, UINT64_C(32) , true);
      sail_int zgsz3225;
      CREATE(sail_int)(&zgsz3225);
      CONVERT_OF(sail_int, mach_int)(&zgsz3225, INT64_C(19));
      sail_int zgsz3226;
      CREATE(sail_int)(&zgsz3226);
      CONVERT_OF(sail_int, mach_int)(&zgsz3226, INT64_C(15));
      lbits zgsz3227;
      CREATE(lbits)(&zgsz3227);
      vector_subrange_lbits(&zgsz3227, zgsz3224, zgsz3225, zgsz3226);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3227, true);
      KILL(lbits)(&zgsz3227);
      KILL(sail_int)(&zgsz3226);
      KILL(sail_int)(&zgsz3225);
      KILL(lbits)(&zgsz3224);
    }
    uint64_t zrd;
    {
      lbits zgsz3228;
      CREATE(lbits)(&zgsz3228);
      CONVERT_OF(lbits, fbits)(&zgsz3228, zv__23, UINT64_C(32) , true);
      sail_int zgsz3229;
      CREATE(sail_int)(&zgsz3229);
      CONVERT_OF(sail_int, mach_int)(&zgsz3229, INT64_C(11));
      sail_int zgsz3230;
      CREATE(sail_int)(&zgsz3230);
      CONVERT_OF(sail_int, mach_int)(&zgsz3230, INT64_C(7));
      lbits zgsz3231;
      CREATE(lbits)(&zgsz3231);
      vector_subrange_lbits(&zgsz3231, zgsz3228, zgsz3229, zgsz3230);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3231, true);
      KILL(lbits)(&zgsz3231);
      KILL(sail_int)(&zgsz3230);
      KILL(sail_int)(&zgsz3229);
      KILL(lbits)(&zgsz3228);
    }
    uint64_t zimmshadowz31;
    {
      lbits zgsz3232;
      CREATE(lbits)(&zgsz3232);
      CONVERT_OF(lbits, fbits)(&zgsz3232, zv__23, UINT64_C(32) , true);
      sail_int zgsz3233;
      CREATE(sail_int)(&zgsz3233);
      CONVERT_OF(sail_int, mach_int)(&zgsz3233, INT64_C(31));
      sail_int zgsz3234;
      CREATE(sail_int)(&zgsz3234);
      CONVERT_OF(sail_int, mach_int)(&zgsz3234, INT64_C(20));
      lbits zgsz3235;
      CREATE(lbits)(&zgsz3235);
      vector_subrange_lbits(&zgsz3235, zgsz3232, zgsz3233, zgsz3234);
      zimmshadowz31 = CONVERT_OF(fbits, lbits)(zgsz3235, true);
      KILL(lbits)(&zgsz3235);
      KILL(sail_int)(&zgsz3234);
      KILL(sail_int)(&zgsz3233);
      KILL(lbits)(&zgsz3232);
    }
    struct zast zgaz330;
    CREATE(zast)(&zgaz330);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3236;
      zgsz3236.ztup0 = zimmshadowz31;
      zgsz3236.ztup1 = zrs1;
      zgsz3236.ztup2 = zrd;
      zgsz3236.ztup3 = zSLTI;
      zITYPE(&zgaz330, zgsz3236);
    
    }
    {
      struct zast zgsz3586;
      CREATE(zast)(&zgsz3586);
      COPY(zast)(&zgsz3586, zgaz330);
      zSomez3z5unionz0zzast(&zgsz32, zgsz3586);
      KILL(zast)(&zgsz3586);
    }
    KILL(zast)(&zgaz330);
  
  
  
  
  
    goto finish_match_2;
  }
case_11: ;
  {
    uint64_t zv__25;
    zv__25 = zmergez3var;
    uint64_t zgaz333;
    {
      lbits zgsz3240;
      CREATE(lbits)(&zgsz3240);
      CONVERT_OF(lbits, fbits)(&zgsz3240, zv__25, UINT64_C(32) , true);
      sail_int zgsz3241;
      CREATE(sail_int)(&zgsz3241);
      CONVERT_OF(sail_int, mach_int)(&zgsz3241, INT64_C(6));
      sail_int zgsz3242;
      CREATE(sail_int)(&zgsz3242);
      CONVERT_OF(sail_int, mach_int)(&zgsz3242, INT64_C(0));
      lbits zgsz3243;
      CREATE(lbits)(&zgsz3243);
      vector_subrange_lbits(&zgsz3243, zgsz3240, zgsz3241, zgsz3242);
      zgaz333 = CONVERT_OF(fbits, lbits)(zgsz3243, true);
      KILL(lbits)(&zgsz3243);
      KILL(sail_int)(&zgsz3242);
      KILL(sail_int)(&zgsz3241);
      KILL(lbits)(&zgsz3240);
    }
    bool zgsz3261;
    {
      lbits zgsz3263;
      CREATE(lbits)(&zgsz3263);
      CONVERT_OF(lbits, fbits)(&zgsz3263, UINT64_C(0b0010011), UINT64_C(7) , true);
      lbits zgsz3262;
      CREATE(lbits)(&zgsz3262);
      CONVERT_OF(lbits, fbits)(&zgsz3262, zgaz333, UINT64_C(7) , true);
      zgsz3261 = eq_bits(zgsz3262, zgsz3263);
      KILL(lbits)(&zgsz3263);
      KILL(lbits)(&zgsz3262);
    }
  
    if (!(zgsz3261)) {
  
    goto case_12;
    }
    uint64_t zimm;
    {
      lbits zgsz3244;
      CREATE(lbits)(&zgsz3244);
      CONVERT_OF(lbits, fbits)(&zgsz3244, zv__25, UINT64_C(32) , true);
      sail_int zgsz3245;
      CREATE(sail_int)(&zgsz3245);
      CONVERT_OF(sail_int, mach_int)(&zgsz3245, INT64_C(31));
      sail_int zgsz3246;
      CREATE(sail_int)(&zgsz3246);
      CONVERT_OF(sail_int, mach_int)(&zgsz3246, INT64_C(20));
      lbits zgsz3247;
      CREATE(lbits)(&zgsz3247);
      vector_subrange_lbits(&zgsz3247, zgsz3244, zgsz3245, zgsz3246);
      zimm = CONVERT_OF(fbits, lbits)(zgsz3247, true);
      KILL(lbits)(&zgsz3247);
      KILL(sail_int)(&zgsz3246);
      KILL(sail_int)(&zgsz3245);
      KILL(lbits)(&zgsz3244);
    }
    uint64_t zrs1;
    {
      lbits zgsz3248;
      CREATE(lbits)(&zgsz3248);
      CONVERT_OF(lbits, fbits)(&zgsz3248, zv__25, UINT64_C(32) , true);
      sail_int zgsz3249;
      CREATE(sail_int)(&zgsz3249);
      CONVERT_OF(sail_int, mach_int)(&zgsz3249, INT64_C(19));
      sail_int zgsz3250;
      CREATE(sail_int)(&zgsz3250);
      CONVERT_OF(sail_int, mach_int)(&zgsz3250, INT64_C(15));
      lbits zgsz3251;
      CREATE(lbits)(&zgsz3251);
      vector_subrange_lbits(&zgsz3251, zgsz3248, zgsz3249, zgsz3250);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3251, true);
      KILL(lbits)(&zgsz3251);
      KILL(sail_int)(&zgsz3250);
      KILL(sail_int)(&zgsz3249);
      KILL(lbits)(&zgsz3248);
    }
    uint64_t zrd;
    {
      lbits zgsz3252;
      CREATE(lbits)(&zgsz3252);
      CONVERT_OF(lbits, fbits)(&zgsz3252, zv__25, UINT64_C(32) , true);
      sail_int zgsz3253;
      CREATE(sail_int)(&zgsz3253);
      CONVERT_OF(sail_int, mach_int)(&zgsz3253, INT64_C(11));
      sail_int zgsz3254;
      CREATE(sail_int)(&zgsz3254);
      CONVERT_OF(sail_int, mach_int)(&zgsz3254, INT64_C(7));
      lbits zgsz3255;
      CREATE(lbits)(&zgsz3255);
      vector_subrange_lbits(&zgsz3255, zgsz3252, zgsz3253, zgsz3254);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3255, true);
      KILL(lbits)(&zgsz3255);
      KILL(sail_int)(&zgsz3254);
      KILL(sail_int)(&zgsz3253);
      KILL(lbits)(&zgsz3252);
    }
    uint64_t zimmshadowz32;
    {
      lbits zgsz3256;
      CREATE(lbits)(&zgsz3256);
      CONVERT_OF(lbits, fbits)(&zgsz3256, zv__25, UINT64_C(32) , true);
      sail_int zgsz3257;
      CREATE(sail_int)(&zgsz3257);
      CONVERT_OF(sail_int, mach_int)(&zgsz3257, INT64_C(31));
      sail_int zgsz3258;
      CREATE(sail_int)(&zgsz3258);
      CONVERT_OF(sail_int, mach_int)(&zgsz3258, INT64_C(20));
      lbits zgsz3259;
      CREATE(lbits)(&zgsz3259);
      vector_subrange_lbits(&zgsz3259, zgsz3256, zgsz3257, zgsz3258);
      zimmshadowz32 = CONVERT_OF(fbits, lbits)(zgsz3259, true);
      KILL(lbits)(&zgsz3259);
      KILL(sail_int)(&zgsz3258);
      KILL(sail_int)(&zgsz3257);
      KILL(lbits)(&zgsz3256);
    }
    struct zast zgaz332;
    CREATE(zast)(&zgaz332);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3260;
      zgsz3260.ztup0 = zimmshadowz32;
      zgsz3260.ztup1 = zrs1;
      zgsz3260.ztup2 = zrd;
      zgsz3260.ztup3 = zANDI;
      zITYPE(&zgaz332, zgsz3260);
    
    }
    {
      struct zast zgsz3587;
      CREATE(zast)(&zgsz3587);
      COPY(zast)(&zgsz3587, zgaz332);
      zSomez3z5unionz0zzast(&zgsz32, zgsz3587);
      KILL(zast)(&zgsz3587);
    }
    KILL(zast)(&zgaz332);
  
  
  
  
  
    goto finish_match_2;
  }
case_12: ;
  {
    uint64_t zv__27;
    zv__27 = zmergez3var;
    uint64_t zgaz335;
    {
      lbits zgsz3264;
      CREATE(lbits)(&zgsz3264);
      CONVERT_OF(lbits, fbits)(&zgsz3264, zv__27, UINT64_C(32) , true);
      sail_int zgsz3265;
      CREATE(sail_int)(&zgsz3265);
      CONVERT_OF(sail_int, mach_int)(&zgsz3265, INT64_C(6));
      sail_int zgsz3266;
      CREATE(sail_int)(&zgsz3266);
      CONVERT_OF(sail_int, mach_int)(&zgsz3266, INT64_C(0));
      lbits zgsz3267;
      CREATE(lbits)(&zgsz3267);
      vector_subrange_lbits(&zgsz3267, zgsz3264, zgsz3265, zgsz3266);
      zgaz335 = CONVERT_OF(fbits, lbits)(zgsz3267, true);
      KILL(lbits)(&zgsz3267);
      KILL(sail_int)(&zgsz3266);
      KILL(sail_int)(&zgsz3265);
      KILL(lbits)(&zgsz3264);
    }
    bool zgsz3285;
    {
      lbits zgsz3287;
      CREATE(lbits)(&zgsz3287);
      CONVERT_OF(lbits, fbits)(&zgsz3287, UINT64_C(0b0010011), UINT64_C(7) , true);
      lbits zgsz3286;
      CREATE(lbits)(&zgsz3286);
      CONVERT_OF(lbits, fbits)(&zgsz3286, zgaz335, UINT64_C(7) , true);
      zgsz3285 = eq_bits(zgsz3286, zgsz3287);
      KILL(lbits)(&zgsz3287);
      KILL(lbits)(&zgsz3286);
    }
  
    if (!(zgsz3285)) {
  
    goto case_13;
    }
    uint64_t zimm;
    {
      lbits zgsz3268;
      CREATE(lbits)(&zgsz3268);
      CONVERT_OF(lbits, fbits)(&zgsz3268, zv__27, UINT64_C(32) , true);
      sail_int zgsz3269;
      CREATE(sail_int)(&zgsz3269);
      CONVERT_OF(sail_int, mach_int)(&zgsz3269, INT64_C(31));
      sail_int zgsz3270;
      CREATE(sail_int)(&zgsz3270);
      CONVERT_OF(sail_int, mach_int)(&zgsz3270, INT64_C(20));
      lbits zgsz3271;
      CREATE(lbits)(&zgsz3271);
      vector_subrange_lbits(&zgsz3271, zgsz3268, zgsz3269, zgsz3270);
      zimm = CONVERT_OF(fbits, lbits)(zgsz3271, true);
      KILL(lbits)(&zgsz3271);
      KILL(sail_int)(&zgsz3270);
      KILL(sail_int)(&zgsz3269);
      KILL(lbits)(&zgsz3268);
    }
    uint64_t zrs1;
    {
      lbits zgsz3272;
      CREATE(lbits)(&zgsz3272);
      CONVERT_OF(lbits, fbits)(&zgsz3272, zv__27, UINT64_C(32) , true);
      sail_int zgsz3273;
      CREATE(sail_int)(&zgsz3273);
      CONVERT_OF(sail_int, mach_int)(&zgsz3273, INT64_C(19));
      sail_int zgsz3274;
      CREATE(sail_int)(&zgsz3274);
      CONVERT_OF(sail_int, mach_int)(&zgsz3274, INT64_C(15));
      lbits zgsz3275;
      CREATE(lbits)(&zgsz3275);
      vector_subrange_lbits(&zgsz3275, zgsz3272, zgsz3273, zgsz3274);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3275, true);
      KILL(lbits)(&zgsz3275);
      KILL(sail_int)(&zgsz3274);
      KILL(sail_int)(&zgsz3273);
      KILL(lbits)(&zgsz3272);
    }
    uint64_t zrd;
    {
      lbits zgsz3276;
      CREATE(lbits)(&zgsz3276);
      CONVERT_OF(lbits, fbits)(&zgsz3276, zv__27, UINT64_C(32) , true);
      sail_int zgsz3277;
      CREATE(sail_int)(&zgsz3277);
      CONVERT_OF(sail_int, mach_int)(&zgsz3277, INT64_C(11));
      sail_int zgsz3278;
      CREATE(sail_int)(&zgsz3278);
      CONVERT_OF(sail_int, mach_int)(&zgsz3278, INT64_C(7));
      lbits zgsz3279;
      CREATE(lbits)(&zgsz3279);
      vector_subrange_lbits(&zgsz3279, zgsz3276, zgsz3277, zgsz3278);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3279, true);
      KILL(lbits)(&zgsz3279);
      KILL(sail_int)(&zgsz3278);
      KILL(sail_int)(&zgsz3277);
      KILL(lbits)(&zgsz3276);
    }
    uint64_t zimmshadowz33;
    {
      lbits zgsz3280;
      CREATE(lbits)(&zgsz3280);
      CONVERT_OF(lbits, fbits)(&zgsz3280, zv__27, UINT64_C(32) , true);
      sail_int zgsz3281;
      CREATE(sail_int)(&zgsz3281);
      CONVERT_OF(sail_int, mach_int)(&zgsz3281, INT64_C(31));
      sail_int zgsz3282;
      CREATE(sail_int)(&zgsz3282);
      CONVERT_OF(sail_int, mach_int)(&zgsz3282, INT64_C(20));
      lbits zgsz3283;
      CREATE(lbits)(&zgsz3283);
      vector_subrange_lbits(&zgsz3283, zgsz3280, zgsz3281, zgsz3282);
      zimmshadowz33 = CONVERT_OF(fbits, lbits)(zgsz3283, true);
      KILL(lbits)(&zgsz3283);
      KILL(sail_int)(&zgsz3282);
      KILL(sail_int)(&zgsz3281);
      KILL(lbits)(&zgsz3280);
    }
    struct zast zgaz334;
    CREATE(zast)(&zgaz334);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3284;
      zgsz3284.ztup0 = zimmshadowz33;
      zgsz3284.ztup1 = zrs1;
      zgsz3284.ztup2 = zrd;
      zgsz3284.ztup3 = zORI;
      zITYPE(&zgaz334, zgsz3284);
    
    }
    {
      struct zast zgsz3588;
      CREATE(zast)(&zgsz3588);
      COPY(zast)(&zgsz3588, zgaz334);
      zSomez3z5unionz0zzast(&zgsz32, zgsz3588);
      KILL(zast)(&zgsz3588);
    }
    KILL(zast)(&zgaz334);
  
  
  
  
  
    goto finish_match_2;
  }
case_13: ;
  {
    uint64_t zv__29;
    zv__29 = zmergez3var;
    uint64_t zgaz337;
    {
      lbits zgsz3288;
      CREATE(lbits)(&zgsz3288);
      CONVERT_OF(lbits, fbits)(&zgsz3288, zv__29, UINT64_C(32) , true);
      sail_int zgsz3289;
      CREATE(sail_int)(&zgsz3289);
      CONVERT_OF(sail_int, mach_int)(&zgsz3289, INT64_C(6));
      sail_int zgsz3290;
      CREATE(sail_int)(&zgsz3290);
      CONVERT_OF(sail_int, mach_int)(&zgsz3290, INT64_C(0));
      lbits zgsz3291;
      CREATE(lbits)(&zgsz3291);
      vector_subrange_lbits(&zgsz3291, zgsz3288, zgsz3289, zgsz3290);
      zgaz337 = CONVERT_OF(fbits, lbits)(zgsz3291, true);
      KILL(lbits)(&zgsz3291);
      KILL(sail_int)(&zgsz3290);
      KILL(sail_int)(&zgsz3289);
      KILL(lbits)(&zgsz3288);
    }
    bool zgsz3309;
    {
      lbits zgsz3311;
      CREATE(lbits)(&zgsz3311);
      CONVERT_OF(lbits, fbits)(&zgsz3311, UINT64_C(0b0010011), UINT64_C(7) , true);
      lbits zgsz3310;
      CREATE(lbits)(&zgsz3310);
      CONVERT_OF(lbits, fbits)(&zgsz3310, zgaz337, UINT64_C(7) , true);
      zgsz3309 = eq_bits(zgsz3310, zgsz3311);
      KILL(lbits)(&zgsz3311);
      KILL(lbits)(&zgsz3310);
    }
  
    if (!(zgsz3309)) {
  
    goto case_14;
    }
    uint64_t zimm;
    {
      lbits zgsz3292;
      CREATE(lbits)(&zgsz3292);
      CONVERT_OF(lbits, fbits)(&zgsz3292, zv__29, UINT64_C(32) , true);
      sail_int zgsz3293;
      CREATE(sail_int)(&zgsz3293);
      CONVERT_OF(sail_int, mach_int)(&zgsz3293, INT64_C(31));
      sail_int zgsz3294;
      CREATE(sail_int)(&zgsz3294);
      CONVERT_OF(sail_int, mach_int)(&zgsz3294, INT64_C(20));
      lbits zgsz3295;
      CREATE(lbits)(&zgsz3295);
      vector_subrange_lbits(&zgsz3295, zgsz3292, zgsz3293, zgsz3294);
      zimm = CONVERT_OF(fbits, lbits)(zgsz3295, true);
      KILL(lbits)(&zgsz3295);
      KILL(sail_int)(&zgsz3294);
      KILL(sail_int)(&zgsz3293);
      KILL(lbits)(&zgsz3292);
    }
    uint64_t zrs1;
    {
      lbits zgsz3296;
      CREATE(lbits)(&zgsz3296);
      CONVERT_OF(lbits, fbits)(&zgsz3296, zv__29, UINT64_C(32) , true);
      sail_int zgsz3297;
      CREATE(sail_int)(&zgsz3297);
      CONVERT_OF(sail_int, mach_int)(&zgsz3297, INT64_C(19));
      sail_int zgsz3298;
      CREATE(sail_int)(&zgsz3298);
      CONVERT_OF(sail_int, mach_int)(&zgsz3298, INT64_C(15));
      lbits zgsz3299;
      CREATE(lbits)(&zgsz3299);
      vector_subrange_lbits(&zgsz3299, zgsz3296, zgsz3297, zgsz3298);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3299, true);
      KILL(lbits)(&zgsz3299);
      KILL(sail_int)(&zgsz3298);
      KILL(sail_int)(&zgsz3297);
      KILL(lbits)(&zgsz3296);
    }
    uint64_t zrd;
    {
      lbits zgsz3300;
      CREATE(lbits)(&zgsz3300);
      CONVERT_OF(lbits, fbits)(&zgsz3300, zv__29, UINT64_C(32) , true);
      sail_int zgsz3301;
      CREATE(sail_int)(&zgsz3301);
      CONVERT_OF(sail_int, mach_int)(&zgsz3301, INT64_C(11));
      sail_int zgsz3302;
      CREATE(sail_int)(&zgsz3302);
      CONVERT_OF(sail_int, mach_int)(&zgsz3302, INT64_C(7));
      lbits zgsz3303;
      CREATE(lbits)(&zgsz3303);
      vector_subrange_lbits(&zgsz3303, zgsz3300, zgsz3301, zgsz3302);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3303, true);
      KILL(lbits)(&zgsz3303);
      KILL(sail_int)(&zgsz3302);
      KILL(sail_int)(&zgsz3301);
      KILL(lbits)(&zgsz3300);
    }
    uint64_t zimmshadowz34;
    {
      lbits zgsz3304;
      CREATE(lbits)(&zgsz3304);
      CONVERT_OF(lbits, fbits)(&zgsz3304, zv__29, UINT64_C(32) , true);
      sail_int zgsz3305;
      CREATE(sail_int)(&zgsz3305);
      CONVERT_OF(sail_int, mach_int)(&zgsz3305, INT64_C(31));
      sail_int zgsz3306;
      CREATE(sail_int)(&zgsz3306);
      CONVERT_OF(sail_int, mach_int)(&zgsz3306, INT64_C(20));
      lbits zgsz3307;
      CREATE(lbits)(&zgsz3307);
      vector_subrange_lbits(&zgsz3307, zgsz3304, zgsz3305, zgsz3306);
      zimmshadowz34 = CONVERT_OF(fbits, lbits)(zgsz3307, true);
      KILL(lbits)(&zgsz3307);
      KILL(sail_int)(&zgsz3306);
      KILL(sail_int)(&zgsz3305);
      KILL(lbits)(&zgsz3304);
    }
    struct zast zgaz336;
    CREATE(zast)(&zgaz336);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3308;
      zgsz3308.ztup0 = zimmshadowz34;
      zgsz3308.ztup1 = zrs1;
      zgsz3308.ztup2 = zrd;
      zgsz3308.ztup3 = zXORI;
      zITYPE(&zgaz336, zgsz3308);
    
    }
    {
      struct zast zgsz3589;
      CREATE(zast)(&zgsz3589);
      COPY(zast)(&zgsz3589, zgaz336);
      zSomez3z5unionz0zzast(&zgsz32, zgsz3589);
      KILL(zast)(&zgsz3589);
    }
    KILL(zast)(&zgaz336);
  
  
  
  
  
    goto finish_match_2;
  }
case_14: ;
  {
    uint64_t zv__31;
    zv__31 = zmergez3var;
    uint64_t zgaz339;
    {
      lbits zgsz3312;
      CREATE(lbits)(&zgsz3312);
      CONVERT_OF(lbits, fbits)(&zgsz3312, zv__31, UINT64_C(32) , true);
      sail_int zgsz3313;
      CREATE(sail_int)(&zgsz3313);
      CONVERT_OF(sail_int, mach_int)(&zgsz3313, INT64_C(6));
      sail_int zgsz3314;
      CREATE(sail_int)(&zgsz3314);
      CONVERT_OF(sail_int, mach_int)(&zgsz3314, INT64_C(0));
      lbits zgsz3315;
      CREATE(lbits)(&zgsz3315);
      vector_subrange_lbits(&zgsz3315, zgsz3312, zgsz3313, zgsz3314);
      zgaz339 = CONVERT_OF(fbits, lbits)(zgsz3315, true);
      KILL(lbits)(&zgsz3315);
      KILL(sail_int)(&zgsz3314);
      KILL(sail_int)(&zgsz3313);
      KILL(lbits)(&zgsz3312);
    }
    bool zgsz3333;
    {
      lbits zgsz3335;
      CREATE(lbits)(&zgsz3335);
      CONVERT_OF(lbits, fbits)(&zgsz3335, UINT64_C(0b1100111), UINT64_C(7) , true);
      lbits zgsz3334;
      CREATE(lbits)(&zgsz3334);
      CONVERT_OF(lbits, fbits)(&zgsz3334, zgaz339, UINT64_C(7) , true);
      zgsz3333 = eq_bits(zgsz3334, zgsz3335);
      KILL(lbits)(&zgsz3335);
      KILL(lbits)(&zgsz3334);
    }
  
    if (!(zgsz3333)) {
  
    goto case_15;
    }
    uint64_t zimm;
    {
      lbits zgsz3316;
      CREATE(lbits)(&zgsz3316);
      CONVERT_OF(lbits, fbits)(&zgsz3316, zv__31, UINT64_C(32) , true);
      sail_int zgsz3317;
      CREATE(sail_int)(&zgsz3317);
      CONVERT_OF(sail_int, mach_int)(&zgsz3317, INT64_C(31));
      sail_int zgsz3318;
      CREATE(sail_int)(&zgsz3318);
      CONVERT_OF(sail_int, mach_int)(&zgsz3318, INT64_C(20));
      lbits zgsz3319;
      CREATE(lbits)(&zgsz3319);
      vector_subrange_lbits(&zgsz3319, zgsz3316, zgsz3317, zgsz3318);
      zimm = CONVERT_OF(fbits, lbits)(zgsz3319, true);
      KILL(lbits)(&zgsz3319);
      KILL(sail_int)(&zgsz3318);
      KILL(sail_int)(&zgsz3317);
      KILL(lbits)(&zgsz3316);
    }
    uint64_t zrs1;
    {
      lbits zgsz3320;
      CREATE(lbits)(&zgsz3320);
      CONVERT_OF(lbits, fbits)(&zgsz3320, zv__31, UINT64_C(32) , true);
      sail_int zgsz3321;
      CREATE(sail_int)(&zgsz3321);
      CONVERT_OF(sail_int, mach_int)(&zgsz3321, INT64_C(19));
      sail_int zgsz3322;
      CREATE(sail_int)(&zgsz3322);
      CONVERT_OF(sail_int, mach_int)(&zgsz3322, INT64_C(15));
      lbits zgsz3323;
      CREATE(lbits)(&zgsz3323);
      vector_subrange_lbits(&zgsz3323, zgsz3320, zgsz3321, zgsz3322);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3323, true);
      KILL(lbits)(&zgsz3323);
      KILL(sail_int)(&zgsz3322);
      KILL(sail_int)(&zgsz3321);
      KILL(lbits)(&zgsz3320);
    }
    uint64_t zrd;
    {
      lbits zgsz3324;
      CREATE(lbits)(&zgsz3324);
      CONVERT_OF(lbits, fbits)(&zgsz3324, zv__31, UINT64_C(32) , true);
      sail_int zgsz3325;
      CREATE(sail_int)(&zgsz3325);
      CONVERT_OF(sail_int, mach_int)(&zgsz3325, INT64_C(11));
      sail_int zgsz3326;
      CREATE(sail_int)(&zgsz3326);
      CONVERT_OF(sail_int, mach_int)(&zgsz3326, INT64_C(7));
      lbits zgsz3327;
      CREATE(lbits)(&zgsz3327);
      vector_subrange_lbits(&zgsz3327, zgsz3324, zgsz3325, zgsz3326);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3327, true);
      KILL(lbits)(&zgsz3327);
      KILL(sail_int)(&zgsz3326);
      KILL(sail_int)(&zgsz3325);
      KILL(lbits)(&zgsz3324);
    }
    uint64_t zimmshadowz35;
    {
      lbits zgsz3328;
      CREATE(lbits)(&zgsz3328);
      CONVERT_OF(lbits, fbits)(&zgsz3328, zv__31, UINT64_C(32) , true);
      sail_int zgsz3329;
      CREATE(sail_int)(&zgsz3329);
      CONVERT_OF(sail_int, mach_int)(&zgsz3329, INT64_C(31));
      sail_int zgsz3330;
      CREATE(sail_int)(&zgsz3330);
      CONVERT_OF(sail_int, mach_int)(&zgsz3330, INT64_C(20));
      lbits zgsz3331;
      CREATE(lbits)(&zgsz3331);
      vector_subrange_lbits(&zgsz3331, zgsz3328, zgsz3329, zgsz3330);
      zimmshadowz35 = CONVERT_OF(fbits, lbits)(zgsz3331, true);
      KILL(lbits)(&zgsz3331);
      KILL(sail_int)(&zgsz3330);
      KILL(sail_int)(&zgsz3329);
      KILL(lbits)(&zgsz3328);
    }
    struct zast zgaz338;
    CREATE(zast)(&zgaz338);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3332;
      zgsz3332.ztup0 = zimmshadowz35;
      zgsz3332.ztup1 = zrs1;
      zgsz3332.ztup2 = zrd;
      zgsz3332.ztup3 = zJALR;
      zITYPE(&zgaz338, zgsz3332);
    
    }
    {
      struct zast zgsz3590;
      CREATE(zast)(&zgsz3590);
      COPY(zast)(&zgsz3590, zgaz338);
      zSomez3z5unionz0zzast(&zgsz32, zgsz3590);
      KILL(zast)(&zgsz3590);
    }
    KILL(zast)(&zgaz338);
  
  
  
  
  
    goto finish_match_2;
  }
case_15: ;
  {
    uint64_t zv__33;
    zv__33 = zmergez3var;
    uint64_t zgaz341;
    {
      lbits zgsz3336;
      CREATE(lbits)(&zgsz3336);
      CONVERT_OF(lbits, fbits)(&zgsz3336, zv__33, UINT64_C(32) , true);
      sail_int zgsz3337;
      CREATE(sail_int)(&zgsz3337);
      CONVERT_OF(sail_int, mach_int)(&zgsz3337, INT64_C(6));
      sail_int zgsz3338;
      CREATE(sail_int)(&zgsz3338);
      CONVERT_OF(sail_int, mach_int)(&zgsz3338, INT64_C(0));
      lbits zgsz3339;
      CREATE(lbits)(&zgsz3339);
      vector_subrange_lbits(&zgsz3339, zgsz3336, zgsz3337, zgsz3338);
      zgaz341 = CONVERT_OF(fbits, lbits)(zgsz3339, true);
      KILL(lbits)(&zgsz3339);
      KILL(sail_int)(&zgsz3338);
      KILL(sail_int)(&zgsz3337);
      KILL(lbits)(&zgsz3336);
    }
    bool zgsz3357;
    {
      lbits zgsz3359;
      CREATE(lbits)(&zgsz3359);
      CONVERT_OF(lbits, fbits)(&zgsz3359, UINT64_C(0b0000011), UINT64_C(7) , true);
      lbits zgsz3358;
      CREATE(lbits)(&zgsz3358);
      CONVERT_OF(lbits, fbits)(&zgsz3358, zgaz341, UINT64_C(7) , true);
      zgsz3357 = eq_bits(zgsz3358, zgsz3359);
      KILL(lbits)(&zgsz3359);
      KILL(lbits)(&zgsz3358);
    }
  
    if (!(zgsz3357)) {
  
    goto case_16;
    }
    uint64_t zimm;
    {
      lbits zgsz3340;
      CREATE(lbits)(&zgsz3340);
      CONVERT_OF(lbits, fbits)(&zgsz3340, zv__33, UINT64_C(32) , true);
      sail_int zgsz3341;
      CREATE(sail_int)(&zgsz3341);
      CONVERT_OF(sail_int, mach_int)(&zgsz3341, INT64_C(31));
      sail_int zgsz3342;
      CREATE(sail_int)(&zgsz3342);
      CONVERT_OF(sail_int, mach_int)(&zgsz3342, INT64_C(20));
      lbits zgsz3343;
      CREATE(lbits)(&zgsz3343);
      vector_subrange_lbits(&zgsz3343, zgsz3340, zgsz3341, zgsz3342);
      zimm = CONVERT_OF(fbits, lbits)(zgsz3343, true);
      KILL(lbits)(&zgsz3343);
      KILL(sail_int)(&zgsz3342);
      KILL(sail_int)(&zgsz3341);
      KILL(lbits)(&zgsz3340);
    }
    uint64_t zrs1;
    {
      lbits zgsz3344;
      CREATE(lbits)(&zgsz3344);
      CONVERT_OF(lbits, fbits)(&zgsz3344, zv__33, UINT64_C(32) , true);
      sail_int zgsz3345;
      CREATE(sail_int)(&zgsz3345);
      CONVERT_OF(sail_int, mach_int)(&zgsz3345, INT64_C(19));
      sail_int zgsz3346;
      CREATE(sail_int)(&zgsz3346);
      CONVERT_OF(sail_int, mach_int)(&zgsz3346, INT64_C(15));
      lbits zgsz3347;
      CREATE(lbits)(&zgsz3347);
      vector_subrange_lbits(&zgsz3347, zgsz3344, zgsz3345, zgsz3346);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3347, true);
      KILL(lbits)(&zgsz3347);
      KILL(sail_int)(&zgsz3346);
      KILL(sail_int)(&zgsz3345);
      KILL(lbits)(&zgsz3344);
    }
    uint64_t zrd;
    {
      lbits zgsz3348;
      CREATE(lbits)(&zgsz3348);
      CONVERT_OF(lbits, fbits)(&zgsz3348, zv__33, UINT64_C(32) , true);
      sail_int zgsz3349;
      CREATE(sail_int)(&zgsz3349);
      CONVERT_OF(sail_int, mach_int)(&zgsz3349, INT64_C(11));
      sail_int zgsz3350;
      CREATE(sail_int)(&zgsz3350);
      CONVERT_OF(sail_int, mach_int)(&zgsz3350, INT64_C(7));
      lbits zgsz3351;
      CREATE(lbits)(&zgsz3351);
      vector_subrange_lbits(&zgsz3351, zgsz3348, zgsz3349, zgsz3350);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3351, true);
      KILL(lbits)(&zgsz3351);
      KILL(sail_int)(&zgsz3350);
      KILL(sail_int)(&zgsz3349);
      KILL(lbits)(&zgsz3348);
    }
    uint64_t zimmshadowz36;
    {
      lbits zgsz3352;
      CREATE(lbits)(&zgsz3352);
      CONVERT_OF(lbits, fbits)(&zgsz3352, zv__33, UINT64_C(32) , true);
      sail_int zgsz3353;
      CREATE(sail_int)(&zgsz3353);
      CONVERT_OF(sail_int, mach_int)(&zgsz3353, INT64_C(31));
      sail_int zgsz3354;
      CREATE(sail_int)(&zgsz3354);
      CONVERT_OF(sail_int, mach_int)(&zgsz3354, INT64_C(20));
      lbits zgsz3355;
      CREATE(lbits)(&zgsz3355);
      vector_subrange_lbits(&zgsz3355, zgsz3352, zgsz3353, zgsz3354);
      zimmshadowz36 = CONVERT_OF(fbits, lbits)(zgsz3355, true);
      KILL(lbits)(&zgsz3355);
      KILL(sail_int)(&zgsz3354);
      KILL(sail_int)(&zgsz3353);
      KILL(lbits)(&zgsz3352);
    }
    struct zast zgaz340;
    CREATE(zast)(&zgaz340);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3356;
      zgsz3356.ztup0 = zimmshadowz36;
      zgsz3356.ztup1 = zrs1;
      zgsz3356.ztup2 = zrd;
      zgsz3356.ztup3 = zLW;
      zITYPE(&zgaz340, zgsz3356);
    
    }
    {
      struct zast zgsz3591;
      CREATE(zast)(&zgsz3591);
      COPY(zast)(&zgsz3591, zgaz340);
      zSomez3z5unionz0zzast(&zgsz32, zgsz3591);
      KILL(zast)(&zgsz3591);
    }
    KILL(zast)(&zgaz340);
  
  
  
  
  
    goto finish_match_2;
  }
case_16: ;
  {
    uint64_t zv__35;
    zv__35 = zmergez3var;
    uint64_t zgaz343;
    {
      lbits zgsz3360;
      CREATE(lbits)(&zgsz3360);
      CONVERT_OF(lbits, fbits)(&zgsz3360, zv__35, UINT64_C(32) , true);
      sail_int zgsz3361;
      CREATE(sail_int)(&zgsz3361);
      CONVERT_OF(sail_int, mach_int)(&zgsz3361, INT64_C(6));
      sail_int zgsz3362;
      CREATE(sail_int)(&zgsz3362);
      CONVERT_OF(sail_int, mach_int)(&zgsz3362, INT64_C(0));
      lbits zgsz3363;
      CREATE(lbits)(&zgsz3363);
      vector_subrange_lbits(&zgsz3363, zgsz3360, zgsz3361, zgsz3362);
      zgaz343 = CONVERT_OF(fbits, lbits)(zgsz3363, true);
      KILL(lbits)(&zgsz3363);
      KILL(sail_int)(&zgsz3362);
      KILL(sail_int)(&zgsz3361);
      KILL(lbits)(&zgsz3360);
    }
    bool zgsz3385;
    {
      lbits zgsz3387;
      CREATE(lbits)(&zgsz3387);
      CONVERT_OF(lbits, fbits)(&zgsz3387, UINT64_C(0b0100011), UINT64_C(7) , true);
      lbits zgsz3386;
      CREATE(lbits)(&zgsz3386);
      CONVERT_OF(lbits, fbits)(&zgsz3386, zgaz343, UINT64_C(7) , true);
      zgsz3385 = eq_bits(zgsz3386, zgsz3387);
      KILL(lbits)(&zgsz3387);
      KILL(lbits)(&zgsz3386);
    }
  
    if (!(zgsz3385)) {
  
    goto case_17;
    }
    uint64_t zimm2;
    {
      lbits zgsz3364;
      CREATE(lbits)(&zgsz3364);
      CONVERT_OF(lbits, fbits)(&zgsz3364, zv__35, UINT64_C(32) , true);
      sail_int zgsz3365;
      CREATE(sail_int)(&zgsz3365);
      CONVERT_OF(sail_int, mach_int)(&zgsz3365, INT64_C(31));
      sail_int zgsz3366;
      CREATE(sail_int)(&zgsz3366);
      CONVERT_OF(sail_int, mach_int)(&zgsz3366, INT64_C(25));
      lbits zgsz3367;
      CREATE(lbits)(&zgsz3367);
      vector_subrange_lbits(&zgsz3367, zgsz3364, zgsz3365, zgsz3366);
      zimm2 = CONVERT_OF(fbits, lbits)(zgsz3367, true);
      KILL(lbits)(&zgsz3367);
      KILL(sail_int)(&zgsz3366);
      KILL(sail_int)(&zgsz3365);
      KILL(lbits)(&zgsz3364);
    }
    uint64_t zrs2;
    {
      lbits zgsz3368;
      CREATE(lbits)(&zgsz3368);
      CONVERT_OF(lbits, fbits)(&zgsz3368, zv__35, UINT64_C(32) , true);
      sail_int zgsz3369;
      CREATE(sail_int)(&zgsz3369);
      CONVERT_OF(sail_int, mach_int)(&zgsz3369, INT64_C(24));
      sail_int zgsz3370;
      CREATE(sail_int)(&zgsz3370);
      CONVERT_OF(sail_int, mach_int)(&zgsz3370, INT64_C(20));
      lbits zgsz3371;
      CREATE(lbits)(&zgsz3371);
      vector_subrange_lbits(&zgsz3371, zgsz3368, zgsz3369, zgsz3370);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz3371, true);
      KILL(lbits)(&zgsz3371);
      KILL(sail_int)(&zgsz3370);
      KILL(sail_int)(&zgsz3369);
      KILL(lbits)(&zgsz3368);
    }
    uint64_t zrs1;
    {
      lbits zgsz3372;
      CREATE(lbits)(&zgsz3372);
      CONVERT_OF(lbits, fbits)(&zgsz3372, zv__35, UINT64_C(32) , true);
      sail_int zgsz3373;
      CREATE(sail_int)(&zgsz3373);
      CONVERT_OF(sail_int, mach_int)(&zgsz3373, INT64_C(19));
      sail_int zgsz3374;
      CREATE(sail_int)(&zgsz3374);
      CONVERT_OF(sail_int, mach_int)(&zgsz3374, INT64_C(15));
      lbits zgsz3375;
      CREATE(lbits)(&zgsz3375);
      vector_subrange_lbits(&zgsz3375, zgsz3372, zgsz3373, zgsz3374);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3375, true);
      KILL(lbits)(&zgsz3375);
      KILL(sail_int)(&zgsz3374);
      KILL(sail_int)(&zgsz3373);
      KILL(lbits)(&zgsz3372);
    }
    uint64_t zimm2shadowz37;
    {
      lbits zgsz3376;
      CREATE(lbits)(&zgsz3376);
      CONVERT_OF(lbits, fbits)(&zgsz3376, zv__35, UINT64_C(32) , true);
      sail_int zgsz3377;
      CREATE(sail_int)(&zgsz3377);
      CONVERT_OF(sail_int, mach_int)(&zgsz3377, INT64_C(31));
      sail_int zgsz3378;
      CREATE(sail_int)(&zgsz3378);
      CONVERT_OF(sail_int, mach_int)(&zgsz3378, INT64_C(25));
      lbits zgsz3379;
      CREATE(lbits)(&zgsz3379);
      vector_subrange_lbits(&zgsz3379, zgsz3376, zgsz3377, zgsz3378);
      zimm2shadowz37 = CONVERT_OF(fbits, lbits)(zgsz3379, true);
      KILL(lbits)(&zgsz3379);
      KILL(sail_int)(&zgsz3378);
      KILL(sail_int)(&zgsz3377);
      KILL(lbits)(&zgsz3376);
    }
    uint64_t zimm1;
    {
      lbits zgsz3380;
      CREATE(lbits)(&zgsz3380);
      CONVERT_OF(lbits, fbits)(&zgsz3380, zv__35, UINT64_C(32) , true);
      sail_int zgsz3381;
      CREATE(sail_int)(&zgsz3381);
      CONVERT_OF(sail_int, mach_int)(&zgsz3381, INT64_C(11));
      sail_int zgsz3382;
      CREATE(sail_int)(&zgsz3382);
      CONVERT_OF(sail_int, mach_int)(&zgsz3382, INT64_C(7));
      lbits zgsz3383;
      CREATE(lbits)(&zgsz3383);
      vector_subrange_lbits(&zgsz3383, zgsz3380, zgsz3381, zgsz3382);
      zimm1 = CONVERT_OF(fbits, lbits)(zgsz3383, true);
      KILL(lbits)(&zgsz3383);
      KILL(sail_int)(&zgsz3382);
      KILL(sail_int)(&zgsz3381);
      KILL(lbits)(&zgsz3380);
    }
    struct zast zgaz342;
    CREATE(zast)(&zgaz342);
    {
      struct ztuple_z8z5bv7zCz0z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzsopz9 zgsz3384;
      zgsz3384.ztup0 = zimm2shadowz37;
      zgsz3384.ztup1 = zrs2;
      zgsz3384.ztup2 = zrs1;
      zgsz3384.ztup3 = zimm1;
      zgsz3384.ztup4 = zSW;
      zSTYPE(&zgaz342, zgsz3384);
    
    }
    {
      struct zast zgsz3592;
      CREATE(zast)(&zgsz3592);
      COPY(zast)(&zgsz3592, zgaz342);
      zSomez3z5unionz0zzast(&zgsz32, zgsz3592);
      KILL(zast)(&zgsz3592);
    }
    KILL(zast)(&zgaz342);
  
  
  
  
  
  
    goto finish_match_2;
  }
case_17: ;
  {
    uint64_t zv__37;
    zv__37 = zmergez3var;
    uint64_t zgaz345;
    {
      lbits zgsz3388;
      CREATE(lbits)(&zgsz3388);
      CONVERT_OF(lbits, fbits)(&zgsz3388, zv__37, UINT64_C(32) , true);
      sail_int zgsz3389;
      CREATE(sail_int)(&zgsz3389);
      CONVERT_OF(sail_int, mach_int)(&zgsz3389, INT64_C(6));
      sail_int zgsz3390;
      CREATE(sail_int)(&zgsz3390);
      CONVERT_OF(sail_int, mach_int)(&zgsz3390, INT64_C(0));
      lbits zgsz3391;
      CREATE(lbits)(&zgsz3391);
      vector_subrange_lbits(&zgsz3391, zgsz3388, zgsz3389, zgsz3390);
      zgaz345 = CONVERT_OF(fbits, lbits)(zgsz3391, true);
      KILL(lbits)(&zgsz3391);
      KILL(sail_int)(&zgsz3390);
      KILL(sail_int)(&zgsz3389);
      KILL(lbits)(&zgsz3388);
    }
    bool zgsz3421;
    {
      lbits zgsz3423;
      CREATE(lbits)(&zgsz3423);
      CONVERT_OF(lbits, fbits)(&zgsz3423, UINT64_C(0b1100011), UINT64_C(7) , true);
      lbits zgsz3422;
      CREATE(lbits)(&zgsz3422);
      CONVERT_OF(lbits, fbits)(&zgsz3422, zgaz345, UINT64_C(7) , true);
      zgsz3421 = eq_bits(zgsz3422, zgsz3423);
      KILL(lbits)(&zgsz3423);
      KILL(lbits)(&zgsz3422);
    }
  
    if (!(zgsz3421)) {
  
    goto case_18;
    }
    uint64_t zimm4;
    {
      lbits zgsz3392;
      CREATE(lbits)(&zgsz3392);
      CONVERT_OF(lbits, fbits)(&zgsz3392, zv__37, UINT64_C(32) , true);
      sail_int zgsz3393;
      CREATE(sail_int)(&zgsz3393);
      CONVERT_OF(sail_int, mach_int)(&zgsz3393, INT64_C(31));
      sail_int zgsz3394;
      CREATE(sail_int)(&zgsz3394);
      CONVERT_OF(sail_int, mach_int)(&zgsz3394, INT64_C(31));
      lbits zgsz3395;
      CREATE(lbits)(&zgsz3395);
      vector_subrange_lbits(&zgsz3395, zgsz3392, zgsz3393, zgsz3394);
      zimm4 = CONVERT_OF(fbits, lbits)(zgsz3395, true);
      KILL(lbits)(&zgsz3395);
      KILL(sail_int)(&zgsz3394);
      KILL(sail_int)(&zgsz3393);
      KILL(lbits)(&zgsz3392);
    }
    uint64_t zrs2;
    {
      lbits zgsz3396;
      CREATE(lbits)(&zgsz3396);
      CONVERT_OF(lbits, fbits)(&zgsz3396, zv__37, UINT64_C(32) , true);
      sail_int zgsz3397;
      CREATE(sail_int)(&zgsz3397);
      CONVERT_OF(sail_int, mach_int)(&zgsz3397, INT64_C(24));
      sail_int zgsz3398;
      CREATE(sail_int)(&zgsz3398);
      CONVERT_OF(sail_int, mach_int)(&zgsz3398, INT64_C(20));
      lbits zgsz3399;
      CREATE(lbits)(&zgsz3399);
      vector_subrange_lbits(&zgsz3399, zgsz3396, zgsz3397, zgsz3398);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz3399, true);
      KILL(lbits)(&zgsz3399);
      KILL(sail_int)(&zgsz3398);
      KILL(sail_int)(&zgsz3397);
      KILL(lbits)(&zgsz3396);
    }
    uint64_t zrs1;
    {
      lbits zgsz3400;
      CREATE(lbits)(&zgsz3400);
      CONVERT_OF(lbits, fbits)(&zgsz3400, zv__37, UINT64_C(32) , true);
      sail_int zgsz3401;
      CREATE(sail_int)(&zgsz3401);
      CONVERT_OF(sail_int, mach_int)(&zgsz3401, INT64_C(19));
      sail_int zgsz3402;
      CREATE(sail_int)(&zgsz3402);
      CONVERT_OF(sail_int, mach_int)(&zgsz3402, INT64_C(15));
      lbits zgsz3403;
      CREATE(lbits)(&zgsz3403);
      vector_subrange_lbits(&zgsz3403, zgsz3400, zgsz3401, zgsz3402);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3403, true);
      KILL(lbits)(&zgsz3403);
      KILL(sail_int)(&zgsz3402);
      KILL(sail_int)(&zgsz3401);
      KILL(lbits)(&zgsz3400);
    }
    uint64_t zimm4shadowz38;
    {
      lbits zgsz3404;
      CREATE(lbits)(&zgsz3404);
      CONVERT_OF(lbits, fbits)(&zgsz3404, zv__37, UINT64_C(32) , true);
      sail_int zgsz3405;
      CREATE(sail_int)(&zgsz3405);
      CONVERT_OF(sail_int, mach_int)(&zgsz3405, INT64_C(31));
      sail_int zgsz3406;
      CREATE(sail_int)(&zgsz3406);
      CONVERT_OF(sail_int, mach_int)(&zgsz3406, INT64_C(31));
      lbits zgsz3407;
      CREATE(lbits)(&zgsz3407);
      vector_subrange_lbits(&zgsz3407, zgsz3404, zgsz3405, zgsz3406);
      zimm4shadowz38 = CONVERT_OF(fbits, lbits)(zgsz3407, true);
      KILL(lbits)(&zgsz3407);
      KILL(sail_int)(&zgsz3406);
      KILL(sail_int)(&zgsz3405);
      KILL(lbits)(&zgsz3404);
    }
    uint64_t zimm3;
    {
      lbits zgsz3408;
      CREATE(lbits)(&zgsz3408);
      CONVERT_OF(lbits, fbits)(&zgsz3408, zv__37, UINT64_C(32) , true);
      sail_int zgsz3409;
      CREATE(sail_int)(&zgsz3409);
      CONVERT_OF(sail_int, mach_int)(&zgsz3409, INT64_C(7));
      sail_int zgsz3410;
      CREATE(sail_int)(&zgsz3410);
      CONVERT_OF(sail_int, mach_int)(&zgsz3410, INT64_C(7));
      lbits zgsz3411;
      CREATE(lbits)(&zgsz3411);
      vector_subrange_lbits(&zgsz3411, zgsz3408, zgsz3409, zgsz3410);
      zimm3 = CONVERT_OF(fbits, lbits)(zgsz3411, true);
      KILL(lbits)(&zgsz3411);
      KILL(sail_int)(&zgsz3410);
      KILL(sail_int)(&zgsz3409);
      KILL(lbits)(&zgsz3408);
    }
    uint64_t zimm2;
    {
      lbits zgsz3412;
      CREATE(lbits)(&zgsz3412);
      CONVERT_OF(lbits, fbits)(&zgsz3412, zv__37, UINT64_C(32) , true);
      sail_int zgsz3413;
      CREATE(sail_int)(&zgsz3413);
      CONVERT_OF(sail_int, mach_int)(&zgsz3413, INT64_C(30));
      sail_int zgsz3414;
      CREATE(sail_int)(&zgsz3414);
      CONVERT_OF(sail_int, mach_int)(&zgsz3414, INT64_C(25));
      lbits zgsz3415;
      CREATE(lbits)(&zgsz3415);
      vector_subrange_lbits(&zgsz3415, zgsz3412, zgsz3413, zgsz3414);
      zimm2 = CONVERT_OF(fbits, lbits)(zgsz3415, true);
      KILL(lbits)(&zgsz3415);
      KILL(sail_int)(&zgsz3414);
      KILL(sail_int)(&zgsz3413);
      KILL(lbits)(&zgsz3412);
    }
    uint64_t zimm1;
    {
      lbits zgsz3416;
      CREATE(lbits)(&zgsz3416);
      CONVERT_OF(lbits, fbits)(&zgsz3416, zv__37, UINT64_C(32) , true);
      sail_int zgsz3417;
      CREATE(sail_int)(&zgsz3417);
      CONVERT_OF(sail_int, mach_int)(&zgsz3417, INT64_C(11));
      sail_int zgsz3418;
      CREATE(sail_int)(&zgsz3418);
      CONVERT_OF(sail_int, mach_int)(&zgsz3418, INT64_C(8));
      lbits zgsz3419;
      CREATE(lbits)(&zgsz3419);
      vector_subrange_lbits(&zgsz3419, zgsz3416, zgsz3417, zgsz3418);
      zimm1 = CONVERT_OF(fbits, lbits)(zgsz3419, true);
      KILL(lbits)(&zgsz3419);
      KILL(sail_int)(&zgsz3418);
      KILL(sail_int)(&zgsz3417);
      KILL(lbits)(&zgsz3416);
    }
    struct zast zgaz344;
    CREATE(zast)(&zgaz344);
    {
      struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 zgsz3420;
      zgsz3420.ztup0 = zimm4shadowz38;
      zgsz3420.ztup1 = zimm2;
      zgsz3420.ztup2 = zrs2;
      zgsz3420.ztup3 = zrs1;
      zgsz3420.ztup4 = zimm1;
      zgsz3420.ztup5 = zimm3;
      zgsz3420.ztup6 = zBEQ;
      zBTYPE(&zgaz344, zgsz3420);
    
    }
    {
      struct zast zgsz3593;
      CREATE(zast)(&zgsz3593);
      COPY(zast)(&zgsz3593, zgaz344);
      zSomez3z5unionz0zzast(&zgsz32, zgsz3593);
      KILL(zast)(&zgsz3593);
    }
    KILL(zast)(&zgaz344);
  
  
  
  
  
  
  
  
    goto finish_match_2;
  }
case_18: ;
  {
    uint64_t zv__39;
    zv__39 = zmergez3var;
    uint64_t zgaz347;
    {
      lbits zgsz3424;
      CREATE(lbits)(&zgsz3424);
      CONVERT_OF(lbits, fbits)(&zgsz3424, zv__39, UINT64_C(32) , true);
      sail_int zgsz3425;
      CREATE(sail_int)(&zgsz3425);
      CONVERT_OF(sail_int, mach_int)(&zgsz3425, INT64_C(6));
      sail_int zgsz3426;
      CREATE(sail_int)(&zgsz3426);
      CONVERT_OF(sail_int, mach_int)(&zgsz3426, INT64_C(0));
      lbits zgsz3427;
      CREATE(lbits)(&zgsz3427);
      vector_subrange_lbits(&zgsz3427, zgsz3424, zgsz3425, zgsz3426);
      zgaz347 = CONVERT_OF(fbits, lbits)(zgsz3427, true);
      KILL(lbits)(&zgsz3427);
      KILL(sail_int)(&zgsz3426);
      KILL(sail_int)(&zgsz3425);
      KILL(lbits)(&zgsz3424);
    }
    bool zgsz3457;
    {
      lbits zgsz3459;
      CREATE(lbits)(&zgsz3459);
      CONVERT_OF(lbits, fbits)(&zgsz3459, UINT64_C(0b1100011), UINT64_C(7) , true);
      lbits zgsz3458;
      CREATE(lbits)(&zgsz3458);
      CONVERT_OF(lbits, fbits)(&zgsz3458, zgaz347, UINT64_C(7) , true);
      zgsz3457 = eq_bits(zgsz3458, zgsz3459);
      KILL(lbits)(&zgsz3459);
      KILL(lbits)(&zgsz3458);
    }
  
    if (!(zgsz3457)) {
  
    goto case_19;
    }
    uint64_t zimm4;
    {
      lbits zgsz3428;
      CREATE(lbits)(&zgsz3428);
      CONVERT_OF(lbits, fbits)(&zgsz3428, zv__39, UINT64_C(32) , true);
      sail_int zgsz3429;
      CREATE(sail_int)(&zgsz3429);
      CONVERT_OF(sail_int, mach_int)(&zgsz3429, INT64_C(31));
      sail_int zgsz3430;
      CREATE(sail_int)(&zgsz3430);
      CONVERT_OF(sail_int, mach_int)(&zgsz3430, INT64_C(31));
      lbits zgsz3431;
      CREATE(lbits)(&zgsz3431);
      vector_subrange_lbits(&zgsz3431, zgsz3428, zgsz3429, zgsz3430);
      zimm4 = CONVERT_OF(fbits, lbits)(zgsz3431, true);
      KILL(lbits)(&zgsz3431);
      KILL(sail_int)(&zgsz3430);
      KILL(sail_int)(&zgsz3429);
      KILL(lbits)(&zgsz3428);
    }
    uint64_t zrs2;
    {
      lbits zgsz3432;
      CREATE(lbits)(&zgsz3432);
      CONVERT_OF(lbits, fbits)(&zgsz3432, zv__39, UINT64_C(32) , true);
      sail_int zgsz3433;
      CREATE(sail_int)(&zgsz3433);
      CONVERT_OF(sail_int, mach_int)(&zgsz3433, INT64_C(24));
      sail_int zgsz3434;
      CREATE(sail_int)(&zgsz3434);
      CONVERT_OF(sail_int, mach_int)(&zgsz3434, INT64_C(20));
      lbits zgsz3435;
      CREATE(lbits)(&zgsz3435);
      vector_subrange_lbits(&zgsz3435, zgsz3432, zgsz3433, zgsz3434);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz3435, true);
      KILL(lbits)(&zgsz3435);
      KILL(sail_int)(&zgsz3434);
      KILL(sail_int)(&zgsz3433);
      KILL(lbits)(&zgsz3432);
    }
    uint64_t zrs1;
    {
      lbits zgsz3436;
      CREATE(lbits)(&zgsz3436);
      CONVERT_OF(lbits, fbits)(&zgsz3436, zv__39, UINT64_C(32) , true);
      sail_int zgsz3437;
      CREATE(sail_int)(&zgsz3437);
      CONVERT_OF(sail_int, mach_int)(&zgsz3437, INT64_C(19));
      sail_int zgsz3438;
      CREATE(sail_int)(&zgsz3438);
      CONVERT_OF(sail_int, mach_int)(&zgsz3438, INT64_C(15));
      lbits zgsz3439;
      CREATE(lbits)(&zgsz3439);
      vector_subrange_lbits(&zgsz3439, zgsz3436, zgsz3437, zgsz3438);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3439, true);
      KILL(lbits)(&zgsz3439);
      KILL(sail_int)(&zgsz3438);
      KILL(sail_int)(&zgsz3437);
      KILL(lbits)(&zgsz3436);
    }
    uint64_t zimm4shadowz39;
    {
      lbits zgsz3440;
      CREATE(lbits)(&zgsz3440);
      CONVERT_OF(lbits, fbits)(&zgsz3440, zv__39, UINT64_C(32) , true);
      sail_int zgsz3441;
      CREATE(sail_int)(&zgsz3441);
      CONVERT_OF(sail_int, mach_int)(&zgsz3441, INT64_C(31));
      sail_int zgsz3442;
      CREATE(sail_int)(&zgsz3442);
      CONVERT_OF(sail_int, mach_int)(&zgsz3442, INT64_C(31));
      lbits zgsz3443;
      CREATE(lbits)(&zgsz3443);
      vector_subrange_lbits(&zgsz3443, zgsz3440, zgsz3441, zgsz3442);
      zimm4shadowz39 = CONVERT_OF(fbits, lbits)(zgsz3443, true);
      KILL(lbits)(&zgsz3443);
      KILL(sail_int)(&zgsz3442);
      KILL(sail_int)(&zgsz3441);
      KILL(lbits)(&zgsz3440);
    }
    uint64_t zimm3;
    {
      lbits zgsz3444;
      CREATE(lbits)(&zgsz3444);
      CONVERT_OF(lbits, fbits)(&zgsz3444, zv__39, UINT64_C(32) , true);
      sail_int zgsz3445;
      CREATE(sail_int)(&zgsz3445);
      CONVERT_OF(sail_int, mach_int)(&zgsz3445, INT64_C(7));
      sail_int zgsz3446;
      CREATE(sail_int)(&zgsz3446);
      CONVERT_OF(sail_int, mach_int)(&zgsz3446, INT64_C(7));
      lbits zgsz3447;
      CREATE(lbits)(&zgsz3447);
      vector_subrange_lbits(&zgsz3447, zgsz3444, zgsz3445, zgsz3446);
      zimm3 = CONVERT_OF(fbits, lbits)(zgsz3447, true);
      KILL(lbits)(&zgsz3447);
      KILL(sail_int)(&zgsz3446);
      KILL(sail_int)(&zgsz3445);
      KILL(lbits)(&zgsz3444);
    }
    uint64_t zimm2;
    {
      lbits zgsz3448;
      CREATE(lbits)(&zgsz3448);
      CONVERT_OF(lbits, fbits)(&zgsz3448, zv__39, UINT64_C(32) , true);
      sail_int zgsz3449;
      CREATE(sail_int)(&zgsz3449);
      CONVERT_OF(sail_int, mach_int)(&zgsz3449, INT64_C(30));
      sail_int zgsz3450;
      CREATE(sail_int)(&zgsz3450);
      CONVERT_OF(sail_int, mach_int)(&zgsz3450, INT64_C(25));
      lbits zgsz3451;
      CREATE(lbits)(&zgsz3451);
      vector_subrange_lbits(&zgsz3451, zgsz3448, zgsz3449, zgsz3450);
      zimm2 = CONVERT_OF(fbits, lbits)(zgsz3451, true);
      KILL(lbits)(&zgsz3451);
      KILL(sail_int)(&zgsz3450);
      KILL(sail_int)(&zgsz3449);
      KILL(lbits)(&zgsz3448);
    }
    uint64_t zimm1;
    {
      lbits zgsz3452;
      CREATE(lbits)(&zgsz3452);
      CONVERT_OF(lbits, fbits)(&zgsz3452, zv__39, UINT64_C(32) , true);
      sail_int zgsz3453;
      CREATE(sail_int)(&zgsz3453);
      CONVERT_OF(sail_int, mach_int)(&zgsz3453, INT64_C(11));
      sail_int zgsz3454;
      CREATE(sail_int)(&zgsz3454);
      CONVERT_OF(sail_int, mach_int)(&zgsz3454, INT64_C(8));
      lbits zgsz3455;
      CREATE(lbits)(&zgsz3455);
      vector_subrange_lbits(&zgsz3455, zgsz3452, zgsz3453, zgsz3454);
      zimm1 = CONVERT_OF(fbits, lbits)(zgsz3455, true);
      KILL(lbits)(&zgsz3455);
      KILL(sail_int)(&zgsz3454);
      KILL(sail_int)(&zgsz3453);
      KILL(lbits)(&zgsz3452);
    }
    struct zast zgaz346;
    CREATE(zast)(&zgaz346);
    {
      struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 zgsz3456;
      zgsz3456.ztup0 = zimm4shadowz39;
      zgsz3456.ztup1 = zimm2;
      zgsz3456.ztup2 = zrs2;
      zgsz3456.ztup3 = zrs1;
      zgsz3456.ztup4 = zimm1;
      zgsz3456.ztup5 = zimm3;
      zgsz3456.ztup6 = zBNE;
      zBTYPE(&zgaz346, zgsz3456);
    
    }
    {
      struct zast zgsz3594;
      CREATE(zast)(&zgsz3594);
      COPY(zast)(&zgsz3594, zgaz346);
      zSomez3z5unionz0zzast(&zgsz32, zgsz3594);
      KILL(zast)(&zgsz3594);
    }
    KILL(zast)(&zgaz346);
  
  
  
  
  
  
  
  
    goto finish_match_2;
  }
case_19: ;
  {
    uint64_t zv__41;
    zv__41 = zmergez3var;
    uint64_t zgaz349;
    {
      lbits zgsz3460;
      CREATE(lbits)(&zgsz3460);
      CONVERT_OF(lbits, fbits)(&zgsz3460, zv__41, UINT64_C(32) , true);
      sail_int zgsz3461;
      CREATE(sail_int)(&zgsz3461);
      CONVERT_OF(sail_int, mach_int)(&zgsz3461, INT64_C(6));
      sail_int zgsz3462;
      CREATE(sail_int)(&zgsz3462);
      CONVERT_OF(sail_int, mach_int)(&zgsz3462, INT64_C(0));
      lbits zgsz3463;
      CREATE(lbits)(&zgsz3463);
      vector_subrange_lbits(&zgsz3463, zgsz3460, zgsz3461, zgsz3462);
      zgaz349 = CONVERT_OF(fbits, lbits)(zgsz3463, true);
      KILL(lbits)(&zgsz3463);
      KILL(sail_int)(&zgsz3462);
      KILL(sail_int)(&zgsz3461);
      KILL(lbits)(&zgsz3460);
    }
    bool zgsz3477;
    {
      lbits zgsz3479;
      CREATE(lbits)(&zgsz3479);
      CONVERT_OF(lbits, fbits)(&zgsz3479, UINT64_C(0b0110111), UINT64_C(7) , true);
      lbits zgsz3478;
      CREATE(lbits)(&zgsz3478);
      CONVERT_OF(lbits, fbits)(&zgsz3478, zgaz349, UINT64_C(7) , true);
      zgsz3477 = eq_bits(zgsz3478, zgsz3479);
      KILL(lbits)(&zgsz3479);
      KILL(lbits)(&zgsz3478);
    }
  
    if (!(zgsz3477)) {
  
    goto case_20;
    }
    uint64_t zimm;
    {
      lbits zgsz3464;
      CREATE(lbits)(&zgsz3464);
      CONVERT_OF(lbits, fbits)(&zgsz3464, zv__41, UINT64_C(32) , true);
      sail_int zgsz3465;
      CREATE(sail_int)(&zgsz3465);
      CONVERT_OF(sail_int, mach_int)(&zgsz3465, INT64_C(31));
      sail_int zgsz3466;
      CREATE(sail_int)(&zgsz3466);
      CONVERT_OF(sail_int, mach_int)(&zgsz3466, INT64_C(12));
      lbits zgsz3467;
      CREATE(lbits)(&zgsz3467);
      vector_subrange_lbits(&zgsz3467, zgsz3464, zgsz3465, zgsz3466);
      zimm = CONVERT_OF(fbits, lbits)(zgsz3467, true);
      KILL(lbits)(&zgsz3467);
      KILL(sail_int)(&zgsz3466);
      KILL(sail_int)(&zgsz3465);
      KILL(lbits)(&zgsz3464);
    }
    uint64_t zrd;
    {
      lbits zgsz3468;
      CREATE(lbits)(&zgsz3468);
      CONVERT_OF(lbits, fbits)(&zgsz3468, zv__41, UINT64_C(32) , true);
      sail_int zgsz3469;
      CREATE(sail_int)(&zgsz3469);
      CONVERT_OF(sail_int, mach_int)(&zgsz3469, INT64_C(11));
      sail_int zgsz3470;
      CREATE(sail_int)(&zgsz3470);
      CONVERT_OF(sail_int, mach_int)(&zgsz3470, INT64_C(7));
      lbits zgsz3471;
      CREATE(lbits)(&zgsz3471);
      vector_subrange_lbits(&zgsz3471, zgsz3468, zgsz3469, zgsz3470);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3471, true);
      KILL(lbits)(&zgsz3471);
      KILL(sail_int)(&zgsz3470);
      KILL(sail_int)(&zgsz3469);
      KILL(lbits)(&zgsz3468);
    }
    uint64_t zimmshadowz310;
    {
      lbits zgsz3472;
      CREATE(lbits)(&zgsz3472);
      CONVERT_OF(lbits, fbits)(&zgsz3472, zv__41, UINT64_C(32) , true);
      sail_int zgsz3473;
      CREATE(sail_int)(&zgsz3473);
      CONVERT_OF(sail_int, mach_int)(&zgsz3473, INT64_C(31));
      sail_int zgsz3474;
      CREATE(sail_int)(&zgsz3474);
      CONVERT_OF(sail_int, mach_int)(&zgsz3474, INT64_C(12));
      lbits zgsz3475;
      CREATE(lbits)(&zgsz3475);
      vector_subrange_lbits(&zgsz3475, zgsz3472, zgsz3473, zgsz3474);
      zimmshadowz310 = CONVERT_OF(fbits, lbits)(zgsz3475, true);
      KILL(lbits)(&zgsz3475);
      KILL(sail_int)(&zgsz3474);
      KILL(sail_int)(&zgsz3473);
      KILL(lbits)(&zgsz3472);
    }
    struct zast zgaz348;
    CREATE(zast)(&zgaz348);
    {
      struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 zgsz3476;
      zgsz3476.ztup0 = zimmshadowz310;
      zgsz3476.ztup1 = zrd;
      zgsz3476.ztup2 = zLUI;
      zUTYPE(&zgaz348, zgsz3476);
    
    }
    {
      struct zast zgsz3595;
      CREATE(zast)(&zgsz3595);
      COPY(zast)(&zgsz3595, zgaz348);
      zSomez3z5unionz0zzast(&zgsz32, zgsz3595);
      KILL(zast)(&zgsz3595);
    }
    KILL(zast)(&zgaz348);
  
  
  
  
    goto finish_match_2;
  }
case_20: ;
  {
    uint64_t zv__43;
    zv__43 = zmergez3var;
    uint64_t zgaz351;
    {
      lbits zgsz3480;
      CREATE(lbits)(&zgsz3480);
      CONVERT_OF(lbits, fbits)(&zgsz3480, zv__43, UINT64_C(32) , true);
      sail_int zgsz3481;
      CREATE(sail_int)(&zgsz3481);
      CONVERT_OF(sail_int, mach_int)(&zgsz3481, INT64_C(6));
      sail_int zgsz3482;
      CREATE(sail_int)(&zgsz3482);
      CONVERT_OF(sail_int, mach_int)(&zgsz3482, INT64_C(0));
      lbits zgsz3483;
      CREATE(lbits)(&zgsz3483);
      vector_subrange_lbits(&zgsz3483, zgsz3480, zgsz3481, zgsz3482);
      zgaz351 = CONVERT_OF(fbits, lbits)(zgsz3483, true);
      KILL(lbits)(&zgsz3483);
      KILL(sail_int)(&zgsz3482);
      KILL(sail_int)(&zgsz3481);
      KILL(lbits)(&zgsz3480);
    }
    bool zgsz3497;
    {
      lbits zgsz3499;
      CREATE(lbits)(&zgsz3499);
      CONVERT_OF(lbits, fbits)(&zgsz3499, UINT64_C(0b0010111), UINT64_C(7) , true);
      lbits zgsz3498;
      CREATE(lbits)(&zgsz3498);
      CONVERT_OF(lbits, fbits)(&zgsz3498, zgaz351, UINT64_C(7) , true);
      zgsz3497 = eq_bits(zgsz3498, zgsz3499);
      KILL(lbits)(&zgsz3499);
      KILL(lbits)(&zgsz3498);
    }
  
    if (!(zgsz3497)) {
  
    goto case_21;
    }
    uint64_t zimm;
    {
      lbits zgsz3484;
      CREATE(lbits)(&zgsz3484);
      CONVERT_OF(lbits, fbits)(&zgsz3484, zv__43, UINT64_C(32) , true);
      sail_int zgsz3485;
      CREATE(sail_int)(&zgsz3485);
      CONVERT_OF(sail_int, mach_int)(&zgsz3485, INT64_C(31));
      sail_int zgsz3486;
      CREATE(sail_int)(&zgsz3486);
      CONVERT_OF(sail_int, mach_int)(&zgsz3486, INT64_C(12));
      lbits zgsz3487;
      CREATE(lbits)(&zgsz3487);
      vector_subrange_lbits(&zgsz3487, zgsz3484, zgsz3485, zgsz3486);
      zimm = CONVERT_OF(fbits, lbits)(zgsz3487, true);
      KILL(lbits)(&zgsz3487);
      KILL(sail_int)(&zgsz3486);
      KILL(sail_int)(&zgsz3485);
      KILL(lbits)(&zgsz3484);
    }
    uint64_t zrd;
    {
      lbits zgsz3488;
      CREATE(lbits)(&zgsz3488);
      CONVERT_OF(lbits, fbits)(&zgsz3488, zv__43, UINT64_C(32) , true);
      sail_int zgsz3489;
      CREATE(sail_int)(&zgsz3489);
      CONVERT_OF(sail_int, mach_int)(&zgsz3489, INT64_C(11));
      sail_int zgsz3490;
      CREATE(sail_int)(&zgsz3490);
      CONVERT_OF(sail_int, mach_int)(&zgsz3490, INT64_C(7));
      lbits zgsz3491;
      CREATE(lbits)(&zgsz3491);
      vector_subrange_lbits(&zgsz3491, zgsz3488, zgsz3489, zgsz3490);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3491, true);
      KILL(lbits)(&zgsz3491);
      KILL(sail_int)(&zgsz3490);
      KILL(sail_int)(&zgsz3489);
      KILL(lbits)(&zgsz3488);
    }
    uint64_t zimmshadowz311;
    {
      lbits zgsz3492;
      CREATE(lbits)(&zgsz3492);
      CONVERT_OF(lbits, fbits)(&zgsz3492, zv__43, UINT64_C(32) , true);
      sail_int zgsz3493;
      CREATE(sail_int)(&zgsz3493);
      CONVERT_OF(sail_int, mach_int)(&zgsz3493, INT64_C(31));
      sail_int zgsz3494;
      CREATE(sail_int)(&zgsz3494);
      CONVERT_OF(sail_int, mach_int)(&zgsz3494, INT64_C(12));
      lbits zgsz3495;
      CREATE(lbits)(&zgsz3495);
      vector_subrange_lbits(&zgsz3495, zgsz3492, zgsz3493, zgsz3494);
      zimmshadowz311 = CONVERT_OF(fbits, lbits)(zgsz3495, true);
      KILL(lbits)(&zgsz3495);
      KILL(sail_int)(&zgsz3494);
      KILL(sail_int)(&zgsz3493);
      KILL(lbits)(&zgsz3492);
    }
    struct zast zgaz350;
    CREATE(zast)(&zgaz350);
    {
      struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 zgsz3496;
      zgsz3496.ztup0 = zimmshadowz311;
      zgsz3496.ztup1 = zrd;
      zgsz3496.ztup2 = zAUIPC;
      zUTYPE(&zgaz350, zgsz3496);
    
    }
    {
      struct zast zgsz3596;
      CREATE(zast)(&zgsz3596);
      COPY(zast)(&zgsz3596, zgaz350);
      zSomez3z5unionz0zzast(&zgsz32, zgsz3596);
      KILL(zast)(&zgsz3596);
    }
    KILL(zast)(&zgaz350);
  
  
  
  
    goto finish_match_2;
  }
case_21: ;
  {
    uint64_t zv__45;
    zv__45 = zmergez3var;
    uint64_t zgaz353;
    {
      lbits zgsz3500;
      CREATE(lbits)(&zgsz3500);
      CONVERT_OF(lbits, fbits)(&zgsz3500, zv__45, UINT64_C(32) , true);
      sail_int zgsz3501;
      CREATE(sail_int)(&zgsz3501);
      CONVERT_OF(sail_int, mach_int)(&zgsz3501, INT64_C(6));
      sail_int zgsz3502;
      CREATE(sail_int)(&zgsz3502);
      CONVERT_OF(sail_int, mach_int)(&zgsz3502, INT64_C(0));
      lbits zgsz3503;
      CREATE(lbits)(&zgsz3503);
      vector_subrange_lbits(&zgsz3503, zgsz3500, zgsz3501, zgsz3502);
      zgaz353 = CONVERT_OF(fbits, lbits)(zgsz3503, true);
      KILL(lbits)(&zgsz3503);
      KILL(sail_int)(&zgsz3502);
      KILL(sail_int)(&zgsz3501);
      KILL(lbits)(&zgsz3500);
    }
    bool zgsz3529;
    {
      lbits zgsz3531;
      CREATE(lbits)(&zgsz3531);
      CONVERT_OF(lbits, fbits)(&zgsz3531, UINT64_C(0b1101111), UINT64_C(7) , true);
      lbits zgsz3530;
      CREATE(lbits)(&zgsz3530);
      CONVERT_OF(lbits, fbits)(&zgsz3530, zgaz353, UINT64_C(7) , true);
      zgsz3529 = eq_bits(zgsz3530, zgsz3531);
      KILL(lbits)(&zgsz3531);
      KILL(lbits)(&zgsz3530);
    }
  
    if (!(zgsz3529)) {
  
    goto case_22;
    }
    uint64_t zimm4;
    {
      lbits zgsz3504;
      CREATE(lbits)(&zgsz3504);
      CONVERT_OF(lbits, fbits)(&zgsz3504, zv__45, UINT64_C(32) , true);
      sail_int zgsz3505;
      CREATE(sail_int)(&zgsz3505);
      CONVERT_OF(sail_int, mach_int)(&zgsz3505, INT64_C(31));
      sail_int zgsz3506;
      CREATE(sail_int)(&zgsz3506);
      CONVERT_OF(sail_int, mach_int)(&zgsz3506, INT64_C(31));
      lbits zgsz3507;
      CREATE(lbits)(&zgsz3507);
      vector_subrange_lbits(&zgsz3507, zgsz3504, zgsz3505, zgsz3506);
      zimm4 = CONVERT_OF(fbits, lbits)(zgsz3507, true);
      KILL(lbits)(&zgsz3507);
      KILL(sail_int)(&zgsz3506);
      KILL(sail_int)(&zgsz3505);
      KILL(lbits)(&zgsz3504);
    }
    uint64_t zrd;
    {
      lbits zgsz3508;
      CREATE(lbits)(&zgsz3508);
      CONVERT_OF(lbits, fbits)(&zgsz3508, zv__45, UINT64_C(32) , true);
      sail_int zgsz3509;
      CREATE(sail_int)(&zgsz3509);
      CONVERT_OF(sail_int, mach_int)(&zgsz3509, INT64_C(11));
      sail_int zgsz3510;
      CREATE(sail_int)(&zgsz3510);
      CONVERT_OF(sail_int, mach_int)(&zgsz3510, INT64_C(7));
      lbits zgsz3511;
      CREATE(lbits)(&zgsz3511);
      vector_subrange_lbits(&zgsz3511, zgsz3508, zgsz3509, zgsz3510);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3511, true);
      KILL(lbits)(&zgsz3511);
      KILL(sail_int)(&zgsz3510);
      KILL(sail_int)(&zgsz3509);
      KILL(lbits)(&zgsz3508);
    }
    uint64_t zimm4shadowz312;
    {
      lbits zgsz3512;
      CREATE(lbits)(&zgsz3512);
      CONVERT_OF(lbits, fbits)(&zgsz3512, zv__45, UINT64_C(32) , true);
      sail_int zgsz3513;
      CREATE(sail_int)(&zgsz3513);
      CONVERT_OF(sail_int, mach_int)(&zgsz3513, INT64_C(31));
      sail_int zgsz3514;
      CREATE(sail_int)(&zgsz3514);
      CONVERT_OF(sail_int, mach_int)(&zgsz3514, INT64_C(31));
      lbits zgsz3515;
      CREATE(lbits)(&zgsz3515);
      vector_subrange_lbits(&zgsz3515, zgsz3512, zgsz3513, zgsz3514);
      zimm4shadowz312 = CONVERT_OF(fbits, lbits)(zgsz3515, true);
      KILL(lbits)(&zgsz3515);
      KILL(sail_int)(&zgsz3514);
      KILL(sail_int)(&zgsz3513);
      KILL(lbits)(&zgsz3512);
    }
    uint64_t zimm3;
    {
      lbits zgsz3516;
      CREATE(lbits)(&zgsz3516);
      CONVERT_OF(lbits, fbits)(&zgsz3516, zv__45, UINT64_C(32) , true);
      sail_int zgsz3517;
      CREATE(sail_int)(&zgsz3517);
      CONVERT_OF(sail_int, mach_int)(&zgsz3517, INT64_C(19));
      sail_int zgsz3518;
      CREATE(sail_int)(&zgsz3518);
      CONVERT_OF(sail_int, mach_int)(&zgsz3518, INT64_C(12));
      lbits zgsz3519;
      CREATE(lbits)(&zgsz3519);
      vector_subrange_lbits(&zgsz3519, zgsz3516, zgsz3517, zgsz3518);
      zimm3 = CONVERT_OF(fbits, lbits)(zgsz3519, true);
      KILL(lbits)(&zgsz3519);
      KILL(sail_int)(&zgsz3518);
      KILL(sail_int)(&zgsz3517);
      KILL(lbits)(&zgsz3516);
    }
    uint64_t zimm2;
    {
      lbits zgsz3520;
      CREATE(lbits)(&zgsz3520);
      CONVERT_OF(lbits, fbits)(&zgsz3520, zv__45, UINT64_C(32) , true);
      sail_int zgsz3521;
      CREATE(sail_int)(&zgsz3521);
      CONVERT_OF(sail_int, mach_int)(&zgsz3521, INT64_C(20));
      sail_int zgsz3522;
      CREATE(sail_int)(&zgsz3522);
      CONVERT_OF(sail_int, mach_int)(&zgsz3522, INT64_C(20));
      lbits zgsz3523;
      CREATE(lbits)(&zgsz3523);
      vector_subrange_lbits(&zgsz3523, zgsz3520, zgsz3521, zgsz3522);
      zimm2 = CONVERT_OF(fbits, lbits)(zgsz3523, true);
      KILL(lbits)(&zgsz3523);
      KILL(sail_int)(&zgsz3522);
      KILL(sail_int)(&zgsz3521);
      KILL(lbits)(&zgsz3520);
    }
    uint64_t zimm1;
    {
      lbits zgsz3524;
      CREATE(lbits)(&zgsz3524);
      CONVERT_OF(lbits, fbits)(&zgsz3524, zv__45, UINT64_C(32) , true);
      sail_int zgsz3525;
      CREATE(sail_int)(&zgsz3525);
      CONVERT_OF(sail_int, mach_int)(&zgsz3525, INT64_C(30));
      sail_int zgsz3526;
      CREATE(sail_int)(&zgsz3526);
      CONVERT_OF(sail_int, mach_int)(&zgsz3526, INT64_C(21));
      lbits zgsz3527;
      CREATE(lbits)(&zgsz3527);
      vector_subrange_lbits(&zgsz3527, zgsz3524, zgsz3525, zgsz3526);
      zimm1 = CONVERT_OF(fbits, lbits)(zgsz3527, true);
      KILL(lbits)(&zgsz3527);
      KILL(sail_int)(&zgsz3526);
      KILL(sail_int)(&zgsz3525);
      KILL(lbits)(&zgsz3524);
    }
    struct zast zgaz352;
    CREATE(zast)(&zgaz352);
    {
      struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv8zCz0z5bv5zCz0z5enumz0zzjopz9 zgsz3528;
      zgsz3528.ztup0 = zimm4shadowz312;
      zgsz3528.ztup1 = zimm1;
      zgsz3528.ztup2 = zimm2;
      zgsz3528.ztup3 = zimm3;
      zgsz3528.ztup4 = zrd;
      zgsz3528.ztup5 = zJAL;
      zJTYPE(&zgaz352, zgsz3528);
    
    }
    {
      struct zast zgsz3597;
      CREATE(zast)(&zgsz3597);
      COPY(zast)(&zgsz3597, zgaz352);
      zSomez3z5unionz0zzast(&zgsz32, zgsz3597);
      KILL(zast)(&zgsz3597);
    }
    KILL(zast)(&zgaz352);
  
  
  
  
  
  
  
    goto finish_match_2;
  }
case_22: ;
  sail_match_failure("decode");
finish_match_2: ;
  COPY(zoption)((*(&zcbz30)), zgsz32);
  KILL(zoption)(&zgsz32);
end_function_23: ;
  goto end_function_55;
end_block_exception_24: ;
  goto end_function_55;
end_function_55: ;
}

unit zexecute(struct zast zmergez3var)
{
  __label__ case_27, case_28, case_29, case_30, case_31, case_32, case_33, case_34, case_35, case_36, case_37, case_38, case_39, case_40, case_41, case_42, case_43, case_44, case_45, case_46, finish_match_26, end_function_47, end_block_exception_48;

  unit zcbz31;
  unit zgsz3532;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_27;
    uint64_t zrs2;
    zrs2 = zmergez3var.zRTYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zRTYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zRTYPE.ztup2;
    if ((zADD != zmergez3var.zRTYPE.ztup3)) goto case_27;
    zgsz3532 = print_endline("execute ADD\n");
  
  
  
    goto finish_match_26;
  }
case_27: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_28;
    uint64_t zrs2;
    zrs2 = zmergez3var.zRTYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zRTYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zRTYPE.ztup2;
    if ((zAND != zmergez3var.zRTYPE.ztup3)) goto case_28;
    zgsz3532 = print_endline("execute AND\n");
  
  
  
    goto finish_match_26;
  }
case_28: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_29;
    uint64_t zrs2;
    zrs2 = zmergez3var.zRTYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zRTYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zRTYPE.ztup2;
    if ((zOR != zmergez3var.zRTYPE.ztup3)) goto case_29;
    zgsz3532 = print_endline("execute OR\n");
  
  
  
    goto finish_match_26;
  }
case_29: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_30;
    uint64_t zrs2;
    zrs2 = zmergez3var.zRTYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zRTYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zRTYPE.ztup2;
    if ((zXOR != zmergez3var.zRTYPE.ztup3)) goto case_30;
    zgsz3532 = print_endline("execute XOR\n");
  
  
  
    goto finish_match_26;
  }
case_30: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_31;
    uint64_t zrs2;
    zrs2 = zmergez3var.zRTYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zRTYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zRTYPE.ztup2;
    if ((zMUL != zmergez3var.zRTYPE.ztup3)) goto case_31;
    zgsz3532 = print_endline("execute MUL\n");
  
  
  
    goto finish_match_26;
  }
case_31: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_32;
    uint64_t zrs2;
    zrs2 = zmergez3var.zRTYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zRTYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zRTYPE.ztup2;
    if ((zDIV != zmergez3var.zRTYPE.ztup3)) goto case_32;
    zgsz3532 = print_endline("execute DIV\n");
  
  
  
    goto finish_match_26;
  }
case_32: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_33;
    uint64_t zrs2;
    zrs2 = zmergez3var.zRTYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zRTYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zRTYPE.ztup2;
    if ((zREM != zmergez3var.zRTYPE.ztup3)) goto case_33;
    zgsz3532 = print_endline("execute REM\n");
  
  
  
    goto finish_match_26;
  }
case_33: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_34;
    uint64_t zimm;
    zimm = zmergez3var.zITYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zITYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zITYPE.ztup2;
    if ((zADDI != zmergez3var.zITYPE.ztup3)) goto case_34;
    zgsz3532 = print_endline("execute ADDI\n");
  
  
  
    goto finish_match_26;
  }
case_34: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_35;
    uint64_t zimm;
    zimm = zmergez3var.zITYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zITYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zITYPE.ztup2;
    if ((zSLTI != zmergez3var.zITYPE.ztup3)) goto case_35;
    zgsz3532 = print_endline("execute SLTI\n");
  
  
  
    goto finish_match_26;
  }
case_35: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_36;
    uint64_t zimm;
    zimm = zmergez3var.zITYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zITYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zITYPE.ztup2;
    if ((zANDI != zmergez3var.zITYPE.ztup3)) goto case_36;
    zgsz3532 = print_endline("execute ANDI\n");
  
  
  
    goto finish_match_26;
  }
case_36: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_37;
    uint64_t zimm;
    zimm = zmergez3var.zITYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zITYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zITYPE.ztup2;
    if ((zORI != zmergez3var.zITYPE.ztup3)) goto case_37;
    zgsz3532 = print_endline("execute ORI\n");
  
  
  
    goto finish_match_26;
  }
case_37: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_38;
    uint64_t zimm;
    zimm = zmergez3var.zITYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zITYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zITYPE.ztup2;
    if ((zXORI != zmergez3var.zITYPE.ztup3)) goto case_38;
    zgsz3532 = print_endline("execute XORI\n");
  
  
  
    goto finish_match_26;
  }
case_38: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_39;
    uint64_t zimm;
    zimm = zmergez3var.zITYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zITYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zITYPE.ztup2;
    if ((zJALR != zmergez3var.zITYPE.ztup3)) goto case_39;
    zgsz3532 = print_endline("execute JALR\n");
  
  
  
    goto finish_match_26;
  }
case_39: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_40;
    uint64_t zimm;
    zimm = zmergez3var.zITYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zITYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zITYPE.ztup2;
    if ((zLW != zmergez3var.zITYPE.ztup3)) goto case_40;
    zgsz3532 = print_endline("execute LW\n");
  
  
  
    goto finish_match_26;
  }
case_40: ;
  {
    if (zmergez3var.kind != Kind_zSTYPE) goto case_41;
    uint64_t zimm2;
    zimm2 = zmergez3var.zSTYPE.ztup0;
    uint64_t zrs2;
    zrs2 = zmergez3var.zSTYPE.ztup1;
    uint64_t zrs1;
    zrs1 = zmergez3var.zSTYPE.ztup2;
    uint64_t zimm1;
    zimm1 = zmergez3var.zSTYPE.ztup3;
    if ((zSW != zmergez3var.zSTYPE.ztup4)) goto case_41;
    zgsz3532 = print_endline("execute SW\n");
  
  
  
  
    goto finish_match_26;
  }
case_41: ;
  {
    if (zmergez3var.kind != Kind_zBTYPE) goto case_42;
    uint64_t zimm4;
    zimm4 = zmergez3var.zBTYPE.ztup0;
    uint64_t zimm2;
    zimm2 = zmergez3var.zBTYPE.ztup1;
    uint64_t zrs2;
    zrs2 = zmergez3var.zBTYPE.ztup2;
    uint64_t zrs1;
    zrs1 = zmergez3var.zBTYPE.ztup3;
    uint64_t zimm1;
    zimm1 = zmergez3var.zBTYPE.ztup4;
    uint64_t zimm3;
    zimm3 = zmergez3var.zBTYPE.ztup5;
    if ((zBEQ != zmergez3var.zBTYPE.ztup6)) goto case_42;
    zgsz3532 = print_endline("execute BEQ\n");
  
  
  
  
  
  
    goto finish_match_26;
  }
case_42: ;
  {
    if (zmergez3var.kind != Kind_zBTYPE) goto case_43;
    uint64_t zimm4;
    zimm4 = zmergez3var.zBTYPE.ztup0;
    uint64_t zimm2;
    zimm2 = zmergez3var.zBTYPE.ztup1;
    uint64_t zrs2;
    zrs2 = zmergez3var.zBTYPE.ztup2;
    uint64_t zrs1;
    zrs1 = zmergez3var.zBTYPE.ztup3;
    uint64_t zimm1;
    zimm1 = zmergez3var.zBTYPE.ztup4;
    uint64_t zimm3;
    zimm3 = zmergez3var.zBTYPE.ztup5;
    if ((zBNE != zmergez3var.zBTYPE.ztup6)) goto case_43;
    zgsz3532 = print_endline("execute BNE\n");
  
  
  
  
  
  
    goto finish_match_26;
  }
case_43: ;
  {
    if (zmergez3var.kind != Kind_zUTYPE) goto case_44;
    uint64_t zimm;
    zimm = zmergez3var.zUTYPE.ztup0;
    uint64_t zrd;
    zrd = zmergez3var.zUTYPE.ztup1;
    if ((zLUI != zmergez3var.zUTYPE.ztup2)) goto case_44;
    zgsz3532 = print_endline("execute LUI\n");
  
  
    goto finish_match_26;
  }
case_44: ;
  {
    if (zmergez3var.kind != Kind_zUTYPE) goto case_45;
    uint64_t zimm;
    zimm = zmergez3var.zUTYPE.ztup0;
    uint64_t zrd;
    zrd = zmergez3var.zUTYPE.ztup1;
    if ((zAUIPC != zmergez3var.zUTYPE.ztup2)) goto case_45;
    zgsz3532 = print_endline("execute AUIPC\n");
  
  
    goto finish_match_26;
  }
case_45: ;
  {
    if (zmergez3var.kind != Kind_zJTYPE) goto case_46;
    uint64_t zimm4;
    zimm4 = zmergez3var.zJTYPE.ztup0;
    uint64_t zimm1;
    zimm1 = zmergez3var.zJTYPE.ztup1;
    uint64_t zimm2;
    zimm2 = zmergez3var.zJTYPE.ztup2;
    uint64_t zimm3;
    zimm3 = zmergez3var.zJTYPE.ztup3;
    uint64_t zrd;
    zrd = zmergez3var.zJTYPE.ztup4;
    if ((zJAL != zmergez3var.zJTYPE.ztup5)) goto case_46;
    zgsz3532 = print_endline("execute JAL\n");
  
  
  
  
  
    goto finish_match_26;
  }
case_46: ;
  sail_match_failure("execute");
finish_match_26: ;
  zcbz31 = zgsz3532;

end_function_47: ;
  return zcbz31;
end_block_exception_48: ;

  return UNIT;
}

unit zmain(unit);

unit zmain(unit zgsz3553)
{
  __label__ end_function_50, end_block_exception_51;

  unit zcbz32;
  sail_int zPC;
  CREATE(sail_int)(&zPC);
  elf_entry(&zPC, UNIT);
  zcbz32 = print_int("PC = ", zPC);
  KILL(sail_int)(&zPC);
end_function_50: ;
  return zcbz32;
end_block_exception_51: ;

  return UNIT;
}

unit zinitializze_registers(unit);

unit zinitializze_registers(unit zgsz3554)
{
  __label__ end_function_53, end_block_exception_54;

  unit zcbz33;
  {
    {
      sail_int zgsz3555;
      CREATE(sail_int)(&zgsz3555);
      CONVERT_OF(sail_int, mach_int)(&zgsz3555, INT64_C(32));
      lbits zgsz3556;
      CREATE(lbits)(&zgsz3556);
      UNDEFINED(lbits)(&zgsz3556, zgsz3555);
      zzzero = CONVERT_OF(fbits, lbits)(zgsz3556, true);
      KILL(lbits)(&zgsz3556);
      KILL(sail_int)(&zgsz3555);
    }
    unit zgsz3575;
    zgsz3575 = UNIT;
  }
  {
    {
      sail_int zgsz3557;
      CREATE(sail_int)(&zgsz3557);
      CONVERT_OF(sail_int, mach_int)(&zgsz3557, INT64_C(32));
      lbits zgsz3558;
      CREATE(lbits)(&zgsz3558);
      UNDEFINED(lbits)(&zgsz3558, zgsz3557);
      zra = CONVERT_OF(fbits, lbits)(zgsz3558, true);
      KILL(lbits)(&zgsz3558);
      KILL(sail_int)(&zgsz3557);
    }
    unit zgsz3574;
    zgsz3574 = UNIT;
  }
  {
    {
      sail_int zgsz3559;
      CREATE(sail_int)(&zgsz3559);
      CONVERT_OF(sail_int, mach_int)(&zgsz3559, INT64_C(32));
      lbits zgsz3560;
      CREATE(lbits)(&zgsz3560);
      UNDEFINED(lbits)(&zgsz3560, zgsz3559);
      zsp = CONVERT_OF(fbits, lbits)(zgsz3560, true);
      KILL(lbits)(&zgsz3560);
      KILL(sail_int)(&zgsz3559);
    }
    unit zgsz3573;
    zgsz3573 = UNIT;
  }
  {
    {
      sail_int zgsz3561;
      CREATE(sail_int)(&zgsz3561);
      CONVERT_OF(sail_int, mach_int)(&zgsz3561, INT64_C(32));
      lbits zgsz3562;
      CREATE(lbits)(&zgsz3562);
      UNDEFINED(lbits)(&zgsz3562, zgsz3561);
      zgp = CONVERT_OF(fbits, lbits)(zgsz3562, true);
      KILL(lbits)(&zgsz3562);
      KILL(sail_int)(&zgsz3561);
    }
    unit zgsz3572;
    zgsz3572 = UNIT;
  }
  {
    {
      sail_int zgsz3563;
      CREATE(sail_int)(&zgsz3563);
      CONVERT_OF(sail_int, mach_int)(&zgsz3563, INT64_C(32));
      lbits zgsz3564;
      CREATE(lbits)(&zgsz3564);
      UNDEFINED(lbits)(&zgsz3564, zgsz3563);
      za0 = CONVERT_OF(fbits, lbits)(zgsz3564, true);
      KILL(lbits)(&zgsz3564);
      KILL(sail_int)(&zgsz3563);
    }
    unit zgsz3571;
    zgsz3571 = UNIT;
  }
  {
    {
      sail_int zgsz3565;
      CREATE(sail_int)(&zgsz3565);
      CONVERT_OF(sail_int, mach_int)(&zgsz3565, INT64_C(32));
      lbits zgsz3566;
      CREATE(lbits)(&zgsz3566);
      UNDEFINED(lbits)(&zgsz3566, zgsz3565);
      za1 = CONVERT_OF(fbits, lbits)(zgsz3566, true);
      KILL(lbits)(&zgsz3566);
      KILL(sail_int)(&zgsz3565);
    }
    unit zgsz3570;
    zgsz3570 = UNIT;
  }
  {
    {
      sail_int zgsz3567;
      CREATE(sail_int)(&zgsz3567);
      CONVERT_OF(sail_int, mach_int)(&zgsz3567, INT64_C(32));
      lbits zgsz3568;
      CREATE(lbits)(&zgsz3568);
      UNDEFINED(lbits)(&zgsz3568, zgsz3567);
      za2 = CONVERT_OF(fbits, lbits)(zgsz3568, true);
      KILL(lbits)(&zgsz3568);
      KILL(sail_int)(&zgsz3567);
    }
    unit zgsz3569;
    zgsz3569 = UNIT;
  }
  {
    sail_int zgsz3576;
    CREATE(sail_int)(&zgsz3576);
    CONVERT_OF(sail_int, mach_int)(&zgsz3576, INT64_C(32));
    lbits zgsz3577;
    CREATE(lbits)(&zgsz3577);
    UNDEFINED(lbits)(&zgsz3577, zgsz3576);
    za3 = CONVERT_OF(fbits, lbits)(zgsz3577, true);
    KILL(lbits)(&zgsz3577);
    KILL(sail_int)(&zgsz3576);
  }
  zcbz33 = UNIT;
end_function_53: ;
  return zcbz33;
end_block_exception_54: ;

  return UNIT;
}

void model_init(void)
{
  setup_rts();
  zinitializze_registers(UNIT);
  create_letbind_0();
}

void model_fini(void)
{
  kill_letbind_0();
  cleanup_rts();
}

int model_main(int argc, char *argv[])
{
  model_init();
  if (process_arguments(argc, argv)) exit(EXIT_FAILURE);
  zmain(UNIT);
  model_fini();
  return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
  return model_main(argc, argv);
}
