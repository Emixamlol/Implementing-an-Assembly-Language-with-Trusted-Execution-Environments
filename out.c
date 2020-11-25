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

// struct tuple_(%bv1, %bv10, %bv1, %bv9, %bv5, %enum zjop)
struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv9zCz0z5bv5zCz0z5enumz0zzjopz9 {
  uint64_t ztup0;
  uint64_t ztup1;
  uint64_t ztup2;
  uint64_t ztup3;
  uint64_t ztup4;
  enum zjop ztup5;
};

static void COPY(ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv9zCz0z5bv5zCz0z5enumz0zzjopz9)(struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv9zCz0z5bv5zCz0z5enumz0zzjopz9 *rop, const struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv9zCz0z5bv5zCz0z5enumz0zzjopz9 op) {
  rop->ztup0 = op.ztup0;
  rop->ztup1 = op.ztup1;
  rop->ztup2 = op.ztup2;
  rop->ztup3 = op.ztup3;
  rop->ztup4 = op.ztup4;
  rop->ztup5 = op.ztup5;
}

static bool EQUAL(ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv9zCz0z5bv5zCz0z5enumz0zzjopz9)(struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv9zCz0z5bv5zCz0z5enumz0zzjopz9 op1, struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv9zCz0z5bv5zCz0z5enumz0zzjopz9 op2) {
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
    struct { struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv9zCz0z5bv5zCz0z5enumz0zzjopz9 zJTYPE; };
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
    return EQUAL(ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv9zCz0z5bv5zCz0z5enumz0zzjopz9)(op1.zJTYPE, op2.zJTYPE);
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

static void zJTYPE(struct zast *rop, struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv9zCz0z5bv5zCz0z5enumz0zzjopz9 op)
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




































void zdecode(struct zoption *rop, uint64_t);













void zdecode(struct zoption *zcbz30, uint64_t zmergez3var)
{
  __label__ case_2, case_3, case_4, case_5, case_6, case_7, case_8, finish_match_1, end_function_9, end_block_exception_10, end_function_11;

  struct zoption zgsz30;
  CREATE(zoption)(&zgsz30);
  {
    uint64_t zv__0;
    zv__0 = zmergez3var;
    bool zgaz35;
    {
      uint64_t zgaz31;
      {
        lbits zgsz31;
        CREATE(lbits)(&zgsz31);
        CONVERT_OF(lbits, fbits)(&zgsz31, zv__0, UINT64_C(32) , true);
        sail_int zgsz32;
        CREATE(sail_int)(&zgsz32);
        CONVERT_OF(sail_int, mach_int)(&zgsz32, INT64_C(31));
        sail_int zgsz33;
        CREATE(sail_int)(&zgsz33);
        CONVERT_OF(sail_int, mach_int)(&zgsz33, INT64_C(25));
        lbits zgsz34;
        CREATE(lbits)(&zgsz34);
        vector_subrange_lbits(&zgsz34, zgsz31, zgsz32, zgsz33);
        zgaz31 = CONVERT_OF(fbits, lbits)(zgsz34, true);
        KILL(lbits)(&zgsz34);
        KILL(sail_int)(&zgsz33);
        KILL(sail_int)(&zgsz32);
        KILL(lbits)(&zgsz31);
      }
      {
        lbits zgsz36;
        CREATE(lbits)(&zgsz36);
        CONVERT_OF(lbits, fbits)(&zgsz36, UINT64_C(0b0000000), UINT64_C(7) , true);
        lbits zgsz35;
        CREATE(lbits)(&zgsz35);
        CONVERT_OF(lbits, fbits)(&zgsz35, zgaz31, UINT64_C(7) , true);
        zgaz35 = eq_bits(zgsz35, zgsz36);
        KILL(lbits)(&zgsz36);
        KILL(lbits)(&zgsz35);
      }
    
    }
    bool zgsz320;
    if (zgaz35) {
    bool zgaz34;
    {
      uint64_t zgaz32;
      {
        lbits zgsz37;
        CREATE(lbits)(&zgsz37);
        CONVERT_OF(lbits, fbits)(&zgsz37, zv__0, UINT64_C(32) , true);
        sail_int zgsz38;
        CREATE(sail_int)(&zgsz38);
        CONVERT_OF(sail_int, mach_int)(&zgsz38, INT64_C(14));
        sail_int zgsz39;
        CREATE(sail_int)(&zgsz39);
        CONVERT_OF(sail_int, mach_int)(&zgsz39, INT64_C(12));
        lbits zgsz310;
        CREATE(lbits)(&zgsz310);
        vector_subrange_lbits(&zgsz310, zgsz37, zgsz38, zgsz39);
        zgaz32 = CONVERT_OF(fbits, lbits)(zgsz310, true);
        KILL(lbits)(&zgsz310);
        KILL(sail_int)(&zgsz39);
        KILL(sail_int)(&zgsz38);
        KILL(lbits)(&zgsz37);
      }
      {
        lbits zgsz312;
        CREATE(lbits)(&zgsz312);
        CONVERT_OF(lbits, fbits)(&zgsz312, UINT64_C(0b000), UINT64_C(3) , true);
        lbits zgsz311;
        CREATE(lbits)(&zgsz311);
        CONVERT_OF(lbits, fbits)(&zgsz311, zgaz32, UINT64_C(3) , true);
        zgaz34 = eq_bits(zgsz311, zgsz312);
        KILL(lbits)(&zgsz312);
        KILL(lbits)(&zgsz311);
      }
    
    }
    bool zgsz317;
    if (zgaz34) {
    uint64_t zgaz33;
    {
      lbits zgsz313;
      CREATE(lbits)(&zgsz313);
      CONVERT_OF(lbits, fbits)(&zgsz313, zv__0, UINT64_C(32) , true);
      sail_int zgsz314;
      CREATE(sail_int)(&zgsz314);
      CONVERT_OF(sail_int, mach_int)(&zgsz314, INT64_C(6));
      sail_int zgsz315;
      CREATE(sail_int)(&zgsz315);
      CONVERT_OF(sail_int, mach_int)(&zgsz315, INT64_C(0));
      lbits zgsz316;
      CREATE(lbits)(&zgsz316);
      vector_subrange_lbits(&zgsz316, zgsz313, zgsz314, zgsz315);
      zgaz33 = CONVERT_OF(fbits, lbits)(zgsz316, true);
      KILL(lbits)(&zgsz316);
      KILL(sail_int)(&zgsz315);
      KILL(sail_int)(&zgsz314);
      KILL(lbits)(&zgsz313);
    }
    {
      lbits zgsz319;
      CREATE(lbits)(&zgsz319);
      CONVERT_OF(lbits, fbits)(&zgsz319, UINT64_C(0b0110011), UINT64_C(7) , true);
      lbits zgsz318;
      CREATE(lbits)(&zgsz318);
      CONVERT_OF(lbits, fbits)(&zgsz318, zgaz33, UINT64_C(7) , true);
      zgsz317 = eq_bits(zgsz318, zgsz319);
      KILL(lbits)(&zgsz319);
      KILL(lbits)(&zgsz318);
    }
  
    } else {  zgsz317 = false;  }
    zgsz320 = zgsz317;
  
    } else {  zgsz320 = false;  }
    bool zgsz334;
    zgsz334 = zgsz320;
  
    if (!(zgsz334)) {
  
    goto case_2;
    }
    uint64_t zrs2;
    {
      lbits zgsz321;
      CREATE(lbits)(&zgsz321);
      CONVERT_OF(lbits, fbits)(&zgsz321, zv__0, UINT64_C(32) , true);
      sail_int zgsz322;
      CREATE(sail_int)(&zgsz322);
      CONVERT_OF(sail_int, mach_int)(&zgsz322, INT64_C(24));
      sail_int zgsz323;
      CREATE(sail_int)(&zgsz323);
      CONVERT_OF(sail_int, mach_int)(&zgsz323, INT64_C(20));
      lbits zgsz324;
      CREATE(lbits)(&zgsz324);
      vector_subrange_lbits(&zgsz324, zgsz321, zgsz322, zgsz323);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz324, true);
      KILL(lbits)(&zgsz324);
      KILL(sail_int)(&zgsz323);
      KILL(sail_int)(&zgsz322);
      KILL(lbits)(&zgsz321);
    }
    uint64_t zrs1;
    {
      lbits zgsz325;
      CREATE(lbits)(&zgsz325);
      CONVERT_OF(lbits, fbits)(&zgsz325, zv__0, UINT64_C(32) , true);
      sail_int zgsz326;
      CREATE(sail_int)(&zgsz326);
      CONVERT_OF(sail_int, mach_int)(&zgsz326, INT64_C(19));
      sail_int zgsz327;
      CREATE(sail_int)(&zgsz327);
      CONVERT_OF(sail_int, mach_int)(&zgsz327, INT64_C(15));
      lbits zgsz328;
      CREATE(lbits)(&zgsz328);
      vector_subrange_lbits(&zgsz328, zgsz325, zgsz326, zgsz327);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz328, true);
      KILL(lbits)(&zgsz328);
      KILL(sail_int)(&zgsz327);
      KILL(sail_int)(&zgsz326);
      KILL(lbits)(&zgsz325);
    }
    uint64_t zrd;
    {
      lbits zgsz329;
      CREATE(lbits)(&zgsz329);
      CONVERT_OF(lbits, fbits)(&zgsz329, zv__0, UINT64_C(32) , true);
      sail_int zgsz330;
      CREATE(sail_int)(&zgsz330);
      CONVERT_OF(sail_int, mach_int)(&zgsz330, INT64_C(11));
      sail_int zgsz331;
      CREATE(sail_int)(&zgsz331);
      CONVERT_OF(sail_int, mach_int)(&zgsz331, INT64_C(7));
      lbits zgsz332;
      CREATE(lbits)(&zgsz332);
      vector_subrange_lbits(&zgsz332, zgsz329, zgsz330, zgsz331);
      zrd = CONVERT_OF(fbits, lbits)(zgsz332, true);
      KILL(lbits)(&zgsz332);
      KILL(sail_int)(&zgsz331);
      KILL(sail_int)(&zgsz330);
      KILL(lbits)(&zgsz329);
    }
    struct zast zgaz30;
    CREATE(zast)(&zgaz30);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz333;
      zgsz333.ztup0 = zrs2;
      zgsz333.ztup1 = zrs1;
      zgsz333.ztup2 = zrd;
      zgsz333.ztup3 = zADD;
      zRTYPE(&zgaz30, zgsz333);
    
    }
    {
      struct zast zgsz3239;
      CREATE(zast)(&zgsz3239);
      COPY(zast)(&zgsz3239, zgaz30);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3239);
      KILL(zast)(&zgsz3239);
    }
    KILL(zast)(&zgaz30);
  
  
  
  
    goto finish_match_1;
  }
