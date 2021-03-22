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
  __label__ end_function_4, end_block_exception_5, end_function_167;

  bool zgaz32;
  {
    RECREATE(sail_int)(&zghz30);
    length_lbits(&zghz30, zv);
    zgaz32 = lteq(zlen, zghz30);
  }
  if (zgaz32) {  sail_truncate((*(&zcbz31)), zv, zlen);  } else {  zero_extend((*(&zcbz31)), zv, zlen);  }

end_function_4: ;
  goto end_function_167;
end_block_exception_5: ;
  goto end_function_167;
end_function_167: ;
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
  __label__ end_function_7, end_block_exception_8, end_function_166;

  RECREATE(lbits)(&zghz31);
  zeros(&zghz31, zn);
  not_bits((*(&zcbz32)), zghz31);
end_function_7: ;
  goto end_function_166;
end_block_exception_8: ;
  goto end_function_166;
end_function_166: ;
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
  __label__ end_function_10, end_block_exception_11, end_function_165;

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
  goto end_function_165;
end_block_exception_11: ;
  goto end_function_165;
end_function_165: ;
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
  __label__ end_function_14, end_block_exception_15, end_function_164;

  zero_extend((*(&zcbz34)), zxs, zm);
end_function_14: ;
  goto end_function_164;
end_block_exception_15: ;
  goto end_function_164;
end_function_164: ;
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

bool zgt_bit(lbits, lbits);

sail_int zghz342;
sail_int zghz343;

void startup_zgt_bit(void)
{
  CREATE(sail_int)(&zghz342);
  CREATE(sail_int)(&zghz343);
}

bool zgt_bit(lbits zx, lbits zy)
{
  __label__ end_function_41, end_block_exception_42;

  bool zcbz312;
  RECREATE(sail_int)(&zghz342);
  sail_unsigned(&zghz342, zx);
  RECREATE(sail_int)(&zghz343);
  sail_unsigned(&zghz343, zy);
  zcbz312 = gt(zghz342, zghz343);
end_function_41: ;
  return zcbz312;
end_block_exception_42: ;

  return false;
}



void finish_zgt_bit(void)
{
  KILL(sail_int)(&zghz343);
  KILL(sail_int)(&zghz342);
}

bool zlt_bit(lbits, lbits);

sail_int zghz344;
sail_int zghz345;

void startup_zlt_bit(void)
{
  CREATE(sail_int)(&zghz344);
  CREATE(sail_int)(&zghz345);
}

bool zlt_bit(lbits zx, lbits zy)
{
  __label__ end_function_44, end_block_exception_45;

  bool zcbz313;
  RECREATE(sail_int)(&zghz344);
  sail_unsigned(&zghz344, zx);
  RECREATE(sail_int)(&zghz345);
  sail_unsigned(&zghz345, zy);
  zcbz313 = lt(zghz344, zghz345);
end_function_44: ;
  return zcbz313;
end_block_exception_45: ;

  return false;
}



void finish_zlt_bit(void)
{
  KILL(sail_int)(&zghz345);
  KILL(sail_int)(&zghz344);
}

fbits zxor_bit(fbits, fbits);

fbits zxor_bit(fbits zb1, fbits zb2)
{
  __label__ end_function_47, end_block_exception_48;

  fbits zcbz314;
  bool zgaz325;
  zgaz325 = (zb1 == zb2);
  if (zgaz325) {  zcbz314 = UINT64_C(0);  } else {  zcbz314 = UINT64_C(1);  }

end_function_47: ;
  return zcbz314;
end_block_exception_48: ;

  return UINT64_C(0);
}

void zxor_bitvector(lbits *rop, lbits, lbits);

sail_int zghz346;
lbits zghz347;
sail_int zghz348;
sail_int zghz349;
sail_int zghz350;
sail_int zghz351;
sail_int zghz352;

void startup_zxor_bitvector(void)
{
  CREATE(sail_int)(&zghz346);
  CREATE(lbits)(&zghz347);
  CREATE(sail_int)(&zghz348);
  CREATE(sail_int)(&zghz349);
  CREATE(sail_int)(&zghz350);
  CREATE(sail_int)(&zghz351);
  CREATE(sail_int)(&zghz352);
}

void zxor_bitvector(lbits *zcbz315, lbits zv1, lbits zv2)
{
  __label__ end_function_52, end_block_exception_53, end_function_163;

  RECREATE(sail_int)(&zghz346);
  length_lbits(&zghz346, zv2);
  RECREATE(lbits)(&zghz347);
  zeros(&zghz347, zghz346);
  {
    int64_t zgsz344;
    {    zgsz344 = INT64_C(0);
    }
    int64_t zgsz345;
    {
      {
        RECREATE(sail_int)(&zghz351);
        CONVERT_OF(sail_int, mach_int)(&zghz351, INT64_C(1));
        RECREATE(sail_int)(&zghz352);
        sub_int(&zghz352, zghz346, zghz351);
        zgsz345 = CONVERT_OF(mach_int, sail_int)(zghz352);
      }
    }
    int64_t zgsz346;
    {    zgsz346 = INT64_C(1);
    }
    {
      __label__ for_start_50, for_end_51;

      int64_t zi;
      zi = zgsz344;
      unit zgsz350;
    for_start_50: ;
      {
        if ((zi > zgsz345)) goto for_end_51;
        fbits zb1;
        {
          RECREATE(sail_int)(&zghz350);
          CONVERT_OF(sail_int, mach_int)(&zghz350, zi);
          zb1 = bitvector_access(zv1, zghz350);
        }
        fbits zb2;
        {
          RECREATE(sail_int)(&zghz349);
          CONVERT_OF(sail_int, mach_int)(&zghz349, zi);
          zb2 = bitvector_access(zv2, zghz349);
        }
        fbits zgaz326;
        zgaz326 = zxor_bit(zb1, zb2);
        {
          RECREATE(sail_int)(&zghz348);
          CONVERT_OF(sail_int, mach_int)(&zghz348, zi);
          update_lbits(&zghz347, zghz347, zghz348, zgaz326);
        }
        zgsz350 = UNIT;
      
      
      
        zi = (zi + zgsz346);
        goto for_start_50;
      }
    for_end_51: ;
    }
    unit zgsz353;
    zgsz353 = UNIT;
  }
  COPY(lbits)((*(&zcbz315)), zghz347);
end_function_52: ;
  goto end_function_163;
end_block_exception_53: ;
  goto end_function_163;
end_function_163: ;
}



void finish_zxor_bitvector(void)
{
  KILL(sail_int)(&zghz352);
  KILL(sail_int)(&zghz351);
  KILL(sail_int)(&zghz350);
  KILL(sail_int)(&zghz349);
  KILL(sail_int)(&zghz348);
  KILL(lbits)(&zghz347);
  KILL(sail_int)(&zghz346);
}

bool zxor_bool(bool, bool);

bool zxor_bool(bool zb1, bool zb2)
{
  __label__ end_function_55, end_block_exception_56;

  bool zcbz316;
  bool zgaz327;
  zgaz327 = eq_bool(zb1, zb2);
  if (zgaz327) {  zcbz316 = false;  } else {  zcbz316 = true;  }

end_function_55: ;
  return zcbz316;
end_block_exception_56: ;

  return false;
}

void ztwos_complement(lbits *rop, lbits);

lbits zghz353;
lbits zghz354;
sail_int zghz355;
lbits zghz356;

void startup_ztwos_complement(void)
{
  CREATE(lbits)(&zghz353);
  CREATE(lbits)(&zghz354);
  CREATE(sail_int)(&zghz355);
  CREATE(lbits)(&zghz356);
}

void ztwos_complement(lbits *zcbz317, lbits zv)
{
  __label__ end_function_58, end_block_exception_59, end_function_162;

  RECREATE(lbits)(&zghz353);
  not_bits(&zghz353, zv);
  {
    RECREATE(lbits)(&zghz354);
    {
      RECREATE(sail_int)(&zghz355);
      length_lbits(&zghz355, zv);
      {
        RECREATE(lbits)(&zghz356);
        CONVERT_OF(lbits, fbits)(&zghz356, UINT64_C(0b1), UINT64_C(1) , true);
        zextzz(&zghz354, zghz355, zghz356);
      }
    }
    add_bits(&zghz353, zghz353, zghz354);
    unit zgsz355;
    zgsz355 = UNIT;
  }
  COPY(lbits)((*(&zcbz317)), zghz353);
end_function_58: ;
  goto end_function_162;
end_block_exception_59: ;
  goto end_function_162;
end_function_162: ;
}



void finish_ztwos_complement(void)
{
  KILL(lbits)(&zghz356);
  KILL(sail_int)(&zghz355);
  KILL(lbits)(&zghz354);
  KILL(lbits)(&zghz353);
}

void zabs(lbits *rop, lbits);

sail_int zghz357;
lbits zghz358;
sail_int zghz359;
sail_int zghz360;

void startup_zabs(void)
{
  CREATE(sail_int)(&zghz357);
  CREATE(lbits)(&zghz358);
  CREATE(sail_int)(&zghz359);
  CREATE(sail_int)(&zghz360);
}

void zabs(lbits *zcbz318, lbits zv)
{
  __label__ case_62, case_63, finish_match_61, end_function_64, end_block_exception_65, end_function_161;

  RECREATE(sail_int)(&zghz357);
  {
    RECREATE(sail_int)(&zghz359);
    length_lbits(&zghz359, zv);
    {
      RECREATE(sail_int)(&zghz360);
      CONVERT_OF(sail_int, mach_int)(&zghz360, INT64_C(1));
      sub_int(&zghz357, zghz359, zghz360);
    }
  }
  fbits zgaz330;
  zgaz330 = bitvector_access(zv, zghz357);
  RECREATE(lbits)(&zghz358);
  {
    fbits zp0z3;
    zp0z3 = zgaz330;
    bool zgsz358;
    zgsz358 = eq_bit(zp0z3, UINT64_C(0));
    if (!(zgsz358)) {
  
    goto case_62;
    }
    COPY(lbits)(&zghz358, zv);
  
    goto finish_match_61;
  }
case_62: ;
  {
    fbits zuz30;
    zuz30 = zgaz330;
    bool zgsz359;
    zgsz359 = eq_bit(zuz30, UINT64_C(1));
    if (!(zgsz359)) {
  
    goto case_63;
    }
    ztwos_complement(&zghz358, zv);
  
    goto finish_match_61;
  }
case_63: ;
  sail_match_failure("abs");
finish_match_61: ;
  COPY(lbits)((*(&zcbz318)), zghz358);

end_function_64: ;
  goto end_function_161;
end_block_exception_65: ;
  goto end_function_161;
end_function_161: ;
}



void finish_zabs(void)
{
  KILL(sail_int)(&zghz360);
  KILL(sail_int)(&zghz359);
  KILL(lbits)(&zghz358);
  KILL(sail_int)(&zghz357);
}

void zmul_bitvector(lbits *rop, lbits, lbits);

sail_int zghz361;
lbits zghz362;
lbits zghz363;
lbits zghz364;
sail_int zghz365;
sail_int zghz366;
lbits zghz367;
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
sail_int zghz378;
sail_int zghz379;
sail_int zghz380;
sail_int zghz381;
sail_int zghz382;
sail_int zghz383;
sail_int zghz384;

void startup_zmul_bitvector(void)
{
  CREATE(sail_int)(&zghz361);
  CREATE(lbits)(&zghz362);
  CREATE(lbits)(&zghz363);
  CREATE(lbits)(&zghz364);
  CREATE(sail_int)(&zghz365);
  CREATE(sail_int)(&zghz366);
  CREATE(lbits)(&zghz367);
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
  CREATE(sail_int)(&zghz378);
  CREATE(sail_int)(&zghz379);
  CREATE(sail_int)(&zghz380);
  CREATE(sail_int)(&zghz381);
  CREATE(sail_int)(&zghz382);
  CREATE(sail_int)(&zghz383);
  CREATE(sail_int)(&zghz384);
}

void zmul_bitvector(lbits *zcbz319, lbits zmultiplicand, lbits zmultiplier)
{
  __label__ end_function_72, end_block_exception_73, end_function_160;

  {
    RECREATE(sail_int)(&zghz384);
    sail_signed(&zghz384, zmultiplicand);
    unit zgsz361;
    zgsz361 = print_int("multiplicand = ", zghz384);
  }
  {
    RECREATE(sail_int)(&zghz383);
    sail_signed(&zghz383, zmultiplier);
    unit zgsz360;
    zgsz360 = print_int("mutliplier = ", zghz383);
  }
  RECREATE(sail_int)(&zghz361);
  length_lbits(&zghz361, zmultiplier);
  RECREATE(lbits)(&zghz362);
  {
    RECREATE(sail_int)(&zghz381);
    {
      RECREATE(sail_int)(&zghz382);
      CONVERT_OF(sail_int, mach_int)(&zghz382, INT64_C(2));
      mult_int(&zghz381, zghz382, zghz361);
    }
    sign_extend(&zghz362, zmultiplicand, zghz381);
  }
  RECREATE(lbits)(&zghz363);
  {
    RECREATE(sail_int)(&zghz379);
    {
      RECREATE(sail_int)(&zghz380);
      CONVERT_OF(sail_int, mach_int)(&zghz380, INT64_C(2));
      mult_int(&zghz379, zghz380, zghz361);
    }
    sign_extend(&zghz363, zmultiplier, zghz379);
  }
  RECREATE(lbits)(&zghz364);
  {
    RECREATE(sail_int)(&zghz377);
    {
      RECREATE(sail_int)(&zghz378);
      CONVERT_OF(sail_int, mach_int)(&zghz378, INT64_C(2));
      mult_int(&zghz377, zghz378, zghz361);
    }
    zeros(&zghz364, zghz377);
  }
  {
    RECREATE(sail_int)(&zghz366);
    {
      RECREATE(sail_int)(&zghz376);
      CONVERT_OF(sail_int, mach_int)(&zghz376, INT64_C(1));
      sub_int(&zghz366, zghz361, zghz376);
    }
    int64_t zgsz366;
    {    zgsz366 = INT64_C(0);
    }
    int64_t zgsz367;
    {    zgsz367 = CONVERT_OF(mach_int, sail_int)(zghz366);
    }
    int64_t zgsz368;
    {    zgsz368 = INT64_C(1);
    }
    {
      __label__ for_start_67, for_end_68;

      int64_t zi;
      zi = zgsz366;
      unit zgsz370;
    for_start_67: ;
      {
        if ((zi > zgsz367)) goto for_end_68;
        bool zgaz335;
        {
          fbits zgaz334;
          {
            RECREATE(sail_int)(&zghz375);
            CONVERT_OF(sail_int, mach_int)(&zghz375, zi);
            zgaz334 = bitvector_access(zghz363, zghz375);
          }
          zgaz335 = eq_bit(zgaz334, UINT64_C(1));
        
        }
        if (zgaz335) {
        __label__ case_70, case_71, finish_match_69;

        unit zgsz371;
        {
          RECREATE(sail_int)(&zghz369);
          CONVERT_OF(sail_int, mach_int)(&zghz369, zi);
          RECREATE(sail_int)(&zghz370);
          {
            RECREATE(sail_int)(&zghz374);
            CONVERT_OF(sail_int, mach_int)(&zghz374, INT64_C(1));
            sub_int(&zghz370, zghz361, zghz374);
          }
          bool zgsz374;
          zgsz374 = eq_int(zghz369, zghz370);
          if (!(zgsz374))
            goto case_70;
          RECREATE(lbits)(&zghz371);
          {
            RECREATE(lbits)(&zghz372);
            {
              RECREATE(sail_int)(&zghz373);
              CONVERT_OF(sail_int, mach_int)(&zghz373, zi);
              shiftl(&zghz372, zghz362, zghz373);
            }
            ztwos_complement(&zghz371, zghz372);
          }
          add_bits(&zghz364, zghz364, zghz371);
          zgsz371 = UNIT;
          goto finish_match_69;
        }
      case_70: ;
        {
          RECREATE(lbits)(&zghz367);
          {
            RECREATE(sail_int)(&zghz368);
            CONVERT_OF(sail_int, mach_int)(&zghz368, zi);
            shiftl(&zghz367, zghz362, zghz368);
          }
          add_bits(&zghz364, zghz364, zghz367);
          zgsz371 = UNIT;
          goto finish_match_69;
        }
      case_71: ;
        sail_match_failure("mul_bitvector");
      finish_match_69: ;
        zgsz370 = zgsz371;
      
        } else {  zgsz370 = UNIT;  }
      
        zi = (zi + zgsz368);
        goto for_start_67;
      }
    for_end_68: ;
    }
    unit zgsz378;
    zgsz378 = UNIT;
  }
  {
    RECREATE(sail_int)(&zghz365);
    sail_signed(&zghz365, zghz364);
    unit zgsz377;
    zgsz377 = print_int("result = ", zghz365);
  }
  COPY(lbits)((*(&zcbz319)), zghz364);
end_function_72: ;
  goto end_function_160;
end_block_exception_73: ;
  goto end_function_160;
end_function_160: ;
}



