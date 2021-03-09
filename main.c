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
  __label__ end_function_1, end_block_exception_2, end_function_118;

  bool zgaz31;
  {
    RECREATE(sail_int)(&zghz30);
    length_lbits(&zghz30, zv);
    zgaz31 = lteq(zlen, zghz30);
  }
  if (zgaz31) {  sail_truncate((*(&zcbz30)), zv, zlen);  } else {  zero_extend((*(&zcbz30)), zv, zlen);  }

end_function_1: ;
  goto end_function_118;
end_block_exception_2: ;
  goto end_function_118;
end_function_118: ;
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
  __label__ end_function_4, end_block_exception_5, end_function_117;

  RECREATE(lbits)(&zghz31);
  zeros(&zghz31, zn);
  not_bits((*(&zcbz31)), zghz31);
end_function_4: ;
  goto end_function_117;
end_block_exception_5: ;
  goto end_function_117;
end_function_117: ;
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
  __label__ end_function_7, end_block_exception_8, end_function_116;

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
  goto end_function_116;
end_block_exception_8: ;
  goto end_function_116;
end_function_116: ;
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
  __label__ end_function_11, end_block_exception_12, end_function_115;

  zero_extend((*(&zcbz33)), zxs, zm);
end_function_11: ;
  goto end_function_115;
end_block_exception_12: ;
  goto end_function_115;
end_function_115: ;
}

fbits zxor_bit(fbits, fbits);

fbits zxor_bit(fbits zb1, fbits zb2)
{
  __label__ end_function_14, end_block_exception_15;

  fbits zcbz34;
  bool zgaz311;
  zgaz311 = (zb1 == zb2);
  if (zgaz311) {  zcbz34 = UINT64_C(0);  } else {  zcbz34 = UINT64_C(1);  }

end_function_14: ;
  return zcbz34;
end_block_exception_15: ;

  return UINT64_C(0);
}

void zxor_bitvector(lbits *rop, lbits, lbits);

sail_int zghz314;
lbits zghz315;
sail_int zghz316;
sail_int zghz317;
sail_int zghz318;
sail_int zghz319;
sail_int zghz320;
lbits zghz321;

void startup_zxor_bitvector(void)
{
  CREATE(sail_int)(&zghz314);
  CREATE(lbits)(&zghz315);
  CREATE(sail_int)(&zghz316);
  CREATE(sail_int)(&zghz317);
  CREATE(sail_int)(&zghz318);
  CREATE(sail_int)(&zghz319);
  CREATE(sail_int)(&zghz320);
  CREATE(lbits)(&zghz321);
}

void zxor_bitvector(lbits *zcbz35, lbits zv1, lbits zv2)
{
  __label__ end_function_19, end_block_exception_20, end_function_114;

  RECREATE(sail_int)(&zghz314);
  length_lbits(&zghz314, zv2);
  RECREATE(lbits)(&zghz315);
  {
    RECREATE(lbits)(&zghz321);
    CONVERT_OF(lbits, fbits)(&zghz321, UINT64_C(0b0), UINT64_C(1) , true);
    zero_extend(&zghz315, zghz321, zghz314);
  }
  {
    int64_t zgsz313;
    {    zgsz313 = INT64_C(0);
    }
    int64_t zgsz314;
    {
      {
        RECREATE(sail_int)(&zghz319);
        CONVERT_OF(sail_int, mach_int)(&zghz319, INT64_C(1));
        RECREATE(sail_int)(&zghz320);
        sub_int(&zghz320, zghz314, zghz319);
        zgsz314 = CONVERT_OF(mach_int, sail_int)(zghz320);
      }
    }
    int64_t zgsz315;
    {    zgsz315 = INT64_C(1);
    }
    {
      __label__ for_start_17, for_end_18;

      int64_t zi;
      zi = zgsz313;
      unit zgsz319;
    for_start_17: ;
      {
        if ((zi > zgsz314)) goto for_end_18;
        fbits zb1;
        {
          RECREATE(sail_int)(&zghz318);
          CONVERT_OF(sail_int, mach_int)(&zghz318, zi);
          zb1 = bitvector_access(zv1, zghz318);
        }
        fbits zb2;
        {
          RECREATE(sail_int)(&zghz317);
          CONVERT_OF(sail_int, mach_int)(&zghz317, zi);
          zb2 = bitvector_access(zv2, zghz317);
        }
        fbits zgaz312;
        zgaz312 = zxor_bit(zb1, zb2);
        {
          RECREATE(sail_int)(&zghz316);
          CONVERT_OF(sail_int, mach_int)(&zghz316, zi);
          update_lbits(&zghz315, zghz315, zghz316, zgaz312);
        }
        zgsz319 = UNIT;
      
      
      
        zi = (zi + zgsz315);
        goto for_start_17;
      }
    for_end_18: ;
    }
    unit zgsz322;
    zgsz322 = UNIT;
  }
  COPY(lbits)((*(&zcbz35)), zghz315);
end_function_19: ;
  goto end_function_114;
end_block_exception_20: ;
  goto end_function_114;
end_function_114: ;
}



void finish_zxor_bitvector(void)
{
  KILL(lbits)(&zghz321);
  KILL(sail_int)(&zghz320);
  KILL(sail_int)(&zghz319);
  KILL(sail_int)(&zghz318);
  KILL(sail_int)(&zghz317);
  KILL(sail_int)(&zghz316);
  KILL(lbits)(&zghz315);
  KILL(sail_int)(&zghz314);
}

uint64_t zrX(uint64_t);

sail_int zghz322;

void startup_zrX(void)
{    CREATE(sail_int)(&zghz322);
}

uint64_t zrX(uint64_t zr)
{
  __label__ end_function_22, end_block_exception_23;

  uint64_t zcbz36;
  uint64_t zoffset;
  zoffset = (safe_rshift(UINT64_MAX, 64 - 3) & (zr >> INT64_C(0)));
  uint64_t* zgaz314;
  {
    int64_t zgaz313;
    zgaz313 = ((mach_int) zoffset);
    {
      RECREATE(sail_int)(&zghz322);
      CONVERT_OF(sail_int, mach_int)(&zghz322, zgaz313);
      zgaz314 = vector_access_zz5vecz8z6z8z5bv32z9z9(zXs, zghz322);
    }
  
  }
  zcbz36 = *(zgaz314);


end_function_22: ;
  return zcbz36;
end_block_exception_23: ;

  return UINT64_C(0xdeadc0de);
}



void finish_zrX(void)
{    KILL(sail_int)(&zghz322);
}

unit zwX(uint64_t, uint64_t);

sail_int zghz323;
sail_int zghz324;
lbits zghz325;
lbits zghz326;
sail_int zghz327;
sail_int zghz328;
sail_int zghz329;

void startup_zwX(void)
{
  CREATE(sail_int)(&zghz323);
  CREATE(sail_int)(&zghz324);
  CREATE(lbits)(&zghz325);
  CREATE(lbits)(&zghz326);
  CREATE(sail_int)(&zghz327);
  CREATE(sail_int)(&zghz328);
  CREATE(sail_int)(&zghz329);
}

unit zwX(uint64_t zr, uint64_t zv)
{
  __label__ case_26, case_27, finish_match_25, end_function_28, end_block_exception_29;

  unit zcbz37;
  uint64_t zoffset;
  zoffset = (safe_rshift(UINT64_MAX, 64 - 3) & (zr >> INT64_C(0)));
  {
    uint64_t zvz30;
    zvz30 = zoffset;
    uint64_t zgaz317;
    {
      int64_t zgaz316;
      {
        int64_t zgaz315;
        {
          RECREATE(sail_int)(&zghz327);
          CONVERT_OF(sail_int, mach_int)(&zghz327, INT64_C(2));
          RECREATE(sail_int)(&zghz328);
          CONVERT_OF(sail_int, mach_int)(&zghz328, INT64_C(0));
          RECREATE(sail_int)(&zghz329);
          sub_int(&zghz329, zghz327, zghz328);
          zgaz315 = CONVERT_OF(mach_int, sail_int)(zghz329);
        }
        zgaz316 = (zgaz315 + INT64_C(1));
      
      }
      {
        RECREATE(sail_int)(&zghz324);
        CONVERT_OF(sail_int, mach_int)(&zghz324, zgaz316);
        RECREATE(lbits)(&zghz325);
        CONVERT_OF(lbits, fbits)(&zghz325, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz326);
        zextzz(&zghz326, zghz324, zghz325);
        zgaz317 = CONVERT_OF(fbits, lbits)(zghz326, true);
      }
    
    }
    bool zgsz331;
    zgsz331 = (zvz30 == zgaz317);
  
    if (!(zgsz331)) {
  
    goto case_26;
    }
    zcbz37 = print_endline("Cannot overwrite hard-wired zero register");
  
    goto finish_match_25;
  }
case_26: ;
  {
    uint64_t* zgaz318;
    {
      int64_t zgaz319;
      zgaz319 = ((mach_int) zoffset);
      {
        RECREATE(sail_int)(&zghz323);
        CONVERT_OF(sail_int, mach_int)(&zghz323, zgaz319);
        zgaz318 = vector_access_zz5vecz8z6z8z5bv32z9z9(zXs, zghz323);
      }
    
    }
    (*(zgaz318)) = zv;
    zcbz37 = UNIT;
  
    goto finish_match_25;
  }
case_27: ;
  sail_match_failure("wX");
finish_match_25: ;

end_function_28: ;
  return zcbz37;
end_block_exception_29: ;

  return UNIT;
}



void finish_zwX(void)
{
  KILL(sail_int)(&zghz329);
  KILL(sail_int)(&zghz328);
  KILL(sail_int)(&zghz327);
  KILL(lbits)(&zghz326);
  KILL(lbits)(&zghz325);
  KILL(sail_int)(&zghz324);
  KILL(sail_int)(&zghz323);
}

unit zadd_to_PC(sail_int);

lbits zghz330;
lbits zghz331;

void startup_zadd_to_PC(void)
{
  CREATE(lbits)(&zghz330);
  CREATE(lbits)(&zghz331);
}

