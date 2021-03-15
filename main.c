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
enum ziop { zADDI, zSLTI, zANDI, zORI, zXORI, zJALR, zLW };

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



































void zsail_mask(lbits *rop, sail_int, lbits);

sail_int zghz30;

void startup_zsail_mask(void)
{    CREATE(sail_int)(&zghz30);
}

void zsail_mask(lbits *zcbz30, sail_int zlen, lbits zv)
{
  __label__ end_function_1, end_block_exception_2, end_function_151;

  bool zgaz31;
  {
    RECREATE(sail_int)(&zghz30);
    length_lbits(&zghz30, zv);
    zgaz31 = lteq(zlen, zghz30);
  }
  if (zgaz31) {  sail_truncate((*(&zcbz30)), zv, zlen);  } else {  zero_extend((*(&zcbz30)), zv, zlen);  }

end_function_1: ;
  goto end_function_151;
end_block_exception_2: ;
  goto end_function_151;
end_function_151: ;
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

void zsail_ones(lbits *zcbz31, sail_int zn)
{
  __label__ end_function_4, end_block_exception_5, end_function_150;

  RECREATE(lbits)(&zghz31);
  zeros(&zghz31, zn);
  not_bits((*(&zcbz31)), zghz31);
end_function_4: ;
  goto end_function_150;
end_block_exception_5: ;
  goto end_function_150;
end_function_150: ;
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

void zfdiv_int(sail_int *zcbz32, sail_int zn, sail_int zm)
{
  __label__ end_function_7, end_block_exception_8, end_function_149;

  bool zgaz34;
  {
    bool zgaz33;
    {
      RECREATE(sail_int)(&zghz313);
      CONVERT_OF(sail_int, mach_int)(&zghz313, INT64_C(0));
      zgaz33 = lt(zn, zghz313);
    }
    bool zgsz31;
    if (zgaz33) {
    {
      RECREATE(sail_int)(&zghz312);
      CONVERT_OF(sail_int, mach_int)(&zghz312, INT64_C(0));
      zgsz31 = gt(zm, zghz312);
    }
    } else {  zgsz31 = false;  }
    zgaz34 = zgsz31;
  
  }
  if (zgaz34) {
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
    sub_int((*(&zcbz32)), zghz38, zghz39);
  }
  } else {
  bool zgaz38;
  {
    bool zgaz37;
    {
      RECREATE(sail_int)(&zghz37);
      CONVERT_OF(sail_int, mach_int)(&zghz37, INT64_C(0));
      zgaz37 = gt(zn, zghz37);
    }
    bool zgsz34;
    if (zgaz37) {
    {
      RECREATE(sail_int)(&zghz36);
      CONVERT_OF(sail_int, mach_int)(&zghz36, INT64_C(0));
      zgsz34 = lt(zm, zghz36);
    }
    } else {  zgsz34 = false;  }
    zgaz38 = zgsz34;
  
  }
  if (zgaz38) {
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
    sub_int((*(&zcbz32)), zghz32, zghz33);
  }
  } else {  tdiv_int((*(&zcbz32)), zn, zm);  }

  }

end_function_7: ;
  goto end_function_149;
end_block_exception_8: ;
  goto end_function_149;
end_function_149: ;
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
let_end_9: ;
}
static void kill_letbind_0(void) {    KILL(zz5vecz8z6z8z5bv32z9z9)(&zXs);
}

void zextzz(lbits *rop, sail_int, lbits);