void finish_zmul_bitvector(void)
{
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
  KILL(sail_int)(&zghz374);
  KILL(sail_int)(&zghz373);
  KILL(lbits)(&zghz372);
  KILL(lbits)(&zghz371);
  KILL(sail_int)(&zghz370);
  KILL(sail_int)(&zghz369);
  KILL(sail_int)(&zghz368);
  KILL(lbits)(&zghz367);
  KILL(sail_int)(&zghz366);
  KILL(sail_int)(&zghz365);
  KILL(lbits)(&zghz364);
  KILL(lbits)(&zghz363);
  KILL(lbits)(&zghz362);
  KILL(sail_int)(&zghz361);
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

sail_int zghz385;
lbits zghz386;
lbits zghz387;
lbits zghz388;
lbits zghz389;
sail_int zghz390;
sail_int zghz391;
sail_int zghz392;
sail_int zghz393;
sail_int zghz394;
sail_int zghz395;
sail_int zghz396;
lbits zghz397;
lbits zghz398;
sail_int zghz399;
sail_int zghz3100;
sail_int zghz3101;
sail_int zghz3102;
sail_int zghz3103;
lbits zghz3104;
sail_int zghz3105;
sail_int zghz3106;
lbits zghz3107;
sail_int zghz3108;
sail_int zghz3109;
sail_int zghz3110;
sail_int zghz3111;

void startup_zdiv_bitvector(void)
{
  CREATE(sail_int)(&zghz385);
  CREATE(lbits)(&zghz386);
  CREATE(lbits)(&zghz387);
  CREATE(lbits)(&zghz388);
  CREATE(lbits)(&zghz389);
  CREATE(sail_int)(&zghz390);
  CREATE(sail_int)(&zghz391);
  CREATE(sail_int)(&zghz392);
  CREATE(sail_int)(&zghz393);
  CREATE(sail_int)(&zghz394);
  CREATE(sail_int)(&zghz395);
  CREATE(sail_int)(&zghz396);
  CREATE(lbits)(&zghz397);
  CREATE(lbits)(&zghz398);
  CREATE(sail_int)(&zghz399);
  CREATE(sail_int)(&zghz3100);
  CREATE(sail_int)(&zghz3101);
  CREATE(sail_int)(&zghz3102);
  CREATE(sail_int)(&zghz3103);
  CREATE(lbits)(&zghz3104);
  CREATE(sail_int)(&zghz3105);
  CREATE(sail_int)(&zghz3106);
  CREATE(lbits)(&zghz3107);
  CREATE(sail_int)(&zghz3108);
  CREATE(sail_int)(&zghz3109);
  CREATE(sail_int)(&zghz3110);
  CREATE(sail_int)(&zghz3111);
}

void zdiv_bitvector(struct ztuple_z8z5bvzCz0z5bvz9 *zcbz320, lbits zdividend, lbits zdivisor)
{
  __label__ end_function_77, end_block_exception_78, end_function_159;

  {
    RECREATE(sail_int)(&zghz3111);
    sail_signed(&zghz3111, zdividend);
    unit zgsz380;
    zgsz380 = print_int("dividend = ", zghz3111);
  }
  {
    RECREATE(sail_int)(&zghz3110);
    sail_signed(&zghz3110, zdivisor);
    unit zgsz379;
    zgsz379 = print_int("divisor = ", zghz3110);
  }
  RECREATE(sail_int)(&zghz385);
  length_lbits(&zghz385, zdivisor);
  RECREATE(lbits)(&zghz386);
  {
    RECREATE(lbits)(&zghz3107);
    {
      RECREATE(sail_int)(&zghz3108);
      {
        RECREATE(sail_int)(&zghz3109);
        CONVERT_OF(sail_int, mach_int)(&zghz3109, INT64_C(2));
        mult_int(&zghz3108, zghz3109, zghz385);
      }
      sign_extend(&zghz3107, zdivisor, zghz3108);
    }
    zabs(&zghz386, zghz3107);
  }
  RECREATE(lbits)(&zghz387);
  {
    RECREATE(lbits)(&zghz3104);
    {
      RECREATE(sail_int)(&zghz3105);
      {
        RECREATE(sail_int)(&zghz3106);
        CONVERT_OF(sail_int, mach_int)(&zghz3106, INT64_C(2));
        mult_int(&zghz3105, zghz3106, zghz385);
      }
      sign_extend(&zghz3104, zdividend, zghz3105);
    }
    zabs(&zghz387, zghz3104);
  }
  RECREATE(lbits)(&zghz388);
  {
    RECREATE(sail_int)(&zghz3102);
    {
      RECREATE(sail_int)(&zghz3103);
      CONVERT_OF(sail_int, mach_int)(&zghz3103, INT64_C(2));
      mult_int(&zghz3102, zghz3103, zghz385);
    }
    zeros(&zghz388, zghz3102);
  }
  RECREATE(lbits)(&zghz389);
  {
    RECREATE(sail_int)(&zghz3100);
    {
      RECREATE(sail_int)(&zghz3101);
      CONVERT_OF(sail_int, mach_int)(&zghz3101, INT64_C(2));
      mult_int(&zghz3100, zghz3101, zghz385);
    }
    zeros(&zghz389, zghz3100);
  }
  {
    int64_t zgsz385;
    {    zgsz385 = INT64_C(0);
    }
    int64_t zgsz386;
    {    zgsz386 = CONVERT_OF(mach_int, sail_int)(zghz385);
    }
    int64_t zgsz387;
    {    zgsz387 = INT64_C(1);
    }
    {
      __label__ for_start_75, for_end_76;

      int64_t zi;
      zi = zgsz385;
      unit zgsz392;
    for_start_75: ;
      {
        if ((zi > zgsz386)) goto for_end_76;
        RECREATE(sail_int)(&zghz394);
        {
          RECREATE(sail_int)(&zghz399);
          CONVERT_OF(sail_int, mach_int)(&zghz399, zi);
          sub_int(&zghz394, zghz385, zghz399);
        }
        {
          bool zgaz347;
          {
            RECREATE(lbits)(&zghz398);
            shiftl(&zghz398, zghz386, zghz394);
            zgaz347 = zgt_bit(zghz387, zghz398);
          }
          unit zgsz389;
          if (zgaz347) {
          {
            RECREATE(lbits)(&zghz397);
            shiftl(&zghz397, zghz386, zghz394);
            sub_bits(&zghz387, zghz387, zghz397);
            unit zgsz390;
            zgsz390 = UNIT;
          }
          update_lbits(&zghz388, zghz388, zghz394, UINT64_C(1));
          zgsz389 = UNIT;
          } else {  zgsz389 = UNIT;  }
        
        }
        bool zgaz349;
        {
          RECREATE(sail_int)(&zghz396);
          CONVERT_OF(sail_int, mach_int)(&zghz396, INT64_C(0));
          zgaz349 = eq_int(zghz394, zghz396);
        }
        if (zgaz349) {
        {
          RECREATE(sail_int)(&zghz395);
          CONVERT_OF(sail_int, mach_int)(&zghz395, INT64_C(1));
          replicate_bits(&zghz389, zghz387, zghz395);
        }
        zgsz392 = UNIT;
        } else {  zgsz392 = UNIT;  }
      
        zi = (zi + zgsz387);
        goto for_start_75;
      }
    for_end_76: ;
    }
    unit zgsz399;
    zgsz399 = UNIT;
  }
  {
    RECREATE(sail_int)(&zghz392);
    {
      RECREATE(sail_int)(&zghz393);
      CONVERT_OF(sail_int, mach_int)(&zghz393, INT64_C(1));
      sub_int(&zghz392, zghz385, zghz393);
    }
    bool zgaz354;
    {
      bool zgaz352;
      {
        fbits zgaz350;
        zgaz350 = bitvector_access(zdividend, zghz392);
        zgaz352 = eq_bit(zgaz350, UINT64_C(1));
      
      }
      bool zgaz353;
      {
        fbits zgaz351;
        zgaz351 = bitvector_access(zdivisor, zghz392);
        zgaz353 = eq_bit(zgaz351, UINT64_C(1));
      
      }
      zgaz354 = zxor_bool(zgaz352, zgaz353);
    
    
    }
    unit zgsz397;
    if (zgaz354) {
    {
      ztwos_complement(&zghz388, zghz388);
      unit zgsz398;
      zgsz398 = UNIT;
    }
    ztwos_complement(&zghz389, zghz389);
    zgsz397 = UNIT;
    } else {  zgsz397 = UNIT;  }
  
  }
  {
    RECREATE(sail_int)(&zghz391);
    sail_signed(&zghz391, zghz388);
    unit zgsz396;
    zgsz396 = print_int("quotient = ", zghz391);
  }
  {
    RECREATE(sail_int)(&zghz390);
    sail_signed(&zghz390, zghz389);
    unit zgsz395;
    zgsz395 = print_int("remainder = ", zghz390);
  }
  struct ztuple_z8z5bvzCz0z5bvz9 zgsz3100;
  CREATE(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3100);
  COPY(lbits)(&((&zgsz3100)->ztup0), zghz388);
  COPY(lbits)(&((&zgsz3100)->ztup1), zghz389);
  COPY(ztuple_z8z5bvzCz0z5bvz9)((*(&zcbz320)), zgsz3100);
  KILL(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3100);
end_function_77: ;
  goto end_function_159;
end_block_exception_78: ;
  goto end_function_159;
end_function_159: ;
}



void finish_zdiv_bitvector(void)
{
  KILL(sail_int)(&zghz3111);
  KILL(sail_int)(&zghz3110);
  KILL(sail_int)(&zghz3109);
  KILL(sail_int)(&zghz3108);
  KILL(lbits)(&zghz3107);
  KILL(sail_int)(&zghz3106);
  KILL(sail_int)(&zghz3105);
  KILL(lbits)(&zghz3104);
  KILL(sail_int)(&zghz3103);
  KILL(sail_int)(&zghz3102);
  KILL(sail_int)(&zghz3101);
  KILL(sail_int)(&zghz3100);
  KILL(sail_int)(&zghz399);
  KILL(lbits)(&zghz398);
  KILL(lbits)(&zghz397);
  KILL(sail_int)(&zghz396);
  KILL(sail_int)(&zghz395);
  KILL(sail_int)(&zghz394);
  KILL(sail_int)(&zghz393);
  KILL(sail_int)(&zghz392);
  KILL(sail_int)(&zghz391);
  KILL(sail_int)(&zghz390);
  KILL(lbits)(&zghz389);
  KILL(lbits)(&zghz388);
  KILL(lbits)(&zghz387);
  KILL(lbits)(&zghz386);
  KILL(sail_int)(&zghz385);
}






void zdecode(struct zoption *rop, uint64_t);






unit zexecute(struct zast);

lbits zghz3112;
sail_int zghz3113;
lbits zghz3114;
sail_int zghz3115;
lbits zghz3116;
sail_int zghz3117;
lbits zghz3118;
lbits zghz3119;
sail_int zghz3120;
lbits zghz3121;
lbits zghz3122;
sail_int zghz3123;
lbits zghz3124;
sail_int zghz3125;
lbits zghz3126;
lbits zghz3127;
sail_int zghz3128;
lbits zghz3129;
lbits zghz3130;
sail_int zghz3131;
lbits zghz3132;
lbits zghz3133;
lbits zghz3134;
lbits zghz3135;
lbits zghz3136;
sail_int zghz3137;
lbits zghz3138;
lbits zghz3139;
sail_int zghz3140;
lbits zghz3141;
lbits zghz3142;
sail_int zghz3143;
lbits zghz3144;
lbits zghz3145;
sail_int zghz3146;
lbits zghz3147;
lbits zghz3148;
sail_int zghz3149;
lbits zghz3150;
lbits zghz3151;
sail_int zghz3152;
lbits zghz3153;
lbits zghz3154;
sail_int zghz3155;
lbits zghz3156;
lbits zghz3157;
sail_int zghz3158;
lbits zghz3159;
lbits zghz3160;
lbits zghz3161;
lbits zghz3162;
sail_int zghz3163;
sail_int zghz3164;
sail_int zghz3165;
lbits zghz3166;
lbits zghz3167;
sail_int zghz3168;
sail_int zghz3169;
sail_int zghz3170;
lbits zghz3171;
lbits zghz3172;
sail_int zghz3173;
sail_int zghz3174;
sail_int zghz3175;
lbits zghz3176;
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
lbits zghz3188;
lbits zghz3189;
lbits zghz3190;
sail_int zghz3191;
lbits zghz3192;
lbits zghz3193;
sail_int zghz3194;
lbits zghz3195;
lbits zghz3196;
sail_int zghz3197;
lbits zghz3198;
lbits zghz3199;
sail_int zghz3200;
lbits zghz3201;
lbits zghz3202;
sail_int zghz3203;
lbits zghz3204;
lbits zghz3205;
sail_int zghz3206;
lbits zghz3207;
lbits zghz3208;

void startup_zexecute(void)
{
  CREATE(lbits)(&zghz3112);
  CREATE(sail_int)(&zghz3113);
  CREATE(lbits)(&zghz3114);
  CREATE(sail_int)(&zghz3115);
  CREATE(lbits)(&zghz3116);
  CREATE(sail_int)(&zghz3117);
  CREATE(lbits)(&zghz3118);
  CREATE(lbits)(&zghz3119);
  CREATE(sail_int)(&zghz3120);
  CREATE(lbits)(&zghz3121);
  CREATE(lbits)(&zghz3122);
  CREATE(sail_int)(&zghz3123);
  CREATE(lbits)(&zghz3124);
  CREATE(sail_int)(&zghz3125);
  CREATE(lbits)(&zghz3126);
  CREATE(lbits)(&zghz3127);
  CREATE(sail_int)(&zghz3128);
  CREATE(lbits)(&zghz3129);
  CREATE(lbits)(&zghz3130);
  CREATE(sail_int)(&zghz3131);
  CREATE(lbits)(&zghz3132);
  CREATE(lbits)(&zghz3133);
  CREATE(lbits)(&zghz3134);
  CREATE(lbits)(&zghz3135);
  CREATE(lbits)(&zghz3136);
  CREATE(sail_int)(&zghz3137);
  CREATE(lbits)(&zghz3138);
  CREATE(lbits)(&zghz3139);
  CREATE(sail_int)(&zghz3140);
  CREATE(lbits)(&zghz3141);
  CREATE(lbits)(&zghz3142);
  CREATE(sail_int)(&zghz3143);
  CREATE(lbits)(&zghz3144);
  CREATE(lbits)(&zghz3145);
  CREATE(sail_int)(&zghz3146);
  CREATE(lbits)(&zghz3147);
  CREATE(lbits)(&zghz3148);
  CREATE(sail_int)(&zghz3149);
  CREATE(lbits)(&zghz3150);
  CREATE(lbits)(&zghz3151);
  CREATE(sail_int)(&zghz3152);
  CREATE(lbits)(&zghz3153);
  CREATE(lbits)(&zghz3154);
  CREATE(sail_int)(&zghz3155);
  CREATE(lbits)(&zghz3156);
  CREATE(lbits)(&zghz3157);
  CREATE(sail_int)(&zghz3158);
  CREATE(lbits)(&zghz3159);
  CREATE(lbits)(&zghz3160);
  CREATE(lbits)(&zghz3161);
  CREATE(lbits)(&zghz3162);
  CREATE(sail_int)(&zghz3163);
  CREATE(sail_int)(&zghz3164);
  CREATE(sail_int)(&zghz3165);
  CREATE(lbits)(&zghz3166);
  CREATE(lbits)(&zghz3167);
  CREATE(sail_int)(&zghz3168);
  CREATE(sail_int)(&zghz3169);
  CREATE(sail_int)(&zghz3170);
  CREATE(lbits)(&zghz3171);
  CREATE(lbits)(&zghz3172);
  CREATE(sail_int)(&zghz3173);
  CREATE(sail_int)(&zghz3174);
  CREATE(sail_int)(&zghz3175);
  CREATE(lbits)(&zghz3176);
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
  CREATE(lbits)(&zghz3188);
  CREATE(lbits)(&zghz3189);
  CREATE(lbits)(&zghz3190);
  CREATE(sail_int)(&zghz3191);
  CREATE(lbits)(&zghz3192);
  CREATE(lbits)(&zghz3193);
  CREATE(sail_int)(&zghz3194);
  CREATE(lbits)(&zghz3195);
  CREATE(lbits)(&zghz3196);
  CREATE(sail_int)(&zghz3197);
  CREATE(lbits)(&zghz3198);
  CREATE(lbits)(&zghz3199);
  CREATE(sail_int)(&zghz3200);
  CREATE(lbits)(&zghz3201);
  CREATE(lbits)(&zghz3202);
  CREATE(sail_int)(&zghz3203);
  CREATE(lbits)(&zghz3204);
  CREATE(lbits)(&zghz3205);
  CREATE(sail_int)(&zghz3206);
  CREATE(lbits)(&zghz3207);
  CREATE(lbits)(&zghz3208);
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
  __label__ case_81, case_82, case_86, case_90, case_94, case_95, case_98, case_101, case_102, case_103, case_107, case_111, case_115, case_116, case_117, case_118, case_119, case_120, case_121, case_122, finish_match_80, end_function_123, end_block_exception_124;

  unit zcbz321;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_81;
    uint64_t zrs2;
    zrs2 = zmergez3var.zRTYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zRTYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zRTYPE.ztup2;
    if ((zADD != zmergez3var.zRTYPE.ztup3)) goto case_81;
    uint64_t zrs1_val;
    zrs1_val = zrREG(zrs1);
    uint64_t zrs2_val;
    zrs2_val = zrREG(zrs2);
    uint64_t zresult;
    zresult = ((zrs1_val + zrs2_val) & UINT64_C(0xFFFFFFFF));
    zcbz321 = zwREG(zrd, zresult);
  
  
  
  
  
  
    goto finish_match_80;
  }
case_81: ;
  {
    __label__ case_84, case_85, finish_match_83;

    if (zmergez3var.kind != Kind_zRTYPE) goto case_82;
    uint64_t zuz31;
    zuz31 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz32;
    zuz32 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz33;
    zuz33 = zmergez3var.zRTYPE.ztup2;
    if ((zAND != zmergez3var.zRTYPE.ztup3)) goto case_82;
    uint64_t zuz34;
    zuz34 = zrREG(zuz32);
    uint64_t zuz35;
    zuz35 = zrREG(zuz31);
    uint64_t zbitwise_AND;
    zbitwise_AND = (zuz34 & zuz35);
    {
      uint64_t zvz31;
      zvz31 = zbitwise_AND;
      uint64_t zgaz364;
      {
        RECREATE(sail_int)(&zghz3206);
        CONVERT_OF(sail_int, mach_int)(&zghz3206, INT64_C(32));
        RECREATE(lbits)(&zghz3207);
        CONVERT_OF(lbits, fbits)(&zghz3207, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3208);
        zextzz(&zghz3208, zghz3206, zghz3207);
        zgaz364 = CONVERT_OF(fbits, lbits)(zghz3208, true);
      }
      bool zgsz3110;
      zgsz3110 = (zvz31 == zgaz364);
    
      if (!(zgsz3110)) {
    
      goto case_84;
      }
      uint64_t zgaz363;
      {
        RECREATE(sail_int)(&zghz3203);
        CONVERT_OF(sail_int, mach_int)(&zghz3203, INT64_C(32));
        RECREATE(lbits)(&zghz3204);
        CONVERT_OF(lbits, fbits)(&zghz3204, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3205);
        zextzz(&zghz3205, zghz3203, zghz3204);
        zgaz363 = CONVERT_OF(fbits, lbits)(zghz3205, true);
      }
      zcbz321 = zwREG(zuz33, zgaz363);
    
    
      goto finish_match_83;
    }
  case_84: ;
    {
      uint64_t zgaz365;
      {
        RECREATE(sail_int)(&zghz3200);
        CONVERT_OF(sail_int, mach_int)(&zghz3200, INT64_C(32));
        RECREATE(lbits)(&zghz3201);
        CONVERT_OF(lbits, fbits)(&zghz3201, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3202);
        zextzz(&zghz3202, zghz3200, zghz3201);
        zgaz365 = CONVERT_OF(fbits, lbits)(zghz3202, true);
      }
      zcbz321 = zwREG(zuz33, zgaz365);
    
      goto finish_match_83;
    }
  case_85: ;
    sail_match_failure("execute");
  finish_match_83: ;
  
  
  
  
  
  
    goto finish_match_80;
  }
case_82: ;
  {
    __label__ case_88, case_89, finish_match_87;

    if (zmergez3var.kind != Kind_zRTYPE) goto case_86;
    uint64_t zuz36;
    zuz36 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz37;
    zuz37 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz38;
    zuz38 = zmergez3var.zRTYPE.ztup2;
    if ((zOR != zmergez3var.zRTYPE.ztup3)) goto case_86;
    uint64_t zuz39;
    zuz39 = zrREG(zuz37);
    uint64_t zuz310;
    zuz310 = zrREG(zuz36);
    uint64_t zbitwise_OR;
    zbitwise_OR = (zuz39 | zuz310);
    {
      uint64_t zvz32;
      zvz32 = zbitwise_OR;
      uint64_t zgaz367;
      {
        RECREATE(sail_int)(&zghz3197);
        CONVERT_OF(sail_int, mach_int)(&zghz3197, INT64_C(32));
        RECREATE(lbits)(&zghz3198);
        CONVERT_OF(lbits, fbits)(&zghz3198, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3199);
        zextzz(&zghz3199, zghz3197, zghz3198);
        zgaz367 = CONVERT_OF(fbits, lbits)(zghz3199, true);
      }
      bool zgsz3123;
      zgsz3123 = (zvz32 == zgaz367);
    
      if (!(zgsz3123)) {
    
      goto case_88;
      }
      uint64_t zgaz366;
      {
        RECREATE(sail_int)(&zghz3194);
        CONVERT_OF(sail_int, mach_int)(&zghz3194, INT64_C(32));
        RECREATE(lbits)(&zghz3195);
        CONVERT_OF(lbits, fbits)(&zghz3195, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3196);
        zextzz(&zghz3196, zghz3194, zghz3195);
        zgaz366 = CONVERT_OF(fbits, lbits)(zghz3196, true);
      }
      zcbz321 = zwREG(zuz38, zgaz366);
    
    
      goto finish_match_87;
    }
  case_88: ;
    {
      uint64_t zgaz368;
      {
        RECREATE(sail_int)(&zghz3191);
        CONVERT_OF(sail_int, mach_int)(&zghz3191, INT64_C(32));
        RECREATE(lbits)(&zghz3192);
        CONVERT_OF(lbits, fbits)(&zghz3192, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3193);
        zextzz(&zghz3193, zghz3191, zghz3192);
        zgaz368 = CONVERT_OF(fbits, lbits)(zghz3193, true);
      }
      zcbz321 = zwREG(zuz38, zgaz368);
    
      goto finish_match_87;
    }
  case_89: ;
    sail_match_failure("execute");
  finish_match_87: ;
  
  
  
  
  
  
    goto finish_match_80;
  }
case_86: ;
  {
    __label__ case_92, case_93, finish_match_91;

    if (zmergez3var.kind != Kind_zRTYPE) goto case_90;
    uint64_t zuz311;
    zuz311 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz312;
    zuz312 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz313;
    zuz313 = zmergez3var.zRTYPE.ztup2;
    if ((zXOR != zmergez3var.zRTYPE.ztup3)) goto case_90;
    uint64_t zuz314;
    zuz314 = zrREG(zuz312);
    uint64_t zuz315;
    zuz315 = zrREG(zuz311);
    uint64_t zbitwise_XOR;
    {
      RECREATE(lbits)(&zghz3188);
      CONVERT_OF(lbits, fbits)(&zghz3188, zuz314, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz3189);
      CONVERT_OF(lbits, fbits)(&zghz3189, zuz315, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz3190);
      zxor_bitvector(&zghz3190, zghz3188, zghz3189);
      zbitwise_XOR = CONVERT_OF(fbits, lbits)(zghz3190, true);
    }
    {
      uint64_t zvz33;
      zvz33 = zbitwise_XOR;
      uint64_t zgaz370;
      {
        RECREATE(sail_int)(&zghz3185);
        CONVERT_OF(sail_int, mach_int)(&zghz3185, INT64_C(32));
        RECREATE(lbits)(&zghz3186);
        CONVERT_OF(lbits, fbits)(&zghz3186, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3187);
        zextzz(&zghz3187, zghz3185, zghz3186);
        zgaz370 = CONVERT_OF(fbits, lbits)(zghz3187, true);
      }
      bool zgsz3139;
      zgsz3139 = (zvz33 == zgaz370);
    
      if (!(zgsz3139)) {
    
      goto case_92;
      }
      uint64_t zgaz369;
      {
        RECREATE(sail_int)(&zghz3182);
        CONVERT_OF(sail_int, mach_int)(&zghz3182, INT64_C(32));
        RECREATE(lbits)(&zghz3183);
        CONVERT_OF(lbits, fbits)(&zghz3183, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3184);
        zextzz(&zghz3184, zghz3182, zghz3183);
        zgaz369 = CONVERT_OF(fbits, lbits)(zghz3184, true);
      }
      zcbz321 = zwREG(zuz313, zgaz369);
    
    
      goto finish_match_91;
    }
  case_92: ;
    {
      uint64_t zgaz371;
      {
        RECREATE(sail_int)(&zghz3179);
        CONVERT_OF(sail_int, mach_int)(&zghz3179, INT64_C(32));
        RECREATE(lbits)(&zghz3180);
        CONVERT_OF(lbits, fbits)(&zghz3180, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3181);
        zextzz(&zghz3181, zghz3179, zghz3180);
        zgaz371 = CONVERT_OF(fbits, lbits)(zghz3181, true);
      }
      zcbz321 = zwREG(zuz313, zgaz371);
    
      goto finish_match_91;
    }
  case_93: ;
    sail_match_failure("execute");
  finish_match_91: ;
  
  
  
  
  
  
    goto finish_match_80;
  }
case_90: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_94;
    uint64_t zuz316;
    zuz316 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz317;
    zuz317 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz318;
    zuz318 = zmergez3var.zRTYPE.ztup2;
    if ((zMUL != zmergez3var.zRTYPE.ztup3)) goto case_94;
    uint64_t zmultiplicand;
    zmultiplicand = zrREG(zuz317);
    uint64_t zmultiplier;
    zmultiplier = zrREG(zuz316);
    uint64_t zproduct;
    {
      RECREATE(lbits)(&zghz3176);
      CONVERT_OF(lbits, fbits)(&zghz3176, zmultiplicand, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz3177);
      CONVERT_OF(lbits, fbits)(&zghz3177, zmultiplier, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz3178);
      zmul_bitvector(&zghz3178, zghz3176, zghz3177);
      zproduct = CONVERT_OF(fbits, lbits)(zghz3178, true);
    }
    int64_t zlen;
    {
      RECREATE(sail_int)(&zghz3173);
      CONVERT_OF(sail_int, mach_int)(&zghz3173, INT64_C(32));
      RECREATE(sail_int)(&zghz3174);
      CONVERT_OF(sail_int, mach_int)(&zghz3174, INT64_C(1));
      RECREATE(sail_int)(&zghz3175);
      sub_int(&zghz3175, zghz3173, zghz3174);
      zlen = CONVERT_OF(mach_int, sail_int)(zghz3175);
    }
    uint64_t zuz319;
    zuz319 = (safe_rshift(UINT64_MAX, 64 - 32) & (zproduct >> INT64_C(0)));
    zcbz321 = zwREG(zuz318, zuz319);
  
  
  
  
  
  
  
  
    goto finish_match_80;
  }