unit zadd_to_PC(sail_int zbytes)
{
  __label__ end_function_31, end_block_exception_32;

  unit zcbz38;
  {
    RECREATE(lbits)(&zghz330);
    CONVERT_OF(lbits, fbits)(&zghz330, zPC, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz331);
    add_bits_int(&zghz331, zghz330, zbytes);
    zPC = CONVERT_OF(fbits, lbits)(zghz331, true);
  }
  zcbz38 = UNIT;
end_function_31: ;
  return zcbz38;
end_block_exception_32: ;

  return UNIT;
}



void finish_zadd_to_PC(void)
{
  KILL(lbits)(&zghz331);
  KILL(lbits)(&zghz330);
}

unit zinc_PC(unit);

sail_int zghz332;

void startup_zinc_PC(void)
{    CREATE(sail_int)(&zghz332);
}

unit zinc_PC(unit zgsz336)
{
  __label__ end_function_34, end_block_exception_35;

  unit zcbz39;
  {
    RECREATE(sail_int)(&zghz332);
    CONVERT_OF(sail_int, mach_int)(&zghz332, INT64_C(4));
    zcbz39 = zadd_to_PC(zghz332);
  }
end_function_34: ;
  return zcbz39;
end_block_exception_35: ;

  return UNIT;
}



void finish_zinc_PC(void)
{    KILL(sail_int)(&zghz332);
}






void zdecode(struct zoption *rop, uint64_t);






unit zexecute(struct zast);

sail_int zghz333;
lbits zghz334;
lbits zghz335;
sail_int zghz336;
lbits zghz337;
lbits zghz338;
sail_int zghz339;
lbits zghz340;
lbits zghz341;
lbits zghz342;
lbits zghz343;
lbits zghz344;
sail_int zghz345;
lbits zghz346;
lbits zghz347;
sail_int zghz348;
lbits zghz349;
lbits zghz350;
sail_int zghz351;
lbits zghz352;
lbits zghz353;
sail_int zghz354;
lbits zghz355;
lbits zghz356;
sail_int zghz357;
lbits zghz358;
lbits zghz359;
sail_int zghz360;
lbits zghz361;
lbits zghz362;

void startup_zexecute(void)
{
  CREATE(sail_int)(&zghz333);
  CREATE(lbits)(&zghz334);
  CREATE(lbits)(&zghz335);
  CREATE(sail_int)(&zghz336);
  CREATE(lbits)(&zghz337);
  CREATE(lbits)(&zghz338);
  CREATE(sail_int)(&zghz339);
  CREATE(lbits)(&zghz340);
  CREATE(lbits)(&zghz341);
  CREATE(lbits)(&zghz342);
  CREATE(lbits)(&zghz343);
  CREATE(lbits)(&zghz344);
  CREATE(sail_int)(&zghz345);
  CREATE(lbits)(&zghz346);
  CREATE(lbits)(&zghz347);
  CREATE(sail_int)(&zghz348);
  CREATE(lbits)(&zghz349);
  CREATE(lbits)(&zghz350);
  CREATE(sail_int)(&zghz351);
  CREATE(lbits)(&zghz352);
  CREATE(lbits)(&zghz353);
  CREATE(sail_int)(&zghz354);
  CREATE(lbits)(&zghz355);
  CREATE(lbits)(&zghz356);
  CREATE(sail_int)(&zghz357);
  CREATE(lbits)(&zghz358);
  CREATE(lbits)(&zghz359);
  CREATE(sail_int)(&zghz360);
  CREATE(lbits)(&zghz361);
  CREATE(lbits)(&zghz362);
}

unit zexecute(struct zast zmergez3var)
{
  __label__ case_38, case_39, case_43, case_47, case_51, case_52, case_53, case_54, case_55, case_56, case_57, case_58, case_59, case_60, case_61, case_62, case_63, case_64, case_65, case_66, finish_match_37, end_function_67, end_block_exception_68;

  unit zcbz310;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_38;
    uint64_t zrs2;
    zrs2 = zmergez3var.zRTYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zRTYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zRTYPE.ztup2;
    if ((zADD != zmergez3var.zRTYPE.ztup3)) goto case_38;
    uint64_t zrs1_val;
    zrs1_val = zrX(zrs1);
    uint64_t zrs2_val;
    zrs2_val = zrX(zrs2);
    uint64_t zresult;
    zresult = ((zrs1_val + zrs2_val) & UINT64_C(0xFFFFFFFF));
    zcbz310 = zwX(zrd, zresult);
  
  
  
  
  
  
    goto finish_match_37;
  }
case_38: ;
  {
    __label__ case_41, case_42, finish_match_40;

    if (zmergez3var.kind != Kind_zRTYPE) goto case_39;
    uint64_t zuz30;
    zuz30 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz31;
    zuz31 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz32;
    zuz32 = zmergez3var.zRTYPE.ztup2;
    if ((zAND != zmergez3var.zRTYPE.ztup3)) goto case_39;
    uint64_t zuz33;
    zuz33 = zrX(zuz31);
    uint64_t zuz34;
    zuz34 = zrX(zuz30);
    uint64_t zbitwise_AND;
    zbitwise_AND = (zuz33 & zuz34);
    {
      uint64_t zvz31;
      zvz31 = zbitwise_AND;
      uint64_t zgaz321;
      {
        RECREATE(sail_int)(&zghz360);
        CONVERT_OF(sail_int, mach_int)(&zghz360, INT64_C(32));
        RECREATE(lbits)(&zghz361);
        CONVERT_OF(lbits, fbits)(&zghz361, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz362);
        zextzz(&zghz362, zghz360, zghz361);
        zgaz321 = CONVERT_OF(fbits, lbits)(zghz362, true);
      }
      bool zgsz347;
      zgsz347 = (zvz31 == zgaz321);
    
      if (!(zgsz347)) {
    
      goto case_41;
      }
      uint64_t zgaz320;
      {
        RECREATE(sail_int)(&zghz357);
        CONVERT_OF(sail_int, mach_int)(&zghz357, INT64_C(32));
        RECREATE(lbits)(&zghz358);
        CONVERT_OF(lbits, fbits)(&zghz358, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz359);
        zextzz(&zghz359, zghz357, zghz358);
        zgaz320 = CONVERT_OF(fbits, lbits)(zghz359, true);
      }
      zcbz310 = zwX(zuz32, zgaz320);
    
    
      goto finish_match_40;
    }
  case_41: ;
    {
      uint64_t zgaz322;
      {
        RECREATE(sail_int)(&zghz354);
        CONVERT_OF(sail_int, mach_int)(&zghz354, INT64_C(32));
        RECREATE(lbits)(&zghz355);
        CONVERT_OF(lbits, fbits)(&zghz355, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz356);
        zextzz(&zghz356, zghz354, zghz355);
        zgaz322 = CONVERT_OF(fbits, lbits)(zghz356, true);
      }
      zcbz310 = zwX(zuz32, zgaz322);
    
      goto finish_match_40;
    }
  case_42: ;
    sail_match_failure("execute");
  finish_match_40: ;
  
  
  
  
  
  
    goto finish_match_37;
  }
case_39: ;
  {
    __label__ case_45, case_46, finish_match_44;

    if (zmergez3var.kind != Kind_zRTYPE) goto case_43;
    uint64_t zuz35;
    zuz35 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz36;
    zuz36 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz37;
    zuz37 = zmergez3var.zRTYPE.ztup2;
    if ((zOR != zmergez3var.zRTYPE.ztup3)) goto case_43;
    uint64_t zuz38;
    zuz38 = zrX(zuz36);
    uint64_t zuz39;
    zuz39 = zrX(zuz35);
    uint64_t zbitwise_OR;
    zbitwise_OR = (zuz38 | zuz39);
    {
      uint64_t zvz32;
      zvz32 = zbitwise_OR;
      uint64_t zgaz324;
      {
        RECREATE(sail_int)(&zghz351);
        CONVERT_OF(sail_int, mach_int)(&zghz351, INT64_C(32));
        RECREATE(lbits)(&zghz352);
        CONVERT_OF(lbits, fbits)(&zghz352, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz353);
        zextzz(&zghz353, zghz351, zghz352);
        zgaz324 = CONVERT_OF(fbits, lbits)(zghz353, true);
      }
      bool zgsz360;
      zgsz360 = (zvz32 == zgaz324);
    
      if (!(zgsz360)) {
    
      goto case_45;
      }
      uint64_t zgaz323;
      {
        RECREATE(sail_int)(&zghz348);
        CONVERT_OF(sail_int, mach_int)(&zghz348, INT64_C(32));
        RECREATE(lbits)(&zghz349);
        CONVERT_OF(lbits, fbits)(&zghz349, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz350);
        zextzz(&zghz350, zghz348, zghz349);
        zgaz323 = CONVERT_OF(fbits, lbits)(zghz350, true);
      }
      zcbz310 = zwX(zuz37, zgaz323);
    
    
      goto finish_match_44;
    }
  case_45: ;
    {
      uint64_t zgaz325;
      {
        RECREATE(sail_int)(&zghz345);
        CONVERT_OF(sail_int, mach_int)(&zghz345, INT64_C(32));
        RECREATE(lbits)(&zghz346);
        CONVERT_OF(lbits, fbits)(&zghz346, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz347);
        zextzz(&zghz347, zghz345, zghz346);
        zgaz325 = CONVERT_OF(fbits, lbits)(zghz347, true);
      }
      zcbz310 = zwX(zuz37, zgaz325);
    
      goto finish_match_44;
    }
  case_46: ;
    sail_match_failure("execute");
  finish_match_44: ;
  
  
  
  
  
  
    goto finish_match_37;
  }
