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
  __label__ end_function_1, end_block_exception_2, end_function_87;

  bool zgaz31;
  {
    RECREATE(sail_int)(&zghz30);
    length_lbits(&zghz30, zv);
    zgaz31 = lteq(zlen, zghz30);
  }
  if (zgaz31) {  sail_truncate((*(&zcbz30)), zv, zlen);  } else {  zero_extend((*(&zcbz30)), zv, zlen);  }

end_function_1: ;
  goto end_function_87;
end_block_exception_2: ;
  goto end_function_87;
end_function_87: ;
}



void finish_zsail_mask(void)
{    KILL(sail_int)(&zghz30);
}















void zsail_ones(lbits *rop, sail_int);

lbits zghz31;

void startup_zsail_ones(void)
{    CREATE(lbits)(&zghz31);
}

void zsail_ones(lbits *zcbz31, sail_int zn)
{
  __label__ end_function_4, end_block_exception_5, end_function_86;

  RECREATE(lbits)(&zghz31);
  zeros(&zghz31, zn);
  not_bits((*(&zcbz31)), zghz31);
end_function_4: ;
  goto end_function_86;
end_block_exception_5: ;
  goto end_function_86;
end_function_86: ;
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
  __label__ end_function_7, end_block_exception_8, end_function_85;

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
  goto end_function_85;
end_block_exception_8: ;
  goto end_function_85;
end_function_85: ;
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
let_end_9: ;
}
static void kill_letbind_0(void) {    KILL(zz5vecz8z6z8z5bv32z9z9)(&zX);
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
  __label__ end_function_11, end_block_exception_12;

  unit zcbz33;
  {
    RECREATE(lbits)(&zghz314);
    CONVERT_OF(lbits, fbits)(&zghz314, zPC, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz315);
    add_bits_int(&zghz315, zghz314, zbytes);
    zPC = CONVERT_OF(fbits, lbits)(zghz315, true);
  }
  zcbz33 = UNIT;
end_function_11: ;
  return zcbz33;
end_block_exception_12: ;

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
  __label__ end_function_14, end_block_exception_15;

  unit zcbz34;
  {
    RECREATE(sail_int)(&zghz316);
    CONVERT_OF(sail_int, mach_int)(&zghz316, INT64_C(4));
    zcbz34 = zadd_to_PC(zghz316);
  }
end_function_14: ;
  return zcbz34;
end_block_exception_15: ;

  return UNIT;
}



void finish_zinc_PC(void)
{    KILL(sail_int)(&zghz316);
}










void zdecode(struct zoption *rop, uint64_t);






unit zexecute(struct zast);

unit zexecute(struct zast zmergez3var)
{
  __label__ case_18, case_19, case_20, case_21, case_22, case_23, case_24, case_25, case_26, case_27, case_28, case_29, case_30, case_31, case_32, case_33, case_34, case_35, case_36, case_37, finish_match_17, end_function_38, end_block_exception_39;

  unit zcbz35;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_18;
    uint64_t zrs2;
    zrs2 = zmergez3var.zRTYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zRTYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zRTYPE.ztup2;
    if ((zADD != zmergez3var.zRTYPE.ztup3)) goto case_18;
    zcbz35 = print_endline("execute ADD\n");
  
  
  
    goto finish_match_17;
  }
case_18: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_19;
    uint64_t zuz30;
    zuz30 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz31;
    zuz31 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz32;
    zuz32 = zmergez3var.zRTYPE.ztup2;
    if ((zAND != zmergez3var.zRTYPE.ztup3)) goto case_19;
    zcbz35 = print_endline("execute AND\n");
  
  
  
    goto finish_match_17;
  }
case_19: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_20;
    uint64_t zuz33;
    zuz33 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz34;
    zuz34 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz35;
    zuz35 = zmergez3var.zRTYPE.ztup2;
    if ((zOR != zmergez3var.zRTYPE.ztup3)) goto case_20;
    zcbz35 = print_endline("execute OR\n");
  
  
  
    goto finish_match_17;
  }
case_20: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_21;
    uint64_t zuz36;
    zuz36 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz37;
    zuz37 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz38;
    zuz38 = zmergez3var.zRTYPE.ztup2;
    if ((zXOR != zmergez3var.zRTYPE.ztup3)) goto case_21;
    zcbz35 = print_endline("execute XOR\n");
  
  
  
    goto finish_match_17;
  }
case_21: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_22;
    uint64_t zuz39;
    zuz39 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz310;
    zuz310 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz311;
    zuz311 = zmergez3var.zRTYPE.ztup2;
    if ((zMUL != zmergez3var.zRTYPE.ztup3)) goto case_22;
    zcbz35 = print_endline("execute MUL\n");
  
  
  
    goto finish_match_17;
  }
case_22: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_23;
    uint64_t zuz312;
    zuz312 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz313;
    zuz313 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz314;
    zuz314 = zmergez3var.zRTYPE.ztup2;
    if ((zDIV != zmergez3var.zRTYPE.ztup3)) goto case_23;
    zcbz35 = print_endline("execute DIV\n");
  
  
  
    goto finish_match_17;
  }
case_23: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_24;
    uint64_t zuz315;
    zuz315 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz316;
    zuz316 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz317;
    zuz317 = zmergez3var.zRTYPE.ztup2;
    if ((zREM != zmergez3var.zRTYPE.ztup3)) goto case_24;
    zcbz35 = print_endline("execute REM\n");
  
  
  
    goto finish_match_17;
  }
case_24: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_25;
    uint64_t zimm;
    zimm = zmergez3var.zITYPE.ztup0;
    uint64_t zuz318;
    zuz318 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz319;
    zuz319 = zmergez3var.zITYPE.ztup2;
    if ((zADDI != zmergez3var.zITYPE.ztup3)) goto case_25;
    zcbz35 = print_endline("execute ADDI\n");
  
  
  
    goto finish_match_17;
  }
case_25: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_26;
    uint64_t zuz320;
    zuz320 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz321;
    zuz321 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz322;
    zuz322 = zmergez3var.zITYPE.ztup2;
    if ((zSLTI != zmergez3var.zITYPE.ztup3)) goto case_26;
    zcbz35 = print_endline("execute SLTI\n");
  
  
  
    goto finish_match_17;
  }
case_26: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_27;
    uint64_t zuz323;
    zuz323 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz324;
    zuz324 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz325;
    zuz325 = zmergez3var.zITYPE.ztup2;
    if ((zANDI != zmergez3var.zITYPE.ztup3)) goto case_27;
    zcbz35 = print_endline("execute ANDI\n");
  
  
  
    goto finish_match_17;
  }
case_27: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_28;
    uint64_t zuz326;
    zuz326 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz327;
    zuz327 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz328;
    zuz328 = zmergez3var.zITYPE.ztup2;
    if ((zORI != zmergez3var.zITYPE.ztup3)) goto case_28;
    zcbz35 = print_endline("execute ORI\n");
  
  
  
    goto finish_match_17;
  }
case_28: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_29;
    uint64_t zuz329;
    zuz329 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz330;
    zuz330 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz331;
    zuz331 = zmergez3var.zITYPE.ztup2;
    if ((zXORI != zmergez3var.zITYPE.ztup3)) goto case_29;
    zcbz35 = print_endline("execute XORI\n");
  
  
  
    goto finish_match_17;
  }
