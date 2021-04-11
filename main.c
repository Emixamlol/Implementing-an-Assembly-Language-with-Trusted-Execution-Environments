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
  __label__ end_function_4, end_block_exception_5, end_function_202;

  bool zgaz32;
  {
    RECREATE(sail_int)(&zghz30);
    length_lbits(&zghz30, zv);
    zgaz32 = lteq(zlen, zghz30);
  }
  if (zgaz32) {  sail_truncate((*(&zcbz31)), zv, zlen);  } else {  zero_extend((*(&zcbz31)), zv, zlen);  }

end_function_4: ;
  goto end_function_202;
end_block_exception_5: ;
  goto end_function_202;
end_function_202: ;
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
  __label__ end_function_7, end_block_exception_8, end_function_201;

  RECREATE(lbits)(&zghz31);
  zeros(&zghz31, zn);
  not_bits((*(&zcbz32)), zghz31);
end_function_7: ;
  goto end_function_201;
end_block_exception_8: ;
  goto end_function_201;
end_function_201: ;
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
  __label__ end_function_10, end_block_exception_11, end_function_200;

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
  goto end_function_200;
end_block_exception_11: ;
  goto end_function_200;
end_function_200: ;
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















// register PC
uint64_t zPC;

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
  COPY(zz5vecz8z6z8z5bv32z9z9)(&zXs, zgsz311);
  KILL(zz5vecz8z6z8z5bv32z9z9)(&zgsz311);
let_end_12: ;
}
static void kill_letbind_0(void) {    KILL(zz5vecz8z6z8z5bv32z9z9)(&zXs);
}

void zextzz(lbits *rop, sail_int, lbits);

void zextzz(lbits *zcbz34, sail_int zm, lbits zxs)
{
  __label__ end_function_14, end_block_exception_15, end_function_199;

  zero_extend((*(&zcbz34)), zxs, zm);
end_function_14: ;
  goto end_function_199;
end_block_exception_15: ;
  goto end_function_199;
end_function_199: ;
}

uint64_t zEXTS(sbits);

lbits zghz314;
sail_int zghz315;
lbits zghz316;

void startup_zEXTS(void)
{
  CREATE(lbits)(&zghz314);
  CREATE(sail_int)(&zghz315);
  CREATE(lbits)(&zghz316);
}

uint64_t zEXTS(sbits zxs)
{
  __label__ end_function_17, end_block_exception_18;

  uint64_t zcbz35;
  {
    RECREATE(lbits)(&zghz314);
    CONVERT_OF(lbits, sbits)(&zghz314, zxs, true);
    RECREATE(sail_int)(&zghz315);
    CONVERT_OF(sail_int, mach_int)(&zghz315, INT64_C(32));
    RECREATE(lbits)(&zghz316);
    sign_extend(&zghz316, zghz314, zghz315);
    zcbz35 = CONVERT_OF(fbits, lbits)(zghz316, true);
  }
end_function_17: ;
  return zcbz35;
end_block_exception_18: ;

  return UINT64_C(0xdeadc0de);
}



void finish_zEXTS(void)
{
  KILL(lbits)(&zghz316);
  KILL(sail_int)(&zghz315);
  KILL(lbits)(&zghz314);
}

unit zadd_to_PC(sail_int);

lbits zghz317;
lbits zghz318;

void startup_zadd_to_PC(void)
{
  CREATE(lbits)(&zghz317);
  CREATE(lbits)(&zghz318);
}

unit zadd_to_PC(sail_int zbytes)
{
  __label__ end_function_20, end_block_exception_21;

  unit zcbz36;
  {
    RECREATE(lbits)(&zghz317);
    CONVERT_OF(lbits, fbits)(&zghz317, zPC, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz318);
    add_bits_int(&zghz318, zghz317, zbytes);
    zPC = CONVERT_OF(fbits, lbits)(zghz318, true);
  }
  zcbz36 = UNIT;
end_function_20: ;
  return zcbz36;
end_block_exception_21: ;

  return UNIT;
}



void finish_zadd_to_PC(void)
{
  KILL(lbits)(&zghz318);
  KILL(lbits)(&zghz317);
}

unit zinc_PC(unit);

sail_int zghz319;

void startup_zinc_PC(void)
{    CREATE(sail_int)(&zghz319);
}

unit zinc_PC(unit zgsz317)
{
  __label__ end_function_23, end_block_exception_24;

  unit zcbz37;
  {
    RECREATE(sail_int)(&zghz319);
    CONVERT_OF(sail_int, mach_int)(&zghz319, INT64_C(4));
    zcbz37 = zadd_to_PC(zghz319);
  }
end_function_23: ;
  return zcbz37;
end_block_exception_24: ;

  return UNIT;
}



void finish_zinc_PC(void)
{    KILL(sail_int)(&zghz319);
}

uint64_t zrREG(uint64_t);

sail_int zghz320;

void startup_zrREG(void)
{    CREATE(sail_int)(&zghz320);
}

uint64_t zrREG(uint64_t zr)
{
  __label__ end_function_26, end_block_exception_27;

  uint64_t zcbz38;
  uint64_t zoffset;
  zoffset = (safe_rshift(UINT64_MAX, 64 - 3) & (zr >> INT64_C(0)));
  uint64_t* zgaz313;
  {
    int64_t zgaz312;
    zgaz312 = ((mach_int) zoffset);
    {
      RECREATE(sail_int)(&zghz320);
      CONVERT_OF(sail_int, mach_int)(&zghz320, zgaz312);
      zgaz313 = vector_access_zz5vecz8z6z8z5bv32z9z9(zXs, zghz320);
    }
  
  }
  zcbz38 = *(zgaz313);


end_function_26: ;
  return zcbz38;
end_block_exception_27: ;

  return UINT64_C(0xdeadc0de);
}



void finish_zrREG(void)
{    KILL(sail_int)(&zghz320);
}

unit zwREG(uint64_t, uint64_t);

sail_int zghz321;
sail_int zghz322;
lbits zghz323;
lbits zghz324;
sail_int zghz325;
sail_int zghz326;
sail_int zghz327;

void startup_zwREG(void)
{
  CREATE(sail_int)(&zghz321);
  CREATE(sail_int)(&zghz322);
  CREATE(lbits)(&zghz323);
  CREATE(lbits)(&zghz324);
  CREATE(sail_int)(&zghz325);
  CREATE(sail_int)(&zghz326);
  CREATE(sail_int)(&zghz327);
}

unit zwREG(uint64_t zr, uint64_t zv)
{
  __label__ case_30, case_31, finish_match_29, end_function_32, end_block_exception_33;

  unit zcbz39;
  uint64_t zoffset;
  zoffset = (safe_rshift(UINT64_MAX, 64 - 3) & (zr >> INT64_C(0)));
  {
    uint64_t zvz30;
    zvz30 = zoffset;
    uint64_t zgaz316;
    {
      int64_t zgaz315;
      {
        int64_t zgaz314;
        {
          RECREATE(sail_int)(&zghz325);
          CONVERT_OF(sail_int, mach_int)(&zghz325, INT64_C(2));
          RECREATE(sail_int)(&zghz326);
          CONVERT_OF(sail_int, mach_int)(&zghz326, INT64_C(0));
          RECREATE(sail_int)(&zghz327);
          sub_int(&zghz327, zghz325, zghz326);
          zgaz314 = CONVERT_OF(mach_int, sail_int)(zghz327);
        }
        zgaz315 = (zgaz314 + INT64_C(1));
      
      }
      {
        RECREATE(sail_int)(&zghz322);
        CONVERT_OF(sail_int, mach_int)(&zghz322, zgaz315);
        RECREATE(lbits)(&zghz323);
        CONVERT_OF(lbits, fbits)(&zghz323, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz324);
        zextzz(&zghz324, zghz322, zghz323);
        zgaz316 = CONVERT_OF(fbits, lbits)(zghz324, true);
      }
    
    }
    bool zgsz327;
    zgsz327 = (zvz30 == zgaz316);
  
    if (!(zgsz327)) {
  
    goto case_30;
    }
    zcbz39 = print_endline("Cannot overwrite hard-wired zero register");
  
    goto finish_match_29;
  }
case_30: ;
  {
    uint64_t* zgaz317;
    {
      int64_t zgaz318;
      zgaz318 = ((mach_int) zoffset);
      {
        RECREATE(sail_int)(&zghz321);
        CONVERT_OF(sail_int, mach_int)(&zghz321, zgaz318);
        zgaz317 = vector_access_zz5vecz8z6z8z5bv32z9z9(zXs, zghz321);
      }
    
    }
    (*(zgaz317)) = zv;
    zcbz39 = UNIT;
  
    goto finish_match_29;
  }
case_31: ;
  sail_match_failure("wREG");
finish_match_29: ;

end_function_32: ;
  return zcbz39;
end_block_exception_33: ;

  return UNIT;
}



void finish_zwREG(void)
{
  KILL(sail_int)(&zghz327);
  KILL(sail_int)(&zghz326);
  KILL(sail_int)(&zghz325);
  KILL(lbits)(&zghz324);
  KILL(lbits)(&zghz323);
  KILL(sail_int)(&zghz322);
  KILL(sail_int)(&zghz321);
}



uint64_t zread_mem(uint64_t);

sail_int zghz328;
sail_int zghz329;
lbits zghz330;
lbits zghz331;
lbits zghz332;
sail_int zghz333;
lbits zghz334;

void startup_zread_mem(void)
{
  CREATE(sail_int)(&zghz328);
  CREATE(sail_int)(&zghz329);
  CREATE(lbits)(&zghz330);
  CREATE(lbits)(&zghz331);
  CREATE(lbits)(&zghz332);
  CREATE(sail_int)(&zghz333);
  CREATE(lbits)(&zghz334);
}

uint64_t zread_mem(uint64_t zaddr)
{
  __label__ end_function_35, end_block_exception_36;

  uint64_t zcbz310;
  uint64_t zgaz319;
  {
    RECREATE(sail_int)(&zghz333);
    CONVERT_OF(sail_int, mach_int)(&zghz333, INT64_C(32));
    RECREATE(lbits)(&zghz334);
    zeros(&zghz334, zghz333);
    zgaz319 = CONVERT_OF(fbits, lbits)(zghz334, true);
  }
  {
    RECREATE(sail_int)(&zghz328);
    CONVERT_OF(sail_int, mach_int)(&zghz328, INT64_C(32));
    RECREATE(sail_int)(&zghz329);
    CONVERT_OF(sail_int, mach_int)(&zghz329, INT64_C(4));
    RECREATE(lbits)(&zghz330);
    CONVERT_OF(lbits, fbits)(&zghz330, zgaz319, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz331);
    CONVERT_OF(lbits, fbits)(&zghz331, zaddr, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz332);
    read_ram(&zghz332, zghz328, zghz329, zghz330, zghz331);
    zcbz310 = CONVERT_OF(fbits, lbits)(zghz332, true);
  }

end_function_35: ;
  return zcbz310;
end_block_exception_36: ;

  return UINT64_C(0xdeadc0de);
}



void finish_zread_mem(void)
{
  KILL(lbits)(&zghz334);
  KILL(sail_int)(&zghz333);
  KILL(lbits)(&zghz332);
  KILL(lbits)(&zghz331);
  KILL(lbits)(&zghz330);
  KILL(sail_int)(&zghz329);
  KILL(sail_int)(&zghz328);
}



unit zwrite_mem(uint64_t, uint64_t);

lbits zghz335;
lbits zghz336;
lbits zghz337;
sail_int zghz338;
sail_int zghz339;
sail_int zghz340;
lbits zghz341;

void startup_zwrite_mem(void)
{
  CREATE(lbits)(&zghz335);
  CREATE(lbits)(&zghz336);
  CREATE(lbits)(&zghz337);
  CREATE(sail_int)(&zghz338);
  CREATE(sail_int)(&zghz339);
  CREATE(sail_int)(&zghz340);
  CREATE(lbits)(&zghz341);
}

unit zwrite_mem(uint64_t zaddr, uint64_t zdata)
{
  __label__ end_function_38, end_block_exception_39;

  unit zcbz311;
  uint64_t zgaz320;
  {
    RECREATE(sail_int)(&zghz340);
    CONVERT_OF(sail_int, mach_int)(&zghz340, INT64_C(32));
    RECREATE(lbits)(&zghz341);
    zeros(&zghz341, zghz340);
    zgaz320 = CONVERT_OF(fbits, lbits)(zghz341, true);
  }
  {
    RECREATE(lbits)(&zghz335);
    CONVERT_OF(lbits, fbits)(&zghz335, zdata, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz336);
    CONVERT_OF(lbits, fbits)(&zghz336, zaddr, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz337);
    CONVERT_OF(lbits, fbits)(&zghz337, zgaz320, UINT64_C(32) , true);
    RECREATE(sail_int)(&zghz338);
    CONVERT_OF(sail_int, mach_int)(&zghz338, INT64_C(4));
    RECREATE(sail_int)(&zghz339);
    CONVERT_OF(sail_int, mach_int)(&zghz339, INT64_C(32));
    zcbz311 = write_ram(zghz339, zghz338, zghz337, zghz336, zghz335);
  }

end_function_38: ;
  return zcbz311;
end_block_exception_39: ;

  return UNIT;
}



void finish_zwrite_mem(void)
{
  KILL(lbits)(&zghz341);
  KILL(sail_int)(&zghz340);
  KILL(sail_int)(&zghz339);
  KILL(sail_int)(&zghz338);
  KILL(lbits)(&zghz337);
  KILL(lbits)(&zghz336);
  KILL(lbits)(&zghz335);
}

unit zobj_dump(unit);

lbits zghz342;
sail_int zghz343;

void startup_zobj_dump(void)
{
  CREATE(lbits)(&zghz342);
  CREATE(sail_int)(&zghz343);
}

unit zobj_dump(unit zgsz344)
{
  __label__ end_function_53, end_block_exception_54;

  unit zcbz312;
  int64_t zgsz345;
  {    zgsz345 = INT64_C(0);
  }
  int64_t zgsz346;
  {    zgsz346 = INT64_C(7);
  }
  int64_t zgsz347;
  {    zgsz347 = INT64_C(1);
  }
  {
    __label__ for_start_41, for_end_42;

    int64_t zi;
    zi = zgsz345;
    unit zgsz360;
  for_start_41: ;
    {
      if ((zi > zgsz346)) goto for_end_42;
      uint64_t zcontent;
      {
        uint64_t* zgaz322;
        {
          RECREATE(sail_int)(&zghz343);
          CONVERT_OF(sail_int, mach_int)(&zghz343, zi);
          zgaz322 = vector_access_zz5vecz8z6z8z5bv32z9z9(zXs, zghz343);
        }
        zcontent = *(zgaz322);
      
      }
      sail_string zreg_name;
      CREATE(sail_string)(&zreg_name);
      COPY(sail_string)(&zreg_name, "");
      {
        __label__ case_44, case_45, case_46, case_47, case_48, case_49, case_50, case_51, case_52, finish_match_43;

        unit zgsz349;
        {
          int64_t zp0z3;
          zp0z3 = zi;
          bool zgsz350;
          zgsz350 = (zp0z3 == INT64_C(0));
          if (!(zgsz350)) {
        
          goto case_44;
          }
          COPY(sail_string)(&zreg_name, "zero");
          zgsz349 = UNIT;
        
          goto finish_match_43;
        }
      case_44: ;
        {
          int64_t zuz30;
          zuz30 = zi;
          bool zgsz351;
          zgsz351 = (zuz30 == INT64_C(1));
          if (!(zgsz351)) {
        
          goto case_45;
          }
          COPY(sail_string)(&zreg_name, "ra");
          zgsz349 = UNIT;
        
          goto finish_match_43;
        }
      case_45: ;
        {
          int64_t zuz31;
          zuz31 = zi;
          bool zgsz352;
          zgsz352 = (zuz31 == INT64_C(2));
          if (!(zgsz352)) {
        
          goto case_46;
          }
          COPY(sail_string)(&zreg_name, "sp");
          zgsz349 = UNIT;
        
          goto finish_match_43;
        }
      case_46: ;
        {
          int64_t zuz32;
          zuz32 = zi;
          bool zgsz353;
          zgsz353 = (zuz32 == INT64_C(3));
          if (!(zgsz353)) {
        
          goto case_47;
          }
          COPY(sail_string)(&zreg_name, "gp");
          zgsz349 = UNIT;
        
          goto finish_match_43;
        }
      case_47: ;
        {
          int64_t zuz33;
          zuz33 = zi;
          bool zgsz354;
          zgsz354 = (zuz33 == INT64_C(4));
          if (!(zgsz354)) {
        
          goto case_48;
          }
          COPY(sail_string)(&zreg_name, "a0");
          zgsz349 = UNIT;
        
          goto finish_match_43;
        }
      case_48: ;
        {
          int64_t zuz34;
          zuz34 = zi;
          bool zgsz355;
          zgsz355 = (zuz34 == INT64_C(5));
          if (!(zgsz355)) {
        
          goto case_49;
          }
          COPY(sail_string)(&zreg_name, "a1");
          zgsz349 = UNIT;
        
          goto finish_match_43;
        }
      case_49: ;
        {
          int64_t zuz35;
          zuz35 = zi;
          bool zgsz356;
          zgsz356 = (zuz35 == INT64_C(6));
          if (!(zgsz356)) {
        
          goto case_50;
          }
          COPY(sail_string)(&zreg_name, "a2");
          zgsz349 = UNIT;
        
          goto finish_match_43;
        }
      case_50: ;
        {
          int64_t zuz36;
          zuz36 = zi;
          bool zgsz357;
          zgsz357 = (zuz36 == INT64_C(7));
          if (!(zgsz357)) {
        
          goto case_51;
          }
          COPY(sail_string)(&zreg_name, "a3");
          zgsz349 = UNIT;
        
          goto finish_match_43;
        }
      case_51: ;
        {
          zgsz349 = print_endline("unkown register");
          goto finish_match_43;
        }
      case_52: ;
        sail_match_failure("obj_dump");
      finish_match_43: ;
        unit zgsz359;
        zgsz359 = zgsz349;
      
      }
      sail_string zgaz321;
      CREATE(sail_string)(&zgaz321);
      concat_str(&zgaz321, zreg_name, " = ");
      {
        RECREATE(lbits)(&zghz342);
        CONVERT_OF(lbits, fbits)(&zghz342, zcontent, UINT64_C(32) , true);
        zgsz360 = print_bits(zgaz321, zghz342);
      }
      KILL(sail_string)(&zgaz321);
      KILL(sail_string)(&zreg_name);
    
      zi = (zi + zgsz347);
      goto for_start_41;
    }
  for_end_42: ;
  }
  zcbz312 = UNIT;
end_function_53: ;
  return zcbz312;
end_block_exception_54: ;

  return UNIT;
}



