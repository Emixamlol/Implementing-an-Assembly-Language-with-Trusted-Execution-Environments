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






































void zdecode(struct zoption *rop, uint64_t);






unit zexecute(struct zast);


















void zdecode(struct zoption *zcbz30, uint64_t zmergez3var)
{
  __label__ case_2, case_3, case_4, case_5, case_6, case_7, case_8, case_9, case_10, case_11, case_12, case_13, case_14, case_15, case_16, case_17, case_18, case_19, case_20, case_21, finish_match_1, end_function_22, end_block_exception_23, end_function_51;

  struct zoption zgsz30;
  CREATE(zoption)(&zgsz30);
  {
    uint64_t zv__0;
    zv__0 = zmergez3var;
    bool zgaz33;
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
        zgaz33 = eq_bits(zgsz35, zgsz36);
        KILL(lbits)(&zgsz36);
        KILL(lbits)(&zgsz35);
      }
    
    }
    bool zgsz311;
    if (zgaz33) {
    uint64_t zgaz32;
    {
      lbits zgsz37;
      CREATE(lbits)(&zgsz37);
      CONVERT_OF(lbits, fbits)(&zgsz37, zv__0, UINT64_C(32) , true);
      sail_int zgsz38;
      CREATE(sail_int)(&zgsz38);
      CONVERT_OF(sail_int, mach_int)(&zgsz38, INT64_C(6));
      sail_int zgsz39;
      CREATE(sail_int)(&zgsz39);
      CONVERT_OF(sail_int, mach_int)(&zgsz39, INT64_C(0));
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
      lbits zgsz313;
      CREATE(lbits)(&zgsz313);
      CONVERT_OF(lbits, fbits)(&zgsz313, UINT64_C(0b0110011), UINT64_C(7) , true);
      lbits zgsz312;
      CREATE(lbits)(&zgsz312);
      CONVERT_OF(lbits, fbits)(&zgsz312, zgaz32, UINT64_C(7) , true);
      zgsz311 = eq_bits(zgsz312, zgsz313);
      KILL(lbits)(&zgsz313);
      KILL(lbits)(&zgsz312);
    }
  
    } else {  zgsz311 = false;  }
    bool zgsz327;
    zgsz327 = zgsz311;
  
    if (!(zgsz327)) {
  
    goto case_2;
    }
    uint64_t zrs2;
    {
      lbits zgsz314;
      CREATE(lbits)(&zgsz314);
      CONVERT_OF(lbits, fbits)(&zgsz314, zv__0, UINT64_C(32) , true);
      sail_int zgsz315;
      CREATE(sail_int)(&zgsz315);
      CONVERT_OF(sail_int, mach_int)(&zgsz315, INT64_C(24));
      sail_int zgsz316;
      CREATE(sail_int)(&zgsz316);
      CONVERT_OF(sail_int, mach_int)(&zgsz316, INT64_C(20));
      lbits zgsz317;
      CREATE(lbits)(&zgsz317);
      vector_subrange_lbits(&zgsz317, zgsz314, zgsz315, zgsz316);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz317, true);
      KILL(lbits)(&zgsz317);
      KILL(sail_int)(&zgsz316);
      KILL(sail_int)(&zgsz315);
      KILL(lbits)(&zgsz314);
    }
    uint64_t zrs1;
    {
      lbits zgsz318;
      CREATE(lbits)(&zgsz318);
      CONVERT_OF(lbits, fbits)(&zgsz318, zv__0, UINT64_C(32) , true);
      sail_int zgsz319;
      CREATE(sail_int)(&zgsz319);
      CONVERT_OF(sail_int, mach_int)(&zgsz319, INT64_C(19));
      sail_int zgsz320;
      CREATE(sail_int)(&zgsz320);
      CONVERT_OF(sail_int, mach_int)(&zgsz320, INT64_C(15));
      lbits zgsz321;
      CREATE(lbits)(&zgsz321);
      vector_subrange_lbits(&zgsz321, zgsz318, zgsz319, zgsz320);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz321, true);
      KILL(lbits)(&zgsz321);
      KILL(sail_int)(&zgsz320);
      KILL(sail_int)(&zgsz319);
      KILL(lbits)(&zgsz318);
    }
    uint64_t zrd;
    {
      lbits zgsz322;
      CREATE(lbits)(&zgsz322);
      CONVERT_OF(lbits, fbits)(&zgsz322, zv__0, UINT64_C(32) , true);
      sail_int zgsz323;
      CREATE(sail_int)(&zgsz323);
      CONVERT_OF(sail_int, mach_int)(&zgsz323, INT64_C(11));
      sail_int zgsz324;
      CREATE(sail_int)(&zgsz324);
      CONVERT_OF(sail_int, mach_int)(&zgsz324, INT64_C(7));
      lbits zgsz325;
      CREATE(lbits)(&zgsz325);
      vector_subrange_lbits(&zgsz325, zgsz322, zgsz323, zgsz324);
      zrd = CONVERT_OF(fbits, lbits)(zgsz325, true);
      KILL(lbits)(&zgsz325);
      KILL(sail_int)(&zgsz324);
      KILL(sail_int)(&zgsz323);
      KILL(lbits)(&zgsz322);
    }
    struct zast zgaz30;
    CREATE(zast)(&zgaz30);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz326;
      zgsz326.ztup0 = zrs2;
      zgsz326.ztup1 = zrs1;
      zgsz326.ztup2 = zrd;
      zgsz326.ztup3 = zADD;
      zRTYPE(&zgaz30, zgsz326);
    
    }
    {
      struct zast zgsz3552;
      CREATE(zast)(&zgsz3552);
      COPY(zast)(&zgsz3552, zgaz30);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3552);
      KILL(zast)(&zgsz3552);
    }
    KILL(zast)(&zgaz30);
  
  
  
  
    goto finish_match_1;
  }
case_2: ;
  {
    uint64_t zv__3;
    zv__3 = zmergez3var;
    bool zgaz37;
    {
      uint64_t zgaz35;
      {
        lbits zgsz328;
        CREATE(lbits)(&zgsz328);
        CONVERT_OF(lbits, fbits)(&zgsz328, zv__3, UINT64_C(32) , true);
        sail_int zgsz329;
        CREATE(sail_int)(&zgsz329);
        CONVERT_OF(sail_int, mach_int)(&zgsz329, INT64_C(31));
        sail_int zgsz330;
        CREATE(sail_int)(&zgsz330);
        CONVERT_OF(sail_int, mach_int)(&zgsz330, INT64_C(25));
        lbits zgsz331;
        CREATE(lbits)(&zgsz331);
        vector_subrange_lbits(&zgsz331, zgsz328, zgsz329, zgsz330);
        zgaz35 = CONVERT_OF(fbits, lbits)(zgsz331, true);
        KILL(lbits)(&zgsz331);
        KILL(sail_int)(&zgsz330);
        KILL(sail_int)(&zgsz329);
        KILL(lbits)(&zgsz328);
      }
      {
        lbits zgsz333;
        CREATE(lbits)(&zgsz333);
        CONVERT_OF(lbits, fbits)(&zgsz333, UINT64_C(0b0000000), UINT64_C(7) , true);
        lbits zgsz332;
        CREATE(lbits)(&zgsz332);
        CONVERT_OF(lbits, fbits)(&zgsz332, zgaz35, UINT64_C(7) , true);
        zgaz37 = eq_bits(zgsz332, zgsz333);
        KILL(lbits)(&zgsz333);
        KILL(lbits)(&zgsz332);
      }
    
    }
    bool zgsz338;
    if (zgaz37) {
    uint64_t zgaz36;
    {
      lbits zgsz334;
      CREATE(lbits)(&zgsz334);
      CONVERT_OF(lbits, fbits)(&zgsz334, zv__3, UINT64_C(32) , true);
      sail_int zgsz335;
      CREATE(sail_int)(&zgsz335);
      CONVERT_OF(sail_int, mach_int)(&zgsz335, INT64_C(6));
      sail_int zgsz336;
      CREATE(sail_int)(&zgsz336);
      CONVERT_OF(sail_int, mach_int)(&zgsz336, INT64_C(0));
      lbits zgsz337;
      CREATE(lbits)(&zgsz337);
      vector_subrange_lbits(&zgsz337, zgsz334, zgsz335, zgsz336);
      zgaz36 = CONVERT_OF(fbits, lbits)(zgsz337, true);
      KILL(lbits)(&zgsz337);
      KILL(sail_int)(&zgsz336);
      KILL(sail_int)(&zgsz335);
      KILL(lbits)(&zgsz334);
    }
    {
      lbits zgsz340;
      CREATE(lbits)(&zgsz340);
      CONVERT_OF(lbits, fbits)(&zgsz340, UINT64_C(0b0110011), UINT64_C(7) , true);
      lbits zgsz339;
      CREATE(lbits)(&zgsz339);
      CONVERT_OF(lbits, fbits)(&zgsz339, zgaz36, UINT64_C(7) , true);
      zgsz338 = eq_bits(zgsz339, zgsz340);
      KILL(lbits)(&zgsz340);
      KILL(lbits)(&zgsz339);
    }
  
    } else {  zgsz338 = false;  }
    bool zgsz354;
    zgsz354 = zgsz338;
  
    if (!(zgsz354)) {
  
    goto case_3;
    }
    uint64_t zrs2;
    {
      lbits zgsz341;
      CREATE(lbits)(&zgsz341);
      CONVERT_OF(lbits, fbits)(&zgsz341, zv__3, UINT64_C(32) , true);
      sail_int zgsz342;
      CREATE(sail_int)(&zgsz342);
      CONVERT_OF(sail_int, mach_int)(&zgsz342, INT64_C(24));
      sail_int zgsz343;
      CREATE(sail_int)(&zgsz343);
      CONVERT_OF(sail_int, mach_int)(&zgsz343, INT64_C(20));
      lbits zgsz344;
      CREATE(lbits)(&zgsz344);
      vector_subrange_lbits(&zgsz344, zgsz341, zgsz342, zgsz343);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz344, true);
      KILL(lbits)(&zgsz344);
      KILL(sail_int)(&zgsz343);
      KILL(sail_int)(&zgsz342);
      KILL(lbits)(&zgsz341);
    }
    uint64_t zrs1;
    {
      lbits zgsz345;
      CREATE(lbits)(&zgsz345);
      CONVERT_OF(lbits, fbits)(&zgsz345, zv__3, UINT64_C(32) , true);
      sail_int zgsz346;
      CREATE(sail_int)(&zgsz346);
      CONVERT_OF(sail_int, mach_int)(&zgsz346, INT64_C(19));
      sail_int zgsz347;
      CREATE(sail_int)(&zgsz347);
      CONVERT_OF(sail_int, mach_int)(&zgsz347, INT64_C(15));
      lbits zgsz348;
      CREATE(lbits)(&zgsz348);
      vector_subrange_lbits(&zgsz348, zgsz345, zgsz346, zgsz347);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz348, true);
      KILL(lbits)(&zgsz348);
      KILL(sail_int)(&zgsz347);
      KILL(sail_int)(&zgsz346);
      KILL(lbits)(&zgsz345);
    }
    uint64_t zrd;
    {
      lbits zgsz349;
      CREATE(lbits)(&zgsz349);
      CONVERT_OF(lbits, fbits)(&zgsz349, zv__3, UINT64_C(32) , true);
      sail_int zgsz350;
      CREATE(sail_int)(&zgsz350);
      CONVERT_OF(sail_int, mach_int)(&zgsz350, INT64_C(11));
      sail_int zgsz351;
      CREATE(sail_int)(&zgsz351);
      CONVERT_OF(sail_int, mach_int)(&zgsz351, INT64_C(7));
      lbits zgsz352;
      CREATE(lbits)(&zgsz352);
      vector_subrange_lbits(&zgsz352, zgsz349, zgsz350, zgsz351);
      zrd = CONVERT_OF(fbits, lbits)(zgsz352, true);
      KILL(lbits)(&zgsz352);
      KILL(sail_int)(&zgsz351);
      KILL(sail_int)(&zgsz350);
      KILL(lbits)(&zgsz349);
    }
    struct zast zgaz34;
    CREATE(zast)(&zgaz34);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz353;
      zgsz353.ztup0 = zrs2;
      zgsz353.ztup1 = zrs1;
      zgsz353.ztup2 = zrd;
      zgsz353.ztup3 = zAND;
      zRTYPE(&zgaz34, zgsz353);
    
    }
    {
      struct zast zgsz3553;
      CREATE(zast)(&zgsz3553);
      COPY(zast)(&zgsz3553, zgaz34);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3553);
      KILL(zast)(&zgsz3553);
    }
    KILL(zast)(&zgaz34);
  
  
  
  
    goto finish_match_1;
  }
case_3: ;
  {
    uint64_t zv__6;
    zv__6 = zmergez3var;
    bool zgaz311;
    {
      uint64_t zgaz39;
      {
        lbits zgsz355;
        CREATE(lbits)(&zgsz355);
        CONVERT_OF(lbits, fbits)(&zgsz355, zv__6, UINT64_C(32) , true);
        sail_int zgsz356;
        CREATE(sail_int)(&zgsz356);
        CONVERT_OF(sail_int, mach_int)(&zgsz356, INT64_C(31));
        sail_int zgsz357;
        CREATE(sail_int)(&zgsz357);
        CONVERT_OF(sail_int, mach_int)(&zgsz357, INT64_C(25));
        lbits zgsz358;
        CREATE(lbits)(&zgsz358);
        vector_subrange_lbits(&zgsz358, zgsz355, zgsz356, zgsz357);
        zgaz39 = CONVERT_OF(fbits, lbits)(zgsz358, true);
        KILL(lbits)(&zgsz358);
        KILL(sail_int)(&zgsz357);
        KILL(sail_int)(&zgsz356);
        KILL(lbits)(&zgsz355);
      }
      {
        lbits zgsz360;
        CREATE(lbits)(&zgsz360);
        CONVERT_OF(lbits, fbits)(&zgsz360, UINT64_C(0b0000000), UINT64_C(7) , true);
        lbits zgsz359;
        CREATE(lbits)(&zgsz359);
        CONVERT_OF(lbits, fbits)(&zgsz359, zgaz39, UINT64_C(7) , true);
        zgaz311 = eq_bits(zgsz359, zgsz360);
        KILL(lbits)(&zgsz360);
        KILL(lbits)(&zgsz359);
      }
    
    }
    bool zgsz365;
    if (zgaz311) {
    uint64_t zgaz310;
    {
      lbits zgsz361;
      CREATE(lbits)(&zgsz361);
      CONVERT_OF(lbits, fbits)(&zgsz361, zv__6, UINT64_C(32) , true);
      sail_int zgsz362;
      CREATE(sail_int)(&zgsz362);
      CONVERT_OF(sail_int, mach_int)(&zgsz362, INT64_C(6));
      sail_int zgsz363;
      CREATE(sail_int)(&zgsz363);
      CONVERT_OF(sail_int, mach_int)(&zgsz363, INT64_C(0));
      lbits zgsz364;
      CREATE(lbits)(&zgsz364);
      vector_subrange_lbits(&zgsz364, zgsz361, zgsz362, zgsz363);
      zgaz310 = CONVERT_OF(fbits, lbits)(zgsz364, true);
      KILL(lbits)(&zgsz364);
      KILL(sail_int)(&zgsz363);
      KILL(sail_int)(&zgsz362);
      KILL(lbits)(&zgsz361);
    }
    {
      lbits zgsz367;
      CREATE(lbits)(&zgsz367);
      CONVERT_OF(lbits, fbits)(&zgsz367, UINT64_C(0b0110011), UINT64_C(7) , true);
      lbits zgsz366;
      CREATE(lbits)(&zgsz366);
      CONVERT_OF(lbits, fbits)(&zgsz366, zgaz310, UINT64_C(7) , true);
      zgsz365 = eq_bits(zgsz366, zgsz367);
      KILL(lbits)(&zgsz367);
      KILL(lbits)(&zgsz366);
    }
  
    } else {  zgsz365 = false;  }
    bool zgsz381;
    zgsz381 = zgsz365;
  
    if (!(zgsz381)) {
  
    goto case_4;
    }
    uint64_t zrs2;
    {
      lbits zgsz368;
      CREATE(lbits)(&zgsz368);
      CONVERT_OF(lbits, fbits)(&zgsz368, zv__6, UINT64_C(32) , true);
      sail_int zgsz369;
      CREATE(sail_int)(&zgsz369);
      CONVERT_OF(sail_int, mach_int)(&zgsz369, INT64_C(24));
      sail_int zgsz370;
      CREATE(sail_int)(&zgsz370);
      CONVERT_OF(sail_int, mach_int)(&zgsz370, INT64_C(20));
      lbits zgsz371;
      CREATE(lbits)(&zgsz371);
      vector_subrange_lbits(&zgsz371, zgsz368, zgsz369, zgsz370);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz371, true);
      KILL(lbits)(&zgsz371);
      KILL(sail_int)(&zgsz370);
      KILL(sail_int)(&zgsz369);
      KILL(lbits)(&zgsz368);
    }
    uint64_t zrs1;
    {
      lbits zgsz372;
      CREATE(lbits)(&zgsz372);
      CONVERT_OF(lbits, fbits)(&zgsz372, zv__6, UINT64_C(32) , true);
      sail_int zgsz373;
      CREATE(sail_int)(&zgsz373);
      CONVERT_OF(sail_int, mach_int)(&zgsz373, INT64_C(19));
      sail_int zgsz374;
      CREATE(sail_int)(&zgsz374);
      CONVERT_OF(sail_int, mach_int)(&zgsz374, INT64_C(15));
      lbits zgsz375;
      CREATE(lbits)(&zgsz375);
      vector_subrange_lbits(&zgsz375, zgsz372, zgsz373, zgsz374);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz375, true);
      KILL(lbits)(&zgsz375);
      KILL(sail_int)(&zgsz374);
      KILL(sail_int)(&zgsz373);
      KILL(lbits)(&zgsz372);
    }
    uint64_t zrd;
    {
      lbits zgsz376;
      CREATE(lbits)(&zgsz376);
      CONVERT_OF(lbits, fbits)(&zgsz376, zv__6, UINT64_C(32) , true);
      sail_int zgsz377;
      CREATE(sail_int)(&zgsz377);
      CONVERT_OF(sail_int, mach_int)(&zgsz377, INT64_C(11));
      sail_int zgsz378;
      CREATE(sail_int)(&zgsz378);
      CONVERT_OF(sail_int, mach_int)(&zgsz378, INT64_C(7));
      lbits zgsz379;
      CREATE(lbits)(&zgsz379);
      vector_subrange_lbits(&zgsz379, zgsz376, zgsz377, zgsz378);
      zrd = CONVERT_OF(fbits, lbits)(zgsz379, true);
      KILL(lbits)(&zgsz379);
      KILL(sail_int)(&zgsz378);
      KILL(sail_int)(&zgsz377);
      KILL(lbits)(&zgsz376);
    }
    struct zast zgaz38;
    CREATE(zast)(&zgaz38);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz380;
      zgsz380.ztup0 = zrs2;
      zgsz380.ztup1 = zrs1;
      zgsz380.ztup2 = zrd;
      zgsz380.ztup3 = zOR;
      zRTYPE(&zgaz38, zgsz380);
    
    }
    {
      struct zast zgsz3554;
      CREATE(zast)(&zgsz3554);
      COPY(zast)(&zgsz3554, zgaz38);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3554);
      KILL(zast)(&zgsz3554);
    }
    KILL(zast)(&zgaz38);
  
  
  
  
    goto finish_match_1;
  }