case_29: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_30;
    uint64_t zuz332;
    zuz332 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz333;
    zuz333 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz334;
    zuz334 = zmergez3var.zITYPE.ztup2;
    if ((zJALR != zmergez3var.zITYPE.ztup3)) goto case_30;
    zcbz35 = print_endline("execute JALR\n");
  
  
  
    goto finish_match_17;
  }
case_30: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_31;
    uint64_t zuz335;
    zuz335 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz336;
    zuz336 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz337;
    zuz337 = zmergez3var.zITYPE.ztup2;
    if ((zLW != zmergez3var.zITYPE.ztup3)) goto case_31;
    zcbz35 = print_endline("execute LW\n");
  
  
  
    goto finish_match_17;
  }
case_31: ;
  {
    if (zmergez3var.kind != Kind_zSTYPE) goto case_32;
    uint64_t zimm2;
    zimm2 = zmergez3var.zSTYPE.ztup0;
    uint64_t zuz338;
    zuz338 = zmergez3var.zSTYPE.ztup1;
    uint64_t zuz339;
    zuz339 = zmergez3var.zSTYPE.ztup2;
    uint64_t zimm1;
    zimm1 = zmergez3var.zSTYPE.ztup3;
    if ((zSW != zmergez3var.zSTYPE.ztup4)) goto case_32;
    zcbz35 = print_endline("execute SW\n");
  
  
  
  
    goto finish_match_17;
  }
case_32: ;
  {
    if (zmergez3var.kind != Kind_zBTYPE) goto case_33;
    uint64_t zimm4;
    zimm4 = zmergez3var.zBTYPE.ztup0;
    uint64_t zuz340;
    zuz340 = zmergez3var.zBTYPE.ztup1;
    uint64_t zuz341;
    zuz341 = zmergez3var.zBTYPE.ztup2;
    uint64_t zuz342;
    zuz342 = zmergez3var.zBTYPE.ztup3;
    uint64_t zuz343;
    zuz343 = zmergez3var.zBTYPE.ztup4;
    uint64_t zimm3;
    zimm3 = zmergez3var.zBTYPE.ztup5;
    if ((zBEQ != zmergez3var.zBTYPE.ztup6)) goto case_33;
    zcbz35 = print_endline("execute BEQ\n");
  
  
  
  
  
  
    goto finish_match_17;
  }
case_33: ;
  {
    if (zmergez3var.kind != Kind_zBTYPE) goto case_34;
    uint64_t zuz344;
    zuz344 = zmergez3var.zBTYPE.ztup0;
    uint64_t zuz345;
    zuz345 = zmergez3var.zBTYPE.ztup1;
    uint64_t zuz346;
    zuz346 = zmergez3var.zBTYPE.ztup2;
    uint64_t zuz347;
    zuz347 = zmergez3var.zBTYPE.ztup3;
    uint64_t zuz348;
    zuz348 = zmergez3var.zBTYPE.ztup4;
    uint64_t zuz349;
    zuz349 = zmergez3var.zBTYPE.ztup5;
    if ((zBNE != zmergez3var.zBTYPE.ztup6)) goto case_34;
    zcbz35 = print_endline("execute BNE\n");
  
  
  
  
  
  
    goto finish_match_17;
  }
case_34: ;
  {
    if (zmergez3var.kind != Kind_zUTYPE) goto case_35;
    uint64_t zuz350;
    zuz350 = zmergez3var.zUTYPE.ztup0;
    uint64_t zuz351;
    zuz351 = zmergez3var.zUTYPE.ztup1;
    if ((zLUI != zmergez3var.zUTYPE.ztup2)) goto case_35;
    zcbz35 = print_endline("execute LUI\n");
  
  
    goto finish_match_17;
  }
case_35: ;
  {
    if (zmergez3var.kind != Kind_zUTYPE) goto case_36;
    uint64_t zuz352;
    zuz352 = zmergez3var.zUTYPE.ztup0;
    uint64_t zuz353;
    zuz353 = zmergez3var.zUTYPE.ztup1;
    if ((zAUIPC != zmergez3var.zUTYPE.ztup2)) goto case_36;
    zcbz35 = print_endline("execute AUIPC\n");
  
  
    goto finish_match_17;
  }
case_36: ;
  {
    if (zmergez3var.kind != Kind_zJTYPE) goto case_37;
    uint64_t zuz354;
    zuz354 = zmergez3var.zJTYPE.ztup0;
    uint64_t zuz355;
    zuz355 = zmergez3var.zJTYPE.ztup1;
    uint64_t zuz356;
    zuz356 = zmergez3var.zJTYPE.ztup2;
    uint64_t zuz357;
    zuz357 = zmergez3var.zJTYPE.ztup3;
    uint64_t zuz358;
    zuz358 = zmergez3var.zJTYPE.ztup4;
    if ((zJAL != zmergez3var.zJTYPE.ztup5)) goto case_37;
    zcbz35 = print_endline("execute JAL\n");
  
  
  
  
  
    goto finish_match_17;
  }
case_37: ;
  sail_match_failure("execute");
finish_match_17: ;
end_function_38: ;
  return zcbz35;
end_block_exception_39: ;

  return UNIT;
}


















void zdecode(struct zoption *zcbz36, uint64_t zmergez3var)
{
  __label__ case_42, case_43, case_44, case_45, case_46, case_47, case_48, case_49, case_50, case_51, case_52, case_53, case_54, case_55, case_56, case_57, case_58, case_59, case_60, case_61, case_62, finish_match_41, end_function_63, end_block_exception_64, end_function_84;

  struct zoption zgsz337;
  CREATE(zoption)(&zgsz337);
  {
    uint64_t zv__0;
    zv__0 = zmergez3var;
    bool zgaz314;
    {
      uint64_t zgaz312;
      zgaz312 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__0 >> INT64_C(25)));
      zgaz314 = (zgaz312 == UINT64_C(0b0000000));
    
    }
    bool zgsz338;
    if (zgaz314) {
    uint64_t zgaz313;
    zgaz313 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__0 >> INT64_C(0)));
    zgsz338 = (zgaz313 == UINT64_C(0b0110011));
  
    } else {  zgsz338 = false;  }
    bool zgsz340;
    zgsz340 = zgsz338;
  
    if (!(zgsz340)) {
  
    goto case_42;
    }
    uint64_t zrs2;
    zrs2 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(20)));
    uint64_t zrs1;
    zrs1 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(15)));
    uint64_t zrd;
    zrd = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(7)));
    struct zast zgaz311;
    CREATE(zast)(&zgaz311);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz339;
      zgsz339.ztup0 = zrs2;
      zgsz339.ztup1 = zrs1;
      zgsz339.ztup2 = zrd;
      zgsz339.ztup3 = zADD;
      zRTYPE(&zgaz311, zgsz339);
    
    }
    {
      struct zast zgsz3143;
      CREATE(zast)(&zgsz3143);
      COPY(zast)(&zgsz3143, zgaz311);
      zSomez3z5unionz0zzast(&zgsz337, zgsz3143);
      KILL(zast)(&zgsz3143);
    }
    KILL(zast)(&zgaz311);
  
  
  
  
    goto finish_match_41;
  }