case_2: ;
  {
    uint64_t zv__4;
    zv__4 = zmergez3var;
    bool zgaz311;
    {
      uint64_t zgaz37;
      {
        lbits zgsz335;
        CREATE(lbits)(&zgsz335);
        CONVERT_OF(lbits, fbits)(&zgsz335, zv__4, UINT64_C(32) , true);
        sail_int zgsz336;
        CREATE(sail_int)(&zgsz336);
        CONVERT_OF(sail_int, mach_int)(&zgsz336, INT64_C(31));
        sail_int zgsz337;
        CREATE(sail_int)(&zgsz337);
        CONVERT_OF(sail_int, mach_int)(&zgsz337, INT64_C(25));
        lbits zgsz338;
        CREATE(lbits)(&zgsz338);
        vector_subrange_lbits(&zgsz338, zgsz335, zgsz336, zgsz337);
        zgaz37 = CONVERT_OF(fbits, lbits)(zgsz338, true);
        KILL(lbits)(&zgsz338);
        KILL(sail_int)(&zgsz337);
        KILL(sail_int)(&zgsz336);
        KILL(lbits)(&zgsz335);
      }
      {
        lbits zgsz340;
        CREATE(lbits)(&zgsz340);
        CONVERT_OF(lbits, fbits)(&zgsz340, UINT64_C(0b0000000), UINT64_C(7) , true);
        lbits zgsz339;
        CREATE(lbits)(&zgsz339);
        CONVERT_OF(lbits, fbits)(&zgsz339, zgaz37, UINT64_C(7) , true);
        zgaz311 = eq_bits(zgsz339, zgsz340);
        KILL(lbits)(&zgsz340);
        KILL(lbits)(&zgsz339);
      }
    
    }
    bool zgsz354;
    if (zgaz311) {
    bool zgaz310;
    {
      uint64_t zgaz38;
      {
        lbits zgsz341;
        CREATE(lbits)(&zgsz341);
        CONVERT_OF(lbits, fbits)(&zgsz341, zv__4, UINT64_C(32) , true);
        sail_int zgsz342;
        CREATE(sail_int)(&zgsz342);
        CONVERT_OF(sail_int, mach_int)(&zgsz342, INT64_C(14));
        sail_int zgsz343;
        CREATE(sail_int)(&zgsz343);
        CONVERT_OF(sail_int, mach_int)(&zgsz343, INT64_C(12));
        lbits zgsz344;
        CREATE(lbits)(&zgsz344);
        vector_subrange_lbits(&zgsz344, zgsz341, zgsz342, zgsz343);
        zgaz38 = CONVERT_OF(fbits, lbits)(zgsz344, true);
        KILL(lbits)(&zgsz344);
        KILL(sail_int)(&zgsz343);
        KILL(sail_int)(&zgsz342);
        KILL(lbits)(&zgsz341);
      }
      {
        lbits zgsz346;
        CREATE(lbits)(&zgsz346);
        CONVERT_OF(lbits, fbits)(&zgsz346, UINT64_C(0b111), UINT64_C(3) , true);
        lbits zgsz345;
        CREATE(lbits)(&zgsz345);
        CONVERT_OF(lbits, fbits)(&zgsz345, zgaz38, UINT64_C(3) , true);
        zgaz310 = eq_bits(zgsz345, zgsz346);
        KILL(lbits)(&zgsz346);
        KILL(lbits)(&zgsz345);
      }
    
    }
    bool zgsz351;
    if (zgaz310) {
    uint64_t zgaz39;
    {
      lbits zgsz347;
      CREATE(lbits)(&zgsz347);
      CONVERT_OF(lbits, fbits)(&zgsz347, zv__4, UINT64_C(32) , true);
      sail_int zgsz348;
      CREATE(sail_int)(&zgsz348);
      CONVERT_OF(sail_int, mach_int)(&zgsz348, INT64_C(6));
      sail_int zgsz349;
      CREATE(sail_int)(&zgsz349);
      CONVERT_OF(sail_int, mach_int)(&zgsz349, INT64_C(0));
      lbits zgsz350;
      CREATE(lbits)(&zgsz350);
      vector_subrange_lbits(&zgsz350, zgsz347, zgsz348, zgsz349);
      zgaz39 = CONVERT_OF(fbits, lbits)(zgsz350, true);
      KILL(lbits)(&zgsz350);
      KILL(sail_int)(&zgsz349);
      KILL(sail_int)(&zgsz348);
      KILL(lbits)(&zgsz347);
    }
    {
      lbits zgsz353;
      CREATE(lbits)(&zgsz353);
      CONVERT_OF(lbits, fbits)(&zgsz353, UINT64_C(0b0110011), UINT64_C(7) , true);
      lbits zgsz352;
      CREATE(lbits)(&zgsz352);
      CONVERT_OF(lbits, fbits)(&zgsz352, zgaz39, UINT64_C(7) , true);
      zgsz351 = eq_bits(zgsz352, zgsz353);
      KILL(lbits)(&zgsz353);
      KILL(lbits)(&zgsz352);
    }
  
    } else {  zgsz351 = false;  }
    zgsz354 = zgsz351;
  
    } else {  zgsz354 = false;  }
    bool zgsz368;
    zgsz368 = zgsz354;
  
    if (!(zgsz368)) {
  
    goto case_3;
    }
    uint64_t zrs2;
    {
      lbits zgsz355;
      CREATE(lbits)(&zgsz355);
      CONVERT_OF(lbits, fbits)(&zgsz355, zv__4, UINT64_C(32) , true);
      sail_int zgsz356;
      CREATE(sail_int)(&zgsz356);
      CONVERT_OF(sail_int, mach_int)(&zgsz356, INT64_C(24));
      sail_int zgsz357;
      CREATE(sail_int)(&zgsz357);
      CONVERT_OF(sail_int, mach_int)(&zgsz357, INT64_C(20));
      lbits zgsz358;
      CREATE(lbits)(&zgsz358);
      vector_subrange_lbits(&zgsz358, zgsz355, zgsz356, zgsz357);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz358, true);
      KILL(lbits)(&zgsz358);
      KILL(sail_int)(&zgsz357);
      KILL(sail_int)(&zgsz356);
      KILL(lbits)(&zgsz355);
    }
    uint64_t zrs1;
    {
      lbits zgsz359;
      CREATE(lbits)(&zgsz359);
      CONVERT_OF(lbits, fbits)(&zgsz359, zv__4, UINT64_C(32) , true);
      sail_int zgsz360;
      CREATE(sail_int)(&zgsz360);
      CONVERT_OF(sail_int, mach_int)(&zgsz360, INT64_C(19));
      sail_int zgsz361;
      CREATE(sail_int)(&zgsz361);
      CONVERT_OF(sail_int, mach_int)(&zgsz361, INT64_C(15));
      lbits zgsz362;
      CREATE(lbits)(&zgsz362);
      vector_subrange_lbits(&zgsz362, zgsz359, zgsz360, zgsz361);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz362, true);
      KILL(lbits)(&zgsz362);
      KILL(sail_int)(&zgsz361);
      KILL(sail_int)(&zgsz360);
      KILL(lbits)(&zgsz359);
    }
    uint64_t zrd;
    {
      lbits zgsz363;
      CREATE(lbits)(&zgsz363);
      CONVERT_OF(lbits, fbits)(&zgsz363, zv__4, UINT64_C(32) , true);
      sail_int zgsz364;
      CREATE(sail_int)(&zgsz364);
      CONVERT_OF(sail_int, mach_int)(&zgsz364, INT64_C(11));
      sail_int zgsz365;
      CREATE(sail_int)(&zgsz365);
      CONVERT_OF(sail_int, mach_int)(&zgsz365, INT64_C(7));
      lbits zgsz366;
      CREATE(lbits)(&zgsz366);
      vector_subrange_lbits(&zgsz366, zgsz363, zgsz364, zgsz365);
      zrd = CONVERT_OF(fbits, lbits)(zgsz366, true);
      KILL(lbits)(&zgsz366);
      KILL(sail_int)(&zgsz365);
      KILL(sail_int)(&zgsz364);
      KILL(lbits)(&zgsz363);
    }
    struct zast zgaz36;
    CREATE(zast)(&zgaz36);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz367;
      zgsz367.ztup0 = zrs2;
      zgsz367.ztup1 = zrs1;
      zgsz367.ztup2 = zrd;
      zgsz367.ztup3 = zAND;
      zRTYPE(&zgaz36, zgsz367);
    
    }
    {
      struct zast zgsz3240;
      CREATE(zast)(&zgsz3240);
      COPY(zast)(&zgsz3240, zgaz36);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3240);
      KILL(zast)(&zgsz3240);
    }
    KILL(zast)(&zgaz36);
  
  
  
  
    goto finish_match_1;
  }