case_43: ;
  {
    __label__ case_49, case_50, finish_match_48;

    if (zmergez3var.kind != Kind_zRTYPE) goto case_47;
    uint64_t zuz310;
    zuz310 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz311;
    zuz311 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz312;
    zuz312 = zmergez3var.zRTYPE.ztup2;
    if ((zXOR != zmergez3var.zRTYPE.ztup3)) goto case_47;
    uint64_t zuz313;
    zuz313 = zrX(zuz311);
    uint64_t zuz314;
    zuz314 = zrX(zuz310);
    uint64_t zbitwise_XOR;
    {
      RECREATE(lbits)(&zghz342);
      CONVERT_OF(lbits, fbits)(&zghz342, zuz313, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz343);
      CONVERT_OF(lbits, fbits)(&zghz343, zuz314, UINT64_C(32) , true);
      RECREATE(lbits)(&zghz344);
      zxor_bitvector(&zghz344, zghz342, zghz343);
      zbitwise_XOR = CONVERT_OF(fbits, lbits)(zghz344, true);
    }
    {
      uint64_t zvz33;
      zvz33 = zbitwise_XOR;
      uint64_t zgaz327;
      {
        RECREATE(sail_int)(&zghz339);
        CONVERT_OF(sail_int, mach_int)(&zghz339, INT64_C(32));
        RECREATE(lbits)(&zghz340);
        CONVERT_OF(lbits, fbits)(&zghz340, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz341);
        zextzz(&zghz341, zghz339, zghz340);
        zgaz327 = CONVERT_OF(fbits, lbits)(zghz341, true);
      }
      bool zgsz376;
      zgsz376 = (zvz33 == zgaz327);
    
      if (!(zgsz376)) {
    
      goto case_49;
      }
      uint64_t zgaz326;
      {
        RECREATE(sail_int)(&zghz336);
        CONVERT_OF(sail_int, mach_int)(&zghz336, INT64_C(32));
        RECREATE(lbits)(&zghz337);
        CONVERT_OF(lbits, fbits)(&zghz337, UINT64_C(0b1), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz338);
        zextzz(&zghz338, zghz336, zghz337);
        zgaz326 = CONVERT_OF(fbits, lbits)(zghz338, true);
      }
      zcbz310 = zwX(zuz312, zgaz326);
    
    
      goto finish_match_48;
    }
  case_49: ;
    {
      uint64_t zgaz328;
      {
        RECREATE(sail_int)(&zghz333);
        CONVERT_OF(sail_int, mach_int)(&zghz333, INT64_C(32));
        RECREATE(lbits)(&zghz334);
        CONVERT_OF(lbits, fbits)(&zghz334, UINT64_C(0b0), UINT64_C(1) , true);
        RECREATE(lbits)(&zghz335);
        zextzz(&zghz335, zghz333, zghz334);
        zgaz328 = CONVERT_OF(fbits, lbits)(zghz335, true);
      }
      zcbz310 = zwX(zuz312, zgaz328);
    
      goto finish_match_48;
    }
  case_50: ;
    sail_match_failure("execute");
  finish_match_48: ;
  
  
  
  
  
  
    goto finish_match_37;
  }
case_47: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_51;
    uint64_t zuz315;
    zuz315 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz316;
    zuz316 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz317;
    zuz317 = zmergez3var.zRTYPE.ztup2;
    if ((zMUL != zmergez3var.zRTYPE.ztup3)) goto case_51;
    zcbz310 = print_endline("execute MUL\n");
  
  
  
    goto finish_match_37;
  }
case_51: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_52;
    uint64_t zuz318;
    zuz318 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz319;
    zuz319 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz320;
    zuz320 = zmergez3var.zRTYPE.ztup2;
    if ((zDIV != zmergez3var.zRTYPE.ztup3)) goto case_52;
    zcbz310 = print_endline("execute DIV\n");
  
  
  
    goto finish_match_37;
  }
case_52: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_53;
    uint64_t zuz321;
    zuz321 = zmergez3var.zRTYPE.ztup0;
    uint64_t zuz322;
    zuz322 = zmergez3var.zRTYPE.ztup1;
    uint64_t zuz323;
    zuz323 = zmergez3var.zRTYPE.ztup2;
    if ((zREM != zmergez3var.zRTYPE.ztup3)) goto case_53;
    zcbz310 = print_endline("execute REM\n");
  
  
  
    goto finish_match_37;
  }
case_53: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_54;
    uint64_t zimm;
    zimm = zmergez3var.zITYPE.ztup0;
    uint64_t zuz324;
    zuz324 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz325;
    zuz325 = zmergez3var.zITYPE.ztup2;
    if ((zADDI != zmergez3var.zITYPE.ztup3)) goto case_54;
    zcbz310 = print_endline("execute ADDI\n");
  
  
  
    goto finish_match_37;
  }
case_54: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_55;
    uint64_t zuz326;
    zuz326 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz327;
    zuz327 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz328;
    zuz328 = zmergez3var.zITYPE.ztup2;
    if ((zSLTI != zmergez3var.zITYPE.ztup3)) goto case_55;
    zcbz310 = print_endline("execute SLTI\n");
  
  
  
    goto finish_match_37;
  }
case_55: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_56;
    uint64_t zuz329;
    zuz329 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz330;
    zuz330 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz331;
    zuz331 = zmergez3var.zITYPE.ztup2;
    if ((zANDI != zmergez3var.zITYPE.ztup3)) goto case_56;
    zcbz310 = print_endline("execute ANDI\n");
  
  
  
    goto finish_match_37;
  }
case_56: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_57;
    uint64_t zuz332;
    zuz332 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz333;
    zuz333 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz334;
    zuz334 = zmergez3var.zITYPE.ztup2;
    if ((zORI != zmergez3var.zITYPE.ztup3)) goto case_57;
    zcbz310 = print_endline("execute ORI\n");
  
  
  
    goto finish_match_37;
  }
case_57: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_58;
    uint64_t zuz335;
    zuz335 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz336;
    zuz336 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz337;
    zuz337 = zmergez3var.zITYPE.ztup2;
    if ((zXORI != zmergez3var.zITYPE.ztup3)) goto case_58;
    zcbz310 = print_endline("execute XORI\n");
  
  
  
    goto finish_match_37;
  }
case_58: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_59;
    uint64_t zuz338;
    zuz338 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz339;
    zuz339 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz340;
    zuz340 = zmergez3var.zITYPE.ztup2;
    if ((zJALR != zmergez3var.zITYPE.ztup3)) goto case_59;
    zcbz310 = print_endline("execute JALR\n");
  
  
  
    goto finish_match_37;
  }
case_59: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_60;
    uint64_t zuz341;
    zuz341 = zmergez3var.zITYPE.ztup0;
    uint64_t zuz342;
    zuz342 = zmergez3var.zITYPE.ztup1;
    uint64_t zuz343;
    zuz343 = zmergez3var.zITYPE.ztup2;
    if ((zLW != zmergez3var.zITYPE.ztup3)) goto case_60;
    zcbz310 = print_endline("execute LW\n");
  
  
  
    goto finish_match_37;
  }
case_60: ;
  {
    if (zmergez3var.kind != Kind_zSTYPE) goto case_61;
    uint64_t zimm2;
    zimm2 = zmergez3var.zSTYPE.ztup0;
    uint64_t zuz344;
    zuz344 = zmergez3var.zSTYPE.ztup1;
    uint64_t zuz345;
    zuz345 = zmergez3var.zSTYPE.ztup2;
    uint64_t zimm1;
    zimm1 = zmergez3var.zSTYPE.ztup3;
    if ((zSW != zmergez3var.zSTYPE.ztup4)) goto case_61;
    zcbz310 = print_endline("execute SW\n");
  
  
  
  
    goto finish_match_37;
  }
case_61: ;
  {
    if (zmergez3var.kind != Kind_zBTYPE) goto case_62;
    uint64_t zimm4;
    zimm4 = zmergez3var.zBTYPE.ztup0;
    uint64_t zuz346;
    zuz346 = zmergez3var.zBTYPE.ztup1;
    uint64_t zuz347;
    zuz347 = zmergez3var.zBTYPE.ztup2;
    uint64_t zuz348;
    zuz348 = zmergez3var.zBTYPE.ztup3;
    uint64_t zuz349;
    zuz349 = zmergez3var.zBTYPE.ztup4;
    uint64_t zimm3;
    zimm3 = zmergez3var.zBTYPE.ztup5;
    if ((zBEQ != zmergez3var.zBTYPE.ztup6)) goto case_62;
    zcbz310 = print_endline("execute BEQ\n");
  
  
  
  
  
  
    goto finish_match_37;
  }
case_62: ;
  {
    if (zmergez3var.kind != Kind_zBTYPE) goto case_63;
    uint64_t zuz350;
    zuz350 = zmergez3var.zBTYPE.ztup0;
    uint64_t zuz351;
    zuz351 = zmergez3var.zBTYPE.ztup1;
    uint64_t zuz352;
    zuz352 = zmergez3var.zBTYPE.ztup2;
    uint64_t zuz353;
    zuz353 = zmergez3var.zBTYPE.ztup3;
    uint64_t zuz354;
    zuz354 = zmergez3var.zBTYPE.ztup4;
    uint64_t zuz355;
    zuz355 = zmergez3var.zBTYPE.ztup5;
    if ((zBNE != zmergez3var.zBTYPE.ztup6)) goto case_63;
    zcbz310 = print_endline("execute BNE\n");
  
  
  
  
  
  
    goto finish_match_37;
  }
case_63: ;
  {
    if (zmergez3var.kind != Kind_zUTYPE) goto case_64;
    uint64_t zuz356;
    zuz356 = zmergez3var.zUTYPE.ztup0;
    uint64_t zuz357;
    zuz357 = zmergez3var.zUTYPE.ztup1;
    if ((zLUI != zmergez3var.zUTYPE.ztup2)) goto case_64;
    zcbz310 = print_endline("execute LUI\n");
  
  
    goto finish_match_37;
  }
case_64: ;
  {
    if (zmergez3var.kind != Kind_zUTYPE) goto case_65;
    uint64_t zuz358;
    zuz358 = zmergez3var.zUTYPE.ztup0;
    uint64_t zuz359;
    zuz359 = zmergez3var.zUTYPE.ztup1;
    if ((zAUIPC != zmergez3var.zUTYPE.ztup2)) goto case_65;
    zcbz310 = print_endline("execute AUIPC\n");
  
  
    goto finish_match_37;
  }