case_42: ;
  {
    uint64_t zv__3;
    zv__3 = zmergez3var;
    bool zgaz318;
    {
      uint64_t zgaz316;
      zgaz316 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__3 >> INT64_C(25)));
      zgaz318 = (zgaz316 == UINT64_C(0b0000000));
    
    }
    bool zgsz341;
    if (zgaz318) {
    uint64_t zgaz317;
    zgaz317 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__3 >> INT64_C(0)));
    zgsz341 = (zgaz317 == UINT64_C(0b0110011));
  
    } else {  zgsz341 = false;  }
    bool zgsz343;
    zgsz343 = zgsz341;
  
    if (!(zgsz343)) {
  
    goto case_43;
    }
    uint64_t zuz359;
    zuz359 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(20)));
    uint64_t zuz360;
    zuz360 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(15)));
    uint64_t zuz361;
    zuz361 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(7)));
    struct zast zgaz315;
    CREATE(zast)(&zgaz315);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz342;
      zgsz342.ztup0 = zuz359;
      zgsz342.ztup1 = zuz360;
      zgsz342.ztup2 = zuz361;
      zgsz342.ztup3 = zAND;
      zRTYPE(&zgaz315, zgsz342);
    
    }
    {
      struct zast zgsz3144;
      CREATE(zast)(&zgsz3144);
      COPY(zast)(&zgsz3144, zgaz315);
      zSomez3z5unionz0zzast(&zgsz337, zgsz3144);
      KILL(zast)(&zgsz3144);
    }
    KILL(zast)(&zgaz315);
  
  
  
  
    goto finish_match_41;
  }
case_43: ;
  {
    uint64_t zv__6;
    zv__6 = zmergez3var;
    bool zgaz322;
    {
      uint64_t zgaz320;
      zgaz320 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__6 >> INT64_C(25)));
      zgaz322 = (zgaz320 == UINT64_C(0b0000000));
    
    }
    bool zgsz344;
    if (zgaz322) {
    uint64_t zgaz321;
    zgaz321 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__6 >> INT64_C(0)));
    zgsz344 = (zgaz321 == UINT64_C(0b0110011));
  
    } else {  zgsz344 = false;  }
    bool zgsz346;
    zgsz346 = zgsz344;
  
    if (!(zgsz346)) {
  
    goto case_44;
    }
    uint64_t zuz362;
    zuz362 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(20)));
    uint64_t zuz363;
    zuz363 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(15)));
    uint64_t zuz364;
    zuz364 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(7)));
    struct zast zgaz319;
    CREATE(zast)(&zgaz319);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz345;
      zgsz345.ztup0 = zuz362;
      zgsz345.ztup1 = zuz363;
      zgsz345.ztup2 = zuz364;
      zgsz345.ztup3 = zOR;
      zRTYPE(&zgaz319, zgsz345);
    
    }
    {
      struct zast zgsz3145;
      CREATE(zast)(&zgsz3145);
      COPY(zast)(&zgsz3145, zgaz319);
      zSomez3z5unionz0zzast(&zgsz337, zgsz3145);
      KILL(zast)(&zgsz3145);
    }
    KILL(zast)(&zgaz319);
  
  
  
  
    goto finish_match_41;
  }
case_44: ;
  {
    uint64_t zv__9;
    zv__9 = zmergez3var;
    bool zgaz326;
    {
      uint64_t zgaz324;
      zgaz324 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__9 >> INT64_C(25)));
      zgaz326 = (zgaz324 == UINT64_C(0b0000000));
    
    }
    bool zgsz347;
    if (zgaz326) {
    uint64_t zgaz325;
    zgaz325 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__9 >> INT64_C(0)));
    zgsz347 = (zgaz325 == UINT64_C(0b0110011));
  
    } else {  zgsz347 = false;  }
    bool zgsz349;
    zgsz349 = zgsz347;
  
    if (!(zgsz349)) {
  
    goto case_45;
    }
    uint64_t zuz365;
    zuz365 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(20)));
    uint64_t zuz366;
    zuz366 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(15)));
    uint64_t zuz367;
    zuz367 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(7)));
    struct zast zgaz323;
    CREATE(zast)(&zgaz323);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz348;
      zgsz348.ztup0 = zuz365;
      zgsz348.ztup1 = zuz366;
      zgsz348.ztup2 = zuz367;
      zgsz348.ztup3 = zXOR;
      zRTYPE(&zgaz323, zgsz348);
    
    }
    {
      struct zast zgsz3146;
      CREATE(zast)(&zgsz3146);
      COPY(zast)(&zgsz3146, zgaz323);
      zSomez3z5unionz0zzast(&zgsz337, zgsz3146);
      KILL(zast)(&zgsz3146);
    }
    KILL(zast)(&zgaz323);
  
  
  
  
    goto finish_match_41;
  }
case_45: ;
  {
    uint64_t zv__12;
    zv__12 = zmergez3var;
    bool zgaz330;
    {
      uint64_t zgaz328;
      zgaz328 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__12 >> INT64_C(25)));
      zgaz330 = (zgaz328 == UINT64_C(0b0000001));
    
    }
    bool zgsz350;
    if (zgaz330) {
    uint64_t zgaz329;
    zgaz329 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__12 >> INT64_C(0)));
    zgsz350 = (zgaz329 == UINT64_C(0b0110011));
  
    } else {  zgsz350 = false;  }
    bool zgsz352;
    zgsz352 = zgsz350;
  
    if (!(zgsz352)) {
  
    goto case_46;
    }
    uint64_t zuz368;
    zuz368 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(20)));
    uint64_t zuz369;
    zuz369 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(15)));
    uint64_t zuz370;
    zuz370 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(7)));
    struct zast zgaz327;
    CREATE(zast)(&zgaz327);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz351;
      zgsz351.ztup0 = zuz368;
      zgsz351.ztup1 = zuz369;
      zgsz351.ztup2 = zuz370;
      zgsz351.ztup3 = zMUL;
      zRTYPE(&zgaz327, zgsz351);
    
    }
    {
      struct zast zgsz3147;
      CREATE(zast)(&zgsz3147);
      COPY(zast)(&zgsz3147, zgaz327);
      zSomez3z5unionz0zzast(&zgsz337, zgsz3147);
      KILL(zast)(&zgsz3147);
    }
    KILL(zast)(&zgaz327);
  
  
  
  
    goto finish_match_41;
  }
case_46: ;
  {
    uint64_t zv__15;
    zv__15 = zmergez3var;
    bool zgaz334;
    {
      uint64_t zgaz332;
      zgaz332 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__15 >> INT64_C(25)));
      zgaz334 = (zgaz332 == UINT64_C(0b0000001));
    
    }
    bool zgsz353;
    if (zgaz334) {
    uint64_t zgaz333;
    zgaz333 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__15 >> INT64_C(0)));
    zgsz353 = (zgaz333 == UINT64_C(0b0110011));
  
    } else {  zgsz353 = false;  }
    bool zgsz355;
    zgsz355 = zgsz353;
  
    if (!(zgsz355)) {
  
    goto case_47;
    }
    uint64_t zuz371;
    zuz371 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(20)));
    uint64_t zuz372;
    zuz372 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(15)));
    uint64_t zuz373;
    zuz373 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(7)));
    struct zast zgaz331;
    CREATE(zast)(&zgaz331);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz354;
      zgsz354.ztup0 = zuz371;
      zgsz354.ztup1 = zuz372;
      zgsz354.ztup2 = zuz373;
      zgsz354.ztup3 = zDIV;
      zRTYPE(&zgaz331, zgsz354);
    
    }
    {
      struct zast zgsz3148;
      CREATE(zast)(&zgsz3148);
      COPY(zast)(&zgsz3148, zgaz331);
      zSomez3z5unionz0zzast(&zgsz337, zgsz3148);
      KILL(zast)(&zgsz3148);
    }
    KILL(zast)(&zgaz331);
  
  
  
  
    goto finish_match_41;
  }