void finish_zobj_dump(void)
{
  KILL(sail_int)(&zghz343);
  KILL(lbits)(&zghz342);
}

bool zgt_bit(lbits, lbits);

sail_int zghz344;
sail_int zghz345;

void startup_zgt_bit(void)
{
  CREATE(sail_int)(&zghz344);
  CREATE(sail_int)(&zghz345);
}

bool zgt_bit(lbits zx, lbits zy)
{
  __label__ end_function_56, end_block_exception_57;

  bool zcbz313;
  RECREATE(sail_int)(&zghz344);
  sail_unsigned(&zghz344, zx);
  RECREATE(sail_int)(&zghz345);
  sail_unsigned(&zghz345, zy);
  zcbz313 = gt(zghz344, zghz345);
end_function_56: ;
  return zcbz313;
end_block_exception_57: ;

  return false;
}



void finish_zgt_bit(void)
{
  KILL(sail_int)(&zghz345);
  KILL(sail_int)(&zghz344);
}

bool zlt_bit(lbits, lbits);

sail_int zghz346;
sail_int zghz347;

void startup_zlt_bit(void)
{
  CREATE(sail_int)(&zghz346);
  CREATE(sail_int)(&zghz347);
}

bool zlt_bit(lbits zx, lbits zy)
{
  __label__ end_function_59, end_block_exception_60;

  bool zcbz314;
  RECREATE(sail_int)(&zghz346);
  sail_unsigned(&zghz346, zx);
  RECREATE(sail_int)(&zghz347);
  sail_unsigned(&zghz347, zy);
  zcbz314 = lt(zghz346, zghz347);
end_function_59: ;
  return zcbz314;
end_block_exception_60: ;

  return false;
}



void finish_zlt_bit(void)
{
  KILL(sail_int)(&zghz347);
  KILL(sail_int)(&zghz346);
}

fbits zxor_bit(fbits, fbits);

fbits zxor_bit(fbits zb1, fbits zb2)
{
  __label__ end_function_62, end_block_exception_63;

  fbits zcbz315;
  bool zgaz327;
  zgaz327 = (zb1 == zb2);
  if (zgaz327) {  zcbz315 = UINT64_C(0);  } else {  zcbz315 = UINT64_C(1);  }

end_function_62: ;
  return zcbz315;
end_block_exception_63: ;

  return UINT64_C(0);
}

void zxor_bitvector(lbits *rop, lbits, lbits);

sail_int zghz348;
lbits zghz349;
sail_int zghz350;
sail_int zghz351;
sail_int zghz352;
sail_int zghz353;
sail_int zghz354;

void startup_zxor_bitvector(void)
{
  CREATE(sail_int)(&zghz348);
  CREATE(lbits)(&zghz349);
  CREATE(sail_int)(&zghz350);
  CREATE(sail_int)(&zghz351);
  CREATE(sail_int)(&zghz352);
  CREATE(sail_int)(&zghz353);
  CREATE(sail_int)(&zghz354);
}

void zxor_bitvector(lbits *zcbz316, lbits zv1, lbits zv2)
{
  __label__ end_function_67, end_block_exception_68, end_function_198;

  RECREATE(sail_int)(&zghz348);
  length_lbits(&zghz348, zv2);
  RECREATE(lbits)(&zghz349);
  zeros(&zghz349, zghz348);
  {
    int64_t zgsz362;
    {    zgsz362 = INT64_C(0);
    }
    int64_t zgsz363;
    {
      {
        RECREATE(sail_int)(&zghz353);
        CONVERT_OF(sail_int, mach_int)(&zghz353, INT64_C(1));
        RECREATE(sail_int)(&zghz354);
        sub_int(&zghz354, zghz348, zghz353);
        zgsz363 = CONVERT_OF(mach_int, sail_int)(zghz354);
      }
    }
    int64_t zgsz364;
    {    zgsz364 = INT64_C(1);
    }
    {
      __label__ for_start_65, for_end_66;

      int64_t zi;
      zi = zgsz362;
      unit zgsz368;
    for_start_65: ;
      {
        if ((zi > zgsz363)) goto for_end_66;
        fbits zb1;
        {
          RECREATE(sail_int)(&zghz352);
          CONVERT_OF(sail_int, mach_int)(&zghz352, zi);
          zb1 = bitvector_access(zv1, zghz352);
        }
        fbits zb2;
        {
          RECREATE(sail_int)(&zghz351);
          CONVERT_OF(sail_int, mach_int)(&zghz351, zi);
          zb2 = bitvector_access(zv2, zghz351);
        }
        fbits zgaz328;
        zgaz328 = zxor_bit(zb1, zb2);
        {
          RECREATE(sail_int)(&zghz350);
          CONVERT_OF(sail_int, mach_int)(&zghz350, zi);
          update_lbits(&zghz349, zghz349, zghz350, zgaz328);
        }
        zgsz368 = UNIT;
      
      
      
        zi = (zi + zgsz364);
        goto for_start_65;
      }
    for_end_66: ;
    }
    unit zgsz371;
    zgsz371 = UNIT;
  }
  COPY(lbits)((*(&zcbz316)), zghz349);
end_function_67: ;
  goto end_function_198;
end_block_exception_68: ;
  goto end_function_198;
end_function_198: ;
}



void finish_zxor_bitvector(void)
{
  KILL(sail_int)(&zghz354);
  KILL(sail_int)(&zghz353);
  KILL(sail_int)(&zghz352);
  KILL(sail_int)(&zghz351);
  KILL(sail_int)(&zghz350);
  KILL(lbits)(&zghz349);
  KILL(sail_int)(&zghz348);
}

bool zxor_bool(bool, bool);

bool zxor_bool(bool zb1, bool zb2)
{
  __label__ end_function_70, end_block_exception_71;

  bool zcbz317;
  bool zgaz329;
  zgaz329 = eq_bool(zb1, zb2);
  if (zgaz329) {  zcbz317 = false;  } else {  zcbz317 = true;  }

end_function_70: ;
  return zcbz317;
end_block_exception_71: ;

  return false;
}

void ztwos_complement(lbits *rop, lbits);

lbits zghz355;
lbits zghz356;
sail_int zghz357;
lbits zghz358;

void startup_ztwos_complement(void)
{
  CREATE(lbits)(&zghz355);
  CREATE(lbits)(&zghz356);
  CREATE(sail_int)(&zghz357);
  CREATE(lbits)(&zghz358);
}

void ztwos_complement(lbits *zcbz318, lbits zv)
{
  __label__ end_function_73, end_block_exception_74, end_function_197;

  RECREATE(lbits)(&zghz355);
  not_bits(&zghz355, zv);
  {
    RECREATE(lbits)(&zghz356);
    {
      RECREATE(sail_int)(&zghz357);
      length_lbits(&zghz357, zv);
      {
        RECREATE(lbits)(&zghz358);
        CONVERT_OF(lbits, fbits)(&zghz358, UINT64_C(0b1), UINT64_C(1) , true);
        zextzz(&zghz356, zghz357, zghz358);
      }
    }
    add_bits(&zghz355, zghz355, zghz356);
    unit zgsz373;
    zgsz373 = UNIT;
  }
  COPY(lbits)((*(&zcbz318)), zghz355);
end_function_73: ;
  goto end_function_197;
end_block_exception_74: ;
  goto end_function_197;
end_function_197: ;
}



void finish_ztwos_complement(void)
{
  KILL(lbits)(&zghz358);
  KILL(sail_int)(&zghz357);
  KILL(lbits)(&zghz356);
  KILL(lbits)(&zghz355);
}

void zabs(lbits *rop, lbits);

sail_int zghz359;
lbits zghz360;
sail_int zghz361;
sail_int zghz362;

void startup_zabs(void)
{
  CREATE(sail_int)(&zghz359);
  CREATE(lbits)(&zghz360);
  CREATE(sail_int)(&zghz361);
  CREATE(sail_int)(&zghz362);
}

void zabs(lbits *zcbz319, lbits zv)
{
  __label__ case_77, case_78, finish_match_76, end_function_79, end_block_exception_80, end_function_196;

  RECREATE(sail_int)(&zghz359);
  {
    RECREATE(sail_int)(&zghz361);
    length_lbits(&zghz361, zv);
    {
      RECREATE(sail_int)(&zghz362);
      CONVERT_OF(sail_int, mach_int)(&zghz362, INT64_C(1));
      sub_int(&zghz359, zghz361, zghz362);
    }
  }
  fbits zgaz332;
  zgaz332 = bitvector_access(zv, zghz359);
  RECREATE(lbits)(&zghz360);
  {
    fbits zp0z3;
    zp0z3 = zgaz332;
    bool zgsz376;
    zgsz376 = eq_bit(zp0z3, UINT64_C(0));
    if (!(zgsz376)) {
  
    goto case_77;
    }
    COPY(lbits)(&zghz360, zv);
  
    goto finish_match_76;
  }
case_77: ;
  {
    fbits zuz37;
    zuz37 = zgaz332;
    bool zgsz377;
    zgsz377 = eq_bit(zuz37, UINT64_C(1));
    if (!(zgsz377)) {
  
    goto case_78;
    }
    ztwos_complement(&zghz360, zv);
  
    goto finish_match_76;
  }
case_78: ;
  sail_match_failure("abs");
finish_match_76: ;
  COPY(lbits)((*(&zcbz319)), zghz360);

end_function_79: ;
  goto end_function_196;
end_block_exception_80: ;
  goto end_function_196;
end_function_196: ;
}



void finish_zabs(void)
{
  KILL(sail_int)(&zghz362);
  KILL(sail_int)(&zghz361);
  KILL(lbits)(&zghz360);
  KILL(sail_int)(&zghz359);
}

void zmul_bitvector(lbits *rop, lbits, lbits);

sail_int zghz363;
lbits zghz364;
lbits zghz365;
lbits zghz366;
sail_int zghz367;
sail_int zghz368;
lbits zghz369;
sail_int zghz370;
sail_int zghz371;
sail_int zghz372;
lbits zghz373;
lbits zghz374;
sail_int zghz375;
sail_int zghz376;
sail_int zghz377;
sail_int zghz378;
sail_int zghz379;
sail_int zghz380;
sail_int zghz381;
sail_int zghz382;
sail_int zghz383;
sail_int zghz384;
sail_int zghz385;
sail_int zghz386;

void startup_zmul_bitvector(void)
{
  CREATE(sail_int)(&zghz363);
  CREATE(lbits)(&zghz364);
  CREATE(lbits)(&zghz365);
  CREATE(lbits)(&zghz366);
  CREATE(sail_int)(&zghz367);
  CREATE(sail_int)(&zghz368);
  CREATE(lbits)(&zghz369);
  CREATE(sail_int)(&zghz370);
  CREATE(sail_int)(&zghz371);
  CREATE(sail_int)(&zghz372);
  CREATE(lbits)(&zghz373);
  CREATE(lbits)(&zghz374);
  CREATE(sail_int)(&zghz375);
  CREATE(sail_int)(&zghz376);
  CREATE(sail_int)(&zghz377);
  CREATE(sail_int)(&zghz378);
  CREATE(sail_int)(&zghz379);
  CREATE(sail_int)(&zghz380);
  CREATE(sail_int)(&zghz381);
  CREATE(sail_int)(&zghz382);
  CREATE(sail_int)(&zghz383);
  CREATE(sail_int)(&zghz384);
  CREATE(sail_int)(&zghz385);
  CREATE(sail_int)(&zghz386);
}

void zmul_bitvector(lbits *zcbz320, lbits zmultiplicand, lbits zmultiplier)
{
  __label__ end_function_87, end_block_exception_88, end_function_195;

  {
    RECREATE(sail_int)(&zghz386);
    sail_signed(&zghz386, zmultiplicand);
    unit zgsz379;
    zgsz379 = print_int("multiplicand = ", zghz386);
  }
  {
    RECREATE(sail_int)(&zghz385);
    sail_signed(&zghz385, zmultiplier);
    unit zgsz378;
    zgsz378 = print_int("mutliplier = ", zghz385);
  }
  RECREATE(sail_int)(&zghz363);
  length_lbits(&zghz363, zmultiplier);
  RECREATE(lbits)(&zghz364);
  {
    RECREATE(sail_int)(&zghz383);
    {
      RECREATE(sail_int)(&zghz384);
      CONVERT_OF(sail_int, mach_int)(&zghz384, INT64_C(2));
      mult_int(&zghz383, zghz384, zghz363);
    }
    sign_extend(&zghz364, zmultiplicand, zghz383);
  }
  RECREATE(lbits)(&zghz365);
  {
    RECREATE(sail_int)(&zghz381);
    {
      RECREATE(sail_int)(&zghz382);
      CONVERT_OF(sail_int, mach_int)(&zghz382, INT64_C(2));
      mult_int(&zghz381, zghz382, zghz363);
    }
    sign_extend(&zghz365, zmultiplier, zghz381);
  }
  RECREATE(lbits)(&zghz366);
  {
    RECREATE(sail_int)(&zghz379);
    {
      RECREATE(sail_int)(&zghz380);
      CONVERT_OF(sail_int, mach_int)(&zghz380, INT64_C(2));
      mult_int(&zghz379, zghz380, zghz363);
    }
    zeros(&zghz366, zghz379);
  }
  {
    RECREATE(sail_int)(&zghz368);
    {
      RECREATE(sail_int)(&zghz378);
      CONVERT_OF(sail_int, mach_int)(&zghz378, INT64_C(1));
      sub_int(&zghz368, zghz363, zghz378);
    }
    int64_t zgsz384;
    {    zgsz384 = INT64_C(0);
    }
    int64_t zgsz385;
    {    zgsz385 = CONVERT_OF(mach_int, sail_int)(zghz368);
    }
    int64_t zgsz386;
    {    zgsz386 = INT64_C(1);
    }
    {
      __label__ for_start_82, for_end_83;

      int64_t zi;
      zi = zgsz384;
      unit zgsz388;
    for_start_82: ;
      {
        if ((zi > zgsz385)) goto for_end_83;
        bool zgaz337;
        {
          fbits zgaz336;
          {
            RECREATE(sail_int)(&zghz377);
            CONVERT_OF(sail_int, mach_int)(&zghz377, zi);
            zgaz336 = bitvector_access(zghz365, zghz377);
          }
          zgaz337 = eq_bit(zgaz336, UINT64_C(1));
        
        }
        if (zgaz337) {
        __label__ case_85, case_86, finish_match_84;

        unit zgsz389;
        {
          RECREATE(sail_int)(&zghz371);
          CONVERT_OF(sail_int, mach_int)(&zghz371, zi);
          RECREATE(sail_int)(&zghz372);
          {
            RECREATE(sail_int)(&zghz376);
            CONVERT_OF(sail_int, mach_int)(&zghz376, INT64_C(1));
            sub_int(&zghz372, zghz363, zghz376);
          }
          bool zgsz392;
          zgsz392 = eq_int(zghz371, zghz372);
          if (!(zgsz392))
            goto case_85;
          RECREATE(lbits)(&zghz373);
          {
            RECREATE(lbits)(&zghz374);
            {
              RECREATE(sail_int)(&zghz375);
              CONVERT_OF(sail_int, mach_int)(&zghz375, zi);
              shiftl(&zghz374, zghz364, zghz375);
            }
            ztwos_complement(&zghz373, zghz374);
          }
          add_bits(&zghz366, zghz366, zghz373);
          zgsz389 = UNIT;
          goto finish_match_84;
        }
      case_85: ;
        {
          RECREATE(lbits)(&zghz369);
          {
            RECREATE(sail_int)(&zghz370);
            CONVERT_OF(sail_int, mach_int)(&zghz370, zi);
            shiftl(&zghz369, zghz364, zghz370);
          }
          add_bits(&zghz366, zghz366, zghz369);
          zgsz389 = UNIT;
          goto finish_match_84;
        }
      case_86: ;
        sail_match_failure("mul_bitvector");
      finish_match_84: ;
        zgsz388 = zgsz389;
      
        } else {  zgsz388 = UNIT;  }
      
        zi = (zi + zgsz386);
        goto for_start_82;
      }
    for_end_83: ;
    }
    unit zgsz396;
    zgsz396 = UNIT;
  }
  {
    RECREATE(sail_int)(&zghz367);
    sail_signed(&zghz367, zghz366);
    unit zgsz395;
    zgsz395 = print_int("result = ", zghz367);
  }
  COPY(lbits)((*(&zcbz320)), zghz366);
end_function_87: ;
  goto end_function_195;
end_block_exception_88: ;
  goto end_function_195;
end_function_195: ;
}



