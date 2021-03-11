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
  __label__ end_function_1, end_block_exception_2, end_function_121;

  bool zgaz31;
  {
    RECREATE(sail_int)(&zghz30);
    length_lbits(&zghz30, zv);
    zgaz31 = lteq(zlen, zghz30);
  }
  if (zgaz31) {  sail_truncate((*(&zcbz30)), zv, zlen);  } else {  zero_extend((*(&zcbz30)), zv, zlen);  }

end_function_1: ;
  goto end_function_121;
end_block_exception_2: ;
  goto end_function_121;
end_function_121: ;
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
  __label__ end_function_4, end_block_exception_5, end_function_120;

  RECREATE(lbits)(&zghz31);
  zeros(&zghz31, zn);
  not_bits((*(&zcbz31)), zghz31);
end_function_4: ;
  goto end_function_120;
end_block_exception_5: ;
  goto end_function_120;
end_function_120: ;
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
  __label__ end_function_7, end_block_exception_8, end_function_119;

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
  goto end_function_119;
end_block_exception_8: ;
  goto end_function_119;
end_function_119: ;
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
  __label__ end_function_11, end_block_exception_12, end_function_118;

  zero_extend((*(&zcbz33)), zxs, zm);
end_function_11: ;
  goto end_function_118;
end_block_exception_12: ;
  goto end_function_118;
end_function_118: ;
}

unit zadd_to_PC(sail_int);

lbits zghz314;
lbits zghz315;

void startup_zadd_to_PC(void)
{
  CREATE(lbits)(&zghz314);
  CREATE(lbits)(&zghz315);
}

unit zadd_to_PC(sail_int zbytes)
{
  __label__ end_function_14, end_block_exception_15;

  unit zcbz34;
  {
    RECREATE(lbits)(&zghz314);
    CONVERT_OF(lbits, fbits)(&zghz314, zPC, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz315);
    add_bits_int(&zghz315, zghz314, zbytes);
    zPC = CONVERT_OF(fbits, lbits)(zghz315, true);
  }
  zcbz34 = UNIT;
end_function_14: ;
  return zcbz34;
end_block_exception_15: ;

  return UNIT;
}



void finish_zadd_to_PC(void)
{
  KILL(lbits)(&zghz315);
  KILL(lbits)(&zghz314);
}

unit zinc_PC(unit);

sail_int zghz316;

void startup_zinc_PC(void)
{    CREATE(sail_int)(&zghz316);
}

unit zinc_PC(unit zgsz314)
{
  __label__ end_function_17, end_block_exception_18;

  unit zcbz35;
  {
    RECREATE(sail_int)(&zghz316);
    CONVERT_OF(sail_int, mach_int)(&zghz316, INT64_C(4));
    zcbz35 = zadd_to_PC(zghz316);
  }
end_function_17: ;
  return zcbz35;
end_block_exception_18: ;

  return UNIT;
}



void finish_zinc_PC(void)
{    KILL(sail_int)(&zghz316);
}

uint64_t zrX(uint64_t);

sail_int zghz317;

void startup_zrX(void)
{    CREATE(sail_int)(&zghz317);
}

uint64_t zrX(uint64_t zr)
{
  __label__ end_function_20, end_block_exception_21;

  uint64_t zcbz36;
  uint64_t zoffset;
  zoffset = (safe_rshift(UINT64_MAX, 64 - 3) & (zr >> INT64_C(0)));
  uint64_t* zgaz312;
  {
    int64_t zgaz311;
    zgaz311 = ((mach_int) zoffset);
    {
      RECREATE(sail_int)(&zghz317);
      CONVERT_OF(sail_int, mach_int)(&zghz317, zgaz311);
      zgaz312 = vector_access_zz5vecz8z6z8z5bv32z9z9(zXs, zghz317);
    }
  
  }
  zcbz36 = *(zgaz312);


end_function_20: ;
  return zcbz36;
end_block_exception_21: ;

  return UINT64_C(0xdeadc0de);
}



void finish_zrX(void)
{    KILL(sail_int)(&zghz317);
}

unit zwX(uint64_t, uint64_t);

sail_int zghz318;
sail_int zghz319;
lbits zghz320;
lbits zghz321;
sail_int zghz322;
sail_int zghz323;
sail_int zghz324;

void startup_zwX(void)
{
  CREATE(sail_int)(&zghz318);
  CREATE(sail_int)(&zghz319);
  CREATE(lbits)(&zghz320);
  CREATE(lbits)(&zghz321);
  CREATE(sail_int)(&zghz322);
  CREATE(sail_int)(&zghz323);
  CREATE(sail_int)(&zghz324);
}

unit zwX(uint64_t zr, uint64_t zv)
{
  __label__ case_24, case_25, finish_match_23, end_function_26, end_block_exception_27;

  unit zcbz37;
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
          RECREATE(sail_int)(&zghz322);
          CONVERT_OF(sail_int, mach_int)(&zghz322, INT64_C(2));
          RECREATE(sail_int)(&zghz323);
          CONVERT_OF(sail_int, mach_int)(&zghz323, INT64_C(0));
          RECREATE(sail_int)(&zghz324);
          sub_int(&zghz324, zghz322, zghz323);
          zgaz313 = CONVERT_OF(mach_int, sail_int)(zghz324);
        }
        zgaz314 = (zgaz313 + INT64_C(1));
      
      }
      {
        RECREATE(sail_int)(&zghz319);
        CONVERT_OF(sail_int, mach_int)(&zghz319, zgaz314);
        RECREATE(lbits)(&zghz320);
        CONVERT_OF(lbits, fbits)(&zghz320, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz321);
        zextzz(&zghz321, zghz319, zghz320);
        zgaz315 = CONVERT_OF(fbits, lbits)(zghz321, true);
      }
    
    }
    bool zgsz324;
    zgsz324 = (zvz30 == zgaz315);
  
    if (!(zgsz324)) {
  
    goto case_24;
    }
    zcbz37 = print_endline("Cannot overwrite hard-wired zero register");
  
    goto finish_match_23;
  }
case_24: ;
  {
    uint64_t* zgaz316;
    {
      int64_t zgaz317;
      zgaz317 = ((mach_int) zoffset);
      {
        RECREATE(sail_int)(&zghz318);
        CONVERT_OF(sail_int, mach_int)(&zghz318, zgaz317);
        zgaz316 = vector_access_zz5vecz8z6z8z5bv32z9z9(zXs, zghz318);
      }
    
    }
    (*(zgaz316)) = zv;
    zcbz37 = UNIT;
  
    goto finish_match_23;
  }
case_25: ;
  sail_match_failure("wX");
finish_match_23: ;

end_function_26: ;
  return zcbz37;
end_block_exception_27: ;

  return UNIT;
}



void finish_zwX(void)
{
  KILL(sail_int)(&zghz324);
  KILL(sail_int)(&zghz323);
  KILL(sail_int)(&zghz322);
  KILL(lbits)(&zghz321);
  KILL(lbits)(&zghz320);
  KILL(sail_int)(&zghz319);
  KILL(sail_int)(&zghz318);
}

fbits zxor_bit(fbits, fbits);

fbits zxor_bit(fbits zb1, fbits zb2)
{
  __label__ end_function_29, end_block_exception_30;

  fbits zcbz38;
  bool zgaz318;
  zgaz318 = (zb1 == zb2);
  if (zgaz318) {  zcbz38 = UINT64_C(0);  } else {  zcbz38 = UINT64_C(1);  }

end_function_29: ;
  return zcbz38;
end_block_exception_30: ;

  return UINT64_C(0);
}

void zxor_bitvector(lbits *rop, lbits, lbits);

sail_int zghz325;
lbits zghz326;
sail_int zghz327;
sail_int zghz328;
sail_int zghz329;
sail_int zghz330;
sail_int zghz331;

void startup_zxor_bitvector(void)
{
  CREATE(sail_int)(&zghz325);
  CREATE(lbits)(&zghz326);
  CREATE(sail_int)(&zghz327);
  CREATE(sail_int)(&zghz328);
  CREATE(sail_int)(&zghz329);
  CREATE(sail_int)(&zghz330);
  CREATE(sail_int)(&zghz331);
}

void zxor_bitvector(lbits *zcbz39, lbits zv1, lbits zv2)
{
  __label__ end_function_34, end_block_exception_35, end_function_117;

  RECREATE(sail_int)(&zghz325);
  length_lbits(&zghz325, zv2);
  RECREATE(lbits)(&zghz326);
  zeros(&zghz326, zghz325);
  {
    int64_t zgsz327;
    {    zgsz327 = INT64_C(0);
    }
    int64_t zgsz328;
    {
      {
        RECREATE(sail_int)(&zghz330);
        CONVERT_OF(sail_int, mach_int)(&zghz330, INT64_C(1));
        RECREATE(sail_int)(&zghz331);
        sub_int(&zghz331, zghz325, zghz330);
        zgsz328 = CONVERT_OF(mach_int, sail_int)(zghz331);
      }
    }
    int64_t zgsz329;
    {    zgsz329 = INT64_C(1);
    }
    {
      __label__ for_start_32, for_end_33;

      int64_t zi;
      zi = zgsz327;
      unit zgsz333;
    for_start_32: ;
      {
        if ((zi > zgsz328)) goto for_end_33;
        fbits zb1;
        {
          RECREATE(sail_int)(&zghz329);
          CONVERT_OF(sail_int, mach_int)(&zghz329, zi);
          zb1 = bitvector_access(zv1, zghz329);
        }
        fbits zb2;
        {
          RECREATE(sail_int)(&zghz328);
          CONVERT_OF(sail_int, mach_int)(&zghz328, zi);
          zb2 = bitvector_access(zv2, zghz328);
        }
        fbits zgaz319;
        zgaz319 = zxor_bit(zb1, zb2);
        {
          RECREATE(sail_int)(&zghz327);
          CONVERT_OF(sail_int, mach_int)(&zghz327, zi);
          update_lbits(&zghz326, zghz326, zghz327, zgaz319);
        }
        zgsz333 = UNIT;
      
      
      
        zi = (zi + zgsz329);
        goto for_start_32;
      }
    for_end_33: ;
    }
    unit zgsz336;
    zgsz336 = UNIT;
  }
  COPY(lbits)((*(&zcbz39)), zghz326);
end_function_34: ;
  goto end_function_117;
end_block_exception_35: ;
  goto end_function_117;
end_function_117: ;
}



void finish_zxor_bitvector(void)
{
  KILL(sail_int)(&zghz331);
  KILL(sail_int)(&zghz330);
  KILL(sail_int)(&zghz329);
  KILL(sail_int)(&zghz328);
  KILL(sail_int)(&zghz327);
  KILL(lbits)(&zghz326);
  KILL(sail_int)(&zghz325);
}

void ztwos_complement(lbits *rop, lbits);

lbits zghz332;
lbits zghz333;
sail_int zghz334;
lbits zghz335;