case_4: ;
  {
    uint64_t zv__9;
    zv__9 = zmergez3var;
    bool zgaz315;
    {
      uint64_t zgaz313;
      {
        lbits zgsz382;
        CREATE(lbits)(&zgsz382);
        CONVERT_OF(lbits, fbits)(&zgsz382, zv__9, UINT64_C(32) , true);
        sail_int zgsz383;
        CREATE(sail_int)(&zgsz383);
        CONVERT_OF(sail_int, mach_int)(&zgsz383, INT64_C(31));
        sail_int zgsz384;
        CREATE(sail_int)(&zgsz384);
        CONVERT_OF(sail_int, mach_int)(&zgsz384, INT64_C(25));
        lbits zgsz385;
        CREATE(lbits)(&zgsz385);
        vector_subrange_lbits(&zgsz385, zgsz382, zgsz383, zgsz384);
        zgaz313 = CONVERT_OF(fbits, lbits)(zgsz385, true);
        KILL(lbits)(&zgsz385);
        KILL(sail_int)(&zgsz384);
        KILL(sail_int)(&zgsz383);
        KILL(lbits)(&zgsz382);
      }
      {
        lbits zgsz387;
        CREATE(lbits)(&zgsz387);
        CONVERT_OF(lbits, fbits)(&zgsz387, UINT64_C(0b0000000), UINT64_C(7) , true);
        lbits zgsz386;
        CREATE(lbits)(&zgsz386);
        CONVERT_OF(lbits, fbits)(&zgsz386, zgaz313, UINT64_C(7) , true);
        zgaz315 = eq_bits(zgsz386, zgsz387);
        KILL(lbits)(&zgsz387);
        KILL(lbits)(&zgsz386);
      }
    
    }
    bool zgsz392;
    if (zgaz315) {
    uint64_t zgaz314;
    {
      lbits zgsz388;
      CREATE(lbits)(&zgsz388);
      CONVERT_OF(lbits, fbits)(&zgsz388, zv__9, UINT64_C(32) , true);
      sail_int zgsz389;
      CREATE(sail_int)(&zgsz389);
      CONVERT_OF(sail_int, mach_int)(&zgsz389, INT64_C(6));
      sail_int zgsz390;
      CREATE(sail_int)(&zgsz390);
      CONVERT_OF(sail_int, mach_int)(&zgsz390, INT64_C(0));
      lbits zgsz391;
      CREATE(lbits)(&zgsz391);
      vector_subrange_lbits(&zgsz391, zgsz388, zgsz389, zgsz390);
      zgaz314 = CONVERT_OF(fbits, lbits)(zgsz391, true);
      KILL(lbits)(&zgsz391);
      KILL(sail_int)(&zgsz390);
      KILL(sail_int)(&zgsz389);
      KILL(lbits)(&zgsz388);
    }
    {
      lbits zgsz394;
      CREATE(lbits)(&zgsz394);
      CONVERT_OF(lbits, fbits)(&zgsz394, UINT64_C(0b0110011), UINT64_C(7) , true);
      lbits zgsz393;
      CREATE(lbits)(&zgsz393);
      CONVERT_OF(lbits, fbits)(&zgsz393, zgaz314, UINT64_C(7) , true);
      zgsz392 = eq_bits(zgsz393, zgsz394);
      KILL(lbits)(&zgsz394);
      KILL(lbits)(&zgsz393);
    }
  
    } else {  zgsz392 = false;  }
    bool zgsz3108;
    zgsz3108 = zgsz392;
  
    if (!(zgsz3108)) {
  
    goto case_5;
    }
    uint64_t zrs2;
    {
      lbits zgsz395;
      CREATE(lbits)(&zgsz395);
      CONVERT_OF(lbits, fbits)(&zgsz395, zv__9, UINT64_C(32) , true);
      sail_int zgsz396;
      CREATE(sail_int)(&zgsz396);
      CONVERT_OF(sail_int, mach_int)(&zgsz396, INT64_C(24));
      sail_int zgsz397;
      CREATE(sail_int)(&zgsz397);
      CONVERT_OF(sail_int, mach_int)(&zgsz397, INT64_C(20));
      lbits zgsz398;
      CREATE(lbits)(&zgsz398);
      vector_subrange_lbits(&zgsz398, zgsz395, zgsz396, zgsz397);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz398, true);
      KILL(lbits)(&zgsz398);
      KILL(sail_int)(&zgsz397);
      KILL(sail_int)(&zgsz396);
      KILL(lbits)(&zgsz395);
    }
    uint64_t zrs1;
    {
      lbits zgsz399;
      CREATE(lbits)(&zgsz399);
      CONVERT_OF(lbits, fbits)(&zgsz399, zv__9, UINT64_C(32) , true);
      sail_int zgsz3100;
      CREATE(sail_int)(&zgsz3100);
      CONVERT_OF(sail_int, mach_int)(&zgsz3100, INT64_C(19));
      sail_int zgsz3101;
      CREATE(sail_int)(&zgsz3101);
      CONVERT_OF(sail_int, mach_int)(&zgsz3101, INT64_C(15));
      lbits zgsz3102;
      CREATE(lbits)(&zgsz3102);
      vector_subrange_lbits(&zgsz3102, zgsz399, zgsz3100, zgsz3101);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3102, true);
      KILL(lbits)(&zgsz3102);
      KILL(sail_int)(&zgsz3101);
      KILL(sail_int)(&zgsz3100);
      KILL(lbits)(&zgsz399);
    }
    uint64_t zrd;
    {
      lbits zgsz3103;
      CREATE(lbits)(&zgsz3103);
      CONVERT_OF(lbits, fbits)(&zgsz3103, zv__9, UINT64_C(32) , true);
      sail_int zgsz3104;
      CREATE(sail_int)(&zgsz3104);
      CONVERT_OF(sail_int, mach_int)(&zgsz3104, INT64_C(11));
      sail_int zgsz3105;
      CREATE(sail_int)(&zgsz3105);
      CONVERT_OF(sail_int, mach_int)(&zgsz3105, INT64_C(7));
      lbits zgsz3106;
      CREATE(lbits)(&zgsz3106);
      vector_subrange_lbits(&zgsz3106, zgsz3103, zgsz3104, zgsz3105);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3106, true);
      KILL(lbits)(&zgsz3106);
      KILL(sail_int)(&zgsz3105);
      KILL(sail_int)(&zgsz3104);
      KILL(lbits)(&zgsz3103);
    }
    struct zast zgaz312;
    CREATE(zast)(&zgaz312);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3107;
      zgsz3107.ztup0 = zrs2;
      zgsz3107.ztup1 = zrs1;
      zgsz3107.ztup2 = zrd;
      zgsz3107.ztup3 = zXOR;
      zRTYPE(&zgaz312, zgsz3107);
    
    }
    {
      struct zast zgsz3555;
      CREATE(zast)(&zgsz3555);
      COPY(zast)(&zgsz3555, zgaz312);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3555);
      KILL(zast)(&zgsz3555);
    }
    KILL(zast)(&zgaz312);
  
  
  
  
    goto finish_match_1;
  }
case_5: ;
  {
    uint64_t zv__12;
    zv__12 = zmergez3var;
    bool zgaz319;
    {
      uint64_t zgaz317;
      {
        lbits zgsz3109;
        CREATE(lbits)(&zgsz3109);
        CONVERT_OF(lbits, fbits)(&zgsz3109, zv__12, UINT64_C(32) , true);
        sail_int zgsz3110;
        CREATE(sail_int)(&zgsz3110);
        CONVERT_OF(sail_int, mach_int)(&zgsz3110, INT64_C(31));
        sail_int zgsz3111;
        CREATE(sail_int)(&zgsz3111);
        CONVERT_OF(sail_int, mach_int)(&zgsz3111, INT64_C(25));
        lbits zgsz3112;
        CREATE(lbits)(&zgsz3112);
        vector_subrange_lbits(&zgsz3112, zgsz3109, zgsz3110, zgsz3111);
        zgaz317 = CONVERT_OF(fbits, lbits)(zgsz3112, true);
        KILL(lbits)(&zgsz3112);
        KILL(sail_int)(&zgsz3111);
        KILL(sail_int)(&zgsz3110);
        KILL(lbits)(&zgsz3109);
      }
      {
        lbits zgsz3114;
        CREATE(lbits)(&zgsz3114);
        CONVERT_OF(lbits, fbits)(&zgsz3114, UINT64_C(0b0000001), UINT64_C(7) , true);
        lbits zgsz3113;
        CREATE(lbits)(&zgsz3113);
        CONVERT_OF(lbits, fbits)(&zgsz3113, zgaz317, UINT64_C(7) , true);
        zgaz319 = eq_bits(zgsz3113, zgsz3114);
        KILL(lbits)(&zgsz3114);
        KILL(lbits)(&zgsz3113);
      }
    
    }
    bool zgsz3119;
    if (zgaz319) {
    uint64_t zgaz318;
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
      zgaz318 = CONVERT_OF(fbits, lbits)(zgsz3118, true);
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
      CONVERT_OF(lbits, fbits)(&zgsz3120, zgaz318, UINT64_C(7) , true);
      zgsz3119 = eq_bits(zgsz3120, zgsz3121);
      KILL(lbits)(&zgsz3121);
      KILL(lbits)(&zgsz3120);
    }
  
    } else {  zgsz3119 = false;  }
    bool zgsz3135;
    zgsz3135 = zgsz3119;
  
    if (!(zgsz3135)) {
  
    goto case_6;
    }
    uint64_t zrs2;
    {
      lbits zgsz3122;
      CREATE(lbits)(&zgsz3122);
      CONVERT_OF(lbits, fbits)(&zgsz3122, zv__12, UINT64_C(32) , true);
      sail_int zgsz3123;
      CREATE(sail_int)(&zgsz3123);
      CONVERT_OF(sail_int, mach_int)(&zgsz3123, INT64_C(24));
      sail_int zgsz3124;
      CREATE(sail_int)(&zgsz3124);
      CONVERT_OF(sail_int, mach_int)(&zgsz3124, INT64_C(20));
      lbits zgsz3125;
      CREATE(lbits)(&zgsz3125);
      vector_subrange_lbits(&zgsz3125, zgsz3122, zgsz3123, zgsz3124);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz3125, true);
      KILL(lbits)(&zgsz3125);
      KILL(sail_int)(&zgsz3124);
      KILL(sail_int)(&zgsz3123);
      KILL(lbits)(&zgsz3122);
    }
    uint64_t zrs1;
    {
      lbits zgsz3126;
      CREATE(lbits)(&zgsz3126);
      CONVERT_OF(lbits, fbits)(&zgsz3126, zv__12, UINT64_C(32) , true);
      sail_int zgsz3127;
      CREATE(sail_int)(&zgsz3127);
      CONVERT_OF(sail_int, mach_int)(&zgsz3127, INT64_C(19));
      sail_int zgsz3128;
      CREATE(sail_int)(&zgsz3128);
      CONVERT_OF(sail_int, mach_int)(&zgsz3128, INT64_C(15));
      lbits zgsz3129;
      CREATE(lbits)(&zgsz3129);
      vector_subrange_lbits(&zgsz3129, zgsz3126, zgsz3127, zgsz3128);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3129, true);
      KILL(lbits)(&zgsz3129);
      KILL(sail_int)(&zgsz3128);
      KILL(sail_int)(&zgsz3127);
      KILL(lbits)(&zgsz3126);
    }
    uint64_t zrd;
    {
      lbits zgsz3130;
      CREATE(lbits)(&zgsz3130);
      CONVERT_OF(lbits, fbits)(&zgsz3130, zv__12, UINT64_C(32) , true);
      sail_int zgsz3131;
      CREATE(sail_int)(&zgsz3131);
      CONVERT_OF(sail_int, mach_int)(&zgsz3131, INT64_C(11));
      sail_int zgsz3132;
      CREATE(sail_int)(&zgsz3132);
      CONVERT_OF(sail_int, mach_int)(&zgsz3132, INT64_C(7));
      lbits zgsz3133;
      CREATE(lbits)(&zgsz3133);
      vector_subrange_lbits(&zgsz3133, zgsz3130, zgsz3131, zgsz3132);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3133, true);
      KILL(lbits)(&zgsz3133);
      KILL(sail_int)(&zgsz3132);
      KILL(sail_int)(&zgsz3131);
      KILL(lbits)(&zgsz3130);
    }
    struct zast zgaz316;
    CREATE(zast)(&zgaz316);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3134;
      zgsz3134.ztup0 = zrs2;
      zgsz3134.ztup1 = zrs1;
      zgsz3134.ztup2 = zrd;
      zgsz3134.ztup3 = zMUL;
      zRTYPE(&zgaz316, zgsz3134);
    
    }
    {
      struct zast zgsz3556;
      CREATE(zast)(&zgsz3556);
      COPY(zast)(&zgsz3556, zgaz316);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3556);
      KILL(zast)(&zgsz3556);
    }
    KILL(zast)(&zgaz316);
  
  
  
  
    goto finish_match_1;
  }
case_6: ;
  {
    uint64_t zv__15;
    zv__15 = zmergez3var;
    bool zgaz323;
    {
      uint64_t zgaz321;
      {
        lbits zgsz3136;
        CREATE(lbits)(&zgsz3136);
        CONVERT_OF(lbits, fbits)(&zgsz3136, zv__15, UINT64_C(32) , true);
        sail_int zgsz3137;
        CREATE(sail_int)(&zgsz3137);
        CONVERT_OF(sail_int, mach_int)(&zgsz3137, INT64_C(31));
        sail_int zgsz3138;
        CREATE(sail_int)(&zgsz3138);
        CONVERT_OF(sail_int, mach_int)(&zgsz3138, INT64_C(25));
        lbits zgsz3139;
        CREATE(lbits)(&zgsz3139);
        vector_subrange_lbits(&zgsz3139, zgsz3136, zgsz3137, zgsz3138);
        zgaz321 = CONVERT_OF(fbits, lbits)(zgsz3139, true);
        KILL(lbits)(&zgsz3139);
        KILL(sail_int)(&zgsz3138);
        KILL(sail_int)(&zgsz3137);
        KILL(lbits)(&zgsz3136);
      }
      {
        lbits zgsz3141;
        CREATE(lbits)(&zgsz3141);
        CONVERT_OF(lbits, fbits)(&zgsz3141, UINT64_C(0b0000001), UINT64_C(7) , true);
        lbits zgsz3140;
        CREATE(lbits)(&zgsz3140);
        CONVERT_OF(lbits, fbits)(&zgsz3140, zgaz321, UINT64_C(7) , true);
        zgaz323 = eq_bits(zgsz3140, zgsz3141);
        KILL(lbits)(&zgsz3141);
        KILL(lbits)(&zgsz3140);
      }
    
    }
    bool zgsz3146;
    if (zgaz323) {
    uint64_t zgaz322;
    {
      lbits zgsz3142;
      CREATE(lbits)(&zgsz3142);
      CONVERT_OF(lbits, fbits)(&zgsz3142, zv__15, UINT64_C(32) , true);
      sail_int zgsz3143;
      CREATE(sail_int)(&zgsz3143);
      CONVERT_OF(sail_int, mach_int)(&zgsz3143, INT64_C(6));
      sail_int zgsz3144;
      CREATE(sail_int)(&zgsz3144);
      CONVERT_OF(sail_int, mach_int)(&zgsz3144, INT64_C(0));
      lbits zgsz3145;
      CREATE(lbits)(&zgsz3145);
      vector_subrange_lbits(&zgsz3145, zgsz3142, zgsz3143, zgsz3144);
      zgaz322 = CONVERT_OF(fbits, lbits)(zgsz3145, true);
      KILL(lbits)(&zgsz3145);
      KILL(sail_int)(&zgsz3144);
      KILL(sail_int)(&zgsz3143);
      KILL(lbits)(&zgsz3142);
    }
    {
      lbits zgsz3148;
      CREATE(lbits)(&zgsz3148);
      CONVERT_OF(lbits, fbits)(&zgsz3148, UINT64_C(0b0110011), UINT64_C(7) , true);
      lbits zgsz3147;
      CREATE(lbits)(&zgsz3147);
      CONVERT_OF(lbits, fbits)(&zgsz3147, zgaz322, UINT64_C(7) , true);
      zgsz3146 = eq_bits(zgsz3147, zgsz3148);
      KILL(lbits)(&zgsz3148);
      KILL(lbits)(&zgsz3147);
    }
  
    } else {  zgsz3146 = false;  }
    bool zgsz3162;
    zgsz3162 = zgsz3146;
  
    if (!(zgsz3162)) {
  
    goto case_7;
    }
    uint64_t zrs2;
    {
      lbits zgsz3149;
      CREATE(lbits)(&zgsz3149);
      CONVERT_OF(lbits, fbits)(&zgsz3149, zv__15, UINT64_C(32) , true);
      sail_int zgsz3150;
      CREATE(sail_int)(&zgsz3150);
      CONVERT_OF(sail_int, mach_int)(&zgsz3150, INT64_C(24));
      sail_int zgsz3151;
      CREATE(sail_int)(&zgsz3151);
      CONVERT_OF(sail_int, mach_int)(&zgsz3151, INT64_C(20));
      lbits zgsz3152;
      CREATE(lbits)(&zgsz3152);
      vector_subrange_lbits(&zgsz3152, zgsz3149, zgsz3150, zgsz3151);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz3152, true);
      KILL(lbits)(&zgsz3152);
      KILL(sail_int)(&zgsz3151);
      KILL(sail_int)(&zgsz3150);
      KILL(lbits)(&zgsz3149);
    }
    uint64_t zrs1;
    {
      lbits zgsz3153;
      CREATE(lbits)(&zgsz3153);
      CONVERT_OF(lbits, fbits)(&zgsz3153, zv__15, UINT64_C(32) , true);
      sail_int zgsz3154;
      CREATE(sail_int)(&zgsz3154);
      CONVERT_OF(sail_int, mach_int)(&zgsz3154, INT64_C(19));
      sail_int zgsz3155;
      CREATE(sail_int)(&zgsz3155);
      CONVERT_OF(sail_int, mach_int)(&zgsz3155, INT64_C(15));
      lbits zgsz3156;
      CREATE(lbits)(&zgsz3156);
      vector_subrange_lbits(&zgsz3156, zgsz3153, zgsz3154, zgsz3155);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3156, true);
      KILL(lbits)(&zgsz3156);
      KILL(sail_int)(&zgsz3155);
      KILL(sail_int)(&zgsz3154);
      KILL(lbits)(&zgsz3153);
    }
    uint64_t zrd;
    {
      lbits zgsz3157;
      CREATE(lbits)(&zgsz3157);
      CONVERT_OF(lbits, fbits)(&zgsz3157, zv__15, UINT64_C(32) , true);
      sail_int zgsz3158;
      CREATE(sail_int)(&zgsz3158);
      CONVERT_OF(sail_int, mach_int)(&zgsz3158, INT64_C(11));
      sail_int zgsz3159;
      CREATE(sail_int)(&zgsz3159);
      CONVERT_OF(sail_int, mach_int)(&zgsz3159, INT64_C(7));
      lbits zgsz3160;
      CREATE(lbits)(&zgsz3160);
      vector_subrange_lbits(&zgsz3160, zgsz3157, zgsz3158, zgsz3159);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3160, true);
      KILL(lbits)(&zgsz3160);
      KILL(sail_int)(&zgsz3159);
      KILL(sail_int)(&zgsz3158);
      KILL(lbits)(&zgsz3157);
    }
    struct zast zgaz320;
    CREATE(zast)(&zgaz320);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3161;
      zgsz3161.ztup0 = zrs2;
      zgsz3161.ztup1 = zrs1;
      zgsz3161.ztup2 = zrd;
      zgsz3161.ztup3 = zDIV;
      zRTYPE(&zgaz320, zgsz3161);
    
    }
    {
      struct zast zgsz3557;
      CREATE(zast)(&zgsz3557);
      COPY(zast)(&zgsz3557, zgaz320);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3557);
      KILL(zast)(&zgsz3557);
    }
    KILL(zast)(&zgaz320);
  
  
  
  
    goto finish_match_1;
  }