case_3: ;
  {
    uint64_t zv__8;
    zv__8 = zmergez3var;
    bool zgaz317;
    {
      uint64_t zgaz313;
      {
        lbits zgsz369;
        CREATE(lbits)(&zgsz369);
        CONVERT_OF(lbits, fbits)(&zgsz369, zv__8, UINT64_C(32) , true);
        sail_int zgsz370;
        CREATE(sail_int)(&zgsz370);
        CONVERT_OF(sail_int, mach_int)(&zgsz370, INT64_C(31));
        sail_int zgsz371;
        CREATE(sail_int)(&zgsz371);
        CONVERT_OF(sail_int, mach_int)(&zgsz371, INT64_C(25));
        lbits zgsz372;
        CREATE(lbits)(&zgsz372);
        vector_subrange_lbits(&zgsz372, zgsz369, zgsz370, zgsz371);
        zgaz313 = CONVERT_OF(fbits, lbits)(zgsz372, true);
        KILL(lbits)(&zgsz372);
        KILL(sail_int)(&zgsz371);
        KILL(sail_int)(&zgsz370);
        KILL(lbits)(&zgsz369);
      }
      {
        lbits zgsz374;
        CREATE(lbits)(&zgsz374);
        CONVERT_OF(lbits, fbits)(&zgsz374, UINT64_C(0b0000000), UINT64_C(7) , true);
        lbits zgsz373;
        CREATE(lbits)(&zgsz373);
        CONVERT_OF(lbits, fbits)(&zgsz373, zgaz313, UINT64_C(7) , true);
        zgaz317 = eq_bits(zgsz373, zgsz374);
        KILL(lbits)(&zgsz374);
        KILL(lbits)(&zgsz373);
      }
    
    }
    bool zgsz388;
    if (zgaz317) {
    bool zgaz316;
    {
      uint64_t zgaz314;
      {
        lbits zgsz375;
        CREATE(lbits)(&zgsz375);
        CONVERT_OF(lbits, fbits)(&zgsz375, zv__8, UINT64_C(32) , true);
        sail_int zgsz376;
        CREATE(sail_int)(&zgsz376);
        CONVERT_OF(sail_int, mach_int)(&zgsz376, INT64_C(14));
        sail_int zgsz377;
        CREATE(sail_int)(&zgsz377);
        CONVERT_OF(sail_int, mach_int)(&zgsz377, INT64_C(12));
        lbits zgsz378;
        CREATE(lbits)(&zgsz378);
        vector_subrange_lbits(&zgsz378, zgsz375, zgsz376, zgsz377);
        zgaz314 = CONVERT_OF(fbits, lbits)(zgsz378, true);
        KILL(lbits)(&zgsz378);
        KILL(sail_int)(&zgsz377);
        KILL(sail_int)(&zgsz376);
        KILL(lbits)(&zgsz375);
      }
      {
        lbits zgsz380;
        CREATE(lbits)(&zgsz380);
        CONVERT_OF(lbits, fbits)(&zgsz380, UINT64_C(0b110), UINT64_C(3) , true);
        lbits zgsz379;
        CREATE(lbits)(&zgsz379);
        CONVERT_OF(lbits, fbits)(&zgsz379, zgaz314, UINT64_C(3) , true);
        zgaz316 = eq_bits(zgsz379, zgsz380);
        KILL(lbits)(&zgsz380);
        KILL(lbits)(&zgsz379);
      }
    
    }
    bool zgsz385;
    if (zgaz316) {
    uint64_t zgaz315;
    {
      lbits zgsz381;
      CREATE(lbits)(&zgsz381);
      CONVERT_OF(lbits, fbits)(&zgsz381, zv__8, UINT64_C(32) , true);
      sail_int zgsz382;
      CREATE(sail_int)(&zgsz382);
      CONVERT_OF(sail_int, mach_int)(&zgsz382, INT64_C(6));
      sail_int zgsz383;
      CREATE(sail_int)(&zgsz383);
      CONVERT_OF(sail_int, mach_int)(&zgsz383, INT64_C(0));
      lbits zgsz384;
      CREATE(lbits)(&zgsz384);
      vector_subrange_lbits(&zgsz384, zgsz381, zgsz382, zgsz383);
      zgaz315 = CONVERT_OF(fbits, lbits)(zgsz384, true);
      KILL(lbits)(&zgsz384);
      KILL(sail_int)(&zgsz383);
      KILL(sail_int)(&zgsz382);
      KILL(lbits)(&zgsz381);
    }
    {
      lbits zgsz387;
      CREATE(lbits)(&zgsz387);
      CONVERT_OF(lbits, fbits)(&zgsz387, UINT64_C(0b0110011), UINT64_C(7) , true);
      lbits zgsz386;
      CREATE(lbits)(&zgsz386);
      CONVERT_OF(lbits, fbits)(&zgsz386, zgaz315, UINT64_C(7) , true);
      zgsz385 = eq_bits(zgsz386, zgsz387);
      KILL(lbits)(&zgsz387);
      KILL(lbits)(&zgsz386);
    }
  
    } else {  zgsz385 = false;  }
    zgsz388 = zgsz385;
  
    } else {  zgsz388 = false;  }
    bool zgsz3102;
    zgsz3102 = zgsz388;
  
    if (!(zgsz3102)) {
  
    goto case_4;
    }
    uint64_t zrs2;
    {
      lbits zgsz389;
      CREATE(lbits)(&zgsz389);
      CONVERT_OF(lbits, fbits)(&zgsz389, zv__8, UINT64_C(32) , true);
      sail_int zgsz390;
      CREATE(sail_int)(&zgsz390);
      CONVERT_OF(sail_int, mach_int)(&zgsz390, INT64_C(24));
      sail_int zgsz391;
      CREATE(sail_int)(&zgsz391);
      CONVERT_OF(sail_int, mach_int)(&zgsz391, INT64_C(20));
      lbits zgsz392;
      CREATE(lbits)(&zgsz392);
      vector_subrange_lbits(&zgsz392, zgsz389, zgsz390, zgsz391);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz392, true);
      KILL(lbits)(&zgsz392);
      KILL(sail_int)(&zgsz391);
      KILL(sail_int)(&zgsz390);
      KILL(lbits)(&zgsz389);
    }
    uint64_t zrs1;
    {
      lbits zgsz393;
      CREATE(lbits)(&zgsz393);
      CONVERT_OF(lbits, fbits)(&zgsz393, zv__8, UINT64_C(32) , true);
      sail_int zgsz394;
      CREATE(sail_int)(&zgsz394);
      CONVERT_OF(sail_int, mach_int)(&zgsz394, INT64_C(19));
      sail_int zgsz395;
      CREATE(sail_int)(&zgsz395);
      CONVERT_OF(sail_int, mach_int)(&zgsz395, INT64_C(15));
      lbits zgsz396;
      CREATE(lbits)(&zgsz396);
      vector_subrange_lbits(&zgsz396, zgsz393, zgsz394, zgsz395);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz396, true);
      KILL(lbits)(&zgsz396);
      KILL(sail_int)(&zgsz395);
      KILL(sail_int)(&zgsz394);
      KILL(lbits)(&zgsz393);
    }
    uint64_t zrd;
    {
      lbits zgsz397;
      CREATE(lbits)(&zgsz397);
      CONVERT_OF(lbits, fbits)(&zgsz397, zv__8, UINT64_C(32) , true);
      sail_int zgsz398;
      CREATE(sail_int)(&zgsz398);
      CONVERT_OF(sail_int, mach_int)(&zgsz398, INT64_C(11));
      sail_int zgsz399;
      CREATE(sail_int)(&zgsz399);
      CONVERT_OF(sail_int, mach_int)(&zgsz399, INT64_C(7));
      lbits zgsz3100;
      CREATE(lbits)(&zgsz3100);
      vector_subrange_lbits(&zgsz3100, zgsz397, zgsz398, zgsz399);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3100, true);
      KILL(lbits)(&zgsz3100);
      KILL(sail_int)(&zgsz399);
      KILL(sail_int)(&zgsz398);
      KILL(lbits)(&zgsz397);
    }
    struct zast zgaz312;
    CREATE(zast)(&zgaz312);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3101;
      zgsz3101.ztup0 = zrs2;
      zgsz3101.ztup1 = zrs1;
      zgsz3101.ztup2 = zrd;
      zgsz3101.ztup3 = zOR;
      zRTYPE(&zgaz312, zgsz3101);
    
    }
    {
      struct zast zgsz3241;
      CREATE(zast)(&zgsz3241);
      COPY(zast)(&zgsz3241, zgaz312);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3241);
      KILL(zast)(&zgsz3241);
    }
    KILL(zast)(&zgaz312);
  
  
  
  
    goto finish_match_1;
  }