void zextzz(lbits *zcbz33, sail_int zm, lbits zxs)
{
  __label__ end_function_11, end_block_exception_12, end_function_148;

  zero_extend((*(&zcbz33)), zxs, zm);
end_function_11: ;
  goto end_function_148;
end_block_exception_12: ;
  goto end_function_148;
end_function_148: ;
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
  __label__ end_function_14, end_block_exception_15;

  uint64_t zcbz34;
  {
    RECREATE(lbits)(&zghz314);
    CONVERT_OF(lbits, sbits)(&zghz314, zxs, true);
    RECREATE(sail_int)(&zghz315);
    CONVERT_OF(sail_int, mach_int)(&zghz315, INT64_C(32));
    RECREATE(lbits)(&zghz316);
    sign_extend(&zghz316, zghz314, zghz315);
    zcbz34 = CONVERT_OF(fbits, lbits)(zghz316, true);
  }
end_function_14: ;
  return zcbz34;
end_block_exception_15: ;

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
  __label__ end_function_17, end_block_exception_18;

  unit zcbz35;
  {
    RECREATE(lbits)(&zghz317);
    CONVERT_OF(lbits, fbits)(&zghz317, zPC, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz318);
    add_bits_int(&zghz318, zghz317, zbytes);
    zPC = CONVERT_OF(fbits, lbits)(zghz318, true);
  }
  zcbz35 = UNIT;
end_function_17: ;
  return zcbz35;
end_block_exception_18: ;

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
  __label__ end_function_20, end_block_exception_21;

  unit zcbz36;
  {
    RECREATE(sail_int)(&zghz319);
    CONVERT_OF(sail_int, mach_int)(&zghz319, INT64_C(4));
    zcbz36 = zadd_to_PC(zghz319);
  }
end_function_20: ;
  return zcbz36;
end_block_exception_21: ;

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
  __label__ end_function_23, end_block_exception_24;

  uint64_t zcbz37;
  uint64_t zoffset;
  zoffset = (safe_rshift(UINT64_MAX, 64 - 3) & (zr >> INT64_C(0)));
  uint64_t* zgaz312;
  {
    int64_t zgaz311;
    zgaz311 = ((mach_int) zoffset);
    {
      RECREATE(sail_int)(&zghz320);
      CONVERT_OF(sail_int, mach_int)(&zghz320, zgaz311);
      zgaz312 = vector_access_zz5vecz8z6z8z5bv32z9z9(zXs, zghz320);
    }
  
  }
  zcbz37 = *(zgaz312);


end_function_23: ;
  return zcbz37;
end_block_exception_24: ;

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
  __label__ case_27, case_28, finish_match_26, end_function_29, end_block_exception_30;

  unit zcbz38;
  uint64_t zoffset;
  zoffset = (safe_rshift(UINT64_MAX, 64 - 3) & (zr >> INT64_C(0)));
  {
    uint64_t zvz30;
    zvz30 = zoffset;
    uint64_t zgaz315;
    {
      int64_t zgaz314;
      {
        int64_t zgaz313;
        {
          RECREATE(sail_int)(&zghz325);
          CONVERT_OF(sail_int, mach_int)(&zghz325, INT64_C(2));
          RECREATE(sail_int)(&zghz326);
          CONVERT_OF(sail_int, mach_int)(&zghz326, INT64_C(0));
          RECREATE(sail_int)(&zghz327);
          sub_int(&zghz327, zghz325, zghz326);
          zgaz313 = CONVERT_OF(mach_int, sail_int)(zghz327);
        }
        zgaz314 = (zgaz313 + INT64_C(1));
      
      }
      {
        RECREATE(sail_int)(&zghz322);
        CONVERT_OF(sail_int, mach_int)(&zghz322, zgaz314);
        RECREATE(lbits)(&zghz323);
        CONVERT_OF(lbits, fbits)(&zghz323, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz324);
        zextzz(&zghz324, zghz322, zghz323);
        zgaz315 = CONVERT_OF(fbits, lbits)(zghz324, true);
      }
    
    }
    bool zgsz327;
    zgsz327 = (zvz30 == zgaz315);
  
    if (!(zgsz327)) {
  
    goto case_27;
    }
    zcbz38 = print_endline("Cannot overwrite hard-wired zero register");
  
    goto finish_match_26;
  }
case_27: ;
  {
    uint64_t* zgaz316;
    {
      int64_t zgaz317;
      zgaz317 = ((mach_int) zoffset);
      {
        RECREATE(sail_int)(&zghz321);
        CONVERT_OF(sail_int, mach_int)(&zghz321, zgaz317);
        zgaz316 = vector_access_zz5vecz8z6z8z5bv32z9z9(zXs, zghz321);
      }
    
    }
    (*(zgaz316)) = zv;
    zcbz38 = UNIT;
  
    goto finish_match_26;
  }
case_28: ;
  sail_match_failure("wREG");
finish_match_26: ;

end_function_29: ;
  return zcbz38;
end_block_exception_30: ;

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
lbits zghz333;
sail_int zghz334;
lbits zghz335;

void startup_zread_mem(void)
{
  CREATE(sail_int)(&zghz328);
  CREATE(sail_int)(&zghz329);
  CREATE(lbits)(&zghz330);
  CREATE(lbits)(&zghz331);
  CREATE(lbits)(&zghz332);
  CREATE(lbits)(&zghz333);
  CREATE(sail_int)(&zghz334);
  CREATE(lbits)(&zghz335);
}

uint64_t zread_mem(uint64_t zaddr)
{
  __label__ end_function_32, end_block_exception_33;

  uint64_t zcbz39;
  uint64_t zgaz318;
  {
    RECREATE(lbits)(&zghz333);
    CONVERT_OF(lbits, fbits)(&zghz333, UINT64_C(0x0), UINT64_C(4) , true);
    RECREATE(sail_int)(&zghz334);
    CONVERT_OF(sail_int, mach_int)(&zghz334, INT64_C(32));
    RECREATE(lbits)(&zghz335);
    zero_extend(&zghz335, zghz333, zghz334);
    zgaz318 = CONVERT_OF(fbits, lbits)(zghz335, true);
  }
  {
    RECREATE(sail_int)(&zghz328);
    CONVERT_OF(sail_int, mach_int)(&zghz328, INT64_C(32));
    RECREATE(sail_int)(&zghz329);
    CONVERT_OF(sail_int, mach_int)(&zghz329, INT64_C(4));
    RECREATE(lbits)(&zghz330);
    CONVERT_OF(lbits, fbits)(&zghz330, zgaz318, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz331);
    CONVERT_OF(lbits, fbits)(&zghz331, zaddr, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz332);
    read_ram(&zghz332, zghz328, zghz329, zghz330, zghz331);
    zcbz39 = CONVERT_OF(fbits, lbits)(zghz332, true);
  }

end_function_32: ;
  return zcbz39;
end_block_exception_33: ;

  return UINT64_C(0xdeadc0de);
}



void finish_zread_mem(void)
{
  KILL(lbits)(&zghz335);
  KILL(sail_int)(&zghz334);
  KILL(lbits)(&zghz333);
  KILL(lbits)(&zghz332);
  KILL(lbits)(&zghz331);
  KILL(lbits)(&zghz330);
  KILL(sail_int)(&zghz329);
  KILL(sail_int)(&zghz328);
}

bool zgt_bit(lbits, lbits);

sail_int zghz336;
sail_int zghz337;

void startup_zgt_bit(void)
{
  CREATE(sail_int)(&zghz336);
  CREATE(sail_int)(&zghz337);
}

bool zgt_bit(lbits zx, lbits zy)
{
  __label__ end_function_35, end_block_exception_36;

  bool zcbz310;
  RECREATE(sail_int)(&zghz336);
  sail_unsigned(&zghz336, zx);
  RECREATE(sail_int)(&zghz337);
  sail_unsigned(&zghz337, zy);
  zcbz310 = gt(zghz336, zghz337);
end_function_35: ;
  return zcbz310;
end_block_exception_36: ;

  return false;
}



void finish_zgt_bit(void)
{
  KILL(sail_int)(&zghz337);
  KILL(sail_int)(&zghz336);
}

bool zlt_bit(lbits, lbits);

sail_int zghz338;
sail_int zghz339;

void startup_zlt_bit(void)
{
  CREATE(sail_int)(&zghz338);
  CREATE(sail_int)(&zghz339);
}

bool zlt_bit(lbits zx, lbits zy)
{
  __label__ end_function_38, end_block_exception_39;

  bool zcbz311;
  RECREATE(sail_int)(&zghz338);
  sail_unsigned(&zghz338, zx);
  RECREATE(sail_int)(&zghz339);
  sail_unsigned(&zghz339, zy);
  zcbz311 = lt(zghz338, zghz339);
end_function_38: ;
  return zcbz311;
end_block_exception_39: ;

  return false;
}



void finish_zlt_bit(void)
{
  KILL(sail_int)(&zghz339);
  KILL(sail_int)(&zghz338);
}

fbits zxor_bit(fbits, fbits);

fbits zxor_bit(fbits zb1, fbits zb2)
{
  __label__ end_function_41, end_block_exception_42;

  fbits zcbz312;
  bool zgaz323;
  zgaz323 = (zb1 == zb2);
  if (zgaz323) {  zcbz312 = UINT64_C(0);  } else {  zcbz312 = UINT64_C(1);  }

end_function_41: ;
  return zcbz312;
end_block_exception_42: ;

  return UINT64_C(0);
}

void zxor_bitvector(lbits *rop, lbits, lbits);

sail_int zghz340;
lbits zghz341;
sail_int zghz342;
sail_int zghz343;
sail_int zghz344;
sail_int zghz345;
sail_int zghz346;

void startup_zxor_bitvector(void)
{
  CREATE(sail_int)(&zghz340);
  CREATE(lbits)(&zghz341);
  CREATE(sail_int)(&zghz342);
  CREATE(sail_int)(&zghz343);
  CREATE(sail_int)(&zghz344);
  CREATE(sail_int)(&zghz345);
  CREATE(sail_int)(&zghz346);
}

void zxor_bitvector(lbits *zcbz313, lbits zv1, lbits zv2)
{
  __label__ end_function_46, end_block_exception_47, end_function_147;

  RECREATE(sail_int)(&zghz340);
  length_lbits(&zghz340, zv2);
  RECREATE(lbits)(&zghz341);
  zeros(&zghz341, zghz340);
  {
    int64_t zgsz338;
    {    zgsz338 = INT64_C(0);
    }
    int64_t zgsz339;
    {
      {
        RECREATE(sail_int)(&zghz345);
        CONVERT_OF(sail_int, mach_int)(&zghz345, INT64_C(1));
        RECREATE(sail_int)(&zghz346);
        sub_int(&zghz346, zghz340, zghz345);
        zgsz339 = CONVERT_OF(mach_int, sail_int)(zghz346);
      }
    }
    int64_t zgsz340;
    {    zgsz340 = INT64_C(1);
    }
    {
      __label__ for_start_44, for_end_45;

      int64_t zi;
      zi = zgsz338;
      unit zgsz344;
    for_start_44: ;
      {
        if ((zi > zgsz339)) goto for_end_45;
        fbits zb1;
        {
          RECREATE(sail_int)(&zghz344);
          CONVERT_OF(sail_int, mach_int)(&zghz344, zi);
          zb1 = bitvector_access(zv1, zghz344);
        }
        fbits zb2;
        {
          RECREATE(sail_int)(&zghz343);
          CONVERT_OF(sail_int, mach_int)(&zghz343, zi);
          zb2 = bitvector_access(zv2, zghz343);
        }
        fbits zgaz324;
        zgaz324 = zxor_bit(zb1, zb2);
        {
          RECREATE(sail_int)(&zghz342);
          CONVERT_OF(sail_int, mach_int)(&zghz342, zi);
          update_lbits(&zghz341, zghz341, zghz342, zgaz324);
        }
        zgsz344 = UNIT;
      
      
      
        zi = (zi + zgsz340);
        goto for_start_44;
      }
    for_end_45: ;
    }
    unit zgsz347;
    zgsz347 = UNIT;
  }
  COPY(lbits)((*(&zcbz313)), zghz341);
end_function_46: ;
  goto end_function_147;
end_block_exception_47: ;
  goto end_function_147;
end_function_147: ;
}



void finish_zxor_bitvector(void)
{
  KILL(sail_int)(&zghz346);
  KILL(sail_int)(&zghz345);
  KILL(sail_int)(&zghz344);
  KILL(sail_int)(&zghz343);
  KILL(sail_int)(&zghz342);
  KILL(lbits)(&zghz341);
  KILL(sail_int)(&zghz340);
}

void ztwos_complement(lbits *rop, lbits);

lbits zghz347;
lbits zghz348;
sail_int zghz349;
lbits zghz350;

void startup_ztwos_complement(void)
{
  CREATE(lbits)(&zghz347);
  CREATE(lbits)(&zghz348);
  CREATE(sail_int)(&zghz349);
  CREATE(lbits)(&zghz350);
}

void ztwos_complement(lbits *zcbz314, lbits zv)
{
  __label__ end_function_49, end_block_exception_50, end_function_146;

  RECREATE(lbits)(&zghz347);
  not_bits(&zghz347, zv);
  {
    RECREATE(lbits)(&zghz348);
    {
      RECREATE(sail_int)(&zghz349);
      length_lbits(&zghz349, zv);
      {
        RECREATE(lbits)(&zghz350);
        CONVERT_OF(lbits, fbits)(&zghz350, UINT64_C(0b1), UINT64_C(1) , true);
        zextzz(&zghz348, zghz349, zghz350);
      }
    }
    add_bits(&zghz347, zghz347, zghz348);
    unit zgsz349;
    zgsz349 = UNIT;
  }
  COPY(lbits)((*(&zcbz314)), zghz347);
end_function_49: ;
  goto end_function_146;
end_block_exception_50: ;
  goto end_function_146;
end_function_146: ;
}



void finish_ztwos_complement(void)
{
  KILL(lbits)(&zghz350);
  KILL(sail_int)(&zghz349);
  KILL(lbits)(&zghz348);
  KILL(lbits)(&zghz347);
}

void zmul_bitvector(lbits *rop, lbits, lbits);

sail_int zghz351;
lbits zghz352;
lbits zghz353;
lbits zghz354;
sail_int zghz355;
lbits zghz356;
sail_int zghz357;
sail_int zghz358;
lbits zghz359;
lbits zghz360;
sail_int zghz361;
sail_int zghz362;
sail_int zghz363;
sail_int zghz364;
sail_int zghz365;
sail_int zghz366;
sail_int zghz367;
sail_int zghz368;
sail_int zghz369;
sail_int zghz370;
sail_int zghz371;

void startup_zmul_bitvector(void)
{
  CREATE(sail_int)(&zghz351);
  CREATE(lbits)(&zghz352);
  CREATE(lbits)(&zghz353);
  CREATE(lbits)(&zghz354);
  CREATE(sail_int)(&zghz355);
  CREATE(lbits)(&zghz356);
  CREATE(sail_int)(&zghz357);
  CREATE(sail_int)(&zghz358);
  CREATE(lbits)(&zghz359);
  CREATE(lbits)(&zghz360);
  CREATE(sail_int)(&zghz361);
  CREATE(sail_int)(&zghz362);
  CREATE(sail_int)(&zghz363);
  CREATE(sail_int)(&zghz364);
  CREATE(sail_int)(&zghz365);
  CREATE(sail_int)(&zghz366);
  CREATE(sail_int)(&zghz367);
  CREATE(sail_int)(&zghz368);
  CREATE(sail_int)(&zghz369);
  CREATE(sail_int)(&zghz370);
  CREATE(sail_int)(&zghz371);
}

void zmul_bitvector(lbits *zcbz315, lbits zmultiplicand, lbits zmultiplier)
{
  __label__ end_function_57, end_block_exception_58, end_function_145;

  RECREATE(sail_int)(&zghz351);
  length_lbits(&zghz351, zmultiplier);
  RECREATE(lbits)(&zghz352);
  {
    RECREATE(sail_int)(&zghz370);
    {
      RECREATE(sail_int)(&zghz371);
      CONVERT_OF(sail_int, mach_int)(&zghz371, INT64_C(2));
      mult_int(&zghz370, zghz371, zghz351);
    }
    sign_extend(&zghz352, zmultiplicand, zghz370);
  }
  RECREATE(lbits)(&zghz353);
  {
    RECREATE(sail_int)(&zghz368);
    {
      RECREATE(sail_int)(&zghz369);
      CONVERT_OF(sail_int, mach_int)(&zghz369, INT64_C(2));
      mult_int(&zghz368, zghz369, zghz351);
    }
    sign_extend(&zghz353, zmultiplier, zghz368);
  }
  RECREATE(lbits)(&zghz354);
  {
    RECREATE(sail_int)(&zghz366);
    {
      RECREATE(sail_int)(&zghz367);
      CONVERT_OF(sail_int, mach_int)(&zghz367, INT64_C(2));
      mult_int(&zghz366, zghz367, zghz351);
    }
    zeros(&zghz354, zghz366);
  }
  {
    int64_t zgsz353;
    {    zgsz353 = INT64_C(0);
    }
    int64_t zgsz354;
    {
      {
        RECREATE(sail_int)(&zghz364);
        CONVERT_OF(sail_int, mach_int)(&zghz364, INT64_C(1));
        RECREATE(sail_int)(&zghz365);
        sub_int(&zghz365, zghz351, zghz364);
        zgsz354 = CONVERT_OF(mach_int, sail_int)(zghz365);
      }
    }
    int64_t zgsz355;
    {    zgsz355 = INT64_C(1);
    }
    {
      __label__ for_start_52, for_end_53;

      int64_t zi;
      zi = zgsz353;
      unit zgsz357;
    for_start_52: ;
      {
        if ((zi > zgsz354)) goto for_end_53;
        bool zgaz328;
        {
          fbits zgaz327;
          {
            RECREATE(sail_int)(&zghz363);
            CONVERT_OF(sail_int, mach_int)(&zghz363, zi);
            zgaz327 = bitvector_access(zghz353, zghz363);
          }
          zgaz328 = eq_bit(zgaz327, UINT64_C(1));
        
        }
        if (zgaz328) {
        __label__ case_55, case_56, finish_match_54;

        RECREATE(sail_int)(&zghz355);
        {
          RECREATE(sail_int)(&zghz362);
          CONVERT_OF(sail_int, mach_int)(&zghz362, INT64_C(1));
          sub_int(&zghz355, zghz351, zghz362);
        }
        unit zgsz359;
        {
          RECREATE(sail_int)(&zghz358);
          CONVERT_OF(sail_int, mach_int)(&zghz358, zi);
          RECREATE(lbits)(&zghz359);
          {
            RECREATE(lbits)(&zghz360);
            {
              RECREATE(sail_int)(&zghz361);
              CONVERT_OF(sail_int, mach_int)(&zghz361, zi);
              shiftl(&zghz360, zghz352, zghz361);
            }
            ztwos_complement(&zghz359, zghz360);
          }
          add_bits(&zghz354, zghz354, zghz359);
          zgsz359 = UNIT;
          goto finish_match_54;
        }
      case_55: ;
        {
          RECREATE(lbits)(&zghz356);
          {
            RECREATE(sail_int)(&zghz357);
            CONVERT_OF(sail_int, mach_int)(&zghz357, zi);
            shiftl(&zghz356, zghz352, zghz357);
          }
          add_bits(&zghz354, zghz354, zghz356);
          zgsz359 = UNIT;
          goto finish_match_54;
        }
      case_56: ;
        sail_match_failure("mul_bitvector");
      finish_match_54: ;
        zgsz357 = zgsz359;
      
        } else {  zgsz357 = UNIT;  }
      
        zi = (zi + zgsz355);
        goto for_start_52;
      }
    for_end_53: ;
    }
    unit zgsz366;
    zgsz366 = UNIT;
  }
  COPY(lbits)((*(&zcbz315)), zghz354);
end_function_57: ;
  goto end_function_145;
end_block_exception_58: ;
  goto end_function_145;
end_function_145: ;
}



void finish_zmul_bitvector(void)
{
  KILL(sail_int)(&zghz371);
  KILL(sail_int)(&zghz370);
  KILL(sail_int)(&zghz369);
  KILL(sail_int)(&zghz368);
  KILL(sail_int)(&zghz367);
  KILL(sail_int)(&zghz366);
  KILL(sail_int)(&zghz365);
  KILL(sail_int)(&zghz364);
  KILL(sail_int)(&zghz363);
  KILL(sail_int)(&zghz362);
  KILL(sail_int)(&zghz361);
  KILL(lbits)(&zghz360);
  KILL(lbits)(&zghz359);
  KILL(sail_int)(&zghz358);
  KILL(sail_int)(&zghz357);
  KILL(lbits)(&zghz356);
  KILL(sail_int)(&zghz355);
  KILL(lbits)(&zghz354);
  KILL(lbits)(&zghz353);
  KILL(lbits)(&zghz352);
  KILL(sail_int)(&zghz351);
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

sail_int zghz372;
lbits zghz373;
lbits zghz374;
lbits zghz375;
lbits zghz376;
sail_int zghz377;
sail_int zghz378;
sail_int zghz379;
lbits zghz380;
lbits zghz381;
sail_int zghz382;
sail_int zghz383;
sail_int zghz384;
sail_int zghz385;
sail_int zghz386;
lbits zghz387;
sail_int zghz388;
sail_int zghz389;
lbits zghz390;
sail_int zghz391;
sail_int zghz392;

void startup_zdiv_bitvector(void)
{
  CREATE(sail_int)(&zghz372);
  CREATE(lbits)(&zghz373);
  CREATE(lbits)(&zghz374);
  CREATE(lbits)(&zghz375);
  CREATE(lbits)(&zghz376);
  CREATE(sail_int)(&zghz377);
  CREATE(sail_int)(&zghz378);
  CREATE(sail_int)(&zghz379);
  CREATE(lbits)(&zghz380);
  CREATE(lbits)(&zghz381);
  CREATE(sail_int)(&zghz382);
  CREATE(sail_int)(&zghz383);
  CREATE(sail_int)(&zghz384);
  CREATE(sail_int)(&zghz385);
  CREATE(sail_int)(&zghz386);
  CREATE(lbits)(&zghz387);
  CREATE(sail_int)(&zghz388);
  CREATE(sail_int)(&zghz389);
  CREATE(lbits)(&zghz390);
  CREATE(sail_int)(&zghz391);
  CREATE(sail_int)(&zghz392);
}

void zdiv_bitvector(struct ztuple_z8z5bvzCz0z5bvz9 *zcbz316, lbits zdividend, lbits zdivisor)
{
  __label__ end_function_62, end_block_exception_63, end_function_144;

  RECREATE(sail_int)(&zghz372);
  length_lbits(&zghz372, zdivisor);
  RECREATE(lbits)(&zghz373);
  {
    RECREATE(lbits)(&zghz390);
    {
      RECREATE(sail_int)(&zghz391);
      {
        RECREATE(sail_int)(&zghz392);
        CONVERT_OF(sail_int, mach_int)(&zghz392, INT64_C(2));
        mult_int(&zghz391, zghz392, zghz372);
      }
      sign_extend(&zghz390, zdivisor, zghz391);
    }
    ztwos_complement(&zghz373, zghz390);
  }
  RECREATE(lbits)(&zghz374);
  {
    RECREATE(lbits)(&zghz387);
    {
      RECREATE(sail_int)(&zghz388);
      {
        RECREATE(sail_int)(&zghz389);
        CONVERT_OF(sail_int, mach_int)(&zghz389, INT64_C(2));
        mult_int(&zghz388, zghz389, zghz372);
      }
      sign_extend(&zghz387, zdividend, zghz388);
    }
    ztwos_complement(&zghz374, zghz387);
  }
  RECREATE(lbits)(&zghz375);
  {
    RECREATE(sail_int)(&zghz385);
    {
      RECREATE(sail_int)(&zghz386);
      CONVERT_OF(sail_int, mach_int)(&zghz386, INT64_C(2));
      mult_int(&zghz385, zghz386, zghz372);
    }
    zeros(&zghz375, zghz385);
  }
  RECREATE(lbits)(&zghz376);
  {
    RECREATE(sail_int)(&zghz383);
    {
      RECREATE(sail_int)(&zghz384);
      CONVERT_OF(sail_int, mach_int)(&zghz384, INT64_C(2));
      mult_int(&zghz383, zghz384, zghz372);
    }
    zeros(&zghz376, zghz383);
  }
  {
    int64_t zgsz371;
    {    zgsz371 = INT64_C(0);
    }
    int64_t zgsz372;
    {    zgsz372 = CONVERT_OF(mach_int, sail_int)(zghz372);
    }
    int64_t zgsz373;
    {    zgsz373 = INT64_C(1);
    }
    {
      __label__ for_start_60, for_end_61;

      int64_t zi;
      zi = zgsz371;
      unit zgsz378;
    for_start_60: ;
      {
        if ((zi > zgsz372)) goto for_end_61;
        RECREATE(sail_int)(&zghz377);
        {
          RECREATE(sail_int)(&zghz382);
          CONVERT_OF(sail_int, mach_int)(&zghz382, zi);
          sub_int(&zghz377, zghz372, zghz382);
        }
        {
          bool zgaz336;
          {
            RECREATE(lbits)(&zghz381);
            shiftl(&zghz381, zghz373, zghz377);
            zgaz336 = zgt_bit(zghz374, zghz381);
          }
          unit zgsz375;
          if (zgaz336) {
          {
            RECREATE(lbits)(&zghz380);
            shiftl(&zghz380, zghz373, zghz377);
            sub_bits(&zghz374, zghz374, zghz380);
            unit zgsz376;
            zgsz376 = UNIT;
          }
          update_lbits(&zghz375, zghz375, zghz377, UINT64_C(1));
          zgsz375 = UNIT;
          } else {  zgsz375 = UNIT;  }
        
        }
        bool zgaz338;
        {
          RECREATE(sail_int)(&zghz379);
          CONVERT_OF(sail_int, mach_int)(&zghz379, INT64_C(0));
          zgaz338 = eq_int(zghz377, zghz379);
        }
        if (zgaz338) {
        {
          RECREATE(sail_int)(&zghz378);
          CONVERT_OF(sail_int, mach_int)(&zghz378, INT64_C(1));
          replicate_bits(&zghz376, zghz374, zghz378);
        }
        zgsz378 = UNIT;
        } else {  zgsz378 = UNIT;  }
      
        zi = (zi + zgsz373);
        goto for_start_60;
      }
    for_end_61: ;
    }
    unit zgsz380;
    zgsz380 = UNIT;
  }
  struct ztuple_z8z5bvzCz0z5bvz9 zgsz381;
  CREATE(ztuple_z8z5bvzCz0z5bvz9)(&zgsz381);
  COPY(lbits)(&((&zgsz381)->ztup0), zghz375);
  COPY(lbits)(&((&zgsz381)->ztup1), zghz376);
  COPY(ztuple_z8z5bvzCz0z5bvz9)((*(&zcbz316)), zgsz381);
  KILL(ztuple_z8z5bvzCz0z5bvz9)(&zgsz381);
end_function_62: ;
  goto end_function_144;
end_block_exception_63: ;
  goto end_function_144;
end_function_144: ;
}



void finish_zdiv_bitvector(void)
{
  KILL(sail_int)(&zghz392);
  KILL(sail_int)(&zghz391);
  KILL(lbits)(&zghz390);
  KILL(sail_int)(&zghz389);
  KILL(sail_int)(&zghz388);
  KILL(lbits)(&zghz387);
  KILL(sail_int)(&zghz386);
  KILL(sail_int)(&zghz385);
  KILL(sail_int)(&zghz384);
  KILL(sail_int)(&zghz383);
  KILL(sail_int)(&zghz382);
  KILL(lbits)(&zghz381);
  KILL(lbits)(&zghz380);
  KILL(sail_int)(&zghz379);
  KILL(sail_int)(&zghz378);
  KILL(sail_int)(&zghz377);
  KILL(lbits)(&zghz376);
  KILL(lbits)(&zghz375);
  KILL(lbits)(&zghz374);
  KILL(lbits)(&zghz373);
  KILL(sail_int)(&zghz372);
}






void zdecode(struct zoption *rop, uint64_t);






unit zexecute(struct zast);

lbits zghz393;
sail_int zghz394;
lbits zghz395;
lbits zghz396;
sail_int zghz397;
lbits zghz398;
sail_int zghz399;
lbits zghz3100;
lbits zghz3101;
sail_int zghz3102;
lbits zghz3103;
lbits zghz3104;
sail_int zghz3105;
lbits zghz3106;
lbits zghz3107;
lbits zghz3108;
lbits zghz3109;
lbits zghz3110;
sail_int zghz3111;
lbits zghz3112;
lbits zghz3113;
sail_int zghz3114;
lbits zghz3115;
lbits zghz3116;
sail_int zghz3117;
lbits zghz3118;
lbits zghz3119;
sail_int zghz3120;
lbits zghz3121;
lbits zghz3122;
sail_int zghz3123;
lbits zghz3124;
lbits zghz3125;
sail_int zghz3126;
lbits zghz3127;
lbits zghz3128;
sail_int zghz3129;
lbits zghz3130;
lbits zghz3131;
sail_int zghz3132;
lbits zghz3133;
lbits zghz3134;
lbits zghz3135;
lbits zghz3136;
sail_int zghz3137;
sail_int zghz3138;
sail_int zghz3139;
lbits zghz3140;
lbits zghz3141;
sail_int zghz3142;
sail_int zghz3143;
sail_int zghz3144;
lbits zghz3145;
lbits zghz3146;
sail_int zghz3147;
sail_int zghz3148;
sail_int zghz3149;
lbits zghz3150;
lbits zghz3151;
lbits zghz3152;
sail_int zghz3153;
lbits zghz3154;
lbits zghz3155;
sail_int zghz3156;
lbits zghz3157;
lbits zghz3158;
sail_int zghz3159;
lbits zghz3160;
lbits zghz3161;
lbits zghz3162;
lbits zghz3163;
lbits zghz3164;
sail_int zghz3165;
lbits zghz3166;
lbits zghz3167;
sail_int zghz3168;
lbits zghz3169;
lbits zghz3170;
sail_int zghz3171;
lbits zghz3172;
lbits zghz3173;
sail_int zghz3174;
lbits zghz3175;
lbits zghz3176;
sail_int zghz3177;
lbits zghz3178;
lbits zghz3179;
sail_int zghz3180;
lbits zghz3181;
lbits zghz3182;

void startup_zexecute(void)
{
  CREATE(lbits)(&zghz393);
  CREATE(sail_int)(&zghz394);
  CREATE(lbits)(&zghz395);
  CREATE(lbits)(&zghz396);
  CREATE(sail_int)(&zghz397);
  CREATE(lbits)(&zghz398);
  CREATE(sail_int)(&zghz399);
  CREATE(lbits)(&zghz3100);
  CREATE(lbits)(&zghz3101);
  CREATE(sail_int)(&zghz3102);
  CREATE(lbits)(&zghz3103);
  CREATE(lbits)(&zghz3104);
  CREATE(sail_int)(&zghz3105);
  CREATE(lbits)(&zghz3106);
  CREATE(lbits)(&zghz3107);
  CREATE(lbits)(&zghz3108);
  CREATE(lbits)(&zghz3109);
  CREATE(lbits)(&zghz3110);
  CREATE(sail_int)(&zghz3111);
  CREATE(lbits)(&zghz3112);
  CREATE(lbits)(&zghz3113);
  CREATE(sail_int)(&zghz3114);
  CREATE(lbits)(&zghz3115);
  CREATE(lbits)(&zghz3116);
  CREATE(sail_int)(&zghz3117);
  CREATE(lbits)(&zghz3118);
  CREATE(lbits)(&zghz3119);
  CREATE(sail_int)(&zghz3120);
  CREATE(lbits)(&zghz3121);
  CREATE(lbits)(&zghz3122);
  CREATE(sail_int)(&zghz3123);
  CREATE(lbits)(&zghz3124);
  CREATE(lbits)(&zghz3125);
  CREATE(sail_int)(&zghz3126);
  CREATE(lbits)(&zghz3127);
  CREATE(lbits)(&zghz3128);
  CREATE(sail_int)(&zghz3129);
  CREATE(lbits)(&zghz3130);
  CREATE(lbits)(&zghz3131);
  CREATE(sail_int)(&zghz3132);
  CREATE(lbits)(&zghz3133);
  CREATE(lbits)(&zghz3134);
  CREATE(lbits)(&zghz3135);
  CREATE(lbits)(&zghz3136);
  CREATE(sail_int)(&zghz3137);
  CREATE(sail_int)(&zghz3138);
  CREATE(sail_int)(&zghz3139);
  CREATE(lbits)(&zghz3140);
  CREATE(lbits)(&zghz3141);
  CREATE(sail_int)(&zghz3142);
  CREATE(sail_int)(&zghz3143);
  CREATE(sail_int)(&zghz3144);
  CREATE(lbits)(&zghz3145);
  CREATE(lbits)(&zghz3146);
  CREATE(sail_int)(&zghz3147);
  CREATE(sail_int)(&zghz3148);
  CREATE(sail_int)(&zghz3149);
  CREATE(lbits)(&zghz3150);
  CREATE(lbits)(&zghz3151);
  CREATE(lbits)(&zghz3152);
  CREATE(sail_int)(&zghz3153);
  CREATE(lbits)(&zghz3154);
  CREATE(lbits)(&zghz3155);
  CREATE(sail_int)(&zghz3156);
  CREATE(lbits)(&zghz3157);
  CREATE(lbits)(&zghz3158);
  CREATE(sail_int)(&zghz3159);
  CREATE(lbits)(&zghz3160);
  CREATE(lbits)(&zghz3161);
  CREATE(lbits)(&zghz3162);
  CREATE(lbits)(&zghz3163);
  CREATE(lbits)(&zghz3164);
  CREATE(sail_int)(&zghz3165);
  CREATE(lbits)(&zghz3166);
  CREATE(lbits)(&zghz3167);
  CREATE(sail_int)(&zghz3168);
  CREATE(lbits)(&zghz3169);
  CREATE(lbits)(&zghz3170);
  CREATE(sail_int)(&zghz3171);
  CREATE(lbits)(&zghz3172);
  CREATE(lbits)(&zghz3173);
  CREATE(sail_int)(&zghz3174);
  CREATE(lbits)(&zghz3175);
  CREATE(lbits)(&zghz3176);
  CREATE(sail_int)(&zghz3177);
  CREATE(lbits)(&zghz3178);
  CREATE(lbits)(&zghz3179);
  CREATE(sail_int)(&zghz3180);
  CREATE(lbits)(&zghz3181);
  CREATE(lbits)(&zghz3182);
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
  __label__ case_66, case_67, case_71, case_75, case_79, case_80, case_83, case_86, case_87, case_88, case_92, case_96, case_100, case_101, case_102, case_103, case_104, case_105, case_106, case_107, finish_match_65, end_function_108, end_block_exception_109;

  unit zcbz317;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_66;
    uint64_t zrs2;
    zrs2 = zmergez3var.zRTYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zRTYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zRTYPE.ztup2;
    if ((zADD != zmergez3var.zRTYPE.ztup3)) goto case_66;
    uint64_t zrs1_val;
    zrs1_val = zrREG(zrs1);
    uint64_t zrs2_val;
    zrs2_val = zrREG(zrs2);
    uint64_t zresult;
    zresult = ((zrs1_val + zrs2_val) & UINT64_C(0xFFFFFFFF));
    zcbz317 = zwREG(zrd, zresult);
  
  
  
  
  
  
    goto finish_match_65;
  }
case_66: ;
  {
    __label__ case_69, case_70, finish_match_68;

    if (zmergez3var.kind != Kind_zRTYPE) goto case_67;
    uint64_t zuz30;
    zuz30 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz31;
    zuz31 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz32;
    zuz32 = zmergez3var.zRTYPE.ztup2;
    if ((zAND != zmergez3var.zRTYPE.ztup3)) goto case_67;
    uint64_t zuz33;
    zuz33 = zrREG(zuz31);
    uint64_t zuz34;
    zuz34 = zrREG(zuz30);
    uint64_t zbitwise_AND;
    zbitwise_AND = (zuz33 & zuz34);
    {
      uint64_t zvz31;
      zvz31 = zbitwise_AND;
      uint64_t zgaz346;
      {
        RECREATE(sail_int)(&zghz3180);
        CONVERT_OF(sail_int, mach_int)(&zghz3180, INT64_C(32));
        RECREATE(lbits)(&zghz3181);
        CONVERT_OF(lbits, fbits)(&zghz3181, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3182);
        zextzz(&zghz3182, zghz3180, zghz3181);
        zgaz346 = CONVERT_OF(fbits, lbits)(zghz3182, true);
      }
      bool zgsz391;
      zgsz391 = (zvz31 == zgaz346);
    
      if (!(zgsz391)) {
    
      goto case_69;
      }
      uint64_t zgaz345;
      {
        RECREATE(sail_int)(&zghz3177);
        CONVERT_OF(sail_int, mach_int)(&zghz3177, INT64_C(32));
        RECREATE(lbits)(&zghz3178);
        CONVERT_OF(lbits, fbits)(&zghz3178, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3179);
        zextzz(&zghz3179, zghz3177, zghz3178);
        zgaz345 = CONVERT_OF(fbits, lbits)(zghz3179, true);
      }
      zcbz317 = zwREG(zuz32, zgaz345);
    
    
      goto finish_match_68;
    }
  case_69: ;
    {
      uint64_t zgaz347;
      {
        RECREATE(sail_int)(&zghz3174);
        CONVERT_OF(sail_int, mach_int)(&zghz3174, INT64_C(32));
        RECREATE(lbits)(&zghz3175);
        CONVERT_OF(lbits, fbits)(&zghz3175, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3176);
        zextzz(&zghz3176, zghz3174, zghz3175);
        zgaz347 = CONVERT_OF(fbits, lbits)(zghz3176, true);
      }
      zcbz317 = zwREG(zuz32, zgaz347);
    
      goto finish_match_68;
    }
  case_70: ;
    sail_match_failure("execute");
  finish_match_68: ;
  
  
  
  
  
  
    goto finish_match_65;
  }
case_67: ;
  {
    __label__ case_73, case_74, finish_match_72;

    if (zmergez3var.kind != Kind_zRTYPE) goto case_71;
    uint64_t zuz35;
    zuz35 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz36;
    zuz36 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz37;
    zuz37 = zmergez3var.zRTYPE.ztup2;
    if ((zOR != zmergez3var.zRTYPE.ztup3)) goto case_71;
    uint64_t zuz38;
    zuz38 = zrREG(zuz36);
    uint64_t zuz39;
    zuz39 = zrREG(zuz35);
    uint64_t zbitwise_OR;
    zbitwise_OR = (zuz38 | zuz39);
    {
      uint64_t zvz32;
      zvz32 = zbitwise_OR;
      uint64_t zgaz349;
      {
        RECREATE(sail_int)(&zghz3171);
        CONVERT_OF(sail_int, mach_int)(&zghz3171, INT64_C(32));
        RECREATE(lbits)(&zghz3172);
        CONVERT_OF(lbits, fbits)(&zghz3172, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3173);
        zextzz(&zghz3173, zghz3171, zghz3172);
        zgaz349 = CONVERT_OF(fbits, lbits)(zghz3173, true);
      }
      bool zgsz3104;
      zgsz3104 = (zvz32 == zgaz349);
    
      if (!(zgsz3104)) {
    
      goto case_73;
      }
      uint64_t zgaz348;
      {
        RECREATE(sail_int)(&zghz3168);
        CONVERT_OF(sail_int, mach_int)(&zghz3168, INT64_C(32));
        RECREATE(lbits)(&zghz3169);
        CONVERT_OF(lbits, fbits)(&zghz3169, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3170);
        zextzz(&zghz3170, zghz3168, zghz3169);
        zgaz348 = CONVERT_OF(fbits, lbits)(zghz3170, true);
      }
      zcbz317 = zwREG(zuz37, zgaz348);
    
    
      goto finish_match_72;
    }
  case_73: ;
    {
      uint64_t zgaz350;
      {
        RECREATE(sail_int)(&zghz3165);
        CONVERT_OF(sail_int, mach_int)(&zghz3165, INT64_C(32));
        RECREATE(lbits)(&zghz3166);
        CONVERT_OF(lbits, fbits)(&zghz3166, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3167);
        zextzz(&zghz3167, zghz3165, zghz3166);
        zgaz350 = CONVERT_OF(fbits, lbits)(zghz3167, true);
      }
      zcbz317 = zwREG(zuz37, zgaz350);
    
      goto finish_match_72;
    }
  case_74: ;
    sail_match_failure("execute");
  finish_match_72: ;
  
  
  
  
  
  
    goto finish_match_65;
  }
case_71: ;
  {
    __label__ case_77, case_78, finish_match_76;

    if (zmergez3var.kind != Kind_zRTYPE) goto case_75;
    uint64_t zuz310;
    zuz310 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz311;
    zuz311 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz312;
    zuz312 = zmergez3var.zRTYPE.ztup2;
    if ((zXOR != zmergez3var.zRTYPE.ztup3)) goto case_75;
    uint64_t zuz313;
    zuz313 = zrREG(zuz311);
    uint64_t zuz314;
    zuz314 = zrREG(zuz310);
    uint64_t zbitwise_XOR;
    {
      RECREATE(lbits)(&zghz3162);
      CONVERT_OF(lbits, fbits)(&zghz3162, zuz313, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz3163);
      CONVERT_OF(lbits, fbits)(&zghz3163, zuz314, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz3164);
      zxor_bitvector(&zghz3164, zghz3162, zghz3163);
      zbitwise_XOR = CONVERT_OF(fbits, lbits)(zghz3164, true);
    }
    {
      uint64_t zvz33;
      zvz33 = zbitwise_XOR;
      uint64_t zgaz352;
      {
        RECREATE(sail_int)(&zghz3159);
        CONVERT_OF(sail_int, mach_int)(&zghz3159, INT64_C(32));
        RECREATE(lbits)(&zghz3160);
        CONVERT_OF(lbits, fbits)(&zghz3160, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3161);
        zextzz(&zghz3161, zghz3159, zghz3160);
        zgaz352 = CONVERT_OF(fbits, lbits)(zghz3161, true);
      }
      bool zgsz3120;
      zgsz3120 = (zvz33 == zgaz352);
    
      if (!(zgsz3120)) {
    
      goto case_77;
      }
      uint64_t zgaz351;
      {
        RECREATE(sail_int)(&zghz3156);
        CONVERT_OF(sail_int, mach_int)(&zghz3156, INT64_C(32));
        RECREATE(lbits)(&zghz3157);
        CONVERT_OF(lbits, fbits)(&zghz3157, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3158);
        zextzz(&zghz3158, zghz3156, zghz3157);
        zgaz351 = CONVERT_OF(fbits, lbits)(zghz3158, true);
      }
      zcbz317 = zwREG(zuz312, zgaz351);
    
    
      goto finish_match_76;
    }
  case_77: ;
    {
      uint64_t zgaz353;
      {
        RECREATE(sail_int)(&zghz3153);
        CONVERT_OF(sail_int, mach_int)(&zghz3153, INT64_C(32));
        RECREATE(lbits)(&zghz3154);
        CONVERT_OF(lbits, fbits)(&zghz3154, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3155);
        zextzz(&zghz3155, zghz3153, zghz3154);
        zgaz353 = CONVERT_OF(fbits, lbits)(zghz3155, true);
      }
      zcbz317 = zwREG(zuz312, zgaz353);
    
      goto finish_match_76;
    }
  case_78: ;
    sail_match_failure("execute");
  finish_match_76: ;
  
  
  
  
  
  
    goto finish_match_65;
  }
case_75: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_79;
    uint64_t zuz315;
    zuz315 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz316;
    zuz316 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz317;
    zuz317 = zmergez3var.zRTYPE.ztup2;
    if ((zMUL != zmergez3var.zRTYPE.ztup3)) goto case_79;
    uint64_t zmultiplicand;
    zmultiplicand = zrREG(zuz316);
    uint64_t zmultiplier;
    zmultiplier = zrREG(zuz315);
    uint64_t zproduct;
    {
      RECREATE(lbits)(&zghz3150);
      CONVERT_OF(lbits, fbits)(&zghz3150, zmultiplicand, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz3151);
      CONVERT_OF(lbits, fbits)(&zghz3151, zmultiplier, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz3152);
      zmul_bitvector(&zghz3152, zghz3150, zghz3151);
      zproduct = CONVERT_OF(fbits, lbits)(zghz3152, true);
    }
    int64_t zlen;
    {
      RECREATE(sail_int)(&zghz3147);
      CONVERT_OF(sail_int, mach_int)(&zghz3147, INT64_C(32));
      RECREATE(sail_int)(&zghz3148);
      CONVERT_OF(sail_int, mach_int)(&zghz3148, INT64_C(1));
      RECREATE(sail_int)(&zghz3149);
      sub_int(&zghz3149, zghz3147, zghz3148);
      zlen = CONVERT_OF(mach_int, sail_int)(zghz3149);
    }
    uint64_t zuz318;
    zuz318 = (safe_rshift(UINT64_MAX, 64 - 32) & (zproduct >> INT64_C(0)));
    zcbz317 = zwREG(zuz317, zuz318);
  
  
  
  
  
  
  
  
    goto finish_match_65;
  }
case_79: ;
  {
    __label__ case_82, finish_match_81;

    if (zmergez3var.kind != Kind_zRTYPE) goto case_80;
    uint64_t zuz319;
    zuz319 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz320;
    zuz320 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz321;
    zuz321 = zmergez3var.zRTYPE.ztup2;
    if ((zDIV != zmergez3var.zRTYPE.ztup3)) goto case_80;
    uint64_t zdividend;
    zdividend = zrREG(zuz320);
    uint64_t zdivisor;
    zdivisor = zrREG(zuz319);
    struct ztuple_z8z5bv64zCz0z5bv64z9 zgaz354;
    {
      RECREATE(lbits)(&zghz3145);
      CONVERT_OF(lbits, fbits)(&zghz3145, zdividend, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz3146);
      CONVERT_OF(lbits, fbits)(&zghz3146, zdivisor, UINT64_C(32) , true);
      struct ztuple_z8z5bvzCz0z5bvz9 zgsz3135;
      CREATE(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3135);
      zdiv_bitvector(&zgsz3135, zghz3145, zghz3146);
      /* conversions */
      zgaz354.ztup0 = CONVERT_OF(fbits, lbits)(zgsz3135.ztup0, true);
      zgaz354.ztup1 = CONVERT_OF(fbits, lbits)(zgsz3135.ztup1, true);
      /* end conversions */
      KILL(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3135);
    }
    {
      uint64_t zdiv;
      zdiv = zgaz354.ztup0;
      uint64_t zrem;
      zrem = zgaz354.ztup1;
      int64_t zuz322;
      {
        RECREATE(sail_int)(&zghz3142);
        CONVERT_OF(sail_int, mach_int)(&zghz3142, INT64_C(32));
        RECREATE(sail_int)(&zghz3143);
        CONVERT_OF(sail_int, mach_int)(&zghz3143, INT64_C(1));
        RECREATE(sail_int)(&zghz3144);
        sub_int(&zghz3144, zghz3142, zghz3143);
        zuz322 = CONVERT_OF(mach_int, sail_int)(zghz3144);
      }
      uint64_t zuz323;
      zuz323 = (safe_rshift(UINT64_MAX, 64 - 32) & (zdiv >> INT64_C(0)));
      zcbz317 = zwREG(zuz321, zuz323);
    
    
    
    
      goto finish_match_81;
    }
  case_82: ;
    sail_match_failure("execute");
  finish_match_81: ;
  
  
  
  
  
  
    goto finish_match_65;
  }
case_80: ;
  {
    __label__ case_85, finish_match_84;

    if (zmergez3var.kind != Kind_zRTYPE) goto case_83;
    uint64_t zuz324;
    zuz324 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz325;
    zuz325 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz326;
    zuz326 = zmergez3var.zRTYPE.ztup2;
    if ((zREM != zmergez3var.zRTYPE.ztup3)) goto case_83;
    uint64_t zuz327;
    zuz327 = zrREG(zuz325);
    uint64_t zuz328;
    zuz328 = zrREG(zuz324);
    struct ztuple_z8z5bv64zCz0z5bv64z9 zgaz355;
    {
      RECREATE(lbits)(&zghz3140);
      CONVERT_OF(lbits, fbits)(&zghz3140, zuz327, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz3141);
      CONVERT_OF(lbits, fbits)(&zghz3141, zuz328, UINT64_C(32) , true);
      struct ztuple_z8z5bvzCz0z5bvz9 zgsz3144;
      CREATE(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3144);
      zdiv_bitvector(&zgsz3144, zghz3140, zghz3141);
      /* conversions */
      zgaz355.ztup0 = CONVERT_OF(fbits, lbits)(zgsz3144.ztup0, true);
      zgaz355.ztup1 = CONVERT_OF(fbits, lbits)(zgsz3144.ztup1, true);
      /* end conversions */
      KILL(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3144);
    }
    {
      uint64_t zuz329;
      zuz329 = zgaz355.ztup0;
      uint64_t zuz330;
      zuz330 = zgaz355.ztup1;
      int64_t zuz331;
      {
        RECREATE(sail_int)(&zghz3137);
        CONVERT_OF(sail_int, mach_int)(&zghz3137, INT64_C(32));
        RECREATE(sail_int)(&zghz3138);
        CONVERT_OF(sail_int, mach_int)(&zghz3138, INT64_C(1));
        RECREATE(sail_int)(&zghz3139);
        sub_int(&zghz3139, zghz3137, zghz3138);
        zuz331 = CONVERT_OF(mach_int, sail_int)(zghz3139);
      }
      uint64_t zuz332;
      zuz332 = (safe_rshift(UINT64_MAX, 64 - 32) & (zuz330 >> INT64_C(0)));
      zcbz317 = zwREG(zuz326, zuz332);
    
    
    
    
      goto finish_match_84;
    }
  case_85: ;
    sail_match_failure("execute");
  finish_match_84: ;
  
  
  
  
  
  
    goto finish_match_65;
  }
case_83: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_86;
    uint64_t zimm;
    zimm = zmergez3var.zITYPE.ztup0;
    uint64_t zuz333;
    zuz333 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz334;
    zuz334 = zmergez3var.zITYPE.ztup2;
    if ((zADDI != zmergez3var.zITYPE.ztup3)) goto case_86;
    uint64_t zuz335;
    zuz335 = zrREG(zuz333);
    uint64_t zimm_ext;
    {
      sbits zgsz3151;
      zgsz3151 = CONVERT_OF(sbits, fbits)(zimm, UINT64_C(12) , true);
      zimm_ext = zEXTS(zgsz3151);
    
    }
    uint64_t zuz336;
    zuz336 = ((zuz335 + zimm_ext) & UINT64_C(0xFFFFFFFF));
    zcbz317 = zwREG(zuz334, zuz336);
  
  
  
  
  
  
    goto finish_match_65;
  }