case_7: ;
  {
    uint64_t zv__18;
    zv__18 = zmergez3var;
    bool zgaz327;
    {
      uint64_t zgaz325;
      {
        lbits zgsz3163;
        CREATE(lbits)(&zgsz3163);
        CONVERT_OF(lbits, fbits)(&zgsz3163, zv__18, UINT64_C(32) , true);
        sail_int zgsz3164;
        CREATE(sail_int)(&zgsz3164);
        CONVERT_OF(sail_int, mach_int)(&zgsz3164, INT64_C(31));
        sail_int zgsz3165;
        CREATE(sail_int)(&zgsz3165);
        CONVERT_OF(sail_int, mach_int)(&zgsz3165, INT64_C(25));
        lbits zgsz3166;
        CREATE(lbits)(&zgsz3166);
        vector_subrange_lbits(&zgsz3166, zgsz3163, zgsz3164, zgsz3165);
        zgaz325 = CONVERT_OF(fbits, lbits)(zgsz3166, true);
        KILL(lbits)(&zgsz3166);
        KILL(sail_int)(&zgsz3165);
        KILL(sail_int)(&zgsz3164);
        KILL(lbits)(&zgsz3163);
      }
      {
        lbits zgsz3168;
        CREATE(lbits)(&zgsz3168);
        CONVERT_OF(lbits, fbits)(&zgsz3168, UINT64_C(0b0000001), UINT64_C(7) , true);
        lbits zgsz3167;
        CREATE(lbits)(&zgsz3167);
        CONVERT_OF(lbits, fbits)(&zgsz3167, zgaz325, UINT64_C(7) , true);
        zgaz327 = eq_bits(zgsz3167, zgsz3168);
        KILL(lbits)(&zgsz3168);
        KILL(lbits)(&zgsz3167);
      }
    
    }
    bool zgsz3173;
    if (zgaz327) {
    uint64_t zgaz326;
    {
      lbits zgsz3169;
      CREATE(lbits)(&zgsz3169);
      CONVERT_OF(lbits, fbits)(&zgsz3169, zv__18, UINT64_C(32) , true);
      sail_int zgsz3170;
      CREATE(sail_int)(&zgsz3170);
      CONVERT_OF(sail_int, mach_int)(&zgsz3170, INT64_C(6));
      sail_int zgsz3171;
      CREATE(sail_int)(&zgsz3171);
      CONVERT_OF(sail_int, mach_int)(&zgsz3171, INT64_C(0));
      lbits zgsz3172;
      CREATE(lbits)(&zgsz3172);
      vector_subrange_lbits(&zgsz3172, zgsz3169, zgsz3170, zgsz3171);
      zgaz326 = CONVERT_OF(fbits, lbits)(zgsz3172, true);
      KILL(lbits)(&zgsz3172);
      KILL(sail_int)(&zgsz3171);
      KILL(sail_int)(&zgsz3170);
      KILL(lbits)(&zgsz3169);
    }
    {
      lbits zgsz3175;
      CREATE(lbits)(&zgsz3175);
      CONVERT_OF(lbits, fbits)(&zgsz3175, UINT64_C(0b0110011), UINT64_C(7) , true);
      lbits zgsz3174;
      CREATE(lbits)(&zgsz3174);
      CONVERT_OF(lbits, fbits)(&zgsz3174, zgaz326, UINT64_C(7) , true);
      zgsz3173 = eq_bits(zgsz3174, zgsz3175);
      KILL(lbits)(&zgsz3175);
      KILL(lbits)(&zgsz3174);
    }
  
    } else {  zgsz3173 = false;  }
    bool zgsz3189;
    zgsz3189 = zgsz3173;
  
    if (!(zgsz3189)) {
  
    goto case_8;
    }
    uint64_t zrs2;
    {
      lbits zgsz3176;
      CREATE(lbits)(&zgsz3176);
      CONVERT_OF(lbits, fbits)(&zgsz3176, zv__18, UINT64_C(32) , true);
      sail_int zgsz3177;
      CREATE(sail_int)(&zgsz3177);
      CONVERT_OF(sail_int, mach_int)(&zgsz3177, INT64_C(24));
      sail_int zgsz3178;
      CREATE(sail_int)(&zgsz3178);
      CONVERT_OF(sail_int, mach_int)(&zgsz3178, INT64_C(20));
      lbits zgsz3179;
      CREATE(lbits)(&zgsz3179);
      vector_subrange_lbits(&zgsz3179, zgsz3176, zgsz3177, zgsz3178);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz3179, true);
      KILL(lbits)(&zgsz3179);
      KILL(sail_int)(&zgsz3178);
      KILL(sail_int)(&zgsz3177);
      KILL(lbits)(&zgsz3176);
    }
    uint64_t zrs1;
    {
      lbits zgsz3180;
      CREATE(lbits)(&zgsz3180);
      CONVERT_OF(lbits, fbits)(&zgsz3180, zv__18, UINT64_C(32) , true);
      sail_int zgsz3181;
      CREATE(sail_int)(&zgsz3181);
      CONVERT_OF(sail_int, mach_int)(&zgsz3181, INT64_C(19));
      sail_int zgsz3182;
      CREATE(sail_int)(&zgsz3182);
      CONVERT_OF(sail_int, mach_int)(&zgsz3182, INT64_C(15));
      lbits zgsz3183;
      CREATE(lbits)(&zgsz3183);
      vector_subrange_lbits(&zgsz3183, zgsz3180, zgsz3181, zgsz3182);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3183, true);
      KILL(lbits)(&zgsz3183);
      KILL(sail_int)(&zgsz3182);
      KILL(sail_int)(&zgsz3181);
      KILL(lbits)(&zgsz3180);
    }
    uint64_t zrd;
    {
      lbits zgsz3184;
      CREATE(lbits)(&zgsz3184);
      CONVERT_OF(lbits, fbits)(&zgsz3184, zv__18, UINT64_C(32) , true);
      sail_int zgsz3185;
      CREATE(sail_int)(&zgsz3185);
      CONVERT_OF(sail_int, mach_int)(&zgsz3185, INT64_C(11));
      sail_int zgsz3186;
      CREATE(sail_int)(&zgsz3186);
      CONVERT_OF(sail_int, mach_int)(&zgsz3186, INT64_C(7));
      lbits zgsz3187;
      CREATE(lbits)(&zgsz3187);
      vector_subrange_lbits(&zgsz3187, zgsz3184, zgsz3185, zgsz3186);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3187, true);
      KILL(lbits)(&zgsz3187);
      KILL(sail_int)(&zgsz3186);
      KILL(sail_int)(&zgsz3185);
      KILL(lbits)(&zgsz3184);
    }
    struct zast zgaz324;
    CREATE(zast)(&zgaz324);
    {
      struct ztuple_z8z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzropz9 zgsz3188;
      zgsz3188.ztup0 = zrs2;
      zgsz3188.ztup1 = zrs1;
      zgsz3188.ztup2 = zrd;
      zgsz3188.ztup3 = zREM;
      zRTYPE(&zgaz324, zgsz3188);
    
    }
    {
      struct zast zgsz3558;
      CREATE(zast)(&zgsz3558);
      COPY(zast)(&zgsz3558, zgaz324);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3558);
      KILL(zast)(&zgsz3558);
    }
    KILL(zast)(&zgaz324);
  
  
  
  
    goto finish_match_1;
  }
case_8: ;
  {
    uint64_t zv__21;
    zv__21 = zmergez3var;
    uint64_t zgaz329;
    {
      lbits zgsz3190;
      CREATE(lbits)(&zgsz3190);
      CONVERT_OF(lbits, fbits)(&zgsz3190, zv__21, UINT64_C(32) , true);
      sail_int zgsz3191;
      CREATE(sail_int)(&zgsz3191);
      CONVERT_OF(sail_int, mach_int)(&zgsz3191, INT64_C(6));
      sail_int zgsz3192;
      CREATE(sail_int)(&zgsz3192);
      CONVERT_OF(sail_int, mach_int)(&zgsz3192, INT64_C(0));
      lbits zgsz3193;
      CREATE(lbits)(&zgsz3193);
      vector_subrange_lbits(&zgsz3193, zgsz3190, zgsz3191, zgsz3192);
      zgaz329 = CONVERT_OF(fbits, lbits)(zgsz3193, true);
      KILL(lbits)(&zgsz3193);
      KILL(sail_int)(&zgsz3192);
      KILL(sail_int)(&zgsz3191);
      KILL(lbits)(&zgsz3190);
    }
    bool zgsz3211;
    {
      lbits zgsz3213;
      CREATE(lbits)(&zgsz3213);
      CONVERT_OF(lbits, fbits)(&zgsz3213, UINT64_C(0b0010011), UINT64_C(7) , true);
      lbits zgsz3212;
      CREATE(lbits)(&zgsz3212);
      CONVERT_OF(lbits, fbits)(&zgsz3212, zgaz329, UINT64_C(7) , true);
      zgsz3211 = eq_bits(zgsz3212, zgsz3213);
      KILL(lbits)(&zgsz3213);
      KILL(lbits)(&zgsz3212);
    }
  
    if (!(zgsz3211)) {
  
    goto case_9;
    }
    uint64_t zimm;
    {
      lbits zgsz3194;
      CREATE(lbits)(&zgsz3194);
      CONVERT_OF(lbits, fbits)(&zgsz3194, zv__21, UINT64_C(32) , true);
      sail_int zgsz3195;
      CREATE(sail_int)(&zgsz3195);
      CONVERT_OF(sail_int, mach_int)(&zgsz3195, INT64_C(31));
      sail_int zgsz3196;
      CREATE(sail_int)(&zgsz3196);
      CONVERT_OF(sail_int, mach_int)(&zgsz3196, INT64_C(20));
      lbits zgsz3197;
      CREATE(lbits)(&zgsz3197);
      vector_subrange_lbits(&zgsz3197, zgsz3194, zgsz3195, zgsz3196);
      zimm = CONVERT_OF(fbits, lbits)(zgsz3197, true);
      KILL(lbits)(&zgsz3197);
      KILL(sail_int)(&zgsz3196);
      KILL(sail_int)(&zgsz3195);
      KILL(lbits)(&zgsz3194);
    }
    uint64_t zrs1;
    {
      lbits zgsz3198;
      CREATE(lbits)(&zgsz3198);
      CONVERT_OF(lbits, fbits)(&zgsz3198, zv__21, UINT64_C(32) , true);
      sail_int zgsz3199;
      CREATE(sail_int)(&zgsz3199);
      CONVERT_OF(sail_int, mach_int)(&zgsz3199, INT64_C(19));
      sail_int zgsz3200;
      CREATE(sail_int)(&zgsz3200);
      CONVERT_OF(sail_int, mach_int)(&zgsz3200, INT64_C(15));
      lbits zgsz3201;
      CREATE(lbits)(&zgsz3201);
      vector_subrange_lbits(&zgsz3201, zgsz3198, zgsz3199, zgsz3200);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3201, true);
      KILL(lbits)(&zgsz3201);
      KILL(sail_int)(&zgsz3200);
      KILL(sail_int)(&zgsz3199);
      KILL(lbits)(&zgsz3198);
    }
    uint64_t zrd;
    {
      lbits zgsz3202;
      CREATE(lbits)(&zgsz3202);
      CONVERT_OF(lbits, fbits)(&zgsz3202, zv__21, UINT64_C(32) , true);
      sail_int zgsz3203;
      CREATE(sail_int)(&zgsz3203);
      CONVERT_OF(sail_int, mach_int)(&zgsz3203, INT64_C(11));
      sail_int zgsz3204;
      CREATE(sail_int)(&zgsz3204);
      CONVERT_OF(sail_int, mach_int)(&zgsz3204, INT64_C(7));
      lbits zgsz3205;
      CREATE(lbits)(&zgsz3205);
      vector_subrange_lbits(&zgsz3205, zgsz3202, zgsz3203, zgsz3204);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3205, true);
      KILL(lbits)(&zgsz3205);
      KILL(sail_int)(&zgsz3204);
      KILL(sail_int)(&zgsz3203);
      KILL(lbits)(&zgsz3202);
    }
    uint64_t zimmshadowz30;
    {
      lbits zgsz3206;
      CREATE(lbits)(&zgsz3206);
      CONVERT_OF(lbits, fbits)(&zgsz3206, zv__21, UINT64_C(32) , true);
      sail_int zgsz3207;
      CREATE(sail_int)(&zgsz3207);
      CONVERT_OF(sail_int, mach_int)(&zgsz3207, INT64_C(31));
      sail_int zgsz3208;
      CREATE(sail_int)(&zgsz3208);
      CONVERT_OF(sail_int, mach_int)(&zgsz3208, INT64_C(20));
      lbits zgsz3209;
      CREATE(lbits)(&zgsz3209);
      vector_subrange_lbits(&zgsz3209, zgsz3206, zgsz3207, zgsz3208);
      zimmshadowz30 = CONVERT_OF(fbits, lbits)(zgsz3209, true);
      KILL(lbits)(&zgsz3209);
      KILL(sail_int)(&zgsz3208);
      KILL(sail_int)(&zgsz3207);
      KILL(lbits)(&zgsz3206);
    }
    struct zast zgaz328;
    CREATE(zast)(&zgaz328);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3210;
      zgsz3210.ztup0 = zimmshadowz30;
      zgsz3210.ztup1 = zrs1;
      zgsz3210.ztup2 = zrd;
      zgsz3210.ztup3 = zADDI;
      zITYPE(&zgaz328, zgsz3210);
    
    }
    {
      struct zast zgsz3559;
      CREATE(zast)(&zgsz3559);
      COPY(zast)(&zgsz3559, zgaz328);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3559);
      KILL(zast)(&zgsz3559);
    }
    KILL(zast)(&zgaz328);
  
  
  
  
  
    goto finish_match_1;
  }