case_65: ;
  {
    if (zmergez3var.kind != Kind_zJTYPE) goto case_66;
    uint64_t zuz360;
    zuz360 = zmergez3var.zJTYPE.ztup0;
    uint64_t zuz361;
    zuz361 = zmergez3var.zJTYPE.ztup1;
    uint64_t zuz362;
    zuz362 = zmergez3var.zJTYPE.ztup2;
    uint64_t zuz363;
    zuz363 = zmergez3var.zJTYPE.ztup3;
    uint64_t zuz364;
    zuz364 = zmergez3var.zJTYPE.ztup4;
    if ((zJAL != zmergez3var.zJTYPE.ztup5)) goto case_66;
    zcbz310 = print_endline("execute JAL\n");
  
  
  
  
  
    goto finish_match_37;
  }
case_66: ;
  sail_match_failure("execute");
finish_match_37: ;
end_function_67: ;
  return zcbz310;
end_block_exception_68: ;

  return UNIT;
}



void finish_zexecute(void)
{
  KILL(lbits)(&zghz362);
  KILL(lbits)(&zghz361);
  KILL(sail_int)(&zghz360);
  KILL(lbits)(&zghz359);
  KILL(lbits)(&zghz358);
  KILL(sail_int)(&zghz357);
  KILL(lbits)(&zghz356);
  KILL(lbits)(&zghz355);
  KILL(sail_int)(&zghz354);
  KILL(lbits)(&zghz353);
  KILL(lbits)(&zghz352);
  KILL(sail_int)(&zghz351);
  KILL(lbits)(&zghz350);
  KILL(lbits)(&zghz349);
  KILL(sail_int)(&zghz348);
  KILL(lbits)(&zghz347);
  KILL(lbits)(&zghz346);
  KILL(sail_int)(&zghz345);
  KILL(lbits)(&zghz344);
  KILL(lbits)(&zghz343);
  KILL(lbits)(&zghz342);
  KILL(lbits)(&zghz341);
  KILL(lbits)(&zghz340);
  KILL(sail_int)(&zghz339);
  KILL(lbits)(&zghz338);
  KILL(lbits)(&zghz337);
  KILL(sail_int)(&zghz336);
  KILL(lbits)(&zghz335);
  KILL(lbits)(&zghz334);
  KILL(sail_int)(&zghz333);
}


















void zdecode(struct zoption *zcbz311, uint64_t zmergez3var)
{
  __label__ case_71, case_72, case_73, case_74, case_75, case_76, case_77, case_78, case_79, case_80, case_81, case_82, case_83, case_84, case_85, case_86, case_87, case_88, case_89, case_90, case_91, finish_match_70, end_function_92, end_block_exception_93, end_function_113;

  struct zoption zgsz398;
  CREATE(zoption)(&zgsz398);
  {
    uint64_t zv__0;
    zv__0 = zmergez3var;
    bool zgaz332;
    {
      uint64_t zgaz330;
      zgaz330 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__0 >> INT64_C(25)));
      zgaz332 = (zgaz330 == UINT64_C(0b0000000));
    
    }
    bool zgsz399;
    if (zgaz332) {
    uint64_t zgaz331;
    zgaz331 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__0 >> INT64_C(0)));
    zgsz399 = (zgaz331 == UINT64_C(0b0110011));
  
    } else {  zgsz399 = false;  }
    bool zgsz3101;
    zgsz3101 = zgsz399;
  
    if (!(zgsz3101)) {
  
    goto case_71;
    }
    uint64_t zrs2;
    zrs2 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(20)));
    uint64_t zrs1;
    zrs1 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(15)));
    uint64_t zrd;
    zrd = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__0 >> INT64_C(7)));
    struct zast zgaz329;
    CREATE(zast)(&zgaz329);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3100;
      zgsz3100.ztup0 = zrs2;
      zgsz3100.ztup1 = zrs1;
      zgsz3100.ztup2 = zrd;
      zgsz3100.ztup3 = zADD;
      zRTYPE(&zgaz329, zgsz3100);
    
    }
    {
      struct zast zgsz3204;
      CREATE(zast)(&zgsz3204);
      COPY(zast)(&zgsz3204, zgaz329);
      zSomez3z5unionz0zzast(&zgsz398, zgsz3204);
      KILL(zast)(&zgsz3204);
    }
    KILL(zast)(&zgaz329);
  
  
  
  
    goto finish_match_70;
  }
case_71: ;
  {
    uint64_t zv__3;
    zv__3 = zmergez3var;
    bool zgaz336;
    {
      uint64_t zgaz334;
      zgaz334 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__3 >> INT64_C(25)));
      zgaz336 = (zgaz334 == UINT64_C(0b0000000));
    
    }
    bool zgsz3102;
    if (zgaz336) {
    uint64_t zgaz335;
    zgaz335 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__3 >> INT64_C(0)));
    zgsz3102 = (zgaz335 == UINT64_C(0b0110011));
  
    } else {  zgsz3102 = false;  }
    bool zgsz3104;
    zgsz3104 = zgsz3102;
  
    if (!(zgsz3104)) {
  
    goto case_72;
    }
    uint64_t zuz365;
    zuz365 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(20)));
    uint64_t zuz366;
    zuz366 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(15)));
    uint64_t zuz367;
    zuz367 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__3 >> INT64_C(7)));
    struct zast zgaz333;
    CREATE(zast)(&zgaz333);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3103;
      zgsz3103.ztup0 = zuz365;
      zgsz3103.ztup1 = zuz366;
      zgsz3103.ztup2 = zuz367;
      zgsz3103.ztup3 = zAND;
      zRTYPE(&zgaz333, zgsz3103);
    
    }
    {
      struct zast zgsz3205;
      CREATE(zast)(&zgsz3205);
      COPY(zast)(&zgsz3205, zgaz333);
      zSomez3z5unionz0zzast(&zgsz398, zgsz3205);
      KILL(zast)(&zgsz3205);
    }
    KILL(zast)(&zgaz333);
  
  
  
  
    goto finish_match_70;
  }
case_72: ;
  {
    uint64_t zv__6;
    zv__6 = zmergez3var;
    bool zgaz340;
    {
      uint64_t zgaz338;
      zgaz338 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__6 >> INT64_C(25)));
      zgaz340 = (zgaz338 == UINT64_C(0b0000000));
    
    }
    bool zgsz3105;
    if (zgaz340) {
    uint64_t zgaz339;
    zgaz339 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__6 >> INT64_C(0)));
    zgsz3105 = (zgaz339 == UINT64_C(0b0110011));
  
    } else {  zgsz3105 = false;  }
    bool zgsz3107;
    zgsz3107 = zgsz3105;
  
    if (!(zgsz3107)) {
  
    goto case_73;
    }
    uint64_t zuz368;
    zuz368 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(20)));
    uint64_t zuz369;
    zuz369 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(15)));
    uint64_t zuz370;
    zuz370 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__6 >> INT64_C(7)));
    struct zast zgaz337;
    CREATE(zast)(&zgaz337);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3106;
      zgsz3106.ztup0 = zuz368;
      zgsz3106.ztup1 = zuz369;
      zgsz3106.ztup2 = zuz370;
      zgsz3106.ztup3 = zOR;
      zRTYPE(&zgaz337, zgsz3106);
    
    }
    {
      struct zast zgsz3206;
      CREATE(zast)(&zgsz3206);
      COPY(zast)(&zgsz3206, zgaz337);
      zSomez3z5unionz0zzast(&zgsz398, zgsz3206);
      KILL(zast)(&zgsz3206);
    }
    KILL(zast)(&zgaz337);
  
  
  
  
    goto finish_match_70;
  }
case_73: ;
  {
    uint64_t zv__9;
    zv__9 = zmergez3var;
    bool zgaz344;
    {
      uint64_t zgaz342;
      zgaz342 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__9 >> INT64_C(25)));
      zgaz344 = (zgaz342 == UINT64_C(0b0000000));
    
    }
    bool zgsz3108;
    if (zgaz344) {
    uint64_t zgaz343;
    zgaz343 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__9 >> INT64_C(0)));
    zgsz3108 = (zgaz343 == UINT64_C(0b0110011));
  
    } else {  zgsz3108 = false;  }
    bool zgsz3110;
    zgsz3110 = zgsz3108;
  
    if (!(zgsz3110)) {
  
    goto case_74;
    }
    uint64_t zuz371;
    zuz371 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(20)));
    uint64_t zuz372;
    zuz372 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(15)));
    uint64_t zuz373;
    zuz373 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__9 >> INT64_C(7)));
    struct zast zgaz341;
    CREATE(zast)(&zgaz341);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3109;
      zgsz3109.ztup0 = zuz371;
      zgsz3109.ztup1 = zuz372;
      zgsz3109.ztup2 = zuz373;
      zgsz3109.ztup3 = zXOR;
      zRTYPE(&zgaz341, zgsz3109);
    
    }
    {
      struct zast zgsz3207;
      CREATE(zast)(&zgsz3207);
      COPY(zast)(&zgsz3207, zgaz341);
      zSomez3z5unionz0zzast(&zgsz398, zgsz3207);
      KILL(zast)(&zgsz3207);
    }
    KILL(zast)(&zgaz341);
  
  
  
  
    goto finish_match_70;
  }
case_74: ;
  {
    uint64_t zv__12;
    zv__12 = zmergez3var;
    bool zgaz348;
    {
      uint64_t zgaz346;
      zgaz346 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__12 >> INT64_C(25)));
      zgaz348 = (zgaz346 == UINT64_C(0b0000001));
    
    }
    bool zgsz3111;
    if (zgaz348) {
    uint64_t zgaz347;
    zgaz347 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__12 >> INT64_C(0)));
    zgsz3111 = (zgaz347 == UINT64_C(0b0110011));
  
    } else {  zgsz3111 = false;  }
    bool zgsz3113;
    zgsz3113 = zgsz3111;
  
    if (!(zgsz3113)) {
  
    goto case_75;
    }
    uint64_t zuz374;
    zuz374 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(20)));
    uint64_t zuz375;
    zuz375 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(15)));
    uint64_t zuz376;
    zuz376 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__12 >> INT64_C(7)));
    struct zast zgaz345;
    CREATE(zast)(&zgaz345);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3112;
      zgsz3112.ztup0 = zuz374;
      zgsz3112.ztup1 = zuz375;
      zgsz3112.ztup2 = zuz376;
      zgsz3112.ztup3 = zMUL;
      zRTYPE(&zgaz345, zgsz3112);
    
    }
    {
      struct zast zgsz3208;
      CREATE(zast)(&zgsz3208);
      COPY(zast)(&zgsz3208, zgaz345);
      zSomez3z5unionz0zzast(&zgsz398, zgsz3208);
      KILL(zast)(&zgsz3208);
    }
    KILL(zast)(&zgaz345);
  
  
  
  
    goto finish_match_70;
  }