void startup_ztwos_complement(void)
{
  CREATE(lbits)(&zghz332);
  CREATE(lbits)(&zghz333);
  CREATE(sail_int)(&zghz334);
  CREATE(lbits)(&zghz335);
}

void ztwos_complement(lbits *zcbz310, lbits zv)
{
  __label__ end_function_37, end_block_exception_38, end_function_116;

  RECREATE(lbits)(&zghz332);
  not_bits(&zghz332, zv);
  {
    RECREATE(lbits)(&zghz333);
    {
      RECREATE(sail_int)(&zghz334);
      length_lbits(&zghz334, zv);
      {
        RECREATE(lbits)(&zghz335);
        CONVERT_OF(lbits, fbits)(&zghz335, UINT64_C(0b1), UINT64_C(1) , true);
        zextzz(&zghz333, zghz334, zghz335);
      }
    }
    add_bits(&zghz332, zghz332, zghz333);
    unit zgsz338;
    zgsz338 = UNIT;
  }
  COPY(lbits)((*(&zcbz310)), zghz332);
end_function_37: ;
  goto end_function_116;
end_block_exception_38: ;
  goto end_function_116;
end_function_116: ;
}



void finish_ztwos_complement(void)
{
  KILL(lbits)(&zghz335);
  KILL(sail_int)(&zghz334);
  KILL(lbits)(&zghz333);
  KILL(lbits)(&zghz332);
}

void zmul_bitvector(lbits *rop, lbits, lbits);

sail_int zghz336;
lbits zghz337;
lbits zghz338;
lbits zghz339;
sail_int zghz340;
lbits zghz341;
sail_int zghz342;
sail_int zghz343;
lbits zghz344;
lbits zghz345;
sail_int zghz346;
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

void startup_zmul_bitvector(void)
{
  CREATE(sail_int)(&zghz336);
  CREATE(lbits)(&zghz337);
  CREATE(lbits)(&zghz338);
  CREATE(lbits)(&zghz339);
  CREATE(sail_int)(&zghz340);
  CREATE(lbits)(&zghz341);
  CREATE(sail_int)(&zghz342);
  CREATE(sail_int)(&zghz343);
  CREATE(lbits)(&zghz344);
  CREATE(lbits)(&zghz345);
  CREATE(sail_int)(&zghz346);
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
}

void zmul_bitvector(lbits *zcbz311, lbits zmultiplicand, lbits zmultiplier)
{
  __label__ end_function_45, end_block_exception_46, end_function_115;

  RECREATE(sail_int)(&zghz336);
  length_lbits(&zghz336, zmultiplier);
  RECREATE(lbits)(&zghz337);
  {
    RECREATE(sail_int)(&zghz355);
    {
      RECREATE(sail_int)(&zghz356);
      CONVERT_OF(sail_int, mach_int)(&zghz356, INT64_C(2));
      mult_int(&zghz355, zghz356, zghz336);
    }
    sign_extend(&zghz337, zmultiplicand, zghz355);
  }
  RECREATE(lbits)(&zghz338);
  {
    RECREATE(sail_int)(&zghz353);
    {
      RECREATE(sail_int)(&zghz354);
      CONVERT_OF(sail_int, mach_int)(&zghz354, INT64_C(2));
      mult_int(&zghz353, zghz354, zghz336);
    }
    sign_extend(&zghz338, zmultiplier, zghz353);
  }
  RECREATE(lbits)(&zghz339);
  {
    RECREATE(sail_int)(&zghz351);
    {
      RECREATE(sail_int)(&zghz352);
      CONVERT_OF(sail_int, mach_int)(&zghz352, INT64_C(2));
      mult_int(&zghz351, zghz352, zghz336);
    }
    zeros(&zghz339, zghz351);
  }
  {
    int64_t zgsz342;
    {    zgsz342 = INT64_C(0);
    }
    int64_t zgsz343;
    {
      {
        RECREATE(sail_int)(&zghz349);
        CONVERT_OF(sail_int, mach_int)(&zghz349, INT64_C(1));
        RECREATE(sail_int)(&zghz350);
        sub_int(&zghz350, zghz336, zghz349);
        zgsz343 = CONVERT_OF(mach_int, sail_int)(zghz350);
      }
    }
    int64_t zgsz344;
    {    zgsz344 = INT64_C(1);
    }
    {
      __label__ for_start_40, for_end_41;

      int64_t zi;
      zi = zgsz342;
      unit zgsz346;
    for_start_40: ;
      {
        if ((zi > zgsz343)) goto for_end_41;
        bool zgaz323;
        {
          fbits zgaz322;
          {
            RECREATE(sail_int)(&zghz348);
            CONVERT_OF(sail_int, mach_int)(&zghz348, zi);
            zgaz322 = bitvector_access(zghz338, zghz348);
          }
          zgaz323 = eq_bit(zgaz322, UINT64_C(1));
        
        }
        if (zgaz323) {
        __label__ case_43, case_44, finish_match_42;

        RECREATE(sail_int)(&zghz340);
        {
          RECREATE(sail_int)(&zghz347);
          CONVERT_OF(sail_int, mach_int)(&zghz347, INT64_C(1));
          sub_int(&zghz340, zghz336, zghz347);
        }
        unit zgsz348;
        {
          RECREATE(sail_int)(&zghz343);
          CONVERT_OF(sail_int, mach_int)(&zghz343, zi);
          RECREATE(lbits)(&zghz344);
          {
            RECREATE(lbits)(&zghz345);
            {
              RECREATE(sail_int)(&zghz346);
              CONVERT_OF(sail_int, mach_int)(&zghz346, zi);
              shiftl(&zghz345, zghz337, zghz346);
            }
            ztwos_complement(&zghz344, zghz345);
          }
          add_bits(&zghz339, zghz339, zghz344);
          zgsz348 = UNIT;
          goto finish_match_42;
        }
      case_43: ;
        {
          RECREATE(lbits)(&zghz341);
          {
            RECREATE(sail_int)(&zghz342);
            CONVERT_OF(sail_int, mach_int)(&zghz342, zi);
            shiftl(&zghz341, zghz337, zghz342);
          }
          add_bits(&zghz339, zghz339, zghz341);
          zgsz348 = UNIT;
          goto finish_match_42;
        }
      case_44: ;
        sail_match_failure("mul_bitvector");
      finish_match_42: ;
        zgsz346 = zgsz348;
      
        } else {  zgsz346 = UNIT;  }
      
        zi = (zi + zgsz344);
        goto for_start_40;
      }
    for_end_41: ;
    }
    unit zgsz355;
    zgsz355 = UNIT;
  }
  COPY(lbits)((*(&zcbz311)), zghz339);
end_function_45: ;
  goto end_function_115;
end_block_exception_46: ;
  goto end_function_115;
end_function_115: ;
}



void finish_zmul_bitvector(void)
{
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
  KILL(sail_int)(&zghz346);
  KILL(lbits)(&zghz345);
  KILL(lbits)(&zghz344);
  KILL(sail_int)(&zghz343);
  KILL(sail_int)(&zghz342);
  KILL(lbits)(&zghz341);
  KILL(sail_int)(&zghz340);
  KILL(lbits)(&zghz339);
  KILL(lbits)(&zghz338);
  KILL(lbits)(&zghz337);
  KILL(sail_int)(&zghz336);
}






void zdecode(struct zoption *rop, uint64_t);






unit zexecute(struct zast);

sail_int zghz357;
sail_int zghz358;
sail_int zghz359;
lbits zghz360;
lbits zghz361;
lbits zghz362;
sail_int zghz363;
lbits zghz364;
lbits zghz365;
sail_int zghz366;
lbits zghz367;
lbits zghz368;
sail_int zghz369;
lbits zghz370;
lbits zghz371;
lbits zghz372;
lbits zghz373;
lbits zghz374;
sail_int zghz375;
lbits zghz376;
lbits zghz377;
sail_int zghz378;
lbits zghz379;
lbits zghz380;
sail_int zghz381;
lbits zghz382;
lbits zghz383;
sail_int zghz384;
lbits zghz385;
lbits zghz386;
sail_int zghz387;
lbits zghz388;
lbits zghz389;
sail_int zghz390;
lbits zghz391;
lbits zghz392;

void startup_zexecute(void)
{
  CREATE(sail_int)(&zghz357);
  CREATE(sail_int)(&zghz358);
  CREATE(sail_int)(&zghz359);
  CREATE(lbits)(&zghz360);
  CREATE(lbits)(&zghz361);
  CREATE(lbits)(&zghz362);
  CREATE(sail_int)(&zghz363);
  CREATE(lbits)(&zghz364);
  CREATE(lbits)(&zghz365);
  CREATE(sail_int)(&zghz366);
  CREATE(lbits)(&zghz367);
  CREATE(lbits)(&zghz368);
  CREATE(sail_int)(&zghz369);
  CREATE(lbits)(&zghz370);
  CREATE(lbits)(&zghz371);
  CREATE(lbits)(&zghz372);
  CREATE(lbits)(&zghz373);
  CREATE(lbits)(&zghz374);
  CREATE(sail_int)(&zghz375);
  CREATE(lbits)(&zghz376);
  CREATE(lbits)(&zghz377);
  CREATE(sail_int)(&zghz378);
  CREATE(lbits)(&zghz379);
  CREATE(lbits)(&zghz380);
  CREATE(sail_int)(&zghz381);
  CREATE(lbits)(&zghz382);
  CREATE(lbits)(&zghz383);
  CREATE(sail_int)(&zghz384);
  CREATE(lbits)(&zghz385);
  CREATE(lbits)(&zghz386);
  CREATE(sail_int)(&zghz387);
  CREATE(lbits)(&zghz388);
  CREATE(lbits)(&zghz389);
  CREATE(sail_int)(&zghz390);
  CREATE(lbits)(&zghz391);
  CREATE(lbits)(&zghz392);
}

unit zexecute(struct zast zmergez3var)
{
  __label__ case_49, case_50, case_54, case_58, case_62, case_63, case_64, case_65, case_66, case_67, case_68, case_69, case_70, case_71, case_72, case_73, case_74, case_75, case_76, case_77, finish_match_48, end_function_78, end_block_exception_79;

  unit zcbz312;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_49;
    uint64_t zrs2;
    zrs2 = zmergez3var.zRTYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zRTYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zRTYPE.ztup2;
    if ((zADD != zmergez3var.zRTYPE.ztup3)) goto case_49;
    uint64_t zrs1_val;
    zrs1_val = zrX(zrs1);
    uint64_t zrs2_val;
    zrs2_val = zrX(zrs2);
    uint64_t zresult;
    zresult = ((zrs1_val + zrs2_val) & UINT64_C(0xFFFFFFFF));
    zcbz312 = zwX(zrd, zresult);
  
  
  
  
  
  
    goto finish_match_48;
  }