case_9: ;
  {
    uint64_t zv__23;
    zv__23 = zmergez3var;
    uint64_t zgaz331;
    {
      lbits zgsz3214;
      CREATE(lbits)(&zgsz3214);
      CONVERT_OF(lbits, fbits)(&zgsz3214, zv__23, UINT64_C(32) , true);
      sail_int zgsz3215;
      CREATE(sail_int)(&zgsz3215);
      CONVERT_OF(sail_int, mach_int)(&zgsz3215, INT64_C(6));
      sail_int zgsz3216;
      CREATE(sail_int)(&zgsz3216);
      CONVERT_OF(sail_int, mach_int)(&zgsz3216, INT64_C(0));
      lbits zgsz3217;
      CREATE(lbits)(&zgsz3217);
      vector_subrange_lbits(&zgsz3217, zgsz3214, zgsz3215, zgsz3216);
      zgaz331 = CONVERT_OF(fbits, lbits)(zgsz3217, true);
      KILL(lbits)(&zgsz3217);
      KILL(sail_int)(&zgsz3216);
      KILL(sail_int)(&zgsz3215);
      KILL(lbits)(&zgsz3214);
    }
    bool zgsz3235;
    {
      lbits zgsz3237;
      CREATE(lbits)(&zgsz3237);
      CONVERT_OF(lbits, fbits)(&zgsz3237, UINT64_C(0b0010011), UINT64_C(7) , true);
      lbits zgsz3236;
      CREATE(lbits)(&zgsz3236);
      CONVERT_OF(lbits, fbits)(&zgsz3236, zgaz331, UINT64_C(7) , true);
      zgsz3235 = eq_bits(zgsz3236, zgsz3237);
      KILL(lbits)(&zgsz3237);
      KILL(lbits)(&zgsz3236);
    }
  
    if (!(zgsz3235)) {
  
    goto case_10;
    }
    uint64_t zimm;
    {
      lbits zgsz3218;
      CREATE(lbits)(&zgsz3218);
      CONVERT_OF(lbits, fbits)(&zgsz3218, zv__23, UINT64_C(32) , true);
      sail_int zgsz3219;
      CREATE(sail_int)(&zgsz3219);
      CONVERT_OF(sail_int, mach_int)(&zgsz3219, INT64_C(31));
      sail_int zgsz3220;
      CREATE(sail_int)(&zgsz3220);
      CONVERT_OF(sail_int, mach_int)(&zgsz3220, INT64_C(20));
      lbits zgsz3221;
      CREATE(lbits)(&zgsz3221);
      vector_subrange_lbits(&zgsz3221, zgsz3218, zgsz3219, zgsz3220);
      zimm = CONVERT_OF(fbits, lbits)(zgsz3221, true);
      KILL(lbits)(&zgsz3221);
      KILL(sail_int)(&zgsz3220);
      KILL(sail_int)(&zgsz3219);
      KILL(lbits)(&zgsz3218);
    }
    uint64_t zrs1;
    {
      lbits zgsz3222;
      CREATE(lbits)(&zgsz3222);
      CONVERT_OF(lbits, fbits)(&zgsz3222, zv__23, UINT64_C(32) , true);
      sail_int zgsz3223;
      CREATE(sail_int)(&zgsz3223);
      CONVERT_OF(sail_int, mach_int)(&zgsz3223, INT64_C(19));
      sail_int zgsz3224;
      CREATE(sail_int)(&zgsz3224);
      CONVERT_OF(sail_int, mach_int)(&zgsz3224, INT64_C(15));
      lbits zgsz3225;
      CREATE(lbits)(&zgsz3225);
      vector_subrange_lbits(&zgsz3225, zgsz3222, zgsz3223, zgsz3224);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3225, true);
      KILL(lbits)(&zgsz3225);
      KILL(sail_int)(&zgsz3224);
      KILL(sail_int)(&zgsz3223);
      KILL(lbits)(&zgsz3222);
    }
    uint64_t zrd;
    {
      lbits zgsz3226;
      CREATE(lbits)(&zgsz3226);
      CONVERT_OF(lbits, fbits)(&zgsz3226, zv__23, UINT64_C(32) , true);
      sail_int zgsz3227;
      CREATE(sail_int)(&zgsz3227);
      CONVERT_OF(sail_int, mach_int)(&zgsz3227, INT64_C(11));
      sail_int zgsz3228;
      CREATE(sail_int)(&zgsz3228);
      CONVERT_OF(sail_int, mach_int)(&zgsz3228, INT64_C(7));
      lbits zgsz3229;
      CREATE(lbits)(&zgsz3229);
      vector_subrange_lbits(&zgsz3229, zgsz3226, zgsz3227, zgsz3228);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3229, true);
      KILL(lbits)(&zgsz3229);
      KILL(sail_int)(&zgsz3228);
      KILL(sail_int)(&zgsz3227);
      KILL(lbits)(&zgsz3226);
    }
    uint64_t zimmshadowz31;
    {
      lbits zgsz3230;
      CREATE(lbits)(&zgsz3230);
      CONVERT_OF(lbits, fbits)(&zgsz3230, zv__23, UINT64_C(32) , true);
      sail_int zgsz3231;
      CREATE(sail_int)(&zgsz3231);
      CONVERT_OF(sail_int, mach_int)(&zgsz3231, INT64_C(31));
      sail_int zgsz3232;
      CREATE(sail_int)(&zgsz3232);
      CONVERT_OF(sail_int, mach_int)(&zgsz3232, INT64_C(20));
      lbits zgsz3233;
      CREATE(lbits)(&zgsz3233);
      vector_subrange_lbits(&zgsz3233, zgsz3230, zgsz3231, zgsz3232);
      zimmshadowz31 = CONVERT_OF(fbits, lbits)(zgsz3233, true);
      KILL(lbits)(&zgsz3233);
      KILL(sail_int)(&zgsz3232);
      KILL(sail_int)(&zgsz3231);
      KILL(lbits)(&zgsz3230);
    }
    struct zast zgaz330;
    CREATE(zast)(&zgaz330);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3234;
      zgsz3234.ztup0 = zimmshadowz31;
      zgsz3234.ztup1 = zrs1;
      zgsz3234.ztup2 = zrd;
      zgsz3234.ztup3 = zSLTI;
      zITYPE(&zgaz330, zgsz3234);
    
    }
    {
      struct zast zgsz3560;
      CREATE(zast)(&zgsz3560);
      COPY(zast)(&zgsz3560, zgaz330);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3560);
      KILL(zast)(&zgsz3560);
    }
    KILL(zast)(&zgaz330);
  
  
  
  
  
    goto finish_match_1;
  }
case_10: ;
  {
    uint64_t zv__25;
    zv__25 = zmergez3var;
    uint64_t zgaz333;
    {
      lbits zgsz3238;
      CREATE(lbits)(&zgsz3238);
      CONVERT_OF(lbits, fbits)(&zgsz3238, zv__25, UINT64_C(32) , true);
      sail_int zgsz3239;
      CREATE(sail_int)(&zgsz3239);
      CONVERT_OF(sail_int, mach_int)(&zgsz3239, INT64_C(6));
      sail_int zgsz3240;
      CREATE(sail_int)(&zgsz3240);
      CONVERT_OF(sail_int, mach_int)(&zgsz3240, INT64_C(0));
      lbits zgsz3241;
      CREATE(lbits)(&zgsz3241);
      vector_subrange_lbits(&zgsz3241, zgsz3238, zgsz3239, zgsz3240);
      zgaz333 = CONVERT_OF(fbits, lbits)(zgsz3241, true);
      KILL(lbits)(&zgsz3241);
      KILL(sail_int)(&zgsz3240);
      KILL(sail_int)(&zgsz3239);
      KILL(lbits)(&zgsz3238);
    }
    bool zgsz3259;
    {
      lbits zgsz3261;
      CREATE(lbits)(&zgsz3261);
      CONVERT_OF(lbits, fbits)(&zgsz3261, UINT64_C(0b0010011), UINT64_C(7) , true);
      lbits zgsz3260;
      CREATE(lbits)(&zgsz3260);
      CONVERT_OF(lbits, fbits)(&zgsz3260, zgaz333, UINT64_C(7) , true);
      zgsz3259 = eq_bits(zgsz3260, zgsz3261);
      KILL(lbits)(&zgsz3261);
      KILL(lbits)(&zgsz3260);
    }
  
    if (!(zgsz3259)) {
  
    goto case_11;
    }
    uint64_t zimm;
    {
      lbits zgsz3242;
      CREATE(lbits)(&zgsz3242);
      CONVERT_OF(lbits, fbits)(&zgsz3242, zv__25, UINT64_C(32) , true);
      sail_int zgsz3243;
      CREATE(sail_int)(&zgsz3243);
      CONVERT_OF(sail_int, mach_int)(&zgsz3243, INT64_C(31));
      sail_int zgsz3244;
      CREATE(sail_int)(&zgsz3244);
      CONVERT_OF(sail_int, mach_int)(&zgsz3244, INT64_C(20));
      lbits zgsz3245;
      CREATE(lbits)(&zgsz3245);
      vector_subrange_lbits(&zgsz3245, zgsz3242, zgsz3243, zgsz3244);
      zimm = CONVERT_OF(fbits, lbits)(zgsz3245, true);
      KILL(lbits)(&zgsz3245);
      KILL(sail_int)(&zgsz3244);
      KILL(sail_int)(&zgsz3243);
      KILL(lbits)(&zgsz3242);
    }
    uint64_t zrs1;
    {
      lbits zgsz3246;
      CREATE(lbits)(&zgsz3246);
      CONVERT_OF(lbits, fbits)(&zgsz3246, zv__25, UINT64_C(32) , true);
      sail_int zgsz3247;
      CREATE(sail_int)(&zgsz3247);
      CONVERT_OF(sail_int, mach_int)(&zgsz3247, INT64_C(19));
      sail_int zgsz3248;
      CREATE(sail_int)(&zgsz3248);
      CONVERT_OF(sail_int, mach_int)(&zgsz3248, INT64_C(15));
      lbits zgsz3249;
      CREATE(lbits)(&zgsz3249);
      vector_subrange_lbits(&zgsz3249, zgsz3246, zgsz3247, zgsz3248);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3249, true);
      KILL(lbits)(&zgsz3249);
      KILL(sail_int)(&zgsz3248);
      KILL(sail_int)(&zgsz3247);
      KILL(lbits)(&zgsz3246);
    }
    uint64_t zrd;
    {
      lbits zgsz3250;
      CREATE(lbits)(&zgsz3250);
      CONVERT_OF(lbits, fbits)(&zgsz3250, zv__25, UINT64_C(32) , true);
      sail_int zgsz3251;
      CREATE(sail_int)(&zgsz3251);
      CONVERT_OF(sail_int, mach_int)(&zgsz3251, INT64_C(11));
      sail_int zgsz3252;
      CREATE(sail_int)(&zgsz3252);
      CONVERT_OF(sail_int, mach_int)(&zgsz3252, INT64_C(7));
      lbits zgsz3253;
      CREATE(lbits)(&zgsz3253);
      vector_subrange_lbits(&zgsz3253, zgsz3250, zgsz3251, zgsz3252);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3253, true);
      KILL(lbits)(&zgsz3253);
      KILL(sail_int)(&zgsz3252);
      KILL(sail_int)(&zgsz3251);
      KILL(lbits)(&zgsz3250);
    }
    uint64_t zimmshadowz32;
    {
      lbits zgsz3254;
      CREATE(lbits)(&zgsz3254);
      CONVERT_OF(lbits, fbits)(&zgsz3254, zv__25, UINT64_C(32) , true);
      sail_int zgsz3255;
      CREATE(sail_int)(&zgsz3255);
      CONVERT_OF(sail_int, mach_int)(&zgsz3255, INT64_C(31));
      sail_int zgsz3256;
      CREATE(sail_int)(&zgsz3256);
      CONVERT_OF(sail_int, mach_int)(&zgsz3256, INT64_C(20));
      lbits zgsz3257;
      CREATE(lbits)(&zgsz3257);
      vector_subrange_lbits(&zgsz3257, zgsz3254, zgsz3255, zgsz3256);
      zimmshadowz32 = CONVERT_OF(fbits, lbits)(zgsz3257, true);
      KILL(lbits)(&zgsz3257);
      KILL(sail_int)(&zgsz3256);
      KILL(sail_int)(&zgsz3255);
      KILL(lbits)(&zgsz3254);
    }
    struct zast zgaz332;
    CREATE(zast)(&zgaz332);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3258;
      zgsz3258.ztup0 = zimmshadowz32;
      zgsz3258.ztup1 = zrs1;
      zgsz3258.ztup2 = zrd;
      zgsz3258.ztup3 = zANDI;
      zITYPE(&zgaz332, zgsz3258);
    
    }
    {
      struct zast zgsz3561;
      CREATE(zast)(&zgsz3561);
      COPY(zast)(&zgsz3561, zgaz332);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3561);
      KILL(zast)(&zgsz3561);
    }
    KILL(zast)(&zgaz332);
  
  
  
  
  
    goto finish_match_1;
  }
case_11: ;
  {
    uint64_t zv__27;
    zv__27 = zmergez3var;
    uint64_t zgaz335;
    {
      lbits zgsz3262;
      CREATE(lbits)(&zgsz3262);
      CONVERT_OF(lbits, fbits)(&zgsz3262, zv__27, UINT64_C(32) , true);
      sail_int zgsz3263;
      CREATE(sail_int)(&zgsz3263);
      CONVERT_OF(sail_int, mach_int)(&zgsz3263, INT64_C(6));
      sail_int zgsz3264;
      CREATE(sail_int)(&zgsz3264);
      CONVERT_OF(sail_int, mach_int)(&zgsz3264, INT64_C(0));
      lbits zgsz3265;
      CREATE(lbits)(&zgsz3265);
      vector_subrange_lbits(&zgsz3265, zgsz3262, zgsz3263, zgsz3264);
      zgaz335 = CONVERT_OF(fbits, lbits)(zgsz3265, true);
      KILL(lbits)(&zgsz3265);
      KILL(sail_int)(&zgsz3264);
      KILL(sail_int)(&zgsz3263);
      KILL(lbits)(&zgsz3262);
    }
    bool zgsz3283;
    {
      lbits zgsz3285;
      CREATE(lbits)(&zgsz3285);
      CONVERT_OF(lbits, fbits)(&zgsz3285, UINT64_C(0b0010011), UINT64_C(7) , true);
      lbits zgsz3284;
      CREATE(lbits)(&zgsz3284);
      CONVERT_OF(lbits, fbits)(&zgsz3284, zgaz335, UINT64_C(7) , true);
      zgsz3283 = eq_bits(zgsz3284, zgsz3285);
      KILL(lbits)(&zgsz3285);
      KILL(lbits)(&zgsz3284);
    }
  
    if (!(zgsz3283)) {
  
    goto case_12;
    }
    uint64_t zimm;
    {
      lbits zgsz3266;
      CREATE(lbits)(&zgsz3266);
      CONVERT_OF(lbits, fbits)(&zgsz3266, zv__27, UINT64_C(32) , true);
      sail_int zgsz3267;
      CREATE(sail_int)(&zgsz3267);
      CONVERT_OF(sail_int, mach_int)(&zgsz3267, INT64_C(31));
      sail_int zgsz3268;
      CREATE(sail_int)(&zgsz3268);
      CONVERT_OF(sail_int, mach_int)(&zgsz3268, INT64_C(20));
      lbits zgsz3269;
      CREATE(lbits)(&zgsz3269);
      vector_subrange_lbits(&zgsz3269, zgsz3266, zgsz3267, zgsz3268);
      zimm = CONVERT_OF(fbits, lbits)(zgsz3269, true);
      KILL(lbits)(&zgsz3269);
      KILL(sail_int)(&zgsz3268);
      KILL(sail_int)(&zgsz3267);
      KILL(lbits)(&zgsz3266);
    }
    uint64_t zrs1;
    {
      lbits zgsz3270;
      CREATE(lbits)(&zgsz3270);
      CONVERT_OF(lbits, fbits)(&zgsz3270, zv__27, UINT64_C(32) , true);
      sail_int zgsz3271;
      CREATE(sail_int)(&zgsz3271);
      CONVERT_OF(sail_int, mach_int)(&zgsz3271, INT64_C(19));
      sail_int zgsz3272;
      CREATE(sail_int)(&zgsz3272);
      CONVERT_OF(sail_int, mach_int)(&zgsz3272, INT64_C(15));
      lbits zgsz3273;
      CREATE(lbits)(&zgsz3273);
      vector_subrange_lbits(&zgsz3273, zgsz3270, zgsz3271, zgsz3272);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3273, true);
      KILL(lbits)(&zgsz3273);
      KILL(sail_int)(&zgsz3272);
      KILL(sail_int)(&zgsz3271);
      KILL(lbits)(&zgsz3270);
    }
    uint64_t zrd;
    {
      lbits zgsz3274;
      CREATE(lbits)(&zgsz3274);
      CONVERT_OF(lbits, fbits)(&zgsz3274, zv__27, UINT64_C(32) , true);
      sail_int zgsz3275;
      CREATE(sail_int)(&zgsz3275);
      CONVERT_OF(sail_int, mach_int)(&zgsz3275, INT64_C(11));
      sail_int zgsz3276;
      CREATE(sail_int)(&zgsz3276);
      CONVERT_OF(sail_int, mach_int)(&zgsz3276, INT64_C(7));
      lbits zgsz3277;
      CREATE(lbits)(&zgsz3277);
      vector_subrange_lbits(&zgsz3277, zgsz3274, zgsz3275, zgsz3276);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3277, true);
      KILL(lbits)(&zgsz3277);
      KILL(sail_int)(&zgsz3276);
      KILL(sail_int)(&zgsz3275);
      KILL(lbits)(&zgsz3274);
    }
    uint64_t zimmshadowz33;
    {
      lbits zgsz3278;
      CREATE(lbits)(&zgsz3278);
      CONVERT_OF(lbits, fbits)(&zgsz3278, zv__27, UINT64_C(32) , true);
      sail_int zgsz3279;
      CREATE(sail_int)(&zgsz3279);
      CONVERT_OF(sail_int, mach_int)(&zgsz3279, INT64_C(31));
      sail_int zgsz3280;
      CREATE(sail_int)(&zgsz3280);
      CONVERT_OF(sail_int, mach_int)(&zgsz3280, INT64_C(20));
      lbits zgsz3281;
      CREATE(lbits)(&zgsz3281);
      vector_subrange_lbits(&zgsz3281, zgsz3278, zgsz3279, zgsz3280);
      zimmshadowz33 = CONVERT_OF(fbits, lbits)(zgsz3281, true);
      KILL(lbits)(&zgsz3281);
      KILL(sail_int)(&zgsz3280);
      KILL(sail_int)(&zgsz3279);
      KILL(lbits)(&zgsz3278);
    }
    struct zast zgaz334;
    CREATE(zast)(&zgaz334);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3282;
      zgsz3282.ztup0 = zimmshadowz33;
      zgsz3282.ztup1 = zrs1;
      zgsz3282.ztup2 = zrd;
      zgsz3282.ztup3 = zORI;
      zITYPE(&zgaz334, zgsz3282);
    
    }
    {
      struct zast zgsz3562;
      CREATE(zast)(&zgsz3562);
      COPY(zast)(&zgsz3562, zgaz334);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3562);
      KILL(zast)(&zgsz3562);
    }
    KILL(zast)(&zgaz334);
  
  
  
  
  
    goto finish_match_1;
  }