void finish_zmul_bitvector(void)
{
  KILL(sail_int)(&zghz386);
  KILL(sail_int)(&zghz385);
  KILL(sail_int)(&zghz384);
  KILL(sail_int)(&zghz383);
  KILL(sail_int)(&zghz382);
  KILL(sail_int)(&zghz381);
  KILL(sail_int)(&zghz380);
  KILL(sail_int)(&zghz379);
  KILL(sail_int)(&zghz378);
  KILL(sail_int)(&zghz377);
  KILL(sail_int)(&zghz376);
  KILL(sail_int)(&zghz375);
  KILL(lbits)(&zghz374);
  KILL(lbits)(&zghz373);
  KILL(sail_int)(&zghz372);
  KILL(sail_int)(&zghz371);
  KILL(sail_int)(&zghz370);
  KILL(lbits)(&zghz369);
  KILL(sail_int)(&zghz368);
  KILL(sail_int)(&zghz367);
  KILL(lbits)(&zghz366);
  KILL(lbits)(&zghz365);
  KILL(lbits)(&zghz364);
  KILL(sail_int)(&zghz363);
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

sail_int zghz387;
lbits zghz388;
lbits zghz389;
lbits zghz390;
lbits zghz391;
sail_int zghz392;
sail_int zghz393;
sail_int zghz394;
sail_int zghz395;
sail_int zghz396;
sail_int zghz397;
sail_int zghz398;
lbits zghz399;
lbits zghz3100;
sail_int zghz3101;
sail_int zghz3102;
sail_int zghz3103;
sail_int zghz3104;
sail_int zghz3105;
lbits zghz3106;
sail_int zghz3107;
sail_int zghz3108;
lbits zghz3109;
sail_int zghz3110;
sail_int zghz3111;
sail_int zghz3112;
sail_int zghz3113;

void startup_zdiv_bitvector(void)
{
  CREATE(sail_int)(&zghz387);
  CREATE(lbits)(&zghz388);
  CREATE(lbits)(&zghz389);
  CREATE(lbits)(&zghz390);
  CREATE(lbits)(&zghz391);
  CREATE(sail_int)(&zghz392);
  CREATE(sail_int)(&zghz393);
  CREATE(sail_int)(&zghz394);
  CREATE(sail_int)(&zghz395);
  CREATE(sail_int)(&zghz396);
  CREATE(sail_int)(&zghz397);
  CREATE(sail_int)(&zghz398);
  CREATE(lbits)(&zghz399);
  CREATE(lbits)(&zghz3100);
  CREATE(sail_int)(&zghz3101);
  CREATE(sail_int)(&zghz3102);
  CREATE(sail_int)(&zghz3103);
  CREATE(sail_int)(&zghz3104);
  CREATE(sail_int)(&zghz3105);
  CREATE(lbits)(&zghz3106);
  CREATE(sail_int)(&zghz3107);
  CREATE(sail_int)(&zghz3108);
  CREATE(lbits)(&zghz3109);
  CREATE(sail_int)(&zghz3110);
  CREATE(sail_int)(&zghz3111);
  CREATE(sail_int)(&zghz3112);
  CREATE(sail_int)(&zghz3113);
}

void zdiv_bitvector(struct ztuple_z8z5bvzCz0z5bvz9 *zcbz321, lbits zdividend, lbits zdivisor)
{
  __label__ end_function_92, end_block_exception_93, end_function_194;

  {
    RECREATE(sail_int)(&zghz3113);
    sail_signed(&zghz3113, zdividend);
    unit zgsz398;
    zgsz398 = print_int("dividend = ", zghz3113);
  }
  {
    RECREATE(sail_int)(&zghz3112);
    sail_signed(&zghz3112, zdivisor);
    unit zgsz397;
    zgsz397 = print_int("divisor = ", zghz3112);
  }
  RECREATE(sail_int)(&zghz387);
  length_lbits(&zghz387, zdivisor);
  RECREATE(lbits)(&zghz388);
  {
    RECREATE(lbits)(&zghz3109);
    {
      RECREATE(sail_int)(&zghz3110);
      {
        RECREATE(sail_int)(&zghz3111);
        CONVERT_OF(sail_int, mach_int)(&zghz3111, INT64_C(2));
        mult_int(&zghz3110, zghz3111, zghz387);
      }
      sign_extend(&zghz3109, zdivisor, zghz3110);
    }
    zabs(&zghz388, zghz3109);
  }
  RECREATE(lbits)(&zghz389);
  {
    RECREATE(lbits)(&zghz3106);
    {
      RECREATE(sail_int)(&zghz3107);
      {
        RECREATE(sail_int)(&zghz3108);
        CONVERT_OF(sail_int, mach_int)(&zghz3108, INT64_C(2));
        mult_int(&zghz3107, zghz3108, zghz387);
      }
      sign_extend(&zghz3106, zdividend, zghz3107);
    }
    zabs(&zghz389, zghz3106);
  }
  RECREATE(lbits)(&zghz390);
  {
    RECREATE(sail_int)(&zghz3104);
    {
      RECREATE(sail_int)(&zghz3105);
      CONVERT_OF(sail_int, mach_int)(&zghz3105, INT64_C(2));
      mult_int(&zghz3104, zghz3105, zghz387);
    }
    zeros(&zghz390, zghz3104);
  }
  RECREATE(lbits)(&zghz391);
  {
    RECREATE(sail_int)(&zghz3102);
    {
      RECREATE(sail_int)(&zghz3103);
      CONVERT_OF(sail_int, mach_int)(&zghz3103, INT64_C(2));
      mult_int(&zghz3102, zghz3103, zghz387);
    }
    zeros(&zghz391, zghz3102);
  }
  {
    int64_t zgsz3103;
    {    zgsz3103 = INT64_C(0);
    }
    int64_t zgsz3104;
    {    zgsz3104 = CONVERT_OF(mach_int, sail_int)(zghz387);
    }
    int64_t zgsz3105;
    {    zgsz3105 = INT64_C(1);
    }
    {
      __label__ for_start_90, for_end_91;

      int64_t zi;
      zi = zgsz3103;
      unit zgsz3110;
    for_start_90: ;
      {
        if ((zi > zgsz3104)) goto for_end_91;
        RECREATE(sail_int)(&zghz396);
        {
          RECREATE(sail_int)(&zghz3101);
          CONVERT_OF(sail_int, mach_int)(&zghz3101, zi);
          sub_int(&zghz396, zghz387, zghz3101);
        }
        {
          bool zgaz349;
          {
            RECREATE(lbits)(&zghz3100);
            shiftl(&zghz3100, zghz388, zghz396);
            zgaz349 = zgt_bit(zghz389, zghz3100);
          }
          unit zgsz3107;
          if (zgaz349) {
          {
            RECREATE(lbits)(&zghz399);
            shiftl(&zghz399, zghz388, zghz396);
            sub_bits(&zghz389, zghz389, zghz399);
            unit zgsz3108;
            zgsz3108 = UNIT;
          }
          update_lbits(&zghz390, zghz390, zghz396, UINT64_C(1));
          zgsz3107 = UNIT;
          } else {  zgsz3107 = UNIT;  }
        
        }
        bool zgaz351;
        {
          RECREATE(sail_int)(&zghz398);
          CONVERT_OF(sail_int, mach_int)(&zghz398, INT64_C(0));
          zgaz351 = eq_int(zghz396, zghz398);
        }
        if (zgaz351) {
        {
          RECREATE(sail_int)(&zghz397);
          CONVERT_OF(sail_int, mach_int)(&zghz397, INT64_C(1));
          replicate_bits(&zghz391, zghz389, zghz397);
        }
        zgsz3110 = UNIT;
        } else {  zgsz3110 = UNIT;  }
      
        zi = (zi + zgsz3105);
        goto for_start_90;
      }
    for_end_91: ;
    }
    unit zgsz3117;
    zgsz3117 = UNIT;
  }
  {
    RECREATE(sail_int)(&zghz394);
    {
      RECREATE(sail_int)(&zghz395);
      CONVERT_OF(sail_int, mach_int)(&zghz395, INT64_C(1));
      sub_int(&zghz394, zghz387, zghz395);
    }
    bool zgaz356;
    {
      bool zgaz354;
      {
        fbits zgaz352;
        zgaz352 = bitvector_access(zdividend, zghz394);
        zgaz354 = eq_bit(zgaz352, UINT64_C(1));
      
      }
      bool zgaz355;
      {
        fbits zgaz353;
        zgaz353 = bitvector_access(zdivisor, zghz394);
        zgaz355 = eq_bit(zgaz353, UINT64_C(1));
      
      }
      zgaz356 = zxor_bool(zgaz354, zgaz355);
    
    
    }
    unit zgsz3115;
    if (zgaz356) {
    {
      ztwos_complement(&zghz390, zghz390);
      unit zgsz3116;
      zgsz3116 = UNIT;
    }
    ztwos_complement(&zghz391, zghz391);
    zgsz3115 = UNIT;
    } else {  zgsz3115 = UNIT;  }
  
  }
  {
    RECREATE(sail_int)(&zghz393);
    sail_signed(&zghz393, zghz390);
    unit zgsz3114;
    zgsz3114 = print_int("quotient = ", zghz393);
  }
  {
    RECREATE(sail_int)(&zghz392);
    sail_signed(&zghz392, zghz391);
    unit zgsz3113;
    zgsz3113 = print_int("remainder = ", zghz392);
  }
  struct ztuple_z8z5bvzCz0z5bvz9 zgsz3118;
  CREATE(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3118);
  COPY(lbits)(&((&zgsz3118)->ztup0), zghz390);
  COPY(lbits)(&((&zgsz3118)->ztup1), zghz391);
  COPY(ztuple_z8z5bvzCz0z5bvz9)((*(&zcbz321)), zgsz3118);
  KILL(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3118);
end_function_92: ;
  goto end_function_194;
end_block_exception_93: ;
  goto end_function_194;
end_function_194: ;
}



void finish_zdiv_bitvector(void)
{
  KILL(sail_int)(&zghz3113);
  KILL(sail_int)(&zghz3112);
  KILL(sail_int)(&zghz3111);
  KILL(sail_int)(&zghz3110);
  KILL(lbits)(&zghz3109);
  KILL(sail_int)(&zghz3108);
  KILL(sail_int)(&zghz3107);
  KILL(lbits)(&zghz3106);
  KILL(sail_int)(&zghz3105);
  KILL(sail_int)(&zghz3104);
  KILL(sail_int)(&zghz3103);
  KILL(sail_int)(&zghz3102);
  KILL(sail_int)(&zghz3101);
  KILL(lbits)(&zghz3100);
  KILL(lbits)(&zghz399);
  KILL(sail_int)(&zghz398);
  KILL(sail_int)(&zghz397);
  KILL(sail_int)(&zghz396);
  KILL(sail_int)(&zghz395);
  KILL(sail_int)(&zghz394);
  KILL(sail_int)(&zghz393);
  KILL(sail_int)(&zghz392);
  KILL(lbits)(&zghz391);
  KILL(lbits)(&zghz390);
  KILL(lbits)(&zghz389);
  KILL(lbits)(&zghz388);
  KILL(sail_int)(&zghz387);
}






void zdecode(struct zoption *rop, uint64_t);






unit zexecute(struct zast);



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
  __label__ case_96, case_97, case_101, case_105, case_109, case_110, case_113, case_116, case_117, case_118, case_122, case_126, case_130, case_131, case_132, case_133, case_139, case_140, case_141, case_142, case_143, case_144, case_145, finish_match_95, end_function_146, end_block_exception_147;

  unit zcbz322;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_96;
    uint64_t zrs2;
    zrs2 = zmergez3var.zRTYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zRTYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zRTYPE.ztup2;
    if ((zADD != zmergez3var.zRTYPE.ztup3)) goto case_96;
    uint64_t zrs1_val;
    zrs1_val = zrREG(zrs1);
    uint64_t zrs2_val;
    zrs2_val = zrREG(zrs2);
    uint64_t zresult;
    zresult = ((zrs1_val + zrs2_val) & UINT64_C(0xFFFFFFFF));
    zcbz322 = zwREG(zrd, zresult);
  
  
  
  
  
  
    goto finish_match_95;
  }
case_96: ;
  {
    __label__ case_99, case_100, finish_match_98;

    if (zmergez3var.kind != Kind_zRTYPE) goto case_97;
    uint64_t zuz38;
    zuz38 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz39;
    zuz39 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz310;
    zuz310 = zmergez3var.zRTYPE.ztup2;
    if ((zAND != zmergez3var.zRTYPE.ztup3)) goto case_97;
    uint64_t zuz311;
    zuz311 = zrREG(zuz39);
    uint64_t zuz312;
    zuz312 = zrREG(zuz38);
    uint64_t zbitwise_AND;
    zbitwise_AND = (zuz311 & zuz312);
    {
      uint64_t zvz31;
      zvz31 = zbitwise_AND;
      uint64_t zgaz366;
      {
        sail_int zgsz3122;
        CREATE(sail_int)(&zgsz3122);
        CONVERT_OF(sail_int, mach_int)(&zgsz3122, INT64_C(32));
        lbits zgsz3123;
        CREATE(lbits)(&zgsz3123);
        CONVERT_OF(lbits, fbits)(&zgsz3123, UINT64_C(0b1), UINT64_C(1) , true);
        lbits zgsz3124;
        CREATE(lbits)(&zgsz3124);
        zextzz(&zgsz3124, zgsz3122, zgsz3123);
        zgaz366 = CONVERT_OF(fbits, lbits)(zgsz3124, true);
        KILL(lbits)(&zgsz3124);
        KILL(lbits)(&zgsz3123);
        KILL(sail_int)(&zgsz3122);
      }
      bool zgsz3128;
      zgsz3128 = (zvz31 == zgaz366);
    
      if (!(zgsz3128)) {
    
      goto case_99;
      }
      uint64_t zgaz365;
      {
        sail_int zgsz3125;
        CREATE(sail_int)(&zgsz3125);
        CONVERT_OF(sail_int, mach_int)(&zgsz3125, INT64_C(32));
        lbits zgsz3126;
        CREATE(lbits)(&zgsz3126);
        CONVERT_OF(lbits, fbits)(&zgsz3126, UINT64_C(0b1), UINT64_C(1) , true);
        lbits zgsz3127;
        CREATE(lbits)(&zgsz3127);
        zextzz(&zgsz3127, zgsz3125, zgsz3126);
        zgaz365 = CONVERT_OF(fbits, lbits)(zgsz3127, true);
        KILL(lbits)(&zgsz3127);
        KILL(lbits)(&zgsz3126);
        KILL(sail_int)(&zgsz3125);
      }
      zcbz322 = zwREG(zuz310, zgaz365);
    
    
      goto finish_match_98;
    }
  case_99: ;
    {
      uint64_t zgaz367;
      {
        sail_int zgsz3129;
        CREATE(sail_int)(&zgsz3129);
        CONVERT_OF(sail_int, mach_int)(&zgsz3129, INT64_C(32));
        lbits zgsz3130;
        CREATE(lbits)(&zgsz3130);
        CONVERT_OF(lbits, fbits)(&zgsz3130, UINT64_C(0b0), UINT64_C(1) , true);
        lbits zgsz3131;
        CREATE(lbits)(&zgsz3131);
        zextzz(&zgsz3131, zgsz3129, zgsz3130);
        zgaz367 = CONVERT_OF(fbits, lbits)(zgsz3131, true);
        KILL(lbits)(&zgsz3131);
        KILL(lbits)(&zgsz3130);
        KILL(sail_int)(&zgsz3129);
      }
      zcbz322 = zwREG(zuz310, zgaz367);
    
      goto finish_match_98;
    }
  case_100: ;
    sail_match_failure("execute");
  finish_match_98: ;
  
  
  
  
  
  
    goto finish_match_95;
  }
case_97: ;
  {
    __label__ case_103, case_104, finish_match_102;

    if (zmergez3var.kind != Kind_zRTYPE) goto case_101;
    uint64_t zuz313;
    zuz313 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz314;
    zuz314 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz315;
    zuz315 = zmergez3var.zRTYPE.ztup2;
    if ((zOR != zmergez3var.zRTYPE.ztup3)) goto case_101;
    uint64_t zuz316;
    zuz316 = zrREG(zuz314);
    uint64_t zuz317;
    zuz317 = zrREG(zuz313);
    uint64_t zbitwise_OR;
    zbitwise_OR = (zuz316 | zuz317);
    {
      uint64_t zvz32;
      zvz32 = zbitwise_OR;
      uint64_t zgaz369;
      {
        sail_int zgsz3135;
        CREATE(sail_int)(&zgsz3135);
        CONVERT_OF(sail_int, mach_int)(&zgsz3135, INT64_C(32));
        lbits zgsz3136;
        CREATE(lbits)(&zgsz3136);
        CONVERT_OF(lbits, fbits)(&zgsz3136, UINT64_C(0b1), UINT64_C(1) , true);
        lbits zgsz3137;
        CREATE(lbits)(&zgsz3137);
        zextzz(&zgsz3137, zgsz3135, zgsz3136);
        zgaz369 = CONVERT_OF(fbits, lbits)(zgsz3137, true);
        KILL(lbits)(&zgsz3137);
        KILL(lbits)(&zgsz3136);
        KILL(sail_int)(&zgsz3135);
      }
      bool zgsz3141;
      zgsz3141 = (zvz32 == zgaz369);
    
      if (!(zgsz3141)) {
    
      goto case_103;
      }
      uint64_t zgaz368;
      {
        sail_int zgsz3138;
        CREATE(sail_int)(&zgsz3138);
        CONVERT_OF(sail_int, mach_int)(&zgsz3138, INT64_C(32));
        lbits zgsz3139;
        CREATE(lbits)(&zgsz3139);
        CONVERT_OF(lbits, fbits)(&zgsz3139, UINT64_C(0b1), UINT64_C(1) , true);
        lbits zgsz3140;
        CREATE(lbits)(&zgsz3140);
        zextzz(&zgsz3140, zgsz3138, zgsz3139);
        zgaz368 = CONVERT_OF(fbits, lbits)(zgsz3140, true);
        KILL(lbits)(&zgsz3140);
        KILL(lbits)(&zgsz3139);
        KILL(sail_int)(&zgsz3138);
      }
      zcbz322 = zwREG(zuz315, zgaz368);
    
    
      goto finish_match_102;
    }
  case_103: ;
    {
      uint64_t zgaz370;
      {
        sail_int zgsz3142;
        CREATE(sail_int)(&zgsz3142);
        CONVERT_OF(sail_int, mach_int)(&zgsz3142, INT64_C(32));
        lbits zgsz3143;
        CREATE(lbits)(&zgsz3143);
        CONVERT_OF(lbits, fbits)(&zgsz3143, UINT64_C(0b0), UINT64_C(1) , true);
        lbits zgsz3144;
        CREATE(lbits)(&zgsz3144);
        zextzz(&zgsz3144, zgsz3142, zgsz3143);
        zgaz370 = CONVERT_OF(fbits, lbits)(zgsz3144, true);
        KILL(lbits)(&zgsz3144);
        KILL(lbits)(&zgsz3143);
        KILL(sail_int)(&zgsz3142);
      }
      zcbz322 = zwREG(zuz315, zgaz370);
    
      goto finish_match_102;
    }
  case_104: ;
    sail_match_failure("execute");
  finish_match_102: ;
  
  
  
  
  
  
    goto finish_match_95;
  }