case_49: ;
  {
    __label__ case_52, case_53, finish_match_51;

    if (zmergez3var.kind != Kind_zRTYPE) goto case_50;
    uint64_t zuz30;
    zuz30 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz31;
    zuz31 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz32;
    zuz32 = zmergez3var.zRTYPE.ztup2;
    if ((zAND != zmergez3var.zRTYPE.ztup3)) goto case_50;
    uint64_t zuz33;
    zuz33 = zrX(zuz31);
    uint64_t zuz34;
    zuz34 = zrX(zuz30);
    uint64_t zbitwise_AND;
    zbitwise_AND = (zuz33 & zuz34);
    {
      uint64_t zvz31;
      zvz31 = zbitwise_AND;
      uint64_t zgaz331;
      {
        RECREATE(sail_int)(&zghz390);
        CONVERT_OF(sail_int, mach_int)(&zghz390, INT64_C(32));
        RECREATE(lbits)(&zghz391);
        CONVERT_OF(lbits, fbits)(&zghz391, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz392);
        zextzz(&zghz392, zghz390, zghz391);
        zgaz331 = CONVERT_OF(fbits, lbits)(zghz392, true);
      }
      bool zgsz365;
      zgsz365 = (zvz31 == zgaz331);
    
      if (!(zgsz365)) {
    
      goto case_52;
      }
      uint64_t zgaz330;
      {
        RECREATE(sail_int)(&zghz387);
        CONVERT_OF(sail_int, mach_int)(&zghz387, INT64_C(32));
        RECREATE(lbits)(&zghz388);
        CONVERT_OF(lbits, fbits)(&zghz388, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz389);
        zextzz(&zghz389, zghz387, zghz388);
        zgaz330 = CONVERT_OF(fbits, lbits)(zghz389, true);
      }
      zcbz312 = zwX(zuz32, zgaz330);
    
    
      goto finish_match_51;
    }
  case_52: ;
    {
      uint64_t zgaz332;
      {
        RECREATE(sail_int)(&zghz384);
        CONVERT_OF(sail_int, mach_int)(&zghz384, INT64_C(32));
        RECREATE(lbits)(&zghz385);
        CONVERT_OF(lbits, fbits)(&zghz385, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz386);
        zextzz(&zghz386, zghz384, zghz385);
        zgaz332 = CONVERT_OF(fbits, lbits)(zghz386, true);
      }
      zcbz312 = zwX(zuz32, zgaz332);
    
      goto finish_match_51;
    }
  case_53: ;
    sail_match_failure("execute");
  finish_match_51: ;
  
  
  
  
  
  
    goto finish_match_48;
  }
case_50: ;
  {
    __label__ case_56, case_57, finish_match_55;

    if (zmergez3var.kind != Kind_zRTYPE) goto case_54;
    uint64_t zuz35;
    zuz35 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz36;
    zuz36 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz37;
    zuz37 = zmergez3var.zRTYPE.ztup2;
    if ((zOR != zmergez3var.zRTYPE.ztup3)) goto case_54;
    uint64_t zuz38;
    zuz38 = zrX(zuz36);
    uint64_t zuz39;
    zuz39 = zrX(zuz35);
    uint64_t zbitwise_OR;
    zbitwise_OR = (zuz38 | zuz39);
    {
      uint64_t zvz32;
      zvz32 = zbitwise_OR;
      uint64_t zgaz334;
      {
        RECREATE(sail_int)(&zghz381);
        CONVERT_OF(sail_int, mach_int)(&zghz381, INT64_C(32));
        RECREATE(lbits)(&zghz382);
        CONVERT_OF(lbits, fbits)(&zghz382, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz383);
        zextzz(&zghz383, zghz381, zghz382);
        zgaz334 = CONVERT_OF(fbits, lbits)(zghz383, true);
      }
      bool zgsz378;
      zgsz378 = (zvz32 == zgaz334);
    
      if (!(zgsz378)) {
    
      goto case_56;
      }
      uint64_t zgaz333;
      {
        RECREATE(sail_int)(&zghz378);
        CONVERT_OF(sail_int, mach_int)(&zghz378, INT64_C(32));
        RECREATE(lbits)(&zghz379);
        CONVERT_OF(lbits, fbits)(&zghz379, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz380);
        zextzz(&zghz380, zghz378, zghz379);
        zgaz333 = CONVERT_OF(fbits, lbits)(zghz380, true);
      }
      zcbz312 = zwX(zuz37, zgaz333);
    
    
      goto finish_match_55;
    }
  case_56: ;
    {
      uint64_t zgaz335;
      {
        RECREATE(sail_int)(&zghz375);
        CONVERT_OF(sail_int, mach_int)(&zghz375, INT64_C(32));
        RECREATE(lbits)(&zghz376);
        CONVERT_OF(lbits, fbits)(&zghz376, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz377);
        zextzz(&zghz377, zghz375, zghz376);
        zgaz335 = CONVERT_OF(fbits, lbits)(zghz377, true);
      }
      zcbz312 = zwX(zuz37, zgaz335);
    
      goto finish_match_55;
    }
  case_57: ;
    sail_match_failure("execute");
  finish_match_55: ;
  
  
  
  
  
  
    goto finish_match_48;
  }
case_54: ;
  {
    __label__ case_60, case_61, finish_match_59;

    if (zmergez3var.kind != Kind_zRTYPE) goto case_58;
    uint64_t zuz310;
    zuz310 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz311;
    zuz311 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz312;
    zuz312 = zmergez3var.zRTYPE.ztup2;
    if ((zXOR != zmergez3var.zRTYPE.ztup3)) goto case_58;
    uint64_t zuz313;
    zuz313 = zrX(zuz311);
    uint64_t zuz314;
    zuz314 = zrX(zuz310);
    uint64_t zbitwise_XOR;
    {
      RECREATE(lbits)(&zghz372);
      CONVERT_OF(lbits, fbits)(&zghz372, zuz313, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz373);
      CONVERT_OF(lbits, fbits)(&zghz373, zuz314, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz374);
      zxor_bitvector(&zghz374, zghz372, zghz373);
      zbitwise_XOR = CONVERT_OF(fbits, lbits)(zghz374, true);
    }
    {
      uint64_t zvz33;
      zvz33 = zbitwise_XOR;
      uint64_t zgaz337;
      {
        RECREATE(sail_int)(&zghz369);
        CONVERT_OF(sail_int, mach_int)(&zghz369, INT64_C(32));
        RECREATE(lbits)(&zghz370);
        CONVERT_OF(lbits, fbits)(&zghz370, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz371);
        zextzz(&zghz371, zghz369, zghz370);
        zgaz337 = CONVERT_OF(fbits, lbits)(zghz371, true);
      }
      bool zgsz394;
      zgsz394 = (zvz33 == zgaz337);
    
      if (!(zgsz394)) {
    
      goto case_60;
      }
      uint64_t zgaz336;
      {
        RECREATE(sail_int)(&zghz366);
        CONVERT_OF(sail_int, mach_int)(&zghz366, INT64_C(32));
        RECREATE(lbits)(&zghz367);
        CONVERT_OF(lbits, fbits)(&zghz367, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz368);
        zextzz(&zghz368, zghz366, zghz367);
        zgaz336 = CONVERT_OF(fbits, lbits)(zghz368, true);
      }
      zcbz312 = zwX(zuz312, zgaz336);
    
    
      goto finish_match_59;
    }
  case_60: ;
    {
      uint64_t zgaz338;
      {
        RECREATE(sail_int)(&zghz363);
        CONVERT_OF(sail_int, mach_int)(&zghz363, INT64_C(32));
        RECREATE(lbits)(&zghz364);
        CONVERT_OF(lbits, fbits)(&zghz364, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz365);
        zextzz(&zghz365, zghz363, zghz364);
        zgaz338 = CONVERT_OF(fbits, lbits)(zghz365, true);
      }
      zcbz312 = zwX(zuz312, zgaz338);
    
      goto finish_match_59;
    }
  case_61: ;
    sail_match_failure("execute");
  finish_match_59: ;
  
  
  
  
  
  
    goto finish_match_48;
  }
case_58: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_62;
    uint64_t zuz315;
    zuz315 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz316;
    zuz316 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz317;
    zuz317 = zmergez3var.zRTYPE.ztup2;
    if ((zMUL != zmergez3var.zRTYPE.ztup3)) goto case_62;
    uint64_t zmultiplicand;
    zmultiplicand = zrX(zuz316);
    uint64_t zmultiplier;
    zmultiplier = zrX(zuz315);
    uint64_t zproduct;
    {
      RECREATE(lbits)(&zghz360);
      CONVERT_OF(lbits, fbits)(&zghz360, zmultiplicand, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz361);
      CONVERT_OF(lbits, fbits)(&zghz361, zmultiplier, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz362);
      zmul_bitvector(&zghz362, zghz360, zghz361);
      zproduct = CONVERT_OF(fbits, lbits)(zghz362, true);
    }
    int64_t zlen;
    {
      RECREATE(sail_int)(&zghz357);
      CONVERT_OF(sail_int, mach_int)(&zghz357, INT64_C(32));
      RECREATE(sail_int)(&zghz358);
      CONVERT_OF(sail_int, mach_int)(&zghz358, INT64_C(1));
      RECREATE(sail_int)(&zghz359);
      sub_int(&zghz359, zghz357, zghz358);
      zlen = CONVERT_OF(mach_int, sail_int)(zghz359);
    }
    uint64_t zuz318;
    zuz318 = (safe_rshift(UINT64_MAX, 64 - 32) & (zproduct >> INT64_C(0)));
    zcbz312 = zwX(zuz317, zuz318);
  
  
  
  
  
  
  
  
    goto finish_match_48;
  }
case_62: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_63;
    uint64_t zuz319;
    zuz319 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz320;
    zuz320 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz321;
    zuz321 = zmergez3var.zRTYPE.ztup2;
    if ((zDIV != zmergez3var.zRTYPE.ztup3)) goto case_63;
    zcbz312 = print_endline("execute DIV\n");
  
  
  
    goto finish_match_48;
  }
case_63: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_64;
    uint64_t zuz322;
    zuz322 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz323;
    zuz323 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz324;
    zuz324 = zmergez3var.zRTYPE.ztup2;
    if ((zREM != zmergez3var.zRTYPE.ztup3)) goto case_64;
    zcbz312 = print_endline("execute REM\n");
  
  
  
    goto finish_match_48;
  }
case_64: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_65;
    uint64_t zimm;
    zimm = zmergez3var.zITYPE.ztup0;
    uint64_t zuz325;
    zuz325 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz326;
    zuz326 = zmergez3var.zITYPE.ztup2;
    if ((zADDI != zmergez3var.zITYPE.ztup3)) goto case_65;
    zcbz312 = print_endline("execute ADDI\n");
  
  
  
    goto finish_match_48;
  }