case_47: ;
  {
    uint64_t zv__18;
    zv__18 = zmergez3var;
    bool zgaz338;
    {
      uint64_t zgaz336;
      zgaz336 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__18 >> INT64_C(25)));
      zgaz338 = (zgaz336 == UINT64_C(0b0000001));
    
    }
    bool zgsz356;
    if (zgaz338) {
    uint64_t zgaz337;
    zgaz337 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__18 >> INT64_C(0)));
    zgsz356 = (zgaz337 == UINT64_C(0b0110011));
  
    } else {  zgsz356 = false;  }
    bool zgsz358;
    zgsz358 = zgsz356;
  
    if (!(zgsz358)) {
  
    goto case_48;
    }
    uint64_t zuz374;
    zuz374 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(20)));
    uint64_t zuz375;
    zuz375 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(15)));
    uint64_t zuz376;
    zuz376 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(7)));
    struct zast zgaz335;
    CREATE(zast)(&zgaz335);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz357;
      zgsz357.ztup0 = zuz374;
      zgsz357.ztup1 = zuz375;
      zgsz357.ztup2 = zuz376;
      zgsz357.ztup3 = zREM;
      zRTYPE(&zgaz335, zgsz357);
    
    }
    {
      struct zast zgsz3149;
      CREATE(zast)(&zgsz3149);
      COPY(zast)(&zgsz3149, zgaz335);
      zSomez3z5unionz0zzast(&zgsz337, zgsz3149);
      KILL(zast)(&zgsz3149);
    }
    KILL(zast)(&zgaz335);
  
  
  
  
    goto finish_match_41;
  }
case_48: ;
  {
    uint64_t zv__21;
    zv__21 = zmergez3var;
    uint64_t zgaz340;
    zgaz340 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__21 >> INT64_C(0)));
    bool zgsz360;
    zgsz360 = (zgaz340 == UINT64_C(0b0010011));
  
    if (!(zgsz360)) {
  
    goto case_49;
    }
    uint64_t zimm;
    zimm = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__21 >> INT64_C(20)));
    uint64_t zuz377;
    zuz377 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__21 >> INT64_C(15)));
    uint64_t zuz378;
    zuz378 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__21 >> INT64_C(7)));
    uint64_t zimmshadowz30;
    zimmshadowz30 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__21 >> INT64_C(20)));
    struct zast zgaz339;
    CREATE(zast)(&zgaz339);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz359;
      zgsz359.ztup0 = zimmshadowz30;
      zgsz359.ztup1 = zuz377;
      zgsz359.ztup2 = zuz378;
      zgsz359.ztup3 = zADDI;
      zITYPE(&zgaz339, zgsz359);
    
    }
    {
      struct zast zgsz3150;
      CREATE(zast)(&zgsz3150);
      COPY(zast)(&zgsz3150, zgaz339);
      zSomez3z5unionz0zzast(&zgsz337, zgsz3150);
      KILL(zast)(&zgsz3150);
    }
    KILL(zast)(&zgaz339);
  
  
  
  
  
    goto finish_match_41;
  }
case_49: ;
  {
    uint64_t zv__23;
    zv__23 = zmergez3var;
    uint64_t zgaz342;
    zgaz342 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__23 >> INT64_C(0)));
    bool zgsz362;
    zgsz362 = (zgaz342 == UINT64_C(0b0010011));
  
    if (!(zgsz362)) {
  
    goto case_50;
    }
    uint64_t zuz379;
    zuz379 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__23 >> INT64_C(20)));
    uint64_t zuz380;
    zuz380 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__23 >> INT64_C(15)));
    uint64_t zuz381;
    zuz381 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__23 >> INT64_C(7)));
    uint64_t zimmshadowz31;
    zimmshadowz31 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__23 >> INT64_C(20)));
    struct zast zgaz341;
    CREATE(zast)(&zgaz341);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz361;
      zgsz361.ztup0 = zimmshadowz31;
      zgsz361.ztup1 = zuz380;
      zgsz361.ztup2 = zuz381;
      zgsz361.ztup3 = zSLTI;
      zITYPE(&zgaz341, zgsz361);
    
    }
    {
      struct zast zgsz3151;
      CREATE(zast)(&zgsz3151);
      COPY(zast)(&zgsz3151, zgaz341);
      zSomez3z5unionz0zzast(&zgsz337, zgsz3151);
      KILL(zast)(&zgsz3151);
    }
    KILL(zast)(&zgaz341);
  
  
  
  
  
    goto finish_match_41;
  }
case_50: ;
  {
    uint64_t zv__25;
    zv__25 = zmergez3var;
    uint64_t zgaz344;
    zgaz344 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__25 >> INT64_C(0)));
    bool zgsz364;
    zgsz364 = (zgaz344 == UINT64_C(0b0010011));
  
    if (!(zgsz364)) {
  
    goto case_51;
    }
    uint64_t zuz382;
    zuz382 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__25 >> INT64_C(20)));
    uint64_t zuz383;
    zuz383 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__25 >> INT64_C(15)));
    uint64_t zuz384;
    zuz384 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__25 >> INT64_C(7)));
    uint64_t zimmshadowz32;
    zimmshadowz32 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__25 >> INT64_C(20)));
    struct zast zgaz343;
    CREATE(zast)(&zgaz343);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz363;
      zgsz363.ztup0 = zimmshadowz32;
      zgsz363.ztup1 = zuz383;
      zgsz363.ztup2 = zuz384;
      zgsz363.ztup3 = zANDI;
      zITYPE(&zgaz343, zgsz363);
    
    }
    {
      struct zast zgsz3152;
      CREATE(zast)(&zgsz3152);
      COPY(zast)(&zgsz3152, zgaz343);
      zSomez3z5unionz0zzast(&zgsz337, zgsz3152);
      KILL(zast)(&zgsz3152);
    }
    KILL(zast)(&zgaz343);
  
  
  
  
  
    goto finish_match_41;
  }
case_51: ;
  {
    uint64_t zv__27;
    zv__27 = zmergez3var;
    uint64_t zgaz346;
    zgaz346 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__27 >> INT64_C(0)));
    bool zgsz366;
    zgsz366 = (zgaz346 == UINT64_C(0b0010011));
  
    if (!(zgsz366)) {
  
    goto case_52;
    }
    uint64_t zuz385;
    zuz385 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__27 >> INT64_C(20)));
    uint64_t zuz386;
    zuz386 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__27 >> INT64_C(15)));
    uint64_t zuz387;
    zuz387 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__27 >> INT64_C(7)));
    uint64_t zimmshadowz33;
    zimmshadowz33 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__27 >> INT64_C(20)));
    struct zast zgaz345;
    CREATE(zast)(&zgaz345);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz365;
      zgsz365.ztup0 = zimmshadowz33;
      zgsz365.ztup1 = zuz386;
      zgsz365.ztup2 = zuz387;
      zgsz365.ztup3 = zORI;
      zITYPE(&zgaz345, zgsz365);
    
    }
    {
      struct zast zgsz3153;
      CREATE(zast)(&zgsz3153);
      COPY(zast)(&zgsz3153, zgaz345);
      zSomez3z5unionz0zzast(&zgsz337, zgsz3153);
      KILL(zast)(&zgsz3153);
    }
    KILL(zast)(&zgaz345);
  
  
  
  
  
    goto finish_match_41;
  }