case_94: ;
  {
    __label__ case_97, finish_match_96;

    if (zmergez3var.kind != Kind_zRTYPE) goto case_95;
    uint64_t zuz320;
    zuz320 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz321;
    zuz321 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz322;
    zuz322 = zmergez3var.zRTYPE.ztup2;
    if ((zDIV != zmergez3var.zRTYPE.ztup3)) goto case_95;
    uint64_t zdividend;
    zdividend = zrREG(zuz321);
    uint64_t zdivisor;
    zdivisor = zrREG(zuz320);
    struct ztuple_z8z5bv64zCz0z5bv64z9 zgaz372;
    {
      RECREATE(lbits)(&zghz3171);
      CONVERT_OF(lbits, fbits)(&zghz3171, zdividend, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz3172);
      CONVERT_OF(lbits, fbits)(&zghz3172, zdivisor, UINT64_C(32) , true);
      struct ztuple_z8z5bvzCz0z5bvz9 zgsz3154;
      CREATE(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3154);
      zdiv_bitvector(&zgsz3154, zghz3171, zghz3172);
      /* conversions */
      zgaz372.ztup0 = CONVERT_OF(fbits, lbits)(zgsz3154.ztup0, true);
      zgaz372.ztup1 = CONVERT_OF(fbits, lbits)(zgsz3154.ztup1, true);
      /* end conversions */
      KILL(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3154);
    }
    {
      uint64_t zdiv;
      zdiv = zgaz372.ztup0;
      uint64_t zrem;
      zrem = zgaz372.ztup1;
      int64_t zuz323;
      {
        RECREATE(sail_int)(&zghz3168);
        CONVERT_OF(sail_int, mach_int)(&zghz3168, INT64_C(32));
        RECREATE(sail_int)(&zghz3169);
        CONVERT_OF(sail_int, mach_int)(&zghz3169, INT64_C(1));
        RECREATE(sail_int)(&zghz3170);
        sub_int(&zghz3170, zghz3168, zghz3169);
        zuz323 = CONVERT_OF(mach_int, sail_int)(zghz3170);
      }
      uint64_t zuz324;
      zuz324 = (safe_rshift(UINT64_MAX, 64 - 32) & (zdiv >> INT64_C(0)));
      zcbz321 = zwREG(zuz322, zuz324);
    
    
    
    
      goto finish_match_96;
    }
  case_97: ;
    sail_match_failure("execute");
  finish_match_96: ;
  
  
  
  
  
  
    goto finish_match_80;
  }