case_75: ;
  {
    uint64_t zv__15;
    zv__15 = zmergez3var;
    bool zgaz352;
    {
      uint64_t zgaz350;
      zgaz350 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__15 >> INT64_C(25)));
      zgaz352 = (zgaz350 == UINT64_C(0b0000001));
    
    }
    bool zgsz3114;
    if (zgaz352) {
    uint64_t zgaz351;
    zgaz351 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__15 >> INT64_C(0)));
    zgsz3114 = (zgaz351 == UINT64_C(0b0110011));
  
    } else {  zgsz3114 = false;  }
    bool zgsz3116;
    zgsz3116 = zgsz3114;
  
    if (!(zgsz3116)) {
  
    goto case_76;
    }
    uint64_t zuz377;
    zuz377 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(20)));
    uint64_t zuz378;
    zuz378 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(15)));
    uint64_t zuz379;
    zuz379 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__15 >> INT64_C(7)));
    struct zast zgaz349;
    CREATE(zast)(&zgaz349);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3115;
      zgsz3115.ztup0 = zuz377;
      zgsz3115.ztup1 = zuz378;
      zgsz3115.ztup2 = zuz379;
      zgsz3115.ztup3 = zDIV;
      zRTYPE(&zgaz349, zgsz3115);
    
    }
    {
      struct zast zgsz3209;
      CREATE(zast)(&zgsz3209);
      COPY(zast)(&zgsz3209, zgaz349);
      zSomez3z5unionz0zzast(&zgsz398, zgsz3209);
      KILL(zast)(&zgsz3209);
    }
    KILL(zast)(&zgaz349);
  
  
  
  
    goto finish_match_70;
  }
case_76: ;
  {
    uint64_t zv__18;
    zv__18 = zmergez3var;
    bool zgaz356;
    {
      uint64_t zgaz354;
      zgaz354 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__18 >> INT64_C(25)));
      zgaz356 = (zgaz354 == UINT64_C(0b0000001));
    
    }
    bool zgsz3117;
    if (zgaz356) {
    uint64_t zgaz355;
    zgaz355 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__18 >> INT64_C(0)));
    zgsz3117 = (zgaz355 == UINT64_C(0b0110011));
  
    } else {  zgsz3117 = false;  }
    bool zgsz3119;
    zgsz3119 = zgsz3117;
  
    if (!(zgsz3119)) {
  
    goto case_77;
    }
    uint64_t zuz380;
    zuz380 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(20)));
    uint64_t zuz381;
    zuz381 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(15)));
    uint64_t zuz382;
    zuz382 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__18 >> INT64_C(7)));
    struct zast zgaz353;
    CREATE(zast)(&zgaz353);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3118;
      zgsz3118.ztup0 = zuz380;
      zgsz3118.ztup1 = zuz381;
      zgsz3118.ztup2 = zuz382;
      zgsz3118.ztup3 = zREM;
      zRTYPE(&zgaz353, zgsz3118);
    
    }
    {
      struct zast zgsz3210;
      CREATE(zast)(&zgsz3210);
      COPY(zast)(&zgsz3210, zgaz353);
      zSomez3z5unionz0zzast(&zgsz398, zgsz3210);
      KILL(zast)(&zgsz3210);
    }
    KILL(zast)(&zgaz353);
  
  
  
  
    goto finish_match_70;
  }
case_77: ;
  {
    uint64_t zv__21;
    zv__21 = zmergez3var;
    uint64_t zgaz358;
    zgaz358 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__21 >> INT64_C(0)));
    bool zgsz3121;
    zgsz3121 = (zgaz358 == UINT64_C(0b0010011));
  
    if (!(zgsz3121)) {
  
    goto case_78;
    }
    uint64_t zimm;
    zimm = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__21 >> INT64_C(20)));
    uint64_t zuz383;
    zuz383 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__21 >> INT64_C(15)));
    uint64_t zuz384;
    zuz384 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__21 >> INT64_C(7)));
    uint64_t zimmshadowz30;
    zimmshadowz30 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__21 >> INT64_C(20)));
    struct zast zgaz357;
    CREATE(zast)(&zgaz357);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3120;
      zgsz3120.ztup0 = zimmshadowz30;
      zgsz3120.ztup1 = zuz383;
      zgsz3120.ztup2 = zuz384;
      zgsz3120.ztup3 = zADDI;
      zITYPE(&zgaz357, zgsz3120);
    
    }
    {
      struct zast zgsz3211;
      CREATE(zast)(&zgsz3211);
      COPY(zast)(&zgsz3211, zgaz357);
      zSomez3z5unionz0zzast(&zgsz398, zgsz3211);
      KILL(zast)(&zgsz3211);
    }
    KILL(zast)(&zgaz357);
  
  
  
  
  
    goto finish_match_70;
  }
case_78: ;
  {
    uint64_t zv__23;
    zv__23 = zmergez3var;
    uint64_t zgaz360;
    zgaz360 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__23 >> INT64_C(0)));
    bool zgsz3123;
    zgsz3123 = (zgaz360 == UINT64_C(0b0010011));
  
    if (!(zgsz3123)) {
  
    goto case_79;
    }
    uint64_t zuz385;
    zuz385 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__23 >> INT64_C(20)));
    uint64_t zuz386;
    zuz386 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__23 >> INT64_C(15)));
    uint64_t zuz387;
    zuz387 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__23 >> INT64_C(7)));
    uint64_t zimmshadowz31;
    zimmshadowz31 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__23 >> INT64_C(20)));
    struct zast zgaz359;
    CREATE(zast)(&zgaz359);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3122;
      zgsz3122.ztup0 = zimmshadowz31;
      zgsz3122.ztup1 = zuz386;
      zgsz3122.ztup2 = zuz387;
      zgsz3122.ztup3 = zSLTI;
      zITYPE(&zgaz359, zgsz3122);
    
    }
    {
      struct zast zgsz3212;
      CREATE(zast)(&zgsz3212);
      COPY(zast)(&zgsz3212, zgaz359);
      zSomez3z5unionz0zzast(&zgsz398, zgsz3212);
      KILL(zast)(&zgsz3212);
    }
    KILL(zast)(&zgaz359);
  
  
  
  
  
    goto finish_match_70;
  }
case_79: ;
  {
    uint64_t zv__25;
    zv__25 = zmergez3var;
    uint64_t zgaz362;
    zgaz362 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__25 >> INT64_C(0)));
    bool zgsz3125;
    zgsz3125 = (zgaz362 == UINT64_C(0b0010011));
  
    if (!(zgsz3125)) {
  
    goto case_80;
    }
    uint64_t zuz388;
    zuz388 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__25 >> INT64_C(20)));
    uint64_t zuz389;
    zuz389 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__25 >> INT64_C(15)));
    uint64_t zuz390;
    zuz390 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__25 >> INT64_C(7)));
    uint64_t zimmshadowz32;
    zimmshadowz32 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__25 >> INT64_C(20)));
    struct zast zgaz361;
    CREATE(zast)(&zgaz361);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3124;
      zgsz3124.ztup0 = zimmshadowz32;
      zgsz3124.ztup1 = zuz389;
      zgsz3124.ztup2 = zuz390;
      zgsz3124.ztup3 = zANDI;
      zITYPE(&zgaz361, zgsz3124);
    
    }
    {
      struct zast zgsz3213;
      CREATE(zast)(&zgsz3213);
      COPY(zast)(&zgsz3213, zgaz361);
      zSomez3z5unionz0zzast(&zgsz398, zgsz3213);
      KILL(zast)(&zgsz3213);
    }
    KILL(zast)(&zgaz361);
  
  
  
  
  
    goto finish_match_70;
  }
case_80: ;
  {
    uint64_t zv__27;
    zv__27 = zmergez3var;
    uint64_t zgaz364;
    zgaz364 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__27 >> INT64_C(0)));
    bool zgsz3127;
    zgsz3127 = (zgaz364 == UINT64_C(0b0010011));
  
    if (!(zgsz3127)) {
  
    goto case_81;
    }
    uint64_t zuz391;
    zuz391 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__27 >> INT64_C(20)));
    uint64_t zuz392;
    zuz392 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__27 >> INT64_C(15)));
    uint64_t zuz393;
    zuz393 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__27 >> INT64_C(7)));
    uint64_t zimmshadowz33;
    zimmshadowz33 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__27 >> INT64_C(20)));
    struct zast zgaz363;
    CREATE(zast)(&zgaz363);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3126;
      zgsz3126.ztup0 = zimmshadowz33;
      zgsz3126.ztup1 = zuz392;
      zgsz3126.ztup2 = zuz393;
      zgsz3126.ztup3 = zORI;
      zITYPE(&zgaz363, zgsz3126);
    
    }
    {
      struct zast zgsz3214;
      CREATE(zast)(&zgsz3214);
      COPY(zast)(&zgsz3214, zgaz363);
      zSomez3z5unionz0zzast(&zgsz398, zgsz3214);
      KILL(zast)(&zgsz3214);
    }
    KILL(zast)(&zgaz363);
  
  
  
  
  
    goto finish_match_70;
  }