case_52: ;
  {
    uint64_t zv__29;
    zv__29 = zmergez3var;
    uint64_t zgaz348;
    zgaz348 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__29 >> INT64_C(0)));
    bool zgsz368;
    zgsz368 = (zgaz348 == UINT64_C(0b0010011));
  
    if (!(zgsz368)) {
  
    goto case_53;
    }
    uint64_t zuz388;
    zuz388 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__29 >> INT64_C(20)));
    uint64_t zuz389;
    zuz389 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__29 >> INT64_C(15)));
    uint64_t zuz390;
    zuz390 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__29 >> INT64_C(7)));
    uint64_t zimmshadowz34;
    zimmshadowz34 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__29 >> INT64_C(20)));
    struct zast zgaz347;
    CREATE(zast)(&zgaz347);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz367;
      zgsz367.ztup0 = zimmshadowz34;
      zgsz367.ztup1 = zuz389;
      zgsz367.ztup2 = zuz390;
      zgsz367.ztup3 = zXORI;
      zITYPE(&zgaz347, zgsz367);
    
    }
    {
      struct zast zgsz3154;
      CREATE(zast)(&zgsz3154);
      COPY(zast)(&zgsz3154, zgaz347);
      zSomez3z5unionz0zzast(&zgsz337, zgsz3154);
      KILL(zast)(&zgsz3154);
    }
    KILL(zast)(&zgaz347);
  
  
  
  
  
    goto finish_match_41;
  }
case_53: ;
  {
    uint64_t zv__31;
    zv__31 = zmergez3var;
    uint64_t zgaz350;
    zgaz350 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__31 >> INT64_C(0)));
    bool zgsz370;
    zgsz370 = (zgaz350 == UINT64_C(0b1100111));
  
    if (!(zgsz370)) {
  
    goto case_54;
    }
    uint64_t zuz391;
    zuz391 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__31 >> INT64_C(20)));
    uint64_t zuz392;
    zuz392 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__31 >> INT64_C(15)));
    uint64_t zuz393;
    zuz393 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__31 >> INT64_C(7)));
    uint64_t zimmshadowz35;
    zimmshadowz35 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__31 >> INT64_C(20)));
    struct zast zgaz349;
    CREATE(zast)(&zgaz349);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz369;
      zgsz369.ztup0 = zimmshadowz35;
      zgsz369.ztup1 = zuz392;
      zgsz369.ztup2 = zuz393;
      zgsz369.ztup3 = zJALR;
      zITYPE(&zgaz349, zgsz369);
    
    }
    {
      struct zast zgsz3155;
      CREATE(zast)(&zgsz3155);
      COPY(zast)(&zgsz3155, zgaz349);
      zSomez3z5unionz0zzast(&zgsz337, zgsz3155);
      KILL(zast)(&zgsz3155);
    }
    KILL(zast)(&zgaz349);
  
  
  
  
  
    goto finish_match_41;
  }
case_54: ;
  {
    uint64_t zv__33;
    zv__33 = zmergez3var;
    uint64_t zgaz352;
    zgaz352 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__33 >> INT64_C(0)));
    bool zgsz372;
    zgsz372 = (zgaz352 == UINT64_C(0b0000011));
  
    if (!(zgsz372)) {
  
    goto case_55;
    }
    uint64_t zuz394;
    zuz394 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__33 >> INT64_C(20)));
    uint64_t zuz395;
    zuz395 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__33 >> INT64_C(15)));
    uint64_t zuz396;
    zuz396 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__33 >> INT64_C(7)));
    uint64_t zimmshadowz36;
    zimmshadowz36 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__33 >> INT64_C(20)));
    struct zast zgaz351;
    CREATE(zast)(&zgaz351);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz371;
      zgsz371.ztup0 = zimmshadowz36;
      zgsz371.ztup1 = zuz395;
      zgsz371.ztup2 = zuz396;
      zgsz371.ztup3 = zLW;
      zITYPE(&zgaz351, zgsz371);
    
    }
    {
      struct zast zgsz3156;
      CREATE(zast)(&zgsz3156);
      COPY(zast)(&zgsz3156, zgaz351);
      zSomez3z5unionz0zzast(&zgsz337, zgsz3156);
      KILL(zast)(&zgsz3156);
    }
    KILL(zast)(&zgaz351);
  
  
  
  
  
    goto finish_match_41;
  }
case_55: ;
  {
    uint64_t zv__35;
    zv__35 = zmergez3var;
    uint64_t zgaz354;
    zgaz354 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__35 >> INT64_C(0)));
    bool zgsz374;
    zgsz374 = (zgaz354 == UINT64_C(0b0100011));
  
    if (!(zgsz374)) {
  
    goto case_56;
    }
    uint64_t zimm2;
    zimm2 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__35 >> INT64_C(25)));
    uint64_t zuz397;
    zuz397 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__35 >> INT64_C(20)));
    uint64_t zuz398;
    zuz398 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__35 >> INT64_C(15)));
    uint64_t zimm2shadowz37;
    zimm2shadowz37 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__35 >> INT64_C(25)));
    uint64_t zimm1;
    zimm1 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__35 >> INT64_C(7)));
    struct zast zgaz353;
    CREATE(zast)(&zgaz353);
    {
      struct ztuple_z8z5bv7zCz0z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzsopz9 zgsz373;
      zgsz373.ztup0 = zimm2shadowz37;
      zgsz373.ztup1 = zuz397;
      zgsz373.ztup2 = zuz398;
      zgsz373.ztup3 = zimm1;
      zgsz373.ztup4 = zSW;
      zSTYPE(&zgaz353, zgsz373);
    
    }
    {
      struct zast zgsz3157;
      CREATE(zast)(&zgsz3157);
      COPY(zast)(&zgsz3157, zgaz353);
      zSomez3z5unionz0zzast(&zgsz337, zgsz3157);
      KILL(zast)(&zgsz3157);
    }
    KILL(zast)(&zgaz353);
  
  
  
  
  
  
    goto finish_match_41;
  }
case_56: ;
  {
    uint64_t zv__37;
    zv__37 = zmergez3var;
    uint64_t zgaz356;
    zgaz356 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__37 >> INT64_C(0)));
    bool zgsz376;
    zgsz376 = (zgaz356 == UINT64_C(0b1100011));
  
    if (!(zgsz376)) {
  
    goto case_57;
    }
    uint64_t zimm4;
    zimm4 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__37 >> INT64_C(31)));
    uint64_t zuz399;
    zuz399 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__37 >> INT64_C(20)));
    uint64_t zuz3100;
    zuz3100 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__37 >> INT64_C(15)));
    uint64_t zimm4shadowz38;
    zimm4shadowz38 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__37 >> INT64_C(31)));
    uint64_t zimm3;
    zimm3 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__37 >> INT64_C(7)));
    uint64_t zuz3101;
    zuz3101 = (safe_rshift(UINT64_MAX, 64 - 6) & (zv__37 >> INT64_C(25)));
    uint64_t zuz3102;
    zuz3102 = (safe_rshift(UINT64_MAX, 64 - 4) & (zv__37 >> INT64_C(8)));
    struct zast zgaz355;
    CREATE(zast)(&zgaz355);
    {
      struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 zgsz375;
      zgsz375.ztup0 = zimm4shadowz38;
      zgsz375.ztup1 = zuz3101;
      zgsz375.ztup2 = zuz399;
      zgsz375.ztup3 = zuz3100;
      zgsz375.ztup4 = zuz3102;
      zgsz375.ztup5 = zimm3;
      zgsz375.ztup6 = zBEQ;
      zBTYPE(&zgaz355, zgsz375);
    
    }
    {
      struct zast zgsz3158;
      CREATE(zast)(&zgsz3158);
      COPY(zast)(&zgsz3158, zgaz355);
      zSomez3z5unionz0zzast(&zgsz337, zgsz3158);
      KILL(zast)(&zgsz3158);
    }
    KILL(zast)(&zgaz355);
  
  
  
  
  
  
  
  
    goto finish_match_41;
  }