case_86: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_87;
    uint64_t zuz337;
    zuz337 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz338;
    zuz338 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz339;
    zuz339 = zmergez3var.zITYPE.ztup2;
    if ((zSLTI != zmergez3var.zITYPE.ztup3)) goto case_87;
    uint64_t zuz340;
    zuz340 = zrREG(zuz338);
    uint64_t zuz341;
    {
      sbits zgsz3153;
      zgsz3153 = CONVERT_OF(sbits, fbits)(zuz337, UINT64_C(12) , true);
      zuz341 = zEXTS(zgsz3153);
    
    }
    bool zgaz356;
    {
      RECREATE(lbits)(&zghz3135);
      CONVERT_OF(lbits, fbits)(&zghz3135, zuz341, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz3136);
      CONVERT_OF(lbits, fbits)(&zghz3136, zuz340, UINT64_C(32) , true);
      zgaz356 = zlt_bit(zghz3136, zghz3135);
    }
    if (zgaz356) {
    uint64_t zgaz357;
    {
      RECREATE(sail_int)(&zghz3132);
      CONVERT_OF(sail_int, mach_int)(&zghz3132, INT64_C(32));
      RECREATE(lbits)(&zghz3133);
      CONVERT_OF(lbits, fbits)(&zghz3133, UINT64_C(0b1), UINT64_C(1) , true);
      RECREATE(lbits)(&zghz3134);
      zextzz(&zghz3134, zghz3132, zghz3133);
      zgaz357 = CONVERT_OF(fbits, lbits)(zghz3134, true);
    }
    zcbz317 = zwREG(zuz339, zgaz357);
  
    } else {
    uint64_t zgaz358;
    {
      RECREATE(sail_int)(&zghz3129);
      CONVERT_OF(sail_int, mach_int)(&zghz3129, INT64_C(32));
      RECREATE(lbits)(&zghz3130);
      CONVERT_OF(lbits, fbits)(&zghz3130, UINT64_C(0b0), UINT64_C(1) , true);
      RECREATE(lbits)(&zghz3131);
      zextzz(&zghz3131, zghz3129, zghz3130);
      zgaz358 = CONVERT_OF(fbits, lbits)(zghz3131, true);
    }
    zcbz317 = zwREG(zuz339, zgaz358);
  
    }
  
  
  
  
  
  
    goto finish_match_65;
  }
