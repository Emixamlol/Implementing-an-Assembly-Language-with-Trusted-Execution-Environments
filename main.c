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











bool zneq_bool(bool, bool);

bool zneq_bool(bool zx, bool zy)
{
  __label__ end_function_1, end_block_exception_2;

  bool zcbz30;
  bool zgaz30;
  zgaz30 = eq_bool(zx, zy);
  zcbz30 = not(zgaz30);

end_function_1: ;
  return zcbz30;
end_block_exception_2: ;

  return false;
}

































void zsail_mask(lbits *rop, sail_int, lbits);

sail_int zghz30;

void startup_zsail_mask(void)
{    CREATE(sail_int)(&zghz30);
}

void zsail_mask(lbits *zcbz31, sail_int zlen, lbits zv)
{
  __label__ end_function_4, end_block_exception_5, end_function_95;

  bool zgaz32;
  {
    RECREATE(sail_int)(&zghz30);
    length_lbits(&zghz30, zv);
    zgaz32 = lteq(zlen, zghz30);
  }
  if (zgaz32) {  sail_truncate((*(&zcbz31)), zv, zlen);  } else {  zero_extend((*(&zcbz31)), zv, zlen);  }

end_function_4: ;
  goto end_function_95;
end_block_exception_5: ;
  goto end_function_95;
end_function_95: ;
}



void finish_zsail_mask(void)
{    KILL(sail_int)(&zghz30);
}

















void zsail_ones(lbits *rop, sail_int);

lbits zghz31;

void startup_zsail_ones(void)
{    CREATE(lbits)(&zghz31);
}

void zsail_ones(lbits *zcbz32, sail_int zn)
{
  __label__ end_function_7, end_block_exception_8, end_function_94;

  RECREATE(lbits)(&zghz31);
  zeros(&zghz31, zn);
  not_bits((*(&zcbz32)), zghz31);
end_function_7: ;
  goto end_function_94;
end_block_exception_8: ;
  goto end_function_94;
end_function_94: ;
}



void finish_zsail_ones(void)
{    KILL(lbits)(&zghz31);
}









void zfdiv_int(sail_int *rop, sail_int, sail_int);

sail_int zghz32;
sail_int zghz33;
sail_int zghz34;
sail_int zghz35;
sail_int zghz36;
sail_int zghz37;
sail_int zghz38;
sail_int zghz39;
sail_int zghz310;
sail_int zghz311;
sail_int zghz312;
sail_int zghz313;

void startup_zfdiv_int(void)
{
  CREATE(sail_int)(&zghz32);
  CREATE(sail_int)(&zghz33);
  CREATE(sail_int)(&zghz34);
  CREATE(sail_int)(&zghz35);
  CREATE(sail_int)(&zghz36);
  CREATE(sail_int)(&zghz37);
  CREATE(sail_int)(&zghz38);
  CREATE(sail_int)(&zghz39);
  CREATE(sail_int)(&zghz310);
  CREATE(sail_int)(&zghz311);
  CREATE(sail_int)(&zghz312);
  CREATE(sail_int)(&zghz313);
}

void zfdiv_int(sail_int *zcbz33, sail_int zn, sail_int zm)
{
  __label__ end_function_10, end_block_exception_11, end_function_93;

  bool zgaz35;
  {
    bool zgaz34;
    {
      RECREATE(sail_int)(&zghz313);
      CONVERT_OF(sail_int, mach_int)(&zghz313, INT64_C(0));
      zgaz34 = lt(zn, zghz313);
    }
    bool zgsz31;
    if (zgaz34) {
    {
      RECREATE(sail_int)(&zghz312);
      CONVERT_OF(sail_int, mach_int)(&zghz312, INT64_C(0));
      zgsz31 = gt(zm, zghz312);
    }
    } else {  zgsz31 = false;  }
    zgaz35 = zgsz31;
  
  }
  if (zgaz35) {
  RECREATE(sail_int)(&zghz38);
  {
    RECREATE(sail_int)(&zghz310);
    {
      RECREATE(sail_int)(&zghz311);
      CONVERT_OF(sail_int, mach_int)(&zghz311, INT64_C(1));
      add_int(&zghz310, zn, zghz311);
    }
    tdiv_int(&zghz38, zghz310, zm);
  }
  {
    RECREATE(sail_int)(&zghz39);
    CONVERT_OF(sail_int, mach_int)(&zghz39, INT64_C(1));
    sub_int((*(&zcbz33)), zghz38, zghz39);
  }
  } else {
  bool zgaz39;
  {
    bool zgaz38;
    {
      RECREATE(sail_int)(&zghz37);
      CONVERT_OF(sail_int, mach_int)(&zghz37, INT64_C(0));
      zgaz38 = gt(zn, zghz37);
    }
    bool zgsz34;
    if (zgaz38) {
    {
      RECREATE(sail_int)(&zghz36);
      CONVERT_OF(sail_int, mach_int)(&zghz36, INT64_C(0));
      zgsz34 = lt(zm, zghz36);
    }
    } else {  zgsz34 = false;  }
    zgaz39 = zgsz34;
  
  }
  if (zgaz39) {
  RECREATE(sail_int)(&zghz32);
  {
    RECREATE(sail_int)(&zghz34);
    {
      RECREATE(sail_int)(&zghz35);
      CONVERT_OF(sail_int, mach_int)(&zghz35, INT64_C(1));
      sub_int(&zghz34, zn, zghz35);
    }
    tdiv_int(&zghz32, zghz34, zm);
  }
  {
    RECREATE(sail_int)(&zghz33);
    CONVERT_OF(sail_int, mach_int)(&zghz33, INT64_C(1));
    sub_int((*(&zcbz33)), zghz32, zghz33);
  }
  } else {  tdiv_int((*(&zcbz33)), zn, zm);  }

  }

end_function_10: ;
  goto end_function_93;
end_block_exception_11: ;
  goto end_function_93;
end_function_93: ;
}



void finish_zfdiv_int(void)
{
  KILL(sail_int)(&zghz313);
  KILL(sail_int)(&zghz312);
  KILL(sail_int)(&zghz311);
  KILL(sail_int)(&zghz310);
  KILL(sail_int)(&zghz39);
  KILL(sail_int)(&zghz38);
  KILL(sail_int)(&zghz37);
  KILL(sail_int)(&zghz36);
  KILL(sail_int)(&zghz35);
  KILL(sail_int)(&zghz34);
  KILL(sail_int)(&zghz33);
  KILL(sail_int)(&zghz32);
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


  zz5vecz8z6z8z5bv32z9z9 zgsz311;
  CREATE(zz5vecz8z6z8z5bv32z9z9)(&zgsz311);
  zz5vecz8z6z8z5bv32z9z9 zgsz310;
  CREATE(zz5vecz8z6z8z5bv32z9z9)(&zgsz310);
  internal_vector_init_zz5vecz8z6z8z5bv32z9z9(&zgsz310, INT64_C(8));
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz310, zgsz310, INT64_C(0), &zzzero);
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz310, zgsz310, INT64_C(1), &zra);
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz310, zgsz310, INT64_C(2), &zsp);
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz310, zgsz310, INT64_C(3), &zgp);
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz310, zgsz310, INT64_C(4), &za0);
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz310, zgsz310, INT64_C(5), &za1);
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz310, zgsz310, INT64_C(6), &za2);
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz310, zgsz310, INT64_C(7), &za3);
  COPY(zz5vecz8z6z8z5bv32z9z9)(&zgsz311, zgsz310);
  KILL(zz5vecz8z6z8z5bv32z9z9)(&zgsz310);
  COPY(zz5vecz8z6z8z5bv32z9z9)(&zX, zgsz311);
  KILL(zz5vecz8z6z8z5bv32z9z9)(&zgsz311);
let_end_12: ;
}
static void kill_letbind_0(void) {    KILL(zz5vecz8z6z8z5bv32z9z9)(&zX);
}






void zdecode(struct zoption *rop, uint64_t);






unit zexecute(struct zast);


















void zdecode(struct zoption *zcbz34, uint64_t zmergez3var)
{
  __label__ case_15, case_16, case_17, case_18, case_19, case_20, case_21, case_22, case_23, case_24, case_25, case_26, case_27, case_28, case_29, case_30, case_31, case_32, case_33, case_34, finish_match_14, end_function_35, end_block_exception_36, end_function_92;

  struct zoption zgsz312;
  CREATE(zoption)(&zgsz312);
  {
    uint64_t zv__0;
    zv__0 = zmergez3var;
    bool zgaz315;
    {
      uint64_t zgaz313;
      zgaz313 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__0 >> INT64_C(25)));
      zgaz315 = (zgaz313 == UINT64_C(0b0000000));
    
    }
    bool zgsz313;
    if (zgaz315) {
    uint64_t zgaz314;
    zgaz314 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__0 >> INT64_C(0)));
    zgsz313 = (zgaz314 == UINT64_C(0b0110011));
  
    } else {  zgsz313 = false;  }
    bool zgsz315;
    zgsz315 = zgsz313;
  
    if (!(zgsz315)) {
  
    goto case_15;
    }
    uint64_t zrs2;
    zrs2 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(20)));
    uint64_t zrs1;
    zrs1 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(15)));
    uint64_t zrd;
    zrd = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(7)));
    struct zast zgaz312;
    CREATE(zast)(&zgaz312);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz314;
      zgsz314.ztup0 = zrs2;
      zgsz314.ztup1 = zrs1;
      zgsz314.ztup2 = zrd;
      zgsz314.ztup3 = zADD;
      zRTYPE(&zgaz312, zgsz314);
    
    }
    {
      struct zast zgsz3168;
      CREATE(zast)(&zgsz3168);
      COPY(zast)(&zgsz3168, zgaz312);
      zSomez3z5unionz0zzast(&zgsz312, zgsz3168);
      KILL(zast)(&zgsz3168);
    }
    KILL(zast)(&zgaz312);
  
  
  
  
    goto finish_match_14;
  }