case_12: ;
  {
    uint64_t zv__29;
    zv__29 = zmergez3var;
    uint64_t zgaz337;
    {
      lbits zgsz3286;
      CREATE(lbits)(&zgsz3286);
      CONVERT_OF(lbits, fbits)(&zgsz3286, zv__29, UINT64_C(32) , true);
      sail_int zgsz3287;
      CREATE(sail_int)(&zgsz3287);
      CONVERT_OF(sail_int, mach_int)(&zgsz3287, INT64_C(6));
      sail_int zgsz3288;
      CREATE(sail_int)(&zgsz3288);
      CONVERT_OF(sail_int, mach_int)(&zgsz3288, INT64_C(0));
      lbits zgsz3289;
      CREATE(lbits)(&zgsz3289);
      vector_subrange_lbits(&zgsz3289, zgsz3286, zgsz3287, zgsz3288);
      zgaz337 = CONVERT_OF(fbits, lbits)(zgsz3289, true);
      KILL(lbits)(&zgsz3289);
      KILL(sail_int)(&zgsz3288);
      KILL(sail_int)(&zgsz3287);
      KILL(lbits)(&zgsz3286);
    }
    bool zgsz3307;
    {
      lbits zgsz3309;
      CREATE(lbits)(&zgsz3309);
      CONVERT_OF(lbits, fbits)(&zgsz3309, UINT64_C(0b0010011), UINT64_C(7) , true);
      lbits zgsz3308;
      CREATE(lbits)(&zgsz3308);
      CONVERT_OF(lbits, fbits)(&zgsz3308, zgaz337, UINT64_C(7) , true);
      zgsz3307 = eq_bits(zgsz3308, zgsz3309);
      KILL(lbits)(&zgsz3309);
      KILL(lbits)(&zgsz3308);
    }
  
    if (!(zgsz3307)) {
  
    goto case_13;
    }
    uint64_t zimm;
    {
      lbits zgsz3290;
      CREATE(lbits)(&zgsz3290);
      CONVERT_OF(lbits, fbits)(&zgsz3290, zv__29, UINT64_C(32) , true);
      sail_int zgsz3291;
      CREATE(sail_int)(&zgsz3291);
      CONVERT_OF(sail_int, mach_int)(&zgsz3291, INT64_C(31));
      sail_int zgsz3292;
      CREATE(sail_int)(&zgsz3292);
      CONVERT_OF(sail_int, mach_int)(&zgsz3292, INT64_C(20));
      lbits zgsz3293;
      CREATE(lbits)(&zgsz3293);
      vector_subrange_lbits(&zgsz3293, zgsz3290, zgsz3291, zgsz3292);
      zimm = CONVERT_OF(fbits, lbits)(zgsz3293, true);
      KILL(lbits)(&zgsz3293);
      KILL(sail_int)(&zgsz3292);
      KILL(sail_int)(&zgsz3291);
      KILL(lbits)(&zgsz3290);
    }
    uint64_t zrs1;
    {
      lbits zgsz3294;
      CREATE(lbits)(&zgsz3294);
      CONVERT_OF(lbits, fbits)(&zgsz3294, zv__29, UINT64_C(32) , true);
      sail_int zgsz3295;
      CREATE(sail_int)(&zgsz3295);
      CONVERT_OF(sail_int, mach_int)(&zgsz3295, INT64_C(19));
      sail_int zgsz3296;
      CREATE(sail_int)(&zgsz3296);
      CONVERT_OF(sail_int, mach_int)(&zgsz3296, INT64_C(15));
      lbits zgsz3297;
      CREATE(lbits)(&zgsz3297);
      vector_subrange_lbits(&zgsz3297, zgsz3294, zgsz3295, zgsz3296);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3297, true);
      KILL(lbits)(&zgsz3297);
      KILL(sail_int)(&zgsz3296);
      KILL(sail_int)(&zgsz3295);
      KILL(lbits)(&zgsz3294);
    }
    uint64_t zrd;
    {
      lbits zgsz3298;
      CREATE(lbits)(&zgsz3298);
      CONVERT_OF(lbits, fbits)(&zgsz3298, zv__29, UINT64_C(32) , true);
      sail_int zgsz3299;
      CREATE(sail_int)(&zgsz3299);
      CONVERT_OF(sail_int, mach_int)(&zgsz3299, INT64_C(11));
      sail_int zgsz3300;
      CREATE(sail_int)(&zgsz3300);
      CONVERT_OF(sail_int, mach_int)(&zgsz3300, INT64_C(7));
      lbits zgsz3301;
      CREATE(lbits)(&zgsz3301);
      vector_subrange_lbits(&zgsz3301, zgsz3298, zgsz3299, zgsz3300);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3301, true);
      KILL(lbits)(&zgsz3301);
      KILL(sail_int)(&zgsz3300);
      KILL(sail_int)(&zgsz3299);
      KILL(lbits)(&zgsz3298);
    }
    uint64_t zimmshadowz34;
    {
      lbits zgsz3302;
      CREATE(lbits)(&zgsz3302);
      CONVERT_OF(lbits, fbits)(&zgsz3302, zv__29, UINT64_C(32) , true);
      sail_int zgsz3303;
      CREATE(sail_int)(&zgsz3303);
      CONVERT_OF(sail_int, mach_int)(&zgsz3303, INT64_C(31));
      sail_int zgsz3304;
      CREATE(sail_int)(&zgsz3304);
      CONVERT_OF(sail_int, mach_int)(&zgsz3304, INT64_C(20));
      lbits zgsz3305;
      CREATE(lbits)(&zgsz3305);
      vector_subrange_lbits(&zgsz3305, zgsz3302, zgsz3303, zgsz3304);
      zimmshadowz34 = CONVERT_OF(fbits, lbits)(zgsz3305, true);
      KILL(lbits)(&zgsz3305);
      KILL(sail_int)(&zgsz3304);
      KILL(sail_int)(&zgsz3303);
      KILL(lbits)(&zgsz3302);
    }
    struct zast zgaz336;
    CREATE(zast)(&zgaz336);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3306;
      zgsz3306.ztup0 = zimmshadowz34;
      zgsz3306.ztup1 = zrs1;
      zgsz3306.ztup2 = zrd;
      zgsz3306.ztup3 = zXORI;
      zITYPE(&zgaz336, zgsz3306);
    
    }
    {
      struct zast zgsz3563;
      CREATE(zast)(&zgsz3563);
      COPY(zast)(&zgsz3563, zgaz336);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3563);
      KILL(zast)(&zgsz3563);
    }
    KILL(zast)(&zgaz336);
  
  
  
  
  
    goto finish_match_1;
  }
case_13: ;
  {
    uint64_t zv__31;
    zv__31 = zmergez3var;
    uint64_t zgaz339;
    {
      lbits zgsz3310;
      CREATE(lbits)(&zgsz3310);
      CONVERT_OF(lbits, fbits)(&zgsz3310, zv__31, UINT64_C(32) , true);
      sail_int zgsz3311;
      CREATE(sail_int)(&zgsz3311);
      CONVERT_OF(sail_int, mach_int)(&zgsz3311, INT64_C(6));
      sail_int zgsz3312;
      CREATE(sail_int)(&zgsz3312);
      CONVERT_OF(sail_int, mach_int)(&zgsz3312, INT64_C(0));
      lbits zgsz3313;
      CREATE(lbits)(&zgsz3313);
      vector_subrange_lbits(&zgsz3313, zgsz3310, zgsz3311, zgsz3312);
      zgaz339 = CONVERT_OF(fbits, lbits)(zgsz3313, true);
      KILL(lbits)(&zgsz3313);
      KILL(sail_int)(&zgsz3312);
      KILL(sail_int)(&zgsz3311);
      KILL(lbits)(&zgsz3310);
    }
    bool zgsz3331;
    {
      lbits zgsz3333;
      CREATE(lbits)(&zgsz3333);
      CONVERT_OF(lbits, fbits)(&zgsz3333, UINT64_C(0b1100111), UINT64_C(7) , true);
      lbits zgsz3332;
      CREATE(lbits)(&zgsz3332);
      CONVERT_OF(lbits, fbits)(&zgsz3332, zgaz339, UINT64_C(7) , true);
      zgsz3331 = eq_bits(zgsz3332, zgsz3333);
      KILL(lbits)(&zgsz3333);
      KILL(lbits)(&zgsz3332);
    }
  
    if (!(zgsz3331)) {
  
    goto case_14;
    }
    uint64_t zimm;
    {
      lbits zgsz3314;
      CREATE(lbits)(&zgsz3314);
      CONVERT_OF(lbits, fbits)(&zgsz3314, zv__31, UINT64_C(32) , true);
      sail_int zgsz3315;
      CREATE(sail_int)(&zgsz3315);
      CONVERT_OF(sail_int, mach_int)(&zgsz3315, INT64_C(31));
      sail_int zgsz3316;
      CREATE(sail_int)(&zgsz3316);
      CONVERT_OF(sail_int, mach_int)(&zgsz3316, INT64_C(20));
      lbits zgsz3317;
      CREATE(lbits)(&zgsz3317);
      vector_subrange_lbits(&zgsz3317, zgsz3314, zgsz3315, zgsz3316);
      zimm = CONVERT_OF(fbits, lbits)(zgsz3317, true);
      KILL(lbits)(&zgsz3317);
      KILL(sail_int)(&zgsz3316);
      KILL(sail_int)(&zgsz3315);
      KILL(lbits)(&zgsz3314);
    }
    uint64_t zrs1;
    {
      lbits zgsz3318;
      CREATE(lbits)(&zgsz3318);
      CONVERT_OF(lbits, fbits)(&zgsz3318, zv__31, UINT64_C(32) , true);
      sail_int zgsz3319;
      CREATE(sail_int)(&zgsz3319);
      CONVERT_OF(sail_int, mach_int)(&zgsz3319, INT64_C(19));
      sail_int zgsz3320;
      CREATE(sail_int)(&zgsz3320);
      CONVERT_OF(sail_int, mach_int)(&zgsz3320, INT64_C(15));
      lbits zgsz3321;
      CREATE(lbits)(&zgsz3321);
      vector_subrange_lbits(&zgsz3321, zgsz3318, zgsz3319, zgsz3320);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3321, true);
      KILL(lbits)(&zgsz3321);
      KILL(sail_int)(&zgsz3320);
      KILL(sail_int)(&zgsz3319);
      KILL(lbits)(&zgsz3318);
    }
    uint64_t zrd;
    {
      lbits zgsz3322;
      CREATE(lbits)(&zgsz3322);
      CONVERT_OF(lbits, fbits)(&zgsz3322, zv__31, UINT64_C(32) , true);
      sail_int zgsz3323;
      CREATE(sail_int)(&zgsz3323);
      CONVERT_OF(sail_int, mach_int)(&zgsz3323, INT64_C(11));
      sail_int zgsz3324;
      CREATE(sail_int)(&zgsz3324);
      CONVERT_OF(sail_int, mach_int)(&zgsz3324, INT64_C(7));
      lbits zgsz3325;
      CREATE(lbits)(&zgsz3325);
      vector_subrange_lbits(&zgsz3325, zgsz3322, zgsz3323, zgsz3324);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3325, true);
      KILL(lbits)(&zgsz3325);
      KILL(sail_int)(&zgsz3324);
      KILL(sail_int)(&zgsz3323);
      KILL(lbits)(&zgsz3322);
    }
    uint64_t zimmshadowz35;
    {
      lbits zgsz3326;
      CREATE(lbits)(&zgsz3326);
      CONVERT_OF(lbits, fbits)(&zgsz3326, zv__31, UINT64_C(32) , true);
      sail_int zgsz3327;
      CREATE(sail_int)(&zgsz3327);
      CONVERT_OF(sail_int, mach_int)(&zgsz3327, INT64_C(31));
      sail_int zgsz3328;
      CREATE(sail_int)(&zgsz3328);
      CONVERT_OF(sail_int, mach_int)(&zgsz3328, INT64_C(20));
      lbits zgsz3329;
      CREATE(lbits)(&zgsz3329);
      vector_subrange_lbits(&zgsz3329, zgsz3326, zgsz3327, zgsz3328);
      zimmshadowz35 = CONVERT_OF(fbits, lbits)(zgsz3329, true);
      KILL(lbits)(&zgsz3329);
      KILL(sail_int)(&zgsz3328);
      KILL(sail_int)(&zgsz3327);
      KILL(lbits)(&zgsz3326);
    }
    struct zast zgaz338;
    CREATE(zast)(&zgaz338);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3330;
      zgsz3330.ztup0 = zimmshadowz35;
      zgsz3330.ztup1 = zrs1;
      zgsz3330.ztup2 = zrd;
      zgsz3330.ztup3 = zJALR;
      zITYPE(&zgaz338, zgsz3330);
    
    }
    {
      struct zast zgsz3564;
      CREATE(zast)(&zgsz3564);
      COPY(zast)(&zgsz3564, zgaz338);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3564);
      KILL(zast)(&zgsz3564);
    }
    KILL(zast)(&zgaz338);
  
  
  
  
  
    goto finish_match_1;
  }
case_14: ;
  {
    uint64_t zv__33;
    zv__33 = zmergez3var;
    uint64_t zgaz341;
    {
      lbits zgsz3334;
      CREATE(lbits)(&zgsz3334);
      CONVERT_OF(lbits, fbits)(&zgsz3334, zv__33, UINT64_C(32) , true);
      sail_int zgsz3335;
      CREATE(sail_int)(&zgsz3335);
      CONVERT_OF(sail_int, mach_int)(&zgsz3335, INT64_C(6));
      sail_int zgsz3336;
      CREATE(sail_int)(&zgsz3336);
      CONVERT_OF(sail_int, mach_int)(&zgsz3336, INT64_C(0));
      lbits zgsz3337;
      CREATE(lbits)(&zgsz3337);
      vector_subrange_lbits(&zgsz3337, zgsz3334, zgsz3335, zgsz3336);
      zgaz341 = CONVERT_OF(fbits, lbits)(zgsz3337, true);
      KILL(lbits)(&zgsz3337);
      KILL(sail_int)(&zgsz3336);
      KILL(sail_int)(&zgsz3335);
      KILL(lbits)(&zgsz3334);
    }
    bool zgsz3355;
    {
      lbits zgsz3357;
      CREATE(lbits)(&zgsz3357);
      CONVERT_OF(lbits, fbits)(&zgsz3357, UINT64_C(0b0000011), UINT64_C(7) , true);
      lbits zgsz3356;
      CREATE(lbits)(&zgsz3356);
      CONVERT_OF(lbits, fbits)(&zgsz3356, zgaz341, UINT64_C(7) , true);
      zgsz3355 = eq_bits(zgsz3356, zgsz3357);
      KILL(lbits)(&zgsz3357);
      KILL(lbits)(&zgsz3356);
    }
  
    if (!(zgsz3355)) {
  
    goto case_15;
    }
    uint64_t zimm;
    {
      lbits zgsz3338;
      CREATE(lbits)(&zgsz3338);
      CONVERT_OF(lbits, fbits)(&zgsz3338, zv__33, UINT64_C(32) , true);
      sail_int zgsz3339;
      CREATE(sail_int)(&zgsz3339);
      CONVERT_OF(sail_int, mach_int)(&zgsz3339, INT64_C(31));
      sail_int zgsz3340;
      CREATE(sail_int)(&zgsz3340);
      CONVERT_OF(sail_int, mach_int)(&zgsz3340, INT64_C(20));
      lbits zgsz3341;
      CREATE(lbits)(&zgsz3341);
      vector_subrange_lbits(&zgsz3341, zgsz3338, zgsz3339, zgsz3340);
      zimm = CONVERT_OF(fbits, lbits)(zgsz3341, true);
      KILL(lbits)(&zgsz3341);
      KILL(sail_int)(&zgsz3340);
      KILL(sail_int)(&zgsz3339);
      KILL(lbits)(&zgsz3338);
    }
    uint64_t zrs1;
    {
      lbits zgsz3342;
      CREATE(lbits)(&zgsz3342);
      CONVERT_OF(lbits, fbits)(&zgsz3342, zv__33, UINT64_C(32) , true);
      sail_int zgsz3343;
      CREATE(sail_int)(&zgsz3343);
      CONVERT_OF(sail_int, mach_int)(&zgsz3343, INT64_C(19));
      sail_int zgsz3344;
      CREATE(sail_int)(&zgsz3344);
      CONVERT_OF(sail_int, mach_int)(&zgsz3344, INT64_C(15));
      lbits zgsz3345;
      CREATE(lbits)(&zgsz3345);
      vector_subrange_lbits(&zgsz3345, zgsz3342, zgsz3343, zgsz3344);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3345, true);
      KILL(lbits)(&zgsz3345);
      KILL(sail_int)(&zgsz3344);
      KILL(sail_int)(&zgsz3343);
      KILL(lbits)(&zgsz3342);
    }
    uint64_t zrd;
    {
      lbits zgsz3346;
      CREATE(lbits)(&zgsz3346);
      CONVERT_OF(lbits, fbits)(&zgsz3346, zv__33, UINT64_C(32) , true);
      sail_int zgsz3347;
      CREATE(sail_int)(&zgsz3347);
      CONVERT_OF(sail_int, mach_int)(&zgsz3347, INT64_C(11));
      sail_int zgsz3348;
      CREATE(sail_int)(&zgsz3348);
      CONVERT_OF(sail_int, mach_int)(&zgsz3348, INT64_C(7));
      lbits zgsz3349;
      CREATE(lbits)(&zgsz3349);
      vector_subrange_lbits(&zgsz3349, zgsz3346, zgsz3347, zgsz3348);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3349, true);
      KILL(lbits)(&zgsz3349);
      KILL(sail_int)(&zgsz3348);
      KILL(sail_int)(&zgsz3347);
      KILL(lbits)(&zgsz3346);
    }
    uint64_t zimmshadowz36;
    {
      lbits zgsz3350;
      CREATE(lbits)(&zgsz3350);
      CONVERT_OF(lbits, fbits)(&zgsz3350, zv__33, UINT64_C(32) , true);
      sail_int zgsz3351;
      CREATE(sail_int)(&zgsz3351);
      CONVERT_OF(sail_int, mach_int)(&zgsz3351, INT64_C(31));
      sail_int zgsz3352;
      CREATE(sail_int)(&zgsz3352);
      CONVERT_OF(sail_int, mach_int)(&zgsz3352, INT64_C(20));
      lbits zgsz3353;
      CREATE(lbits)(&zgsz3353);
      vector_subrange_lbits(&zgsz3353, zgsz3350, zgsz3351, zgsz3352);
      zimmshadowz36 = CONVERT_OF(fbits, lbits)(zgsz3353, true);
      KILL(lbits)(&zgsz3353);
      KILL(sail_int)(&zgsz3352);
      KILL(sail_int)(&zgsz3351);
      KILL(lbits)(&zgsz3350);
    }
    struct zast zgaz340;
    CREATE(zast)(&zgaz340);
    {
      struct ztuple_z8z5bv12zCz0z5bv5zCz0z5bv5zCz0z5enumz0zziopz9 zgsz3354;
      zgsz3354.ztup0 = zimmshadowz36;
      zgsz3354.ztup1 = zrs1;
      zgsz3354.ztup2 = zrd;
      zgsz3354.ztup3 = zLW;
      zITYPE(&zgaz340, zgsz3354);
    
    }
    {
      struct zast zgsz3565;
      CREATE(zast)(&zgsz3565);
      COPY(zast)(&zgsz3565, zgaz340);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3565);
      KILL(zast)(&zgsz3565);
    }
    KILL(zast)(&zgaz340);
  
  
  
  
  
    goto finish_match_1;
  }