case_57: ;
  {
    uint64_t zv__39;
    zv__39 = zmergez3var;
    uint64_t zgaz358;
    zgaz358 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__39 >> INT64_C(0)));
    bool zgsz378;
    zgsz378 = (zgaz358 == UINT64_C(0b1100011));
  
    if (!(zgsz378)) {
  
    goto case_58;
    }
    uint64_t zuz3103;
    zuz3103 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__39 >> INT64_C(31)));
    uint64_t zuz3104;
    zuz3104 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__39 >> INT64_C(20)));
    uint64_t zuz3105;
    zuz3105 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__39 >> INT64_C(15)));
    uint64_t zimm4shadowz39;
    zimm4shadowz39 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__39 >> INT64_C(31)));
    uint64_t zuz3106;
    zuz3106 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__39 >> INT64_C(7)));
    uint64_t zuz3107;
    zuz3107 = (safe_rshift(UINT64_MAX, 64 - 6) & (zv__39 >> INT64_C(25)));
    uint64_t zuz3108;
    zuz3108 = (safe_rshift(UINT64_MAX, 64 - 4) & (zv__39 >> INT64_C(8)));
    struct zast zgaz357;
    CREATE(zast)(&zgaz357);
    {
      struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 zgsz377;
      zgsz377.ztup0 = zimm4shadowz39;
      zgsz377.ztup1 = zuz3107;
      zgsz377.ztup2 = zuz3104;
      zgsz377.ztup3 = zuz3105;
      zgsz377.ztup4 = zuz3108;
      zgsz377.ztup5 = zuz3106;
      zgsz377.ztup6 = zBNE;
      zBTYPE(&zgaz357, zgsz377);
    
    }
    {
      struct zast zgsz3159;
      CREATE(zast)(&zgsz3159);
      COPY(zast)(&zgsz3159, zgaz357);
      zSomez3z5unionz0zzast(&zgsz337, zgsz3159);
      KILL(zast)(&zgsz3159);
    }
    KILL(zast)(&zgaz357);
  
  
  
  
  
  
  
  
    goto finish_match_41;
  }
case_58: ;
  {
    uint64_t zv__41;
    zv__41 = zmergez3var;
    uint64_t zgaz360;
    zgaz360 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__41 >> INT64_C(0)));
    bool zgsz380;
    zgsz380 = (zgaz360 == UINT64_C(0b0110111));
  
    if (!(zgsz380)) {
  
    goto case_59;
    }
    uint64_t zuz3109;
    zuz3109 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__41 >> INT64_C(12)));
    uint64_t zuz3110;
    zuz3110 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__41 >> INT64_C(7)));
    uint64_t zimmshadowz310;
    zimmshadowz310 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__41 >> INT64_C(12)));
    struct zast zgaz359;
    CREATE(zast)(&zgaz359);
    {
      struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 zgsz379;
      zgsz379.ztup0 = zimmshadowz310;
      zgsz379.ztup1 = zuz3110;
      zgsz379.ztup2 = zLUI;
      zUTYPE(&zgaz359, zgsz379);
    
    }
    {
      struct zast zgsz3160;
      CREATE(zast)(&zgsz3160);
      COPY(zast)(&zgsz3160, zgaz359);
      zSomez3z5unionz0zzast(&zgsz337, zgsz3160);
      KILL(zast)(&zgsz3160);
    }
    KILL(zast)(&zgaz359);
  
  
  
  
    goto finish_match_41;
  }
case_59: ;
  {
    uint64_t zv__43;
    zv__43 = zmergez3var;
    uint64_t zgaz362;
    zgaz362 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__43 >> INT64_C(0)));
    bool zgsz382;
    zgsz382 = (zgaz362 == UINT64_C(0b0010111));
  
    if (!(zgsz382)) {
  
    goto case_60;
    }
    uint64_t zuz3111;
    zuz3111 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__43 >> INT64_C(12)));
    uint64_t zuz3112;
    zuz3112 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__43 >> INT64_C(7)));
    uint64_t zimmshadowz311;
    zimmshadowz311 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__43 >> INT64_C(12)));
    struct zast zgaz361;
    CREATE(zast)(&zgaz361);
    {
      struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 zgsz381;
      zgsz381.ztup0 = zimmshadowz311;
      zgsz381.ztup1 = zuz3112;
      zgsz381.ztup2 = zAUIPC;
      zUTYPE(&zgaz361, zgsz381);
    
    }
    {
      struct zast zgsz3161;
      CREATE(zast)(&zgsz3161);
      COPY(zast)(&zgsz3161, zgaz361);
      zSomez3z5unionz0zzast(&zgsz337, zgsz3161);
      KILL(zast)(&zgsz3161);
    }
    KILL(zast)(&zgaz361);
  
  
  
  
    goto finish_match_41;
  }
case_60: ;
  {
    uint64_t zv__45;
    zv__45 = zmergez3var;
    uint64_t zgaz364;
    zgaz364 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__45 >> INT64_C(0)));
    bool zgsz384;
    zgsz384 = (zgaz364 == UINT64_C(0b1101111));
  
    if (!(zgsz384)) {
  
    goto case_61;
    }
    uint64_t zuz3113;
    zuz3113 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__45 >> INT64_C(31)));
    uint64_t zuz3114;
    zuz3114 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__45 >> INT64_C(7)));
    uint64_t zimm4shadowz312;
    zimm4shadowz312 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__45 >> INT64_C(31)));
    uint64_t zuz3115;
    zuz3115 = (safe_rshift(UINT64_MAX, 64 - 8) & (zv__45 >> INT64_C(12)));
    uint64_t zuz3116;
    zuz3116 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__45 >> INT64_C(20)));
    uint64_t zuz3117;
    zuz3117 = (safe_rshift(UINT64_MAX, 64 - 10) & (zv__45 >> INT64_C(21)));
    struct zast zgaz363;
    CREATE(zast)(&zgaz363);
    {
      struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv8zCz0z5bv5zCz0z5enumz0zzjopz9 zgsz383;
      zgsz383.ztup0 = zimm4shadowz312;
      zgsz383.ztup1 = zuz3117;
      zgsz383.ztup2 = zuz3116;
      zgsz383.ztup3 = zuz3115;
      zgsz383.ztup4 = zuz3114;
      zgsz383.ztup5 = zJAL;
      zJTYPE(&zgaz363, zgsz383);
    
    }
    {
      struct zast zgsz3162;
      CREATE(zast)(&zgsz3162);
      COPY(zast)(&zgsz3162, zgaz363);
      zSomez3z5unionz0zzast(&zgsz337, zgsz3162);
      KILL(zast)(&zgsz3162);
    }
    KILL(zast)(&zgaz363);
  
  
  
  
  
  
  
    goto finish_match_41;
  }