case_95: ;
  {
    __label__ case_100, finish_match_99;

    if (zmergez3var.kind != Kind_zRTYPE) goto case_98;
    uint64_t zuz325;
    zuz325 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz326;
    zuz326 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz327;
    zuz327 = zmergez3var.zRTYPE.ztup2;
    if ((zREM != zmergez3var.zRTYPE.ztup3)) goto case_98;
    uint64_t zuz328;
    zuz328 = zrREG(zuz326);
    uint64_t zuz329;
    zuz329 = zrREG(zuz325);
    struct ztuple_z8z5bv64zCz0z5bv64z9 zgaz373;
    {
      RECREATE(lbits)(&zghz3166);
      CONVERT_OF(lbits, fbits)(&zghz3166, zuz328, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz3167);
      CONVERT_OF(lbits, fbits)(&zghz3167, zuz329, UINT64_C(32) , true);
      struct ztuple_z8z5bvzCz0z5bvz9 zgsz3163;
      CREATE(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3163);
      zdiv_bitvector(&zgsz3163, zghz3166, zghz3167);
      /* conversions */
      zgaz373.ztup0 = CONVERT_OF(fbits, lbits)(zgsz3163.ztup0, true);
      zgaz373.ztup1 = CONVERT_OF(fbits, lbits)(zgsz3163.ztup1, true);
      /* end conversions */
      KILL(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3163);
    }
    {
      uint64_t zuz330;
      zuz330 = zgaz373.ztup0;
      uint64_t zuz331;
      zuz331 = zgaz373.ztup1;
      int64_t zuz332;
      {
        RECREATE(sail_int)(&zghz3163);
        CONVERT_OF(sail_int, mach_int)(&zghz3163, INT64_C(32));
        RECREATE(sail_int)(&zghz3164);
        CONVERT_OF(sail_int, mach_int)(&zghz3164, INT64_C(1));
        RECREATE(sail_int)(&zghz3165);
        sub_int(&zghz3165, zghz3163, zghz3164);
        zuz332 = CONVERT_OF(mach_int, sail_int)(zghz3165);
      }
      uint64_t zuz333;
      zuz333 = (safe_rshift(UINT64_MAX, 64 - 32) & (zuz331 >> INT64_C(0)));
      zcbz321 = zwREG(zuz327, zuz333);
    
    
    
    
      goto finish_match_99;
    }
  case_100: ;
    sail_match_failure("execute");
  finish_match_99: ;
  
  
  
  
  
  
    goto finish_match_80;
  }
case_98: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_101;
    uint64_t zimm;
    zimm = zmergez3var.zITYPE.ztup0;
    uint64_t zuz334;
    zuz334 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz335;
    zuz335 = zmergez3var.zITYPE.ztup2;
    if ((zADDI != zmergez3var.zITYPE.ztup3)) goto case_101;
    uint64_t zuz336;
    zuz336 = zrREG(zuz334);
    uint64_t zimm_ext;
    {
      sbits zgsz3170;
      zgsz3170 = CONVERT_OF(sbits, fbits)(zimm, UINT64_C(12) , true);
      zimm_ext = zEXTS(zgsz3170);
    
    }
    uint64_t zuz337;
    zuz337 = ((zuz336 + zimm_ext) & UINT64_C(0xFFFFFFFF));
    zcbz321 = zwREG(zuz335, zuz337);
  
  
  
  
  
  
    goto finish_match_80;
  }
case_101: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_102;
    uint64_t zuz338;
    zuz338 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz339;
    zuz339 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz340;
    zuz340 = zmergez3var.zITYPE.ztup2;
    if ((zSLTI != zmergez3var.zITYPE.ztup3)) goto case_102;
    uint64_t zuz341;
    zuz341 = zrREG(zuz339);
    uint64_t zuz342;
    {
      sbits zgsz3172;
      zgsz3172 = CONVERT_OF(sbits, fbits)(zuz338, UINT64_C(12) , true);
      zuz342 = zEXTS(zgsz3172);
    
    }
    bool zgaz374;
    {
      RECREATE(lbits)(&zghz3161);
      CONVERT_OF(lbits, fbits)(&zghz3161, zuz342, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz3162);
      CONVERT_OF(lbits, fbits)(&zghz3162, zuz341, UINT64_C(32) , true);
      zgaz374 = zlt_bit(zghz3162, zghz3161);
    }
    if (zgaz374) {
    uint64_t zgaz375;
    {
      RECREATE(sail_int)(&zghz3158);
      CONVERT_OF(sail_int, mach_int)(&zghz3158, INT64_C(32));
      RECREATE(lbits)(&zghz3159);
      CONVERT_OF(lbits, fbits)(&zghz3159, UINT64_C(0b1), UINT64_C(1) , true);
      RECREATE(lbits)(&zghz3160);
      zextzz(&zghz3160, zghz3158, zghz3159);
      zgaz375 = CONVERT_OF(fbits, lbits)(zghz3160, true);
    }
    zcbz321 = zwREG(zuz340, zgaz375);
  
    } else {
    uint64_t zgaz376;
    {
      RECREATE(sail_int)(&zghz3155);
      CONVERT_OF(sail_int, mach_int)(&zghz3155, INT64_C(32));
      RECREATE(lbits)(&zghz3156);
      CONVERT_OF(lbits, fbits)(&zghz3156, UINT64_C(0b0), UINT64_C(1) , true);
      RECREATE(lbits)(&zghz3157);
      zextzz(&zghz3157, zghz3155, zghz3156);
      zgaz376 = CONVERT_OF(fbits, lbits)(zghz3157, true);
    }
    zcbz321 = zwREG(zuz340, zgaz376);
  
    }
  
  
  
  
  
  
    goto finish_match_80;
  }
case_102: ;
  {
    __label__ case_105, case_106, finish_match_104;

    if (zmergez3var.kind != Kind_zITYPE) goto case_103;
    uint64_t zuz343;
    zuz343 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz344;
    zuz344 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz345;
    zuz345 = zmergez3var.zITYPE.ztup2;
    if ((zANDI != zmergez3var.zITYPE.ztup3)) goto case_103;
    uint64_t zuz346;
    zuz346 = zrREG(zuz344);
    uint64_t zuz347;
    {
      sbits zgsz3182;
      zgsz3182 = CONVERT_OF(sbits, fbits)(zuz343, UINT64_C(12) , true);
      zuz347 = zEXTS(zgsz3182);
    
    }
    uint64_t zuz348;
    zuz348 = (zuz346 & zuz347);
    {
      uint64_t zvz34;
      zvz34 = zuz348;
      uint64_t zgaz378;
      {
        RECREATE(sail_int)(&zghz3152);
        CONVERT_OF(sail_int, mach_int)(&zghz3152, INT64_C(32));
        RECREATE(lbits)(&zghz3153);
        CONVERT_OF(lbits, fbits)(&zghz3153, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3154);
        zextzz(&zghz3154, zghz3152, zghz3153);
        zgaz378 = CONVERT_OF(fbits, lbits)(zghz3154, true);
      }
      bool zgsz3190;
      zgsz3190 = (zvz34 == zgaz378);
    
      if (!(zgsz3190)) {
    
      goto case_105;
      }
      uint64_t zgaz377;
      {
        RECREATE(sail_int)(&zghz3149);
        CONVERT_OF(sail_int, mach_int)(&zghz3149, INT64_C(32));
        RECREATE(lbits)(&zghz3150);
        CONVERT_OF(lbits, fbits)(&zghz3150, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3151);
        zextzz(&zghz3151, zghz3149, zghz3150);
        zgaz377 = CONVERT_OF(fbits, lbits)(zghz3151, true);
      }
      zcbz321 = zwREG(zuz345, zgaz377);
    
    
      goto finish_match_104;
    }
  case_105: ;
    {
      uint64_t zgaz379;
      {
        RECREATE(sail_int)(&zghz3146);
        CONVERT_OF(sail_int, mach_int)(&zghz3146, INT64_C(32));
        RECREATE(lbits)(&zghz3147);
        CONVERT_OF(lbits, fbits)(&zghz3147, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3148);
        zextzz(&zghz3148, zghz3146, zghz3147);
        zgaz379 = CONVERT_OF(fbits, lbits)(zghz3148, true);
      }
      zcbz321 = zwREG(zuz345, zgaz379);
    
      goto finish_match_104;
    }
  case_106: ;
    sail_match_failure("execute");
  finish_match_104: ;
  
  
  
  
  
  
    goto finish_match_80;
  }
case_103: ;
  {
    __label__ case_109, case_110, finish_match_108;

    if (zmergez3var.kind != Kind_zITYPE) goto case_107;
    uint64_t zuz349;
    zuz349 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz350;
    zuz350 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz351;
    zuz351 = zmergez3var.zITYPE.ztup2;
    if ((zORI != zmergez3var.zITYPE.ztup3)) goto case_107;
    uint64_t zuz352;
    zuz352 = zrREG(zuz350);
    uint64_t zuz353;
    {
      sbits zgsz3196;
      zgsz3196 = CONVERT_OF(sbits, fbits)(zuz349, UINT64_C(12) , true);
      zuz353 = zEXTS(zgsz3196);
    
    }
    uint64_t zuz354;
    zuz354 = (zuz352 | zuz353);
    {
      uint64_t zvz35;
      zvz35 = zuz354;
      uint64_t zgaz381;
      {
        RECREATE(sail_int)(&zghz3143);
        CONVERT_OF(sail_int, mach_int)(&zghz3143, INT64_C(32));
        RECREATE(lbits)(&zghz3144);
        CONVERT_OF(lbits, fbits)(&zghz3144, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3145);
        zextzz(&zghz3145, zghz3143, zghz3144);
        zgaz381 = CONVERT_OF(fbits, lbits)(zghz3145, true);
      }
      bool zgsz3204;
      zgsz3204 = (zvz35 == zgaz381);
    
      if (!(zgsz3204)) {
    
      goto case_109;
      }
      uint64_t zgaz380;
      {
        RECREATE(sail_int)(&zghz3140);
        CONVERT_OF(sail_int, mach_int)(&zghz3140, INT64_C(32));
        RECREATE(lbits)(&zghz3141);
        CONVERT_OF(lbits, fbits)(&zghz3141, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3142);
        zextzz(&zghz3142, zghz3140, zghz3141);
        zgaz380 = CONVERT_OF(fbits, lbits)(zghz3142, true);
      }
      zcbz321 = zwREG(zuz351, zgaz380);
    
    
      goto finish_match_108;
    }
  case_109: ;
    {
      uint64_t zgaz382;
      {
        RECREATE(sail_int)(&zghz3137);
        CONVERT_OF(sail_int, mach_int)(&zghz3137, INT64_C(32));
        RECREATE(lbits)(&zghz3138);
        CONVERT_OF(lbits, fbits)(&zghz3138, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3139);
        zextzz(&zghz3139, zghz3137, zghz3138);
        zgaz382 = CONVERT_OF(fbits, lbits)(zghz3139, true);
      }
      zcbz321 = zwREG(zuz351, zgaz382);
    
      goto finish_match_108;
    }
  case_110: ;
    sail_match_failure("execute");
  finish_match_108: ;
  
  
  
  
  
  
    goto finish_match_80;
  }
case_107: ;
  {
    __label__ case_113, case_114, finish_match_112;

    if (zmergez3var.kind != Kind_zITYPE) goto case_111;
    uint64_t zuz355;
    zuz355 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz356;
    zuz356 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz357;
    zuz357 = zmergez3var.zITYPE.ztup2;
    if ((zXORI != zmergez3var.zITYPE.ztup3)) goto case_111;
    uint64_t zuz358;
    zuz358 = zrREG(zuz356);
    uint64_t zuz359;
    {
      sbits zgsz3210;
      zgsz3210 = CONVERT_OF(sbits, fbits)(zuz355, UINT64_C(12) , true);
      zuz359 = zEXTS(zgsz3210);
    
    }
    uint64_t zuz360;
    {
      RECREATE(lbits)(&zghz3134);
      CONVERT_OF(lbits, fbits)(&zghz3134, zuz358, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz3135);
      CONVERT_OF(lbits, fbits)(&zghz3135, zuz359, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz3136);
      zxor_bitvector(&zghz3136, zghz3134, zghz3135);
      zuz360 = CONVERT_OF(fbits, lbits)(zghz3136, true);
    }
    {
      uint64_t zvz36;
      zvz36 = zuz360;
      uint64_t zgaz384;
      {
        RECREATE(sail_int)(&zghz3131);
        CONVERT_OF(sail_int, mach_int)(&zghz3131, INT64_C(32));
        RECREATE(lbits)(&zghz3132);
        CONVERT_OF(lbits, fbits)(&zghz3132, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3133);
        zextzz(&zghz3133, zghz3131, zghz3132);
        zgaz384 = CONVERT_OF(fbits, lbits)(zghz3133, true);
      }
      bool zgsz3221;
      zgsz3221 = (zvz36 == zgaz384);
    
      if (!(zgsz3221)) {
    
      goto case_113;
      }
      uint64_t zgaz383;
      {
        RECREATE(sail_int)(&zghz3128);
        CONVERT_OF(sail_int, mach_int)(&zghz3128, INT64_C(32));
        RECREATE(lbits)(&zghz3129);
        CONVERT_OF(lbits, fbits)(&zghz3129, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3130);
        zextzz(&zghz3130, zghz3128, zghz3129);
        zgaz383 = CONVERT_OF(fbits, lbits)(zghz3130, true);
      }
      zcbz321 = zwREG(zuz357, zgaz383);
    
    
      goto finish_match_112;
    }
  case_113: ;
    {
      uint64_t zgaz385;
      {
        RECREATE(sail_int)(&zghz3125);
        CONVERT_OF(sail_int, mach_int)(&zghz3125, INT64_C(32));
        RECREATE(lbits)(&zghz3126);
        CONVERT_OF(lbits, fbits)(&zghz3126, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz3127);
        zextzz(&zghz3127, zghz3125, zghz3126);
        zgaz385 = CONVERT_OF(fbits, lbits)(zghz3127, true);
      }
      zcbz321 = zwREG(zuz357, zgaz385);
    
      goto finish_match_112;
    }
  case_114: ;
    sail_match_failure("execute");
  finish_match_112: ;
  
  
  
  
  
  
    goto finish_match_80;
  }
case_111: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_115;
    uint64_t zuz361;
    zuz361 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz362;
    zuz362 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz363;
    zuz363 = zmergez3var.zITYPE.ztup2;
    if ((zJALR != zmergez3var.zITYPE.ztup3)) goto case_115;
    {
      uint64_t zgaz386;
      {
        RECREATE(lbits)(&zghz3122);
        CONVERT_OF(lbits, fbits)(&zghz3122, zPC, UINT64_C(32) , true);
        RECREATE(sail_int)(&zghz3123);
        CONVERT_OF(sail_int, mach_int)(&zghz3123, INT64_C(4));
        RECREATE(lbits)(&zghz3124);
        add_bits_int(&zghz3124, zghz3122, zghz3123);
        zgaz386 = CONVERT_OF(fbits, lbits)(zghz3124, true);
      }
      unit zgsz3230;
      zgsz3230 = zwREG(zuz363, zgaz386);
    
    }
    uint64_t zuz364;
    zuz364 = zrREG(zuz362);
    uint64_t zuz365;
    {
      sbits zgsz3231;
      zgsz3231 = CONVERT_OF(sbits, fbits)(zuz361, UINT64_C(12) , true);
      zuz365 = zEXTS(zgsz3231);
    
    }
    uint64_t znewPC;
    znewPC = ((zuz364 + zuz365) & UINT64_C(0xFFFFFFFF));
    {
      {
        RECREATE(lbits)(&zghz3119);
        CONVERT_OF(lbits, fbits)(&zghz3119, znewPC, UINT64_C(32) , true);
        RECREATE(sail_int)(&zghz3120);
        CONVERT_OF(sail_int, mach_int)(&zghz3120, INT64_C(0));
        RECREATE(lbits)(&zghz3121);
        update_lbits(&zghz3121, zghz3119, zghz3120, UINT64_C(0));
        znewPC = CONVERT_OF(fbits, lbits)(zghz3121, true);
      }
      unit zgsz3235;
      zgsz3235 = UNIT;
    }
    zPC = znewPC;
    zcbz321 = UNIT;
  
  
  
  
  
  
    goto finish_match_80;
  }