case_87: ;
  {
    __label__ case_90, case_91, finish_match_89;

    if (zmergez3var.kind != Kind_zITYPE) goto case_88;
    uint64_t zuz342;
    zuz342 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz343;
    zuz343 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz344;
    zuz344 = zmergez3var.zITYPE.ztup2;
    if ((zANDI != zmergez3var.zITYPE.ztup3)) goto case_88;
    uint64_t zuz345;
    zuz345 = zrREG(zuz343);
    uint64_t zuz346;
    {
      sbits zgsz3163;
      zgsz3163 = CONVERT_OF(sbits, fbits)(zuz342, UINT64_C(12) , true);
      zuz346 = zEXTS(zgsz3163);
    
    }
    uint64_t zuz347;
    zuz347 = (zuz345 & zuz346);
    {
      uint64_t zvz34;
      zvz34 = zuz347;
      uint64_t zgaz360;
      {
        RECREATE(sail_int)(&zghz3126);
        CONVERT_OF(sail_int, mach_int)(&zghz3126, INT64_C(32));
        RECREATE(lbits)(&zghz3127);
        CONVERT_OF(lbits, fbits)(&zghz3127, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3128);
        zextzz(&zghz3128, zghz3126, zghz3127);
        zgaz360 = CONVERT_OF(fbits, lbits)(zghz3128, true);
      }
      bool zgsz3171;
      zgsz3171 = (zvz34 == zgaz360);
    
      if (!(zgsz3171)) {
    
      goto case_90;
      }
      uint64_t zgaz359;
      {
        RECREATE(sail_int)(&zghz3123);
        CONVERT_OF(sail_int, mach_int)(&zghz3123, INT64_C(32));
        RECREATE(lbits)(&zghz3124);
        CONVERT_OF(lbits, fbits)(&zghz3124, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3125);
        zextzz(&zghz3125, zghz3123, zghz3124);
        zgaz359 = CONVERT_OF(fbits, lbits)(zghz3125, true);
      }
      zcbz317 = zwREG(zuz344, zgaz359);
    
    
      goto finish_match_89;
    }
  case_90: ;
    {
      uint64_t zgaz361;
      {
        RECREATE(sail_int)(&zghz3120);
        CONVERT_OF(sail_int, mach_int)(&zghz3120, INT64_C(32));
        RECREATE(lbits)(&zghz3121);
        CONVERT_OF(lbits, fbits)(&zghz3121, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3122);
        zextzz(&zghz3122, zghz3120, zghz3121);
        zgaz361 = CONVERT_OF(fbits, lbits)(zghz3122, true);
      }
      zcbz317 = zwREG(zuz344, zgaz361);
    
      goto finish_match_89;
    }
  case_91: ;
    sail_match_failure("execute");
  finish_match_89: ;
  
  
  
  
  
  
    goto finish_match_65;
  }
case_88: ;
  {
    __label__ case_94, case_95, finish_match_93;

    if (zmergez3var.kind != Kind_zITYPE) goto case_92;
    uint64_t zuz348;
    zuz348 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz349;
    zuz349 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz350;
    zuz350 = zmergez3var.zITYPE.ztup2;
    if ((zORI != zmergez3var.zITYPE.ztup3)) goto case_92;
    uint64_t zuz351;
    zuz351 = zrREG(zuz349);
    uint64_t zuz352;
    {
      sbits zgsz3177;
      zgsz3177 = CONVERT_OF(sbits, fbits)(zuz348, UINT64_C(12) , true);
      zuz352 = zEXTS(zgsz3177);
    
    }
    uint64_t zuz353;
    zuz353 = (zuz351 | zuz352);
    {
      uint64_t zvz35;
      zvz35 = zuz353;
      uint64_t zgaz363;
      {
        RECREATE(sail_int)(&zghz3117);
        CONVERT_OF(sail_int, mach_int)(&zghz3117, INT64_C(32));
        RECREATE(lbits)(&zghz3118);
        CONVERT_OF(lbits, fbits)(&zghz3118, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3119);
        zextzz(&zghz3119, zghz3117, zghz3118);
        zgaz363 = CONVERT_OF(fbits, lbits)(zghz3119, true);
      }
      bool zgsz3185;
      zgsz3185 = (zvz35 == zgaz363);
    
      if (!(zgsz3185)) {
    
      goto case_94;
      }
      uint64_t zgaz362;
      {
        RECREATE(sail_int)(&zghz3114);
        CONVERT_OF(sail_int, mach_int)(&zghz3114, INT64_C(32));
        RECREATE(lbits)(&zghz3115);
        CONVERT_OF(lbits, fbits)(&zghz3115, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3116);
        zextzz(&zghz3116, zghz3114, zghz3115);
        zgaz362 = CONVERT_OF(fbits, lbits)(zghz3116, true);
      }
      zcbz317 = zwREG(zuz350, zgaz362);
    
    
      goto finish_match_93;
    }
  case_94: ;
    {
      uint64_t zgaz364;
      {
        RECREATE(sail_int)(&zghz3111);
        CONVERT_OF(sail_int, mach_int)(&zghz3111, INT64_C(32));
        RECREATE(lbits)(&zghz3112);
        CONVERT_OF(lbits, fbits)(&zghz3112, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3113);
        zextzz(&zghz3113, zghz3111, zghz3112);
        zgaz364 = CONVERT_OF(fbits, lbits)(zghz3113, true);
      }
      zcbz317 = zwREG(zuz350, zgaz364);
    
      goto finish_match_93;
    }
  case_95: ;
    sail_match_failure("execute");
  finish_match_93: ;
  
  
  
  
  
  
    goto finish_match_65;
  }