case_15: ;
  {
    uint64_t zv__3;
    zv__3 = zmergez3var;
    bool zgaz319;
    {
      uint64_t zgaz317;
      zgaz317 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__3 >> INT64_C(25)));
      zgaz319 = (zgaz317 == UINT64_C(0b0000000));
    
    }
    bool zgsz316;
    if (zgaz319) {
    uint64_t zgaz318;
    zgaz318 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__3 >> INT64_C(0)));
    zgsz316 = (zgaz318 == UINT64_C(0b0110011));
  
    } else {  zgsz316 = false;  }
    bool zgsz318;
    zgsz318 = zgsz316;
  
    if (!(zgsz318)) {
  
    goto case_16;
    }
    uint64_t zuz30;
    zuz30 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(20)));
    uint64_t zuz31;
    zuz31 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(15)));
    uint64_t zuz32;
    zuz32 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(7)));
    struct zast zgaz316;
    CREATE(zast)(&zgaz316);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz317;
      zgsz317.ztup0 = zuz30;
      zgsz317.ztup1 = zuz31;
      zgsz317.ztup2 = zuz32;
      zgsz317.ztup3 = zAND;
      zRTYPE(&zgaz316, zgsz317);
    
    }
    {
      struct zast zgsz3169;
      CREATE(zast)(&zgsz3169);
      COPY(zast)(&zgsz3169, zgaz316);
      zSomez3z5unionz0zzast(&zgsz312, zgsz3169);
      KILL(zast)(&zgsz3169);
    }
    KILL(zast)(&zgaz316);
  
  
  
  
    goto finish_match_14;
  }
case_16: ;
  {
    uint64_t zv__6;
    zv__6 = zmergez3var;
    bool zgaz323;
    {
      uint64_t zgaz321;
      zgaz321 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__6 >> INT64_C(25)));
      zgaz323 = (zgaz321 == UINT64_C(0b0000000));
    
    }
    bool zgsz319;
    if (zgaz323) {
    uint64_t zgaz322;
    zgaz322 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__6 >> INT64_C(0)));
    zgsz319 = (zgaz322 == UINT64_C(0b0110011));
  
    } else {  zgsz319 = false;  }
    bool zgsz321;
    zgsz321 = zgsz319;
  
    if (!(zgsz321)) {
  
    goto case_17;
    }
    uint64_t zuz33;
    zuz33 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(20)));
    uint64_t zuz34;
    zuz34 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(15)));
    uint64_t zuz35;
    zuz35 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(7)));
    struct zast zgaz320;
    CREATE(zast)(&zgaz320);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz320;
      zgsz320.ztup0 = zuz33;
      zgsz320.ztup1 = zuz34;
      zgsz320.ztup2 = zuz35;
      zgsz320.ztup3 = zOR;
      zRTYPE(&zgaz320, zgsz320);
    
    }
    {
      struct zast zgsz3170;
      CREATE(zast)(&zgsz3170);
      COPY(zast)(&zgsz3170, zgaz320);
      zSomez3z5unionz0zzast(&zgsz312, zgsz3170);
      KILL(zast)(&zgsz3170);
    }
    KILL(zast)(&zgaz320);
  
  
  
  
    goto finish_match_14;
  }
case_17: ;
  {
    uint64_t zv__9;
    zv__9 = zmergez3var;
    bool zgaz327;
    {
      uint64_t zgaz325;
      zgaz325 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__9 >> INT64_C(25)));
      zgaz327 = (zgaz325 == UINT64_C(0b0000000));
    
    }
    bool zgsz322;
    if (zgaz327) {
    uint64_t zgaz326;
    zgaz326 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__9 >> INT64_C(0)));
    zgsz322 = (zgaz326 == UINT64_C(0b0110011));
  
    } else {  zgsz322 = false;  }
    bool zgsz324;
    zgsz324 = zgsz322;
  
    if (!(zgsz324)) {
  
    goto case_18;
    }
    uint64_t zuz36;
    zuz36 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(20)));
    uint64_t zuz37;
    zuz37 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(15)));
    uint64_t zuz38;
    zuz38 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(7)));
    struct zast zgaz324;
    CREATE(zast)(&zgaz324);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz323;
      zgsz323.ztup0 = zuz36;
      zgsz323.ztup1 = zuz37;
      zgsz323.ztup2 = zuz38;
      zgsz323.ztup3 = zXOR;
      zRTYPE(&zgaz324, zgsz323);
    
    }
    {
      struct zast zgsz3171;
      CREATE(zast)(&zgsz3171);
      COPY(zast)(&zgsz3171, zgaz324);
      zSomez3z5unionz0zzast(&zgsz312, zgsz3171);
      KILL(zast)(&zgsz3171);
    }
    KILL(zast)(&zgaz324);
  
  
  
  
    goto finish_match_14;
  }
case_18: ;
  {
    uint64_t zv__12;
    zv__12 = zmergez3var;
    bool zgaz331;
    {
      uint64_t zgaz329;
      zgaz329 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__12 >> INT64_C(25)));
      zgaz331 = (zgaz329 == UINT64_C(0b0000001));
    
    }
    bool zgsz325;
    if (zgaz331) {
    uint64_t zgaz330;
    zgaz330 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__12 >> INT64_C(0)));
    zgsz325 = (zgaz330 == UINT64_C(0b0110011));
  
    } else {  zgsz325 = false;  }
    bool zgsz327;
    zgsz327 = zgsz325;
  
    if (!(zgsz327)) {
  
    goto case_19;
    }
    uint64_t zuz39;
    zuz39 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(20)));
    uint64_t zuz310;
    zuz310 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(15)));
    uint64_t zuz311;
    zuz311 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(7)));
    struct zast zgaz328;
    CREATE(zast)(&zgaz328);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz326;
      zgsz326.ztup0 = zuz39;
      zgsz326.ztup1 = zuz310;
      zgsz326.ztup2 = zuz311;
      zgsz326.ztup3 = zMUL;
      zRTYPE(&zgaz328, zgsz326);
    
    }
    {
      struct zast zgsz3172;
      CREATE(zast)(&zgsz3172);
      COPY(zast)(&zgsz3172, zgaz328);
      zSomez3z5unionz0zzast(&zgsz312, zgsz3172);
      KILL(zast)(&zgsz3172);
    }
    KILL(zast)(&zgaz328);
  
  
  
  
    goto finish_match_14;
  }
case_19: ;
  {
    uint64_t zv__15;
    zv__15 = zmergez3var;
    bool zgaz335;
    {
      uint64_t zgaz333;
      zgaz333 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__15 >> INT64_C(25)));
      zgaz335 = (zgaz333 == UINT64_C(0b0000001));
    
    }
    bool zgsz328;
    if (zgaz335) {
    uint64_t zgaz334;
    zgaz334 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__15 >> INT64_C(0)));
    zgsz328 = (zgaz334 == UINT64_C(0b0110011));
  
    } else {  zgsz328 = false;  }
    bool zgsz330;
    zgsz330 = zgsz328;
  
    if (!(zgsz330)) {
  
    goto case_20;
    }
    uint64_t zuz312;
    zuz312 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(20)));
    uint64_t zuz313;
    zuz313 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(15)));
    uint64_t zuz314;
    zuz314 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(7)));
    struct zast zgaz332;
    CREATE(zast)(&zgaz332);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz329;
      zgsz329.ztup0 = zuz312;
      zgsz329.ztup1 = zuz313;
      zgsz329.ztup2 = zuz314;
      zgsz329.ztup3 = zDIV;
      zRTYPE(&zgaz332, zgsz329);
    
    }
    {
      struct zast zgsz3173;
      CREATE(zast)(&zgsz3173);
      COPY(zast)(&zgsz3173, zgaz332);
      zSomez3z5unionz0zzast(&zgsz312, zgsz3173);
      KILL(zast)(&zgsz3173);
    }
    KILL(zast)(&zgaz332);
  
  
  
  
    goto finish_match_14;
  }