case_101: ;
  {
    __label__ case_107, case_108, finish_match_106;

    if (zmergez3var.kind != Kind_zRTYPE) goto case_105;
    uint64_t zuz318;
    zuz318 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz319;
    zuz319 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz320;
    zuz320 = zmergez3var.zRTYPE.ztup2;
    if ((zXOR != zmergez3var.zRTYPE.ztup3)) goto case_105;
    uint64_t zuz321;
    zuz321 = zrREG(zuz319);
    uint64_t zuz322;
    zuz322 = zrREG(zuz318);
    uint64_t zbitwise_XOR;
    {
      lbits zgsz3147;
      CREATE(lbits)(&zgsz3147);
      CONVERT_OF(lbits, fbits)(&zgsz3147, zuz321, UINT64_C(32) , true);
      lbits zgsz3148;
      CREATE(lbits)(&zgsz3148);
      CONVERT_OF(lbits, fbits)(&zgsz3148, zuz322, UINT64_C(32) , true);
      lbits zgsz3149;
      CREATE(lbits)(&zgsz3149);
      zxor_bitvector(&zgsz3149, zgsz3147, zgsz3148);
      zbitwise_XOR = CONVERT_OF(fbits, lbits)(zgsz3149, true);
      KILL(lbits)(&zgsz3149);
      KILL(lbits)(&zgsz3148);
      KILL(lbits)(&zgsz3147);
    }
    {
      uint64_t zvz33;
      zvz33 = zbitwise_XOR;
      uint64_t zgaz372;
      {
        sail_int zgsz3151;
        CREATE(sail_int)(&zgsz3151);
        CONVERT_OF(sail_int, mach_int)(&zgsz3151, INT64_C(32));
        lbits zgsz3152;
        CREATE(lbits)(&zgsz3152);
        CONVERT_OF(lbits, fbits)(&zgsz3152, UINT64_C(0b1), UINT64_C(1) , true);
        lbits zgsz3153;
        CREATE(lbits)(&zgsz3153);
        zextzz(&zgsz3153, zgsz3151, zgsz3152);
        zgaz372 = CONVERT_OF(fbits, lbits)(zgsz3153, true);
        KILL(lbits)(&zgsz3153);
        KILL(lbits)(&zgsz3152);
        KILL(sail_int)(&zgsz3151);
      }
      bool zgsz3157;
      zgsz3157 = (zvz33 == zgaz372);
    
      if (!(zgsz3157)) {
    
      goto case_107;
      }
      uint64_t zgaz371;
      {
        sail_int zgsz3154;
        CREATE(sail_int)(&zgsz3154);
        CONVERT_OF(sail_int, mach_int)(&zgsz3154, INT64_C(32));
        lbits zgsz3155;
        CREATE(lbits)(&zgsz3155);
        CONVERT_OF(lbits, fbits)(&zgsz3155, UINT64_C(0b1), UINT64_C(1) , true);
        lbits zgsz3156;
        CREATE(lbits)(&zgsz3156);
        zextzz(&zgsz3156, zgsz3154, zgsz3155);
        zgaz371 = CONVERT_OF(fbits, lbits)(zgsz3156, true);
        KILL(lbits)(&zgsz3156);
        KILL(lbits)(&zgsz3155);
        KILL(sail_int)(&zgsz3154);
      }
      zcbz322 = zwREG(zuz320, zgaz371);
    
    
      goto finish_match_106;
    }
  case_107: ;
    {
      uint64_t zgaz373;
      {
        sail_int zgsz3158;
        CREATE(sail_int)(&zgsz3158);
        CONVERT_OF(sail_int, mach_int)(&zgsz3158, INT64_C(32));
        lbits zgsz3159;
        CREATE(lbits)(&zgsz3159);
        CONVERT_OF(lbits, fbits)(&zgsz3159, UINT64_C(0b0), UINT64_C(1) , true);
        lbits zgsz3160;
        CREATE(lbits)(&zgsz3160);
        zextzz(&zgsz3160, zgsz3158, zgsz3159);
        zgaz373 = CONVERT_OF(fbits, lbits)(zgsz3160, true);
        KILL(lbits)(&zgsz3160);
        KILL(lbits)(&zgsz3159);
        KILL(sail_int)(&zgsz3158);
      }
      zcbz322 = zwREG(zuz320, zgaz373);
    
      goto finish_match_106;
    }
  case_108: ;
    sail_match_failure("execute");
  finish_match_106: ;
  
  
  
  
  
  
    goto finish_match_95;
  }
case_105: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_109;
    uint64_t zuz323;
    zuz323 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz324;
    zuz324 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz325;
    zuz325 = zmergez3var.zRTYPE.ztup2;
    if ((zMUL != zmergez3var.zRTYPE.ztup3)) goto case_109;
    uint64_t zmultiplicand;
    zmultiplicand = zrREG(zuz324);
    uint64_t zmultiplier;
    zmultiplier = zrREG(zuz323);
    uint64_t zproduct;
    {
      lbits zgsz3163;
      CREATE(lbits)(&zgsz3163);
      CONVERT_OF(lbits, fbits)(&zgsz3163, zmultiplicand, UINT64_C(32) , true);
      lbits zgsz3164;
      CREATE(lbits)(&zgsz3164);
      CONVERT_OF(lbits, fbits)(&zgsz3164, zmultiplier, UINT64_C(32) , true);
      lbits zgsz3165;
      CREATE(lbits)(&zgsz3165);
      zmul_bitvector(&zgsz3165, zgsz3163, zgsz3164);
      zproduct = CONVERT_OF(fbits, lbits)(zgsz3165, true);
      KILL(lbits)(&zgsz3165);
      KILL(lbits)(&zgsz3164);
      KILL(lbits)(&zgsz3163);
    }
    int64_t zlen;
    {
      sail_int zgsz3166;
      CREATE(sail_int)(&zgsz3166);
      CONVERT_OF(sail_int, mach_int)(&zgsz3166, INT64_C(32));
      sail_int zgsz3167;
      CREATE(sail_int)(&zgsz3167);
      CONVERT_OF(sail_int, mach_int)(&zgsz3167, INT64_C(1));
      sail_int zgsz3168;
      CREATE(sail_int)(&zgsz3168);
      sub_int(&zgsz3168, zgsz3166, zgsz3167);
      zlen = CONVERT_OF(mach_int, sail_int)(zgsz3168);
      KILL(sail_int)(&zgsz3168);
      KILL(sail_int)(&zgsz3167);
      KILL(sail_int)(&zgsz3166);
    }
    uint64_t zuz326;
    zuz326 = (safe_rshift(UINT64_MAX, 64 - 32) & (zproduct >> INT64_C(0)));
    zcbz322 = zwREG(zuz325, zuz326);
  
  
  
  
  
  
  
  
    goto finish_match_95;
  }
case_109: ;
  {
    __label__ case_112, finish_match_111;

    if (zmergez3var.kind != Kind_zRTYPE) goto case_110;
    uint64_t zuz327;
    zuz327 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz328;
    zuz328 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz329;
    zuz329 = zmergez3var.zRTYPE.ztup2;
    if ((zDIV != zmergez3var.zRTYPE.ztup3)) goto case_110;
    uint64_t zdividend;
    zdividend = zrREG(zuz328);
    uint64_t zdivisor;
    zdivisor = zrREG(zuz327);
    struct ztuple_z8z5bv64zCz0z5bv64z9 zgaz374;
    {
      lbits zgsz3170;
      CREATE(lbits)(&zgsz3170);
      CONVERT_OF(lbits, fbits)(&zgsz3170, zdividend, UINT64_C(32) , true);
      lbits zgsz3171;
      CREATE(lbits)(&zgsz3171);
      CONVERT_OF(lbits, fbits)(&zgsz3171, zdivisor, UINT64_C(32) , true);
      struct ztuple_z8z5bvzCz0z5bvz9 zgsz3172;
      CREATE(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3172);
      zdiv_bitvector(&zgsz3172, zgsz3170, zgsz3171);
      /* conversions */
      zgaz374.ztup0 = CONVERT_OF(fbits, lbits)(zgsz3172.ztup0, true);
      zgaz374.ztup1 = CONVERT_OF(fbits, lbits)(zgsz3172.ztup1, true);
      /* end conversions */
      KILL(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3172);
      KILL(lbits)(&zgsz3171);
      KILL(lbits)(&zgsz3170);
    }
    {
      uint64_t zdiv;
      zdiv = zgaz374.ztup0;
      uint64_t zrem;
      zrem = zgaz374.ztup1;
      int64_t zuz330;
      {
        sail_int zgsz3174;
        CREATE(sail_int)(&zgsz3174);
        CONVERT_OF(sail_int, mach_int)(&zgsz3174, INT64_C(32));
        sail_int zgsz3175;
        CREATE(sail_int)(&zgsz3175);
        CONVERT_OF(sail_int, mach_int)(&zgsz3175, INT64_C(1));
        sail_int zgsz3176;
        CREATE(sail_int)(&zgsz3176);
        sub_int(&zgsz3176, zgsz3174, zgsz3175);
        zuz330 = CONVERT_OF(mach_int, sail_int)(zgsz3176);
        KILL(sail_int)(&zgsz3176);
        KILL(sail_int)(&zgsz3175);
        KILL(sail_int)(&zgsz3174);
      }
      uint64_t zuz331;
      zuz331 = (safe_rshift(UINT64_MAX, 64 - 32) & (zdiv >> INT64_C(0)));
      zcbz322 = zwREG(zuz329, zuz331);
    
    
    
    
      goto finish_match_111;
    }
  case_112: ;
    sail_match_failure("execute");
  finish_match_111: ;
  
  
  
  
  
  
    goto finish_match_95;
  }
case_110: ;
  {
    __label__ case_115, finish_match_114;

    if (zmergez3var.kind != Kind_zRTYPE) goto case_113;
    uint64_t zuz332;
    zuz332 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz333;
    zuz333 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz334;
    zuz334 = zmergez3var.zRTYPE.ztup2;
    if ((zREM != zmergez3var.zRTYPE.ztup3)) goto case_113;
    uint64_t zuz335;
    zuz335 = zrREG(zuz333);
    uint64_t zuz336;
    zuz336 = zrREG(zuz332);
    struct ztuple_z8z5bv64zCz0z5bv64z9 zgaz375;
    {
      lbits zgsz3179;
      CREATE(lbits)(&zgsz3179);
      CONVERT_OF(lbits, fbits)(&zgsz3179, zuz335, UINT64_C(32) , true);
      lbits zgsz3180;
      CREATE(lbits)(&zgsz3180);
      CONVERT_OF(lbits, fbits)(&zgsz3180, zuz336, UINT64_C(32) , true);
      struct ztuple_z8z5bvzCz0z5bvz9 zgsz3181;
      CREATE(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3181);
      zdiv_bitvector(&zgsz3181, zgsz3179, zgsz3180);
      /* conversions */
      zgaz375.ztup0 = CONVERT_OF(fbits, lbits)(zgsz3181.ztup0, true);
      zgaz375.ztup1 = CONVERT_OF(fbits, lbits)(zgsz3181.ztup1, true);
      /* end conversions */
      KILL(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3181);
      KILL(lbits)(&zgsz3180);
      KILL(lbits)(&zgsz3179);
    }
    {
      uint64_t zuz337;
      zuz337 = zgaz375.ztup0;
      uint64_t zuz338;
      zuz338 = zgaz375.ztup1;
      int64_t zuz339;
      {
        sail_int zgsz3183;
        CREATE(sail_int)(&zgsz3183);
        CONVERT_OF(sail_int, mach_int)(&zgsz3183, INT64_C(32));
        sail_int zgsz3184;
        CREATE(sail_int)(&zgsz3184);
        CONVERT_OF(sail_int, mach_int)(&zgsz3184, INT64_C(1));
        sail_int zgsz3185;
        CREATE(sail_int)(&zgsz3185);
        sub_int(&zgsz3185, zgsz3183, zgsz3184);
        zuz339 = CONVERT_OF(mach_int, sail_int)(zgsz3185);
        KILL(sail_int)(&zgsz3185);
        KILL(sail_int)(&zgsz3184);
        KILL(sail_int)(&zgsz3183);
      }
      uint64_t zuz340;
      zuz340 = (safe_rshift(UINT64_MAX, 64 - 32) & (zuz338 >> INT64_C(0)));
      zcbz322 = zwREG(zuz334, zuz340);
    
    
    
    
      goto finish_match_114;
    }
  case_115: ;
    sail_match_failure("execute");
  finish_match_114: ;
  
  
  
  
  
  
    goto finish_match_95;
  }
case_113: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_116;
    uint64_t zimm;
    zimm = zmergez3var.zITYPE.ztup0;
    uint64_t zuz341;
    zuz341 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz342;
    zuz342 = zmergez3var.zITYPE.ztup2;
    if ((zADDI != zmergez3var.zITYPE.ztup3)) goto case_116;
    uint64_t zuz343;
    zuz343 = zrREG(zuz341);
    uint64_t zimm_ext;
    {
      sbits zgsz3188;
      zgsz3188 = CONVERT_OF(sbits, fbits)(zimm, UINT64_C(12) , true);
      zimm_ext = zEXTS(zgsz3188);
    
    }
    uint64_t zuz344;
    zuz344 = ((zuz343 + zimm_ext) & UINT64_C(0xFFFFFFFF));
    zcbz322 = zwREG(zuz342, zuz344);
  
  
  
  
  
  
    goto finish_match_95;
  }
case_116: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_117;
    uint64_t zuz345;
    zuz345 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz346;
    zuz346 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz347;
    zuz347 = zmergez3var.zITYPE.ztup2;
    if ((zSLTI != zmergez3var.zITYPE.ztup3)) goto case_117;
    uint64_t zuz348;
    zuz348 = zrREG(zuz346);
    uint64_t zuz349;
    {
      sbits zgsz3190;
      zgsz3190 = CONVERT_OF(sbits, fbits)(zuz345, UINT64_C(12) , true);
      zuz349 = zEXTS(zgsz3190);
    
    }
    bool zgaz376;
    {
      lbits zgsz3192;
      CREATE(lbits)(&zgsz3192);
      CONVERT_OF(lbits, fbits)(&zgsz3192, zuz349, UINT64_C(32) , true);
      lbits zgsz3191;
      CREATE(lbits)(&zgsz3191);
      CONVERT_OF(lbits, fbits)(&zgsz3191, zuz348, UINT64_C(32) , true);
      zgaz376 = zlt_bit(zgsz3191, zgsz3192);
      KILL(lbits)(&zgsz3192);
      KILL(lbits)(&zgsz3191);
    }
    if (zgaz376) {
    uint64_t zgaz377;
    {
      sail_int zgsz3197;
      CREATE(sail_int)(&zgsz3197);
      CONVERT_OF(sail_int, mach_int)(&zgsz3197, INT64_C(32));
      lbits zgsz3198;
      CREATE(lbits)(&zgsz3198);
      CONVERT_OF(lbits, fbits)(&zgsz3198, UINT64_C(0b1), UINT64_C(1) , true);
      lbits zgsz3199;
      CREATE(lbits)(&zgsz3199);
      zextzz(&zgsz3199, zgsz3197, zgsz3198);
      zgaz377 = CONVERT_OF(fbits, lbits)(zgsz3199, true);
      KILL(lbits)(&zgsz3199);
      KILL(lbits)(&zgsz3198);
      KILL(sail_int)(&zgsz3197);
    }
    zcbz322 = zwREG(zuz347, zgaz377);
  
    } else {
    uint64_t zgaz378;
    {
      sail_int zgsz3194;
      CREATE(sail_int)(&zgsz3194);
      CONVERT_OF(sail_int, mach_int)(&zgsz3194, INT64_C(32));
      lbits zgsz3195;
      CREATE(lbits)(&zgsz3195);
      CONVERT_OF(lbits, fbits)(&zgsz3195, UINT64_C(0b0), UINT64_C(1) , true);
      lbits zgsz3196;
      CREATE(lbits)(&zgsz3196);
      zextzz(&zgsz3196, zgsz3194, zgsz3195);
      zgaz378 = CONVERT_OF(fbits, lbits)(zgsz3196, true);
      KILL(lbits)(&zgsz3196);
      KILL(lbits)(&zgsz3195);
      KILL(sail_int)(&zgsz3194);
    }
    zcbz322 = zwREG(zuz347, zgaz378);
  
    }
  
  
  
  
  
  
    goto finish_match_95;
  }
case_117: ;
  {
    __label__ case_120, case_121, finish_match_119;

    if (zmergez3var.kind != Kind_zITYPE) goto case_118;
    uint64_t zuz350;
    zuz350 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz351;
    zuz351 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz352;
    zuz352 = zmergez3var.zITYPE.ztup2;
    if ((zANDI != zmergez3var.zITYPE.ztup3)) goto case_118;
    uint64_t zuz353;
    zuz353 = zrREG(zuz351);
    uint64_t zuz354;
    {
      sbits zgsz3200;
      zgsz3200 = CONVERT_OF(sbits, fbits)(zuz350, UINT64_C(12) , true);
      zuz354 = zEXTS(zgsz3200);
    
    }
    uint64_t zuz355;
    zuz355 = (zuz353 & zuz354);
    {
      uint64_t zvz34;
      zvz34 = zuz355;
      uint64_t zgaz380;
      {
        sail_int zgsz3202;
        CREATE(sail_int)(&zgsz3202);
        CONVERT_OF(sail_int, mach_int)(&zgsz3202, INT64_C(32));
        lbits zgsz3203;
        CREATE(lbits)(&zgsz3203);
        CONVERT_OF(lbits, fbits)(&zgsz3203, UINT64_C(0b1), UINT64_C(1) , true);
        lbits zgsz3204;
        CREATE(lbits)(&zgsz3204);
        zextzz(&zgsz3204, zgsz3202, zgsz3203);
        zgaz380 = CONVERT_OF(fbits, lbits)(zgsz3204, true);
        KILL(lbits)(&zgsz3204);
        KILL(lbits)(&zgsz3203);
        KILL(sail_int)(&zgsz3202);
      }
      bool zgsz3208;
      zgsz3208 = (zvz34 == zgaz380);
    
      if (!(zgsz3208)) {
    
      goto case_120;
      }
      uint64_t zgaz379;
      {
        sail_int zgsz3205;
        CREATE(sail_int)(&zgsz3205);
        CONVERT_OF(sail_int, mach_int)(&zgsz3205, INT64_C(32));
        lbits zgsz3206;
        CREATE(lbits)(&zgsz3206);
        CONVERT_OF(lbits, fbits)(&zgsz3206, UINT64_C(0b1), UINT64_C(1) , true);
        lbits zgsz3207;
        CREATE(lbits)(&zgsz3207);
        zextzz(&zgsz3207, zgsz3205, zgsz3206);
        zgaz379 = CONVERT_OF(fbits, lbits)(zgsz3207, true);
        KILL(lbits)(&zgsz3207);
        KILL(lbits)(&zgsz3206);
        KILL(sail_int)(&zgsz3205);
      }
      zcbz322 = zwREG(zuz352, zgaz379);
    
    
      goto finish_match_119;
    }
  case_120: ;
    {
      uint64_t zgaz381;
      {
        sail_int zgsz3209;
        CREATE(sail_int)(&zgsz3209);
        CONVERT_OF(sail_int, mach_int)(&zgsz3209, INT64_C(32));
        lbits zgsz3210;
        CREATE(lbits)(&zgsz3210);
        CONVERT_OF(lbits, fbits)(&zgsz3210, UINT64_C(0b0), UINT64_C(1) , true);
        lbits zgsz3211;
        CREATE(lbits)(&zgsz3211);
        zextzz(&zgsz3211, zgsz3209, zgsz3210);
        zgaz381 = CONVERT_OF(fbits, lbits)(zgsz3211, true);
        KILL(lbits)(&zgsz3211);
        KILL(lbits)(&zgsz3210);
        KILL(sail_int)(&zgsz3209);
      }
      zcbz322 = zwREG(zuz352, zgaz381);
    
      goto finish_match_119;
    }
  case_121: ;
    sail_match_failure("execute");
  finish_match_119: ;
  
  
  
  
  
  
    goto finish_match_95;
  }