case_65: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_66;
    uint64_t zuz327;
    zuz327 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz328;
    zuz328 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz329;
    zuz329 = zmergez3var.zITYPE.ztup2;
    if ((zSLTI != zmergez3var.zITYPE.ztup3)) goto case_66;
    zcbz312 = print_endline("execute SLTI\n");
  
  
  
    goto finish_match_48;
  }
case_66: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_67;
    uint64_t zuz330;
    zuz330 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz331;
    zuz331 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz332;
    zuz332 = zmergez3var.zITYPE.ztup2;
    if ((zANDI != zmergez3var.zITYPE.ztup3)) goto case_67;
    zcbz312 = print_endline("execute ANDI\n");
  
  
  
    goto finish_match_48;
  }
case_67: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_68;
    uint64_t zuz333;
    zuz333 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz334;
    zuz334 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz335;
    zuz335 = zmergez3var.zITYPE.ztup2;
    if ((zORI != zmergez3var.zITYPE.ztup3)) goto case_68;
    zcbz312 = print_endline("execute ORI\n");
  
  
  
    goto finish_match_48;
  }
case_68: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_69;
    uint64_t zuz336;
    zuz336 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz337;
    zuz337 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz338;
    zuz338 = zmergez3var.zITYPE.ztup2;
    if ((zXORI != zmergez3var.zITYPE.ztup3)) goto case_69;
    zcbz312 = print_endline("execute XORI\n");
  
  
  
    goto finish_match_48;
  }
case_69: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_70;
    uint64_t zuz339;
    zuz339 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz340;
    zuz340 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz341;
    zuz341 = zmergez3var.zITYPE.ztup2;
    if ((zJALR != zmergez3var.zITYPE.ztup3)) goto case_70;
    zcbz312 = print_endline("execute JALR\n");
  
  
  
    goto finish_match_48;
  }
case_70: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_71;
    uint64_t zuz342;
    zuz342 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz343;
    zuz343 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz344;
    zuz344 = zmergez3var.zITYPE.ztup2;
    if ((zLW != zmergez3var.zITYPE.ztup3)) goto case_71;
    zcbz312 = print_endline("execute LW\n");
  
  
  
    goto finish_match_48;
  }
case_71: ;
  {
    if (zmergez3var.kind != Kind_zSTYPE) goto case_72;
    uint64_t zimm2;
    zimm2 = zmergez3var.zSTYPE.ztup0;
    uint64_t zuz345;
    zuz345 = zmergez3var.zSTYPE.ztup1;
    uint64_t zuz346;
    zuz346 = zmergez3var.zSTYPE.ztup2;
    uint64_t zimm1;
    zimm1 = zmergez3var.zSTYPE.ztup3;
    if ((zSW != zmergez3var.zSTYPE.ztup4)) goto case_72;
    zcbz312 = print_endline("execute SW\n");
  
  
  
  
    goto finish_match_48;
  }
case_72: ;
  {
    if (zmergez3var.kind != Kind_zBTYPE) goto case_73;
    uint64_t zimm4;
    zimm4 = zmergez3var.zBTYPE.ztup0;
    uint64_t zuz347;
    zuz347 = zmergez3var.zBTYPE.ztup1;
    uint64_t zuz348;
    zuz348 = zmergez3var.zBTYPE.ztup2;
    uint64_t zuz349;
    zuz349 = zmergez3var.zBTYPE.ztup3;
    uint64_t zuz350;
    zuz350 = zmergez3var.zBTYPE.ztup4;
    uint64_t zimm3;
    zimm3 = zmergez3var.zBTYPE.ztup5;
    if ((zBEQ != zmergez3var.zBTYPE.ztup6)) goto case_73;
    zcbz312 = print_endline("execute BEQ\n");
  
  
  
  
  
  
    goto finish_match_48;
  }
case_73: ;
  {
    if (zmergez3var.kind != Kind_zBTYPE) goto case_74;
    uint64_t zuz351;
    zuz351 = zmergez3var.zBTYPE.ztup0;
    uint64_t zuz352;
    zuz352 = zmergez3var.zBTYPE.ztup1;
    uint64_t zuz353;
    zuz353 = zmergez3var.zBTYPE.ztup2;
    uint64_t zuz354;
    zuz354 = zmergez3var.zBTYPE.ztup3;
    uint64_t zuz355;
    zuz355 = zmergez3var.zBTYPE.ztup4;
    uint64_t zuz356;
    zuz356 = zmergez3var.zBTYPE.ztup5;
    if ((zBNE != zmergez3var.zBTYPE.ztup6)) goto case_74;
    zcbz312 = print_endline("execute BNE\n");
  
  
  
  
  
  
    goto finish_match_48;
  }
case_74: ;
  {
    if (zmergez3var.kind != Kind_zUTYPE) goto case_75;
    uint64_t zuz357;
    zuz357 = zmergez3var.zUTYPE.ztup0;
    uint64_t zuz358;
    zuz358 = zmergez3var.zUTYPE.ztup1;
    if ((zLUI != zmergez3var.zUTYPE.ztup2)) goto case_75;
    zcbz312 = print_endline("execute LUI\n");
  
  
    goto finish_match_48;
  }
case_75: ;
  {
    if (zmergez3var.kind != Kind_zUTYPE) goto case_76;
    uint64_t zuz359;
    zuz359 = zmergez3var.zUTYPE.ztup0;
    uint64_t zuz360;
    zuz360 = zmergez3var.zUTYPE.ztup1;
    if ((zAUIPC != zmergez3var.zUTYPE.ztup2)) goto case_76;
    zcbz312 = print_endline("execute AUIPC\n");
  
  
    goto finish_match_48;
  }
case_76: ;
  {
    if (zmergez3var.kind != Kind_zJTYPE) goto case_77;
    uint64_t zuz361;
    zuz361 = zmergez3var.zJTYPE.ztup0;
    uint64_t zuz362;
    zuz362 = zmergez3var.zJTYPE.ztup1;
    uint64_t zuz363;
    zuz363 = zmergez3var.zJTYPE.ztup2;
    uint64_t zuz364;
    zuz364 = zmergez3var.zJTYPE.ztup3;
    uint64_t zuz365;
    zuz365 = zmergez3var.zJTYPE.ztup4;
    if ((zJAL != zmergez3var.zJTYPE.ztup5)) goto case_77;
    zcbz312 = print_endline("execute JAL\n");
  
  
  
  
  
    goto finish_match_48;
  }
case_77: ;
  sail_match_failure("execute");
finish_match_48: ;
end_function_78: ;
  return zcbz312;
end_block_exception_79: ;

  return UNIT;
}



void finish_zexecute(void)
{
  KILL(lbits)(&zghz392);
  KILL(lbits)(&zghz391);
  KILL(sail_int)(&zghz390);
  KILL(lbits)(&zghz389);
  KILL(lbits)(&zghz388);
  KILL(sail_int)(&zghz387);
  KILL(lbits)(&zghz386);
  KILL(lbits)(&zghz385);
  KILL(sail_int)(&zghz384);
  KILL(lbits)(&zghz383);
  KILL(lbits)(&zghz382);
  KILL(sail_int)(&zghz381);
  KILL(lbits)(&zghz380);
  KILL(lbits)(&zghz379);
  KILL(sail_int)(&zghz378);
  KILL(lbits)(&zghz377);
  KILL(lbits)(&zghz376);
  KILL(sail_int)(&zghz375);
  KILL(lbits)(&zghz374);
  KILL(lbits)(&zghz373);
  KILL(lbits)(&zghz372);
  KILL(lbits)(&zghz371);
  KILL(lbits)(&zghz370);
  KILL(sail_int)(&zghz369);
  KILL(lbits)(&zghz368);
  KILL(lbits)(&zghz367);
  KILL(sail_int)(&zghz366);
  KILL(lbits)(&zghz365);
  KILL(lbits)(&zghz364);
  KILL(sail_int)(&zghz363);
  KILL(lbits)(&zghz362);
  KILL(lbits)(&zghz361);
  KILL(lbits)(&zghz360);
  KILL(sail_int)(&zghz359);
  KILL(sail_int)(&zghz358);
  KILL(sail_int)(&zghz357);
}


















void zdecode(struct zoption *zcbz313, uint64_t zmergez3var)
{
  __label__ case_82, case_83, case_84, case_85, case_86, case_87, case_88, case_89, case_90, case_91, case_92, case_93, case_94, case_95, case_96, case_97, case_98, case_99, case_100, case_101, case_102, finish_match_81, end_function_103, end_block_exception_104, end_function_114;

  struct zoption zgsz3122;
  CREATE(zoption)(&zgsz3122);
  {
    uint64_t zv__0;
    zv__0 = zmergez3var;
    bool zgaz342;
    {
      uint64_t zgaz340;
      zgaz340 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__0 >> INT64_C(25)));
      zgaz342 = (zgaz340 == UINT64_C(0b0000000));
    
    }
    bool zgsz3123;
    if (zgaz342) {
    uint64_t zgaz341;
    zgaz341 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__0 >> INT64_C(0)));
    zgsz3123 = (zgaz341 == UINT64_C(0b0110011));
  
    } else {  zgsz3123 = false;  }
    bool zgsz3125;
    zgsz3125 = zgsz3123;
  
    if (!(zgsz3125)) {
  
    goto case_82;
    }
    uint64_t zrs2;
    zrs2 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(20)));
    uint64_t zrs1;
    zrs1 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(15)));
    uint64_t zrd;
    zrd = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(7)));
    struct zast zgaz339;
    CREATE(zast)(&zgaz339);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3124;
      zgsz3124.ztup0 = zrs2;
      zgsz3124.ztup1 = zrs1;
      zgsz3124.ztup2 = zrd;
      zgsz3124.ztup3 = zADD;
      zRTYPE(&zgaz339, zgsz3124);
    
    }
    {
      struct zast zgsz3221;
      CREATE(zast)(&zgsz3221);
      COPY(zast)(&zgsz3221, zgaz339);
      zSomez3z5unionz0zzast(&zgsz3122, zgsz3221);
      KILL(zast)(&zgsz3221);
    }
    KILL(zast)(&zgaz339);
  
  
  
  
    goto finish_match_81;
  }
case_82: ;
  {
    uint64_t zv__3;
    zv__3 = zmergez3var;
    bool zgaz346;
    {
      uint64_t zgaz344;
      zgaz344 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__3 >> INT64_C(25)));
      zgaz346 = (zgaz344 == UINT64_C(0b0000000));
    
    }
    bool zgsz3126;
    if (zgaz346) {
    uint64_t zgaz345;
    zgaz345 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__3 >> INT64_C(0)));
    zgsz3126 = (zgaz345 == UINT64_C(0b0110011));
  
    } else {  zgsz3126 = false;  }
    bool zgsz3128;
    zgsz3128 = zgsz3126;
  
    if (!(zgsz3128)) {
  
    goto case_83;
    }
    uint64_t zuz366;
    zuz366 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(20)));
    uint64_t zuz367;
    zuz367 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(15)));
    uint64_t zuz368;
    zuz368 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(7)));
    struct zast zgaz343;
    CREATE(zast)(&zgaz343);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3127;
      zgsz3127.ztup0 = zuz366;
      zgsz3127.ztup1 = zuz367;
      zgsz3127.ztup2 = zuz368;
      zgsz3127.ztup3 = zAND;
      zRTYPE(&zgaz343, zgsz3127);
    
    }
    {
      struct zast zgsz3222;
      CREATE(zast)(&zgsz3222);
      COPY(zast)(&zgsz3222, zgaz343);
      zSomez3z5unionz0zzast(&zgsz3122, zgsz3222);
      KILL(zast)(&zgsz3222);
    }
    KILL(zast)(&zgaz343);
  
  
  
  
    goto finish_match_81;
  }