case_92: ;
  {
    __label__ case_98, case_99, finish_match_97;

    if (zmergez3var.kind != Kind_zITYPE) goto case_96;
    uint64_t zuz354;
    zuz354 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz355;
    zuz355 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz356;
    zuz356 = zmergez3var.zITYPE.ztup2;
    if ((zXORI != zmergez3var.zITYPE.ztup3)) goto case_96;
    uint64_t zuz357;
    zuz357 = zrREG(zuz355);
    uint64_t zuz358;
    {
      sbits zgsz3191;
      zgsz3191 = CONVERT_OF(sbits, fbits)(zuz354, UINT64_C(12) , true);
      zuz358 = zEXTS(zgsz3191);
    
    }
    uint64_t zuz359;
    {
      RECREATE(lbits)(&zghz3108);
      CONVERT_OF(lbits, fbits)(&zghz3108, zuz357, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz3109);
      CONVERT_OF(lbits, fbits)(&zghz3109, zuz358, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz3110);
      zxor_bitvector(&zghz3110, zghz3108, zghz3109);
      zuz359 = CONVERT_OF(fbits, lbits)(zghz3110, true);
    }
    {
      uint64_t zvz36;
      zvz36 = zuz359;
      uint64_t zgaz366;
      {
        RECREATE(sail_int)(&zghz3105);
        CONVERT_OF(sail_int, mach_int)(&zghz3105, INT64_C(32));
        RECREATE(lbits)(&zghz3106);
        CONVERT_OF(lbits, fbits)(&zghz3106, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3107);
        zextzz(&zghz3107, zghz3105, zghz3106);
        zgaz366 = CONVERT_OF(fbits, lbits)(zghz3107, true);
      }
      bool zgsz3202;
      zgsz3202 = (zvz36 == zgaz366);
    
      if (!(zgsz3202)) {
    
      goto case_98;
      }
      uint64_t zgaz365;
      {
        RECREATE(sail_int)(&zghz3102);
        CONVERT_OF(sail_int, mach_int)(&zghz3102, INT64_C(32));
        RECREATE(lbits)(&zghz3103);
        CONVERT_OF(lbits, fbits)(&zghz3103, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3104);
        zextzz(&zghz3104, zghz3102, zghz3103);
        zgaz365 = CONVERT_OF(fbits, lbits)(zghz3104, true);
      }
      zcbz317 = zwREG(zuz356, zgaz365);
    
    
      goto finish_match_97;
    }
  case_98: ;
    {
      uint64_t zgaz367;
      {
        RECREATE(sail_int)(&zghz399);
        CONVERT_OF(sail_int, mach_int)(&zghz399, INT64_C(32));
        RECREATE(lbits)(&zghz3100);
        CONVERT_OF(lbits, fbits)(&zghz3100, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3101);
        zextzz(&zghz3101, zghz399, zghz3100);
        zgaz367 = CONVERT_OF(fbits, lbits)(zghz3101, true);
      }
      zcbz317 = zwREG(zuz356, zgaz367);
    
      goto finish_match_97;
    }
  case_99: ;
    sail_match_failure("execute");
  finish_match_97: ;
  
  
  
  
  
  
    goto finish_match_65;
  }
case_96: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_100;
    uint64_t zuz360;
    zuz360 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz361;
    zuz361 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz362;
    zuz362 = zmergez3var.zITYPE.ztup2;
    if ((zJALR != zmergez3var.zITYPE.ztup3)) goto case_100;
    uint64_t zuz363;
    zuz363 = zrREG(zuz361);
    uint64_t zuz364;
    {
      sbits zgsz3208;
      zgsz3208 = CONVERT_OF(sbits, fbits)(zuz360, UINT64_C(12) , true);
      zuz364 = zEXTS(zgsz3208);
    
    }
    uint64_t zoffset;
    zoffset = ((zuz363 + zuz364) & UINT64_C(0xFFFFFFFF));
    {
      {
        RECREATE(lbits)(&zghz396);
        CONVERT_OF(lbits, fbits)(&zghz396, zoffset, UINT64_C(32) , true);
        RECREATE(sail_int)(&zghz397);
        CONVERT_OF(sail_int, mach_int)(&zghz397, INT64_C(0));
        RECREATE(lbits)(&zghz398);
        update_lbits(&zghz398, zghz396, zghz397, UINT64_C(0));
        zoffset = CONVERT_OF(fbits, lbits)(zghz398, true);
      }
      unit zgsz3216;
      zgsz3216 = UNIT;
    }
    {
      uint64_t zgaz368;
      {
        RECREATE(lbits)(&zghz393);
        CONVERT_OF(lbits, fbits)(&zghz393, zPC, UINT64_C(32) , true);
        RECREATE(sail_int)(&zghz394);
        CONVERT_OF(sail_int, mach_int)(&zghz394, INT64_C(4));
        RECREATE(lbits)(&zghz395);
        add_bits_int(&zghz395, zghz393, zghz394);
        zgaz368 = CONVERT_OF(fbits, lbits)(zghz395, true);
      }
      unit zgsz3215;
      zgsz3215 = zwREG(zuz362, zgaz368);
    
    }
    zPC = ((zPC + zoffset) & UINT64_C(0xFFFFFFFF));
    zcbz317 = UNIT;
  
  
  
  
  
  
    goto finish_match_65;
  }
case_100: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_101;
    uint64_t zuz365;
    zuz365 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz366;
    zuz366 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz367;
    zuz367 = zmergez3var.zITYPE.ztup2;
    if ((zLW != zmergez3var.zITYPE.ztup3)) goto case_101;
    uint64_t zuz368;
    zuz368 = zrREG(zuz366);
    uint64_t zuz369;
    {
      sbits zgsz3218;
      zgsz3218 = CONVERT_OF(sbits, fbits)(zuz365, UINT64_C(12) , true);
      zuz369 = zEXTS(zgsz3218);
    
    }
    uint64_t zaddr;
    zaddr = ((zuz368 + zuz369) & UINT64_C(0xFFFFFFFF));
    uint64_t zmem_val;
    zmem_val = zread_mem(zaddr);
    zcbz317 = zwREG(zuz367, zmem_val);
  
  
  
  
  
  
  
    goto finish_match_65;
  }
case_101: ;
  {
    if (zmergez3var.kind != Kind_zSTYPE) goto case_102;
    uint64_t zimm2;
    zimm2 = zmergez3var.zSTYPE.ztup0;
    uint64_t zuz370;
    zuz370 = zmergez3var.zSTYPE.ztup1;
    uint64_t zuz371;
    zuz371 = zmergez3var.zSTYPE.ztup2;
    uint64_t zimm1;
    zimm1 = zmergez3var.zSTYPE.ztup3;
    if ((zSW != zmergez3var.zSTYPE.ztup4)) goto case_102;
    zcbz317 = print_endline("execute SW\n");
  
  
  
  
    goto finish_match_65;
  }
case_102: ;
  {
    if (zmergez3var.kind != Kind_zBTYPE) goto case_103;
    uint64_t zimm4;
    zimm4 = zmergez3var.zBTYPE.ztup0;
    uint64_t zuz372;
    zuz372 = zmergez3var.zBTYPE.ztup1;
    uint64_t zuz373;
    zuz373 = zmergez3var.zBTYPE.ztup2;
    uint64_t zuz374;
    zuz374 = zmergez3var.zBTYPE.ztup3;
    uint64_t zuz375;
    zuz375 = zmergez3var.zBTYPE.ztup4;
    uint64_t zimm3;
    zimm3 = zmergez3var.zBTYPE.ztup5;
    if ((zBEQ != zmergez3var.zBTYPE.ztup6)) goto case_103;
    zcbz317 = print_endline("execute BEQ\n");
  
  
  
  
  
  
    goto finish_match_65;
  }
case_103: ;
  {
    if (zmergez3var.kind != Kind_zBTYPE) goto case_104;
    uint64_t zuz376;
    zuz376 = zmergez3var.zBTYPE.ztup0;
    uint64_t zuz377;
    zuz377 = zmergez3var.zBTYPE.ztup1;
    uint64_t zuz378;
    zuz378 = zmergez3var.zBTYPE.ztup2;
    uint64_t zuz379;
    zuz379 = zmergez3var.zBTYPE.ztup3;
    uint64_t zuz380;
    zuz380 = zmergez3var.zBTYPE.ztup4;
    uint64_t zuz381;
    zuz381 = zmergez3var.zBTYPE.ztup5;
    if ((zBNE != zmergez3var.zBTYPE.ztup6)) goto case_104;
    zcbz317 = print_endline("execute BNE\n");
  
  
  
  
  
  
    goto finish_match_65;
  }
case_104: ;
  {
    if (zmergez3var.kind != Kind_zUTYPE) goto case_105;
    uint64_t zuz382;
    zuz382 = zmergez3var.zUTYPE.ztup0;
    uint64_t zuz383;
    zuz383 = zmergez3var.zUTYPE.ztup1;
    if ((zLUI != zmergez3var.zUTYPE.ztup2)) goto case_105;
    zcbz317 = print_endline("execute LUI\n");
  
  
    goto finish_match_65;
  }
case_105: ;
  {
    if (zmergez3var.kind != Kind_zUTYPE) goto case_106;
    uint64_t zuz384;
    zuz384 = zmergez3var.zUTYPE.ztup0;
    uint64_t zuz385;
    zuz385 = zmergez3var.zUTYPE.ztup1;
    if ((zAUIPC != zmergez3var.zUTYPE.ztup2)) goto case_106;
    zcbz317 = print_endline("execute AUIPC\n");
  
  
    goto finish_match_65;
  }
case_106: ;
  {
    if (zmergez3var.kind != Kind_zJTYPE) goto case_107;
    uint64_t zuz386;
    zuz386 = zmergez3var.zJTYPE.ztup0;
    uint64_t zuz387;
    zuz387 = zmergez3var.zJTYPE.ztup1;
    uint64_t zuz388;
    zuz388 = zmergez3var.zJTYPE.ztup2;
    uint64_t zuz389;
    zuz389 = zmergez3var.zJTYPE.ztup3;
    uint64_t zuz390;
    zuz390 = zmergez3var.zJTYPE.ztup4;
    if ((zJAL != zmergez3var.zJTYPE.ztup5)) goto case_107;
    zcbz317 = print_endline("execute JAL\n");
  
  
  
  
  
    goto finish_match_65;
  }
case_107: ;
  sail_match_failure("execute");
finish_match_65: ;
end_function_108: ;
  return zcbz317;
end_block_exception_109: ;

  return UNIT;
}



void finish_zexecute(void)
{
  KILL(lbits)(&zghz3182);
  KILL(lbits)(&zghz3181);
  KILL(sail_int)(&zghz3180);
  KILL(lbits)(&zghz3179);
  KILL(lbits)(&zghz3178);
  KILL(sail_int)(&zghz3177);
  KILL(lbits)(&zghz3176);
  KILL(lbits)(&zghz3175);
  KILL(sail_int)(&zghz3174);
  KILL(lbits)(&zghz3173);
  KILL(lbits)(&zghz3172);
  KILL(sail_int)(&zghz3171);
  KILL(lbits)(&zghz3170);
  KILL(lbits)(&zghz3169);
  KILL(sail_int)(&zghz3168);
  KILL(lbits)(&zghz3167);
  KILL(lbits)(&zghz3166);
  KILL(sail_int)(&zghz3165);
  KILL(lbits)(&zghz3164);
  KILL(lbits)(&zghz3163);
  KILL(lbits)(&zghz3162);
  KILL(lbits)(&zghz3161);
  KILL(lbits)(&zghz3160);
  KILL(sail_int)(&zghz3159);
  KILL(lbits)(&zghz3158);
  KILL(lbits)(&zghz3157);
  KILL(sail_int)(&zghz3156);
  KILL(lbits)(&zghz3155);
  KILL(lbits)(&zghz3154);
  KILL(sail_int)(&zghz3153);
  KILL(lbits)(&zghz3152);
  KILL(lbits)(&zghz3151);
  KILL(lbits)(&zghz3150);
  KILL(sail_int)(&zghz3149);
  KILL(sail_int)(&zghz3148);
  KILL(sail_int)(&zghz3147);
  KILL(lbits)(&zghz3146);
  KILL(lbits)(&zghz3145);
  KILL(sail_int)(&zghz3144);
  KILL(sail_int)(&zghz3143);
  KILL(sail_int)(&zghz3142);
  KILL(lbits)(&zghz3141);
  KILL(lbits)(&zghz3140);
  KILL(sail_int)(&zghz3139);
  KILL(sail_int)(&zghz3138);
  KILL(sail_int)(&zghz3137);
  KILL(lbits)(&zghz3136);
  KILL(lbits)(&zghz3135);
  KILL(lbits)(&zghz3134);
  KILL(lbits)(&zghz3133);
  KILL(sail_int)(&zghz3132);
  KILL(lbits)(&zghz3131);
  KILL(lbits)(&zghz3130);
  KILL(sail_int)(&zghz3129);
  KILL(lbits)(&zghz3128);
  KILL(lbits)(&zghz3127);
  KILL(sail_int)(&zghz3126);
  KILL(lbits)(&zghz3125);
  KILL(lbits)(&zghz3124);
  KILL(sail_int)(&zghz3123);
  KILL(lbits)(&zghz3122);
  KILL(lbits)(&zghz3121);
  KILL(sail_int)(&zghz3120);
  KILL(lbits)(&zghz3119);
  KILL(lbits)(&zghz3118);
  KILL(sail_int)(&zghz3117);
  KILL(lbits)(&zghz3116);
  KILL(lbits)(&zghz3115);
  KILL(sail_int)(&zghz3114);
  KILL(lbits)(&zghz3113);
  KILL(lbits)(&zghz3112);
  KILL(sail_int)(&zghz3111);
  KILL(lbits)(&zghz3110);
  KILL(lbits)(&zghz3109);
  KILL(lbits)(&zghz3108);
  KILL(lbits)(&zghz3107);
  KILL(lbits)(&zghz3106);
  KILL(sail_int)(&zghz3105);
  KILL(lbits)(&zghz3104);
  KILL(lbits)(&zghz3103);
  KILL(sail_int)(&zghz3102);
  KILL(lbits)(&zghz3101);
  KILL(lbits)(&zghz3100);
  KILL(sail_int)(&zghz399);
  KILL(lbits)(&zghz398);
  KILL(sail_int)(&zghz397);
  KILL(lbits)(&zghz396);
  KILL(lbits)(&zghz395);
  KILL(sail_int)(&zghz394);
  KILL(lbits)(&zghz393);
}


