case_118: ;
  {
    __label__ case_124, case_125, finish_match_123;

    if (zmergez3var.kind != Kind_zITYPE) goto case_122;
    uint64_t zuz356;
    zuz356 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz357;
    zuz357 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz358;
    zuz358 = zmergez3var.zITYPE.ztup2;
    if ((zORI != zmergez3var.zITYPE.ztup3)) goto case_122;
    uint64_t zuz359;
    zuz359 = zrREG(zuz357);
    uint64_t zuz360;
    {
      sbits zgsz3214;
      zgsz3214 = CONVERT_OF(sbits, fbits)(zuz356, UINT64_C(12) , true);
      zuz360 = zEXTS(zgsz3214);
    
    }
    uint64_t zuz361;
    zuz361 = (zuz359 | zuz360);
    {
      uint64_t zvz35;
      zvz35 = zuz361;
      uint64_t zgaz383;
      {
        sail_int zgsz3216;
        CREATE(sail_int)(&zgsz3216);
        CONVERT_OF(sail_int, mach_int)(&zgsz3216, INT64_C(32));
        lbits zgsz3217;
        CREATE(lbits)(&zgsz3217);
        CONVERT_OF(lbits, fbits)(&zgsz3217, UINT64_C(0b1), UINT64_C(1) , true);
        lbits zgsz3218;
        CREATE(lbits)(&zgsz3218);
        zextzz(&zgsz3218, zgsz3216, zgsz3217);
        zgaz383 = CONVERT_OF(fbits, lbits)(zgsz3218, true);
        KILL(lbits)(&zgsz3218);
        KILL(lbits)(&zgsz3217);
        KILL(sail_int)(&zgsz3216);
      }
      bool zgsz3222;
      zgsz3222 = (zvz35 == zgaz383);
    
      if (!(zgsz3222)) {
    
      goto case_124;
      }
      uint64_t zgaz382;
      {
        sail_int zgsz3219;
        CREATE(sail_int)(&zgsz3219);
        CONVERT_OF(sail_int, mach_int)(&zgsz3219, INT64_C(32));
        lbits zgsz3220;
        CREATE(lbits)(&zgsz3220);
        CONVERT_OF(lbits, fbits)(&zgsz3220, UINT64_C(0b1), UINT64_C(1) , true);
        lbits zgsz3221;
        CREATE(lbits)(&zgsz3221);
        zextzz(&zgsz3221, zgsz3219, zgsz3220);
        zgaz382 = CONVERT_OF(fbits, lbits)(zgsz3221, true);
        KILL(lbits)(&zgsz3221);
        KILL(lbits)(&zgsz3220);
        KILL(sail_int)(&zgsz3219);
      }
      zcbz322 = zwREG(zuz358, zgaz382);
    
    
      goto finish_match_123;
    }
  case_124: ;
    {
      uint64_t zgaz384;
      {
        sail_int zgsz3223;
        CREATE(sail_int)(&zgsz3223);
        CONVERT_OF(sail_int, mach_int)(&zgsz3223, INT64_C(32));
        lbits zgsz3224;
        CREATE(lbits)(&zgsz3224);
        CONVERT_OF(lbits, fbits)(&zgsz3224, UINT64_C(0b0), UINT64_C(1) , true);
        lbits zgsz3225;
        CREATE(lbits)(&zgsz3225);
        zextzz(&zgsz3225, zgsz3223, zgsz3224);
        zgaz384 = CONVERT_OF(fbits, lbits)(zgsz3225, true);
        KILL(lbits)(&zgsz3225);
        KILL(lbits)(&zgsz3224);
        KILL(sail_int)(&zgsz3223);
      }
      zcbz322 = zwREG(zuz358, zgaz384);
    
      goto finish_match_123;
    }
  case_125: ;
    sail_match_failure("execute");
  finish_match_123: ;
  
  
  
  
  
  
    goto finish_match_95;
  }
case_122: ;
  {
    __label__ case_128, case_129, finish_match_127;

    if (zmergez3var.kind != Kind_zITYPE) goto case_126;
    uint64_t zuz362;
    zuz362 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz363;
    zuz363 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz364;
    zuz364 = zmergez3var.zITYPE.ztup2;
    if ((zXORI != zmergez3var.zITYPE.ztup3)) goto case_126;
    uint64_t zuz365;
    zuz365 = zrREG(zuz363);
    uint64_t zuz366;
    {
      sbits zgsz3228;
      zgsz3228 = CONVERT_OF(sbits, fbits)(zuz362, UINT64_C(12) , true);
      zuz366 = zEXTS(zgsz3228);
    
    }
    uint64_t zuz367;
    {
      lbits zgsz3229;
      CREATE(lbits)(&zgsz3229);
      CONVERT_OF(lbits, fbits)(&zgsz3229, zuz365, UINT64_C(32) , true);
      lbits zgsz3230;
      CREATE(lbits)(&zgsz3230);
      CONVERT_OF(lbits, fbits)(&zgsz3230, zuz366, UINT64_C(32) , true);
      lbits zgsz3231;
      CREATE(lbits)(&zgsz3231);
      zxor_bitvector(&zgsz3231, zgsz3229, zgsz3230);
      zuz367 = CONVERT_OF(fbits, lbits)(zgsz3231, true);
      KILL(lbits)(&zgsz3231);
      KILL(lbits)(&zgsz3230);
      KILL(lbits)(&zgsz3229);
    }
    {
      uint64_t zvz36;
      zvz36 = zuz367;
      uint64_t zgaz386;
      {
        sail_int zgsz3233;
        CREATE(sail_int)(&zgsz3233);
        CONVERT_OF(sail_int, mach_int)(&zgsz3233, INT64_C(32));
        lbits zgsz3234;
        CREATE(lbits)(&zgsz3234);
        CONVERT_OF(lbits, fbits)(&zgsz3234, UINT64_C(0b1), UINT64_C(1) , true);
        lbits zgsz3235;
        CREATE(lbits)(&zgsz3235);
        zextzz(&zgsz3235, zgsz3233, zgsz3234);
        zgaz386 = CONVERT_OF(fbits, lbits)(zgsz3235, true);
        KILL(lbits)(&zgsz3235);
        KILL(lbits)(&zgsz3234);
        KILL(sail_int)(&zgsz3233);
      }
      bool zgsz3239;
      zgsz3239 = (zvz36 == zgaz386);
    
      if (!(zgsz3239)) {
    
      goto case_128;
      }
      uint64_t zgaz385;
      {
        sail_int zgsz3236;
        CREATE(sail_int)(&zgsz3236);
        CONVERT_OF(sail_int, mach_int)(&zgsz3236, INT64_C(32));
        lbits zgsz3237;
        CREATE(lbits)(&zgsz3237);
        CONVERT_OF(lbits, fbits)(&zgsz3237, UINT64_C(0b1), UINT64_C(1) , true);
        lbits zgsz3238;
        CREATE(lbits)(&zgsz3238);
        zextzz(&zgsz3238, zgsz3236, zgsz3237);
        zgaz385 = CONVERT_OF(fbits, lbits)(zgsz3238, true);
        KILL(lbits)(&zgsz3238);
        KILL(lbits)(&zgsz3237);
        KILL(sail_int)(&zgsz3236);
      }
      zcbz322 = zwREG(zuz364, zgaz385);
    
    
      goto finish_match_127;
    }
  case_128: ;
    {
      uint64_t zgaz387;
      {
        sail_int zgsz3240;
        CREATE(sail_int)(&zgsz3240);
        CONVERT_OF(sail_int, mach_int)(&zgsz3240, INT64_C(32));
        lbits zgsz3241;
        CREATE(lbits)(&zgsz3241);
        CONVERT_OF(lbits, fbits)(&zgsz3241, UINT64_C(0b0), UINT64_C(1) , true);
        lbits zgsz3242;
        CREATE(lbits)(&zgsz3242);
        zextzz(&zgsz3242, zgsz3240, zgsz3241);
        zgaz387 = CONVERT_OF(fbits, lbits)(zgsz3242, true);
        KILL(lbits)(&zgsz3242);
        KILL(lbits)(&zgsz3241);
        KILL(sail_int)(&zgsz3240);
      }
      zcbz322 = zwREG(zuz364, zgaz387);
    
      goto finish_match_127;
    }
  case_129: ;
    sail_match_failure("execute");
  finish_match_127: ;
  
  
  
  
  
  
    goto finish_match_95;
  }
case_126: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_130;
    uint64_t zuz368;
    zuz368 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz369;
    zuz369 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz370;
    zuz370 = zmergez3var.zITYPE.ztup2;
    if ((zJALR != zmergez3var.zITYPE.ztup3)) goto case_130;
    {
      uint64_t zgaz388;
      {
        lbits zgsz3245;
        CREATE(lbits)(&zgsz3245);
        CONVERT_OF(lbits, fbits)(&zgsz3245, zPC, UINT64_C(32) , true);
        sail_int zgsz3246;
        CREATE(sail_int)(&zgsz3246);
        CONVERT_OF(sail_int, mach_int)(&zgsz3246, INT64_C(4));
        lbits zgsz3247;
        CREATE(lbits)(&zgsz3247);
        add_bits_int(&zgsz3247, zgsz3245, zgsz3246);
        zgaz388 = CONVERT_OF(fbits, lbits)(zgsz3247, true);
        KILL(lbits)(&zgsz3247);
        KILL(sail_int)(&zgsz3246);
        KILL(lbits)(&zgsz3245);
      }
      unit zgsz3248;
      zgsz3248 = zwREG(zuz370, zgaz388);
    
    }
    uint64_t zuz371;
    zuz371 = zrREG(zuz369);
    uint64_t zuz372;
    {
      sbits zgsz3249;
      zgsz3249 = CONVERT_OF(sbits, fbits)(zuz368, UINT64_C(12) , true);
      zuz372 = zEXTS(zgsz3249);
    
    }
    uint64_t znewPC;
    znewPC = ((zuz371 + zuz372) & UINT64_C(0xFFFFFFFF));
    {
      {
        lbits zgsz3250;
        CREATE(lbits)(&zgsz3250);
        CONVERT_OF(lbits, fbits)(&zgsz3250, znewPC, UINT64_C(32) , true);
        sail_int zgsz3251;
        CREATE(sail_int)(&zgsz3251);
        CONVERT_OF(sail_int, mach_int)(&zgsz3251, INT64_C(0));
        lbits zgsz3252;
        CREATE(lbits)(&zgsz3252);
        update_lbits(&zgsz3252, zgsz3250, zgsz3251, UINT64_C(0));
        znewPC = CONVERT_OF(fbits, lbits)(zgsz3252, true);
        KILL(lbits)(&zgsz3252);
        KILL(sail_int)(&zgsz3251);
        KILL(lbits)(&zgsz3250);
      }
      unit zgsz3253;
      zgsz3253 = UNIT;
    }
    zPC = znewPC;
    zcbz322 = UNIT;
  
  
  
  
  
  
    goto finish_match_95;
  }
case_130: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_131;
    uint64_t zuz373;
    zuz373 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz374;
    zuz374 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz375;
    zuz375 = zmergez3var.zITYPE.ztup2;
    if ((zLW != zmergez3var.zITYPE.ztup3)) goto case_131;
    uint64_t zuz376;
    zuz376 = zrREG(zuz374);
    uint64_t zuz377;
    {
      sbits zgsz3255;
      zgsz3255 = CONVERT_OF(sbits, fbits)(zuz373, UINT64_C(12) , true);
      zuz377 = zEXTS(zgsz3255);
    
    }
    uint64_t zaddr;
    zaddr = ((zuz376 + zuz377) & UINT64_C(0xFFFFFFFF));
    uint64_t zmem_val;
    zmem_val = zread_mem(zaddr);
    zcbz322 = zwREG(zuz375, zmem_val);
  
  
  
  
  
  
  
    goto finish_match_95;
  }
case_131: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_132;
    uint64_t zuz378;
    zuz378 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz379;
    zuz379 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz380;
    zuz380 = zmergez3var.zITYPE.ztup2;
    if ((zSLLI != zmergez3var.zITYPE.ztup3)) goto case_132;
    uint64_t zuz381;
    zuz381 = zrREG(zuz379);
    uint64_t zuz382;
    {
      sbits zgsz3257;
      zgsz3257 = CONVERT_OF(sbits, fbits)(zuz378, UINT64_C(12) , true);
      zuz382 = zEXTS(zgsz3257);
    
    }
    bool zgaz389;
    zgaz389 = (zuz381 == zuz382);
    if (zgaz389) {
    uint64_t zgaz390;
    {
      sail_int zgsz3262;
      CREATE(sail_int)(&zgsz3262);
      CONVERT_OF(sail_int, mach_int)(&zgsz3262, INT64_C(32));
      lbits zgsz3263;
      CREATE(lbits)(&zgsz3263);
      CONVERT_OF(lbits, fbits)(&zgsz3263, UINT64_C(0b1), UINT64_C(1) , true);
      lbits zgsz3264;
      CREATE(lbits)(&zgsz3264);
      zextzz(&zgsz3264, zgsz3262, zgsz3263);
      zgaz390 = CONVERT_OF(fbits, lbits)(zgsz3264, true);
      KILL(lbits)(&zgsz3264);
      KILL(lbits)(&zgsz3263);
      KILL(sail_int)(&zgsz3262);
    }
    zcbz322 = zwREG(zuz380, zgaz390);
  
    } else {
    uint64_t zgaz391;
    {
      sail_int zgsz3259;
      CREATE(sail_int)(&zgsz3259);
      CONVERT_OF(sail_int, mach_int)(&zgsz3259, INT64_C(32));
      lbits zgsz3260;
      CREATE(lbits)(&zgsz3260);
      CONVERT_OF(lbits, fbits)(&zgsz3260, UINT64_C(0b0), UINT64_C(1) , true);
      lbits zgsz3261;
      CREATE(lbits)(&zgsz3261);
      zextzz(&zgsz3261, zgsz3259, zgsz3260);
      zgaz391 = CONVERT_OF(fbits, lbits)(zgsz3261, true);
      KILL(lbits)(&zgsz3261);
      KILL(lbits)(&zgsz3260);
      KILL(sail_int)(&zgsz3259);
    }
    zcbz322 = zwREG(zuz380, zgaz391);
  
    }
  
  
  
  
  
  
    goto finish_match_95;
  }
case_132: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_133;
    uint64_t zuz383;
    zuz383 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz384;
    zuz384 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz385;
    zuz385 = zmergez3var.zITYPE.ztup2;
    if ((zLB != zmergez3var.zITYPE.ztup3)) goto case_133;
    {
      za0 = zPC;
      unit zgsz3265;
      zgsz3265 = UNIT;
    }
    bool zcontinue_loop;
    zcontinue_loop = true;
    {
      __label__ while_134, wend_135;

      bool zgsz3271;
      unit zgsz3272;
    while_134: ;
      {
        __label__ case_137, case_138, finish_match_136;

        zgsz3271 = zcontinue_loop;
        if (!(zgsz3271)) goto wend_135;
        uint64_t zinstruction;
        {
          uint64_t zgaz393;
          zgaz393 = *(&zPC);
          zinstruction = zread_mem(zgaz393);
        
        }
        struct zoption zdecoded_instruction;
        CREATE(zoption)(&zdecoded_instruction);
        zdecode(&zdecoded_instruction, zinstruction);
        {
          if (zdecoded_instruction.kind != Kind_zSomez3z5unionz0zzast) goto case_137;
          if (zdecoded_instruction.zSomez3z5unionz0zzast.kind != Kind_zITYPE) goto case_137;
          uint64_t zimmshadowz31;
          zimmshadowz31 = zdecoded_instruction.zSomez3z5unionz0zzast.zITYPE.ztup0;
          uint64_t zrs1shadowz33;
          zrs1shadowz33 = zdecoded_instruction.zSomez3z5unionz0zzast.zITYPE.ztup1;
          uint64_t zrdshadowz32;
          zrdshadowz32 = zdecoded_instruction.zSomez3z5unionz0zzast.zITYPE.ztup2;
          if ((zLH != zdecoded_instruction.zSomez3z5unionz0zzast.zITYPE.ztup3)) goto case_137;
          {
            struct zast zgaz392;
            CREATE(zast)(&zgaz392);
            {
              struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3267;
              zgsz3267.ztup0 = zimmshadowz31;
              zgsz3267.ztup1 = zrs1shadowz33;
              zgsz3267.ztup2 = zrdshadowz32;
              zgsz3267.ztup3 = zLH;
              zITYPE(&zgaz392, zgsz3267);
            
            }
            unit zgsz3268;
            zgsz3268 = zexecute(zgaz392);
            KILL(zast)(&zgaz392);
          }
          zcontinue_loop = false;
          zgsz3272 = UNIT;
        
        
        
          goto finish_match_136;
        }
      case_137: ;
        {
          zgsz3272 = zinc_PC(UNIT);
          goto finish_match_136;
        }
      case_138: ;
        sail_match_failure("execute");
      finish_match_136: ;
        KILL(zoption)(&zdecoded_instruction);
      
        goto while_134;
      }
    wend_135: ;
      unit zgsz3273;
      zgsz3273 = UNIT;
    }
    zPC = za0;
    zcbz322 = UNIT;
  
  
  
  
    goto finish_match_95;
  }
case_133: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_139;
    uint64_t zuz386;
    zuz386 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz387;
    zuz387 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz388;
    zuz388 = zmergez3var.zITYPE.ztup2;
    if ((zLH != zmergez3var.zITYPE.ztup3)) goto case_139;
    za1 = zPC;
    zcbz322 = UNIT;
  
  
  
    goto finish_match_95;
  }
case_139: ;
  {
    if (zmergez3var.kind != Kind_zSTYPE) goto case_140;
    uint64_t zimm2;
    zimm2 = zmergez3var.zSTYPE.ztup0;
    uint64_t zuz389;
    zuz389 = zmergez3var.zSTYPE.ztup1;
    uint64_t zuz390;
    zuz390 = zmergez3var.zSTYPE.ztup2;
    uint64_t zimm1;
    zimm1 = zmergez3var.zSTYPE.ztup3;
    if ((zSW != zmergez3var.zSTYPE.ztup4)) goto case_140;
    uint64_t zuz391;
    zuz391 = zrREG(zuz390);
    uint64_t zuz392;
    {
      uint64_t zgaz394;
      zgaz394 = (zimm2 << 5) | zimm1;
      {
        sbits zgsz3276;
        zgsz3276 = CONVERT_OF(sbits, fbits)(zgaz394, UINT64_C(12) , true);
        zuz392 = zEXTS(zgsz3276);
      
      }
    
    }
    uint64_t zuz393;
    zuz393 = ((zuz391 + zuz392) & UINT64_C(0xFFFFFFFF));
    uint64_t zuz394;
    zuz394 = zrREG(zuz389);
    zcbz322 = zwrite_mem(zuz393, zuz394);
  
  
  
  
  
  
  
  
    goto finish_match_95;
  }
