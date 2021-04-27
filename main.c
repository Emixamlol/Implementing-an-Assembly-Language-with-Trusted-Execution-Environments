#include "sail.h"
#include "rts.h"
#include "elf.h"

// enum uop
enum zuop { zLUI, zAUIPC };

static bool eq_zuop(enum zuop op1, enum zuop op2) { return op1 == op2; }

static enum zuop UNDEFINED(zuop)(unit u) { return zLUI; }

// enum sop
enum zsop { zSW };

static bool eq_zsop(enum zsop op1, enum zsop op2) { return op1 == op2; }

static enum zsop UNDEFINED(zsop)(unit u) { return zSW; }

// enum rop
enum zrop { zADD, zAND, zOR, zXOR, zMUL, zDIV, zREM };

static bool eq_zrop(enum zrop op1, enum zrop op2) { return op1 == op2; }

static enum zrop UNDEFINED(zrop)(unit u) { return zADD; }

// enum jop
enum zjop { zJAL };

static bool eq_zjop(enum zjop op1, enum zjop op2) { return op1 == op2; }

static enum zjop UNDEFINED(zjop)(unit u) { return zJAL; }

// enum iop
enum ziop { zADDI, zSLTI, zANDI, zORI, zXORI, zJALR, zLW, zSLLI, zLB, zLH };

static bool eq_ziop(enum ziop op1, enum ziop op2) { return op1 == op2; }

static enum ziop UNDEFINED(ziop)(unit u) { return zADDI; }

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
enum kind_zast { Kind_zBTYPE, Kind_zEBREAK, Kind_zITYPE, Kind_zJTYPE, Kind_zRTYPE, Kind_zSTYPE, Kind_zUTYPE };

struct zast {
  enum kind_zast kind;
  union {
    struct { struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 zBTYPE; };
    struct { unit zEBREAK; };
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
  } else if (op->kind == Kind_zEBREAK) {
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
  } else if (rop->kind == Kind_zEBREAK) {
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
  } else if (op.kind == Kind_zEBREAK) {
    rop->zEBREAK = op.zEBREAK;
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
  } else if (op1.kind == Kind_zEBREAK && op2.kind == Kind_zEBREAK) {
    return EQUAL(unit)(op1.zEBREAK, op2.zEBREAK);
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
  } else if (rop->kind == Kind_zEBREAK) {
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

static void zEBREAK(struct zast *rop, unit op)
{
  if (rop->kind == Kind_zBTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zEBREAK) {
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
  rop->kind = Kind_zEBREAK;
  rop->zEBREAK = op;
}

static void zITYPE(struct zast *rop, struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 op)
{
  if (rop->kind == Kind_zBTYPE) {
    /* do nothing */
  } else if (rop->kind == Kind_zEBREAK) {
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
  } else if (rop->kind == Kind_zEBREAK) {
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
  } else if (rop->kind == Kind_zEBREAK) {
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
  } else if (rop->kind == Kind_zEBREAK) {
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
  } else if (rop->kind == Kind_zEBREAK) {
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





























bool zneq_bits(lbits zx, lbits zy)
{
  __label__ end_function_1, end_block_exception_2;

  bool zcbz30;
  bool zgaz30;
  zgaz30 = eq_bits(zx, zy);
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
  __label__ end_function_4, end_block_exception_5, end_function_228;

  bool zgaz32;
  {
    RECREATE(sail_int)(&zghz30);
    length_lbits(&zghz30, zv);
    zgaz32 = lteq(zlen, zghz30);
  }
  if (zgaz32) {  sail_truncate((*(&zcbz31)), zv, zlen);  } else {  zero_extend((*(&zcbz31)), zv, zlen);  }

end_function_4: ;
  goto end_function_228;
end_block_exception_5: ;
  goto end_function_228;
end_function_228: ;
}



void finish_zsail_mask(void)
{    KILL(sail_int)(&zghz30);
}







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























void zsail_ones(lbits *rop, sail_int);

lbits zghz31;

void startup_zsail_ones(void)
{    CREATE(lbits)(&zghz31);
}

void zsail_ones(lbits *zcbz32, sail_int zn)
{
  __label__ end_function_7, end_block_exception_8, end_function_227;

  RECREATE(lbits)(&zghz31);
  zeros(&zghz31, zn);
  not_bits((*(&zcbz32)), zghz31);
end_function_7: ;
  goto end_function_227;
end_block_exception_8: ;
  goto end_function_227;
end_function_227: ;
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
  __label__ end_function_10, end_block_exception_11, end_function_226;

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
  goto end_function_226;
end_block_exception_11: ;
  goto end_function_226;
end_function_226: ;
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



void zextzz(lbits *rop, sail_int, lbits);

void zextzz(lbits *zcbz34, sail_int zm, lbits zxs)
{
  __label__ end_function_13, end_block_exception_14, end_function_225;

  zero_extend((*(&zcbz34)), zxs, zm);
end_function_13: ;
  goto end_function_225;
end_block_exception_14: ;
  goto end_function_225;
end_function_225: ;
}













bool zgt_bit(lbits, lbits);

sail_int zghz314;
sail_int zghz315;

void startup_zgt_bit(void)
{
  CREATE(sail_int)(&zghz314);
  CREATE(sail_int)(&zghz315);
}

bool zgt_bit(lbits zx, lbits zy)
{
  __label__ end_function_16, end_block_exception_17;

  bool zcbz35;
  RECREATE(sail_int)(&zghz314);
  sail_unsigned(&zghz314, zx);
  RECREATE(sail_int)(&zghz315);
  sail_unsigned(&zghz315, zy);
  zcbz35 = gt(zghz314, zghz315);
end_function_16: ;
  return zcbz35;
end_block_exception_17: ;

  return false;
}



void finish_zgt_bit(void)
{
  KILL(sail_int)(&zghz315);
  KILL(sail_int)(&zghz314);
}

bool zlt_bit(lbits, lbits);

sail_int zghz316;
sail_int zghz317;

void startup_zlt_bit(void)
{
  CREATE(sail_int)(&zghz316);
  CREATE(sail_int)(&zghz317);
}

bool zlt_bit(lbits zx, lbits zy)
{
  __label__ end_function_19, end_block_exception_20;

  bool zcbz36;
  RECREATE(sail_int)(&zghz316);
  sail_unsigned(&zghz316, zx);
  RECREATE(sail_int)(&zghz317);
  sail_unsigned(&zghz317, zy);
  zcbz36 = lt(zghz316, zghz317);
end_function_19: ;
  return zcbz36;
end_block_exception_20: ;

  return false;
}



void finish_zlt_bit(void)
{
  KILL(sail_int)(&zghz317);
  KILL(sail_int)(&zghz316);
}

bool zlte_bit(lbits, lbits);

sail_int zghz318;
sail_int zghz319;

void startup_zlte_bit(void)
{
  CREATE(sail_int)(&zghz318);
  CREATE(sail_int)(&zghz319);
}

bool zlte_bit(lbits zx, lbits zy)
{
  __label__ end_function_22, end_block_exception_23;

  bool zcbz37;
  RECREATE(sail_int)(&zghz318);
  sail_unsigned(&zghz318, zx);
  RECREATE(sail_int)(&zghz319);
  sail_unsigned(&zghz319, zy);
  zcbz37 = lteq(zghz318, zghz319);
end_function_22: ;
  return zcbz37;
end_block_exception_23: ;

  return false;
}



void finish_zlte_bit(void)
{
  KILL(sail_int)(&zghz319);
  KILL(sail_int)(&zghz318);
}

fbits zxor_bit(fbits, fbits);

fbits zxor_bit(fbits zb1, fbits zb2)
{
  __label__ end_function_25, end_block_exception_26;

  fbits zcbz38;
  bool zgaz318;
  zgaz318 = (zb1 == zb2);
  if (zgaz318) {  zcbz38 = UINT64_C(0);  } else {  zcbz38 = UINT64_C(1);  }

end_function_25: ;
  return zcbz38;
end_block_exception_26: ;

  return UINT64_C(0);
}

void zxor_bitvector(lbits *rop, lbits, lbits);

sail_int zghz320;
lbits zghz321;
sail_int zghz322;
sail_int zghz323;
sail_int zghz324;
sail_int zghz325;
sail_int zghz326;

void startup_zxor_bitvector(void)
{
  CREATE(sail_int)(&zghz320);
  CREATE(lbits)(&zghz321);
  CREATE(sail_int)(&zghz322);
  CREATE(sail_int)(&zghz323);
  CREATE(sail_int)(&zghz324);
  CREATE(sail_int)(&zghz325);
  CREATE(sail_int)(&zghz326);
}

void zxor_bitvector(lbits *zcbz39, lbits zv1, lbits zv2)
{
  __label__ end_function_30, end_block_exception_31, end_function_224;

  RECREATE(sail_int)(&zghz320);
  length_lbits(&zghz320, zv2);
  RECREATE(lbits)(&zghz321);
  zeros(&zghz321, zghz320);
  {
    int64_t zgsz310;
    {    zgsz310 = INT64_C(0);
    }
    int64_t zgsz311;
    {
      {
        RECREATE(sail_int)(&zghz325);
        CONVERT_OF(sail_int, mach_int)(&zghz325, INT64_C(1));
        RECREATE(sail_int)(&zghz326);
        sub_int(&zghz326, zghz320, zghz325);
        zgsz311 = CONVERT_OF(mach_int, sail_int)(zghz326);
      }
    }
    int64_t zgsz312;
    {    zgsz312 = INT64_C(1);
    }
    {
      __label__ for_start_28, for_end_29;

      int64_t zi;
      zi = zgsz310;
      unit zgsz316;
    for_start_28: ;
      {
        if ((zi > zgsz311)) goto for_end_29;
        fbits zb1;
        {
          RECREATE(sail_int)(&zghz324);
          CONVERT_OF(sail_int, mach_int)(&zghz324, zi);
          zb1 = bitvector_access(zv1, zghz324);
        }
        fbits zb2;
        {
          RECREATE(sail_int)(&zghz323);
          CONVERT_OF(sail_int, mach_int)(&zghz323, zi);
          zb2 = bitvector_access(zv2, zghz323);
        }
        fbits zgaz319;
        zgaz319 = zxor_bit(zb1, zb2);
        {
          RECREATE(sail_int)(&zghz322);
          CONVERT_OF(sail_int, mach_int)(&zghz322, zi);
          update_lbits(&zghz321, zghz321, zghz322, zgaz319);
        }
        zgsz316 = UNIT;
      
      
      
        zi = (zi + zgsz312);
        goto for_start_28;
      }
    for_end_29: ;
    }
    unit zgsz319;
    zgsz319 = UNIT;
  }
  COPY(lbits)((*(&zcbz39)), zghz321);
end_function_30: ;
  goto end_function_224;
end_block_exception_31: ;
  goto end_function_224;
end_function_224: ;
}



void finish_zxor_bitvector(void)
{
  KILL(sail_int)(&zghz326);
  KILL(sail_int)(&zghz325);
  KILL(sail_int)(&zghz324);
  KILL(sail_int)(&zghz323);
  KILL(sail_int)(&zghz322);
  KILL(lbits)(&zghz321);
  KILL(sail_int)(&zghz320);
}

bool zxor_bool(bool, bool);

bool zxor_bool(bool zb1, bool zb2)
{
  __label__ end_function_33, end_block_exception_34;

  bool zcbz310;
  bool zgaz320;
  zgaz320 = eq_bool(zb1, zb2);
  if (zgaz320) {  zcbz310 = false;  } else {  zcbz310 = true;  }

end_function_33: ;
  return zcbz310;
end_block_exception_34: ;

  return false;
}

void ztwos_complement(lbits *rop, lbits);

lbits zghz327;
lbits zghz328;
sail_int zghz329;
lbits zghz330;

void startup_ztwos_complement(void)
{
  CREATE(lbits)(&zghz327);
  CREATE(lbits)(&zghz328);
  CREATE(sail_int)(&zghz329);
  CREATE(lbits)(&zghz330);
}

void ztwos_complement(lbits *zcbz311, lbits zv)
{
  __label__ end_function_36, end_block_exception_37, end_function_223;

  RECREATE(lbits)(&zghz327);
  not_bits(&zghz327, zv);
  {
    RECREATE(lbits)(&zghz328);
    {
      RECREATE(sail_int)(&zghz329);
      length_lbits(&zghz329, zv);
      {
        RECREATE(lbits)(&zghz330);
        CONVERT_OF(lbits, fbits)(&zghz330, UINT64_C(0b1), UINT64_C(1) , true);
        zextzz(&zghz328, zghz329, zghz330);
      }
    }
    add_bits(&zghz327, zghz327, zghz328);
    unit zgsz321;
    zgsz321 = UNIT;
  }
  COPY(lbits)((*(&zcbz311)), zghz327);
end_function_36: ;
  goto end_function_223;
end_block_exception_37: ;
  goto end_function_223;
end_function_223: ;
}



void finish_ztwos_complement(void)
{
  KILL(lbits)(&zghz330);
  KILL(sail_int)(&zghz329);
  KILL(lbits)(&zghz328);
  KILL(lbits)(&zghz327);
}

void zabs(lbits *rop, lbits);

sail_int zghz331;
lbits zghz332;
sail_int zghz333;
sail_int zghz334;

void startup_zabs(void)
{
  CREATE(sail_int)(&zghz331);
  CREATE(lbits)(&zghz332);
  CREATE(sail_int)(&zghz333);
  CREATE(sail_int)(&zghz334);
}

void zabs(lbits *zcbz312, lbits zv)
{
  __label__ case_40, case_41, finish_match_39, end_function_42, end_block_exception_43, end_function_222;

  RECREATE(sail_int)(&zghz331);
  {
    RECREATE(sail_int)(&zghz333);
    length_lbits(&zghz333, zv);
    {
      RECREATE(sail_int)(&zghz334);
      CONVERT_OF(sail_int, mach_int)(&zghz334, INT64_C(1));
      sub_int(&zghz331, zghz333, zghz334);
    }
  }
  fbits zgaz323;
  zgaz323 = bitvector_access(zv, zghz331);
  RECREATE(lbits)(&zghz332);
  {
    fbits zp0z3;
    zp0z3 = zgaz323;
    bool zgsz324;
    zgsz324 = eq_bit(zp0z3, UINT64_C(0));
    if (!(zgsz324)) {
  
    goto case_40;
    }
    COPY(lbits)(&zghz332, zv);
  
    goto finish_match_39;
  }
case_40: ;
  {
    fbits zuz30;
    zuz30 = zgaz323;
    bool zgsz325;
    zgsz325 = eq_bit(zuz30, UINT64_C(1));
    if (!(zgsz325)) {
  
    goto case_41;
    }
    ztwos_complement(&zghz332, zv);
  
    goto finish_match_39;
  }
case_41: ;
  sail_match_failure("abs");
finish_match_39: ;
  COPY(lbits)((*(&zcbz312)), zghz332);

end_function_42: ;
  goto end_function_222;
end_block_exception_43: ;
  goto end_function_222;
end_function_222: ;
}



void finish_zabs(void)
{
  KILL(sail_int)(&zghz334);
  KILL(sail_int)(&zghz333);
  KILL(lbits)(&zghz332);
  KILL(sail_int)(&zghz331);
}

void zmul_bitvector(lbits *rop, lbits, lbits);

sail_int zghz335;
lbits zghz336;
lbits zghz337;
lbits zghz338;
sail_int zghz339;
sail_int zghz340;
lbits zghz341;
sail_int zghz342;
sail_int zghz343;
sail_int zghz344;
lbits zghz345;
lbits zghz346;
sail_int zghz347;
sail_int zghz348;
sail_int zghz349;
sail_int zghz350;
sail_int zghz351;
sail_int zghz352;
sail_int zghz353;
sail_int zghz354;
sail_int zghz355;
sail_int zghz356;
sail_int zghz357;
sail_int zghz358;

void startup_zmul_bitvector(void)
{
  CREATE(sail_int)(&zghz335);
  CREATE(lbits)(&zghz336);
  CREATE(lbits)(&zghz337);
  CREATE(lbits)(&zghz338);
  CREATE(sail_int)(&zghz339);
  CREATE(sail_int)(&zghz340);
  CREATE(lbits)(&zghz341);
  CREATE(sail_int)(&zghz342);
  CREATE(sail_int)(&zghz343);
  CREATE(sail_int)(&zghz344);
  CREATE(lbits)(&zghz345);
  CREATE(lbits)(&zghz346);
  CREATE(sail_int)(&zghz347);
  CREATE(sail_int)(&zghz348);
  CREATE(sail_int)(&zghz349);
  CREATE(sail_int)(&zghz350);
  CREATE(sail_int)(&zghz351);
  CREATE(sail_int)(&zghz352);
  CREATE(sail_int)(&zghz353);
  CREATE(sail_int)(&zghz354);
  CREATE(sail_int)(&zghz355);
  CREATE(sail_int)(&zghz356);
  CREATE(sail_int)(&zghz357);
  CREATE(sail_int)(&zghz358);
}

void zmul_bitvector(lbits *zcbz313, lbits zmultiplicand, lbits zmultiplier)
{
  __label__ end_function_50, end_block_exception_51, end_function_221;

  {
    RECREATE(sail_int)(&zghz358);
    sail_signed(&zghz358, zmultiplicand);
    unit zgsz327;
    zgsz327 = print_int("multiplicand = ", zghz358);
  }
  {
    RECREATE(sail_int)(&zghz357);
    sail_signed(&zghz357, zmultiplier);
    unit zgsz326;
    zgsz326 = print_int("mutliplier = ", zghz357);
  }
  RECREATE(sail_int)(&zghz335);
  length_lbits(&zghz335, zmultiplier);
  RECREATE(lbits)(&zghz336);
  {
    RECREATE(sail_int)(&zghz355);
    {
      RECREATE(sail_int)(&zghz356);
      CONVERT_OF(sail_int, mach_int)(&zghz356, INT64_C(2));
      mult_int(&zghz355, zghz356, zghz335);
    }
    sign_extend(&zghz336, zmultiplicand, zghz355);
  }
  RECREATE(lbits)(&zghz337);
  {
    RECREATE(sail_int)(&zghz353);
    {
      RECREATE(sail_int)(&zghz354);
      CONVERT_OF(sail_int, mach_int)(&zghz354, INT64_C(2));
      mult_int(&zghz353, zghz354, zghz335);
    }
    sign_extend(&zghz337, zmultiplier, zghz353);
  }
  RECREATE(lbits)(&zghz338);
  {
    RECREATE(sail_int)(&zghz351);
    {
      RECREATE(sail_int)(&zghz352);
      CONVERT_OF(sail_int, mach_int)(&zghz352, INT64_C(2));
      mult_int(&zghz351, zghz352, zghz335);
    }
    zeros(&zghz338, zghz351);
  }
  {
    RECREATE(sail_int)(&zghz340);
    {
      RECREATE(sail_int)(&zghz350);
      CONVERT_OF(sail_int, mach_int)(&zghz350, INT64_C(1));
      sub_int(&zghz340, zghz335, zghz350);
    }
    int64_t zgsz332;
    {    zgsz332 = INT64_C(0);
    }
    int64_t zgsz333;
    {    zgsz333 = CONVERT_OF(mach_int, sail_int)(zghz340);
    }
    int64_t zgsz334;
    {    zgsz334 = INT64_C(1);
    }
    {
      __label__ for_start_45, for_end_46;

      int64_t zi;
      zi = zgsz332;
      unit zgsz336;
    for_start_45: ;
      {
        if ((zi > zgsz333)) goto for_end_46;
        bool zgaz328;
        {
          fbits zgaz327;
          {
            RECREATE(sail_int)(&zghz349);
            CONVERT_OF(sail_int, mach_int)(&zghz349, zi);
            zgaz327 = bitvector_access(zghz337, zghz349);
          }
          zgaz328 = eq_bit(zgaz327, UINT64_C(1));
        
        }
        if (zgaz328) {
        __label__ case_48, case_49, finish_match_47;

        unit zgsz337;
        {
          RECREATE(sail_int)(&zghz343);
          CONVERT_OF(sail_int, mach_int)(&zghz343, zi);
          RECREATE(sail_int)(&zghz344);
          {
            RECREATE(sail_int)(&zghz348);
            CONVERT_OF(sail_int, mach_int)(&zghz348, INT64_C(1));
            sub_int(&zghz344, zghz335, zghz348);
          }
          bool zgsz340;
          zgsz340 = eq_int(zghz343, zghz344);
          if (!(zgsz340))
            goto case_48;
          RECREATE(lbits)(&zghz345);
          {
            RECREATE(lbits)(&zghz346);
            {
              RECREATE(sail_int)(&zghz347);
              CONVERT_OF(sail_int, mach_int)(&zghz347, zi);
              shiftl(&zghz346, zghz336, zghz347);
            }
            ztwos_complement(&zghz345, zghz346);
          }
          add_bits(&zghz338, zghz338, zghz345);
          zgsz337 = UNIT;
          goto finish_match_47;
        }
      case_48: ;
        {
          RECREATE(lbits)(&zghz341);
          {
            RECREATE(sail_int)(&zghz342);
            CONVERT_OF(sail_int, mach_int)(&zghz342, zi);
            shiftl(&zghz341, zghz336, zghz342);
          }
          add_bits(&zghz338, zghz338, zghz341);
          zgsz337 = UNIT;
          goto finish_match_47;
        }
      case_49: ;
        sail_match_failure("mul_bitvector");
      finish_match_47: ;
        zgsz336 = zgsz337;
      
        } else {  zgsz336 = UNIT;  }
      
        zi = (zi + zgsz334);
        goto for_start_45;
      }
    for_end_46: ;
    }
    unit zgsz344;
    zgsz344 = UNIT;
  }
  {
    RECREATE(sail_int)(&zghz339);
    sail_signed(&zghz339, zghz338);
    unit zgsz343;
    zgsz343 = print_int("result = ", zghz339);
  }
  COPY(lbits)((*(&zcbz313)), zghz338);
end_function_50: ;
  goto end_function_221;
end_block_exception_51: ;
  goto end_function_221;
end_function_221: ;
}



void finish_zmul_bitvector(void)
{
  KILL(sail_int)(&zghz358);
  KILL(sail_int)(&zghz357);
  KILL(sail_int)(&zghz356);
  KILL(sail_int)(&zghz355);
  KILL(sail_int)(&zghz354);
  KILL(sail_int)(&zghz353);
  KILL(sail_int)(&zghz352);
  KILL(sail_int)(&zghz351);
  KILL(sail_int)(&zghz350);
  KILL(sail_int)(&zghz349);
  KILL(sail_int)(&zghz348);
  KILL(sail_int)(&zghz347);
  KILL(lbits)(&zghz346);
  KILL(lbits)(&zghz345);
  KILL(sail_int)(&zghz344);
  KILL(sail_int)(&zghz343);
  KILL(sail_int)(&zghz342);
  KILL(lbits)(&zghz341);
  KILL(sail_int)(&zghz340);
  KILL(sail_int)(&zghz339);
  KILL(lbits)(&zghz338);
  KILL(lbits)(&zghz337);
  KILL(lbits)(&zghz336);
  KILL(sail_int)(&zghz335);
}

// struct tuple_(%bv, %bv)
struct ztuple_z8z5bvzCz0z5bvz9 {
  lbits ztup0;
  lbits ztup1;
};

static void COPY(ztuple_z8z5bvzCz0z5bvz9)(struct ztuple_z8z5bvzCz0z5bvz9 *rop, const struct ztuple_z8z5bvzCz0z5bvz9 op) {
  COPY(lbits)(&rop->ztup0, op.ztup0);
  COPY(lbits)(&rop->ztup1, op.ztup1);
}

static void CREATE(ztuple_z8z5bvzCz0z5bvz9)(struct ztuple_z8z5bvzCz0z5bvz9 *op) {
  CREATE(lbits)(&op->ztup0);
  CREATE(lbits)(&op->ztup1);
}

static void RECREATE(ztuple_z8z5bvzCz0z5bvz9)(struct ztuple_z8z5bvzCz0z5bvz9 *op) {
  RECREATE(lbits)(&op->ztup0);
  RECREATE(lbits)(&op->ztup1);
}

static void KILL(ztuple_z8z5bvzCz0z5bvz9)(struct ztuple_z8z5bvzCz0z5bvz9 *op) {
  KILL(lbits)(&op->ztup0);
  KILL(lbits)(&op->ztup1);
}

static bool EQUAL(ztuple_z8z5bvzCz0z5bvz9)(struct ztuple_z8z5bvzCz0z5bvz9 op1, struct ztuple_z8z5bvzCz0z5bvz9 op2) {
  return EQUAL(lbits)(op1.ztup0, op2.ztup0) && EQUAL(lbits)(op1.ztup1, op2.ztup1);
}

void zdiv_bitvector(struct ztuple_z8z5bvzCz0z5bvz9 *rop, lbits, lbits);

sail_int zghz359;
lbits zghz360;
lbits zghz361;
lbits zghz362;
lbits zghz363;
sail_int zghz364;
sail_int zghz365;
sail_int zghz366;
sail_int zghz367;
sail_int zghz368;
sail_int zghz369;
sail_int zghz370;
lbits zghz371;
lbits zghz372;
sail_int zghz373;
sail_int zghz374;
sail_int zghz375;
sail_int zghz376;
sail_int zghz377;
lbits zghz378;
sail_int zghz379;
sail_int zghz380;
lbits zghz381;
sail_int zghz382;
sail_int zghz383;
sail_int zghz384;
sail_int zghz385;

void startup_zdiv_bitvector(void)
{
  CREATE(sail_int)(&zghz359);
  CREATE(lbits)(&zghz360);
  CREATE(lbits)(&zghz361);
  CREATE(lbits)(&zghz362);
  CREATE(lbits)(&zghz363);
  CREATE(sail_int)(&zghz364);
  CREATE(sail_int)(&zghz365);
  CREATE(sail_int)(&zghz366);
  CREATE(sail_int)(&zghz367);
  CREATE(sail_int)(&zghz368);
  CREATE(sail_int)(&zghz369);
  CREATE(sail_int)(&zghz370);
  CREATE(lbits)(&zghz371);
  CREATE(lbits)(&zghz372);
  CREATE(sail_int)(&zghz373);
  CREATE(sail_int)(&zghz374);
  CREATE(sail_int)(&zghz375);
  CREATE(sail_int)(&zghz376);
  CREATE(sail_int)(&zghz377);
  CREATE(lbits)(&zghz378);
  CREATE(sail_int)(&zghz379);
  CREATE(sail_int)(&zghz380);
  CREATE(lbits)(&zghz381);
  CREATE(sail_int)(&zghz382);
  CREATE(sail_int)(&zghz383);
  CREATE(sail_int)(&zghz384);
  CREATE(sail_int)(&zghz385);
}

void zdiv_bitvector(struct ztuple_z8z5bvzCz0z5bvz9 *zcbz314, lbits zdividend, lbits zdivisor)
{
  __label__ end_function_55, end_block_exception_56, end_function_220;

  {
    RECREATE(sail_int)(&zghz385);
    sail_signed(&zghz385, zdividend);
    unit zgsz346;
    zgsz346 = print_int("dividend = ", zghz385);
  }
  {
    RECREATE(sail_int)(&zghz384);
    sail_signed(&zghz384, zdivisor);
    unit zgsz345;
    zgsz345 = print_int("divisor = ", zghz384);
  }
  RECREATE(sail_int)(&zghz359);
  length_lbits(&zghz359, zdivisor);
  RECREATE(lbits)(&zghz360);
  {
    RECREATE(lbits)(&zghz381);
    {
      RECREATE(sail_int)(&zghz382);
      {
        RECREATE(sail_int)(&zghz383);
        CONVERT_OF(sail_int, mach_int)(&zghz383, INT64_C(2));
        mult_int(&zghz382, zghz383, zghz359);
      }
      sign_extend(&zghz381, zdivisor, zghz382);
    }
    zabs(&zghz360, zghz381);
  }
  RECREATE(lbits)(&zghz361);
  {
    RECREATE(lbits)(&zghz378);
    {
      RECREATE(sail_int)(&zghz379);
      {
        RECREATE(sail_int)(&zghz380);
        CONVERT_OF(sail_int, mach_int)(&zghz380, INT64_C(2));
        mult_int(&zghz379, zghz380, zghz359);
      }
      sign_extend(&zghz378, zdividend, zghz379);
    }
    zabs(&zghz361, zghz378);
  }
  RECREATE(lbits)(&zghz362);
  {
    RECREATE(sail_int)(&zghz376);
    {
      RECREATE(sail_int)(&zghz377);
      CONVERT_OF(sail_int, mach_int)(&zghz377, INT64_C(2));
      mult_int(&zghz376, zghz377, zghz359);
    }
    zeros(&zghz362, zghz376);
  }
  RECREATE(lbits)(&zghz363);
  {
    RECREATE(sail_int)(&zghz374);
    {
      RECREATE(sail_int)(&zghz375);
      CONVERT_OF(sail_int, mach_int)(&zghz375, INT64_C(2));
      mult_int(&zghz374, zghz375, zghz359);
    }
    zeros(&zghz363, zghz374);
  }
  {
    int64_t zgsz351;
    {    zgsz351 = INT64_C(0);
    }
    int64_t zgsz352;
    {    zgsz352 = CONVERT_OF(mach_int, sail_int)(zghz359);
    }
    int64_t zgsz353;
    {    zgsz353 = INT64_C(1);
    }
    {
      __label__ for_start_53, for_end_54;

      int64_t zi;
      zi = zgsz351;
      unit zgsz358;
    for_start_53: ;
      {
        if ((zi > zgsz352)) goto for_end_54;
        RECREATE(sail_int)(&zghz368);
        {
          RECREATE(sail_int)(&zghz373);
          CONVERT_OF(sail_int, mach_int)(&zghz373, zi);
          sub_int(&zghz368, zghz359, zghz373);
        }
        {
          bool zgaz340;
          {
            RECREATE(lbits)(&zghz372);
            shiftl(&zghz372, zghz360, zghz368);
            zgaz340 = zgt_bit(zghz361, zghz372);
          }
          unit zgsz355;
          if (zgaz340) {
          {
            RECREATE(lbits)(&zghz371);
            shiftl(&zghz371, zghz360, zghz368);
            sub_bits(&zghz361, zghz361, zghz371);
            unit zgsz356;
            zgsz356 = UNIT;
          }
          update_lbits(&zghz362, zghz362, zghz368, UINT64_C(1));
          zgsz355 = UNIT;
          } else {  zgsz355 = UNIT;  }
        
        }
        bool zgaz342;
        {
          RECREATE(sail_int)(&zghz370);
          CONVERT_OF(sail_int, mach_int)(&zghz370, INT64_C(0));
          zgaz342 = eq_int(zghz368, zghz370);
        }
        if (zgaz342) {
        {
          RECREATE(sail_int)(&zghz369);
          CONVERT_OF(sail_int, mach_int)(&zghz369, INT64_C(1));
          replicate_bits(&zghz363, zghz361, zghz369);
        }
        zgsz358 = UNIT;
        } else {  zgsz358 = UNIT;  }
      
        zi = (zi + zgsz353);
        goto for_start_53;
      }
    for_end_54: ;
    }
    unit zgsz365;
    zgsz365 = UNIT;
  }
  {
    RECREATE(sail_int)(&zghz366);
    {
      RECREATE(sail_int)(&zghz367);
      CONVERT_OF(sail_int, mach_int)(&zghz367, INT64_C(1));
      sub_int(&zghz366, zghz359, zghz367);
    }
    bool zgaz347;
    {
      bool zgaz345;
      {
        fbits zgaz343;
        zgaz343 = bitvector_access(zdividend, zghz366);
        zgaz345 = eq_bit(zgaz343, UINT64_C(1));
      
      }
      bool zgaz346;
      {
        fbits zgaz344;
        zgaz344 = bitvector_access(zdivisor, zghz366);
        zgaz346 = eq_bit(zgaz344, UINT64_C(1));
      
      }
      zgaz347 = zxor_bool(zgaz345, zgaz346);
    
    
    }
    unit zgsz363;
    if (zgaz347) {
    {
      ztwos_complement(&zghz362, zghz362);
      unit zgsz364;
      zgsz364 = UNIT;
    }
    ztwos_complement(&zghz363, zghz363);
    zgsz363 = UNIT;
    } else {  zgsz363 = UNIT;  }
  
  }
  {
    RECREATE(sail_int)(&zghz365);
    sail_signed(&zghz365, zghz362);
    unit zgsz362;
    zgsz362 = print_int("quotient = ", zghz365);
  }
  {
    RECREATE(sail_int)(&zghz364);
    sail_signed(&zghz364, zghz363);
    unit zgsz361;
    zgsz361 = print_int("remainder = ", zghz364);
  }
  struct ztuple_z8z5bvzCz0z5bvz9 zgsz366;
  CREATE(ztuple_z8z5bvzCz0z5bvz9)(&zgsz366);
  COPY(lbits)(&((&zgsz366)->ztup0), zghz362);
  COPY(lbits)(&((&zgsz366)->ztup1), zghz363);
  COPY(ztuple_z8z5bvzCz0z5bvz9)((*(&zcbz314)), zgsz366);
  KILL(ztuple_z8z5bvzCz0z5bvz9)(&zgsz366);
end_function_55: ;
  goto end_function_220;
end_block_exception_56: ;
  goto end_function_220;
end_function_220: ;
}



void finish_zdiv_bitvector(void)
{
  KILL(sail_int)(&zghz385);
  KILL(sail_int)(&zghz384);
  KILL(sail_int)(&zghz383);
  KILL(sail_int)(&zghz382);
  KILL(lbits)(&zghz381);
  KILL(sail_int)(&zghz380);
  KILL(sail_int)(&zghz379);
  KILL(lbits)(&zghz378);
  KILL(sail_int)(&zghz377);
  KILL(sail_int)(&zghz376);
  KILL(sail_int)(&zghz375);
  KILL(sail_int)(&zghz374);
  KILL(sail_int)(&zghz373);
  KILL(lbits)(&zghz372);
  KILL(lbits)(&zghz371);
  KILL(sail_int)(&zghz370);
  KILL(sail_int)(&zghz369);
  KILL(sail_int)(&zghz368);
  KILL(sail_int)(&zghz367);
  KILL(sail_int)(&zghz366);
  KILL(sail_int)(&zghz365);
  KILL(sail_int)(&zghz364);
  KILL(lbits)(&zghz363);
  KILL(lbits)(&zghz362);
  KILL(lbits)(&zghz361);
  KILL(lbits)(&zghz360);
  KILL(sail_int)(&zghz359);
}

// register PC
uint64_t zPC;

// register start_boundary
uint64_t zstart_boundary;

// register end_boundary
uint64_t zend_boundary;

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

zz5vecz8z6z8z5bv32z9z9 zXs;
static void create_letbind_0(void) {    CREATE(zz5vecz8z6z8z5bv32z9z9)(&zXs);


  zz5vecz8z6z8z5bv32z9z9 zgsz368;
  CREATE(zz5vecz8z6z8z5bv32z9z9)(&zgsz368);
  zz5vecz8z6z8z5bv32z9z9 zgsz367;
  CREATE(zz5vecz8z6z8z5bv32z9z9)(&zgsz367);
  internal_vector_init_zz5vecz8z6z8z5bv32z9z9(&zgsz367, INT64_C(8));
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz367, zgsz367, INT64_C(0), &zzzero);
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz367, zgsz367, INT64_C(1), &zra);
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz367, zgsz367, INT64_C(2), &zsp);
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz367, zgsz367, INT64_C(3), &zgp);
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz367, zgsz367, INT64_C(4), &za0);
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz367, zgsz367, INT64_C(5), &za1);
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz367, zgsz367, INT64_C(6), &za2);
  internal_vector_update_zz5vecz8z6z8z5bv32z9z9(&zgsz367, zgsz367, INT64_C(7), &za3);
  COPY(zz5vecz8z6z8z5bv32z9z9)(&zgsz368, zgsz367);
  KILL(zz5vecz8z6z8z5bv32z9z9)(&zgsz367);
  COPY(zz5vecz8z6z8z5bv32z9z9)(&zXs, zgsz368);
  KILL(zz5vecz8z6z8z5bv32z9z9)(&zgsz368);