case_4: ;
  {
    uint64_t zv__12;
    zv__12 = zmergez3var;
    bool zgaz323;
    {
      uint64_t zgaz319;
      {
        lbits zgsz3103;
        CREATE(lbits)(&zgsz3103);
        CONVERT_OF(lbits, fbits)(&zgsz3103, zv__12, UINT64_C(32) , true);
        sail_int zgsz3104;
        CREATE(sail_int)(&zgsz3104);
        CONVERT_OF(sail_int, mach_int)(&zgsz3104, INT64_C(31));
        sail_int zgsz3105;
        CREATE(sail_int)(&zgsz3105);
        CONVERT_OF(sail_int, mach_int)(&zgsz3105, INT64_C(25));
        lbits zgsz3106;
        CREATE(lbits)(&zgsz3106);
        vector_subrange_lbits(&zgsz3106, zgsz3103, zgsz3104, zgsz3105);
        zgaz319 = CONVERT_OF(fbits, lbits)(zgsz3106, true);
        KILL(lbits)(&zgsz3106);
        KILL(sail_int)(&zgsz3105);
        KILL(sail_int)(&zgsz3104);
        KILL(lbits)(&zgsz3103);
      }
      {
        lbits zgsz3108;
        CREATE(lbits)(&zgsz3108);
        CONVERT_OF(lbits, fbits)(&zgsz3108, UINT64_C(0b0000000), UINT64_C(7) , true);
        lbits zgsz3107;
        CREATE(lbits)(&zgsz3107);
        CONVERT_OF(lbits, fbits)(&zgsz3107, zgaz319, UINT64_C(7) , true);
        zgaz323 = eq_bits(zgsz3107, zgsz3108);
        KILL(lbits)(&zgsz3108);
        KILL(lbits)(&zgsz3107);
      }
    
    }
    bool zgsz3122;
    if (zgaz323) {
    bool zgaz322;
    {
      uint64_t zgaz320;
      {
        lbits zgsz3109;
        CREATE(lbits)(&zgsz3109);
        CONVERT_OF(lbits, fbits)(&zgsz3109, zv__12, UINT64_C(32) , true);
        sail_int zgsz3110;
        CREATE(sail_int)(&zgsz3110);
        CONVERT_OF(sail_int, mach_int)(&zgsz3110, INT64_C(14));
        sail_int zgsz3111;
        CREATE(sail_int)(&zgsz3111);
        CONVERT_OF(sail_int, mach_int)(&zgsz3111, INT64_C(12));
        lbits zgsz3112;
        CREATE(lbits)(&zgsz3112);
        vector_subrange_lbits(&zgsz3112, zgsz3109, zgsz3110, zgsz3111);
        zgaz320 = CONVERT_OF(fbits, lbits)(zgsz3112, true);
        KILL(lbits)(&zgsz3112);
        KILL(sail_int)(&zgsz3111);
        KILL(sail_int)(&zgsz3110);
        KILL(lbits)(&zgsz3109);
      }
      {
        lbits zgsz3114;
        CREATE(lbits)(&zgsz3114);
        CONVERT_OF(lbits, fbits)(&zgsz3114, UINT64_C(0b100), UINT64_C(3) , true);
        lbits zgsz3113;
        CREATE(lbits)(&zgsz3113);
        CONVERT_OF(lbits, fbits)(&zgsz3113, zgaz320, UINT64_C(3) , true);
        zgaz322 = eq_bits(zgsz3113, zgsz3114);
        KILL(lbits)(&zgsz3114);
        KILL(lbits)(&zgsz3113);
      }
    
    }
    bool zgsz3119;
    if (zgaz322) {
    uint64_t zgaz321;
    {
      lbits zgsz3115;
      CREATE(lbits)(&zgsz3115);
      CONVERT_OF(lbits, fbits)(&zgsz3115, zv__12, UINT64_C(32) , true);
      sail_int zgsz3116;
      CREATE(sail_int)(&zgsz3116);
      CONVERT_OF(sail_int, mach_int)(&zgsz3116, INT64_C(6));
      sail_int zgsz3117;
      CREATE(sail_int)(&zgsz3117);
      CONVERT_OF(sail_int, mach_int)(&zgsz3117, INT64_C(0));
      lbits zgsz3118;
      CREATE(lbits)(&zgsz3118);
      vector_subrange_lbits(&zgsz3118, zgsz3115, zgsz3116, zgsz3117);
      zgaz321 = CONVERT_OF(fbits, lbits)(zgsz3118, true);
      KILL(lbits)(&zgsz3118);
      KILL(sail_int)(&zgsz3117);
      KILL(sail_int)(&zgsz3116);
      KILL(lbits)(&zgsz3115);
    }
    {
      lbits zgsz3121;
      CREATE(lbits)(&zgsz3121);
      CONVERT_OF(lbits, fbits)(&zgsz3121, UINT64_C(0b0110011), UINT64_C(7) , true);
      lbits zgsz3120;
      CREATE(lbits)(&zgsz3120);
      CONVERT_OF(lbits, fbits)(&zgsz3120, zgaz321, UINT64_C(7) , true);
      zgsz3119 = eq_bits(zgsz3120, zgsz3121);
      KILL(lbits)(&zgsz3121);
      KILL(lbits)(&zgsz3120);
    }
  
    } else {  zgsz3119 = false;  }
    zgsz3122 = zgsz3119;
  
    } else {  zgsz3122 = false;  }
    bool zgsz3136;
    zgsz3136 = zgsz3122;
  
    if (!(zgsz3136)) {
  
    goto case_5;
    }
    uint64_t zrs2;
    {
      lbits zgsz3123;
      CREATE(lbits)(&zgsz3123);
      CONVERT_OF(lbits, fbits)(&zgsz3123, zv__12, UINT64_C(32) , true);
      sail_int zgsz3124;
      CREATE(sail_int)(&zgsz3124);
      CONVERT_OF(sail_int, mach_int)(&zgsz3124, INT64_C(24));
      sail_int zgsz3125;
      CREATE(sail_int)(&zgsz3125);
      CONVERT_OF(sail_int, mach_int)(&zgsz3125, INT64_C(20));
      lbits zgsz3126;
      CREATE(lbits)(&zgsz3126);
      vector_subrange_lbits(&zgsz3126, zgsz3123, zgsz3124, zgsz3125);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz3126, true);
      KILL(lbits)(&zgsz3126);
      KILL(sail_int)(&zgsz3125);
      KILL(sail_int)(&zgsz3124);
      KILL(lbits)(&zgsz3123);
    }
    uint64_t zrs1;
    {
      lbits zgsz3127;
      CREATE(lbits)(&zgsz3127);
      CONVERT_OF(lbits, fbits)(&zgsz3127, zv__12, UINT64_C(32) , true);
      sail_int zgsz3128;
      CREATE(sail_int)(&zgsz3128);
      CONVERT_OF(sail_int, mach_int)(&zgsz3128, INT64_C(19));
      sail_int zgsz3129;
      CREATE(sail_int)(&zgsz3129);
      CONVERT_OF(sail_int, mach_int)(&zgsz3129, INT64_C(15));
      lbits zgsz3130;
      CREATE(lbits)(&zgsz3130);
      vector_subrange_lbits(&zgsz3130, zgsz3127, zgsz3128, zgsz3129);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3130, true);
      KILL(lbits)(&zgsz3130);
      KILL(sail_int)(&zgsz3129);
      KILL(sail_int)(&zgsz3128);
      KILL(lbits)(&zgsz3127);
    }
    uint64_t zrd;
    {
      lbits zgsz3131;
      CREATE(lbits)(&zgsz3131);
      CONVERT_OF(lbits, fbits)(&zgsz3131, zv__12, UINT64_C(32) , true);
      sail_int zgsz3132;
      CREATE(sail_int)(&zgsz3132);
      CONVERT_OF(sail_int, mach_int)(&zgsz3132, INT64_C(11));
      sail_int zgsz3133;
      CREATE(sail_int)(&zgsz3133);
      CONVERT_OF(sail_int, mach_int)(&zgsz3133, INT64_C(7));
      lbits zgsz3134;
      CREATE(lbits)(&zgsz3134);
      vector_subrange_lbits(&zgsz3134, zgsz3131, zgsz3132, zgsz3133);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3134, true);
      KILL(lbits)(&zgsz3134);
      KILL(sail_int)(&zgsz3133);
      KILL(sail_int)(&zgsz3132);
      KILL(lbits)(&zgsz3131);
    }
    struct zast zgaz318;
    CREATE(zast)(&zgaz318);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3135;
      zgsz3135.ztup0 = zrs2;
      zgsz3135.ztup1 = zrs1;
      zgsz3135.ztup2 = zrd;
      zgsz3135.ztup3 = zXOR;
      zRTYPE(&zgaz318, zgsz3135);
    
    }
    {
      struct zast zgsz3242;
      CREATE(zast)(&zgsz3242);
      COPY(zast)(&zgsz3242, zgaz318);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3242);
      KILL(zast)(&zgsz3242);
    }
    KILL(zast)(&zgaz318);
  
  
  
  
    goto finish_match_1;
  }