case_61: ;
  {
    uint64_t zv__47;
    zv__47 = zmergez3var;
    bool zgsz385;
    zgsz385 = (zv__47 == UINT64_C(0x00100073));
    if (!(zgsz385)) {
  
    goto case_62;
    }
    struct zast zgaz365;
    CREATE(zast)(&zgaz365);
    zEBREAK(&zgaz365, UNIT);
    {
      struct zast zgsz3163;
      CREATE(zast)(&zgsz3163);
      COPY(zast)(&zgsz3163, zgaz365);
      zSomez3z5unionz0zzast(&zgsz337, zgsz3163);
      KILL(zast)(&zgsz3163);
    }
    KILL(zast)(&zgaz365);
  
    goto finish_match_41;
  }
case_62: ;
  sail_match_failure("decode");
finish_match_41: ;
  COPY(zoption)((*(&zcbz36)), zgsz337);
  KILL(zoption)(&zgsz337);
end_function_63: ;
  goto end_function_84;
end_block_exception_64: ;
  goto end_function_84;
end_function_84: ;
}



uint64_t zread_mem(uint64_t);

sail_int zghz317;
sail_int zghz318;
lbits zghz319;
lbits zghz320;
lbits zghz321;
lbits zghz322;
sail_int zghz323;
lbits zghz324;

void startup_zread_mem(void)
{
  CREATE(sail_int)(&zghz317);
  CREATE(sail_int)(&zghz318);
  CREATE(lbits)(&zghz319);
  CREATE(lbits)(&zghz320);
  CREATE(lbits)(&zghz321);
  CREATE(lbits)(&zghz322);
  CREATE(sail_int)(&zghz323);
  CREATE(lbits)(&zghz324);
}

uint64_t zread_mem(uint64_t zaddr)
{
  __label__ end_function_66, end_block_exception_67;

  uint64_t zcbz37;
  uint64_t zgaz366;
  {
    RECREATE(lbits)(&zghz322);
    CONVERT_OF(lbits, fbits)(&zghz322, UINT64_C(0x0), UINT64_C(4) , true);
    RECREATE(sail_int)(&zghz323);
    CONVERT_OF(sail_int, mach_int)(&zghz323, INT64_C(32));
    RECREATE(lbits)(&zghz324);
    zero_extend(&zghz324, zghz322, zghz323);
    zgaz366 = CONVERT_OF(fbits, lbits)(zghz324, true);
  }
  {
    RECREATE(sail_int)(&zghz317);
    CONVERT_OF(sail_int, mach_int)(&zghz317, INT64_C(32));
    RECREATE(sail_int)(&zghz318);
    CONVERT_OF(sail_int, mach_int)(&zghz318, INT64_C(4));
    RECREATE(lbits)(&zghz319);
    CONVERT_OF(lbits, fbits)(&zghz319, zgaz366, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz320);
    CONVERT_OF(lbits, fbits)(&zghz320, zaddr, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz321);
    read_ram(&zghz321, zghz317, zghz318, zghz319, zghz320);
    zcbz37 = CONVERT_OF(fbits, lbits)(zghz321, true);
  }

end_function_66: ;
  return zcbz37;
end_block_exception_67: ;

  return UINT64_C(0xdeadc0de);
}



void finish_zread_mem(void)
{
  KILL(lbits)(&zghz324);
  KILL(sail_int)(&zghz323);
  KILL(lbits)(&zghz322);
  KILL(lbits)(&zghz321);
  KILL(lbits)(&zghz320);
  KILL(lbits)(&zghz319);
  KILL(sail_int)(&zghz318);
  KILL(sail_int)(&zghz317);
}

unit zfde_loop(unit);

lbits zghz325;
lbits zghz326;

void startup_zfde_loop(void)
{
  CREATE(lbits)(&zghz325);
  CREATE(lbits)(&zghz326);
}












unit zfde_loop(unit zgsz394)
{
  __label__ while_69, wend_70, end_function_76, end_block_exception_77;

  unit zcbz38;
  bool zcontinue_loop;
  zcontinue_loop = true;
  bool zgsz3105;
  unit zgsz3106;
while_69: ;
  {
    zgsz3105 = zcontinue_loop;
    if (!(zgsz3105)) goto wend_70;
    uint64_t zinstruction;
    {
      uint64_t zgaz367;
      zgaz367 = *(&zPC);
      zinstruction = zread_mem(zgaz367);
    
    }
    {
      unit zgsz3103;
      {
        RECREATE(lbits)(&zghz326);
        CONVERT_OF(lbits, fbits)(&zghz326, zinstruction, UINT64_C(32) , true);
        zgsz3103 = print_bits("Instruction = ", zghz326);
      }
    }
    {
      __label__ case_72, case_73, case_74, case_75, finish_match_71;

      struct zoption zdecoded_instruction;
      CREATE(zoption)(&zdecoded_instruction);
      zdecode(&zdecoded_instruction, zinstruction);
      unit zgsz395;
      {
        if (zdecoded_instruction.kind != Kind_zSomez3z5unionz0zzast) goto case_72;
        if (zdecoded_instruction.zSomez3z5unionz0zzast.kind != Kind_zEBREAK) goto case_72;
        zcontinue_loop = false;
        zgsz395 = UNIT;
        goto finish_match_71;
      }
    case_72: ;
      {
        if (zdecoded_instruction.kind != Kind_zSomez3z5unionz0zzast) goto case_73;
        struct zast zinst;
        CREATE(zast)(&zinst);
        COPY(zast)(&zinst, zdecoded_instruction.zSomez3z5unionz0zzast);
        zgsz395 = zexecute(zinst);
        KILL(zast)(&zinst);
        goto finish_match_71;
      }
    case_73: ;
      {
        if (zdecoded_instruction.kind != Kind_zNone) goto case_74;
        zgsz395 = print_endline("instruction is None()");
        goto finish_match_71;
      }
    case_74: ;
      {
        zgsz395 = print_endline("decoding the instruction resulted in something unexpected");
        goto finish_match_71;
      }
    case_75: ;
      sail_match_failure("fde_loop");
    finish_match_71: ;
      unit zgsz3102;
      zgsz3102 = zgsz395;
    
      KILL(zoption)(&zdecoded_instruction);
    }
    {
      unit zgsz3100;
      {
        RECREATE(lbits)(&zghz325);
        CONVERT_OF(lbits, fbits)(&zghz325, zPC, UINT64_C(32) , true);
        zgsz3100 = print_bits("PC in fde_loop = ", zghz325);
      }
    }
    zgsz3106 = zinc_PC(UNIT);
  
    goto while_69;
  }
wend_70: ;
  zcbz38 = UNIT;

end_function_76: ;
  return zcbz38;
end_block_exception_77: ;

  return UNIT;
}



void finish_zfde_loop(void)
{
  KILL(lbits)(&zghz326);
  KILL(lbits)(&zghz325);
}

unit zmain(unit);

lbits zghz327;
lbits zghz328;
sail_int zghz329;
sail_int zghz330;
sail_int zghz331;
lbits zghz332;

void startup_zmain(void)
{
  CREATE(lbits)(&zghz327);
  CREATE(lbits)(&zghz328);
  CREATE(sail_int)(&zghz329);
  CREATE(sail_int)(&zghz330);
  CREATE(sail_int)(&zghz331);
  CREATE(lbits)(&zghz332);
}