case_81: ;
  {
    uint64_t zv__29;
    zv__29 = zmergez3var;
    uint64_t zgaz366;
    zgaz366 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__29 >> INT64_C(0)));
    bool zgsz3129;
    zgsz3129 = (zgaz366 == UINT64_C(0b0010011));
  
    if (!(zgsz3129)) {
  
    goto case_82;
    }
    uint64_t zuz394;
    zuz394 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__29 >> INT64_C(20)));
    uint64_t zuz395;
    zuz395 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__29 >> INT64_C(15)));
    uint64_t zuz396;
    zuz396 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__29 >> INT64_C(7)));
    uint64_t zimmshadowz34;
    zimmshadowz34 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__29 >> INT64_C(20)));
    struct zast zgaz365;
    CREATE(zast)(&zgaz365);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3128;
      zgsz3128.ztup0 = zimmshadowz34;
      zgsz3128.ztup1 = zuz395;
      zgsz3128.ztup2 = zuz396;
      zgsz3128.ztup3 = zXORI;
      zITYPE(&zgaz365, zgsz3128);
    
    }
    {
      struct zast zgsz3215;
      CREATE(zast)(&zgsz3215);
      COPY(zast)(&zgsz3215, zgaz365);
      zSomez3z5unionz0zzast(&zgsz398, zgsz3215);
      KILL(zast)(&zgsz3215);
    }
    KILL(zast)(&zgaz365);
  
  
  
  
  
    goto finish_match_70;
  }
case_82: ;
  {
    uint64_t zv__31;
    zv__31 = zmergez3var;
    uint64_t zgaz368;
    zgaz368 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__31 >> INT64_C(0)));
    bool zgsz3131;
    zgsz3131 = (zgaz368 == UINT64_C(0b1100111));
  
    if (!(zgsz3131)) {
  
    goto case_83;
    }
    uint64_t zuz397;
    zuz397 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__31 >> INT64_C(20)));
    uint64_t zuz398;
    zuz398 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__31 >> INT64_C(15)));
    uint64_t zuz399;
    zuz399 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__31 >> INT64_C(7)));
    uint64_t zimmshadowz35;
    zimmshadowz35 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__31 >> INT64_C(20)));
    struct zast zgaz367;
    CREATE(zast)(&zgaz367);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3130;
      zgsz3130.ztup0 = zimmshadowz35;
      zgsz3130.ztup1 = zuz398;
      zgsz3130.ztup2 = zuz399;
      zgsz3130.ztup3 = zJALR;
      zITYPE(&zgaz367, zgsz3130);
    
    }
    {
      struct zast zgsz3216;
      CREATE(zast)(&zgsz3216);
      COPY(zast)(&zgsz3216, zgaz367);
      zSomez3z5unionz0zzast(&zgsz398, zgsz3216);
      KILL(zast)(&zgsz3216);
    }
    KILL(zast)(&zgaz367);
  
  
  
  
  
    goto finish_match_70;
  }
case_83: ;
  {
    uint64_t zv__33;
    zv__33 = zmergez3var;
    uint64_t zgaz370;
    zgaz370 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__33 >> INT64_C(0)));
    bool zgsz3133;
    zgsz3133 = (zgaz370 == UINT64_C(0b0000011));
  
    if (!(zgsz3133)) {
  
    goto case_84;
    }
    uint64_t zuz3100;
    zuz3100 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__33 >> INT64_C(20)));
    uint64_t zuz3101;
    zuz3101 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__33 >> INT64_C(15)));
    uint64_t zuz3102;
    zuz3102 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__33 >> INT64_C(7)));
    uint64_t zimmshadowz36;
    zimmshadowz36 = (safe_rshift(UINT64_MAX, 64 - 12) & (zv__33 >> INT64_C(20)));
    struct zast zgaz369;
    CREATE(zast)(&zgaz369);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3132;
      zgsz3132.ztup0 = zimmshadowz36;
      zgsz3132.ztup1 = zuz3101;
      zgsz3132.ztup2 = zuz3102;
      zgsz3132.ztup3 = zLW;
      zITYPE(&zgaz369, zgsz3132);
    
    }
    {
      struct zast zgsz3217;
      CREATE(zast)(&zgsz3217);
      COPY(zast)(&zgsz3217, zgaz369);
      zSomez3z5unionz0zzast(&zgsz398, zgsz3217);
      KILL(zast)(&zgsz3217);
    }
    KILL(zast)(&zgaz369);
  
  
  
  
  
    goto finish_match_70;
  }
case_84: ;
  {
    uint64_t zv__35;
    zv__35 = zmergez3var;
    uint64_t zgaz372;
    zgaz372 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__35 >> INT64_C(0)));
    bool zgsz3135;
    zgsz3135 = (zgaz372 == UINT64_C(0b0100011));
  
    if (!(zgsz3135)) {
  
    goto case_85;
    }
    uint64_t zimm2;
    zimm2 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__35 >> INT64_C(25)));
    uint64_t zuz3103;
    zuz3103 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__35 >> INT64_C(20)));
    uint64_t zuz3104;
    zuz3104 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__35 >> INT64_C(15)));
    uint64_t zimm2shadowz37;
    zimm2shadowz37 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__35 >> INT64_C(25)));
    uint64_t zimm1;
    zimm1 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__35 >> INT64_C(7)));
    struct zast zgaz371;
    CREATE(zast)(&zgaz371);
    {
      struct ztuple_z8z5bv7zCz0z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzsopz9 zgsz3134;
      zgsz3134.ztup0 = zimm2shadowz37;
      zgsz3134.ztup1 = zuz3103;
      zgsz3134.ztup2 = zuz3104;
      zgsz3134.ztup3 = zimm1;
      zgsz3134.ztup4 = zSW;
      zSTYPE(&zgaz371, zgsz3134);
    
    }
    {
      struct zast zgsz3218;
      CREATE(zast)(&zgsz3218);
      COPY(zast)(&zgsz3218, zgaz371);
      zSomez3z5unionz0zzast(&zgsz398, zgsz3218);
      KILL(zast)(&zgsz3218);
    }
    KILL(zast)(&zgaz371);
  
  
  
  
  
  
    goto finish_match_70;
  }
case_85: ;
  {
    uint64_t zv__37;
    zv__37 = zmergez3var;
    uint64_t zgaz374;
    zgaz374 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__37 >> INT64_C(0)));
    bool zgsz3137;
    zgsz3137 = (zgaz374 == UINT64_C(0b1100011));
  
    if (!(zgsz3137)) {
  
    goto case_86;
    }
    uint64_t zimm4;
    zimm4 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__37 >> INT64_C(31)));
    uint64_t zuz3105;
    zuz3105 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__37 >> INT64_C(20)));
    uint64_t zuz3106;
    zuz3106 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__37 >> INT64_C(15)));
    uint64_t zimm4shadowz38;
    zimm4shadowz38 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__37 >> INT64_C(31)));
    uint64_t zimm3;
    zimm3 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__37 >> INT64_C(7)));
    uint64_t zuz3107;
    zuz3107 = (safe_rshift(UINT64_MAX, 64 - 6) & (zv__37 >> INT64_C(25)));
    uint64_t zuz3108;
    zuz3108 = (safe_rshift(UINT64_MAX, 64 - 4) & (zv__37 >> INT64_C(8)));
    struct zast zgaz373;
    CREATE(zast)(&zgaz373);
    {
      struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 zgsz3136;
      zgsz3136.ztup0 = zimm4shadowz38;
      zgsz3136.ztup1 = zuz3107;
      zgsz3136.ztup2 = zuz3105;
      zgsz3136.ztup3 = zuz3106;
      zgsz3136.ztup4 = zuz3108;
      zgsz3136.ztup5 = zimm3;
      zgsz3136.ztup6 = zBEQ;
      zBTYPE(&zgaz373, zgsz3136);
    
    }
    {
      struct zast zgsz3219;
      CREATE(zast)(&zgsz3219);
      COPY(zast)(&zgsz3219, zgaz373);
      zSomez3z5unionz0zzast(&zgsz398, zgsz3219);
      KILL(zast)(&zgsz3219);
    }
    KILL(zast)(&zgaz373);
  
  
  
  
  
  
  
  
    goto finish_match_70;
  }
case_86: ;
  {
    uint64_t zv__39;
    zv__39 = zmergez3var;
    uint64_t zgaz376;
    zgaz376 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__39 >> INT64_C(0)));
    bool zgsz3139;
    zgsz3139 = (zgaz376 == UINT64_C(0b1100011));
  
    if (!(zgsz3139)) {
  
    goto case_87;
    }
    uint64_t zuz3109;
    zuz3109 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__39 >> INT64_C(31)));
    uint64_t zuz3110;
    zuz3110 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__39 >> INT64_C(20)));
    uint64_t zuz3111;
    zuz3111 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__39 >> INT64_C(15)));
    uint64_t zimm4shadowz39;
    zimm4shadowz39 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__39 >> INT64_C(31)));
    uint64_t zuz3112;
    zuz3112 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__39 >> INT64_C(7)));
    uint64_t zuz3113;
    zuz3113 = (safe_rshift(UINT64_MAX, 64 - 6) & (zv__39 >> INT64_C(25)));
    uint64_t zuz3114;
    zuz3114 = (safe_rshift(UINT64_MAX, 64 - 4) & (zv__39 >> INT64_C(8)));
    struct zast zgaz375;
    CREATE(zast)(&zgaz375);
    {
      struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 zgsz3138;
      zgsz3138.ztup0 = zimm4shadowz39;
      zgsz3138.ztup1 = zuz3113;
      zgsz3138.ztup2 = zuz3110;
      zgsz3138.ztup3 = zuz3111;
      zgsz3138.ztup4 = zuz3114;
      zgsz3138.ztup5 = zuz3112;
      zgsz3138.ztup6 = zBNE;
      zBTYPE(&zgaz375, zgsz3138);
    
    }
    {
      struct zast zgsz3220;
      CREATE(zast)(&zgsz3220);
      COPY(zast)(&zgsz3220, zgaz375);
      zSomez3z5unionz0zzast(&zgsz398, zgsz3220);
      KILL(zast)(&zgsz3220);
    }
    KILL(zast)(&zgaz375);
  
  
  
  
  
  
  
  
    goto finish_match_70;
  }