case_140: ;
  {
    if (zmergez3var.kind != Kind_zBTYPE) goto case_141;
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
    if ((zBEQ != zmergez3var.zBTYPE.ztup6)) goto case_141;
    uint64_t zuz399;
    zuz399 = zrREG(zuz397);
    uint64_t zuz3100;
    zuz3100 = zrREG(zuz396);
    bool zgaz395;
    zgaz395 = (zuz399 == zuz3100);
    if (zgaz395) {
    uint64_t zoffset;
    {
      uint64_t zgaz398;
      {
        uint64_t zgaz397;
        {
          uint64_t zgaz396;
          zgaz396 = (zuz395 << 4) | zuz398;
          zgaz397 = (zimm3 << 10) | zgaz396;
        
        }
        zgaz398 = (zimm4 << 11) | zgaz397;
      
      }
      {
        sbits zgsz3279;
        zgsz3279 = CONVERT_OF(sbits, fbits)(zgaz398, UINT64_C(12) , true);
        zoffset = zEXTS(zgsz3279);
      
      }
    
    }
    zPC = ((zPC + zoffset) & UINT64_C(0xFFFFFFFF));
    zcbz322 = UNIT;
  
    } else {  zcbz322 = UNIT;  }
  
  
  
  
  
  
  
  
  
    goto finish_match_95;
  }
case_141: ;
  {
    if (zmergez3var.kind != Kind_zBTYPE) goto case_142;
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
    if ((zBNE != zmergez3var.zBTYPE.ztup6)) goto case_142;
    uint64_t zuz3107;
    zuz3107 = zrREG(zuz3104);
    uint64_t zuz3108;
    zuz3108 = zrREG(zuz3103);
    bool zgaz399;
    zgaz399 = (zuz3107 != zuz3108);
    if (zgaz399) {
    uint64_t zuz3109;
    {
      uint64_t zgaz3102;
      {
        uint64_t zgaz3101;
        {
          uint64_t zgaz3100;
          zgaz3100 = (zuz3102 << 4) | zuz3105;
          zgaz3101 = (zuz3106 << 10) | zgaz3100;
        
        }
        zgaz3102 = (zuz3101 << 11) | zgaz3101;
      
      }
      {
        sbits zgsz3281;
        zgsz3281 = CONVERT_OF(sbits, fbits)(zgaz3102, UINT64_C(12) , true);
        zuz3109 = zEXTS(zgsz3281);
      
      }
    
    }
    zPC = ((zPC + zuz3109) & UINT64_C(0xFFFFFFFF));
    zcbz322 = UNIT;
  
    } else {  zcbz322 = UNIT;  }
  
  
  
  
  
  
  
  
  
    goto finish_match_95;
  }
case_142: ;
  {
    if (zmergez3var.kind != Kind_zUTYPE) goto case_143;
    uint64_t zuz3110;
    zuz3110 = zmergez3var.zUTYPE.ztup0;
    uint64_t zuz3111;
    zuz3111 = zmergez3var.zUTYPE.ztup1;
    if ((zLUI != zmergez3var.zUTYPE.ztup2)) goto case_143;
    uint64_t zgaz3104;
    {
      uint64_t zgaz3103;
      {
        sail_int zgsz3282;
        CREATE(sail_int)(&zgsz3282);
        CONVERT_OF(sail_int, mach_int)(&zgsz3282, INT64_C(12));
        lbits zgsz3283;
        CREATE(lbits)(&zgsz3283);
        zeros(&zgsz3283, zgsz3282);
        zgaz3103 = CONVERT_OF(fbits, lbits)(zgsz3283, true);
        KILL(lbits)(&zgsz3283);
        KILL(sail_int)(&zgsz3282);
      }
      zgaz3104 = (zuz3110 << 12) | zgaz3103;
    
    }
    zcbz322 = zwREG(zuz3111, zgaz3104);
  
  
  
    goto finish_match_95;
  }
case_143: ;
  {
    if (zmergez3var.kind != Kind_zUTYPE) goto case_144;
    uint64_t zuz3112;
    zuz3112 = zmergez3var.zUTYPE.ztup0;
    uint64_t zuz3113;
    zuz3113 = zmergez3var.zUTYPE.ztup1;
    if ((zAUIPC != zmergez3var.zUTYPE.ztup2)) goto case_144;
    uint64_t zuz3114;
    {
      uint64_t zgaz3106;
      {
        sail_int zgsz3285;
        CREATE(sail_int)(&zgsz3285);
        CONVERT_OF(sail_int, mach_int)(&zgsz3285, INT64_C(12));
        lbits zgsz3286;
        CREATE(lbits)(&zgsz3286);
        zeros(&zgsz3286, zgsz3285);
        zgaz3106 = CONVERT_OF(fbits, lbits)(zgsz3286, true);
        KILL(lbits)(&zgsz3286);
        KILL(sail_int)(&zgsz3285);
      }
      zuz3114 = (zuz3112 << 12) | zgaz3106;
    
    }
    uint64_t zgaz3105;
    zgaz3105 = ((zPC + zuz3114) & UINT64_C(0xFFFFFFFF));
    zcbz322 = zwREG(zuz3113, zgaz3105);
  
  
  
  
    goto finish_match_95;
  }
case_144: ;
  {
    if (zmergez3var.kind != Kind_zJTYPE) goto case_145;
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
    if ((zJAL != zmergez3var.zJTYPE.ztup5)) goto case_145;
    {
      uint64_t zgaz3107;
      {
        lbits zgsz3288;
        CREATE(lbits)(&zgsz3288);
        CONVERT_OF(lbits, fbits)(&zgsz3288, zPC, UINT64_C(32) , true);
        sail_int zgsz3289;
        CREATE(sail_int)(&zgsz3289);
        CONVERT_OF(sail_int, mach_int)(&zgsz3289, INT64_C(4));
        lbits zgsz3290;
        CREATE(lbits)(&zgsz3290);
        add_bits_int(&zgsz3290, zgsz3288, zgsz3289);
        zgaz3107 = CONVERT_OF(fbits, lbits)(zgsz3290, true);
        KILL(lbits)(&zgsz3290);
        KILL(sail_int)(&zgsz3289);
        KILL(lbits)(&zgsz3288);
      }
      unit zgsz3291;
      zgsz3291 = zwREG(zuz3119, zgaz3107);
    
    }
    uint64_t zuz3120;
    {
      uint64_t zgaz3110;
      {
        uint64_t zgaz3109;
        {
          uint64_t zgaz3108;
          zgaz3108 = (zuz3117 << 10) | zuz3116;
          zgaz3109 = (zuz3118 << 11) | zgaz3108;
        
        }
        zgaz3110 = (zuz3115 << 19) | zgaz3109;
      
      }
      {
        sbits zgsz3292;
        zgsz3292 = CONVERT_OF(sbits, fbits)(zgaz3110, UINT64_C(20) , true);
        zuz3120 = zEXTS(zgsz3292);
      
      }
    
    }
    zPC = ((zPC + zuz3120) & UINT64_C(0xFFFFFFFF));
    zcbz322 = UNIT;
  
  
  
  
  
  
    goto finish_match_95;
  }
case_145: ;
  sail_match_failure("execute");
finish_match_95: ;
end_function_146: ;
  return zcbz322;
end_block_exception_147: ;

  return UNIT;
}


















void zdecode(struct zoption *zcbz323, uint64_t zmergez3var)
{
  __label__ case_150, case_151, case_152, case_153, case_154, case_155, case_156, case_157, case_158, case_159, case_160, case_161, case_162, case_163, case_164, case_165, case_166, case_167, case_168, case_169, case_170, case_171, case_172, case_173, case_174, finish_match_149, end_function_175, end_block_exception_176, end_function_193;

  struct zoption zgsz3294;
  CREATE(zoption)(&zgsz3294);
  {
    uint64_t zv__0;
    zv__0 = zmergez3var;
    bool zgaz3114;
    {
      uint64_t zgaz3112;
      zgaz3112 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__0 >> INT64_C(25)));
      zgaz3114 = (zgaz3112 == UINT64_C(0b0000000));
    
    }
    bool zgsz3295;
    if (zgaz3114) {
    uint64_t zgaz3113;
    zgaz3113 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__0 >> INT64_C(0)));
    zgsz3295 = (zgaz3113 == UINT64_C(0b0110011));
  
    } else {  zgsz3295 = false;  }
    bool zgsz3297;
    zgsz3297 = zgsz3295;
  
    if (!(zgsz3297)) {
  
    goto case_150;
    }
    uint64_t zrs2;
    zrs2 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(20)));
    uint64_t zrs1;
    zrs1 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(15)));
    uint64_t zrd;
    zrd = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(7)));
    struct zast zgaz3111;
    CREATE(zast)(&zgaz3111);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3296;
      zgsz3296.ztup0 = zrs2;
      zgsz3296.ztup1 = zrs1;
      zgsz3296.ztup2 = zrd;
      zgsz3296.ztup3 = zADD;
      zRTYPE(&zgaz3111, zgsz3296);
    
    }
    {
      struct zast zgsz3398;
      CREATE(zast)(&zgsz3398);
      COPY(zast)(&zgsz3398, zgaz3111);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3398);
      KILL(zast)(&zgsz3398);
    }
    KILL(zast)(&zgaz3111);
  
  
  
  
    goto finish_match_149;
  }
case_150: ;
  {
    uint64_t zv__3;
    zv__3 = zmergez3var;
    bool zgaz3118;
    {
      uint64_t zgaz3116;
      zgaz3116 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__3 >> INT64_C(25)));
      zgaz3118 = (zgaz3116 == UINT64_C(0b0000000));
    
    }
    bool zgsz3298;
    if (zgaz3118) {
    uint64_t zgaz3117;
    zgaz3117 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__3 >> INT64_C(0)));
    zgsz3298 = (zgaz3117 == UINT64_C(0b0110011));
  
    } else {  zgsz3298 = false;  }
    bool zgsz3300;
    zgsz3300 = zgsz3298;
  
    if (!(zgsz3300)) {
  
    goto case_151;
    }
    uint64_t zuz3121;
    zuz3121 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(20)));
    uint64_t zuz3122;
    zuz3122 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(15)));
    uint64_t zuz3123;
    zuz3123 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(7)));
    struct zast zgaz3115;
    CREATE(zast)(&zgaz3115);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3299;
      zgsz3299.ztup0 = zuz3121;
      zgsz3299.ztup1 = zuz3122;
      zgsz3299.ztup2 = zuz3123;
      zgsz3299.ztup3 = zAND;
      zRTYPE(&zgaz3115, zgsz3299);
    
    }
    {
      struct zast zgsz3399;
      CREATE(zast)(&zgsz3399);
      COPY(zast)(&zgsz3399, zgaz3115);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3399);
      KILL(zast)(&zgsz3399);
    }
    KILL(zast)(&zgaz3115);
  
  
  
  
    goto finish_match_149;
  }
case_151: ;
  {
    uint64_t zv__6;
    zv__6 = zmergez3var;
    bool zgaz3122;
    {
      uint64_t zgaz3120;
      zgaz3120 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__6 >> INT64_C(25)));
      zgaz3122 = (zgaz3120 == UINT64_C(0b0000000));
    
    }
    bool zgsz3301;
    if (zgaz3122) {
    uint64_t zgaz3121;
    zgaz3121 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__6 >> INT64_C(0)));
    zgsz3301 = (zgaz3121 == UINT64_C(0b0110011));
  
    } else {  zgsz3301 = false;  }
    bool zgsz3303;
    zgsz3303 = zgsz3301;
  
    if (!(zgsz3303)) {
  
    goto case_152;
    }
    uint64_t zuz3124;
    zuz3124 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(20)));
    uint64_t zuz3125;
    zuz3125 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(15)));
    uint64_t zuz3126;
    zuz3126 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(7)));
    struct zast zgaz3119;
    CREATE(zast)(&zgaz3119);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3302;
      zgsz3302.ztup0 = zuz3124;
      zgsz3302.ztup1 = zuz3125;
      zgsz3302.ztup2 = zuz3126;
      zgsz3302.ztup3 = zOR;
      zRTYPE(&zgaz3119, zgsz3302);
    
    }
    {
      struct zast zgsz3400;
      CREATE(zast)(&zgsz3400);
      COPY(zast)(&zgsz3400, zgaz3119);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3400);
      KILL(zast)(&zgsz3400);
    }
    KILL(zast)(&zgaz3119);
  
  
  
  
    goto finish_match_149;
  }
case_152: ;
  {
    uint64_t zv__9;
    zv__9 = zmergez3var;
    bool zgaz3126;
    {
      uint64_t zgaz3124;
      zgaz3124 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__9 >> INT64_C(25)));
      zgaz3126 = (zgaz3124 == UINT64_C(0b0000000));
    
    }
    bool zgsz3304;
    if (zgaz3126) {
    uint64_t zgaz3125;
    zgaz3125 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__9 >> INT64_C(0)));
    zgsz3304 = (zgaz3125 == UINT64_C(0b0110011));
  
    } else {  zgsz3304 = false;  }
    bool zgsz3306;
    zgsz3306 = zgsz3304;
  
    if (!(zgsz3306)) {
  
    goto case_153;
    }
    uint64_t zuz3127;
    zuz3127 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(20)));
    uint64_t zuz3128;
    zuz3128 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(15)));
    uint64_t zuz3129;
    zuz3129 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(7)));
    struct zast zgaz3123;
    CREATE(zast)(&zgaz3123);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3305;
      zgsz3305.ztup0 = zuz3127;
      zgsz3305.ztup1 = zuz3128;
      zgsz3305.ztup2 = zuz3129;
      zgsz3305.ztup3 = zXOR;
      zRTYPE(&zgaz3123, zgsz3305);
    
    }
    {
      struct zast zgsz3401;
      CREATE(zast)(&zgsz3401);
      COPY(zast)(&zgsz3401, zgaz3123);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3401);
      KILL(zast)(&zgsz3401);
    }
    KILL(zast)(&zgaz3123);
  
  
  
  
    goto finish_match_149;
  }
case_153: ;
  {
    uint64_t zv__12;
    zv__12 = zmergez3var;
    bool zgaz3130;
    {
      uint64_t zgaz3128;
      zgaz3128 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__12 >> INT64_C(25)));
      zgaz3130 = (zgaz3128 == UINT64_C(0b0000001));
    
    }
    bool zgsz3307;
    if (zgaz3130) {
    uint64_t zgaz3129;
    zgaz3129 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__12 >> INT64_C(0)));
    zgsz3307 = (zgaz3129 == UINT64_C(0b0110011));
  
    } else {  zgsz3307 = false;  }
    bool zgsz3309;
    zgsz3309 = zgsz3307;
  
    if (!(zgsz3309)) {
  
    goto case_154;
    }
    uint64_t zuz3130;
    zuz3130 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(20)));
    uint64_t zuz3131;
    zuz3131 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(15)));
    uint64_t zuz3132;
    zuz3132 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(7)));
    struct zast zgaz3127;
    CREATE(zast)(&zgaz3127);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3308;
      zgsz3308.ztup0 = zuz3130;
      zgsz3308.ztup1 = zuz3131;
      zgsz3308.ztup2 = zuz3132;
      zgsz3308.ztup3 = zMUL;
      zRTYPE(&zgaz3127, zgsz3308);
    
    }
    {
      struct zast zgsz3402;
      CREATE(zast)(&zgsz3402);
      COPY(zast)(&zgsz3402, zgaz3127);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3402);
      KILL(zast)(&zgsz3402);
    }
    KILL(zast)(&zgaz3127);
  
  
  
  
    goto finish_match_149;
  }
case_154: ;
  {
    uint64_t zv__15;
    zv__15 = zmergez3var;
    bool zgaz3134;
    {
      uint64_t zgaz3132;
      zgaz3132 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__15 >> INT64_C(25)));
      zgaz3134 = (zgaz3132 == UINT64_C(0b0000001));
    
    }
    bool zgsz3310;
    if (zgaz3134) {
    uint64_t zgaz3133;
    zgaz3133 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__15 >> INT64_C(0)));
    zgsz3310 = (zgaz3133 == UINT64_C(0b0110011));
  
    } else {  zgsz3310 = false;  }
    bool zgsz3312;
    zgsz3312 = zgsz3310;
  
    if (!(zgsz3312)) {
  
    goto case_155;
    }
    uint64_t zuz3133;
    zuz3133 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(20)));
    uint64_t zuz3134;
    zuz3134 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(15)));
    uint64_t zuz3135;
    zuz3135 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(7)));
    struct zast zgaz3131;
    CREATE(zast)(&zgaz3131);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3311;
      zgsz3311.ztup0 = zuz3133;
      zgsz3311.ztup1 = zuz3134;
      zgsz3311.ztup2 = zuz3135;
      zgsz3311.ztup3 = zDIV;
      zRTYPE(&zgaz3131, zgsz3311);
    
    }
    {
      struct zast zgsz3403;
      CREATE(zast)(&zgsz3403);
      COPY(zast)(&zgsz3403, zgaz3131);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3403);
      KILL(zast)(&zgsz3403);
    }
    KILL(zast)(&zgaz3131);
  
  
  
  
    goto finish_match_149;
  }
case_155: ;
  {
    uint64_t zv__18;
    zv__18 = zmergez3var;
    bool zgaz3138;
    {
      uint64_t zgaz3136;
      zgaz3136 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__18 >> INT64_C(25)));
      zgaz3138 = (zgaz3136 == UINT64_C(0b0000001));
    
    }
    bool zgsz3313;
    if (zgaz3138) {
    uint64_t zgaz3137;
    zgaz3137 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__18 >> INT64_C(0)));
    zgsz3313 = (zgaz3137 == UINT64_C(0b0110011));
  
    } else {  zgsz3313 = false;  }
    bool zgsz3315;
    zgsz3315 = zgsz3313;
  
    if (!(zgsz3315)) {
  
    goto case_156;
    }
    uint64_t zuz3136;
    zuz3136 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(20)));
    uint64_t zuz3137;
    zuz3137 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(15)));
    uint64_t zuz3138;
    zuz3138 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(7)));
    struct zast zgaz3135;
    CREATE(zast)(&zgaz3135);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3314;
      zgsz3314.ztup0 = zuz3136;
      zgsz3314.ztup1 = zuz3137;
      zgsz3314.ztup2 = zuz3138;
      zgsz3314.ztup3 = zREM;
      zRTYPE(&zgaz3135, zgsz3314);
    
    }
    {
      struct zast zgsz3404;
      CREATE(zast)(&zgsz3404);
      COPY(zast)(&zgsz3404, zgaz3135);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3404);
      KILL(zast)(&zgsz3404);
    }
    KILL(zast)(&zgaz3135);
  
  
  
  
    goto finish_match_149;
  }