let_end_57: ;
}
static void kill_letbind_0(void) {    KILL(zz5vecz8z6z8z5bv32z9z9)(&zXs);
}

uint64_t zEXTS(sbits);

lbits zghz386;
sail_int zghz387;
lbits zghz388;

void startup_zEXTS(void)
{
  CREATE(lbits)(&zghz386);
  CREATE(sail_int)(&zghz387);
  CREATE(lbits)(&zghz388);
}

uint64_t zEXTS(sbits zxs)
{
  __label__ end_function_59, end_block_exception_60;

  uint64_t zcbz315;
  {
    RECREATE(lbits)(&zghz386);
    CONVERT_OF(lbits, sbits)(&zghz386, zxs, true);
    RECREATE(sail_int)(&zghz387);
    CONVERT_OF(sail_int, mach_int)(&zghz387, INT64_C(32));
    RECREATE(lbits)(&zghz388);
    sign_extend(&zghz388, zghz386, zghz387);
    zcbz315 = CONVERT_OF(fbits, lbits)(zghz388, true);
  }
end_function_59: ;
  return zcbz315;
end_block_exception_60: ;

  return UINT64_C(0xdeadc0de);
}



void finish_zEXTS(void)
{
  KILL(lbits)(&zghz388);
  KILL(sail_int)(&zghz387);
  KILL(lbits)(&zghz386);
}

unit zadd_to_PC(sail_int);

lbits zghz389;
lbits zghz390;

void startup_zadd_to_PC(void)
{
  CREATE(lbits)(&zghz389);
  CREATE(lbits)(&zghz390);
}

unit zadd_to_PC(sail_int zbytes)
{
  __label__ end_function_62, end_block_exception_63;

  unit zcbz316;
  {
    RECREATE(lbits)(&zghz389);
    CONVERT_OF(lbits, fbits)(&zghz389, zPC, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz390);
    add_bits_int(&zghz390, zghz389, zbytes);
    zPC = CONVERT_OF(fbits, lbits)(zghz390, true);
  }
  zcbz316 = UNIT;
end_function_62: ;
  return zcbz316;
end_block_exception_63: ;

  return UNIT;
}



void finish_zadd_to_PC(void)
{
  KILL(lbits)(&zghz390);
  KILL(lbits)(&zghz389);
}

unit zinc_PC(unit);

sail_int zghz391;

void startup_zinc_PC(void)
{    CREATE(sail_int)(&zghz391);
}

unit zinc_PC(unit zgsz374)
{
  __label__ end_function_65, end_block_exception_66;

  unit zcbz317;
  {
    RECREATE(sail_int)(&zghz391);
    CONVERT_OF(sail_int, mach_int)(&zghz391, INT64_C(4));
    zcbz317 = zadd_to_PC(zghz391);
  }
end_function_65: ;
  return zcbz317;
end_block_exception_66: ;

  return UNIT;
}



void finish_zinc_PC(void)
{    KILL(sail_int)(&zghz391);
}

bool zprotected(uint64_t);

lbits zghz392;
lbits zghz393;
lbits zghz394;
lbits zghz395;

void startup_zprotected(void)
{
  CREATE(lbits)(&zghz392);
  CREATE(lbits)(&zghz393);
  CREATE(lbits)(&zghz394);
  CREATE(lbits)(&zghz395);
}

bool zprotected(uint64_t zaddr)
{
  __label__ end_function_68, end_block_exception_69;

  bool zcbz318;
  bool zgaz356;
  {
    RECREATE(lbits)(&zghz394);
    CONVERT_OF(lbits, fbits)(&zghz394, zaddr, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz395);
    CONVERT_OF(lbits, fbits)(&zghz395, zstart_boundary, UINT64_C(32) , true);
    zgaz356 = zlte_bit(zghz395, zghz394);
  }
  bool zgsz378;
  if (zgaz356) {
  {
    RECREATE(lbits)(&zghz392);
    CONVERT_OF(lbits, fbits)(&zghz392, zend_boundary, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz393);
    CONVERT_OF(lbits, fbits)(&zghz393, zaddr, UINT64_C(32) , true);
    zgsz378 = zlte_bit(zghz393, zghz392);
  }
  } else {  zgsz378 = false;  }
  zcbz318 = zgsz378;

end_function_68: ;
  return zcbz318;
end_block_exception_69: ;

  return false;
}



void finish_zprotected(void)
{
  KILL(lbits)(&zghz395);
  KILL(lbits)(&zghz394);
  KILL(lbits)(&zghz393);
  KILL(lbits)(&zghz392);
}

bool zunprotected(uint64_t);

lbits zghz396;
lbits zghz397;
lbits zghz398;
lbits zghz399;

void startup_zunprotected(void)
{
  CREATE(lbits)(&zghz396);
  CREATE(lbits)(&zghz397);
  CREATE(lbits)(&zghz398);
  CREATE(lbits)(&zghz399);
}

bool zunprotected(uint64_t zaddr)
{
  __label__ end_function_71, end_block_exception_72;

  bool zcbz319;
  bool zgaz357;
  {
    RECREATE(lbits)(&zghz398);
    CONVERT_OF(lbits, fbits)(&zghz398, zstart_boundary, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz399);
    CONVERT_OF(lbits, fbits)(&zghz399, zaddr, UINT64_C(32) , true);
    zgaz357 = zlt_bit(zghz399, zghz398);
  }
  bool zgsz383;
  if (zgaz357) {  zgsz383 = true;  } else {
  {
    RECREATE(lbits)(&zghz396);
    CONVERT_OF(lbits, fbits)(&zghz396, zaddr, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz397);
    CONVERT_OF(lbits, fbits)(&zghz397, zend_boundary, UINT64_C(32) , true);
    zgsz383 = zlt_bit(zghz397, zghz396);
  }
  }
  zcbz319 = zgsz383;

end_function_71: ;
  return zcbz319;
end_block_exception_72: ;

  return false;
}



void finish_zunprotected(void)
{
  KILL(lbits)(&zghz399);
  KILL(lbits)(&zghz398);
  KILL(lbits)(&zghz397);
  KILL(lbits)(&zghz396);
}

uint64_t zreg_offset(uint64_t);

lbits zghz3100;
lbits zghz3101;
lbits zghz3102;
lbits zghz3103;

void startup_zreg_offset(void)
{
  CREATE(lbits)(&zghz3100);
  CREATE(lbits)(&zghz3101);
  CREATE(lbits)(&zghz3102);
  CREATE(lbits)(&zghz3103);
}

uint64_t zreg_offset(uint64_t zr)
{
  __label__ case_75, case_76, case_77, case_78, case_79, case_80, finish_match_74, end_function_81, end_block_exception_82;

  uint64_t zcbz320;
  {
    uint64_t zreg;
    zreg = zr;
    bool zgaz358;
    {
      RECREATE(lbits)(&zghz3102);
      CONVERT_OF(lbits, fbits)(&zghz3102, zreg, UINT64_C(5) , true);
      RECREATE(lbits)(&zghz3103);
      CONVERT_OF(lbits, fbits)(&zghz3103, UINT64_C(0b00000), UINT64_C(5) , true);
      zgaz358 = zlte_bit(zghz3103, zghz3102);
    }
    bool zgsz389;
    if (zgaz358) {
    {
      RECREATE(lbits)(&zghz3100);
      CONVERT_OF(lbits, fbits)(&zghz3100, UINT64_C(0b00011), UINT64_C(5) , true);
      RECREATE(lbits)(&zghz3101);
      CONVERT_OF(lbits, fbits)(&zghz3101, zreg, UINT64_C(5) , true);
      zgsz389 = zlte_bit(zghz3101, zghz3100);
    }
    } else {  zgsz389 = false;  }
    bool zgsz392;
    zgsz392 = zgsz389;
  
    if (!(zgsz392)) {
  
    goto case_75;
    }
    zcbz320 = (safe_rshift(UINT64_MAX, 64 - 3) & (zr >> INT64_C(0)));
  
    goto finish_match_74;
  }
case_75: ;
  {
    uint64_t zb__0;
    zb__0 = zr;
    bool zgsz393;
    zgsz393 = (zb__0 == UINT64_C(0b01010));
    if (!(zgsz393)) {
  
    goto case_76;
    }
    zcbz320 = UINT64_C(0b100);
  
    goto finish_match_74;
  }
case_76: ;
  {
    uint64_t zb__1;
    zb__1 = zr;
    bool zgsz394;
    zgsz394 = (zb__1 == UINT64_C(0b01011));
    if (!(zgsz394)) {
  
    goto case_77;
    }
    zcbz320 = UINT64_C(0b101);
  
    goto finish_match_74;
  }
case_77: ;
  {
    uint64_t zb__2;
    zb__2 = zr;
    bool zgsz395;
    zgsz395 = (zb__2 == UINT64_C(0b01100));
    if (!(zgsz395)) {
  
    goto case_78;
    }
    zcbz320 = UINT64_C(0b110);
  
    goto finish_match_74;
  }
case_78: ;
  {
    uint64_t zb__3;
    zb__3 = zr;
    bool zgsz396;
    zgsz396 = (zb__3 == UINT64_C(0b01101));
    if (!(zgsz396)) {
  
    goto case_79;
    }
    zcbz320 = UINT64_C(0b111);
  
    goto finish_match_74;
  }
case_79: ;
  {
    zcbz320 = UINT64_C(0b000);
    goto finish_match_74;
  }
case_80: ;
  sail_match_failure("reg_offset");
finish_match_74: ;
end_function_81: ;
  return zcbz320;
end_block_exception_82: ;

  return UINT64_C(0xdeadc0de);
}



void finish_zreg_offset(void)
{
  KILL(lbits)(&zghz3103);
  KILL(lbits)(&zghz3102);
  KILL(lbits)(&zghz3101);
  KILL(lbits)(&zghz3100);
}

uint64_t zrREG(uint64_t);

sail_int zghz3104;

void startup_zrREG(void)
{    CREATE(sail_int)(&zghz3104);
}