case_15: ;
  {
    uint64_t zv__35;
    zv__35 = zmergez3var;
    uint64_t zgaz343;
    {
      lbits zgsz3358;
      CREATE(lbits)(&zgsz3358);
      CONVERT_OF(lbits, fbits)(&zgsz3358, zv__35, UINT64_C(32) , true);
      sail_int zgsz3359;
      CREATE(sail_int)(&zgsz3359);
      CONVERT_OF(sail_int, mach_int)(&zgsz3359, INT64_C(6));
      sail_int zgsz3360;
      CREATE(sail_int)(&zgsz3360);
      CONVERT_OF(sail_int, mach_int)(&zgsz3360, INT64_C(0));
      lbits zgsz3361;
      CREATE(lbits)(&zgsz3361);
      vector_subrange_lbits(&zgsz3361, zgsz3358, zgsz3359, zgsz3360);
      zgaz343 = CONVERT_OF(fbits, lbits)(zgsz3361, true);
      KILL(lbits)(&zgsz3361);
      KILL(sail_int)(&zgsz3360);
      KILL(sail_int)(&zgsz3359);
      KILL(lbits)(&zgsz3358);
    }
    bool zgsz3383;
    {
      lbits zgsz3385;
      CREATE(lbits)(&zgsz3385);
      CONVERT_OF(lbits, fbits)(&zgsz3385, UINT64_C(0b0100011), UINT64_C(7) , true);
      lbits zgsz3384;
      CREATE(lbits)(&zgsz3384);
      CONVERT_OF(lbits, fbits)(&zgsz3384, zgaz343, UINT64_C(7) , true);
      zgsz3383 = eq_bits(zgsz3384, zgsz3385);
      KILL(lbits)(&zgsz3385);
      KILL(lbits)(&zgsz3384);
    }
  
    if (!(zgsz3383)) {
  
    goto case_16;
    }
    uint64_t zimm2;
    {
      lbits zgsz3362;
      CREATE(lbits)(&zgsz3362);
      CONVERT_OF(lbits, fbits)(&zgsz3362, zv__35, UINT64_C(32) , true);
      sail_int zgsz3363;
      CREATE(sail_int)(&zgsz3363);
      CONVERT_OF(sail_int, mach_int)(&zgsz3363, INT64_C(31));
      sail_int zgsz3364;
      CREATE(sail_int)(&zgsz3364);
      CONVERT_OF(sail_int, mach_int)(&zgsz3364, INT64_C(25));
      lbits zgsz3365;
      CREATE(lbits)(&zgsz3365);
      vector_subrange_lbits(&zgsz3365, zgsz3362, zgsz3363, zgsz3364);
      zimm2 = CONVERT_OF(fbits, lbits)(zgsz3365, true);
      KILL(lbits)(&zgsz3365);
      KILL(sail_int)(&zgsz3364);
      KILL(sail_int)(&zgsz3363);
      KILL(lbits)(&zgsz3362);
    }
    uint64_t zrs2;
    {
      lbits zgsz3366;
      CREATE(lbits)(&zgsz3366);
      CONVERT_OF(lbits, fbits)(&zgsz3366, zv__35, UINT64_C(32) , true);
      sail_int zgsz3367;
      CREATE(sail_int)(&zgsz3367);
      CONVERT_OF(sail_int, mach_int)(&zgsz3367, INT64_C(24));
      sail_int zgsz3368;
      CREATE(sail_int)(&zgsz3368);
      CONVERT_OF(sail_int, mach_int)(&zgsz3368, INT64_C(20));
      lbits zgsz3369;
      CREATE(lbits)(&zgsz3369);
      vector_subrange_lbits(&zgsz3369, zgsz3366, zgsz3367, zgsz3368);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz3369, true);
      KILL(lbits)(&zgsz3369);
      KILL(sail_int)(&zgsz3368);
      KILL(sail_int)(&zgsz3367);
      KILL(lbits)(&zgsz3366);
    }
    uint64_t zrs1;
    {
      lbits zgsz3370;
      CREATE(lbits)(&zgsz3370);
      CONVERT_OF(lbits, fbits)(&zgsz3370, zv__35, UINT64_C(32) , true);
      sail_int zgsz3371;
      CREATE(sail_int)(&zgsz3371);
      CONVERT_OF(sail_int, mach_int)(&zgsz3371, INT64_C(19));
      sail_int zgsz3372;
      CREATE(sail_int)(&zgsz3372);
      CONVERT_OF(sail_int, mach_int)(&zgsz3372, INT64_C(15));
      lbits zgsz3373;
      CREATE(lbits)(&zgsz3373);
      vector_subrange_lbits(&zgsz3373, zgsz3370, zgsz3371, zgsz3372);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3373, true);
      KILL(lbits)(&zgsz3373);
      KILL(sail_int)(&zgsz3372);
      KILL(sail_int)(&zgsz3371);
      KILL(lbits)(&zgsz3370);
    }
    uint64_t zimm2shadowz37;
    {
      lbits zgsz3374;
      CREATE(lbits)(&zgsz3374);
      CONVERT_OF(lbits, fbits)(&zgsz3374, zv__35, UINT64_C(32) , true);
      sail_int zgsz3375;
      CREATE(sail_int)(&zgsz3375);
      CONVERT_OF(sail_int, mach_int)(&zgsz3375, INT64_C(31));
      sail_int zgsz3376;
      CREATE(sail_int)(&zgsz3376);
      CONVERT_OF(sail_int, mach_int)(&zgsz3376, INT64_C(25));
      lbits zgsz3377;
      CREATE(lbits)(&zgsz3377);
      vector_subrange_lbits(&zgsz3377, zgsz3374, zgsz3375, zgsz3376);
      zimm2shadowz37 = CONVERT_OF(fbits, lbits)(zgsz3377, true);
      KILL(lbits)(&zgsz3377);
      KILL(sail_int)(&zgsz3376);
      KILL(sail_int)(&zgsz3375);
      KILL(lbits)(&zgsz3374);
    }
    uint64_t zimm1;
    {
      lbits zgsz3378;
      CREATE(lbits)(&zgsz3378);
      CONVERT_OF(lbits, fbits)(&zgsz3378, zv__35, UINT64_C(32) , true);
      sail_int zgsz3379;
      CREATE(sail_int)(&zgsz3379);
      CONVERT_OF(sail_int, mach_int)(&zgsz3379, INT64_C(11));
      sail_int zgsz3380;
      CREATE(sail_int)(&zgsz3380);
      CONVERT_OF(sail_int, mach_int)(&zgsz3380, INT64_C(7));
      lbits zgsz3381;
      CREATE(lbits)(&zgsz3381);
      vector_subrange_lbits(&zgsz3381, zgsz3378, zgsz3379, zgsz3380);
      zimm1 = CONVERT_OF(fbits, lbits)(zgsz3381, true);
      KILL(lbits)(&zgsz3381);
      KILL(sail_int)(&zgsz3380);
      KILL(sail_int)(&zgsz3379);
      KILL(lbits)(&zgsz3378);
    }
    struct zast zgaz342;
    CREATE(zast)(&zgaz342);
    {
      struct ztuple_z8z5bv7zCz0z5bv5zCz0z5bv5zCz0z5bv5zCz0z5enumz0zzsopz9 zgsz3382;
      zgsz3382.ztup0 = zimm2shadowz37;
      zgsz3382.ztup1 = zrs2;
      zgsz3382.ztup2 = zrs1;
      zgsz3382.ztup3 = zimm1;
      zgsz3382.ztup4 = zSW;
      zSTYPE(&zgaz342, zgsz3382);
    
    }
    {
      struct zast zgsz3566;
      CREATE(zast)(&zgsz3566);
      COPY(zast)(&zgsz3566, zgaz342);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3566);
      KILL(zast)(&zgsz3566);
    }
    KILL(zast)(&zgaz342);
  
  
  
  
  
  
    goto finish_match_1;
  }
case_16: ;
  {
    uint64_t zv__37;
    zv__37 = zmergez3var;
    uint64_t zgaz345;
    {
      lbits zgsz3386;
      CREATE(lbits)(&zgsz3386);
      CONVERT_OF(lbits, fbits)(&zgsz3386, zv__37, UINT64_C(32) , true);
      sail_int zgsz3387;
      CREATE(sail_int)(&zgsz3387);
      CONVERT_OF(sail_int, mach_int)(&zgsz3387, INT64_C(6));
      sail_int zgsz3388;
      CREATE(sail_int)(&zgsz3388);
      CONVERT_OF(sail_int, mach_int)(&zgsz3388, INT64_C(0));
      lbits zgsz3389;
      CREATE(lbits)(&zgsz3389);
      vector_subrange_lbits(&zgsz3389, zgsz3386, zgsz3387, zgsz3388);
      zgaz345 = CONVERT_OF(fbits, lbits)(zgsz3389, true);
      KILL(lbits)(&zgsz3389);
      KILL(sail_int)(&zgsz3388);
      KILL(sail_int)(&zgsz3387);
      KILL(lbits)(&zgsz3386);
    }
    bool zgsz3419;
    {
      lbits zgsz3421;
      CREATE(lbits)(&zgsz3421);
      CONVERT_OF(lbits, fbits)(&zgsz3421, UINT64_C(0b1100011), UINT64_C(7) , true);
      lbits zgsz3420;
      CREATE(lbits)(&zgsz3420);
      CONVERT_OF(lbits, fbits)(&zgsz3420, zgaz345, UINT64_C(7) , true);
      zgsz3419 = eq_bits(zgsz3420, zgsz3421);
      KILL(lbits)(&zgsz3421);
      KILL(lbits)(&zgsz3420);
    }
  
    if (!(zgsz3419)) {
  
    goto case_17;
    }
    uint64_t zimm4;
    {
      lbits zgsz3390;
      CREATE(lbits)(&zgsz3390);
      CONVERT_OF(lbits, fbits)(&zgsz3390, zv__37, UINT64_C(32) , true);
      sail_int zgsz3391;
      CREATE(sail_int)(&zgsz3391);
      CONVERT_OF(sail_int, mach_int)(&zgsz3391, INT64_C(31));
      sail_int zgsz3392;
      CREATE(sail_int)(&zgsz3392);
      CONVERT_OF(sail_int, mach_int)(&zgsz3392, INT64_C(31));
      lbits zgsz3393;
      CREATE(lbits)(&zgsz3393);
      vector_subrange_lbits(&zgsz3393, zgsz3390, zgsz3391, zgsz3392);
      zimm4 = CONVERT_OF(fbits, lbits)(zgsz3393, true);
      KILL(lbits)(&zgsz3393);
      KILL(sail_int)(&zgsz3392);
      KILL(sail_int)(&zgsz3391);
      KILL(lbits)(&zgsz3390);
    }
    uint64_t zrs2;
    {
      lbits zgsz3394;
      CREATE(lbits)(&zgsz3394);
      CONVERT_OF(lbits, fbits)(&zgsz3394, zv__37, UINT64_C(32) , true);
      sail_int zgsz3395;
      CREATE(sail_int)(&zgsz3395);
      CONVERT_OF(sail_int, mach_int)(&zgsz3395, INT64_C(24));
      sail_int zgsz3396;
      CREATE(sail_int)(&zgsz3396);
      CONVERT_OF(sail_int, mach_int)(&zgsz3396, INT64_C(20));
      lbits zgsz3397;
      CREATE(lbits)(&zgsz3397);
      vector_subrange_lbits(&zgsz3397, zgsz3394, zgsz3395, zgsz3396);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz3397, true);
      KILL(lbits)(&zgsz3397);
      KILL(sail_int)(&zgsz3396);
      KILL(sail_int)(&zgsz3395);
      KILL(lbits)(&zgsz3394);
    }
    uint64_t zrs1;
    {
      lbits zgsz3398;
      CREATE(lbits)(&zgsz3398);
      CONVERT_OF(lbits, fbits)(&zgsz3398, zv__37, UINT64_C(32) , true);
      sail_int zgsz3399;
      CREATE(sail_int)(&zgsz3399);
      CONVERT_OF(sail_int, mach_int)(&zgsz3399, INT64_C(19));
      sail_int zgsz3400;
      CREATE(sail_int)(&zgsz3400);
      CONVERT_OF(sail_int, mach_int)(&zgsz3400, INT64_C(15));
      lbits zgsz3401;
      CREATE(lbits)(&zgsz3401);
      vector_subrange_lbits(&zgsz3401, zgsz3398, zgsz3399, zgsz3400);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3401, true);
      KILL(lbits)(&zgsz3401);
      KILL(sail_int)(&zgsz3400);
      KILL(sail_int)(&zgsz3399);
      KILL(lbits)(&zgsz3398);
    }
    uint64_t zimm4shadowz38;
    {
      lbits zgsz3402;
      CREATE(lbits)(&zgsz3402);
      CONVERT_OF(lbits, fbits)(&zgsz3402, zv__37, UINT64_C(32) , true);
      sail_int zgsz3403;
      CREATE(sail_int)(&zgsz3403);
      CONVERT_OF(sail_int, mach_int)(&zgsz3403, INT64_C(31));
      sail_int zgsz3404;
      CREATE(sail_int)(&zgsz3404);
      CONVERT_OF(sail_int, mach_int)(&zgsz3404, INT64_C(31));
      lbits zgsz3405;
      CREATE(lbits)(&zgsz3405);
      vector_subrange_lbits(&zgsz3405, zgsz3402, zgsz3403, zgsz3404);
      zimm4shadowz38 = CONVERT_OF(fbits, lbits)(zgsz3405, true);
      KILL(lbits)(&zgsz3405);
      KILL(sail_int)(&zgsz3404);
      KILL(sail_int)(&zgsz3403);
      KILL(lbits)(&zgsz3402);
    }
    uint64_t zimm3;
    {
      lbits zgsz3406;
      CREATE(lbits)(&zgsz3406);
      CONVERT_OF(lbits, fbits)(&zgsz3406, zv__37, UINT64_C(32) , true);
      sail_int zgsz3407;
      CREATE(sail_int)(&zgsz3407);
      CONVERT_OF(sail_int, mach_int)(&zgsz3407, INT64_C(7));
      sail_int zgsz3408;
      CREATE(sail_int)(&zgsz3408);
      CONVERT_OF(sail_int, mach_int)(&zgsz3408, INT64_C(7));
      lbits zgsz3409;
      CREATE(lbits)(&zgsz3409);
      vector_subrange_lbits(&zgsz3409, zgsz3406, zgsz3407, zgsz3408);
      zimm3 = CONVERT_OF(fbits, lbits)(zgsz3409, true);
      KILL(lbits)(&zgsz3409);
      KILL(sail_int)(&zgsz3408);
      KILL(sail_int)(&zgsz3407);
      KILL(lbits)(&zgsz3406);
    }
    uint64_t zimm2;
    {
      lbits zgsz3410;
      CREATE(lbits)(&zgsz3410);
      CONVERT_OF(lbits, fbits)(&zgsz3410, zv__37, UINT64_C(32) , true);
      sail_int zgsz3411;
      CREATE(sail_int)(&zgsz3411);
      CONVERT_OF(sail_int, mach_int)(&zgsz3411, INT64_C(30));
      sail_int zgsz3412;
      CREATE(sail_int)(&zgsz3412);
      CONVERT_OF(sail_int, mach_int)(&zgsz3412, INT64_C(25));
      lbits zgsz3413;
      CREATE(lbits)(&zgsz3413);
      vector_subrange_lbits(&zgsz3413, zgsz3410, zgsz3411, zgsz3412);
      zimm2 = CONVERT_OF(fbits, lbits)(zgsz3413, true);
      KILL(lbits)(&zgsz3413);
      KILL(sail_int)(&zgsz3412);
      KILL(sail_int)(&zgsz3411);
      KILL(lbits)(&zgsz3410);
    }
    uint64_t zimm1;
    {
      lbits zgsz3414;
      CREATE(lbits)(&zgsz3414);
      CONVERT_OF(lbits, fbits)(&zgsz3414, zv__37, UINT64_C(32) , true);
      sail_int zgsz3415;
      CREATE(sail_int)(&zgsz3415);
      CONVERT_OF(sail_int, mach_int)(&zgsz3415, INT64_C(11));
      sail_int zgsz3416;
      CREATE(sail_int)(&zgsz3416);
      CONVERT_OF(sail_int, mach_int)(&zgsz3416, INT64_C(8));
      lbits zgsz3417;
      CREATE(lbits)(&zgsz3417);
      vector_subrange_lbits(&zgsz3417, zgsz3414, zgsz3415, zgsz3416);
      zimm1 = CONVERT_OF(fbits, lbits)(zgsz3417, true);
      KILL(lbits)(&zgsz3417);
      KILL(sail_int)(&zgsz3416);
      KILL(sail_int)(&zgsz3415);
      KILL(lbits)(&zgsz3414);
    }
    struct zast zgaz344;
    CREATE(zast)(&zgaz344);
    {
      struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 zgsz3418;
      zgsz3418.ztup0 = zimm4shadowz38;
      zgsz3418.ztup1 = zimm2;
      zgsz3418.ztup2 = zrs2;
      zgsz3418.ztup3 = zrs1;
      zgsz3418.ztup4 = zimm1;
      zgsz3418.ztup5 = zimm3;
      zgsz3418.ztup6 = zBEQ;
      zBTYPE(&zgaz344, zgsz3418);
    
    }
    {
      struct zast zgsz3567;
      CREATE(zast)(&zgsz3567);
      COPY(zast)(&zgsz3567, zgaz344);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3567);
      KILL(zast)(&zgsz3567);
    }
    KILL(zast)(&zgaz344);
  
  
  
  
  
  
  
  
    goto finish_match_1;
  }