case_5: ;
  {
    uint64_t zv__16;
    zv__16 = zmergez3var;
    bool zgaz329;
    {
      uint64_t zgaz325;
      {
        lbits zgsz3137;
        CREATE(lbits)(&zgsz3137);
        CONVERT_OF(lbits, fbits)(&zgsz3137, zv__16, UINT64_C(32) , true);
        sail_int zgsz3138;
        CREATE(sail_int)(&zgsz3138);
        CONVERT_OF(sail_int, mach_int)(&zgsz3138, INT64_C(31));
        sail_int zgsz3139;
        CREATE(sail_int)(&zgsz3139);
        CONVERT_OF(sail_int, mach_int)(&zgsz3139, INT64_C(25));
        lbits zgsz3140;
        CREATE(lbits)(&zgsz3140);
        vector_subrange_lbits(&zgsz3140, zgsz3137, zgsz3138, zgsz3139);
        zgaz325 = CONVERT_OF(fbits, lbits)(zgsz3140, true);
        KILL(lbits)(&zgsz3140);
        KILL(sail_int)(&zgsz3139);
        KILL(sail_int)(&zgsz3138);
        KILL(lbits)(&zgsz3137);
      }
      {
        lbits zgsz3142;
        CREATE(lbits)(&zgsz3142);
        CONVERT_OF(lbits, fbits)(&zgsz3142, UINT64_C(0b0000001), UINT64_C(7) , true);
        lbits zgsz3141;
        CREATE(lbits)(&zgsz3141);
        CONVERT_OF(lbits, fbits)(&zgsz3141, zgaz325, UINT64_C(7) , true);
        zgaz329 = eq_bits(zgsz3141, zgsz3142);
        KILL(lbits)(&zgsz3142);
        KILL(lbits)(&zgsz3141);
      }
    
    }
    bool zgsz3156;
    if (zgaz329) {
    bool zgaz328;
    {
      uint64_t zgaz326;
      {
        lbits zgsz3143;
        CREATE(lbits)(&zgsz3143);
        CONVERT_OF(lbits, fbits)(&zgsz3143, zv__16, UINT64_C(32) , true);
        sail_int zgsz3144;
        CREATE(sail_int)(&zgsz3144);
        CONVERT_OF(sail_int, mach_int)(&zgsz3144, INT64_C(14));
        sail_int zgsz3145;
        CREATE(sail_int)(&zgsz3145);
        CONVERT_OF(sail_int, mach_int)(&zgsz3145, INT64_C(12));
        lbits zgsz3146;
        CREATE(lbits)(&zgsz3146);
        vector_subrange_lbits(&zgsz3146, zgsz3143, zgsz3144, zgsz3145);
        zgaz326 = CONVERT_OF(fbits, lbits)(zgsz3146, true);
        KILL(lbits)(&zgsz3146);
        KILL(sail_int)(&zgsz3145);
        KILL(sail_int)(&zgsz3144);
        KILL(lbits)(&zgsz3143);
      }
      {
        lbits zgsz3148;
        CREATE(lbits)(&zgsz3148);
        CONVERT_OF(lbits, fbits)(&zgsz3148, UINT64_C(0b000), UINT64_C(3) , true);
        lbits zgsz3147;
        CREATE(lbits)(&zgsz3147);
        CONVERT_OF(lbits, fbits)(&zgsz3147, zgaz326, UINT64_C(3) , true);
        zgaz328 = eq_bits(zgsz3147, zgsz3148);
        KILL(lbits)(&zgsz3148);
        KILL(lbits)(&zgsz3147);
      }
    
    }
    bool zgsz3153;
    if (zgaz328) {
    uint64_t zgaz327;
    {
      lbits zgsz3149;
      CREATE(lbits)(&zgsz3149);
      CONVERT_OF(lbits, fbits)(&zgsz3149, zv__16, UINT64_C(32) , true);
      sail_int zgsz3150;
      CREATE(sail_int)(&zgsz3150);
      CONVERT_OF(sail_int, mach_int)(&zgsz3150, INT64_C(6));
      sail_int zgsz3151;
      CREATE(sail_int)(&zgsz3151);
      CONVERT_OF(sail_int, mach_int)(&zgsz3151, INT64_C(0));
      lbits zgsz3152;
      CREATE(lbits)(&zgsz3152);
      vector_subrange_lbits(&zgsz3152, zgsz3149, zgsz3150, zgsz3151);
      zgaz327 = CONVERT_OF(fbits, lbits)(zgsz3152, true);
      KILL(lbits)(&zgsz3152);
      KILL(sail_int)(&zgsz3151);
      KILL(sail_int)(&zgsz3150);
      KILL(lbits)(&zgsz3149);
    }
    {
      lbits zgsz3155;
      CREATE(lbits)(&zgsz3155);
      CONVERT_OF(lbits, fbits)(&zgsz3155, UINT64_C(0b0110011), UINT64_C(7) , true);
      lbits zgsz3154;
      CREATE(lbits)(&zgsz3154);
      CONVERT_OF(lbits, fbits)(&zgsz3154, zgaz327, UINT64_C(7) , true);
      zgsz3153 = eq_bits(zgsz3154, zgsz3155);
      KILL(lbits)(&zgsz3155);
      KILL(lbits)(&zgsz3154);
    }
  
    } else {  zgsz3153 = false;  }
    zgsz3156 = zgsz3153;
  
    } else {  zgsz3156 = false;  }
    bool zgsz3170;
    zgsz3170 = zgsz3156;
  
    if (!(zgsz3170)) {
  
    goto case_6;
    }
    uint64_t zrs2;
    {
      lbits zgsz3157;
      CREATE(lbits)(&zgsz3157);
      CONVERT_OF(lbits, fbits)(&zgsz3157, zv__16, UINT64_C(32) , true);
      sail_int zgsz3158;
      CREATE(sail_int)(&zgsz3158);
      CONVERT_OF(sail_int, mach_int)(&zgsz3158, INT64_C(24));
      sail_int zgsz3159;
      CREATE(sail_int)(&zgsz3159);
      CONVERT_OF(sail_int, mach_int)(&zgsz3159, INT64_C(20));
      lbits zgsz3160;
      CREATE(lbits)(&zgsz3160);
      vector_subrange_lbits(&zgsz3160, zgsz3157, zgsz3158, zgsz3159);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz3160, true);
      KILL(lbits)(&zgsz3160);
      KILL(sail_int)(&zgsz3159);
      KILL(sail_int)(&zgsz3158);
      KILL(lbits)(&zgsz3157);
    }
    uint64_t zrs1;
    {
      lbits zgsz3161;
      CREATE(lbits)(&zgsz3161);
      CONVERT_OF(lbits, fbits)(&zgsz3161, zv__16, UINT64_C(32) , true);
      sail_int zgsz3162;
      CREATE(sail_int)(&zgsz3162);
      CONVERT_OF(sail_int, mach_int)(&zgsz3162, INT64_C(19));
      sail_int zgsz3163;
      CREATE(sail_int)(&zgsz3163);
      CONVERT_OF(sail_int, mach_int)(&zgsz3163, INT64_C(15));
      lbits zgsz3164;
      CREATE(lbits)(&zgsz3164);
      vector_subrange_lbits(&zgsz3164, zgsz3161, zgsz3162, zgsz3163);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3164, true);
      KILL(lbits)(&zgsz3164);
      KILL(sail_int)(&zgsz3163);
      KILL(sail_int)(&zgsz3162);
      KILL(lbits)(&zgsz3161);
    }
    uint64_t zrd;
    {
      lbits zgsz3165;
      CREATE(lbits)(&zgsz3165);
      CONVERT_OF(lbits, fbits)(&zgsz3165, zv__16, UINT64_C(32) , true);
      sail_int zgsz3166;
      CREATE(sail_int)(&zgsz3166);
      CONVERT_OF(sail_int, mach_int)(&zgsz3166, INT64_C(11));
      sail_int zgsz3167;
      CREATE(sail_int)(&zgsz3167);
      CONVERT_OF(sail_int, mach_int)(&zgsz3167, INT64_C(7));
      lbits zgsz3168;
      CREATE(lbits)(&zgsz3168);
      vector_subrange_lbits(&zgsz3168, zgsz3165, zgsz3166, zgsz3167);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3168, true);
      KILL(lbits)(&zgsz3168);
      KILL(sail_int)(&zgsz3167);
      KILL(sail_int)(&zgsz3166);
      KILL(lbits)(&zgsz3165);
    }
    struct zast zgaz324;
    CREATE(zast)(&zgaz324);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3169;
      zgsz3169.ztup0 = zrs2;
      zgsz3169.ztup1 = zrs1;
      zgsz3169.ztup2 = zrd;
      zgsz3169.ztup3 = zMUL;
      zRTYPE(&zgaz324, zgsz3169);
    
    }
    {
      struct zast zgsz3243;
      CREATE(zast)(&zgsz3243);
      COPY(zast)(&zgsz3243, zgaz324);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3243);
      KILL(zast)(&zgsz3243);
    }
    KILL(zast)(&zgaz324);
  
  
  
  
    goto finish_match_1;
  }