case_115: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_116;
    uint64_t zuz366;
    zuz366 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz367;
    zuz367 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz368;
    zuz368 = zmergez3var.zITYPE.ztup2;
    if ((zLW != zmergez3var.zITYPE.ztup3)) goto case_116;
    uint64_t zuz369;
    zuz369 = zrREG(zuz367);
    uint64_t zuz370;
    {
      sbits zgsz3237;
      zgsz3237 = CONVERT_OF(sbits, fbits)(zuz366, UINT64_C(12) , true);
      zuz370 = zEXTS(zgsz3237);
    
    }
    uint64_t zaddr;
    zaddr = ((zuz369 + zuz370) & UINT64_C(0xFFFFFFFF));
    uint64_t zmem_val;
    zmem_val = zread_mem(zaddr);
    zcbz321 = zwREG(zuz368, zmem_val);
  
  
  
  
  
  
  
    goto finish_match_80;
  }
case_116: ;
  {
    if (zmergez3var.kind != Kind_zSTYPE) goto case_117;
    uint64_t zimm2;
    zimm2 = zmergez3var.zSTYPE.ztup0;
    uint64_t zuz371;
    zuz371 = zmergez3var.zSTYPE.ztup1;
    uint64_t zuz372;
    zuz372 = zmergez3var.zSTYPE.ztup2;
    uint64_t zimm1;
    zimm1 = zmergez3var.zSTYPE.ztup3;
    if ((zSW != zmergez3var.zSTYPE.ztup4)) goto case_117;
    uint64_t zuz373;
    zuz373 = zrREG(zuz372);
    uint64_t zuz374;
    {
      uint64_t zgaz387;
      zgaz387 = (zimm2 << 5) | zimm1;
      {
        sbits zgsz3239;
        zgsz3239 = CONVERT_OF(sbits, fbits)(zgaz387, UINT64_C(12) , true);
        zuz374 = zEXTS(zgsz3239);
      
      }
    
    }
    uint64_t zuz375;
    zuz375 = ((zuz373 + zuz374) & UINT64_C(0xFFFFFFFF));
    uint64_t zuz376;
    zuz376 = zrREG(zuz371);
    zcbz321 = zwrite_mem(zuz375, zuz376);
  
  
  
  
  
  
  
  
    goto finish_match_80;
  }
case_117: ;
  {
    if (zmergez3var.kind != Kind_zBTYPE) goto case_118;
    uint64_t zimm4;
    zimm4 = zmergez3var.zBTYPE.ztup0;
    uint64_t zuz377;
    zuz377 = zmergez3var.zBTYPE.ztup1;
    uint64_t zuz378;
    zuz378 = zmergez3var.zBTYPE.ztup2;
    uint64_t zuz379;
    zuz379 = zmergez3var.zBTYPE.ztup3;
    uint64_t zuz380;
    zuz380 = zmergez3var.zBTYPE.ztup4;
    uint64_t zimm3;
    zimm3 = zmergez3var.zBTYPE.ztup5;
    if ((zBEQ != zmergez3var.zBTYPE.ztup6)) goto case_118;
    uint64_t zuz381;
    zuz381 = zrREG(zuz379);
    uint64_t zuz382;
    zuz382 = zrREG(zuz378);
    bool zgaz388;
    zgaz388 = (zuz381 == zuz382);
    if (zgaz388) {
    uint64_t zoffset;
    {
      uint64_t zgaz391;
      {
        uint64_t zgaz390;
        {
          uint64_t zgaz389;
          zgaz389 = (zuz377 << 4) | zuz380;
          zgaz390 = (zimm3 << 10) | zgaz389;
        
        }
        zgaz391 = (zimm4 << 11) | zgaz390;
      
      }
      {
        sbits zgsz3242;
        zgsz3242 = CONVERT_OF(sbits, fbits)(zgaz391, UINT64_C(12) , true);
        zoffset = zEXTS(zgsz3242);
      
      }
    
    }
    zPC = ((zPC + zoffset) & UINT64_C(0xFFFFFFFF));
    zcbz321 = UNIT;
  
    } else {  zcbz321 = UNIT;  }
  
  
  
  
  
  
  
  
  
    goto finish_match_80;
  }
case_118: ;
  {
    if (zmergez3var.kind != Kind_zBTYPE) goto case_119;
    uint64_t zuz383;
    zuz383 = zmergez3var.zBTYPE.ztup0;
    uint64_t zuz384;
    zuz384 = zmergez3var.zBTYPE.ztup1;
    uint64_t zuz385;
    zuz385 = zmergez3var.zBTYPE.ztup2;
    uint64_t zuz386;
    zuz386 = zmergez3var.zBTYPE.ztup3;
    uint64_t zuz387;
    zuz387 = zmergez3var.zBTYPE.ztup4;
    uint64_t zuz388;
    zuz388 = zmergez3var.zBTYPE.ztup5;
    if ((zBNE != zmergez3var.zBTYPE.ztup6)) goto case_119;
    uint64_t zuz389;
    zuz389 = zrREG(zuz386);
    uint64_t zuz390;
    zuz390 = zrREG(zuz385);
    bool zgaz392;
    zgaz392 = (zuz389 != zuz390);
    if (zgaz392) {
    uint64_t zuz391;
    {
      uint64_t zgaz395;
      {
        uint64_t zgaz394;
        {
          uint64_t zgaz393;
          zgaz393 = (zuz384 << 4) | zuz387;
          zgaz394 = (zuz388 << 10) | zgaz393;
        
        }
        zgaz395 = (zuz383 << 11) | zgaz394;
      
      }
      {
        sbits zgsz3244;
        zgsz3244 = CONVERT_OF(sbits, fbits)(zgaz395, UINT64_C(12) , true);
        zuz391 = zEXTS(zgsz3244);
      
      }
    
    }
    zPC = ((zPC + zuz391) & UINT64_C(0xFFFFFFFF));
    zcbz321 = UNIT;
  
    } else {  zcbz321 = UNIT;  }
  
  
  
  
  
  
  
  
  
    goto finish_match_80;
  }
case_119: ;
  {
    if (zmergez3var.kind != Kind_zUTYPE) goto case_120;
    uint64_t zuz392;
    zuz392 = zmergez3var.zUTYPE.ztup0;
    uint64_t zuz393;
    zuz393 = zmergez3var.zUTYPE.ztup1;
    if ((zLUI != zmergez3var.zUTYPE.ztup2)) goto case_120;
    uint64_t zgaz397;
    {
      uint64_t zgaz396;
      {
        RECREATE(sail_int)(&zghz3117);
        CONVERT_OF(sail_int, mach_int)(&zghz3117, INT64_C(12));
        RECREATE(lbits)(&zghz3118);
        zeros(&zghz3118, zghz3117);
        zgaz396 = CONVERT_OF(fbits, lbits)(zghz3118, true);
      }
      zgaz397 = (zuz392 << 12) | zgaz396;
    
    }
    zcbz321 = zwREG(zuz393, zgaz397);
  
  
  
    goto finish_match_80;
  }
case_120: ;
  {
    if (zmergez3var.kind != Kind_zUTYPE) goto case_121;
    uint64_t zuz394;
    zuz394 = zmergez3var.zUTYPE.ztup0;
    uint64_t zuz395;
    zuz395 = zmergez3var.zUTYPE.ztup1;
    if ((zAUIPC != zmergez3var.zUTYPE.ztup2)) goto case_121;
    uint64_t zuz396;
    {
      uint64_t zgaz399;
      {
        RECREATE(sail_int)(&zghz3115);
        CONVERT_OF(sail_int, mach_int)(&zghz3115, INT64_C(12));
        RECREATE(lbits)(&zghz3116);
        zeros(&zghz3116, zghz3115);
        zgaz399 = CONVERT_OF(fbits, lbits)(zghz3116, true);
      }
      zuz396 = (zuz394 << 12) | zgaz399;
    
    }
    uint64_t zgaz398;
    zgaz398 = ((zPC + zuz396) & UINT64_C(0xFFFFFFFF));
    zcbz321 = zwREG(zuz395, zgaz398);
  
  
  
  
    goto finish_match_80;
  }
case_121: ;
  {
    if (zmergez3var.kind != Kind_zJTYPE) goto case_122;
    uint64_t zuz397;
    zuz397 = zmergez3var.zJTYPE.ztup0;
    uint64_t zuz398;
    zuz398 = zmergez3var.zJTYPE.ztup1;
    uint64_t zuz399;
    zuz399 = zmergez3var.zJTYPE.ztup2;
    uint64_t zuz3100;
    zuz3100 = zmergez3var.zJTYPE.ztup3;
    uint64_t zuz3101;
    zuz3101 = zmergez3var.zJTYPE.ztup4;
    if ((zJAL != zmergez3var.zJTYPE.ztup5)) goto case_122;
    {
      uint64_t zgaz3100;
      {
        RECREATE(lbits)(&zghz3112);
        CONVERT_OF(lbits, fbits)(&zghz3112, zPC, UINT64_C(32) , true);
        RECREATE(sail_int)(&zghz3113);
        CONVERT_OF(sail_int, mach_int)(&zghz3113, INT64_C(4));
        RECREATE(lbits)(&zghz3114);
        add_bits_int(&zghz3114, zghz3112, zghz3113);
        zgaz3100 = CONVERT_OF(fbits, lbits)(zghz3114, true);
      }
      unit zgsz3254;
      zgsz3254 = zwREG(zuz3101, zgaz3100);
    
    }
    uint64_t zuz3102;
    {
      uint64_t zgaz3103;
      {
        uint64_t zgaz3102;
        {
          uint64_t zgaz3101;
          zgaz3101 = (zuz399 << 10) | zuz398;
          zgaz3102 = (zuz3100 << 11) | zgaz3101;
        
        }
        zgaz3103 = (zuz397 << 19) | zgaz3102;
      
      }
      {
        sbits zgsz3255;
        zgsz3255 = CONVERT_OF(sbits, fbits)(zgaz3103, UINT64_C(20) , true);
        zuz3102 = zEXTS(zgsz3255);
      
      }
    
    }
    zPC = ((zPC + zuz3102) & UINT64_C(0xFFFFFFFF));
    zcbz321 = UNIT;
  
  
  
  
  
  
    goto finish_match_80;
  }
case_122: ;
  sail_match_failure("execute");
finish_match_80: ;
end_function_123: ;
  return zcbz321;
end_block_exception_124: ;

  return UNIT;
}



void finish_zexecute(void)
{
  KILL(lbits)(&zghz3208);
  KILL(lbits)(&zghz3207);
  KILL(sail_int)(&zghz3206);
  KILL(lbits)(&zghz3205);
  KILL(lbits)(&zghz3204);
  KILL(sail_int)(&zghz3203);
  KILL(lbits)(&zghz3202);
  KILL(lbits)(&zghz3201);
  KILL(sail_int)(&zghz3200);
  KILL(lbits)(&zghz3199);
  KILL(lbits)(&zghz3198);
  KILL(sail_int)(&zghz3197);
  KILL(lbits)(&zghz3196);
  KILL(lbits)(&zghz3195);
  KILL(sail_int)(&zghz3194);
  KILL(lbits)(&zghz3193);
  KILL(lbits)(&zghz3192);
  KILL(sail_int)(&zghz3191);
  KILL(lbits)(&zghz3190);
  KILL(lbits)(&zghz3189);
  KILL(lbits)(&zghz3188);
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
  KILL(lbits)(&zghz3176);
  KILL(sail_int)(&zghz3175);
  KILL(sail_int)(&zghz3174);
  KILL(sail_int)(&zghz3173);
  KILL(lbits)(&zghz3172);
  KILL(lbits)(&zghz3171);
  KILL(sail_int)(&zghz3170);
  KILL(sail_int)(&zghz3169);
  KILL(sail_int)(&zghz3168);
  KILL(lbits)(&zghz3167);
  KILL(lbits)(&zghz3166);
  KILL(sail_int)(&zghz3165);
  KILL(sail_int)(&zghz3164);
  KILL(sail_int)(&zghz3163);
  KILL(lbits)(&zghz3162);
  KILL(lbits)(&zghz3161);
  KILL(lbits)(&zghz3160);
  KILL(lbits)(&zghz3159);
  KILL(sail_int)(&zghz3158);
  KILL(lbits)(&zghz3157);
  KILL(lbits)(&zghz3156);
  KILL(sail_int)(&zghz3155);
  KILL(lbits)(&zghz3154);
  KILL(lbits)(&zghz3153);
  KILL(sail_int)(&zghz3152);
  KILL(lbits)(&zghz3151);
  KILL(lbits)(&zghz3150);
  KILL(sail_int)(&zghz3149);
  KILL(lbits)(&zghz3148);
  KILL(lbits)(&zghz3147);
  KILL(sail_int)(&zghz3146);
  KILL(lbits)(&zghz3145);
  KILL(lbits)(&zghz3144);
  KILL(sail_int)(&zghz3143);
  KILL(lbits)(&zghz3142);
  KILL(lbits)(&zghz3141);
  KILL(sail_int)(&zghz3140);
  KILL(lbits)(&zghz3139);
  KILL(lbits)(&zghz3138);
  KILL(sail_int)(&zghz3137);
  KILL(lbits)(&zghz3136);
  KILL(lbits)(&zghz3135);
  KILL(lbits)(&zghz3134);
  KILL(lbits)(&zghz3133);
  KILL(lbits)(&zghz3132);
  KILL(sail_int)(&zghz3131);
  KILL(lbits)(&zghz3130);
  KILL(lbits)(&zghz3129);
  KILL(sail_int)(&zghz3128);
  KILL(lbits)(&zghz3127);
  KILL(lbits)(&zghz3126);
  KILL(sail_int)(&zghz3125);
  KILL(lbits)(&zghz3124);
  KILL(sail_int)(&zghz3123);
  KILL(lbits)(&zghz3122);
  KILL(lbits)(&zghz3121);
  KILL(sail_int)(&zghz3120);
  KILL(lbits)(&zghz3119);
  KILL(lbits)(&zghz3118);
  KILL(sail_int)(&zghz3117);
  KILL(lbits)(&zghz3116);
  KILL(sail_int)(&zghz3115);
  KILL(lbits)(&zghz3114);
  KILL(sail_int)(&zghz3113);
  KILL(lbits)(&zghz3112);
}


