case_83: ;
  {
    uint64_t zv__6;
    zv__6 = zmergez3var;
    bool zgaz350;
    {
      uint64_t zgaz348;
      zgaz348 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__6 >> INT64_C(25)));
      zgaz350 = (zgaz348 == UINT64_C(0b0000000));
    
    }
    bool zgsz3129;
    if (zgaz350) {
    uint64_t zgaz349;
    zgaz349 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__6 >> INT64_C(0)));
    zgsz3129 = (zgaz349 == UINT64_C(0b0110011));
  
    } else {  zgsz3129 = false;  }
    bool zgsz3131;
    zgsz3131 = zgsz3129;
  
    if (!(zgsz3131)) {
  
    goto case_84;
    }
    uint64_t zuz369;
    zuz369 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(20)));
    uint64_t zuz370;
    zuz370 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(15)));
    uint64_t zuz371;
    zuz371 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(7)));
    struct zast zgaz347;
    CREATE(zast)(&zgaz347);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3130;
      zgsz3130.ztup0 = zuz369;
      zgsz3130.ztup1 = zuz370;
      zgsz3130.ztup2 = zuz371;
      zgsz3130.ztup3 = zOR;
      zRTYPE(&zgaz347, zgsz3130);
    
    }
    {
      struct zast zgsz3223;
      CREATE(zast)(&zgsz3223);
      COPY(zast)(&zgsz3223, zgaz347);
      zSomez3z5unionz0zzast(&zgsz3122, zgsz3223);
      KILL(zast)(&zgsz3223);
    }
    KILL(zast)(&zgaz347);
  
  
  
  
    goto finish_match_81;
  }
case_84: ;
  {
    uint64_t zv__9;
    zv__9 = zmergez3var;
    bool zgaz354;
    {
      uint64_t zgaz352;
      zgaz352 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__9 >> INT64_C(25)));
      zgaz354 = (zgaz352 == UINT64_C(0b0000000));
    
    }
    bool zgsz3132;
    if (zgaz354) {
    uint64_t zgaz353;
    zgaz353 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__9 >> INT64_C(0)));
    zgsz3132 = (zgaz353 == UINT64_C(0b0110011));
  
    } else {  zgsz3132 = false;  }
    bool zgsz3134;
    zgsz3134 = zgsz3132;
  
    if (!(zgsz3134)) {
  
    goto case_85;
    }
    uint64_t zuz372;
    zuz372 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(20)));
    uint64_t zuz373;
    zuz373 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(15)));
    uint64_t zuz374;
    zuz374 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(7)));
    struct zast zgaz351;
    CREATE(zast)(&zgaz351);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3133;
      zgsz3133.ztup0 = zuz372;
      zgsz3133.ztup1 = zuz373;
      zgsz3133.ztup2 = zuz374;
      zgsz3133.ztup3 = zXOR;
      zRTYPE(&zgaz351, zgsz3133);
    
    }
    {
      struct zast zgsz3224;
      CREATE(zast)(&zgsz3224);
      COPY(zast)(&zgsz3224, zgaz351);
      zSomez3z5unionz0zzast(&zgsz3122, zgsz3224);
      KILL(zast)(&zgsz3224);
    }
    KILL(zast)(&zgaz351);
  
  
  
  
    goto finish_match_81;
  }
case_85: ;
  {
    uint64_t zv__12;
    zv__12 = zmergez3var;
    bool zgaz358;
    {
      uint64_t zgaz356;
      zgaz356 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__12 >> INT64_C(25)));
      zgaz358 = (zgaz356 == UINT64_C(0b0000001));
    
    }
    bool zgsz3135;
    if (zgaz358) {
    uint64_t zgaz357;
    zgaz357 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__12 >> INT64_C(0)));
    zgsz3135 = (zgaz357 == UINT64_C(0b0110011));
  
    } else {  zgsz3135 = false;  }
    bool zgsz3137;
    zgsz3137 = zgsz3135;
  
    if (!(zgsz3137)) {
  
    goto case_86;
    }
    uint64_t zuz375;
    zuz375 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(20)));
    uint64_t zuz376;
    zuz376 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(15)));
    uint64_t zuz377;
    zuz377 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(7)));
    struct zast zgaz355;
    CREATE(zast)(&zgaz355);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3136;
      zgsz3136.ztup0 = zuz375;
      zgsz3136.ztup1 = zuz376;
      zgsz3136.ztup2 = zuz377;
      zgsz3136.ztup3 = zMUL;
      zRTYPE(&zgaz355, zgsz3136);
    
    }
    {
      struct zast zgsz3225;
      CREATE(zast)(&zgsz3225);
      COPY(zast)(&zgsz3225, zgaz355);
      zSomez3z5unionz0zzast(&zgsz3122, zgsz3225);
      KILL(zast)(&zgsz3225);
    }
    KILL(zast)(&zgaz355);
  
  
  
  
    goto finish_match_81;
  }
case_86: ;
  {
    uint64_t zv__15;
    zv__15 = zmergez3var;
    bool zgaz362;
    {
      uint64_t zgaz360;
      zgaz360 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__15 >> INT64_C(25)));
      zgaz362 = (zgaz360 == UINT64_C(0b0000001));
    
    }
    bool zgsz3138;
    if (zgaz362) {
    uint64_t zgaz361;
    zgaz361 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__15 >> INT64_C(0)));
    zgsz3138 = (zgaz361 == UINT64_C(0b0110011));
  
    } else {  zgsz3138 = false;  }
    bool zgsz3140;
    zgsz3140 = zgsz3138;
  
    if (!(zgsz3140)) {
  
    goto case_87;
    }
    uint64_t zuz378;
    zuz378 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(20)));
    uint64_t zuz379;
    zuz379 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(15)));
    uint64_t zuz380;
    zuz380 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(7)));
    struct zast zgaz359;
    CREATE(zast)(&zgaz359);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3139;
      zgsz3139.ztup0 = zuz378;
      zgsz3139.ztup1 = zuz379;
      zgsz3139.ztup2 = zuz380;
      zgsz3139.ztup3 = zDIV;
      zRTYPE(&zgaz359, zgsz3139);
    
    }
    {
      struct zast zgsz3226;
      CREATE(zast)(&zgsz3226);
      COPY(zast)(&zgsz3226, zgaz359);
      zSomez3z5unionz0zzast(&zgsz3122, zgsz3226);
      KILL(zast)(&zgsz3226);
    }
    KILL(zast)(&zgaz359);
  
  
  
  
    goto finish_match_81;
  }
case_87: ;
  {
    uint64_t zv__18;
    zv__18 = zmergez3var;
    bool zgaz366;
    {
      uint64_t zgaz364;
      zgaz364 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__18 >> INT64_C(25)));
      zgaz366 = (zgaz364 == UINT64_C(0b0000001));
    
    }
    bool zgsz3141;
    if (zgaz366) {
    uint64_t zgaz365;
    zgaz365 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__18 >> INT64_C(0)));
    zgsz3141 = (zgaz365 == UINT64_C(0b0110011));
  
    } else {  zgsz3141 = false;  }
    bool zgsz3143;
    zgsz3143 = zgsz3141;
  
    if (!(zgsz3143)) {
  
    goto case_88;
    }
    uint64_t zuz381;
    zuz381 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(20)));
    uint64_t zuz382;
    zuz382 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(15)));
    uint64_t zuz383;
    zuz383 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(7)));
    struct zast zgaz363;
    CREATE(zast)(&zgaz363);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3142;
      zgsz3142.ztup0 = zuz381;
      zgsz3142.ztup1 = zuz382;
      zgsz3142.ztup2 = zuz383;
      zgsz3142.ztup3 = zREM;
      zRTYPE(&zgaz363, zgsz3142);
    
    }
    {
      struct zast zgsz3227;
      CREATE(zast)(&zgsz3227);
      COPY(zast)(&zgsz3227, zgaz363);
      zSomez3z5unionz0zzast(&zgsz3122, zgsz3227);
      KILL(zast)(&zgsz3227);
    }
    KILL(zast)(&zgaz363);
  
  
  
  
    goto finish_match_81;
  }
case_88: ;
  {
    uint64_t zv__21;
    zv__21 = zmergez3var;
    uint64_t zgaz368;
    zgaz368 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__21 >> INT64_C(0)));
    bool zgsz3145;
    zgsz3145 = (zgaz368 == UINT64_C(0b0010011));
  
    if (!(zgsz3145)) {
  
    goto case_89;
    }
    uint64_t zimm;
    zimm = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__21 >> INT64_C(20)));
    uint64_t zuz384;
    zuz384 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__21 >> INT64_C(15)));
    uint64_t zuz385;
    zuz385 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__21 >> INT64_C(7)));
    uint64_t zimmshadowz31;
    zimmshadowz31 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__21 >> INT64_C(20)));
    struct zast zgaz367;
    CREATE(zast)(&zgaz367);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3144;
      zgsz3144.ztup0 = zimmshadowz31;
      zgsz3144.ztup1 = zuz384;
      zgsz3144.ztup2 = zuz385;
      zgsz3144.ztup3 = zADDI;
      zITYPE(&zgaz367, zgsz3144);
    
    }
    {
      struct zast zgsz3228;
      CREATE(zast)(&zgsz3228);
      COPY(zast)(&zgsz3228, zgaz367);
      zSomez3z5unionz0zzast(&zgsz3122, zgsz3228);
      KILL(zast)(&zgsz3228);
    }
    KILL(zast)(&zgaz367);
  
  
  
  
  
    goto finish_match_81;
  }