uint64_t zrREG(uint64_t zr)
{
  __label__ end_function_84, end_block_exception_85;

  uint64_t zcbz321;
  uint64_t zoffset;
  zoffset = zreg_offset(zr);
  uint64_t* zgaz360;
  {
    int64_t zgaz359;
    zgaz359 = ((mach_int) zoffset);
    {
      RECREATE(sail_int)(&zghz3104);
      CONVERT_OF(sail_int, mach_int)(&zghz3104, zgaz359);
      zgaz360 = vector_access_zz5vecz8z6z8z5bv32z9z9(zXs, zghz3104);
    }
  
  }
  zcbz321 = *(zgaz360);


end_function_84: ;
  return zcbz321;
end_block_exception_85: ;

  return UINT64_C(0xdeadc0de);
}



void finish_zrREG(void)
{    KILL(sail_int)(&zghz3104);
}

unit zwREG(uint64_t, uint64_t);

sail_int zghz3105;
sail_int zghz3106;
lbits zghz3107;
lbits zghz3108;
sail_int zghz3109;
sail_int zghz3110;
lbits zghz3111;
lbits zghz3112;

void startup_zwREG(void)
{
  CREATE(sail_int)(&zghz3105);
  CREATE(sail_int)(&zghz3106);
  CREATE(lbits)(&zghz3107);
  CREATE(lbits)(&zghz3108);
  CREATE(sail_int)(&zghz3109);
  CREATE(sail_int)(&zghz3110);
  CREATE(lbits)(&zghz3111);
  CREATE(lbits)(&zghz3112);
}

unit zwREG(uint64_t zr, uint64_t zv)
{
  __label__ case_88, case_89, finish_match_87, end_function_90, end_block_exception_91;

  unit zcbz322;
  uint64_t zoffset;
  zoffset = zreg_offset(zr);
  {
    uint64_t zb__0;
    zb__0 = zoffset;
    bool zgsz3103;
    zgsz3103 = (zb__0 == UINT64_C(0b000));
    if (!(zgsz3103)) {
  
    goto case_88;
    }
    bool zgaz362;
    {
      uint64_t zgaz361;
      {
        RECREATE(sail_int)(&zghz3110);
        CONVERT_OF(sail_int, mach_int)(&zghz3110, INT64_C(32));
        RECREATE(lbits)(&zghz3111);
        CONVERT_OF(lbits, fbits)(&zghz3111, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3112);
        zextzz(&zghz3112, zghz3110, zghz3111);
        zgaz361 = CONVERT_OF(fbits, lbits)(zghz3112, true);
      }
      zgaz362 = (zv == zgaz361);
    
    }
    if (zgaz362) {
    uint64_t* zgaz363;
    {
      RECREATE(sail_int)(&zghz3109);
      CONVERT_OF(sail_int, mach_int)(&zghz3109, INT64_C(0));
      zgaz363 = vector_access_zz5vecz8z6z8z5bv32z9z9(zXs, zghz3109);
    }
    {
      RECREATE(sail_int)(&zghz3106);
      CONVERT_OF(sail_int, mach_int)(&zghz3106, INT64_C(32));
      RECREATE(lbits)(&zghz3107);
      CONVERT_OF(lbits, fbits)(&zghz3107, UINT64_C(0b0), UINT64_C(1) , true);
      RECREATE(lbits)(&zghz3108);
      zextzz(&zghz3108, zghz3106, zghz3107);
      (*(zgaz363)) = CONVERT_OF(fbits, lbits)(zghz3108, true);
    }
    zcbz322 = UNIT;
  
    } else {  zcbz322 = print_endline("Cannot overwrite hard-wired zero register");  }
  
  
    goto finish_match_87;
  }
case_88: ;
  {
    uint64_t* zgaz364;
    {
      int64_t zgaz365;
      zgaz365 = ((mach_int) zoffset);
      {
        RECREATE(sail_int)(&zghz3105);
        CONVERT_OF(sail_int, mach_int)(&zghz3105, zgaz365);
        zgaz364 = vector_access_zz5vecz8z6z8z5bv32z9z9(zXs, zghz3105);
      }
    
    }
    (*(zgaz364)) = zv;
    zcbz322 = UNIT;
  
    goto finish_match_87;
  }
case_89: ;
  sail_match_failure("wREG");
finish_match_87: ;

end_function_90: ;
  return zcbz322;
end_block_exception_91: ;

  return UNIT;
}



void finish_zwREG(void)
{
  KILL(lbits)(&zghz3112);
  KILL(lbits)(&zghz3111);
  KILL(sail_int)(&zghz3110);
  KILL(sail_int)(&zghz3109);
  KILL(lbits)(&zghz3108);
  KILL(lbits)(&zghz3107);
  KILL(sail_int)(&zghz3106);
  KILL(sail_int)(&zghz3105);
}



uint64_t zread_mem(uint64_t);

sail_int zghz3113;
sail_int zghz3114;
lbits zghz3115;
lbits zghz3116;
lbits zghz3117;
sail_int zghz3118;
lbits zghz3119;

void startup_zread_mem(void)
{
  CREATE(sail_int)(&zghz3113);
  CREATE(sail_int)(&zghz3114);
  CREATE(lbits)(&zghz3115);
  CREATE(lbits)(&zghz3116);
  CREATE(lbits)(&zghz3117);
  CREATE(sail_int)(&zghz3118);
  CREATE(lbits)(&zghz3119);
}

uint64_t zread_mem(uint64_t zaddr)
{
  __label__ end_function_93, end_block_exception_94;

  uint64_t zcbz323;
  uint64_t zgaz366;
  {
    RECREATE(sail_int)(&zghz3118);
    CONVERT_OF(sail_int, mach_int)(&zghz3118, INT64_C(32));
    RECREATE(lbits)(&zghz3119);
    zeros(&zghz3119, zghz3118);
    zgaz366 = CONVERT_OF(fbits, lbits)(zghz3119, true);
  }
  {
    RECREATE(sail_int)(&zghz3113);
    CONVERT_OF(sail_int, mach_int)(&zghz3113, INT64_C(32));
    RECREATE(sail_int)(&zghz3114);
    CONVERT_OF(sail_int, mach_int)(&zghz3114, INT64_C(4));
    RECREATE(lbits)(&zghz3115);
    CONVERT_OF(lbits, fbits)(&zghz3115, zgaz366, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz3116);
    CONVERT_OF(lbits, fbits)(&zghz3116, zaddr, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz3117);
    read_ram(&zghz3117, zghz3113, zghz3114, zghz3115, zghz3116);
    zcbz323 = CONVERT_OF(fbits, lbits)(zghz3117, true);
  }

end_function_93: ;
  return zcbz323;
end_block_exception_94: ;

  return UINT64_C(0xdeadc0de);
}



void finish_zread_mem(void)
{
  KILL(lbits)(&zghz3119);
  KILL(sail_int)(&zghz3118);
  KILL(lbits)(&zghz3117);
  KILL(lbits)(&zghz3116);
  KILL(lbits)(&zghz3115);
  KILL(sail_int)(&zghz3114);
  KILL(sail_int)(&zghz3113);
}



unit zwrite_mem(uint64_t, uint64_t);

lbits zghz3120;
lbits zghz3121;
lbits zghz3122;
sail_int zghz3123;
sail_int zghz3124;
sail_int zghz3125;
lbits zghz3126;

void startup_zwrite_mem(void)
{
  CREATE(lbits)(&zghz3120);
  CREATE(lbits)(&zghz3121);
  CREATE(lbits)(&zghz3122);
  CREATE(sail_int)(&zghz3123);
  CREATE(sail_int)(&zghz3124);
  CREATE(sail_int)(&zghz3125);
  CREATE(lbits)(&zghz3126);
}

unit zwrite_mem(uint64_t zaddr, uint64_t zdata)
{
  __label__ end_function_96, end_block_exception_97;

  unit zcbz324;
  uint64_t zgaz367;
  {
    RECREATE(sail_int)(&zghz3125);
    CONVERT_OF(sail_int, mach_int)(&zghz3125, INT64_C(32));
    RECREATE(lbits)(&zghz3126);
    zeros(&zghz3126, zghz3125);
    zgaz367 = CONVERT_OF(fbits, lbits)(zghz3126, true);
  }
  {
    RECREATE(lbits)(&zghz3120);
    CONVERT_OF(lbits, fbits)(&zghz3120, zdata, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz3121);
    CONVERT_OF(lbits, fbits)(&zghz3121, zaddr, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz3122);
    CONVERT_OF(lbits, fbits)(&zghz3122, zgaz367, UINT64_C(32) , true);
    RECREATE(sail_int)(&zghz3123);
    CONVERT_OF(sail_int, mach_int)(&zghz3123, INT64_C(4));
    RECREATE(sail_int)(&zghz3124);
    CONVERT_OF(sail_int, mach_int)(&zghz3124, INT64_C(32));
    zcbz324 = write_ram(zghz3124, zghz3123, zghz3122, zghz3121, zghz3120);
  }

end_function_96: ;
  return zcbz324;
end_block_exception_97: ;

  return UNIT;
}



void finish_zwrite_mem(void)
{
  KILL(lbits)(&zghz3126);
  KILL(sail_int)(&zghz3125);
  KILL(sail_int)(&zghz3124);
  KILL(sail_int)(&zghz3123);
  KILL(lbits)(&zghz3122);
  KILL(lbits)(&zghz3121);
  KILL(lbits)(&zghz3120);
}

unit zreset_registers(unit);

sail_int zghz3127;
lbits zghz3128;
lbits zghz3129;
sail_int zghz3130;

void startup_zreset_registers(void)
{
  CREATE(sail_int)(&zghz3127);
  CREATE(lbits)(&zghz3128);
  CREATE(lbits)(&zghz3129);
  CREATE(sail_int)(&zghz3130);
}

unit zreset_registers(unit zgsz3124)
{
  __label__ end_function_101, end_block_exception_102;

  unit zcbz325;
  int64_t zgsz3125;
  {    zgsz3125 = INT64_C(0);
  }
  int64_t zgsz3126;
  {    zgsz3126 = INT64_C(6);
  }
  int64_t zgsz3127;
  {    zgsz3127 = INT64_C(1);
  }
  {
    __label__ for_start_99, for_end_100;

    int64_t zi;
    zi = zgsz3125;
    unit zgsz3132;
  for_start_99: ;
    {
      if ((zi > zgsz3126)) goto for_end_100;
      uint64_t* zgaz368;
      {
        RECREATE(sail_int)(&zghz3130);
        CONVERT_OF(sail_int, mach_int)(&zghz3130, zi);
        zgaz368 = vector_access_zz5vecz8z6z8z5bv32z9z9(zXs, zghz3130);
      }
      {
        RECREATE(sail_int)(&zghz3127);
        CONVERT_OF(sail_int, mach_int)(&zghz3127, INT64_C(32));
        RECREATE(lbits)(&zghz3128);
        CONVERT_OF(lbits, fbits)(&zghz3128, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3129);
        zextzz(&zghz3129, zghz3127, zghz3128);
        (*(zgaz368)) = CONVERT_OF(fbits, lbits)(zghz3129, true);
      }
      zgsz3132 = UNIT;
    
      zi = (zi + zgsz3127);
      goto for_start_99;
    }
  for_end_100: ;
  }
  zcbz325 = UNIT;
end_function_101: ;
  return zcbz325;
end_block_exception_102: ;

  return UNIT;
}



void finish_zreset_registers(void)
{
  KILL(sail_int)(&zghz3130);
  KILL(lbits)(&zghz3129);
  KILL(lbits)(&zghz3128);
  KILL(sail_int)(&zghz3127);
}

unit zobj_dump(unit);

lbits zghz3131;
sail_int zghz3132;

void startup_zobj_dump(void)
{
  CREATE(lbits)(&zghz3131);
  CREATE(sail_int)(&zghz3132);
}

unit zobj_dump(unit zgsz3133)
{
  __label__ end_function_115, end_block_exception_116;

  unit zcbz326;
  int64_t zgsz3134;
  {    zgsz3134 = INT64_C(0);
  }
  int64_t zgsz3135;
  {    zgsz3135 = INT64_C(7);
  }
  int64_t zgsz3136;
  {    zgsz3136 = INT64_C(1);
  }
  {
    __label__ for_start_104, for_end_105;

    int64_t zi;
    zi = zgsz3134;
    unit zgsz3147;
  for_start_104: ;
    {
      if ((zi > zgsz3135)) goto for_end_105;
      uint64_t zcontent;
      {
        uint64_t* zgaz370;
        {
          RECREATE(sail_int)(&zghz3132);
          CONVERT_OF(sail_int, mach_int)(&zghz3132, zi);
          zgaz370 = vector_access_zz5vecz8z6z8z5bv32z9z9(zXs, zghz3132);
        }
        zcontent = *(zgaz370);
      
      }
      sail_string zreg_name;
      CREATE(sail_string)(&zreg_name);
      {
        __label__ case_107, case_108, case_109, case_110, case_111, case_112, case_113, case_114, finish_match_106;

        {
          int64_t zp0z3;
          zp0z3 = zi;
          bool zgsz3139;
          zgsz3139 = (zp0z3 == INT64_C(0));
          if (!(zgsz3139)) {
        
          goto case_107;
          }
          COPY(sail_string)(&zreg_name, "zero");
        
          goto finish_match_106;
        }
      case_107: ;
        {
          int64_t zuz31;
          zuz31 = zi;
          bool zgsz3140;
          zgsz3140 = (zuz31 == INT64_C(1));
          if (!(zgsz3140)) {
        
          goto case_108;
          }
          COPY(sail_string)(&zreg_name, "ra");
        
          goto finish_match_106;
        }
      case_108: ;
        {
          int64_t zuz32;
          zuz32 = zi;
          bool zgsz3141;
          zgsz3141 = (zuz32 == INT64_C(2));
          if (!(zgsz3141)) {
        
          goto case_109;
          }
          COPY(sail_string)(&zreg_name, "sp");
        
          goto finish_match_106;
        }
      case_109: ;
        {
          int64_t zuz33;
          zuz33 = zi;
          bool zgsz3142;
          zgsz3142 = (zuz33 == INT64_C(3));
          if (!(zgsz3142)) {
        
          goto case_110;
          }
          COPY(sail_string)(&zreg_name, "gp");
        
          goto finish_match_106;
        }
      case_110: ;
        {
          int64_t zuz34;
          zuz34 = zi;
          bool zgsz3143;
          zgsz3143 = (zuz34 == INT64_C(4));
          if (!(zgsz3143)) {
        
          goto case_111;
          }
          COPY(sail_string)(&zreg_name, "a0");
        
          goto finish_match_106;
        }
      case_111: ;
        {
          int64_t zuz35;
          zuz35 = zi;
          bool zgsz3144;
          zgsz3144 = (zuz35 == INT64_C(5));
          if (!(zgsz3144)) {
        
          goto case_112;
          }
          COPY(sail_string)(&zreg_name, "a1");
        
          goto finish_match_106;
        }
      case_112: ;
        {
          int64_t zuz36;
          zuz36 = zi;
          bool zgsz3145;
          zgsz3145 = (zuz36 == INT64_C(6));
          if (!(zgsz3145)) {
        
          goto case_113;
          }
          COPY(sail_string)(&zreg_name, "a2");
        
          goto finish_match_106;
        }
      case_113: ;
        {
          int64_t zuz37;
          zuz37 = zi;
          bool zgsz3146;
          zgsz3146 = (zuz37 == INT64_C(7));
          if (!(zgsz3146)) {
        
          goto case_114;
          }
          COPY(sail_string)(&zreg_name, "a3");
        
          goto finish_match_106;
        }
      case_114: ;
        sail_match_failure("obj_dump");
      finish_match_106: ;
      }
      sail_string zgaz369;
      CREATE(sail_string)(&zgaz369);
      concat_str(&zgaz369, zreg_name, " = ");
      {
        RECREATE(lbits)(&zghz3131);
        CONVERT_OF(lbits, fbits)(&zghz3131, zcontent, UINT64_C(32) , true);
        zgsz3147 = print_bits(zgaz369, zghz3131);
      }
      KILL(sail_string)(&zgaz369);
      KILL(sail_string)(&zreg_name);
    
      zi = (zi + zgsz3136);
      goto for_start_104;
    }
  for_end_105: ;
  }
  zcbz326 = UNIT;
end_function_115: ;
  return zcbz326;
end_block_exception_116: ;

  return UNIT;
}



void finish_zobj_dump(void)
{
  KILL(sail_int)(&zghz3132);
  KILL(lbits)(&zghz3131);
}






void zdecode(struct zoption *rop, uint64_t);






unit zexecute(struct zast);

unit zprinte(sail_string);

unit zprinte(sail_string zstr)
{
  __label__ end_function_118, end_block_exception_119;

  unit zcbz327;
  sail_string zgaz371;
  CREATE(sail_string)(&zgaz371);
  concat_str(&zgaz371, "executing ", zstr);
  zcbz327 = print_endline(zgaz371);
  KILL(sail_string)(&zgaz371);
end_function_118: ;
  return zcbz327;
end_block_exception_119: ;

  return UNIT;
}

lbits zghz3133;
sail_int zghz3134;
lbits zghz3135;
sail_int zghz3136;
lbits zghz3137;
sail_int zghz3138;
lbits zghz3139;
lbits zghz3140;
sail_int zghz3141;
lbits zghz3142;
sail_int zghz3143;
lbits zghz3144;
lbits zghz3145;
sail_int zghz3146;
lbits zghz3147;
lbits zghz3148;
lbits zghz3149;
sail_int zghz3150;
lbits zghz3151;
lbits zghz3152;
sail_int zghz3153;
lbits zghz3154;
sail_int zghz3155;
lbits zghz3156;
lbits zghz3157;
sail_int zghz3158;
lbits zghz3159;
lbits zghz3160;
sail_int zghz3161;
lbits zghz3162;
lbits zghz3163;
lbits zghz3164;
lbits zghz3165;
lbits zghz3166;
sail_int zghz3167;
lbits zghz3168;
lbits zghz3169;
sail_int zghz3170;
lbits zghz3171;
lbits zghz3172;
sail_int zghz3173;
lbits zghz3174;
lbits zghz3175;
sail_int zghz3176;
lbits zghz3177;
lbits zghz3178;
sail_int zghz3179;
lbits zghz3180;
lbits zghz3181;
sail_int zghz3182;
lbits zghz3183;
lbits zghz3184;
sail_int zghz3185;
lbits zghz3186;
lbits zghz3187;
sail_int zghz3188;
lbits zghz3189;
lbits zghz3190;
lbits zghz3191;
lbits zghz3192;
sail_int zghz3193;
sail_int zghz3194;
sail_int zghz3195;
lbits zghz3196;
lbits zghz3197;
sail_int zghz3198;
sail_int zghz3199;
sail_int zghz3200;
lbits zghz3201;
lbits zghz3202;
sail_int zghz3203;
sail_int zghz3204;
sail_int zghz3205;
lbits zghz3206;
lbits zghz3207;
lbits zghz3208;
sail_int zghz3209;
lbits zghz3210;
lbits zghz3211;
sail_int zghz3212;
lbits zghz3213;
lbits zghz3214;
sail_int zghz3215;
lbits zghz3216;
lbits zghz3217;
lbits zghz3218;
lbits zghz3219;
lbits zghz3220;
sail_int zghz3221;
lbits zghz3222;
lbits zghz3223;
sail_int zghz3224;
lbits zghz3225;
lbits zghz3226;
sail_int zghz3227;
lbits zghz3228;
lbits zghz3229;
sail_int zghz3230;
lbits zghz3231;
lbits zghz3232;
sail_int zghz3233;
lbits zghz3234;
lbits zghz3235;
sail_int zghz3236;
lbits zghz3237;
lbits zghz3238;

void startup_zexecute(void)
{
  CREATE(lbits)(&zghz3133);
  CREATE(sail_int)(&zghz3134);
  CREATE(lbits)(&zghz3135);
  CREATE(sail_int)(&zghz3136);
  CREATE(lbits)(&zghz3137);
  CREATE(sail_int)(&zghz3138);
  CREATE(lbits)(&zghz3139);
  CREATE(lbits)(&zghz3140);
  CREATE(sail_int)(&zghz3141);
  CREATE(lbits)(&zghz3142);
  CREATE(sail_int)(&zghz3143);
  CREATE(lbits)(&zghz3144);
  CREATE(lbits)(&zghz3145);
  CREATE(sail_int)(&zghz3146);
  CREATE(lbits)(&zghz3147);
  CREATE(lbits)(&zghz3148);
  CREATE(lbits)(&zghz3149);
  CREATE(sail_int)(&zghz3150);
  CREATE(lbits)(&zghz3151);
  CREATE(lbits)(&zghz3152);
  CREATE(sail_int)(&zghz3153);
  CREATE(lbits)(&zghz3154);
  CREATE(sail_int)(&zghz3155);
  CREATE(lbits)(&zghz3156);
  CREATE(lbits)(&zghz3157);
  CREATE(sail_int)(&zghz3158);
  CREATE(lbits)(&zghz3159);
  CREATE(lbits)(&zghz3160);
  CREATE(sail_int)(&zghz3161);
  CREATE(lbits)(&zghz3162);
  CREATE(lbits)(&zghz3163);
  CREATE(lbits)(&zghz3164);
  CREATE(lbits)(&zghz3165);
  CREATE(lbits)(&zghz3166);
  CREATE(sail_int)(&zghz3167);
  CREATE(lbits)(&zghz3168);
  CREATE(lbits)(&zghz3169);
  CREATE(sail_int)(&zghz3170);
  CREATE(lbits)(&zghz3171);
  CREATE(lbits)(&zghz3172);
  CREATE(sail_int)(&zghz3173);
  CREATE(lbits)(&zghz3174);
  CREATE(lbits)(&zghz3175);
  CREATE(sail_int)(&zghz3176);
  CREATE(lbits)(&zghz3177);
  CREATE(lbits)(&zghz3178);
  CREATE(sail_int)(&zghz3179);
  CREATE(lbits)(&zghz3180);
  CREATE(lbits)(&zghz3181);
  CREATE(sail_int)(&zghz3182);
  CREATE(lbits)(&zghz3183);
  CREATE(lbits)(&zghz3184);
  CREATE(sail_int)(&zghz3185);
  CREATE(lbits)(&zghz3186);
  CREATE(lbits)(&zghz3187);
  CREATE(sail_int)(&zghz3188);
  CREATE(lbits)(&zghz3189);
  CREATE(lbits)(&zghz3190);
  CREATE(lbits)(&zghz3191);
  CREATE(lbits)(&zghz3192);
  CREATE(sail_int)(&zghz3193);
  CREATE(sail_int)(&zghz3194);
  CREATE(sail_int)(&zghz3195);
  CREATE(lbits)(&zghz3196);
  CREATE(lbits)(&zghz3197);
  CREATE(sail_int)(&zghz3198);
  CREATE(sail_int)(&zghz3199);
  CREATE(sail_int)(&zghz3200);
  CREATE(lbits)(&zghz3201);
  CREATE(lbits)(&zghz3202);
  CREATE(sail_int)(&zghz3203);
  CREATE(sail_int)(&zghz3204);
  CREATE(sail_int)(&zghz3205);
  CREATE(lbits)(&zghz3206);
  CREATE(lbits)(&zghz3207);
  CREATE(lbits)(&zghz3208);
  CREATE(sail_int)(&zghz3209);
  CREATE(lbits)(&zghz3210);
  CREATE(lbits)(&zghz3211);
  CREATE(sail_int)(&zghz3212);
  CREATE(lbits)(&zghz3213);
  CREATE(lbits)(&zghz3214);
  CREATE(sail_int)(&zghz3215);
  CREATE(lbits)(&zghz3216);
  CREATE(lbits)(&zghz3217);
  CREATE(lbits)(&zghz3218);
  CREATE(lbits)(&zghz3219);
  CREATE(lbits)(&zghz3220);
  CREATE(sail_int)(&zghz3221);
  CREATE(lbits)(&zghz3222);
  CREATE(lbits)(&zghz3223);
  CREATE(sail_int)(&zghz3224);
  CREATE(lbits)(&zghz3225);
  CREATE(lbits)(&zghz3226);
  CREATE(sail_int)(&zghz3227);
  CREATE(lbits)(&zghz3228);
  CREATE(lbits)(&zghz3229);
  CREATE(sail_int)(&zghz3230);
  CREATE(lbits)(&zghz3231);
  CREATE(lbits)(&zghz3232);
  CREATE(sail_int)(&zghz3233);
  CREATE(lbits)(&zghz3234);
  CREATE(lbits)(&zghz3235);
  CREATE(sail_int)(&zghz3236);
  CREATE(lbits)(&zghz3237);
  CREATE(lbits)(&zghz3238);
}