case_20: ;
  {
    uint64_t zv__18;
    zv__18 = zmergez3var;
    bool zgaz339;
    {
      uint64_t zgaz337;
      zgaz337 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__18 >> INT64_C(25)));
      zgaz339 = (zgaz337 == UINT64_C(0b0000001));
    
    }
    bool zgsz331;
    if (zgaz339) {
    uint64_t zgaz338;
    zgaz338 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__18 >> INT64_C(0)));
    zgsz331 = (zgaz338 == UINT64_C(0b0110011));
  
    } else {  zgsz331 = false;  }
    bool zgsz333;
    zgsz333 = zgsz331;
  
    if (!(zgsz333)) {
  
    goto case_21;
    }
    uint64_t zuz315;
    zuz315 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(20)));
    uint64_t zuz316;
    zuz316 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(15)));
    uint64_t zuz317;
    zuz317 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(7)));
    struct zast zgaz336;
    CREATE(zast)(&zgaz336);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz332;
      zgsz332.ztup0 = zuz315;
      zgsz332.ztup1 = zuz316;
      zgsz332.ztup2 = zuz317;
      zgsz332.ztup3 = zREM;
      zRTYPE(&zgaz336, zgsz332);
    
    }
    {
      struct zast zgsz3174;
      CREATE(zast)(&zgsz3174);
      COPY(zast)(&zgsz3174, zgaz336);
      zSomez3z5unionz0zzast(&zgsz312, zgsz3174);
      KILL(zast)(&zgsz3174);
    }
    KILL(zast)(&zgaz336);
  
  
  
  
    goto finish_match_14;
  }
case_21: ;
  {
    uint64_t zv__21;
    zv__21 = zmergez3var;
    uint64_t zgaz341;
    zgaz341 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__21 >> INT64_C(0)));
    bool zgsz335;
    zgsz335 = (zgaz341 == UINT64_C(0b0010011));
  
    if (!(zgsz335)) {
  
    goto case_22;
    }
    uint64_t zimm;
    zimm = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__21 >> INT64_C(20)));
    uint64_t zuz318;
    zuz318 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__21 >> INT64_C(15)));
    uint64_t zuz319;
    zuz319 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__21 >> INT64_C(7)));
    uint64_t zimmshadowz30;
    zimmshadowz30 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__21 >> INT64_C(20)));
    struct zast zgaz340;
    CREATE(zast)(&zgaz340);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz334;
      zgsz334.ztup0 = zimmshadowz30;
      zgsz334.ztup1 = zuz318;
      zgsz334.ztup2 = zuz319;
      zgsz334.ztup3 = zADDI;
      zITYPE(&zgaz340, zgsz334);
    
    }
    {
      struct zast zgsz3175;
      CREATE(zast)(&zgsz3175);
      COPY(zast)(&zgsz3175, zgaz340);
      zSomez3z5unionz0zzast(&zgsz312, zgsz3175);
      KILL(zast)(&zgsz3175);
    }
    KILL(zast)(&zgaz340);
  
  
  
  
  
    goto finish_match_14;
  }
case_22: ;
  {
    uint64_t zv__23;
    zv__23 = zmergez3var;
    uint64_t zgaz343;
    zgaz343 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__23 >> INT64_C(0)));
    bool zgsz337;
    zgsz337 = (zgaz343 == UINT64_C(0b0010011));
  
    if (!(zgsz337)) {
  
    goto case_23;
    }
    uint64_t zuz320;
    zuz320 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__23 >> INT64_C(20)));
    uint64_t zuz321;
    zuz321 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__23 >> INT64_C(15)));
    uint64_t zuz322;
    zuz322 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__23 >> INT64_C(7)));
    uint64_t zimmshadowz31;
    zimmshadowz31 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__23 >> INT64_C(20)));
    struct zast zgaz342;
    CREATE(zast)(&zgaz342);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz336;
      zgsz336.ztup0 = zimmshadowz31;
      zgsz336.ztup1 = zuz321;
      zgsz336.ztup2 = zuz322;
      zgsz336.ztup3 = zSLTI;
      zITYPE(&zgaz342, zgsz336);
    
    }
    {
      struct zast zgsz3176;
      CREATE(zast)(&zgsz3176);
      COPY(zast)(&zgsz3176, zgaz342);
      zSomez3z5unionz0zzast(&zgsz312, zgsz3176);
      KILL(zast)(&zgsz3176);
    }
    KILL(zast)(&zgaz342);
  
  
  
  
  
    goto finish_match_14;
  }
case_23: ;
  {
    uint64_t zv__25;
    zv__25 = zmergez3var;
    uint64_t zgaz345;
    zgaz345 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__25 >> INT64_C(0)));
    bool zgsz339;
    zgsz339 = (zgaz345 == UINT64_C(0b0010011));
  
    if (!(zgsz339)) {
  
    goto case_24;
    }
    uint64_t zuz323;
    zuz323 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__25 >> INT64_C(20)));
    uint64_t zuz324;
    zuz324 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__25 >> INT64_C(15)));
    uint64_t zuz325;
    zuz325 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__25 >> INT64_C(7)));
    uint64_t zimmshadowz32;
    zimmshadowz32 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__25 >> INT64_C(20)));
    struct zast zgaz344;
    CREATE(zast)(&zgaz344);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz338;
      zgsz338.ztup0 = zimmshadowz32;
      zgsz338.ztup1 = zuz324;
      zgsz338.ztup2 = zuz325;
      zgsz338.ztup3 = zANDI;
      zITYPE(&zgaz344, zgsz338);
    
    }
    {
      struct zast zgsz3177;
      CREATE(zast)(&zgsz3177);
      COPY(zast)(&zgsz3177, zgaz344);
      zSomez3z5unionz0zzast(&zgsz312, zgsz3177);
      KILL(zast)(&zgsz3177);
    }
    KILL(zast)(&zgaz344);
  
  
  
  
  
    goto finish_match_14;
  }
case_24: ;
  {
    uint64_t zv__27;
    zv__27 = zmergez3var;
    uint64_t zgaz347;
    zgaz347 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__27 >> INT64_C(0)));
    bool zgsz341;
    zgsz341 = (zgaz347 == UINT64_C(0b0010011));
  
    if (!(zgsz341)) {
  
    goto case_25;
    }
    uint64_t zuz326;
    zuz326 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__27 >> INT64_C(20)));
    uint64_t zuz327;
    zuz327 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__27 >> INT64_C(15)));
    uint64_t zuz328;
    zuz328 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__27 >> INT64_C(7)));
    uint64_t zimmshadowz33;
    zimmshadowz33 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__27 >> INT64_C(20)));
    struct zast zgaz346;
    CREATE(zast)(&zgaz346);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz340;
      zgsz340.ztup0 = zimmshadowz33;
      zgsz340.ztup1 = zuz327;
      zgsz340.ztup2 = zuz328;
      zgsz340.ztup3 = zORI;
      zITYPE(&zgaz346, zgsz340);
    
    }
    {
      struct zast zgsz3178;
      CREATE(zast)(&zgsz3178);
      COPY(zast)(&zgsz3178, zgaz346);
      zSomez3z5unionz0zzast(&zgsz312, zgsz3178);
      KILL(zast)(&zgsz3178);
    }
    KILL(zast)(&zgaz346);
  
  
  
  
  
    goto finish_match_14;
  }
case_25: ;
  {
    uint64_t zv__29;
    zv__29 = zmergez3var;
    uint64_t zgaz349;
    zgaz349 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__29 >> INT64_C(0)));
    bool zgsz343;
    zgsz343 = (zgaz349 == UINT64_C(0b0010011));
  
    if (!(zgsz343)) {
  
    goto case_26;
    }
    uint64_t zuz329;
    zuz329 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__29 >> INT64_C(20)));
    uint64_t zuz330;
    zuz330 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__29 >> INT64_C(15)));
    uint64_t zuz331;
    zuz331 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__29 >> INT64_C(7)));
    uint64_t zimmshadowz34;
    zimmshadowz34 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__29 >> INT64_C(20)));
    struct zast zgaz348;
    CREATE(zast)(&zgaz348);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz342;
      zgsz342.ztup0 = zimmshadowz34;
      zgsz342.ztup1 = zuz330;
      zgsz342.ztup2 = zuz331;
      zgsz342.ztup3 = zXORI;
      zITYPE(&zgaz348, zgsz342);
    
    }
    {
      struct zast zgsz3179;
      CREATE(zast)(&zgsz3179);
      COPY(zast)(&zgsz3179, zgaz348);
      zSomez3z5unionz0zzast(&zgsz312, zgsz3179);
      KILL(zast)(&zgsz3179);
    }
    KILL(zast)(&zgaz348);
  
  
  
  
  
    goto finish_match_14;
  }
case_26: ;
  {
    uint64_t zv__31;
    zv__31 = zmergez3var;
    uint64_t zgaz351;
    zgaz351 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__31 >> INT64_C(0)));
    bool zgsz345;
    zgsz345 = (zgaz351 == UINT64_C(0b1100111));
  
    if (!(zgsz345)) {
  
    goto case_27;
    }
    uint64_t zuz332;
    zuz332 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__31 >> INT64_C(20)));
    uint64_t zuz333;
    zuz333 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__31 >> INT64_C(15)));
    uint64_t zuz334;
    zuz334 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__31 >> INT64_C(7)));
    uint64_t zimmshadowz35;
    zimmshadowz35 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__31 >> INT64_C(20)));
    struct zast zgaz350;
    CREATE(zast)(&zgaz350);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz344;
      zgsz344.ztup0 = zimmshadowz35;
      zgsz344.ztup1 = zuz333;
      zgsz344.ztup2 = zuz334;
      zgsz344.ztup3 = zJALR;
      zITYPE(&zgaz350, zgsz344);
    
    }
    {
      struct zast zgsz3180;
      CREATE(zast)(&zgsz3180);
      COPY(zast)(&zgsz3180, zgaz350);
      zSomez3z5unionz0zzast(&zgsz312, zgsz3180);
      KILL(zast)(&zgsz3180);
    }
    KILL(zast)(&zgaz350);
  
  
  
  
  
    goto finish_match_14;
  }