case_6: ;
  {
    uint64_t zv__20;
    zv__20 = zmergez3var;
    bool zgaz335;
    {
      uint64_t zgaz331;
      {
        lbits zgsz3171;
        CREATE(lbits)(&zgsz3171);
        CONVERT_OF(lbits, fbits)(&zgsz3171, zv__20, UINT64_C(32) , true);
        sail_int zgsz3172;
        CREATE(sail_int)(&zgsz3172);
        CONVERT_OF(sail_int, mach_int)(&zgsz3172, INT64_C(31));
        sail_int zgsz3173;
        CREATE(sail_int)(&zgsz3173);
        CONVERT_OF(sail_int, mach_int)(&zgsz3173, INT64_C(25));
        lbits zgsz3174;
        CREATE(lbits)(&zgsz3174);
        vector_subrange_lbits(&zgsz3174, zgsz3171, zgsz3172, zgsz3173);
        zgaz331 = CONVERT_OF(fbits, lbits)(zgsz3174, true);
        KILL(lbits)(&zgsz3174);
        KILL(sail_int)(&zgsz3173);
        KILL(sail_int)(&zgsz3172);
        KILL(lbits)(&zgsz3171);
      }
      {
        lbits zgsz3176;
        CREATE(lbits)(&zgsz3176);
        CONVERT_OF(lbits, fbits)(&zgsz3176, UINT64_C(0b0000001), UINT64_C(7) , true);
        lbits zgsz3175;
        CREATE(lbits)(&zgsz3175);
        CONVERT_OF(lbits, fbits)(&zgsz3175, zgaz331, UINT64_C(7) , true);
        zgaz335 = eq_bits(zgsz3175, zgsz3176);
        KILL(lbits)(&zgsz3176);
        KILL(lbits)(&zgsz3175);
      }
    
    }
    bool zgsz3190;
    if (zgaz335) {
    bool zgaz334;
    {
      uint64_t zgaz332;
      {
        lbits zgsz3177;
        CREATE(lbits)(&zgsz3177);
        CONVERT_OF(lbits, fbits)(&zgsz3177, zv__20, UINT64_C(32) , true);
        sail_int zgsz3178;
        CREATE(sail_int)(&zgsz3178);
        CONVERT_OF(sail_int, mach_int)(&zgsz3178, INT64_C(14));
        sail_int zgsz3179;
        CREATE(sail_int)(&zgsz3179);
        CONVERT_OF(sail_int, mach_int)(&zgsz3179, INT64_C(12));
        lbits zgsz3180;
        CREATE(lbits)(&zgsz3180);
        vector_subrange_lbits(&zgsz3180, zgsz3177, zgsz3178, zgsz3179);
        zgaz332 = CONVERT_OF(fbits, lbits)(zgsz3180, true);
        KILL(lbits)(&zgsz3180);
        KILL(sail_int)(&zgsz3179);
        KILL(sail_int)(&zgsz3178);
        KILL(lbits)(&zgsz3177);
      }
      {
        lbits zgsz3182;
        CREATE(lbits)(&zgsz3182);
        CONVERT_OF(lbits, fbits)(&zgsz3182, UINT64_C(0b100), UINT64_C(3) , true);
        lbits zgsz3181;
        CREATE(lbits)(&zgsz3181);
        CONVERT_OF(lbits, fbits)(&zgsz3181, zgaz332, UINT64_C(3) , true);
        zgaz334 = eq_bits(zgsz3181, zgsz3182);
        KILL(lbits)(&zgsz3182);
        KILL(lbits)(&zgsz3181);
      }
    
    }
    bool zgsz3187;
    if (zgaz334) {
    uint64_t zgaz333;
    {
      lbits zgsz3183;
      CREATE(lbits)(&zgsz3183);
      CONVERT_OF(lbits, fbits)(&zgsz3183, zv__20, UINT64_C(32) , true);
      sail_int zgsz3184;
      CREATE(sail_int)(&zgsz3184);
      CONVERT_OF(sail_int, mach_int)(&zgsz3184, INT64_C(6));
      sail_int zgsz3185;
      CREATE(sail_int)(&zgsz3185);
      CONVERT_OF(sail_int, mach_int)(&zgsz3185, INT64_C(0));
      lbits zgsz3186;
      CREATE(lbits)(&zgsz3186);
      vector_subrange_lbits(&zgsz3186, zgsz3183, zgsz3184, zgsz3185);
      zgaz333 = CONVERT_OF(fbits, lbits)(zgsz3186, true);
      KILL(lbits)(&zgsz3186);
      KILL(sail_int)(&zgsz3185);
      KILL(sail_int)(&zgsz3184);
      KILL(lbits)(&zgsz3183);
    }
    {
      lbits zgsz3189;
      CREATE(lbits)(&zgsz3189);
      CONVERT_OF(lbits, fbits)(&zgsz3189, UINT64_C(0b0110011), UINT64_C(7) , true);
      lbits zgsz3188;
      CREATE(lbits)(&zgsz3188);
      CONVERT_OF(lbits, fbits)(&zgsz3188, zgaz333, UINT64_C(7) , true);
      zgsz3187 = eq_bits(zgsz3188, zgsz3189);
      KILL(lbits)(&zgsz3189);
      KILL(lbits)(&zgsz3188);
    }
  
    } else {  zgsz3187 = false;  }
    zgsz3190 = zgsz3187;
  
    } else {  zgsz3190 = false;  }
    bool zgsz3204;
    zgsz3204 = zgsz3190;
  
    if (!(zgsz3204)) {
  
    goto case_7;
    }
    uint64_t zrs2;
    {
      lbits zgsz3191;
      CREATE(lbits)(&zgsz3191);
      CONVERT_OF(lbits, fbits)(&zgsz3191, zv__20, UINT64_C(32) , true);
      sail_int zgsz3192;
      CREATE(sail_int)(&zgsz3192);
      CONVERT_OF(sail_int, mach_int)(&zgsz3192, INT64_C(24));
      sail_int zgsz3193;
      CREATE(sail_int)(&zgsz3193);
      CONVERT_OF(sail_int, mach_int)(&zgsz3193, INT64_C(20));
      lbits zgsz3194;
      CREATE(lbits)(&zgsz3194);
      vector_subrange_lbits(&zgsz3194, zgsz3191, zgsz3192, zgsz3193);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz3194, true);
      KILL(lbits)(&zgsz3194);
      KILL(sail_int)(&zgsz3193);
      KILL(sail_int)(&zgsz3192);
      KILL(lbits)(&zgsz3191);
    }
    uint64_t zrs1;
    {
      lbits zgsz3195;
      CREATE(lbits)(&zgsz3195);
      CONVERT_OF(lbits, fbits)(&zgsz3195, zv__20, UINT64_C(32) , true);
      sail_int zgsz3196;
      CREATE(sail_int)(&zgsz3196);
      CONVERT_OF(sail_int, mach_int)(&zgsz3196, INT64_C(19));
      sail_int zgsz3197;
      CREATE(sail_int)(&zgsz3197);
      CONVERT_OF(sail_int, mach_int)(&zgsz3197, INT64_C(15));
      lbits zgsz3198;
      CREATE(lbits)(&zgsz3198);
      vector_subrange_lbits(&zgsz3198, zgsz3195, zgsz3196, zgsz3197);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3198, true);
      KILL(lbits)(&zgsz3198);
      KILL(sail_int)(&zgsz3197);
      KILL(sail_int)(&zgsz3196);
      KILL(lbits)(&zgsz3195);
    }
    uint64_t zrd;
    {
      lbits zgsz3199;
      CREATE(lbits)(&zgsz3199);
      CONVERT_OF(lbits, fbits)(&zgsz3199, zv__20, UINT64_C(32) , true);
      sail_int zgsz3200;
      CREATE(sail_int)(&zgsz3200);
      CONVERT_OF(sail_int, mach_int)(&zgsz3200, INT64_C(11));
      sail_int zgsz3201;
      CREATE(sail_int)(&zgsz3201);
      CONVERT_OF(sail_int, mach_int)(&zgsz3201, INT64_C(7));
      lbits zgsz3202;
      CREATE(lbits)(&zgsz3202);
      vector_subrange_lbits(&zgsz3202, zgsz3199, zgsz3200, zgsz3201);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3202, true);
      KILL(lbits)(&zgsz3202);
      KILL(sail_int)(&zgsz3201);
      KILL(sail_int)(&zgsz3200);
      KILL(lbits)(&zgsz3199);
    }
    struct zast zgaz330;
    CREATE(zast)(&zgaz330);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3203;
      zgsz3203.ztup0 = zrs2;
      zgsz3203.ztup1 = zrs1;
      zgsz3203.ztup2 = zrd;
      zgsz3203.ztup3 = zDIV;
      zRTYPE(&zgaz330, zgsz3203);
    
    }
    {
      struct zast zgsz3244;
      CREATE(zast)(&zgsz3244);
      COPY(zast)(&zgsz3244, zgaz330);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3244);
      KILL(zast)(&zgsz3244);
    }
    KILL(zast)(&zgaz330);
  
  
  
  
    goto finish_match_1;
  }