// struct tuple_(%bv64, %bv64)
struct ztuple_z8z5bv64zCz0z5bv64z9 {
  uint64_t ztup0;
  uint64_t ztup1;
};

static void COPY(ztuple_z8z5bv64zCz0z5bv64z9)(struct ztuple_z8z5bv64zCz0z5bv64z9 *rop, const struct ztuple_z8z5bv64zCz0z5bv64z9 op) {
  rop->ztup0 = op.ztup0;
  rop->ztup1 = op.ztup1;
}

static bool EQUAL(ztuple_z8z5bv64zCz0z5bv64z9)(struct ztuple_z8z5bv64zCz0z5bv64z9 op1, struct ztuple_z8z5bv64zCz0z5bv64z9 op2) {
  return EQUAL(fbits)(op1.ztup0, op2.ztup0) && EQUAL(fbits)(op1.ztup1, op2.ztup1);
}







unit zexecute(struct zast zmergez3var)
{
  __label__ case_122, case_123, case_127, case_131, case_135, case_136, case_139, case_142, case_143, case_144, case_148, case_152, case_156, case_157, case_158, case_159, case_165, case_166, case_167, case_168, case_169, case_170, case_171, finish_match_121, end_function_172, end_block_exception_173;

  unit zcbz328;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_122;
    uint64_t zrs2;
    zrs2 = zmergez3var.zRTYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zRTYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zRTYPE.ztup2;
    if ((zADD != zmergez3var.zRTYPE.ztup3)) goto case_122;
    {
      unit zgsz3151;
      zgsz3151 = zprinte("add");
    }
    {
      uint64_t zrs1_val;
      zrs1_val = zrREG(zrs1);
      uint64_t zrs2_val;
      zrs2_val = zrREG(zrs2);
      uint64_t zresult;
      zresult = ((zrs1_val + zrs2_val) & UINT64_C(0xFFFFFFFF));
      unit zgsz3150;
      zgsz3150 = zwREG(zrd, zresult);
    
    
    
    }
    zcbz328 = zinc_PC(UNIT);
  
  
  
    goto finish_match_121;
  }
case_122: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_123;
    uint64_t zuz38;
    zuz38 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz39;
    zuz39 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz310;
    zuz310 = zmergez3var.zRTYPE.ztup2;
    if ((zAND != zmergez3var.zRTYPE.ztup3)) goto case_123;
    {
      unit zgsz3166;
      zgsz3166 = zprinte("and");
    }
    {
      __label__ case_125, case_126, finish_match_124;

      uint64_t zuz311;
      zuz311 = zrREG(zuz39);
      uint64_t zuz312;
      zuz312 = zrREG(zuz38);
      uint64_t zbitwise_AND;
      zbitwise_AND = (zuz311 & zuz312);
      unit zgsz3153;
      {
        uint64_t zvz30;
        zvz30 = zbitwise_AND;
        uint64_t zgaz373;
        {
          RECREATE(sail_int)(&zghz3236);
          CONVERT_OF(sail_int, mach_int)(&zghz3236, INT64_C(32));
          RECREATE(lbits)(&zghz3237);
          CONVERT_OF(lbits, fbits)(&zghz3237, UINT64_C(0b1), UINT64_C(1) , true);
          RECREATE(lbits)(&zghz3238);
          zextzz(&zghz3238, zghz3236, zghz3237);
          zgaz373 = CONVERT_OF(fbits, lbits)(zghz3238, true);
        }
        bool zgsz3160;
        zgsz3160 = (zvz30 == zgaz373);
      
        if (!(zgsz3160)) {
      
        goto case_125;
        }
        uint64_t zgaz372;
        {
          RECREATE(sail_int)(&zghz3233);
          CONVERT_OF(sail_int, mach_int)(&zghz3233, INT64_C(32));
          RECREATE(lbits)(&zghz3234);
          CONVERT_OF(lbits, fbits)(&zghz3234, UINT64_C(0b1), UINT64_C(1) , true);
          RECREATE(lbits)(&zghz3235);
          zextzz(&zghz3235, zghz3233, zghz3234);
          zgaz372 = CONVERT_OF(fbits, lbits)(zghz3235, true);
        }
        zgsz3153 = zwREG(zuz310, zgaz372);
      
      
        goto finish_match_124;
      }
    case_125: ;
      {
        uint64_t zgaz374;
        {
          RECREATE(sail_int)(&zghz3230);
          CONVERT_OF(sail_int, mach_int)(&zghz3230, INT64_C(32));
          RECREATE(lbits)(&zghz3231);
          CONVERT_OF(lbits, fbits)(&zghz3231, UINT64_C(0b0), UINT64_C(1) , true);
          RECREATE(lbits)(&zghz3232);
          zextzz(&zghz3232, zghz3230, zghz3231);
          zgaz374 = CONVERT_OF(fbits, lbits)(zghz3232, true);
        }
        zgsz3153 = zwREG(zuz310, zgaz374);
      
        goto finish_match_124;
      }
    case_126: ;
      sail_match_failure("execute");
    finish_match_124: ;
      unit zgsz3165;
      zgsz3165 = zgsz3153;
    
    
    
    
    }
    zcbz328 = zinc_PC(UNIT);
  
  
  
    goto finish_match_121;
  }
case_123: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_127;
    uint64_t zuz313;
    zuz313 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz314;
    zuz314 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz315;
    zuz315 = zmergez3var.zRTYPE.ztup2;
    if ((zOR != zmergez3var.zRTYPE.ztup3)) goto case_127;
    {
      unit zgsz3181;
      zgsz3181 = zprinte("or");
    }
    {
      __label__ case_129, case_130, finish_match_128;

      uint64_t zuz316;
      zuz316 = zrREG(zuz314);
      uint64_t zuz317;
      zuz317 = zrREG(zuz313);
      uint64_t zbitwise_OR;
      zbitwise_OR = (zuz316 | zuz317);
      unit zgsz3168;
      {
        uint64_t zvz31;
        zvz31 = zbitwise_OR;
        uint64_t zgaz376;
        {
          RECREATE(sail_int)(&zghz3227);
          CONVERT_OF(sail_int, mach_int)(&zghz3227, INT64_C(32));
          RECREATE(lbits)(&zghz3228);
          CONVERT_OF(lbits, fbits)(&zghz3228, UINT64_C(0b1), UINT64_C(1) , true);
          RECREATE(lbits)(&zghz3229);
          zextzz(&zghz3229, zghz3227, zghz3228);
          zgaz376 = CONVERT_OF(fbits, lbits)(zghz3229, true);
        }
        bool zgsz3175;
        zgsz3175 = (zvz31 == zgaz376);
      
        if (!(zgsz3175)) {
      
        goto case_129;
        }
        uint64_t zgaz375;
        {
          RECREATE(sail_int)(&zghz3224);
          CONVERT_OF(sail_int, mach_int)(&zghz3224, INT64_C(32));
          RECREATE(lbits)(&zghz3225);
          CONVERT_OF(lbits, fbits)(&zghz3225, UINT64_C(0b1), UINT64_C(1) , true);
          RECREATE(lbits)(&zghz3226);
          zextzz(&zghz3226, zghz3224, zghz3225);
          zgaz375 = CONVERT_OF(fbits, lbits)(zghz3226, true);
        }
        zgsz3168 = zwREG(zuz315, zgaz375);
      
      
        goto finish_match_128;
      }
    case_129: ;
      {
        uint64_t zgaz377;
        {
          RECREATE(sail_int)(&zghz3221);
          CONVERT_OF(sail_int, mach_int)(&zghz3221, INT64_C(32));
          RECREATE(lbits)(&zghz3222);
          CONVERT_OF(lbits, fbits)(&zghz3222, UINT64_C(0b0), UINT64_C(1) , true);
          RECREATE(lbits)(&zghz3223);
          zextzz(&zghz3223, zghz3221, zghz3222);
          zgaz377 = CONVERT_OF(fbits, lbits)(zghz3223, true);
        }
        zgsz3168 = zwREG(zuz315, zgaz377);
      
        goto finish_match_128;
      }
    case_130: ;
      sail_match_failure("execute");
    finish_match_128: ;
      unit zgsz3180;
      zgsz3180 = zgsz3168;
    
    
    
    
    }
    zcbz328 = zinc_PC(UNIT);
  
  
  
    goto finish_match_121;
  }
case_127: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_131;
    uint64_t zuz318;
    zuz318 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz319;
    zuz319 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz320;
    zuz320 = zmergez3var.zRTYPE.ztup2;
    if ((zXOR != zmergez3var.zRTYPE.ztup3)) goto case_131;
    {
      unit zgsz3199;
      zgsz3199 = zprinte("xor");
    }
    {
      __label__ case_133, case_134, finish_match_132;

      uint64_t zuz321;
      zuz321 = zrREG(zuz319);
      uint64_t zuz322;
      zuz322 = zrREG(zuz318);
      uint64_t zbitwise_XOR;
      {
        RECREATE(lbits)(&zghz3218);
        CONVERT_OF(lbits, fbits)(&zghz3218, zuz321, UINT64_C(32) , true);
        RECREATE(lbits)(&zghz3219);
        CONVERT_OF(lbits, fbits)(&zghz3219, zuz322, UINT64_C(32) , true);
        RECREATE(lbits)(&zghz3220);
        zxor_bitvector(&zghz3220, zghz3218, zghz3219);
        zbitwise_XOR = CONVERT_OF(fbits, lbits)(zghz3220, true);
      }
      unit zgsz3186;
      {
        uint64_t zvz32;
        zvz32 = zbitwise_XOR;
        uint64_t zgaz379;
        {
          RECREATE(sail_int)(&zghz3215);
          CONVERT_OF(sail_int, mach_int)(&zghz3215, INT64_C(32));
          RECREATE(lbits)(&zghz3216);
          CONVERT_OF(lbits, fbits)(&zghz3216, UINT64_C(0b1), UINT64_C(1) , true);
          RECREATE(lbits)(&zghz3217);
          zextzz(&zghz3217, zghz3215, zghz3216);
          zgaz379 = CONVERT_OF(fbits, lbits)(zghz3217, true);
        }
        bool zgsz3193;
        zgsz3193 = (zvz32 == zgaz379);
      
        if (!(zgsz3193)) {
      
        goto case_133;
        }
        uint64_t zgaz378;
        {
          RECREATE(sail_int)(&zghz3212);
          CONVERT_OF(sail_int, mach_int)(&zghz3212, INT64_C(32));
          RECREATE(lbits)(&zghz3213);
          CONVERT_OF(lbits, fbits)(&zghz3213, UINT64_C(0b1), UINT64_C(1) , true);
          RECREATE(lbits)(&zghz3214);
          zextzz(&zghz3214, zghz3212, zghz3213);
          zgaz378 = CONVERT_OF(fbits, lbits)(zghz3214, true);
        }
        zgsz3186 = zwREG(zuz320, zgaz378);
      
      
        goto finish_match_132;
      }
    case_133: ;
      {
        uint64_t zgaz380;
        {
          RECREATE(sail_int)(&zghz3209);
          CONVERT_OF(sail_int, mach_int)(&zghz3209, INT64_C(32));
          RECREATE(lbits)(&zghz3210);
          CONVERT_OF(lbits, fbits)(&zghz3210, UINT64_C(0b0), UINT64_C(1) , true);
          RECREATE(lbits)(&zghz3211);
          zextzz(&zghz3211, zghz3209, zghz3210);
          zgaz380 = CONVERT_OF(fbits, lbits)(zghz3211, true);
        }
        zgsz3186 = zwREG(zuz320, zgaz380);
      
        goto finish_match_132;
      }
    case_134: ;
      sail_match_failure("execute");
    finish_match_132: ;
      unit zgsz3198;
      zgsz3198 = zgsz3186;
    
    
    
    
    }
    zcbz328 = zinc_PC(UNIT);
  
  
  
    goto finish_match_121;
  }
case_131: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_135;
    uint64_t zuz323;
    zuz323 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz324;
    zuz324 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz325;
    zuz325 = zmergez3var.zRTYPE.ztup2;
    if ((zMUL != zmergez3var.zRTYPE.ztup3)) goto case_135;
    {
      unit zgsz3208;
      zgsz3208 = zprinte("mul");
    }
    {
      uint64_t zmultiplicand;
      zmultiplicand = zrREG(zuz324);
      uint64_t zmultiplier;
      zmultiplier = zrREG(zuz323);
      uint64_t zproduct;
      {
        RECREATE(lbits)(&zghz3206);
        CONVERT_OF(lbits, fbits)(&zghz3206, zmultiplicand, UINT64_C(32) , true);
        RECREATE(lbits)(&zghz3207);
        CONVERT_OF(lbits, fbits)(&zghz3207, zmultiplier, UINT64_C(32) , true);
        RECREATE(lbits)(&zghz3208);
        zmul_bitvector(&zghz3208, zghz3206, zghz3207);
        zproduct = CONVERT_OF(fbits, lbits)(zghz3208, true);
      }
      int64_t zlen;
      {
        RECREATE(sail_int)(&zghz3203);
        CONVERT_OF(sail_int, mach_int)(&zghz3203, INT64_C(32));
        RECREATE(sail_int)(&zghz3204);
        CONVERT_OF(sail_int, mach_int)(&zghz3204, INT64_C(1));
        RECREATE(sail_int)(&zghz3205);
        sub_int(&zghz3205, zghz3203, zghz3204);
        zlen = CONVERT_OF(mach_int, sail_int)(zghz3205);
      }
      uint64_t zuz326;
      zuz326 = (safe_rshift(UINT64_MAX, 64 - 32) & (zproduct >> INT64_C(0)));
      unit zgsz3207;
      zgsz3207 = zwREG(zuz325, zuz326);
    
    
    
    
    
    }
    zcbz328 = zinc_PC(UNIT);
  
  
  
    goto finish_match_121;
  }
case_135: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_136;
    uint64_t zuz327;
    zuz327 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz328;
    zuz328 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz329;
    zuz329 = zmergez3var.zRTYPE.ztup2;
    if ((zDIV != zmergez3var.zRTYPE.ztup3)) goto case_136;
    {
      unit zgsz3219;
      zgsz3219 = zprinte("div");
    }
    {
      __label__ case_138, finish_match_137;

      uint64_t zdividend;
      zdividend = zrREG(zuz328);
      uint64_t zdivisor;
      zdivisor = zrREG(zuz327);
      struct ztuple_z8z5bv64zCz0z5bv64z9 zgaz381;
      {
        RECREATE(lbits)(&zghz3201);
        CONVERT_OF(lbits, fbits)(&zghz3201, zdividend, UINT64_C(32) , true);
        RECREATE(lbits)(&zghz3202);
        CONVERT_OF(lbits, fbits)(&zghz3202, zdivisor, UINT64_C(32) , true);
        struct ztuple_z8z5bvzCz0z5bvz9 zgsz3212;
        CREATE(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3212);
        zdiv_bitvector(&zgsz3212, zghz3201, zghz3202);
        /* conversions */
        zgaz381.ztup0 = CONVERT_OF(fbits, lbits)(zgsz3212.ztup0, true);
        zgaz381.ztup1 = CONVERT_OF(fbits, lbits)(zgsz3212.ztup1, true);
        /* end conversions */
        KILL(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3212);
      }
      unit zgsz3213;
      {
        uint64_t zdiv;
        zdiv = zgaz381.ztup0;
        uint64_t zrem;
        zrem = zgaz381.ztup1;
        int64_t zuz330;
        {
          RECREATE(sail_int)(&zghz3198);
          CONVERT_OF(sail_int, mach_int)(&zghz3198, INT64_C(32));
          RECREATE(sail_int)(&zghz3199);
          CONVERT_OF(sail_int, mach_int)(&zghz3199, INT64_C(1));
          RECREATE(sail_int)(&zghz3200);
          sub_int(&zghz3200, zghz3198, zghz3199);
          zuz330 = CONVERT_OF(mach_int, sail_int)(zghz3200);
        }
        uint64_t zuz331;
        zuz331 = (safe_rshift(UINT64_MAX, 64 - 32) & (zdiv >> INT64_C(0)));
        zgsz3213 = zwREG(zuz329, zuz331);
      
      
      
      
        goto finish_match_137;
      }
    case_138: ;
      sail_match_failure("execute");
    finish_match_137: ;
      unit zgsz3218;
      zgsz3218 = zgsz3213;
    
    
    
    
    }
    zcbz328 = zinc_PC(UNIT);
  
  
  
    goto finish_match_121;
  }
case_136: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_139;
    uint64_t zuz332;
    zuz332 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz333;
    zuz333 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz334;
    zuz334 = zmergez3var.zRTYPE.ztup2;
    if ((zREM != zmergez3var.zRTYPE.ztup3)) goto case_139;
    {
      unit zgsz3230;
      zgsz3230 = zprinte("rem");
    }
    {
      __label__ case_141, finish_match_140;

      uint64_t zuz335;
      zuz335 = zrREG(zuz333);
      uint64_t zuz336;
      zuz336 = zrREG(zuz332);
      struct ztuple_z8z5bv64zCz0z5bv64z9 zgaz382;
      {
        RECREATE(lbits)(&zghz3196);
        CONVERT_OF(lbits, fbits)(&zghz3196, zuz335, UINT64_C(32) , true);
        RECREATE(lbits)(&zghz3197);
        CONVERT_OF(lbits, fbits)(&zghz3197, zuz336, UINT64_C(32) , true);
        struct ztuple_z8z5bvzCz0z5bvz9 zgsz3223;
        CREATE(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3223);
        zdiv_bitvector(&zgsz3223, zghz3196, zghz3197);
        /* conversions */
        zgaz382.ztup0 = CONVERT_OF(fbits, lbits)(zgsz3223.ztup0, true);
        zgaz382.ztup1 = CONVERT_OF(fbits, lbits)(zgsz3223.ztup1, true);
        /* end conversions */
        KILL(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3223);
      }
      unit zgsz3224;
      {
        uint64_t zuz337;
        zuz337 = zgaz382.ztup0;
        uint64_t zuz338;
        zuz338 = zgaz382.ztup1;
        int64_t zuz339;
        {
          RECREATE(sail_int)(&zghz3193);
          CONVERT_OF(sail_int, mach_int)(&zghz3193, INT64_C(32));
          RECREATE(sail_int)(&zghz3194);
          CONVERT_OF(sail_int, mach_int)(&zghz3194, INT64_C(1));
          RECREATE(sail_int)(&zghz3195);
          sub_int(&zghz3195, zghz3193, zghz3194);
          zuz339 = CONVERT_OF(mach_int, sail_int)(zghz3195);
        }
        uint64_t zuz340;
        zuz340 = (safe_rshift(UINT64_MAX, 64 - 32) & (zuz338 >> INT64_C(0)));
        zgsz3224 = zwREG(zuz334, zuz340);
      
      
      
      
        goto finish_match_140;
      }
    case_141: ;
      sail_match_failure("execute");
    finish_match_140: ;
      unit zgsz3229;
      zgsz3229 = zgsz3224;
    
    
    
    
    }
    zcbz328 = zinc_PC(UNIT);
  
  
  
    goto finish_match_121;
  }
case_139: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_142;
    uint64_t zimm;
    zimm = zmergez3var.zITYPE.ztup0;
    uint64_t zuz341;
    zuz341 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz342;
    zuz342 = zmergez3var.zITYPE.ztup2;
    if ((zADDI != zmergez3var.zITYPE.ztup3)) goto case_142;
    {
      unit zgsz3234;
      zgsz3234 = zprinte("addi");
    }
    {
      uint64_t zuz343;
      zuz343 = zrREG(zuz341);
      uint64_t zimm_ext;
      {
        sbits zgsz3232;
        zgsz3232 = CONVERT_OF(sbits, fbits)(zimm, UINT64_C(12) , true);
        zimm_ext = zEXTS(zgsz3232);
      
      }
      uint64_t zuz344;
      zuz344 = ((zuz343 + zimm_ext) & UINT64_C(0xFFFFFFFF));
      unit zgsz3233;
      zgsz3233 = zwREG(zuz342, zuz344);
    
    
    
    }
    zcbz328 = zinc_PC(UNIT);
  
  
  
    goto finish_match_121;
  }
case_142: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_143;
    uint64_t zuz345;
    zuz345 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz346;
    zuz346 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz347;
    zuz347 = zmergez3var.zITYPE.ztup2;
    if ((zSLTI != zmergez3var.zITYPE.ztup3)) goto case_143;
    {
      unit zgsz3246;
      zgsz3246 = zprinte("slti");
    }
    {
      uint64_t zuz348;
      zuz348 = zrREG(zuz346);
      uint64_t zuz349;
      {
        sbits zgsz3236;
        zgsz3236 = CONVERT_OF(sbits, fbits)(zuz345, UINT64_C(12) , true);
        zuz349 = zEXTS(zgsz3236);
      
      }
      bool zgaz383;
      {
        RECREATE(lbits)(&zghz3191);
        CONVERT_OF(lbits, fbits)(&zghz3191, zuz349, UINT64_C(32) , true);
        RECREATE(lbits)(&zghz3192);
        CONVERT_OF(lbits, fbits)(&zghz3192, zuz348, UINT64_C(32) , true);
        zgaz383 = zlt_bit(zghz3192, zghz3191);
      }
      unit zgsz3239;
      if (zgaz383) {
      uint64_t zgaz384;
      {
        RECREATE(sail_int)(&zghz3188);
        CONVERT_OF(sail_int, mach_int)(&zghz3188, INT64_C(32));
        RECREATE(lbits)(&zghz3189);
        CONVERT_OF(lbits, fbits)(&zghz3189, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3190);
        zextzz(&zghz3190, zghz3188, zghz3189);
        zgaz384 = CONVERT_OF(fbits, lbits)(zghz3190, true);
      }
      zgsz3239 = zwREG(zuz347, zgaz384);
    
      } else {
      uint64_t zgaz385;
      {
        RECREATE(sail_int)(&zghz3185);
        CONVERT_OF(sail_int, mach_int)(&zghz3185, INT64_C(32));
        RECREATE(lbits)(&zghz3186);
        CONVERT_OF(lbits, fbits)(&zghz3186, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3187);
        zextzz(&zghz3187, zghz3185, zghz3186);
        zgaz385 = CONVERT_OF(fbits, lbits)(zghz3187, true);
      }
      zgsz3239 = zwREG(zuz347, zgaz385);
    
      }
    
    
    
    }
    zcbz328 = zinc_PC(UNIT);
  
  
  
    goto finish_match_121;
  }