case_27: ;
  {
    uint64_t zv__33;
    zv__33 = zmergez3var;
    uint64_t zgaz353;
    zgaz353 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__33 >> INT64_C(0)));
    bool zgsz347;
    zgsz347 = (zgaz353 == UINT64_C(0b0000011));
  
    if (!(zgsz347)) {
  
    goto case_28;
    }
    uint64_t zuz335;
    zuz335 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__33 >> INT64_C(20)));
    uint64_t zuz336;
    zuz336 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__33 >> INT64_C(15)));
    uint64_t zuz337;
    zuz337 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__33 >> INT64_C(7)));
    uint64_t zimmshadowz36;
    zimmshadowz36 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__33 >> INT64_C(20)));
    struct zast zgaz352;
    CREATE(zast)(&zgaz352);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz346;
      zgsz346.ztup0 = zimmshadowz36;
      zgsz346.ztup1 = zuz336;
      zgsz346.ztup2 = zuz337;
      zgsz346.ztup3 = zLW;
      zITYPE(&zgaz352, zgsz346);
    
    }
    {
      struct zast zgsz3181;
      CREATE(zast)(&zgsz3181);
      COPY(zast)(&zgsz3181, zgaz352);
      zSomez3z5unionz0zzast(&zgsz312, zgsz3181);
      KILL(zast)(&zgsz3181);
    }
    KILL(zast)(&zgaz352);
  
  
  
  
  
    goto finish_match_14;
  }
case_28: ;
  {
    uint64_t zv__35;
    zv__35 = zmergez3var;
    uint64_t zgaz355;
    zgaz355 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__35 >> INT64_C(0)));
    bool zgsz349;
    zgsz349 = (zgaz355 == UINT64_C(0b0100011));
  
    if (!(zgsz349)) {
  
    goto case_29;
    }
    uint64_t zimm2;
    zimm2 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__35 >> INT64_C(25)));
    uint64_t zuz338;
    zuz338 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__35 >> INT64_C(20)));
    uint64_t zuz339;
    zuz339 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__35 >> INT64_C(15)));
    uint64_t zimm2shadowz37;
    zimm2shadowz37 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__35 >> INT64_C(25)));
    uint64_t zimm1;
    zimm1 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__35 >> INT64_C(7)));
    struct zast zgaz354;
    CREATE(zast)(&zgaz354);
    {
      struct ztuple_z8z5bv7zCz0z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzsopz9 zgsz348;
      zgsz348.ztup0 = zimm2shadowz37;
      zgsz348.ztup1 = zuz338;
      zgsz348.ztup2 = zuz339;
      zgsz348.ztup3 = zimm1;
      zgsz348.ztup4 = zSW;
      zSTYPE(&zgaz354, zgsz348);
    
    }
    {
      struct zast zgsz3182;
      CREATE(zast)(&zgsz3182);
      COPY(zast)(&zgsz3182, zgaz354);
      zSomez3z5unionz0zzast(&zgsz312, zgsz3182);
      KILL(zast)(&zgsz3182);
    }
    KILL(zast)(&zgaz354);
  
  
  
  
  
  
    goto finish_match_14;
  }
case_29: ;
  {
    uint64_t zv__37;
    zv__37 = zmergez3var;
    uint64_t zgaz357;
    zgaz357 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__37 >> INT64_C(0)));
    bool zgsz351;
    zgsz351 = (zgaz357 == UINT64_C(0b1100011));
  
    if (!(zgsz351)) {
  
    goto case_30;
    }
    uint64_t zimm4;
    zimm4 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__37 >> INT64_C(31)));
    uint64_t zuz340;
    zuz340 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__37 >> INT64_C(20)));
    uint64_t zuz341;
    zuz341 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__37 >> INT64_C(15)));
    uint64_t zimm4shadowz38;
    zimm4shadowz38 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__37 >> INT64_C(31)));
    uint64_t zimm3;
    zimm3 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__37 >> INT64_C(7)));
    uint64_t zuz342;
    zuz342 = (safe_rshift(UINT64_MAX, 64 - 6) & (zv__37 >> INT64_C(25)));
    uint64_t zuz343;
    zuz343 = (safe_rshift(UINT64_MAX, 64 - 4) & (zv__37 >> INT64_C(8)));
    struct zast zgaz356;
    CREATE(zast)(&zgaz356);
    {
      struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 zgsz350;
      zgsz350.ztup0 = zimm4shadowz38;
      zgsz350.ztup1 = zuz342;
      zgsz350.ztup2 = zuz340;
      zgsz350.ztup3 = zuz341;
      zgsz350.ztup4 = zuz343;
      zgsz350.ztup5 = zimm3;
      zgsz350.ztup6 = zBEQ;
      zBTYPE(&zgaz356, zgsz350);
    
    }
    {
      struct zast zgsz3183;
      CREATE(zast)(&zgsz3183);
      COPY(zast)(&zgsz3183, zgaz356);
      zSomez3z5unionz0zzast(&zgsz312, zgsz3183);
      KILL(zast)(&zgsz3183);
    }
    KILL(zast)(&zgaz356);
  
  
  
  
  
  
  
  
    goto finish_match_14;
  }
case_30: ;
  {
    uint64_t zv__39;
    zv__39 = zmergez3var;
    uint64_t zgaz359;
    zgaz359 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__39 >> INT64_C(0)));
    bool zgsz353;
    zgsz353 = (zgaz359 == UINT64_C(0b1100011));
  
    if (!(zgsz353)) {
  
    goto case_31;
    }
    uint64_t zuz344;
    zuz344 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__39 >> INT64_C(31)));
    uint64_t zuz345;
    zuz345 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__39 >> INT64_C(20)));
    uint64_t zuz346;
    zuz346 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__39 >> INT64_C(15)));
    uint64_t zimm4shadowz39;
    zimm4shadowz39 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__39 >> INT64_C(31)));
    uint64_t zuz347;
    zuz347 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__39 >> INT64_C(7)));
    uint64_t zuz348;
    zuz348 = (safe_rshift(UINT64_MAX, 64 - 6) & (zv__39 >> INT64_C(25)));
    uint64_t zuz349;
    zuz349 = (safe_rshift(UINT64_MAX, 64 - 4) & (zv__39 >> INT64_C(8)));
    struct zast zgaz358;
    CREATE(zast)(&zgaz358);
    {
      struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 zgsz352;
      zgsz352.ztup0 = zimm4shadowz39;
      zgsz352.ztup1 = zuz348;
      zgsz352.ztup2 = zuz345;
      zgsz352.ztup3 = zuz346;
      zgsz352.ztup4 = zuz349;
      zgsz352.ztup5 = zuz347;
      zgsz352.ztup6 = zBNE;
      zBTYPE(&zgaz358, zgsz352);
    
    }
    {
      struct zast zgsz3184;
      CREATE(zast)(&zgsz3184);
      COPY(zast)(&zgsz3184, zgaz358);
      zSomez3z5unionz0zzast(&zgsz312, zgsz3184);
      KILL(zast)(&zgsz3184);
    }
    KILL(zast)(&zgaz358);
  
  
  
  
  
  
  
  
    goto finish_match_14;
  }
case_31: ;
  {
    uint64_t zv__41;
    zv__41 = zmergez3var;
    uint64_t zgaz361;
    zgaz361 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__41 >> INT64_C(0)));
    bool zgsz355;
    zgsz355 = (zgaz361 == UINT64_C(0b0110111));
  
    if (!(zgsz355)) {
  
    goto case_32;
    }
    uint64_t zuz350;
    zuz350 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__41 >> INT64_C(12)));
    uint64_t zuz351;
    zuz351 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__41 >> INT64_C(7)));
    uint64_t zimmshadowz310;
    zimmshadowz310 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__41 >> INT64_C(12)));
    struct zast zgaz360;
    CREATE(zast)(&zgaz360);
    {
      struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 zgsz354;
      zgsz354.ztup0 = zimmshadowz310;
      zgsz354.ztup1 = zuz351;
      zgsz354.ztup2 = zLUI;
      zUTYPE(&zgaz360, zgsz354);
    
    }
    {
      struct zast zgsz3185;
      CREATE(zast)(&zgsz3185);
      COPY(zast)(&zgsz3185, zgaz360);
      zSomez3z5unionz0zzast(&zgsz312, zgsz3185);
      KILL(zast)(&zgsz3185);
    }
    KILL(zast)(&zgaz360);
  
  
  
  
    goto finish_match_14;
  }