void zdecode(struct zoption *zcbz322, uint64_t zmergez3var)
{
  __label__ case_127, case_128, case_129, case_130, case_131, case_132, case_133, case_134, case_135, case_136, case_137, case_138, case_139, case_140, case_141, case_142, case_143, case_144, case_145, case_146, case_147, finish_match_126, end_function_148, end_block_exception_149, end_function_158;

  struct zoption zgsz3257;
  CREATE(zoption)(&zgsz3257);
  {
    uint64_t zv__0;
    zv__0 = zmergez3var;
    bool zgaz3107;
    {
      uint64_t zgaz3105;
      zgaz3105 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__0 >> INT64_C(25)));
      zgaz3107 = (zgaz3105 == UINT64_C(0b0000000));
    
    }
    bool zgsz3258;
    if (zgaz3107) {
    uint64_t zgaz3106;
    zgaz3106 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__0 >> INT64_C(0)));
    zgsz3258 = (zgaz3106 == UINT64_C(0b0110011));
  
    } else {  zgsz3258 = false;  }
    bool zgsz3260;
    zgsz3260 = zgsz3258;
  
    if (!(zgsz3260)) {
  
    goto case_127;
    }
    uint64_t zrs2;
    zrs2 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(20)));
    uint64_t zrs1;
    zrs1 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(15)));
    uint64_t zrd;
    zrd = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(7)));
    struct zast zgaz3104;
    CREATE(zast)(&zgaz3104);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3259;
      zgsz3259.ztup0 = zrs2;
      zgsz3259.ztup1 = zrs1;
      zgsz3259.ztup2 = zrd;
      zgsz3259.ztup3 = zADD;
      zRTYPE(&zgaz3104, zgsz3259);
    
    }
    {
      struct zast zgsz3361;
      CREATE(zast)(&zgsz3361);
      COPY(zast)(&zgsz3361, zgaz3104);
      zSomez3z5unionz0zzast(&zgsz3257, zgsz3361);
      KILL(zast)(&zgsz3361);
    }
    KILL(zast)(&zgaz3104);
  
  
  
  
    goto finish_match_126;
  }
case_127: ;
  {
    uint64_t zv__3;
    zv__3 = zmergez3var;
    bool zgaz3111;
    {
      uint64_t zgaz3109;
      zgaz3109 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__3 >> INT64_C(25)));
      zgaz3111 = (zgaz3109 == UINT64_C(0b0000000));
    
    }
    bool zgsz3261;
    if (zgaz3111) {
    uint64_t zgaz3110;
    zgaz3110 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__3 >> INT64_C(0)));
    zgsz3261 = (zgaz3110 == UINT64_C(0b0110011));
  
    } else {  zgsz3261 = false;  }
    bool zgsz3263;
    zgsz3263 = zgsz3261;
  
    if (!(zgsz3263)) {
  
    goto case_128;
    }
    uint64_t zuz3103;
    zuz3103 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(20)));
    uint64_t zuz3104;
    zuz3104 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(15)));
    uint64_t zuz3105;
    zuz3105 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(7)));
    struct zast zgaz3108;
    CREATE(zast)(&zgaz3108);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3262;
      zgsz3262.ztup0 = zuz3103;
      zgsz3262.ztup1 = zuz3104;
      zgsz3262.ztup2 = zuz3105;
      zgsz3262.ztup3 = zAND;
      zRTYPE(&zgaz3108, zgsz3262);
    
    }
    {
      struct zast zgsz3362;
      CREATE(zast)(&zgsz3362);
      COPY(zast)(&zgsz3362, zgaz3108);
      zSomez3z5unionz0zzast(&zgsz3257, zgsz3362);
      KILL(zast)(&zgsz3362);
    }
    KILL(zast)(&zgaz3108);
  
  
  
  
    goto finish_match_126;
  }
case_128: ;
  {
    uint64_t zv__6;
    zv__6 = zmergez3var;
    bool zgaz3115;
    {
      uint64_t zgaz3113;
      zgaz3113 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__6 >> INT64_C(25)));
      zgaz3115 = (zgaz3113 == UINT64_C(0b0000000));
    
    }
    bool zgsz3264;
    if (zgaz3115) {
    uint64_t zgaz3114;
    zgaz3114 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__6 >> INT64_C(0)));
    zgsz3264 = (zgaz3114 == UINT64_C(0b0110011));
  
    } else {  zgsz3264 = false;  }
    bool zgsz3266;
    zgsz3266 = zgsz3264;
  
    if (!(zgsz3266)) {
  
    goto case_129;
    }
    uint64_t zuz3106;
    zuz3106 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(20)));
    uint64_t zuz3107;
    zuz3107 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(15)));
    uint64_t zuz3108;
    zuz3108 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(7)));
    struct zast zgaz3112;
    CREATE(zast)(&zgaz3112);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3265;
      zgsz3265.ztup0 = zuz3106;
      zgsz3265.ztup1 = zuz3107;
      zgsz3265.ztup2 = zuz3108;
      zgsz3265.ztup3 = zOR;
      zRTYPE(&zgaz3112, zgsz3265);
    
    }
    {
      struct zast zgsz3363;
      CREATE(zast)(&zgsz3363);
      COPY(zast)(&zgsz3363, zgaz3112);
      zSomez3z5unionz0zzast(&zgsz3257, zgsz3363);
      KILL(zast)(&zgsz3363);
    }
    KILL(zast)(&zgaz3112);
  
  
  
  
    goto finish_match_126;
  }
case_129: ;
  {
    uint64_t zv__9;
    zv__9 = zmergez3var;
    bool zgaz3119;
    {
      uint64_t zgaz3117;
      zgaz3117 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__9 >> INT64_C(25)));
      zgaz3119 = (zgaz3117 == UINT64_C(0b0000000));
    
    }
    bool zgsz3267;
    if (zgaz3119) {
    uint64_t zgaz3118;
    zgaz3118 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__9 >> INT64_C(0)));
    zgsz3267 = (zgaz3118 == UINT64_C(0b0110011));
  
    } else {  zgsz3267 = false;  }
    bool zgsz3269;
    zgsz3269 = zgsz3267;
  
    if (!(zgsz3269)) {
  
    goto case_130;
    }
    uint64_t zuz3109;
    zuz3109 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(20)));
    uint64_t zuz3110;
    zuz3110 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(15)));
    uint64_t zuz3111;
    zuz3111 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(7)));
    struct zast zgaz3116;
    CREATE(zast)(&zgaz3116);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3268;
      zgsz3268.ztup0 = zuz3109;
      zgsz3268.ztup1 = zuz3110;
      zgsz3268.ztup2 = zuz3111;
      zgsz3268.ztup3 = zXOR;
      zRTYPE(&zgaz3116, zgsz3268);
    
    }
    {
      struct zast zgsz3364;
      CREATE(zast)(&zgsz3364);
      COPY(zast)(&zgsz3364, zgaz3116);
      zSomez3z5unionz0zzast(&zgsz3257, zgsz3364);
      KILL(zast)(&zgsz3364);
    }
    KILL(zast)(&zgaz3116);
  
  
  
  
    goto finish_match_126;
  }
case_130: ;
  {
    uint64_t zv__12;
    zv__12 = zmergez3var;
    bool zgaz3123;
    {
      uint64_t zgaz3121;
      zgaz3121 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__12 >> INT64_C(25)));
      zgaz3123 = (zgaz3121 == UINT64_C(0b0000001));
    
    }
    bool zgsz3270;
    if (zgaz3123) {
    uint64_t zgaz3122;
    zgaz3122 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__12 >> INT64_C(0)));
    zgsz3270 = (zgaz3122 == UINT64_C(0b0110011));
  
    } else {  zgsz3270 = false;  }
    bool zgsz3272;
    zgsz3272 = zgsz3270;
  
    if (!(zgsz3272)) {
  
    goto case_131;
    }
    uint64_t zuz3112;
    zuz3112 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(20)));
    uint64_t zuz3113;
    zuz3113 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(15)));
    uint64_t zuz3114;
    zuz3114 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(7)));
    struct zast zgaz3120;
    CREATE(zast)(&zgaz3120);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3271;
      zgsz3271.ztup0 = zuz3112;
      zgsz3271.ztup1 = zuz3113;
      zgsz3271.ztup2 = zuz3114;
      zgsz3271.ztup3 = zMUL;
      zRTYPE(&zgaz3120, zgsz3271);
    
    }
    {
      struct zast zgsz3365;
      CREATE(zast)(&zgsz3365);
      COPY(zast)(&zgsz3365, zgaz3120);
      zSomez3z5unionz0zzast(&zgsz3257, zgsz3365);
      KILL(zast)(&zgsz3365);
    }
    KILL(zast)(&zgaz3120);
  
  
  
  
    goto finish_match_126;
  }
case_131: ;
  {
    uint64_t zv__15;
    zv__15 = zmergez3var;
    bool zgaz3127;
    {
      uint64_t zgaz3125;
      zgaz3125 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__15 >> INT64_C(25)));
      zgaz3127 = (zgaz3125 == UINT64_C(0b0000001));
    
    }
    bool zgsz3273;
    if (zgaz3127) {
    uint64_t zgaz3126;
    zgaz3126 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__15 >> INT64_C(0)));
    zgsz3273 = (zgaz3126 == UINT64_C(0b0110011));
  
    } else {  zgsz3273 = false;  }
    bool zgsz3275;
    zgsz3275 = zgsz3273;
  
    if (!(zgsz3275)) {
  
    goto case_132;
    }
    uint64_t zuz3115;
    zuz3115 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(20)));
    uint64_t zuz3116;
    zuz3116 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(15)));
    uint64_t zuz3117;
    zuz3117 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(7)));
    struct zast zgaz3124;
    CREATE(zast)(&zgaz3124);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3274;
      zgsz3274.ztup0 = zuz3115;
      zgsz3274.ztup1 = zuz3116;
      zgsz3274.ztup2 = zuz3117;
      zgsz3274.ztup3 = zDIV;
      zRTYPE(&zgaz3124, zgsz3274);
    
    }
    {
      struct zast zgsz3366;
      CREATE(zast)(&zgsz3366);
      COPY(zast)(&zgsz3366, zgaz3124);
      zSomez3z5unionz0zzast(&zgsz3257, zgsz3366);
      KILL(zast)(&zgsz3366);
    }
    KILL(zast)(&zgaz3124);
  
  
  
  
    goto finish_match_126;
  }
case_132: ;
  {
    uint64_t zv__18;
    zv__18 = zmergez3var;
    bool zgaz3131;
    {
      uint64_t zgaz3129;
      zgaz3129 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__18 >> INT64_C(25)));
      zgaz3131 = (zgaz3129 == UINT64_C(0b0000001));
    
    }
    bool zgsz3276;
    if (zgaz3131) {
    uint64_t zgaz3130;
    zgaz3130 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__18 >> INT64_C(0)));
    zgsz3276 = (zgaz3130 == UINT64_C(0b0110011));
  
    } else {  zgsz3276 = false;  }
    bool zgsz3278;
    zgsz3278 = zgsz3276;
  
    if (!(zgsz3278)) {
  
    goto case_133;
    }
    uint64_t zuz3118;
    zuz3118 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(20)));
    uint64_t zuz3119;
    zuz3119 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(15)));
    uint64_t zuz3120;
    zuz3120 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(7)));
    struct zast zgaz3128;
    CREATE(zast)(&zgaz3128);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3277;
      zgsz3277.ztup0 = zuz3118;
      zgsz3277.ztup1 = zuz3119;
      zgsz3277.ztup2 = zuz3120;
      zgsz3277.ztup3 = zREM;
      zRTYPE(&zgaz3128, zgsz3277);
    
    }
    {
      struct zast zgsz3367;
      CREATE(zast)(&zgsz3367);
      COPY(zast)(&zgsz3367, zgaz3128);
      zSomez3z5unionz0zzast(&zgsz3257, zgsz3367);
      KILL(zast)(&zgsz3367);
    }
    KILL(zast)(&zgaz3128);
  
  
  
  
    goto finish_match_126;
  }
case_133: ;
  {
    uint64_t zv__21;
    zv__21 = zmergez3var;
    uint64_t zgaz3133;
    zgaz3133 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__21 >> INT64_C(0)));
    bool zgsz3280;
    zgsz3280 = (zgaz3133 == UINT64_C(0b0010011));
  
    if (!(zgsz3280)) {
  
    goto case_134;
    }
    uint64_t zimm;
    zimm = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__21 >> INT64_C(20)));
    uint64_t zuz3121;
    zuz3121 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__21 >> INT64_C(15)));
    uint64_t zuz3122;
    zuz3122 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__21 >> INT64_C(7)));
    uint64_t zimmshadowz31;
    zimmshadowz31 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__21 >> INT64_C(20)));
    struct zast zgaz3132;
    CREATE(zast)(&zgaz3132);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3279;
      zgsz3279.ztup0 = zimmshadowz31;
      zgsz3279.ztup1 = zuz3121;
      zgsz3279.ztup2 = zuz3122;
      zgsz3279.ztup3 = zADDI;
      zITYPE(&zgaz3132, zgsz3279);
    
    }
    {
      struct zast zgsz3368;
      CREATE(zast)(&zgsz3368);
      COPY(zast)(&zgsz3368, zgaz3132);
      zSomez3z5unionz0zzast(&zgsz3257, zgsz3368);
      KILL(zast)(&zgsz3368);
    }
    KILL(zast)(&zgaz3132);
  
  
  
  
  
    goto finish_match_126;
  }
case_134: ;
  {
    uint64_t zv__23;
    zv__23 = zmergez3var;
    uint64_t zgaz3135;
    zgaz3135 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__23 >> INT64_C(0)));
    bool zgsz3282;
    zgsz3282 = (zgaz3135 == UINT64_C(0b0010011));
  
    if (!(zgsz3282)) {
  
    goto case_135;
    }
    uint64_t zuz3123;
    zuz3123 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__23 >> INT64_C(20)));
    uint64_t zuz3124;
    zuz3124 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__23 >> INT64_C(15)));
    uint64_t zuz3125;
    zuz3125 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__23 >> INT64_C(7)));
    uint64_t zimmshadowz32;
    zimmshadowz32 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__23 >> INT64_C(20)));
    struct zast zgaz3134;
    CREATE(zast)(&zgaz3134);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3281;
      zgsz3281.ztup0 = zimmshadowz32;
      zgsz3281.ztup1 = zuz3124;
      zgsz3281.ztup2 = zuz3125;
      zgsz3281.ztup3 = zSLTI;
      zITYPE(&zgaz3134, zgsz3281);
    
    }
    {
      struct zast zgsz3369;
      CREATE(zast)(&zgsz3369);
      COPY(zast)(&zgsz3369, zgaz3134);
      zSomez3z5unionz0zzast(&zgsz3257, zgsz3369);
      KILL(zast)(&zgsz3369);
    }
    KILL(zast)(&zgaz3134);
  
  
  
  
  
    goto finish_match_126;
  }
case_135: ;
  {
    uint64_t zv__25;
    zv__25 = zmergez3var;
    uint64_t zgaz3137;
    zgaz3137 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__25 >> INT64_C(0)));
    bool zgsz3284;
    zgsz3284 = (zgaz3137 == UINT64_C(0b0010011));
  
    if (!(zgsz3284)) {
  
    goto case_136;
    }
    uint64_t zuz3126;
    zuz3126 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__25 >> INT64_C(20)));
    uint64_t zuz3127;
    zuz3127 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__25 >> INT64_C(15)));
    uint64_t zuz3128;
    zuz3128 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__25 >> INT64_C(7)));
    uint64_t zimmshadowz33;
    zimmshadowz33 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__25 >> INT64_C(20)));
    struct zast zgaz3136;
    CREATE(zast)(&zgaz3136);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3283;
      zgsz3283.ztup0 = zimmshadowz33;
      zgsz3283.ztup1 = zuz3127;
      zgsz3283.ztup2 = zuz3128;
      zgsz3283.ztup3 = zANDI;
      zITYPE(&zgaz3136, zgsz3283);
    
    }
    {
      struct zast zgsz3370;
      CREATE(zast)(&zgsz3370);
      COPY(zast)(&zgsz3370, zgaz3136);
      zSomez3z5unionz0zzast(&zgsz3257, zgsz3370);
      KILL(zast)(&zgsz3370);
    }
    KILL(zast)(&zgaz3136);
  
  
  
  
  
    goto finish_match_126;
  }