case_17: ;
  {
    uint64_t zv__39;
    zv__39 = zmergez3var;
    uint64_t zgaz347;
    {
      lbits zgsz3422;
      CREATE(lbits)(&zgsz3422);
      CONVERT_OF(lbits, fbits)(&zgsz3422, zv__39, UINT64_C(32) , true);
      sail_int zgsz3423;
      CREATE(sail_int)(&zgsz3423);
      CONVERT_OF(sail_int, mach_int)(&zgsz3423, INT64_C(6));
      sail_int zgsz3424;
      CREATE(sail_int)(&zgsz3424);
      CONVERT_OF(sail_int, mach_int)(&zgsz3424, INT64_C(0));
      lbits zgsz3425;
      CREATE(lbits)(&zgsz3425);
      vector_subrange_lbits(&zgsz3425, zgsz3422, zgsz3423, zgsz3424);
      zgaz347 = CONVERT_OF(fbits, lbits)(zgsz3425, true);
      KILL(lbits)(&zgsz3425);
      KILL(sail_int)(&zgsz3424);
      KILL(sail_int)(&zgsz3423);
      KILL(lbits)(&zgsz3422);
    }
    bool zgsz3455;
    {
      lbits zgsz3457;
      CREATE(lbits)(&zgsz3457);
      CONVERT_OF(lbits, fbits)(&zgsz3457, UINT64_C(0b1100011), UINT64_C(7) , true);
      lbits zgsz3456;
      CREATE(lbits)(&zgsz3456);
      CONVERT_OF(lbits, fbits)(&zgsz3456, zgaz347, UINT64_C(7) , true);
      zgsz3455 = eq_bits(zgsz3456, zgsz3457);
      KILL(lbits)(&zgsz3457);
      KILL(lbits)(&zgsz3456);
    }
  
    if (!(zgsz3455)) {
  
    goto case_18;
    }
    uint64_t zimm4;
    {
      lbits zgsz3426;
      CREATE(lbits)(&zgsz3426);
      CONVERT_OF(lbits, fbits)(&zgsz3426, zv__39, UINT64_C(32) , true);
      sail_int zgsz3427;
      CREATE(sail_int)(&zgsz3427);
      CONVERT_OF(sail_int, mach_int)(&zgsz3427, INT64_C(31));
      sail_int zgsz3428;
      CREATE(sail_int)(&zgsz3428);
      CONVERT_OF(sail_int, mach_int)(&zgsz3428, INT64_C(31));
      lbits zgsz3429;
      CREATE(lbits)(&zgsz3429);
      vector_subrange_lbits(&zgsz3429, zgsz3426, zgsz3427, zgsz3428);
      zimm4 = CONVERT_OF(fbits, lbits)(zgsz3429, true);
      KILL(lbits)(&zgsz3429);
      KILL(sail_int)(&zgsz3428);
      KILL(sail_int)(&zgsz3427);
      KILL(lbits)(&zgsz3426);
    }
    uint64_t zrs2;
    {
      lbits zgsz3430;
      CREATE(lbits)(&zgsz3430);
      CONVERT_OF(lbits, fbits)(&zgsz3430, zv__39, UINT64_C(32) , true);
      sail_int zgsz3431;
      CREATE(sail_int)(&zgsz3431);
      CONVERT_OF(sail_int, mach_int)(&zgsz3431, INT64_C(24));
      sail_int zgsz3432;
      CREATE(sail_int)(&zgsz3432);
      CONVERT_OF(sail_int, mach_int)(&zgsz3432, INT64_C(20));
      lbits zgsz3433;
      CREATE(lbits)(&zgsz3433);
      vector_subrange_lbits(&zgsz3433, zgsz3430, zgsz3431, zgsz3432);
      zrs2 = CONVERT_OF(fbits, lbits)(zgsz3433, true);
      KILL(lbits)(&zgsz3433);
      KILL(sail_int)(&zgsz3432);
      KILL(sail_int)(&zgsz3431);
      KILL(lbits)(&zgsz3430);
    }
    uint64_t zrs1;
    {
      lbits zgsz3434;
      CREATE(lbits)(&zgsz3434);
      CONVERT_OF(lbits, fbits)(&zgsz3434, zv__39, UINT64_C(32) , true);
      sail_int zgsz3435;
      CREATE(sail_int)(&zgsz3435);
      CONVERT_OF(sail_int, mach_int)(&zgsz3435, INT64_C(19));
      sail_int zgsz3436;
      CREATE(sail_int)(&zgsz3436);
      CONVERT_OF(sail_int, mach_int)(&zgsz3436, INT64_C(15));
      lbits zgsz3437;
      CREATE(lbits)(&zgsz3437);
      vector_subrange_lbits(&zgsz3437, zgsz3434, zgsz3435, zgsz3436);
      zrs1 = CONVERT_OF(fbits, lbits)(zgsz3437, true);
      KILL(lbits)(&zgsz3437);
      KILL(sail_int)(&zgsz3436);
      KILL(sail_int)(&zgsz3435);
      KILL(lbits)(&zgsz3434);
    }
    uint64_t zimm4shadowz39;
    {
      lbits zgsz3438;
      CREATE(lbits)(&zgsz3438);
      CONVERT_OF(lbits, fbits)(&zgsz3438, zv__39, UINT64_C(32) , true);
      sail_int zgsz3439;
      CREATE(sail_int)(&zgsz3439);
      CONVERT_OF(sail_int, mach_int)(&zgsz3439, INT64_C(31));
      sail_int zgsz3440;
      CREATE(sail_int)(&zgsz3440);
      CONVERT_OF(sail_int, mach_int)(&zgsz3440, INT64_C(31));
      lbits zgsz3441;
      CREATE(lbits)(&zgsz3441);
      vector_subrange_lbits(&zgsz3441, zgsz3438, zgsz3439, zgsz3440);
      zimm4shadowz39 = CONVERT_OF(fbits, lbits)(zgsz3441, true);
      KILL(lbits)(&zgsz3441);
      KILL(sail_int)(&zgsz3440);
      KILL(sail_int)(&zgsz3439);
      KILL(lbits)(&zgsz3438);
    }
    uint64_t zimm3;
    {
      lbits zgsz3442;
      CREATE(lbits)(&zgsz3442);
      CONVERT_OF(lbits, fbits)(&zgsz3442, zv__39, UINT64_C(32) , true);
      sail_int zgsz3443;
      CREATE(sail_int)(&zgsz3443);
      CONVERT_OF(sail_int, mach_int)(&zgsz3443, INT64_C(7));
      sail_int zgsz3444;
      CREATE(sail_int)(&zgsz3444);
      CONVERT_OF(sail_int, mach_int)(&zgsz3444, INT64_C(7));
      lbits zgsz3445;
      CREATE(lbits)(&zgsz3445);
      vector_subrange_lbits(&zgsz3445, zgsz3442, zgsz3443, zgsz3444);
      zimm3 = CONVERT_OF(fbits, lbits)(zgsz3445, true);
      KILL(lbits)(&zgsz3445);
      KILL(sail_int)(&zgsz3444);
      KILL(sail_int)(&zgsz3443);
      KILL(lbits)(&zgsz3442);
    }
    uint64_t zimm2;
    {
      lbits zgsz3446;
      CREATE(lbits)(&zgsz3446);
      CONVERT_OF(lbits, fbits)(&zgsz3446, zv__39, UINT64_C(32) , true);
      sail_int zgsz3447;
      CREATE(sail_int)(&zgsz3447);
      CONVERT_OF(sail_int, mach_int)(&zgsz3447, INT64_C(30));
      sail_int zgsz3448;
      CREATE(sail_int)(&zgsz3448);
      CONVERT_OF(sail_int, mach_int)(&zgsz3448, INT64_C(25));
      lbits zgsz3449;
      CREATE(lbits)(&zgsz3449);
      vector_subrange_lbits(&zgsz3449, zgsz3446, zgsz3447, zgsz3448);
      zimm2 = CONVERT_OF(fbits, lbits)(zgsz3449, true);
      KILL(lbits)(&zgsz3449);
      KILL(sail_int)(&zgsz3448);
      KILL(sail_int)(&zgsz3447);
      KILL(lbits)(&zgsz3446);
    }
    uint64_t zimm1;
    {
      lbits zgsz3450;
      CREATE(lbits)(&zgsz3450);
      CONVERT_OF(lbits, fbits)(&zgsz3450, zv__39, UINT64_C(32) , true);
      sail_int zgsz3451;
      CREATE(sail_int)(&zgsz3451);
      CONVERT_OF(sail_int, mach_int)(&zgsz3451, INT64_C(11));
      sail_int zgsz3452;
      CREATE(sail_int)(&zgsz3452);
      CONVERT_OF(sail_int, mach_int)(&zgsz3452, INT64_C(8));
      lbits zgsz3453;
      CREATE(lbits)(&zgsz3453);
      vector_subrange_lbits(&zgsz3453, zgsz3450, zgsz3451, zgsz3452);
      zimm1 = CONVERT_OF(fbits, lbits)(zgsz3453, true);
      KILL(lbits)(&zgsz3453);
      KILL(sail_int)(&zgsz3452);
      KILL(sail_int)(&zgsz3451);
      KILL(lbits)(&zgsz3450);
    }
    struct zast zgaz346;
    CREATE(zast)(&zgaz346);
    {
      struct ztuple_z8z5bv1zCz0z5bv6zCz0z5bv5zCz0z5bv5zCz0z5bv4zCz0z5bv1zCz0z5enumz0zzbopz9 zgsz3454;
      zgsz3454.ztup0 = zimm4shadowz39;
      zgsz3454.ztup1 = zimm2;
      zgsz3454.ztup2 = zrs2;
      zgsz3454.ztup3 = zrs1;
      zgsz3454.ztup4 = zimm1;
      zgsz3454.ztup5 = zimm3;
      zgsz3454.ztup6 = zBNE;
      zBTYPE(&zgaz346, zgsz3454);
    
    }
    {
      struct zast zgsz3568;
      CREATE(zast)(&zgsz3568);
      COPY(zast)(&zgsz3568, zgaz346);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3568);
      KILL(zast)(&zgsz3568);
    }
    KILL(zast)(&zgaz346);
  
  
  
  
  
  
  
  
    goto finish_match_1;
  }
case_18: ;
  {
    uint64_t zv__41;
    zv__41 = zmergez3var;
    uint64_t zgaz349;
    {
      lbits zgsz3458;
      CREATE(lbits)(&zgsz3458);
      CONVERT_OF(lbits, fbits)(&zgsz3458, zv__41, UINT64_C(32) , true);
      sail_int zgsz3459;
      CREATE(sail_int)(&zgsz3459);
      CONVERT_OF(sail_int, mach_int)(&zgsz3459, INT64_C(6));
      sail_int zgsz3460;
      CREATE(sail_int)(&zgsz3460);
      CONVERT_OF(sail_int, mach_int)(&zgsz3460, INT64_C(0));
      lbits zgsz3461;
      CREATE(lbits)(&zgsz3461);
      vector_subrange_lbits(&zgsz3461, zgsz3458, zgsz3459, zgsz3460);
      zgaz349 = CONVERT_OF(fbits, lbits)(zgsz3461, true);
      KILL(lbits)(&zgsz3461);
      KILL(sail_int)(&zgsz3460);
      KILL(sail_int)(&zgsz3459);
      KILL(lbits)(&zgsz3458);
    }
    bool zgsz3475;
    {
      lbits zgsz3477;
      CREATE(lbits)(&zgsz3477);
      CONVERT_OF(lbits, fbits)(&zgsz3477, UINT64_C(0b0110111), UINT64_C(7) , true);
      lbits zgsz3476;
      CREATE(lbits)(&zgsz3476);
      CONVERT_OF(lbits, fbits)(&zgsz3476, zgaz349, UINT64_C(7) , true);
      zgsz3475 = eq_bits(zgsz3476, zgsz3477);
      KILL(lbits)(&zgsz3477);
      KILL(lbits)(&zgsz3476);
    }
  
    if (!(zgsz3475)) {
  
    goto case_19;
    }
    uint64_t zimm;
    {
      lbits zgsz3462;
      CREATE(lbits)(&zgsz3462);
      CONVERT_OF(lbits, fbits)(&zgsz3462, zv__41, UINT64_C(32) , true);
      sail_int zgsz3463;
      CREATE(sail_int)(&zgsz3463);
      CONVERT_OF(sail_int, mach_int)(&zgsz3463, INT64_C(31));
      sail_int zgsz3464;
      CREATE(sail_int)(&zgsz3464);
      CONVERT_OF(sail_int, mach_int)(&zgsz3464, INT64_C(12));
      lbits zgsz3465;
      CREATE(lbits)(&zgsz3465);
      vector_subrange_lbits(&zgsz3465, zgsz3462, zgsz3463, zgsz3464);
      zimm = CONVERT_OF(fbits, lbits)(zgsz3465, true);
      KILL(lbits)(&zgsz3465);
      KILL(sail_int)(&zgsz3464);
      KILL(sail_int)(&zgsz3463);
      KILL(lbits)(&zgsz3462);
    }
    uint64_t zrd;
    {
      lbits zgsz3466;
      CREATE(lbits)(&zgsz3466);
      CONVERT_OF(lbits, fbits)(&zgsz3466, zv__41, UINT64_C(32) , true);
      sail_int zgsz3467;
      CREATE(sail_int)(&zgsz3467);
      CONVERT_OF(sail_int, mach_int)(&zgsz3467, INT64_C(11));
      sail_int zgsz3468;
      CREATE(sail_int)(&zgsz3468);
      CONVERT_OF(sail_int, mach_int)(&zgsz3468, INT64_C(7));
      lbits zgsz3469;
      CREATE(lbits)(&zgsz3469);
      vector_subrange_lbits(&zgsz3469, zgsz3466, zgsz3467, zgsz3468);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3469, true);
      KILL(lbits)(&zgsz3469);
      KILL(sail_int)(&zgsz3468);
      KILL(sail_int)(&zgsz3467);
      KILL(lbits)(&zgsz3466);
    }
    uint64_t zimmshadowz310;
    {
      lbits zgsz3470;
      CREATE(lbits)(&zgsz3470);
      CONVERT_OF(lbits, fbits)(&zgsz3470, zv__41, UINT64_C(32) , true);
      sail_int zgsz3471;
      CREATE(sail_int)(&zgsz3471);
      CONVERT_OF(sail_int, mach_int)(&zgsz3471, INT64_C(31));
      sail_int zgsz3472;
      CREATE(sail_int)(&zgsz3472);
      CONVERT_OF(sail_int, mach_int)(&zgsz3472, INT64_C(12));
      lbits zgsz3473;
      CREATE(lbits)(&zgsz3473);
      vector_subrange_lbits(&zgsz3473, zgsz3470, zgsz3471, zgsz3472);
      zimmshadowz310 = CONVERT_OF(fbits, lbits)(zgsz3473, true);
      KILL(lbits)(&zgsz3473);
      KILL(sail_int)(&zgsz3472);
      KILL(sail_int)(&zgsz3471);
      KILL(lbits)(&zgsz3470);
    }
    struct zast zgaz348;
    CREATE(zast)(&zgaz348);
    {
      struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 zgsz3474;
      zgsz3474.ztup0 = zimmshadowz310;
      zgsz3474.ztup1 = zrd;
      zgsz3474.ztup2 = zLUI;
      zUTYPE(&zgaz348, zgsz3474);
    
    }
    {
      struct zast zgsz3569;
      CREATE(zast)(&zgsz3569);
      COPY(zast)(&zgsz3569, zgaz348);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3569);
      KILL(zast)(&zgsz3569);
    }
    KILL(zast)(&zgaz348);
  
  
  
  
    goto finish_match_1;
  }
case_19: ;
  {
    uint64_t zv__43;
    zv__43 = zmergez3var;
    uint64_t zgaz351;
    {
      lbits zgsz3478;
      CREATE(lbits)(&zgsz3478);
      CONVERT_OF(lbits, fbits)(&zgsz3478, zv__43, UINT64_C(32) , true);
      sail_int zgsz3479;
      CREATE(sail_int)(&zgsz3479);
      CONVERT_OF(sail_int, mach_int)(&zgsz3479, INT64_C(6));
      sail_int zgsz3480;
      CREATE(sail_int)(&zgsz3480);
      CONVERT_OF(sail_int, mach_int)(&zgsz3480, INT64_C(0));
      lbits zgsz3481;
      CREATE(lbits)(&zgsz3481);
      vector_subrange_lbits(&zgsz3481, zgsz3478, zgsz3479, zgsz3480);
      zgaz351 = CONVERT_OF(fbits, lbits)(zgsz3481, true);
      KILL(lbits)(&zgsz3481);
      KILL(sail_int)(&zgsz3480);
      KILL(sail_int)(&zgsz3479);
      KILL(lbits)(&zgsz3478);
    }
    bool zgsz3495;
    {
      lbits zgsz3497;
      CREATE(lbits)(&zgsz3497);
      CONVERT_OF(lbits, fbits)(&zgsz3497, UINT64_C(0b0010111), UINT64_C(7) , true);
      lbits zgsz3496;
      CREATE(lbits)(&zgsz3496);
      CONVERT_OF(lbits, fbits)(&zgsz3496, zgaz351, UINT64_C(7) , true);
      zgsz3495 = eq_bits(zgsz3496, zgsz3497);
      KILL(lbits)(&zgsz3497);
      KILL(lbits)(&zgsz3496);
    }
  
    if (!(zgsz3495)) {
  
    goto case_20;
    }
    uint64_t zimm;
    {
      lbits zgsz3482;
      CREATE(lbits)(&zgsz3482);
      CONVERT_OF(lbits, fbits)(&zgsz3482, zv__43, UINT64_C(32) , true);
      sail_int zgsz3483;
      CREATE(sail_int)(&zgsz3483);
      CONVERT_OF(sail_int, mach_int)(&zgsz3483, INT64_C(31));
      sail_int zgsz3484;
      CREATE(sail_int)(&zgsz3484);
      CONVERT_OF(sail_int, mach_int)(&zgsz3484, INT64_C(12));
      lbits zgsz3485;
      CREATE(lbits)(&zgsz3485);
      vector_subrange_lbits(&zgsz3485, zgsz3482, zgsz3483, zgsz3484);
      zimm = CONVERT_OF(fbits, lbits)(zgsz3485, true);
      KILL(lbits)(&zgsz3485);
      KILL(sail_int)(&zgsz3484);
      KILL(sail_int)(&zgsz3483);
      KILL(lbits)(&zgsz3482);
    }
    uint64_t zrd;
    {
      lbits zgsz3486;
      CREATE(lbits)(&zgsz3486);
      CONVERT_OF(lbits, fbits)(&zgsz3486, zv__43, UINT64_C(32) , true);
      sail_int zgsz3487;
      CREATE(sail_int)(&zgsz3487);
      CONVERT_OF(sail_int, mach_int)(&zgsz3487, INT64_C(11));
      sail_int zgsz3488;
      CREATE(sail_int)(&zgsz3488);
      CONVERT_OF(sail_int, mach_int)(&zgsz3488, INT64_C(7));
      lbits zgsz3489;
      CREATE(lbits)(&zgsz3489);
      vector_subrange_lbits(&zgsz3489, zgsz3486, zgsz3487, zgsz3488);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3489, true);
      KILL(lbits)(&zgsz3489);
      KILL(sail_int)(&zgsz3488);
      KILL(sail_int)(&zgsz3487);
      KILL(lbits)(&zgsz3486);
    }
    uint64_t zimmshadowz311;
    {
      lbits zgsz3490;
      CREATE(lbits)(&zgsz3490);
      CONVERT_OF(lbits, fbits)(&zgsz3490, zv__43, UINT64_C(32) , true);
      sail_int zgsz3491;
      CREATE(sail_int)(&zgsz3491);
      CONVERT_OF(sail_int, mach_int)(&zgsz3491, INT64_C(31));
      sail_int zgsz3492;
      CREATE(sail_int)(&zgsz3492);
      CONVERT_OF(sail_int, mach_int)(&zgsz3492, INT64_C(12));
      lbits zgsz3493;
      CREATE(lbits)(&zgsz3493);
      vector_subrange_lbits(&zgsz3493, zgsz3490, zgsz3491, zgsz3492);
      zimmshadowz311 = CONVERT_OF(fbits, lbits)(zgsz3493, true);
      KILL(lbits)(&zgsz3493);
      KILL(sail_int)(&zgsz3492);
      KILL(sail_int)(&zgsz3491);
      KILL(lbits)(&zgsz3490);
    }
    struct zast zgaz350;
    CREATE(zast)(&zgaz350);
    {
      struct ztuple_z8z5bv20zCz0z5bv5zCz0z5enumz0zzuopz9 zgsz3494;
      zgsz3494.ztup0 = zimmshadowz311;
      zgsz3494.ztup1 = zrd;
      zgsz3494.ztup2 = zAUIPC;
      zUTYPE(&zgaz350, zgsz3494);
    
    }
    {
      struct zast zgsz3570;
      CREATE(zast)(&zgsz3570);
      COPY(zast)(&zgsz3570, zgaz350);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3570);
      KILL(zast)(&zgsz3570);
    }
    KILL(zast)(&zgaz350);
  
  
  
  
    goto finish_match_1;
  }