case_89: ;
  {
    uint64_t zv__23;
    zv__23 = zmergez3var;
    uint64_t zgaz370;
    zgaz370 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__23 >> INT64_C(0)));
    bool zgsz3147;
    zgsz3147 = (zgaz370 == UINT64_C(0b0010011));
  
    if (!(zgsz3147)) {
  
    goto case_90;
    }
    uint64_t zuz386;
    zuz386 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__23 >> INT64_C(20)));
    uint64_t zuz387;
    zuz387 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__23 >> INT64_C(15)));
    uint64_t zuz388;
    zuz388 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__23 >> INT64_C(7)));
    uint64_t zimmshadowz32;
    zimmshadowz32 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__23 >> INT64_C(20)));
    struct zast zgaz369;
    CREATE(zast)(&zgaz369);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3146;
      zgsz3146.ztup0 = zimmshadowz32;
      zgsz3146.ztup1 = zuz387;
      zgsz3146.ztup2 = zuz388;
      zgsz3146.ztup3 = zSLTI;
      zITYPE(&zgaz369, zgsz3146);
    
    }
    {
      struct zast zgsz3229;
      CREATE(zast)(&zgsz3229);
      COPY(zast)(&zgsz3229, zgaz369);
      zSomez3z5unionz0zzast(&zgsz3122, zgsz3229);
      KILL(zast)(&zgsz3229);
    }
    KILL(zast)(&zgaz369);
  
  
  
  
  
    goto finish_match_81;
  }
case_90: ;
  {
    uint64_t zv__25;
    zv__25 = zmergez3var;
    uint64_t zgaz372;
    zgaz372 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__25 >> INT64_C(0)));
    bool zgsz3149;
    zgsz3149 = (zgaz372 == UINT64_C(0b0010011));
  
    if (!(zgsz3149)) {
  
    goto case_91;
    }
    uint64_t zuz389;
    zuz389 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__25 >> INT64_C(20)));
    uint64_t zuz390;
    zuz390 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__25 >> INT64_C(15)));
    uint64_t zuz391;
    zuz391 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__25 >> INT64_C(7)));
    uint64_t zimmshadowz33;
    zimmshadowz33 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__25 >> INT64_C(20)));
    struct zast zgaz371;
    CREATE(zast)(&zgaz371);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3148;
      zgsz3148.ztup0 = zimmshadowz33;
      zgsz3148.ztup1 = zuz390;
      zgsz3148.ztup2 = zuz391;
      zgsz3148.ztup3 = zANDI;
      zITYPE(&zgaz371, zgsz3148);
    
    }
    {
      struct zast zgsz3230;
      CREATE(zast)(&zgsz3230);
      COPY(zast)(&zgsz3230, zgaz371);
      zSomez3z5unionz0zzast(&zgsz3122, zgsz3230);
      KILL(zast)(&zgsz3230);
    }
    KILL(zast)(&zgaz371);
  
  
  
  
  
    goto finish_match_81;
  }
case_91: ;
  {
    uint64_t zv__27;
    zv__27 = zmergez3var;
    uint64_t zgaz374;
    zgaz374 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__27 >> INT64_C(0)));
    bool zgsz3151;
    zgsz3151 = (zgaz374 == UINT64_C(0b0010011));
  
    if (!(zgsz3151)) {
  
    goto case_92;
    }
    uint64_t zuz392;
    zuz392 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__27 >> INT64_C(20)));
    uint64_t zuz393;
    zuz393 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__27 >> INT64_C(15)));
    uint64_t zuz394;
    zuz394 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__27 >> INT64_C(7)));
    uint64_t zimmshadowz34;
    zimmshadowz34 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__27 >> INT64_C(20)));
    struct zast zgaz373;
    CREATE(zast)(&zgaz373);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3150;
      zgsz3150.ztup0 = zimmshadowz34;
      zgsz3150.ztup1 = zuz393;
      zgsz3150.ztup2 = zuz394;
      zgsz3150.ztup3 = zORI;
      zITYPE(&zgaz373, zgsz3150);
    
    }
    {
      struct zast zgsz3231;
      CREATE(zast)(&zgsz3231);
      COPY(zast)(&zgsz3231, zgaz373);
      zSomez3z5unionz0zzast(&zgsz3122, zgsz3231);
      KILL(zast)(&zgsz3231);
    }
    KILL(zast)(&zgaz373);
  
  
  
  
  
    goto finish_match_81;
  }
case_92: ;
  {
    uint64_t zv__29;
    zv__29 = zmergez3var;
    uint64_t zgaz376;
    zgaz376 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__29 >> INT64_C(0)));
    bool zgsz3153;
    zgsz3153 = (zgaz376 == UINT64_C(0b0010011));
  
    if (!(zgsz3153)) {
  
    goto case_93;
    }
    uint64_t zuz395;
    zuz395 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__29 >> INT64_C(20)));
    uint64_t zuz396;
    zuz396 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__29 >> INT64_C(15)));
    uint64_t zuz397;
    zuz397 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__29 >> INT64_C(7)));
    uint64_t zimmshadowz35;
    zimmshadowz35 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__29 >> INT64_C(20)));
    struct zast zgaz375;
    CREATE(zast)(&zgaz375);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3152;
      zgsz3152.ztup0 = zimmshadowz35;
      zgsz3152.ztup1 = zuz396;
      zgsz3152.ztup2 = zuz397;
      zgsz3152.ztup3 = zXORI;
      zITYPE(&zgaz375, zgsz3152);
    
    }
    {
      struct zast zgsz3232;
      CREATE(zast)(&zgsz3232);
      COPY(zast)(&zgsz3232, zgaz375);
      zSomez3z5unionz0zzast(&zgsz3122, zgsz3232);
      KILL(zast)(&zgsz3232);
    }
    KILL(zast)(&zgaz375);
  
  
  
  
  
    goto finish_match_81;
  }
case_93: ;
  {
    uint64_t zv__31;
    zv__31 = zmergez3var;
    uint64_t zgaz378;
    zgaz378 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__31 >> INT64_C(0)));
    bool zgsz3155;
    zgsz3155 = (zgaz378 == UINT64_C(0b1100111));
  
    if (!(zgsz3155)) {
  
    goto case_94;
    }
    uint64_t zuz398;
    zuz398 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__31 >> INT64_C(20)));
    uint64_t zuz399;
    zuz399 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__31 >> INT64_C(15)));
    uint64_t zuz3100;
    zuz3100 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__31 >> INT64_C(7)));
    uint64_t zimmshadowz36;
    zimmshadowz36 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__31 >> INT64_C(20)));
    struct zast zgaz377;
    CREATE(zast)(&zgaz377);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3154;
      zgsz3154.ztup0 = zimmshadowz36;
      zgsz3154.ztup1 = zuz399;
      zgsz3154.ztup2 = zuz3100;
      zgsz3154.ztup3 = zJALR;
      zITYPE(&zgaz377, zgsz3154);
    
    }
    {
      struct zast zgsz3233;
      CREATE(zast)(&zgsz3233);
      COPY(zast)(&zgsz3233, zgaz377);
      zSomez3z5unionz0zzast(&zgsz3122, zgsz3233);
      KILL(zast)(&zgsz3233);
    }
    KILL(zast)(&zgaz377);
  
  
  
  
  
    goto finish_match_81;
  }
case_94: ;
  {
    uint64_t zv__33;
    zv__33 = zmergez3var;
    uint64_t zgaz380;
    zgaz380 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__33 >> INT64_C(0)));
    bool zgsz3157;
    zgsz3157 = (zgaz380 == UINT64_C(0b0000011));
  
    if (!(zgsz3157)) {
  
    goto case_95;
    }
    uint64_t zuz3101;
    zuz3101 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__33 >> INT64_C(20)));
    uint64_t zuz3102;
    zuz3102 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__33 >> INT64_C(15)));
    uint64_t zuz3103;
    zuz3103 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__33 >> INT64_C(7)));
    uint64_t zimmshadowz37;
    zimmshadowz37 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__33 >> INT64_C(20)));
    struct zast zgaz379;
    CREATE(zast)(&zgaz379);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3156;
      zgsz3156.ztup0 = zimmshadowz37;
      zgsz3156.ztup1 = zuz3102;
      zgsz3156.ztup2 = zuz3103;
      zgsz3156.ztup3 = zLW;
      zITYPE(&zgaz379, zgsz3156);
    
    }
    {
      struct zast zgsz3234;
      CREATE(zast)(&zgsz3234);
      COPY(zast)(&zgsz3234, zgaz379);
      zSomez3z5unionz0zzast(&zgsz3122, zgsz3234);
      KILL(zast)(&zgsz3234);
    }
    KILL(zast)(&zgaz379);
  
  
  
  
  
    goto finish_match_81;
  }
case_95: ;
  {
    uint64_t zv__35;
    zv__35 = zmergez3var;
    uint64_t zgaz382;
    zgaz382 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__35 >> INT64_C(0)));
    bool zgsz3159;
    zgsz3159 = (zgaz382 == UINT64_C(0b0100011));
  
    if (!(zgsz3159)) {
  
    goto case_96;
    }
    uint64_t zimm2;
    zimm2 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__35 >> INT64_C(25)));
    uint64_t zuz3104;
    zuz3104 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__35 >> INT64_C(20)));
    uint64_t zuz3105;
    zuz3105 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__35 >> INT64_C(15)));
    uint64_t zimm2shadowz38;
    zimm2shadowz38 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__35 >> INT64_C(25)));
    uint64_t zimm1;
    zimm1 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__35 >> INT64_C(7)));
    struct zast zgaz381;
    CREATE(zast)(&zgaz381);
    {
      struct ztuple_z8z5bv7zCz0z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzsopz9 zgsz3158;
      zgsz3158.ztup0 = zimm2shadowz38;
      zgsz3158.ztup1 = zuz3104;
      zgsz3158.ztup2 = zuz3105;
      zgsz3158.ztup3 = zimm1;
      zgsz3158.ztup4 = zSW;
      zSTYPE(&zgaz381, zgsz3158);
    
    }
    {
      struct zast zgsz3235;
      CREATE(zast)(&zgsz3235);
      COPY(zast)(&zgsz3235, zgaz381);
      zSomez3z5unionz0zzast(&zgsz3122, zgsz3235);
      KILL(zast)(&zgsz3235);
    }
    KILL(zast)(&zgaz381);
  
  
  
  
  
  
    goto finish_match_81;
  }
case_96: ;
  {
    uint64_t zv__37;
    zv__37 = zmergez3var;
    uint64_t zgaz384;
    zgaz384 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__37 >> INT64_C(0)));
    bool zgsz3161;
    zgsz3161 = (zgaz384 == UINT64_C(0b1100011));
  
    if (!(zgsz3161)) {
  
    goto case_97;
    }
    uint64_t zimm4;
    zimm4 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__37 >> INT64_C(31)));
    uint64_t zuz3106;
    zuz3106 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__37 >> INT64_C(20)));
    uint64_t zuz3107;
    zuz3107 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__37 >> INT64_C(15)));
    uint64_t zimm4shadowz39;
    zimm4shadowz39 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__37 >> INT64_C(31)));
    uint64_t zimm3;
    zimm3 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__37 >> INT64_C(7)));
    uint64_t zuz3108;
    zuz3108 = (safe_rshift(UINT64_MAX, 64 - 6) & (zv__37 >> INT64_C(25)));
    uint64_t zuz3109;
    zuz3109 = (safe_rshift(UINT64_MAX, 64 - 4) & (zv__37 >> INT64_C(8)));
    struct zast zgaz383;
    CREATE(zast)(&zgaz383);
    {
      struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 zgsz3160;
      zgsz3160.ztup0 = zimm4shadowz39;
      zgsz3160.ztup1 = zuz3108;
      zgsz3160.ztup2 = zuz3106;
      zgsz3160.ztup3 = zuz3107;
      zgsz3160.ztup4 = zuz3109;
      zgsz3160.ztup5 = zimm3;
      zgsz3160.ztup6 = zBEQ;
      zBTYPE(&zgaz383, zgsz3160);
    
    }
    {
      struct zast zgsz3236;
      CREATE(zast)(&zgsz3236);
      COPY(zast)(&zgsz3236, zgaz383);
      zSomez3z5unionz0zzast(&zgsz3122, zgsz3236);
      KILL(zast)(&zgsz3236);
    }
    KILL(zast)(&zgaz383);
  
  
  
  
  
  
  
  
    goto finish_match_81;
  }