case_143: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_144;
    uint64_t zuz350;
    zuz350 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz351;
    zuz351 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz352;
    zuz352 = zmergez3var.zITYPE.ztup2;
    if ((zANDI != zmergez3var.zITYPE.ztup3)) goto case_144;
    {
      unit zgsz3262;
      zgsz3262 = zprinte("andi");
    }
    {
      __label__ case_146, case_147, finish_match_145;

      uint64_t zuz353;
      zuz353 = zrREG(zuz351);
      uint64_t zuz354;
      {
        sbits zgsz3248;
        zgsz3248 = CONVERT_OF(sbits, fbits)(zuz350, UINT64_C(12) , true);
        zuz354 = zEXTS(zgsz3248);
      
      }
      uint64_t zuz355;
      zuz355 = (zuz353 & zuz354);
      unit zgsz3249;
      {
        uint64_t zvz33;
        zvz33 = zuz355;
        uint64_t zgaz387;
        {
          RECREATE(sail_int)(&zghz3182);
          CONVERT_OF(sail_int, mach_int)(&zghz3182, INT64_C(32));
          RECREATE(lbits)(&zghz3183);
          CONVERT_OF(lbits, fbits)(&zghz3183, UINT64_C(0b1), UINT64_C(1) , true);
          RECREATE(lbits)(&zghz3184);
          zextzz(&zghz3184, zghz3182, zghz3183);
          zgaz387 = CONVERT_OF(fbits, lbits)(zghz3184, true);
        }
        bool zgsz3256;
        zgsz3256 = (zvz33 == zgaz387);
      
        if (!(zgsz3256)) {
      
        goto case_146;
        }
        uint64_t zgaz386;
        {
          RECREATE(sail_int)(&zghz3179);
          CONVERT_OF(sail_int, mach_int)(&zghz3179, INT64_C(32));
          RECREATE(lbits)(&zghz3180);
          CONVERT_OF(lbits, fbits)(&zghz3180, UINT64_C(0b1), UINT64_C(1) , true);
          RECREATE(lbits)(&zghz3181);
          zextzz(&zghz3181, zghz3179, zghz3180);
          zgaz386 = CONVERT_OF(fbits, lbits)(zghz3181, true);
        }
        zgsz3249 = zwREG(zuz352, zgaz386);
      
      
        goto finish_match_145;
      }
    case_146: ;
      {
        uint64_t zgaz388;
        {
          RECREATE(sail_int)(&zghz3176);
          CONVERT_OF(sail_int, mach_int)(&zghz3176, INT64_C(32));
          RECREATE(lbits)(&zghz3177);
          CONVERT_OF(lbits, fbits)(&zghz3177, UINT64_C(0b0), UINT64_C(1) , true);
          RECREATE(lbits)(&zghz3178);
          zextzz(&zghz3178, zghz3176, zghz3177);
          zgaz388 = CONVERT_OF(fbits, lbits)(zghz3178, true);
        }
        zgsz3249 = zwREG(zuz352, zgaz388);
      
        goto finish_match_145;
      }
    case_147: ;
      sail_match_failure("execute");
    finish_match_145: ;
      unit zgsz3261;
      zgsz3261 = zgsz3249;
    
    
    
    
    }
    zcbz328 = zinc_PC(UNIT);
  
  
  
    goto finish_match_121;
  }
case_144: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_148;
    uint64_t zuz356;
    zuz356 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz357;
    zuz357 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz358;
    zuz358 = zmergez3var.zITYPE.ztup2;
    if ((zORI != zmergez3var.zITYPE.ztup3)) goto case_148;
    {
      unit zgsz3278;
      zgsz3278 = zprinte("ori");
    }
    {
      __label__ case_150, case_151, finish_match_149;

      uint64_t zuz359;
      zuz359 = zrREG(zuz357);
      uint64_t zuz360;
      {
        sbits zgsz3264;
        zgsz3264 = CONVERT_OF(sbits, fbits)(zuz356, UINT64_C(12) , true);
        zuz360 = zEXTS(zgsz3264);
      
      }
      uint64_t zuz361;
      zuz361 = (zuz359 | zuz360);
      unit zgsz3265;
      {
        uint64_t zvz34;
        zvz34 = zuz361;
        uint64_t zgaz390;
        {
          RECREATE(sail_int)(&zghz3173);
          CONVERT_OF(sail_int, mach_int)(&zghz3173, INT64_C(32));
          RECREATE(lbits)(&zghz3174);
          CONVERT_OF(lbits, fbits)(&zghz3174, UINT64_C(0b1), UINT64_C(1) , true);
          RECREATE(lbits)(&zghz3175);
          zextzz(&zghz3175, zghz3173, zghz3174);
          zgaz390 = CONVERT_OF(fbits, lbits)(zghz3175, true);
        }
        bool zgsz3272;
        zgsz3272 = (zvz34 == zgaz390);
      
        if (!(zgsz3272)) {
      
        goto case_150;
        }
        uint64_t zgaz389;
        {
          RECREATE(sail_int)(&zghz3170);
          CONVERT_OF(sail_int, mach_int)(&zghz3170, INT64_C(32));
          RECREATE(lbits)(&zghz3171);
          CONVERT_OF(lbits, fbits)(&zghz3171, UINT64_C(0b1), UINT64_C(1) , true);
          RECREATE(lbits)(&zghz3172);
          zextzz(&zghz3172, zghz3170, zghz3171);
          zgaz389 = CONVERT_OF(fbits, lbits)(zghz3172, true);
        }
        zgsz3265 = zwREG(zuz358, zgaz389);
      
      
        goto finish_match_149;
      }
    case_150: ;
      {
        uint64_t zgaz391;
        {
          RECREATE(sail_int)(&zghz3167);
          CONVERT_OF(sail_int, mach_int)(&zghz3167, INT64_C(32));
          RECREATE(lbits)(&zghz3168);
          CONVERT_OF(lbits, fbits)(&zghz3168, UINT64_C(0b0), UINT64_C(1) , true);
          RECREATE(lbits)(&zghz3169);
          zextzz(&zghz3169, zghz3167, zghz3168);
          zgaz391 = CONVERT_OF(fbits, lbits)(zghz3169, true);
        }
        zgsz3265 = zwREG(zuz358, zgaz391);
      
        goto finish_match_149;
      }
    case_151: ;
      sail_match_failure("execute");
    finish_match_149: ;
      unit zgsz3277;
      zgsz3277 = zgsz3265;
    
    
    
    
    }
    zcbz328 = zinc_PC(UNIT);
  
  
  
    goto finish_match_121;
  }
case_148: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_152;
    uint64_t zuz362;
    zuz362 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz363;
    zuz363 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz364;
    zuz364 = zmergez3var.zITYPE.ztup2;
    if ((zXORI != zmergez3var.zITYPE.ztup3)) goto case_152;
    {
      unit zgsz3297;
      zgsz3297 = zprinte("xori");
    }
    {
      __label__ case_154, case_155, finish_match_153;

      uint64_t zuz365;
      zuz365 = zrREG(zuz363);
      uint64_t zuz366;
      {
        sbits zgsz3280;
        zgsz3280 = CONVERT_OF(sbits, fbits)(zuz362, UINT64_C(12) , true);
        zuz366 = zEXTS(zgsz3280);
      
      }
      uint64_t zuz367;
      {
        RECREATE(lbits)(&zghz3164);
        CONVERT_OF(lbits, fbits)(&zghz3164, zuz365, UINT64_C(32) , true);
        RECREATE(lbits)(&zghz3165);
        CONVERT_OF(lbits, fbits)(&zghz3165, zuz366, UINT64_C(32) , true);
        RECREATE(lbits)(&zghz3166);
        zxor_bitvector(&zghz3166, zghz3164, zghz3165);
        zuz367 = CONVERT_OF(fbits, lbits)(zghz3166, true);
      }
      unit zgsz3284;
      {
        uint64_t zvz35;
        zvz35 = zuz367;
        uint64_t zgaz393;
        {
          RECREATE(sail_int)(&zghz3161);
          CONVERT_OF(sail_int, mach_int)(&zghz3161, INT64_C(32));
          RECREATE(lbits)(&zghz3162);
          CONVERT_OF(lbits, fbits)(&zghz3162, UINT64_C(0b1), UINT64_C(1) , true);
          RECREATE(lbits)(&zghz3163);
          zextzz(&zghz3163, zghz3161, zghz3162);
          zgaz393 = CONVERT_OF(fbits, lbits)(zghz3163, true);
        }
        bool zgsz3291;
        zgsz3291 = (zvz35 == zgaz393);
      
        if (!(zgsz3291)) {
      
        goto case_154;
        }
        uint64_t zgaz392;
        {
          RECREATE(sail_int)(&zghz3158);
          CONVERT_OF(sail_int, mach_int)(&zghz3158, INT64_C(32));
          RECREATE(lbits)(&zghz3159);
          CONVERT_OF(lbits, fbits)(&zghz3159, UINT64_C(0b1), UINT64_C(1) , true);
          RECREATE(lbits)(&zghz3160);
          zextzz(&zghz3160, zghz3158, zghz3159);
          zgaz392 = CONVERT_OF(fbits, lbits)(zghz3160, true);
        }
        zgsz3284 = zwREG(zuz364, zgaz392);
      
      
        goto finish_match_153;
      }
    case_154: ;
      {
        uint64_t zgaz394;
        {
          RECREATE(sail_int)(&zghz3155);
          CONVERT_OF(sail_int, mach_int)(&zghz3155, INT64_C(32));
          RECREATE(lbits)(&zghz3156);
          CONVERT_OF(lbits, fbits)(&zghz3156, UINT64_C(0b0), UINT64_C(1) , true);
          RECREATE(lbits)(&zghz3157);
          zextzz(&zghz3157, zghz3155, zghz3156);
          zgaz394 = CONVERT_OF(fbits, lbits)(zghz3157, true);
        }
        zgsz3284 = zwREG(zuz364, zgaz394);
      
        goto finish_match_153;
      }
    case_155: ;
      sail_match_failure("execute");
    finish_match_153: ;
      unit zgsz3296;
      zgsz3296 = zgsz3284;
    
    
    
    
    }
    zcbz328 = zinc_PC(UNIT);
  
  
  
    goto finish_match_121;
  }
case_152: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_156;
    uint64_t zuz368;
    zuz368 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz369;
    zuz369 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz370;
    zuz370 = zmergez3var.zITYPE.ztup2;
    if ((zJALR != zmergez3var.zITYPE.ztup3)) goto case_156;
    {
      unit zgsz3303;
      zgsz3303 = zprinte("jalr");
    }
    {
      uint64_t zgaz395;
      {
        RECREATE(lbits)(&zghz3152);
        CONVERT_OF(lbits, fbits)(&zghz3152, zPC, UINT64_C(32) , true);
        RECREATE(sail_int)(&zghz3153);
        CONVERT_OF(sail_int, mach_int)(&zghz3153, INT64_C(4));
        RECREATE(lbits)(&zghz3154);
        add_bits_int(&zghz3154, zghz3152, zghz3153);
        zgaz395 = CONVERT_OF(fbits, lbits)(zghz3154, true);
      }
      unit zgsz3302;
      zgsz3302 = zwREG(zuz370, zgaz395);
    
    }
    uint64_t zuz371;
    zuz371 = zrREG(zuz369);
    uint64_t zuz372;
    {
      sbits zgsz3304;
      zgsz3304 = CONVERT_OF(sbits, fbits)(zuz368, UINT64_C(12) , true);
      zuz372 = zEXTS(zgsz3304);
    
    }
    uint64_t znewPC;
    znewPC = ((zuz371 + zuz372) & UINT64_C(0xFFFFFFFF));
    {
      {
        RECREATE(lbits)(&zghz3149);
        CONVERT_OF(lbits, fbits)(&zghz3149, znewPC, UINT64_C(32) , true);
        RECREATE(sail_int)(&zghz3150);
        CONVERT_OF(sail_int, mach_int)(&zghz3150, INT64_C(0));
        RECREATE(lbits)(&zghz3151);
        update_lbits(&zghz3151, zghz3149, zghz3150, UINT64_C(0));
        znewPC = CONVERT_OF(fbits, lbits)(zghz3151, true);
      }
      unit zgsz3310;
      zgsz3310 = UNIT;
    }
    {
      bool zgaz396;
      zgaz396 = zunprotected(zPC);
      unit zgsz3308;
      if (zgaz396) {
      bool zgaz397;
      zgaz397 = zprotected(znewPC);
      if (zgaz397) {  zgsz3308 = print_endline("You are not allowed to jump to protected memory section");  } else {
      zPC = znewPC;
      zgsz3308 = UNIT;
      }
    
      } else {
      {
        zPC = znewPC;
        unit zgsz3309;
        zgsz3309 = UNIT;
      }
      bool zgaz398;
      zgaz398 = zunprotected(znewPC);
      if (zgaz398) {  zgsz3308 = zreset_registers(UNIT);  } else {  zgsz3308 = UNIT;  }
    
      }
    
    }
    bool zgaz399;
    zgaz399 = (zPC == zstart_boundary);
    if (zgaz399) {  zcbz328 = zinc_PC(UNIT);  } else {  zcbz328 = UNIT;  }
  
  
  
  
  
  
  
    goto finish_match_121;
  }
case_156: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_157;
    uint64_t zuz373;
    zuz373 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz374;
    zuz374 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz375;
    zuz375 = zmergez3var.zITYPE.ztup2;
    if ((zLW != zmergez3var.zITYPE.ztup3)) goto case_157;
    {
      unit zgsz3316;
      zgsz3316 = zprinte("lw");
    }
    {
      uint64_t zuz376;
      zuz376 = zrREG(zuz374);
      uint64_t zuz377;
      {
        sbits zgsz3312;
        zgsz3312 = CONVERT_OF(sbits, fbits)(zuz373, UINT64_C(12) , true);
        zuz377 = zEXTS(zgsz3312);
      
      }
      uint64_t zaddr;
      zaddr = ((zuz376 + zuz377) & UINT64_C(0xFFFFFFFF));
      bool zgaz3102;
      {
        bool zgaz3101;
        {
          bool zgaz3100;
          zgaz3100 = zprotected(zaddr);
          bool zgsz3313;
          if (zgaz3100) {  zgsz3313 = zprotected(zPC);  } else {  zgsz3313 = false;  }
          zgaz3101 = zgsz3313;
        
        }
        bool zgsz3314;
        if (zgaz3101) {  zgsz3314 = true;  } else {  zgsz3314 = zunprotected(zaddr);  }
        zgaz3102 = zgsz3314;
      
      }
      unit zgsz3315;
      if (zgaz3102) {
      uint64_t zmem_val;
      zmem_val = zread_mem(zaddr);
      zgsz3315 = zwREG(zuz375, zmem_val);
    
      } else {  zgsz3315 = print_endline("You are not allowed to read from protected memory section");  }
    
    
    
    
    }
    zcbz328 = zinc_PC(UNIT);
  
  
  
    goto finish_match_121;
  }
case_157: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_158;
    uint64_t zuz378;
    zuz378 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz379;
    zuz379 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz380;
    zuz380 = zmergez3var.zITYPE.ztup2;
    if ((zSLLI != zmergez3var.zITYPE.ztup3)) goto case_158;
    {
      unit zgsz3326;
      zgsz3326 = zprinte("assert");
    }
    {
      uint64_t zuz381;
      zuz381 = zrREG(zuz379);
      uint64_t zuz382;
      {
        sbits zgsz3318;
        zgsz3318 = CONVERT_OF(sbits, fbits)(zuz378, UINT64_C(12) , true);
        zuz382 = zEXTS(zgsz3318);
      
      }
      bool zgaz3103;
      zgaz3103 = (zuz381 == zuz382);
      unit zgsz3319;
      if (zgaz3103) {
      uint64_t zgaz3104;
      {
        RECREATE(sail_int)(&zghz3146);
        CONVERT_OF(sail_int, mach_int)(&zghz3146, INT64_C(32));
        RECREATE(lbits)(&zghz3147);
        CONVERT_OF(lbits, fbits)(&zghz3147, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3148);
        zextzz(&zghz3148, zghz3146, zghz3147);
        zgaz3104 = CONVERT_OF(fbits, lbits)(zghz3148, true);
      }
      zgsz3319 = zwREG(zuz380, zgaz3104);
    
      } else {
      uint64_t zgaz3105;
      {
        RECREATE(sail_int)(&zghz3143);
        CONVERT_OF(sail_int, mach_int)(&zghz3143, INT64_C(32));
        RECREATE(lbits)(&zghz3144);
        CONVERT_OF(lbits, fbits)(&zghz3144, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3145);
        zextzz(&zghz3145, zghz3143, zghz3144);
        zgaz3105 = CONVERT_OF(fbits, lbits)(zghz3145, true);
      }
      zgsz3319 = zwREG(zuz380, zgaz3105);
    
      }
    
    
    
    }
    zcbz328 = zinc_PC(UNIT);
  
  
  
    goto finish_match_121;
  }
case_158: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_159;
    uint64_t zuz383;
    zuz383 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz384;
    zuz384 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz385;
    zuz385 = zmergez3var.zITYPE.ztup2;
    if ((zLB != zmergez3var.zITYPE.ztup3)) goto case_159;
    {
      unit zgsz3329;
      zgsz3329 = zprinte("begin enclave");
    }
    {
      zstart_boundary = zPC;
      unit zgsz3328;
      zgsz3328 = UNIT;
    }
    bool zcontinue_loop;
    zcontinue_loop = true;
    {
      __label__ while_160, wend_161;

      bool zgsz3334;
      unit zgsz3335;
    while_160: ;
      {
        __label__ case_163, case_164, finish_match_162;

        zgsz3334 = zcontinue_loop;
        if (!(zgsz3334)) goto wend_161;
        uint64_t zinstruction;
        {
          uint64_t zgaz3106;
          zgaz3106 = *(&zPC);
          zinstruction = zread_mem(zgaz3106);
        
        }
        struct zoption zdecoded_instruction;
        CREATE(zoption)(&zdecoded_instruction);
        zdecode(&zdecoded_instruction, zinstruction);
        {
          if (zdecoded_instruction.kind != Kind_zSomez3z5unionz0zzast) goto case_163;
          if (zdecoded_instruction.zSomez3z5unionz0zzast.kind != Kind_zITYPE) goto case_163;
          uint64_t zimmshadowz31;
          zimmshadowz31 = zdecoded_instruction.zSomez3z5unionz0zzast.zITYPE.ztup0;
          uint64_t zrs1shadowz33;
          zrs1shadowz33 = zdecoded_instruction.zSomez3z5unionz0zzast.zITYPE.ztup1;
          uint64_t zrdshadowz32;
          zrdshadowz32 = zdecoded_instruction.zSomez3z5unionz0zzast.zITYPE.ztup2;
          if ((zLH != zdecoded_instruction.zSomez3z5unionz0zzast.zITYPE.ztup3)) goto case_163;
          {
            zend_boundary = zPC;
            unit zgsz3331;
            zgsz3331 = UNIT;
          }
          zcontinue_loop = false;
          zgsz3335 = UNIT;
        
        
        
          goto finish_match_162;
        }
      case_163: ;
        {
          zgsz3335 = zinc_PC(UNIT);
          goto finish_match_162;
        }
      case_164: ;
        sail_match_failure("execute");
      finish_match_162: ;
        KILL(zoption)(&zdecoded_instruction);
      
        goto while_160;
      }
    wend_161: ;
      unit zgsz3336;
      zgsz3336 = UNIT;
    }
    {
      RECREATE(lbits)(&zghz3140);
      CONVERT_OF(lbits, fbits)(&zghz3140, zstart_boundary, UINT64_C(32) , true);
      RECREATE(sail_int)(&zghz3141);
      CONVERT_OF(sail_int, mach_int)(&zghz3141, INT64_C(4));
      RECREATE(lbits)(&zghz3142);
      add_bits_int(&zghz3142, zghz3140, zghz3141);
      zPC = CONVERT_OF(fbits, lbits)(zghz3142, true);
    }
    zcbz328 = UNIT;
  
  
  
  
    goto finish_match_121;
  }
case_159: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_165;
    uint64_t zuz386;
    zuz386 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz387;
    zuz387 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz388;
    zuz388 = zmergez3var.zITYPE.ztup2;
    if ((zLH != zmergez3var.zITYPE.ztup3)) goto case_165;
    {
      unit zgsz3343;
      zgsz3343 = zprinte("end enclave");
    }
    {
      zPC = zra;
      unit zgsz3342;
      zgsz3342 = UNIT;
    }
    {
      unit zgsz3341;
      zgsz3341 = zreset_registers(UNIT);
    }
    zcbz328 = zinc_PC(UNIT);
  
  
  
    goto finish_match_121;
  }
case_165: ;
  {
    if (zmergez3var.kind != Kind_zSTYPE) goto case_166;
    uint64_t zimm2;
    zimm2 = zmergez3var.zSTYPE.ztup0;
    uint64_t zuz389;
    zuz389 = zmergez3var.zSTYPE.ztup1;
    uint64_t zuz390;
    zuz390 = zmergez3var.zSTYPE.ztup2;
    uint64_t zimm1;
    zimm1 = zmergez3var.zSTYPE.ztup3;
    if ((zSW != zmergez3var.zSTYPE.ztup4)) goto case_166;
    {
      unit zgsz3349;
      zgsz3349 = zprinte("sw");
    }
    {
      uint64_t zuz391;
      zuz391 = zrREG(zuz390);
      uint64_t zuz392;
      {
        uint64_t zgaz3110;
        zgaz3110 = (zimm2 << 5) | zimm1;
        {
          sbits zgsz3345;
          zgsz3345 = CONVERT_OF(sbits, fbits)(zgaz3110, UINT64_C(12) , true);
          zuz392 = zEXTS(zgsz3345);
        
        }
      
      }
      uint64_t zuz393;
      zuz393 = ((zuz391 + zuz392) & UINT64_C(0xFFFFFFFF));
      bool zgaz3109;
      {
        bool zgaz3108;
        {
          bool zgaz3107;
          zgaz3107 = zprotected(zuz393);
          bool zgsz3346;
          if (zgaz3107) {  zgsz3346 = zprotected(zPC);  } else {  zgsz3346 = false;  }
          zgaz3108 = zgsz3346;
        
        }
        bool zgsz3347;
        if (zgaz3108) {  zgsz3347 = true;  } else {  zgsz3347 = zunprotected(zuz393);  }
        zgaz3109 = zgsz3347;
      
      }
      unit zgsz3348;
      if (zgaz3109) {
      uint64_t zuz394;
      zuz394 = zrREG(zuz389);
      zgsz3348 = zwrite_mem(zuz393, zuz394);
    
      } else {  zgsz3348 = print_endline("You are not allowed to write to protected memory section");  }
    
    
    
    
    }
    zcbz328 = zinc_PC(UNIT);
  
  
  
  
    goto finish_match_121;
  }