case_32: ;
  {
    uint64_t zv__43;
    zv__43 = zmergez3var;
    uint64_t zgaz363;
    zgaz363 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__43 >> INT64_C(0)));
    bool zgsz357;
    zgsz357 = (zgaz363 == UINT64_C(0b0010111));
  
    if (!(zgsz357)) {
  
    goto case_33;
    }
    uint64_t zuz352;
    zuz352 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__43 >> INT64_C(12)));
    uint64_t zuz353;
    zuz353 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__43 >> INT64_C(7)));
    uint64_t zimmshadowz311;
    zimmshadowz311 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__43 >> INT64_C(12)));
    struct zast zgaz362;
    CREATE(zast)(&zgaz362);
    {
      struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 zgsz356;
      zgsz356.ztup0 = zimmshadowz311;
      zgsz356.ztup1 = zuz353;
      zgsz356.ztup2 = zAUIPC;
      zUTYPE(&zgaz362, zgsz356);
    
    }
    {
      struct zast zgsz3186;
      CREATE(zast)(&zgsz3186);
      COPY(zast)(&zgsz3186, zgaz362);
      zSomez3z5unionz0zzast(&zgsz312, zgsz3186);
      KILL(zast)(&zgsz3186);
    }
    KILL(zast)(&zgaz362);
  
  
  
  
    goto finish_match_14;
  }
case_33: ;
  {
    uint64_t zv__45;
    zv__45 = zmergez3var;
    uint64_t zgaz365;
    zgaz365 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__45 >> INT64_C(0)));
    bool zgsz359;
    zgsz359 = (zgaz365 == UINT64_C(0b1101111));
  
    if (!(zgsz359)) {
  
    goto case_34;
    }
    uint64_t zuz354;
    zuz354 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__45 >> INT64_C(31)));
    uint64_t zuz355;
    zuz355 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__45 >> INT64_C(7)));
    uint64_t zimm4shadowz312;
    zimm4shadowz312 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__45 >> INT64_C(31)));
    uint64_t zuz356;
    zuz356 = (safe_rshift(UINT64_MAX, 64 - 8) & (zv__45 >> INT64_C(12)));
    uint64_t zuz357;
    zuz357 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__45 >> INT64_C(20)));
    uint64_t zuz358;
    zuz358 = (safe_rshift(UINT64_MAX, 64 - 10) & (zv__45 >> INT64_C(21)));
    struct zast zgaz364;
    CREATE(zast)(&zgaz364);
    {
      struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv8zCz0z5bv5zCz0z5enumz0zzjopz9 zgsz358;
      zgsz358.ztup0 = zimm4shadowz312;
      zgsz358.ztup1 = zuz358;
      zgsz358.ztup2 = zuz357;
      zgsz358.ztup3 = zuz356;
      zgsz358.ztup4 = zuz355;
      zgsz358.ztup5 = zJAL;
      zJTYPE(&zgaz364, zgsz358);
    
    }
    {
      struct zast zgsz3187;
      CREATE(zast)(&zgsz3187);
      COPY(zast)(&zgsz3187, zgaz364);
      zSomez3z5unionz0zzast(&zgsz312, zgsz3187);
      KILL(zast)(&zgsz3187);
    }
    KILL(zast)(&zgaz364);
  
  
  
  
  
  
  
    goto finish_match_14;
  }
case_34: ;
  sail_match_failure("decode");
finish_match_14: ;
  COPY(zoption)((*(&zcbz34)), zgsz312);
  KILL(zoption)(&zgsz312);
end_function_35: ;
  goto end_function_92;
end_block_exception_36: ;
  goto end_function_92;
end_function_92: ;
}

unit zexecute(struct zast zmergez3var)
{
  __label__ case_39, case_40, case_41, case_42, case_43, case_44, case_45, case_46, case_47, case_48, case_49, case_50, case_51, case_52, case_53, case_54, case_55, case_56, case_57, case_58, finish_match_38, end_function_59, end_block_exception_60;

  unit zcbz35;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_39;
    uint64_t zrs2;
    zrs2 = zmergez3var.zRTYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zRTYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zRTYPE.ztup2;
    if ((zADD != zmergez3var.zRTYPE.ztup3)) goto case_39;
    zcbz35 = print_endline("execute ADD\n");
  
  
  
    goto finish_match_38;
  }
case_39: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_40;
    uint64_t zuz359;
    zuz359 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz360;
    zuz360 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz361;
    zuz361 = zmergez3var.zRTYPE.ztup2;
    if ((zAND != zmergez3var.zRTYPE.ztup3)) goto case_40;
    zcbz35 = print_endline("execute AND\n");
  
  
  
    goto finish_match_38;
  }
case_40: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_41;
    uint64_t zuz362;
    zuz362 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz363;
    zuz363 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz364;
    zuz364 = zmergez3var.zRTYPE.ztup2;
    if ((zOR != zmergez3var.zRTYPE.ztup3)) goto case_41;
    zcbz35 = print_endline("execute OR\n");
  
  
  
    goto finish_match_38;
  }
case_41: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_42;
    uint64_t zuz365;
    zuz365 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz366;
    zuz366 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz367;
    zuz367 = zmergez3var.zRTYPE.ztup2;
    if ((zXOR != zmergez3var.zRTYPE.ztup3)) goto case_42;
    zcbz35 = print_endline("execute XOR\n");
  
  
  
    goto finish_match_38;
  }
case_42: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_43;
    uint64_t zuz368;
    zuz368 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz369;
    zuz369 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz370;
    zuz370 = zmergez3var.zRTYPE.ztup2;
    if ((zMUL != zmergez3var.zRTYPE.ztup3)) goto case_43;
    zcbz35 = print_endline("execute MUL\n");
  
  
  
    goto finish_match_38;
  }
case_43: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_44;
    uint64_t zuz371;
    zuz371 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz372;
    zuz372 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz373;
    zuz373 = zmergez3var.zRTYPE.ztup2;
    if ((zDIV != zmergez3var.zRTYPE.ztup3)) goto case_44;
    zcbz35 = print_endline("execute DIV\n");
  
  
  
    goto finish_match_38;
  }
case_44: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_45;
    uint64_t zuz374;
    zuz374 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz375;
    zuz375 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz376;
    zuz376 = zmergez3var.zRTYPE.ztup2;
    if ((zREM != zmergez3var.zRTYPE.ztup3)) goto case_45;
    zcbz35 = print_endline("execute REM\n");
  
  
  
    goto finish_match_38;
  }
case_45: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_46;
    uint64_t zimm;
    zimm = zmergez3var.zITYPE.ztup0;
    uint64_t zuz377;
    zuz377 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz378;
    zuz378 = zmergez3var.zITYPE.ztup2;
    if ((zADDI != zmergez3var.zITYPE.ztup3)) goto case_46;
    zcbz35 = print_endline("execute ADDI\n");
  
  
  
    goto finish_match_38;
  }
case_46: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_47;
    uint64_t zuz379;
    zuz379 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz380;
    zuz380 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz381;
    zuz381 = zmergez3var.zITYPE.ztup2;
    if ((zSLTI != zmergez3var.zITYPE.ztup3)) goto case_47;
    zcbz35 = print_endline("execute SLTI\n");
  
  
  
    goto finish_match_38;
  }
case_47: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_48;
    uint64_t zuz382;
    zuz382 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz383;
    zuz383 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz384;
    zuz384 = zmergez3var.zITYPE.ztup2;
    if ((zANDI != zmergez3var.zITYPE.ztup3)) goto case_48;
    zcbz35 = print_endline("execute ANDI\n");
  
  
  
    goto finish_match_38;
  }
case_48: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_49;
    uint64_t zuz385;
    zuz385 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz386;
    zuz386 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz387;
    zuz387 = zmergez3var.zITYPE.ztup2;
    if ((zORI != zmergez3var.zITYPE.ztup3)) goto case_49;
    zcbz35 = print_endline("execute ORI\n");
  
  
  
    goto finish_match_38;
  }
case_49: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_50;
    uint64_t zuz388;
    zuz388 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz389;
    zuz389 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz390;
    zuz390 = zmergez3var.zITYPE.ztup2;
    if ((zXORI != zmergez3var.zITYPE.ztup3)) goto case_50;
    zcbz35 = print_endline("execute XORI\n");
  
  
  
    goto finish_match_38;
  }
case_50: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_51;
    uint64_t zuz391;
    zuz391 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz392;
    zuz392 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz393;
    zuz393 = zmergez3var.zITYPE.ztup2;
    if ((zJALR != zmergez3var.zITYPE.ztup3)) goto case_51;
    zcbz35 = print_endline("execute JALR\n");
  
  
  
    goto finish_match_38;
  }
case_51: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_52;
    uint64_t zuz394;
    zuz394 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz395;
    zuz395 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz396;
    zuz396 = zmergez3var.zITYPE.ztup2;
    if ((zLW != zmergez3var.zITYPE.ztup3)) goto case_52;
    zcbz35 = print_endline("execute LW\n");
  
  
  
    goto finish_match_38;
  }
case_52: ;
  {
    if (zmergez3var.kind != Kind_zSTYPE) goto case_53;
    uint64_t zimm2;
    zimm2 = zmergez3var.zSTYPE.ztup0;
    uint64_t zuz397;
    zuz397 = zmergez3var.zSTYPE.ztup1;
    uint64_t zuz398;
    zuz398 = zmergez3var.zSTYPE.ztup2;
    uint64_t zimm1;
    zimm1 = zmergez3var.zSTYPE.ztup3;
    if ((zSW != zmergez3var.zSTYPE.ztup4)) goto case_53;
    zcbz35 = print_endline("execute SW\n");
  
  
  
  
    goto finish_match_38;
  }