case_136: ;
  {
    uint64_t zv__27;
    zv__27 = zmergez3var;
    uint64_t zgaz3139;
    zgaz3139 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__27 >> INT64_C(0)));
    bool zgsz3286;
    zgsz3286 = (zgaz3139 == UINT64_C(0b0010011));
  
    if (!(zgsz3286)) {
  
    goto case_137;
    }
    uint64_t zuz3129;
    zuz3129 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__27 >> INT64_C(20)));
    uint64_t zuz3130;
    zuz3130 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__27 >> INT64_C(15)));
    uint64_t zuz3131;
    zuz3131 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__27 >> INT64_C(7)));
    uint64_t zimmshadowz34;
    zimmshadowz34 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__27 >> INT64_C(20)));
    struct zast zgaz3138;
    CREATE(zast)(&zgaz3138);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3285;
      zgsz3285.ztup0 = zimmshadowz34;
      zgsz3285.ztup1 = zuz3130;
      zgsz3285.ztup2 = zuz3131;
      zgsz3285.ztup3 = zORI;
      zITYPE(&zgaz3138, zgsz3285);
    
    }
    {
      struct zast zgsz3371;
      CREATE(zast)(&zgsz3371);
      COPY(zast)(&zgsz3371, zgaz3138);
      zSomez3z5unionz0zzast(&zgsz3257, zgsz3371);
      KILL(zast)(&zgsz3371);
    }
    KILL(zast)(&zgaz3138);
  
  
  
  
  
    goto finish_match_126;
  }
case_137: ;
  {
    uint64_t zv__29;
    zv__29 = zmergez3var;
    uint64_t zgaz3141;
    zgaz3141 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__29 >> INT64_C(0)));
    bool zgsz3288;
    zgsz3288 = (zgaz3141 == UINT64_C(0b0010011));
  
    if (!(zgsz3288)) {
  
    goto case_138;
    }
    uint64_t zuz3132;
    zuz3132 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__29 >> INT64_C(20)));
    uint64_t zuz3133;
    zuz3133 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__29 >> INT64_C(15)));
    uint64_t zuz3134;
    zuz3134 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__29 >> INT64_C(7)));
    uint64_t zimmshadowz35;
    zimmshadowz35 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__29 >> INT64_C(20)));
    struct zast zgaz3140;
    CREATE(zast)(&zgaz3140);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3287;
      zgsz3287.ztup0 = zimmshadowz35;
      zgsz3287.ztup1 = zuz3133;
      zgsz3287.ztup2 = zuz3134;
      zgsz3287.ztup3 = zXORI;
      zITYPE(&zgaz3140, zgsz3287);
    
    }
    {
      struct zast zgsz3372;
      CREATE(zast)(&zgsz3372);
      COPY(zast)(&zgsz3372, zgaz3140);
      zSomez3z5unionz0zzast(&zgsz3257, zgsz3372);
      KILL(zast)(&zgsz3372);
    }
    KILL(zast)(&zgaz3140);
  
  
  
  
  
    goto finish_match_126;
  }
case_138: ;
  {
    uint64_t zv__31;
    zv__31 = zmergez3var;
    uint64_t zgaz3143;
    zgaz3143 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__31 >> INT64_C(0)));
    bool zgsz3290;
    zgsz3290 = (zgaz3143 == UINT64_C(0b1100111));
  
    if (!(zgsz3290)) {
  
    goto case_139;
    }
    uint64_t zuz3135;
    zuz3135 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__31 >> INT64_C(20)));
    uint64_t zuz3136;
    zuz3136 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__31 >> INT64_C(15)));
    uint64_t zuz3137;
    zuz3137 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__31 >> INT64_C(7)));
    uint64_t zimmshadowz36;
    zimmshadowz36 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__31 >> INT64_C(20)));
    struct zast zgaz3142;
    CREATE(zast)(&zgaz3142);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3289;
      zgsz3289.ztup0 = zimmshadowz36;
      zgsz3289.ztup1 = zuz3136;
      zgsz3289.ztup2 = zuz3137;
      zgsz3289.ztup3 = zJALR;
      zITYPE(&zgaz3142, zgsz3289);
    
    }
    {
      struct zast zgsz3373;
      CREATE(zast)(&zgsz3373);
      COPY(zast)(&zgsz3373, zgaz3142);
      zSomez3z5unionz0zzast(&zgsz3257, zgsz3373);
      KILL(zast)(&zgsz3373);
    }
    KILL(zast)(&zgaz3142);
  
  
  
  
  
    goto finish_match_126;
  }
case_139: ;
  {
    uint64_t zv__33;
    zv__33 = zmergez3var;
    uint64_t zgaz3145;
    zgaz3145 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__33 >> INT64_C(0)));
    bool zgsz3292;
    zgsz3292 = (zgaz3145 == UINT64_C(0b0000011));
  
    if (!(zgsz3292)) {
  
    goto case_140;
    }
    uint64_t zuz3138;
    zuz3138 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__33 >> INT64_C(20)));
    uint64_t zuz3139;
    zuz3139 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__33 >> INT64_C(15)));
    uint64_t zuz3140;
    zuz3140 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__33 >> INT64_C(7)));
    uint64_t zimmshadowz37;
    zimmshadowz37 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__33 >> INT64_C(20)));
    struct zast zgaz3144;
    CREATE(zast)(&zgaz3144);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3291;
      zgsz3291.ztup0 = zimmshadowz37;
      zgsz3291.ztup1 = zuz3139;
      zgsz3291.ztup2 = zuz3140;
      zgsz3291.ztup3 = zLW;
      zITYPE(&zgaz3144, zgsz3291);
    
    }
    {
      struct zast zgsz3374;
      CREATE(zast)(&zgsz3374);
      COPY(zast)(&zgsz3374, zgaz3144);
      zSomez3z5unionz0zzast(&zgsz3257, zgsz3374);
      KILL(zast)(&zgsz3374);
    }
    KILL(zast)(&zgaz3144);
  
  
  
  
  
    goto finish_match_126;
  }
case_140: ;
  {
    uint64_t zv__35;
    zv__35 = zmergez3var;
    uint64_t zgaz3147;
    zgaz3147 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__35 >> INT64_C(0)));
    bool zgsz3294;
    zgsz3294 = (zgaz3147 == UINT64_C(0b0100011));
  
    if (!(zgsz3294)) {
  
    goto case_141;
    }
    uint64_t zimm2;
    zimm2 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__35 >> INT64_C(25)));
    uint64_t zuz3141;
    zuz3141 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__35 >> INT64_C(20)));
    uint64_t zuz3142;
    zuz3142 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__35 >> INT64_C(15)));
    uint64_t zimm2shadowz38;
    zimm2shadowz38 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__35 >> INT64_C(25)));
    uint64_t zimm1;
    zimm1 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__35 >> INT64_C(7)));
    struct zast zgaz3146;
    CREATE(zast)(&zgaz3146);
    {
      struct ztuple_z8z5bv7zCz0z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzsopz9 zgsz3293;
      zgsz3293.ztup0 = zimm2shadowz38;
      zgsz3293.ztup1 = zuz3141;
      zgsz3293.ztup2 = zuz3142;
      zgsz3293.ztup3 = zimm1;
      zgsz3293.ztup4 = zSW;
      zSTYPE(&zgaz3146, zgsz3293);
    
    }
    {
      struct zast zgsz3375;
      CREATE(zast)(&zgsz3375);
      COPY(zast)(&zgsz3375, zgaz3146);
      zSomez3z5unionz0zzast(&zgsz3257, zgsz3375);
      KILL(zast)(&zgsz3375);
    }
    KILL(zast)(&zgaz3146);
  
  
  
  
  
  
    goto finish_match_126;
  }
case_141: ;
  {
    uint64_t zv__37;
    zv__37 = zmergez3var;
    uint64_t zgaz3149;
    zgaz3149 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__37 >> INT64_C(0)));
    bool zgsz3296;
    zgsz3296 = (zgaz3149 == UINT64_C(0b1100011));
  
    if (!(zgsz3296)) {
  
    goto case_142;
    }
    uint64_t zimm4;
    zimm4 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__37 >> INT64_C(31)));
    uint64_t zuz3143;
    zuz3143 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__37 >> INT64_C(20)));
    uint64_t zuz3144;
    zuz3144 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__37 >> INT64_C(15)));
    uint64_t zimm4shadowz39;
    zimm4shadowz39 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__37 >> INT64_C(31)));
    uint64_t zimm3;
    zimm3 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__37 >> INT64_C(7)));
    uint64_t zuz3145;
    zuz3145 = (safe_rshift(UINT64_MAX, 64 - 6) & (zv__37 >> INT64_C(25)));
    uint64_t zuz3146;
    zuz3146 = (safe_rshift(UINT64_MAX, 64 - 4) & (zv__37 >> INT64_C(8)));
    struct zast zgaz3148;
    CREATE(zast)(&zgaz3148);
    {
      struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 zgsz3295;
      zgsz3295.ztup0 = zimm4shadowz39;
      zgsz3295.ztup1 = zuz3145;
      zgsz3295.ztup2 = zuz3143;
      zgsz3295.ztup3 = zuz3144;
      zgsz3295.ztup4 = zuz3146;
      zgsz3295.ztup5 = zimm3;
      zgsz3295.ztup6 = zBEQ;
      zBTYPE(&zgaz3148, zgsz3295);
    
    }
    {
      struct zast zgsz3376;
      CREATE(zast)(&zgsz3376);
      COPY(zast)(&zgsz3376, zgaz3148);
      zSomez3z5unionz0zzast(&zgsz3257, zgsz3376);
      KILL(zast)(&zgsz3376);
    }
    KILL(zast)(&zgaz3148);
  
  
  
  
  
  
  
  
    goto finish_match_126;
  }
case_142: ;
  {
    uint64_t zv__39;
    zv__39 = zmergez3var;
    uint64_t zgaz3151;
    zgaz3151 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__39 >> INT64_C(0)));
    bool zgsz3298;
    zgsz3298 = (zgaz3151 == UINT64_C(0b1100011));
  
    if (!(zgsz3298)) {
  
    goto case_143;
    }
    uint64_t zuz3147;
    zuz3147 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__39 >> INT64_C(31)));
    uint64_t zuz3148;
    zuz3148 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__39 >> INT64_C(20)));
    uint64_t zuz3149;
    zuz3149 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__39 >> INT64_C(15)));
    uint64_t zimm4shadowz310;
    zimm4shadowz310 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__39 >> INT64_C(31)));
    uint64_t zuz3150;
    zuz3150 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__39 >> INT64_C(7)));
    uint64_t zuz3151;
    zuz3151 = (safe_rshift(UINT64_MAX, 64 - 6) & (zv__39 >> INT64_C(25)));
    uint64_t zuz3152;
    zuz3152 = (safe_rshift(UINT64_MAX, 64 - 4) & (zv__39 >> INT64_C(8)));
    struct zast zgaz3150;
    CREATE(zast)(&zgaz3150);
    {
      struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 zgsz3297;
      zgsz3297.ztup0 = zimm4shadowz310;
      zgsz3297.ztup1 = zuz3151;
      zgsz3297.ztup2 = zuz3148;
      zgsz3297.ztup3 = zuz3149;
      zgsz3297.ztup4 = zuz3152;
      zgsz3297.ztup5 = zuz3150;
      zgsz3297.ztup6 = zBNE;
      zBTYPE(&zgaz3150, zgsz3297);
    
    }
    {
      struct zast zgsz3377;
      CREATE(zast)(&zgsz3377);
      COPY(zast)(&zgsz3377, zgaz3150);
      zSomez3z5unionz0zzast(&zgsz3257, zgsz3377);
      KILL(zast)(&zgsz3377);
    }
    KILL(zast)(&zgaz3150);
  
  
  
  
  
  
  
  
    goto finish_match_126;
  }
case_143: ;
  {
    uint64_t zv__41;
    zv__41 = zmergez3var;
    uint64_t zgaz3153;
    zgaz3153 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__41 >> INT64_C(0)));
    bool zgsz3300;
    zgsz3300 = (zgaz3153 == UINT64_C(0b0110111));
  
    if (!(zgsz3300)) {
  
    goto case_144;
    }
    uint64_t zuz3153;
    zuz3153 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__41 >> INT64_C(12)));
    uint64_t zuz3154;
    zuz3154 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__41 >> INT64_C(7)));
    uint64_t zimmshadowz311;
    zimmshadowz311 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__41 >> INT64_C(12)));
    struct zast zgaz3152;
    CREATE(zast)(&zgaz3152);
    {
      struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 zgsz3299;
      zgsz3299.ztup0 = zimmshadowz311;
      zgsz3299.ztup1 = zuz3154;
      zgsz3299.ztup2 = zLUI;
      zUTYPE(&zgaz3152, zgsz3299);
    
    }
    {
      struct zast zgsz3378;
      CREATE(zast)(&zgsz3378);
      COPY(zast)(&zgsz3378, zgaz3152);
      zSomez3z5unionz0zzast(&zgsz3257, zgsz3378);
      KILL(zast)(&zgsz3378);
    }
    KILL(zast)(&zgaz3152);
  
  
  
  
    goto finish_match_126;
  }
case_144: ;
  {
    uint64_t zv__43;
    zv__43 = zmergez3var;
    uint64_t zgaz3155;
    zgaz3155 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__43 >> INT64_C(0)));
    bool zgsz3302;
    zgsz3302 = (zgaz3155 == UINT64_C(0b0010111));
  
    if (!(zgsz3302)) {
  
    goto case_145;
    }
    uint64_t zuz3155;
    zuz3155 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__43 >> INT64_C(12)));
    uint64_t zuz3156;
    zuz3156 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__43 >> INT64_C(7)));
    uint64_t zimmshadowz312;
    zimmshadowz312 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__43 >> INT64_C(12)));
    struct zast zgaz3154;
    CREATE(zast)(&zgaz3154);
    {
      struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 zgsz3301;
      zgsz3301.ztup0 = zimmshadowz312;
      zgsz3301.ztup1 = zuz3156;
      zgsz3301.ztup2 = zAUIPC;
      zUTYPE(&zgaz3154, zgsz3301);
    
    }
    {
      struct zast zgsz3379;
      CREATE(zast)(&zgsz3379);
      COPY(zast)(&zgsz3379, zgaz3154);
      zSomez3z5unionz0zzast(&zgsz3257, zgsz3379);
      KILL(zast)(&zgsz3379);
    }
    KILL(zast)(&zgaz3154);
  
  
  
  
    goto finish_match_126;
  }
case_145: ;
  {
    uint64_t zv__45;
    zv__45 = zmergez3var;
    uint64_t zgaz3157;
    zgaz3157 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__45 >> INT64_C(0)));
    bool zgsz3304;
    zgsz3304 = (zgaz3157 == UINT64_C(0b1101111));
  
    if (!(zgsz3304)) {
  
    goto case_146;
    }
    uint64_t zuz3157;
    zuz3157 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__45 >> INT64_C(31)));
    uint64_t zuz3158;
    zuz3158 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__45 >> INT64_C(7)));
    uint64_t zimm4shadowz313;
    zimm4shadowz313 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__45 >> INT64_C(31)));
    uint64_t zuz3159;
    zuz3159 = (safe_rshift(UINT64_MAX, 64 - 8) & (zv__45 >> INT64_C(12)));
    uint64_t zuz3160;
    zuz3160 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__45 >> INT64_C(20)));
    uint64_t zuz3161;
    zuz3161 = (safe_rshift(UINT64_MAX, 64 - 10) & (zv__45 >> INT64_C(21)));
    struct zast zgaz3156;
    CREATE(zast)(&zgaz3156);
    {
      struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv8zCz0z5bv5zCz0z5enumz0zzjopz9 zgsz3303;
      zgsz3303.ztup0 = zimm4shadowz313;
      zgsz3303.ztup1 = zuz3161;
      zgsz3303.ztup2 = zuz3160;
      zgsz3303.ztup3 = zuz3159;
      zgsz3303.ztup4 = zuz3158;
      zgsz3303.ztup5 = zJAL;
      zJTYPE(&zgaz3156, zgsz3303);
    
    }
    {
      struct zast zgsz3380;
      CREATE(zast)(&zgsz3380);
      COPY(zast)(&zgsz3380, zgaz3156);
      zSomez3z5unionz0zzast(&zgsz3257, zgsz3380);
      KILL(zast)(&zgsz3380);
    }
    KILL(zast)(&zgaz3156);
  
  
  
  
  
  
  
    goto finish_match_126;
  }