case_87: ;
  {
    uint64_t zv__41;
    zv__41 = zmergez3var;
    uint64_t zgaz378;
    zgaz378 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__41 >> INT64_C(0)));
    bool zgsz3141;
    zgsz3141 = (zgaz378 == UINT64_C(0b0110111));
  
    if (!(zgsz3141)) {
  
    goto case_88;
    }
    uint64_t zuz3115;
    zuz3115 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__41 >> INT64_C(12)));
    uint64_t zuz3116;
    zuz3116 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__41 >> INT64_C(7)));
    uint64_t zimmshadowz310;
    zimmshadowz310 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__41 >> INT64_C(12)));
    struct zast zgaz377;
    CREATE(zast)(&zgaz377);
    {
      struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 zgsz3140;
      zgsz3140.ztup0 = zimmshadowz310;
      zgsz3140.ztup1 = zuz3116;
      zgsz3140.ztup2 = zLUI;
      zUTYPE(&zgaz377, zgsz3140);
    
    }
    {
      struct zast zgsz3221;
      CREATE(zast)(&zgsz3221);
      COPY(zast)(&zgsz3221, zgaz377);
      zSomez3z5unionz0zzast(&zgsz398, zgsz3221);
      KILL(zast)(&zgsz3221);
    }
    KILL(zast)(&zgaz377);
  
  
  
  
    goto finish_match_70;
  }
case_88: ;
  {
    uint64_t zv__43;
    zv__43 = zmergez3var;
    uint64_t zgaz380;
    zgaz380 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__43 >> INT64_C(0)));
    bool zgsz3143;
    zgsz3143 = (zgaz380 == UINT64_C(0b0010111));
  
    if (!(zgsz3143)) {
  
    goto case_89;
    }
    uint64_t zuz3117;
    zuz3117 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__43 >> INT64_C(12)));
    uint64_t zuz3118;
    zuz3118 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__43 >> INT64_C(7)));
    uint64_t zimmshadowz311;
    zimmshadowz311 = (safe_rshift(UINT64_MAX, 64 - 20) & (zv__43 >> INT64_C(12)));
    struct zast zgaz379;
    CREATE(zast)(&zgaz379);
    {
      struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 zgsz3142;
      zgsz3142.ztup0 = zimmshadowz311;
      zgsz3142.ztup1 = zuz3118;
      zgsz3142.ztup2 = zAUIPC;
      zUTYPE(&zgaz379, zgsz3142);
    
    }
    {
      struct zast zgsz3222;
      CREATE(zast)(&zgsz3222);
      COPY(zast)(&zgsz3222, zgaz379);
      zSomez3z5unionz0zzast(&zgsz398, zgsz3222);
      KILL(zast)(&zgsz3222);
    }
    KILL(zast)(&zgaz379);
  
  
  
  
    goto finish_match_70;
  }
case_89: ;
  {
    uint64_t zv__45;
    zv__45 = zmergez3var;
    uint64_t zgaz382;
    zgaz382 = (safe_rshift(UINT64_MAX, 64 - 7) & (zv__45 >> INT64_C(0)));
    bool zgsz3145;
    zgsz3145 = (zgaz382 == UINT64_C(0b1101111));
  
    if (!(zgsz3145)) {
  
    goto case_90;
    }
    uint64_t zuz3119;
    zuz3119 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__45 >> INT64_C(31)));
    uint64_t zuz3120;
    zuz3120 = (safe_rshift(UINT64_MAX, 64 - 5) & (zv__45 >> INT64_C(7)));
    uint64_t zimm4shadowz312;
    zimm4shadowz312 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__45 >> INT64_C(31)));
    uint64_t zuz3121;
    zuz3121 = (safe_rshift(UINT64_MAX, 64 - 8) & (zv__45 >> INT64_C(12)));
    uint64_t zuz3122;
    zuz3122 = (safe_rshift(UINT64_MAX, 64 - 1) & (zv__45 >> INT64_C(20)));
    uint64_t zuz3123;
    zuz3123 = (safe_rshift(UINT64_MAX, 64 - 10) & (zv__45 >> INT64_C(21)));
    struct zast zgaz381;
    CREATE(zast)(&zgaz381);
    {
      struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv8zCz0z5bv5zCz0z5enumz0zzjopz9 zgsz3144;
      zgsz3144.ztup0 = zimm4shadowz312;
      zgsz3144.ztup1 = zuz3123;
      zgsz3144.ztup2 = zuz3122;
      zgsz3144.ztup3 = zuz3121;
      zgsz3144.ztup4 = zuz3120;
      zgsz3144.ztup5 = zJAL;
      zJTYPE(&zgaz381, zgsz3144);
    
    }
    {
      struct zast zgsz3223;
      CREATE(zast)(&zgsz3223);
      COPY(zast)(&zgsz3223, zgaz381);
      zSomez3z5unionz0zzast(&zgsz398, zgsz3223);
      KILL(zast)(&zgsz3223);
    }
    KILL(zast)(&zgaz381);
  
  
  
  
  
  
  
    goto finish_match_70;
  }
case_90: ;
  {
    uint64_t zv__47;
    zv__47 = zmergez3var;
    bool zgsz3146;
    zgsz3146 = (zv__47 == UINT64_C(0x00100073));
    if (!(zgsz3146)) {
  
    goto case_91;
    }
    struct zast zgaz383;
    CREATE(zast)(&zgaz383);
    zEBREAK(&zgaz383, UNIT);
    {
      struct zast zgsz3224;
      CREATE(zast)(&zgsz3224);
      COPY(zast)(&zgsz3224, zgaz383);
      zSomez3z5unionz0zzast(&zgsz398, zgsz3224);
      KILL(zast)(&zgsz3224);
    }
    KILL(zast)(&zgaz383);
  
    goto finish_match_70;
  }
case_91: ;
  sail_match_failure("decode");
finish_match_70: ;
  COPY(zoption)((*(&zcbz311)), zgsz398);
  KILL(zoption)(&zgsz398);
end_function_92: ;
  goto end_function_113;
end_block_exception_93: ;
  goto end_function_113;
end_function_113: ;
}



uint64_t zread_mem(uint64_t);

sail_int zghz363;
sail_int zghz364;
lbits zghz365;
lbits zghz366;
lbits zghz367;
lbits zghz368;
sail_int zghz369;
lbits zghz370;

void startup_zread_mem(void)
{
  CREATE(sail_int)(&zghz363);
  CREATE(sail_int)(&zghz364);
  CREATE(lbits)(&zghz365);
  CREATE(lbits)(&zghz366);
  CREATE(lbits)(&zghz367);
  CREATE(lbits)(&zghz368);
  CREATE(sail_int)(&zghz369);
  CREATE(lbits)(&zghz370);
}

uint64_t zread_mem(uint64_t zaddr)
{
  __label__ end_function_95, end_block_exception_96;

  uint64_t zcbz312;
  uint64_t zgaz384;
  {
    RECREATE(lbits)(&zghz368);
    CONVERT_OF(lbits, fbits)(&zghz368, UINT64_C(0x0), UINT64_C(4) , true);
    RECREATE(sail_int)(&zghz369);
    CONVERT_OF(sail_int, mach_int)(&zghz369, INT64_C(32));
    RECREATE(lbits)(&zghz370);
    zero_extend(&zghz370, zghz368, zghz369);
    zgaz384 = CONVERT_OF(fbits, lbits)(zghz370, true);
  }
  {
    RECREATE(sail_int)(&zghz363);
    CONVERT_OF(sail_int, mach_int)(&zghz363, INT64_C(32));
    RECREATE(sail_int)(&zghz364);
    CONVERT_OF(sail_int, mach_int)(&zghz364, INT64_C(4));
    RECREATE(lbits)(&zghz365);
    CONVERT_OF(lbits, fbits)(&zghz365, zgaz384, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz366);
    CONVERT_OF(lbits, fbits)(&zghz366, zaddr, UINT64_C(32) , true);
    RECREATE(lbits)(&zghz367);
    read_ram(&zghz367, zghz363, zghz364, zghz365, zghz366);
    zcbz312 = CONVERT_OF(fbits, lbits)(zghz367, true);
  }

end_function_95: ;
  return zcbz312;
end_block_exception_96: ;

  return UINT64_C(0xdeadc0de);
}



void finish_zread_mem(void)
{
  KILL(lbits)(&zghz370);
  KILL(sail_int)(&zghz369);
  KILL(lbits)(&zghz368);
  KILL(lbits)(&zghz367);
  KILL(lbits)(&zghz366);
  KILL(lbits)(&zghz365);
  KILL(sail_int)(&zghz364);
  KILL(sail_int)(&zghz363);
}

unit zfde_loop(unit);

lbits zghz371;
lbits zghz372;

void startup_zfde_loop(void)
{
  CREATE(lbits)(&zghz371);
  CREATE(lbits)(&zghz372);
}