case_166: ;
  {
    if (zmergez3var.kind != Kind_zBTYPE) goto case_167;
    uint64_t zimm4;
    zimm4 = zmergez3var.zBTYPE.ztup0;
    uint64_t zuz395;
    zuz395 = zmergez3var.zBTYPE.ztup1;
    uint64_t zuz396;
    zuz396 = zmergez3var.zBTYPE.ztup2;
    uint64_t zuz397;
    zuz397 = zmergez3var.zBTYPE.ztup3;
    uint64_t zuz398;
    zuz398 = zmergez3var.zBTYPE.ztup4;
    uint64_t zimm3;
    zimm3 = zmergez3var.zBTYPE.ztup5;
    if ((zBEQ != zmergez3var.zBTYPE.ztup6)) goto case_167;
    {
      unit zgsz3351;
      zgsz3351 = zprinte("beq");
    }
    uint64_t zuz399;
    zuz399 = zrREG(zuz397);
    uint64_t zuz3100;
    zuz3100 = zrREG(zuz396);
    bool zgaz3111;
    zgaz3111 = (zuz399 == zuz3100);
    if (zgaz3111) {
    uint64_t zoffset;
    {
      uint64_t zgaz3114;
      {
        uint64_t zgaz3113;
        {
          uint64_t zgaz3112;
          zgaz3112 = (zuz395 << 4) | zuz398;
          zgaz3113 = (zimm3 << 10) | zgaz3112;
        
        }
        zgaz3114 = (zimm4 << 11) | zgaz3113;
      
      }
      {
        sbits zgsz3353;
        zgsz3353 = CONVERT_OF(sbits, fbits)(zgaz3114, UINT64_C(12) , true);
        zoffset = zEXTS(zgsz3353);
      
      }
    
    }
    zPC = ((zPC + zoffset) & UINT64_C(0xFFFFFFFF));
    zcbz328 = UNIT;
  
    } else {  zcbz328 = UNIT;  }
  
  
  
  
  
  
  
  
  
    goto finish_match_121;
  }
case_167: ;
  {
    if (zmergez3var.kind != Kind_zBTYPE) goto case_168;
    uint64_t zuz3101;
    zuz3101 = zmergez3var.zBTYPE.ztup0;
    uint64_t zuz3102;
    zuz3102 = zmergez3var.zBTYPE.ztup1;
    uint64_t zuz3103;
    zuz3103 = zmergez3var.zBTYPE.ztup2;
    uint64_t zuz3104;
    zuz3104 = zmergez3var.zBTYPE.ztup3;
    uint64_t zuz3105;
    zuz3105 = zmergez3var.zBTYPE.ztup4;
    uint64_t zuz3106;
    zuz3106 = zmergez3var.zBTYPE.ztup5;
    if ((zBNE != zmergez3var.zBTYPE.ztup6)) goto case_168;
    {
      unit zgsz3354;
      zgsz3354 = zprinte("bne");
    }
    uint64_t zuz3107;
    zuz3107 = zrREG(zuz3104);
    uint64_t zuz3108;
    zuz3108 = zrREG(zuz3103);
    bool zgaz3115;
    zgaz3115 = (zuz3107 != zuz3108);
    if (zgaz3115) {
    uint64_t zuz3109;
    {
      uint64_t zgaz3118;
      {
        uint64_t zgaz3117;
        {
          uint64_t zgaz3116;
          zgaz3116 = (zuz3102 << 4) | zuz3105;
          zgaz3117 = (zuz3106 << 10) | zgaz3116;
        
        }
        zgaz3118 = (zuz3101 << 11) | zgaz3117;
      
      }
      {
        sbits zgsz3356;
        zgsz3356 = CONVERT_OF(sbits, fbits)(zgaz3118, UINT64_C(12) , true);
        zuz3109 = zEXTS(zgsz3356);
      
      }
    
    }
    zPC = ((zPC + zuz3109) & UINT64_C(0xFFFFFFFF));
    zcbz328 = UNIT;
  
    } else {  zcbz328 = UNIT;  }
  
  
  
  
  
  
  
  
  
    goto finish_match_121;
  }
case_168: ;
  {
    if (zmergez3var.kind != Kind_zUTYPE) goto case_169;
    uint64_t zuz3110;
    zuz3110 = zmergez3var.zUTYPE.ztup0;
    uint64_t zuz3111;
    zuz3111 = zmergez3var.zUTYPE.ztup1;
    if ((zLUI != zmergez3var.zUTYPE.ztup2)) goto case_169;
    {
      unit zgsz3360;
      zgsz3360 = zprinte("lui");
    }
    {
      uint64_t zgaz3120;
      {
        uint64_t zgaz3119;
        {
          RECREATE(sail_int)(&zghz3138);
          CONVERT_OF(sail_int, mach_int)(&zghz3138, INT64_C(12));
          RECREATE(lbits)(&zghz3139);
          zeros(&zghz3139, zghz3138);
          zgaz3119 = CONVERT_OF(fbits, lbits)(zghz3139, true);
        }
        zgaz3120 = (zuz3110 << 12) | zgaz3119;
      
      }
      unit zgsz3359;
      zgsz3359 = zwREG(zuz3111, zgaz3120);
    
    }
    zcbz328 = zinc_PC(UNIT);
  
  
    goto finish_match_121;
  }
case_169: ;
  {
    if (zmergez3var.kind != Kind_zUTYPE) goto case_170;
    uint64_t zuz3112;
    zuz3112 = zmergez3var.zUTYPE.ztup0;
    uint64_t zuz3113;
    zuz3113 = zmergez3var.zUTYPE.ztup1;
    if ((zAUIPC != zmergez3var.zUTYPE.ztup2)) goto case_170;
    {
      unit zgsz3365;
      zgsz3365 = zprinte("auipc");
    }
    {
      uint64_t zuz3114;
      {
        uint64_t zgaz3122;
        {
          RECREATE(sail_int)(&zghz3136);
          CONVERT_OF(sail_int, mach_int)(&zghz3136, INT64_C(12));
          RECREATE(lbits)(&zghz3137);
          zeros(&zghz3137, zghz3136);
          zgaz3122 = CONVERT_OF(fbits, lbits)(zghz3137, true);
        }
        zuz3114 = (zuz3112 << 12) | zgaz3122;
      
      }
      uint64_t zgaz3121;
      zgaz3121 = ((zPC + zuz3114) & UINT64_C(0xFFFFFFFF));
      unit zgsz3364;
      zgsz3364 = zwREG(zuz3113, zgaz3121);
    
    
    }
    zcbz328 = zinc_PC(UNIT);
  
  
    goto finish_match_121;
  }
case_170: ;
  {
    if (zmergez3var.kind != Kind_zJTYPE) goto case_171;
    uint64_t zuz3115;
    zuz3115 = zmergez3var.zJTYPE.ztup0;
    uint64_t zuz3116;
    zuz3116 = zmergez3var.zJTYPE.ztup1;
    uint64_t zuz3117;
    zuz3117 = zmergez3var.zJTYPE.ztup2;
    uint64_t zuz3118;
    zuz3118 = zmergez3var.zJTYPE.ztup3;
    uint64_t zuz3119;
    zuz3119 = zmergez3var.zJTYPE.ztup4;
    if ((zJAL != zmergez3var.zJTYPE.ztup5)) goto case_171;
    {
      unit zgsz3374;
      zgsz3374 = zprinte("jal");
    }
    {
      uint64_t zgaz3123;
      {
        RECREATE(lbits)(&zghz3133);
        CONVERT_OF(lbits, fbits)(&zghz3133, zPC, UINT64_C(32) , true);
        RECREATE(sail_int)(&zghz3134);
        CONVERT_OF(sail_int, mach_int)(&zghz3134, INT64_C(4));
        RECREATE(lbits)(&zghz3135);
        add_bits_int(&zghz3135, zghz3133, zghz3134);
        zgaz3123 = CONVERT_OF(fbits, lbits)(zghz3135, true);
      }
      unit zgsz3373;
      zgsz3373 = zwREG(zuz3119, zgaz3123);
    
    }
    {
      uint64_t zuz3120;
      {
        uint64_t zgaz3129;
        {
          uint64_t zgaz3128;
          {
            uint64_t zgaz3127;
            zgaz3127 = (zuz3117 << 10) | zuz3116;
            zgaz3128 = (zuz3118 << 11) | zgaz3127;
          
          }
          zgaz3129 = (zuz3115 << 19) | zgaz3128;
        
        }
        {
          sbits zgsz3370;
          zgsz3370 = CONVERT_OF(sbits, fbits)(zgaz3129, UINT64_C(20) , true);
          zuz3120 = zEXTS(zgsz3370);
        
        }
      
      }
      uint64_t zuz3121;
      zuz3121 = ((zPC + zuz3120) & UINT64_C(0xFFFFFFFF));
      bool zgaz3124;
      zgaz3124 = zunprotected(zPC);
      unit zgsz3371;
      if (zgaz3124) {
      bool zgaz3125;
      zgaz3125 = zprotected(zuz3121);
      if (zgaz3125) {  zgsz3371 = print_endline("You are not allowed to jump to protected memory section");  } else {
      zPC = zuz3121;
      zgsz3371 = UNIT;
      }
    
      } else {
      {
        zPC = zuz3121;
        unit zgsz3372;
        zgsz3372 = UNIT;
      }
      bool zgaz3126;
      zgaz3126 = zunprotected(zuz3121);
      if (zgaz3126) {  zgsz3371 = zreset_registers(UNIT);  } else {  zgsz3371 = UNIT;  }
    
      }
    
    
    
    }
    bool zgaz3130;
    zgaz3130 = (zPC == zstart_boundary);
    if (zgaz3130) {  zcbz328 = zinc_PC(UNIT);  } else {  zcbz328 = UNIT;  }
  
  
  
  
  
  
    goto finish_match_121;
  }
case_171: ;
  sail_match_failure("execute");
finish_match_121: ;
end_function_172: ;
  return zcbz328;
end_block_exception_173: ;

  return UNIT;
}



void finish_zexecute(void)
{
  KILL(lbits)(&zghz3238);
  KILL(lbits)(&zghz3237);
  KILL(sail_int)(&zghz3236);
  KILL(lbits)(&zghz3235);
  KILL(lbits)(&zghz3234);
  KILL(sail_int)(&zghz3233);
  KILL(lbits)(&zghz3232);
  KILL(lbits)(&zghz3231);
  KILL(sail_int)(&zghz3230);
  KILL(lbits)(&zghz3229);
  KILL(lbits)(&zghz3228);
  KILL(sail_int)(&zghz3227);
  KILL(lbits)(&zghz3226);
  KILL(lbits)(&zghz3225);
  KILL(sail_int)(&zghz3224);
  KILL(lbits)(&zghz3223);
  KILL(lbits)(&zghz3222);
  KILL(sail_int)(&zghz3221);
  KILL(lbits)(&zghz3220);
  KILL(lbits)(&zghz3219);
  KILL(lbits)(&zghz3218);
  KILL(lbits)(&zghz3217);
  KILL(lbits)(&zghz3216);
  KILL(sail_int)(&zghz3215);
  KILL(lbits)(&zghz3214);
  KILL(lbits)(&zghz3213);
  KILL(sail_int)(&zghz3212);
  KILL(lbits)(&zghz3211);
  KILL(lbits)(&zghz3210);
  KILL(sail_int)(&zghz3209);
  KILL(lbits)(&zghz3208);
  KILL(lbits)(&zghz3207);
  KILL(lbits)(&zghz3206);
  KILL(sail_int)(&zghz3205);
  KILL(sail_int)(&zghz3204);
  KILL(sail_int)(&zghz3203);
  KILL(lbits)(&zghz3202);
  KILL(lbits)(&zghz3201);
  KILL(sail_int)(&zghz3200);
  KILL(sail_int)(&zghz3199);
  KILL(sail_int)(&zghz3198);
  KILL(lbits)(&zghz3197);
  KILL(lbits)(&zghz3196);
  KILL(sail_int)(&zghz3195);
  KILL(sail_int)(&zghz3194);
  KILL(sail_int)(&zghz3193);
  KILL(lbits)(&zghz3192);
  KILL(lbits)(&zghz3191);
  KILL(lbits)(&zghz3190);
  KILL(lbits)(&zghz3189);
  KILL(sail_int)(&zghz3188);
  KILL(lbits)(&zghz3187);
  KILL(lbits)(&zghz3186);
  KILL(sail_int)(&zghz3185);
  KILL(lbits)(&zghz3184);
  KILL(lbits)(&zghz3183);
  KILL(sail_int)(&zghz3182);
  KILL(lbits)(&zghz3181);
  KILL(lbits)(&zghz3180);
  KILL(sail_int)(&zghz3179);
  KILL(lbits)(&zghz3178);
  KILL(lbits)(&zghz3177);
  KILL(sail_int)(&zghz3176);
  KILL(lbits)(&zghz3175);
  KILL(lbits)(&zghz3174);
  KILL(sail_int)(&zghz3173);
  KILL(lbits)(&zghz3172);
  KILL(lbits)(&zghz3171);
  KILL(sail_int)(&zghz3170);
  KILL(lbits)(&zghz3169);
  KILL(lbits)(&zghz3168);
  KILL(sail_int)(&zghz3167);
  KILL(lbits)(&zghz3166);
  KILL(lbits)(&zghz3165);
  KILL(lbits)(&zghz3164);
  KILL(lbits)(&zghz3163);
  KILL(lbits)(&zghz3162);
  KILL(sail_int)(&zghz3161);
  KILL(lbits)(&zghz3160);
  KILL(lbits)(&zghz3159);
  KILL(sail_int)(&zghz3158);
  KILL(lbits)(&zghz3157);
  KILL(lbits)(&zghz3156);
  KILL(sail_int)(&zghz3155);
  KILL(lbits)(&zghz3154);
  KILL(sail_int)(&zghz3153);
  KILL(lbits)(&zghz3152);
  KILL(lbits)(&zghz3151);
  KILL(sail_int)(&zghz3150);
  KILL(lbits)(&zghz3149);
  KILL(lbits)(&zghz3148);
  KILL(lbits)(&zghz3147);
  KILL(sail_int)(&zghz3146);
  KILL(lbits)(&zghz3145);
  KILL(lbits)(&zghz3144);
  KILL(sail_int)(&zghz3143);
  KILL(lbits)(&zghz3142);
  KILL(sail_int)(&zghz3141);
  KILL(lbits)(&zghz3140);
  KILL(lbits)(&zghz3139);
  KILL(sail_int)(&zghz3138);
  KILL(lbits)(&zghz3137);
  KILL(sail_int)(&zghz3136);
  KILL(lbits)(&zghz3135);
  KILL(sail_int)(&zghz3134);
  KILL(lbits)(&zghz3133);
}

sail_int zghz3239;
lbits zghz3240;
lbits zghz3241;
sail_int zghz3242;
lbits zghz3243;
lbits zghz3244;
sail_int zghz3245;
lbits zghz3246;
lbits zghz3247;
sail_int zghz3248;
lbits zghz3249;
lbits zghz3250;

void startup_zdecode(void)
{
  CREATE(sail_int)(&zghz3239);
  CREATE(lbits)(&zghz3240);
  CREATE(lbits)(&zghz3241);
  CREATE(sail_int)(&zghz3242);
  CREATE(lbits)(&zghz3243);
  CREATE(lbits)(&zghz3244);
  CREATE(sail_int)(&zghz3245);
  CREATE(lbits)(&zghz3246);
  CREATE(lbits)(&zghz3247);
  CREATE(sail_int)(&zghz3248);
  CREATE(lbits)(&zghz3249);
  CREATE(lbits)(&zghz3250);
}


















void zdecode(struct zoption *zcbz329, uint64_t zmergez3var)
{
  __label__ case_176, case_177, case_178, case_179, case_180, case_181, case_182, case_183, case_184, case_185, case_186, case_187, case_188, case_189, case_190, case_191, case_192, case_193, case_194, case_195, case_196, case_197, case_198, case_199, case_200, finish_match_175, end_function_201, end_block_exception_202, end_function_219;

  struct zoption zgsz3376;
  CREATE(zoption)(&zgsz3376);
  {
    uint64_t zv__0;
    zv__0 = zmergez3var;
    bool zgaz3134;
    {
      uint64_t zgaz3132;
      zgaz3132 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__0 >> INT64_C(25)));
      zgaz3134 = (zgaz3132 == UINT64_C(0b0000000));
    
    }
    bool zgsz3377;
    if (zgaz3134) {
    uint64_t zgaz3133;
    zgaz3133 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__0 >> INT64_C(0)));
    zgsz3377 = (zgaz3133 == UINT64_C(0b0110011));
  
    } else {  zgsz3377 = false;  }
    bool zgsz3379;
    zgsz3379 = zgsz3377;
  
    if (!(zgsz3379)) {
  
    goto case_176;
    }
    uint64_t zrs2;
    zrs2 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(20)));
    uint64_t zrs1;
    zrs1 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(15)));
    uint64_t zrd;
    zrd = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(7)));
    struct zast zgaz3131;
    CREATE(zast)(&zgaz3131);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3378;
      zgsz3378.ztup0 = zrs2;
      zgsz3378.ztup1 = zrs1;
      zgsz3378.ztup2 = zrd;
      zgsz3378.ztup3 = zADD;
      zRTYPE(&zgaz3131, zgsz3378);
    
    }
    {
      struct zast zgsz3501;
      CREATE(zast)(&zgsz3501);
      COPY(zast)(&zgsz3501, zgaz3131);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3501);
      KILL(zast)(&zgsz3501);
    }
    KILL(zast)(&zgaz3131);
  
  
  
  
    goto finish_match_175;
  }
case_176: ;
  {
    uint64_t zv__3;
    zv__3 = zmergez3var;
    bool zgaz3138;
    {
      uint64_t zgaz3136;
      zgaz3136 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__3 >> INT64_C(25)));
      zgaz3138 = (zgaz3136 == UINT64_C(0b0000000));
    
    }
    bool zgsz3380;
    if (zgaz3138) {
    uint64_t zgaz3137;
    zgaz3137 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__3 >> INT64_C(0)));
    zgsz3380 = (zgaz3137 == UINT64_C(0b0110011));
  
    } else {  zgsz3380 = false;  }
    bool zgsz3382;
    zgsz3382 = zgsz3380;
  
    if (!(zgsz3382)) {
  
    goto case_177;
    }
    uint64_t zuz3122;
    zuz3122 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(20)));
    uint64_t zuz3123;
    zuz3123 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(15)));
    uint64_t zuz3124;
    zuz3124 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(7)));
    struct zast zgaz3135;
    CREATE(zast)(&zgaz3135);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3381;
      zgsz3381.ztup0 = zuz3122;
      zgsz3381.ztup1 = zuz3123;
      zgsz3381.ztup2 = zuz3124;
      zgsz3381.ztup3 = zAND;
      zRTYPE(&zgaz3135, zgsz3381);
    
    }
    {
      struct zast zgsz3502;
      CREATE(zast)(&zgsz3502);
      COPY(zast)(&zgsz3502, zgaz3135);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3502);
      KILL(zast)(&zgsz3502);
    }
    KILL(zast)(&zgaz3135);
  
  
  
  
    goto finish_match_175;
  }
case_177: ;
  {
    uint64_t zv__6;
    zv__6 = zmergez3var;
    bool zgaz3142;
    {
      uint64_t zgaz3140;
      zgaz3140 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__6 >> INT64_C(25)));
      zgaz3142 = (zgaz3140 == UINT64_C(0b0000000));
    
    }
    bool zgsz3383;
    if (zgaz3142) {
    uint64_t zgaz3141;
    zgaz3141 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__6 >> INT64_C(0)));
    zgsz3383 = (zgaz3141 == UINT64_C(0b0110011));
  
    } else {  zgsz3383 = false;  }
    bool zgsz3385;
    zgsz3385 = zgsz3383;
  
    if (!(zgsz3385)) {
  
    goto case_178;
    }
    uint64_t zuz3125;
    zuz3125 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(20)));
    uint64_t zuz3126;
    zuz3126 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(15)));
    uint64_t zuz3127;
    zuz3127 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(7)));
    struct zast zgaz3139;
    CREATE(zast)(&zgaz3139);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3384;
      zgsz3384.ztup0 = zuz3125;
      zgsz3384.ztup1 = zuz3126;
      zgsz3384.ztup2 = zuz3127;
      zgsz3384.ztup3 = zOR;
      zRTYPE(&zgaz3139, zgsz3384);
    
    }
    {
      struct zast zgsz3503;
      CREATE(zast)(&zgsz3503);
      COPY(zast)(&zgsz3503, zgaz3139);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3503);
      KILL(zast)(&zgsz3503);
    }
    KILL(zast)(&zgaz3139);
  
  
  
  
    goto finish_match_175;
  }
case_178: ;
  {
    uint64_t zv__9;
    zv__9 = zmergez3var;
    bool zgaz3146;
    {
      uint64_t zgaz3144;
      zgaz3144 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__9 >> INT64_C(25)));
      zgaz3146 = (zgaz3144 == UINT64_C(0b0000000));
    
    }
    bool zgsz3386;
    if (zgaz3146) {
    uint64_t zgaz3145;
    zgaz3145 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__9 >> INT64_C(0)));
    zgsz3386 = (zgaz3145 == UINT64_C(0b0110011));
  
    } else {  zgsz3386 = false;  }
    bool zgsz3388;
    zgsz3388 = zgsz3386;
  
    if (!(zgsz3388)) {
  
    goto case_179;
    }
    uint64_t zuz3128;
    zuz3128 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(20)));
    uint64_t zuz3129;
    zuz3129 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(15)));
    uint64_t zuz3130;
    zuz3130 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(7)));
    struct zast zgaz3143;
    CREATE(zast)(&zgaz3143);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3387;
      zgsz3387.ztup0 = zuz3128;
      zgsz3387.ztup1 = zuz3129;
      zgsz3387.ztup2 = zuz3130;
      zgsz3387.ztup3 = zXOR;
      zRTYPE(&zgaz3143, zgsz3387);
    
    }
    {
      struct zast zgsz3504;
      CREATE(zast)(&zgsz3504);
      COPY(zast)(&zgsz3504, zgaz3143);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3504);
      KILL(zast)(&zgsz3504);
    }
    KILL(zast)(&zgaz3143);
  
  
  
  
    goto finish_match_175;
  }