unit zmain(unit zgsz3107)
{
  __label__ end_function_79, end_block_exception_80;

  unit zcbz39;
  {
    RECREATE(sail_int)(&zghz329);
    elf_entry(&zghz329, UNIT);
    {
      RECREATE(sail_int)(&zghz330);
      CONVERT_OF(sail_int, mach_int)(&zghz330, INT64_C(32));
      RECREATE(sail_int)(&zghz331);
      CONVERT_OF(sail_int, mach_int)(&zghz331, INT64_C(0));
      RECREATE(lbits)(&zghz332);
      get_slice_int(&zghz332, zghz330, zghz329, zghz331);
      zPC = CONVERT_OF(fbits, lbits)(zghz332, true);
    }
    unit zgsz3115;
    zgsz3115 = UNIT;
  }
  {
    unit zgsz3113;
    {
      RECREATE(lbits)(&zghz328);
      CONVERT_OF(lbits, fbits)(&zghz328, zPC, UINT64_C(32) , true);
      zgsz3113 = print_bits("PC = ", zghz328);
    }
  }
  {
    uint64_t zline;
    zline = zread_mem(zPC);
    unit zgsz3111;
    {
      RECREATE(lbits)(&zghz327);
      CONVERT_OF(lbits, fbits)(&zghz327, zline, UINT64_C(32) , true);
      zgsz3111 = print_bits("line = ", zghz327);
    }
  
  }
  zcbz39 = zfde_loop(UNIT);
end_function_79: ;
  return zcbz39;
end_block_exception_80: ;

  return UNIT;
}



void finish_zmain(void)
{
  KILL(lbits)(&zghz332);
  KILL(sail_int)(&zghz331);
  KILL(sail_int)(&zghz330);
  KILL(sail_int)(&zghz329);
  KILL(lbits)(&zghz328);
  KILL(lbits)(&zghz327);
}

unit zinitializze_registers(unit);

sail_int zghz333;
lbits zghz334;
sail_int zghz335;
lbits zghz336;
sail_int zghz337;
lbits zghz338;
sail_int zghz339;
lbits zghz340;
sail_int zghz341;
lbits zghz342;
sail_int zghz343;
lbits zghz344;
sail_int zghz345;
lbits zghz346;
sail_int zghz347;
lbits zghz348;
sail_int zghz349;
lbits zghz350;

void startup_zinitializze_registers(void)
{
  CREATE(sail_int)(&zghz333);
  CREATE(lbits)(&zghz334);
  CREATE(sail_int)(&zghz335);
  CREATE(lbits)(&zghz336);
  CREATE(sail_int)(&zghz337);
  CREATE(lbits)(&zghz338);
  CREATE(sail_int)(&zghz339);
  CREATE(lbits)(&zghz340);
  CREATE(sail_int)(&zghz341);
  CREATE(lbits)(&zghz342);
  CREATE(sail_int)(&zghz343);
  CREATE(lbits)(&zghz344);
  CREATE(sail_int)(&zghz345);
  CREATE(lbits)(&zghz346);
  CREATE(sail_int)(&zghz347);
  CREATE(lbits)(&zghz348);
  CREATE(sail_int)(&zghz349);
  CREATE(lbits)(&zghz350);
}

unit zinitializze_registers(unit zgsz3116)
{
  __label__ end_function_82, end_block_exception_83;

  unit zcbz310;
  {
    {
      RECREATE(sail_int)(&zghz349);
      CONVERT_OF(sail_int, mach_int)(&zghz349, INT64_C(32));
      RECREATE(lbits)(&zghz350);
      UNDEFINED(lbits)(&zghz350, zghz349);
      zPC = CONVERT_OF(fbits, lbits)(zghz350, true);
    }
    unit zgsz3140;
    zgsz3140 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz347);
      CONVERT_OF(sail_int, mach_int)(&zghz347, INT64_C(32));
      RECREATE(lbits)(&zghz348);
      UNDEFINED(lbits)(&zghz348, zghz347);
      zzzero = CONVERT_OF(fbits, lbits)(zghz348, true);
    }
    unit zgsz3139;
    zgsz3139 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz345);
      CONVERT_OF(sail_int, mach_int)(&zghz345, INT64_C(32));
      RECREATE(lbits)(&zghz346);
      UNDEFINED(lbits)(&zghz346, zghz345);
      zra = CONVERT_OF(fbits, lbits)(zghz346, true);
    }
    unit zgsz3138;
    zgsz3138 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz343);
      CONVERT_OF(sail_int, mach_int)(&zghz343, INT64_C(32));
      RECREATE(lbits)(&zghz344);
      UNDEFINED(lbits)(&zghz344, zghz343);
      zsp = CONVERT_OF(fbits, lbits)(zghz344, true);
    }
    unit zgsz3137;
    zgsz3137 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz341);
      CONVERT_OF(sail_int, mach_int)(&zghz341, INT64_C(32));
      RECREATE(lbits)(&zghz342);
      UNDEFINED(lbits)(&zghz342, zghz341);
      zgp = CONVERT_OF(fbits, lbits)(zghz342, true);
    }
    unit zgsz3136;
    zgsz3136 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz339);
      CONVERT_OF(sail_int, mach_int)(&zghz339, INT64_C(32));
      RECREATE(lbits)(&zghz340);
      UNDEFINED(lbits)(&zghz340, zghz339);
      za0 = CONVERT_OF(fbits, lbits)(zghz340, true);
    }
    unit zgsz3135;
    zgsz3135 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz337);
      CONVERT_OF(sail_int, mach_int)(&zghz337, INT64_C(32));
      RECREATE(lbits)(&zghz338);
      UNDEFINED(lbits)(&zghz338, zghz337);
      za1 = CONVERT_OF(fbits, lbits)(zghz338, true);
    }
    unit zgsz3134;
    zgsz3134 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz335);
      CONVERT_OF(sail_int, mach_int)(&zghz335, INT64_C(32));
      RECREATE(lbits)(&zghz336);
      UNDEFINED(lbits)(&zghz336, zghz335);
      za2 = CONVERT_OF(fbits, lbits)(zghz336, true);
    }
    unit zgsz3133;
    zgsz3133 = UNIT;
  }
  {
    RECREATE(sail_int)(&zghz333);
    CONVERT_OF(sail_int, mach_int)(&zghz333, INT64_C(32));
    RECREATE(lbits)(&zghz334);
    UNDEFINED(lbits)(&zghz334, zghz333);
    za3 = CONVERT_OF(fbits, lbits)(zghz334, true);
  }
  zcbz310 = UNIT;
end_function_82: ;
  return zcbz310;
end_block_exception_83: ;

  return UNIT;
}



void finish_zinitializze_registers(void)
{
  KILL(lbits)(&zghz350);
  KILL(sail_int)(&zghz349);
  KILL(lbits)(&zghz348);
  KILL(sail_int)(&zghz347);
  KILL(lbits)(&zghz346);
  KILL(sail_int)(&zghz345);
  KILL(lbits)(&zghz344);
  KILL(sail_int)(&zghz343);
  KILL(lbits)(&zghz342);
  KILL(sail_int)(&zghz341);
  KILL(lbits)(&zghz340);
  KILL(sail_int)(&zghz339);
  KILL(lbits)(&zghz338);
  KILL(sail_int)(&zghz337);
  KILL(lbits)(&zghz336);
  KILL(sail_int)(&zghz335);
  KILL(lbits)(&zghz334);
  KILL(sail_int)(&zghz333);
}

void model_init(void)
{
  setup_rts();
  startup_zsail_mask();
  startup_zsail_ones();
  startup_zfdiv_int();
  startup_zadd_to_PC();
  startup_zinc_PC();
  startup_zread_mem();
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
  finish_zadd_to_PC();
  finish_zinc_PC();
  finish_zread_mem();
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