case_156: ;
  {
    uint64_t zv__21;
    zv__21 = zmergez3var;
    uint64_t zgaz3140;
    zgaz3140 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__21 >> INT64_C(0)));
    bool zgsz3317;
    zgsz3317 = (zgaz3140 == UINT64_C(0b0010011));
  
    if (!(zgsz3317)) {
  
    goto case_157;
    }
    uint64_t zimm;
    zimm = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__21 >> INT64_C(20)));
    uint64_t zuz3139;
    zuz3139 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__21 >> INT64_C(15)));
    uint64_t zuz3140;
    zuz3140 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__21 >> INT64_C(7)));
    uint64_t zimmshadowz34;
    zimmshadowz34 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__21 >> INT64_C(20)));
    struct zast zgaz3139;
    CREATE(zast)(&zgaz3139);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3316;
      zgsz3316.ztup0 = zimmshadowz34;
      zgsz3316.ztup1 = zuz3139;
      zgsz3316.ztup2 = zuz3140;
      zgsz3316.ztup3 = zADDI;
      zITYPE(&zgaz3139, zgsz3316);
    
    }
    {
      struct zast zgsz3405;
      CREATE(zast)(&zgsz3405);
      COPY(zast)(&zgsz3405, zgaz3139);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3405);
      KILL(zast)(&zgsz3405);
    }
    KILL(zast)(&zgaz3139);
  
  
  
  
  
    goto finish_match_149;
  }
case_157: ;
  {
    uint64_t zv__23;
    zv__23 = zmergez3var;
    uint64_t zgaz3142;
    zgaz3142 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__23 >> INT64_C(0)));
    bool zgsz3319;
    zgsz3319 = (zgaz3142 == UINT64_C(0b0010011));
  
    if (!(zgsz3319)) {
  
    goto case_158;
    }
    uint64_t zuz3141;
    zuz3141 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__23 >> INT64_C(20)));
    uint64_t zuz3142;
    zuz3142 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__23 >> INT64_C(15)));
    uint64_t zuz3143;
    zuz3143 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__23 >> INT64_C(7)));
    uint64_t zimmshadowz35;
    zimmshadowz35 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__23 >> INT64_C(20)));
    struct zast zgaz3141;
    CREATE(zast)(&zgaz3141);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3318;
      zgsz3318.ztup0 = zimmshadowz35;
      zgsz3318.ztup1 = zuz3142;
      zgsz3318.ztup2 = zuz3143;
      zgsz3318.ztup3 = zSLTI;
      zITYPE(&zgaz3141, zgsz3318);
    
    }
    {
      struct zast zgsz3406;
      CREATE(zast)(&zgsz3406);
      COPY(zast)(&zgsz3406, zgaz3141);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3406);
      KILL(zast)(&zgsz3406);
    }
    KILL(zast)(&zgaz3141);
  
  
  
  
  
    goto finish_match_149;
  }
case_158: ;
  {
    uint64_t zv__25;
    zv__25 = zmergez3var;
    uint64_t zgaz3144;
    zgaz3144 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__25 >> INT64_C(0)));
    bool zgsz3321;
    zgsz3321 = (zgaz3144 == UINT64_C(0b0010011));
  
    if (!(zgsz3321)) {
  
    goto case_159;
    }
    uint64_t zuz3144;
    zuz3144 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__25 >> INT64_C(20)));
    uint64_t zuz3145;
    zuz3145 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__25 >> INT64_C(15)));
    uint64_t zuz3146;
    zuz3146 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__25 >> INT64_C(7)));
    uint64_t zimmshadowz36;
    zimmshadowz36 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__25 >> INT64_C(20)));
    struct zast zgaz3143;
    CREATE(zast)(&zgaz3143);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3320;
      zgsz3320.ztup0 = zimmshadowz36;
      zgsz3320.ztup1 = zuz3145;
      zgsz3320.ztup2 = zuz3146;
      zgsz3320.ztup3 = zANDI;
      zITYPE(&zgaz3143, zgsz3320);
    
    }
    {
      struct zast zgsz3407;
      CREATE(zast)(&zgsz3407);
      COPY(zast)(&zgsz3407, zgaz3143);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3407);
      KILL(zast)(&zgsz3407);
    }
    KILL(zast)(&zgaz3143);
  
  
  
  
  
    goto finish_match_149;
  }
case_159: ;
  {
    uint64_t zv__27;
    zv__27 = zmergez3var;
    uint64_t zgaz3146;
    zgaz3146 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__27 >> INT64_C(0)));
    bool zgsz3323;
    zgsz3323 = (zgaz3146 == UINT64_C(0b0010011));
  
    if (!(zgsz3323)) {
  
    goto case_160;
    }
    uint64_t zuz3147;
    zuz3147 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__27 >> INT64_C(20)));
    uint64_t zuz3148;
    zuz3148 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__27 >> INT64_C(15)));
    uint64_t zuz3149;
    zuz3149 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__27 >> INT64_C(7)));
    uint64_t zimmshadowz37;
    zimmshadowz37 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__27 >> INT64_C(20)));
    struct zast zgaz3145;
    CREATE(zast)(&zgaz3145);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3322;
      zgsz3322.ztup0 = zimmshadowz37;
      zgsz3322.ztup1 = zuz3148;
      zgsz3322.ztup2 = zuz3149;
      zgsz3322.ztup3 = zORI;
      zITYPE(&zgaz3145, zgsz3322);
    
    }
    {
      struct zast zgsz3408;
      CREATE(zast)(&zgsz3408);
      COPY(zast)(&zgsz3408, zgaz3145);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3408);
      KILL(zast)(&zgsz3408);
    }
    KILL(zast)(&zgaz3145);
  
  
  
  
  
    goto finish_match_149;
  }
case_160: ;
  {
    uint64_t zv__29;
    zv__29 = zmergez3var;
    uint64_t zgaz3148;
    zgaz3148 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__29 >> INT64_C(0)));
    bool zgsz3325;
    zgsz3325 = (zgaz3148 == UINT64_C(0b0010011));
  
    if (!(zgsz3325)) {
  
    goto case_161;
    }
    uint64_t zuz3150;
    zuz3150 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__29 >> INT64_C(20)));
    uint64_t zuz3151;
    zuz3151 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__29 >> INT64_C(15)));
    uint64_t zuz3152;
    zuz3152 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__29 >> INT64_C(7)));
    uint64_t zimmshadowz38;
    zimmshadowz38 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__29 >> INT64_C(20)));
    struct zast zgaz3147;
    CREATE(zast)(&zgaz3147);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3324;
      zgsz3324.ztup0 = zimmshadowz38;
      zgsz3324.ztup1 = zuz3151;
      zgsz3324.ztup2 = zuz3152;
      zgsz3324.ztup3 = zXORI;
      zITYPE(&zgaz3147, zgsz3324);
    
    }
    {
      struct zast zgsz3409;
      CREATE(zast)(&zgsz3409);
      COPY(zast)(&zgsz3409, zgaz3147);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3409);
      KILL(zast)(&zgsz3409);
    }
    KILL(zast)(&zgaz3147);
  
  
  
  
  
    goto finish_match_149;
  }
case_161: ;
  {
    uint64_t zv__31;
    zv__31 = zmergez3var;
    uint64_t zgaz3150;
    zgaz3150 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__31 >> INT64_C(0)));
    bool zgsz3327;
    zgsz3327 = (zgaz3150 == UINT64_C(0b1100111));
  
    if (!(zgsz3327)) {
  
    goto case_162;
    }
    uint64_t zuz3153;
    zuz3153 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__31 >> INT64_C(20)));
    uint64_t zuz3154;
    zuz3154 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__31 >> INT64_C(15)));
    uint64_t zuz3155;
    zuz3155 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__31 >> INT64_C(7)));
    uint64_t zimmshadowz39;
    zimmshadowz39 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__31 >> INT64_C(20)));
    struct zast zgaz3149;
    CREATE(zast)(&zgaz3149);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3326;
      zgsz3326.ztup0 = zimmshadowz39;
      zgsz3326.ztup1 = zuz3154;
      zgsz3326.ztup2 = zuz3155;
      zgsz3326.ztup3 = zJALR;
      zITYPE(&zgaz3149, zgsz3326);
    
    }
    {
      struct zast zgsz3410;
      CREATE(zast)(&zgsz3410);
      COPY(zast)(&zgsz3410, zgaz3149);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3410);
      KILL(zast)(&zgsz3410);
    }
    KILL(zast)(&zgaz3149);
  
  
  
  
  
    goto finish_match_149;
  }
case_162: ;
  {
    uint64_t zv__33;
    zv__33 = zmergez3var;
    uint64_t zgaz3152;
    zgaz3152 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__33 >> INT64_C(0)));
    bool zgsz3329;
    zgsz3329 = (zgaz3152 == UINT64_C(0b0000011));
  
    if (!(zgsz3329)) {
  
    goto case_163;
    }
    uint64_t zuz3156;
    zuz3156 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__33 >> INT64_C(20)));
    uint64_t zuz3157;
    zuz3157 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__33 >> INT64_C(15)));
    uint64_t zuz3158;
    zuz3158 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__33 >> INT64_C(7)));
    uint64_t zimmshadowz310;
    zimmshadowz310 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__33 >> INT64_C(20)));
    struct zast zgaz3151;
    CREATE(zast)(&zgaz3151);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3328;
      zgsz3328.ztup0 = zimmshadowz310;
      zgsz3328.ztup1 = zuz3157;
      zgsz3328.ztup2 = zuz3158;
      zgsz3328.ztup3 = zLW;
      zITYPE(&zgaz3151, zgsz3328);
    
    }
    {
      struct zast zgsz3411;
      CREATE(zast)(&zgsz3411);
      COPY(zast)(&zgsz3411, zgaz3151);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3411);
      KILL(zast)(&zgsz3411);
    }
    KILL(zast)(&zgaz3151);
  
  
  
  
  
    goto finish_match_149;
  }
case_163: ;
  {
    uint64_t zv__35;
    zv__35 = zmergez3var;
    uint64_t zgaz3154;
    zgaz3154 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__35 >> INT64_C(0)));
    bool zgsz3331;
    zgsz3331 = (zgaz3154 == UINT64_C(0b0010011));
  
    if (!(zgsz3331)) {
  
    goto case_164;
    }
    uint64_t zuz3159;
    zuz3159 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__35 >> INT64_C(20)));
    uint64_t zuz3160;
    zuz3160 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__35 >> INT64_C(15)));
    uint64_t zuz3161;
    zuz3161 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__35 >> INT64_C(7)));
    uint64_t zimmshadowz311;
    zimmshadowz311 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__35 >> INT64_C(20)));
    struct zast zgaz3153;
    CREATE(zast)(&zgaz3153);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3330;
      zgsz3330.ztup0 = zimmshadowz311;
      zgsz3330.ztup1 = zuz3160;
      zgsz3330.ztup2 = zuz3161;
      zgsz3330.ztup3 = zSLLI;
      zITYPE(&zgaz3153, zgsz3330);
    
    }
    {
      struct zast zgsz3412;
      CREATE(zast)(&zgsz3412);
      COPY(zast)(&zgsz3412, zgaz3153);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3412);
      KILL(zast)(&zgsz3412);
    }
    KILL(zast)(&zgaz3153);
  
  
  
  
  
    goto finish_match_149;
  }
case_164: ;
  {
    uint64_t zv__37;
    zv__37 = zmergez3var;
    uint64_t zgaz3156;
    zgaz3156 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__37 >> INT64_C(0)));
    bool zgsz3333;
    zgsz3333 = (zgaz3156 == UINT64_C(0b0000011));
  
    if (!(zgsz3333)) {
  
    goto case_165;
    }
    uint64_t zuz3162;
    zuz3162 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__37 >> INT64_C(20)));
    uint64_t zuz3163;
    zuz3163 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__37 >> INT64_C(15)));
    uint64_t zuz3164;
    zuz3164 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__37 >> INT64_C(7)));
    uint64_t zimmshadowz312;
    zimmshadowz312 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__37 >> INT64_C(20)));
    struct zast zgaz3155;
    CREATE(zast)(&zgaz3155);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3332;
      zgsz3332.ztup0 = zimmshadowz312;
      zgsz3332.ztup1 = zuz3163;
      zgsz3332.ztup2 = zuz3164;
      zgsz3332.ztup3 = zLB;
      zITYPE(&zgaz3155, zgsz3332);
    
    }
    {
      struct zast zgsz3413;
      CREATE(zast)(&zgsz3413);
      COPY(zast)(&zgsz3413, zgaz3155);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3413);
      KILL(zast)(&zgsz3413);
    }
    KILL(zast)(&zgaz3155);
  
  
  
  
  
    goto finish_match_149;
  }
case_165: ;
  {
    uint64_t zv__39;
    zv__39 = zmergez3var;
    uint64_t zgaz3158;
    zgaz3158 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__39 >> INT64_C(0)));
    bool zgsz3335;
    zgsz3335 = (zgaz3158 == UINT64_C(0b0000011));
  
    if (!(zgsz3335)) {
  
    goto case_166;
    }
    uint64_t zuz3165;
    zuz3165 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__39 >> INT64_C(20)));
    uint64_t zuz3166;
    zuz3166 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__39 >> INT64_C(15)));
    uint64_t zuz3167;
    zuz3167 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__39 >> INT64_C(7)));
    uint64_t zimmshadowz313;
    zimmshadowz313 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__39 >> INT64_C(20)));
    struct zast zgaz3157;
    CREATE(zast)(&zgaz3157);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3334;
      zgsz3334.ztup0 = zimmshadowz313;
      zgsz3334.ztup1 = zuz3166;
      zgsz3334.ztup2 = zuz3167;
      zgsz3334.ztup3 = zLH;
      zITYPE(&zgaz3157, zgsz3334);
    
    }
    {
      struct zast zgsz3414;
      CREATE(zast)(&zgsz3414);
      COPY(zast)(&zgsz3414, zgaz3157);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3414);
      KILL(zast)(&zgsz3414);
    }
    KILL(zast)(&zgaz3157);
  
  
  
  
  
    goto finish_match_149;
  }
case_166: ;
  {
    uint64_t zv__41;
    zv__41 = zmergez3var;
    uint64_t zgaz3160;
    zgaz3160 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__41 >> INT64_C(0)));
    bool zgsz3337;
    zgsz3337 = (zgaz3160 == UINT64_C(0b0100011));
  
    if (!(zgsz3337)) {
  
    goto case_167;
    }
    uint64_t zimm2;
    zimm2 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__41 >> INT64_C(25)));
    uint64_t zuz3168;
    zuz3168 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__41 >> INT64_C(20)));
    uint64_t zuz3169;
    zuz3169 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__41 >> INT64_C(15)));
    uint64_t zimm2shadowz314;
    zimm2shadowz314 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__41 >> INT64_C(25)));
    uint64_t zimm1;
    zimm1 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__41 >> INT64_C(7)));
    struct zast zgaz3159;
    CREATE(zast)(&zgaz3159);
    {
      struct ztuple_z8z5bv7zCz0z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzsopz9 zgsz3336;
      zgsz3336.ztup0 = zimm2shadowz314;
      zgsz3336.ztup1 = zuz3168;
      zgsz3336.ztup2 = zuz3169;
      zgsz3336.ztup3 = zimm1;
      zgsz3336.ztup4 = zSW;
      zSTYPE(&zgaz3159, zgsz3336);
    
    }
    {
      struct zast zgsz3415;
      CREATE(zast)(&zgsz3415);
      COPY(zast)(&zgsz3415, zgaz3159);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3415);
      KILL(zast)(&zgsz3415);
    }
    KILL(zast)(&zgaz3159);
  
  
  
  
  
  
    goto finish_match_149;
  }
case_167: ;
  {
    uint64_t zv__43;
    zv__43 = zmergez3var;
    uint64_t zgaz3162;
    zgaz3162 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__43 >> INT64_C(0)));
    bool zgsz3339;
    zgsz3339 = (zgaz3162 == UINT64_C(0b1100011));
  
    if (!(zgsz3339)) {
  
    goto case_168;
    }
    uint64_t zimm4;
    zimm4 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__43 >> INT64_C(31)));
    uint64_t zuz3170;
    zuz3170 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__43 >> INT64_C(20)));
    uint64_t zuz3171;
    zuz3171 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__43 >> INT64_C(15)));
    uint64_t zimm4shadowz315;
    zimm4shadowz315 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__43 >> INT64_C(31)));
    uint64_t zimm3;
    zimm3 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__43 >> INT64_C(7)));
    uint64_t zuz3172;
    zuz3172 = (safe_rshift(UINT64_MAX, 64 - 6) & (zv__43 >> INT64_C(25)));
    uint64_t zuz3173;
    zuz3173 = (safe_rshift(UINT64_MAX, 64 - 4) & (zv__43 >> INT64_C(8)));
    struct zast zgaz3161;
    CREATE(zast)(&zgaz3161);
    {
      struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 zgsz3338;
      zgsz3338.ztup0 = zimm4shadowz315;
      zgsz3338.ztup1 = zuz3172;
      zgsz3338.ztup2 = zuz3170;
      zgsz3338.ztup3 = zuz3171;
      zgsz3338.ztup4 = zuz3173;
      zgsz3338.ztup5 = zimm3;
      zgsz3338.ztup6 = zBEQ;
      zBTYPE(&zgaz3161, zgsz3338);
    
    }
    {
      struct zast zgsz3416;
      CREATE(zast)(&zgsz3416);
      COPY(zast)(&zgsz3416, zgaz3161);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3416);
      KILL(zast)(&zgsz3416);
    }
    KILL(zast)(&zgaz3161);
  
  
  
  
  
  
  
  
    goto finish_match_149;
  }
case_168: ;
  {
    uint64_t zv__45;
    zv__45 = zmergez3var;
    uint64_t zgaz3164;
    zgaz3164 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__45 >> INT64_C(0)));
    bool zgsz3341;
    zgsz3341 = (zgaz3164 == UINT64_C(0b1100011));
  
    if (!(zgsz3341)) {
  
    goto case_169;
    }
    uint64_t zuz3174;
    zuz3174 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__45 >> INT64_C(31)));
    uint64_t zuz3175;
    zuz3175 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__45 >> INT64_C(20)));
    uint64_t zuz3176;
    zuz3176 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__45 >> INT64_C(15)));
    uint64_t zimm4shadowz316;
    zimm4shadowz316 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__45 >> INT64_C(31)));
    uint64_t zuz3177;
    zuz3177 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__45 >> INT64_C(7)));
    uint64_t zuz3178;
    zuz3178 = (safe_rshift(UINT64_MAX, 64 - 6) & (zv__45 >> INT64_C(25)));
    uint64_t zuz3179;
    zuz3179 = (safe_rshift(UINT64_MAX, 64 - 4) & (zv__45 >> INT64_C(8)));
    struct zast zgaz3163;
    CREATE(zast)(&zgaz3163);
    {
      struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 zgsz3340;
      zgsz3340.ztup0 = zimm4shadowz316;
      zgsz3340.ztup1 = zuz3178;
      zgsz3340.ztup2 = zuz3175;
      zgsz3340.ztup3 = zuz3176;
      zgsz3340.ztup4 = zuz3179;
      zgsz3340.ztup5 = zuz3177;
      zgsz3340.ztup6 = zBNE;
      zBTYPE(&zgaz3163, zgsz3340);
    
    }
    {
      struct zast zgsz3417;
      CREATE(zast)(&zgsz3417);
      COPY(zast)(&zgsz3417, zgaz3163);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3417);
      KILL(zast)(&zgsz3417);
    }
    KILL(zast)(&zgaz3163);
  
  
  
  
  
  
  
  
    goto finish_match_149;
  }