void zdecode(struct zoption *zcbz318, uint64_t zmergez3var)
{
  __label__ case_112, case_113, case_114, case_115, case_116, case_117, case_118, case_119, case_120, case_121, case_122, case_123, case_124, case_125, case_126, case_127, case_128, case_129, case_130, case_131, case_132, finish_match_111, end_function_133, end_block_exception_134, end_function_143;

  struct zoption zgsz3226;
  CREATE(zoption)(&zgsz3226);
  {
    uint64_t zv__0;
    zv__0 = zmergez3var;
    bool zgaz372;
    {
      uint64_t zgaz370;
      zgaz370 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__0 >> INT64_C(25)));
      zgaz372 = (zgaz370 == UINT64_C(0b0000000));
    
    }
    bool zgsz3227;
    if (zgaz372) {
    uint64_t zgaz371;
    zgaz371 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__0 >> INT64_C(0)));
    zgsz3227 = (zgaz371 == UINT64_C(0b0110011));
  
    } else {  zgsz3227 = false;  }
    bool zgsz3229;
    zgsz3229 = zgsz3227;
  
    if (!(zgsz3229)) {
  
    goto case_112;
    }
    uint64_t zrs2;
    zrs2 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(20)));
    uint64_t zrs1;
    zrs1 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(15)));
    uint64_t zrd;
    zrd = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(7)));
    struct zast zgaz369;
    CREATE(zast)(&zgaz369);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3228;
      zgsz3228.ztup0 = zrs2;
      zgsz3228.ztup1 = zrs1;
      zgsz3228.ztup2 = zrd;
      zgsz3228.ztup3 = zADD;
      zRTYPE(&zgaz369, zgsz3228);
    
    }
    {
      struct zast zgsz3324;
      CREATE(zast)(&zgsz3324);
      COPY(zast)(&zgsz3324, zgaz369);
      zSomez3z5unionz0zzast(&zgsz3226, zgsz3324);
      KILL(zast)(&zgsz3324);
    }
    KILL(zast)(&zgaz369);
  
  
  
  
    goto finish_match_111;
  }
case_112: ;
  {
    uint64_t zv__3;
    zv__3 = zmergez3var;
    bool zgaz376;
    {
      uint64_t zgaz374;
      zgaz374 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__3 >> INT64_C(25)));
      zgaz376 = (zgaz374 == UINT64_C(0b0000000));
    
    }
    bool zgsz3230;
    if (zgaz376) {
    uint64_t zgaz375;
    zgaz375 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__3 >> INT64_C(0)));
    zgsz3230 = (zgaz375 == UINT64_C(0b0110011));
  
    } else {  zgsz3230 = false;  }
    bool zgsz3232;
    zgsz3232 = zgsz3230;
  
    if (!(zgsz3232)) {
  
    goto case_113;
    }
    uint64_t zuz391;
    zuz391 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(20)));
    uint64_t zuz392;
    zuz392 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(15)));
    uint64_t zuz393;
    zuz393 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(7)));
    struct zast zgaz373;
    CREATE(zast)(&zgaz373);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3231;
      zgsz3231.ztup0 = zuz391;
      zgsz3231.ztup1 = zuz392;
      zgsz3231.ztup2 = zuz393;
      zgsz3231.ztup3 = zAND;
      zRTYPE(&zgaz373, zgsz3231);
    
    }
    {
      struct zast zgsz3325;
      CREATE(zast)(&zgsz3325);
      COPY(zast)(&zgsz3325, zgaz373);
      zSomez3z5unionz0zzast(&zgsz3226, zgsz3325);
      KILL(zast)(&zgsz3325);
    }
    KILL(zast)(&zgaz373);
  
  
  
  
    goto finish_match_111;
  }
case_113: ;
  {
    uint64_t zv__6;
    zv__6 = zmergez3var;
    bool zgaz380;
    {
      uint64_t zgaz378;
      zgaz378 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__6 >> INT64_C(25)));
      zgaz380 = (zgaz378 == UINT64_C(0b0000000));
    
    }
    bool zgsz3233;
    if (zgaz380) {
    uint64_t zgaz379;
    zgaz379 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__6 >> INT64_C(0)));
    zgsz3233 = (zgaz379 == UINT64_C(0b0110011));
  
    } else {  zgsz3233 = false;  }
    bool zgsz3235;
    zgsz3235 = zgsz3233;
  
    if (!(zgsz3235)) {
  
    goto case_114;
    }
    uint64_t zuz394;
    zuz394 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(20)));
    uint64_t zuz395;
    zuz395 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(15)));
    uint64_t zuz396;
    zuz396 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(7)));
    struct zast zgaz377;
    CREATE(zast)(&zgaz377);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3234;
      zgsz3234.ztup0 = zuz394;
      zgsz3234.ztup1 = zuz395;
      zgsz3234.ztup2 = zuz396;
      zgsz3234.ztup3 = zOR;
      zRTYPE(&zgaz377, zgsz3234);
    
    }
    {
      struct zast zgsz3326;
      CREATE(zast)(&zgsz3326);
      COPY(zast)(&zgsz3326, zgaz377);
      zSomez3z5unionz0zzast(&zgsz3226, zgsz3326);
      KILL(zast)(&zgsz3326);
    }
    KILL(zast)(&zgaz377);
  
  
  
  
    goto finish_match_111;
  }
case_114: ;
  {
    uint64_t zv__9;
    zv__9 = zmergez3var;
    bool zgaz384;
    {
      uint64_t zgaz382;
      zgaz382 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__9 >> INT64_C(25)));
      zgaz384 = (zgaz382 == UINT64_C(0b0000000));
    
    }
    bool zgsz3236;
    if (zgaz384) {
    uint64_t zgaz383;
    zgaz383 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__9 >> INT64_C(0)));
    zgsz3236 = (zgaz383 == UINT64_C(0b0110011));
  
    } else {  zgsz3236 = false;  }
    bool zgsz3238;
    zgsz3238 = zgsz3236;
  
    if (!(zgsz3238)) {
  
    goto case_115;
    }
    uint64_t zuz397;
    zuz397 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(20)));
    uint64_t zuz398;
    zuz398 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(15)));
    uint64_t zuz399;
    zuz399 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(7)));
    struct zast zgaz381;
    CREATE(zast)(&zgaz381);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3237;
      zgsz3237.ztup0 = zuz397;
      zgsz3237.ztup1 = zuz398;
      zgsz3237.ztup2 = zuz399;
      zgsz3237.ztup3 = zXOR;
      zRTYPE(&zgaz381, zgsz3237);
    
    }
    {
      struct zast zgsz3327;
      CREATE(zast)(&zgsz3327);
      COPY(zast)(&zgsz3327, zgaz381);
      zSomez3z5unionz0zzast(&zgsz3226, zgsz3327);
      KILL(zast)(&zgsz3327);
    }
    KILL(zast)(&zgaz381);
  
  
  
  
    goto finish_match_111;
  }
case_115: ;
  {
    uint64_t zv__12;
    zv__12 = zmergez3var;
    bool zgaz388;
    {
      uint64_t zgaz386;
      zgaz386 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__12 >> INT64_C(25)));
      zgaz388 = (zgaz386 == UINT64_C(0b0000001));
    
    }
    bool zgsz3239;
    if (zgaz388) {
    uint64_t zgaz387;
    zgaz387 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__12 >> INT64_C(0)));
    zgsz3239 = (zgaz387 == UINT64_C(0b0110011));
  
    } else {  zgsz3239 = false;  }
    bool zgsz3241;
    zgsz3241 = zgsz3239;
  
    if (!(zgsz3241)) {
  
    goto case_116;
    }
    uint64_t zuz3100;
    zuz3100 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(20)));
    uint64_t zuz3101;
    zuz3101 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(15)));
    uint64_t zuz3102;
    zuz3102 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(7)));
    struct zast zgaz385;
    CREATE(zast)(&zgaz385);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3240;
      zgsz3240.ztup0 = zuz3100;
      zgsz3240.ztup1 = zuz3101;
      zgsz3240.ztup2 = zuz3102;
      zgsz3240.ztup3 = zMUL;
      zRTYPE(&zgaz385, zgsz3240);
    
    }
    {
      struct zast zgsz3328;
      CREATE(zast)(&zgsz3328);
      COPY(zast)(&zgsz3328, zgaz385);
      zSomez3z5unionz0zzast(&zgsz3226, zgsz3328);
      KILL(zast)(&zgsz3328);
    }
    KILL(zast)(&zgaz385);
  
  
  
  
    goto finish_match_111;
  }
case_116: ;
  {
    uint64_t zv__15;
    zv__15 = zmergez3var;
    bool zgaz392;
    {
      uint64_t zgaz390;
      zgaz390 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__15 >> INT64_C(25)));
      zgaz392 = (zgaz390 == UINT64_C(0b0000001));
    
    }
    bool zgsz3242;
    if (zgaz392) {
    uint64_t zgaz391;
    zgaz391 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__15 >> INT64_C(0)));
    zgsz3242 = (zgaz391 == UINT64_C(0b0110011));
  
    } else {  zgsz3242 = false;  }
    bool zgsz3244;
    zgsz3244 = zgsz3242;
  
    if (!(zgsz3244)) {
  
    goto case_117;
    }
    uint64_t zuz3103;
    zuz3103 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(20)));
    uint64_t zuz3104;
    zuz3104 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(15)));
    uint64_t zuz3105;
    zuz3105 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(7)));
    struct zast zgaz389;
    CREATE(zast)(&zgaz389);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3243;
      zgsz3243.ztup0 = zuz3103;
      zgsz3243.ztup1 = zuz3104;
      zgsz3243.ztup2 = zuz3105;
      zgsz3243.ztup3 = zDIV;
      zRTYPE(&zgaz389, zgsz3243);
    
    }
    {
      struct zast zgsz3329;
      CREATE(zast)(&zgsz3329);
      COPY(zast)(&zgsz3329, zgaz389);
      zSomez3z5unionz0zzast(&zgsz3226, zgsz3329);
      KILL(zast)(&zgsz3329);
    }
    KILL(zast)(&zgaz389);
  
  
  
  
    goto finish_match_111;
  }
case_117: ;
  {
    uint64_t zv__18;
    zv__18 = zmergez3var;
    bool zgaz396;
    {
      uint64_t zgaz394;
      zgaz394 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__18 >> INT64_C(25)));
      zgaz396 = (zgaz394 == UINT64_C(0b0000001));
    
    }
    bool zgsz3245;
    if (zgaz396) {
    uint64_t zgaz395;
    zgaz395 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__18 >> INT64_C(0)));
    zgsz3245 = (zgaz395 == UINT64_C(0b0110011));
  
    } else {  zgsz3245 = false;  }
    bool zgsz3247;
    zgsz3247 = zgsz3245;
  
    if (!(zgsz3247)) {
  
    goto case_118;
    }
    uint64_t zuz3106;
    zuz3106 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(20)));
    uint64_t zuz3107;
    zuz3107 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(15)));
    uint64_t zuz3108;
    zuz3108 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(7)));
    struct zast zgaz393;
    CREATE(zast)(&zgaz393);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3246;
      zgsz3246.ztup0 = zuz3106;
      zgsz3246.ztup1 = zuz3107;
      zgsz3246.ztup2 = zuz3108;
      zgsz3246.ztup3 = zREM;
      zRTYPE(&zgaz393, zgsz3246);
    
    }
    {
      struct zast zgsz3330;
      CREATE(zast)(&zgsz3330);
      COPY(zast)(&zgsz3330, zgaz393);
      zSomez3z5unionz0zzast(&zgsz3226, zgsz3330);
      KILL(zast)(&zgsz3330);
    }
    KILL(zast)(&zgaz393);
  
  
  
  
    goto finish_match_111;
  }
case_118: ;
  {
    uint64_t zv__21;
    zv__21 = zmergez3var;
    uint64_t zgaz398;
    zgaz398 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__21 >> INT64_C(0)));
    bool zgsz3249;
    zgsz3249 = (zgaz398 == UINT64_C(0b0010011));
  
    if (!(zgsz3249)) {
  
    goto case_119;
    }
    uint64_t zimm;
    zimm = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__21 >> INT64_C(20)));
    uint64_t zuz3109;
    zuz3109 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__21 >> INT64_C(15)));
    uint64_t zuz3110;
    zuz3110 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__21 >> INT64_C(7)));
    uint64_t zimmshadowz31;
    zimmshadowz31 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__21 >> INT64_C(20)));
    struct zast zgaz397;
    CREATE(zast)(&zgaz397);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3248;
      zgsz3248.ztup0 = zimmshadowz31;
      zgsz3248.ztup1 = zuz3109;
      zgsz3248.ztup2 = zuz3110;
      zgsz3248.ztup3 = zADDI;
      zITYPE(&zgaz397, zgsz3248);
    
    }
    {
      struct zast zgsz3331;
      CREATE(zast)(&zgsz3331);
      COPY(zast)(&zgsz3331, zgaz397);
      zSomez3z5unionz0zzast(&zgsz3226, zgsz3331);
      KILL(zast)(&zgsz3331);
    }
    KILL(zast)(&zgaz397);
  
  
  
  
  
    goto finish_match_111;
  }
case_119: ;
  {
    uint64_t zv__23;
    zv__23 = zmergez3var;
    uint64_t zgaz3100;
    zgaz3100 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__23 >> INT64_C(0)));
    bool zgsz3251;
    zgsz3251 = (zgaz3100 == UINT64_C(0b0010011));
  
    if (!(zgsz3251)) {
  
    goto case_120;
    }
    uint64_t zuz3111;
    zuz3111 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__23 >> INT64_C(20)));
    uint64_t zuz3112;
    zuz3112 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__23 >> INT64_C(15)));
    uint64_t zuz3113;
    zuz3113 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__23 >> INT64_C(7)));
    uint64_t zimmshadowz32;
    zimmshadowz32 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__23 >> INT64_C(20)));
    struct zast zgaz399;
    CREATE(zast)(&zgaz399);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3250;
      zgsz3250.ztup0 = zimmshadowz32;
      zgsz3250.ztup1 = zuz3112;
      zgsz3250.ztup2 = zuz3113;
      zgsz3250.ztup3 = zSLTI;
      zITYPE(&zgaz399, zgsz3250);
    
    }
    {
      struct zast zgsz3332;
      CREATE(zast)(&zgsz3332);
      COPY(zast)(&zgsz3332, zgaz399);
      zSomez3z5unionz0zzast(&zgsz3226, zgsz3332);
      KILL(zast)(&zgsz3332);
    }
    KILL(zast)(&zgaz399);
  
  
  
  
  
    goto finish_match_111;
  }
case_120: ;
  {
    uint64_t zv__25;
    zv__25 = zmergez3var;
    uint64_t zgaz3102;
    zgaz3102 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__25 >> INT64_C(0)));
    bool zgsz3253;
    zgsz3253 = (zgaz3102 == UINT64_C(0b0010011));
  
    if (!(zgsz3253)) {
  
    goto case_121;
    }
    uint64_t zuz3114;
    zuz3114 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__25 >> INT64_C(20)));
    uint64_t zuz3115;
    zuz3115 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__25 >> INT64_C(15)));
    uint64_t zuz3116;
    zuz3116 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__25 >> INT64_C(7)));
    uint64_t zimmshadowz33;
    zimmshadowz33 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__25 >> INT64_C(20)));
    struct zast zgaz3101;
    CREATE(zast)(&zgaz3101);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3252;
      zgsz3252.ztup0 = zimmshadowz33;
      zgsz3252.ztup1 = zuz3115;
      zgsz3252.ztup2 = zuz3116;
      zgsz3252.ztup3 = zANDI;
      zITYPE(&zgaz3101, zgsz3252);
    
    }
    {
      struct zast zgsz3333;
      CREATE(zast)(&zgsz3333);
      COPY(zast)(&zgsz3333, zgaz3101);
      zSomez3z5unionz0zzast(&zgsz3226, zgsz3333);
      KILL(zast)(&zgsz3333);
    }
    KILL(zast)(&zgaz3101);
  
  
  
  
  
    goto finish_match_111;
  }