case_146: ;
  {
    uint64_t zv__47;
    zv__47 = zmergez3var;
    bool zgsz3305;
    zgsz3305 = (zv__47 == UINT64_C(0x00100073));
    if (!(zgsz3305)) {
  
    goto case_147;
    }
    struct zast zgaz3158;
    CREATE(zast)(&zgaz3158);
    zEBREAK(&zgaz3158, UNIT);
    {
      struct zast zgsz3381;
      CREATE(zast)(&zgsz3381);
      COPY(zast)(&zgsz3381, zgaz3158);
      zSomez3z5unionz0zzast(&zgsz3257, zgsz3381);
      KILL(zast)(&zgsz3381);
    }
    KILL(zast)(&zgaz3158);
  
    goto finish_match_126;
  }
case_147: ;
  sail_match_failure("decode");
finish_match_126: ;
  COPY(zoption)((*(&zcbz322)), zgsz3257);
  KILL(zoption)(&zgsz3257);
end_function_148: ;
  goto end_function_158;
end_block_exception_149: ;
  goto end_function_158;
end_function_158: ;
}

unit zmain(unit);

lbits zghz3209;
lbits zghz3210;
lbits zghz3211;
lbits zghz3212;
lbits zghz3213;
lbits zghz3214;
lbits zghz3215;
lbits zghz3216;
lbits zghz3217;
lbits zghz3218;
sail_int zghz3219;
lbits zghz3220;
lbits zghz3221;
lbits zghz3222;
sail_int zghz3223;
sail_int zghz3224;
sail_int zghz3225;
lbits zghz3226;

void startup_zmain(void)
{
  CREATE(lbits)(&zghz3209);
  CREATE(lbits)(&zghz3210);
  CREATE(lbits)(&zghz3211);
  CREATE(lbits)(&zghz3212);
  CREATE(lbits)(&zghz3213);
  CREATE(lbits)(&zghz3214);
  CREATE(lbits)(&zghz3215);
  CREATE(lbits)(&zghz3216);
  CREATE(lbits)(&zghz3217);
  CREATE(lbits)(&zghz3218);
  CREATE(sail_int)(&zghz3219);
  CREATE(lbits)(&zghz3220);
  CREATE(lbits)(&zghz3221);
  CREATE(lbits)(&zghz3222);
  CREATE(sail_int)(&zghz3223);
  CREATE(sail_int)(&zghz3224);
  CREATE(sail_int)(&zghz3225);
  CREATE(lbits)(&zghz3226);
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

unit zmain(unit zgsz3306)
{
  __label__ case_152, finish_match_151, end_function_153, end_block_exception_154;

  unit zcbz323;
  {
    RECREATE(sail_int)(&zghz3223);
    elf_entry(&zghz3223, UNIT);
    {
      RECREATE(sail_int)(&zghz3224);
      CONVERT_OF(sail_int, mach_int)(&zghz3224, INT64_C(32));
      RECREATE(sail_int)(&zghz3225);
      CONVERT_OF(sail_int, mach_int)(&zghz3225, INT64_C(0));
      RECREATE(lbits)(&zghz3226);
      get_slice_int(&zghz3226, zghz3224, zghz3223, zghz3225);
      zPC = CONVERT_OF(fbits, lbits)(zghz3226, true);
    }
    unit zgsz3314;
    zgsz3314 = UNIT;
  }
  {
    unit zgsz3312;
    {
      RECREATE(lbits)(&zghz3222);
      CONVERT_OF(lbits, fbits)(&zghz3222, zPC, UINT64_C(32) , true);
      zgsz3312 = print_bits("PC = ", zghz3222);
    }
  }
  {
    uint64_t zline;
    zline = zread_mem(zPC);
    unit zgsz3310;
    {
      RECREATE(lbits)(&zghz3221);
      CONVERT_OF(lbits, fbits)(&zghz3221, zline, UINT64_C(32) , true);
      zgsz3310 = print_bits("line = ", zghz3221);
    }
  
  }
  uint64_t ztest;
  ztest = UINT64_C(0xFF);
  {
    {
      RECREATE(lbits)(&zghz3218);
      CONVERT_OF(lbits, fbits)(&zghz3218, ztest, UINT64_C(8) , true);
      RECREATE(sail_int)(&zghz3219);
      CONVERT_OF(sail_int, mach_int)(&zghz3219, INT64_C(3));
      RECREATE(lbits)(&zghz3220);
      shiftl(&zghz3220, zghz3218, zghz3219);
      ztest = CONVERT_OF(fbits, lbits)(zghz3220, true);
    }
    unit zgsz3320;
    zgsz3320 = UNIT;
  }
  {
    unit zgsz3318;
    {
      RECREATE(lbits)(&zghz3217);
      CONVERT_OF(lbits, fbits)(&zghz3217, ztest, UINT64_C(8) , true);
      zgsz3318 = print_bits("test = ", zghz3217);
    }
  }
  uint64_t za;
  za = UINT64_C(0x9);
  uint64_t zb;
  zb = UINT64_C(0xB);
  struct ztuple_z8z5bv8zCz0z5bv8z9 zgaz3160;
  {
    RECREATE(lbits)(&zghz3215);
    CONVERT_OF(lbits, fbits)(&zghz3215, za, UINT64_C(4) , true);
    RECREATE(lbits)(&zghz3216);
    CONVERT_OF(lbits, fbits)(&zghz3216, zb, UINT64_C(4) , true);
    struct ztuple_z8z5bvzCz0z5bvz9 zgsz3323;
    CREATE(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3323);
    zdiv_bitvector(&zgsz3323, zghz3215, zghz3216);
    /* conversions */
    zgaz3160.ztup0 = CONVERT_OF(fbits, lbits)(zgsz3323.ztup0, true);
    zgaz3160.ztup1 = CONVERT_OF(fbits, lbits)(zgsz3323.ztup1, true);
    /* end conversions */
    KILL(ztuple_z8z5bvzCz0z5bvz9)(&zgsz3323);
  }
  unit zgsz3324;
  {
    uint64_t zdiv;
    zdiv = zgaz3160.ztup0;
    uint64_t zrem;
    zrem = zgaz3160.ztup1;
    {
      unit zgsz3327;
      {
        RECREATE(lbits)(&zghz3214);
        CONVERT_OF(lbits, fbits)(&zghz3214, zdiv, UINT64_C(8) , true);
        zgsz3327 = print_bits("quotient = ", zghz3214);
      }
    }
    {
      unit zgsz3325;
      {
        RECREATE(lbits)(&zghz3213);
        CONVERT_OF(lbits, fbits)(&zghz3213, zrem, UINT64_C(8) , true);
        zgsz3325 = print_bits("remainder = ", zghz3213);
      }
    }
    uint64_t zc;
    zc = UINT64_C(0x6);
    uint64_t zd;
    zd = UINT64_C(0x7);
    uint64_t zmul;
    {
      RECREATE(lbits)(&zghz3210);
      CONVERT_OF(lbits, fbits)(&zghz3210, zc, UINT64_C(4) , true);
      RECREATE(lbits)(&zghz3211);
      CONVERT_OF(lbits, fbits)(&zghz3211, zd, UINT64_C(4) , true);
      RECREATE(lbits)(&zghz3212);
      zmul_bitvector(&zghz3212, zghz3210, zghz3211);
      zmul = CONVERT_OF(fbits, lbits)(zghz3212, true);
    }
    {
      RECREATE(lbits)(&zghz3209);
      CONVERT_OF(lbits, fbits)(&zghz3209, zmul, UINT64_C(8) , true);
      zgsz3324 = print_bits("mul = ", zghz3209);
    }
  
  
  
  
  
    goto finish_match_151;
  }
case_152: ;
  sail_match_failure("main");
finish_match_151: ;
  zcbz323 = zgsz3324;





end_function_153: ;
  return zcbz323;
end_block_exception_154: ;

  return UNIT;
}



void finish_zmain(void)
{
  KILL(lbits)(&zghz3226);
  KILL(sail_int)(&zghz3225);
  KILL(sail_int)(&zghz3224);
  KILL(sail_int)(&zghz3223);
  KILL(lbits)(&zghz3222);
  KILL(lbits)(&zghz3221);
  KILL(lbits)(&zghz3220);
  KILL(sail_int)(&zghz3219);
  KILL(lbits)(&zghz3218);
  KILL(lbits)(&zghz3217);
  KILL(lbits)(&zghz3216);
  KILL(lbits)(&zghz3215);
  KILL(lbits)(&zghz3214);
  KILL(lbits)(&zghz3213);
  KILL(lbits)(&zghz3212);
  KILL(lbits)(&zghz3211);
  KILL(lbits)(&zghz3210);
  KILL(lbits)(&zghz3209);
}

unit zinitializze_registers(unit);

sail_int zghz3227;
lbits zghz3228;
sail_int zghz3229;
lbits zghz3230;
sail_int zghz3231;
lbits zghz3232;
sail_int zghz3233;
lbits zghz3234;
sail_int zghz3235;
lbits zghz3236;
sail_int zghz3237;
lbits zghz3238;
sail_int zghz3239;
lbits zghz3240;
sail_int zghz3241;
lbits zghz3242;
sail_int zghz3243;
lbits zghz3244;

void startup_zinitializze_registers(void)
{
  CREATE(sail_int)(&zghz3227);
  CREATE(lbits)(&zghz3228);
  CREATE(sail_int)(&zghz3229);
  CREATE(lbits)(&zghz3230);
  CREATE(sail_int)(&zghz3231);
  CREATE(lbits)(&zghz3232);
  CREATE(sail_int)(&zghz3233);
  CREATE(lbits)(&zghz3234);
  CREATE(sail_int)(&zghz3235);
  CREATE(lbits)(&zghz3236);
  CREATE(sail_int)(&zghz3237);
  CREATE(lbits)(&zghz3238);
  CREATE(sail_int)(&zghz3239);
  CREATE(lbits)(&zghz3240);
  CREATE(sail_int)(&zghz3241);
  CREATE(lbits)(&zghz3242);
  CREATE(sail_int)(&zghz3243);
  CREATE(lbits)(&zghz3244);
}

unit zinitializze_registers(unit zgsz3334)
{
  __label__ end_function_156, end_block_exception_157;

  unit zcbz324;
  {
    {
      RECREATE(sail_int)(&zghz3243);
      CONVERT_OF(sail_int, mach_int)(&zghz3243, INT64_C(32));
      RECREATE(lbits)(&zghz3244);
      UNDEFINED(lbits)(&zghz3244, zghz3243);
      zPC = CONVERT_OF(fbits, lbits)(zghz3244, true);
    }
    unit zgsz3358;
    zgsz3358 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3241);
      CONVERT_OF(sail_int, mach_int)(&zghz3241, INT64_C(32));
      RECREATE(lbits)(&zghz3242);
      UNDEFINED(lbits)(&zghz3242, zghz3241);
      zzzero = CONVERT_OF(fbits, lbits)(zghz3242, true);
    }
    unit zgsz3357;
    zgsz3357 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3239);
      CONVERT_OF(sail_int, mach_int)(&zghz3239, INT64_C(32));
      RECREATE(lbits)(&zghz3240);
      UNDEFINED(lbits)(&zghz3240, zghz3239);
      zra = CONVERT_OF(fbits, lbits)(zghz3240, true);
    }
    unit zgsz3356;
    zgsz3356 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3237);
      CONVERT_OF(sail_int, mach_int)(&zghz3237, INT64_C(32));
      RECREATE(lbits)(&zghz3238);
      UNDEFINED(lbits)(&zghz3238, zghz3237);
      zsp = CONVERT_OF(fbits, lbits)(zghz3238, true);
    }
    unit zgsz3355;
    zgsz3355 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3235);
      CONVERT_OF(sail_int, mach_int)(&zghz3235, INT64_C(32));
      RECREATE(lbits)(&zghz3236);
      UNDEFINED(lbits)(&zghz3236, zghz3235);
      zgp = CONVERT_OF(fbits, lbits)(zghz3236, true);
    }
    unit zgsz3354;
    zgsz3354 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3233);
      CONVERT_OF(sail_int, mach_int)(&zghz3233, INT64_C(32));
      RECREATE(lbits)(&zghz3234);
      UNDEFINED(lbits)(&zghz3234, zghz3233);
      za0 = CONVERT_OF(fbits, lbits)(zghz3234, true);
    }
    unit zgsz3353;
    zgsz3353 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3231);
      CONVERT_OF(sail_int, mach_int)(&zghz3231, INT64_C(32));
      RECREATE(lbits)(&zghz3232);
      UNDEFINED(lbits)(&zghz3232, zghz3231);
      za1 = CONVERT_OF(fbits, lbits)(zghz3232, true);
    }
    unit zgsz3352;
    zgsz3352 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz3229);
      CONVERT_OF(sail_int, mach_int)(&zghz3229, INT64_C(32));
      RECREATE(lbits)(&zghz3230);
      UNDEFINED(lbits)(&zghz3230, zghz3229);
      za2 = CONVERT_OF(fbits, lbits)(zghz3230, true);
    }
    unit zgsz3351;
    zgsz3351 = UNIT;
  }
  {
    RECREATE(sail_int)(&zghz3227);
    CONVERT_OF(sail_int, mach_int)(&zghz3227, INT64_C(32));
    RECREATE(lbits)(&zghz3228);
    UNDEFINED(lbits)(&zghz3228, zghz3227);
    za3 = CONVERT_OF(fbits, lbits)(zghz3228, true);
  }
  zcbz324 = UNIT;
end_function_156: ;
  return zcbz324;
end_block_exception_157: ;

  return UNIT;
}



void finish_zinitializze_registers(void)
{
  KILL(lbits)(&zghz3244);
  KILL(sail_int)(&zghz3243);
  KILL(lbits)(&zghz3242);
  KILL(sail_int)(&zghz3241);
  KILL(lbits)(&zghz3240);
  KILL(sail_int)(&zghz3239);
  KILL(lbits)(&zghz3238);
  KILL(sail_int)(&zghz3237);
  KILL(lbits)(&zghz3236);
  KILL(sail_int)(&zghz3235);
  KILL(lbits)(&zghz3234);
  KILL(sail_int)(&zghz3233);
  KILL(lbits)(&zghz3232);
  KILL(sail_int)(&zghz3231);
  KILL(lbits)(&zghz3230);
  KILL(sail_int)(&zghz3229);
  KILL(lbits)(&zghz3228);
  KILL(sail_int)(&zghz3227);
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
  startup_zgt_bit();
  startup_zlt_bit();
  startup_zxor_bitvector();
  startup_ztwos_complement();
  startup_zabs();
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
  finish_zwrite_mem();
  finish_zgt_bit();
  finish_zlt_bit();
  finish_zxor_bitvector();
  finish_ztwos_complement();
  finish_zabs();
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