case_7: ;
  {
    uint64_t zv__24;
    zv__24 = zmergez3var;
    bool zgaz341;
    {
      uint64_t zgaz337;
      {
        lbits zgsz3205;
        CREATE(lbits)(&zgsz3205);
        CONVERT_OF(lbits, fbits)(&zgsz3205, zv__24, UINT64_C(32) , true);
        sail_int zgsz3206;
        CREATE(sail_int)(&zgsz3206);
        CONVERT_OF(sail_int, mach_int)(&zgsz3206, INT64_C(31));
        sail_int zgsz3207;
        CREATE(sail_int)(&zgsz3207);
        CONVERT_OF(sail_int, mach_int)(&zgsz3207, INT64_C(25));
        lbits zgsz3208;
        CREATE(lbits)(&zgsz3208);
        vector_subrange_lbits(&zgsz3208, zgsz3205, zgsz3206, zgsz3207);
        zgaz337 = CONVERT_OF(fbits, lbits)(zgsz3208, true);
        KILL(lbits)(&zgsz3208);
        KILL(sail_int)(&zgsz3207);
        KILL(sail_int)(&zgsz3206);
        KILL(lbits)(&zgsz3205);
      }
      {
        lbits zgsz3210;
        CREATE(lbits)(&zgsz3210);
        CONVERT_OF(lbits, fbits)(&zgsz3210, UINT64_C(0b0000001), UINT64_C(7) , true);
        lbits zgsz3209;
        CREATE(lbits)(&zgsz3209);
        CONVERT_OF(lbits, fbits)(&zgsz3209, zgaz337, UINT64_C(7) , true);
        zgaz341 = eq_bits(zgsz3209, zgsz3210);
        KILL(lbits)(&zgsz3210);
        KILL(lbits)(&zgsz3209);
      }
    
    }
    bool zgsz3224;
    if (zgaz341) {
    bool zgaz340;
    {
      uint64_t zgaz338;
      {
        lbits zgsz3211;
        CREATE(lbits)(&zgsz3211);
        CONVERT_OF(lbits, fbits)(&zgsz3211, zv__24, UINT64_C(32) , true);
        sail_int zgsz3212;
        CREATE(sail_int)(&zgsz3212);
        CONVERT_OF(sail_int, mach_int)(&zgsz3212, INT64_C(14));
        sail_int zgsz3213;
        CREATE(sail_int)(&zgsz3213);
        CONVERT_OF(sail_int, mach_int)(&zgsz3213, INT64_C(12));
        lbits zgsz3214;
        CREATE(lbits)(&zgsz3214);
        vector_subrange_lbits(&zgsz3214, zgsz3211, zgsz3212, zgsz3213);
        zgaz338 = CONVERT_OF(fbits, lbits)(zgsz3214, true);
        KILL(lbits)(&zgsz3214);
        KILL(sail_int)(&zgsz3213);
        KILL(sail_int)(&zgsz3212);
        KILL(lbits)(&zgsz3211);
      }
      {
        lbits zgsz3216;
        CREATE(lbits)(&zgsz3216);
        CONVERT_OF(lbits, fbits)(&zgsz3216, UINT64_C(0b110), UINT64_C(3) , true);
        lbits zgsz3215;
        CREATE(lbits)(&zgsz3215);
        CONVERT_OF(lbits, fbits)(&zgsz3215, zgaz338, UINT64_C(3) , true);
        zgaz340 = eq_bits(zgsz3215, zgsz3216);
        KILL(lbits)(&zgsz3216);
        KILL(lbits)(&zgsz3215);
      }
    
    }
    bool zgsz3221;
    if (zgaz340) {
    uint64_t zgaz339;
    {
      lbits zgsz3217;
      CREATE(lbits)(&zgsz3217);
      CONVERT_OF(lbits, fbits)(&zgsz3217, zv__24, UINT64_C(32) , true);
      sail_int zgsz3218;
      CREATE(sail_int)(&zgsz3218);
      CONVERT_OF(sail_int, mach_int)(&zgsz3218, INT64_C(6));
      sail_int zgsz3219;
      CREATE(sail_int)(&zgsz3219);
      CONVERT_OF(sail_int, mach_int)(&zgsz3219, INT64_C(0));
      lbits zgsz3220;
      CREATE(lbits)(&zgsz3220);
      vector_subrange_lbits(&zgsz3220, zgsz3217, zgsz3218, zgsz3219);
      zgaz339 = CONVERT_OF(fbits, lbits)(zgsz3220, true);
      KILL(lbits)(&zgsz3220);
      KILL(sail_int)(&zgsz3219);
      KILL(sail_int)(&zgsz3218);
      KILL(lbits)(&zgsz3217);
    }
    {
      lbits zgsz3223;
      CREATE(lbits)(&zgsz3223);
      CONVERT_OF(lbits, fbits)(&zgsz3223, UINT64_C(0b0110011), UINT64_C(7) , true);
      lbits zgsz3222;
      CREATE(lbits)(&zgsz3222);
      CONVERT_OF(lbits, fbits)(&zgsz3222, zgaz339, UINT64_C(7) , true);
      zgsz3221 = eq_bits(zgsz3222, zgsz3223);
      KILL(lbits)(&zgsz3223);
      KILL(lbits)(&zgsz3222);
    }
  
    } else {  zgsz3221 = false;  }
    zgsz3224 = zgsz3221;
  
    } else {  zgsz3224 = false;  }
    bool zgsz3238;
    zgsz3238 = zgsz3224;
  
    if (!(zgsz3238)) {
  
    goto case_8;
    }
    uint64_t zrs2;
    {
      lbits zgsz3225;
      CREATE(lbits)(&zgsz3225);
      CONVERT_OF(lbits, fbits)(&zgsz3225, zv__24, UINT64_C(32) , true);
      sail_int zgsz3226;
      CREATE(sail_int)(&zgsz3226);
      CONVERT_OF(sail_int, mach_int)(&zgsz3226, INT64_C(24));
      sail_int zgsz3227;
      CREATE(sail_int)(&zgsz3227);
      CONVERT_OF(sail_int, mach_int)(&zgsz3227, INT64_C(20));
      lbits zgsz3228;
      CREATE(lbits)(&zgsz3228);
      vector_subrange_lbits(&zgsz3228, zgsz3225, zgsz3226, zgsz3227);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz3228, true);
      KILL(lbits)(&zgsz3228);
      KILL(sail_int)(&zgsz3227);
      KILL(sail_int)(&zgsz3226);
      KILL(lbits)(&zgsz3225);
    }
    uint64_t zrs1;
    {
      lbits zgsz3229;
      CREATE(lbits)(&zgsz3229);
      CONVERT_OF(lbits, fbits)(&zgsz3229, zv__24, UINT64_C(32) , true);
      sail_int zgsz3230;
      CREATE(sail_int)(&zgsz3230);
      CONVERT_OF(sail_int, mach_int)(&zgsz3230, INT64_C(19));
      sail_int zgsz3231;
      CREATE(sail_int)(&zgsz3231);
      CONVERT_OF(sail_int, mach_int)(&zgsz3231, INT64_C(15));
      lbits zgsz3232;
      CREATE(lbits)(&zgsz3232);
      vector_subrange_lbits(&zgsz3232, zgsz3229, zgsz3230, zgsz3231);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3232, true);
      KILL(lbits)(&zgsz3232);
      KILL(sail_int)(&zgsz3231);
      KILL(sail_int)(&zgsz3230);
      KILL(lbits)(&zgsz3229);
    }
    uint64_t zrd;
    {
      lbits zgsz3233;
      CREATE(lbits)(&zgsz3233);
      CONVERT_OF(lbits, fbits)(&zgsz3233, zv__24, UINT64_C(32) , true);
      sail_int zgsz3234;
      CREATE(sail_int)(&zgsz3234);
      CONVERT_OF(sail_int, mach_int)(&zgsz3234, INT64_C(11));
      sail_int zgsz3235;
      CREATE(sail_int)(&zgsz3235);
      CONVERT_OF(sail_int, mach_int)(&zgsz3235, INT64_C(7));
      lbits zgsz3236;
      CREATE(lbits)(&zgsz3236);
      vector_subrange_lbits(&zgsz3236, zgsz3233, zgsz3234, zgsz3235);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3236, true);
      KILL(lbits)(&zgsz3236);
      KILL(sail_int)(&zgsz3235);
      KILL(sail_int)(&zgsz3234);
      KILL(lbits)(&zgsz3233);
    }
    struct zast zgaz336;
    CREATE(zast)(&zgaz336);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3237;
      zgsz3237.ztup0 = zrs2;
      zgsz3237.ztup1 = zrs1;
      zgsz3237.ztup2 = zrd;
      zgsz3237.ztup3 = zREM;
      zRTYPE(&zgaz336, zgsz3237);
    
    }
    {
      struct zast zgsz3245;
      CREATE(zast)(&zgsz3245);
      COPY(zast)(&zgsz3245, zgaz336);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3245);
      KILL(zast)(&zgsz3245);
    }
    KILL(zast)(&zgaz336);
  
  
  
  
    goto finish_match_1;
  }
case_8: ;
  sail_match_failure("decode");
finish_match_1: ;
  COPY(zoption)((*(&zcbz30)), zgsz30);
  KILL(zoption)(&zgsz30);
end_function_9: ;
  goto end_function_11;
end_block_exception_10: ;
  goto end_function_11;
end_function_11: ;
}

void model_init(void)
{
  setup_rts();
}

void model_fini(void)
{
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