case_121: ;
  {
    uint64_t zv__27;
    zv__27 = zmergez3var;
    uint64_t zgaz3104;
    zgaz3104 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__27 >> INT64_C(0)));
    bool zgsz3255;
    zgsz3255 = (zgaz3104 == UINT64_C(0b0010011));
  
    if (!(zgsz3255)) {
  
    goto case_122;
    }
    uint64_t zuz3117;
    zuz3117 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__27 >> INT64_C(20)));
    uint64_t zuz3118;
    zuz3118 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__27 >> INT64_C(15)));
    uint64_t zuz3119;
    zuz3119 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__27 >> INT64_C(7)));
    uint64_t zimmshadowz34;
    zimmshadowz34 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__27 >> INT64_C(20)));
    struct zast zgaz3103;
    CREATE(zast)(&zgaz3103);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3254;
      zgsz3254.ztup0 = zimmshadowz34;
      zgsz3254.ztup1 = zuz3118;
      zgsz3254.ztup2 = zuz3119;
      zgsz3254.ztup3 = zORI;
      zITYPE(&zgaz3103, zgsz3254);
    
    }
    {
      struct zast zgsz3334;
      CREATE(zast)(&zgsz3334);
      COPY(zast)(&zgsz3334, zgaz3103);
      zSomez3z5unionz0zzast(&zgsz3226, zgsz3334);
      KILL(zast)(&zgsz3334);
    }
    KILL(zast)(&zgaz3103);
  
  
  
  
  
    goto finish_match_111;
  }
case_122: ;
  {
    uint64_t zv__29;
    zv__29 = zmergez3var;
    uint64_t zgaz3106;
    zgaz3106 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__29 >> INT64_C(0)));
    bool zgsz3257;
    zgsz3257 = (zgaz3106 == UINT64_C(0b0010011));
  
    if (!(zgsz3257)) {
  
    goto case_123;
    }
    uint64_t zuz3120;
    zuz3120 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__29 >> INT64_C(20)));
    uint64_t zuz3121;
    zuz3121 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__29 >> INT64_C(15)));
    uint64_t zuz3122;
    zuz3122 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__29 >> INT64_C(7)));
    uint64_t zimmshadowz35;
    zimmshadowz35 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__29 >> INT64_C(20)));
    struct zast zgaz3105;
    CREATE(zast)(&zgaz3105);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3256;
      zgsz3256.ztup0 = zimmshadowz35;
      zgsz3256.ztup1 = zuz3121;
      zgsz3256.ztup2 = zuz3122;
      zgsz3256.ztup3 = zXORI;
      zITYPE(&zgaz3105, zgsz3256);
    
    }
    {
      struct zast zgsz3335;
      CREATE(zast)(&zgsz3335);
      COPY(zast)(&zgsz3335, zgaz3105);
      zSomez3z5unionz0zzast(&zgsz3226, zgsz3335);
      KILL(zast)(&zgsz3335);
    }
    KILL(zast)(&zgaz3105);
  
  
  
  
  
    goto finish_match_111;
  }
case_123: ;
  {
    uint64_t zv__31;
    zv__31 = zmergez3var;
    uint64_t zgaz3108;
    zgaz3108 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__31 >> INT64_C(0)));
    bool zgsz3259;
    zgsz3259 = (zgaz3108 == UINT64_C(0b1100111));
  
    if (!(zgsz3259)) {
  
    goto case_124;
    }
    uint64_t zuz3123;
    zuz3123 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__31 >> INT64_C(20)));
    uint64_t zuz3124;
    zuz3124 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__31 >> INT64_C(15)));
    uint64_t zuz3125;
    zuz3125 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__31 >> INT64_C(7)));
    uint64_t zimmshadowz36;
    zimmshadowz36 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__31 >> INT64_C(20)));
    struct zast zgaz3107;
    CREATE(zast)(&zgaz3107);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3258;
      zgsz3258.ztup0 = zimmshadowz36;
      zgsz3258.ztup1 = zuz3124;
      zgsz3258.ztup2 = zuz3125;
      zgsz3258.ztup3 = zJALR;
      zITYPE(&zgaz3107, zgsz3258);
    
    }
    {
      struct zast zgsz3336;
      CREATE(zast)(&zgsz3336);
      COPY(zast)(&zgsz3336, zgaz3107);
      zSomez3z5unionz0zzast(&zgsz3226, zgsz3336);
      KILL(zast)(&zgsz3336);
    }
    KILL(zast)(&zgaz3107);
  
  
  
  
  
    goto finish_match_111;
  }
case_124: ;
  {
    uint64_t zv__33;
    zv__33 = zmergez3var;
    uint64_t zgaz3110;
    zgaz3110 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__33 >> INT64_C(0)));
    bool zgsz3261;
    zgsz3261 = (zgaz3110 == UINT64_C(0b0000011));
  
    if (!(zgsz3261)) {
  
    goto case_125;
    }
    uint64_t zuz3126;
    zuz3126 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__33 >> INT64_C(20)));
    uint64_t zuz3127;
    zuz3127 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__33 >> INT64_C(15)));
    uint64_t zuz3128;
    zuz3128 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__33 >> INT64_C(7)));
    uint64_t zimmshadowz37;
    zimmshadowz37 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__33 >> INT64_C(20)));
    struct zast zgaz3109;
    CREATE(zast)(&zgaz3109);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3260;
      zgsz3260.ztup0 = zimmshadowz37;
      zgsz3260.ztup1 = zuz3127;
      zgsz3260.ztup2 = zuz3128;
      zgsz3260.ztup3 = zLW;
      zITYPE(&zgaz3109, zgsz3260);
    
    }
    {
      struct zast zgsz3337;
      CREATE(zast)(&zgsz3337);
      COPY(zast)(&zgsz3337, zgaz3109);
      zSomez3z5unionz0zzast(&zgsz3226, zgsz3337);
      KILL(zast)(&zgsz3337);
    }
    KILL(zast)(&zgaz3109);
  
  
  
  
  
    goto finish_match_111;
  }
case_125: ;
  {
    uint64_t zv__35;
    zv__35 = zmergez3var;
    uint64_t zgaz3112;
    zgaz3112 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__35 >> INT64_C(0)));
    bool zgsz3263;
    zgsz3263 = (zgaz3112 == UINT64_C(0b0100011));
  
    if (!(zgsz3263)) {
  
    goto case_126;
    }
    uint64_t zimm2;
    zimm2 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__35 >> INT64_C(25)));
    uint64_t zuz3129;
    zuz3129 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__35 >> INT64_C(20)));
    uint64_t zuz3130;
    zuz3130 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__35 >> INT64_C(15)));
    uint64_t zimm2shadowz38;
    zimm2shadowz38 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__35 >> INT64_C(25)));
    uint64_t zimm1;
    zimm1 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__35 >> INT64_C(7)));
    struct zast zgaz3111;
    CREATE(zast)(&zgaz3111);
    {
      struct ztuple_z8z5bv7zCz0z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzsopz9 zgsz3262;
      zgsz3262.ztup0 = zimm2shadowz38;
      zgsz3262.ztup1 = zuz3129;
      zgsz3262.ztup2 = zuz3130;
      zgsz3262.ztup3 = zimm1;
      zgsz3262.ztup4 = zSW;
      zSTYPE(&zgaz3111, zgsz3262);
    
    }
    {
      struct zast zgsz3338;
      CREATE(zast)(&zgsz3338);
      COPY(zast)(&zgsz3338, zgaz3111);
      zSomez3z5unionz0zzast(&zgsz3226, zgsz3338);
      KILL(zast)(&zgsz3338);
    }
    KILL(zast)(&zgaz3111);
  
  
  
  
  
  
    goto finish_match_111;
  }
case_126: ;
  {
    uint64_t zv__37;
    zv__37 = zmergez3var;
    uint64_t zgaz3114;
    zgaz3114 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__37 >> INT64_C(0)));
    bool zgsz3265;
    zgsz3265 = (zgaz3114 == UINT64_C(0b1100011));
  
    if (!(zgsz3265)) {
  
    goto case_127;
    }
    uint64_t zimm4;
    zimm4 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__37 >> INT64_C(31)));
    uint64_t zuz3131;
    zuz3131 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__37 >> INT64_C(20)));
    uint64_t zuz3132;
    zuz3132 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__37 >> INT64_C(15)));
    uint64_t zimm4shadowz39;
    zimm4shadowz39 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__37 >> INT64_C(31)));
    uint64_t zimm3;
    zimm3 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__37 >> INT64_C(7)));
    uint64_t zuz3133;
    zuz3133 = (safe_rshift(UINT64_MAX, 64 - 6) & (zv__37 >> INT64_C(25)));
    uint64_t zuz3134;
    zuz3134 = (safe_rshift(UINT64_MAX, 64 - 4) & (zv__37 >> INT64_C(8)));
    struct zast zgaz3113;
    CREATE(zast)(&zgaz3113);
    {
      struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 zgsz3264;
      zgsz3264.ztup0 = zimm4shadowz39;
      zgsz3264.ztup1 = zuz3133;
      zgsz3264.ztup2 = zuz3131;
      zgsz3264.ztup3 = zuz3132;
      zgsz3264.ztup4 = zuz3134;
      zgsz3264.ztup5 = zimm3;
      zgsz3264.ztup6 = zBEQ;
      zBTYPE(&zgaz3113, zgsz3264);
    
    }
    {
      struct zast zgsz3339;
      CREATE(zast)(&zgsz3339);
      COPY(zast)(&zgsz3339, zgaz3113);
      zSomez3z5unionz0zzast(&zgsz3226, zgsz3339);
      KILL(zast)(&zgsz3339);
    }
    KILL(zast)(&zgaz3113);
  
  
  
  
  
  
  
  
    goto finish_match_111;
  }
case_127: ;
  {
    uint64_t zv__39;
    zv__39 = zmergez3var;
    uint64_t zgaz3116;
    zgaz3116 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__39 >> INT64_C(0)));
    bool zgsz3267;
    zgsz3267 = (zgaz3116 == UINT64_C(0b1100011));
  
    if (!(zgsz3267)) {
  
    goto case_128;
    }
    uint64_t zuz3135;
    zuz3135 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__39 >> INT64_C(31)));
    uint64_t zuz3136;
    zuz3136 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__39 >> INT64_C(20)));
    uint64_t zuz3137;
    zuz3137 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__39 >> INT64_C(15)));
    uint64_t zimm4shadowz310;
    zimm4shadowz310 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__39 >> INT64_C(31)));
    uint64_t zuz3138;
    zuz3138 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__39 >> INT64_C(7)));
    uint64_t zuz3139;
    zuz3139 = (safe_rshift(UINT64_MAX, 64 - 6) & (zv__39 >> INT64_C(25)));
    uint64_t zuz3140;
    zuz3140 = (safe_rshift(UINT64_MAX, 64 - 4) & (zv__39 >> INT64_C(8)));
    struct zast zgaz3115;
    CREATE(zast)(&zgaz3115);
    {
      struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 zgsz3266;
      zgsz3266.ztup0 = zimm4shadowz310;
      zgsz3266.ztup1 = zuz3139;
      zgsz3266.ztup2 = zuz3136;
      zgsz3266.ztup3 = zuz3137;
      zgsz3266.ztup4 = zuz3140;
      zgsz3266.ztup5 = zuz3138;
      zgsz3266.ztup6 = zBNE;
      zBTYPE(&zgaz3115, zgsz3266);
    
    }
    {
      struct zast zgsz3340;
      CREATE(zast)(&zgsz3340);
      COPY(zast)(&zgsz3340, zgaz3115);
      zSomez3z5unionz0zzast(&zgsz3226, zgsz3340);
      KILL(zast)(&zgsz3340);
    }
    KILL(zast)(&zgaz3115);
  
  
  
  
  
  
  
  
    goto finish_match_111;
  }
case_128: ;
  {
    uint64_t zv__41;
    zv__41 = zmergez3var;
    uint64_t zgaz3118;
    zgaz3118 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__41 >> INT64_C(0)));
    bool zgsz3269;
    zgsz3269 = (zgaz3118 == UINT64_C(0b0110111));
  
    if (!(zgsz3269)) {
  
    goto case_129;
    }
    uint64_t zuz3141;
    zuz3141 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__41 >> INT64_C(12)));
    uint64_t zuz3142;
    zuz3142 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__41 >> INT64_C(7)));
    uint64_t zimmshadowz311;
    zimmshadowz311 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__41 >> INT64_C(12)));
    struct zast zgaz3117;
    CREATE(zast)(&zgaz3117);
    {
      struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 zgsz3268;
      zgsz3268.ztup0 = zimmshadowz311;
      zgsz3268.ztup1 = zuz3142;
      zgsz3268.ztup2 = zLUI;
      zUTYPE(&zgaz3117, zgsz3268);
    
    }
    {
      struct zast zgsz3341;
      CREATE(zast)(&zgsz3341);
      COPY(zast)(&zgsz3341, zgaz3117);
      zSomez3z5unionz0zzast(&zgsz3226, zgsz3341);
      KILL(zast)(&zgsz3341);
    }
    KILL(zast)(&zgaz3117);
  
  
  
  
    goto finish_match_111;
  }
case_129: ;
  {
    uint64_t zv__43;
    zv__43 = zmergez3var;
    uint64_t zgaz3120;
    zgaz3120 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__43 >> INT64_C(0)));
    bool zgsz3271;
    zgsz3271 = (zgaz3120 == UINT64_C(0b0010111));
  
    if (!(zgsz3271)) {
  
    goto case_130;
    }
    uint64_t zuz3143;
    zuz3143 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__43 >> INT64_C(12)));
    uint64_t zuz3144;
    zuz3144 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__43 >> INT64_C(7)));
    uint64_t zimmshadowz312;
    zimmshadowz312 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__43 >> INT64_C(12)));
    struct zast zgaz3119;
    CREATE(zast)(&zgaz3119);
    {
      struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 zgsz3270;
      zgsz3270.ztup0 = zimmshadowz312;
      zgsz3270.ztup1 = zuz3144;
      zgsz3270.ztup2 = zAUIPC;
      zUTYPE(&zgaz3119, zgsz3270);
    
    }
    {
      struct zast zgsz3342;
      CREATE(zast)(&zgsz3342);
      COPY(zast)(&zgsz3342, zgaz3119);
      zSomez3z5unionz0zzast(&zgsz3226, zgsz3342);
      KILL(zast)(&zgsz3342);
    }
    KILL(zast)(&zgaz3119);
  
  
  
  
    goto finish_match_111;
  }