unit zfde_loop(unit zgsz3155)
{
  __label__ while_98, wend_99, end_function_105, end_block_exception_106;

  unit zcbz313;
  bool zcontinue_loop;
  zcontinue_loop = true;
  bool zgsz3166;
  unit zgsz3167;
while_98: ;
  {
    zgsz3166 = zcontinue_loop;
    if (!(zgsz3166)) goto wend_99;
    uint64_t zinstruction;
    {
      uint64_t zgaz385;
      zgaz385 = *(&zPC);
      zinstruction = zread_mem(zgaz385);
    
    }
    {
      unit zgsz3164;
      {
        RECREATE(lbits)(&zghz372);
        CONVERT_OF(lbits, fbits)(&zghz372, zinstruction, UINT64_C(32) , true);
        zgsz3164 = print_bits("Instruction = ", zghz372);
      }
    }
    {
      __label__ case_101, case_102, case_103, case_104, finish_match_100;

      struct zoption zdecoded_instruction;
      CREATE(zoption)(&zdecoded_instruction);
      zdecode(&zdecoded_instruction, zinstruction);
      unit zgsz3156;
      {
        if (zdecoded_instruction.kind != Kind_zSomez3z5unionz0zzast) goto case_101;
        if (zdecoded_instruction.zSomez3z5unionz0zzast.kind != Kind_zEBREAK) goto case_101;
        zcontinue_loop = false;
        zgsz3156 = UNIT;
        goto finish_match_100;
      }
    case_101: ;
      {
        if (zdecoded_instruction.kind != Kind_zSomez3z5unionz0zzast) goto case_102;
        struct zast zinst;
        CREATE(zast)(&zinst);
        COPY(zast)(&zinst, zdecoded_instruction.zSomez3z5unionz0zzast);
        zgsz3156 = zexecute(zinst);
        KILL(zast)(&zinst);
        goto finish_match_100;
      }
    case_102: ;
      {
        if (zdecoded_instruction.kind != Kind_zNone) goto case_103;
        zgsz3156 = print_endline("instruction is None()");
        goto finish_match_100;
      }
    case_103: ;
      {
        zgsz3156 = print_endline("decoding the instruction resulted in something unexpected");
        goto finish_match_100;
      }
    case_104: ;
      sail_match_failure("fde_loop");
    finish_match_100: ;
      unit zgsz3163;
      zgsz3163 = zgsz3156;
    
      KILL(zoption)(&zdecoded_instruction);
    }
    {
      unit zgsz3161;
      {
        RECREATE(lbits)(&zghz371);
        CONVERT_OF(lbits, fbits)(&zghz371, zPC, UINT64_C(32) , true);
        zgsz3161 = print_bits("PC in fde_loop = ", zghz371);
      }
    }
    zgsz3167 = zinc_PC(UNIT);
  
    goto while_98;
  }
wend_99: ;
  zcbz313 = UNIT;

end_function_105: ;
  return zcbz313;
end_block_exception_106: ;

  return UNIT;
}



void finish_zfde_loop(void)
{
  KILL(lbits)(&zghz372);
  KILL(lbits)(&zghz371);
}

unit zmain(unit);

lbits zghz373;
lbits zghz374;
sail_int zghz375;
sail_int zghz376;
sail_int zghz377;
lbits zghz378;

void startup_zmain(void)
{
  CREATE(lbits)(&zghz373);
  CREATE(lbits)(&zghz374);
  CREATE(sail_int)(&zghz375);
  CREATE(sail_int)(&zghz376);
  CREATE(sail_int)(&zghz377);
  CREATE(lbits)(&zghz378);
}

unit zmain(unit zgsz3168)
{
  __label__ end_function_108, end_block_exception_109;

  unit zcbz314;
  {
    RECREATE(sail_int)(&zghz375);
    elf_entry(&zghz375, UNIT);
    {
      RECREATE(sail_int)(&zghz376);
      CONVERT_OF(sail_int, mach_int)(&zghz376, INT64_C(32));
      RECREATE(sail_int)(&zghz377);
      CONVERT_OF(sail_int, mach_int)(&zghz377, INT64_C(0));
      RECREATE(lbits)(&zghz378);
      get_slice_int(&zghz378, zghz376, zghz375, zghz377);
      zPC = CONVERT_OF(fbits, lbits)(zghz378, true);
    }
    unit zgsz3176;
    zgsz3176 = UNIT;
  }
  {
    unit zgsz3174;
    {
      RECREATE(lbits)(&zghz374);
      CONVERT_OF(lbits, fbits)(&zghz374, zPC, UINT64_C(32) , true);
      zgsz3174 = print_bits("PC = ", zghz374);
    }
  }
  {
    uint64_t zline;
    zline = zread_mem(zPC);
    unit zgsz3172;
    {
      RECREATE(lbits)(&zghz373);
      CONVERT_OF(lbits, fbits)(&zghz373, zline, UINT64_C(32) , true);
      zgsz3172 = print_bits("line = ", zghz373);
    }
  
  }
  zcbz314 = zfde_loop(UNIT);
end_function_108: ;
  return zcbz314;
end_block_exception_109: ;

  return UNIT;
}



void finish_zmain(void)
{
  KILL(lbits)(&zghz378);
  KILL(sail_int)(&zghz377);
  KILL(sail_int)(&zghz376);
  KILL(sail_int)(&zghz375);
  KILL(lbits)(&zghz374);
  KILL(lbits)(&zghz373);
}

unit zinitializze_registers(unit);

sail_int zghz379;
lbits zghz380;
sail_int zghz381;
lbits zghz382;
sail_int zghz383;
lbits zghz384;
sail_int zghz385;
lbits zghz386;
sail_int zghz387;
lbits zghz388;
sail_int zghz389;
lbits zghz390;
sail_int zghz391;
lbits zghz392;
sail_int zghz393;
lbits zghz394;
sail_int zghz395;
lbits zghz396;

void startup_zinitializze_registers(void)
{
  CREATE(sail_int)(&zghz379);
  CREATE(lbits)(&zghz380);
  CREATE(sail_int)(&zghz381);
  CREATE(lbits)(&zghz382);
  CREATE(sail_int)(&zghz383);
  CREATE(lbits)(&zghz384);
  CREATE(sail_int)(&zghz385);
  CREATE(lbits)(&zghz386);
  CREATE(sail_int)(&zghz387);
  CREATE(lbits)(&zghz388);
  CREATE(sail_int)(&zghz389);
  CREATE(lbits)(&zghz390);
  CREATE(sail_int)(&zghz391);
  CREATE(lbits)(&zghz392);
  CREATE(sail_int)(&zghz393);
  CREATE(lbits)(&zghz394);
  CREATE(sail_int)(&zghz395);
  CREATE(lbits)(&zghz396);
}

unit zinitializze_registers(unit zgsz3177)
{
  __label__ end_function_111, end_block_exception_112;

  unit zcbz315;
  {
    {
      RECREATE(sail_int)(&zghz395);
      CONVERT_OF(sail_int, mach_int)(&zghz395, INT64_C(32));
      RECREATE(lbits)(&zghz396);
      UNDEFINED(lbits)(&zghz396, zghz395);
      zPC = CONVERT_OF(fbits, lbits)(zghz396, true);
    }
    unit zgsz3201;
    zgsz3201 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz393);
      CONVERT_OF(sail_int, mach_int)(&zghz393, INT64_C(32));
      RECREATE(lbits)(&zghz394);
      UNDEFINED(lbits)(&zghz394, zghz393);
      zzzero = CONVERT_OF(fbits, lbits)(zghz394, true);
    }
    unit zgsz3200;
    zgsz3200 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz391);
      CONVERT_OF(sail_int, mach_int)(&zghz391, INT64_C(32));
      RECREATE(lbits)(&zghz392);
      UNDEFINED(lbits)(&zghz392, zghz391);
      zra = CONVERT_OF(fbits, lbits)(zghz392, true);
    }
    unit zgsz3199;
    zgsz3199 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz389);
      CONVERT_OF(sail_int, mach_int)(&zghz389, INT64_C(32));
      RECREATE(lbits)(&zghz390);
      UNDEFINED(lbits)(&zghz390, zghz389);
      zsp = CONVERT_OF(fbits, lbits)(zghz390, true);
    }
    unit zgsz3198;
    zgsz3198 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz387);
      CONVERT_OF(sail_int, mach_int)(&zghz387, INT64_C(32));
      RECREATE(lbits)(&zghz388);
      UNDEFINED(lbits)(&zghz388, zghz387);
      zgp = CONVERT_OF(fbits, lbits)(zghz388, true);
    }
    unit zgsz3197;
    zgsz3197 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz385);
      CONVERT_OF(sail_int, mach_int)(&zghz385, INT64_C(32));
      RECREATE(lbits)(&zghz386);
      UNDEFINED(lbits)(&zghz386, zghz385);
      za0 = CONVERT_OF(fbits, lbits)(zghz386, true);
    }
    unit zgsz3196;
    zgsz3196 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz383);
      CONVERT_OF(sail_int, mach_int)(&zghz383, INT64_C(32));
      RECREATE(lbits)(&zghz384);
      UNDEFINED(lbits)(&zghz384, zghz383);
      za1 = CONVERT_OF(fbits, lbits)(zghz384, true);
    }
    unit zgsz3195;
    zgsz3195 = UNIT;
  }
  {
    {
      RECREATE(sail_int)(&zghz381);
      CONVERT_OF(sail_int, mach_int)(&zghz381, INT64_C(32));
      RECREATE(lbits)(&zghz382);
      UNDEFINED(lbits)(&zghz382, zghz381);
      za2 = CONVERT_OF(fbits, lbits)(zghz382, true);
    }
    unit zgsz3194;
    zgsz3194 = UNIT;
  }
  {
    RECREATE(sail_int)(&zghz379);
    CONVERT_OF(sail_int, mach_int)(&zghz379, INT64_C(32));
    RECREATE(lbits)(&zghz380);
    UNDEFINED(lbits)(&zghz380, zghz379);
    za3 = CONVERT_OF(fbits, lbits)(zghz380, true);
  }
  zcbz315 = UNIT;
end_function_111: ;
  return zcbz315;
end_block_exception_112: ;

  return UNIT;
}



void finish_zinitializze_registers(void)
{
  KILL(lbits)(&zghz396);
  KILL(sail_int)(&zghz395);
  KILL(lbits)(&zghz394);
  KILL(sail_int)(&zghz393);
  KILL(lbits)(&zghz392);
  KILL(sail_int)(&zghz391);
  KILL(lbits)(&zghz390);
  KILL(sail_int)(&zghz389);
  KILL(lbits)(&zghz388);
  KILL(sail_int)(&zghz387);
  KILL(lbits)(&zghz386);
  KILL(sail_int)(&zghz385);
  KILL(lbits)(&zghz384);
  KILL(sail_int)(&zghz383);
  KILL(lbits)(&zghz382);
  KILL(sail_int)(&zghz381);
  KILL(lbits)(&zghz380);
  KILL(sail_int)(&zghz379);
}

void model_init(void)
{
  setup_rts();
  startup_zsail_mask();
  startup_zsail_ones();
  startup_zfdiv_int();
  startup_zxor_bitvector();
  startup_zrX();
  startup_zwX();
  startup_zadd_to_PC();
  startup_zinc_PC();
  startup_zexecute();
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
  finish_zxor_bitvector();
  finish_zrX();
  finish_zwX();
  finish_zadd_to_PC();
  finish_zinc_PC();
  finish_zexecute();
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