case_53: ;
  {
    if (zmergez3var.kind != Kind_zBTYPE) goto case_54;
    uint64_t zimm4;
    zimm4 = zmergez3var.zBTYPE.ztup0;
    uint64_t zuz399;
    zuz399 = zmergez3var.zBTYPE.ztup1;
    uint64_t zuz3100;
    zuz3100 = zmergez3var.zBTYPE.ztup2;
    uint64_t zuz3101;
    zuz3101 = zmergez3var.zBTYPE.ztup3;
    uint64_t zuz3102;
    zuz3102 = zmergez3var.zBTYPE.ztup4;
    uint64_t zimm3;
    zimm3 = zmergez3var.zBTYPE.ztup5;
    if ((zBEQ != zmergez3var.zBTYPE.ztup6)) goto case_54;
    zcbz35 = print_endline("execute BEQ\n");
  
  
  
  
  
  
    goto finish_match_38;
  }
case_54: ;
  {
    if (zmergez3var.kind != Kind_zBTYPE) goto case_55;
    uint64_t zuz3103;
    zuz3103 = zmergez3var.zBTYPE.ztup0;
    uint64_t zuz3104;
    zuz3104 = zmergez3var.zBTYPE.ztup1;
    uint64_t zuz3105;
    zuz3105 = zmergez3var.zBTYPE.ztup2;
    uint64_t zuz3106;
    zuz3106 = zmergez3var.zBTYPE.ztup3;
    uint64_t zuz3107;
    zuz3107 = zmergez3var.zBTYPE.ztup4;
    uint64_t zuz3108;
    zuz3108 = zmergez3var.zBTYPE.ztup5;
    if ((zBNE != zmergez3var.zBTYPE.ztup6)) goto case_55;
    zcbz35 = print_endline("execute BNE\n");
  
  
  
  
  
  
    goto finish_match_38;
  }
case_55: ;
  {
    if (zmergez3var.kind != Kind_zUTYPE) goto case_56;
    uint64_t zuz3109;
    zuz3109 = zmergez3var.zUTYPE.ztup0;
    uint64_t zuz3110;
    zuz3110 = zmergez3var.zUTYPE.ztup1;
    if ((zLUI != zmergez3var.zUTYPE.ztup2)) goto case_56;
    zcbz35 = print_endline("execute LUI\n");
  
  
    goto finish_match_38;
  }
case_56: ;
  {
    if (zmergez3var.kind != Kind_zUTYPE) goto case_57;
    uint64_t zuz3111;
    zuz3111 = zmergez3var.zUTYPE.ztup0;
    uint64_t zuz3112;
    zuz3112 = zmergez3var.zUTYPE.ztup1;
    if ((zAUIPC != zmergez3var.zUTYPE.ztup2)) goto case_57;
    zcbz35 = print_endline("execute AUIPC\n");
  
  
    goto finish_match_38;
  }
case_57: ;
  {
    if (zmergez3var.kind != Kind_zJTYPE) goto case_58;
    uint64_t zuz3113;
    zuz3113 = zmergez3var.zJTYPE.ztup0;
    uint64_t zuz3114;
    zuz3114 = zmergez3var.zJTYPE.ztup1;
    uint64_t zuz3115;
    zuz3115 = zmergez3var.zJTYPE.ztup2;
    uint64_t zuz3116;
    zuz3116 = zmergez3var.zJTYPE.ztup3;
    uint64_t zuz3117;
    zuz3117 = zmergez3var.zJTYPE.ztup4;
    if ((zJAL != zmergez3var.zJTYPE.ztup5)) goto case_58;
    zcbz35 = print_endline("execute JAL\n");
  
  
  
  
  
    goto finish_match_38;
  }
case_58: ;
  sail_match_failure("execute");
finish_match_38: ;
end_function_59: ;
  return zcbz35;
end_block_exception_60: ;

  return UNIT;
}

// register PC
uint64_t zPC;

void zextzz(lbits *rop, sail_int, lbits);

void zextzz(lbits *zcbz36, sail_int zm, lbits zxs)
{
  __label__ end_function_62, end_block_exception_63, end_function_91;

  zero_extend((*(&zcbz36)), zxs, zm);
end_function_62: ;
  goto end_function_91;
end_block_exception_63: ;
  goto end_function_91;
end_function_91: ;
}

unit zadd_bytes_to_PC(sail_int);

sail_int zghz314;
sail_int zghz315;
lbits zghz316;
lbits zghz317;
sail_int zghz318;
sail_int zghz319;
sail_int zghz320;
lbits zghz321;
lbits zghz322;
sail_int zghz323;
sail_int zghz324;
sail_int zghz325;
lbits zghz326;
lbits zghz327;
sail_int zghz328;
sail_int zghz329;
sail_int zghz330;
lbits zghz331;
lbits zghz332;
sail_int zghz333;
sail_int zghz334;
lbits zghz335;
lbits zghz336;

void startup_zadd_bytes_to_PC(void)
{
  CREATE(sail_int)(&zghz314);
  CREATE(sail_int)(&zghz315);
  CREATE(lbits)(&zghz316);
  CREATE(lbits)(&zghz317);
  CREATE(sail_int)(&zghz318);
  CREATE(sail_int)(&zghz319);
  CREATE(sail_int)(&zghz320);
  CREATE(lbits)(&zghz321);
  CREATE(lbits)(&zghz322);
  CREATE(sail_int)(&zghz323);
  CREATE(sail_int)(&zghz324);
  CREATE(sail_int)(&zghz325);
  CREATE(lbits)(&zghz326);
  CREATE(lbits)(&zghz327);
  CREATE(sail_int)(&zghz328);
  CREATE(sail_int)(&zghz329);
  CREATE(sail_int)(&zghz330);
  CREATE(lbits)(&zghz331);
  CREATE(lbits)(&zghz332);
  CREATE(sail_int)(&zghz333);
  CREATE(sail_int)(&zghz334);
  CREATE(lbits)(&zghz335);
  CREATE(lbits)(&zghz336);
}

unit zadd_bytes_to_PC(sail_int zbytes)
{
  __label__ end_function_71, end_block_exception_72;

  unit zcbz37;
  uint64_t zx;
  {
    RECREATE(sail_int)(&zghz334);
    CONVERT_OF(sail_int, mach_int)(&zghz334, INT64_C(32));
    RECREATE(lbits)(&zghz335);
    CONVERT_OF(lbits, fbits)(&zghz335, UINT64_C(0x0), UINT64_C(4) , true);
    RECREATE(lbits)(&zghz336);
    zextzz(&zghz336, zghz334, zghz335);
    zx = CONVERT_OF(fbits, lbits)(zghz336, true);
  }
  {
    __label__ case_66, case_67, case_68, case_69, case_70, finish_match_65;

    unit zgsz384;
    {
      RECREATE(sail_int)(&zghz329);
      COPY(sail_int)(&zghz329, zbytes);
      bool zgsz388;
      {
        RECREATE(sail_int)(&zghz333);
        CONVERT_OF(sail_int, mach_int)(&zghz333, INT64_C(1));
        zgsz388 = eq_int(zghz329, zghz333);
      }
      if (!(zgsz388))
        goto case_66;
      {
        RECREATE(sail_int)(&zghz330);
        CONVERT_OF(sail_int, mach_int)(&zghz330, INT64_C(32));
        RECREATE(lbits)(&zghz331);
        CONVERT_OF(lbits, fbits)(&zghz331, UINT64_C(0x8), UINT64_C(4) , true);
        RECREATE(lbits)(&zghz332);
        zextzz(&zghz332, zghz330, zghz331);
        zx = CONVERT_OF(fbits, lbits)(zghz332, true);
      }
      zgsz384 = UNIT;
      goto finish_match_65;
    }
  case_66: ;
    {
      RECREATE(sail_int)(&zghz324);
      COPY(sail_int)(&zghz324, zbytes);
      bool zgsz393;
      {
        RECREATE(sail_int)(&zghz328);
        CONVERT_OF(sail_int, mach_int)(&zghz328, INT64_C(2));
        zgsz393 = eq_int(zghz324, zghz328);
      }
      if (!(zgsz393))
        goto case_67;
      {
        RECREATE(sail_int)(&zghz325);
        CONVERT_OF(sail_int, mach_int)(&zghz325, INT64_C(32));
        RECREATE(lbits)(&zghz326);
        CONVERT_OF(lbits, fbits)(&zghz326, UINT64_C(0x10), UINT64_C(8) , true);
        RECREATE(lbits)(&zghz327);
        zextzz(&zghz327, zghz325, zghz326);
        zx = CONVERT_OF(fbits, lbits)(zghz327, true);
      }
      zgsz384 = UNIT;
      goto finish_match_65;
    }
  case_67: ;
    {
      RECREATE(sail_int)(&zghz319);
      COPY(sail_int)(&zghz319, zbytes);
      bool zgsz398;
      {
        RECREATE(sail_int)(&zghz323);
        CONVERT_OF(sail_int, mach_int)(&zghz323, INT64_C(3));
        zgsz398 = eq_int(zghz319, zghz323);
      }
      if (!(zgsz398))
        goto case_68;
      {
        RECREATE(sail_int)(&zghz320);
        CONVERT_OF(sail_int, mach_int)(&zghz320, INT64_C(32));
        RECREATE(lbits)(&zghz321);
        CONVERT_OF(lbits, fbits)(&zghz321, UINT64_C(0x18), UINT64_C(8) , true);
        RECREATE(lbits)(&zghz322);
        zextzz(&zghz322, zghz320, zghz321);
        zx = CONVERT_OF(fbits, lbits)(zghz322, true);
      }
      zgsz384 = UNIT;
      goto finish_match_65;
    }
  case_68: ;
    {
      RECREATE(sail_int)(&zghz314);
      COPY(sail_int)(&zghz314, zbytes);
      bool zgsz3103;
      {
        RECREATE(sail_int)(&zghz318);
        CONVERT_OF(sail_int, mach_int)(&zghz318, INT64_C(4));
        zgsz3103 = eq_int(zghz314, zghz318);
      }
      if (!(zgsz3103))
        goto case_69;
      {
        RECREATE(sail_int)(&zghz315);
        CONVERT_OF(sail_int, mach_int)(&zghz315, INT64_C(32));
        RECREATE(lbits)(&zghz316);
        CONVERT_OF(lbits, fbits)(&zghz316, UINT64_C(0x20), UINT64_C(8) , true);
        RECREATE(lbits)(&zghz317);
        zextzz(&zghz317, zghz315, zghz316);
        zx = CONVERT_OF(fbits, lbits)(zghz317, true);
      }
      zgsz384 = UNIT;
      goto finish_match_65;
    }
  case_69: ;
    {
      zgsz384 = print_endline("Cannot add this amount of bytes to PC register");
      goto finish_match_65;
    }
  case_70: ;
    sail_match_failure("add_bytes_to_PC");
  finish_match_65: ;
    unit zgsz3106;
    zgsz3106 = zgsz384;
  
  }
  uint64_t* zgaz366;
  zgaz366 = &zPC;
  (*(zgaz366)) = ((zPC + zx) & UINT64_C(0xFFFFFFFF));
  zcbz37 = UNIT;


end_function_71: ;
  return zcbz37;
end_block_exception_72: ;

  return UNIT;
}