case_20: ;
  {
    uint64_t zv__45;
    zv__45 = zmergez3var;
    uint64_t zgaz353;
    {
      lbits zgsz3498;
      CREATE(lbits)(&zgsz3498);
      CONVERT_OF(lbits, fbits)(&zgsz3498, zv__45, UINT64_C(32) , true);
      sail_int zgsz3499;
      CREATE(sail_int)(&zgsz3499);
      CONVERT_OF(sail_int, mach_int)(&zgsz3499, INT64_C(6));
      sail_int zgsz3500;
      CREATE(sail_int)(&zgsz3500);
      CONVERT_OF(sail_int, mach_int)(&zgsz3500, INT64_C(0));
      lbits zgsz3501;
      CREATE(lbits)(&zgsz3501);
      vector_subrange_lbits(&zgsz3501, zgsz3498, zgsz3499, zgsz3500);
      zgaz353 = CONVERT_OF(fbits, lbits)(zgsz3501, true);
      KILL(lbits)(&zgsz3501);
      KILL(sail_int)(&zgsz3500);
      KILL(sail_int)(&zgsz3499);
      KILL(lbits)(&zgsz3498);
    }
    bool zgsz3527;
    {
      lbits zgsz3529;
      CREATE(lbits)(&zgsz3529);
      CONVERT_OF(lbits, fbits)(&zgsz3529, UINT64_C(0b1101111), UINT64_C(7) , true);
      lbits zgsz3528;
      CREATE(lbits)(&zgsz3528);
      CONVERT_OF(lbits, fbits)(&zgsz3528, zgaz353, UINT64_C(7) , true);
      zgsz3527 = eq_bits(zgsz3528, zgsz3529);
      KILL(lbits)(&zgsz3529);
      KILL(lbits)(&zgsz3528);
    }
  
    if (!(zgsz3527)) {
  
    goto case_21;
    }
    uint64_t zimm4;
    {
      lbits zgsz3502;
      CREATE(lbits)(&zgsz3502);
      CONVERT_OF(lbits, fbits)(&zgsz3502, zv__45, UINT64_C(32) , true);
      sail_int zgsz3503;
      CREATE(sail_int)(&zgsz3503);
      CONVERT_OF(sail_int, mach_int)(&zgsz3503, INT64_C(31));
      sail_int zgsz3504;
      CREATE(sail_int)(&zgsz3504);
      CONVERT_OF(sail_int, mach_int)(&zgsz3504, INT64_C(31));
      lbits zgsz3505;
      CREATE(lbits)(&zgsz3505);
      vector_subrange_lbits(&zgsz3505, zgsz3502, zgsz3503, zgsz3504);
      zimm4 = CONVERT_OF(fbits, lbits)(zgsz3505, true);
      KILL(lbits)(&zgsz3505);
      KILL(sail_int)(&zgsz3504);
      KILL(sail_int)(&zgsz3503);
      KILL(lbits)(&zgsz3502);
    }
    uint64_t zrd;
    {
      lbits zgsz3506;
      CREATE(lbits)(&zgsz3506);
      CONVERT_OF(lbits, fbits)(&zgsz3506, zv__45, UINT64_C(32) , true);
      sail_int zgsz3507;
      CREATE(sail_int)(&zgsz3507);
      CONVERT_OF(sail_int, mach_int)(&zgsz3507, INT64_C(11));
      sail_int zgsz3508;
      CREATE(sail_int)(&zgsz3508);
      CONVERT_OF(sail_int, mach_int)(&zgsz3508, INT64_C(7));
      lbits zgsz3509;
      CREATE(lbits)(&zgsz3509);
      vector_subrange_lbits(&zgsz3509, zgsz3506, zgsz3507, zgsz3508);
      zrd = CONVERT_OF(fbits, lbits)(zgsz3509, true);
      KILL(lbits)(&zgsz3509);
      KILL(sail_int)(&zgsz3508);
      KILL(sail_int)(&zgsz3507);
      KILL(lbits)(&zgsz3506);
    }
    uint64_t zimm4shadowz312;
    {
      lbits zgsz3510;
      CREATE(lbits)(&zgsz3510);
      CONVERT_OF(lbits, fbits)(&zgsz3510, zv__45, UINT64_C(32) , true);
      sail_int zgsz3511;
      CREATE(sail_int)(&zgsz3511);
      CONVERT_OF(sail_int, mach_int)(&zgsz3511, INT64_C(31));
      sail_int zgsz3512;
      CREATE(sail_int)(&zgsz3512);
      CONVERT_OF(sail_int, mach_int)(&zgsz3512, INT64_C(31));
      lbits zgsz3513;
      CREATE(lbits)(&zgsz3513);
      vector_subrange_lbits(&zgsz3513, zgsz3510, zgsz3511, zgsz3512);
      zimm4shadowz312 = CONVERT_OF(fbits, lbits)(zgsz3513, true);
      KILL(lbits)(&zgsz3513);
      KILL(sail_int)(&zgsz3512);
      KILL(sail_int)(&zgsz3511);
      KILL(lbits)(&zgsz3510);
    }
    uint64_t zimm3;
    {
      lbits zgsz3514;
      CREATE(lbits)(&zgsz3514);
      CONVERT_OF(lbits, fbits)(&zgsz3514, zv__45, UINT64_C(32) , true);
      sail_int zgsz3515;
      CREATE(sail_int)(&zgsz3515);
      CONVERT_OF(sail_int, mach_int)(&zgsz3515, INT64_C(19));
      sail_int zgsz3516;
      CREATE(sail_int)(&zgsz3516);
      CONVERT_OF(sail_int, mach_int)(&zgsz3516, INT64_C(12));
      lbits zgsz3517;
      CREATE(lbits)(&zgsz3517);
      vector_subrange_lbits(&zgsz3517, zgsz3514, zgsz3515, zgsz3516);
      zimm3 = CONVERT_OF(fbits, lbits)(zgsz3517, true);
      KILL(lbits)(&zgsz3517);
      KILL(sail_int)(&zgsz3516);
      KILL(sail_int)(&zgsz3515);
      KILL(lbits)(&zgsz3514);
    }
    uint64_t zimm2;
    {
      lbits zgsz3518;
      CREATE(lbits)(&zgsz3518);
      CONVERT_OF(lbits, fbits)(&zgsz3518, zv__45, UINT64_C(32) , true);
      sail_int zgsz3519;
      CREATE(sail_int)(&zgsz3519);
      CONVERT_OF(sail_int, mach_int)(&zgsz3519, INT64_C(20));
      sail_int zgsz3520;
      CREATE(sail_int)(&zgsz3520);
      CONVERT_OF(sail_int, mach_int)(&zgsz3520, INT64_C(20));
      lbits zgsz3521;
      CREATE(lbits)(&zgsz3521);
      vector_subrange_lbits(&zgsz3521, zgsz3518, zgsz3519, zgsz3520);
      zimm2 = CONVERT_OF(fbits, lbits)(zgsz3521, true);
      KILL(lbits)(&zgsz3521);
      KILL(sail_int)(&zgsz3520);
      KILL(sail_int)(&zgsz3519);
      KILL(lbits)(&zgsz3518);
    }
    uint64_t zimm1;
    {
      lbits zgsz3522;
      CREATE(lbits)(&zgsz3522);
      CONVERT_OF(lbits, fbits)(&zgsz3522, zv__45, UINT64_C(32) , true);
      sail_int zgsz3523;
      CREATE(sail_int)(&zgsz3523);
      CONVERT_OF(sail_int, mach_int)(&zgsz3523, INT64_C(30));
      sail_int zgsz3524;
      CREATE(sail_int)(&zgsz3524);
      CONVERT_OF(sail_int, mach_int)(&zgsz3524, INT64_C(21));
      lbits zgsz3525;
      CREATE(lbits)(&zgsz3525);
      vector_subrange_lbits(&zgsz3525, zgsz3522, zgsz3523, zgsz3524);
      zimm1 = CONVERT_OF(fbits, lbits)(zgsz3525, true);
      KILL(lbits)(&zgsz3525);
      KILL(sail_int)(&zgsz3524);
      KILL(sail_int)(&zgsz3523);
      KILL(lbits)(&zgsz3522);
    }
    struct zast zgaz352;
    CREATE(zast)(&zgaz352);
    {
      struct ztuple_z8z5bv1zCz0z5bv10zCz0z5bv1zCz0z5bv8zCz0z5bv5zCz0z5enumz0zzjopz9 zgsz3526;
      zgsz3526.ztup0 = zimm4shadowz312;
      zgsz3526.ztup1 = zimm1;
      zgsz3526.ztup2 = zimm2;
      zgsz3526.ztup3 = zimm3;
      zgsz3526.ztup4 = zrd;
      zgsz3526.ztup5 = zJAL;
      zJTYPE(&zgaz352, zgsz3526);
    
    }
    {
      struct zast zgsz3571;
      CREATE(zast)(&zgsz3571);
      COPY(zast)(&zgsz3571, zgaz352);
      zSomez3z5unionz0zzast(&zgsz30, zgsz3571);
      KILL(zast)(&zgsz3571);
    }
    KILL(zast)(&zgaz352);
  
  
  
  
  
  
  
    goto finish_match_1;
  }
case_21: ;
  sail_match_failure("decode");
finish_match_1: ;
  COPY(zoption)((*(&zcbz30)), zgsz30);
  KILL(zoption)(&zgsz30);
end_function_22: ;
  goto end_function_51;
end_block_exception_23: ;
  goto end_function_51;
end_function_51: ;
}

unit zexecute(struct zast zmergez3var)
{
  __label__ case_26, case_27, case_28, case_29, case_30, case_31, case_32, case_33, case_34, case_35, case_36, case_37, case_38, case_39, case_40, case_41, case_42, case_43, case_44, case_45, finish_match_25, end_function_46, end_block_exception_47;

  unit zcbz31;
  unit zgsz3530;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_26;
    uint64_t zrs2;
    zrs2 = zmergez3var.zRTYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zRTYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zRTYPE.ztup2;
    if ((zADD != zmergez3var.zRTYPE.ztup3)) goto case_26;
    zgsz3530 = print_endline("execute ADD\n");
  
  
  
    goto finish_match_25;
  }
case_26: ;
  {
    if (zmergez3var.kind != Kind_zRTYPE) goto case_27;
    uint64_t zrs2;
    zrs2 = zmergez3var.zRTYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zRTYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zRTYPE.ztup2;
    if ((zAND != zmergez3var.zRTYPE.ztup3)) goto case_27;
    zgsz3530 = print_endline("execute AND\n");
  
  
  
    goto finish_match_25;
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
    if ((zOR != zmergez3var.zRTYPE.ztup3)) goto case_28;
    zgsz3530 = print_endline("execute OR\n");
  
  
  
    goto finish_match_25;
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
    if ((zXOR != zmergez3var.zRTYPE.ztup3)) goto case_29;
    zgsz3530 = print_endline("execute XOR\n");
  
  
  
    goto finish_match_25;
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
    if ((zMUL != zmergez3var.zRTYPE.ztup3)) goto case_30;
    zgsz3530 = print_endline("execute MUL\n");
  
  
  
    goto finish_match_25;
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
    if ((zDIV != zmergez3var.zRTYPE.ztup3)) goto case_31;
    zgsz3530 = print_endline("execute DIV\n");
  
  
  
    goto finish_match_25;
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
    if ((zREM != zmergez3var.zRTYPE.ztup3)) goto case_32;
    zgsz3530 = print_endline("execute REM\n");
  
  
  
    goto finish_match_25;
  }
case_32: ;
  {
    if (zmergez3var.kind != Kind_zITYPE) goto case_33;
    uint64_t zimm;
    zimm = zmergez3var.zITYPE.ztup0;
    uint64_t zrs1;
    zrs1 = zmergez3var.zITYPE.ztup1;
    uint64_t zrd;
    zrd = zmergez3var.zITYPE.ztup2;
    if ((zADDI != zmergez3var.zITYPE.ztup3)) goto case_33;
    zgsz3530 = print_endline("execute ADDI\n");
  
  
  
    goto finish_match_25;
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
    if ((zSLTI != zmergez3var.zITYPE.ztup3)) goto case_34;
    zgsz3530 = print_endline("execute SLTI\n");
  
  
  
    goto finish_match_25;
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
    if ((zANDI != zmergez3var.zITYPE.ztup3)) goto case_35;
    zgsz3530 = print_endline("execute ANDI\n");
  
  
  
    goto finish_match_25;
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
    if ((zORI != zmergez3var.zITYPE.ztup3)) goto case_36;
    zgsz3530 = print_endline("execute ORI\n");
  
  
  
    goto finish_match_25;
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
    if ((zXORI != zmergez3var.zITYPE.ztup3)) goto case_37;
    zgsz3530 = print_endline("execute XORI\n");
  
  
  
    goto finish_match_25;
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
    if ((zJALR != zmergez3var.zITYPE.ztup3)) goto case_38;
    zgsz3530 = print_endline("execute JALR\n");
  
  
  
    goto finish_match_25;
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
    if ((zLW != zmergez3var.zITYPE.ztup3)) goto case_39;
    zgsz3530 = print_endline("execute LW\n");
  
  
  
    goto finish_match_25;
  }
case_39: ;
  {
    if (zmergez3var.kind != Kind_zSTYPE) goto case_40;
    uint64_t zimm2;
    zimm2 = zmergez3var.zSTYPE.ztup0;
    uint64_t zrs2;
    zrs2 = zmergez3var.zSTYPE.ztup1;
    uint64_t zrs1;
    zrs1 = zmergez3var.zSTYPE.ztup2;
    uint64_t zimm1;
    zimm1 = zmergez3var.zSTYPE.ztup3;
    if ((zSW != zmergez3var.zSTYPE.ztup4)) goto case_40;
    zgsz3530 = print_endline("execute SW\n");
  
  
  
  
    goto finish_match_25;
  }
case_40: ;
  {
    if (zmergez3var.kind != Kind_zBTYPE) goto case_41;
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
    if ((zBEQ != zmergez3var.zBTYPE.ztup6)) goto case_41;
    zgsz3530 = print_endline("execute BEQ\n");
  
  
  
  
  
  
    goto finish_match_25;
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
    if ((zBNE != zmergez3var.zBTYPE.ztup6)) goto case_42;
    zgsz3530 = print_endline("execute BNE\n");
  
  
  
  
  
  
    goto finish_match_25;
  }
case_42: ;
  {
    if (zmergez3var.kind != Kind_zUTYPE) goto case_43;
    uint64_t zimm;
    zimm = zmergez3var.zUTYPE.ztup0;
    uint64_t zrd;
    zrd = zmergez3var.zUTYPE.ztup1;
    if ((zLUI != zmergez3var.zUTYPE.ztup2)) goto case_43;
    zgsz3530 = print_endline("execute LUI\n");
  
  
    goto finish_match_25;
  }
case_43: ;
  {
    if (zmergez3var.kind != Kind_zUTYPE) goto case_44;
    uint64_t zimm;
    zimm = zmergez3var.zUTYPE.ztup0;
    uint64_t zrd;
    zrd = zmergez3var.zUTYPE.ztup1;
    if ((zAUIPC != zmergez3var.zUTYPE.ztup2)) goto case_44;
    zgsz3530 = print_endline("execute AUIPC\n");
  
  
    goto finish_match_25;
  }
case_44: ;
  {
    if (zmergez3var.kind != Kind_zJTYPE) goto case_45;
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
    if ((zJAL != zmergez3var.zJTYPE.ztup5)) goto case_45;
    zgsz3530 = print_endline("execute JAL\n");
  
  
  
  
  
    goto finish_match_25;
  }
case_45: ;
  sail_match_failure("execute");
finish_match_25: ;
  zcbz31 = zgsz3530;

end_function_46: ;
  return zcbz31;
end_block_exception_47: ;

  return UNIT;
}

unit zmain(unit);

unit zmain(unit zgsz3551)
{
  __label__ end_function_49, end_block_exception_50;

  unit zcbz32;
  zcbz32 = print_endline("Hello World");
end_function_49: ;
  return zcbz32;
end_block_exception_50: ;

  return UNIT;
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