case_97: ;
  {
    uint64_t zv__39;
    zv__39 = zmergez3var;
    uint64_t zgaz386;
    zgaz386 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__39 >> INT64_C(0)));
    bool zgsz3163;
    zgsz3163 = (zgaz386 == UINT64_C(0b1100011));
  
    if (!(zgsz3163)) {
  
    goto case_98;
    }
    uint64_t zuz3110;
    zuz3110 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__39 >> INT64_C(31)));
    uint64_t zuz3111;
    zuz3111 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__39 >> INT64_C(20)));
    uint64_t zuz3112;
    zuz3112 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__39 >> INT64_C(15)));
    uint64_t zimm4shadowz310;
    zimm4shadowz310 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__39 >> INT64_C(31)));
    uint64_t zuz3113;
    zuz3113 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__39 >> INT64_C(7)));
    uint64_t zuz3114;
    zuz3114 = (safe_rshift(UINT64_MAX, 64 - 6) & (zv__39 >> INT64_C(25)));
    uint64_t zuz3115;
    zuz3115 = (safe_rshift(UINT64_MAX, 64 - 4) & (zv__39 >> INT64_C(8)));
    struct zast zgaz385;
    CREATE(zast)(&zgaz385);
    {
      struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 zgsz3162;
      zgsz3162.ztup0 = zimm4shadowz310;
      zgsz3162.ztup1 = zuz3114;
      zgsz3162.ztup2 = zuz3111;
      zgsz3162.ztup3 = zuz3112;
      zgsz3162.ztup4 = zuz3115;
      zgsz3162.ztup5 = zuz3113;
      zgsz3162.ztup6 = zBNE;
      zBTYPE(&zgaz385, zgsz3162);
    
    }
    {
      struct zast zgsz3237;
      CREATE(zast)(&zgsz3237);
      COPY(zast)(&zgsz3237, zgaz385);
      zSomez3z5unionz0zzast(&zgsz3122, zgsz3237);
      KILL(zast)(&zgsz3237);
    }
    KILL(zast)(&zgaz385);
  
  
  
  
  
  
  
  
    goto finish_match_81;
  }
case_98: ;
  {
    uint64_t zv__41;
    zv__41 = zmergez3var;
    uint64_t zgaz388;
    zgaz388 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__41 >> INT64_C(0)));
    bool zgsz3165;
    zgsz3165 = (zgaz388 == UINT64_C(0b0110111));
  
    if (!(zgsz3165)) {
  
    goto case_99;
    }
    uint64_t zuz3116;
    zuz3116 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__41 >> INT64_C(12)));
    uint64_t zuz3117;
    zuz3117 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__41 >> INT64_C(7)));
    uint64_t zimmshadowz311;
    zimmshadowz311 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__41 >> INT64_C(12)));
    struct zast zgaz387;
    CREATE(zast)(&zgaz387);
    {
      struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 zgsz3164;
      zgsz3164.ztup0 = zimmshadowz311;
      zgsz3164.ztup1 = zuz3117;
      zgsz3164.ztup2 = zLUI;
      zUTYPE(&zgaz387, zgsz3164);
    
    }
    {
      struct zast zgsz3238;
      CREATE(zast)(&zgsz3238);
      COPY(zast)(&zgsz3238, zgaz387);
      zSomez3z5unionz0zzast(&zgsz3122, zgsz3238);
      KILL(zast)(&zgsz3238);
    }
    KILL(zast)(&zgaz387);
  
  
  
  
    goto finish_match_81;
  }
case_99: ;
  {
    uint64_t zv__43;
    zv__43 = zmergez3var;
    uint64_t zgaz390;
    zgaz390 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__43 >> INT64_C(0)));
    bool zgsz3167;
    zgsz3167 = (zgaz390 == UINT64_C(0b0010111));
  
    if (!(zgsz3167)) {
  
    goto case_100;
    }
    uint64_t zuz3118;
    zuz3118 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__43 >> INT64_C(12)));
    uint64_t zuz3119;
    zuz3119 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__43 >> INT64_C(7)));
    uint64_t zimmshadowz312;
    zimmshadowz312 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__43 >> INT64_C(12)));
    struct zast zgaz389;
    CREATE(zast)(&zgaz389);
    {
      struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 zgsz3166;
      zgsz3166.ztup0 = zimmshadowz312;
      zgsz3166.ztup1 = zuz3119;
      zgsz3166.ztup2 = zAUIPC;
      zUTYPE(&zgaz389, zgsz3166);
    
    }
    {
      struct zast zgsz3239;
      CREATE(zast)(&zgsz3239);
      COPY(zast)(&zgsz3239, zgaz389);
      zSomez3z5unionz0zzast(&zgsz3122, zgsz3239);
      KILL(zast)(&zgsz3239);
    }
    KILL(zast)(&zgaz389);
  
  
  
  
    goto finish_match_81;
  }
case_100: ;
  {
    uint64_t zv__45;
    zv__45 = zmergez3var;
    uint64_t zgaz392;
    zgaz392 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__45 >> INT64_C(0)));
    bool zgsz3169;
    zgsz3169 = (zgaz392 == UINT64_C(0b1101111));
  
    if (!(zgsz3169)) {
  
    goto case_101;
    }
    uint64_t zuz3120;
    zuz3120 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__45 >> INT64_C(31)));
    uint64_t zuz3121;
    zuz3121 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__45 >> INT64_C(7)));
    uint64_t zimm4shadowz313;
    zimm4shadowz313 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__45 >> INT64_C(31)));
    uint64_t zuz3122;
    zuz3122 = (safe_rshift(UINT64_MAX, 64 - 8) & (zv__45 >> INT64_C(12)));
    uint64_t zuz3123;
    zuz3123 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__45 >> INT64_C(20)));
    uint64_t zuz3124;
    zuz3124 = (safe_rshift(UINT64_MAX, 64 - 10) & (zv__45 >> INT64_C(21)));
    struct zast zgaz391;
    CREATE(zast)(&zgaz391);
    {
      struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv8zCz0z5bv5zCz0z5enumz0zzjopz9 zgsz3168;
      zgsz3168.ztup0 = zimm4shadowz313;
      zgsz3168.ztup1 = zuz3124;
      zgsz3168.ztup2 = zuz3123;
      zgsz3168.ztup3 = zuz3122;
      zgsz3168.ztup4 = zuz3121;
      zgsz3168.ztup5 = zJAL;
      zJTYPE(&zgaz391, zgsz3168);
    
    }
    {
      struct zast zgsz3240;
      CREATE(zast)(&zgsz3240);
      COPY(zast)(&zgsz3240, zgaz391);
      zSomez3z5unionz0zzast(&zgsz3122, zgsz3240);
      KILL(zast)(&zgsz3240);
    }
    KILL(zast)(&zgaz391);
  
  
  
  
  
  
  
    goto finish_match_81;
  }
case_101: ;
  {
    uint64_t zv__47;
    zv__47 = zmergez3var;
    bool zgsz3170;
    zgsz3170 = (zv__47 == UINT64_C(0x00100073));
    if (!(zgsz3170)) {
  
    goto case_102;
    }
    struct zast zgaz393;
    CREATE(zast)(&zgaz393);
    zEBREAK(&zgaz393, UNIT);
    {
      struct zast zgsz3241;
      CREATE(zast)(&zgsz3241);
      COPY(zast)(&zgsz3241, zgaz393);
      zSomez3z5unionz0zzast(&zgsz3122, zgsz3241);
      KILL(zast)(&zgsz3241);
    }
    KILL(zast)(&zgaz393);
  
    goto finish_match_81;
  }
case_102: ;
  sail_match_failure("decode");
finish_match_81: ;
  COPY(zoption)((*(&zcbz313)), zgsz3122);
  KILL(zoption)(&zgsz3122);
end_function_103: ;
  goto end_function_114;
end_block_exception_104: ;
  goto end_function_114;
end_function_114: ;
}



uint64_t zread_mem(uint64_t);

sail_int zghz393;
sail_int zghz394;
lbits zghz395;
lbits zghz396;
lbits zghz397;
lbits zghz398;
sail_int zghz399;
lbits zghz3100;

void startup_zread_mem(void)
{
  CREATE(sail_int)(&zghz393);
  CREATE(sail_int)(&zghz394);
  CREATE(lbits)(&zghz395);
  CREATE(lbits)(&zghz396);
  CREATE(lbits)(&zghz397);
  CREATE(lbits)(&zghz398);
  CREATE(sail_int)(&zghz399);
  CREATE(lbits)(&zghz3100);
}

uint64_t zread_mem(uint64_t zaddr)
{
  __label__ end_function_106, end_block_exception_107;

  uint64_t zcbz314;
  uint64_t zgaz394;
  {
    RECREATE(lbits)(&zghz398);
    CONVERT_OF(lbits, fbits)(&zghz398, UINT64_C(0x0), UINT64_C(4) , true);
    RECREATE(sail_int)(&zghz399);
    CONVERT_OF(sail_int, mach_int)(&zghz399, INT64_C(32));
    RECREATE(lbits)(&zghz3100);
    zero_extend(&zghz3100, zghz398, zghz399);
    zgaz394 = CONVERT_OF(fbits, lbits)(zghz3100, true);
  }
  {
    RECREATE(sail_int)(&zghz393);
    CONVERT_OF(sail_int, mach_int)(&zghz393, INT64_C(32));
    RECREATE(sail_int)(&zghz394);
    CONVERT_OF(sail_int, mach_int)(&zghz394, INT64_C(4));
    RECREATE(lbits)(&zghz395);
    CONVERT_OF(lbits, fbits)(&zghz395, zgaz394, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz396);
    CONVERT_OF(lbits, fbits)(&zghz396, zaddr, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz397);
    read_ram(&zghz397, zghz393, zghz394, zghz395, zghz396);
    zcbz314 = CONVERT_OF(fbits, lbits)(zghz397, true);
  }

end_function_106: ;
  return zcbz314;
end_block_exception_107: ;

  return UINT64_C(0xdeadc0de);
}



