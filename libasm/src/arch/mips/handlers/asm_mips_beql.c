/**
* @file libasm/src/arch/mips/handlers/asm_mips_beql.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_beql(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BEQL;
   ins->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: None */

   return 4;
}