case_130: ;
  {
    uint64_t zv__45;
    zv__45 = zmergez3var;
    uint64_t zgaz3122;
    zgaz3122 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__45 >> INT64_C(0)));
    bool zgsz3273;
    zgsz3273 = (zgaz3122 == UINT64_C(0b1101111));
  
    if (!(zgsz3273)) {
  
    goto case_131;
    }
    uint64_t zuz3145;
    zuz3145 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__45 >> INT64_C(31)));
    uint64_t zuz3146;
    zuz3146 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__45 >> INT64_C(7)));
    uint64_t zimm4shadowz313;
    zimm4shadowz313 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__45 >> INT64_C(31)));
    uint64_t zuz3147;
    zuz3147 = (safe_rshift(UINT64_MAX, 64 - 8) & (zv__45 >> INT64_C(12)));
    uint64_t zuz3148;
    zuz3148 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__45 >> INT64_C(20)));
    uint64_t zuz3149;
    zuz3149 = (safe_rshift(UINT64_MAX, 64 - 10) & (zv__45 >> INT64_C(21)));
    struct zast zgaz3121;
    CREATE(zast)(&zgaz3121);
    {
      struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv8zCz0z5bv5zCz0z5enumz0zzjopz9 zgsz3272;
      zgsz3272.ztup0 = zimm4shadowz313;
      zgsz3272.ztup1 = zuz3149;
      zgsz3272.ztup2 = zuz3148;
      zgsz3272.ztup3 = zuz3147;
      zgsz3272.ztup4 = zuz3146;
      zgsz3272.ztup5 = zJAL;
      zJTYPE(&zgaz3121, zgsz3272);
    
    }
    {
      struct zast zgsz3343;
      CREATE(zast)(&zgsz3343);
      COPY(zast)(&zgsz3343, zgaz3121);
      zSomez3z5unionz0zzast(&zgsz3226, zgsz3343);
      KILL(zast)(&zgsz3343);
    }
    KILL(zast)(&zgaz3121);
  
  
  
  
  
  
  
    goto finish_match_111;
  }
case_131: ;
  {
    uint64_t zv__47;
    zv__47 = zmergez3var;
    bool zgsz3274;
    zgsz3274 = (zv__47 == UINT64_C(0x00100073));
    if (!(zgsz3274)) {
  
    goto case_132;
    }
    struct zast zgaz3123;
    CREATE(zast)(&zgaz3123);
    zEBREAK(&zgaz3123, UNIT);
    {
      struct zast zgsz3344;
      CREATE(zast)(&zgsz3344);
      COPY(zast)(&zgsz3344, zgaz3123);
      zSomez3z5unionz0zzast(&zgsz3226, zgsz3344);
      KILL(zast)(&zgsz3344);
    }
    KILL(zast)(&zgaz3123);
  
    goto finish_match_111;
  }
case_132: ;
  sail_match_failure("decode");
finish_match_111: ;
  COPY(zoption)((*(&zcbz318)), zgsz3226);
  KILL(zoption)(&zgsz3226);
end_function_133: ;
  goto end_function_143;
end_block_exception_134: ;
  goto end_function_143;
end_function_143: ;
}

unit zmain(unit);

lbits zghz3183;
lbits zghz3184;
lbits zghz3185;
lbits zghz3186;
lbits zghz3187;
sail_int zghz3188;
lbits zghz3189;
lbits zghz3190;
lbits zghz3191;
sail_int zghz3192;
sail_int zghz3193;
sail_int zghz3194;
lbits zghz3195;

void startup_zmain(void)
{
  CREATE(lbits)(&zghz3183);
  CREATE(lbits)(&zghz3184);
  CREATE(lbits)(&zghz3185);
  CREATE(lbits)(&zghz3186);
  CREATE(lbits)(&zghz3187);
  CREATE(sail_int)(&zghz3188);
  CREATE(lbits)(&zghz3189);
  CREATE(lbits)(&zghz3190);
  CREATE(lbits)(&zghz3191);
  CREATE(sail_int)(&zghz3192);
  CREATE(sail_int)(&zghz3193);
  CREATE(sail_int)(&zghz3194);
  CREATE(lbits)(&zghz3195);
}


// struct tuple_(%bv8, %bv8)
struct ztuple_z8z5bv8zCz0z5bv8z9 {
  uint64_t ztup0;
  uint64_t ztup1;
};

static void COPY(ztuple_z8z5bv8zCz0z5bv8z9)(struct ztuple_z8z5bv8zCz0z5bv8z9 *rop, const struct ztuple_z8z5bv8zCz0z5bv8z9 op) {
  rop->ztup0 = op.ztup0;
  rop->ztup1 = op.ztup1;
}

static bool EQUAL(ztuple_z8z5bv8zCz0z5bv8z9)(struct ztuple_z8z5bv8zCz0z5bv8z9 op1, struct ztuple_z8z5bv8zCz0z5bv8z9 op2) {
  return EQUAL(fbits)(op1.ztup0, op2.ztup0) && EQUAL(fbits)(op1.ztup1, op2.ztup1);
}

unit zmain(unit zgsz3275)
{
  __label__ case_137, finish_match_136, end_function_138, end_block_exception_139;

  unit zcbz319;
  {
    RECREATE(sail_int)(&zghz3192);
    elf_entry(&zghz3192, UNIT);
    {
      RECREATE(sail_int)(&zghz3193);
      CONVERT_OF(sail_int, mach_int)(&zghz3193, INT64_C(32));
      RECREATE(sail_int)(&zghz3194);
      CONVERT_OF(sail_int, mach_int)(&zghz3194, INT64_C(0));
      RECREATE(lbits)(&zghz3195);
      get_slice_int(&zghz3195, zghz3193, zghz3192, zghz3194);
      zPC = CONVERT_OF(fbits, lbits)(zghz3195, true);
    }
    unit zgsz3283;
    zgsz3283 = UNIT;
  }
  {
    unit zgsz3281;
    {
      RECREATE(lbits)(&zghz3191);
      CONVERT_OF(lbits, fbits)(&zghz3191, zPC, UINT64_C(32) , true);
      zgsz3281 = print_bits("PC = ", zghz3191);
    }
  }
  {
    uint64_t zline;
    zline = zread_mem(zPC);
    unit zgsz3279;
    {
      RECREATE(lbits)(&zghz3190);
      CONVERT_OF(lbits, fbits)(&zghz3190, zline, UINT64_C(32) , true);
      zgsz3279 = print_bits("line = ", zghz3190);
    }
  
  }
  uint64_t ztest;
  ztest = UINT64_C(0xFF);
  {
    {
      RECREATE(lbits)(&zghz3187);
      CONVERT_OF(lbits, fbits)(&zghz3187, ztest, UINT64_C(8) , true);
      RECREATE(sail_int)(&zghz3188);
      CONVERT_OF(sail_int, mach_int)(&zghz3188, INT64_C(3));
      RECREATE(lbits)(&zghz3189);
      shiftl(&zghz3189, zghz3187, zghz3188);
      ztest = CONVERT_OF(fbits, lbits)(zghz3189, true);
    }
    unit zgsz3289;
    zgsz3289 = UNIT;
  }
  {
    unit zgsz3287;
    {
      RECREATE(lbits)(&zghz3186);
      CONVERT_OF(lbits, fbits)(&zghz3186, ztest, UINT64_C(8) , true);
      zgsz3287 = print_bits("test = ", zghz3186);
    }
  }
  uint64_t za;
  za = UINT64_C(0x7);
  uint64_t zb;
  zb = UINT64_C(0x3);
  struct ztuple_z8z5bv8zCz0z5bv8z9 zgaz3125;
  {
    RECREATE(lbits)(&zghz3184);
    CONVERT_OF(lbits, fbits)(&zghz3184, za, UINT64_C(4) , true);
    RECREATE(lbits)(&zghz3185);
    CONVERT_OF(lbits, fbits)(&zghz3185, zb, UINT64_C(4) , true);
    struct ztuple_z8z5bvzCz0z5bvz9 zgsz3292;
    CREATE(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3292);
    zdiv_bitvector(&zgsz3292, zghz3184, zghz3185);
    /* conversions */
    zgaz3125.ztup0 = CONVERT_OF(fbits, lbits)(zgsz3292.ztup0, true);
    zgaz3125.ztup1 = CONVERT_OF(fbits, lbits)(zgsz3292.ztup1, true);
    /* end conversions */
    KILL(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3292);
  }
  unit zgsz3293;
  {
    uint64_t zv1;
    zv1 = zgaz3125.ztup0;
    uint64_t zv2;
    zv2 = zgaz3125.ztup1;
    {
      unit zgsz3294;
      {
        RECREATE(lbits)(&zghz3183);
        CONVERT_OF(lbits, fbits)(&zghz3183, zv2, UINT64_C(8) , true);
        zgsz3294 = print_bits("v2 = ", zghz3183);
      }
    }
    zgsz3293 = print_endline("dummy");
  
  
    goto finish_match_136;
  }
case_137: ;
  sail_match_failure("main");
finish_match_136: ;
  zcbz319 = zgsz3293;





end_function_138: ;
  return zcbz319;
end_block_exception_139: ;

  return UNIT;
}



void finish_zmain(void)
{
  KILL(lbits)(&zghz3195);
  KILL(sail_int)(&zghz3194);
  KILL(sail_int)(&zghz3193);
  KILL(sail_int)(&zghz3192);
  KILL(lbits)(&zghz3191);
  KILL(lbits)(&zghz3190);
  KILL(lbits)(&zghz3189);
  KILL(sail_int)(&zghz3188);
  KILL(lbits)(&zghz3187);
  KILL(lbits)(&zghz3186);
  KILL(lbits)(&zghz3185);
  KILL(lbits)(&zghz3184);
  KILL(lbits)(&zghz3183);
}

unit zinitializze_registers(unit);

sail_int zghz3196;
lbits zghz3197;
sail_int zghz3198;
lbits zghz3199;
sail_int zghz3200;
lbits zghz3201;
sail_int zghz3202;
lbits zghz3203;
sail_int zghz3204;
lbits zghz3205;
sail_int zghz3206;
lbits zghz3207;
sail_int zghz3208;
lbits zghz3209;
sail_int zghz3210;
lbits zghz3211;
sail_int zghz3212;
lbits zghz3213;

void startup_zinitializze_registers(void)
{
  CREATE(sail_int)(&zghz3196);
  CREATE(lbits)(&zghz3197);
  CREATE(sail_int)(&zghz3198);
  CREATE(lbits)(&zghz3199);
  CREATE(sail_int)(&zghz3200);
  CREATE(lbits)(&zghz3201);
  CREATE(sail_int)(&zghz3202);
  CREATE(lbits)(&zghz3203);
  CREATE(sail_int)(&zghz3204);
  CREATE(lbits)(&zghz3205);
  CREATE(sail_int)(&zghz3206);
  CREATE(lbits)(&zghz3207);
  CREATE(sail_int)(&zghz3208);
  CREATE(lbits)(&zghz3209);
  CREATE(sail_int)(&zghz3210);
  CREATE(lbits)(&zghz3211);
  CREATE(sail_int)(&zghz3212);
  CREATE(lbits)(&zghz3213);
}

unit zinitializze_registers(unit zgsz3297)
{
  __label__ end_function_141, end_block_exception_142;

  unit zcbz320;
  {
    {
      RECREATE(sail_int)(&zghz3212);
      CONVERT_OF(sail_int, mach_int)(&zghz3212, INT64_C(32));
      RECREATE(lbits)(&zghz3213);
      UNDEFINED(lbits)(&zghz3213, zghz3212);
      zPC = CONVERT_OF(fbits, lbits)(zghz3213, true);
    }
    unit zgsz3321;
    zgsz3321 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3210);
      CONVERT_OF(sail_int, mach_int)(&zghz3210, INT64_C(32));
      RECREATE(lbits)(&zghz3211);
      UNDEFINED(lbits)(&zghz3211, zghz3210);
      zzzero = CONVERT_OF(fbits, lbits)(zghz3211, true);
    }
    unit zgsz3320;
    zgsz3320 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3208);
      CONVERT_OF(sail_int, mach_int)(&zghz3208, INT64_C(32));
      RECREATE(lbits)(&zghz3209);
      UNDEFINED(lbits)(&zghz3209, zghz3208);
      zra = CONVERT_OF(fbits, lbits)(zghz3209, true);
    }
    unit zgsz3319;
    zgsz3319 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3206);
      CONVERT_OF(sail_int, mach_int)(&zghz3206, INT64_C(32));
      RECREATE(lbits)(&zghz3207);
      UNDEFINED(lbits)(&zghz3207, zghz3206);
      zsp = CONVERT_OF(fbits, lbits)(zghz3207, true);
    }
    unit zgsz3318;
    zgsz3318 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3204);
      CONVERT_OF(sail_int, mach_int)(&zghz3204, INT64_C(32));
      RECREATE(lbits)(&zghz3205);
      UNDEFINED(lbits)(&zghz3205, zghz3204);
      zgp = CONVERT_OF(fbits, lbits)(zghz3205, true);
    }
    unit zgsz3317;
    zgsz3317 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3202);
      CONVERT_OF(sail_int, mach_int)(&zghz3202, INT64_C(32));
      RECREATE(lbits)(&zghz3203);
      UNDEFINED(lbits)(&zghz3203, zghz3202);
      za0 = CONVERT_OF(fbits, lbits)(zghz3203, true);
    }
    unit zgsz3316;
    zgsz3316 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3200);
      CONVERT_OF(sail_int, mach_int)(&zghz3200, INT64_C(32));
      RECREATE(lbits)(&zghz3201);
      UNDEFINED(lbits)(&zghz3201, zghz3200);
      za1 = CONVERT_OF(fbits, lbits)(zghz3201, true);
    }
    unit zgsz3315;
    zgsz3315 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3198);
      CONVERT_OF(sail_int, mach_int)(&zghz3198, INT64_C(32));
      RECREATE(lbits)(&zghz3199);
      UNDEFINED(lbits)(&zghz3199, zghz3198);
      za2 = CONVERT_OF(fbits, lbits)(zghz3199, true);
    }
    unit zgsz3314;
    zgsz3314 = UNIT;
  }
  {
    RECREATE(sail_int)(&zghz3196);
    CONVERT_OF(sail_int, mach_int)(&zghz3196, INT64_C(32));
    RECREATE(lbits)(&zghz3197);
    UNDEFINED(lbits)(&zghz3197, zghz3196);
    za3 = CONVERT_OF(fbits, lbits)(zghz3197, true);
  }
  zcbz320 = UNIT;
end_function_141: ;
  return zcbz320;
end_block_exception_142: ;

  return UNIT;
}



void finish_zinitializze_registers(void)
{
  KILL(lbits)(&zghz3213);
  KILL(sail_int)(&zghz3212);
  KILL(lbits)(&zghz3211);
  KILL(sail_int)(&zghz3210);
  KILL(lbits)(&zghz3209);
  KILL(sail_int)(&zghz3208);
  KILL(lbits)(&zghz3207);
  KILL(sail_int)(&zghz3206);
  KILL(lbits)(&zghz3205);
  KILL(sail_int)(&zghz3204);
  KILL(lbits)(&zghz3203);
  KILL(sail_int)(&zghz3202);
  KILL(lbits)(&zghz3201);
  KILL(sail_int)(&zghz3200);
  KILL(lbits)(&zghz3199);
  KILL(sail_int)(&zghz3198);
  KILL(lbits)(&zghz3197);
  KILL(sail_int)(&zghz3196);
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
  startup_zgt_bit();
  startup_zlt_bit();
  startup_zxor_bitvector();
  startup_ztwos_complement();
  startup_zmul_bitvector();
  startup_zdiv_bitvector();
  startup_zexecute();
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
  finish_zgt_bit();
  finish_zlt_bit();
  finish_zxor_bitvector();
  finish_ztwos_complement();
  finish_zmul_bitvector();
  finish_zdiv_bitvector();
  finish_zexecute();
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