case_179: ;
  {
    uint64_t zv__12;
    zv__12 = zmergez3var;
    bool zgaz3150;
    {
      uint64_t zgaz3148;
      zgaz3148 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__12 >> INT64_C(25)));
      zgaz3150 = (zgaz3148 == UINT64_C(0b0000001));
    
    }
    bool zgsz3389;
    if (zgaz3150) {
    uint64_t zgaz3149;
    zgaz3149 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__12 >> INT64_C(0)));
    zgsz3389 = (zgaz3149 == UINT64_C(0b0110011));
  
    } else {  zgsz3389 = false;  }
    bool zgsz3391;
    zgsz3391 = zgsz3389;
  
    if (!(zgsz3391)) {
  
    goto case_180;
    }
    uint64_t zuz3131;
    zuz3131 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(20)));
    uint64_t zuz3132;
    zuz3132 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(15)));
    uint64_t zuz3133;
    zuz3133 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(7)));
    struct zast zgaz3147;
    CREATE(zast)(&zgaz3147);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3390;
      zgsz3390.ztup0 = zuz3131;
      zgsz3390.ztup1 = zuz3132;
      zgsz3390.ztup2 = zuz3133;
      zgsz3390.ztup3 = zMUL;
      zRTYPE(&zgaz3147, zgsz3390);
    
    }
    {
      struct zast zgsz3505;
      CREATE(zast)(&zgsz3505);
      COPY(zast)(&zgsz3505, zgaz3147);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3505);
      KILL(zast)(&zgsz3505);
    }
    KILL(zast)(&zgaz3147);
  
  
  
  
    goto finish_match_175;
  }
case_180: ;
  {
    uint64_t zv__15;
    zv__15 = zmergez3var;
    bool zgaz3154;
    {
      uint64_t zgaz3152;
      zgaz3152 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__15 >> INT64_C(25)));
      zgaz3154 = (zgaz3152 == UINT64_C(0b0000001));
    
    }
    bool zgsz3392;
    if (zgaz3154) {
    uint64_t zgaz3153;
    zgaz3153 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__15 >> INT64_C(0)));
    zgsz3392 = (zgaz3153 == UINT64_C(0b0110011));
  
    } else {  zgsz3392 = false;  }
    bool zgsz3394;
    zgsz3394 = zgsz3392;
  
    if (!(zgsz3394)) {
  
    goto case_181;
    }
    uint64_t zuz3134;
    zuz3134 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(20)));
    uint64_t zuz3135;
    zuz3135 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(15)));
    uint64_t zuz3136;
    zuz3136 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(7)));
    struct zast zgaz3151;
    CREATE(zast)(&zgaz3151);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3393;
      zgsz3393.ztup0 = zuz3134;
      zgsz3393.ztup1 = zuz3135;
      zgsz3393.ztup2 = zuz3136;
      zgsz3393.ztup3 = zDIV;
      zRTYPE(&zgaz3151, zgsz3393);
    
    }
    {
      struct zast zgsz3506;
      CREATE(zast)(&zgsz3506);
      COPY(zast)(&zgsz3506, zgaz3151);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3506);
      KILL(zast)(&zgsz3506);
    }
    KILL(zast)(&zgaz3151);
  
  
  
  
    goto finish_match_175;
  }
case_181: ;
  {
    uint64_t zv__18;
    zv__18 = zmergez3var;
    bool zgaz3158;
    {
      uint64_t zgaz3156;
      zgaz3156 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__18 >> INT64_C(25)));
      zgaz3158 = (zgaz3156 == UINT64_C(0b0000001));
    
    }
    bool zgsz3395;
    if (zgaz3158) {
    uint64_t zgaz3157;
    zgaz3157 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__18 >> INT64_C(0)));
    zgsz3395 = (zgaz3157 == UINT64_C(0b0110011));
  
    } else {  zgsz3395 = false;  }
    bool zgsz3397;
    zgsz3397 = zgsz3395;
  
    if (!(zgsz3397)) {
  
    goto case_182;
    }
    uint64_t zuz3137;
    zuz3137 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(20)));
    uint64_t zuz3138;
    zuz3138 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(15)));
    uint64_t zuz3139;
    zuz3139 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(7)));
    struct zast zgaz3155;
    CREATE(zast)(&zgaz3155);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3396;
      zgsz3396.ztup0 = zuz3137;
      zgsz3396.ztup1 = zuz3138;
      zgsz3396.ztup2 = zuz3139;
      zgsz3396.ztup3 = zREM;
      zRTYPE(&zgaz3155, zgsz3396);
    
    }
    {
      struct zast zgsz3507;
      CREATE(zast)(&zgsz3507);
      COPY(zast)(&zgsz3507, zgaz3155);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3507);
      KILL(zast)(&zgsz3507);
    }
    KILL(zast)(&zgaz3155);
  
  
  
  
    goto finish_match_175;
  }
case_182: ;
  {
    uint64_t zv__21;
    zv__21 = zmergez3var;
    uint64_t zgaz3160;
    zgaz3160 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__21 >> INT64_C(0)));
    bool zgsz3399;
    zgsz3399 = (zgaz3160 == UINT64_C(0b0010011));
  
    if (!(zgsz3399)) {
  
    goto case_183;
    }
    uint64_t zimm;
    zimm = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__21 >> INT64_C(20)));
    uint64_t zuz3140;
    zuz3140 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__21 >> INT64_C(15)));
    uint64_t zuz3141;
    zuz3141 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__21 >> INT64_C(7)));
    uint64_t zimmshadowz34;
    zimmshadowz34 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__21 >> INT64_C(20)));
    struct zast zgaz3159;
    CREATE(zast)(&zgaz3159);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3398;
      zgsz3398.ztup0 = zimmshadowz34;
      zgsz3398.ztup1 = zuz3140;
      zgsz3398.ztup2 = zuz3141;
      zgsz3398.ztup3 = zADDI;
      zITYPE(&zgaz3159, zgsz3398);
    
    }
    {
      struct zast zgsz3508;
      CREATE(zast)(&zgsz3508);
      COPY(zast)(&zgsz3508, zgaz3159);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3508);
      KILL(zast)(&zgsz3508);
    }
    KILL(zast)(&zgaz3159);
  
  
  
  
  
    goto finish_match_175;
  }
case_183: ;
  {
    uint64_t zv__23;
    zv__23 = zmergez3var;
    uint64_t zgaz3162;
    zgaz3162 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__23 >> INT64_C(0)));
    bool zgsz3401;
    zgsz3401 = (zgaz3162 == UINT64_C(0b0010011));
  
    if (!(zgsz3401)) {
  
    goto case_184;
    }
    uint64_t zuz3142;
    zuz3142 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__23 >> INT64_C(20)));
    uint64_t zuz3143;
    zuz3143 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__23 >> INT64_C(15)));
    uint64_t zuz3144;
    zuz3144 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__23 >> INT64_C(7)));
    uint64_t zimmshadowz35;
    zimmshadowz35 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__23 >> INT64_C(20)));
    struct zast zgaz3161;
    CREATE(zast)(&zgaz3161);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3400;
      zgsz3400.ztup0 = zimmshadowz35;
      zgsz3400.ztup1 = zuz3143;
      zgsz3400.ztup2 = zuz3144;
      zgsz3400.ztup3 = zSLTI;
      zITYPE(&zgaz3161, zgsz3400);
    
    }
    {
      struct zast zgsz3509;
      CREATE(zast)(&zgsz3509);
      COPY(zast)(&zgsz3509, zgaz3161);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3509);
      KILL(zast)(&zgsz3509);
    }
    KILL(zast)(&zgaz3161);
  
  
  
  
  
    goto finish_match_175;
  }
case_184: ;
  {
    uint64_t zv__25;
    zv__25 = zmergez3var;
    uint64_t zgaz3164;
    zgaz3164 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__25 >> INT64_C(0)));
    bool zgsz3403;
    zgsz3403 = (zgaz3164 == UINT64_C(0b0010011));
  
    if (!(zgsz3403)) {
  
    goto case_185;
    }
    uint64_t zuz3145;
    zuz3145 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__25 >> INT64_C(20)));
    uint64_t zuz3146;
    zuz3146 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__25 >> INT64_C(15)));
    uint64_t zuz3147;
    zuz3147 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__25 >> INT64_C(7)));
    uint64_t zimmshadowz36;
    zimmshadowz36 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__25 >> INT64_C(20)));
    struct zast zgaz3163;
    CREATE(zast)(&zgaz3163);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3402;
      zgsz3402.ztup0 = zimmshadowz36;
      zgsz3402.ztup1 = zuz3146;
      zgsz3402.ztup2 = zuz3147;
      zgsz3402.ztup3 = zANDI;
      zITYPE(&zgaz3163, zgsz3402);
    
    }
    {
      struct zast zgsz3510;
      CREATE(zast)(&zgsz3510);
      COPY(zast)(&zgsz3510, zgaz3163);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3510);
      KILL(zast)(&zgsz3510);
    }
    KILL(zast)(&zgaz3163);
  
  
  
  
  
    goto finish_match_175;
  }
case_185: ;
  {
    uint64_t zv__27;
    zv__27 = zmergez3var;
    uint64_t zgaz3166;
    zgaz3166 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__27 >> INT64_C(0)));
    bool zgsz3405;
    zgsz3405 = (zgaz3166 == UINT64_C(0b0010011));
  
    if (!(zgsz3405)) {
  
    goto case_186;
    }
    uint64_t zuz3148;
    zuz3148 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__27 >> INT64_C(20)));
    uint64_t zuz3149;
    zuz3149 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__27 >> INT64_C(15)));
    uint64_t zuz3150;
    zuz3150 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__27 >> INT64_C(7)));
    uint64_t zimmshadowz37;
    zimmshadowz37 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__27 >> INT64_C(20)));
    struct zast zgaz3165;
    CREATE(zast)(&zgaz3165);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3404;
      zgsz3404.ztup0 = zimmshadowz37;
      zgsz3404.ztup1 = zuz3149;
      zgsz3404.ztup2 = zuz3150;
      zgsz3404.ztup3 = zORI;
      zITYPE(&zgaz3165, zgsz3404);
    
    }
    {
      struct zast zgsz3511;
      CREATE(zast)(&zgsz3511);
      COPY(zast)(&zgsz3511, zgaz3165);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3511);
      KILL(zast)(&zgsz3511);
    }
    KILL(zast)(&zgaz3165);
  
  
  
  
  
    goto finish_match_175;
  }
case_186: ;
  {
    uint64_t zv__29;
    zv__29 = zmergez3var;
    uint64_t zgaz3168;
    zgaz3168 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__29 >> INT64_C(0)));
    bool zgsz3407;
    zgsz3407 = (zgaz3168 == UINT64_C(0b0010011));
  
    if (!(zgsz3407)) {
  
    goto case_187;
    }
    uint64_t zuz3151;
    zuz3151 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__29 >> INT64_C(20)));
    uint64_t zuz3152;
    zuz3152 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__29 >> INT64_C(15)));
    uint64_t zuz3153;
    zuz3153 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__29 >> INT64_C(7)));
    uint64_t zimmshadowz38;
    zimmshadowz38 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__29 >> INT64_C(20)));
    struct zast zgaz3167;
    CREATE(zast)(&zgaz3167);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3406;
      zgsz3406.ztup0 = zimmshadowz38;
      zgsz3406.ztup1 = zuz3152;
      zgsz3406.ztup2 = zuz3153;
      zgsz3406.ztup3 = zXORI;
      zITYPE(&zgaz3167, zgsz3406);
    
    }
    {
      struct zast zgsz3512;
      CREATE(zast)(&zgsz3512);
      COPY(zast)(&zgsz3512, zgaz3167);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3512);
      KILL(zast)(&zgsz3512);
    }
    KILL(zast)(&zgaz3167);
  
  
  
  
  
    goto finish_match_175;
  }
case_187: ;
  {
    uint64_t zv__31;
    zv__31 = zmergez3var;
    uint64_t zgaz3170;
    zgaz3170 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__31 >> INT64_C(0)));
    bool zgsz3409;
    zgsz3409 = (zgaz3170 == UINT64_C(0b1100111));
  
    if (!(zgsz3409)) {
  
    goto case_188;
    }
    uint64_t zuz3154;
    zuz3154 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__31 >> INT64_C(20)));
    uint64_t zuz3155;
    zuz3155 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__31 >> INT64_C(15)));
    uint64_t zuz3156;
    zuz3156 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__31 >> INT64_C(7)));
    uint64_t zimmshadowz39;
    zimmshadowz39 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__31 >> INT64_C(20)));
    struct zast zgaz3169;
    CREATE(zast)(&zgaz3169);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3408;
      zgsz3408.ztup0 = zimmshadowz39;
      zgsz3408.ztup1 = zuz3155;
      zgsz3408.ztup2 = zuz3156;
      zgsz3408.ztup3 = zJALR;
      zITYPE(&zgaz3169, zgsz3408);
    
    }
    {
      struct zast zgsz3513;
      CREATE(zast)(&zgsz3513);
      COPY(zast)(&zgsz3513, zgaz3169);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3513);
      KILL(zast)(&zgsz3513);
    }
    KILL(zast)(&zgaz3169);
  
  
  
  
  
    goto finish_match_175;
  }
case_188: ;
  {
    uint64_t zv__33;
    zv__33 = zmergez3var;
    uint64_t zgaz3172;
    zgaz3172 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__33 >> INT64_C(0)));
    bool zgsz3411;
    zgsz3411 = (zgaz3172 == UINT64_C(0b0000011));
  
    if (!(zgsz3411)) {
  
    goto case_189;
    }
    uint64_t zuz3157;
    zuz3157 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__33 >> INT64_C(20)));
    uint64_t zuz3158;
    zuz3158 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__33 >> INT64_C(15)));
    uint64_t zuz3159;
    zuz3159 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__33 >> INT64_C(7)));
    uint64_t zimmshadowz310;
    zimmshadowz310 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__33 >> INT64_C(20)));
    struct zast zgaz3171;
    CREATE(zast)(&zgaz3171);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3410;
      zgsz3410.ztup0 = zimmshadowz310;
      zgsz3410.ztup1 = zuz3158;
      zgsz3410.ztup2 = zuz3159;
      zgsz3410.ztup3 = zLW;
      zITYPE(&zgaz3171, zgsz3410);
    
    }
    {
      struct zast zgsz3514;
      CREATE(zast)(&zgsz3514);
      COPY(zast)(&zgsz3514, zgaz3171);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3514);
      KILL(zast)(&zgsz3514);
    }
    KILL(zast)(&zgaz3171);
  
  
  
  
  
    goto finish_match_175;
  }
case_189: ;
  {
    uint64_t zv__35;
    zv__35 = zmergez3var;
    uint64_t zgaz3174;
    zgaz3174 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__35 >> INT64_C(0)));
    bool zgsz3413;
    zgsz3413 = (zgaz3174 == UINT64_C(0b0010011));
  
    if (!(zgsz3413)) {
  
    goto case_190;
    }
    uint64_t zuz3160;
    zuz3160 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__35 >> INT64_C(20)));
    uint64_t zuz3161;
    zuz3161 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__35 >> INT64_C(15)));
    uint64_t zuz3162;
    zuz3162 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__35 >> INT64_C(7)));
    uint64_t zimmshadowz311;
    zimmshadowz311 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__35 >> INT64_C(20)));
    struct zast zgaz3173;
    CREATE(zast)(&zgaz3173);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3412;
      zgsz3412.ztup0 = zimmshadowz311;
      zgsz3412.ztup1 = zuz3161;
      zgsz3412.ztup2 = zuz3162;
      zgsz3412.ztup3 = zSLLI;
      zITYPE(&zgaz3173, zgsz3412);
    
    }
    {
      struct zast zgsz3515;
      CREATE(zast)(&zgsz3515);
      COPY(zast)(&zgsz3515, zgaz3173);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3515);
      KILL(zast)(&zgsz3515);
    }
    KILL(zast)(&zgaz3173);
  
  
  
  
  
    goto finish_match_175;
  }
case_190: ;
  {
    uint64_t zv__37;
    zv__37 = zmergez3var;
    bool zgaz3181;
    {
      uint64_t zgaz3179;
      zgaz3179 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__37 >> INT64_C(15)));
      zgaz3181 = (zgaz3179 == UINT64_C(0b00000));
    
    }
    bool zgsz3414;
    if (zgaz3181) {
    uint64_t zgaz3180;
    zgaz3180 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__37 >> INT64_C(0)));
    zgsz3414 = (zgaz3180 == UINT64_C(0x003));
  
    } else {  zgsz3414 = false;  }
    bool zgsz3422;
    zgsz3422 = zgsz3414;
  
    if (!(zgsz3422)) {
  
    goto case_191;
    }
    uint64_t zuz3163;
    zuz3163 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__37 >> INT64_C(20)));
    uint64_t zimmshadowz312;
    zimmshadowz312 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__37 >> INT64_C(20)));
    struct zast zgaz3178;
    CREATE(zast)(&zgaz3178);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgaz3177;
      {
        uint64_t zgaz3175;
        {
          RECREATE(sail_int)(&zghz3248);
          CONVERT_OF(sail_int, mach_int)(&zghz3248, INT64_C(5));
          RECREATE(lbits)(&zghz3249);
          CONVERT_OF(lbits, fbits)(&zghz3249, UINT64_C(0b0), UINT64_C(1) , true);
          RECREATE(lbits)(&zghz3250);
          zextzz(&zghz3250, zghz3248, zghz3249);
          zgaz3175 = CONVERT_OF(fbits, lbits)(zghz3250, true);
        }
        uint64_t zgaz3176;
        {
          RECREATE(sail_int)(&zghz3245);
          CONVERT_OF(sail_int, mach_int)(&zghz3245, INT64_C(5));
          RECREATE(lbits)(&zghz3246);
          CONVERT_OF(lbits, fbits)(&zghz3246, UINT64_C(0b0), UINT64_C(1) , true);
          RECREATE(lbits)(&zghz3247);
          zextzz(&zghz3247, zghz3245, zghz3246);
          zgaz3176 = CONVERT_OF(fbits, lbits)(zghz3247, true);
        }
        zgaz3177.ztup0 = zimmshadowz312;
        zgaz3177.ztup1 = zgaz3175;
        zgaz3177.ztup2 = zgaz3176;
        zgaz3177.ztup3 = zLB;
      
      
      }
      zITYPE(&zgaz3178, zgaz3177);
    
    }
    {
      struct zast zgsz3516;
      CREATE(zast)(&zgsz3516);
      COPY(zast)(&zgsz3516, zgaz3178);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3516);
      KILL(zast)(&zgsz3516);
    }
    KILL(zast)(&zgaz3178);
  
  
  
    goto finish_match_175;
  }
case_191: ;
  {
    uint64_t zv__41;
    zv__41 = zmergez3var;
    bool zgaz3188;
    {
      uint64_t zgaz3186;
      zgaz3186 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__41 >> INT64_C(15)));
      zgaz3188 = (zgaz3186 == UINT64_C(0b00000));
    
    }
    bool zgsz3423;
    if (zgaz3188) {
    uint64_t zgaz3187;
    zgaz3187 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__41 >> INT64_C(0)));
    zgsz3423 = (zgaz3187 == UINT64_C(0x003));
  
    } else {  zgsz3423 = false;  }
    bool zgsz3431;
    zgsz3431 = zgsz3423;
  
    if (!(zgsz3431)) {
  
    goto case_192;
    }
    uint64_t zuz3164;
    zuz3164 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__41 >> INT64_C(20)));
    uint64_t zimmshadowz313;
    zimmshadowz313 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__41 >> INT64_C(20)));
    struct zast zgaz3185;
    CREATE(zast)(&zgaz3185);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgaz3184;
      {
        uint64_t zgaz3182;
        {
          RECREATE(sail_int)(&zghz3242);
          CONVERT_OF(sail_int, mach_int)(&zghz3242, INT64_C(5));
          RECREATE(lbits)(&zghz3243);
          CONVERT_OF(lbits, fbits)(&zghz3243, UINT64_C(0b0), UINT64_C(1) , true);
          RECREATE(lbits)(&zghz3244);
          zextzz(&zghz3244, zghz3242, zghz3243);
          zgaz3182 = CONVERT_OF(fbits, lbits)(zghz3244, true);
        }
        uint64_t zgaz3183;
        {
          RECREATE(sail_int)(&zghz3239);
          CONVERT_OF(sail_int, mach_int)(&zghz3239, INT64_C(5));
          RECREATE(lbits)(&zghz3240);
          CONVERT_OF(lbits, fbits)(&zghz3240, UINT64_C(0b0), UINT64_C(1) , true);
          RECREATE(lbits)(&zghz3241);
          zextzz(&zghz3241, zghz3239, zghz3240);
          zgaz3183 = CONVERT_OF(fbits, lbits)(zghz3241, true);
        }
        zgaz3184.ztup0 = zimmshadowz313;
        zgaz3184.ztup1 = zgaz3182;
        zgaz3184.ztup2 = zgaz3183;
        zgaz3184.ztup3 = zLH;
      
      
      }
      zITYPE(&zgaz3185, zgaz3184);
    
    }
    {
      struct zast zgsz3517;
      CREATE(zast)(&zgsz3517);
      COPY(zast)(&zgsz3517, zgaz3185);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3517);
      KILL(zast)(&zgsz3517);
    }
    KILL(zast)(&zgaz3185);
  
  
  
    goto finish_match_175;
  }
case_192: ;
  {
    uint64_t zv__45;
    zv__45 = zmergez3var;
    uint64_t zgaz3190;
    zgaz3190 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__45 >> INT64_C(0)));
    bool zgsz3433;
    zgsz3433 = (zgaz3190 == UINT64_C(0b0100011));
  
    if (!(zgsz3433)) {
  
    goto case_193;
    }
    uint64_t zimm2;
    zimm2 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__45 >> INT64_C(25)));
    uint64_t zuz3165;
    zuz3165 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__45 >> INT64_C(20)));
    uint64_t zuz3166;
    zuz3166 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__45 >> INT64_C(15)));
    uint64_t zimm2shadowz314;
    zimm2shadowz314 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__45 >> INT64_C(25)));
    uint64_t zimm1;
    zimm1 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__45 >> INT64_C(7)));
    struct zast zgaz3189;
    CREATE(zast)(&zgaz3189);
    {
      struct ztuple_z8z5bv7zCz0z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzsopz9 zgsz3432;
      zgsz3432.ztup0 = zimm2shadowz314;
      zgsz3432.ztup1 = zuz3165;
      zgsz3432.ztup2 = zuz3166;
      zgsz3432.ztup3 = zimm1;
      zgsz3432.ztup4 = zSW;
      zSTYPE(&zgaz3189, zgsz3432);
    
    }
    {
      struct zast zgsz3518;
      CREATE(zast)(&zgsz3518);
      COPY(zast)(&zgsz3518, zgaz3189);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3518);
      KILL(zast)(&zgsz3518);
    }
    KILL(zast)(&zgaz3189);
  
  
  
  
  
  
    goto finish_match_175;
  }