case_169: ;
  {
    uint64_t zv__47;
    zv__47 = zmergez3var;
    uint64_t zgaz3166;
    zgaz3166 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__47 >> INT64_C(0)));
    bool zgsz3343;
    zgsz3343 = (zgaz3166 == UINT64_C(0b0110111));
  
    if (!(zgsz3343)) {
  
    goto case_170;
    }
    uint64_t zuz3180;
    zuz3180 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__47 >> INT64_C(12)));
    uint64_t zuz3181;
    zuz3181 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__47 >> INT64_C(7)));
    uint64_t zimmshadowz317;
    zimmshadowz317 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__47 >> INT64_C(12)));
    struct zast zgaz3165;
    CREATE(zast)(&zgaz3165);
    {
      struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 zgsz3342;
      zgsz3342.ztup0 = zimmshadowz317;
      zgsz3342.ztup1 = zuz3181;
      zgsz3342.ztup2 = zLUI;
      zUTYPE(&zgaz3165, zgsz3342);
    
    }
    {
      struct zast zgsz3418;
      CREATE(zast)(&zgsz3418);
      COPY(zast)(&zgsz3418, zgaz3165);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3418);
      KILL(zast)(&zgsz3418);
    }
    KILL(zast)(&zgaz3165);
  
  
  
  
    goto finish_match_149;
  }
case_170: ;
  {
    uint64_t zv__49;
    zv__49 = zmergez3var;
    uint64_t zgaz3168;
    zgaz3168 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__49 >> INT64_C(0)));
    bool zgsz3345;
    zgsz3345 = (zgaz3168 == UINT64_C(0b0010111));
  
    if (!(zgsz3345)) {
  
    goto case_171;
    }
    uint64_t zuz3182;
    zuz3182 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__49 >> INT64_C(12)));
    uint64_t zuz3183;
    zuz3183 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__49 >> INT64_C(7)));
    uint64_t zimmshadowz318;
    zimmshadowz318 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__49 >> INT64_C(12)));
    struct zast zgaz3167;
    CREATE(zast)(&zgaz3167);
    {
      struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 zgsz3344;
      zgsz3344.ztup0 = zimmshadowz318;
      zgsz3344.ztup1 = zuz3183;
      zgsz3344.ztup2 = zAUIPC;
      zUTYPE(&zgaz3167, zgsz3344);
    
    }
    {
      struct zast zgsz3419;
      CREATE(zast)(&zgsz3419);
      COPY(zast)(&zgsz3419, zgaz3167);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3419);
      KILL(zast)(&zgsz3419);
    }
    KILL(zast)(&zgaz3167);
  
  
  
  
    goto finish_match_149;
  }
case_171: ;
  {
    uint64_t zv__51;
    zv__51 = zmergez3var;
    uint64_t zgaz3170;
    zgaz3170 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__51 >> INT64_C(0)));
    bool zgsz3347;
    zgsz3347 = (zgaz3170 == UINT64_C(0b1101111));
  
    if (!(zgsz3347)) {
  
    goto case_172;
    }
    uint64_t zuz3184;
    zuz3184 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__51 >> INT64_C(31)));
    uint64_t zuz3185;
    zuz3185 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__51 >> INT64_C(7)));
    uint64_t zimm4shadowz319;
    zimm4shadowz319 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__51 >> INT64_C(31)));
    uint64_t zuz3186;
    zuz3186 = (safe_rshift(UINT64_MAX, 64 - 8) & (zv__51 >> INT64_C(12)));
    uint64_t zuz3187;
    zuz3187 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__51 >> INT64_C(20)));
    uint64_t zuz3188;
    zuz3188 = (safe_rshift(UINT64_MAX, 64 - 10) & (zv__51 >> INT64_C(21)));
    struct zast zgaz3169;
    CREATE(zast)(&zgaz3169);
    {
      struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv8zCz0z5bv5zCz0z5enumz0zzjopz9 zgsz3346;
      zgsz3346.ztup0 = zimm4shadowz319;
      zgsz3346.ztup1 = zuz3188;
      zgsz3346.ztup2 = zuz3187;
      zgsz3346.ztup3 = zuz3186;
      zgsz3346.ztup4 = zuz3185;
      zgsz3346.ztup5 = zJAL;
      zJTYPE(&zgaz3169, zgsz3346);
    
    }
    {
      struct zast zgsz3420;
      CREATE(zast)(&zgsz3420);
      COPY(zast)(&zgsz3420, zgaz3169);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3420);
      KILL(zast)(&zgsz3420);
    }
    KILL(zast)(&zgaz3169);
  
  
  
  
  
  
  
    goto finish_match_149;
  }
case_172: ;
  {
    uint64_t zv__53;
    zv__53 = zmergez3var;
    bool zgsz3348;
    zgsz3348 = (zv__53 == UINT64_C(0x00100073));
    if (!(zgsz3348)) {
  
    goto case_173;
    }
    struct zast zgaz3171;
    CREATE(zast)(&zgaz3171);
    zEBREAK(&zgaz3171, UNIT);
    {
      struct zast zgsz3421;
      CREATE(zast)(&zgsz3421);
      COPY(zast)(&zgsz3421, zgaz3171);
      zSomez3z5unionz0zzast(&zgsz3294, zgsz3421);
      KILL(zast)(&zgsz3421);
    }
    KILL(zast)(&zgaz3171);
  
    goto finish_match_149;
  }
case_173: ;
  {
    zNone(&zgsz3294, UNIT);
    goto finish_match_149;
  }
case_174: ;
  sail_match_failure("decode");
finish_match_149: ;
  COPY(zoption)((*(&zcbz323)), zgsz3294);
  KILL(zoption)(&zgsz3294);
end_function_175: ;
  goto end_function_193;
end_block_exception_176: ;
  goto end_function_193;
end_function_193: ;
}

unit zfde_loop(unit);

lbits zghz3114;
lbits zghz3115;

void startup_zfde_loop(void)
{
  CREATE(lbits)(&zghz3114);
  CREATE(lbits)(&zghz3115);
}












unit zfde_loop(unit zgsz3350)
{
  __label__ while_178, wend_179, end_function_185, end_block_exception_186;

  unit zcbz324;
  bool zcontinue_loop;
  zcontinue_loop = true;
  bool zgsz3361;
  unit zgsz3362;
while_178: ;
  {
    zgsz3361 = zcontinue_loop;
    if (!(zgsz3361)) goto wend_179;
    uint64_t zinstruction;
    {
      uint64_t zgaz3172;
      zgaz3172 = *(&zPC);
      zinstruction = zread_mem(zgaz3172);
    
    }
    {
      unit zgsz3359;
      {
        RECREATE(lbits)(&zghz3115);
        CONVERT_OF(lbits, fbits)(&zghz3115, zinstruction, UINT64_C(32) , true);
        zgsz3359 = print_bits("Instruction = ", zghz3115);
      }
    }
    {
      __label__ case_181, case_182, case_183, case_184, finish_match_180;

      struct zoption zdecoded_instruction;
      CREATE(zoption)(&zdecoded_instruction);
      zdecode(&zdecoded_instruction, zinstruction);
      unit zgsz3351;
      {
        if (zdecoded_instruction.kind != Kind_zSomez3z5unionz0zzast) goto case_181;
        if (zdecoded_instruction.zSomez3z5unionz0zzast.kind != Kind_zEBREAK) goto case_181;
        zcontinue_loop = false;
        zgsz3351 = UNIT;
        goto finish_match_180;
      }
    case_181: ;
      {
        if (zdecoded_instruction.kind != Kind_zSomez3z5unionz0zzast) goto case_182;
        struct zast zinst;
        CREATE(zast)(&zinst);
        COPY(zast)(&zinst, zdecoded_instruction.zSomez3z5unionz0zzast);
        zgsz3351 = zexecute(zinst);
        KILL(zast)(&zinst);
        goto finish_match_180;
      }
    case_182: ;
      {
        if (zdecoded_instruction.kind != Kind_zNone) goto case_183;
        zgsz3351 = print_endline("instruction is None()");
        goto finish_match_180;
      }
    case_183: ;
      {
        zgsz3351 = print_endline("decoding the instruction resulted in something unexpected");
        goto finish_match_180;
      }
    case_184: ;
      sail_match_failure("fde_loop");
    finish_match_180: ;
      unit zgsz3358;
      zgsz3358 = zgsz3351;
    
      KILL(zoption)(&zdecoded_instruction);
    }
    {
      unit zgsz3356;
      {
        RECREATE(lbits)(&zghz3114);
        CONVERT_OF(lbits, fbits)(&zghz3114, zPC, UINT64_C(32) , true);
        zgsz3356 = print_bits("PC in fde_loop = ", zghz3114);
      }
    }
    zgsz3362 = zinc_PC(UNIT);
  
    goto while_178;
  }
wend_179: ;
  zcbz324 = UNIT;

end_function_185: ;
  return zcbz324;
end_block_exception_186: ;

  return UNIT;
}



void finish_zfde_loop(void)
{
  KILL(lbits)(&zghz3115);
  KILL(lbits)(&zghz3114);
}

unit zmain(unit);

lbits zghz3116;
sail_int zghz3117;
sail_int zghz3118;
sail_int zghz3119;
lbits zghz3120;

void startup_zmain(void)
{
  CREATE(lbits)(&zghz3116);
  CREATE(sail_int)(&zghz3117);
  CREATE(sail_int)(&zghz3118);
  CREATE(sail_int)(&zghz3119);
  CREATE(lbits)(&zghz3120);
}

unit zmain(unit zgsz3363)
{
  __label__ end_function_188, end_block_exception_189;

  unit zcbz325;
  {
    RECREATE(sail_int)(&zghz3117);
    elf_entry(&zghz3117, UNIT);
    {
      RECREATE(sail_int)(&zghz3118);
      CONVERT_OF(sail_int, mach_int)(&zghz3118, INT64_C(32));
      RECREATE(sail_int)(&zghz3119);
      CONVERT_OF(sail_int, mach_int)(&zghz3119, INT64_C(0));
      RECREATE(lbits)(&zghz3120);
      get_slice_int(&zghz3120, zghz3118, zghz3117, zghz3119);
      zPC = CONVERT_OF(fbits, lbits)(zghz3120, true);
    }
    unit zgsz3370;
    zgsz3370 = UNIT;
  }
  {
    unit zgsz3368;
    {
      RECREATE(lbits)(&zghz3116);
      CONVERT_OF(lbits, fbits)(&zghz3116, zPC, UINT64_C(32) , true);
      zgsz3368 = print_bits("PC = ", zghz3116);
    }
  }
  {
    unit zgsz3367;
    zgsz3367 = zfde_loop(UNIT);
  }
  zcbz325 = zobj_dump(UNIT);
end_function_188: ;
  return zcbz325;
end_block_exception_189: ;

  return UNIT;
}



void finish_zmain(void)
{
  KILL(lbits)(&zghz3120);
  KILL(sail_int)(&zghz3119);
  KILL(sail_int)(&zghz3118);
  KILL(sail_int)(&zghz3117);
  KILL(lbits)(&zghz3116);
}

unit zinitializze_registers(unit);

sail_int zghz3121;
lbits zghz3122;
sail_int zghz3123;
lbits zghz3124;
sail_int zghz3125;
lbits zghz3126;
sail_int zghz3127;
lbits zghz3128;
sail_int zghz3129;
lbits zghz3130;
sail_int zghz3131;
lbits zghz3132;
sail_int zghz3133;
lbits zghz3134;
sail_int zghz3135;
lbits zghz3136;
sail_int zghz3137;
lbits zghz3138;

void startup_zinitializze_registers(void)
{
  CREATE(sail_int)(&zghz3121);
  CREATE(lbits)(&zghz3122);
  CREATE(sail_int)(&zghz3123);
  CREATE(lbits)(&zghz3124);
  CREATE(sail_int)(&zghz3125);
  CREATE(lbits)(&zghz3126);
  CREATE(sail_int)(&zghz3127);
  CREATE(lbits)(&zghz3128);
  CREATE(sail_int)(&zghz3129);
  CREATE(lbits)(&zghz3130);
  CREATE(sail_int)(&zghz3131);
  CREATE(lbits)(&zghz3132);
  CREATE(sail_int)(&zghz3133);
  CREATE(lbits)(&zghz3134);
  CREATE(sail_int)(&zghz3135);
  CREATE(lbits)(&zghz3136);
  CREATE(sail_int)(&zghz3137);
  CREATE(lbits)(&zghz3138);
}

unit zinitializze_registers(unit zgsz3371)
{
  __label__ end_function_191, end_block_exception_192;

  unit zcbz326;
  {
    {
      RECREATE(sail_int)(&zghz3137);
      CONVERT_OF(sail_int, mach_int)(&zghz3137, INT64_C(32));
      RECREATE(lbits)(&zghz3138);
      UNDEFINED(lbits)(&zghz3138, zghz3137);
      zPC = CONVERT_OF(fbits, lbits)(zghz3138, true);
    }
    unit zgsz3395;
    zgsz3395 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3135);
      CONVERT_OF(sail_int, mach_int)(&zghz3135, INT64_C(32));
      RECREATE(lbits)(&zghz3136);
      UNDEFINED(lbits)(&zghz3136, zghz3135);
      zzzero = CONVERT_OF(fbits, lbits)(zghz3136, true);
    }
    unit zgsz3394;
    zgsz3394 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3133);
      CONVERT_OF(sail_int, mach_int)(&zghz3133, INT64_C(32));
      RECREATE(lbits)(&zghz3134);
      UNDEFINED(lbits)(&zghz3134, zghz3133);
      zra = CONVERT_OF(fbits, lbits)(zghz3134, true);
    }
    unit zgsz3393;
    zgsz3393 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3131);
      CONVERT_OF(sail_int, mach_int)(&zghz3131, INT64_C(32));
      RECREATE(lbits)(&zghz3132);
      UNDEFINED(lbits)(&zghz3132, zghz3131);
      zsp = CONVERT_OF(fbits, lbits)(zghz3132, true);
    }
    unit zgsz3392;
    zgsz3392 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3129);
      CONVERT_OF(sail_int, mach_int)(&zghz3129, INT64_C(32));
      RECREATE(lbits)(&zghz3130);
      UNDEFINED(lbits)(&zghz3130, zghz3129);
      zgp = CONVERT_OF(fbits, lbits)(zghz3130, true);
    }
    unit zgsz3391;
    zgsz3391 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3127);
      CONVERT_OF(sail_int, mach_int)(&zghz3127, INT64_C(32));
      RECREATE(lbits)(&zghz3128);
      UNDEFINED(lbits)(&zghz3128, zghz3127);
      za0 = CONVERT_OF(fbits, lbits)(zghz3128, true);
    }
    unit zgsz3390;
    zgsz3390 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3125);
      CONVERT_OF(sail_int, mach_int)(&zghz3125, INT64_C(32));
      RECREATE(lbits)(&zghz3126);
      UNDEFINED(lbits)(&zghz3126, zghz3125);
      za1 = CONVERT_OF(fbits, lbits)(zghz3126, true);
    }
    unit zgsz3389;
    zgsz3389 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3123);
      CONVERT_OF(sail_int, mach_int)(&zghz3123, INT64_C(32));
      RECREATE(lbits)(&zghz3124);
      UNDEFINED(lbits)(&zghz3124, zghz3123);
      za2 = CONVERT_OF(fbits, lbits)(zghz3124, true);
    }
    unit zgsz3388;
    zgsz3388 = UNIT;
  }
  {
    RECREATE(sail_int)(&zghz3121);
    CONVERT_OF(sail_int, mach_int)(&zghz3121, INT64_C(32));
    RECREATE(lbits)(&zghz3122);
    UNDEFINED(lbits)(&zghz3122, zghz3121);
    za3 = CONVERT_OF(fbits, lbits)(zghz3122, true);
  }
  zcbz326 = UNIT;
end_function_191: ;
  return zcbz326;
end_block_exception_192: ;

  return UNIT;
}



void finish_zinitializze_registers(void)
{
  KILL(lbits)(&zghz3138);
  KILL(sail_int)(&zghz3137);
  KILL(lbits)(&zghz3136);
  KILL(sail_int)(&zghz3135);
  KILL(lbits)(&zghz3134);
  KILL(sail_int)(&zghz3133);
  KILL(lbits)(&zghz3132);
  KILL(sail_int)(&zghz3131);
  KILL(lbits)(&zghz3130);
  KILL(sail_int)(&zghz3129);
  KILL(lbits)(&zghz3128);
  KILL(sail_int)(&zghz3127);
  KILL(lbits)(&zghz3126);
  KILL(sail_int)(&zghz3125);
  KILL(lbits)(&zghz3124);
  KILL(sail_int)(&zghz3123);
  KILL(lbits)(&zghz3122);
  KILL(sail_int)(&zghz3121);
}

void model_init(void)
{
  setup_rts();
  startup_zsail_mask();
  startup_zsail_ones();
  startup_zfdiv_int();
  startup_zEXTS();
  startup_zadd_to_PC();
  startup_zinc_PC();
  startup_zrREG();
  startup_zwREG();
  startup_zread_mem();
  startup_zwrite_mem();
  startup_zobj_dump();
  startup_zgt_bit();
  startup_zlt_bit();
  startup_zxor_bitvector();
  startup_ztwos_complement();
  startup_zabs();
  startup_zmul_bitvector();
  startup_zdiv_bitvector();
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
  finish_zEXTS();
  finish_zadd_to_PC();
  finish_zinc_PC();
  finish_zrREG();
  finish_zwREG();
  finish_zread_mem();
  finish_zwrite_mem();
  finish_zobj_dump();
  finish_zgt_bit();
  finish_zlt_bit();
  finish_zxor_bitvector();
  finish_ztwos_complement();
  finish_zabs();
  finish_zmul_bitvector();
  finish_zdiv_bitvector();
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