void finish_zadd_bytes_to_PC(void)
{
  KILL(lbits)(&zghz336);
  KILL(lbits)(&zghz335);
  KILL(sail_int)(&zghz334);
  KILL(sail_int)(&zghz333);
  KILL(lbits)(&zghz332);
  KILL(lbits)(&zghz331);
  KILL(sail_int)(&zghz330);
  KILL(sail_int)(&zghz329);
  KILL(sail_int)(&zghz328);
  KILL(lbits)(&zghz327);
  KILL(lbits)(&zghz326);
  KILL(sail_int)(&zghz325);
  KILL(sail_int)(&zghz324);
  KILL(sail_int)(&zghz323);
  KILL(lbits)(&zghz322);
  KILL(lbits)(&zghz321);
  KILL(sail_int)(&zghz320);
  KILL(sail_int)(&zghz319);
  KILL(sail_int)(&zghz318);
  KILL(lbits)(&zghz317);
  KILL(lbits)(&zghz316);
  KILL(sail_int)(&zghz315);
  KILL(sail_int)(&zghz314);
}

unit zadd_4_bytes_to_PC(unit);

sail_int zghz337;

void startup_zadd_4_bytes_to_PC(void)
{    CREATE(sail_int)(&zghz337);
}

unit zadd_4_bytes_to_PC(unit zgsz3107)
{
  __label__ end_function_74, end_block_exception_75;

  unit zcbz38;
  {
    RECREATE(sail_int)(&zghz337);
    CONVERT_OF(sail_int, mach_int)(&zghz337, INT64_C(4));
    zcbz38 = zadd_bytes_to_PC(zghz337);
  }
end_function_74: ;
  return zcbz38;
end_block_exception_75: ;

  return UNIT;
}



void finish_zadd_4_bytes_to_PC(void)
{    KILL(sail_int)(&zghz337);
}



uint64_t zread_mem(uint64_t);

sail_int zghz338;
sail_int zghz339;
lbits zghz340;
lbits zghz341;
lbits zghz342;
lbits zghz343;
sail_int zghz344;
lbits zghz345;

void startup_zread_mem(void)
{
  CREATE(sail_int)(&zghz338);
  CREATE(sail_int)(&zghz339);
  CREATE(lbits)(&zghz340);
  CREATE(lbits)(&zghz341);
  CREATE(lbits)(&zghz342);
  CREATE(lbits)(&zghz343);
  CREATE(sail_int)(&zghz344);
  CREATE(lbits)(&zghz345);
}

uint64_t zread_mem(uint64_t zaddr)
{
  __label__ end_function_77, end_block_exception_78;

  uint64_t zcbz39;
  uint64_t zgaz367;
  {
    RECREATE(lbits)(&zghz343);
    CONVERT_OF(lbits, fbits)(&zghz343, UINT64_C(0x0), UINT64_C(4) , true);
    RECREATE(sail_int)(&zghz344);
    CONVERT_OF(sail_int, mach_int)(&zghz344, INT64_C(32));
    RECREATE(lbits)(&zghz345);
    zero_extend(&zghz345, zghz343, zghz344);
    zgaz367 = CONVERT_OF(fbits, lbits)(zghz345, true);
  }
  {
    RECREATE(sail_int)(&zghz338);
    CONVERT_OF(sail_int, mach_int)(&zghz338, INT64_C(32));
    RECREATE(sail_int)(&zghz339);
    CONVERT_OF(sail_int, mach_int)(&zghz339, INT64_C(4));
    RECREATE(lbits)(&zghz340);
    CONVERT_OF(lbits, fbits)(&zghz340, zgaz367, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz341);
    CONVERT_OF(lbits, fbits)(&zghz341, zaddr, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz342);
    read_ram(&zghz342, zghz338, zghz339, zghz340, zghz341);
    zcbz39 = CONVERT_OF(fbits, lbits)(zghz342, true);
  }

end_function_77: ;
  return zcbz39;
end_block_exception_78: ;

  return UINT64_C(0xdeadc0de);
}



void finish_zread_mem(void)
{
  KILL(lbits)(&zghz345);
  KILL(sail_int)(&zghz344);
  KILL(lbits)(&zghz343);
  KILL(lbits)(&zghz342);
  KILL(lbits)(&zghz341);
  KILL(lbits)(&zghz340);
  KILL(sail_int)(&zghz339);
  KILL(sail_int)(&zghz338);
}

unit zmain(unit);

sail_int zghz346;
lbits zghz347;
lbits zghz348;
lbits zghz349;
lbits zghz350;
lbits zghz351;
lbits zghz352;
lbits zghz353;
sail_int zghz354;
lbits zghz355;

void startup_zmain(void)
{
  CREATE(sail_int)(&zghz346);
  CREATE(lbits)(&zghz347);
  CREATE(lbits)(&zghz348);
  CREATE(lbits)(&zghz349);
  CREATE(lbits)(&zghz350);
  CREATE(lbits)(&zghz351);
  CREATE(lbits)(&zghz352);
  CREATE(lbits)(&zghz353);
  CREATE(sail_int)(&zghz354);
  CREATE(lbits)(&zghz355);
}