void finish_zread_mem(void)
{
  KILL(lbits)(&zghz3100);
  KILL(sail_int)(&zghz399);
  KILL(lbits)(&zghz398);
  KILL(lbits)(&zghz397);
  KILL(lbits)(&zghz396);
  KILL(lbits)(&zghz395);
  KILL(sail_int)(&zghz394);
  KILL(sail_int)(&zghz393);
}

unit zmain(unit);

lbits zghz3101;
lbits zghz3102;
sail_int zghz3103;
lbits zghz3104;
lbits zghz3105;
lbits zghz3106;
sail_int zghz3107;
sail_int zghz3108;
sail_int zghz3109;
lbits zghz3110;

void startup_zmain(void)
{
  CREATE(lbits)(&zghz3101);
  CREATE(lbits)(&zghz3102);
  CREATE(sail_int)(&zghz3103);
  CREATE(lbits)(&zghz3104);
  CREATE(lbits)(&zghz3105);
  CREATE(lbits)(&zghz3106);
  CREATE(sail_int)(&zghz3107);
  CREATE(sail_int)(&zghz3108);
  CREATE(sail_int)(&zghz3109);
  CREATE(lbits)(&zghz3110);
}

unit zmain(unit zgsz3179)
{
  __label__ end_function_109, end_block_exception_110;

  unit zcbz315;
  {
    RECREATE(sail_int)(&zghz3107);
    elf_entry(&zghz3107, UNIT);
    {
      RECREATE(sail_int)(&zghz3108);
      CONVERT_OF(sail_int, mach_int)(&zghz3108, INT64_C(32));
      RECREATE(sail_int)(&zghz3109);
      CONVERT_OF(sail_int, mach_int)(&zghz3109, INT64_C(0));
      RECREATE(lbits)(&zghz3110);
      get_slice_int(&zghz3110, zghz3108, zghz3107, zghz3109);
      zPC = CONVERT_OF(fbits, lbits)(zghz3110, true);
    }
    unit zgsz3187;
    zgsz3187 = UNIT;
  }
  {
    unit zgsz3185;
    {
      RECREATE(lbits)(&zghz3106);
      CONVERT_OF(lbits, fbits)(&zghz3106, zPC, UINT64_C(32) , true);
      zgsz3185 = print_bits("PC = ", zghz3106);
    }
  }
  {
    uint64_t zline;
    zline = zread_mem(zPC);
    unit zgsz3183;
    {
      RECREATE(lbits)(&zghz3105);
      CONVERT_OF(lbits, fbits)(&zghz3105, zline, UINT64_C(32) , true);
      zgsz3183 = print_bits("line = ", zghz3105);
    }
  
  }
  uint64_t ztest;
  ztest = UINT64_C(0xFF);
  {
    {
      RECREATE(lbits)(&zghz3102);
      CONVERT_OF(lbits, fbits)(&zghz3102, ztest, UINT64_C(8) , true);
      RECREATE(sail_int)(&zghz3103);
      CONVERT_OF(sail_int, mach_int)(&zghz3103, INT64_C(3));
      RECREATE(lbits)(&zghz3104);
      shiftl(&zghz3104, zghz3102, zghz3103);
      ztest = CONVERT_OF(fbits, lbits)(zghz3104, true);
    }
    unit zgsz3193;
    zgsz3193 = UNIT;
  }
  {
    unit zgsz3191;
    {
      RECREATE(lbits)(&zghz3101);
      CONVERT_OF(lbits, fbits)(&zghz3101, ztest, UINT64_C(8) , true);
      zgsz3191 = print_bits("test = ", zghz3101);
    }
  }
  uint64_t za;
  za = UINT64_C(0x7);
  uint64_t zb;
  zb = UINT64_C(0x3);
  zcbz315 = print_endline("dummy");



end_function_109: ;
  return zcbz315;
end_block_exception_110: ;

  return UNIT;
}



void finish_zmain(void)
{
  KILL(lbits)(&zghz3110);
  KILL(sail_int)(&zghz3109);
  KILL(sail_int)(&zghz3108);
  KILL(sail_int)(&zghz3107);
  KILL(lbits)(&zghz3106);
  KILL(lbits)(&zghz3105);
  KILL(lbits)(&zghz3104);
  KILL(sail_int)(&zghz3103);
  KILL(lbits)(&zghz3102);
  KILL(lbits)(&zghz3101);
}

unit zinitializze_registers(unit);

sail_int zghz3111;
lbits zghz3112;
sail_int zghz3113;
lbits zghz3114;
sail_int zghz3115;
lbits zghz3116;
sail_int zghz3117;
lbits zghz3118;
sail_int zghz3119;
lbits zghz3120;
sail_int zghz3121;
lbits zghz3122;
sail_int zghz3123;
lbits zghz3124;
sail_int zghz3125;
lbits zghz3126;
sail_int zghz3127;
lbits zghz3128;

void startup_zinitializze_registers(void)
{
  CREATE(sail_int)(&zghz3111);
  CREATE(lbits)(&zghz3112);
  CREATE(sail_int)(&zghz3113);
  CREATE(lbits)(&zghz3114);
  CREATE(sail_int)(&zghz3115);
  CREATE(lbits)(&zghz3116);
  CREATE(sail_int)(&zghz3117);
  CREATE(lbits)(&zghz3118);
  CREATE(sail_int)(&zghz3119);
  CREATE(lbits)(&zghz3120);
  CREATE(sail_int)(&zghz3121);
  CREATE(lbits)(&zghz3122);
  CREATE(sail_int)(&zghz3123);
  CREATE(lbits)(&zghz3124);
  CREATE(sail_int)(&zghz3125);
  CREATE(lbits)(&zghz3126);
  CREATE(sail_int)(&zghz3127);
  CREATE(lbits)(&zghz3128);
}

unit zinitializze_registers(unit zgsz3194)
{
  __label__ end_function_112, end_block_exception_113;

  unit zcbz316;
  {
    {
      RECREATE(sail_int)(&zghz3127);
      CONVERT_OF(sail_int, mach_int)(&zghz3127, INT64_C(32));
      RECREATE(lbits)(&zghz3128);
      UNDEFINED(lbits)(&zghz3128, zghz3127);
      zPC = CONVERT_OF(fbits, lbits)(zghz3128, true);
    }
    unit zgsz3218;
    zgsz3218 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3125);
      CONVERT_OF(sail_int, mach_int)(&zghz3125, INT64_C(32));
      RECREATE(lbits)(&zghz3126);
      UNDEFINED(lbits)(&zghz3126, zghz3125);
      zzzero = CONVERT_OF(fbits, lbits)(zghz3126, true);
    }
    unit zgsz3217;
    zgsz3217 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3123);
      CONVERT_OF(sail_int, mach_int)(&zghz3123, INT64_C(32));
      RECREATE(lbits)(&zghz3124);
      UNDEFINED(lbits)(&zghz3124, zghz3123);
      zra = CONVERT_OF(fbits, lbits)(zghz3124, true);
    }
    unit zgsz3216;
    zgsz3216 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3121);
      CONVERT_OF(sail_int, mach_int)(&zghz3121, INT64_C(32));
      RECREATE(lbits)(&zghz3122);
      UNDEFINED(lbits)(&zghz3122, zghz3121);
      zsp = CONVERT_OF(fbits, lbits)(zghz3122, true);
    }
    unit zgsz3215;
    zgsz3215 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3119);
      CONVERT_OF(sail_int, mach_int)(&zghz3119, INT64_C(32));
      RECREATE(lbits)(&zghz3120);
      UNDEFINED(lbits)(&zghz3120, zghz3119);
      zgp = CONVERT_OF(fbits, lbits)(zghz3120, true);
    }
    unit zgsz3214;
    zgsz3214 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3117);
      CONVERT_OF(sail_int, mach_int)(&zghz3117, INT64_C(32));
      RECREATE(lbits)(&zghz3118);
      UNDEFINED(lbits)(&zghz3118, zghz3117);
      za0 = CONVERT_OF(fbits, lbits)(zghz3118, true);
    }
    unit zgsz3213;
    zgsz3213 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3115);
      CONVERT_OF(sail_int, mach_int)(&zghz3115, INT64_C(32));
      RECREATE(lbits)(&zghz3116);
      UNDEFINED(lbits)(&zghz3116, zghz3115);
      za1 = CONVERT_OF(fbits, lbits)(zghz3116, true);
    }
    unit zgsz3212;
    zgsz3212 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3113);
      CONVERT_OF(sail_int, mach_int)(&zghz3113, INT64_C(32));
      RECREATE(lbits)(&zghz3114);
      UNDEFINED(lbits)(&zghz3114, zghz3113);
      za2 = CONVERT_OF(fbits, lbits)(zghz3114, true);
    }
    unit zgsz3211;
    zgsz3211 = UNIT;
  }
  {
    RECREATE(sail_int)(&zghz3111);
    CONVERT_OF(sail_int, mach_int)(&zghz3111, INT64_C(32));
    RECREATE(lbits)(&zghz3112);
    UNDEFINED(lbits)(&zghz3112, zghz3111);
    za3 = CONVERT_OF(fbits, lbits)(zghz3112, true);
  }
  zcbz316 = UNIT;
end_function_112: ;
  return zcbz316;
end_block_exception_113: ;

  return UNIT;
}



void finish_zinitializze_registers(void)
{
  KILL(lbits)(&zghz3128);
  KILL(sail_int)(&zghz3127);
  KILL(lbits)(&zghz3126);
  KILL(sail_int)(&zghz3125);
  KILL(lbits)(&zghz3124);
  KILL(sail_int)(&zghz3123);
  KILL(lbits)(&zghz3122);
  KILL(sail_int)(&zghz3121);
  KILL(lbits)(&zghz3120);
  KILL(sail_int)(&zghz3119);
  KILL(lbits)(&zghz3118);
  KILL(sail_int)(&zghz3117);
  KILL(lbits)(&zghz3116);
  KILL(sail_int)(&zghz3115);
  KILL(lbits)(&zghz3114);
  KILL(sail_int)(&zghz3113);
  KILL(lbits)(&zghz3112);
  KILL(sail_int)(&zghz3111);
}

void model_init(void)
{
  setup_rts();
  startup_zsail_mask();
  startup_zsail_ones();
  startup_zfdiv_int();
  startup_zadd_to_PC();
  startup_zinc_PC();
  startup_zrX();
  startup_zwX();
  startup_zxor_bitvector();
  startup_ztwos_complement();
  startup_zmul_bitvector();
  startup_zexecute();
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
  finish_zadd_to_PC();
  finish_zinc_PC();
  finish_zrX();
  finish_zwX();
  finish_zxor_bitvector();
  finish_ztwos_complement();
  finish_zmul_bitvector();
  finish_zexecute();
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