case_193: ;
  {
    uint64_t zv__47;
    zv__47 = zmergez3var;
    uint64_t zgaz3192;
    zgaz3192 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__47 >> INT64_C(0)));
    bool zgsz3435;
    zgsz3435 = (zgaz3192 == UINT64_C(0b1100011));
  
    if (!(zgsz3435)) {
  
    goto case_194;
    }
    uint64_t zimm4;
    zimm4 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__47 >> INT64_C(31)));
    uint64_t zuz3167;
    zuz3167 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__47 >> INT64_C(20)));
    uint64_t zuz3168;
    zuz3168 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__47 >> INT64_C(15)));
    uint64_t zimm4shadowz315;
    zimm4shadowz315 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__47 >> INT64_C(31)));
    uint64_t zimm3;
    zimm3 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__47 >> INT64_C(7)));
    uint64_t zuz3169;
    zuz3169 = (safe_rshift(UINT64_MAX, 64 - 6) & (zv__47 >> INT64_C(25)));
    uint64_t zuz3170;
    zuz3170 = (safe_rshift(UINT64_MAX, 64 - 4) & (zv__47 >> INT64_C(8)));
    struct zast zgaz3191;
    CREATE(zast)(&zgaz3191);
    {
      struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 zgsz3434;
      zgsz3434.ztup0 = zimm4shadowz315;
      zgsz3434.ztup1 = zuz3169;
      zgsz3434.ztup2 = zuz3167;
      zgsz3434.ztup3 = zuz3168;
      zgsz3434.ztup4 = zuz3170;
      zgsz3434.ztup5 = zimm3;
      zgsz3434.ztup6 = zBEQ;
      zBTYPE(&zgaz3191, zgsz3434);
    
    }
    {
      struct zast zgsz3519;
      CREATE(zast)(&zgsz3519);
      COPY(zast)(&zgsz3519, zgaz3191);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3519);
      KILL(zast)(&zgsz3519);
    }
    KILL(zast)(&zgaz3191);
  
  
  
  
  
  
  
  
    goto finish_match_175;
  }
case_194: ;
  {
    uint64_t zv__49;
    zv__49 = zmergez3var;
    uint64_t zgaz3194;
    zgaz3194 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__49 >> INT64_C(0)));
    bool zgsz3437;
    zgsz3437 = (zgaz3194 == UINT64_C(0b1100011));
  
    if (!(zgsz3437)) {
  
    goto case_195;
    }
    uint64_t zuz3171;
    zuz3171 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__49 >> INT64_C(31)));
    uint64_t zuz3172;
    zuz3172 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__49 >> INT64_C(20)));
    uint64_t zuz3173;
    zuz3173 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__49 >> INT64_C(15)));
    uint64_t zimm4shadowz316;
    zimm4shadowz316 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__49 >> INT64_C(31)));
    uint64_t zuz3174;
    zuz3174 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__49 >> INT64_C(7)));
    uint64_t zuz3175;
    zuz3175 = (safe_rshift(UINT64_MAX, 64 - 6) & (zv__49 >> INT64_C(25)));
    uint64_t zuz3176;
    zuz3176 = (safe_rshift(UINT64_MAX, 64 - 4) & (zv__49 >> INT64_C(8)));
    struct zast zgaz3193;
    CREATE(zast)(&zgaz3193);
    {
      struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 zgsz3436;
      zgsz3436.ztup0 = zimm4shadowz316;
      zgsz3436.ztup1 = zuz3175;
      zgsz3436.ztup2 = zuz3172;
      zgsz3436.ztup3 = zuz3173;
      zgsz3436.ztup4 = zuz3176;
      zgsz3436.ztup5 = zuz3174;
      zgsz3436.ztup6 = zBNE;
      zBTYPE(&zgaz3193, zgsz3436);
    
    }
    {
      struct zast zgsz3520;
      CREATE(zast)(&zgsz3520);
      COPY(zast)(&zgsz3520, zgaz3193);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3520);
      KILL(zast)(&zgsz3520);
    }
    KILL(zast)(&zgaz3193);
  
  
  
  
  
  
  
  
    goto finish_match_175;
  }
case_195: ;
  {
    uint64_t zv__51;
    zv__51 = zmergez3var;
    uint64_t zgaz3196;
    zgaz3196 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__51 >> INT64_C(0)));
    bool zgsz3439;
    zgsz3439 = (zgaz3196 == UINT64_C(0b0110111));
  
    if (!(zgsz3439)) {
  
    goto case_196;
    }
    uint64_t zuz3177;
    zuz3177 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__51 >> INT64_C(12)));
    uint64_t zuz3178;
    zuz3178 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__51 >> INT64_C(7)));
    uint64_t zimmshadowz317;
    zimmshadowz317 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__51 >> INT64_C(12)));
    struct zast zgaz3195;
    CREATE(zast)(&zgaz3195);
    {
      struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 zgsz3438;
      zgsz3438.ztup0 = zimmshadowz317;
      zgsz3438.ztup1 = zuz3178;
      zgsz3438.ztup2 = zLUI;
      zUTYPE(&zgaz3195, zgsz3438);
    
    }
    {
      struct zast zgsz3521;
      CREATE(zast)(&zgsz3521);
      COPY(zast)(&zgsz3521, zgaz3195);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3521);
      KILL(zast)(&zgsz3521);
    }
    KILL(zast)(&zgaz3195);
  
  
  
  
    goto finish_match_175;
  }
case_196: ;
  {
    uint64_t zv__53;
    zv__53 = zmergez3var;
    uint64_t zgaz3198;
    zgaz3198 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__53 >> INT64_C(0)));
    bool zgsz3441;
    zgsz3441 = (zgaz3198 == UINT64_C(0b0010111));
  
    if (!(zgsz3441)) {
  
    goto case_197;
    }
    uint64_t zuz3179;
    zuz3179 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__53 >> INT64_C(12)));
    uint64_t zuz3180;
    zuz3180 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__53 >> INT64_C(7)));
    uint64_t zimmshadowz318;
    zimmshadowz318 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__53 >> INT64_C(12)));
    struct zast zgaz3197;
    CREATE(zast)(&zgaz3197);
    {
      struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 zgsz3440;
      zgsz3440.ztup0 = zimmshadowz318;
      zgsz3440.ztup1 = zuz3180;
      zgsz3440.ztup2 = zAUIPC;
      zUTYPE(&zgaz3197, zgsz3440);
    
    }
    {
      struct zast zgsz3522;
      CREATE(zast)(&zgsz3522);
      COPY(zast)(&zgsz3522, zgaz3197);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3522);
      KILL(zast)(&zgsz3522);
    }
    KILL(zast)(&zgaz3197);
  
  
  
  
    goto finish_match_175;
  }
case_197: ;
  {
    uint64_t zv__55;
    zv__55 = zmergez3var;
    uint64_t zgaz3200;
    zgaz3200 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__55 >> INT64_C(0)));
    bool zgsz3443;
    zgsz3443 = (zgaz3200 == UINT64_C(0b1101111));
  
    if (!(zgsz3443)) {
  
    goto case_198;
    }
    uint64_t zuz3181;
    zuz3181 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__55 >> INT64_C(31)));
    uint64_t zuz3182;
    zuz3182 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__55 >> INT64_C(7)));
    uint64_t zimm4shadowz319;
    zimm4shadowz319 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__55 >> INT64_C(31)));
    uint64_t zuz3183;
    zuz3183 = (safe_rshift(UINT64_MAX, 64 - 8) & (zv__55 >> INT64_C(12)));
    uint64_t zuz3184;
    zuz3184 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__55 >> INT64_C(20)));
    uint64_t zuz3185;
    zuz3185 = (safe_rshift(UINT64_MAX, 64 - 10) & (zv__55 >> INT64_C(21)));
    struct zast zgaz3199;
    CREATE(zast)(&zgaz3199);
    {
      struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv8zCz0z5bv5zCz0z5enumz0zzjopz9 zgsz3442;
      zgsz3442.ztup0 = zimm4shadowz319;
      zgsz3442.ztup1 = zuz3185;
      zgsz3442.ztup2 = zuz3184;
      zgsz3442.ztup3 = zuz3183;
      zgsz3442.ztup4 = zuz3182;
      zgsz3442.ztup5 = zJAL;
      zJTYPE(&zgaz3199, zgsz3442);
    
    }
    {
      struct zast zgsz3523;
      CREATE(zast)(&zgsz3523);
      COPY(zast)(&zgsz3523, zgaz3199);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3523);
      KILL(zast)(&zgsz3523);
    }
    KILL(zast)(&zgaz3199);
  
  
  
  
  
  
  
    goto finish_match_175;
  }
case_198: ;
  {
    uint64_t zv__57;
    zv__57 = zmergez3var;
    bool zgsz3444;
    zgsz3444 = (zv__57 == UINT64_C(0x00100073));
    if (!(zgsz3444)) {
  
    goto case_199;
    }
    struct zast zgaz3201;
    CREATE(zast)(&zgaz3201);
    zEBREAK(&zgaz3201, UNIT);
    {
      struct zast zgsz3524;
      CREATE(zast)(&zgsz3524);
      COPY(zast)(&zgsz3524, zgaz3201);
      zSomez3z5unionz0zzast(&zgsz3376, zgsz3524);
      KILL(zast)(&zgsz3524);
    }
    KILL(zast)(&zgaz3201);
  
    goto finish_match_175;
  }
case_199: ;
  {
    zNone(&zgsz3376, UNIT);
    goto finish_match_175;
  }
case_200: ;
  sail_match_failure("decode");
finish_match_175: ;
  COPY(zoption)((*(&zcbz329)), zgsz3376);
  KILL(zoption)(&zgsz3376);
end_function_201: ;
  goto end_function_219;
end_block_exception_202: ;
  goto end_function_219;
end_function_219: ;
}



void finish_zdecode(void)
{
  KILL(lbits)(&zghz3250);
  KILL(lbits)(&zghz3249);
  KILL(sail_int)(&zghz3248);
  KILL(lbits)(&zghz3247);
  KILL(lbits)(&zghz3246);
  KILL(sail_int)(&zghz3245);
  KILL(lbits)(&zghz3244);
  KILL(lbits)(&zghz3243);
  KILL(sail_int)(&zghz3242);
  KILL(lbits)(&zghz3241);
  KILL(lbits)(&zghz3240);
  KILL(sail_int)(&zghz3239);
}

unit zfde_loop(unit);

lbits zghz3251;
lbits zghz3252;

void startup_zfde_loop(void)
{
  CREATE(lbits)(&zghz3251);
  CREATE(lbits)(&zghz3252);
}












unit zfde_loop(unit zgsz3446)
{
  __label__ while_204, wend_205, end_function_211, end_block_exception_212;

  unit zcbz330;
  bool zcontinue_loop;
  zcontinue_loop = true;
  bool zgsz3457;
  unit zgsz3458;
while_204: ;
  {
    zgsz3457 = zcontinue_loop;
    if (!(zgsz3457)) goto wend_205;
    uint64_t zinstruction;
    {
      uint64_t zgaz3202;
      zgaz3202 = *(&zPC);
      zinstruction = zread_mem(zgaz3202);
    
    }
    {
      unit zgsz3455;
      {
        RECREATE(lbits)(&zghz3252);
        CONVERT_OF(lbits, fbits)(&zghz3252, zinstruction, UINT64_C(32) , true);
        zgsz3455 = print_bits("Instruction = ", zghz3252);
      }
    }
    {
      __label__ case_207, case_208, case_209, case_210, finish_match_206;

      struct zoption zdecoded_instruction;
      CREATE(zoption)(&zdecoded_instruction);
      zdecode(&zdecoded_instruction, zinstruction);
      unit zgsz3447;
      {
        if (zdecoded_instruction.kind != Kind_zSomez3z5unionz0zzast) goto case_207;
        if (zdecoded_instruction.zSomez3z5unionz0zzast.kind != Kind_zEBREAK) goto case_207;
        zcontinue_loop = false;
        zgsz3447 = UNIT;
        goto finish_match_206;
      }
    case_207: ;
      {
        if (zdecoded_instruction.kind != Kind_zSomez3z5unionz0zzast) goto case_208;
        struct zast zinst;
        CREATE(zast)(&zinst);
        COPY(zast)(&zinst, zdecoded_instruction.zSomez3z5unionz0zzast);
        zgsz3447 = zexecute(zinst);
        KILL(zast)(&zinst);
        goto finish_match_206;
      }
    case_208: ;
      {
        if (zdecoded_instruction.kind != Kind_zNone) goto case_209;
        {
          unit zgsz3450;
          zgsz3450 = print_endline("instruction is None()");
        }
        zgsz3447 = zinc_PC(UNIT);
        goto finish_match_206;
      }
    case_209: ;
      {
        {
          unit zgsz3452;
          zgsz3452 = print_endline("decoding the instruction resulted in something unexpected");
        }
        zcontinue_loop = false;
        zgsz3447 = UNIT;
        goto finish_match_206;
      }
    case_210: ;
      sail_match_failure("fde_loop");
    finish_match_206: ;
      unit zgsz3454;
      zgsz3454 = zgsz3447;
    
      KILL(zoption)(&zdecoded_instruction);
    }
    {
      RECREATE(lbits)(&zghz3251);
      CONVERT_OF(lbits, fbits)(&zghz3251, zPC, UINT64_C(32) , true);
      zgsz3458 = print_bits("PC in fde_loop = ", zghz3251);
    }
  
    goto while_204;
  }
wend_205: ;
  zcbz330 = UNIT;

end_function_211: ;
  return zcbz330;
end_block_exception_212: ;

  return UNIT;
}



void finish_zfde_loop(void)
{
  KILL(lbits)(&zghz3252);
  KILL(lbits)(&zghz3251);
}

unit zmain(unit);

lbits zghz3253;
sail_int zghz3254;
sail_int zghz3255;
sail_int zghz3256;
lbits zghz3257;

void startup_zmain(void)
{
  CREATE(lbits)(&zghz3253);
  CREATE(sail_int)(&zghz3254);
  CREATE(sail_int)(&zghz3255);
  CREATE(sail_int)(&zghz3256);
  CREATE(lbits)(&zghz3257);
}

unit zmain(unit zgsz3460)
{
  __label__ end_function_214, end_block_exception_215;

  unit zcbz331;
  {
    RECREATE(sail_int)(&zghz3254);
    elf_entry(&zghz3254, UNIT);
    {
      RECREATE(sail_int)(&zghz3255);
      CONVERT_OF(sail_int, mach_int)(&zghz3255, INT64_C(32));
      RECREATE(sail_int)(&zghz3256);
      CONVERT_OF(sail_int, mach_int)(&zghz3256, INT64_C(0));
      RECREATE(lbits)(&zghz3257);
      get_slice_int(&zghz3257, zghz3255, zghz3254, zghz3256);
      zPC = CONVERT_OF(fbits, lbits)(zghz3257, true);
    }
    unit zgsz3467;
    zgsz3467 = UNIT;
  }
  {
    unit zgsz3465;
    {
      RECREATE(lbits)(&zghz3253);
      CONVERT_OF(lbits, fbits)(&zghz3253, zPC, UINT64_C(32) , true);
      zgsz3465 = print_bits("PC = ", zghz3253);
    }
  }
  {
    unit zgsz3464;
    zgsz3464 = zfde_loop(UNIT);
  }
  zcbz331 = zobj_dump(UNIT);
end_function_214: ;
  return zcbz331;
end_block_exception_215: ;

  return UNIT;
}



void finish_zmain(void)
{
  KILL(lbits)(&zghz3257);
  KILL(sail_int)(&zghz3256);
  KILL(sail_int)(&zghz3255);
  KILL(sail_int)(&zghz3254);
  KILL(lbits)(&zghz3253);
}

unit zinitializze_registers(unit);

sail_int zghz3258;
lbits zghz3259;
sail_int zghz3260;
lbits zghz3261;
sail_int zghz3262;
lbits zghz3263;
sail_int zghz3264;
lbits zghz3265;
sail_int zghz3266;
lbits zghz3267;
sail_int zghz3268;
lbits zghz3269;
sail_int zghz3270;
lbits zghz3271;
sail_int zghz3272;
lbits zghz3273;
sail_int zghz3274;
lbits zghz3275;
sail_int zghz3276;
lbits zghz3277;
sail_int zghz3278;
lbits zghz3279;

void startup_zinitializze_registers(void)
{
  CREATE(sail_int)(&zghz3258);
  CREATE(lbits)(&zghz3259);
  CREATE(sail_int)(&zghz3260);
  CREATE(lbits)(&zghz3261);
  CREATE(sail_int)(&zghz3262);
  CREATE(lbits)(&zghz3263);
  CREATE(sail_int)(&zghz3264);
  CREATE(lbits)(&zghz3265);
  CREATE(sail_int)(&zghz3266);
  CREATE(lbits)(&zghz3267);
  CREATE(sail_int)(&zghz3268);
  CREATE(lbits)(&zghz3269);
  CREATE(sail_int)(&zghz3270);
  CREATE(lbits)(&zghz3271);
  CREATE(sail_int)(&zghz3272);
  CREATE(lbits)(&zghz3273);
  CREATE(sail_int)(&zghz3274);
  CREATE(lbits)(&zghz3275);
  CREATE(sail_int)(&zghz3276);
  CREATE(lbits)(&zghz3277);
  CREATE(sail_int)(&zghz3278);
  CREATE(lbits)(&zghz3279);
}

unit zinitializze_registers(unit zgsz3468)
{
  __label__ end_function_217, end_block_exception_218;

  unit zcbz332;
  {
    {
      RECREATE(sail_int)(&zghz3278);
      CONVERT_OF(sail_int, mach_int)(&zghz3278, INT64_C(32));
      RECREATE(lbits)(&zghz3279);
      UNDEFINED(lbits)(&zghz3279, zghz3278);
      zPC = CONVERT_OF(fbits, lbits)(zghz3279, true);
    }
    unit zgsz3498;
    zgsz3498 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3276);
      CONVERT_OF(sail_int, mach_int)(&zghz3276, INT64_C(32));
      RECREATE(lbits)(&zghz3277);
      UNDEFINED(lbits)(&zghz3277, zghz3276);
      zstart_boundary = CONVERT_OF(fbits, lbits)(zghz3277, true);
    }
    unit zgsz3497;
    zgsz3497 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3274);
      CONVERT_OF(sail_int, mach_int)(&zghz3274, INT64_C(32));
      RECREATE(lbits)(&zghz3275);
      UNDEFINED(lbits)(&zghz3275, zghz3274);
      zend_boundary = CONVERT_OF(fbits, lbits)(zghz3275, true);
    }
    unit zgsz3496;
    zgsz3496 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3272);
      CONVERT_OF(sail_int, mach_int)(&zghz3272, INT64_C(32));
      RECREATE(lbits)(&zghz3273);
      UNDEFINED(lbits)(&zghz3273, zghz3272);
      zzzero = CONVERT_OF(fbits, lbits)(zghz3273, true);
    }
    unit zgsz3495;
    zgsz3495 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3270);
      CONVERT_OF(sail_int, mach_int)(&zghz3270, INT64_C(32));
      RECREATE(lbits)(&zghz3271);
      UNDEFINED(lbits)(&zghz3271, zghz3270);
      zra = CONVERT_OF(fbits, lbits)(zghz3271, true);
    }
    unit zgsz3494;
    zgsz3494 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3268);
      CONVERT_OF(sail_int, mach_int)(&zghz3268, INT64_C(32));
      RECREATE(lbits)(&zghz3269);
      UNDEFINED(lbits)(&zghz3269, zghz3268);
      zsp = CONVERT_OF(fbits, lbits)(zghz3269, true);
    }
    unit zgsz3493;
    zgsz3493 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3266);
      CONVERT_OF(sail_int, mach_int)(&zghz3266, INT64_C(32));
      RECREATE(lbits)(&zghz3267);
      UNDEFINED(lbits)(&zghz3267, zghz3266);
      zgp = CONVERT_OF(fbits, lbits)(zghz3267, true);
    }
    unit zgsz3492;
    zgsz3492 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3264);
      CONVERT_OF(sail_int, mach_int)(&zghz3264, INT64_C(32));
      RECREATE(lbits)(&zghz3265);
      UNDEFINED(lbits)(&zghz3265, zghz3264);
      za0 = CONVERT_OF(fbits, lbits)(zghz3265, true);
    }
    unit zgsz3491;
    zgsz3491 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3262);
      CONVERT_OF(sail_int, mach_int)(&zghz3262, INT64_C(32));
      RECREATE(lbits)(&zghz3263);
      UNDEFINED(lbits)(&zghz3263, zghz3262);
      za1 = CONVERT_OF(fbits, lbits)(zghz3263, true);
    }
    unit zgsz3490;
    zgsz3490 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3260);
      CONVERT_OF(sail_int, mach_int)(&zghz3260, INT64_C(32));
      RECREATE(lbits)(&zghz3261);
      UNDEFINED(lbits)(&zghz3261, zghz3260);
      za2 = CONVERT_OF(fbits, lbits)(zghz3261, true);
    }
    unit zgsz3489;
    zgsz3489 = UNIT;
  }
  {
    RECREATE(sail_int)(&zghz3258);
    CONVERT_OF(sail_int, mach_int)(&zghz3258, INT64_C(32));
    RECREATE(lbits)(&zghz3259);
    UNDEFINED(lbits)(&zghz3259, zghz3258);
    za3 = CONVERT_OF(fbits, lbits)(zghz3259, true);
  }
  zcbz332 = UNIT;
end_function_217: ;
  return zcbz332;
end_block_exception_218: ;

  return UNIT;
}



void finish_zinitializze_registers(void)
{
  KILL(lbits)(&zghz3279);
  KILL(sail_int)(&zghz3278);
  KILL(lbits)(&zghz3277);
  KILL(sail_int)(&zghz3276);
  KILL(lbits)(&zghz3275);
  KILL(sail_int)(&zghz3274);
  KILL(lbits)(&zghz3273);
  KILL(sail_int)(&zghz3272);
  KILL(lbits)(&zghz3271);
  KILL(sail_int)(&zghz3270);
  KILL(lbits)(&zghz3269);
  KILL(sail_int)(&zghz3268);
  KILL(lbits)(&zghz3267);
  KILL(sail_int)(&zghz3266);
  KILL(lbits)(&zghz3265);
  KILL(sail_int)(&zghz3264);
  KILL(lbits)(&zghz3263);
  KILL(sail_int)(&zghz3262);
  KILL(lbits)(&zghz3261);
  KILL(sail_int)(&zghz3260);
  KILL(lbits)(&zghz3259);
  KILL(sail_int)(&zghz3258);
}

void model_init(void)
{
  setup_rts();
  startup_zsail_mask();
  startup_zsail_ones();
  startup_zfdiv_int();
  startup_zgt_bit();
  startup_zlt_bit();
  startup_zlte_bit();
  startup_zxor_bitvector();
  startup_ztwos_complement();
  startup_zabs();
  startup_zmul_bitvector();
  startup_zdiv_bitvector();
  startup_zEXTS();
  startup_zadd_to_PC();
  startup_zinc_PC();
  startup_zprotected();
  startup_zunprotected();
  startup_zreg_offset();
  startup_zrREG();
  startup_zwREG();
  startup_zread_mem();
  startup_zwrite_mem();
  startup_zreset_registers();
  startup_zobj_dump();
  startup_zexecute();
  startup_zdecode();
  startup_zfde_loop();
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
  finish_zgt_bit();
  finish_zlt_bit();
  finish_zlte_bit();
  finish_zxor_bitvector();
  finish_ztwos_complement();
  finish_zabs();
  finish_zmul_bitvector();
  finish_zdiv_bitvector();
  finish_zEXTS();
  finish_zadd_to_PC();
  finish_zinc_PC();
  finish_zprotected();
  finish_zunprotected();
  finish_zreg_offset();
  finish_zrREG();
  finish_zwREG();
  finish_zread_mem();
  finish_zwrite_mem();
  finish_zreset_registers();
  finish_zobj_dump();
  finish_zexecute();
  finish_zdecode();
  finish_zfde_loop();
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