unit zmain(unit zgsz3117)
{
  __label__ while_80, wend_81, end_function_86, end_block_exception_87;

  unit zcbz310;
  {
    {
      RECREATE(lbits)(&zghz353);
      CONVERT_OF(lbits, fbits)(&zghz353, UINT64_C(0x1000), UINT64_C(16) , true);
      RECREATE(sail_int)(&zghz354);
      CONVERT_OF(sail_int, mach_int)(&zghz354, INT64_C(32));
      RECREATE(lbits)(&zghz355);
      zero_extend(&zghz355, zghz353, zghz354);
      zPC = CONVERT_OF(fbits, lbits)(zghz355, true);
    }
    unit zgsz3130;
    zgsz3130 = UNIT;
  }
  {
    unit zgsz3128;
    {
      RECREATE(lbits)(&zghz352);
      CONVERT_OF(lbits, fbits)(&zghz352, zPC, UINT64_C(32) , true);
      zgsz3128 = print_bits("PC = ", zghz352);
    }
  }
  {
    uint64_t zline;
    zline = zread_mem(zPC);
    unit zgsz3126;
    {
      RECREATE(lbits)(&zghz351);
      CONVERT_OF(lbits, fbits)(&zghz351, zline, UINT64_C(32) , true);
      zgsz3126 = print_bits("line = ", zghz351);
    }
  
  }
  {
    unit zgsz3125;
    zgsz3125 = zadd_4_bytes_to_PC(UNIT);
  }
  {
    unit zgsz3123;
    {
      RECREATE(lbits)(&zghz350);
      CONVERT_OF(lbits, fbits)(&zghz350, zPC, UINT64_C(32) , true);
      zgsz3123 = print_bits("PC = ", zghz350);
    }
  }
  {
    uint64_t zuz3121;
    zuz3121 = zread_mem(zPC);
    unit zgsz3121;
    {
      RECREATE(lbits)(&zghz349);
      CONVERT_OF(lbits, fbits)(&zghz349, zuz3121, UINT64_C(32) , true);
      zgsz3121 = print_bits("line = ", zghz349);
    }
  
  }
  bool zEOF;
  zEOF = false;
  bool zgsz3134;
  unit zgsz3135;
while_80: ;
  {
    zgsz3134 = zneq_bool(zEOF, true);
    if (!(zgsz3134)) goto wend_81;
    uint64_t zinstruction;
    {
      uint64_t zgaz370;
      zgaz370 = *(&zPC);
      zinstruction = zread_mem(zgaz370);
    
    }
    bool zgaz369;
    {
      uint64_t zgaz368;
      {
        RECREATE(sail_int)(&zghz346);
        CONVERT_OF(sail_int, mach_int)(&zghz346, INT64_C(32));
        RECREATE(lbits)(&zghz347);
        CONVERT_OF(lbits, fbits)(&zghz347, UINT64_C(0xF), UINT64_C(4) , true);
        RECREATE(lbits)(&zghz348);
        zextzz(&zghz348, zghz346, zghz347);
        zgaz368 = CONVERT_OF(fbits, lbits)(zghz348, true);
      }
      zgaz369 = (zinstruction == zgaz368);
    
    }
    if (zgaz369) {
    zEOF = true;
    zgsz3135 = UNIT;
    } else {
    struct zoption zdecoded_instruction;
    CREATE(zoption)(&zdecoded_instruction);
    zdecode(&zdecoded_instruction, zinstruction);
    {
      __label__ case_83, case_84, case_85, finish_match_82;

      unit zgsz3136;
      {
        if (zdecoded_instruction.kind != Kind_zSomez3z5unionz0zzast) goto case_83;
        struct zast zinst;
        CREATE(zast)(&zinst);
        COPY(zast)(&zinst, zdecoded_instruction.zSomez3z5unionz0zzast);
        zgsz3136 = zexecute(zinst);
        KILL(zast)(&zinst);
        goto finish_match_82;
      }
    case_83: ;
      {
        if (zdecoded_instruction.kind != Kind_zNone) goto case_84;
        zgsz3136 = print_endline("Instruction is None()");
        goto finish_match_82;
      }
    case_84: ;
      {
        zgsz3136 = print_endline("decoding the instruction resulted in something unexpected");
        goto finish_match_82;
      }
    case_85: ;
      sail_match_failure("main");
    finish_match_82: ;
      unit zgsz3140;
      zgsz3140 = zgsz3136;
    
    }
    zgsz3135 = zadd_4_bytes_to_PC(UNIT);
    KILL(zoption)(&zdecoded_instruction);
    }
  
  
    goto while_80;
  }
wend_81: ;
  zcbz310 = UNIT;

end_function_86: ;
  return zcbz310;
end_block_exception_87: ;

  return UNIT;
}



void finish_zmain(void)
{
  KILL(lbits)(&zghz355);
  KILL(sail_int)(&zghz354);
  KILL(lbits)(&zghz353);
  KILL(lbits)(&zghz352);
  KILL(lbits)(&zghz351);
  KILL(lbits)(&zghz350);
  KILL(lbits)(&zghz349);
  KILL(lbits)(&zghz348);
  KILL(lbits)(&zghz347);
  KILL(sail_int)(&zghz346);
}

unit zinitializze_registers(unit);

sail_int zghz356;
lbits zghz357;
sail_int zghz358;
lbits zghz359;
sail_int zghz360;
lbits zghz361;
sail_int zghz362;
lbits zghz363;
sail_int zghz364;
lbits zghz365;
sail_int zghz366;
lbits zghz367;
sail_int zghz368;
lbits zghz369;
sail_int zghz370;
lbits zghz371;
sail_int zghz372;
lbits zghz373;

void startup_zinitializze_registers(void)
{
  CREATE(sail_int)(&zghz356);
  CREATE(lbits)(&zghz357);
  CREATE(sail_int)(&zghz358);
  CREATE(lbits)(&zghz359);
  CREATE(sail_int)(&zghz360);
  CREATE(lbits)(&zghz361);
  CREATE(sail_int)(&zghz362);
  CREATE(lbits)(&zghz363);
  CREATE(sail_int)(&zghz364);
  CREATE(lbits)(&zghz365);
  CREATE(sail_int)(&zghz366);
  CREATE(lbits)(&zghz367);
  CREATE(sail_int)(&zghz368);
  CREATE(lbits)(&zghz369);
  CREATE(sail_int)(&zghz370);
  CREATE(lbits)(&zghz371);
  CREATE(sail_int)(&zghz372);
  CREATE(lbits)(&zghz373);
}

unit zinitializze_registers(unit zgsz3141)
{
  __label__ end_function_89, end_block_exception_90;

  unit zcbz311;
  {
    {
      RECREATE(sail_int)(&zghz372);
      CONVERT_OF(sail_int, mach_int)(&zghz372, INT64_C(32));
      RECREATE(lbits)(&zghz373);
      UNDEFINED(lbits)(&zghz373, zghz372);
      zzzero = CONVERT_OF(fbits, lbits)(zghz373, true);
    }
    unit zgsz3165;
    zgsz3165 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz370);
      CONVERT_OF(sail_int, mach_int)(&zghz370, INT64_C(32));
      RECREATE(lbits)(&zghz371);
      UNDEFINED(lbits)(&zghz371, zghz370);
      zra = CONVERT_OF(fbits, lbits)(zghz371, true);
    }
    unit zgsz3164;
    zgsz3164 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz368);
      CONVERT_OF(sail_int, mach_int)(&zghz368, INT64_C(32));
      RECREATE(lbits)(&zghz369);
      UNDEFINED(lbits)(&zghz369, zghz368);
      zsp = CONVERT_OF(fbits, lbits)(zghz369, true);
    }
    unit zgsz3163;
    zgsz3163 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz366);
      CONVERT_OF(sail_int, mach_int)(&zghz366, INT64_C(32));
      RECREATE(lbits)(&zghz367);
      UNDEFINED(lbits)(&zghz367, zghz366);
      zgp = CONVERT_OF(fbits, lbits)(zghz367, true);
    }
    unit zgsz3162;
    zgsz3162 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz364);
      CONVERT_OF(sail_int, mach_int)(&zghz364, INT64_C(32));
      RECREATE(lbits)(&zghz365);
      UNDEFINED(lbits)(&zghz365, zghz364);
      za0 = CONVERT_OF(fbits, lbits)(zghz365, true);
    }
    unit zgsz3161;
    zgsz3161 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz362);
      CONVERT_OF(sail_int, mach_int)(&zghz362, INT64_C(32));
      RECREATE(lbits)(&zghz363);
      UNDEFINED(lbits)(&zghz363, zghz362);
      za1 = CONVERT_OF(fbits, lbits)(zghz363, true);
    }
    unit zgsz3160;
    zgsz3160 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz360);
      CONVERT_OF(sail_int, mach_int)(&zghz360, INT64_C(32));
      RECREATE(lbits)(&zghz361);
      UNDEFINED(lbits)(&zghz361, zghz360);
      za2 = CONVERT_OF(fbits, lbits)(zghz361, true);
    }
    unit zgsz3159;
    zgsz3159 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz358);
      CONVERT_OF(sail_int, mach_int)(&zghz358, INT64_C(32));
      RECREATE(lbits)(&zghz359);
      UNDEFINED(lbits)(&zghz359, zghz358);
      za3 = CONVERT_OF(fbits, lbits)(zghz359, true);
    }
    unit zgsz3158;
    zgsz3158 = UNIT;
  }
  {
    RECREATE(sail_int)(&zghz356);
    CONVERT_OF(sail_int, mach_int)(&zghz356, INT64_C(32));
    RECREATE(lbits)(&zghz357);
    UNDEFINED(lbits)(&zghz357, zghz356);
    zPC = CONVERT_OF(fbits, lbits)(zghz357, true);
  }
  zcbz311 = UNIT;
end_function_89: ;
  return zcbz311;
end_block_exception_90: ;

  return UNIT;
}



void finish_zinitializze_registers(void)
{
  KILL(lbits)(&zghz373);
  KILL(sail_int)(&zghz372);
  KILL(lbits)(&zghz371);
  KILL(sail_int)(&zghz370);
  KILL(lbits)(&zghz369);
  KILL(sail_int)(&zghz368);
  KILL(lbits)(&zghz367);
  KILL(sail_int)(&zghz366);
  KILL(lbits)(&zghz365);
  KILL(sail_int)(&zghz364);
  KILL(lbits)(&zghz363);
  KILL(sail_int)(&zghz362);
  KILL(lbits)(&zghz361);
  KILL(sail_int)(&zghz360);
  KILL(lbits)(&zghz359);
  KILL(sail_int)(&zghz358);
  KILL(lbits)(&zghz357);
  KILL(sail_int)(&zghz356);
}

void model_init(void)
{
  setup_rts();
  startup_zsail_mask();
  startup_zsail_ones();
  startup_zfdiv_int();
  startup_zadd_bytes_to_PC();
  startup_zadd_4_bytes_to_PC();
  startup_zread_mem();
  startup_zmain();
  startup_zinitializze_registers();
  zinitializze_registers(UNIT);
  create_letbind_0();
}

void model_fini(void)
{
  kill_letbind_0();
  finish_zsail_mask();
  finish_zsail_ones();
  finish_zfdiv_int();
  finish_zadd_bytes_to_PC();
  finish_zadd_4_bytes_to_PC();
  finish_zread_mem();
  finish_zmain();
  finish_zinitializze_registers();
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
