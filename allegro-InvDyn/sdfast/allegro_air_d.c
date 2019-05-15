/*
Generated 15-Apr-2019 14:28:10 by SD/FAST, Kane's formulation
(sdfast B.2.8 #30123) on machine ID unknown
Copyright (c) 1990-1997 Symbolic Dynamics, Inc.
Copyright (c) 1990-1997 Parametric Technology Corp.
RESTRICTED RIGHTS LEGEND: Use, duplication, or disclosure by the U.S.
Government is subject to restrictions as set forth in subparagraph
(c)(1)(ii) of the Rights in Technical Data and Computer Software
clause at DFARS 52.227-7013 and similar clauses in the FAR and NASA
FAR Supplement.  Symbolic Dynamics, Inc., Mountain View, CA 94041


ROADMAP (allegro_air.sd)

Bodies          Inb
No  Name        body Joint type  Coords q         Multipliers
--- ----------- ---- ----------- ---------------- -----------------------
 -1 $ground                                      |
  0 palm_link    -1  Sixdof        0?  1?  2?    |
                     ...           3?  4?  5? 22 |  0p  1p  2p  3p  4p  5p
  1 link_0        0  Pin           6?            |  6p
  2 link_1        1  Pin           7?            |  7p
  3 link_2        2  Pin           8?            |  8p
  4 link_3        3  Pin           9?            |  9p
  5 link_3_tip    4  Weld                        |
  6 link_12       0  Pin          10?            | 10p
  7 link_13       6  Pin          11?            | 11p
  8 link_14       7  Pin          12?            | 12p
  9 link_15       8  Pin          13?            | 13p
 10 link_15_tip   9  Weld                        |
 11 link_4        0  Pin          14?            | 14p
 12 link_5       11  Pin          15?            | 15p
 13 link_6       12  Pin          16?            | 16p
 14 link_7       13  Pin          17?            | 17p
 15 link_7_tip   14  Weld                        |
 16 link_8        0  Pin          18?            | 18p
 17 link_9       16  Pin          19?            | 19p
 18 link_10      17  Pin          20?            | 20p
 19 link_11      18  Pin          21?            | 21p
 20 link_11_tip  19  Weld                        |

*/
#include <math.h>
#include <stdio.h>

typedef struct {
    int ground_,nbod_,ndof_,ncons_,nloop_,nldof_,nloopc_,nball_,nlball_,npres_,
      nuser_;
    int jtype_[21],inb_[21],outb_[21],njntdof_[21],njntc_[21],njntp_[21],firstq_
      [21],ballq_[21],firstm_[21],firstp_[21];
    int trans_[22];
} allegro_air_gtopo_t;
#define ground (allegro_air_gtopo.ground_)
#define nbod (allegro_air_gtopo.nbod_)
#define ndof (allegro_air_gtopo.ndof_)
#define ncons (allegro_air_gtopo.ncons_)
#define nloop (allegro_air_gtopo.nloop_)
#define nldof (allegro_air_gtopo.nldof_)
#define nloopc (allegro_air_gtopo.nloopc_)
#define nball (allegro_air_gtopo.nball_)
#define nlball (allegro_air_gtopo.nlball_)
#define npres (allegro_air_gtopo.npres_)
#define nuser (allegro_air_gtopo.nuser_)
#define jtype (allegro_air_gtopo.jtype_)
#define inb (allegro_air_gtopo.inb_)
#define outb (allegro_air_gtopo.outb_)
#define njntdof (allegro_air_gtopo.njntdof_)
#define njntc (allegro_air_gtopo.njntc_)
#define njntp (allegro_air_gtopo.njntp_)
#define firstq (allegro_air_gtopo.firstq_)
#define ballq (allegro_air_gtopo.ballq_)
#define firstm (allegro_air_gtopo.firstm_)
#define firstp (allegro_air_gtopo.firstp_)
#define trans (allegro_air_gtopo.trans_)

typedef struct {
    double grav_[3],mk_[21],ik_[21][3][3],pin_[22][3];
    double rk_[21][3],ri_[21][3],pres_[22],stabvel_,stabpos_;
    int mfrcflg_,roustate_,vpkflg_,inerflg_,mmflg_,mmlduflg_,wwflg_,ltauflg_,
      fs0flg_,ii_,mmap_[22];
    int gravq_[3],mkq_[21],ikq_[21][3][3],pinq_[22][3],rkq_[21][3],riq_[21][3],
      presq_[22],stabvelq_,stabposq_;
    double mtot_,psmkg_,rhead_[21][3],rcom_[21][3],mkrcomt_[21][3][3],psikg_[3][
      3],psrcomg_[3],psrkg_[3],psrig_[3],psmk_[22],psik_[22][3][3],psrcom_[22][3
      ],psrk_[22][3],psri_[22][3];
} allegro_air_ginput_t;
#define grav (allegro_air_ginput.grav_)
#define mk (allegro_air_ginput.mk_)
#define ik (allegro_air_ginput.ik_)
#define pin (allegro_air_ginput.pin_)
#define rk (allegro_air_ginput.rk_)
#define ri (allegro_air_ginput.ri_)
#define pres (allegro_air_ginput.pres_)
#define stabvel (allegro_air_ginput.stabvel_)
#define stabpos (allegro_air_ginput.stabpos_)
#define rhead (allegro_air_ginput.rhead_)
#define rcom (allegro_air_ginput.rcom_)
#define psrcomg (allegro_air_ginput.psrcomg_)
#define psrcom (allegro_air_ginput.psrcom_)
#define mkrcomt (allegro_air_ginput.mkrcomt_)
#define psmk (allegro_air_ginput.psmk_)
#define psik (allegro_air_ginput.psik_)
#define psrk (allegro_air_ginput.psrk_)
#define psri (allegro_air_ginput.psri_)
#define psmkg (allegro_air_ginput.psmkg_)
#define psikg (allegro_air_ginput.psikg_)
#define psrkg (allegro_air_ginput.psrkg_)
#define psrig (allegro_air_ginput.psrig_)
#define mtot (allegro_air_ginput.mtot_)
#define mfrcflg (allegro_air_ginput.mfrcflg_)
#define roustate (allegro_air_ginput.roustate_)
#define vpkflg (allegro_air_ginput.vpkflg_)
#define inerflg (allegro_air_ginput.inerflg_)
#define mmflg (allegro_air_ginput.mmflg_)
#define mmlduflg (allegro_air_ginput.mmlduflg_)
#define wwflg (allegro_air_ginput.wwflg_)
#define ltauflg (allegro_air_ginput.ltauflg_)
#define fs0flg (allegro_air_ginput.fs0flg_)
#define ii (allegro_air_ginput.ii_)
#define mmap (allegro_air_ginput.mmap_)
#define gravq (allegro_air_ginput.gravq_)
#define mkq (allegro_air_ginput.mkq_)
#define ikq (allegro_air_ginput.ikq_)
#define pinq (allegro_air_ginput.pinq_)
#define rkq (allegro_air_ginput.rkq_)
#define riq (allegro_air_ginput.riq_)
#define presq (allegro_air_ginput.presq_)
#define stabvelq (allegro_air_ginput.stabvelq_)
#define stabposq (allegro_air_ginput.stabposq_)

typedef struct {
    double curtim_,q_[23],qn_[23],u_[22],cnk_[22][3][3],cnb_[21][3][3];
    double rnk_[22][3],vnk_[22][3],wk_[22][3],rnb_[21][3],vnb_[21][3],wb_[21][3]
      ,wbrcom_[21][3],com_[3],rnkg_[3];
    double Cik_[22][3][3],rikt_[22][3][3],Iko_[22][3][3],mkrk_[22][3][3],Cib_[21
      ][3][3];
    double Wkk_[22][3],Vkk_[22][3],dik_[22][3],rpp_[22][3],rpk_[22][3],rik_[22][
      3],rik2_[22][3];
    double rpri_[22][3],Wik_[22][3],Vik_[22][3],Wirk_[22][3],rkWkk_[22][3],
      Wkrpk_[22][3],VikWkr_[22][3];
    double perr_[22],verr_[22],aerr_[22],mult_[22],ufk_[21][3],utk_[21][3],mfk_[
      21][3],mtk_[21][3];
    double utau_[22],mtau_[22],uacc_[22],uvel_[22],upos_[23];
    double s6_,c6_,s7_,c7_,s8_,c8_,s9_,c9_,s10_,c10_,s11_,c11_,s12_,c12_,s13_,
      c13_,s14_,c14_,s15_,c15_,s16_,c16_,s17_,c17_,s18_,c18_,s19_,c19_,s20_,c20_
      ,s21_,c21_;
} allegro_air_gstate_t;
#define curtim (allegro_air_gstate.curtim_)
#define q (allegro_air_gstate.q_)
#define qn (allegro_air_gstate.qn_)
#define u (allegro_air_gstate.u_)
#define cnk (allegro_air_gstate.cnk_)
#define cnb (allegro_air_gstate.cnb_)
#define rnkg (allegro_air_gstate.rnkg_)
#define rnk (allegro_air_gstate.rnk_)
#define rnb (allegro_air_gstate.rnb_)
#define vnk (allegro_air_gstate.vnk_)
#define vnb (allegro_air_gstate.vnb_)
#define wk (allegro_air_gstate.wk_)
#define wb (allegro_air_gstate.wb_)
#define com (allegro_air_gstate.com_)
#define Cik (allegro_air_gstate.Cik_)
#define Cib (allegro_air_gstate.Cib_)
#define rikt (allegro_air_gstate.rikt_)
#define Iko (allegro_air_gstate.Iko_)
#define mkrk (allegro_air_gstate.mkrk_)
#define Wkk (allegro_air_gstate.Wkk_)
#define Vkk (allegro_air_gstate.Vkk_)
#define dik (allegro_air_gstate.dik_)
#define rpp (allegro_air_gstate.rpp_)
#define rpk (allegro_air_gstate.rpk_)
#define rik (allegro_air_gstate.rik_)
#define rik2 (allegro_air_gstate.rik2_)
#define rpri (allegro_air_gstate.rpri_)
#define Wik (allegro_air_gstate.Wik_)
#define Vik (allegro_air_gstate.Vik_)
#define Wirk (allegro_air_gstate.Wirk_)
#define rkWkk (allegro_air_gstate.rkWkk_)
#define Wkrpk (allegro_air_gstate.Wkrpk_)
#define VikWkr (allegro_air_gstate.VikWkr_)
#define wbrcom (allegro_air_gstate.wbrcom_)
#define perr (allegro_air_gstate.perr_)
#define verr (allegro_air_gstate.verr_)
#define aerr (allegro_air_gstate.aerr_)
#define mult (allegro_air_gstate.mult_)
#define ufk (allegro_air_gstate.ufk_)
#define utk (allegro_air_gstate.utk_)
#define utau (allegro_air_gstate.utau_)
#define mfk (allegro_air_gstate.mfk_)
#define mtk (allegro_air_gstate.mtk_)
#define mtau (allegro_air_gstate.mtau_)
#define uacc (allegro_air_gstate.uacc_)
#define uvel (allegro_air_gstate.uvel_)
#define upos (allegro_air_gstate.upos_)
#define s6 (allegro_air_gstate.s6_)
#define c6 (allegro_air_gstate.c6_)
#define s7 (allegro_air_gstate.s7_)
#define c7 (allegro_air_gstate.c7_)
#define s8 (allegro_air_gstate.s8_)
#define c8 (allegro_air_gstate.c8_)
#define s9 (allegro_air_gstate.s9_)
#define c9 (allegro_air_gstate.c9_)
#define s10 (allegro_air_gstate.s10_)
#define c10 (allegro_air_gstate.c10_)
#define s11 (allegro_air_gstate.s11_)
#define c11 (allegro_air_gstate.c11_)
#define s12 (allegro_air_gstate.s12_)
#define c12 (allegro_air_gstate.c12_)
#define s13 (allegro_air_gstate.s13_)
#define c13 (allegro_air_gstate.c13_)
#define s14 (allegro_air_gstate.s14_)
#define c14 (allegro_air_gstate.c14_)
#define s15 (allegro_air_gstate.s15_)
#define c15 (allegro_air_gstate.c15_)
#define s16 (allegro_air_gstate.s16_)
#define c16 (allegro_air_gstate.c16_)
#define s17 (allegro_air_gstate.s17_)
#define c17 (allegro_air_gstate.c17_)
#define s18 (allegro_air_gstate.s18_)
#define c18 (allegro_air_gstate.c18_)
#define s19 (allegro_air_gstate.s19_)
#define c19 (allegro_air_gstate.c19_)
#define s20 (allegro_air_gstate.s20_)
#define c20 (allegro_air_gstate.c20_)
#define s21 (allegro_air_gstate.s21_)
#define c21 (allegro_air_gstate.c21_)

typedef struct {
    double fs0_[22],qdot_[23],Otk_[22][3],Atk_[22][3],AiOiWi_[22][3],Fstar_[22][
      3];
    double Tstar_[22][3],Fstark_[22][3],Tstark_[22][3],IkWk_[22][3],WkIkWk_[22][
      3],gk_[22][3],IkbWk_[21][3],WkIkbWk_[21][3];
    double w0w0_[21],w1w1_[21],w2w2_[21],w0w1_[21],w0w2_[21],w1w2_[21];
    double w00w11_[21],w00w22_[21],w11w22_[21],ww_[22][22],qraux_[22];
    double mm_[22][22],mlo_[22][22],mdi_[22],IkWpk_[22][22][3],works_[22],
      workss_[22][22];
    double Wpk_[22][22][3],Vpk_[22][22][3],VWri_[22][22][3];
    int wmap_[22],multmap_[22],jpvt_[22],wsiz_,wrank_;
} allegro_air_glhs_t;
#define qdot (allegro_air_glhs.qdot_)
#define Otk (allegro_air_glhs.Otk_)
#define Atk (allegro_air_glhs.Atk_)
#define AiOiWi (allegro_air_glhs.AiOiWi_)
#define Fstar (allegro_air_glhs.Fstar_)
#define Tstar (allegro_air_glhs.Tstar_)
#define fs0 (allegro_air_glhs.fs0_)
#define Fstark (allegro_air_glhs.Fstark_)
#define Tstark (allegro_air_glhs.Tstark_)
#define IkWk (allegro_air_glhs.IkWk_)
#define IkbWk (allegro_air_glhs.IkbWk_)
#define WkIkWk (allegro_air_glhs.WkIkWk_)
#define WkIkbWk (allegro_air_glhs.WkIkbWk_)
#define gk (allegro_air_glhs.gk_)
#define w0w0 (allegro_air_glhs.w0w0_)
#define w1w1 (allegro_air_glhs.w1w1_)
#define w2w2 (allegro_air_glhs.w2w2_)
#define w0w1 (allegro_air_glhs.w0w1_)
#define w0w2 (allegro_air_glhs.w0w2_)
#define w1w2 (allegro_air_glhs.w1w2_)
#define w00w11 (allegro_air_glhs.w00w11_)
#define w00w22 (allegro_air_glhs.w00w22_)
#define w11w22 (allegro_air_glhs.w11w22_)
#define ww (allegro_air_glhs.ww_)
#define qraux (allegro_air_glhs.qraux_)
#define mm (allegro_air_glhs.mm_)
#define mlo (allegro_air_glhs.mlo_)
#define mdi (allegro_air_glhs.mdi_)
#define IkWpk (allegro_air_glhs.IkWpk_)
#define works (allegro_air_glhs.works_)
#define workss (allegro_air_glhs.workss_)
#define Wpk (allegro_air_glhs.Wpk_)
#define Vpk (allegro_air_glhs.Vpk_)
#define VWri (allegro_air_glhs.VWri_)
#define wmap (allegro_air_glhs.wmap_)
#define multmap (allegro_air_glhs.multmap_)
#define jpvt (allegro_air_glhs.jpvt_)
#define wsiz (allegro_air_glhs.wsiz_)
#define wrank (allegro_air_glhs.wrank_)

typedef struct {
    double fs_[22],udot_[22],tauc_[22],dyad_[21][3][3],fc_[22][3],tc_[22][3];
    double ank_[22][3],onk_[22][3],Onkb_[22][3],AOnkri_[22][3],Ankb_[22][3],
      AnkAtk_[22][3],anb_[21][3],onb_[21][3],dyrcom_[21][3];
    double ffk_[22][3],ttk_[22][3],fccikt_[22][3],ffkb_[21][3],ttkb_[21][3];
} allegro_air_grhs_t;
#define fs (allegro_air_grhs.fs_)
#define udot (allegro_air_grhs.udot_)
#define ank (allegro_air_grhs.ank_)
#define anb (allegro_air_grhs.anb_)
#define onk (allegro_air_grhs.onk_)
#define onb (allegro_air_grhs.onb_)
#define Onkb (allegro_air_grhs.Onkb_)
#define AOnkri (allegro_air_grhs.AOnkri_)
#define Ankb (allegro_air_grhs.Ankb_)
#define AnkAtk (allegro_air_grhs.AnkAtk_)
#define dyrcom (allegro_air_grhs.dyrcom_)
#define ffk (allegro_air_grhs.ffk_)
#define ttk (allegro_air_grhs.ttk_)
#define fccikt (allegro_air_grhs.fccikt_)
#define ffkb (allegro_air_grhs.ffkb_)
#define ttkb (allegro_air_grhs.ttkb_)
#define dyad (allegro_air_grhs.dyad_)
#define fc (allegro_air_grhs.fc_)
#define tc (allegro_air_grhs.tc_)
#define tauc (allegro_air_grhs.tauc_)

typedef struct {
    double temp_[3000],tmat1_[3][3],tmat2_[3][3],tvec1_[3],tvec2_[3],tvec3_[3],
      tvec4_[3],tvec5_[3];
    double tsc1_,tsc2_,tsc3_;
} allegro_air_gtemp_t;
#define temp (allegro_air_gtemp.temp_)
#define tmat1 (allegro_air_gtemp.tmat1_)
#define tmat2 (allegro_air_gtemp.tmat2_)
#define tvec1 (allegro_air_gtemp.tvec1_)
#define tvec2 (allegro_air_gtemp.tvec2_)
#define tvec3 (allegro_air_gtemp.tvec3_)
#define tvec4 (allegro_air_gtemp.tvec4_)
#define tvec5 (allegro_air_gtemp.tvec5_)
#define tsc1 (allegro_air_gtemp.tsc1_)
#define tsc2 (allegro_air_gtemp.tsc2_)
#define tsc3 (allegro_air_gtemp.tsc3_)

allegro_air_gtopo_t allegro_air_gtopo = {
/*  Topological information
*/
    /* ground */ 1,
    /* nbod */ 21,
    /* ndof */ 22,
    /* ncons */ 22,
    /* nloop */ 0,
    /* nldof */ 0,
    /* nloopc */ 0,
    /* nball */ 1,
    /* nlball */ 0,
    /* npres */ 22,
    /* nuser */ 0,
    /* jtype[0] */ 6,
    /* jtype[1] */ 1,
    /* jtype[2] */ 1,
    /* jtype[3] */ 1,
    /* jtype[4] */ 1,
    /* jtype[5] */ 9,
    /* jtype[6] */ 1,
    /* jtype[7] */ 1,
    /* jtype[8] */ 1,
    /* jtype[9] */ 1,
    /* jtype[10] */ 9,
    /* jtype[11] */ 1,
    /* jtype[12] */ 1,
    /* jtype[13] */ 1,
    /* jtype[14] */ 1,
    /* jtype[15] */ 9,
    /* jtype[16] */ 1,
    /* jtype[17] */ 1,
    /* jtype[18] */ 1,
    /* jtype[19] */ 1,
    /* jtype[20] */ 9,
    /* inb[0] */ -1,
    /* inb[1] */ 0,
    /* inb[2] */ 1,
    /* inb[3] */ 2,
    /* inb[4] */ 3,
    /* inb[5] */ 4,
    /* inb[6] */ 0,
    /* inb[7] */ 6,
    /* inb[8] */ 7,
    /* inb[9] */ 8,
    /* inb[10] */ 9,
    /* inb[11] */ 0,
    /* inb[12] */ 11,
    /* inb[13] */ 12,
    /* inb[14] */ 13,
    /* inb[15] */ 14,
    /* inb[16] */ 0,
    /* inb[17] */ 16,
    /* inb[18] */ 17,
    /* inb[19] */ 18,
    /* inb[20] */ 19,
    /* outb[0] */ 0,
    /* outb[1] */ 1,
    /* outb[2] */ 2,
    /* outb[3] */ 3,
    /* outb[4] */ 4,
    /* outb[5] */ 5,
    /* outb[6] */ 6,
    /* outb[7] */ 7,
    /* outb[8] */ 8,
    /* outb[9] */ 9,
    /* outb[10] */ 10,
    /* outb[11] */ 11,
    /* outb[12] */ 12,
    /* outb[13] */ 13,
    /* outb[14] */ 14,
    /* outb[15] */ 15,
    /* outb[16] */ 16,
    /* outb[17] */ 17,
    /* outb[18] */ 18,
    /* outb[19] */ 19,
    /* outb[20] */ 20,
    /* njntdof[0] */ 6,
    /* njntdof[1] */ 1,
    /* njntdof[2] */ 1,
    /* njntdof[3] */ 1,
    /* njntdof[4] */ 1,
    /* njntdof[5] */ 0,
    /* njntdof[6] */ 1,
    /* njntdof[7] */ 1,
    /* njntdof[8] */ 1,
    /* njntdof[9] */ 1,
    /* njntdof[10] */ 0,
    /* njntdof[11] */ 1,
    /* njntdof[12] */ 1,
    /* njntdof[13] */ 1,
    /* njntdof[14] */ 1,
    /* njntdof[15] */ 0,
    /* njntdof[16] */ 1,
    /* njntdof[17] */ 1,
    /* njntdof[18] */ 1,
    /* njntdof[19] */ 1,
    /* njntdof[20] */ 0,
    /* njntc[0] */ 0,
    /* njntc[1] */ 0,
    /* njntc[2] */ 0,
    /* njntc[3] */ 0,
    /* njntc[4] */ 0,
    /* njntc[5] */ 0,
    /* njntc[6] */ 0,
    /* njntc[7] */ 0,
    /* njntc[8] */ 0,
    /* njntc[9] */ 0,
    /* njntc[10] */ 0,
    /* njntc[11] */ 0,
    /* njntc[12] */ 0,
    /* njntc[13] */ 0,
    /* njntc[14] */ 0,
    /* njntc[15] */ 0,
    /* njntc[16] */ 0,
    /* njntc[17] */ 0,
    /* njntc[18] */ 0,
    /* njntc[19] */ 0,
    /* njntc[20] */ 0,
    /* njntp[0] */ 6,
    /* njntp[1] */ 1,
    /* njntp[2] */ 1,
    /* njntp[3] */ 1,
    /* njntp[4] */ 1,
    /* njntp[5] */ 0,
    /* njntp[6] */ 1,
    /* njntp[7] */ 1,
    /* njntp[8] */ 1,
    /* njntp[9] */ 1,
    /* njntp[10] */ 0,
    /* njntp[11] */ 1,
    /* njntp[12] */ 1,
    /* njntp[13] */ 1,
    /* njntp[14] */ 1,
    /* njntp[15] */ 0,
    /* njntp[16] */ 1,
    /* njntp[17] */ 1,
    /* njntp[18] */ 1,
    /* njntp[19] */ 1,
    /* njntp[20] */ 0,
    /* firstq[0] */ 0,
    /* firstq[1] */ 6,
    /* firstq[2] */ 7,
    /* firstq[3] */ 8,
    /* firstq[4] */ 9,
    /* firstq[5] */ 10,
    /* firstq[6] */ 10,
    /* firstq[7] */ 11,
    /* firstq[8] */ 12,
    /* firstq[9] */ 13,
    /* firstq[10] */ 14,
    /* firstq[11] */ 14,
    /* firstq[12] */ 15,
    /* firstq[13] */ 16,
    /* firstq[14] */ 17,
    /* firstq[15] */ 18,
    /* firstq[16] */ 18,
    /* firstq[17] */ 19,
    /* firstq[18] */ 20,
    /* firstq[19] */ 21,
    /* firstq[20] */ 22,
    /* ballq[0] */ 22,
    /* ballq[1] */ -104,
    /* ballq[2] */ -104,
    /* ballq[3] */ -104,
    /* ballq[4] */ -104,
    /* ballq[5] */ -104,
    /* ballq[6] */ -104,
    /* ballq[7] */ -104,
    /* ballq[8] */ -104,
    /* ballq[9] */ -104,
    /* ballq[10] */ -104,
    /* ballq[11] */ -104,
    /* ballq[12] */ -104,
    /* ballq[13] */ -104,
    /* ballq[14] */ -104,
    /* ballq[15] */ -104,
    /* ballq[16] */ -104,
    /* ballq[17] */ -104,
    /* ballq[18] */ -104,
    /* ballq[19] */ -104,
    /* ballq[20] */ -104,
    /* firstm[0] */ -1,
    /* firstm[1] */ -1,
    /* firstm[2] */ -1,
    /* firstm[3] */ -1,
    /* firstm[4] */ -1,
    /* firstm[5] */ -1,
    /* firstm[6] */ -1,
    /* firstm[7] */ -1,
    /* firstm[8] */ -1,
    /* firstm[9] */ -1,
    /* firstm[10] */ -1,
    /* firstm[11] */ -1,
    /* firstm[12] */ -1,
    /* firstm[13] */ -1,
    /* firstm[14] */ -1,
    /* firstm[15] */ -1,
    /* firstm[16] */ -1,
    /* firstm[17] */ -1,
    /* firstm[18] */ -1,
    /* firstm[19] */ -1,
    /* firstm[20] */ -1,
    /* firstp[0] */ 0,
    /* firstp[1] */ 6,
    /* firstp[2] */ 7,
    /* firstp[3] */ 8,
    /* firstp[4] */ 9,
    /* firstp[5] */ -1,
    /* firstp[6] */ 10,
    /* firstp[7] */ 11,
    /* firstp[8] */ 12,
    /* firstp[9] */ 13,
    /* firstp[10] */ -1,
    /* firstp[11] */ 14,
    /* firstp[12] */ 15,
    /* firstp[13] */ 16,
    /* firstp[14] */ 17,
    /* firstp[15] */ -1,
    /* firstp[16] */ 18,
    /* firstp[17] */ 19,
    /* firstp[18] */ 20,
    /* firstp[19] */ 21,
    /* firstp[20] */ -1,
    /* trans[0] */ 1,
    /* trans[1] */ 1,
    /* trans[2] */ 1,
    /* trans[3] */ 0,
    /* trans[4] */ 0,
    /* trans[5] */ 0,
    /* trans[6] */ 0,
    /* trans[7] */ 0,
    /* trans[8] */ 0,
    /* trans[9] */ 0,
    /* trans[10] */ 0,
    /* trans[11] */ 0,
    /* trans[12] */ 0,
    /* trans[13] */ 0,
    /* trans[14] */ 0,
    /* trans[15] */ 0,
    /* trans[16] */ 0,
    /* trans[17] */ 0,
    /* trans[18] */ 0,
    /* trans[19] */ 0,
    /* trans[20] */ 0,
    /* trans[21] */ 0,
};
allegro_air_ginput_t allegro_air_ginput = {
/* Model parameters from the input file */

/* gravity */
    /* grav[0] */ 0.,
    /* grav[1] */ 0.,
    /* grav[2] */ -9.81,

/* mass */
    /* mk[0] */ .4154,
    /* mk[1] */ .0119,
    /* mk[2] */ .065,
    /* mk[3] */ .0355,
    /* mk[4] */ .0096,
    /* mk[5] */ .0168,
    /* mk[6] */ .0176,
    /* mk[7] */ .0119,
    /* mk[8] */ .038,
    /* mk[9] */ .0388,
    /* mk[10] */ .0168,
    /* mk[11] */ .0119,
    /* mk[12] */ .065,
    /* mk[13] */ .0355,
    /* mk[14] */ .0096,
    /* mk[15] */ .0168,
    /* mk[16] */ .0119,
    /* mk[17] */ .065,
    /* mk[18] */ .0355,
    /* mk[19] */ .0096,
    /* mk[20] */ .0168,

/* inertia */
    /* ik[0][0][0] */ .001037,
    /* ik[0][0][1] */ 0.,
    /* ik[0][0][2] */ 0.,
    /* ik[0][1][0] */ 0.,
    /* ik[0][1][1] */ .001037,
    /* ik[0][1][2] */ 0.,
    /* ik[0][2][0] */ 0.,
    /* ik[0][2][1] */ 0.,
    /* ik[0][2][2] */ .0001,
    /* ik[1][0][0] */ 1e-6,
    /* ik[1][0][1] */ 0.,
    /* ik[1][0][2] */ 0.,
    /* ik[1][1][0] */ 0.,
    /* ik[1][1][1] */ 1e-6,
    /* ik[1][1][2] */ 0.,
    /* ik[1][2][0] */ 0.,
    /* ik[1][2][1] */ 0.,
    /* ik[1][2][2] */ 1e-6,
    /* ik[2][0][0] */ 8e-5,
    /* ik[2][0][1] */ 2.3e-5,
    /* ik[2][0][2] */ -1.1e-5,
    /* ik[2][1][0] */ 2.3e-5,
    /* ik[2][1][1] */ 2.2e-5,
    /* ik[2][1][2] */ -1.2e-5,
    /* ik[2][2][0] */ -1.1e-5,
    /* ik[2][2][1] */ -1.2e-5,
    /* ik[2][2][2] */ 8.2e-5,
    /* ik[3][0][0] */ 2.6e-5,
    /* ik[3][0][1] */ 9e-6,
    /* ik[3][0][2] */ -6e-6,
    /* ik[3][1][0] */ 9e-6,
    /* ik[3][1][1] */ 1.2e-5,
    /* ik[3][1][2] */ -5e-6,
    /* ik[3][2][0] */ -6e-6,
    /* ik[3][2][1] */ -5e-6,
    /* ik[3][2][2] */ 2.7e-5,
    /* ik[4][0][0] */ 5e-6,
    /* ik[4][0][1] */ 2e-6,
    /* ik[4][0][2] */ -1e-6,
    /* ik[4][1][0] */ 2e-6,
    /* ik[4][1][1] */ 3e-6,
    /* ik[4][1][2] */ -1e-6,
    /* ik[4][2][0] */ -1e-6,
    /* ik[4][2][1] */ -1e-6,
    /* ik[4][2][2] */ 5e-6,
    /* ik[5][0][0] */ 1e-6,
    /* ik[5][0][1] */ 0.,
    /* ik[5][0][2] */ 0.,
    /* ik[5][1][0] */ 0.,
    /* ik[5][1][1] */ 1e-6,
    /* ik[5][1][2] */ 0.,
    /* ik[5][2][0] */ 0.,
    /* ik[5][2][1] */ 0.,
    /* ik[5][2][2] */ 1e-6,
    /* ik[6][0][0] */ 1.4e-5,
    /* ik[6][0][1] */ 8e-6,
    /* ik[6][0][2] */ 6e-6,
    /* ik[6][1][0] */ 8e-6,
    /* ik[6][1][1] */ 2e-5,
    /* ik[6][1][2] */ 5e-6,
    /* ik[6][2][0] */ 6e-6,
    /* ik[6][2][1] */ 5e-6,
    /* ik[6][2][2] */ 1.8e-5,
    /* ik[7][0][0] */ 5e-6,
    /* ik[7][0][1] */ 1e-6,
    /* ik[7][0][2] */ 1e-6,
    /* ik[7][1][0] */ 1e-6,
    /* ik[7][1][1] */ 5e-6,
    /* ik[7][1][2] */ 2e-6,
    /* ik[7][2][0] */ 1e-6,
    /* ik[7][2][1] */ 2e-6,
    /* ik[7][2][2] */ 4e-6,
    /* ik[8][0][0] */ 1.4e-5,
    /* ik[8][0][1] */ 1.1e-5,
    /* ik[8][0][2] */ 1.3e-5,
    /* ik[8][1][0] */ 1.1e-5,
    /* ik[8][1][1] */ 4.4e-5,
    /* ik[8][1][2] */ 5e-6,
    /* ik[8][2][0] */ 1.3e-5,
    /* ik[8][2][1] */ 5e-6,
    /* ik[8][2][2] */ 4.2e-5,
    /* ik[9][0][0] */ 1.5e-5,
    /* ik[9][0][1] */ 9e-6,
    /* ik[9][0][2] */ 1.1e-5,
    /* ik[9][1][0] */ 9e-6,
    /* ik[9][1][1] */ 3.4e-5,
    /* ik[9][1][2] */ 5e-6,
    /* ik[9][2][0] */ 1.1e-5,
    /* ik[9][2][1] */ 5e-6,
    /* ik[9][2][2] */ 3.2e-5,
    /* ik[10][0][0] */ 1e-6,
    /* ik[10][0][1] */ 0.,
    /* ik[10][0][2] */ 0.,
    /* ik[10][1][0] */ 0.,
    /* ik[10][1][1] */ 1e-6,
    /* ik[10][1][2] */ 0.,
    /* ik[10][2][0] */ 0.,
    /* ik[10][2][1] */ 0.,
    /* ik[10][2][2] */ 1e-6,
    /* ik[11][0][0] */ 1e-6,
    /* ik[11][0][1] */ 0.,
    /* ik[11][0][2] */ 0.,
    /* ik[11][1][0] */ 0.,
    /* ik[11][1][1] */ 1e-6,
    /* ik[11][1][2] */ 0.,
    /* ik[11][2][0] */ 0.,
    /* ik[11][2][1] */ 0.,
    /* ik[11][2][2] */ 1e-6,
    /* ik[12][0][0] */ 8e-5,
    /* ik[12][0][1] */ 2.4e-5,
    /* ik[12][0][2] */ -9e-6,
    /* ik[12][1][0] */ 2.4e-5,
    /* ik[12][1][1] */ 2.5e-5,
    /* ik[12][1][2] */ -1.7e-5,
    /* ik[12][2][0] */ -9e-6,
    /* ik[12][2][1] */ -1.7e-5,
    /* ik[12][2][2] */ 8e-5,
    /* ik[13][0][0] */ 2.6e-5,
    /* ik[13][0][1] */ 9e-6,
    /* ik[13][0][2] */ -5e-6,
    /* ik[13][1][0] */ 9e-6,
    /* ik[13][1][1] */ 1.3e-5,
    /* ik[13][1][2] */ -7e-6,
    /* ik[13][2][0] */ -5e-6,
    /* ik[13][2][1] */ -7e-6,
    /* ik[13][2][2] */ 2.6e-5,
    /* ik[14][0][0] */ 5e-6,
    /* ik[14][0][1] */ 2e-6,
    /* ik[14][0][2] */ -1e-6,
    /* ik[14][1][0] */ 2e-6,
    /* ik[14][1][1] */ 4e-6,
    /* ik[14][1][2] */ -1e-6,
    /* ik[14][2][0] */ -1e-6,
    /* ik[14][2][1] */ -1e-6,
    /* ik[14][2][2] */ 5e-6,
    /* ik[15][0][0] */ 1e-6,
    /* ik[15][0][1] */ 0.,
    /* ik[15][0][2] */ 0.,
    /* ik[15][1][0] */ 0.,
    /* ik[15][1][1] */ 1e-6,
    /* ik[15][1][2] */ 0.,
    /* ik[15][2][0] */ 0.,
    /* ik[15][2][1] */ 0.,
    /* ik[15][2][2] */ 1e-6,
    /* ik[16][0][0] */ 1e-6,
    /* ik[16][0][1] */ 0.,
    /* ik[16][0][2] */ 0.,
    /* ik[16][1][0] */ 0.,
    /* ik[16][1][1] */ 1e-6,
    /* ik[16][1][2] */ 0.,
    /* ik[16][2][0] */ 0.,
    /* ik[16][2][1] */ 0.,
    /* ik[16][2][2] */ 1e-6,
    /* ik[17][0][0] */ 8e-5,
    /* ik[17][0][1] */ 2.5e-5,
    /* ik[17][0][2] */ -7e-6,
    /* ik[17][1][0] */ 2.5e-5,
    /* ik[17][1][1] */ 2.8e-5,
    /* ik[17][1][2] */ -2.2e-5,
    /* ik[17][2][0] */ -7e-6,
    /* ik[17][2][1] */ -2.2e-5,
    /* ik[17][2][2] */ 7.6e-5,
    /* ik[18][0][0] */ 2.6e-5,
    /* ik[18][0][1] */ 1e-5,
    /* ik[18][0][2] */ -4e-6,
    /* ik[18][1][0] */ 1e-5,
    /* ik[18][1][1] */ 1.5e-5,
    /* ik[18][1][2] */ -8e-6,
    /* ik[18][2][0] */ -4e-6,
    /* ik[18][2][1] */ -8e-6,
    /* ik[18][2][2] */ 2.5e-5,
    /* ik[19][0][0] */ 5e-6,
    /* ik[19][0][1] */ 2e-6,
    /* ik[19][0][2] */ -1e-6,
    /* ik[19][1][0] */ 2e-6,
    /* ik[19][1][1] */ 4e-6,
    /* ik[19][1][2] */ -1e-6,
    /* ik[19][2][0] */ -1e-6,
    /* ik[19][2][1] */ -1e-6,
    /* ik[19][2][2] */ 4e-6,
    /* ik[20][0][0] */ 1e-6,
    /* ik[20][0][1] */ 0.,
    /* ik[20][0][2] */ 0.,
    /* ik[20][1][0] */ 0.,
    /* ik[20][1][1] */ 1e-6,
    /* ik[20][1][2] */ 0.,
    /* ik[20][2][0] */ 0.,
    /* ik[20][2][1] */ 0.,
    /* ik[20][2][2] */ 1e-6,

/* tree hinge axis vectors */
    /* pin[0][0] */ 1.,
    /* pin[0][1] */ 0.,
    /* pin[0][2] */ 0.,
    /* pin[1][0] */ 0.,
    /* pin[1][1] */ 1.,
    /* pin[1][2] */ 0.,
    /* pin[2][0] */ 0.,
    /* pin[2][1] */ 0.,
    /* pin[2][2] */ 1.,
    /* pin[3][0] */ 0.,
    /* pin[3][1] */ 0.,
    /* pin[3][2] */ 0.,
    /* pin[4][0] */ 0.,
    /* pin[4][1] */ 0.,
    /* pin[4][2] */ 0.,
    /* pin[5][0] */ 0.,
    /* pin[5][1] */ 0.,
    /* pin[5][2] */ 0.,
    /* pin[6][0] */ 0.,
    /* pin[6][1] */ .087156,
    /* pin[6][2] */ .996195,
    /* pin[7][0] */ 0.,
    /* pin[7][1] */ -.996195,
    /* pin[7][2] */ .087156,
    /* pin[8][0] */ 0.,
    /* pin[8][1] */ -.996195,
    /* pin[8][2] */ .087156,
    /* pin[9][0] */ 0.,
    /* pin[9][1] */ -.996195,
    /* pin[9][2] */ .087156,
    /* pin[10][0] */ 0.,
    /* pin[10][1] */ .087156,
    /* pin[10][2] */ .996195,
    /* pin[11][0] */ 0.,
    /* pin[11][1] */ -.996195,
    /* pin[11][2] */ .087156,
    /* pin[12][0] */ 1.,
    /* pin[12][1] */ 0.,
    /* pin[12][2] */ 0.,
    /* pin[13][0] */ 1.,
    /* pin[13][1] */ 0.,
    /* pin[13][2] */ 0.,
    /* pin[14][0] */ 0.,
    /* pin[14][1] */ 0.,
    /* pin[14][2] */ 1.,
    /* pin[15][0] */ 0.,
    /* pin[15][1] */ -1.,
    /* pin[15][2] */ 0.,
    /* pin[16][0] */ 0.,
    /* pin[16][1] */ -1.,
    /* pin[16][2] */ 0.,
    /* pin[17][0] */ 0.,
    /* pin[17][1] */ -1.,
    /* pin[17][2] */ 0.,
    /* pin[18][0] */ 0.,
    /* pin[18][1] */ -.087156,
    /* pin[18][2] */ .996195,
    /* pin[19][0] */ 0.,
    /* pin[19][1] */ -.996195,
    /* pin[19][2] */ -.087156,
    /* pin[20][0] */ 0.,
    /* pin[20][1] */ -.996195,
    /* pin[20][2] */ -.087156,
    /* pin[21][0] */ 0.,
    /* pin[21][1] */ -.996195,
    /* pin[21][2] */ -.087156,

/* tree bodytojoint vectors */
    /* rk[0][0] */ 0.,
    /* rk[0][1] */ 0.,
    /* rk[0][2] */ -.0475,
    /* rk[1][0] */ 0.,
    /* rk[1][1] */ 0.,
    /* rk[1][2] */ 0.,
    /* rk[2][0] */ 0.,
    /* rk[2][1] */ 0.,
    /* rk[2][2] */ 0.,
    /* rk[3][0] */ 0.,
    /* rk[3][1] */ 0.,
    /* rk[3][2] */ 0.,
    /* rk[4][0] */ 0.,
    /* rk[4][1] */ 0.,
    /* rk[4][2] */ 0.,
    /* rk[5][0] */ 0.,
    /* rk[5][1] */ 0.,
    /* rk[5][2] */ 0.,
    /* rk[6][0] */ 0.,
    /* rk[6][1] */ 0.,
    /* rk[6][2] */ 0.,
    /* rk[7][0] */ 0.,
    /* rk[7][1] */ 0.,
    /* rk[7][2] */ 0.,
    /* rk[8][0] */ 0.,
    /* rk[8][1] */ 0.,
    /* rk[8][2] */ 0.,
    /* rk[9][0] */ 0.,
    /* rk[9][1] */ 0.,
    /* rk[9][2] */ 0.,
    /* rk[10][0] */ 0.,
    /* rk[10][1] */ 0.,
    /* rk[10][2] */ 0.,
    /* rk[11][0] */ 0.,
    /* rk[11][1] */ 0.,
    /* rk[11][2] */ 0.,
    /* rk[12][0] */ 0.,
    /* rk[12][1] */ 0.,
    /* rk[12][2] */ 0.,
    /* rk[13][0] */ 0.,
    /* rk[13][1] */ 0.,
    /* rk[13][2] */ 0.,
    /* rk[14][0] */ 0.,
    /* rk[14][1] */ 0.,
    /* rk[14][2] */ 0.,
    /* rk[15][0] */ 0.,
    /* rk[15][1] */ 0.,
    /* rk[15][2] */ 0.,
    /* rk[16][0] */ 0.,
    /* rk[16][1] */ 0.,
    /* rk[16][2] */ 0.,
    /* rk[17][0] */ 0.,
    /* rk[17][1] */ 0.,
    /* rk[17][2] */ 0.,
    /* rk[18][0] */ 0.,
    /* rk[18][1] */ 0.,
    /* rk[18][2] */ 0.,
    /* rk[19][0] */ 0.,
    /* rk[19][1] */ 0.,
    /* rk[19][2] */ 0.,
    /* rk[20][0] */ 0.,
    /* rk[20][1] */ 0.,
    /* rk[20][2] */ 0.,

/* tree inbtojoint vectors */
    /* ri[0][0] */ 0.,
    /* ri[0][1] */ 0.,
    /* ri[0][2] */ .095,
    /* ri[1][0] */ 0.,
    /* ri[1][1] */ .0435,
    /* ri[1][2] */ -.049042,
    /* ri[2][0] */ 0.,
    /* ri[2][1] */ .001429,
    /* ri[2][2] */ .016338,
    /* ri[3][0] */ 0.,
    /* ri[3][1] */ .004706,
    /* ri[3][2] */ .053795,
    /* ri[4][0] */ 0.,
    /* ri[4][1] */ .003347,
    /* ri[4][2] */ .038254,
    /* ri[5][0] */ 0.,
    /* ri[5][1] */ .002327,
    /* ri[5][2] */ .026598,
    /* ri[6][0] */ .0182,
    /* ri[6][1] */ .019333,
    /* ri[6][2] */ -.093487,
    /* ri[7][0] */ -.005,
    /* ri[7][1] */ .037395,
    /* ri[7][2] */ -.030375,
    /* ri[8][0] */ 0.,
    /* ri[8][1] */ .017633,
    /* ri[8][2] */ -.001543,
    /* ri[9][0] */ 0.,
    /* ri[9][1] */ .051204,
    /* ri[9][2] */ -.00448,
    /* ri[10][0] */ 0.,
    /* ri[10][1] */ .042139,
    /* ri[10][2] */ -.003687,
    /* ri[11][0] */ 0.,
    /* ri[11][1] */ 0.,
    /* ri[11][2] */ -.0468,
    /* ri[12][0] */ 0.,
    /* ri[12][1] */ 0.,
    /* ri[12][2] */ .0164,
    /* ri[13][0] */ 0.,
    /* ri[13][1] */ 0.,
    /* ri[13][2] */ .054,
    /* ri[14][0] */ 0.,
    /* ri[14][1] */ 0.,
    /* ri[14][2] */ .0384,
    /* ri[15][0] */ 0.,
    /* ri[15][1] */ 0.,
    /* ri[15][2] */ .0267,
    /* ri[16][0] */ 0.,
    /* ri[16][1] */ -.0435,
    /* ri[16][2] */ -.049042,
    /* ri[17][0] */ 0.,
    /* ri[17][1] */ -.001429,
    /* ri[17][2] */ .016338,
    /* ri[18][0] */ 0.,
    /* ri[18][1] */ -.004706,
    /* ri[18][2] */ .053795,
    /* ri[19][0] */ 0.,
    /* ri[19][1] */ -.003347,
    /* ri[19][2] */ .038254,
    /* ri[20][0] */ 0.,
    /* ri[20][1] */ -.002327,
    /* ri[20][2] */ .026598,

/* tree prescribed motion */
    /* pres[0] */ 0.,
    /* pres[1] */ 0.,
    /* pres[2] */ 0.,
    /* pres[3] */ 0.,
    /* pres[4] */ 0.,
    /* pres[5] */ 0.,
    /* pres[6] */ 0.,
    /* pres[7] */ 0.,
    /* pres[8] */ 0.,
    /* pres[9] */ 0.,
    /* pres[10] */ 0.,
    /* pres[11] */ 0.,
    /* pres[12] */ 0.,
    /* pres[13] */ 0.,
    /* pres[14] */ 0.,
    /* pres[15] */ 0.,
    /* pres[16] */ 0.,
    /* pres[17] */ 0.,
    /* pres[18] */ 0.,
    /* pres[19] */ 0.,
    /* pres[20] */ 0.,
    /* pres[21] */ 0.,

/* stabilization parameters */
    /* stabvel */ 0.,
    /* stabpos */ 0.,

/* miscellaneous */
    /* mfrcflg */ 0,
    /* roustate */ 0,
    /* vpkflg */ 0,
    /* inerflg */ 0,
    /* mmflg */ 0,
    /* mmlduflg */ 0,
    /* wwflg */ 0,
    /* ltauflg */ 0,
    /* fs0flg */ 0,
    /* ii */ 0,
    /* mmap[0] */ 0,
    /* mmap[1] */ 1,
    /* mmap[2] */ 2,
    /* mmap[3] */ 3,
    /* mmap[4] */ 4,
    /* mmap[5] */ 5,
    /* mmap[6] */ 6,
    /* mmap[7] */ 7,
    /* mmap[8] */ 8,
    /* mmap[9] */ 9,
    /* mmap[10] */ 10,
    /* mmap[11] */ 11,
    /* mmap[12] */ 12,
    /* mmap[13] */ 13,
    /* mmap[14] */ 14,
    /* mmap[15] */ 15,
    /* mmap[16] */ 16,
    /* mmap[17] */ 17,
    /* mmap[18] */ 18,
    /* mmap[19] */ 19,
    /* mmap[20] */ 20,
    /* mmap[21] */ 21,

/* Which parameters were "?" (1) or "<nominal>?" (3) */
    /* gravq[0] */ 3,
    /* gravq[1] */ 3,
    /* gravq[2] */ 3,
    /* mkq[0] */ 3,
    /* mkq[1] */ 3,
    /* mkq[2] */ 3,
    /* mkq[3] */ 3,
    /* mkq[4] */ 3,
    /* mkq[5] */ 3,
    /* mkq[6] */ 3,
    /* mkq[7] */ 3,
    /* mkq[8] */ 3,
    /* mkq[9] */ 3,
    /* mkq[10] */ 3,
    /* mkq[11] */ 3,
    /* mkq[12] */ 3,
    /* mkq[13] */ 3,
    /* mkq[14] */ 3,
    /* mkq[15] */ 3,
    /* mkq[16] */ 3,
    /* mkq[17] */ 3,
    /* mkq[18] */ 3,
    /* mkq[19] */ 3,
    /* mkq[20] */ 3,
    /* ikq[0][0][0] */ 3,
    /* ikq[0][0][1] */ 3,
    /* ikq[0][0][2] */ 3,
    /* ikq[0][1][0] */ 3,
    /* ikq[0][1][1] */ 3,
    /* ikq[0][1][2] */ 3,
    /* ikq[0][2][0] */ 3,
    /* ikq[0][2][1] */ 3,
    /* ikq[0][2][2] */ 3,
    /* ikq[1][0][0] */ 3,
    /* ikq[1][0][1] */ 3,
    /* ikq[1][0][2] */ 3,
    /* ikq[1][1][0] */ 3,
    /* ikq[1][1][1] */ 3,
    /* ikq[1][1][2] */ 3,
    /* ikq[1][2][0] */ 3,
    /* ikq[1][2][1] */ 3,
    /* ikq[1][2][2] */ 3,
    /* ikq[2][0][0] */ 3,
    /* ikq[2][0][1] */ 3,
    /* ikq[2][0][2] */ 3,
    /* ikq[2][1][0] */ 3,
    /* ikq[2][1][1] */ 3,
    /* ikq[2][1][2] */ 3,
    /* ikq[2][2][0] */ 3,
    /* ikq[2][2][1] */ 3,
    /* ikq[2][2][2] */ 3,
    /* ikq[3][0][0] */ 3,
    /* ikq[3][0][1] */ 3,
    /* ikq[3][0][2] */ 3,
    /* ikq[3][1][0] */ 3,
    /* ikq[3][1][1] */ 3,
    /* ikq[3][1][2] */ 3,
    /* ikq[3][2][0] */ 3,
    /* ikq[3][2][1] */ 3,
    /* ikq[3][2][2] */ 3,
    /* ikq[4][0][0] */ 3,
    /* ikq[4][0][1] */ 3,
    /* ikq[4][0][2] */ 3,
    /* ikq[4][1][0] */ 3,
    /* ikq[4][1][1] */ 3,
    /* ikq[4][1][2] */ 3,
    /* ikq[4][2][0] */ 3,
    /* ikq[4][2][1] */ 3,
    /* ikq[4][2][2] */ 3,
    /* ikq[5][0][0] */ 3,
    /* ikq[5][0][1] */ 3,
    /* ikq[5][0][2] */ 3,
    /* ikq[5][1][0] */ 3,
    /* ikq[5][1][1] */ 3,
    /* ikq[5][1][2] */ 3,
    /* ikq[5][2][0] */ 3,
    /* ikq[5][2][1] */ 3,
    /* ikq[5][2][2] */ 3,
    /* ikq[6][0][0] */ 3,
    /* ikq[6][0][1] */ 3,
    /* ikq[6][0][2] */ 3,
    /* ikq[6][1][0] */ 3,
    /* ikq[6][1][1] */ 3,
    /* ikq[6][1][2] */ 3,
    /* ikq[6][2][0] */ 3,
    /* ikq[6][2][1] */ 3,
    /* ikq[6][2][2] */ 3,
    /* ikq[7][0][0] */ 3,
    /* ikq[7][0][1] */ 3,
    /* ikq[7][0][2] */ 3,
    /* ikq[7][1][0] */ 3,
    /* ikq[7][1][1] */ 3,
    /* ikq[7][1][2] */ 3,
    /* ikq[7][2][0] */ 3,
    /* ikq[7][2][1] */ 3,
    /* ikq[7][2][2] */ 3,
    /* ikq[8][0][0] */ 3,
    /* ikq[8][0][1] */ 3,
    /* ikq[8][0][2] */ 3,
    /* ikq[8][1][0] */ 3,
    /* ikq[8][1][1] */ 3,
    /* ikq[8][1][2] */ 3,
    /* ikq[8][2][0] */ 3,
    /* ikq[8][2][1] */ 3,
    /* ikq[8][2][2] */ 3,
    /* ikq[9][0][0] */ 3,
    /* ikq[9][0][1] */ 3,
    /* ikq[9][0][2] */ 3,
    /* ikq[9][1][0] */ 3,
    /* ikq[9][1][1] */ 3,
    /* ikq[9][1][2] */ 3,
    /* ikq[9][2][0] */ 3,
    /* ikq[9][2][1] */ 3,
    /* ikq[9][2][2] */ 3,
    /* ikq[10][0][0] */ 3,
    /* ikq[10][0][1] */ 3,
    /* ikq[10][0][2] */ 3,
    /* ikq[10][1][0] */ 3,
    /* ikq[10][1][1] */ 3,
    /* ikq[10][1][2] */ 3,
    /* ikq[10][2][0] */ 3,
    /* ikq[10][2][1] */ 3,
    /* ikq[10][2][2] */ 3,
    /* ikq[11][0][0] */ 3,
    /* ikq[11][0][1] */ 3,
    /* ikq[11][0][2] */ 3,
    /* ikq[11][1][0] */ 3,
    /* ikq[11][1][1] */ 3,
    /* ikq[11][1][2] */ 3,
    /* ikq[11][2][0] */ 3,
    /* ikq[11][2][1] */ 3,
    /* ikq[11][2][2] */ 3,
    /* ikq[12][0][0] */ 3,
    /* ikq[12][0][1] */ 3,
    /* ikq[12][0][2] */ 3,
    /* ikq[12][1][0] */ 3,
    /* ikq[12][1][1] */ 3,
    /* ikq[12][1][2] */ 3,
    /* ikq[12][2][0] */ 3,
    /* ikq[12][2][1] */ 3,
    /* ikq[12][2][2] */ 3,
    /* ikq[13][0][0] */ 3,
    /* ikq[13][0][1] */ 3,
    /* ikq[13][0][2] */ 3,
    /* ikq[13][1][0] */ 3,
    /* ikq[13][1][1] */ 3,
    /* ikq[13][1][2] */ 3,
    /* ikq[13][2][0] */ 3,
    /* ikq[13][2][1] */ 3,
    /* ikq[13][2][2] */ 3,
    /* ikq[14][0][0] */ 3,
    /* ikq[14][0][1] */ 3,
    /* ikq[14][0][2] */ 3,
    /* ikq[14][1][0] */ 3,
    /* ikq[14][1][1] */ 3,
    /* ikq[14][1][2] */ 3,
    /* ikq[14][2][0] */ 3,
    /* ikq[14][2][1] */ 3,
    /* ikq[14][2][2] */ 3,
    /* ikq[15][0][0] */ 3,
    /* ikq[15][0][1] */ 3,
    /* ikq[15][0][2] */ 3,
    /* ikq[15][1][0] */ 3,
    /* ikq[15][1][1] */ 3,
    /* ikq[15][1][2] */ 3,
    /* ikq[15][2][0] */ 3,
    /* ikq[15][2][1] */ 3,
    /* ikq[15][2][2] */ 3,
    /* ikq[16][0][0] */ 3,
    /* ikq[16][0][1] */ 3,
    /* ikq[16][0][2] */ 3,
    /* ikq[16][1][0] */ 3,
    /* ikq[16][1][1] */ 3,
    /* ikq[16][1][2] */ 3,
    /* ikq[16][2][0] */ 3,
    /* ikq[16][2][1] */ 3,
    /* ikq[16][2][2] */ 3,
    /* ikq[17][0][0] */ 3,
    /* ikq[17][0][1] */ 3,
    /* ikq[17][0][2] */ 3,
    /* ikq[17][1][0] */ 3,
    /* ikq[17][1][1] */ 3,
    /* ikq[17][1][2] */ 3,
    /* ikq[17][2][0] */ 3,
    /* ikq[17][2][1] */ 3,
    /* ikq[17][2][2] */ 3,
    /* ikq[18][0][0] */ 3,
    /* ikq[18][0][1] */ 3,
    /* ikq[18][0][2] */ 3,
    /* ikq[18][1][0] */ 3,
    /* ikq[18][1][1] */ 3,
    /* ikq[18][1][2] */ 3,
    /* ikq[18][2][0] */ 3,
    /* ikq[18][2][1] */ 3,
    /* ikq[18][2][2] */ 3,
    /* ikq[19][0][0] */ 3,
    /* ikq[19][0][1] */ 3,
    /* ikq[19][0][2] */ 3,
    /* ikq[19][1][0] */ 3,
    /* ikq[19][1][1] */ 3,
    /* ikq[19][1][2] */ 3,
    /* ikq[19][2][0] */ 3,
    /* ikq[19][2][1] */ 3,
    /* ikq[19][2][2] */ 3,
    /* ikq[20][0][0] */ 3,
    /* ikq[20][0][1] */ 3,
    /* ikq[20][0][2] */ 3,
    /* ikq[20][1][0] */ 3,
    /* ikq[20][1][1] */ 3,
    /* ikq[20][1][2] */ 3,
    /* ikq[20][2][0] */ 3,
    /* ikq[20][2][1] */ 3,
    /* ikq[20][2][2] */ 3,
    /* pinq[0][0] */ 3,
    /* pinq[0][1] */ 3,
    /* pinq[0][2] */ 3,
    /* pinq[1][0] */ 3,
    /* pinq[1][1] */ 3,
    /* pinq[1][2] */ 3,
    /* pinq[2][0] */ 3,
    /* pinq[2][1] */ 3,
    /* pinq[2][2] */ 3,
    /* pinq[3][0] */ 0,
    /* pinq[3][1] */ 0,
    /* pinq[3][2] */ 0,
    /* pinq[4][0] */ 0,
    /* pinq[4][1] */ 0,
    /* pinq[4][2] */ 0,
    /* pinq[5][0] */ 0,
    /* pinq[5][1] */ 0,
    /* pinq[5][2] */ 0,
    /* pinq[6][0] */ 3,
    /* pinq[6][1] */ 3,
    /* pinq[6][2] */ 3,
    /* pinq[7][0] */ 3,
    /* pinq[7][1] */ 3,
    /* pinq[7][2] */ 3,
    /* pinq[8][0] */ 3,
    /* pinq[8][1] */ 3,
    /* pinq[8][2] */ 3,
    /* pinq[9][0] */ 3,
    /* pinq[9][1] */ 3,
    /* pinq[9][2] */ 3,
    /* pinq[10][0] */ 3,
    /* pinq[10][1] */ 3,
    /* pinq[10][2] */ 3,
    /* pinq[11][0] */ 3,
    /* pinq[11][1] */ 3,
    /* pinq[11][2] */ 3,
    /* pinq[12][0] */ 3,
    /* pinq[12][1] */ 3,
    /* pinq[12][2] */ 3,
    /* pinq[13][0] */ 3,
    /* pinq[13][1] */ 3,
    /* pinq[13][2] */ 3,
    /* pinq[14][0] */ 3,
    /* pinq[14][1] */ 3,
    /* pinq[14][2] */ 3,
    /* pinq[15][0] */ 3,
    /* pinq[15][1] */ 3,
    /* pinq[15][2] */ 3,
    /* pinq[16][0] */ 3,
    /* pinq[16][1] */ 3,
    /* pinq[16][2] */ 3,
    /* pinq[17][0] */ 3,
    /* pinq[17][1] */ 3,
    /* pinq[17][2] */ 3,
    /* pinq[18][0] */ 3,
    /* pinq[18][1] */ 3,
    /* pinq[18][2] */ 3,
    /* pinq[19][0] */ 3,
    /* pinq[19][1] */ 3,
    /* pinq[19][2] */ 3,
    /* pinq[20][0] */ 3,
    /* pinq[20][1] */ 3,
    /* pinq[20][2] */ 3,
    /* pinq[21][0] */ 3,
    /* pinq[21][1] */ 3,
    /* pinq[21][2] */ 3,
    /* rkq[0][0] */ 3,
    /* rkq[0][1] */ 3,
    /* rkq[0][2] */ 3,
    /* rkq[1][0] */ 3,
    /* rkq[1][1] */ 3,
    /* rkq[1][2] */ 3,
    /* rkq[2][0] */ 3,
    /* rkq[2][1] */ 3,
    /* rkq[2][2] */ 3,
    /* rkq[3][0] */ 3,
    /* rkq[3][1] */ 3,
    /* rkq[3][2] */ 3,
    /* rkq[4][0] */ 3,
    /* rkq[4][1] */ 3,
    /* rkq[4][2] */ 3,
    /* rkq[5][0] */ 3,
    /* rkq[5][1] */ 3,
    /* rkq[5][2] */ 3,
    /* rkq[6][0] */ 3,
    /* rkq[6][1] */ 3,
    /* rkq[6][2] */ 3,
    /* rkq[7][0] */ 3,
    /* rkq[7][1] */ 3,
    /* rkq[7][2] */ 3,
    /* rkq[8][0] */ 3,
    /* rkq[8][1] */ 3,
    /* rkq[8][2] */ 3,
    /* rkq[9][0] */ 3,
    /* rkq[9][1] */ 3,
    /* rkq[9][2] */ 3,
    /* rkq[10][0] */ 3,
    /* rkq[10][1] */ 3,
    /* rkq[10][2] */ 3,
    /* rkq[11][0] */ 3,
    /* rkq[11][1] */ 3,
    /* rkq[11][2] */ 3,
    /* rkq[12][0] */ 3,
    /* rkq[12][1] */ 3,
    /* rkq[12][2] */ 3,
    /* rkq[13][0] */ 3,
    /* rkq[13][1] */ 3,
    /* rkq[13][2] */ 3,
    /* rkq[14][0] */ 3,
    /* rkq[14][1] */ 3,
    /* rkq[14][2] */ 3,
    /* rkq[15][0] */ 3,
    /* rkq[15][1] */ 3,
    /* rkq[15][2] */ 3,
    /* rkq[16][0] */ 3,
    /* rkq[16][1] */ 3,
    /* rkq[16][2] */ 3,
    /* rkq[17][0] */ 3,
    /* rkq[17][1] */ 3,
    /* rkq[17][2] */ 3,
    /* rkq[18][0] */ 3,
    /* rkq[18][1] */ 3,
    /* rkq[18][2] */ 3,
    /* rkq[19][0] */ 3,
    /* rkq[19][1] */ 3,
    /* rkq[19][2] */ 3,
    /* rkq[20][0] */ 3,
    /* rkq[20][1] */ 3,
    /* rkq[20][2] */ 3,
    /* riq[0][0] */ 3,
    /* riq[0][1] */ 3,
    /* riq[0][2] */ 3,
    /* riq[1][0] */ 3,
    /* riq[1][1] */ 3,
    /* riq[1][2] */ 3,
    /* riq[2][0] */ 3,
    /* riq[2][1] */ 3,
    /* riq[2][2] */ 3,
    /* riq[3][0] */ 3,
    /* riq[3][1] */ 3,
    /* riq[3][2] */ 3,
    /* riq[4][0] */ 3,
    /* riq[4][1] */ 3,
    /* riq[4][2] */ 3,
    /* riq[5][0] */ 3,
    /* riq[5][1] */ 3,
    /* riq[5][2] */ 3,
    /* riq[6][0] */ 3,
    /* riq[6][1] */ 3,
    /* riq[6][2] */ 3,
    /* riq[7][0] */ 3,
    /* riq[7][1] */ 3,
    /* riq[7][2] */ 3,
    /* riq[8][0] */ 3,
    /* riq[8][1] */ 3,
    /* riq[8][2] */ 3,
    /* riq[9][0] */ 3,
    /* riq[9][1] */ 3,
    /* riq[9][2] */ 3,
    /* riq[10][0] */ 3,
    /* riq[10][1] */ 3,
    /* riq[10][2] */ 3,
    /* riq[11][0] */ 3,
    /* riq[11][1] */ 3,
    /* riq[11][2] */ 3,
    /* riq[12][0] */ 3,
    /* riq[12][1] */ 3,
    /* riq[12][2] */ 3,
    /* riq[13][0] */ 3,
    /* riq[13][1] */ 3,
    /* riq[13][2] */ 3,
    /* riq[14][0] */ 3,
    /* riq[14][1] */ 3,
    /* riq[14][2] */ 3,
    /* riq[15][0] */ 3,
    /* riq[15][1] */ 3,
    /* riq[15][2] */ 3,
    /* riq[16][0] */ 3,
    /* riq[16][1] */ 3,
    /* riq[16][2] */ 3,
    /* riq[17][0] */ 3,
    /* riq[17][1] */ 3,
    /* riq[17][2] */ 3,
    /* riq[18][0] */ 3,
    /* riq[18][1] */ 3,
    /* riq[18][2] */ 3,
    /* riq[19][0] */ 3,
    /* riq[19][1] */ 3,
    /* riq[19][2] */ 3,
    /* riq[20][0] */ 3,
    /* riq[20][1] */ 3,
    /* riq[20][2] */ 3,
    /* presq[0] */ 3,
    /* presq[1] */ 3,
    /* presq[2] */ 3,
    /* presq[3] */ 3,
    /* presq[4] */ 3,
    /* presq[5] */ 3,
    /* presq[6] */ 3,
    /* presq[7] */ 3,
    /* presq[8] */ 3,
    /* presq[9] */ 3,
    /* presq[10] */ 3,
    /* presq[11] */ 3,
    /* presq[12] */ 3,
    /* presq[13] */ 3,
    /* presq[14] */ 3,
    /* presq[15] */ 3,
    /* presq[16] */ 3,
    /* presq[17] */ 3,
    /* presq[18] */ 3,
    /* presq[19] */ 3,
    /* presq[20] */ 3,
    /* presq[21] */ 3,
    /* stabvelq */ 3,
    /* stabposq */ 3,

/* End of values from input file */

};
allegro_air_gstate_t allegro_air_gstate;
allegro_air_glhs_t allegro_air_glhs;
allegro_air_grhs_t allegro_air_grhs;
allegro_air_gtemp_t allegro_air_gtemp;


void allegro_air_init(void)
{
/*
Initialization routine


 This routine must be called before the first call to sdstate(), after
 supplying values for any `?' parameters in the input.
*/
    double sumsq,norminv;
    int i,j,k;


/* Check that all `?' parameters have been assigned values */

    for (k = 0; k < 3; k++) {
        if (gravq[k] == 1) {
            allegro_air_seterr(7,25);
        }
    }
    for (k = 0; k < 21; k++) {
        if (mkq[k] == 1) {
            allegro_air_seterr(7,26);
        }
        for (i = 0; i < 3; i++) {
            if (rkq[k][i] == 1) {
                allegro_air_seterr(7,29);
            }
            if (riq[k][i] == 1) {
                allegro_air_seterr(7,30);
            }
            for (j = 0; j < 3; j++) {
                if (ikq[k][i][j] == 1) {
                    allegro_air_seterr(7,27);
                }
            }
        }
    }
    for (k = 0; k < 22; k++) {
        for (i = 0; i < 3; i++) {
            if (pinq[k][i] == 1) {
                allegro_air_seterr(7,28);
            }
        }
    }

/* Normalize pin vectors if necessary */

    sumsq = ((pin[0][2]*pin[0][2])+((pin[0][0]*pin[0][0])+(pin[0][1]*pin[0][1]))
      );
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        allegro_air_seterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[0][0] = (norminv*pin[0][0]);
    pin[0][1] = (norminv*pin[0][1]);
    pin[0][2] = (norminv*pin[0][2]);
    sumsq = ((pin[1][2]*pin[1][2])+((pin[1][0]*pin[1][0])+(pin[1][1]*pin[1][1]))
      );
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        allegro_air_seterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[1][0] = (norminv*pin[1][0]);
    pin[1][1] = (norminv*pin[1][1]);
    pin[1][2] = (norminv*pin[1][2]);
    sumsq = ((pin[2][2]*pin[2][2])+((pin[2][0]*pin[2][0])+(pin[2][1]*pin[2][1]))
      );
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        allegro_air_seterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[2][0] = (norminv*pin[2][0]);
    pin[2][1] = (norminv*pin[2][1]);
    pin[2][2] = (norminv*pin[2][2]);
    sumsq = ((pin[6][2]*pin[6][2])+((pin[6][0]*pin[6][0])+(pin[6][1]*pin[6][1]))
      );
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        allegro_air_seterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[6][0] = (norminv*pin[6][0]);
    pin[6][1] = (norminv*pin[6][1]);
    pin[6][2] = (norminv*pin[6][2]);
    sumsq = ((pin[7][2]*pin[7][2])+((pin[7][0]*pin[7][0])+(pin[7][1]*pin[7][1]))
      );
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        allegro_air_seterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[7][0] = (norminv*pin[7][0]);
    pin[7][1] = (norminv*pin[7][1]);
    pin[7][2] = (norminv*pin[7][2]);
    sumsq = ((pin[8][2]*pin[8][2])+((pin[8][0]*pin[8][0])+(pin[8][1]*pin[8][1]))
      );
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        allegro_air_seterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[8][0] = (norminv*pin[8][0]);
    pin[8][1] = (norminv*pin[8][1]);
    pin[8][2] = (norminv*pin[8][2]);
    sumsq = ((pin[9][2]*pin[9][2])+((pin[9][0]*pin[9][0])+(pin[9][1]*pin[9][1]))
      );
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        allegro_air_seterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[9][0] = (norminv*pin[9][0]);
    pin[9][1] = (norminv*pin[9][1]);
    pin[9][2] = (norminv*pin[9][2]);
    sumsq = ((pin[10][2]*pin[10][2])+((pin[10][0]*pin[10][0])+(pin[10][1]*
      pin[10][1])));
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        allegro_air_seterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[10][0] = (norminv*pin[10][0]);
    pin[10][1] = (norminv*pin[10][1]);
    pin[10][2] = (norminv*pin[10][2]);
    sumsq = ((pin[11][2]*pin[11][2])+((pin[11][0]*pin[11][0])+(pin[11][1]*
      pin[11][1])));
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        allegro_air_seterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[11][0] = (norminv*pin[11][0]);
    pin[11][1] = (norminv*pin[11][1]);
    pin[11][2] = (norminv*pin[11][2]);
    sumsq = ((pin[12][2]*pin[12][2])+((pin[12][0]*pin[12][0])+(pin[12][1]*
      pin[12][1])));
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        allegro_air_seterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[12][0] = (norminv*pin[12][0]);
    pin[12][1] = (norminv*pin[12][1]);
    pin[12][2] = (norminv*pin[12][2]);
    sumsq = ((pin[13][2]*pin[13][2])+((pin[13][0]*pin[13][0])+(pin[13][1]*
      pin[13][1])));
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        allegro_air_seterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[13][0] = (norminv*pin[13][0]);
    pin[13][1] = (norminv*pin[13][1]);
    pin[13][2] = (norminv*pin[13][2]);
    sumsq = ((pin[14][2]*pin[14][2])+((pin[14][0]*pin[14][0])+(pin[14][1]*
      pin[14][1])));
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        allegro_air_seterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[14][0] = (norminv*pin[14][0]);
    pin[14][1] = (norminv*pin[14][1]);
    pin[14][2] = (norminv*pin[14][2]);
    sumsq = ((pin[15][2]*pin[15][2])+((pin[15][0]*pin[15][0])+(pin[15][1]*
      pin[15][1])));
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        allegro_air_seterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[15][0] = (norminv*pin[15][0]);
    pin[15][1] = (norminv*pin[15][1]);
    pin[15][2] = (norminv*pin[15][2]);
    sumsq = ((pin[16][2]*pin[16][2])+((pin[16][0]*pin[16][0])+(pin[16][1]*
      pin[16][1])));
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        allegro_air_seterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[16][0] = (norminv*pin[16][0]);
    pin[16][1] = (norminv*pin[16][1]);
    pin[16][2] = (norminv*pin[16][2]);
    sumsq = ((pin[17][2]*pin[17][2])+((pin[17][0]*pin[17][0])+(pin[17][1]*
      pin[17][1])));
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        allegro_air_seterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[17][0] = (norminv*pin[17][0]);
    pin[17][1] = (norminv*pin[17][1]);
    pin[17][2] = (norminv*pin[17][2]);
    sumsq = ((pin[18][2]*pin[18][2])+((pin[18][0]*pin[18][0])+(pin[18][1]*
      pin[18][1])));
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        allegro_air_seterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[18][0] = (norminv*pin[18][0]);
    pin[18][1] = (norminv*pin[18][1]);
    pin[18][2] = (norminv*pin[18][2]);
    sumsq = ((pin[19][2]*pin[19][2])+((pin[19][0]*pin[19][0])+(pin[19][1]*
      pin[19][1])));
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        allegro_air_seterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[19][0] = (norminv*pin[19][0]);
    pin[19][1] = (norminv*pin[19][1]);
    pin[19][2] = (norminv*pin[19][2]);
    sumsq = ((pin[20][2]*pin[20][2])+((pin[20][0]*pin[20][0])+(pin[20][1]*
      pin[20][1])));
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        allegro_air_seterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[20][0] = (norminv*pin[20][0]);
    pin[20][1] = (norminv*pin[20][1]);
    pin[20][2] = (norminv*pin[20][2]);
    sumsq = ((pin[21][2]*pin[21][2])+((pin[21][0]*pin[21][0])+(pin[21][1]*
      pin[21][1])));
    if ((sumsq < 1e-10)  ) {
        norminv = 0.;
        allegro_air_seterr(7,1);
    } else {
        norminv = (1./sqrt(sumsq));
    }
    pin[21][0] = (norminv*pin[21][0]);
    pin[21][1] = (norminv*pin[21][1]);
    pin[21][2] = (norminv*pin[21][2]);

/* Zero out Vpk and Wpk */

    for (i = 0; i < 22; i++) {
        for (j = i; j <= 21; j++) {
            for (k = 0; k < 3; k++) {
                Vpk[i][j][k] = 0.;
                Wpk[i][j][k] = 0.;
            }
        }
    }

/* Compute pseudobody-related constants */

    psmk[9] = (mk[4]+mk[5]);
    psmk[13] = (mk[9]+mk[10]);
    psmk[17] = (mk[14]+mk[15]);
    psmk[21] = (mk[19]+mk[20]);
    rhead[5][0] = (ri[5][0]-rk[5][0]);
    rhead[5][1] = (ri[5][1]-rk[5][1]);
    rhead[5][2] = (ri[5][2]-rk[5][2]);
    rhead[10][0] = (ri[10][0]-rk[10][0]);
    rhead[10][1] = (ri[10][1]-rk[10][1]);
    rhead[10][2] = (ri[10][2]-rk[10][2]);
    rhead[15][0] = (ri[15][0]-rk[15][0]);
    rhead[15][1] = (ri[15][1]-rk[15][1]);
    rhead[15][2] = (ri[15][2]-rk[15][2]);
    rhead[20][0] = (ri[20][0]-rk[20][0]);
    rhead[20][1] = (ri[20][1]-rk[20][1]);
    rhead[20][2] = (ri[20][2]-rk[20][2]);
    if (psmk[9] != 0.) {
        psrcom[9][0] = ((-(mk[5]*rhead[5][0]))/psmk[9]);
        psrcom[9][1] = ((-(mk[5]*rhead[5][1]))/psmk[9]);
        psrcom[9][2] = ((-(mk[5]*rhead[5][2]))/psmk[9]);
    } else {
        psrcom[9][0] = 0.;
        psrcom[9][1] = 0.;
        psrcom[9][2] = 0.;
    }
    if (psmk[13] != 0.) {
        psrcom[13][0] = ((-(mk[10]*rhead[10][0]))/psmk[13]);
        psrcom[13][1] = ((-(mk[10]*rhead[10][1]))/psmk[13]);
        psrcom[13][2] = ((-(mk[10]*rhead[10][2]))/psmk[13]);
    } else {
        psrcom[13][0] = 0.;
        psrcom[13][1] = 0.;
        psrcom[13][2] = 0.;
    }
    if (psmk[17] != 0.) {
        psrcom[17][0] = ((-(mk[15]*rhead[15][0]))/psmk[17]);
        psrcom[17][1] = ((-(mk[15]*rhead[15][1]))/psmk[17]);
        psrcom[17][2] = ((-(mk[15]*rhead[15][2]))/psmk[17]);
    } else {
        psrcom[17][0] = 0.;
        psrcom[17][1] = 0.;
        psrcom[17][2] = 0.;
    }
    if (psmk[21] != 0.) {
        psrcom[21][0] = ((-(mk[20]*rhead[20][0]))/psmk[21]);
        psrcom[21][1] = ((-(mk[20]*rhead[20][1]))/psmk[21]);
        psrcom[21][2] = ((-(mk[20]*rhead[20][2]))/psmk[21]);
    } else {
        psrcom[21][0] = 0.;
        psrcom[21][1] = 0.;
        psrcom[21][2] = 0.;
    }
    rcom[0][0] = 0.;
    rcom[0][1] = 0.;
    rcom[0][2] = 0.;
    rcom[1][0] = 0.;
    rcom[1][1] = 0.;
    rcom[1][2] = 0.;
    rcom[2][0] = 0.;
    rcom[2][1] = 0.;
    rcom[2][2] = 0.;
    rcom[3][0] = 0.;
    rcom[3][1] = 0.;
    rcom[3][2] = 0.;
    rcom[4][0] = psrcom[9][0];
    rcom[4][1] = psrcom[9][1];
    rcom[4][2] = psrcom[9][2];
    rcom[5][0] = (psrcom[9][0]+rhead[5][0]);
    rcom[5][1] = (psrcom[9][1]+rhead[5][1]);
    rcom[5][2] = (psrcom[9][2]+rhead[5][2]);
    rcom[6][0] = 0.;
    rcom[6][1] = 0.;
    rcom[6][2] = 0.;
    rcom[7][0] = 0.;
    rcom[7][1] = 0.;
    rcom[7][2] = 0.;
    rcom[8][0] = 0.;
    rcom[8][1] = 0.;
    rcom[8][2] = 0.;
    rcom[9][0] = psrcom[13][0];
    rcom[9][1] = psrcom[13][1];
    rcom[9][2] = psrcom[13][2];
    rcom[10][0] = (psrcom[13][0]+rhead[10][0]);
    rcom[10][1] = (psrcom[13][1]+rhead[10][1]);
    rcom[10][2] = (psrcom[13][2]+rhead[10][2]);
    rcom[11][0] = 0.;
    rcom[11][1] = 0.;
    rcom[11][2] = 0.;
    rcom[12][0] = 0.;
    rcom[12][1] = 0.;
    rcom[12][2] = 0.;
    rcom[13][0] = 0.;
    rcom[13][1] = 0.;
    rcom[13][2] = 0.;
    rcom[14][0] = psrcom[17][0];
    rcom[14][1] = psrcom[17][1];
    rcom[14][2] = psrcom[17][2];
    rcom[15][0] = (psrcom[17][0]+rhead[15][0]);
    rcom[15][1] = (psrcom[17][1]+rhead[15][1]);
    rcom[15][2] = (psrcom[17][2]+rhead[15][2]);
    rcom[16][0] = 0.;
    rcom[16][1] = 0.;
    rcom[16][2] = 0.;
    rcom[17][0] = 0.;
    rcom[17][1] = 0.;
    rcom[17][2] = 0.;
    rcom[18][0] = 0.;
    rcom[18][1] = 0.;
    rcom[18][2] = 0.;
    rcom[19][0] = psrcom[21][0];
    rcom[19][1] = psrcom[21][1];
    rcom[19][2] = psrcom[21][2];
    rcom[20][0] = (psrcom[21][0]+rhead[20][0]);
    rcom[20][1] = (psrcom[21][1]+rhead[20][1]);
    rcom[20][2] = (psrcom[21][2]+rhead[20][2]);
    psrk[9][0] = (psrcom[9][0]+rk[4][0]);
    psrk[9][1] = (psrcom[9][1]+rk[4][1]);
    psrk[9][2] = (psrcom[9][2]+rk[4][2]);
    psrk[13][0] = (psrcom[13][0]+rk[9][0]);
    psrk[13][1] = (psrcom[13][1]+rk[9][1]);
    psrk[13][2] = (psrcom[13][2]+rk[9][2]);
    psrk[17][0] = (psrcom[17][0]+rk[14][0]);
    psrk[17][1] = (psrcom[17][1]+rk[14][1]);
    psrk[17][2] = (psrcom[17][2]+rk[14][2]);
    psrk[21][0] = (psrcom[21][0]+rk[19][0]);
    psrk[21][1] = (psrcom[21][1]+rk[19][1]);
    psrk[21][2] = (psrcom[21][2]+rk[19][2]);
    mkrcomt[4][0][1] = -(mk[4]*rcom[4][2]);
    mkrcomt[4][0][2] = (mk[4]*rcom[4][1]);
    mkrcomt[4][1][0] = (mk[4]*rcom[4][2]);
    mkrcomt[4][1][2] = -(mk[4]*rcom[4][0]);
    mkrcomt[4][2][0] = -(mk[4]*rcom[4][1]);
    mkrcomt[4][2][1] = (mk[4]*rcom[4][0]);
    mkrcomt[5][0][1] = -(mk[5]*rcom[5][2]);
    mkrcomt[5][0][2] = (mk[5]*rcom[5][1]);
    mkrcomt[5][1][0] = (mk[5]*rcom[5][2]);
    mkrcomt[5][1][2] = -(mk[5]*rcom[5][0]);
    mkrcomt[5][2][0] = -(mk[5]*rcom[5][1]);
    mkrcomt[5][2][1] = (mk[5]*rcom[5][0]);
    mkrcomt[9][0][1] = -(mk[9]*rcom[9][2]);
    mkrcomt[9][0][2] = (mk[9]*rcom[9][1]);
    mkrcomt[9][1][0] = (mk[9]*rcom[9][2]);
    mkrcomt[9][1][2] = -(mk[9]*rcom[9][0]);
    mkrcomt[9][2][0] = -(mk[9]*rcom[9][1]);
    mkrcomt[9][2][1] = (mk[9]*rcom[9][0]);
    mkrcomt[10][0][1] = -(mk[10]*rcom[10][2]);
    mkrcomt[10][0][2] = (mk[10]*rcom[10][1]);
    mkrcomt[10][1][0] = (mk[10]*rcom[10][2]);
    mkrcomt[10][1][2] = -(mk[10]*rcom[10][0]);
    mkrcomt[10][2][0] = -(mk[10]*rcom[10][1]);
    mkrcomt[10][2][1] = (mk[10]*rcom[10][0]);
    mkrcomt[14][0][1] = -(mk[14]*rcom[14][2]);
    mkrcomt[14][0][2] = (mk[14]*rcom[14][1]);
    mkrcomt[14][1][0] = (mk[14]*rcom[14][2]);
    mkrcomt[14][1][2] = -(mk[14]*rcom[14][0]);
    mkrcomt[14][2][0] = -(mk[14]*rcom[14][1]);
    mkrcomt[14][2][1] = (mk[14]*rcom[14][0]);
    mkrcomt[15][0][1] = -(mk[15]*rcom[15][2]);
    mkrcomt[15][0][2] = (mk[15]*rcom[15][1]);
    mkrcomt[15][1][0] = (mk[15]*rcom[15][2]);
    mkrcomt[15][1][2] = -(mk[15]*rcom[15][0]);
    mkrcomt[15][2][0] = -(mk[15]*rcom[15][1]);
    mkrcomt[15][2][1] = (mk[15]*rcom[15][0]);
    mkrcomt[19][0][1] = -(mk[19]*rcom[19][2]);
    mkrcomt[19][0][2] = (mk[19]*rcom[19][1]);
    mkrcomt[19][1][0] = (mk[19]*rcom[19][2]);
    mkrcomt[19][1][2] = -(mk[19]*rcom[19][0]);
    mkrcomt[19][2][0] = -(mk[19]*rcom[19][1]);
    mkrcomt[19][2][1] = (mk[19]*rcom[19][0]);
    mkrcomt[20][0][1] = -(mk[20]*rcom[20][2]);
    mkrcomt[20][0][2] = (mk[20]*rcom[20][1]);
    mkrcomt[20][1][0] = (mk[20]*rcom[20][2]);
    mkrcomt[20][1][2] = -(mk[20]*rcom[20][0]);
    mkrcomt[20][2][0] = -(mk[20]*rcom[20][1]);
    mkrcomt[20][2][1] = (mk[20]*rcom[20][0]);
    psik[9][0][0] = ((ik[4][0][0]-((mkrcomt[4][0][1]*rcom[4][2])-(
      mkrcomt[4][0][2]*rcom[4][1])))+(ik[5][0][0]-((mkrcomt[5][0][1]*rcom[5][2])
      -(mkrcomt[5][0][2]*rcom[5][1]))));
    psik[9][0][1] = ((ik[4][0][1]-(mkrcomt[4][0][2]*rcom[4][0]))+(ik[5][0][1]-(
      mkrcomt[5][0][2]*rcom[5][0])));
    psik[9][0][2] = ((ik[4][0][2]+(mkrcomt[4][0][1]*rcom[4][0]))+(ik[5][0][2]+(
      mkrcomt[5][0][1]*rcom[5][0])));
    psik[9][1][0] = ((ik[4][1][0]+(mkrcomt[4][1][2]*rcom[4][1]))+(ik[5][1][0]+(
      mkrcomt[5][1][2]*rcom[5][1])));
    psik[9][1][1] = ((ik[4][1][1]-((mkrcomt[4][1][2]*rcom[4][0])-(
      mkrcomt[4][1][0]*rcom[4][2])))+(ik[5][1][1]-((mkrcomt[5][1][2]*rcom[5][0])
      -(mkrcomt[5][1][0]*rcom[5][2]))));
    psik[9][1][2] = ((ik[4][1][2]-(mkrcomt[4][1][0]*rcom[4][1]))+(ik[5][1][2]-(
      mkrcomt[5][1][0]*rcom[5][1])));
    psik[9][2][0] = ((ik[4][2][0]-(mkrcomt[4][2][1]*rcom[4][2]))+(ik[5][2][0]-(
      mkrcomt[5][2][1]*rcom[5][2])));
    psik[9][2][1] = ((ik[4][2][1]+(mkrcomt[4][2][0]*rcom[4][2]))+(ik[5][2][1]+(
      mkrcomt[5][2][0]*rcom[5][2])));
    psik[9][2][2] = ((ik[4][2][2]-((mkrcomt[4][2][0]*rcom[4][1])-(
      mkrcomt[4][2][1]*rcom[4][0])))+(ik[5][2][2]-((mkrcomt[5][2][0]*rcom[5][1])
      -(mkrcomt[5][2][1]*rcom[5][0]))));
    psik[13][0][0] = ((ik[9][0][0]-((mkrcomt[9][0][1]*rcom[9][2])-(
      mkrcomt[9][0][2]*rcom[9][1])))+(ik[10][0][0]-((mkrcomt[10][0][1]*
      rcom[10][2])-(mkrcomt[10][0][2]*rcom[10][1]))));
    psik[13][0][1] = ((ik[9][0][1]-(mkrcomt[9][0][2]*rcom[9][0]))+(ik[10][0][1]-
      (mkrcomt[10][0][2]*rcom[10][0])));
    psik[13][0][2] = ((ik[9][0][2]+(mkrcomt[9][0][1]*rcom[9][0]))+(ik[10][0][2]+
      (mkrcomt[10][0][1]*rcom[10][0])));
    psik[13][1][0] = ((ik[9][1][0]+(mkrcomt[9][1][2]*rcom[9][1]))+(ik[10][1][0]+
      (mkrcomt[10][1][2]*rcom[10][1])));
    psik[13][1][1] = ((ik[9][1][1]-((mkrcomt[9][1][2]*rcom[9][0])-(
      mkrcomt[9][1][0]*rcom[9][2])))+(ik[10][1][1]-((mkrcomt[10][1][2]*
      rcom[10][0])-(mkrcomt[10][1][0]*rcom[10][2]))));
    psik[13][1][2] = ((ik[9][1][2]-(mkrcomt[9][1][0]*rcom[9][1]))+(ik[10][1][2]-
      (mkrcomt[10][1][0]*rcom[10][1])));
    psik[13][2][0] = ((ik[9][2][0]-(mkrcomt[9][2][1]*rcom[9][2]))+(ik[10][2][0]-
      (mkrcomt[10][2][1]*rcom[10][2])));
    psik[13][2][1] = ((ik[9][2][1]+(mkrcomt[9][2][0]*rcom[9][2]))+(ik[10][2][1]+
      (mkrcomt[10][2][0]*rcom[10][2])));
    psik[13][2][2] = ((ik[9][2][2]-((mkrcomt[9][2][0]*rcom[9][1])-(
      mkrcomt[9][2][1]*rcom[9][0])))+(ik[10][2][2]-((mkrcomt[10][2][0]*
      rcom[10][1])-(mkrcomt[10][2][1]*rcom[10][0]))));
    psik[17][0][0] = ((ik[14][0][0]-((mkrcomt[14][0][1]*rcom[14][2])-(
      mkrcomt[14][0][2]*rcom[14][1])))+(ik[15][0][0]-((mkrcomt[15][0][1]*
      rcom[15][2])-(mkrcomt[15][0][2]*rcom[15][1]))));
    psik[17][0][1] = ((ik[14][0][1]-(mkrcomt[14][0][2]*rcom[14][0]))+(
      ik[15][0][1]-(mkrcomt[15][0][2]*rcom[15][0])));
    psik[17][0][2] = ((ik[14][0][2]+(mkrcomt[14][0][1]*rcom[14][0]))+(
      ik[15][0][2]+(mkrcomt[15][0][1]*rcom[15][0])));
    psik[17][1][0] = ((ik[14][1][0]+(mkrcomt[14][1][2]*rcom[14][1]))+(
      ik[15][1][0]+(mkrcomt[15][1][2]*rcom[15][1])));
    psik[17][1][1] = ((ik[14][1][1]-((mkrcomt[14][1][2]*rcom[14][0])-(
      mkrcomt[14][1][0]*rcom[14][2])))+(ik[15][1][1]-((mkrcomt[15][1][2]*
      rcom[15][0])-(mkrcomt[15][1][0]*rcom[15][2]))));
    psik[17][1][2] = ((ik[14][1][2]-(mkrcomt[14][1][0]*rcom[14][1]))+(
      ik[15][1][2]-(mkrcomt[15][1][0]*rcom[15][1])));
    psik[17][2][0] = ((ik[14][2][0]-(mkrcomt[14][2][1]*rcom[14][2]))+(
      ik[15][2][0]-(mkrcomt[15][2][1]*rcom[15][2])));
    psik[17][2][1] = ((ik[14][2][1]+(mkrcomt[14][2][0]*rcom[14][2]))+(
      ik[15][2][1]+(mkrcomt[15][2][0]*rcom[15][2])));
    psik[17][2][2] = ((ik[14][2][2]-((mkrcomt[14][2][0]*rcom[14][1])-(
      mkrcomt[14][2][1]*rcom[14][0])))+(ik[15][2][2]-((mkrcomt[15][2][0]*
      rcom[15][1])-(mkrcomt[15][2][1]*rcom[15][0]))));
    psik[21][0][0] = ((ik[19][0][0]-((mkrcomt[19][0][1]*rcom[19][2])-(
      mkrcomt[19][0][2]*rcom[19][1])))+(ik[20][0][0]-((mkrcomt[20][0][1]*
      rcom[20][2])-(mkrcomt[20][0][2]*rcom[20][1]))));
    psik[21][0][1] = ((ik[19][0][1]-(mkrcomt[19][0][2]*rcom[19][0]))+(
      ik[20][0][1]-(mkrcomt[20][0][2]*rcom[20][0])));
    psik[21][0][2] = ((ik[19][0][2]+(mkrcomt[19][0][1]*rcom[19][0]))+(
      ik[20][0][2]+(mkrcomt[20][0][1]*rcom[20][0])));
    psik[21][1][0] = ((ik[19][1][0]+(mkrcomt[19][1][2]*rcom[19][1]))+(
      ik[20][1][0]+(mkrcomt[20][1][2]*rcom[20][1])));
    psik[21][1][1] = ((ik[19][1][1]-((mkrcomt[19][1][2]*rcom[19][0])-(
      mkrcomt[19][1][0]*rcom[19][2])))+(ik[20][1][1]-((mkrcomt[20][1][2]*
      rcom[20][0])-(mkrcomt[20][1][0]*rcom[20][2]))));
    psik[21][1][2] = ((ik[19][1][2]-(mkrcomt[19][1][0]*rcom[19][1]))+(
      ik[20][1][2]-(mkrcomt[20][1][0]*rcom[20][1])));
    psik[21][2][0] = ((ik[19][2][0]-(mkrcomt[19][2][1]*rcom[19][2]))+(
      ik[20][2][0]-(mkrcomt[20][2][1]*rcom[20][2])));
    psik[21][2][1] = ((ik[19][2][1]+(mkrcomt[19][2][0]*rcom[19][2]))+(
      ik[20][2][1]+(mkrcomt[20][2][0]*rcom[20][2])));
    psik[21][2][2] = ((ik[19][2][2]-((mkrcomt[19][2][0]*rcom[19][1])-(
      mkrcomt[19][2][1]*rcom[19][0])))+(ik[20][2][2]-((mkrcomt[20][2][0]*
      rcom[20][1])-(mkrcomt[20][2][1]*rcom[20][0]))));
    rkWkk[6][0] = ((pin[6][2]*rk[1][1])-(pin[6][1]*rk[1][2]));
    rkWkk[6][1] = ((pin[6][0]*rk[1][2])-(pin[6][2]*rk[1][0]));
    rkWkk[6][2] = ((pin[6][1]*rk[1][0])-(pin[6][0]*rk[1][1]));
    rkWkk[7][0] = ((pin[7][2]*rk[2][1])-(pin[7][1]*rk[2][2]));
    rkWkk[7][1] = ((pin[7][0]*rk[2][2])-(pin[7][2]*rk[2][0]));
    rkWkk[7][2] = ((pin[7][1]*rk[2][0])-(pin[7][0]*rk[2][1]));
    rkWkk[8][0] = ((pin[8][2]*rk[3][1])-(pin[8][1]*rk[3][2]));
    rkWkk[8][1] = ((pin[8][0]*rk[3][2])-(pin[8][2]*rk[3][0]));
    rkWkk[8][2] = ((pin[8][1]*rk[3][0])-(pin[8][0]*rk[3][1]));
    rkWkk[9][0] = ((pin[9][2]*psrk[9][1])-(pin[9][1]*psrk[9][2]));
    rkWkk[9][1] = ((pin[9][0]*psrk[9][2])-(pin[9][2]*psrk[9][0]));
    rkWkk[9][2] = ((pin[9][1]*psrk[9][0])-(pin[9][0]*psrk[9][1]));
    rkWkk[10][0] = ((pin[10][2]*rk[6][1])-(pin[10][1]*rk[6][2]));
    rkWkk[10][1] = ((pin[10][0]*rk[6][2])-(pin[10][2]*rk[6][0]));
    rkWkk[10][2] = ((pin[10][1]*rk[6][0])-(pin[10][0]*rk[6][1]));
    rkWkk[11][0] = ((pin[11][2]*rk[7][1])-(pin[11][1]*rk[7][2]));
    rkWkk[11][1] = ((pin[11][0]*rk[7][2])-(pin[11][2]*rk[7][0]));
    rkWkk[11][2] = ((pin[11][1]*rk[7][0])-(pin[11][0]*rk[7][1]));
    rkWkk[12][0] = ((pin[12][2]*rk[8][1])-(pin[12][1]*rk[8][2]));
    rkWkk[12][1] = ((pin[12][0]*rk[8][2])-(pin[12][2]*rk[8][0]));
    rkWkk[12][2] = ((pin[12][1]*rk[8][0])-(pin[12][0]*rk[8][1]));
    rkWkk[13][0] = ((pin[13][2]*psrk[13][1])-(pin[13][1]*psrk[13][2]));
    rkWkk[13][1] = ((pin[13][0]*psrk[13][2])-(pin[13][2]*psrk[13][0]));
    rkWkk[13][2] = ((pin[13][1]*psrk[13][0])-(pin[13][0]*psrk[13][1]));
    rkWkk[14][0] = ((pin[14][2]*rk[11][1])-(pin[14][1]*rk[11][2]));
    rkWkk[14][1] = ((pin[14][0]*rk[11][2])-(pin[14][2]*rk[11][0]));
    rkWkk[14][2] = ((pin[14][1]*rk[11][0])-(pin[14][0]*rk[11][1]));
    rkWkk[15][0] = ((pin[15][2]*rk[12][1])-(pin[15][1]*rk[12][2]));
    rkWkk[15][1] = ((pin[15][0]*rk[12][2])-(pin[15][2]*rk[12][0]));
    rkWkk[15][2] = ((pin[15][1]*rk[12][0])-(pin[15][0]*rk[12][1]));
    rkWkk[16][0] = ((pin[16][2]*rk[13][1])-(pin[16][1]*rk[13][2]));
    rkWkk[16][1] = ((pin[16][0]*rk[13][2])-(pin[16][2]*rk[13][0]));
    rkWkk[16][2] = ((pin[16][1]*rk[13][0])-(pin[16][0]*rk[13][1]));
    rkWkk[17][0] = ((pin[17][2]*psrk[17][1])-(pin[17][1]*psrk[17][2]));
    rkWkk[17][1] = ((pin[17][0]*psrk[17][2])-(pin[17][2]*psrk[17][0]));
    rkWkk[17][2] = ((pin[17][1]*psrk[17][0])-(pin[17][0]*psrk[17][1]));
    rkWkk[18][0] = ((pin[18][2]*rk[16][1])-(pin[18][1]*rk[16][2]));
    rkWkk[18][1] = ((pin[18][0]*rk[16][2])-(pin[18][2]*rk[16][0]));
    rkWkk[18][2] = ((pin[18][1]*rk[16][0])-(pin[18][0]*rk[16][1]));
    rkWkk[19][0] = ((pin[19][2]*rk[17][1])-(pin[19][1]*rk[17][2]));
    rkWkk[19][1] = ((pin[19][0]*rk[17][2])-(pin[19][2]*rk[17][0]));
    rkWkk[19][2] = ((pin[19][1]*rk[17][0])-(pin[19][0]*rk[17][1]));
    rkWkk[20][0] = ((pin[20][2]*rk[18][1])-(pin[20][1]*rk[18][2]));
    rkWkk[20][1] = ((pin[20][0]*rk[18][2])-(pin[20][2]*rk[18][0]));
    rkWkk[20][2] = ((pin[20][1]*rk[18][0])-(pin[20][0]*rk[18][1]));
    rkWkk[21][0] = ((pin[21][2]*psrk[21][1])-(pin[21][1]*psrk[21][2]));
    rkWkk[21][1] = ((pin[21][0]*psrk[21][2])-(pin[21][2]*psrk[21][0]));
    rkWkk[21][2] = ((pin[21][1]*psrk[21][0])-(pin[21][0]*psrk[21][1]));
    dik[6][0] = (ri[1][0]-rk[0][0]);
    dik[6][1] = (ri[1][1]-rk[0][1]);
    dik[6][2] = (ri[1][2]-rk[0][2]);
    dik[7][0] = (ri[2][0]-rk[1][0]);
    dik[7][1] = (ri[2][1]-rk[1][1]);
    dik[7][2] = (ri[2][2]-rk[1][2]);
    dik[8][0] = (ri[3][0]-rk[2][0]);
    dik[8][1] = (ri[3][1]-rk[2][1]);
    dik[8][2] = (ri[3][2]-rk[2][2]);
    dik[9][0] = (ri[4][0]-rk[3][0]);
    dik[9][1] = (ri[4][1]-rk[3][1]);
    dik[9][2] = (ri[4][2]-rk[3][2]);
    dik[10][0] = (ri[6][0]-rk[0][0]);
    dik[10][1] = (ri[6][1]-rk[0][1]);
    dik[10][2] = (ri[6][2]-rk[0][2]);
    dik[11][0] = (ri[7][0]-rk[6][0]);
    dik[11][1] = (ri[7][1]-rk[6][1]);
    dik[11][2] = (ri[7][2]-rk[6][2]);
    dik[12][0] = (ri[8][0]-rk[7][0]);
    dik[12][1] = (ri[8][1]-rk[7][1]);
    dik[12][2] = (ri[8][2]-rk[7][2]);
    dik[13][0] = (ri[9][0]-rk[8][0]);
    dik[13][1] = (ri[9][1]-rk[8][1]);
    dik[13][2] = (ri[9][2]-rk[8][2]);
    dik[14][0] = (ri[11][0]-rk[0][0]);
    dik[14][1] = (ri[11][1]-rk[0][1]);
    dik[14][2] = (ri[11][2]-rk[0][2]);
    dik[15][0] = (ri[12][0]-rk[11][0]);
    dik[15][1] = (ri[12][1]-rk[11][1]);
    dik[15][2] = (ri[12][2]-rk[11][2]);
    dik[16][0] = (ri[13][0]-rk[12][0]);
    dik[16][1] = (ri[13][1]-rk[12][1]);
    dik[16][2] = (ri[13][2]-rk[12][2]);
    dik[17][0] = (ri[14][0]-rk[13][0]);
    dik[17][1] = (ri[14][1]-rk[13][1]);
    dik[17][2] = (ri[14][2]-rk[13][2]);
    dik[18][0] = (ri[16][0]-rk[0][0]);
    dik[18][1] = (ri[16][1]-rk[0][1]);
    dik[18][2] = (ri[16][2]-rk[0][2]);
    dik[19][0] = (ri[17][0]-rk[16][0]);
    dik[19][1] = (ri[17][1]-rk[16][1]);
    dik[19][2] = (ri[17][2]-rk[16][2]);
    dik[20][0] = (ri[18][0]-rk[17][0]);
    dik[20][1] = (ri[18][1]-rk[17][1]);
    dik[20][2] = (ri[18][2]-rk[17][2]);
    dik[21][0] = (ri[19][0]-rk[18][0]);
    dik[21][1] = (ri[19][1]-rk[18][1]);
    dik[21][2] = (ri[19][2]-rk[18][2]);

/* Compute mass properties-related constants */

    mtot = (mk[20]+(mk[19]+(mk[18]+(mk[17]+(mk[16]+(mk[15]+(mk[14]+(mk[13]+(
      mk[12]+(mk[11]+(mk[10]+(mk[9]+(mk[8]+(mk[7]+(mk[6]+(mk[5]+(mk[4]+(mk[3]+(
      mk[2]+(mk[0]+mk[1]))))))))))))))))))));
    mkrk[5][0][1] = -(mk[0]*rk[0][2]);
    mkrk[5][0][2] = (mk[0]*rk[0][1]);
    mkrk[5][1][0] = (mk[0]*rk[0][2]);
    mkrk[5][1][2] = -(mk[0]*rk[0][0]);
    mkrk[5][2][0] = -(mk[0]*rk[0][1]);
    mkrk[5][2][1] = (mk[0]*rk[0][0]);
    mkrk[6][0][1] = -(mk[1]*rk[1][2]);
    mkrk[6][0][2] = (mk[1]*rk[1][1]);
    mkrk[6][1][0] = (mk[1]*rk[1][2]);
    mkrk[6][1][2] = -(mk[1]*rk[1][0]);
    mkrk[6][2][0] = -(mk[1]*rk[1][1]);
    mkrk[6][2][1] = (mk[1]*rk[1][0]);
    mkrk[7][0][1] = -(mk[2]*rk[2][2]);
    mkrk[7][0][2] = (mk[2]*rk[2][1]);
    mkrk[7][1][0] = (mk[2]*rk[2][2]);
    mkrk[7][1][2] = -(mk[2]*rk[2][0]);
    mkrk[7][2][0] = -(mk[2]*rk[2][1]);
    mkrk[7][2][1] = (mk[2]*rk[2][0]);
    mkrk[8][0][1] = -(mk[3]*rk[3][2]);
    mkrk[8][0][2] = (mk[3]*rk[3][1]);
    mkrk[8][1][0] = (mk[3]*rk[3][2]);
    mkrk[8][1][2] = -(mk[3]*rk[3][0]);
    mkrk[8][2][0] = -(mk[3]*rk[3][1]);
    mkrk[8][2][1] = (mk[3]*rk[3][0]);
    mkrk[9][0][1] = -(psmk[9]*psrk[9][2]);
    mkrk[9][0][2] = (psmk[9]*psrk[9][1]);
    mkrk[9][1][0] = (psmk[9]*psrk[9][2]);
    mkrk[9][1][2] = -(psmk[9]*psrk[9][0]);
    mkrk[9][2][0] = -(psmk[9]*psrk[9][1]);
    mkrk[9][2][1] = (psmk[9]*psrk[9][0]);
    mkrk[10][0][1] = -(mk[6]*rk[6][2]);
    mkrk[10][0][2] = (mk[6]*rk[6][1]);
    mkrk[10][1][0] = (mk[6]*rk[6][2]);
    mkrk[10][1][2] = -(mk[6]*rk[6][0]);
    mkrk[10][2][0] = -(mk[6]*rk[6][1]);
    mkrk[10][2][1] = (mk[6]*rk[6][0]);
    mkrk[11][0][1] = -(mk[7]*rk[7][2]);
    mkrk[11][0][2] = (mk[7]*rk[7][1]);
    mkrk[11][1][0] = (mk[7]*rk[7][2]);
    mkrk[11][1][2] = -(mk[7]*rk[7][0]);
    mkrk[11][2][0] = -(mk[7]*rk[7][1]);
    mkrk[11][2][1] = (mk[7]*rk[7][0]);
    mkrk[12][0][1] = -(mk[8]*rk[8][2]);
    mkrk[12][0][2] = (mk[8]*rk[8][1]);
    mkrk[12][1][0] = (mk[8]*rk[8][2]);
    mkrk[12][1][2] = -(mk[8]*rk[8][0]);
    mkrk[12][2][0] = -(mk[8]*rk[8][1]);
    mkrk[12][2][1] = (mk[8]*rk[8][0]);
    mkrk[13][0][1] = -(psmk[13]*psrk[13][2]);
    mkrk[13][0][2] = (psmk[13]*psrk[13][1]);
    mkrk[13][1][0] = (psmk[13]*psrk[13][2]);
    mkrk[13][1][2] = -(psmk[13]*psrk[13][0]);
    mkrk[13][2][0] = -(psmk[13]*psrk[13][1]);
    mkrk[13][2][1] = (psmk[13]*psrk[13][0]);
    mkrk[14][0][1] = -(mk[11]*rk[11][2]);
    mkrk[14][0][2] = (mk[11]*rk[11][1]);
    mkrk[14][1][0] = (mk[11]*rk[11][2]);
    mkrk[14][1][2] = -(mk[11]*rk[11][0]);
    mkrk[14][2][0] = -(mk[11]*rk[11][1]);
    mkrk[14][2][1] = (mk[11]*rk[11][0]);
    mkrk[15][0][1] = -(mk[12]*rk[12][2]);
    mkrk[15][0][2] = (mk[12]*rk[12][1]);
    mkrk[15][1][0] = (mk[12]*rk[12][2]);
    mkrk[15][1][2] = -(mk[12]*rk[12][0]);
    mkrk[15][2][0] = -(mk[12]*rk[12][1]);
    mkrk[15][2][1] = (mk[12]*rk[12][0]);
    mkrk[16][0][1] = -(mk[13]*rk[13][2]);
    mkrk[16][0][2] = (mk[13]*rk[13][1]);
    mkrk[16][1][0] = (mk[13]*rk[13][2]);
    mkrk[16][1][2] = -(mk[13]*rk[13][0]);
    mkrk[16][2][0] = -(mk[13]*rk[13][1]);
    mkrk[16][2][1] = (mk[13]*rk[13][0]);
    mkrk[17][0][1] = -(psmk[17]*psrk[17][2]);
    mkrk[17][0][2] = (psmk[17]*psrk[17][1]);
    mkrk[17][1][0] = (psmk[17]*psrk[17][2]);
    mkrk[17][1][2] = -(psmk[17]*psrk[17][0]);
    mkrk[17][2][0] = -(psmk[17]*psrk[17][1]);
    mkrk[17][2][1] = (psmk[17]*psrk[17][0]);
    mkrk[18][0][1] = -(mk[16]*rk[16][2]);
    mkrk[18][0][2] = (mk[16]*rk[16][1]);
    mkrk[18][1][0] = (mk[16]*rk[16][2]);
    mkrk[18][1][2] = -(mk[16]*rk[16][0]);
    mkrk[18][2][0] = -(mk[16]*rk[16][1]);
    mkrk[18][2][1] = (mk[16]*rk[16][0]);
    mkrk[19][0][1] = -(mk[17]*rk[17][2]);
    mkrk[19][0][2] = (mk[17]*rk[17][1]);
    mkrk[19][1][0] = (mk[17]*rk[17][2]);
    mkrk[19][1][2] = -(mk[17]*rk[17][0]);
    mkrk[19][2][0] = -(mk[17]*rk[17][1]);
    mkrk[19][2][1] = (mk[17]*rk[17][0]);
    mkrk[20][0][1] = -(mk[18]*rk[18][2]);
    mkrk[20][0][2] = (mk[18]*rk[18][1]);
    mkrk[20][1][0] = (mk[18]*rk[18][2]);
    mkrk[20][1][2] = -(mk[18]*rk[18][0]);
    mkrk[20][2][0] = -(mk[18]*rk[18][1]);
    mkrk[20][2][1] = (mk[18]*rk[18][0]);
    mkrk[21][0][1] = -(psmk[21]*psrk[21][2]);
    mkrk[21][0][2] = (psmk[21]*psrk[21][1]);
    mkrk[21][1][0] = (psmk[21]*psrk[21][2]);
    mkrk[21][1][2] = -(psmk[21]*psrk[21][0]);
    mkrk[21][2][0] = -(psmk[21]*psrk[21][1]);
    mkrk[21][2][1] = (psmk[21]*psrk[21][0]);
    Iko[5][0][0] = (ik[0][0][0]-((mkrk[5][0][1]*rk[0][2])-(mkrk[5][0][2]*
      rk[0][1])));
    Iko[5][0][1] = (ik[0][0][1]-(mkrk[5][0][2]*rk[0][0]));
    Iko[5][0][2] = (ik[0][0][2]+(mkrk[5][0][1]*rk[0][0]));
    Iko[5][1][0] = (ik[0][1][0]+(mkrk[5][1][2]*rk[0][1]));
    Iko[5][1][1] = (ik[0][1][1]-((mkrk[5][1][2]*rk[0][0])-(mkrk[5][1][0]*
      rk[0][2])));
    Iko[5][1][2] = (ik[0][1][2]-(mkrk[5][1][0]*rk[0][1]));
    Iko[5][2][0] = (ik[0][2][0]-(mkrk[5][2][1]*rk[0][2]));
    Iko[5][2][1] = (ik[0][2][1]+(mkrk[5][2][0]*rk[0][2]));
    Iko[5][2][2] = (ik[0][2][2]-((mkrk[5][2][0]*rk[0][1])-(mkrk[5][2][1]*
      rk[0][0])));
    Iko[6][0][0] = (ik[1][0][0]-((mkrk[6][0][1]*rk[1][2])-(mkrk[6][0][2]*
      rk[1][1])));
    Iko[6][0][1] = (ik[1][0][1]-(mkrk[6][0][2]*rk[1][0]));
    Iko[6][0][2] = (ik[1][0][2]+(mkrk[6][0][1]*rk[1][0]));
    Iko[6][1][0] = (ik[1][1][0]+(mkrk[6][1][2]*rk[1][1]));
    Iko[6][1][1] = (ik[1][1][1]-((mkrk[6][1][2]*rk[1][0])-(mkrk[6][1][0]*
      rk[1][2])));
    Iko[6][1][2] = (ik[1][1][2]-(mkrk[6][1][0]*rk[1][1]));
    Iko[6][2][0] = (ik[1][2][0]-(mkrk[6][2][1]*rk[1][2]));
    Iko[6][2][1] = (ik[1][2][1]+(mkrk[6][2][0]*rk[1][2]));
    Iko[6][2][2] = (ik[1][2][2]-((mkrk[6][2][0]*rk[1][1])-(mkrk[6][2][1]*
      rk[1][0])));
    Iko[7][0][0] = (ik[2][0][0]-((mkrk[7][0][1]*rk[2][2])-(mkrk[7][0][2]*
      rk[2][1])));
    Iko[7][0][1] = (ik[2][0][1]-(mkrk[7][0][2]*rk[2][0]));
    Iko[7][0][2] = (ik[2][0][2]+(mkrk[7][0][1]*rk[2][0]));
    Iko[7][1][0] = (ik[2][1][0]+(mkrk[7][1][2]*rk[2][1]));
    Iko[7][1][1] = (ik[2][1][1]-((mkrk[7][1][2]*rk[2][0])-(mkrk[7][1][0]*
      rk[2][2])));
    Iko[7][1][2] = (ik[2][1][2]-(mkrk[7][1][0]*rk[2][1]));
    Iko[7][2][0] = (ik[2][2][0]-(mkrk[7][2][1]*rk[2][2]));
    Iko[7][2][1] = (ik[2][2][1]+(mkrk[7][2][0]*rk[2][2]));
    Iko[7][2][2] = (ik[2][2][2]-((mkrk[7][2][0]*rk[2][1])-(mkrk[7][2][1]*
      rk[2][0])));
    Iko[8][0][0] = (ik[3][0][0]-((mkrk[8][0][1]*rk[3][2])-(mkrk[8][0][2]*
      rk[3][1])));
    Iko[8][0][1] = (ik[3][0][1]-(mkrk[8][0][2]*rk[3][0]));
    Iko[8][0][2] = (ik[3][0][2]+(mkrk[8][0][1]*rk[3][0]));
    Iko[8][1][0] = (ik[3][1][0]+(mkrk[8][1][2]*rk[3][1]));
    Iko[8][1][1] = (ik[3][1][1]-((mkrk[8][1][2]*rk[3][0])-(mkrk[8][1][0]*
      rk[3][2])));
    Iko[8][1][2] = (ik[3][1][2]-(mkrk[8][1][0]*rk[3][1]));
    Iko[8][2][0] = (ik[3][2][0]-(mkrk[8][2][1]*rk[3][2]));
    Iko[8][2][1] = (ik[3][2][1]+(mkrk[8][2][0]*rk[3][2]));
    Iko[8][2][2] = (ik[3][2][2]-((mkrk[8][2][0]*rk[3][1])-(mkrk[8][2][1]*
      rk[3][0])));
    Iko[9][0][0] = (psik[9][0][0]-((mkrk[9][0][1]*psrk[9][2])-(mkrk[9][0][2]*
      psrk[9][1])));
    Iko[9][0][1] = (psik[9][0][1]-(mkrk[9][0][2]*psrk[9][0]));
    Iko[9][0][2] = (psik[9][0][2]+(mkrk[9][0][1]*psrk[9][0]));
    Iko[9][1][0] = (psik[9][1][0]+(mkrk[9][1][2]*psrk[9][1]));
    Iko[9][1][1] = (psik[9][1][1]-((mkrk[9][1][2]*psrk[9][0])-(mkrk[9][1][0]*
      psrk[9][2])));
    Iko[9][1][2] = (psik[9][1][2]-(mkrk[9][1][0]*psrk[9][1]));
    Iko[9][2][0] = (psik[9][2][0]-(mkrk[9][2][1]*psrk[9][2]));
    Iko[9][2][1] = (psik[9][2][1]+(mkrk[9][2][0]*psrk[9][2]));
    Iko[9][2][2] = (psik[9][2][2]-((mkrk[9][2][0]*psrk[9][1])-(mkrk[9][2][1]*
      psrk[9][0])));
    Iko[10][0][0] = (ik[6][0][0]-((mkrk[10][0][1]*rk[6][2])-(mkrk[10][0][2]*
      rk[6][1])));
    Iko[10][0][1] = (ik[6][0][1]-(mkrk[10][0][2]*rk[6][0]));
    Iko[10][0][2] = (ik[6][0][2]+(mkrk[10][0][1]*rk[6][0]));
    Iko[10][1][0] = (ik[6][1][0]+(mkrk[10][1][2]*rk[6][1]));
    Iko[10][1][1] = (ik[6][1][1]-((mkrk[10][1][2]*rk[6][0])-(mkrk[10][1][0]*
      rk[6][2])));
    Iko[10][1][2] = (ik[6][1][2]-(mkrk[10][1][0]*rk[6][1]));
    Iko[10][2][0] = (ik[6][2][0]-(mkrk[10][2][1]*rk[6][2]));
    Iko[10][2][1] = (ik[6][2][1]+(mkrk[10][2][0]*rk[6][2]));
    Iko[10][2][2] = (ik[6][2][2]-((mkrk[10][2][0]*rk[6][1])-(mkrk[10][2][1]*
      rk[6][0])));
    Iko[11][0][0] = (ik[7][0][0]-((mkrk[11][0][1]*rk[7][2])-(mkrk[11][0][2]*
      rk[7][1])));
    Iko[11][0][1] = (ik[7][0][1]-(mkrk[11][0][2]*rk[7][0]));
    Iko[11][0][2] = (ik[7][0][2]+(mkrk[11][0][1]*rk[7][0]));
    Iko[11][1][0] = (ik[7][1][0]+(mkrk[11][1][2]*rk[7][1]));
    Iko[11][1][1] = (ik[7][1][1]-((mkrk[11][1][2]*rk[7][0])-(mkrk[11][1][0]*
      rk[7][2])));
    Iko[11][1][2] = (ik[7][1][2]-(mkrk[11][1][0]*rk[7][1]));
    Iko[11][2][0] = (ik[7][2][0]-(mkrk[11][2][1]*rk[7][2]));
    Iko[11][2][1] = (ik[7][2][1]+(mkrk[11][2][0]*rk[7][2]));
    Iko[11][2][2] = (ik[7][2][2]-((mkrk[11][2][0]*rk[7][1])-(mkrk[11][2][1]*
      rk[7][0])));
    Iko[12][0][0] = (ik[8][0][0]-((mkrk[12][0][1]*rk[8][2])-(mkrk[12][0][2]*
      rk[8][1])));
    Iko[12][0][1] = (ik[8][0][1]-(mkrk[12][0][2]*rk[8][0]));
    Iko[12][0][2] = (ik[8][0][2]+(mkrk[12][0][1]*rk[8][0]));
    Iko[12][1][0] = (ik[8][1][0]+(mkrk[12][1][2]*rk[8][1]));
    Iko[12][1][1] = (ik[8][1][1]-((mkrk[12][1][2]*rk[8][0])-(mkrk[12][1][0]*
      rk[8][2])));
    Iko[12][1][2] = (ik[8][1][2]-(mkrk[12][1][0]*rk[8][1]));
    Iko[12][2][0] = (ik[8][2][0]-(mkrk[12][2][1]*rk[8][2]));
    Iko[12][2][1] = (ik[8][2][1]+(mkrk[12][2][0]*rk[8][2]));
    Iko[12][2][2] = (ik[8][2][2]-((mkrk[12][2][0]*rk[8][1])-(mkrk[12][2][1]*
      rk[8][0])));
    Iko[13][0][0] = (psik[13][0][0]-((mkrk[13][0][1]*psrk[13][2])-(
      mkrk[13][0][2]*psrk[13][1])));
    Iko[13][0][1] = (psik[13][0][1]-(mkrk[13][0][2]*psrk[13][0]));
    Iko[13][0][2] = (psik[13][0][2]+(mkrk[13][0][1]*psrk[13][0]));
    Iko[13][1][0] = (psik[13][1][0]+(mkrk[13][1][2]*psrk[13][1]));
    Iko[13][1][1] = (psik[13][1][1]-((mkrk[13][1][2]*psrk[13][0])-(
      mkrk[13][1][0]*psrk[13][2])));
    Iko[13][1][2] = (psik[13][1][2]-(mkrk[13][1][0]*psrk[13][1]));
    Iko[13][2][0] = (psik[13][2][0]-(mkrk[13][2][1]*psrk[13][2]));
    Iko[13][2][1] = (psik[13][2][1]+(mkrk[13][2][0]*psrk[13][2]));
    Iko[13][2][2] = (psik[13][2][2]-((mkrk[13][2][0]*psrk[13][1])-(
      mkrk[13][2][1]*psrk[13][0])));
    Iko[14][0][0] = (ik[11][0][0]-((mkrk[14][0][1]*rk[11][2])-(mkrk[14][0][2]*
      rk[11][1])));
    Iko[14][0][1] = (ik[11][0][1]-(mkrk[14][0][2]*rk[11][0]));
    Iko[14][0][2] = (ik[11][0][2]+(mkrk[14][0][1]*rk[11][0]));
    Iko[14][1][0] = (ik[11][1][0]+(mkrk[14][1][2]*rk[11][1]));
    Iko[14][1][1] = (ik[11][1][1]-((mkrk[14][1][2]*rk[11][0])-(mkrk[14][1][0]*
      rk[11][2])));
    Iko[14][1][2] = (ik[11][1][2]-(mkrk[14][1][0]*rk[11][1]));
    Iko[14][2][0] = (ik[11][2][0]-(mkrk[14][2][1]*rk[11][2]));
    Iko[14][2][1] = (ik[11][2][1]+(mkrk[14][2][0]*rk[11][2]));
    Iko[14][2][2] = (ik[11][2][2]-((mkrk[14][2][0]*rk[11][1])-(mkrk[14][2][1]*
      rk[11][0])));
    Iko[15][0][0] = (ik[12][0][0]-((mkrk[15][0][1]*rk[12][2])-(mkrk[15][0][2]*
      rk[12][1])));
    Iko[15][0][1] = (ik[12][0][1]-(mkrk[15][0][2]*rk[12][0]));
    Iko[15][0][2] = (ik[12][0][2]+(mkrk[15][0][1]*rk[12][0]));
    Iko[15][1][0] = (ik[12][1][0]+(mkrk[15][1][2]*rk[12][1]));
    Iko[15][1][1] = (ik[12][1][1]-((mkrk[15][1][2]*rk[12][0])-(mkrk[15][1][0]*
      rk[12][2])));
    Iko[15][1][2] = (ik[12][1][2]-(mkrk[15][1][0]*rk[12][1]));
    Iko[15][2][0] = (ik[12][2][0]-(mkrk[15][2][1]*rk[12][2]));
    Iko[15][2][1] = (ik[12][2][1]+(mkrk[15][2][0]*rk[12][2]));
    Iko[15][2][2] = (ik[12][2][2]-((mkrk[15][2][0]*rk[12][1])-(mkrk[15][2][1]*
      rk[12][0])));
    Iko[16][0][0] = (ik[13][0][0]-((mkrk[16][0][1]*rk[13][2])-(mkrk[16][0][2]*
      rk[13][1])));
    Iko[16][0][1] = (ik[13][0][1]-(mkrk[16][0][2]*rk[13][0]));
    Iko[16][0][2] = (ik[13][0][2]+(mkrk[16][0][1]*rk[13][0]));
    Iko[16][1][0] = (ik[13][1][0]+(mkrk[16][1][2]*rk[13][1]));
    Iko[16][1][1] = (ik[13][1][1]-((mkrk[16][1][2]*rk[13][0])-(mkrk[16][1][0]*
      rk[13][2])));
    Iko[16][1][2] = (ik[13][1][2]-(mkrk[16][1][0]*rk[13][1]));
    Iko[16][2][0] = (ik[13][2][0]-(mkrk[16][2][1]*rk[13][2]));
    Iko[16][2][1] = (ik[13][2][1]+(mkrk[16][2][0]*rk[13][2]));
    Iko[16][2][2] = (ik[13][2][2]-((mkrk[16][2][0]*rk[13][1])-(mkrk[16][2][1]*
      rk[13][0])));
    Iko[17][0][0] = (psik[17][0][0]-((mkrk[17][0][1]*psrk[17][2])-(
      mkrk[17][0][2]*psrk[17][1])));
    Iko[17][0][1] = (psik[17][0][1]-(mkrk[17][0][2]*psrk[17][0]));
    Iko[17][0][2] = (psik[17][0][2]+(mkrk[17][0][1]*psrk[17][0]));
    Iko[17][1][0] = (psik[17][1][0]+(mkrk[17][1][2]*psrk[17][1]));
    Iko[17][1][1] = (psik[17][1][1]-((mkrk[17][1][2]*psrk[17][0])-(
      mkrk[17][1][0]*psrk[17][2])));
    Iko[17][1][2] = (psik[17][1][2]-(mkrk[17][1][0]*psrk[17][1]));
    Iko[17][2][0] = (psik[17][2][0]-(mkrk[17][2][1]*psrk[17][2]));
    Iko[17][2][1] = (psik[17][2][1]+(mkrk[17][2][0]*psrk[17][2]));
    Iko[17][2][2] = (psik[17][2][2]-((mkrk[17][2][0]*psrk[17][1])-(
      mkrk[17][2][1]*psrk[17][0])));
    Iko[18][0][0] = (ik[16][0][0]-((mkrk[18][0][1]*rk[16][2])-(mkrk[18][0][2]*
      rk[16][1])));
    Iko[18][0][1] = (ik[16][0][1]-(mkrk[18][0][2]*rk[16][0]));
    Iko[18][0][2] = (ik[16][0][2]+(mkrk[18][0][1]*rk[16][0]));
    Iko[18][1][0] = (ik[16][1][0]+(mkrk[18][1][2]*rk[16][1]));
    Iko[18][1][1] = (ik[16][1][1]-((mkrk[18][1][2]*rk[16][0])-(mkrk[18][1][0]*
      rk[16][2])));
    Iko[18][1][2] = (ik[16][1][2]-(mkrk[18][1][0]*rk[16][1]));
    Iko[18][2][0] = (ik[16][2][0]-(mkrk[18][2][1]*rk[16][2]));
    Iko[18][2][1] = (ik[16][2][1]+(mkrk[18][2][0]*rk[16][2]));
    Iko[18][2][2] = (ik[16][2][2]-((mkrk[18][2][0]*rk[16][1])-(mkrk[18][2][1]*
      rk[16][0])));
    Iko[19][0][0] = (ik[17][0][0]-((mkrk[19][0][1]*rk[17][2])-(mkrk[19][0][2]*
      rk[17][1])));
    Iko[19][0][1] = (ik[17][0][1]-(mkrk[19][0][2]*rk[17][0]));
    Iko[19][0][2] = (ik[17][0][2]+(mkrk[19][0][1]*rk[17][0]));
    Iko[19][1][0] = (ik[17][1][0]+(mkrk[19][1][2]*rk[17][1]));
    Iko[19][1][1] = (ik[17][1][1]-((mkrk[19][1][2]*rk[17][0])-(mkrk[19][1][0]*
      rk[17][2])));
    Iko[19][1][2] = (ik[17][1][2]-(mkrk[19][1][0]*rk[17][1]));
    Iko[19][2][0] = (ik[17][2][0]-(mkrk[19][2][1]*rk[17][2]));
    Iko[19][2][1] = (ik[17][2][1]+(mkrk[19][2][0]*rk[17][2]));
    Iko[19][2][2] = (ik[17][2][2]-((mkrk[19][2][0]*rk[17][1])-(mkrk[19][2][1]*
      rk[17][0])));
    Iko[20][0][0] = (ik[18][0][0]-((mkrk[20][0][1]*rk[18][2])-(mkrk[20][0][2]*
      rk[18][1])));
    Iko[20][0][1] = (ik[18][0][1]-(mkrk[20][0][2]*rk[18][0]));
    Iko[20][0][2] = (ik[18][0][2]+(mkrk[20][0][1]*rk[18][0]));
    Iko[20][1][0] = (ik[18][1][0]+(mkrk[20][1][2]*rk[18][1]));
    Iko[20][1][1] = (ik[18][1][1]-((mkrk[20][1][2]*rk[18][0])-(mkrk[20][1][0]*
      rk[18][2])));
    Iko[20][1][2] = (ik[18][1][2]-(mkrk[20][1][0]*rk[18][1]));
    Iko[20][2][0] = (ik[18][2][0]-(mkrk[20][2][1]*rk[18][2]));
    Iko[20][2][1] = (ik[18][2][1]+(mkrk[20][2][0]*rk[18][2]));
    Iko[20][2][2] = (ik[18][2][2]-((mkrk[20][2][0]*rk[18][1])-(mkrk[20][2][1]*
      rk[18][0])));
    Iko[21][0][0] = (psik[21][0][0]-((mkrk[21][0][1]*psrk[21][2])-(
      mkrk[21][0][2]*psrk[21][1])));
    Iko[21][0][1] = (psik[21][0][1]-(mkrk[21][0][2]*psrk[21][0]));
    Iko[21][0][2] = (psik[21][0][2]+(mkrk[21][0][1]*psrk[21][0]));
    Iko[21][1][0] = (psik[21][1][0]+(mkrk[21][1][2]*psrk[21][1]));
    Iko[21][1][1] = (psik[21][1][1]-((mkrk[21][1][2]*psrk[21][0])-(
      mkrk[21][1][0]*psrk[21][2])));
    Iko[21][1][2] = (psik[21][1][2]-(mkrk[21][1][0]*psrk[21][1]));
    Iko[21][2][0] = (psik[21][2][0]-(mkrk[21][2][1]*psrk[21][2]));
    Iko[21][2][1] = (psik[21][2][1]+(mkrk[21][2][0]*psrk[21][2]));
    Iko[21][2][2] = (psik[21][2][2]-((mkrk[21][2][0]*psrk[21][1])-(
      mkrk[21][2][1]*psrk[21][0])));
    allegro_air_serialno(&i);
    if (i != 30123) {
        allegro_air_seterr(7,41);
    }
    roustate = 1;
}

/* Convert state to form using 1-2-3 Euler angles for ball joints. */

void allegro_air_st2ang(double st[23],
    double stang[22])
{
    int i;
    double dc[3][3];

    for (i = 0; i < 22; i++) {
        stang[i] = st[i];
    }
    allegro_air_quat2dc(st[3],st[4],st[5],st[22],dc);
    allegro_air_dc2ang(dc,&stang[3],&stang[4],&stang[5]);
}

/* Convert 1-2-3 form of state back to Euler parameters for ball joints. */

void allegro_air_ang2st(double stang[22],
    double st[23])
{
    int i;
    double dc[3][3];

    for (i = 0; i < 22; i++) {
        st[i] = stang[i];
    }
    allegro_air_ang2dc(stang[3],stang[4],stang[5],dc);
    allegro_air_dc2quat(dc,&st[3],&st[4],&st[5],&st[22]);
}

/* Normalize Euler parameters in state. */

void allegro_air_nrmsterr(double st[23],
    double normst[23],
    int routine)
{
    int i;
    double norm;

    for (i = 0; i < 23; i++) {
        normst[i] = st[i];
    }
    norm = sqrt(st[3]*st[3]+st[4]*st[4]+st[5]*st[5]+st[22]*st[22]);
    if (routine != 0) {
        if ((norm < .9) || (norm > 1.1)) {
            allegro_air_seterr(routine,14);
        }
    }
    if (norm == 0.) {
        normst[22] = 1.;
        norm = 1.;
    }
    norm = 1./norm;
    normst[3] = normst[3]*norm;
    normst[4] = normst[4]*norm;
    normst[5] = normst[5]*norm;
    normst[22] = normst[22]*norm;
}

void allegro_air_normst(double st[23],
    double normst[23])
{

    allegro_air_nrmsterr(st,normst,0);
}

void allegro_air_state(double timein,
    double qin[23],
    double uin[22])
{
/*
Compute kinematic information and store it in sdgstate.

Generated 15-Apr-2019 14:28:10 by SD/FAST, Kane's formulation
(sdfast B.2.8 #30123) on machine ID unknown
Copyright (c) 1990-1997 Symbolic Dynamics, Inc.
Copyright (c) 1990-1997 Parametric Technology Corp.
RESTRICTED RIGHTS LEGEND: Use, duplication, or disclosure by the U.S.
Government is subject to restrictions as set forth in subparagraph
(c)(1)(ii) of the Rights in Technical Data and Computer Software
clause at DFARS 52.227-7013 and similar clauses in the FAR and NASA
FAR Supplement.  Symbolic Dynamics, Inc., Mountain View, CA 94041
*/
    int i,j,qchg,uchg;
    double ee,stab;

    if ((roustate != 1) && (roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(8,22);
        return;
    }
    if (roustate == 1) {
        for (i = 0; i < 22; i++) {
            if (presq[i] == 1) {
                allegro_air_seterr(8,31);
            }
        }
    }
/*
See if time or any qs have changed since last call
*/
    if ((roustate != 1) && (timein == curtim)) {
        qchg = 0;
        for (i = 0; i < 23; i++) {
            if (qin[i] != q[i]) {
                qchg = 1;
                break;
            }
        }
    } else {
        qchg = 1;
    }
/*
If time and qs are unchanged, check us
*/
    if (qchg == 0) {
        uchg = 0;
        for (i = 0; i < 22; i++) {
            if (uin[i] != u[i]) {
                uchg = 1;
                break;
            }
        }
    } else {
        uchg = 1;
    }
    curtim = timein;
    roustate = 2;
    if (qchg == 0) {
        goto skipqs;
    }
/*
Position-related variables need to be computed
*/
    vpkflg = 0;
    mmflg = 0;
    mmlduflg = 0;
    wwflg = 0;
    for (i = 0; i < 23; i++) {
        q[i] = qin[i];
    }
/*
Normalize Euler parameters in state
*/
    allegro_air_nrmsterr(q,qn,8);
/*
Compute sines and cosines of q
*/
    s6 = sin(q[6]);
    c6 = cos(q[6]);
    s7 = sin(q[7]);
    c7 = cos(q[7]);
    s8 = sin(q[8]);
    c8 = cos(q[8]);
    s9 = sin(q[9]);
    c9 = cos(q[9]);
    s10 = sin(q[10]);
    c10 = cos(q[10]);
    s11 = sin(q[11]);
    c11 = cos(q[11]);
    s12 = sin(q[12]);
    c12 = cos(q[12]);
    s13 = sin(q[13]);
    c13 = cos(q[13]);
    s14 = sin(q[14]);
    c14 = cos(q[14]);
    s15 = sin(q[15]);
    c15 = cos(q[15]);
    s16 = sin(q[16]);
    c16 = cos(q[16]);
    s17 = sin(q[17]);
    c17 = cos(q[17]);
    s18 = sin(q[18]);
    c18 = cos(q[18]);
    s19 = sin(q[19]);
    c19 = cos(q[19]);
    s20 = sin(q[20]);
    c20 = cos(q[20]);
    s21 = sin(q[21]);
    c21 = cos(q[21]);
/*
Compute across-axis direction cosines Cik
*/
    Cik[3][0][0] = (1.-(2.*((qn[4]*qn[4])+(qn[5]*qn[5]))));
    Cik[3][0][1] = (2.*((qn[3]*qn[4])-(qn[5]*qn[22])));
    Cik[3][0][2] = (2.*((qn[3]*qn[5])+(qn[4]*qn[22])));
    Cik[3][1][0] = (2.*((qn[3]*qn[4])+(qn[5]*qn[22])));
    Cik[3][1][1] = (1.-(2.*((qn[3]*qn[3])+(qn[5]*qn[5]))));
    Cik[3][1][2] = (2.*((qn[4]*qn[5])-(qn[3]*qn[22])));
    Cik[3][2][0] = (2.*((qn[3]*qn[5])-(qn[4]*qn[22])));
    Cik[3][2][1] = (2.*((qn[3]*qn[22])+(qn[4]*qn[5])));
    Cik[3][2][2] = (1.-(2.*((qn[3]*qn[3])+(qn[4]*qn[4]))));
    Cik[6][0][0] = ((pin[6][0]*pin[6][0])+(c6*(1.-(pin[6][0]*pin[6][0]))));
    Cik[6][0][1] = (((pin[6][0]*pin[6][1])-(pin[6][2]*s6))-(c6*(pin[6][0]*
      pin[6][1])));
    Cik[6][0][2] = (((pin[6][0]*pin[6][2])+(pin[6][1]*s6))-(c6*(pin[6][0]*
      pin[6][2])));
    Cik[6][1][0] = (((pin[6][0]*pin[6][1])+(pin[6][2]*s6))-(c6*(pin[6][0]*
      pin[6][1])));
    Cik[6][1][1] = ((pin[6][1]*pin[6][1])+(c6*(1.-(pin[6][1]*pin[6][1]))));
    Cik[6][1][2] = (((pin[6][1]*pin[6][2])-(pin[6][0]*s6))-(c6*(pin[6][1]*
      pin[6][2])));
    Cik[6][2][0] = (((pin[6][0]*pin[6][2])-(pin[6][1]*s6))-(c6*(pin[6][0]*
      pin[6][2])));
    Cik[6][2][1] = (((pin[6][0]*s6)+(pin[6][1]*pin[6][2]))-(c6*(pin[6][1]*
      pin[6][2])));
    Cik[6][2][2] = ((pin[6][2]*pin[6][2])+(c6*(1.-(pin[6][2]*pin[6][2]))));
    Cik[7][0][0] = ((pin[7][0]*pin[7][0])+(c7*(1.-(pin[7][0]*pin[7][0]))));
    Cik[7][0][1] = (((pin[7][0]*pin[7][1])-(pin[7][2]*s7))-(c7*(pin[7][0]*
      pin[7][1])));
    Cik[7][0][2] = (((pin[7][0]*pin[7][2])+(pin[7][1]*s7))-(c7*(pin[7][0]*
      pin[7][2])));
    Cik[7][1][0] = (((pin[7][0]*pin[7][1])+(pin[7][2]*s7))-(c7*(pin[7][0]*
      pin[7][1])));
    Cik[7][1][1] = ((pin[7][1]*pin[7][1])+(c7*(1.-(pin[7][1]*pin[7][1]))));
    Cik[7][1][2] = (((pin[7][1]*pin[7][2])-(pin[7][0]*s7))-(c7*(pin[7][1]*
      pin[7][2])));
    Cik[7][2][0] = (((pin[7][0]*pin[7][2])-(pin[7][1]*s7))-(c7*(pin[7][0]*
      pin[7][2])));
    Cik[7][2][1] = (((pin[7][0]*s7)+(pin[7][1]*pin[7][2]))-(c7*(pin[7][1]*
      pin[7][2])));
    Cik[7][2][2] = ((pin[7][2]*pin[7][2])+(c7*(1.-(pin[7][2]*pin[7][2]))));
    Cik[8][0][0] = ((pin[8][0]*pin[8][0])+(c8*(1.-(pin[8][0]*pin[8][0]))));
    Cik[8][0][1] = (((pin[8][0]*pin[8][1])-(pin[8][2]*s8))-(c8*(pin[8][0]*
      pin[8][1])));
    Cik[8][0][2] = (((pin[8][0]*pin[8][2])+(pin[8][1]*s8))-(c8*(pin[8][0]*
      pin[8][2])));
    Cik[8][1][0] = (((pin[8][0]*pin[8][1])+(pin[8][2]*s8))-(c8*(pin[8][0]*
      pin[8][1])));
    Cik[8][1][1] = ((pin[8][1]*pin[8][1])+(c8*(1.-(pin[8][1]*pin[8][1]))));
    Cik[8][1][2] = (((pin[8][1]*pin[8][2])-(pin[8][0]*s8))-(c8*(pin[8][1]*
      pin[8][2])));
    Cik[8][2][0] = (((pin[8][0]*pin[8][2])-(pin[8][1]*s8))-(c8*(pin[8][0]*
      pin[8][2])));
    Cik[8][2][1] = (((pin[8][0]*s8)+(pin[8][1]*pin[8][2]))-(c8*(pin[8][1]*
      pin[8][2])));
    Cik[8][2][2] = ((pin[8][2]*pin[8][2])+(c8*(1.-(pin[8][2]*pin[8][2]))));
    Cik[9][0][0] = ((pin[9][0]*pin[9][0])+(c9*(1.-(pin[9][0]*pin[9][0]))));
    Cik[9][0][1] = (((pin[9][0]*pin[9][1])-(pin[9][2]*s9))-(c9*(pin[9][0]*
      pin[9][1])));
    Cik[9][0][2] = (((pin[9][0]*pin[9][2])+(pin[9][1]*s9))-(c9*(pin[9][0]*
      pin[9][2])));
    Cik[9][1][0] = (((pin[9][0]*pin[9][1])+(pin[9][2]*s9))-(c9*(pin[9][0]*
      pin[9][1])));
    Cik[9][1][1] = ((pin[9][1]*pin[9][1])+(c9*(1.-(pin[9][1]*pin[9][1]))));
    Cik[9][1][2] = (((pin[9][1]*pin[9][2])-(pin[9][0]*s9))-(c9*(pin[9][1]*
      pin[9][2])));
    Cik[9][2][0] = (((pin[9][0]*pin[9][2])-(pin[9][1]*s9))-(c9*(pin[9][0]*
      pin[9][2])));
    Cik[9][2][1] = (((pin[9][0]*s9)+(pin[9][1]*pin[9][2]))-(c9*(pin[9][1]*
      pin[9][2])));
    Cik[9][2][2] = ((pin[9][2]*pin[9][2])+(c9*(1.-(pin[9][2]*pin[9][2]))));
    Cik[10][0][0] = ((pin[10][0]*pin[10][0])+(c10*(1.-(pin[10][0]*pin[10][0]))))
      ;
    Cik[10][0][1] = (((pin[10][0]*pin[10][1])-(pin[10][2]*s10))-(c10*(pin[10][0]
      *pin[10][1])));
    Cik[10][0][2] = (((pin[10][0]*pin[10][2])+(pin[10][1]*s10))-(c10*(pin[10][0]
      *pin[10][2])));
    Cik[10][1][0] = (((pin[10][0]*pin[10][1])+(pin[10][2]*s10))-(c10*(pin[10][0]
      *pin[10][1])));
    Cik[10][1][1] = ((pin[10][1]*pin[10][1])+(c10*(1.-(pin[10][1]*pin[10][1]))))
      ;
    Cik[10][1][2] = (((pin[10][1]*pin[10][2])-(pin[10][0]*s10))-(c10*(pin[10][1]
      *pin[10][2])));
    Cik[10][2][0] = (((pin[10][0]*pin[10][2])-(pin[10][1]*s10))-(c10*(pin[10][0]
      *pin[10][2])));
    Cik[10][2][1] = (((pin[10][0]*s10)+(pin[10][1]*pin[10][2]))-(c10*(pin[10][1]
      *pin[10][2])));
    Cik[10][2][2] = ((pin[10][2]*pin[10][2])+(c10*(1.-(pin[10][2]*pin[10][2]))))
      ;
    Cik[11][0][0] = ((pin[11][0]*pin[11][0])+(c11*(1.-(pin[11][0]*pin[11][0]))))
      ;
    Cik[11][0][1] = (((pin[11][0]*pin[11][1])-(pin[11][2]*s11))-(c11*(pin[11][0]
      *pin[11][1])));
    Cik[11][0][2] = (((pin[11][0]*pin[11][2])+(pin[11][1]*s11))-(c11*(pin[11][0]
      *pin[11][2])));
    Cik[11][1][0] = (((pin[11][0]*pin[11][1])+(pin[11][2]*s11))-(c11*(pin[11][0]
      *pin[11][1])));
    Cik[11][1][1] = ((pin[11][1]*pin[11][1])+(c11*(1.-(pin[11][1]*pin[11][1]))))
      ;
    Cik[11][1][2] = (((pin[11][1]*pin[11][2])-(pin[11][0]*s11))-(c11*(pin[11][1]
      *pin[11][2])));
    Cik[11][2][0] = (((pin[11][0]*pin[11][2])-(pin[11][1]*s11))-(c11*(pin[11][0]
      *pin[11][2])));
    Cik[11][2][1] = (((pin[11][0]*s11)+(pin[11][1]*pin[11][2]))-(c11*(pin[11][1]
      *pin[11][2])));
    Cik[11][2][2] = ((pin[11][2]*pin[11][2])+(c11*(1.-(pin[11][2]*pin[11][2]))))
      ;
    Cik[12][0][0] = ((pin[12][0]*pin[12][0])+(c12*(1.-(pin[12][0]*pin[12][0]))))
      ;
    Cik[12][0][1] = (((pin[12][0]*pin[12][1])-(pin[12][2]*s12))-(c12*(pin[12][0]
      *pin[12][1])));
    Cik[12][0][2] = (((pin[12][0]*pin[12][2])+(pin[12][1]*s12))-(c12*(pin[12][0]
      *pin[12][2])));
    Cik[12][1][0] = (((pin[12][0]*pin[12][1])+(pin[12][2]*s12))-(c12*(pin[12][0]
      *pin[12][1])));
    Cik[12][1][1] = ((pin[12][1]*pin[12][1])+(c12*(1.-(pin[12][1]*pin[12][1]))))
      ;
    Cik[12][1][2] = (((pin[12][1]*pin[12][2])-(pin[12][0]*s12))-(c12*(pin[12][1]
      *pin[12][2])));
    Cik[12][2][0] = (((pin[12][0]*pin[12][2])-(pin[12][1]*s12))-(c12*(pin[12][0]
      *pin[12][2])));
    Cik[12][2][1] = (((pin[12][0]*s12)+(pin[12][1]*pin[12][2]))-(c12*(pin[12][1]
      *pin[12][2])));
    Cik[12][2][2] = ((pin[12][2]*pin[12][2])+(c12*(1.-(pin[12][2]*pin[12][2]))))
      ;
    Cik[13][0][0] = ((pin[13][0]*pin[13][0])+(c13*(1.-(pin[13][0]*pin[13][0]))))
      ;
    Cik[13][0][1] = (((pin[13][0]*pin[13][1])-(pin[13][2]*s13))-(c13*(pin[13][0]
      *pin[13][1])));
    Cik[13][0][2] = (((pin[13][0]*pin[13][2])+(pin[13][1]*s13))-(c13*(pin[13][0]
      *pin[13][2])));
    Cik[13][1][0] = (((pin[13][0]*pin[13][1])+(pin[13][2]*s13))-(c13*(pin[13][0]
      *pin[13][1])));
    Cik[13][1][1] = ((pin[13][1]*pin[13][1])+(c13*(1.-(pin[13][1]*pin[13][1]))))
      ;
    Cik[13][1][2] = (((pin[13][1]*pin[13][2])-(pin[13][0]*s13))-(c13*(pin[13][1]
      *pin[13][2])));
    Cik[13][2][0] = (((pin[13][0]*pin[13][2])-(pin[13][1]*s13))-(c13*(pin[13][0]
      *pin[13][2])));
    Cik[13][2][1] = (((pin[13][0]*s13)+(pin[13][1]*pin[13][2]))-(c13*(pin[13][1]
      *pin[13][2])));
    Cik[13][2][2] = ((pin[13][2]*pin[13][2])+(c13*(1.-(pin[13][2]*pin[13][2]))))
      ;
    Cik[14][0][0] = ((pin[14][0]*pin[14][0])+(c14*(1.-(pin[14][0]*pin[14][0]))))
      ;
    Cik[14][0][1] = (((pin[14][0]*pin[14][1])-(pin[14][2]*s14))-(c14*(pin[14][0]
      *pin[14][1])));
    Cik[14][0][2] = (((pin[14][0]*pin[14][2])+(pin[14][1]*s14))-(c14*(pin[14][0]
      *pin[14][2])));
    Cik[14][1][0] = (((pin[14][0]*pin[14][1])+(pin[14][2]*s14))-(c14*(pin[14][0]
      *pin[14][1])));
    Cik[14][1][1] = ((pin[14][1]*pin[14][1])+(c14*(1.-(pin[14][1]*pin[14][1]))))
      ;
    Cik[14][1][2] = (((pin[14][1]*pin[14][2])-(pin[14][0]*s14))-(c14*(pin[14][1]
      *pin[14][2])));
    Cik[14][2][0] = (((pin[14][0]*pin[14][2])-(pin[14][1]*s14))-(c14*(pin[14][0]
      *pin[14][2])));
    Cik[14][2][1] = (((pin[14][0]*s14)+(pin[14][1]*pin[14][2]))-(c14*(pin[14][1]
      *pin[14][2])));
    Cik[14][2][2] = ((pin[14][2]*pin[14][2])+(c14*(1.-(pin[14][2]*pin[14][2]))))
      ;
    Cik[15][0][0] = ((pin[15][0]*pin[15][0])+(c15*(1.-(pin[15][0]*pin[15][0]))))
      ;
    Cik[15][0][1] = (((pin[15][0]*pin[15][1])-(pin[15][2]*s15))-(c15*(pin[15][0]
      *pin[15][1])));
    Cik[15][0][2] = (((pin[15][0]*pin[15][2])+(pin[15][1]*s15))-(c15*(pin[15][0]
      *pin[15][2])));
    Cik[15][1][0] = (((pin[15][0]*pin[15][1])+(pin[15][2]*s15))-(c15*(pin[15][0]
      *pin[15][1])));
    Cik[15][1][1] = ((pin[15][1]*pin[15][1])+(c15*(1.-(pin[15][1]*pin[15][1]))))
      ;
    Cik[15][1][2] = (((pin[15][1]*pin[15][2])-(pin[15][0]*s15))-(c15*(pin[15][1]
      *pin[15][2])));
    Cik[15][2][0] = (((pin[15][0]*pin[15][2])-(pin[15][1]*s15))-(c15*(pin[15][0]
      *pin[15][2])));
    Cik[15][2][1] = (((pin[15][0]*s15)+(pin[15][1]*pin[15][2]))-(c15*(pin[15][1]
      *pin[15][2])));
    Cik[15][2][2] = ((pin[15][2]*pin[15][2])+(c15*(1.-(pin[15][2]*pin[15][2]))))
      ;
    Cik[16][0][0] = ((pin[16][0]*pin[16][0])+(c16*(1.-(pin[16][0]*pin[16][0]))))
      ;
    Cik[16][0][1] = (((pin[16][0]*pin[16][1])-(pin[16][2]*s16))-(c16*(pin[16][0]
      *pin[16][1])));
    Cik[16][0][2] = (((pin[16][0]*pin[16][2])+(pin[16][1]*s16))-(c16*(pin[16][0]
      *pin[16][2])));
    Cik[16][1][0] = (((pin[16][0]*pin[16][1])+(pin[16][2]*s16))-(c16*(pin[16][0]
      *pin[16][1])));
    Cik[16][1][1] = ((pin[16][1]*pin[16][1])+(c16*(1.-(pin[16][1]*pin[16][1]))))
      ;
    Cik[16][1][2] = (((pin[16][1]*pin[16][2])-(pin[16][0]*s16))-(c16*(pin[16][1]
      *pin[16][2])));
    Cik[16][2][0] = (((pin[16][0]*pin[16][2])-(pin[16][1]*s16))-(c16*(pin[16][0]
      *pin[16][2])));
    Cik[16][2][1] = (((pin[16][0]*s16)+(pin[16][1]*pin[16][2]))-(c16*(pin[16][1]
      *pin[16][2])));
    Cik[16][2][2] = ((pin[16][2]*pin[16][2])+(c16*(1.-(pin[16][2]*pin[16][2]))))
      ;
    Cik[17][0][0] = ((pin[17][0]*pin[17][0])+(c17*(1.-(pin[17][0]*pin[17][0]))))
      ;
    Cik[17][0][1] = (((pin[17][0]*pin[17][1])-(pin[17][2]*s17))-(c17*(pin[17][0]
      *pin[17][1])));
    Cik[17][0][2] = (((pin[17][0]*pin[17][2])+(pin[17][1]*s17))-(c17*(pin[17][0]
      *pin[17][2])));
    Cik[17][1][0] = (((pin[17][0]*pin[17][1])+(pin[17][2]*s17))-(c17*(pin[17][0]
      *pin[17][1])));
    Cik[17][1][1] = ((pin[17][1]*pin[17][1])+(c17*(1.-(pin[17][1]*pin[17][1]))))
      ;
    Cik[17][1][2] = (((pin[17][1]*pin[17][2])-(pin[17][0]*s17))-(c17*(pin[17][1]
      *pin[17][2])));
    Cik[17][2][0] = (((pin[17][0]*pin[17][2])-(pin[17][1]*s17))-(c17*(pin[17][0]
      *pin[17][2])));
    Cik[17][2][1] = (((pin[17][0]*s17)+(pin[17][1]*pin[17][2]))-(c17*(pin[17][1]
      *pin[17][2])));
    Cik[17][2][2] = ((pin[17][2]*pin[17][2])+(c17*(1.-(pin[17][2]*pin[17][2]))))
      ;
    Cik[18][0][0] = ((pin[18][0]*pin[18][0])+(c18*(1.-(pin[18][0]*pin[18][0]))))
      ;
    Cik[18][0][1] = (((pin[18][0]*pin[18][1])-(pin[18][2]*s18))-(c18*(pin[18][0]
      *pin[18][1])));
    Cik[18][0][2] = (((pin[18][0]*pin[18][2])+(pin[18][1]*s18))-(c18*(pin[18][0]
      *pin[18][2])));
    Cik[18][1][0] = (((pin[18][0]*pin[18][1])+(pin[18][2]*s18))-(c18*(pin[18][0]
      *pin[18][1])));
    Cik[18][1][1] = ((pin[18][1]*pin[18][1])+(c18*(1.-(pin[18][1]*pin[18][1]))))
      ;
    Cik[18][1][2] = (((pin[18][1]*pin[18][2])-(pin[18][0]*s18))-(c18*(pin[18][1]
      *pin[18][2])));
    Cik[18][2][0] = (((pin[18][0]*pin[18][2])-(pin[18][1]*s18))-(c18*(pin[18][0]
      *pin[18][2])));
    Cik[18][2][1] = (((pin[18][0]*s18)+(pin[18][1]*pin[18][2]))-(c18*(pin[18][1]
      *pin[18][2])));
    Cik[18][2][2] = ((pin[18][2]*pin[18][2])+(c18*(1.-(pin[18][2]*pin[18][2]))))
      ;
    Cik[19][0][0] = ((pin[19][0]*pin[19][0])+(c19*(1.-(pin[19][0]*pin[19][0]))))
      ;
    Cik[19][0][1] = (((pin[19][0]*pin[19][1])-(pin[19][2]*s19))-(c19*(pin[19][0]
      *pin[19][1])));
    Cik[19][0][2] = (((pin[19][0]*pin[19][2])+(pin[19][1]*s19))-(c19*(pin[19][0]
      *pin[19][2])));
    Cik[19][1][0] = (((pin[19][0]*pin[19][1])+(pin[19][2]*s19))-(c19*(pin[19][0]
      *pin[19][1])));
    Cik[19][1][1] = ((pin[19][1]*pin[19][1])+(c19*(1.-(pin[19][1]*pin[19][1]))))
      ;
    Cik[19][1][2] = (((pin[19][1]*pin[19][2])-(pin[19][0]*s19))-(c19*(pin[19][1]
      *pin[19][2])));
    Cik[19][2][0] = (((pin[19][0]*pin[19][2])-(pin[19][1]*s19))-(c19*(pin[19][0]
      *pin[19][2])));
    Cik[19][2][1] = (((pin[19][0]*s19)+(pin[19][1]*pin[19][2]))-(c19*(pin[19][1]
      *pin[19][2])));
    Cik[19][2][2] = ((pin[19][2]*pin[19][2])+(c19*(1.-(pin[19][2]*pin[19][2]))))
      ;
    Cik[20][0][0] = ((pin[20][0]*pin[20][0])+(c20*(1.-(pin[20][0]*pin[20][0]))))
      ;
    Cik[20][0][1] = (((pin[20][0]*pin[20][1])-(pin[20][2]*s20))-(c20*(pin[20][0]
      *pin[20][1])));
    Cik[20][0][2] = (((pin[20][0]*pin[20][2])+(pin[20][1]*s20))-(c20*(pin[20][0]
      *pin[20][2])));
    Cik[20][1][0] = (((pin[20][0]*pin[20][1])+(pin[20][2]*s20))-(c20*(pin[20][0]
      *pin[20][1])));
    Cik[20][1][1] = ((pin[20][1]*pin[20][1])+(c20*(1.-(pin[20][1]*pin[20][1]))))
      ;
    Cik[20][1][2] = (((pin[20][1]*pin[20][2])-(pin[20][0]*s20))-(c20*(pin[20][1]
      *pin[20][2])));
    Cik[20][2][0] = (((pin[20][0]*pin[20][2])-(pin[20][1]*s20))-(c20*(pin[20][0]
      *pin[20][2])));
    Cik[20][2][1] = (((pin[20][0]*s20)+(pin[20][1]*pin[20][2]))-(c20*(pin[20][1]
      *pin[20][2])));
    Cik[20][2][2] = ((pin[20][2]*pin[20][2])+(c20*(1.-(pin[20][2]*pin[20][2]))))
      ;
    Cik[21][0][0] = ((pin[21][0]*pin[21][0])+(c21*(1.-(pin[21][0]*pin[21][0]))))
      ;
    Cik[21][0][1] = (((pin[21][0]*pin[21][1])-(pin[21][2]*s21))-(c21*(pin[21][0]
      *pin[21][1])));
    Cik[21][0][2] = (((pin[21][0]*pin[21][2])+(pin[21][1]*s21))-(c21*(pin[21][0]
      *pin[21][2])));
    Cik[21][1][0] = (((pin[21][0]*pin[21][1])+(pin[21][2]*s21))-(c21*(pin[21][0]
      *pin[21][1])));
    Cik[21][1][1] = ((pin[21][1]*pin[21][1])+(c21*(1.-(pin[21][1]*pin[21][1]))))
      ;
    Cik[21][1][2] = (((pin[21][1]*pin[21][2])-(pin[21][0]*s21))-(c21*(pin[21][1]
      *pin[21][2])));
    Cik[21][2][0] = (((pin[21][0]*pin[21][2])-(pin[21][1]*s21))-(c21*(pin[21][0]
      *pin[21][2])));
    Cik[21][2][1] = (((pin[21][0]*s21)+(pin[21][1]*pin[21][2]))-(c21*(pin[21][1]
      *pin[21][2])));
    Cik[21][2][2] = ((pin[21][2]*pin[21][2])+(c21*(1.-(pin[21][2]*pin[21][2]))))
      ;
/*
Compute across-joint direction cosines Cib
*/
/*
Compute gravity
*/
    gk[3][0] = ((Cik[3][2][0]*grav[2])+((Cik[3][0][0]*grav[0])+(Cik[3][1][0]*
      grav[1])));
    gk[3][1] = ((Cik[3][2][1]*grav[2])+((Cik[3][0][1]*grav[0])+(Cik[3][1][1]*
      grav[1])));
    gk[3][2] = ((Cik[3][2][2]*grav[2])+((Cik[3][0][2]*grav[0])+(Cik[3][1][2]*
      grav[1])));
    gk[6][0] = ((Cik[6][2][0]*gk[3][2])+((Cik[6][0][0]*gk[3][0])+(Cik[6][1][0]*
      gk[3][1])));
    gk[6][1] = ((Cik[6][2][1]*gk[3][2])+((Cik[6][0][1]*gk[3][0])+(Cik[6][1][1]*
      gk[3][1])));
    gk[6][2] = ((Cik[6][2][2]*gk[3][2])+((Cik[6][0][2]*gk[3][0])+(Cik[6][1][2]*
      gk[3][1])));
    gk[7][0] = ((Cik[7][2][0]*gk[6][2])+((Cik[7][0][0]*gk[6][0])+(Cik[7][1][0]*
      gk[6][1])));
    gk[7][1] = ((Cik[7][2][1]*gk[6][2])+((Cik[7][0][1]*gk[6][0])+(Cik[7][1][1]*
      gk[6][1])));
    gk[7][2] = ((Cik[7][2][2]*gk[6][2])+((Cik[7][0][2]*gk[6][0])+(Cik[7][1][2]*
      gk[6][1])));
    gk[8][0] = ((Cik[8][2][0]*gk[7][2])+((Cik[8][0][0]*gk[7][0])+(Cik[8][1][0]*
      gk[7][1])));
    gk[8][1] = ((Cik[8][2][1]*gk[7][2])+((Cik[8][0][1]*gk[7][0])+(Cik[8][1][1]*
      gk[7][1])));
    gk[8][2] = ((Cik[8][2][2]*gk[7][2])+((Cik[8][0][2]*gk[7][0])+(Cik[8][1][2]*
      gk[7][1])));
    gk[9][0] = ((Cik[9][2][0]*gk[8][2])+((Cik[9][0][0]*gk[8][0])+(Cik[9][1][0]*
      gk[8][1])));
    gk[9][1] = ((Cik[9][2][1]*gk[8][2])+((Cik[9][0][1]*gk[8][0])+(Cik[9][1][1]*
      gk[8][1])));
    gk[9][2] = ((Cik[9][2][2]*gk[8][2])+((Cik[9][0][2]*gk[8][0])+(Cik[9][1][2]*
      gk[8][1])));
    gk[10][0] = ((Cik[10][2][0]*gk[3][2])+((Cik[10][0][0]*gk[3][0])+(
      Cik[10][1][0]*gk[3][1])));
    gk[10][1] = ((Cik[10][2][1]*gk[3][2])+((Cik[10][0][1]*gk[3][0])+(
      Cik[10][1][1]*gk[3][1])));
    gk[10][2] = ((Cik[10][2][2]*gk[3][2])+((Cik[10][0][2]*gk[3][0])+(
      Cik[10][1][2]*gk[3][1])));
    gk[11][0] = ((Cik[11][2][0]*gk[10][2])+((Cik[11][0][0]*gk[10][0])+(
      Cik[11][1][0]*gk[10][1])));
    gk[11][1] = ((Cik[11][2][1]*gk[10][2])+((Cik[11][0][1]*gk[10][0])+(
      Cik[11][1][1]*gk[10][1])));
    gk[11][2] = ((Cik[11][2][2]*gk[10][2])+((Cik[11][0][2]*gk[10][0])+(
      Cik[11][1][2]*gk[10][1])));
    gk[12][0] = ((Cik[12][2][0]*gk[11][2])+((Cik[12][0][0]*gk[11][0])+(
      Cik[12][1][0]*gk[11][1])));
    gk[12][1] = ((Cik[12][2][1]*gk[11][2])+((Cik[12][0][1]*gk[11][0])+(
      Cik[12][1][1]*gk[11][1])));
    gk[12][2] = ((Cik[12][2][2]*gk[11][2])+((Cik[12][0][2]*gk[11][0])+(
      Cik[12][1][2]*gk[11][1])));
    gk[13][0] = ((Cik[13][2][0]*gk[12][2])+((Cik[13][0][0]*gk[12][0])+(
      Cik[13][1][0]*gk[12][1])));
    gk[13][1] = ((Cik[13][2][1]*gk[12][2])+((Cik[13][0][1]*gk[12][0])+(
      Cik[13][1][1]*gk[12][1])));
    gk[13][2] = ((Cik[13][2][2]*gk[12][2])+((Cik[13][0][2]*gk[12][0])+(
      Cik[13][1][2]*gk[12][1])));
    gk[14][0] = ((Cik[14][2][0]*gk[3][2])+((Cik[14][0][0]*gk[3][0])+(
      Cik[14][1][0]*gk[3][1])));
    gk[14][1] = ((Cik[14][2][1]*gk[3][2])+((Cik[14][0][1]*gk[3][0])+(
      Cik[14][1][1]*gk[3][1])));
    gk[14][2] = ((Cik[14][2][2]*gk[3][2])+((Cik[14][0][2]*gk[3][0])+(
      Cik[14][1][2]*gk[3][1])));
    gk[15][0] = ((Cik[15][2][0]*gk[14][2])+((Cik[15][0][0]*gk[14][0])+(
      Cik[15][1][0]*gk[14][1])));
    gk[15][1] = ((Cik[15][2][1]*gk[14][2])+((Cik[15][0][1]*gk[14][0])+(
      Cik[15][1][1]*gk[14][1])));
    gk[15][2] = ((Cik[15][2][2]*gk[14][2])+((Cik[15][0][2]*gk[14][0])+(
      Cik[15][1][2]*gk[14][1])));
    gk[16][0] = ((Cik[16][2][0]*gk[15][2])+((Cik[16][0][0]*gk[15][0])+(
      Cik[16][1][0]*gk[15][1])));
    gk[16][1] = ((Cik[16][2][1]*gk[15][2])+((Cik[16][0][1]*gk[15][0])+(
      Cik[16][1][1]*gk[15][1])));
    gk[16][2] = ((Cik[16][2][2]*gk[15][2])+((Cik[16][0][2]*gk[15][0])+(
      Cik[16][1][2]*gk[15][1])));
    gk[17][0] = ((Cik[17][2][0]*gk[16][2])+((Cik[17][0][0]*gk[16][0])+(
      Cik[17][1][0]*gk[16][1])));
    gk[17][1] = ((Cik[17][2][1]*gk[16][2])+((Cik[17][0][1]*gk[16][0])+(
      Cik[17][1][1]*gk[16][1])));
    gk[17][2] = ((Cik[17][2][2]*gk[16][2])+((Cik[17][0][2]*gk[16][0])+(
      Cik[17][1][2]*gk[16][1])));
    gk[18][0] = ((Cik[18][2][0]*gk[3][2])+((Cik[18][0][0]*gk[3][0])+(
      Cik[18][1][0]*gk[3][1])));
    gk[18][1] = ((Cik[18][2][1]*gk[3][2])+((Cik[18][0][1]*gk[3][0])+(
      Cik[18][1][1]*gk[3][1])));
    gk[18][2] = ((Cik[18][2][2]*gk[3][2])+((Cik[18][0][2]*gk[3][0])+(
      Cik[18][1][2]*gk[3][1])));
    gk[19][0] = ((Cik[19][2][0]*gk[18][2])+((Cik[19][0][0]*gk[18][0])+(
      Cik[19][1][0]*gk[18][1])));
    gk[19][1] = ((Cik[19][2][1]*gk[18][2])+((Cik[19][0][1]*gk[18][0])+(
      Cik[19][1][1]*gk[18][1])));
    gk[19][2] = ((Cik[19][2][2]*gk[18][2])+((Cik[19][0][2]*gk[18][0])+(
      Cik[19][1][2]*gk[18][1])));
    gk[20][0] = ((Cik[20][2][0]*gk[19][2])+((Cik[20][0][0]*gk[19][0])+(
      Cik[20][1][0]*gk[19][1])));
    gk[20][1] = ((Cik[20][2][1]*gk[19][2])+((Cik[20][0][1]*gk[19][0])+(
      Cik[20][1][1]*gk[19][1])));
    gk[20][2] = ((Cik[20][2][2]*gk[19][2])+((Cik[20][0][2]*gk[19][0])+(
      Cik[20][1][2]*gk[19][1])));
    gk[21][0] = ((Cik[21][2][0]*gk[20][2])+((Cik[21][0][0]*gk[20][0])+(
      Cik[21][1][0]*gk[20][1])));
    gk[21][1] = ((Cik[21][2][1]*gk[20][2])+((Cik[21][0][1]*gk[20][0])+(
      Cik[21][1][1]*gk[20][1])));
    gk[21][2] = ((Cik[21][2][2]*gk[20][2])+((Cik[21][0][2]*gk[20][0])+(
      Cik[21][1][2]*gk[20][1])));
/*
Compute cnk & cnb (direction cosines in N)
*/
    cnk[6][0][0] = ((Cik[3][0][2]*Cik[6][2][0])+((Cik[3][0][0]*Cik[6][0][0])+(
      Cik[3][0][1]*Cik[6][1][0])));
    cnk[6][0][1] = ((Cik[3][0][2]*Cik[6][2][1])+((Cik[3][0][0]*Cik[6][0][1])+(
      Cik[3][0][1]*Cik[6][1][1])));
    cnk[6][0][2] = ((Cik[3][0][2]*Cik[6][2][2])+((Cik[3][0][0]*Cik[6][0][2])+(
      Cik[3][0][1]*Cik[6][1][2])));
    cnk[6][1][0] = ((Cik[3][1][2]*Cik[6][2][0])+((Cik[3][1][0]*Cik[6][0][0])+(
      Cik[3][1][1]*Cik[6][1][0])));
    cnk[6][1][1] = ((Cik[3][1][2]*Cik[6][2][1])+((Cik[3][1][0]*Cik[6][0][1])+(
      Cik[3][1][1]*Cik[6][1][1])));
    cnk[6][1][2] = ((Cik[3][1][2]*Cik[6][2][2])+((Cik[3][1][0]*Cik[6][0][2])+(
      Cik[3][1][1]*Cik[6][1][2])));
    cnk[6][2][0] = ((Cik[3][2][2]*Cik[6][2][0])+((Cik[3][2][0]*Cik[6][0][0])+(
      Cik[3][2][1]*Cik[6][1][0])));
    cnk[6][2][1] = ((Cik[3][2][2]*Cik[6][2][1])+((Cik[3][2][0]*Cik[6][0][1])+(
      Cik[3][2][1]*Cik[6][1][1])));
    cnk[6][2][2] = ((Cik[3][2][2]*Cik[6][2][2])+((Cik[3][2][0]*Cik[6][0][2])+(
      Cik[3][2][1]*Cik[6][1][2])));
    cnk[7][0][0] = ((Cik[7][2][0]*cnk[6][0][2])+((Cik[7][0][0]*cnk[6][0][0])+(
      Cik[7][1][0]*cnk[6][0][1])));
    cnk[7][0][1] = ((Cik[7][2][1]*cnk[6][0][2])+((Cik[7][0][1]*cnk[6][0][0])+(
      Cik[7][1][1]*cnk[6][0][1])));
    cnk[7][0][2] = ((Cik[7][2][2]*cnk[6][0][2])+((Cik[7][0][2]*cnk[6][0][0])+(
      Cik[7][1][2]*cnk[6][0][1])));
    cnk[7][1][0] = ((Cik[7][2][0]*cnk[6][1][2])+((Cik[7][0][0]*cnk[6][1][0])+(
      Cik[7][1][0]*cnk[6][1][1])));
    cnk[7][1][1] = ((Cik[7][2][1]*cnk[6][1][2])+((Cik[7][0][1]*cnk[6][1][0])+(
      Cik[7][1][1]*cnk[6][1][1])));
    cnk[7][1][2] = ((Cik[7][2][2]*cnk[6][1][2])+((Cik[7][0][2]*cnk[6][1][0])+(
      Cik[7][1][2]*cnk[6][1][1])));
    cnk[7][2][0] = ((Cik[7][2][0]*cnk[6][2][2])+((Cik[7][0][0]*cnk[6][2][0])+(
      Cik[7][1][0]*cnk[6][2][1])));
    cnk[7][2][1] = ((Cik[7][2][1]*cnk[6][2][2])+((Cik[7][0][1]*cnk[6][2][0])+(
      Cik[7][1][1]*cnk[6][2][1])));
    cnk[7][2][2] = ((Cik[7][2][2]*cnk[6][2][2])+((Cik[7][0][2]*cnk[6][2][0])+(
      Cik[7][1][2]*cnk[6][2][1])));
    cnk[8][0][0] = ((Cik[8][2][0]*cnk[7][0][2])+((Cik[8][0][0]*cnk[7][0][0])+(
      Cik[8][1][0]*cnk[7][0][1])));
    cnk[8][0][1] = ((Cik[8][2][1]*cnk[7][0][2])+((Cik[8][0][1]*cnk[7][0][0])+(
      Cik[8][1][1]*cnk[7][0][1])));
    cnk[8][0][2] = ((Cik[8][2][2]*cnk[7][0][2])+((Cik[8][0][2]*cnk[7][0][0])+(
      Cik[8][1][2]*cnk[7][0][1])));
    cnk[8][1][0] = ((Cik[8][2][0]*cnk[7][1][2])+((Cik[8][0][0]*cnk[7][1][0])+(
      Cik[8][1][0]*cnk[7][1][1])));
    cnk[8][1][1] = ((Cik[8][2][1]*cnk[7][1][2])+((Cik[8][0][1]*cnk[7][1][0])+(
      Cik[8][1][1]*cnk[7][1][1])));
    cnk[8][1][2] = ((Cik[8][2][2]*cnk[7][1][2])+((Cik[8][0][2]*cnk[7][1][0])+(
      Cik[8][1][2]*cnk[7][1][1])));
    cnk[8][2][0] = ((Cik[8][2][0]*cnk[7][2][2])+((Cik[8][0][0]*cnk[7][2][0])+(
      Cik[8][1][0]*cnk[7][2][1])));
    cnk[8][2][1] = ((Cik[8][2][1]*cnk[7][2][2])+((Cik[8][0][1]*cnk[7][2][0])+(
      Cik[8][1][1]*cnk[7][2][1])));
    cnk[8][2][2] = ((Cik[8][2][2]*cnk[7][2][2])+((Cik[8][0][2]*cnk[7][2][0])+(
      Cik[8][1][2]*cnk[7][2][1])));
    cnk[9][0][0] = ((Cik[9][2][0]*cnk[8][0][2])+((Cik[9][0][0]*cnk[8][0][0])+(
      Cik[9][1][0]*cnk[8][0][1])));
    cnk[9][0][1] = ((Cik[9][2][1]*cnk[8][0][2])+((Cik[9][0][1]*cnk[8][0][0])+(
      Cik[9][1][1]*cnk[8][0][1])));
    cnk[9][0][2] = ((Cik[9][2][2]*cnk[8][0][2])+((Cik[9][0][2]*cnk[8][0][0])+(
      Cik[9][1][2]*cnk[8][0][1])));
    cnk[9][1][0] = ((Cik[9][2][0]*cnk[8][1][2])+((Cik[9][0][0]*cnk[8][1][0])+(
      Cik[9][1][0]*cnk[8][1][1])));
    cnk[9][1][1] = ((Cik[9][2][1]*cnk[8][1][2])+((Cik[9][0][1]*cnk[8][1][0])+(
      Cik[9][1][1]*cnk[8][1][1])));
    cnk[9][1][2] = ((Cik[9][2][2]*cnk[8][1][2])+((Cik[9][0][2]*cnk[8][1][0])+(
      Cik[9][1][2]*cnk[8][1][1])));
    cnk[9][2][0] = ((Cik[9][2][0]*cnk[8][2][2])+((Cik[9][0][0]*cnk[8][2][0])+(
      Cik[9][1][0]*cnk[8][2][1])));
    cnk[9][2][1] = ((Cik[9][2][1]*cnk[8][2][2])+((Cik[9][0][1]*cnk[8][2][0])+(
      Cik[9][1][1]*cnk[8][2][1])));
    cnk[9][2][2] = ((Cik[9][2][2]*cnk[8][2][2])+((Cik[9][0][2]*cnk[8][2][0])+(
      Cik[9][1][2]*cnk[8][2][1])));
    cnk[10][0][0] = ((Cik[3][0][2]*Cik[10][2][0])+((Cik[3][0][0]*Cik[10][0][0])+
      (Cik[3][0][1]*Cik[10][1][0])));
    cnk[10][0][1] = ((Cik[3][0][2]*Cik[10][2][1])+((Cik[3][0][0]*Cik[10][0][1])+
      (Cik[3][0][1]*Cik[10][1][1])));
    cnk[10][0][2] = ((Cik[3][0][2]*Cik[10][2][2])+((Cik[3][0][0]*Cik[10][0][2])+
      (Cik[3][0][1]*Cik[10][1][2])));
    cnk[10][1][0] = ((Cik[3][1][2]*Cik[10][2][0])+((Cik[3][1][0]*Cik[10][0][0])+
      (Cik[3][1][1]*Cik[10][1][0])));
    cnk[10][1][1] = ((Cik[3][1][2]*Cik[10][2][1])+((Cik[3][1][0]*Cik[10][0][1])+
      (Cik[3][1][1]*Cik[10][1][1])));
    cnk[10][1][2] = ((Cik[3][1][2]*Cik[10][2][2])+((Cik[3][1][0]*Cik[10][0][2])+
      (Cik[3][1][1]*Cik[10][1][2])));
    cnk[10][2][0] = ((Cik[3][2][2]*Cik[10][2][0])+((Cik[3][2][0]*Cik[10][0][0])+
      (Cik[3][2][1]*Cik[10][1][0])));
    cnk[10][2][1] = ((Cik[3][2][2]*Cik[10][2][1])+((Cik[3][2][0]*Cik[10][0][1])+
      (Cik[3][2][1]*Cik[10][1][1])));
    cnk[10][2][2] = ((Cik[3][2][2]*Cik[10][2][2])+((Cik[3][2][0]*Cik[10][0][2])+
      (Cik[3][2][1]*Cik[10][1][2])));
    cnk[11][0][0] = ((Cik[11][2][0]*cnk[10][0][2])+((Cik[11][0][0]*cnk[10][0][0]
      )+(Cik[11][1][0]*cnk[10][0][1])));
    cnk[11][0][1] = ((Cik[11][2][1]*cnk[10][0][2])+((Cik[11][0][1]*cnk[10][0][0]
      )+(Cik[11][1][1]*cnk[10][0][1])));
    cnk[11][0][2] = ((Cik[11][2][2]*cnk[10][0][2])+((Cik[11][0][2]*cnk[10][0][0]
      )+(Cik[11][1][2]*cnk[10][0][1])));
    cnk[11][1][0] = ((Cik[11][2][0]*cnk[10][1][2])+((Cik[11][0][0]*cnk[10][1][0]
      )+(Cik[11][1][0]*cnk[10][1][1])));
    cnk[11][1][1] = ((Cik[11][2][1]*cnk[10][1][2])+((Cik[11][0][1]*cnk[10][1][0]
      )+(Cik[11][1][1]*cnk[10][1][1])));
    cnk[11][1][2] = ((Cik[11][2][2]*cnk[10][1][2])+((Cik[11][0][2]*cnk[10][1][0]
      )+(Cik[11][1][2]*cnk[10][1][1])));
    cnk[11][2][0] = ((Cik[11][2][0]*cnk[10][2][2])+((Cik[11][0][0]*cnk[10][2][0]
      )+(Cik[11][1][0]*cnk[10][2][1])));
    cnk[11][2][1] = ((Cik[11][2][1]*cnk[10][2][2])+((Cik[11][0][1]*cnk[10][2][0]
      )+(Cik[11][1][1]*cnk[10][2][1])));
    cnk[11][2][2] = ((Cik[11][2][2]*cnk[10][2][2])+((Cik[11][0][2]*cnk[10][2][0]
      )+(Cik[11][1][2]*cnk[10][2][1])));
    cnk[12][0][0] = ((Cik[12][2][0]*cnk[11][0][2])+((Cik[12][0][0]*cnk[11][0][0]
      )+(Cik[12][1][0]*cnk[11][0][1])));
    cnk[12][0][1] = ((Cik[12][2][1]*cnk[11][0][2])+((Cik[12][0][1]*cnk[11][0][0]
      )+(Cik[12][1][1]*cnk[11][0][1])));
    cnk[12][0][2] = ((Cik[12][2][2]*cnk[11][0][2])+((Cik[12][0][2]*cnk[11][0][0]
      )+(Cik[12][1][2]*cnk[11][0][1])));
    cnk[12][1][0] = ((Cik[12][2][0]*cnk[11][1][2])+((Cik[12][0][0]*cnk[11][1][0]
      )+(Cik[12][1][0]*cnk[11][1][1])));
    cnk[12][1][1] = ((Cik[12][2][1]*cnk[11][1][2])+((Cik[12][0][1]*cnk[11][1][0]
      )+(Cik[12][1][1]*cnk[11][1][1])));
    cnk[12][1][2] = ((Cik[12][2][2]*cnk[11][1][2])+((Cik[12][0][2]*cnk[11][1][0]
      )+(Cik[12][1][2]*cnk[11][1][1])));
    cnk[12][2][0] = ((Cik[12][2][0]*cnk[11][2][2])+((Cik[12][0][0]*cnk[11][2][0]
      )+(Cik[12][1][0]*cnk[11][2][1])));
    cnk[12][2][1] = ((Cik[12][2][1]*cnk[11][2][2])+((Cik[12][0][1]*cnk[11][2][0]
      )+(Cik[12][1][1]*cnk[11][2][1])));
    cnk[12][2][2] = ((Cik[12][2][2]*cnk[11][2][2])+((Cik[12][0][2]*cnk[11][2][0]
      )+(Cik[12][1][2]*cnk[11][2][1])));
    cnk[13][0][0] = ((Cik[13][2][0]*cnk[12][0][2])+((Cik[13][0][0]*cnk[12][0][0]
      )+(Cik[13][1][0]*cnk[12][0][1])));
    cnk[13][0][1] = ((Cik[13][2][1]*cnk[12][0][2])+((Cik[13][0][1]*cnk[12][0][0]
      )+(Cik[13][1][1]*cnk[12][0][1])));
    cnk[13][0][2] = ((Cik[13][2][2]*cnk[12][0][2])+((Cik[13][0][2]*cnk[12][0][0]
      )+(Cik[13][1][2]*cnk[12][0][1])));
    cnk[13][1][0] = ((Cik[13][2][0]*cnk[12][1][2])+((Cik[13][0][0]*cnk[12][1][0]
      )+(Cik[13][1][0]*cnk[12][1][1])));
    cnk[13][1][1] = ((Cik[13][2][1]*cnk[12][1][2])+((Cik[13][0][1]*cnk[12][1][0]
      )+(Cik[13][1][1]*cnk[12][1][1])));
    cnk[13][1][2] = ((Cik[13][2][2]*cnk[12][1][2])+((Cik[13][0][2]*cnk[12][1][0]
      )+(Cik[13][1][2]*cnk[12][1][1])));
    cnk[13][2][0] = ((Cik[13][2][0]*cnk[12][2][2])+((Cik[13][0][0]*cnk[12][2][0]
      )+(Cik[13][1][0]*cnk[12][2][1])));
    cnk[13][2][1] = ((Cik[13][2][1]*cnk[12][2][2])+((Cik[13][0][1]*cnk[12][2][0]
      )+(Cik[13][1][1]*cnk[12][2][1])));
    cnk[13][2][2] = ((Cik[13][2][2]*cnk[12][2][2])+((Cik[13][0][2]*cnk[12][2][0]
      )+(Cik[13][1][2]*cnk[12][2][1])));
    cnk[14][0][0] = ((Cik[3][0][2]*Cik[14][2][0])+((Cik[3][0][0]*Cik[14][0][0])+
      (Cik[3][0][1]*Cik[14][1][0])));
    cnk[14][0][1] = ((Cik[3][0][2]*Cik[14][2][1])+((Cik[3][0][0]*Cik[14][0][1])+
      (Cik[3][0][1]*Cik[14][1][1])));
    cnk[14][0][2] = ((Cik[3][0][2]*Cik[14][2][2])+((Cik[3][0][0]*Cik[14][0][2])+
      (Cik[3][0][1]*Cik[14][1][2])));
    cnk[14][1][0] = ((Cik[3][1][2]*Cik[14][2][0])+((Cik[3][1][0]*Cik[14][0][0])+
      (Cik[3][1][1]*Cik[14][1][0])));
    cnk[14][1][1] = ((Cik[3][1][2]*Cik[14][2][1])+((Cik[3][1][0]*Cik[14][0][1])+
      (Cik[3][1][1]*Cik[14][1][1])));
    cnk[14][1][2] = ((Cik[3][1][2]*Cik[14][2][2])+((Cik[3][1][0]*Cik[14][0][2])+
      (Cik[3][1][1]*Cik[14][1][2])));
    cnk[14][2][0] = ((Cik[3][2][2]*Cik[14][2][0])+((Cik[3][2][0]*Cik[14][0][0])+
      (Cik[3][2][1]*Cik[14][1][0])));
    cnk[14][2][1] = ((Cik[3][2][2]*Cik[14][2][1])+((Cik[3][2][0]*Cik[14][0][1])+
      (Cik[3][2][1]*Cik[14][1][1])));
    cnk[14][2][2] = ((Cik[3][2][2]*Cik[14][2][2])+((Cik[3][2][0]*Cik[14][0][2])+
      (Cik[3][2][1]*Cik[14][1][2])));
    cnk[15][0][0] = ((Cik[15][2][0]*cnk[14][0][2])+((Cik[15][0][0]*cnk[14][0][0]
      )+(Cik[15][1][0]*cnk[14][0][1])));
    cnk[15][0][1] = ((Cik[15][2][1]*cnk[14][0][2])+((Cik[15][0][1]*cnk[14][0][0]
      )+(Cik[15][1][1]*cnk[14][0][1])));
    cnk[15][0][2] = ((Cik[15][2][2]*cnk[14][0][2])+((Cik[15][0][2]*cnk[14][0][0]
      )+(Cik[15][1][2]*cnk[14][0][1])));
    cnk[15][1][0] = ((Cik[15][2][0]*cnk[14][1][2])+((Cik[15][0][0]*cnk[14][1][0]
      )+(Cik[15][1][0]*cnk[14][1][1])));
    cnk[15][1][1] = ((Cik[15][2][1]*cnk[14][1][2])+((Cik[15][0][1]*cnk[14][1][0]
      )+(Cik[15][1][1]*cnk[14][1][1])));
    cnk[15][1][2] = ((Cik[15][2][2]*cnk[14][1][2])+((Cik[15][0][2]*cnk[14][1][0]
      )+(Cik[15][1][2]*cnk[14][1][1])));
    cnk[15][2][0] = ((Cik[15][2][0]*cnk[14][2][2])+((Cik[15][0][0]*cnk[14][2][0]
      )+(Cik[15][1][0]*cnk[14][2][1])));
    cnk[15][2][1] = ((Cik[15][2][1]*cnk[14][2][2])+((Cik[15][0][1]*cnk[14][2][0]
      )+(Cik[15][1][1]*cnk[14][2][1])));
    cnk[15][2][2] = ((Cik[15][2][2]*cnk[14][2][2])+((Cik[15][0][2]*cnk[14][2][0]
      )+(Cik[15][1][2]*cnk[14][2][1])));
    cnk[16][0][0] = ((Cik[16][2][0]*cnk[15][0][2])+((Cik[16][0][0]*cnk[15][0][0]
      )+(Cik[16][1][0]*cnk[15][0][1])));
    cnk[16][0][1] = ((Cik[16][2][1]*cnk[15][0][2])+((Cik[16][0][1]*cnk[15][0][0]
      )+(Cik[16][1][1]*cnk[15][0][1])));
    cnk[16][0][2] = ((Cik[16][2][2]*cnk[15][0][2])+((Cik[16][0][2]*cnk[15][0][0]
      )+(Cik[16][1][2]*cnk[15][0][1])));
    cnk[16][1][0] = ((Cik[16][2][0]*cnk[15][1][2])+((Cik[16][0][0]*cnk[15][1][0]
      )+(Cik[16][1][0]*cnk[15][1][1])));
    cnk[16][1][1] = ((Cik[16][2][1]*cnk[15][1][2])+((Cik[16][0][1]*cnk[15][1][0]
      )+(Cik[16][1][1]*cnk[15][1][1])));
    cnk[16][1][2] = ((Cik[16][2][2]*cnk[15][1][2])+((Cik[16][0][2]*cnk[15][1][0]
      )+(Cik[16][1][2]*cnk[15][1][1])));
    cnk[16][2][0] = ((Cik[16][2][0]*cnk[15][2][2])+((Cik[16][0][0]*cnk[15][2][0]
      )+(Cik[16][1][0]*cnk[15][2][1])));
    cnk[16][2][1] = ((Cik[16][2][1]*cnk[15][2][2])+((Cik[16][0][1]*cnk[15][2][0]
      )+(Cik[16][1][1]*cnk[15][2][1])));
    cnk[16][2][2] = ((Cik[16][2][2]*cnk[15][2][2])+((Cik[16][0][2]*cnk[15][2][0]
      )+(Cik[16][1][2]*cnk[15][2][1])));
    cnk[17][0][0] = ((Cik[17][2][0]*cnk[16][0][2])+((Cik[17][0][0]*cnk[16][0][0]
      )+(Cik[17][1][0]*cnk[16][0][1])));
    cnk[17][0][1] = ((Cik[17][2][1]*cnk[16][0][2])+((Cik[17][0][1]*cnk[16][0][0]
      )+(Cik[17][1][1]*cnk[16][0][1])));
    cnk[17][0][2] = ((Cik[17][2][2]*cnk[16][0][2])+((Cik[17][0][2]*cnk[16][0][0]
      )+(Cik[17][1][2]*cnk[16][0][1])));
    cnk[17][1][0] = ((Cik[17][2][0]*cnk[16][1][2])+((Cik[17][0][0]*cnk[16][1][0]
      )+(Cik[17][1][0]*cnk[16][1][1])));
    cnk[17][1][1] = ((Cik[17][2][1]*cnk[16][1][2])+((Cik[17][0][1]*cnk[16][1][0]
      )+(Cik[17][1][1]*cnk[16][1][1])));
    cnk[17][1][2] = ((Cik[17][2][2]*cnk[16][1][2])+((Cik[17][0][2]*cnk[16][1][0]
      )+(Cik[17][1][2]*cnk[16][1][1])));
    cnk[17][2][0] = ((Cik[17][2][0]*cnk[16][2][2])+((Cik[17][0][0]*cnk[16][2][0]
      )+(Cik[17][1][0]*cnk[16][2][1])));
    cnk[17][2][1] = ((Cik[17][2][1]*cnk[16][2][2])+((Cik[17][0][1]*cnk[16][2][0]
      )+(Cik[17][1][1]*cnk[16][2][1])));
    cnk[17][2][2] = ((Cik[17][2][2]*cnk[16][2][2])+((Cik[17][0][2]*cnk[16][2][0]
      )+(Cik[17][1][2]*cnk[16][2][1])));
    cnk[18][0][0] = ((Cik[3][0][2]*Cik[18][2][0])+((Cik[3][0][0]*Cik[18][0][0])+
      (Cik[3][0][1]*Cik[18][1][0])));
    cnk[18][0][1] = ((Cik[3][0][2]*Cik[18][2][1])+((Cik[3][0][0]*Cik[18][0][1])+
      (Cik[3][0][1]*Cik[18][1][1])));
    cnk[18][0][2] = ((Cik[3][0][2]*Cik[18][2][2])+((Cik[3][0][0]*Cik[18][0][2])+
      (Cik[3][0][1]*Cik[18][1][2])));
    cnk[18][1][0] = ((Cik[3][1][2]*Cik[18][2][0])+((Cik[3][1][0]*Cik[18][0][0])+
      (Cik[3][1][1]*Cik[18][1][0])));
    cnk[18][1][1] = ((Cik[3][1][2]*Cik[18][2][1])+((Cik[3][1][0]*Cik[18][0][1])+
      (Cik[3][1][1]*Cik[18][1][1])));
    cnk[18][1][2] = ((Cik[3][1][2]*Cik[18][2][2])+((Cik[3][1][0]*Cik[18][0][2])+
      (Cik[3][1][1]*Cik[18][1][2])));
    cnk[18][2][0] = ((Cik[3][2][2]*Cik[18][2][0])+((Cik[3][2][0]*Cik[18][0][0])+
      (Cik[3][2][1]*Cik[18][1][0])));
    cnk[18][2][1] = ((Cik[3][2][2]*Cik[18][2][1])+((Cik[3][2][0]*Cik[18][0][1])+
      (Cik[3][2][1]*Cik[18][1][1])));
    cnk[18][2][2] = ((Cik[3][2][2]*Cik[18][2][2])+((Cik[3][2][0]*Cik[18][0][2])+
      (Cik[3][2][1]*Cik[18][1][2])));
    cnk[19][0][0] = ((Cik[19][2][0]*cnk[18][0][2])+((Cik[19][0][0]*cnk[18][0][0]
      )+(Cik[19][1][0]*cnk[18][0][1])));
    cnk[19][0][1] = ((Cik[19][2][1]*cnk[18][0][2])+((Cik[19][0][1]*cnk[18][0][0]
      )+(Cik[19][1][1]*cnk[18][0][1])));
    cnk[19][0][2] = ((Cik[19][2][2]*cnk[18][0][2])+((Cik[19][0][2]*cnk[18][0][0]
      )+(Cik[19][1][2]*cnk[18][0][1])));
    cnk[19][1][0] = ((Cik[19][2][0]*cnk[18][1][2])+((Cik[19][0][0]*cnk[18][1][0]
      )+(Cik[19][1][0]*cnk[18][1][1])));
    cnk[19][1][1] = ((Cik[19][2][1]*cnk[18][1][2])+((Cik[19][0][1]*cnk[18][1][0]
      )+(Cik[19][1][1]*cnk[18][1][1])));
    cnk[19][1][2] = ((Cik[19][2][2]*cnk[18][1][2])+((Cik[19][0][2]*cnk[18][1][0]
      )+(Cik[19][1][2]*cnk[18][1][1])));
    cnk[19][2][0] = ((Cik[19][2][0]*cnk[18][2][2])+((Cik[19][0][0]*cnk[18][2][0]
      )+(Cik[19][1][0]*cnk[18][2][1])));
    cnk[19][2][1] = ((Cik[19][2][1]*cnk[18][2][2])+((Cik[19][0][1]*cnk[18][2][0]
      )+(Cik[19][1][1]*cnk[18][2][1])));
    cnk[19][2][2] = ((Cik[19][2][2]*cnk[18][2][2])+((Cik[19][0][2]*cnk[18][2][0]
      )+(Cik[19][1][2]*cnk[18][2][1])));
    cnk[20][0][0] = ((Cik[20][2][0]*cnk[19][0][2])+((Cik[20][0][0]*cnk[19][0][0]
      )+(Cik[20][1][0]*cnk[19][0][1])));
    cnk[20][0][1] = ((Cik[20][2][1]*cnk[19][0][2])+((Cik[20][0][1]*cnk[19][0][0]
      )+(Cik[20][1][1]*cnk[19][0][1])));
    cnk[20][0][2] = ((Cik[20][2][2]*cnk[19][0][2])+((Cik[20][0][2]*cnk[19][0][0]
      )+(Cik[20][1][2]*cnk[19][0][1])));
    cnk[20][1][0] = ((Cik[20][2][0]*cnk[19][1][2])+((Cik[20][0][0]*cnk[19][1][0]
      )+(Cik[20][1][0]*cnk[19][1][1])));
    cnk[20][1][1] = ((Cik[20][2][1]*cnk[19][1][2])+((Cik[20][0][1]*cnk[19][1][0]
      )+(Cik[20][1][1]*cnk[19][1][1])));
    cnk[20][1][2] = ((Cik[20][2][2]*cnk[19][1][2])+((Cik[20][0][2]*cnk[19][1][0]
      )+(Cik[20][1][2]*cnk[19][1][1])));
    cnk[20][2][0] = ((Cik[20][2][0]*cnk[19][2][2])+((Cik[20][0][0]*cnk[19][2][0]
      )+(Cik[20][1][0]*cnk[19][2][1])));
    cnk[20][2][1] = ((Cik[20][2][1]*cnk[19][2][2])+((Cik[20][0][1]*cnk[19][2][0]
      )+(Cik[20][1][1]*cnk[19][2][1])));
    cnk[20][2][2] = ((Cik[20][2][2]*cnk[19][2][2])+((Cik[20][0][2]*cnk[19][2][0]
      )+(Cik[20][1][2]*cnk[19][2][1])));
    cnk[21][0][0] = ((Cik[21][2][0]*cnk[20][0][2])+((Cik[21][0][0]*cnk[20][0][0]
      )+(Cik[21][1][0]*cnk[20][0][1])));
    cnk[21][0][1] = ((Cik[21][2][1]*cnk[20][0][2])+((Cik[21][0][1]*cnk[20][0][0]
      )+(Cik[21][1][1]*cnk[20][0][1])));
    cnk[21][0][2] = ((Cik[21][2][2]*cnk[20][0][2])+((Cik[21][0][2]*cnk[20][0][0]
      )+(Cik[21][1][2]*cnk[20][0][1])));
    cnk[21][1][0] = ((Cik[21][2][0]*cnk[20][1][2])+((Cik[21][0][0]*cnk[20][1][0]
      )+(Cik[21][1][0]*cnk[20][1][1])));
    cnk[21][1][1] = ((Cik[21][2][1]*cnk[20][1][2])+((Cik[21][0][1]*cnk[20][1][0]
      )+(Cik[21][1][1]*cnk[20][1][1])));
    cnk[21][1][2] = ((Cik[21][2][2]*cnk[20][1][2])+((Cik[21][0][2]*cnk[20][1][0]
      )+(Cik[21][1][2]*cnk[20][1][1])));
    cnk[21][2][0] = ((Cik[21][2][0]*cnk[20][2][2])+((Cik[21][0][0]*cnk[20][2][0]
      )+(Cik[21][1][0]*cnk[20][2][1])));
    cnk[21][2][1] = ((Cik[21][2][1]*cnk[20][2][2])+((Cik[21][0][1]*cnk[20][2][0]
      )+(Cik[21][1][1]*cnk[20][2][1])));
    cnk[21][2][2] = ((Cik[21][2][2]*cnk[20][2][2])+((Cik[21][0][2]*cnk[20][2][0]
      )+(Cik[21][1][2]*cnk[20][2][1])));
    cnb[0][0][0] = Cik[3][0][0];
    cnb[0][0][1] = Cik[3][0][1];
    cnb[0][0][2] = Cik[3][0][2];
    cnb[0][1][0] = Cik[3][1][0];
    cnb[0][1][1] = Cik[3][1][1];
    cnb[0][1][2] = Cik[3][1][2];
    cnb[0][2][0] = Cik[3][2][0];
    cnb[0][2][1] = Cik[3][2][1];
    cnb[0][2][2] = Cik[3][2][2];
    cnb[1][0][0] = cnk[6][0][0];
    cnb[1][0][1] = cnk[6][0][1];
    cnb[1][0][2] = cnk[6][0][2];
    cnb[1][1][0] = cnk[6][1][0];
    cnb[1][1][1] = cnk[6][1][1];
    cnb[1][1][2] = cnk[6][1][2];
    cnb[1][2][0] = cnk[6][2][0];
    cnb[1][2][1] = cnk[6][2][1];
    cnb[1][2][2] = cnk[6][2][2];
    cnb[2][0][0] = cnk[7][0][0];
    cnb[2][0][1] = cnk[7][0][1];
    cnb[2][0][2] = cnk[7][0][2];
    cnb[2][1][0] = cnk[7][1][0];
    cnb[2][1][1] = cnk[7][1][1];
    cnb[2][1][2] = cnk[7][1][2];
    cnb[2][2][0] = cnk[7][2][0];
    cnb[2][2][1] = cnk[7][2][1];
    cnb[2][2][2] = cnk[7][2][2];
    cnb[3][0][0] = cnk[8][0][0];
    cnb[3][0][1] = cnk[8][0][1];
    cnb[3][0][2] = cnk[8][0][2];
    cnb[3][1][0] = cnk[8][1][0];
    cnb[3][1][1] = cnk[8][1][1];
    cnb[3][1][2] = cnk[8][1][2];
    cnb[3][2][0] = cnk[8][2][0];
    cnb[3][2][1] = cnk[8][2][1];
    cnb[3][2][2] = cnk[8][2][2];
    cnb[4][0][0] = cnk[9][0][0];
    cnb[4][0][1] = cnk[9][0][1];
    cnb[4][0][2] = cnk[9][0][2];
    cnb[4][1][0] = cnk[9][1][0];
    cnb[4][1][1] = cnk[9][1][1];
    cnb[4][1][2] = cnk[9][1][2];
    cnb[4][2][0] = cnk[9][2][0];
    cnb[4][2][1] = cnk[9][2][1];
    cnb[4][2][2] = cnk[9][2][2];
    cnb[5][0][0] = cnk[9][0][0];
    cnb[5][0][1] = cnk[9][0][1];
    cnb[5][0][2] = cnk[9][0][2];
    cnb[5][1][0] = cnk[9][1][0];
    cnb[5][1][1] = cnk[9][1][1];
    cnb[5][1][2] = cnk[9][1][2];
    cnb[5][2][0] = cnk[9][2][0];
    cnb[5][2][1] = cnk[9][2][1];
    cnb[5][2][2] = cnk[9][2][2];
    cnb[6][0][0] = cnk[10][0][0];
    cnb[6][0][1] = cnk[10][0][1];
    cnb[6][0][2] = cnk[10][0][2];
    cnb[6][1][0] = cnk[10][1][0];
    cnb[6][1][1] = cnk[10][1][1];
    cnb[6][1][2] = cnk[10][1][2];
    cnb[6][2][0] = cnk[10][2][0];
    cnb[6][2][1] = cnk[10][2][1];
    cnb[6][2][2] = cnk[10][2][2];
    cnb[7][0][0] = cnk[11][0][0];
    cnb[7][0][1] = cnk[11][0][1];
    cnb[7][0][2] = cnk[11][0][2];
    cnb[7][1][0] = cnk[11][1][0];
    cnb[7][1][1] = cnk[11][1][1];
    cnb[7][1][2] = cnk[11][1][2];
    cnb[7][2][0] = cnk[11][2][0];
    cnb[7][2][1] = cnk[11][2][1];
    cnb[7][2][2] = cnk[11][2][2];
    cnb[8][0][0] = cnk[12][0][0];
    cnb[8][0][1] = cnk[12][0][1];
    cnb[8][0][2] = cnk[12][0][2];
    cnb[8][1][0] = cnk[12][1][0];
    cnb[8][1][1] = cnk[12][1][1];
    cnb[8][1][2] = cnk[12][1][2];
    cnb[8][2][0] = cnk[12][2][0];
    cnb[8][2][1] = cnk[12][2][1];
    cnb[8][2][2] = cnk[12][2][2];
    cnb[9][0][0] = cnk[13][0][0];
    cnb[9][0][1] = cnk[13][0][1];
    cnb[9][0][2] = cnk[13][0][2];
    cnb[9][1][0] = cnk[13][1][0];
    cnb[9][1][1] = cnk[13][1][1];
    cnb[9][1][2] = cnk[13][1][2];
    cnb[9][2][0] = cnk[13][2][0];
    cnb[9][2][1] = cnk[13][2][1];
    cnb[9][2][2] = cnk[13][2][2];
    cnb[10][0][0] = cnk[13][0][0];
    cnb[10][0][1] = cnk[13][0][1];
    cnb[10][0][2] = cnk[13][0][2];
    cnb[10][1][0] = cnk[13][1][0];
    cnb[10][1][1] = cnk[13][1][1];
    cnb[10][1][2] = cnk[13][1][2];
    cnb[10][2][0] = cnk[13][2][0];
    cnb[10][2][1] = cnk[13][2][1];
    cnb[10][2][2] = cnk[13][2][2];
    cnb[11][0][0] = cnk[14][0][0];
    cnb[11][0][1] = cnk[14][0][1];
    cnb[11][0][2] = cnk[14][0][2];
    cnb[11][1][0] = cnk[14][1][0];
    cnb[11][1][1] = cnk[14][1][1];
    cnb[11][1][2] = cnk[14][1][2];
    cnb[11][2][0] = cnk[14][2][0];
    cnb[11][2][1] = cnk[14][2][1];
    cnb[11][2][2] = cnk[14][2][2];
    cnb[12][0][0] = cnk[15][0][0];
    cnb[12][0][1] = cnk[15][0][1];
    cnb[12][0][2] = cnk[15][0][2];
    cnb[12][1][0] = cnk[15][1][0];
    cnb[12][1][1] = cnk[15][1][1];
    cnb[12][1][2] = cnk[15][1][2];
    cnb[12][2][0] = cnk[15][2][0];
    cnb[12][2][1] = cnk[15][2][1];
    cnb[12][2][2] = cnk[15][2][2];
    cnb[13][0][0] = cnk[16][0][0];
    cnb[13][0][1] = cnk[16][0][1];
    cnb[13][0][2] = cnk[16][0][2];
    cnb[13][1][0] = cnk[16][1][0];
    cnb[13][1][1] = cnk[16][1][1];
    cnb[13][1][2] = cnk[16][1][2];
    cnb[13][2][0] = cnk[16][2][0];
    cnb[13][2][1] = cnk[16][2][1];
    cnb[13][2][2] = cnk[16][2][2];
    cnb[14][0][0] = cnk[17][0][0];
    cnb[14][0][1] = cnk[17][0][1];
    cnb[14][0][2] = cnk[17][0][2];
    cnb[14][1][0] = cnk[17][1][0];
    cnb[14][1][1] = cnk[17][1][1];
    cnb[14][1][2] = cnk[17][1][2];
    cnb[14][2][0] = cnk[17][2][0];
    cnb[14][2][1] = cnk[17][2][1];
    cnb[14][2][2] = cnk[17][2][2];
    cnb[15][0][0] = cnk[17][0][0];
    cnb[15][0][1] = cnk[17][0][1];
    cnb[15][0][2] = cnk[17][0][2];
    cnb[15][1][0] = cnk[17][1][0];
    cnb[15][1][1] = cnk[17][1][1];
    cnb[15][1][2] = cnk[17][1][2];
    cnb[15][2][0] = cnk[17][2][0];
    cnb[15][2][1] = cnk[17][2][1];
    cnb[15][2][2] = cnk[17][2][2];
    cnb[16][0][0] = cnk[18][0][0];
    cnb[16][0][1] = cnk[18][0][1];
    cnb[16][0][2] = cnk[18][0][2];
    cnb[16][1][0] = cnk[18][1][0];
    cnb[16][1][1] = cnk[18][1][1];
    cnb[16][1][2] = cnk[18][1][2];
    cnb[16][2][0] = cnk[18][2][0];
    cnb[16][2][1] = cnk[18][2][1];
    cnb[16][2][2] = cnk[18][2][2];
    cnb[17][0][0] = cnk[19][0][0];
    cnb[17][0][1] = cnk[19][0][1];
    cnb[17][0][2] = cnk[19][0][2];
    cnb[17][1][0] = cnk[19][1][0];
    cnb[17][1][1] = cnk[19][1][1];
    cnb[17][1][2] = cnk[19][1][2];
    cnb[17][2][0] = cnk[19][2][0];
    cnb[17][2][1] = cnk[19][2][1];
    cnb[17][2][2] = cnk[19][2][2];
    cnb[18][0][0] = cnk[20][0][0];
    cnb[18][0][1] = cnk[20][0][1];
    cnb[18][0][2] = cnk[20][0][2];
    cnb[18][1][0] = cnk[20][1][0];
    cnb[18][1][1] = cnk[20][1][1];
    cnb[18][1][2] = cnk[20][1][2];
    cnb[18][2][0] = cnk[20][2][0];
    cnb[18][2][1] = cnk[20][2][1];
    cnb[18][2][2] = cnk[20][2][2];
    cnb[19][0][0] = cnk[21][0][0];
    cnb[19][0][1] = cnk[21][0][1];
    cnb[19][0][2] = cnk[21][0][2];
    cnb[19][1][0] = cnk[21][1][0];
    cnb[19][1][1] = cnk[21][1][1];
    cnb[19][1][2] = cnk[21][1][2];
    cnb[19][2][0] = cnk[21][2][0];
    cnb[19][2][1] = cnk[21][2][1];
    cnb[19][2][2] = cnk[21][2][2];
    cnb[20][0][0] = cnk[21][0][0];
    cnb[20][0][1] = cnk[21][0][1];
    cnb[20][0][2] = cnk[21][0][2];
    cnb[20][1][0] = cnk[21][1][0];
    cnb[20][1][1] = cnk[21][1][1];
    cnb[20][1][2] = cnk[21][1][2];
    cnb[20][2][0] = cnk[21][2][0];
    cnb[20][2][1] = cnk[21][2][1];
    cnb[20][2][2] = cnk[21][2][2];
/*
Compute q-related auxiliary variables
*/
    rpp[0][0] = (pin[0][0]*q[0]);
    rpp[0][1] = (pin[0][1]*q[0]);
    rpp[0][2] = (pin[0][2]*q[0]);
    rpp[1][0] = (pin[1][0]*q[1]);
    rpp[1][1] = (pin[1][1]*q[1]);
    rpp[1][2] = (pin[1][2]*q[1]);
    rpp[2][0] = (pin[2][0]*q[2]);
    rpp[2][1] = (pin[2][1]*q[2]);
    rpp[2][2] = (pin[2][2]*q[2]);
    rpri[0][0] = (ri[0][0]+rpp[0][0]);
    rpri[0][1] = (ri[0][1]+rpp[0][1]);
    rpri[0][2] = (ri[0][2]+rpp[0][2]);
    rik[0][0] = (ri[0][0]+rpp[0][0]);
    rik[0][1] = (ri[0][1]+rpp[0][1]);
    rik[0][2] = (ri[0][2]+rpp[0][2]);
    rik[6][0] = (((Cik[6][2][0]*ri[1][2])+((Cik[6][0][0]*ri[1][0])+(Cik[6][1][0]
      *ri[1][1])))-rk[1][0]);
    rik[6][1] = (((Cik[6][2][1]*ri[1][2])+((Cik[6][0][1]*ri[1][0])+(Cik[6][1][1]
      *ri[1][1])))-rk[1][1]);
    rik[6][2] = (((Cik[6][2][2]*ri[1][2])+((Cik[6][0][2]*ri[1][0])+(Cik[6][1][2]
      *ri[1][1])))-rk[1][2]);
    rik[7][0] = (((Cik[7][2][0]*ri[2][2])+((Cik[7][0][0]*ri[2][0])+(Cik[7][1][0]
      *ri[2][1])))-rk[2][0]);
    rik[7][1] = (((Cik[7][2][1]*ri[2][2])+((Cik[7][0][1]*ri[2][0])+(Cik[7][1][1]
      *ri[2][1])))-rk[2][1]);
    rik[7][2] = (((Cik[7][2][2]*ri[2][2])+((Cik[7][0][2]*ri[2][0])+(Cik[7][1][2]
      *ri[2][1])))-rk[2][2]);
    rik[8][0] = (((Cik[8][2][0]*ri[3][2])+((Cik[8][0][0]*ri[3][0])+(Cik[8][1][0]
      *ri[3][1])))-rk[3][0]);
    rik[8][1] = (((Cik[8][2][1]*ri[3][2])+((Cik[8][0][1]*ri[3][0])+(Cik[8][1][1]
      *ri[3][1])))-rk[3][1]);
    rik[8][2] = (((Cik[8][2][2]*ri[3][2])+((Cik[8][0][2]*ri[3][0])+(Cik[8][1][2]
      *ri[3][1])))-rk[3][2]);
    rik[9][0] = (((Cik[9][2][0]*ri[4][2])+((Cik[9][0][0]*ri[4][0])+(Cik[9][1][0]
      *ri[4][1])))-psrk[9][0]);
    rik[9][1] = (((Cik[9][2][1]*ri[4][2])+((Cik[9][0][1]*ri[4][0])+(Cik[9][1][1]
      *ri[4][1])))-psrk[9][1]);
    rik[9][2] = (((Cik[9][2][2]*ri[4][2])+((Cik[9][0][2]*ri[4][0])+(Cik[9][1][2]
      *ri[4][1])))-psrk[9][2]);
    rik[10][0] = (((Cik[10][2][0]*ri[6][2])+((Cik[10][0][0]*ri[6][0])+(
      Cik[10][1][0]*ri[6][1])))-rk[6][0]);
    rik[10][1] = (((Cik[10][2][1]*ri[6][2])+((Cik[10][0][1]*ri[6][0])+(
      Cik[10][1][1]*ri[6][1])))-rk[6][1]);
    rik[10][2] = (((Cik[10][2][2]*ri[6][2])+((Cik[10][0][2]*ri[6][0])+(
      Cik[10][1][2]*ri[6][1])))-rk[6][2]);
    rik[11][0] = (((Cik[11][2][0]*ri[7][2])+((Cik[11][0][0]*ri[7][0])+(
      Cik[11][1][0]*ri[7][1])))-rk[7][0]);
    rik[11][1] = (((Cik[11][2][1]*ri[7][2])+((Cik[11][0][1]*ri[7][0])+(
      Cik[11][1][1]*ri[7][1])))-rk[7][1]);
    rik[11][2] = (((Cik[11][2][2]*ri[7][2])+((Cik[11][0][2]*ri[7][0])+(
      Cik[11][1][2]*ri[7][1])))-rk[7][2]);
    rik[12][0] = (((Cik[12][2][0]*ri[8][2])+((Cik[12][0][0]*ri[8][0])+(
      Cik[12][1][0]*ri[8][1])))-rk[8][0]);
    rik[12][1] = (((Cik[12][2][1]*ri[8][2])+((Cik[12][0][1]*ri[8][0])+(
      Cik[12][1][1]*ri[8][1])))-rk[8][1]);
    rik[12][2] = (((Cik[12][2][2]*ri[8][2])+((Cik[12][0][2]*ri[8][0])+(
      Cik[12][1][2]*ri[8][1])))-rk[8][2]);
    rik[13][0] = (((Cik[13][2][0]*ri[9][2])+((Cik[13][0][0]*ri[9][0])+(
      Cik[13][1][0]*ri[9][1])))-psrk[13][0]);
    rik[13][1] = (((Cik[13][2][1]*ri[9][2])+((Cik[13][0][1]*ri[9][0])+(
      Cik[13][1][1]*ri[9][1])))-psrk[13][1]);
    rik[13][2] = (((Cik[13][2][2]*ri[9][2])+((Cik[13][0][2]*ri[9][0])+(
      Cik[13][1][2]*ri[9][1])))-psrk[13][2]);
    rik[14][0] = (((Cik[14][2][0]*ri[11][2])+((Cik[14][0][0]*ri[11][0])+(
      Cik[14][1][0]*ri[11][1])))-rk[11][0]);
    rik[14][1] = (((Cik[14][2][1]*ri[11][2])+((Cik[14][0][1]*ri[11][0])+(
      Cik[14][1][1]*ri[11][1])))-rk[11][1]);
    rik[14][2] = (((Cik[14][2][2]*ri[11][2])+((Cik[14][0][2]*ri[11][0])+(
      Cik[14][1][2]*ri[11][1])))-rk[11][2]);
    rik[15][0] = (((Cik[15][2][0]*ri[12][2])+((Cik[15][0][0]*ri[12][0])+(
      Cik[15][1][0]*ri[12][1])))-rk[12][0]);
    rik[15][1] = (((Cik[15][2][1]*ri[12][2])+((Cik[15][0][1]*ri[12][0])+(
      Cik[15][1][1]*ri[12][1])))-rk[12][1]);
    rik[15][2] = (((Cik[15][2][2]*ri[12][2])+((Cik[15][0][2]*ri[12][0])+(
      Cik[15][1][2]*ri[12][1])))-rk[12][2]);
    rik[16][0] = (((Cik[16][2][0]*ri[13][2])+((Cik[16][0][0]*ri[13][0])+(
      Cik[16][1][0]*ri[13][1])))-rk[13][0]);
    rik[16][1] = (((Cik[16][2][1]*ri[13][2])+((Cik[16][0][1]*ri[13][0])+(
      Cik[16][1][1]*ri[13][1])))-rk[13][1]);
    rik[16][2] = (((Cik[16][2][2]*ri[13][2])+((Cik[16][0][2]*ri[13][0])+(
      Cik[16][1][2]*ri[13][1])))-rk[13][2]);
    rik[17][0] = (((Cik[17][2][0]*ri[14][2])+((Cik[17][0][0]*ri[14][0])+(
      Cik[17][1][0]*ri[14][1])))-psrk[17][0]);
    rik[17][1] = (((Cik[17][2][1]*ri[14][2])+((Cik[17][0][1]*ri[14][0])+(
      Cik[17][1][1]*ri[14][1])))-psrk[17][1]);
    rik[17][2] = (((Cik[17][2][2]*ri[14][2])+((Cik[17][0][2]*ri[14][0])+(
      Cik[17][1][2]*ri[14][1])))-psrk[17][2]);
    rik[18][0] = (((Cik[18][2][0]*ri[16][2])+((Cik[18][0][0]*ri[16][0])+(
      Cik[18][1][0]*ri[16][1])))-rk[16][0]);
    rik[18][1] = (((Cik[18][2][1]*ri[16][2])+((Cik[18][0][1]*ri[16][0])+(
      Cik[18][1][1]*ri[16][1])))-rk[16][1]);
    rik[18][2] = (((Cik[18][2][2]*ri[16][2])+((Cik[18][0][2]*ri[16][0])+(
      Cik[18][1][2]*ri[16][1])))-rk[16][2]);
    rik[19][0] = (((Cik[19][2][0]*ri[17][2])+((Cik[19][0][0]*ri[17][0])+(
      Cik[19][1][0]*ri[17][1])))-rk[17][0]);
    rik[19][1] = (((Cik[19][2][1]*ri[17][2])+((Cik[19][0][1]*ri[17][0])+(
      Cik[19][1][1]*ri[17][1])))-rk[17][1]);
    rik[19][2] = (((Cik[19][2][2]*ri[17][2])+((Cik[19][0][2]*ri[17][0])+(
      Cik[19][1][2]*ri[17][1])))-rk[17][2]);
    rik[20][0] = (((Cik[20][2][0]*ri[18][2])+((Cik[20][0][0]*ri[18][0])+(
      Cik[20][1][0]*ri[18][1])))-rk[18][0]);
    rik[20][1] = (((Cik[20][2][1]*ri[18][2])+((Cik[20][0][1]*ri[18][0])+(
      Cik[20][1][1]*ri[18][1])))-rk[18][1]);
    rik[20][2] = (((Cik[20][2][2]*ri[18][2])+((Cik[20][0][2]*ri[18][0])+(
      Cik[20][1][2]*ri[18][1])))-rk[18][2]);
    rik[21][0] = (((Cik[21][2][0]*ri[19][2])+((Cik[21][0][0]*ri[19][0])+(
      Cik[21][1][0]*ri[19][1])))-psrk[21][0]);
    rik[21][1] = (((Cik[21][2][1]*ri[19][2])+((Cik[21][0][1]*ri[19][0])+(
      Cik[21][1][1]*ri[19][1])))-psrk[21][1]);
    rik[21][2] = (((Cik[21][2][2]*ri[19][2])+((Cik[21][0][2]*ri[19][0])+(
      Cik[21][1][2]*ri[19][1])))-psrk[21][2]);
/*
Compute rnk & rnb (mass center locations in N)
*/
    rnk[0][0] = (ri[0][0]+rpp[0][0]);
    rnk[0][1] = (ri[0][1]+rpp[0][1]);
    rnk[0][2] = (ri[0][2]+rpp[0][2]);
    rnk[1][0] = (rnk[0][0]+rpp[1][0]);
    rnk[1][1] = (rnk[0][1]+rpp[1][1]);
    rnk[1][2] = (rnk[0][2]+rpp[1][2]);
    rnk[2][0] = (rnk[1][0]+rpp[2][0]);
    rnk[2][1] = (rnk[1][1]+rpp[2][1]);
    rnk[2][2] = (rnk[1][2]+rpp[2][2]);
    rnk[5][0] = (rnk[2][0]-((Cik[3][0][2]*rk[0][2])+((Cik[3][0][0]*rk[0][0])+(
      Cik[3][0][1]*rk[0][1]))));
    rnk[5][1] = (rnk[2][1]-((Cik[3][1][2]*rk[0][2])+((Cik[3][1][0]*rk[0][0])+(
      Cik[3][1][1]*rk[0][1]))));
    rnk[5][2] = (rnk[2][2]-((Cik[3][2][2]*rk[0][2])+((Cik[3][2][0]*rk[0][0])+(
      Cik[3][2][1]*rk[0][1]))));
    rnk[6][0] = ((rnk[5][0]+((Cik[3][0][2]*ri[1][2])+((Cik[3][0][0]*ri[1][0])+(
      Cik[3][0][1]*ri[1][1]))))-((cnk[6][0][2]*rk[1][2])+((cnk[6][0][0]*rk[1][0]
      )+(cnk[6][0][1]*rk[1][1]))));
    rnk[6][1] = ((rnk[5][1]+((Cik[3][1][2]*ri[1][2])+((Cik[3][1][0]*ri[1][0])+(
      Cik[3][1][1]*ri[1][1]))))-((cnk[6][1][2]*rk[1][2])+((cnk[6][1][0]*rk[1][0]
      )+(cnk[6][1][1]*rk[1][1]))));
    rnk[6][2] = ((rnk[5][2]+((Cik[3][2][2]*ri[1][2])+((Cik[3][2][0]*ri[1][0])+(
      Cik[3][2][1]*ri[1][1]))))-((cnk[6][2][2]*rk[1][2])+((cnk[6][2][0]*rk[1][0]
      )+(cnk[6][2][1]*rk[1][1]))));
    rnk[7][0] = ((rnk[6][0]+((cnk[6][0][2]*ri[2][2])+((cnk[6][0][0]*ri[2][0])+(
      cnk[6][0][1]*ri[2][1]))))-((cnk[7][0][2]*rk[2][2])+((cnk[7][0][0]*rk[2][0]
      )+(cnk[7][0][1]*rk[2][1]))));
    rnk[7][1] = ((rnk[6][1]+((cnk[6][1][2]*ri[2][2])+((cnk[6][1][0]*ri[2][0])+(
      cnk[6][1][1]*ri[2][1]))))-((cnk[7][1][2]*rk[2][2])+((cnk[7][1][0]*rk[2][0]
      )+(cnk[7][1][1]*rk[2][1]))));
    rnk[7][2] = ((rnk[6][2]+((cnk[6][2][2]*ri[2][2])+((cnk[6][2][0]*ri[2][0])+(
      cnk[6][2][1]*ri[2][1]))))-((cnk[7][2][2]*rk[2][2])+((cnk[7][2][0]*rk[2][0]
      )+(cnk[7][2][1]*rk[2][1]))));
    rnk[8][0] = ((rnk[7][0]+((cnk[7][0][2]*ri[3][2])+((cnk[7][0][0]*ri[3][0])+(
      cnk[7][0][1]*ri[3][1]))))-((cnk[8][0][2]*rk[3][2])+((cnk[8][0][0]*rk[3][0]
      )+(cnk[8][0][1]*rk[3][1]))));
    rnk[8][1] = ((rnk[7][1]+((cnk[7][1][2]*ri[3][2])+((cnk[7][1][0]*ri[3][0])+(
      cnk[7][1][1]*ri[3][1]))))-((cnk[8][1][2]*rk[3][2])+((cnk[8][1][0]*rk[3][0]
      )+(cnk[8][1][1]*rk[3][1]))));
    rnk[8][2] = ((rnk[7][2]+((cnk[7][2][2]*ri[3][2])+((cnk[7][2][0]*ri[3][0])+(
      cnk[7][2][1]*ri[3][1]))))-((cnk[8][2][2]*rk[3][2])+((cnk[8][2][0]*rk[3][0]
      )+(cnk[8][2][1]*rk[3][1]))));
    rnk[9][0] = ((rnk[8][0]+((cnk[8][0][2]*ri[4][2])+((cnk[8][0][0]*ri[4][0])+(
      cnk[8][0][1]*ri[4][1]))))-((cnk[9][0][2]*psrk[9][2])+((cnk[9][0][0]*
      psrk[9][0])+(cnk[9][0][1]*psrk[9][1]))));
    rnk[9][1] = ((rnk[8][1]+((cnk[8][1][2]*ri[4][2])+((cnk[8][1][0]*ri[4][0])+(
      cnk[8][1][1]*ri[4][1]))))-((cnk[9][1][2]*psrk[9][2])+((cnk[9][1][0]*
      psrk[9][0])+(cnk[9][1][1]*psrk[9][1]))));
    rnk[9][2] = ((rnk[8][2]+((cnk[8][2][2]*ri[4][2])+((cnk[8][2][0]*ri[4][0])+(
      cnk[8][2][1]*ri[4][1]))))-((cnk[9][2][2]*psrk[9][2])+((cnk[9][2][0]*
      psrk[9][0])+(cnk[9][2][1]*psrk[9][1]))));
    rnk[10][0] = ((rnk[5][0]+((Cik[3][0][2]*ri[6][2])+((Cik[3][0][0]*ri[6][0])+(
      Cik[3][0][1]*ri[6][1]))))-((cnk[10][0][2]*rk[6][2])+((cnk[10][0][0]*
      rk[6][0])+(cnk[10][0][1]*rk[6][1]))));
    rnk[10][1] = ((rnk[5][1]+((Cik[3][1][2]*ri[6][2])+((Cik[3][1][0]*ri[6][0])+(
      Cik[3][1][1]*ri[6][1]))))-((cnk[10][1][2]*rk[6][2])+((cnk[10][1][0]*
      rk[6][0])+(cnk[10][1][1]*rk[6][1]))));
    rnk[10][2] = ((rnk[5][2]+((Cik[3][2][2]*ri[6][2])+((Cik[3][2][0]*ri[6][0])+(
      Cik[3][2][1]*ri[6][1]))))-((cnk[10][2][2]*rk[6][2])+((cnk[10][2][0]*
      rk[6][0])+(cnk[10][2][1]*rk[6][1]))));
    rnk[11][0] = ((rnk[10][0]+((cnk[10][0][2]*ri[7][2])+((cnk[10][0][0]*ri[7][0]
      )+(cnk[10][0][1]*ri[7][1]))))-((cnk[11][0][2]*rk[7][2])+((cnk[11][0][0]*
      rk[7][0])+(cnk[11][0][1]*rk[7][1]))));
    rnk[11][1] = ((rnk[10][1]+((cnk[10][1][2]*ri[7][2])+((cnk[10][1][0]*ri[7][0]
      )+(cnk[10][1][1]*ri[7][1]))))-((cnk[11][1][2]*rk[7][2])+((cnk[11][1][0]*
      rk[7][0])+(cnk[11][1][1]*rk[7][1]))));
    rnk[11][2] = ((rnk[10][2]+((cnk[10][2][2]*ri[7][2])+((cnk[10][2][0]*ri[7][0]
      )+(cnk[10][2][1]*ri[7][1]))))-((cnk[11][2][2]*rk[7][2])+((cnk[11][2][0]*
      rk[7][0])+(cnk[11][2][1]*rk[7][1]))));
    rnk[12][0] = ((rnk[11][0]+((cnk[11][0][2]*ri[8][2])+((cnk[11][0][0]*ri[8][0]
      )+(cnk[11][0][1]*ri[8][1]))))-((cnk[12][0][2]*rk[8][2])+((cnk[12][0][0]*
      rk[8][0])+(cnk[12][0][1]*rk[8][1]))));
    rnk[12][1] = ((rnk[11][1]+((cnk[11][1][2]*ri[8][2])+((cnk[11][1][0]*ri[8][0]
      )+(cnk[11][1][1]*ri[8][1]))))-((cnk[12][1][2]*rk[8][2])+((cnk[12][1][0]*
      rk[8][0])+(cnk[12][1][1]*rk[8][1]))));
    rnk[12][2] = ((rnk[11][2]+((cnk[11][2][2]*ri[8][2])+((cnk[11][2][0]*ri[8][0]
      )+(cnk[11][2][1]*ri[8][1]))))-((cnk[12][2][2]*rk[8][2])+((cnk[12][2][0]*
      rk[8][0])+(cnk[12][2][1]*rk[8][1]))));
    rnk[13][0] = ((rnk[12][0]+((cnk[12][0][2]*ri[9][2])+((cnk[12][0][0]*ri[9][0]
      )+(cnk[12][0][1]*ri[9][1]))))-((cnk[13][0][2]*psrk[13][2])+((cnk[13][0][0]
      *psrk[13][0])+(cnk[13][0][1]*psrk[13][1]))));
    rnk[13][1] = ((rnk[12][1]+((cnk[12][1][2]*ri[9][2])+((cnk[12][1][0]*ri[9][0]
      )+(cnk[12][1][1]*ri[9][1]))))-((cnk[13][1][2]*psrk[13][2])+((cnk[13][1][0]
      *psrk[13][0])+(cnk[13][1][1]*psrk[13][1]))));
    rnk[13][2] = ((rnk[12][2]+((cnk[12][2][2]*ri[9][2])+((cnk[12][2][0]*ri[9][0]
      )+(cnk[12][2][1]*ri[9][1]))))-((cnk[13][2][2]*psrk[13][2])+((cnk[13][2][0]
      *psrk[13][0])+(cnk[13][2][1]*psrk[13][1]))));
    rnk[14][0] = ((rnk[5][0]+((Cik[3][0][2]*ri[11][2])+((Cik[3][0][0]*ri[11][0])
      +(Cik[3][0][1]*ri[11][1]))))-((cnk[14][0][2]*rk[11][2])+((cnk[14][0][0]*
      rk[11][0])+(cnk[14][0][1]*rk[11][1]))));
    rnk[14][1] = ((rnk[5][1]+((Cik[3][1][2]*ri[11][2])+((Cik[3][1][0]*ri[11][0])
      +(Cik[3][1][1]*ri[11][1]))))-((cnk[14][1][2]*rk[11][2])+((cnk[14][1][0]*
      rk[11][0])+(cnk[14][1][1]*rk[11][1]))));
    rnk[14][2] = ((rnk[5][2]+((Cik[3][2][2]*ri[11][2])+((Cik[3][2][0]*ri[11][0])
      +(Cik[3][2][1]*ri[11][1]))))-((cnk[14][2][2]*rk[11][2])+((cnk[14][2][0]*
      rk[11][0])+(cnk[14][2][1]*rk[11][1]))));
    rnk[15][0] = ((rnk[14][0]+((cnk[14][0][2]*ri[12][2])+((cnk[14][0][0]*
      ri[12][0])+(cnk[14][0][1]*ri[12][1]))))-((cnk[15][0][2]*rk[12][2])+((
      cnk[15][0][0]*rk[12][0])+(cnk[15][0][1]*rk[12][1]))));
    rnk[15][1] = ((rnk[14][1]+((cnk[14][1][2]*ri[12][2])+((cnk[14][1][0]*
      ri[12][0])+(cnk[14][1][1]*ri[12][1]))))-((cnk[15][1][2]*rk[12][2])+((
      cnk[15][1][0]*rk[12][0])+(cnk[15][1][1]*rk[12][1]))));
    rnk[15][2] = ((rnk[14][2]+((cnk[14][2][2]*ri[12][2])+((cnk[14][2][0]*
      ri[12][0])+(cnk[14][2][1]*ri[12][1]))))-((cnk[15][2][2]*rk[12][2])+((
      cnk[15][2][0]*rk[12][0])+(cnk[15][2][1]*rk[12][1]))));
    rnk[16][0] = ((rnk[15][0]+((cnk[15][0][2]*ri[13][2])+((cnk[15][0][0]*
      ri[13][0])+(cnk[15][0][1]*ri[13][1]))))-((cnk[16][0][2]*rk[13][2])+((
      cnk[16][0][0]*rk[13][0])+(cnk[16][0][1]*rk[13][1]))));
    rnk[16][1] = ((rnk[15][1]+((cnk[15][1][2]*ri[13][2])+((cnk[15][1][0]*
      ri[13][0])+(cnk[15][1][1]*ri[13][1]))))-((cnk[16][1][2]*rk[13][2])+((
      cnk[16][1][0]*rk[13][0])+(cnk[16][1][1]*rk[13][1]))));
    rnk[16][2] = ((rnk[15][2]+((cnk[15][2][2]*ri[13][2])+((cnk[15][2][0]*
      ri[13][0])+(cnk[15][2][1]*ri[13][1]))))-((cnk[16][2][2]*rk[13][2])+((
      cnk[16][2][0]*rk[13][0])+(cnk[16][2][1]*rk[13][1]))));
    rnk[17][0] = ((rnk[16][0]+((cnk[16][0][2]*ri[14][2])+((cnk[16][0][0]*
      ri[14][0])+(cnk[16][0][1]*ri[14][1]))))-((cnk[17][0][2]*psrk[17][2])+((
      cnk[17][0][0]*psrk[17][0])+(cnk[17][0][1]*psrk[17][1]))));
    rnk[17][1] = ((rnk[16][1]+((cnk[16][1][2]*ri[14][2])+((cnk[16][1][0]*
      ri[14][0])+(cnk[16][1][1]*ri[14][1]))))-((cnk[17][1][2]*psrk[17][2])+((
      cnk[17][1][0]*psrk[17][0])+(cnk[17][1][1]*psrk[17][1]))));
    rnk[17][2] = ((rnk[16][2]+((cnk[16][2][2]*ri[14][2])+((cnk[16][2][0]*
      ri[14][0])+(cnk[16][2][1]*ri[14][1]))))-((cnk[17][2][2]*psrk[17][2])+((
      cnk[17][2][0]*psrk[17][0])+(cnk[17][2][1]*psrk[17][1]))));
    rnk[18][0] = ((rnk[5][0]+((Cik[3][0][2]*ri[16][2])+((Cik[3][0][0]*ri[16][0])
      +(Cik[3][0][1]*ri[16][1]))))-((cnk[18][0][2]*rk[16][2])+((cnk[18][0][0]*
      rk[16][0])+(cnk[18][0][1]*rk[16][1]))));
    rnk[18][1] = ((rnk[5][1]+((Cik[3][1][2]*ri[16][2])+((Cik[3][1][0]*ri[16][0])
      +(Cik[3][1][1]*ri[16][1]))))-((cnk[18][1][2]*rk[16][2])+((cnk[18][1][0]*
      rk[16][0])+(cnk[18][1][1]*rk[16][1]))));
    rnk[18][2] = ((rnk[5][2]+((Cik[3][2][2]*ri[16][2])+((Cik[3][2][0]*ri[16][0])
      +(Cik[3][2][1]*ri[16][1]))))-((cnk[18][2][2]*rk[16][2])+((cnk[18][2][0]*
      rk[16][0])+(cnk[18][2][1]*rk[16][1]))));
    rnk[19][0] = ((rnk[18][0]+((cnk[18][0][2]*ri[17][2])+((cnk[18][0][0]*
      ri[17][0])+(cnk[18][0][1]*ri[17][1]))))-((cnk[19][0][2]*rk[17][2])+((
      cnk[19][0][0]*rk[17][0])+(cnk[19][0][1]*rk[17][1]))));
    rnk[19][1] = ((rnk[18][1]+((cnk[18][1][2]*ri[17][2])+((cnk[18][1][0]*
      ri[17][0])+(cnk[18][1][1]*ri[17][1]))))-((cnk[19][1][2]*rk[17][2])+((
      cnk[19][1][0]*rk[17][0])+(cnk[19][1][1]*rk[17][1]))));
    rnk[19][2] = ((rnk[18][2]+((cnk[18][2][2]*ri[17][2])+((cnk[18][2][0]*
      ri[17][0])+(cnk[18][2][1]*ri[17][1]))))-((cnk[19][2][2]*rk[17][2])+((
      cnk[19][2][0]*rk[17][0])+(cnk[19][2][1]*rk[17][1]))));
    rnk[20][0] = ((rnk[19][0]+((cnk[19][0][2]*ri[18][2])+((cnk[19][0][0]*
      ri[18][0])+(cnk[19][0][1]*ri[18][1]))))-((cnk[20][0][2]*rk[18][2])+((
      cnk[20][0][0]*rk[18][0])+(cnk[20][0][1]*rk[18][1]))));
    rnk[20][1] = ((rnk[19][1]+((cnk[19][1][2]*ri[18][2])+((cnk[19][1][0]*
      ri[18][0])+(cnk[19][1][1]*ri[18][1]))))-((cnk[20][1][2]*rk[18][2])+((
      cnk[20][1][0]*rk[18][0])+(cnk[20][1][1]*rk[18][1]))));
    rnk[20][2] = ((rnk[19][2]+((cnk[19][2][2]*ri[18][2])+((cnk[19][2][0]*
      ri[18][0])+(cnk[19][2][1]*ri[18][1]))))-((cnk[20][2][2]*rk[18][2])+((
      cnk[20][2][0]*rk[18][0])+(cnk[20][2][1]*rk[18][1]))));
    rnk[21][0] = ((rnk[20][0]+((cnk[20][0][2]*ri[19][2])+((cnk[20][0][0]*
      ri[19][0])+(cnk[20][0][1]*ri[19][1]))))-((cnk[21][0][2]*psrk[21][2])+((
      cnk[21][0][0]*psrk[21][0])+(cnk[21][0][1]*psrk[21][1]))));
    rnk[21][1] = ((rnk[20][1]+((cnk[20][1][2]*ri[19][2])+((cnk[20][1][0]*
      ri[19][0])+(cnk[20][1][1]*ri[19][1]))))-((cnk[21][1][2]*psrk[21][2])+((
      cnk[21][1][0]*psrk[21][0])+(cnk[21][1][1]*psrk[21][1]))));
    rnk[21][2] = ((rnk[20][2]+((cnk[20][2][2]*ri[19][2])+((cnk[20][2][0]*
      ri[19][0])+(cnk[20][2][1]*ri[19][1]))))-((cnk[21][2][2]*psrk[21][2])+((
      cnk[21][2][0]*psrk[21][0])+(cnk[21][2][1]*psrk[21][1]))));
    rnb[0][0] = rnk[5][0];
    rnb[0][1] = rnk[5][1];
    rnb[0][2] = rnk[5][2];
    rnb[1][0] = rnk[6][0];
    rnb[1][1] = rnk[6][1];
    rnb[1][2] = rnk[6][2];
    rnb[2][0] = rnk[7][0];
    rnb[2][1] = rnk[7][1];
    rnb[2][2] = rnk[7][2];
    rnb[3][0] = rnk[8][0];
    rnb[3][1] = rnk[8][1];
    rnb[3][2] = rnk[8][2];
    rnb[4][0] = (rnk[9][0]+((cnk[9][0][2]*rcom[4][2])+((cnk[9][0][0]*rcom[4][0])
      +(cnk[9][0][1]*rcom[4][1]))));
    rnb[4][1] = (rnk[9][1]+((cnk[9][1][2]*rcom[4][2])+((cnk[9][1][0]*rcom[4][0])
      +(cnk[9][1][1]*rcom[4][1]))));
    rnb[4][2] = (rnk[9][2]+((cnk[9][2][2]*rcom[4][2])+((cnk[9][2][0]*rcom[4][0])
      +(cnk[9][2][1]*rcom[4][1]))));
    rnb[5][0] = (rnk[9][0]+((cnk[9][0][2]*rcom[5][2])+((cnk[9][0][0]*rcom[5][0])
      +(cnk[9][0][1]*rcom[5][1]))));
    rnb[5][1] = (rnk[9][1]+((cnk[9][1][2]*rcom[5][2])+((cnk[9][1][0]*rcom[5][0])
      +(cnk[9][1][1]*rcom[5][1]))));
    rnb[5][2] = (rnk[9][2]+((cnk[9][2][2]*rcom[5][2])+((cnk[9][2][0]*rcom[5][0])
      +(cnk[9][2][1]*rcom[5][1]))));
    rnb[6][0] = rnk[10][0];
    rnb[6][1] = rnk[10][1];
    rnb[6][2] = rnk[10][2];
    rnb[7][0] = rnk[11][0];
    rnb[7][1] = rnk[11][1];
    rnb[7][2] = rnk[11][2];
    rnb[8][0] = rnk[12][0];
    rnb[8][1] = rnk[12][1];
    rnb[8][2] = rnk[12][2];
    rnb[9][0] = (rnk[13][0]+((cnk[13][0][2]*rcom[9][2])+((cnk[13][0][0]*
      rcom[9][0])+(cnk[13][0][1]*rcom[9][1]))));
    rnb[9][1] = (rnk[13][1]+((cnk[13][1][2]*rcom[9][2])+((cnk[13][1][0]*
      rcom[9][0])+(cnk[13][1][1]*rcom[9][1]))));
    rnb[9][2] = (rnk[13][2]+((cnk[13][2][2]*rcom[9][2])+((cnk[13][2][0]*
      rcom[9][0])+(cnk[13][2][1]*rcom[9][1]))));
    rnb[10][0] = (rnk[13][0]+((cnk[13][0][2]*rcom[10][2])+((cnk[13][0][0]*
      rcom[10][0])+(cnk[13][0][1]*rcom[10][1]))));
    rnb[10][1] = (rnk[13][1]+((cnk[13][1][2]*rcom[10][2])+((cnk[13][1][0]*
      rcom[10][0])+(cnk[13][1][1]*rcom[10][1]))));
    rnb[10][2] = (rnk[13][2]+((cnk[13][2][2]*rcom[10][2])+((cnk[13][2][0]*
      rcom[10][0])+(cnk[13][2][1]*rcom[10][1]))));
    rnb[11][0] = rnk[14][0];
    rnb[11][1] = rnk[14][1];
    rnb[11][2] = rnk[14][2];
    rnb[12][0] = rnk[15][0];
    rnb[12][1] = rnk[15][1];
    rnb[12][2] = rnk[15][2];
    rnb[13][0] = rnk[16][0];
    rnb[13][1] = rnk[16][1];
    rnb[13][2] = rnk[16][2];
    rnb[14][0] = (rnk[17][0]+((cnk[17][0][2]*rcom[14][2])+((cnk[17][0][0]*
      rcom[14][0])+(cnk[17][0][1]*rcom[14][1]))));
    rnb[14][1] = (rnk[17][1]+((cnk[17][1][2]*rcom[14][2])+((cnk[17][1][0]*
      rcom[14][0])+(cnk[17][1][1]*rcom[14][1]))));
    rnb[14][2] = (rnk[17][2]+((cnk[17][2][2]*rcom[14][2])+((cnk[17][2][0]*
      rcom[14][0])+(cnk[17][2][1]*rcom[14][1]))));
    rnb[15][0] = (rnk[17][0]+((cnk[17][0][2]*rcom[15][2])+((cnk[17][0][0]*
      rcom[15][0])+(cnk[17][0][1]*rcom[15][1]))));
    rnb[15][1] = (rnk[17][1]+((cnk[17][1][2]*rcom[15][2])+((cnk[17][1][0]*
      rcom[15][0])+(cnk[17][1][1]*rcom[15][1]))));
    rnb[15][2] = (rnk[17][2]+((cnk[17][2][2]*rcom[15][2])+((cnk[17][2][0]*
      rcom[15][0])+(cnk[17][2][1]*rcom[15][1]))));
    rnb[16][0] = rnk[18][0];
    rnb[16][1] = rnk[18][1];
    rnb[16][2] = rnk[18][2];
    rnb[17][0] = rnk[19][0];
    rnb[17][1] = rnk[19][1];
    rnb[17][2] = rnk[19][2];
    rnb[18][0] = rnk[20][0];
    rnb[18][1] = rnk[20][1];
    rnb[18][2] = rnk[20][2];
    rnb[19][0] = (rnk[21][0]+((cnk[21][0][2]*rcom[19][2])+((cnk[21][0][0]*
      rcom[19][0])+(cnk[21][0][1]*rcom[19][1]))));
    rnb[19][1] = (rnk[21][1]+((cnk[21][1][2]*rcom[19][2])+((cnk[21][1][0]*
      rcom[19][0])+(cnk[21][1][1]*rcom[19][1]))));
    rnb[19][2] = (rnk[21][2]+((cnk[21][2][2]*rcom[19][2])+((cnk[21][2][0]*
      rcom[19][0])+(cnk[21][2][1]*rcom[19][1]))));
    rnb[20][0] = (rnk[21][0]+((cnk[21][0][2]*rcom[20][2])+((cnk[21][0][0]*
      rcom[20][0])+(cnk[21][0][1]*rcom[20][1]))));
    rnb[20][1] = (rnk[21][1]+((cnk[21][1][2]*rcom[20][2])+((cnk[21][1][0]*
      rcom[20][0])+(cnk[21][1][1]*rcom[20][1]))));
    rnb[20][2] = (rnk[21][2]+((cnk[21][2][2]*rcom[20][2])+((cnk[21][2][0]*
      rcom[20][0])+(cnk[21][2][1]*rcom[20][1]))));
/*
Compute com (system mass center location in N)
*/
    com[0] = ((1./mtot)*((psmk[21]*rnk[21][0])+((mk[18]*rnk[20][0])+((mk[17]*
      rnk[19][0])+((mk[16]*rnk[18][0])+((psmk[17]*rnk[17][0])+((mk[13]*
      rnk[16][0])+((mk[12]*rnk[15][0])+((mk[11]*rnk[14][0])+((psmk[13]*
      rnk[13][0])+((mk[8]*rnk[12][0])+((mk[7]*rnk[11][0])+((mk[6]*rnk[10][0])+((
      psmk[9]*rnk[9][0])+((mk[3]*rnk[8][0])+((mk[2]*rnk[7][0])+((mk[0]*rnk[5][0]
      )+(mk[1]*rnk[6][0]))))))))))))))))));
    com[1] = ((1./mtot)*((psmk[21]*rnk[21][1])+((mk[18]*rnk[20][1])+((mk[17]*
      rnk[19][1])+((mk[16]*rnk[18][1])+((psmk[17]*rnk[17][1])+((mk[13]*
      rnk[16][1])+((mk[12]*rnk[15][1])+((mk[11]*rnk[14][1])+((psmk[13]*
      rnk[13][1])+((mk[8]*rnk[12][1])+((mk[7]*rnk[11][1])+((mk[6]*rnk[10][1])+((
      psmk[9]*rnk[9][1])+((mk[3]*rnk[8][1])+((mk[2]*rnk[7][1])+((mk[0]*rnk[5][1]
      )+(mk[1]*rnk[6][1]))))))))))))))))));
    com[2] = ((1./mtot)*((psmk[21]*rnk[21][2])+((mk[18]*rnk[20][2])+((mk[17]*
      rnk[19][2])+((mk[16]*rnk[18][2])+((psmk[17]*rnk[17][2])+((mk[13]*
      rnk[16][2])+((mk[12]*rnk[15][2])+((mk[11]*rnk[14][2])+((psmk[13]*
      rnk[13][2])+((mk[8]*rnk[12][2])+((mk[7]*rnk[11][2])+((mk[6]*rnk[10][2])+((
      psmk[9]*rnk[9][2])+((mk[3]*rnk[8][2])+((mk[2]*rnk[7][2])+((mk[0]*rnk[5][2]
      )+(mk[1]*rnk[6][2]))))))))))))))))));
/*
Compute constraint position errors
*/
    skipqs: ;
    if (uchg == 0) {
        goto skipus;
    }
/*
Velocity-related variables need to be computed
*/
    inerflg = 0;
    for (i = 0; i < 22; i++) {
        u[i] = uin[i];
    }
/*
Compute u-related auxiliary variables
*/
    Wik[6][0] = (pin[6][0]*u[6]);
    Wik[6][1] = (pin[6][1]*u[6]);
    Wik[6][2] = (pin[6][2]*u[6]);
    Wik[7][0] = (pin[7][0]*u[7]);
    Wik[7][1] = (pin[7][1]*u[7]);
    Wik[7][2] = (pin[7][2]*u[7]);
    Wik[8][0] = (pin[8][0]*u[8]);
    Wik[8][1] = (pin[8][1]*u[8]);
    Wik[8][2] = (pin[8][2]*u[8]);
    Wik[9][0] = (pin[9][0]*u[9]);
    Wik[9][1] = (pin[9][1]*u[9]);
    Wik[9][2] = (pin[9][2]*u[9]);
    Wik[10][0] = (pin[10][0]*u[10]);
    Wik[10][1] = (pin[10][1]*u[10]);
    Wik[10][2] = (pin[10][2]*u[10]);
    Wik[11][0] = (pin[11][0]*u[11]);
    Wik[11][1] = (pin[11][1]*u[11]);
    Wik[11][2] = (pin[11][2]*u[11]);
    Wik[12][0] = (pin[12][0]*u[12]);
    Wik[12][1] = (pin[12][1]*u[12]);
    Wik[12][2] = (pin[12][2]*u[12]);
    Wik[13][0] = (pin[13][0]*u[13]);
    Wik[13][1] = (pin[13][1]*u[13]);
    Wik[13][2] = (pin[13][2]*u[13]);
    Wik[14][0] = (pin[14][0]*u[14]);
    Wik[14][1] = (pin[14][1]*u[14]);
    Wik[14][2] = (pin[14][2]*u[14]);
    Wik[15][0] = (pin[15][0]*u[15]);
    Wik[15][1] = (pin[15][1]*u[15]);
    Wik[15][2] = (pin[15][2]*u[15]);
    Wik[16][0] = (pin[16][0]*u[16]);
    Wik[16][1] = (pin[16][1]*u[16]);
    Wik[16][2] = (pin[16][2]*u[16]);
    Wik[17][0] = (pin[17][0]*u[17]);
    Wik[17][1] = (pin[17][1]*u[17]);
    Wik[17][2] = (pin[17][2]*u[17]);
    Wik[18][0] = (pin[18][0]*u[18]);
    Wik[18][1] = (pin[18][1]*u[18]);
    Wik[18][2] = (pin[18][2]*u[18]);
    Wik[19][0] = (pin[19][0]*u[19]);
    Wik[19][1] = (pin[19][1]*u[19]);
    Wik[19][2] = (pin[19][2]*u[19]);
    Wik[20][0] = (pin[20][0]*u[20]);
    Wik[20][1] = (pin[20][1]*u[20]);
    Wik[20][2] = (pin[20][2]*u[20]);
    Wik[21][0] = (pin[21][0]*u[21]);
    Wik[21][1] = (pin[21][1]*u[21]);
    Wik[21][2] = (pin[21][2]*u[21]);
    Vik[0][0] = (pin[0][0]*u[0]);
    Vik[0][1] = (pin[0][1]*u[0]);
    Vik[0][2] = (pin[0][2]*u[0]);
    Vik[1][0] = (pin[1][0]*u[1]);
    Vik[1][1] = (pin[1][1]*u[1]);
    Vik[1][2] = (pin[1][2]*u[1]);
    Vik[2][0] = (pin[2][0]*u[2]);
    Vik[2][1] = (pin[2][1]*u[2]);
    Vik[2][2] = (pin[2][2]*u[2]);
/*
Compute wk & wb (angular velocities)
*/
    wk[6][0] = (Wik[6][0]+((Cik[6][2][0]*u[5])+((Cik[6][0][0]*u[3])+(
      Cik[6][1][0]*u[4]))));
    wk[6][1] = (Wik[6][1]+((Cik[6][2][1]*u[5])+((Cik[6][0][1]*u[3])+(
      Cik[6][1][1]*u[4]))));
    wk[6][2] = (Wik[6][2]+((Cik[6][2][2]*u[5])+((Cik[6][0][2]*u[3])+(
      Cik[6][1][2]*u[4]))));
    wk[7][0] = (Wik[7][0]+((Cik[7][2][0]*wk[6][2])+((Cik[7][0][0]*wk[6][0])+(
      Cik[7][1][0]*wk[6][1]))));
    wk[7][1] = (Wik[7][1]+((Cik[7][2][1]*wk[6][2])+((Cik[7][0][1]*wk[6][0])+(
      Cik[7][1][1]*wk[6][1]))));
    wk[7][2] = (Wik[7][2]+((Cik[7][2][2]*wk[6][2])+((Cik[7][0][2]*wk[6][0])+(
      Cik[7][1][2]*wk[6][1]))));
    wk[8][0] = (Wik[8][0]+((Cik[8][2][0]*wk[7][2])+((Cik[8][0][0]*wk[7][0])+(
      Cik[8][1][0]*wk[7][1]))));
    wk[8][1] = (Wik[8][1]+((Cik[8][2][1]*wk[7][2])+((Cik[8][0][1]*wk[7][0])+(
      Cik[8][1][1]*wk[7][1]))));
    wk[8][2] = (Wik[8][2]+((Cik[8][2][2]*wk[7][2])+((Cik[8][0][2]*wk[7][0])+(
      Cik[8][1][2]*wk[7][1]))));
    wk[9][0] = (Wik[9][0]+((Cik[9][2][0]*wk[8][2])+((Cik[9][0][0]*wk[8][0])+(
      Cik[9][1][0]*wk[8][1]))));
    wk[9][1] = (Wik[9][1]+((Cik[9][2][1]*wk[8][2])+((Cik[9][0][1]*wk[8][0])+(
      Cik[9][1][1]*wk[8][1]))));
    wk[9][2] = (Wik[9][2]+((Cik[9][2][2]*wk[8][2])+((Cik[9][0][2]*wk[8][0])+(
      Cik[9][1][2]*wk[8][1]))));
    wk[10][0] = (Wik[10][0]+((Cik[10][2][0]*u[5])+((Cik[10][0][0]*u[3])+(
      Cik[10][1][0]*u[4]))));
    wk[10][1] = (Wik[10][1]+((Cik[10][2][1]*u[5])+((Cik[10][0][1]*u[3])+(
      Cik[10][1][1]*u[4]))));
    wk[10][2] = (Wik[10][2]+((Cik[10][2][2]*u[5])+((Cik[10][0][2]*u[3])+(
      Cik[10][1][2]*u[4]))));
    wk[11][0] = (Wik[11][0]+((Cik[11][2][0]*wk[10][2])+((Cik[11][0][0]*wk[10][0]
      )+(Cik[11][1][0]*wk[10][1]))));
    wk[11][1] = (Wik[11][1]+((Cik[11][2][1]*wk[10][2])+((Cik[11][0][1]*wk[10][0]
      )+(Cik[11][1][1]*wk[10][1]))));
    wk[11][2] = (Wik[11][2]+((Cik[11][2][2]*wk[10][2])+((Cik[11][0][2]*wk[10][0]
      )+(Cik[11][1][2]*wk[10][1]))));
    wk[12][0] = (Wik[12][0]+((Cik[12][2][0]*wk[11][2])+((Cik[12][0][0]*wk[11][0]
      )+(Cik[12][1][0]*wk[11][1]))));
    wk[12][1] = (Wik[12][1]+((Cik[12][2][1]*wk[11][2])+((Cik[12][0][1]*wk[11][0]
      )+(Cik[12][1][1]*wk[11][1]))));
    wk[12][2] = (Wik[12][2]+((Cik[12][2][2]*wk[11][2])+((Cik[12][0][2]*wk[11][0]
      )+(Cik[12][1][2]*wk[11][1]))));
    wk[13][0] = (Wik[13][0]+((Cik[13][2][0]*wk[12][2])+((Cik[13][0][0]*wk[12][0]
      )+(Cik[13][1][0]*wk[12][1]))));
    wk[13][1] = (Wik[13][1]+((Cik[13][2][1]*wk[12][2])+((Cik[13][0][1]*wk[12][0]
      )+(Cik[13][1][1]*wk[12][1]))));
    wk[13][2] = (Wik[13][2]+((Cik[13][2][2]*wk[12][2])+((Cik[13][0][2]*wk[12][0]
      )+(Cik[13][1][2]*wk[12][1]))));
    wk[14][0] = (Wik[14][0]+((Cik[14][2][0]*u[5])+((Cik[14][0][0]*u[3])+(
      Cik[14][1][0]*u[4]))));
    wk[14][1] = (Wik[14][1]+((Cik[14][2][1]*u[5])+((Cik[14][0][1]*u[3])+(
      Cik[14][1][1]*u[4]))));
    wk[14][2] = (Wik[14][2]+((Cik[14][2][2]*u[5])+((Cik[14][0][2]*u[3])+(
      Cik[14][1][2]*u[4]))));
    wk[15][0] = (Wik[15][0]+((Cik[15][2][0]*wk[14][2])+((Cik[15][0][0]*wk[14][0]
      )+(Cik[15][1][0]*wk[14][1]))));
    wk[15][1] = (Wik[15][1]+((Cik[15][2][1]*wk[14][2])+((Cik[15][0][1]*wk[14][0]
      )+(Cik[15][1][1]*wk[14][1]))));
    wk[15][2] = (Wik[15][2]+((Cik[15][2][2]*wk[14][2])+((Cik[15][0][2]*wk[14][0]
      )+(Cik[15][1][2]*wk[14][1]))));
    wk[16][0] = (Wik[16][0]+((Cik[16][2][0]*wk[15][2])+((Cik[16][0][0]*wk[15][0]
      )+(Cik[16][1][0]*wk[15][1]))));
    wk[16][1] = (Wik[16][1]+((Cik[16][2][1]*wk[15][2])+((Cik[16][0][1]*wk[15][0]
      )+(Cik[16][1][1]*wk[15][1]))));
    wk[16][2] = (Wik[16][2]+((Cik[16][2][2]*wk[15][2])+((Cik[16][0][2]*wk[15][0]
      )+(Cik[16][1][2]*wk[15][1]))));
    wk[17][0] = (Wik[17][0]+((Cik[17][2][0]*wk[16][2])+((Cik[17][0][0]*wk[16][0]
      )+(Cik[17][1][0]*wk[16][1]))));
    wk[17][1] = (Wik[17][1]+((Cik[17][2][1]*wk[16][2])+((Cik[17][0][1]*wk[16][0]
      )+(Cik[17][1][1]*wk[16][1]))));
    wk[17][2] = (Wik[17][2]+((Cik[17][2][2]*wk[16][2])+((Cik[17][0][2]*wk[16][0]
      )+(Cik[17][1][2]*wk[16][1]))));
    wk[18][0] = (Wik[18][0]+((Cik[18][2][0]*u[5])+((Cik[18][0][0]*u[3])+(
      Cik[18][1][0]*u[4]))));
    wk[18][1] = (Wik[18][1]+((Cik[18][2][1]*u[5])+((Cik[18][0][1]*u[3])+(
      Cik[18][1][1]*u[4]))));
    wk[18][2] = (Wik[18][2]+((Cik[18][2][2]*u[5])+((Cik[18][0][2]*u[3])+(
      Cik[18][1][2]*u[4]))));
    wk[19][0] = (Wik[19][0]+((Cik[19][2][0]*wk[18][2])+((Cik[19][0][0]*wk[18][0]
      )+(Cik[19][1][0]*wk[18][1]))));
    wk[19][1] = (Wik[19][1]+((Cik[19][2][1]*wk[18][2])+((Cik[19][0][1]*wk[18][0]
      )+(Cik[19][1][1]*wk[18][1]))));
    wk[19][2] = (Wik[19][2]+((Cik[19][2][2]*wk[18][2])+((Cik[19][0][2]*wk[18][0]
      )+(Cik[19][1][2]*wk[18][1]))));
    wk[20][0] = (Wik[20][0]+((Cik[20][2][0]*wk[19][2])+((Cik[20][0][0]*wk[19][0]
      )+(Cik[20][1][0]*wk[19][1]))));
    wk[20][1] = (Wik[20][1]+((Cik[20][2][1]*wk[19][2])+((Cik[20][0][1]*wk[19][0]
      )+(Cik[20][1][1]*wk[19][1]))));
    wk[20][2] = (Wik[20][2]+((Cik[20][2][2]*wk[19][2])+((Cik[20][0][2]*wk[19][0]
      )+(Cik[20][1][2]*wk[19][1]))));
    wk[21][0] = (Wik[21][0]+((Cik[21][2][0]*wk[20][2])+((Cik[21][0][0]*wk[20][0]
      )+(Cik[21][1][0]*wk[20][1]))));
    wk[21][1] = (Wik[21][1]+((Cik[21][2][1]*wk[20][2])+((Cik[21][0][1]*wk[20][0]
      )+(Cik[21][1][1]*wk[20][1]))));
    wk[21][2] = (Wik[21][2]+((Cik[21][2][2]*wk[20][2])+((Cik[21][0][2]*wk[20][0]
      )+(Cik[21][1][2]*wk[20][1]))));
    wb[0][0] = u[3];
    wb[0][1] = u[4];
    wb[0][2] = u[5];
    wb[1][0] = wk[6][0];
    wb[1][1] = wk[6][1];
    wb[1][2] = wk[6][2];
    wb[2][0] = wk[7][0];
    wb[2][1] = wk[7][1];
    wb[2][2] = wk[7][2];
    wb[3][0] = wk[8][0];
    wb[3][1] = wk[8][1];
    wb[3][2] = wk[8][2];
    wb[4][0] = wk[9][0];
    wb[4][1] = wk[9][1];
    wb[4][2] = wk[9][2];
    wb[5][0] = wk[9][0];
    wb[5][1] = wk[9][1];
    wb[5][2] = wk[9][2];
    wb[6][0] = wk[10][0];
    wb[6][1] = wk[10][1];
    wb[6][2] = wk[10][2];
    wb[7][0] = wk[11][0];
    wb[7][1] = wk[11][1];
    wb[7][2] = wk[11][2];
    wb[8][0] = wk[12][0];
    wb[8][1] = wk[12][1];
    wb[8][2] = wk[12][2];
    wb[9][0] = wk[13][0];
    wb[9][1] = wk[13][1];
    wb[9][2] = wk[13][2];
    wb[10][0] = wk[13][0];
    wb[10][1] = wk[13][1];
    wb[10][2] = wk[13][2];
    wb[11][0] = wk[14][0];
    wb[11][1] = wk[14][1];
    wb[11][2] = wk[14][2];
    wb[12][0] = wk[15][0];
    wb[12][1] = wk[15][1];
    wb[12][2] = wk[15][2];
    wb[13][0] = wk[16][0];
    wb[13][1] = wk[16][1];
    wb[13][2] = wk[16][2];
    wb[14][0] = wk[17][0];
    wb[14][1] = wk[17][1];
    wb[14][2] = wk[17][2];
    wb[15][0] = wk[17][0];
    wb[15][1] = wk[17][1];
    wb[15][2] = wk[17][2];
    wb[16][0] = wk[18][0];
    wb[16][1] = wk[18][1];
    wb[16][2] = wk[18][2];
    wb[17][0] = wk[19][0];
    wb[17][1] = wk[19][1];
    wb[17][2] = wk[19][2];
    wb[18][0] = wk[20][0];
    wb[18][1] = wk[20][1];
    wb[18][2] = wk[20][2];
    wb[19][0] = wk[21][0];
    wb[19][1] = wk[21][1];
    wb[19][2] = wk[21][2];
    wb[20][0] = wk[21][0];
    wb[20][1] = wk[21][1];
    wb[20][2] = wk[21][2];
/*
Compute auxiliary variables involving wk
*/
    Wirk[6][0] = ((ri[1][2]*u[4])-(ri[1][1]*u[5]));
    Wirk[6][1] = ((ri[1][0]*u[5])-(ri[1][2]*u[3]));
    Wirk[6][2] = ((ri[1][1]*u[3])-(ri[1][0]*u[4]));
    Wirk[7][0] = ((ri[2][2]*wk[6][1])-(ri[2][1]*wk[6][2]));
    Wirk[7][1] = ((ri[2][0]*wk[6][2])-(ri[2][2]*wk[6][0]));
    Wirk[7][2] = ((ri[2][1]*wk[6][0])-(ri[2][0]*wk[6][1]));
    Wirk[8][0] = ((ri[3][2]*wk[7][1])-(ri[3][1]*wk[7][2]));
    Wirk[8][1] = ((ri[3][0]*wk[7][2])-(ri[3][2]*wk[7][0]));
    Wirk[8][2] = ((ri[3][1]*wk[7][0])-(ri[3][0]*wk[7][1]));
    Wirk[9][0] = ((ri[4][2]*wk[8][1])-(ri[4][1]*wk[8][2]));
    Wirk[9][1] = ((ri[4][0]*wk[8][2])-(ri[4][2]*wk[8][0]));
    Wirk[9][2] = ((ri[4][1]*wk[8][0])-(ri[4][0]*wk[8][1]));
    Wirk[10][0] = ((ri[6][2]*u[4])-(ri[6][1]*u[5]));
    Wirk[10][1] = ((ri[6][0]*u[5])-(ri[6][2]*u[3]));
    Wirk[10][2] = ((ri[6][1]*u[3])-(ri[6][0]*u[4]));
    Wirk[11][0] = ((ri[7][2]*wk[10][1])-(ri[7][1]*wk[10][2]));
    Wirk[11][1] = ((ri[7][0]*wk[10][2])-(ri[7][2]*wk[10][0]));
    Wirk[11][2] = ((ri[7][1]*wk[10][0])-(ri[7][0]*wk[10][1]));
    Wirk[12][0] = ((ri[8][2]*wk[11][1])-(ri[8][1]*wk[11][2]));
    Wirk[12][1] = ((ri[8][0]*wk[11][2])-(ri[8][2]*wk[11][0]));
    Wirk[12][2] = ((ri[8][1]*wk[11][0])-(ri[8][0]*wk[11][1]));
    Wirk[13][0] = ((ri[9][2]*wk[12][1])-(ri[9][1]*wk[12][2]));
    Wirk[13][1] = ((ri[9][0]*wk[12][2])-(ri[9][2]*wk[12][0]));
    Wirk[13][2] = ((ri[9][1]*wk[12][0])-(ri[9][0]*wk[12][1]));
    Wirk[14][0] = ((ri[11][2]*u[4])-(ri[11][1]*u[5]));
    Wirk[14][1] = ((ri[11][0]*u[5])-(ri[11][2]*u[3]));
    Wirk[14][2] = ((ri[11][1]*u[3])-(ri[11][0]*u[4]));
    Wirk[15][0] = ((ri[12][2]*wk[14][1])-(ri[12][1]*wk[14][2]));
    Wirk[15][1] = ((ri[12][0]*wk[14][2])-(ri[12][2]*wk[14][0]));
    Wirk[15][2] = ((ri[12][1]*wk[14][0])-(ri[12][0]*wk[14][1]));
    Wirk[16][0] = ((ri[13][2]*wk[15][1])-(ri[13][1]*wk[15][2]));
    Wirk[16][1] = ((ri[13][0]*wk[15][2])-(ri[13][2]*wk[15][0]));
    Wirk[16][2] = ((ri[13][1]*wk[15][0])-(ri[13][0]*wk[15][1]));
    Wirk[17][0] = ((ri[14][2]*wk[16][1])-(ri[14][1]*wk[16][2]));
    Wirk[17][1] = ((ri[14][0]*wk[16][2])-(ri[14][2]*wk[16][0]));
    Wirk[17][2] = ((ri[14][1]*wk[16][0])-(ri[14][0]*wk[16][1]));
    Wirk[18][0] = ((ri[16][2]*u[4])-(ri[16][1]*u[5]));
    Wirk[18][1] = ((ri[16][0]*u[5])-(ri[16][2]*u[3]));
    Wirk[18][2] = ((ri[16][1]*u[3])-(ri[16][0]*u[4]));
    Wirk[19][0] = ((ri[17][2]*wk[18][1])-(ri[17][1]*wk[18][2]));
    Wirk[19][1] = ((ri[17][0]*wk[18][2])-(ri[17][2]*wk[18][0]));
    Wirk[19][2] = ((ri[17][1]*wk[18][0])-(ri[17][0]*wk[18][1]));
    Wirk[20][0] = ((ri[18][2]*wk[19][1])-(ri[18][1]*wk[19][2]));
    Wirk[20][1] = ((ri[18][0]*wk[19][2])-(ri[18][2]*wk[19][0]));
    Wirk[20][2] = ((ri[18][1]*wk[19][0])-(ri[18][0]*wk[19][1]));
    Wirk[21][0] = ((ri[19][2]*wk[20][1])-(ri[19][1]*wk[20][2]));
    Wirk[21][1] = ((ri[19][0]*wk[20][2])-(ri[19][2]*wk[20][0]));
    Wirk[21][2] = ((ri[19][1]*wk[20][0])-(ri[19][0]*wk[20][1]));
    Wkrpk[5][0] = ((rk[0][1]*u[5])-(rk[0][2]*u[4]));
    Wkrpk[5][1] = ((rk[0][2]*u[3])-(rk[0][0]*u[5]));
    Wkrpk[5][2] = ((rk[0][0]*u[4])-(rk[0][1]*u[3]));
    Wkrpk[6][0] = ((rk[1][1]*wk[6][2])-(rk[1][2]*wk[6][1]));
    Wkrpk[6][1] = ((rk[1][2]*wk[6][0])-(rk[1][0]*wk[6][2]));
    Wkrpk[6][2] = ((rk[1][0]*wk[6][1])-(rk[1][1]*wk[6][0]));
    Wkrpk[7][0] = ((rk[2][1]*wk[7][2])-(rk[2][2]*wk[7][1]));
    Wkrpk[7][1] = ((rk[2][2]*wk[7][0])-(rk[2][0]*wk[7][2]));
    Wkrpk[7][2] = ((rk[2][0]*wk[7][1])-(rk[2][1]*wk[7][0]));
    Wkrpk[8][0] = ((rk[3][1]*wk[8][2])-(rk[3][2]*wk[8][1]));
    Wkrpk[8][1] = ((rk[3][2]*wk[8][0])-(rk[3][0]*wk[8][2]));
    Wkrpk[8][2] = ((rk[3][0]*wk[8][1])-(rk[3][1]*wk[8][0]));
    Wkrpk[9][0] = ((psrk[9][1]*wk[9][2])-(psrk[9][2]*wk[9][1]));
    Wkrpk[9][1] = ((psrk[9][2]*wk[9][0])-(psrk[9][0]*wk[9][2]));
    Wkrpk[9][2] = ((psrk[9][0]*wk[9][1])-(psrk[9][1]*wk[9][0]));
    Wkrpk[10][0] = ((rk[6][1]*wk[10][2])-(rk[6][2]*wk[10][1]));
    Wkrpk[10][1] = ((rk[6][2]*wk[10][0])-(rk[6][0]*wk[10][2]));
    Wkrpk[10][2] = ((rk[6][0]*wk[10][1])-(rk[6][1]*wk[10][0]));
    Wkrpk[11][0] = ((rk[7][1]*wk[11][2])-(rk[7][2]*wk[11][1]));
    Wkrpk[11][1] = ((rk[7][2]*wk[11][0])-(rk[7][0]*wk[11][2]));
    Wkrpk[11][2] = ((rk[7][0]*wk[11][1])-(rk[7][1]*wk[11][0]));
    Wkrpk[12][0] = ((rk[8][1]*wk[12][2])-(rk[8][2]*wk[12][1]));
    Wkrpk[12][1] = ((rk[8][2]*wk[12][0])-(rk[8][0]*wk[12][2]));
    Wkrpk[12][2] = ((rk[8][0]*wk[12][1])-(rk[8][1]*wk[12][0]));
    Wkrpk[13][0] = ((psrk[13][1]*wk[13][2])-(psrk[13][2]*wk[13][1]));
    Wkrpk[13][1] = ((psrk[13][2]*wk[13][0])-(psrk[13][0]*wk[13][2]));
    Wkrpk[13][2] = ((psrk[13][0]*wk[13][1])-(psrk[13][1]*wk[13][0]));
    Wkrpk[14][0] = ((rk[11][1]*wk[14][2])-(rk[11][2]*wk[14][1]));
    Wkrpk[14][1] = ((rk[11][2]*wk[14][0])-(rk[11][0]*wk[14][2]));
    Wkrpk[14][2] = ((rk[11][0]*wk[14][1])-(rk[11][1]*wk[14][0]));
    Wkrpk[15][0] = ((rk[12][1]*wk[15][2])-(rk[12][2]*wk[15][1]));
    Wkrpk[15][1] = ((rk[12][2]*wk[15][0])-(rk[12][0]*wk[15][2]));
    Wkrpk[15][2] = ((rk[12][0]*wk[15][1])-(rk[12][1]*wk[15][0]));
    Wkrpk[16][0] = ((rk[13][1]*wk[16][2])-(rk[13][2]*wk[16][1]));
    Wkrpk[16][1] = ((rk[13][2]*wk[16][0])-(rk[13][0]*wk[16][2]));
    Wkrpk[16][2] = ((rk[13][0]*wk[16][1])-(rk[13][1]*wk[16][0]));
    Wkrpk[17][0] = ((psrk[17][1]*wk[17][2])-(psrk[17][2]*wk[17][1]));
    Wkrpk[17][1] = ((psrk[17][2]*wk[17][0])-(psrk[17][0]*wk[17][2]));
    Wkrpk[17][2] = ((psrk[17][0]*wk[17][1])-(psrk[17][1]*wk[17][0]));
    Wkrpk[18][0] = ((rk[16][1]*wk[18][2])-(rk[16][2]*wk[18][1]));
    Wkrpk[18][1] = ((rk[16][2]*wk[18][0])-(rk[16][0]*wk[18][2]));
    Wkrpk[18][2] = ((rk[16][0]*wk[18][1])-(rk[16][1]*wk[18][0]));
    Wkrpk[19][0] = ((rk[17][1]*wk[19][2])-(rk[17][2]*wk[19][1]));
    Wkrpk[19][1] = ((rk[17][2]*wk[19][0])-(rk[17][0]*wk[19][2]));
    Wkrpk[19][2] = ((rk[17][0]*wk[19][1])-(rk[17][1]*wk[19][0]));
    Wkrpk[20][0] = ((rk[18][1]*wk[20][2])-(rk[18][2]*wk[20][1]));
    Wkrpk[20][1] = ((rk[18][2]*wk[20][0])-(rk[18][0]*wk[20][2]));
    Wkrpk[20][2] = ((rk[18][0]*wk[20][1])-(rk[18][1]*wk[20][0]));
    Wkrpk[21][0] = ((psrk[21][1]*wk[21][2])-(psrk[21][2]*wk[21][1]));
    Wkrpk[21][1] = ((psrk[21][2]*wk[21][0])-(psrk[21][0]*wk[21][2]));
    Wkrpk[21][2] = ((psrk[21][0]*wk[21][1])-(psrk[21][1]*wk[21][0]));
    IkWk[5][0] = ((ik[0][0][2]*u[5])+((ik[0][0][0]*u[3])+(ik[0][0][1]*u[4])));
    IkWk[5][1] = ((ik[0][1][2]*u[5])+((ik[0][1][0]*u[3])+(ik[0][1][1]*u[4])));
    IkWk[5][2] = ((ik[0][2][2]*u[5])+((ik[0][2][0]*u[3])+(ik[0][2][1]*u[4])));
    WkIkWk[5][0] = ((IkWk[5][2]*u[4])-(IkWk[5][1]*u[5]));
    WkIkWk[5][1] = ((IkWk[5][0]*u[5])-(IkWk[5][2]*u[3]));
    WkIkWk[5][2] = ((IkWk[5][1]*u[3])-(IkWk[5][0]*u[4]));
    IkWk[6][0] = ((ik[1][0][2]*wk[6][2])+((ik[1][0][0]*wk[6][0])+(ik[1][0][1]*
      wk[6][1])));
    IkWk[6][1] = ((ik[1][1][2]*wk[6][2])+((ik[1][1][0]*wk[6][0])+(ik[1][1][1]*
      wk[6][1])));
    IkWk[6][2] = ((ik[1][2][2]*wk[6][2])+((ik[1][2][0]*wk[6][0])+(ik[1][2][1]*
      wk[6][1])));
    WkIkWk[6][0] = ((IkWk[6][2]*wk[6][1])-(IkWk[6][1]*wk[6][2]));
    WkIkWk[6][1] = ((IkWk[6][0]*wk[6][2])-(IkWk[6][2]*wk[6][0]));
    WkIkWk[6][2] = ((IkWk[6][1]*wk[6][0])-(IkWk[6][0]*wk[6][1]));
    IkWk[7][0] = ((ik[2][0][2]*wk[7][2])+((ik[2][0][0]*wk[7][0])+(ik[2][0][1]*
      wk[7][1])));
    IkWk[7][1] = ((ik[2][1][2]*wk[7][2])+((ik[2][1][0]*wk[7][0])+(ik[2][1][1]*
      wk[7][1])));
    IkWk[7][2] = ((ik[2][2][2]*wk[7][2])+((ik[2][2][0]*wk[7][0])+(ik[2][2][1]*
      wk[7][1])));
    WkIkWk[7][0] = ((IkWk[7][2]*wk[7][1])-(IkWk[7][1]*wk[7][2]));
    WkIkWk[7][1] = ((IkWk[7][0]*wk[7][2])-(IkWk[7][2]*wk[7][0]));
    WkIkWk[7][2] = ((IkWk[7][1]*wk[7][0])-(IkWk[7][0]*wk[7][1]));
    IkWk[8][0] = ((ik[3][0][2]*wk[8][2])+((ik[3][0][0]*wk[8][0])+(ik[3][0][1]*
      wk[8][1])));
    IkWk[8][1] = ((ik[3][1][2]*wk[8][2])+((ik[3][1][0]*wk[8][0])+(ik[3][1][1]*
      wk[8][1])));
    IkWk[8][2] = ((ik[3][2][2]*wk[8][2])+((ik[3][2][0]*wk[8][0])+(ik[3][2][1]*
      wk[8][1])));
    WkIkWk[8][0] = ((IkWk[8][2]*wk[8][1])-(IkWk[8][1]*wk[8][2]));
    WkIkWk[8][1] = ((IkWk[8][0]*wk[8][2])-(IkWk[8][2]*wk[8][0]));
    WkIkWk[8][2] = ((IkWk[8][1]*wk[8][0])-(IkWk[8][0]*wk[8][1]));
    IkWk[9][0] = ((psik[9][0][2]*wk[9][2])+((psik[9][0][0]*wk[9][0])+(
      psik[9][0][1]*wk[9][1])));
    IkWk[9][1] = ((psik[9][1][2]*wk[9][2])+((psik[9][1][0]*wk[9][0])+(
      psik[9][1][1]*wk[9][1])));
    IkWk[9][2] = ((psik[9][2][2]*wk[9][2])+((psik[9][2][0]*wk[9][0])+(
      psik[9][2][1]*wk[9][1])));
    WkIkWk[9][0] = ((IkWk[9][2]*wk[9][1])-(IkWk[9][1]*wk[9][2]));
    WkIkWk[9][1] = ((IkWk[9][0]*wk[9][2])-(IkWk[9][2]*wk[9][0]));
    WkIkWk[9][2] = ((IkWk[9][1]*wk[9][0])-(IkWk[9][0]*wk[9][1]));
    IkWk[10][0] = ((ik[6][0][2]*wk[10][2])+((ik[6][0][0]*wk[10][0])+(ik[6][0][1]
      *wk[10][1])));
    IkWk[10][1] = ((ik[6][1][2]*wk[10][2])+((ik[6][1][0]*wk[10][0])+(ik[6][1][1]
      *wk[10][1])));
    IkWk[10][2] = ((ik[6][2][2]*wk[10][2])+((ik[6][2][0]*wk[10][0])+(ik[6][2][1]
      *wk[10][1])));
    WkIkWk[10][0] = ((IkWk[10][2]*wk[10][1])-(IkWk[10][1]*wk[10][2]));
    WkIkWk[10][1] = ((IkWk[10][0]*wk[10][2])-(IkWk[10][2]*wk[10][0]));
    WkIkWk[10][2] = ((IkWk[10][1]*wk[10][0])-(IkWk[10][0]*wk[10][1]));
    IkWk[11][0] = ((ik[7][0][2]*wk[11][2])+((ik[7][0][0]*wk[11][0])+(ik[7][0][1]
      *wk[11][1])));
    IkWk[11][1] = ((ik[7][1][2]*wk[11][2])+((ik[7][1][0]*wk[11][0])+(ik[7][1][1]
      *wk[11][1])));
    IkWk[11][2] = ((ik[7][2][2]*wk[11][2])+((ik[7][2][0]*wk[11][0])+(ik[7][2][1]
      *wk[11][1])));
    WkIkWk[11][0] = ((IkWk[11][2]*wk[11][1])-(IkWk[11][1]*wk[11][2]));
    WkIkWk[11][1] = ((IkWk[11][0]*wk[11][2])-(IkWk[11][2]*wk[11][0]));
    WkIkWk[11][2] = ((IkWk[11][1]*wk[11][0])-(IkWk[11][0]*wk[11][1]));
    IkWk[12][0] = ((ik[8][0][2]*wk[12][2])+((ik[8][0][0]*wk[12][0])+(ik[8][0][1]
      *wk[12][1])));
    IkWk[12][1] = ((ik[8][1][2]*wk[12][2])+((ik[8][1][0]*wk[12][0])+(ik[8][1][1]
      *wk[12][1])));
    IkWk[12][2] = ((ik[8][2][2]*wk[12][2])+((ik[8][2][0]*wk[12][0])+(ik[8][2][1]
      *wk[12][1])));
    WkIkWk[12][0] = ((IkWk[12][2]*wk[12][1])-(IkWk[12][1]*wk[12][2]));
    WkIkWk[12][1] = ((IkWk[12][0]*wk[12][2])-(IkWk[12][2]*wk[12][0]));
    WkIkWk[12][2] = ((IkWk[12][1]*wk[12][0])-(IkWk[12][0]*wk[12][1]));
    IkWk[13][0] = ((psik[13][0][2]*wk[13][2])+((psik[13][0][0]*wk[13][0])+(
      psik[13][0][1]*wk[13][1])));
    IkWk[13][1] = ((psik[13][1][2]*wk[13][2])+((psik[13][1][0]*wk[13][0])+(
      psik[13][1][1]*wk[13][1])));
    IkWk[13][2] = ((psik[13][2][2]*wk[13][2])+((psik[13][2][0]*wk[13][0])+(
      psik[13][2][1]*wk[13][1])));
    WkIkWk[13][0] = ((IkWk[13][2]*wk[13][1])-(IkWk[13][1]*wk[13][2]));
    WkIkWk[13][1] = ((IkWk[13][0]*wk[13][2])-(IkWk[13][2]*wk[13][0]));
    WkIkWk[13][2] = ((IkWk[13][1]*wk[13][0])-(IkWk[13][0]*wk[13][1]));
    IkWk[14][0] = ((ik[11][0][2]*wk[14][2])+((ik[11][0][0]*wk[14][0])+(
      ik[11][0][1]*wk[14][1])));
    IkWk[14][1] = ((ik[11][1][2]*wk[14][2])+((ik[11][1][0]*wk[14][0])+(
      ik[11][1][1]*wk[14][1])));
    IkWk[14][2] = ((ik[11][2][2]*wk[14][2])+((ik[11][2][0]*wk[14][0])+(
      ik[11][2][1]*wk[14][1])));
    WkIkWk[14][0] = ((IkWk[14][2]*wk[14][1])-(IkWk[14][1]*wk[14][2]));
    WkIkWk[14][1] = ((IkWk[14][0]*wk[14][2])-(IkWk[14][2]*wk[14][0]));
    WkIkWk[14][2] = ((IkWk[14][1]*wk[14][0])-(IkWk[14][0]*wk[14][1]));
    IkWk[15][0] = ((ik[12][0][2]*wk[15][2])+((ik[12][0][0]*wk[15][0])+(
      ik[12][0][1]*wk[15][1])));
    IkWk[15][1] = ((ik[12][1][2]*wk[15][2])+((ik[12][1][0]*wk[15][0])+(
      ik[12][1][1]*wk[15][1])));
    IkWk[15][2] = ((ik[12][2][2]*wk[15][2])+((ik[12][2][0]*wk[15][0])+(
      ik[12][2][1]*wk[15][1])));
    WkIkWk[15][0] = ((IkWk[15][2]*wk[15][1])-(IkWk[15][1]*wk[15][2]));
    WkIkWk[15][1] = ((IkWk[15][0]*wk[15][2])-(IkWk[15][2]*wk[15][0]));
    WkIkWk[15][2] = ((IkWk[15][1]*wk[15][0])-(IkWk[15][0]*wk[15][1]));
    IkWk[16][0] = ((ik[13][0][2]*wk[16][2])+((ik[13][0][0]*wk[16][0])+(
      ik[13][0][1]*wk[16][1])));
    IkWk[16][1] = ((ik[13][1][2]*wk[16][2])+((ik[13][1][0]*wk[16][0])+(
      ik[13][1][1]*wk[16][1])));
    IkWk[16][2] = ((ik[13][2][2]*wk[16][2])+((ik[13][2][0]*wk[16][0])+(
      ik[13][2][1]*wk[16][1])));
    WkIkWk[16][0] = ((IkWk[16][2]*wk[16][1])-(IkWk[16][1]*wk[16][2]));
    WkIkWk[16][1] = ((IkWk[16][0]*wk[16][2])-(IkWk[16][2]*wk[16][0]));
    WkIkWk[16][2] = ((IkWk[16][1]*wk[16][0])-(IkWk[16][0]*wk[16][1]));
    IkWk[17][0] = ((psik[17][0][2]*wk[17][2])+((psik[17][0][0]*wk[17][0])+(
      psik[17][0][1]*wk[17][1])));
    IkWk[17][1] = ((psik[17][1][2]*wk[17][2])+((psik[17][1][0]*wk[17][0])+(
      psik[17][1][1]*wk[17][1])));
    IkWk[17][2] = ((psik[17][2][2]*wk[17][2])+((psik[17][2][0]*wk[17][0])+(
      psik[17][2][1]*wk[17][1])));
    WkIkWk[17][0] = ((IkWk[17][2]*wk[17][1])-(IkWk[17][1]*wk[17][2]));
    WkIkWk[17][1] = ((IkWk[17][0]*wk[17][2])-(IkWk[17][2]*wk[17][0]));
    WkIkWk[17][2] = ((IkWk[17][1]*wk[17][0])-(IkWk[17][0]*wk[17][1]));
    IkWk[18][0] = ((ik[16][0][2]*wk[18][2])+((ik[16][0][0]*wk[18][0])+(
      ik[16][0][1]*wk[18][1])));
    IkWk[18][1] = ((ik[16][1][2]*wk[18][2])+((ik[16][1][0]*wk[18][0])+(
      ik[16][1][1]*wk[18][1])));
    IkWk[18][2] = ((ik[16][2][2]*wk[18][2])+((ik[16][2][0]*wk[18][0])+(
      ik[16][2][1]*wk[18][1])));
    WkIkWk[18][0] = ((IkWk[18][2]*wk[18][1])-(IkWk[18][1]*wk[18][2]));
    WkIkWk[18][1] = ((IkWk[18][0]*wk[18][2])-(IkWk[18][2]*wk[18][0]));
    WkIkWk[18][2] = ((IkWk[18][1]*wk[18][0])-(IkWk[18][0]*wk[18][1]));
    IkWk[19][0] = ((ik[17][0][2]*wk[19][2])+((ik[17][0][0]*wk[19][0])+(
      ik[17][0][1]*wk[19][1])));
    IkWk[19][1] = ((ik[17][1][2]*wk[19][2])+((ik[17][1][0]*wk[19][0])+(
      ik[17][1][1]*wk[19][1])));
    IkWk[19][2] = ((ik[17][2][2]*wk[19][2])+((ik[17][2][0]*wk[19][0])+(
      ik[17][2][1]*wk[19][1])));
    WkIkWk[19][0] = ((IkWk[19][2]*wk[19][1])-(IkWk[19][1]*wk[19][2]));
    WkIkWk[19][1] = ((IkWk[19][0]*wk[19][2])-(IkWk[19][2]*wk[19][0]));
    WkIkWk[19][2] = ((IkWk[19][1]*wk[19][0])-(IkWk[19][0]*wk[19][1]));
    IkWk[20][0] = ((ik[18][0][2]*wk[20][2])+((ik[18][0][0]*wk[20][0])+(
      ik[18][0][1]*wk[20][1])));
    IkWk[20][1] = ((ik[18][1][2]*wk[20][2])+((ik[18][1][0]*wk[20][0])+(
      ik[18][1][1]*wk[20][1])));
    IkWk[20][2] = ((ik[18][2][2]*wk[20][2])+((ik[18][2][0]*wk[20][0])+(
      ik[18][2][1]*wk[20][1])));
    WkIkWk[20][0] = ((IkWk[20][2]*wk[20][1])-(IkWk[20][1]*wk[20][2]));
    WkIkWk[20][1] = ((IkWk[20][0]*wk[20][2])-(IkWk[20][2]*wk[20][0]));
    WkIkWk[20][2] = ((IkWk[20][1]*wk[20][0])-(IkWk[20][0]*wk[20][1]));
    IkWk[21][0] = ((psik[21][0][2]*wk[21][2])+((psik[21][0][0]*wk[21][0])+(
      psik[21][0][1]*wk[21][1])));
    IkWk[21][1] = ((psik[21][1][2]*wk[21][2])+((psik[21][1][0]*wk[21][0])+(
      psik[21][1][1]*wk[21][1])));
    IkWk[21][2] = ((psik[21][2][2]*wk[21][2])+((psik[21][2][0]*wk[21][0])+(
      psik[21][2][1]*wk[21][1])));
    WkIkWk[21][0] = ((IkWk[21][2]*wk[21][1])-(IkWk[21][1]*wk[21][2]));
    WkIkWk[21][1] = ((IkWk[21][0]*wk[21][2])-(IkWk[21][2]*wk[21][0]));
    WkIkWk[21][2] = ((IkWk[21][1]*wk[21][0])-(IkWk[21][0]*wk[21][1]));
    IkbWk[5][0] = ((ik[5][0][2]*wk[9][2])+((ik[5][0][0]*wk[9][0])+(ik[5][0][1]*
      wk[9][1])));
    IkbWk[5][1] = ((ik[5][1][2]*wk[9][2])+((ik[5][1][0]*wk[9][0])+(ik[5][1][1]*
      wk[9][1])));
    IkbWk[5][2] = ((ik[5][2][2]*wk[9][2])+((ik[5][2][0]*wk[9][0])+(ik[5][2][1]*
      wk[9][1])));
    WkIkbWk[5][0] = ((IkbWk[5][2]*wk[9][1])-(IkbWk[5][1]*wk[9][2]));
    WkIkbWk[5][1] = ((IkbWk[5][0]*wk[9][2])-(IkbWk[5][2]*wk[9][0]));
    WkIkbWk[5][2] = ((IkbWk[5][1]*wk[9][0])-(IkbWk[5][0]*wk[9][1]));
    IkbWk[10][0] = ((ik[10][0][2]*wk[13][2])+((ik[10][0][0]*wk[13][0])+(
      ik[10][0][1]*wk[13][1])));
    IkbWk[10][1] = ((ik[10][1][2]*wk[13][2])+((ik[10][1][0]*wk[13][0])+(
      ik[10][1][1]*wk[13][1])));
    IkbWk[10][2] = ((ik[10][2][2]*wk[13][2])+((ik[10][2][0]*wk[13][0])+(
      ik[10][2][1]*wk[13][1])));
    WkIkbWk[10][0] = ((IkbWk[10][2]*wk[13][1])-(IkbWk[10][1]*wk[13][2]));
    WkIkbWk[10][1] = ((IkbWk[10][0]*wk[13][2])-(IkbWk[10][2]*wk[13][0]));
    WkIkbWk[10][2] = ((IkbWk[10][1]*wk[13][0])-(IkbWk[10][0]*wk[13][1]));
    IkbWk[15][0] = ((ik[15][0][2]*wk[17][2])+((ik[15][0][0]*wk[17][0])+(
      ik[15][0][1]*wk[17][1])));
    IkbWk[15][1] = ((ik[15][1][2]*wk[17][2])+((ik[15][1][0]*wk[17][0])+(
      ik[15][1][1]*wk[17][1])));
    IkbWk[15][2] = ((ik[15][2][2]*wk[17][2])+((ik[15][2][0]*wk[17][0])+(
      ik[15][2][1]*wk[17][1])));
    WkIkbWk[15][0] = ((IkbWk[15][2]*wk[17][1])-(IkbWk[15][1]*wk[17][2]));
    WkIkbWk[15][1] = ((IkbWk[15][0]*wk[17][2])-(IkbWk[15][2]*wk[17][0]));
    WkIkbWk[15][2] = ((IkbWk[15][1]*wk[17][0])-(IkbWk[15][0]*wk[17][1]));
    IkbWk[20][0] = ((ik[20][0][2]*wk[21][2])+((ik[20][0][0]*wk[21][0])+(
      ik[20][0][1]*wk[21][1])));
    IkbWk[20][1] = ((ik[20][1][2]*wk[21][2])+((ik[20][1][0]*wk[21][0])+(
      ik[20][1][1]*wk[21][1])));
    IkbWk[20][2] = ((ik[20][2][2]*wk[21][2])+((ik[20][2][0]*wk[21][0])+(
      ik[20][2][1]*wk[21][1])));
    WkIkbWk[20][0] = ((IkbWk[20][2]*wk[21][1])-(IkbWk[20][1]*wk[21][2]));
    WkIkbWk[20][1] = ((IkbWk[20][0]*wk[21][2])-(IkbWk[20][2]*wk[21][0]));
    WkIkbWk[20][2] = ((IkbWk[20][1]*wk[21][0])-(IkbWk[20][0]*wk[21][1]));
/*
Compute temporaries for use in SDRHS
*/
    w0w0[0] = (u[3]*u[3]);
    w0w0[1] = (wk[6][0]*wk[6][0]);
    w0w0[2] = (wk[7][0]*wk[7][0]);
    w0w0[3] = (wk[8][0]*wk[8][0]);
    w0w0[4] = (wk[9][0]*wk[9][0]);
    w0w0[5] = (wk[9][0]*wk[9][0]);
    w0w0[6] = (wk[10][0]*wk[10][0]);
    w0w0[7] = (wk[11][0]*wk[11][0]);
    w0w0[8] = (wk[12][0]*wk[12][0]);
    w0w0[9] = (wk[13][0]*wk[13][0]);
    w0w0[10] = (wk[13][0]*wk[13][0]);
    w0w0[11] = (wk[14][0]*wk[14][0]);
    w0w0[12] = (wk[15][0]*wk[15][0]);
    w0w0[13] = (wk[16][0]*wk[16][0]);
    w0w0[14] = (wk[17][0]*wk[17][0]);
    w0w0[15] = (wk[17][0]*wk[17][0]);
    w0w0[16] = (wk[18][0]*wk[18][0]);
    w0w0[17] = (wk[19][0]*wk[19][0]);
    w0w0[18] = (wk[20][0]*wk[20][0]);
    w0w0[19] = (wk[21][0]*wk[21][0]);
    w0w0[20] = (wk[21][0]*wk[21][0]);
    w1w1[0] = (u[4]*u[4]);
    w1w1[1] = (wk[6][1]*wk[6][1]);
    w1w1[2] = (wk[7][1]*wk[7][1]);
    w1w1[3] = (wk[8][1]*wk[8][1]);
    w1w1[4] = (wk[9][1]*wk[9][1]);
    w1w1[5] = (wk[9][1]*wk[9][1]);
    w1w1[6] = (wk[10][1]*wk[10][1]);
    w1w1[7] = (wk[11][1]*wk[11][1]);
    w1w1[8] = (wk[12][1]*wk[12][1]);
    w1w1[9] = (wk[13][1]*wk[13][1]);
    w1w1[10] = (wk[13][1]*wk[13][1]);
    w1w1[11] = (wk[14][1]*wk[14][1]);
    w1w1[12] = (wk[15][1]*wk[15][1]);
    w1w1[13] = (wk[16][1]*wk[16][1]);
    w1w1[14] = (wk[17][1]*wk[17][1]);
    w1w1[15] = (wk[17][1]*wk[17][1]);
    w1w1[16] = (wk[18][1]*wk[18][1]);
    w1w1[17] = (wk[19][1]*wk[19][1]);
    w1w1[18] = (wk[20][1]*wk[20][1]);
    w1w1[19] = (wk[21][1]*wk[21][1]);
    w1w1[20] = (wk[21][1]*wk[21][1]);
    w2w2[0] = (u[5]*u[5]);
    w2w2[1] = (wk[6][2]*wk[6][2]);
    w2w2[2] = (wk[7][2]*wk[7][2]);
    w2w2[3] = (wk[8][2]*wk[8][2]);
    w2w2[4] = (wk[9][2]*wk[9][2]);
    w2w2[5] = (wk[9][2]*wk[9][2]);
    w2w2[6] = (wk[10][2]*wk[10][2]);
    w2w2[7] = (wk[11][2]*wk[11][2]);
    w2w2[8] = (wk[12][2]*wk[12][2]);
    w2w2[9] = (wk[13][2]*wk[13][2]);
    w2w2[10] = (wk[13][2]*wk[13][2]);
    w2w2[11] = (wk[14][2]*wk[14][2]);
    w2w2[12] = (wk[15][2]*wk[15][2]);
    w2w2[13] = (wk[16][2]*wk[16][2]);
    w2w2[14] = (wk[17][2]*wk[17][2]);
    w2w2[15] = (wk[17][2]*wk[17][2]);
    w2w2[16] = (wk[18][2]*wk[18][2]);
    w2w2[17] = (wk[19][2]*wk[19][2]);
    w2w2[18] = (wk[20][2]*wk[20][2]);
    w2w2[19] = (wk[21][2]*wk[21][2]);
    w2w2[20] = (wk[21][2]*wk[21][2]);
    w0w1[0] = (u[3]*u[4]);
    w0w1[1] = (wk[6][0]*wk[6][1]);
    w0w1[2] = (wk[7][0]*wk[7][1]);
    w0w1[3] = (wk[8][0]*wk[8][1]);
    w0w1[4] = (wk[9][0]*wk[9][1]);
    w0w1[5] = (wk[9][0]*wk[9][1]);
    w0w1[6] = (wk[10][0]*wk[10][1]);
    w0w1[7] = (wk[11][0]*wk[11][1]);
    w0w1[8] = (wk[12][0]*wk[12][1]);
    w0w1[9] = (wk[13][0]*wk[13][1]);
    w0w1[10] = (wk[13][0]*wk[13][1]);
    w0w1[11] = (wk[14][0]*wk[14][1]);
    w0w1[12] = (wk[15][0]*wk[15][1]);
    w0w1[13] = (wk[16][0]*wk[16][1]);
    w0w1[14] = (wk[17][0]*wk[17][1]);
    w0w1[15] = (wk[17][0]*wk[17][1]);
    w0w1[16] = (wk[18][0]*wk[18][1]);
    w0w1[17] = (wk[19][0]*wk[19][1]);
    w0w1[18] = (wk[20][0]*wk[20][1]);
    w0w1[19] = (wk[21][0]*wk[21][1]);
    w0w1[20] = (wk[21][0]*wk[21][1]);
    w0w2[0] = (u[3]*u[5]);
    w0w2[1] = (wk[6][0]*wk[6][2]);
    w0w2[2] = (wk[7][0]*wk[7][2]);
    w0w2[3] = (wk[8][0]*wk[8][2]);
    w0w2[4] = (wk[9][0]*wk[9][2]);
    w0w2[5] = (wk[9][0]*wk[9][2]);
    w0w2[6] = (wk[10][0]*wk[10][2]);
    w0w2[7] = (wk[11][0]*wk[11][2]);
    w0w2[8] = (wk[12][0]*wk[12][2]);
    w0w2[9] = (wk[13][0]*wk[13][2]);
    w0w2[10] = (wk[13][0]*wk[13][2]);
    w0w2[11] = (wk[14][0]*wk[14][2]);
    w0w2[12] = (wk[15][0]*wk[15][2]);
    w0w2[13] = (wk[16][0]*wk[16][2]);
    w0w2[14] = (wk[17][0]*wk[17][2]);
    w0w2[15] = (wk[17][0]*wk[17][2]);
    w0w2[16] = (wk[18][0]*wk[18][2]);
    w0w2[17] = (wk[19][0]*wk[19][2]);
    w0w2[18] = (wk[20][0]*wk[20][2]);
    w0w2[19] = (wk[21][0]*wk[21][2]);
    w0w2[20] = (wk[21][0]*wk[21][2]);
    w1w2[0] = (u[4]*u[5]);
    w1w2[1] = (wk[6][1]*wk[6][2]);
    w1w2[2] = (wk[7][1]*wk[7][2]);
    w1w2[3] = (wk[8][1]*wk[8][2]);
    w1w2[4] = (wk[9][1]*wk[9][2]);
    w1w2[5] = (wk[9][1]*wk[9][2]);
    w1w2[6] = (wk[10][1]*wk[10][2]);
    w1w2[7] = (wk[11][1]*wk[11][2]);
    w1w2[8] = (wk[12][1]*wk[12][2]);
    w1w2[9] = (wk[13][1]*wk[13][2]);
    w1w2[10] = (wk[13][1]*wk[13][2]);
    w1w2[11] = (wk[14][1]*wk[14][2]);
    w1w2[12] = (wk[15][1]*wk[15][2]);
    w1w2[13] = (wk[16][1]*wk[16][2]);
    w1w2[14] = (wk[17][1]*wk[17][2]);
    w1w2[15] = (wk[17][1]*wk[17][2]);
    w1w2[16] = (wk[18][1]*wk[18][2]);
    w1w2[17] = (wk[19][1]*wk[19][2]);
    w1w2[18] = (wk[20][1]*wk[20][2]);
    w1w2[19] = (wk[21][1]*wk[21][2]);
    w1w2[20] = (wk[21][1]*wk[21][2]);
    w00w11[0] = -(w0w0[0]+w1w1[0]);
    w00w11[1] = -(w0w0[1]+w1w1[1]);
    w00w11[2] = -(w0w0[2]+w1w1[2]);
    w00w11[3] = -(w0w0[3]+w1w1[3]);
    w00w11[4] = -(w0w0[4]+w1w1[4]);
    w00w11[5] = -(w0w0[5]+w1w1[5]);
    w00w11[6] = -(w0w0[6]+w1w1[6]);
    w00w11[7] = -(w0w0[7]+w1w1[7]);
    w00w11[8] = -(w0w0[8]+w1w1[8]);
    w00w11[9] = -(w0w0[9]+w1w1[9]);
    w00w11[10] = -(w0w0[10]+w1w1[10]);
    w00w11[11] = -(w0w0[11]+w1w1[11]);
    w00w11[12] = -(w0w0[12]+w1w1[12]);
    w00w11[13] = -(w0w0[13]+w1w1[13]);
    w00w11[14] = -(w0w0[14]+w1w1[14]);
    w00w11[15] = -(w0w0[15]+w1w1[15]);
    w00w11[16] = -(w0w0[16]+w1w1[16]);
    w00w11[17] = -(w0w0[17]+w1w1[17]);
    w00w11[18] = -(w0w0[18]+w1w1[18]);
    w00w11[19] = -(w0w0[19]+w1w1[19]);
    w00w11[20] = -(w0w0[20]+w1w1[20]);
    w00w22[0] = -(w0w0[0]+w2w2[0]);
    w00w22[1] = -(w0w0[1]+w2w2[1]);
    w00w22[2] = -(w0w0[2]+w2w2[2]);
    w00w22[3] = -(w0w0[3]+w2w2[3]);
    w00w22[4] = -(w0w0[4]+w2w2[4]);
    w00w22[5] = -(w0w0[5]+w2w2[5]);
    w00w22[6] = -(w0w0[6]+w2w2[6]);
    w00w22[7] = -(w0w0[7]+w2w2[7]);
    w00w22[8] = -(w0w0[8]+w2w2[8]);
    w00w22[9] = -(w0w0[9]+w2w2[9]);
    w00w22[10] = -(w0w0[10]+w2w2[10]);
    w00w22[11] = -(w0w0[11]+w2w2[11]);
    w00w22[12] = -(w0w0[12]+w2w2[12]);
    w00w22[13] = -(w0w0[13]+w2w2[13]);
    w00w22[14] = -(w0w0[14]+w2w2[14]);
    w00w22[15] = -(w0w0[15]+w2w2[15]);
    w00w22[16] = -(w0w0[16]+w2w2[16]);
    w00w22[17] = -(w0w0[17]+w2w2[17]);
    w00w22[18] = -(w0w0[18]+w2w2[18]);
    w00w22[19] = -(w0w0[19]+w2w2[19]);
    w00w22[20] = -(w0w0[20]+w2w2[20]);
    w11w22[0] = -(w1w1[0]+w2w2[0]);
    w11w22[1] = -(w1w1[1]+w2w2[1]);
    w11w22[2] = -(w1w1[2]+w2w2[2]);
    w11w22[3] = -(w1w1[3]+w2w2[3]);
    w11w22[4] = -(w1w1[4]+w2w2[4]);
    w11w22[5] = -(w1w1[5]+w2w2[5]);
    w11w22[6] = -(w1w1[6]+w2w2[6]);
    w11w22[7] = -(w1w1[7]+w2w2[7]);
    w11w22[8] = -(w1w1[8]+w2w2[8]);
    w11w22[9] = -(w1w1[9]+w2w2[9]);
    w11w22[10] = -(w1w1[10]+w2w2[10]);
    w11w22[11] = -(w1w1[11]+w2w2[11]);
    w11w22[12] = -(w1w1[12]+w2w2[12]);
    w11w22[13] = -(w1w1[13]+w2w2[13]);
    w11w22[14] = -(w1w1[14]+w2w2[14]);
    w11w22[15] = -(w1w1[15]+w2w2[15]);
    w11w22[16] = -(w1w1[16]+w2w2[16]);
    w11w22[17] = -(w1w1[17]+w2w2[17]);
    w11w22[18] = -(w1w1[18]+w2w2[18]);
    w11w22[19] = -(w1w1[19]+w2w2[19]);
    w11w22[20] = -(w1w1[20]+w2w2[20]);
/*
Compute vnk & vnb (mass center linear velocities in N)
*/
    vnk[1][0] = (Vik[0][0]+Vik[1][0]);
    vnk[1][1] = (Vik[0][1]+Vik[1][1]);
    vnk[1][2] = (Vik[0][2]+Vik[1][2]);
    vnk[2][0] = (Vik[2][0]+vnk[1][0]);
    vnk[2][1] = (Vik[2][1]+vnk[1][1]);
    vnk[2][2] = (Vik[2][2]+vnk[1][2]);
    vnk[5][0] = (vnk[2][0]+((Cik[3][0][2]*Wkrpk[5][2])+((Cik[3][0][0]*
      Wkrpk[5][0])+(Cik[3][0][1]*Wkrpk[5][1]))));
    vnk[5][1] = (vnk[2][1]+((Cik[3][1][2]*Wkrpk[5][2])+((Cik[3][1][0]*
      Wkrpk[5][0])+(Cik[3][1][1]*Wkrpk[5][1]))));
    vnk[5][2] = (vnk[2][2]+((Cik[3][2][2]*Wkrpk[5][2])+((Cik[3][2][0]*
      Wkrpk[5][0])+(Cik[3][2][1]*Wkrpk[5][1]))));
    vnk[6][0] = ((vnk[5][0]+((Cik[3][0][2]*Wirk[6][2])+((Cik[3][0][0]*Wirk[6][0]
      )+(Cik[3][0][1]*Wirk[6][1]))))+((cnk[6][0][2]*Wkrpk[6][2])+((cnk[6][0][0]*
      Wkrpk[6][0])+(cnk[6][0][1]*Wkrpk[6][1]))));
    vnk[6][1] = ((vnk[5][1]+((Cik[3][1][2]*Wirk[6][2])+((Cik[3][1][0]*Wirk[6][0]
      )+(Cik[3][1][1]*Wirk[6][1]))))+((cnk[6][1][2]*Wkrpk[6][2])+((cnk[6][1][0]*
      Wkrpk[6][0])+(cnk[6][1][1]*Wkrpk[6][1]))));
    vnk[6][2] = ((vnk[5][2]+((Cik[3][2][2]*Wirk[6][2])+((Cik[3][2][0]*Wirk[6][0]
      )+(Cik[3][2][1]*Wirk[6][1]))))+((cnk[6][2][2]*Wkrpk[6][2])+((cnk[6][2][0]*
      Wkrpk[6][0])+(cnk[6][2][1]*Wkrpk[6][1]))));
    vnk[7][0] = ((vnk[6][0]+((cnk[6][0][2]*Wirk[7][2])+((cnk[6][0][0]*Wirk[7][0]
      )+(cnk[6][0][1]*Wirk[7][1]))))+((cnk[7][0][2]*Wkrpk[7][2])+((cnk[7][0][0]*
      Wkrpk[7][0])+(cnk[7][0][1]*Wkrpk[7][1]))));
    vnk[7][1] = ((vnk[6][1]+((cnk[6][1][2]*Wirk[7][2])+((cnk[6][1][0]*Wirk[7][0]
      )+(cnk[6][1][1]*Wirk[7][1]))))+((cnk[7][1][2]*Wkrpk[7][2])+((cnk[7][1][0]*
      Wkrpk[7][0])+(cnk[7][1][1]*Wkrpk[7][1]))));
    vnk[7][2] = ((vnk[6][2]+((cnk[6][2][2]*Wirk[7][2])+((cnk[6][2][0]*Wirk[7][0]
      )+(cnk[6][2][1]*Wirk[7][1]))))+((cnk[7][2][2]*Wkrpk[7][2])+((cnk[7][2][0]*
      Wkrpk[7][0])+(cnk[7][2][1]*Wkrpk[7][1]))));
    vnk[8][0] = ((vnk[7][0]+((cnk[7][0][2]*Wirk[8][2])+((cnk[7][0][0]*Wirk[8][0]
      )+(cnk[7][0][1]*Wirk[8][1]))))+((cnk[8][0][2]*Wkrpk[8][2])+((cnk[8][0][0]*
      Wkrpk[8][0])+(cnk[8][0][1]*Wkrpk[8][1]))));
    vnk[8][1] = ((vnk[7][1]+((cnk[7][1][2]*Wirk[8][2])+((cnk[7][1][0]*Wirk[8][0]
      )+(cnk[7][1][1]*Wirk[8][1]))))+((cnk[8][1][2]*Wkrpk[8][2])+((cnk[8][1][0]*
      Wkrpk[8][0])+(cnk[8][1][1]*Wkrpk[8][1]))));
    vnk[8][2] = ((vnk[7][2]+((cnk[7][2][2]*Wirk[8][2])+((cnk[7][2][0]*Wirk[8][0]
      )+(cnk[7][2][1]*Wirk[8][1]))))+((cnk[8][2][2]*Wkrpk[8][2])+((cnk[8][2][0]*
      Wkrpk[8][0])+(cnk[8][2][1]*Wkrpk[8][1]))));
    vnk[9][0] = ((vnk[8][0]+((cnk[8][0][2]*Wirk[9][2])+((cnk[8][0][0]*Wirk[9][0]
      )+(cnk[8][0][1]*Wirk[9][1]))))+((cnk[9][0][2]*Wkrpk[9][2])+((cnk[9][0][0]*
      Wkrpk[9][0])+(cnk[9][0][1]*Wkrpk[9][1]))));
    vnk[9][1] = ((vnk[8][1]+((cnk[8][1][2]*Wirk[9][2])+((cnk[8][1][0]*Wirk[9][0]
      )+(cnk[8][1][1]*Wirk[9][1]))))+((cnk[9][1][2]*Wkrpk[9][2])+((cnk[9][1][0]*
      Wkrpk[9][0])+(cnk[9][1][1]*Wkrpk[9][1]))));
    vnk[9][2] = ((vnk[8][2]+((cnk[8][2][2]*Wirk[9][2])+((cnk[8][2][0]*Wirk[9][0]
      )+(cnk[8][2][1]*Wirk[9][1]))))+((cnk[9][2][2]*Wkrpk[9][2])+((cnk[9][2][0]*
      Wkrpk[9][0])+(cnk[9][2][1]*Wkrpk[9][1]))));
    vnk[10][0] = ((vnk[5][0]+((Cik[3][0][2]*Wirk[10][2])+((Cik[3][0][0]*
      Wirk[10][0])+(Cik[3][0][1]*Wirk[10][1]))))+((cnk[10][0][2]*Wkrpk[10][2])+(
      (cnk[10][0][0]*Wkrpk[10][0])+(cnk[10][0][1]*Wkrpk[10][1]))));
    vnk[10][1] = ((vnk[5][1]+((Cik[3][1][2]*Wirk[10][2])+((Cik[3][1][0]*
      Wirk[10][0])+(Cik[3][1][1]*Wirk[10][1]))))+((cnk[10][1][2]*Wkrpk[10][2])+(
      (cnk[10][1][0]*Wkrpk[10][0])+(cnk[10][1][1]*Wkrpk[10][1]))));
    vnk[10][2] = ((vnk[5][2]+((Cik[3][2][2]*Wirk[10][2])+((Cik[3][2][0]*
      Wirk[10][0])+(Cik[3][2][1]*Wirk[10][1]))))+((cnk[10][2][2]*Wkrpk[10][2])+(
      (cnk[10][2][0]*Wkrpk[10][0])+(cnk[10][2][1]*Wkrpk[10][1]))));
    vnk[11][0] = ((vnk[10][0]+((cnk[10][0][2]*Wirk[11][2])+((cnk[10][0][0]*
      Wirk[11][0])+(cnk[10][0][1]*Wirk[11][1]))))+((cnk[11][0][2]*Wkrpk[11][2])+
      ((cnk[11][0][0]*Wkrpk[11][0])+(cnk[11][0][1]*Wkrpk[11][1]))));
    vnk[11][1] = ((vnk[10][1]+((cnk[10][1][2]*Wirk[11][2])+((cnk[10][1][0]*
      Wirk[11][0])+(cnk[10][1][1]*Wirk[11][1]))))+((cnk[11][1][2]*Wkrpk[11][2])+
      ((cnk[11][1][0]*Wkrpk[11][0])+(cnk[11][1][1]*Wkrpk[11][1]))));
    vnk[11][2] = ((vnk[10][2]+((cnk[10][2][2]*Wirk[11][2])+((cnk[10][2][0]*
      Wirk[11][0])+(cnk[10][2][1]*Wirk[11][1]))))+((cnk[11][2][2]*Wkrpk[11][2])+
      ((cnk[11][2][0]*Wkrpk[11][0])+(cnk[11][2][1]*Wkrpk[11][1]))));
    vnk[12][0] = ((vnk[11][0]+((cnk[11][0][2]*Wirk[12][2])+((cnk[11][0][0]*
      Wirk[12][0])+(cnk[11][0][1]*Wirk[12][1]))))+((cnk[12][0][2]*Wkrpk[12][2])+
      ((cnk[12][0][0]*Wkrpk[12][0])+(cnk[12][0][1]*Wkrpk[12][1]))));
    vnk[12][1] = ((vnk[11][1]+((cnk[11][1][2]*Wirk[12][2])+((cnk[11][1][0]*
      Wirk[12][0])+(cnk[11][1][1]*Wirk[12][1]))))+((cnk[12][1][2]*Wkrpk[12][2])+
      ((cnk[12][1][0]*Wkrpk[12][0])+(cnk[12][1][1]*Wkrpk[12][1]))));
    vnk[12][2] = ((vnk[11][2]+((cnk[11][2][2]*Wirk[12][2])+((cnk[11][2][0]*
      Wirk[12][0])+(cnk[11][2][1]*Wirk[12][1]))))+((cnk[12][2][2]*Wkrpk[12][2])+
      ((cnk[12][2][0]*Wkrpk[12][0])+(cnk[12][2][1]*Wkrpk[12][1]))));
    vnk[13][0] = ((vnk[12][0]+((cnk[12][0][2]*Wirk[13][2])+((cnk[12][0][0]*
      Wirk[13][0])+(cnk[12][0][1]*Wirk[13][1]))))+((cnk[13][0][2]*Wkrpk[13][2])+
      ((cnk[13][0][0]*Wkrpk[13][0])+(cnk[13][0][1]*Wkrpk[13][1]))));
    vnk[13][1] = ((vnk[12][1]+((cnk[12][1][2]*Wirk[13][2])+((cnk[12][1][0]*
      Wirk[13][0])+(cnk[12][1][1]*Wirk[13][1]))))+((cnk[13][1][2]*Wkrpk[13][2])+
      ((cnk[13][1][0]*Wkrpk[13][0])+(cnk[13][1][1]*Wkrpk[13][1]))));
    vnk[13][2] = ((vnk[12][2]+((cnk[12][2][2]*Wirk[13][2])+((cnk[12][2][0]*
      Wirk[13][0])+(cnk[12][2][1]*Wirk[13][1]))))+((cnk[13][2][2]*Wkrpk[13][2])+
      ((cnk[13][2][0]*Wkrpk[13][0])+(cnk[13][2][1]*Wkrpk[13][1]))));
    vnk[14][0] = ((vnk[5][0]+((Cik[3][0][2]*Wirk[14][2])+((Cik[3][0][0]*
      Wirk[14][0])+(Cik[3][0][1]*Wirk[14][1]))))+((cnk[14][0][2]*Wkrpk[14][2])+(
      (cnk[14][0][0]*Wkrpk[14][0])+(cnk[14][0][1]*Wkrpk[14][1]))));
    vnk[14][1] = ((vnk[5][1]+((Cik[3][1][2]*Wirk[14][2])+((Cik[3][1][0]*
      Wirk[14][0])+(Cik[3][1][1]*Wirk[14][1]))))+((cnk[14][1][2]*Wkrpk[14][2])+(
      (cnk[14][1][0]*Wkrpk[14][0])+(cnk[14][1][1]*Wkrpk[14][1]))));
    vnk[14][2] = ((vnk[5][2]+((Cik[3][2][2]*Wirk[14][2])+((Cik[3][2][0]*
      Wirk[14][0])+(Cik[3][2][1]*Wirk[14][1]))))+((cnk[14][2][2]*Wkrpk[14][2])+(
      (cnk[14][2][0]*Wkrpk[14][0])+(cnk[14][2][1]*Wkrpk[14][1]))));
    vnk[15][0] = ((vnk[14][0]+((cnk[14][0][2]*Wirk[15][2])+((cnk[14][0][0]*
      Wirk[15][0])+(cnk[14][0][1]*Wirk[15][1]))))+((cnk[15][0][2]*Wkrpk[15][2])+
      ((cnk[15][0][0]*Wkrpk[15][0])+(cnk[15][0][1]*Wkrpk[15][1]))));
    vnk[15][1] = ((vnk[14][1]+((cnk[14][1][2]*Wirk[15][2])+((cnk[14][1][0]*
      Wirk[15][0])+(cnk[14][1][1]*Wirk[15][1]))))+((cnk[15][1][2]*Wkrpk[15][2])+
      ((cnk[15][1][0]*Wkrpk[15][0])+(cnk[15][1][1]*Wkrpk[15][1]))));
    vnk[15][2] = ((vnk[14][2]+((cnk[14][2][2]*Wirk[15][2])+((cnk[14][2][0]*
      Wirk[15][0])+(cnk[14][2][1]*Wirk[15][1]))))+((cnk[15][2][2]*Wkrpk[15][2])+
      ((cnk[15][2][0]*Wkrpk[15][0])+(cnk[15][2][1]*Wkrpk[15][1]))));
    vnk[16][0] = ((vnk[15][0]+((cnk[15][0][2]*Wirk[16][2])+((cnk[15][0][0]*
      Wirk[16][0])+(cnk[15][0][1]*Wirk[16][1]))))+((cnk[16][0][2]*Wkrpk[16][2])+
      ((cnk[16][0][0]*Wkrpk[16][0])+(cnk[16][0][1]*Wkrpk[16][1]))));
    vnk[16][1] = ((vnk[15][1]+((cnk[15][1][2]*Wirk[16][2])+((cnk[15][1][0]*
      Wirk[16][0])+(cnk[15][1][1]*Wirk[16][1]))))+((cnk[16][1][2]*Wkrpk[16][2])+
      ((cnk[16][1][0]*Wkrpk[16][0])+(cnk[16][1][1]*Wkrpk[16][1]))));
    vnk[16][2] = ((vnk[15][2]+((cnk[15][2][2]*Wirk[16][2])+((cnk[15][2][0]*
      Wirk[16][0])+(cnk[15][2][1]*Wirk[16][1]))))+((cnk[16][2][2]*Wkrpk[16][2])+
      ((cnk[16][2][0]*Wkrpk[16][0])+(cnk[16][2][1]*Wkrpk[16][1]))));
    vnk[17][0] = ((vnk[16][0]+((cnk[16][0][2]*Wirk[17][2])+((cnk[16][0][0]*
      Wirk[17][0])+(cnk[16][0][1]*Wirk[17][1]))))+((cnk[17][0][2]*Wkrpk[17][2])+
      ((cnk[17][0][0]*Wkrpk[17][0])+(cnk[17][0][1]*Wkrpk[17][1]))));
    vnk[17][1] = ((vnk[16][1]+((cnk[16][1][2]*Wirk[17][2])+((cnk[16][1][0]*
      Wirk[17][0])+(cnk[16][1][1]*Wirk[17][1]))))+((cnk[17][1][2]*Wkrpk[17][2])+
      ((cnk[17][1][0]*Wkrpk[17][0])+(cnk[17][1][1]*Wkrpk[17][1]))));
    vnk[17][2] = ((vnk[16][2]+((cnk[16][2][2]*Wirk[17][2])+((cnk[16][2][0]*
      Wirk[17][0])+(cnk[16][2][1]*Wirk[17][1]))))+((cnk[17][2][2]*Wkrpk[17][2])+
      ((cnk[17][2][0]*Wkrpk[17][0])+(cnk[17][2][1]*Wkrpk[17][1]))));
    vnk[18][0] = ((vnk[5][0]+((Cik[3][0][2]*Wirk[18][2])+((Cik[3][0][0]*
      Wirk[18][0])+(Cik[3][0][1]*Wirk[18][1]))))+((cnk[18][0][2]*Wkrpk[18][2])+(
      (cnk[18][0][0]*Wkrpk[18][0])+(cnk[18][0][1]*Wkrpk[18][1]))));
    vnk[18][1] = ((vnk[5][1]+((Cik[3][1][2]*Wirk[18][2])+((Cik[3][1][0]*
      Wirk[18][0])+(Cik[3][1][1]*Wirk[18][1]))))+((cnk[18][1][2]*Wkrpk[18][2])+(
      (cnk[18][1][0]*Wkrpk[18][0])+(cnk[18][1][1]*Wkrpk[18][1]))));
    vnk[18][2] = ((vnk[5][2]+((Cik[3][2][2]*Wirk[18][2])+((Cik[3][2][0]*
      Wirk[18][0])+(Cik[3][2][1]*Wirk[18][1]))))+((cnk[18][2][2]*Wkrpk[18][2])+(
      (cnk[18][2][0]*Wkrpk[18][0])+(cnk[18][2][1]*Wkrpk[18][1]))));
    vnk[19][0] = ((vnk[18][0]+((cnk[18][0][2]*Wirk[19][2])+((cnk[18][0][0]*
      Wirk[19][0])+(cnk[18][0][1]*Wirk[19][1]))))+((cnk[19][0][2]*Wkrpk[19][2])+
      ((cnk[19][0][0]*Wkrpk[19][0])+(cnk[19][0][1]*Wkrpk[19][1]))));
    vnk[19][1] = ((vnk[18][1]+((cnk[18][1][2]*Wirk[19][2])+((cnk[18][1][0]*
      Wirk[19][0])+(cnk[18][1][1]*Wirk[19][1]))))+((cnk[19][1][2]*Wkrpk[19][2])+
      ((cnk[19][1][0]*Wkrpk[19][0])+(cnk[19][1][1]*Wkrpk[19][1]))));
    vnk[19][2] = ((vnk[18][2]+((cnk[18][2][2]*Wirk[19][2])+((cnk[18][2][0]*
      Wirk[19][0])+(cnk[18][2][1]*Wirk[19][1]))))+((cnk[19][2][2]*Wkrpk[19][2])+
      ((cnk[19][2][0]*Wkrpk[19][0])+(cnk[19][2][1]*Wkrpk[19][1]))));
    vnk[20][0] = ((vnk[19][0]+((cnk[19][0][2]*Wirk[20][2])+((cnk[19][0][0]*
      Wirk[20][0])+(cnk[19][0][1]*Wirk[20][1]))))+((cnk[20][0][2]*Wkrpk[20][2])+
      ((cnk[20][0][0]*Wkrpk[20][0])+(cnk[20][0][1]*Wkrpk[20][1]))));
    vnk[20][1] = ((vnk[19][1]+((cnk[19][1][2]*Wirk[20][2])+((cnk[19][1][0]*
      Wirk[20][0])+(cnk[19][1][1]*Wirk[20][1]))))+((cnk[20][1][2]*Wkrpk[20][2])+
      ((cnk[20][1][0]*Wkrpk[20][0])+(cnk[20][1][1]*Wkrpk[20][1]))));
    vnk[20][2] = ((vnk[19][2]+((cnk[19][2][2]*Wirk[20][2])+((cnk[19][2][0]*
      Wirk[20][0])+(cnk[19][2][1]*Wirk[20][1]))))+((cnk[20][2][2]*Wkrpk[20][2])+
      ((cnk[20][2][0]*Wkrpk[20][0])+(cnk[20][2][1]*Wkrpk[20][1]))));
    vnk[21][0] = ((vnk[20][0]+((cnk[20][0][2]*Wirk[21][2])+((cnk[20][0][0]*
      Wirk[21][0])+(cnk[20][0][1]*Wirk[21][1]))))+((cnk[21][0][2]*Wkrpk[21][2])+
      ((cnk[21][0][0]*Wkrpk[21][0])+(cnk[21][0][1]*Wkrpk[21][1]))));
    vnk[21][1] = ((vnk[20][1]+((cnk[20][1][2]*Wirk[21][2])+((cnk[20][1][0]*
      Wirk[21][0])+(cnk[20][1][1]*Wirk[21][1]))))+((cnk[21][1][2]*Wkrpk[21][2])+
      ((cnk[21][1][0]*Wkrpk[21][0])+(cnk[21][1][1]*Wkrpk[21][1]))));
    vnk[21][2] = ((vnk[20][2]+((cnk[20][2][2]*Wirk[21][2])+((cnk[20][2][0]*
      Wirk[21][0])+(cnk[20][2][1]*Wirk[21][1]))))+((cnk[21][2][2]*Wkrpk[21][2])+
      ((cnk[21][2][0]*Wkrpk[21][0])+(cnk[21][2][1]*Wkrpk[21][1]))));
    vnb[0][0] = vnk[5][0];
    vnb[0][1] = vnk[5][1];
    vnb[0][2] = vnk[5][2];
    vnb[1][0] = vnk[6][0];
    vnb[1][1] = vnk[6][1];
    vnb[1][2] = vnk[6][2];
    vnb[2][0] = vnk[7][0];
    vnb[2][1] = vnk[7][1];
    vnb[2][2] = vnk[7][2];
    vnb[3][0] = vnk[8][0];
    vnb[3][1] = vnk[8][1];
    vnb[3][2] = vnk[8][2];
    wbrcom[4][0] = ((rcom[4][2]*wk[9][1])-(rcom[4][1]*wk[9][2]));
    wbrcom[4][1] = ((rcom[4][0]*wk[9][2])-(rcom[4][2]*wk[9][0]));
    wbrcom[4][2] = ((rcom[4][1]*wk[9][0])-(rcom[4][0]*wk[9][1]));
    vnb[4][0] = (vnk[9][0]+((cnk[9][0][2]*wbrcom[4][2])+((cnk[9][0][0]*
      wbrcom[4][0])+(cnk[9][0][1]*wbrcom[4][1]))));
    vnb[4][1] = (vnk[9][1]+((cnk[9][1][2]*wbrcom[4][2])+((cnk[9][1][0]*
      wbrcom[4][0])+(cnk[9][1][1]*wbrcom[4][1]))));
    vnb[4][2] = (vnk[9][2]+((cnk[9][2][2]*wbrcom[4][2])+((cnk[9][2][0]*
      wbrcom[4][0])+(cnk[9][2][1]*wbrcom[4][1]))));
    wbrcom[5][0] = ((rcom[5][2]*wk[9][1])-(rcom[5][1]*wk[9][2]));
    wbrcom[5][1] = ((rcom[5][0]*wk[9][2])-(rcom[5][2]*wk[9][0]));
    wbrcom[5][2] = ((rcom[5][1]*wk[9][0])-(rcom[5][0]*wk[9][1]));
    vnb[5][0] = (vnk[9][0]+((cnk[9][0][2]*wbrcom[5][2])+((cnk[9][0][0]*
      wbrcom[5][0])+(cnk[9][0][1]*wbrcom[5][1]))));
    vnb[5][1] = (vnk[9][1]+((cnk[9][1][2]*wbrcom[5][2])+((cnk[9][1][0]*
      wbrcom[5][0])+(cnk[9][1][1]*wbrcom[5][1]))));
    vnb[5][2] = (vnk[9][2]+((cnk[9][2][2]*wbrcom[5][2])+((cnk[9][2][0]*
      wbrcom[5][0])+(cnk[9][2][1]*wbrcom[5][1]))));
    vnb[6][0] = vnk[10][0];
    vnb[6][1] = vnk[10][1];
    vnb[6][2] = vnk[10][2];
    vnb[7][0] = vnk[11][0];
    vnb[7][1] = vnk[11][1];
    vnb[7][2] = vnk[11][2];
    vnb[8][0] = vnk[12][0];
    vnb[8][1] = vnk[12][1];
    vnb[8][2] = vnk[12][2];
    wbrcom[9][0] = ((rcom[9][2]*wk[13][1])-(rcom[9][1]*wk[13][2]));
    wbrcom[9][1] = ((rcom[9][0]*wk[13][2])-(rcom[9][2]*wk[13][0]));
    wbrcom[9][2] = ((rcom[9][1]*wk[13][0])-(rcom[9][0]*wk[13][1]));
    vnb[9][0] = (vnk[13][0]+((cnk[13][0][2]*wbrcom[9][2])+((cnk[13][0][0]*
      wbrcom[9][0])+(cnk[13][0][1]*wbrcom[9][1]))));
    vnb[9][1] = (vnk[13][1]+((cnk[13][1][2]*wbrcom[9][2])+((cnk[13][1][0]*
      wbrcom[9][0])+(cnk[13][1][1]*wbrcom[9][1]))));
    vnb[9][2] = (vnk[13][2]+((cnk[13][2][2]*wbrcom[9][2])+((cnk[13][2][0]*
      wbrcom[9][0])+(cnk[13][2][1]*wbrcom[9][1]))));
    wbrcom[10][0] = ((rcom[10][2]*wk[13][1])-(rcom[10][1]*wk[13][2]));
    wbrcom[10][1] = ((rcom[10][0]*wk[13][2])-(rcom[10][2]*wk[13][0]));
    wbrcom[10][2] = ((rcom[10][1]*wk[13][0])-(rcom[10][0]*wk[13][1]));
    vnb[10][0] = (vnk[13][0]+((cnk[13][0][2]*wbrcom[10][2])+((cnk[13][0][0]*
      wbrcom[10][0])+(cnk[13][0][1]*wbrcom[10][1]))));
    vnb[10][1] = (vnk[13][1]+((cnk[13][1][2]*wbrcom[10][2])+((cnk[13][1][0]*
      wbrcom[10][0])+(cnk[13][1][1]*wbrcom[10][1]))));
    vnb[10][2] = (vnk[13][2]+((cnk[13][2][2]*wbrcom[10][2])+((cnk[13][2][0]*
      wbrcom[10][0])+(cnk[13][2][1]*wbrcom[10][1]))));
    vnb[11][0] = vnk[14][0];
    vnb[11][1] = vnk[14][1];
    vnb[11][2] = vnk[14][2];
    vnb[12][0] = vnk[15][0];
    vnb[12][1] = vnk[15][1];
    vnb[12][2] = vnk[15][2];
    vnb[13][0] = vnk[16][0];
    vnb[13][1] = vnk[16][1];
    vnb[13][2] = vnk[16][2];
    wbrcom[14][0] = ((rcom[14][2]*wk[17][1])-(rcom[14][1]*wk[17][2]));
    wbrcom[14][1] = ((rcom[14][0]*wk[17][2])-(rcom[14][2]*wk[17][0]));
    wbrcom[14][2] = ((rcom[14][1]*wk[17][0])-(rcom[14][0]*wk[17][1]));
    vnb[14][0] = (vnk[17][0]+((cnk[17][0][2]*wbrcom[14][2])+((cnk[17][0][0]*
      wbrcom[14][0])+(cnk[17][0][1]*wbrcom[14][1]))));
    vnb[14][1] = (vnk[17][1]+((cnk[17][1][2]*wbrcom[14][2])+((cnk[17][1][0]*
      wbrcom[14][0])+(cnk[17][1][1]*wbrcom[14][1]))));
    vnb[14][2] = (vnk[17][2]+((cnk[17][2][2]*wbrcom[14][2])+((cnk[17][2][0]*
      wbrcom[14][0])+(cnk[17][2][1]*wbrcom[14][1]))));
    wbrcom[15][0] = ((rcom[15][2]*wk[17][1])-(rcom[15][1]*wk[17][2]));
    wbrcom[15][1] = ((rcom[15][0]*wk[17][2])-(rcom[15][2]*wk[17][0]));
    wbrcom[15][2] = ((rcom[15][1]*wk[17][0])-(rcom[15][0]*wk[17][1]));
    vnb[15][0] = (vnk[17][0]+((cnk[17][0][2]*wbrcom[15][2])+((cnk[17][0][0]*
      wbrcom[15][0])+(cnk[17][0][1]*wbrcom[15][1]))));
    vnb[15][1] = (vnk[17][1]+((cnk[17][1][2]*wbrcom[15][2])+((cnk[17][1][0]*
      wbrcom[15][0])+(cnk[17][1][1]*wbrcom[15][1]))));
    vnb[15][2] = (vnk[17][2]+((cnk[17][2][2]*wbrcom[15][2])+((cnk[17][2][0]*
      wbrcom[15][0])+(cnk[17][2][1]*wbrcom[15][1]))));
    vnb[16][0] = vnk[18][0];
    vnb[16][1] = vnk[18][1];
    vnb[16][2] = vnk[18][2];
    vnb[17][0] = vnk[19][0];
    vnb[17][1] = vnk[19][1];
    vnb[17][2] = vnk[19][2];
    vnb[18][0] = vnk[20][0];
    vnb[18][1] = vnk[20][1];
    vnb[18][2] = vnk[20][2];
    wbrcom[19][0] = ((rcom[19][2]*wk[21][1])-(rcom[19][1]*wk[21][2]));
    wbrcom[19][1] = ((rcom[19][0]*wk[21][2])-(rcom[19][2]*wk[21][0]));
    wbrcom[19][2] = ((rcom[19][1]*wk[21][0])-(rcom[19][0]*wk[21][1]));
    vnb[19][0] = (vnk[21][0]+((cnk[21][0][2]*wbrcom[19][2])+((cnk[21][0][0]*
      wbrcom[19][0])+(cnk[21][0][1]*wbrcom[19][1]))));
    vnb[19][1] = (vnk[21][1]+((cnk[21][1][2]*wbrcom[19][2])+((cnk[21][1][0]*
      wbrcom[19][0])+(cnk[21][1][1]*wbrcom[19][1]))));
    vnb[19][2] = (vnk[21][2]+((cnk[21][2][2]*wbrcom[19][2])+((cnk[21][2][0]*
      wbrcom[19][0])+(cnk[21][2][1]*wbrcom[19][1]))));
    wbrcom[20][0] = ((rcom[20][2]*wk[21][1])-(rcom[20][1]*wk[21][2]));
    wbrcom[20][1] = ((rcom[20][0]*wk[21][2])-(rcom[20][2]*wk[21][0]));
    wbrcom[20][2] = ((rcom[20][1]*wk[21][0])-(rcom[20][0]*wk[21][1]));
    vnb[20][0] = (vnk[21][0]+((cnk[21][0][2]*wbrcom[20][2])+((cnk[21][0][0]*
      wbrcom[20][0])+(cnk[21][0][1]*wbrcom[20][1]))));
    vnb[20][1] = (vnk[21][1]+((cnk[21][1][2]*wbrcom[20][2])+((cnk[21][1][0]*
      wbrcom[20][0])+(cnk[21][1][1]*wbrcom[20][1]))));
    vnb[20][2] = (vnk[21][2]+((cnk[21][2][2]*wbrcom[20][2])+((cnk[21][2][0]*
      wbrcom[20][0])+(cnk[21][2][1]*wbrcom[20][1]))));
/*
Compute qdot (kinematical equations)
*/
    qdot[0] = u[0];
    qdot[1] = u[1];
    qdot[2] = u[2];
    qdot[3] = (.5*((q[22]*u[3])+((q[4]*u[5])-(q[5]*u[4]))));
    qdot[4] = (.5*((q[5]*u[3])+((q[22]*u[4])-(q[3]*u[5]))));
    qdot[5] = (.5*(((q[3]*u[4])+(q[22]*u[5]))-(q[4]*u[3])));
    qdot[22] = -(.5*((q[3]*u[3])+((q[4]*u[4])+(q[5]*u[5]))));
    if (stabvel  !=  0.) {
        ee = ((q[22]*q[22])+((q[5]*q[5])+((q[3]*q[3])+(q[4]*q[4]))));
        stab = ((stabvel*(1.-ee))/ee);
        qdot[3] = (qdot[3]+(q[3]*stab));
        qdot[4] = (qdot[4]+(q[4]*stab));
        qdot[5] = (qdot[5]+(q[5]*stab));
        qdot[22] = (qdot[22]+(q[22]*stab));
    }
    qdot[6] = u[6];
    qdot[7] = u[7];
    qdot[8] = u[8];
    qdot[9] = u[9];
    qdot[10] = u[10];
    qdot[11] = u[11];
    qdot[12] = u[12];
    qdot[13] = u[13];
    qdot[14] = u[14];
    qdot[15] = u[15];
    qdot[16] = u[16];
    qdot[17] = u[17];
    qdot[18] = u[18];
    qdot[19] = u[19];
    qdot[20] = u[20];
    qdot[21] = u[21];
/*
Compute constraint velocity errors
*/
    skipus: ;
/*
Initialize applied forces and torques to zero
*/
    for (i = 0; i < 21; i++) {
        for (j = 0; j < 3; j++) {
            ufk[i][j] = 0.;
            utk[i][j] = 0.;
        }
    }
    for (i = 0; i < 22; i++) {
        utau[i] = 0.;
    }
    ltauflg = 0;
    fs0flg = 0;
/*
Initialize prescribed motions
*/
    uacc[0] = 0.;
    uvel[0] = u[0];
    upos[0] = q[0];
    uacc[1] = 0.;
    uvel[1] = u[1];
    upos[1] = q[1];
    uacc[2] = 0.;
    uvel[2] = u[2];
    upos[2] = q[2];
    uacc[3] = 0.;
    uvel[3] = u[3];
    upos[3] = q[3];
    uacc[4] = 0.;
    uvel[4] = u[4];
    upos[4] = q[4];
    uacc[5] = 0.;
    uvel[5] = u[5];
    upos[5] = q[5];
    uacc[6] = 0.;
    uvel[6] = u[6];
    upos[6] = q[6];
    uacc[7] = 0.;
    uvel[7] = u[7];
    upos[7] = q[7];
    uacc[8] = 0.;
    uvel[8] = u[8];
    upos[8] = q[8];
    uacc[9] = 0.;
    uvel[9] = u[9];
    upos[9] = q[9];
    uacc[10] = 0.;
    uvel[10] = u[10];
    upos[10] = q[10];
    uacc[11] = 0.;
    uvel[11] = u[11];
    upos[11] = q[11];
    uacc[12] = 0.;
    uvel[12] = u[12];
    upos[12] = q[12];
    uacc[13] = 0.;
    uvel[13] = u[13];
    upos[13] = q[13];
    uacc[14] = 0.;
    uvel[14] = u[14];
    upos[14] = q[14];
    uacc[15] = 0.;
    uvel[15] = u[15];
    upos[15] = q[15];
    uacc[16] = 0.;
    uvel[16] = u[16];
    upos[16] = q[16];
    uacc[17] = 0.;
    uvel[17] = u[17];
    upos[17] = q[17];
    uacc[18] = 0.;
    uvel[18] = u[18];
    upos[18] = q[18];
    uacc[19] = 0.;
    uvel[19] = u[19];
    upos[19] = q[19];
    uacc[20] = 0.;
    uvel[20] = u[20];
    upos[20] = q[20];
    uacc[21] = 0.;
    uvel[21] = u[21];
    upos[21] = q[21];
/*
 Used 0.01 seconds CPU time,
 0 additional bytes of memory.
 Equations contain 2240 adds/subtracts/negates
                   2998 multiplies
                      4 divides
                   1740 assignments
*/
}

void allegro_air_qdot(double oqdot[23])
{
/*
Return position coordinate derivatives for tree joints.
*/
    int i;

    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(63,23);
        return;
    }
    for (i = 0; i <= 22; i++) {
        oqdot[i] = qdot[i];
    }
}

void allegro_air_u2qdot(double uin[22],
    double oqdot[23])
{
/*
Convert velocities to qdots.
*/
    int i;

    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(64,23);
        return;
    }
    for (i = 0; i <= 21; i++) {
        oqdot[i] = uin[i];
    }
    oqdot[3] = (.5*((q[22]*uin[3])+((q[4]*uin[5])-(q[5]*uin[4]))));
    oqdot[4] = (.5*((q[5]*uin[3])+((q[22]*uin[4])-(q[3]*uin[5]))));
    oqdot[5] = (.5*(((q[3]*uin[4])+(q[22]*uin[5]))-(q[4]*uin[3])));
    oqdot[22] = -(.5*((q[3]*uin[3])+((q[4]*uin[4])+(q[5]*uin[5]))));
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    9 adds/subtracts/negates
                     16 multiplies
                      0 divides
                     26 assignments
*/
}

void allegro_air_psstate(double lqin[1])
{

    if (roustate != 2) {
        allegro_air_seterr(9,23);
        return;
    }
}

void allegro_air_dovpk(void)
{

    if (vpkflg == 0) {
/*
Compute Wpk (partial angular velocities)
*/
        Wpk[3][3][0] = 1.;
        Wpk[3][4][0] = 1.;
        Wpk[3][5][0] = 1.;
        Wpk[3][6][0] = Cik[6][0][0];
        Wpk[3][6][1] = Cik[6][0][1];
        Wpk[3][6][2] = Cik[6][0][2];
        Wpk[3][7][0] = ((Cik[6][0][2]*Cik[7][2][0])+((Cik[6][0][0]*Cik[7][0][0])
          +(Cik[6][0][1]*Cik[7][1][0])));
        Wpk[3][7][1] = ((Cik[6][0][2]*Cik[7][2][1])+((Cik[6][0][0]*Cik[7][0][1])
          +(Cik[6][0][1]*Cik[7][1][1])));
        Wpk[3][7][2] = ((Cik[6][0][2]*Cik[7][2][2])+((Cik[6][0][0]*Cik[7][0][2])
          +(Cik[6][0][1]*Cik[7][1][2])));
        Wpk[3][8][0] = ((Cik[8][2][0]*Wpk[3][7][2])+((Cik[8][0][0]*Wpk[3][7][0])
          +(Cik[8][1][0]*Wpk[3][7][1])));
        Wpk[3][8][1] = ((Cik[8][2][1]*Wpk[3][7][2])+((Cik[8][0][1]*Wpk[3][7][0])
          +(Cik[8][1][1]*Wpk[3][7][1])));
        Wpk[3][8][2] = ((Cik[8][2][2]*Wpk[3][7][2])+((Cik[8][0][2]*Wpk[3][7][0])
          +(Cik[8][1][2]*Wpk[3][7][1])));
        Wpk[3][9][0] = ((Cik[9][2][0]*Wpk[3][8][2])+((Cik[9][0][0]*Wpk[3][8][0])
          +(Cik[9][1][0]*Wpk[3][8][1])));
        Wpk[3][9][1] = ((Cik[9][2][1]*Wpk[3][8][2])+((Cik[9][0][1]*Wpk[3][8][0])
          +(Cik[9][1][1]*Wpk[3][8][1])));
        Wpk[3][9][2] = ((Cik[9][2][2]*Wpk[3][8][2])+((Cik[9][0][2]*Wpk[3][8][0])
          +(Cik[9][1][2]*Wpk[3][8][1])));
        Wpk[3][10][0] = Cik[10][0][0];
        Wpk[3][10][1] = Cik[10][0][1];
        Wpk[3][10][2] = Cik[10][0][2];
        Wpk[3][11][0] = ((Cik[10][0][2]*Cik[11][2][0])+((Cik[10][0][0]*
          Cik[11][0][0])+(Cik[10][0][1]*Cik[11][1][0])));
        Wpk[3][11][1] = ((Cik[10][0][2]*Cik[11][2][1])+((Cik[10][0][0]*
          Cik[11][0][1])+(Cik[10][0][1]*Cik[11][1][1])));
        Wpk[3][11][2] = ((Cik[10][0][2]*Cik[11][2][2])+((Cik[10][0][0]*
          Cik[11][0][2])+(Cik[10][0][1]*Cik[11][1][2])));
        Wpk[3][12][0] = ((Cik[12][2][0]*Wpk[3][11][2])+((Cik[12][0][0]*
          Wpk[3][11][0])+(Cik[12][1][0]*Wpk[3][11][1])));
        Wpk[3][12][1] = ((Cik[12][2][1]*Wpk[3][11][2])+((Cik[12][0][1]*
          Wpk[3][11][0])+(Cik[12][1][1]*Wpk[3][11][1])));
        Wpk[3][12][2] = ((Cik[12][2][2]*Wpk[3][11][2])+((Cik[12][0][2]*
          Wpk[3][11][0])+(Cik[12][1][2]*Wpk[3][11][1])));
        Wpk[3][13][0] = ((Cik[13][2][0]*Wpk[3][12][2])+((Cik[13][0][0]*
          Wpk[3][12][0])+(Cik[13][1][0]*Wpk[3][12][1])));
        Wpk[3][13][1] = ((Cik[13][2][1]*Wpk[3][12][2])+((Cik[13][0][1]*
          Wpk[3][12][0])+(Cik[13][1][1]*Wpk[3][12][1])));
        Wpk[3][13][2] = ((Cik[13][2][2]*Wpk[3][12][2])+((Cik[13][0][2]*
          Wpk[3][12][0])+(Cik[13][1][2]*Wpk[3][12][1])));
        Wpk[3][14][0] = Cik[14][0][0];
        Wpk[3][14][1] = Cik[14][0][1];
        Wpk[3][14][2] = Cik[14][0][2];
        Wpk[3][15][0] = ((Cik[14][0][2]*Cik[15][2][0])+((Cik[14][0][0]*
          Cik[15][0][0])+(Cik[14][0][1]*Cik[15][1][0])));
        Wpk[3][15][1] = ((Cik[14][0][2]*Cik[15][2][1])+((Cik[14][0][0]*
          Cik[15][0][1])+(Cik[14][0][1]*Cik[15][1][1])));
        Wpk[3][15][2] = ((Cik[14][0][2]*Cik[15][2][2])+((Cik[14][0][0]*
          Cik[15][0][2])+(Cik[14][0][1]*Cik[15][1][2])));
        Wpk[3][16][0] = ((Cik[16][2][0]*Wpk[3][15][2])+((Cik[16][0][0]*
          Wpk[3][15][0])+(Cik[16][1][0]*Wpk[3][15][1])));
        Wpk[3][16][1] = ((Cik[16][2][1]*Wpk[3][15][2])+((Cik[16][0][1]*
          Wpk[3][15][0])+(Cik[16][1][1]*Wpk[3][15][1])));
        Wpk[3][16][2] = ((Cik[16][2][2]*Wpk[3][15][2])+((Cik[16][0][2]*
          Wpk[3][15][0])+(Cik[16][1][2]*Wpk[3][15][1])));
        Wpk[3][17][0] = ((Cik[17][2][0]*Wpk[3][16][2])+((Cik[17][0][0]*
          Wpk[3][16][0])+(Cik[17][1][0]*Wpk[3][16][1])));
        Wpk[3][17][1] = ((Cik[17][2][1]*Wpk[3][16][2])+((Cik[17][0][1]*
          Wpk[3][16][0])+(Cik[17][1][1]*Wpk[3][16][1])));
        Wpk[3][17][2] = ((Cik[17][2][2]*Wpk[3][16][2])+((Cik[17][0][2]*
          Wpk[3][16][0])+(Cik[17][1][2]*Wpk[3][16][1])));
        Wpk[3][18][0] = Cik[18][0][0];
        Wpk[3][18][1] = Cik[18][0][1];
        Wpk[3][18][2] = Cik[18][0][2];
        Wpk[3][19][0] = ((Cik[18][0][2]*Cik[19][2][0])+((Cik[18][0][0]*
          Cik[19][0][0])+(Cik[18][0][1]*Cik[19][1][0])));
        Wpk[3][19][1] = ((Cik[18][0][2]*Cik[19][2][1])+((Cik[18][0][0]*
          Cik[19][0][1])+(Cik[18][0][1]*Cik[19][1][1])));
        Wpk[3][19][2] = ((Cik[18][0][2]*Cik[19][2][2])+((Cik[18][0][0]*
          Cik[19][0][2])+(Cik[18][0][1]*Cik[19][1][2])));
        Wpk[3][20][0] = ((Cik[20][2][0]*Wpk[3][19][2])+((Cik[20][0][0]*
          Wpk[3][19][0])+(Cik[20][1][0]*Wpk[3][19][1])));
        Wpk[3][20][1] = ((Cik[20][2][1]*Wpk[3][19][2])+((Cik[20][0][1]*
          Wpk[3][19][0])+(Cik[20][1][1]*Wpk[3][19][1])));
        Wpk[3][20][2] = ((Cik[20][2][2]*Wpk[3][19][2])+((Cik[20][0][2]*
          Wpk[3][19][0])+(Cik[20][1][2]*Wpk[3][19][1])));
        Wpk[3][21][0] = ((Cik[21][2][0]*Wpk[3][20][2])+((Cik[21][0][0]*
          Wpk[3][20][0])+(Cik[21][1][0]*Wpk[3][20][1])));
        Wpk[3][21][1] = ((Cik[21][2][1]*Wpk[3][20][2])+((Cik[21][0][1]*
          Wpk[3][20][0])+(Cik[21][1][1]*Wpk[3][20][1])));
        Wpk[3][21][2] = ((Cik[21][2][2]*Wpk[3][20][2])+((Cik[21][0][2]*
          Wpk[3][20][0])+(Cik[21][1][2]*Wpk[3][20][1])));
        Wpk[4][4][1] = 1.;
        Wpk[4][5][1] = 1.;
        Wpk[4][6][0] = Cik[6][1][0];
        Wpk[4][6][1] = Cik[6][1][1];
        Wpk[4][6][2] = Cik[6][1][2];
        Wpk[4][7][0] = ((Cik[6][1][2]*Cik[7][2][0])+((Cik[6][1][0]*Cik[7][0][0])
          +(Cik[6][1][1]*Cik[7][1][0])));
        Wpk[4][7][1] = ((Cik[6][1][2]*Cik[7][2][1])+((Cik[6][1][0]*Cik[7][0][1])
          +(Cik[6][1][1]*Cik[7][1][1])));
        Wpk[4][7][2] = ((Cik[6][1][2]*Cik[7][2][2])+((Cik[6][1][0]*Cik[7][0][2])
          +(Cik[6][1][1]*Cik[7][1][2])));
        Wpk[4][8][0] = ((Cik[8][2][0]*Wpk[4][7][2])+((Cik[8][0][0]*Wpk[4][7][0])
          +(Cik[8][1][0]*Wpk[4][7][1])));
        Wpk[4][8][1] = ((Cik[8][2][1]*Wpk[4][7][2])+((Cik[8][0][1]*Wpk[4][7][0])
          +(Cik[8][1][1]*Wpk[4][7][1])));
        Wpk[4][8][2] = ((Cik[8][2][2]*Wpk[4][7][2])+((Cik[8][0][2]*Wpk[4][7][0])
          +(Cik[8][1][2]*Wpk[4][7][1])));
        Wpk[4][9][0] = ((Cik[9][2][0]*Wpk[4][8][2])+((Cik[9][0][0]*Wpk[4][8][0])
          +(Cik[9][1][0]*Wpk[4][8][1])));
        Wpk[4][9][1] = ((Cik[9][2][1]*Wpk[4][8][2])+((Cik[9][0][1]*Wpk[4][8][0])
          +(Cik[9][1][1]*Wpk[4][8][1])));
        Wpk[4][9][2] = ((Cik[9][2][2]*Wpk[4][8][2])+((Cik[9][0][2]*Wpk[4][8][0])
          +(Cik[9][1][2]*Wpk[4][8][1])));
        Wpk[4][10][0] = Cik[10][1][0];
        Wpk[4][10][1] = Cik[10][1][1];
        Wpk[4][10][2] = Cik[10][1][2];
        Wpk[4][11][0] = ((Cik[10][1][2]*Cik[11][2][0])+((Cik[10][1][0]*
          Cik[11][0][0])+(Cik[10][1][1]*Cik[11][1][0])));
        Wpk[4][11][1] = ((Cik[10][1][2]*Cik[11][2][1])+((Cik[10][1][0]*
          Cik[11][0][1])+(Cik[10][1][1]*Cik[11][1][1])));
        Wpk[4][11][2] = ((Cik[10][1][2]*Cik[11][2][2])+((Cik[10][1][0]*
          Cik[11][0][2])+(Cik[10][1][1]*Cik[11][1][2])));
        Wpk[4][12][0] = ((Cik[12][2][0]*Wpk[4][11][2])+((Cik[12][0][0]*
          Wpk[4][11][0])+(Cik[12][1][0]*Wpk[4][11][1])));
        Wpk[4][12][1] = ((Cik[12][2][1]*Wpk[4][11][2])+((Cik[12][0][1]*
          Wpk[4][11][0])+(Cik[12][1][1]*Wpk[4][11][1])));
        Wpk[4][12][2] = ((Cik[12][2][2]*Wpk[4][11][2])+((Cik[12][0][2]*
          Wpk[4][11][0])+(Cik[12][1][2]*Wpk[4][11][1])));
        Wpk[4][13][0] = ((Cik[13][2][0]*Wpk[4][12][2])+((Cik[13][0][0]*
          Wpk[4][12][0])+(Cik[13][1][0]*Wpk[4][12][1])));
        Wpk[4][13][1] = ((Cik[13][2][1]*Wpk[4][12][2])+((Cik[13][0][1]*
          Wpk[4][12][0])+(Cik[13][1][1]*Wpk[4][12][1])));
        Wpk[4][13][2] = ((Cik[13][2][2]*Wpk[4][12][2])+((Cik[13][0][2]*
          Wpk[4][12][0])+(Cik[13][1][2]*Wpk[4][12][1])));
        Wpk[4][14][0] = Cik[14][1][0];
        Wpk[4][14][1] = Cik[14][1][1];
        Wpk[4][14][2] = Cik[14][1][2];
        Wpk[4][15][0] = ((Cik[14][1][2]*Cik[15][2][0])+((Cik[14][1][0]*
          Cik[15][0][0])+(Cik[14][1][1]*Cik[15][1][0])));
        Wpk[4][15][1] = ((Cik[14][1][2]*Cik[15][2][1])+((Cik[14][1][0]*
          Cik[15][0][1])+(Cik[14][1][1]*Cik[15][1][1])));
        Wpk[4][15][2] = ((Cik[14][1][2]*Cik[15][2][2])+((Cik[14][1][0]*
          Cik[15][0][2])+(Cik[14][1][1]*Cik[15][1][2])));
        Wpk[4][16][0] = ((Cik[16][2][0]*Wpk[4][15][2])+((Cik[16][0][0]*
          Wpk[4][15][0])+(Cik[16][1][0]*Wpk[4][15][1])));
        Wpk[4][16][1] = ((Cik[16][2][1]*Wpk[4][15][2])+((Cik[16][0][1]*
          Wpk[4][15][0])+(Cik[16][1][1]*Wpk[4][15][1])));
        Wpk[4][16][2] = ((Cik[16][2][2]*Wpk[4][15][2])+((Cik[16][0][2]*
          Wpk[4][15][0])+(Cik[16][1][2]*Wpk[4][15][1])));
        Wpk[4][17][0] = ((Cik[17][2][0]*Wpk[4][16][2])+((Cik[17][0][0]*
          Wpk[4][16][0])+(Cik[17][1][0]*Wpk[4][16][1])));
        Wpk[4][17][1] = ((Cik[17][2][1]*Wpk[4][16][2])+((Cik[17][0][1]*
          Wpk[4][16][0])+(Cik[17][1][1]*Wpk[4][16][1])));
        Wpk[4][17][2] = ((Cik[17][2][2]*Wpk[4][16][2])+((Cik[17][0][2]*
          Wpk[4][16][0])+(Cik[17][1][2]*Wpk[4][16][1])));
        Wpk[4][18][0] = Cik[18][1][0];
        Wpk[4][18][1] = Cik[18][1][1];
        Wpk[4][18][2] = Cik[18][1][2];
        Wpk[4][19][0] = ((Cik[18][1][2]*Cik[19][2][0])+((Cik[18][1][0]*
          Cik[19][0][0])+(Cik[18][1][1]*Cik[19][1][0])));
        Wpk[4][19][1] = ((Cik[18][1][2]*Cik[19][2][1])+((Cik[18][1][0]*
          Cik[19][0][1])+(Cik[18][1][1]*Cik[19][1][1])));
        Wpk[4][19][2] = ((Cik[18][1][2]*Cik[19][2][2])+((Cik[18][1][0]*
          Cik[19][0][2])+(Cik[18][1][1]*Cik[19][1][2])));
        Wpk[4][20][0] = ((Cik[20][2][0]*Wpk[4][19][2])+((Cik[20][0][0]*
          Wpk[4][19][0])+(Cik[20][1][0]*Wpk[4][19][1])));
        Wpk[4][20][1] = ((Cik[20][2][1]*Wpk[4][19][2])+((Cik[20][0][1]*
          Wpk[4][19][0])+(Cik[20][1][1]*Wpk[4][19][1])));
        Wpk[4][20][2] = ((Cik[20][2][2]*Wpk[4][19][2])+((Cik[20][0][2]*
          Wpk[4][19][0])+(Cik[20][1][2]*Wpk[4][19][1])));
        Wpk[4][21][0] = ((Cik[21][2][0]*Wpk[4][20][2])+((Cik[21][0][0]*
          Wpk[4][20][0])+(Cik[21][1][0]*Wpk[4][20][1])));
        Wpk[4][21][1] = ((Cik[21][2][1]*Wpk[4][20][2])+((Cik[21][0][1]*
          Wpk[4][20][0])+(Cik[21][1][1]*Wpk[4][20][1])));
        Wpk[4][21][2] = ((Cik[21][2][2]*Wpk[4][20][2])+((Cik[21][0][2]*
          Wpk[4][20][0])+(Cik[21][1][2]*Wpk[4][20][1])));
        Wpk[5][5][2] = 1.;
        Wpk[5][6][0] = Cik[6][2][0];
        Wpk[5][6][1] = Cik[6][2][1];
        Wpk[5][6][2] = Cik[6][2][2];
        Wpk[5][7][0] = ((Cik[6][2][2]*Cik[7][2][0])+((Cik[6][2][0]*Cik[7][0][0])
          +(Cik[6][2][1]*Cik[7][1][0])));
        Wpk[5][7][1] = ((Cik[6][2][2]*Cik[7][2][1])+((Cik[6][2][0]*Cik[7][0][1])
          +(Cik[6][2][1]*Cik[7][1][1])));
        Wpk[5][7][2] = ((Cik[6][2][2]*Cik[7][2][2])+((Cik[6][2][0]*Cik[7][0][2])
          +(Cik[6][2][1]*Cik[7][1][2])));
        Wpk[5][8][0] = ((Cik[8][2][0]*Wpk[5][7][2])+((Cik[8][0][0]*Wpk[5][7][0])
          +(Cik[8][1][0]*Wpk[5][7][1])));
        Wpk[5][8][1] = ((Cik[8][2][1]*Wpk[5][7][2])+((Cik[8][0][1]*Wpk[5][7][0])
          +(Cik[8][1][1]*Wpk[5][7][1])));
        Wpk[5][8][2] = ((Cik[8][2][2]*Wpk[5][7][2])+((Cik[8][0][2]*Wpk[5][7][0])
          +(Cik[8][1][2]*Wpk[5][7][1])));
        Wpk[5][9][0] = ((Cik[9][2][0]*Wpk[5][8][2])+((Cik[9][0][0]*Wpk[5][8][0])
          +(Cik[9][1][0]*Wpk[5][8][1])));
        Wpk[5][9][1] = ((Cik[9][2][1]*Wpk[5][8][2])+((Cik[9][0][1]*Wpk[5][8][0])
          +(Cik[9][1][1]*Wpk[5][8][1])));
        Wpk[5][9][2] = ((Cik[9][2][2]*Wpk[5][8][2])+((Cik[9][0][2]*Wpk[5][8][0])
          +(Cik[9][1][2]*Wpk[5][8][1])));
        Wpk[5][10][0] = Cik[10][2][0];
        Wpk[5][10][1] = Cik[10][2][1];
        Wpk[5][10][2] = Cik[10][2][2];
        Wpk[5][11][0] = ((Cik[10][2][2]*Cik[11][2][0])+((Cik[10][2][0]*
          Cik[11][0][0])+(Cik[10][2][1]*Cik[11][1][0])));
        Wpk[5][11][1] = ((Cik[10][2][2]*Cik[11][2][1])+((Cik[10][2][0]*
          Cik[11][0][1])+(Cik[10][2][1]*Cik[11][1][1])));
        Wpk[5][11][2] = ((Cik[10][2][2]*Cik[11][2][2])+((Cik[10][2][0]*
          Cik[11][0][2])+(Cik[10][2][1]*Cik[11][1][2])));
        Wpk[5][12][0] = ((Cik[12][2][0]*Wpk[5][11][2])+((Cik[12][0][0]*
          Wpk[5][11][0])+(Cik[12][1][0]*Wpk[5][11][1])));
        Wpk[5][12][1] = ((Cik[12][2][1]*Wpk[5][11][2])+((Cik[12][0][1]*
          Wpk[5][11][0])+(Cik[12][1][1]*Wpk[5][11][1])));
        Wpk[5][12][2] = ((Cik[12][2][2]*Wpk[5][11][2])+((Cik[12][0][2]*
          Wpk[5][11][0])+(Cik[12][1][2]*Wpk[5][11][1])));
        Wpk[5][13][0] = ((Cik[13][2][0]*Wpk[5][12][2])+((Cik[13][0][0]*
          Wpk[5][12][0])+(Cik[13][1][0]*Wpk[5][12][1])));
        Wpk[5][13][1] = ((Cik[13][2][1]*Wpk[5][12][2])+((Cik[13][0][1]*
          Wpk[5][12][0])+(Cik[13][1][1]*Wpk[5][12][1])));
        Wpk[5][13][2] = ((Cik[13][2][2]*Wpk[5][12][2])+((Cik[13][0][2]*
          Wpk[5][12][0])+(Cik[13][1][2]*Wpk[5][12][1])));
        Wpk[5][14][0] = Cik[14][2][0];
        Wpk[5][14][1] = Cik[14][2][1];
        Wpk[5][14][2] = Cik[14][2][2];
        Wpk[5][15][0] = ((Cik[14][2][2]*Cik[15][2][0])+((Cik[14][2][0]*
          Cik[15][0][0])+(Cik[14][2][1]*Cik[15][1][0])));
        Wpk[5][15][1] = ((Cik[14][2][2]*Cik[15][2][1])+((Cik[14][2][0]*
          Cik[15][0][1])+(Cik[14][2][1]*Cik[15][1][1])));
        Wpk[5][15][2] = ((Cik[14][2][2]*Cik[15][2][2])+((Cik[14][2][0]*
          Cik[15][0][2])+(Cik[14][2][1]*Cik[15][1][2])));
        Wpk[5][16][0] = ((Cik[16][2][0]*Wpk[5][15][2])+((Cik[16][0][0]*
          Wpk[5][15][0])+(Cik[16][1][0]*Wpk[5][15][1])));
        Wpk[5][16][1] = ((Cik[16][2][1]*Wpk[5][15][2])+((Cik[16][0][1]*
          Wpk[5][15][0])+(Cik[16][1][1]*Wpk[5][15][1])));
        Wpk[5][16][2] = ((Cik[16][2][2]*Wpk[5][15][2])+((Cik[16][0][2]*
          Wpk[5][15][0])+(Cik[16][1][2]*Wpk[5][15][1])));
        Wpk[5][17][0] = ((Cik[17][2][0]*Wpk[5][16][2])+((Cik[17][0][0]*
          Wpk[5][16][0])+(Cik[17][1][0]*Wpk[5][16][1])));
        Wpk[5][17][1] = ((Cik[17][2][1]*Wpk[5][16][2])+((Cik[17][0][1]*
          Wpk[5][16][0])+(Cik[17][1][1]*Wpk[5][16][1])));
        Wpk[5][17][2] = ((Cik[17][2][2]*Wpk[5][16][2])+((Cik[17][0][2]*
          Wpk[5][16][0])+(Cik[17][1][2]*Wpk[5][16][1])));
        Wpk[5][18][0] = Cik[18][2][0];
        Wpk[5][18][1] = Cik[18][2][1];
        Wpk[5][18][2] = Cik[18][2][2];
        Wpk[5][19][0] = ((Cik[18][2][2]*Cik[19][2][0])+((Cik[18][2][0]*
          Cik[19][0][0])+(Cik[18][2][1]*Cik[19][1][0])));
        Wpk[5][19][1] = ((Cik[18][2][2]*Cik[19][2][1])+((Cik[18][2][0]*
          Cik[19][0][1])+(Cik[18][2][1]*Cik[19][1][1])));
        Wpk[5][19][2] = ((Cik[18][2][2]*Cik[19][2][2])+((Cik[18][2][0]*
          Cik[19][0][2])+(Cik[18][2][1]*Cik[19][1][2])));
        Wpk[5][20][0] = ((Cik[20][2][0]*Wpk[5][19][2])+((Cik[20][0][0]*
          Wpk[5][19][0])+(Cik[20][1][0]*Wpk[5][19][1])));
        Wpk[5][20][1] = ((Cik[20][2][1]*Wpk[5][19][2])+((Cik[20][0][1]*
          Wpk[5][19][0])+(Cik[20][1][1]*Wpk[5][19][1])));
        Wpk[5][20][2] = ((Cik[20][2][2]*Wpk[5][19][2])+((Cik[20][0][2]*
          Wpk[5][19][0])+(Cik[20][1][2]*Wpk[5][19][1])));
        Wpk[5][21][0] = ((Cik[21][2][0]*Wpk[5][20][2])+((Cik[21][0][0]*
          Wpk[5][20][0])+(Cik[21][1][0]*Wpk[5][20][1])));
        Wpk[5][21][1] = ((Cik[21][2][1]*Wpk[5][20][2])+((Cik[21][0][1]*
          Wpk[5][20][0])+(Cik[21][1][1]*Wpk[5][20][1])));
        Wpk[5][21][2] = ((Cik[21][2][2]*Wpk[5][20][2])+((Cik[21][0][2]*
          Wpk[5][20][0])+(Cik[21][1][2]*Wpk[5][20][1])));
        Wpk[6][6][0] = pin[6][0];
        Wpk[6][6][1] = pin[6][1];
        Wpk[6][6][2] = pin[6][2];
        Wpk[6][7][0] = ((Cik[7][2][0]*pin[6][2])+((Cik[7][0][0]*pin[6][0])+(
          Cik[7][1][0]*pin[6][1])));
        Wpk[6][7][1] = ((Cik[7][2][1]*pin[6][2])+((Cik[7][0][1]*pin[6][0])+(
          Cik[7][1][1]*pin[6][1])));
        Wpk[6][7][2] = ((Cik[7][2][2]*pin[6][2])+((Cik[7][0][2]*pin[6][0])+(
          Cik[7][1][2]*pin[6][1])));
        Wpk[6][8][0] = ((Cik[8][2][0]*Wpk[6][7][2])+((Cik[8][0][0]*Wpk[6][7][0])
          +(Cik[8][1][0]*Wpk[6][7][1])));
        Wpk[6][8][1] = ((Cik[8][2][1]*Wpk[6][7][2])+((Cik[8][0][1]*Wpk[6][7][0])
          +(Cik[8][1][1]*Wpk[6][7][1])));
        Wpk[6][8][2] = ((Cik[8][2][2]*Wpk[6][7][2])+((Cik[8][0][2]*Wpk[6][7][0])
          +(Cik[8][1][2]*Wpk[6][7][1])));
        Wpk[6][9][0] = ((Cik[9][2][0]*Wpk[6][8][2])+((Cik[9][0][0]*Wpk[6][8][0])
          +(Cik[9][1][0]*Wpk[6][8][1])));
        Wpk[6][9][1] = ((Cik[9][2][1]*Wpk[6][8][2])+((Cik[9][0][1]*Wpk[6][8][0])
          +(Cik[9][1][1]*Wpk[6][8][1])));
        Wpk[6][9][2] = ((Cik[9][2][2]*Wpk[6][8][2])+((Cik[9][0][2]*Wpk[6][8][0])
          +(Cik[9][1][2]*Wpk[6][8][1])));
        Wpk[7][7][0] = pin[7][0];
        Wpk[7][7][1] = pin[7][1];
        Wpk[7][7][2] = pin[7][2];
        Wpk[7][8][0] = ((Cik[8][2][0]*pin[7][2])+((Cik[8][0][0]*pin[7][0])+(
          Cik[8][1][0]*pin[7][1])));
        Wpk[7][8][1] = ((Cik[8][2][1]*pin[7][2])+((Cik[8][0][1]*pin[7][0])+(
          Cik[8][1][1]*pin[7][1])));
        Wpk[7][8][2] = ((Cik[8][2][2]*pin[7][2])+((Cik[8][0][2]*pin[7][0])+(
          Cik[8][1][2]*pin[7][1])));
        Wpk[7][9][0] = ((Cik[9][2][0]*Wpk[7][8][2])+((Cik[9][0][0]*Wpk[7][8][0])
          +(Cik[9][1][0]*Wpk[7][8][1])));
        Wpk[7][9][1] = ((Cik[9][2][1]*Wpk[7][8][2])+((Cik[9][0][1]*Wpk[7][8][0])
          +(Cik[9][1][1]*Wpk[7][8][1])));
        Wpk[7][9][2] = ((Cik[9][2][2]*Wpk[7][8][2])+((Cik[9][0][2]*Wpk[7][8][0])
          +(Cik[9][1][2]*Wpk[7][8][1])));
        Wpk[8][8][0] = pin[8][0];
        Wpk[8][8][1] = pin[8][1];
        Wpk[8][8][2] = pin[8][2];
        Wpk[8][9][0] = ((Cik[9][2][0]*pin[8][2])+((Cik[9][0][0]*pin[8][0])+(
          Cik[9][1][0]*pin[8][1])));
        Wpk[8][9][1] = ((Cik[9][2][1]*pin[8][2])+((Cik[9][0][1]*pin[8][0])+(
          Cik[9][1][1]*pin[8][1])));
        Wpk[8][9][2] = ((Cik[9][2][2]*pin[8][2])+((Cik[9][0][2]*pin[8][0])+(
          Cik[9][1][2]*pin[8][1])));
        Wpk[9][9][0] = pin[9][0];
        Wpk[9][9][1] = pin[9][1];
        Wpk[9][9][2] = pin[9][2];
        Wpk[10][10][0] = pin[10][0];
        Wpk[10][10][1] = pin[10][1];
        Wpk[10][10][2] = pin[10][2];
        Wpk[10][11][0] = ((Cik[11][2][0]*pin[10][2])+((Cik[11][0][0]*pin[10][0])
          +(Cik[11][1][0]*pin[10][1])));
        Wpk[10][11][1] = ((Cik[11][2][1]*pin[10][2])+((Cik[11][0][1]*pin[10][0])
          +(Cik[11][1][1]*pin[10][1])));
        Wpk[10][11][2] = ((Cik[11][2][2]*pin[10][2])+((Cik[11][0][2]*pin[10][0])
          +(Cik[11][1][2]*pin[10][1])));
        Wpk[10][12][0] = ((Cik[12][2][0]*Wpk[10][11][2])+((Cik[12][0][0]*
          Wpk[10][11][0])+(Cik[12][1][0]*Wpk[10][11][1])));
        Wpk[10][12][1] = ((Cik[12][2][1]*Wpk[10][11][2])+((Cik[12][0][1]*
          Wpk[10][11][0])+(Cik[12][1][1]*Wpk[10][11][1])));
        Wpk[10][12][2] = ((Cik[12][2][2]*Wpk[10][11][2])+((Cik[12][0][2]*
          Wpk[10][11][0])+(Cik[12][1][2]*Wpk[10][11][1])));
        Wpk[10][13][0] = ((Cik[13][2][0]*Wpk[10][12][2])+((Cik[13][0][0]*
          Wpk[10][12][0])+(Cik[13][1][0]*Wpk[10][12][1])));
        Wpk[10][13][1] = ((Cik[13][2][1]*Wpk[10][12][2])+((Cik[13][0][1]*
          Wpk[10][12][0])+(Cik[13][1][1]*Wpk[10][12][1])));
        Wpk[10][13][2] = ((Cik[13][2][2]*Wpk[10][12][2])+((Cik[13][0][2]*
          Wpk[10][12][0])+(Cik[13][1][2]*Wpk[10][12][1])));
        Wpk[11][11][0] = pin[11][0];
        Wpk[11][11][1] = pin[11][1];
        Wpk[11][11][2] = pin[11][2];
        Wpk[11][12][0] = ((Cik[12][2][0]*pin[11][2])+((Cik[12][0][0]*pin[11][0])
          +(Cik[12][1][0]*pin[11][1])));
        Wpk[11][12][1] = ((Cik[12][2][1]*pin[11][2])+((Cik[12][0][1]*pin[11][0])
          +(Cik[12][1][1]*pin[11][1])));
        Wpk[11][12][2] = ((Cik[12][2][2]*pin[11][2])+((Cik[12][0][2]*pin[11][0])
          +(Cik[12][1][2]*pin[11][1])));
        Wpk[11][13][0] = ((Cik[13][2][0]*Wpk[11][12][2])+((Cik[13][0][0]*
          Wpk[11][12][0])+(Cik[13][1][0]*Wpk[11][12][1])));
        Wpk[11][13][1] = ((Cik[13][2][1]*Wpk[11][12][2])+((Cik[13][0][1]*
          Wpk[11][12][0])+(Cik[13][1][1]*Wpk[11][12][1])));
        Wpk[11][13][2] = ((Cik[13][2][2]*Wpk[11][12][2])+((Cik[13][0][2]*
          Wpk[11][12][0])+(Cik[13][1][2]*Wpk[11][12][1])));
        Wpk[12][12][0] = pin[12][0];
        Wpk[12][12][1] = pin[12][1];
        Wpk[12][12][2] = pin[12][2];
        Wpk[12][13][0] = ((Cik[13][2][0]*pin[12][2])+((Cik[13][0][0]*pin[12][0])
          +(Cik[13][1][0]*pin[12][1])));
        Wpk[12][13][1] = ((Cik[13][2][1]*pin[12][2])+((Cik[13][0][1]*pin[12][0])
          +(Cik[13][1][1]*pin[12][1])));
        Wpk[12][13][2] = ((Cik[13][2][2]*pin[12][2])+((Cik[13][0][2]*pin[12][0])
          +(Cik[13][1][2]*pin[12][1])));
        Wpk[13][13][0] = pin[13][0];
        Wpk[13][13][1] = pin[13][1];
        Wpk[13][13][2] = pin[13][2];
        Wpk[14][14][0] = pin[14][0];
        Wpk[14][14][1] = pin[14][1];
        Wpk[14][14][2] = pin[14][2];
        Wpk[14][15][0] = ((Cik[15][2][0]*pin[14][2])+((Cik[15][0][0]*pin[14][0])
          +(Cik[15][1][0]*pin[14][1])));
        Wpk[14][15][1] = ((Cik[15][2][1]*pin[14][2])+((Cik[15][0][1]*pin[14][0])
          +(Cik[15][1][1]*pin[14][1])));
        Wpk[14][15][2] = ((Cik[15][2][2]*pin[14][2])+((Cik[15][0][2]*pin[14][0])
          +(Cik[15][1][2]*pin[14][1])));
        Wpk[14][16][0] = ((Cik[16][2][0]*Wpk[14][15][2])+((Cik[16][0][0]*
          Wpk[14][15][0])+(Cik[16][1][0]*Wpk[14][15][1])));
        Wpk[14][16][1] = ((Cik[16][2][1]*Wpk[14][15][2])+((Cik[16][0][1]*
          Wpk[14][15][0])+(Cik[16][1][1]*Wpk[14][15][1])));
        Wpk[14][16][2] = ((Cik[16][2][2]*Wpk[14][15][2])+((Cik[16][0][2]*
          Wpk[14][15][0])+(Cik[16][1][2]*Wpk[14][15][1])));
        Wpk[14][17][0] = ((Cik[17][2][0]*Wpk[14][16][2])+((Cik[17][0][0]*
          Wpk[14][16][0])+(Cik[17][1][0]*Wpk[14][16][1])));
        Wpk[14][17][1] = ((Cik[17][2][1]*Wpk[14][16][2])+((Cik[17][0][1]*
          Wpk[14][16][0])+(Cik[17][1][1]*Wpk[14][16][1])));
        Wpk[14][17][2] = ((Cik[17][2][2]*Wpk[14][16][2])+((Cik[17][0][2]*
          Wpk[14][16][0])+(Cik[17][1][2]*Wpk[14][16][1])));
        Wpk[15][15][0] = pin[15][0];
        Wpk[15][15][1] = pin[15][1];
        Wpk[15][15][2] = pin[15][2];
        Wpk[15][16][0] = ((Cik[16][2][0]*pin[15][2])+((Cik[16][0][0]*pin[15][0])
          +(Cik[16][1][0]*pin[15][1])));
        Wpk[15][16][1] = ((Cik[16][2][1]*pin[15][2])+((Cik[16][0][1]*pin[15][0])
          +(Cik[16][1][1]*pin[15][1])));
        Wpk[15][16][2] = ((Cik[16][2][2]*pin[15][2])+((Cik[16][0][2]*pin[15][0])
          +(Cik[16][1][2]*pin[15][1])));
        Wpk[15][17][0] = ((Cik[17][2][0]*Wpk[15][16][2])+((Cik[17][0][0]*
          Wpk[15][16][0])+(Cik[17][1][0]*Wpk[15][16][1])));
        Wpk[15][17][1] = ((Cik[17][2][1]*Wpk[15][16][2])+((Cik[17][0][1]*
          Wpk[15][16][0])+(Cik[17][1][1]*Wpk[15][16][1])));
        Wpk[15][17][2] = ((Cik[17][2][2]*Wpk[15][16][2])+((Cik[17][0][2]*
          Wpk[15][16][0])+(Cik[17][1][2]*Wpk[15][16][1])));
        Wpk[16][16][0] = pin[16][0];
        Wpk[16][16][1] = pin[16][1];
        Wpk[16][16][2] = pin[16][2];
        Wpk[16][17][0] = ((Cik[17][2][0]*pin[16][2])+((Cik[17][0][0]*pin[16][0])
          +(Cik[17][1][0]*pin[16][1])));
        Wpk[16][17][1] = ((Cik[17][2][1]*pin[16][2])+((Cik[17][0][1]*pin[16][0])
          +(Cik[17][1][1]*pin[16][1])));
        Wpk[16][17][2] = ((Cik[17][2][2]*pin[16][2])+((Cik[17][0][2]*pin[16][0])
          +(Cik[17][1][2]*pin[16][1])));
        Wpk[17][17][0] = pin[17][0];
        Wpk[17][17][1] = pin[17][1];
        Wpk[17][17][2] = pin[17][2];
        Wpk[18][18][0] = pin[18][0];
        Wpk[18][18][1] = pin[18][1];
        Wpk[18][18][2] = pin[18][2];
        Wpk[18][19][0] = ((Cik[19][2][0]*pin[18][2])+((Cik[19][0][0]*pin[18][0])
          +(Cik[19][1][0]*pin[18][1])));
        Wpk[18][19][1] = ((Cik[19][2][1]*pin[18][2])+((Cik[19][0][1]*pin[18][0])
          +(Cik[19][1][1]*pin[18][1])));
        Wpk[18][19][2] = ((Cik[19][2][2]*pin[18][2])+((Cik[19][0][2]*pin[18][0])
          +(Cik[19][1][2]*pin[18][1])));
        Wpk[18][20][0] = ((Cik[20][2][0]*Wpk[18][19][2])+((Cik[20][0][0]*
          Wpk[18][19][0])+(Cik[20][1][0]*Wpk[18][19][1])));
        Wpk[18][20][1] = ((Cik[20][2][1]*Wpk[18][19][2])+((Cik[20][0][1]*
          Wpk[18][19][0])+(Cik[20][1][1]*Wpk[18][19][1])));
        Wpk[18][20][2] = ((Cik[20][2][2]*Wpk[18][19][2])+((Cik[20][0][2]*
          Wpk[18][19][0])+(Cik[20][1][2]*Wpk[18][19][1])));
        Wpk[18][21][0] = ((Cik[21][2][0]*Wpk[18][20][2])+((Cik[21][0][0]*
          Wpk[18][20][0])+(Cik[21][1][0]*Wpk[18][20][1])));
        Wpk[18][21][1] = ((Cik[21][2][1]*Wpk[18][20][2])+((Cik[21][0][1]*
          Wpk[18][20][0])+(Cik[21][1][1]*Wpk[18][20][1])));
        Wpk[18][21][2] = ((Cik[21][2][2]*Wpk[18][20][2])+((Cik[21][0][2]*
          Wpk[18][20][0])+(Cik[21][1][2]*Wpk[18][20][1])));
        Wpk[19][19][0] = pin[19][0];
        Wpk[19][19][1] = pin[19][1];
        Wpk[19][19][2] = pin[19][2];
        Wpk[19][20][0] = ((Cik[20][2][0]*pin[19][2])+((Cik[20][0][0]*pin[19][0])
          +(Cik[20][1][0]*pin[19][1])));
        Wpk[19][20][1] = ((Cik[20][2][1]*pin[19][2])+((Cik[20][0][1]*pin[19][0])
          +(Cik[20][1][1]*pin[19][1])));
        Wpk[19][20][2] = ((Cik[20][2][2]*pin[19][2])+((Cik[20][0][2]*pin[19][0])
          +(Cik[20][1][2]*pin[19][1])));
        Wpk[19][21][0] = ((Cik[21][2][0]*Wpk[19][20][2])+((Cik[21][0][0]*
          Wpk[19][20][0])+(Cik[21][1][0]*Wpk[19][20][1])));
        Wpk[19][21][1] = ((Cik[21][2][1]*Wpk[19][20][2])+((Cik[21][0][1]*
          Wpk[19][20][0])+(Cik[21][1][1]*Wpk[19][20][1])));
        Wpk[19][21][2] = ((Cik[21][2][2]*Wpk[19][20][2])+((Cik[21][0][2]*
          Wpk[19][20][0])+(Cik[21][1][2]*Wpk[19][20][1])));
        Wpk[20][20][0] = pin[20][0];
        Wpk[20][20][1] = pin[20][1];
        Wpk[20][20][2] = pin[20][2];
        Wpk[20][21][0] = ((Cik[21][2][0]*pin[20][2])+((Cik[21][0][0]*pin[20][0])
          +(Cik[21][1][0]*pin[20][1])));
        Wpk[20][21][1] = ((Cik[21][2][1]*pin[20][2])+((Cik[21][0][1]*pin[20][0])
          +(Cik[21][1][1]*pin[20][1])));
        Wpk[20][21][2] = ((Cik[21][2][2]*pin[20][2])+((Cik[21][0][2]*pin[20][0])
          +(Cik[21][1][2]*pin[20][1])));
        Wpk[21][21][0] = pin[21][0];
        Wpk[21][21][1] = pin[21][1];
        Wpk[21][21][2] = pin[21][2];
/*
Compute Vpk (partial velocities)
*/
        Vpk[0][0][0] = pin[0][0];
        Vpk[0][0][1] = pin[0][1];
        Vpk[0][0][2] = pin[0][2];
        Vpk[0][1][0] = pin[0][0];
        Vpk[0][1][1] = pin[0][1];
        Vpk[0][1][2] = pin[0][2];
        Vpk[0][2][0] = pin[0][0];
        Vpk[0][2][1] = pin[0][1];
        Vpk[0][2][2] = pin[0][2];
        Vpk[0][3][0] = ((Cik[3][2][0]*pin[0][2])+((Cik[3][0][0]*pin[0][0])+(
          Cik[3][1][0]*pin[0][1])));
        Vpk[0][3][1] = ((Cik[3][2][1]*pin[0][2])+((Cik[3][0][1]*pin[0][0])+(
          Cik[3][1][1]*pin[0][1])));
        Vpk[0][3][2] = ((Cik[3][2][2]*pin[0][2])+((Cik[3][0][2]*pin[0][0])+(
          Cik[3][1][2]*pin[0][1])));
        Vpk[0][4][0] = Vpk[0][3][0];
        Vpk[0][4][1] = Vpk[0][3][1];
        Vpk[0][4][2] = Vpk[0][3][2];
        Vpk[0][5][0] = Vpk[0][3][0];
        Vpk[0][5][1] = Vpk[0][3][1];
        Vpk[0][5][2] = Vpk[0][3][2];
        Vpk[0][6][0] = ((Cik[6][2][0]*Vpk[0][3][2])+((Cik[6][0][0]*Vpk[0][3][0])
          +(Cik[6][1][0]*Vpk[0][3][1])));
        Vpk[0][6][1] = ((Cik[6][2][1]*Vpk[0][3][2])+((Cik[6][0][1]*Vpk[0][3][0])
          +(Cik[6][1][1]*Vpk[0][3][1])));
        Vpk[0][6][2] = ((Cik[6][2][2]*Vpk[0][3][2])+((Cik[6][0][2]*Vpk[0][3][0])
          +(Cik[6][1][2]*Vpk[0][3][1])));
        Vpk[0][7][0] = ((Cik[7][2][0]*Vpk[0][6][2])+((Cik[7][0][0]*Vpk[0][6][0])
          +(Cik[7][1][0]*Vpk[0][6][1])));
        Vpk[0][7][1] = ((Cik[7][2][1]*Vpk[0][6][2])+((Cik[7][0][1]*Vpk[0][6][0])
          +(Cik[7][1][1]*Vpk[0][6][1])));
        Vpk[0][7][2] = ((Cik[7][2][2]*Vpk[0][6][2])+((Cik[7][0][2]*Vpk[0][6][0])
          +(Cik[7][1][2]*Vpk[0][6][1])));
        Vpk[0][8][0] = ((Cik[8][2][0]*Vpk[0][7][2])+((Cik[8][0][0]*Vpk[0][7][0])
          +(Cik[8][1][0]*Vpk[0][7][1])));
        Vpk[0][8][1] = ((Cik[8][2][1]*Vpk[0][7][2])+((Cik[8][0][1]*Vpk[0][7][0])
          +(Cik[8][1][1]*Vpk[0][7][1])));
        Vpk[0][8][2] = ((Cik[8][2][2]*Vpk[0][7][2])+((Cik[8][0][2]*Vpk[0][7][0])
          +(Cik[8][1][2]*Vpk[0][7][1])));
        Vpk[0][9][0] = ((Cik[9][2][0]*Vpk[0][8][2])+((Cik[9][0][0]*Vpk[0][8][0])
          +(Cik[9][1][0]*Vpk[0][8][1])));
        Vpk[0][9][1] = ((Cik[9][2][1]*Vpk[0][8][2])+((Cik[9][0][1]*Vpk[0][8][0])
          +(Cik[9][1][1]*Vpk[0][8][1])));
        Vpk[0][9][2] = ((Cik[9][2][2]*Vpk[0][8][2])+((Cik[9][0][2]*Vpk[0][8][0])
          +(Cik[9][1][2]*Vpk[0][8][1])));
        Vpk[0][10][0] = ((Cik[10][2][0]*Vpk[0][3][2])+((Cik[10][0][0]*
          Vpk[0][3][0])+(Cik[10][1][0]*Vpk[0][3][1])));
        Vpk[0][10][1] = ((Cik[10][2][1]*Vpk[0][3][2])+((Cik[10][0][1]*
          Vpk[0][3][0])+(Cik[10][1][1]*Vpk[0][3][1])));
        Vpk[0][10][2] = ((Cik[10][2][2]*Vpk[0][3][2])+((Cik[10][0][2]*
          Vpk[0][3][0])+(Cik[10][1][2]*Vpk[0][3][1])));
        Vpk[0][11][0] = ((Cik[11][2][0]*Vpk[0][10][2])+((Cik[11][0][0]*
          Vpk[0][10][0])+(Cik[11][1][0]*Vpk[0][10][1])));
        Vpk[0][11][1] = ((Cik[11][2][1]*Vpk[0][10][2])+((Cik[11][0][1]*
          Vpk[0][10][0])+(Cik[11][1][1]*Vpk[0][10][1])));
        Vpk[0][11][2] = ((Cik[11][2][2]*Vpk[0][10][2])+((Cik[11][0][2]*
          Vpk[0][10][0])+(Cik[11][1][2]*Vpk[0][10][1])));
        Vpk[0][12][0] = ((Cik[12][2][0]*Vpk[0][11][2])+((Cik[12][0][0]*
          Vpk[0][11][0])+(Cik[12][1][0]*Vpk[0][11][1])));
        Vpk[0][12][1] = ((Cik[12][2][1]*Vpk[0][11][2])+((Cik[12][0][1]*
          Vpk[0][11][0])+(Cik[12][1][1]*Vpk[0][11][1])));
        Vpk[0][12][2] = ((Cik[12][2][2]*Vpk[0][11][2])+((Cik[12][0][2]*
          Vpk[0][11][0])+(Cik[12][1][2]*Vpk[0][11][1])));
        Vpk[0][13][0] = ((Cik[13][2][0]*Vpk[0][12][2])+((Cik[13][0][0]*
          Vpk[0][12][0])+(Cik[13][1][0]*Vpk[0][12][1])));
        Vpk[0][13][1] = ((Cik[13][2][1]*Vpk[0][12][2])+((Cik[13][0][1]*
          Vpk[0][12][0])+(Cik[13][1][1]*Vpk[0][12][1])));
        Vpk[0][13][2] = ((Cik[13][2][2]*Vpk[0][12][2])+((Cik[13][0][2]*
          Vpk[0][12][0])+(Cik[13][1][2]*Vpk[0][12][1])));
        Vpk[0][14][0] = ((Cik[14][2][0]*Vpk[0][3][2])+((Cik[14][0][0]*
          Vpk[0][3][0])+(Cik[14][1][0]*Vpk[0][3][1])));
        Vpk[0][14][1] = ((Cik[14][2][1]*Vpk[0][3][2])+((Cik[14][0][1]*
          Vpk[0][3][0])+(Cik[14][1][1]*Vpk[0][3][1])));
        Vpk[0][14][2] = ((Cik[14][2][2]*Vpk[0][3][2])+((Cik[14][0][2]*
          Vpk[0][3][0])+(Cik[14][1][2]*Vpk[0][3][1])));
        Vpk[0][15][0] = ((Cik[15][2][0]*Vpk[0][14][2])+((Cik[15][0][0]*
          Vpk[0][14][0])+(Cik[15][1][0]*Vpk[0][14][1])));
        Vpk[0][15][1] = ((Cik[15][2][1]*Vpk[0][14][2])+((Cik[15][0][1]*
          Vpk[0][14][0])+(Cik[15][1][1]*Vpk[0][14][1])));
        Vpk[0][15][2] = ((Cik[15][2][2]*Vpk[0][14][2])+((Cik[15][0][2]*
          Vpk[0][14][0])+(Cik[15][1][2]*Vpk[0][14][1])));
        Vpk[0][16][0] = ((Cik[16][2][0]*Vpk[0][15][2])+((Cik[16][0][0]*
          Vpk[0][15][0])+(Cik[16][1][0]*Vpk[0][15][1])));
        Vpk[0][16][1] = ((Cik[16][2][1]*Vpk[0][15][2])+((Cik[16][0][1]*
          Vpk[0][15][0])+(Cik[16][1][1]*Vpk[0][15][1])));
        Vpk[0][16][2] = ((Cik[16][2][2]*Vpk[0][15][2])+((Cik[16][0][2]*
          Vpk[0][15][0])+(Cik[16][1][2]*Vpk[0][15][1])));
        Vpk[0][17][0] = ((Cik[17][2][0]*Vpk[0][16][2])+((Cik[17][0][0]*
          Vpk[0][16][0])+(Cik[17][1][0]*Vpk[0][16][1])));
        Vpk[0][17][1] = ((Cik[17][2][1]*Vpk[0][16][2])+((Cik[17][0][1]*
          Vpk[0][16][0])+(Cik[17][1][1]*Vpk[0][16][1])));
        Vpk[0][17][2] = ((Cik[17][2][2]*Vpk[0][16][2])+((Cik[17][0][2]*
          Vpk[0][16][0])+(Cik[17][1][2]*Vpk[0][16][1])));
        Vpk[0][18][0] = ((Cik[18][2][0]*Vpk[0][3][2])+((Cik[18][0][0]*
          Vpk[0][3][0])+(Cik[18][1][0]*Vpk[0][3][1])));
        Vpk[0][18][1] = ((Cik[18][2][1]*Vpk[0][3][2])+((Cik[18][0][1]*
          Vpk[0][3][0])+(Cik[18][1][1]*Vpk[0][3][1])));
        Vpk[0][18][2] = ((Cik[18][2][2]*Vpk[0][3][2])+((Cik[18][0][2]*
          Vpk[0][3][0])+(Cik[18][1][2]*Vpk[0][3][1])));
        Vpk[0][19][0] = ((Cik[19][2][0]*Vpk[0][18][2])+((Cik[19][0][0]*
          Vpk[0][18][0])+(Cik[19][1][0]*Vpk[0][18][1])));
        Vpk[0][19][1] = ((Cik[19][2][1]*Vpk[0][18][2])+((Cik[19][0][1]*
          Vpk[0][18][0])+(Cik[19][1][1]*Vpk[0][18][1])));
        Vpk[0][19][2] = ((Cik[19][2][2]*Vpk[0][18][2])+((Cik[19][0][2]*
          Vpk[0][18][0])+(Cik[19][1][2]*Vpk[0][18][1])));
        Vpk[0][20][0] = ((Cik[20][2][0]*Vpk[0][19][2])+((Cik[20][0][0]*
          Vpk[0][19][0])+(Cik[20][1][0]*Vpk[0][19][1])));
        Vpk[0][20][1] = ((Cik[20][2][1]*Vpk[0][19][2])+((Cik[20][0][1]*
          Vpk[0][19][0])+(Cik[20][1][1]*Vpk[0][19][1])));
        Vpk[0][20][2] = ((Cik[20][2][2]*Vpk[0][19][2])+((Cik[20][0][2]*
          Vpk[0][19][0])+(Cik[20][1][2]*Vpk[0][19][1])));
        Vpk[0][21][0] = ((Cik[21][2][0]*Vpk[0][20][2])+((Cik[21][0][0]*
          Vpk[0][20][0])+(Cik[21][1][0]*Vpk[0][20][1])));
        Vpk[0][21][1] = ((Cik[21][2][1]*Vpk[0][20][2])+((Cik[21][0][1]*
          Vpk[0][20][0])+(Cik[21][1][1]*Vpk[0][20][1])));
        Vpk[0][21][2] = ((Cik[21][2][2]*Vpk[0][20][2])+((Cik[21][0][2]*
          Vpk[0][20][0])+(Cik[21][1][2]*Vpk[0][20][1])));
        Vpk[1][1][0] = pin[1][0];
        Vpk[1][1][1] = pin[1][1];
        Vpk[1][1][2] = pin[1][2];
        Vpk[1][2][0] = pin[1][0];
        Vpk[1][2][1] = pin[1][1];
        Vpk[1][2][2] = pin[1][2];
        Vpk[1][3][0] = ((Cik[3][2][0]*pin[1][2])+((Cik[3][0][0]*pin[1][0])+(
          Cik[3][1][0]*pin[1][1])));
        Vpk[1][3][1] = ((Cik[3][2][1]*pin[1][2])+((Cik[3][0][1]*pin[1][0])+(
          Cik[3][1][1]*pin[1][1])));
        Vpk[1][3][2] = ((Cik[3][2][2]*pin[1][2])+((Cik[3][0][2]*pin[1][0])+(
          Cik[3][1][2]*pin[1][1])));
        Vpk[1][4][0] = Vpk[1][3][0];
        Vpk[1][4][1] = Vpk[1][3][1];
        Vpk[1][4][2] = Vpk[1][3][2];
        Vpk[1][5][0] = Vpk[1][3][0];
        Vpk[1][5][1] = Vpk[1][3][1];
        Vpk[1][5][2] = Vpk[1][3][2];
        Vpk[1][6][0] = ((Cik[6][2][0]*Vpk[1][3][2])+((Cik[6][0][0]*Vpk[1][3][0])
          +(Cik[6][1][0]*Vpk[1][3][1])));
        Vpk[1][6][1] = ((Cik[6][2][1]*Vpk[1][3][2])+((Cik[6][0][1]*Vpk[1][3][0])
          +(Cik[6][1][1]*Vpk[1][3][1])));
        Vpk[1][6][2] = ((Cik[6][2][2]*Vpk[1][3][2])+((Cik[6][0][2]*Vpk[1][3][0])
          +(Cik[6][1][2]*Vpk[1][3][1])));
        Vpk[1][7][0] = ((Cik[7][2][0]*Vpk[1][6][2])+((Cik[7][0][0]*Vpk[1][6][0])
          +(Cik[7][1][0]*Vpk[1][6][1])));
        Vpk[1][7][1] = ((Cik[7][2][1]*Vpk[1][6][2])+((Cik[7][0][1]*Vpk[1][6][0])
          +(Cik[7][1][1]*Vpk[1][6][1])));
        Vpk[1][7][2] = ((Cik[7][2][2]*Vpk[1][6][2])+((Cik[7][0][2]*Vpk[1][6][0])
          +(Cik[7][1][2]*Vpk[1][6][1])));
        Vpk[1][8][0] = ((Cik[8][2][0]*Vpk[1][7][2])+((Cik[8][0][0]*Vpk[1][7][0])
          +(Cik[8][1][0]*Vpk[1][7][1])));
        Vpk[1][8][1] = ((Cik[8][2][1]*Vpk[1][7][2])+((Cik[8][0][1]*Vpk[1][7][0])
          +(Cik[8][1][1]*Vpk[1][7][1])));
        Vpk[1][8][2] = ((Cik[8][2][2]*Vpk[1][7][2])+((Cik[8][0][2]*Vpk[1][7][0])
          +(Cik[8][1][2]*Vpk[1][7][1])));
        Vpk[1][9][0] = ((Cik[9][2][0]*Vpk[1][8][2])+((Cik[9][0][0]*Vpk[1][8][0])
          +(Cik[9][1][0]*Vpk[1][8][1])));
        Vpk[1][9][1] = ((Cik[9][2][1]*Vpk[1][8][2])+((Cik[9][0][1]*Vpk[1][8][0])
          +(Cik[9][1][1]*Vpk[1][8][1])));
        Vpk[1][9][2] = ((Cik[9][2][2]*Vpk[1][8][2])+((Cik[9][0][2]*Vpk[1][8][0])
          +(Cik[9][1][2]*Vpk[1][8][1])));
        Vpk[1][10][0] = ((Cik[10][2][0]*Vpk[1][3][2])+((Cik[10][0][0]*
          Vpk[1][3][0])+(Cik[10][1][0]*Vpk[1][3][1])));
        Vpk[1][10][1] = ((Cik[10][2][1]*Vpk[1][3][2])+((Cik[10][0][1]*
          Vpk[1][3][0])+(Cik[10][1][1]*Vpk[1][3][1])));
        Vpk[1][10][2] = ((Cik[10][2][2]*Vpk[1][3][2])+((Cik[10][0][2]*
          Vpk[1][3][0])+(Cik[10][1][2]*Vpk[1][3][1])));
        Vpk[1][11][0] = ((Cik[11][2][0]*Vpk[1][10][2])+((Cik[11][0][0]*
          Vpk[1][10][0])+(Cik[11][1][0]*Vpk[1][10][1])));
        Vpk[1][11][1] = ((Cik[11][2][1]*Vpk[1][10][2])+((Cik[11][0][1]*
          Vpk[1][10][0])+(Cik[11][1][1]*Vpk[1][10][1])));
        Vpk[1][11][2] = ((Cik[11][2][2]*Vpk[1][10][2])+((Cik[11][0][2]*
          Vpk[1][10][0])+(Cik[11][1][2]*Vpk[1][10][1])));
        Vpk[1][12][0] = ((Cik[12][2][0]*Vpk[1][11][2])+((Cik[12][0][0]*
          Vpk[1][11][0])+(Cik[12][1][0]*Vpk[1][11][1])));
        Vpk[1][12][1] = ((Cik[12][2][1]*Vpk[1][11][2])+((Cik[12][0][1]*
          Vpk[1][11][0])+(Cik[12][1][1]*Vpk[1][11][1])));
        Vpk[1][12][2] = ((Cik[12][2][2]*Vpk[1][11][2])+((Cik[12][0][2]*
          Vpk[1][11][0])+(Cik[12][1][2]*Vpk[1][11][1])));
        Vpk[1][13][0] = ((Cik[13][2][0]*Vpk[1][12][2])+((Cik[13][0][0]*
          Vpk[1][12][0])+(Cik[13][1][0]*Vpk[1][12][1])));
        Vpk[1][13][1] = ((Cik[13][2][1]*Vpk[1][12][2])+((Cik[13][0][1]*
          Vpk[1][12][0])+(Cik[13][1][1]*Vpk[1][12][1])));
        Vpk[1][13][2] = ((Cik[13][2][2]*Vpk[1][12][2])+((Cik[13][0][2]*
          Vpk[1][12][0])+(Cik[13][1][2]*Vpk[1][12][1])));
        Vpk[1][14][0] = ((Cik[14][2][0]*Vpk[1][3][2])+((Cik[14][0][0]*
          Vpk[1][3][0])+(Cik[14][1][0]*Vpk[1][3][1])));
        Vpk[1][14][1] = ((Cik[14][2][1]*Vpk[1][3][2])+((Cik[14][0][1]*
          Vpk[1][3][0])+(Cik[14][1][1]*Vpk[1][3][1])));
        Vpk[1][14][2] = ((Cik[14][2][2]*Vpk[1][3][2])+((Cik[14][0][2]*
          Vpk[1][3][0])+(Cik[14][1][2]*Vpk[1][3][1])));
        Vpk[1][15][0] = ((Cik[15][2][0]*Vpk[1][14][2])+((Cik[15][0][0]*
          Vpk[1][14][0])+(Cik[15][1][0]*Vpk[1][14][1])));
        Vpk[1][15][1] = ((Cik[15][2][1]*Vpk[1][14][2])+((Cik[15][0][1]*
          Vpk[1][14][0])+(Cik[15][1][1]*Vpk[1][14][1])));
        Vpk[1][15][2] = ((Cik[15][2][2]*Vpk[1][14][2])+((Cik[15][0][2]*
          Vpk[1][14][0])+(Cik[15][1][2]*Vpk[1][14][1])));
        Vpk[1][16][0] = ((Cik[16][2][0]*Vpk[1][15][2])+((Cik[16][0][0]*
          Vpk[1][15][0])+(Cik[16][1][0]*Vpk[1][15][1])));
        Vpk[1][16][1] = ((Cik[16][2][1]*Vpk[1][15][2])+((Cik[16][0][1]*
          Vpk[1][15][0])+(Cik[16][1][1]*Vpk[1][15][1])));
        Vpk[1][16][2] = ((Cik[16][2][2]*Vpk[1][15][2])+((Cik[16][0][2]*
          Vpk[1][15][0])+(Cik[16][1][2]*Vpk[1][15][1])));
        Vpk[1][17][0] = ((Cik[17][2][0]*Vpk[1][16][2])+((Cik[17][0][0]*
          Vpk[1][16][0])+(Cik[17][1][0]*Vpk[1][16][1])));
        Vpk[1][17][1] = ((Cik[17][2][1]*Vpk[1][16][2])+((Cik[17][0][1]*
          Vpk[1][16][0])+(Cik[17][1][1]*Vpk[1][16][1])));
        Vpk[1][17][2] = ((Cik[17][2][2]*Vpk[1][16][2])+((Cik[17][0][2]*
          Vpk[1][16][0])+(Cik[17][1][2]*Vpk[1][16][1])));
        Vpk[1][18][0] = ((Cik[18][2][0]*Vpk[1][3][2])+((Cik[18][0][0]*
          Vpk[1][3][0])+(Cik[18][1][0]*Vpk[1][3][1])));
        Vpk[1][18][1] = ((Cik[18][2][1]*Vpk[1][3][2])+((Cik[18][0][1]*
          Vpk[1][3][0])+(Cik[18][1][1]*Vpk[1][3][1])));
        Vpk[1][18][2] = ((Cik[18][2][2]*Vpk[1][3][2])+((Cik[18][0][2]*
          Vpk[1][3][0])+(Cik[18][1][2]*Vpk[1][3][1])));
        Vpk[1][19][0] = ((Cik[19][2][0]*Vpk[1][18][2])+((Cik[19][0][0]*
          Vpk[1][18][0])+(Cik[19][1][0]*Vpk[1][18][1])));
        Vpk[1][19][1] = ((Cik[19][2][1]*Vpk[1][18][2])+((Cik[19][0][1]*
          Vpk[1][18][0])+(Cik[19][1][1]*Vpk[1][18][1])));
        Vpk[1][19][2] = ((Cik[19][2][2]*Vpk[1][18][2])+((Cik[19][0][2]*
          Vpk[1][18][0])+(Cik[19][1][2]*Vpk[1][18][1])));
        Vpk[1][20][0] = ((Cik[20][2][0]*Vpk[1][19][2])+((Cik[20][0][0]*
          Vpk[1][19][0])+(Cik[20][1][0]*Vpk[1][19][1])));
        Vpk[1][20][1] = ((Cik[20][2][1]*Vpk[1][19][2])+((Cik[20][0][1]*
          Vpk[1][19][0])+(Cik[20][1][1]*Vpk[1][19][1])));
        Vpk[1][20][2] = ((Cik[20][2][2]*Vpk[1][19][2])+((Cik[20][0][2]*
          Vpk[1][19][0])+(Cik[20][1][2]*Vpk[1][19][1])));
        Vpk[1][21][0] = ((Cik[21][2][0]*Vpk[1][20][2])+((Cik[21][0][0]*
          Vpk[1][20][0])+(Cik[21][1][0]*Vpk[1][20][1])));
        Vpk[1][21][1] = ((Cik[21][2][1]*Vpk[1][20][2])+((Cik[21][0][1]*
          Vpk[1][20][0])+(Cik[21][1][1]*Vpk[1][20][1])));
        Vpk[1][21][2] = ((Cik[21][2][2]*Vpk[1][20][2])+((Cik[21][0][2]*
          Vpk[1][20][0])+(Cik[21][1][2]*Vpk[1][20][1])));
        Vpk[2][2][0] = pin[2][0];
        Vpk[2][2][1] = pin[2][1];
        Vpk[2][2][2] = pin[2][2];
        Vpk[2][3][0] = ((Cik[3][2][0]*pin[2][2])+((Cik[3][0][0]*pin[2][0])+(
          Cik[3][1][0]*pin[2][1])));
        Vpk[2][3][1] = ((Cik[3][2][1]*pin[2][2])+((Cik[3][0][1]*pin[2][0])+(
          Cik[3][1][1]*pin[2][1])));
        Vpk[2][3][2] = ((Cik[3][2][2]*pin[2][2])+((Cik[3][0][2]*pin[2][0])+(
          Cik[3][1][2]*pin[2][1])));
        Vpk[2][4][0] = Vpk[2][3][0];
        Vpk[2][4][1] = Vpk[2][3][1];
        Vpk[2][4][2] = Vpk[2][3][2];
        Vpk[2][5][0] = Vpk[2][3][0];
        Vpk[2][5][1] = Vpk[2][3][1];
        Vpk[2][5][2] = Vpk[2][3][2];
        Vpk[2][6][0] = ((Cik[6][2][0]*Vpk[2][3][2])+((Cik[6][0][0]*Vpk[2][3][0])
          +(Cik[6][1][0]*Vpk[2][3][1])));
        Vpk[2][6][1] = ((Cik[6][2][1]*Vpk[2][3][2])+((Cik[6][0][1]*Vpk[2][3][0])
          +(Cik[6][1][1]*Vpk[2][3][1])));
        Vpk[2][6][2] = ((Cik[6][2][2]*Vpk[2][3][2])+((Cik[6][0][2]*Vpk[2][3][0])
          +(Cik[6][1][2]*Vpk[2][3][1])));
        Vpk[2][7][0] = ((Cik[7][2][0]*Vpk[2][6][2])+((Cik[7][0][0]*Vpk[2][6][0])
          +(Cik[7][1][0]*Vpk[2][6][1])));
        Vpk[2][7][1] = ((Cik[7][2][1]*Vpk[2][6][2])+((Cik[7][0][1]*Vpk[2][6][0])
          +(Cik[7][1][1]*Vpk[2][6][1])));
        Vpk[2][7][2] = ((Cik[7][2][2]*Vpk[2][6][2])+((Cik[7][0][2]*Vpk[2][6][0])
          +(Cik[7][1][2]*Vpk[2][6][1])));
        Vpk[2][8][0] = ((Cik[8][2][0]*Vpk[2][7][2])+((Cik[8][0][0]*Vpk[2][7][0])
          +(Cik[8][1][0]*Vpk[2][7][1])));
        Vpk[2][8][1] = ((Cik[8][2][1]*Vpk[2][7][2])+((Cik[8][0][1]*Vpk[2][7][0])
          +(Cik[8][1][1]*Vpk[2][7][1])));
        Vpk[2][8][2] = ((Cik[8][2][2]*Vpk[2][7][2])+((Cik[8][0][2]*Vpk[2][7][0])
          +(Cik[8][1][2]*Vpk[2][7][1])));
        Vpk[2][9][0] = ((Cik[9][2][0]*Vpk[2][8][2])+((Cik[9][0][0]*Vpk[2][8][0])
          +(Cik[9][1][0]*Vpk[2][8][1])));
        Vpk[2][9][1] = ((Cik[9][2][1]*Vpk[2][8][2])+((Cik[9][0][1]*Vpk[2][8][0])
          +(Cik[9][1][1]*Vpk[2][8][1])));
        Vpk[2][9][2] = ((Cik[9][2][2]*Vpk[2][8][2])+((Cik[9][0][2]*Vpk[2][8][0])
          +(Cik[9][1][2]*Vpk[2][8][1])));
        Vpk[2][10][0] = ((Cik[10][2][0]*Vpk[2][3][2])+((Cik[10][0][0]*
          Vpk[2][3][0])+(Cik[10][1][0]*Vpk[2][3][1])));
        Vpk[2][10][1] = ((Cik[10][2][1]*Vpk[2][3][2])+((Cik[10][0][1]*
          Vpk[2][3][0])+(Cik[10][1][1]*Vpk[2][3][1])));
        Vpk[2][10][2] = ((Cik[10][2][2]*Vpk[2][3][2])+((Cik[10][0][2]*
          Vpk[2][3][0])+(Cik[10][1][2]*Vpk[2][3][1])));
        Vpk[2][11][0] = ((Cik[11][2][0]*Vpk[2][10][2])+((Cik[11][0][0]*
          Vpk[2][10][0])+(Cik[11][1][0]*Vpk[2][10][1])));
        Vpk[2][11][1] = ((Cik[11][2][1]*Vpk[2][10][2])+((Cik[11][0][1]*
          Vpk[2][10][0])+(Cik[11][1][1]*Vpk[2][10][1])));
        Vpk[2][11][2] = ((Cik[11][2][2]*Vpk[2][10][2])+((Cik[11][0][2]*
          Vpk[2][10][0])+(Cik[11][1][2]*Vpk[2][10][1])));
        Vpk[2][12][0] = ((Cik[12][2][0]*Vpk[2][11][2])+((Cik[12][0][0]*
          Vpk[2][11][0])+(Cik[12][1][0]*Vpk[2][11][1])));
        Vpk[2][12][1] = ((Cik[12][2][1]*Vpk[2][11][2])+((Cik[12][0][1]*
          Vpk[2][11][0])+(Cik[12][1][1]*Vpk[2][11][1])));
        Vpk[2][12][2] = ((Cik[12][2][2]*Vpk[2][11][2])+((Cik[12][0][2]*
          Vpk[2][11][0])+(Cik[12][1][2]*Vpk[2][11][1])));
        Vpk[2][13][0] = ((Cik[13][2][0]*Vpk[2][12][2])+((Cik[13][0][0]*
          Vpk[2][12][0])+(Cik[13][1][0]*Vpk[2][12][1])));
        Vpk[2][13][1] = ((Cik[13][2][1]*Vpk[2][12][2])+((Cik[13][0][1]*
          Vpk[2][12][0])+(Cik[13][1][1]*Vpk[2][12][1])));
        Vpk[2][13][2] = ((Cik[13][2][2]*Vpk[2][12][2])+((Cik[13][0][2]*
          Vpk[2][12][0])+(Cik[13][1][2]*Vpk[2][12][1])));
        Vpk[2][14][0] = ((Cik[14][2][0]*Vpk[2][3][2])+((Cik[14][0][0]*
          Vpk[2][3][0])+(Cik[14][1][0]*Vpk[2][3][1])));
        Vpk[2][14][1] = ((Cik[14][2][1]*Vpk[2][3][2])+((Cik[14][0][1]*
          Vpk[2][3][0])+(Cik[14][1][1]*Vpk[2][3][1])));
        Vpk[2][14][2] = ((Cik[14][2][2]*Vpk[2][3][2])+((Cik[14][0][2]*
          Vpk[2][3][0])+(Cik[14][1][2]*Vpk[2][3][1])));
        Vpk[2][15][0] = ((Cik[15][2][0]*Vpk[2][14][2])+((Cik[15][0][0]*
          Vpk[2][14][0])+(Cik[15][1][0]*Vpk[2][14][1])));
        Vpk[2][15][1] = ((Cik[15][2][1]*Vpk[2][14][2])+((Cik[15][0][1]*
          Vpk[2][14][0])+(Cik[15][1][1]*Vpk[2][14][1])));
        Vpk[2][15][2] = ((Cik[15][2][2]*Vpk[2][14][2])+((Cik[15][0][2]*
          Vpk[2][14][0])+(Cik[15][1][2]*Vpk[2][14][1])));
        Vpk[2][16][0] = ((Cik[16][2][0]*Vpk[2][15][2])+((Cik[16][0][0]*
          Vpk[2][15][0])+(Cik[16][1][0]*Vpk[2][15][1])));
        Vpk[2][16][1] = ((Cik[16][2][1]*Vpk[2][15][2])+((Cik[16][0][1]*
          Vpk[2][15][0])+(Cik[16][1][1]*Vpk[2][15][1])));
        Vpk[2][16][2] = ((Cik[16][2][2]*Vpk[2][15][2])+((Cik[16][0][2]*
          Vpk[2][15][0])+(Cik[16][1][2]*Vpk[2][15][1])));
        Vpk[2][17][0] = ((Cik[17][2][0]*Vpk[2][16][2])+((Cik[17][0][0]*
          Vpk[2][16][0])+(Cik[17][1][0]*Vpk[2][16][1])));
        Vpk[2][17][1] = ((Cik[17][2][1]*Vpk[2][16][2])+((Cik[17][0][1]*
          Vpk[2][16][0])+(Cik[17][1][1]*Vpk[2][16][1])));
        Vpk[2][17][2] = ((Cik[17][2][2]*Vpk[2][16][2])+((Cik[17][0][2]*
          Vpk[2][16][0])+(Cik[17][1][2]*Vpk[2][16][1])));
        Vpk[2][18][0] = ((Cik[18][2][0]*Vpk[2][3][2])+((Cik[18][0][0]*
          Vpk[2][3][0])+(Cik[18][1][0]*Vpk[2][3][1])));
        Vpk[2][18][1] = ((Cik[18][2][1]*Vpk[2][3][2])+((Cik[18][0][1]*
          Vpk[2][3][0])+(Cik[18][1][1]*Vpk[2][3][1])));
        Vpk[2][18][2] = ((Cik[18][2][2]*Vpk[2][3][2])+((Cik[18][0][2]*
          Vpk[2][3][0])+(Cik[18][1][2]*Vpk[2][3][1])));
        Vpk[2][19][0] = ((Cik[19][2][0]*Vpk[2][18][2])+((Cik[19][0][0]*
          Vpk[2][18][0])+(Cik[19][1][0]*Vpk[2][18][1])));
        Vpk[2][19][1] = ((Cik[19][2][1]*Vpk[2][18][2])+((Cik[19][0][1]*
          Vpk[2][18][0])+(Cik[19][1][1]*Vpk[2][18][1])));
        Vpk[2][19][2] = ((Cik[19][2][2]*Vpk[2][18][2])+((Cik[19][0][2]*
          Vpk[2][18][0])+(Cik[19][1][2]*Vpk[2][18][1])));
        Vpk[2][20][0] = ((Cik[20][2][0]*Vpk[2][19][2])+((Cik[20][0][0]*
          Vpk[2][19][0])+(Cik[20][1][0]*Vpk[2][19][1])));
        Vpk[2][20][1] = ((Cik[20][2][1]*Vpk[2][19][2])+((Cik[20][0][1]*
          Vpk[2][19][0])+(Cik[20][1][1]*Vpk[2][19][1])));
        Vpk[2][20][2] = ((Cik[20][2][2]*Vpk[2][19][2])+((Cik[20][0][2]*
          Vpk[2][19][0])+(Cik[20][1][2]*Vpk[2][19][1])));
        Vpk[2][21][0] = ((Cik[21][2][0]*Vpk[2][20][2])+((Cik[21][0][0]*
          Vpk[2][20][0])+(Cik[21][1][0]*Vpk[2][20][1])));
        Vpk[2][21][1] = ((Cik[21][2][1]*Vpk[2][20][2])+((Cik[21][0][1]*
          Vpk[2][20][0])+(Cik[21][1][1]*Vpk[2][20][1])));
        Vpk[2][21][2] = ((Cik[21][2][2]*Vpk[2][20][2])+((Cik[21][0][2]*
          Vpk[2][20][0])+(Cik[21][1][2]*Vpk[2][20][1])));
        Vpk[3][5][1] = rk[0][2];
        Vpk[3][5][2] = -rk[0][1];
        VWri[3][6][1] = (rk[0][2]-ri[1][2]);
        VWri[3][6][2] = (ri[1][1]-rk[0][1]);
        Vpk[3][6][0] = (((Cik[6][0][2]*rk[1][1])-(Cik[6][0][1]*rk[1][2]))+((
          Cik[6][1][0]*VWri[3][6][1])+(Cik[6][2][0]*VWri[3][6][2])));
        Vpk[3][6][1] = (((Cik[6][0][0]*rk[1][2])-(Cik[6][0][2]*rk[1][0]))+((
          Cik[6][1][1]*VWri[3][6][1])+(Cik[6][2][1]*VWri[3][6][2])));
        Vpk[3][6][2] = (((Cik[6][0][1]*rk[1][0])-(Cik[6][0][0]*rk[1][1]))+((
          Cik[6][1][2]*VWri[3][6][1])+(Cik[6][2][2]*VWri[3][6][2])));
        VWri[3][7][0] = (Vpk[3][6][0]+((Cik[6][0][1]*ri[2][2])-(Cik[6][0][2]*
          ri[2][1])));
        VWri[3][7][1] = (Vpk[3][6][1]+((Cik[6][0][2]*ri[2][0])-(Cik[6][0][0]*
          ri[2][2])));
        VWri[3][7][2] = (Vpk[3][6][2]+((Cik[6][0][0]*ri[2][1])-(Cik[6][0][1]*
          ri[2][0])));
        Vpk[3][7][0] = (((Cik[7][2][0]*VWri[3][7][2])+((Cik[7][0][0]*
          VWri[3][7][0])+(Cik[7][1][0]*VWri[3][7][1])))+((rk[2][1]*Wpk[3][7][2])
          -(rk[2][2]*Wpk[3][7][1])));
        Vpk[3][7][1] = (((Cik[7][2][1]*VWri[3][7][2])+((Cik[7][0][1]*
          VWri[3][7][0])+(Cik[7][1][1]*VWri[3][7][1])))+((rk[2][2]*Wpk[3][7][0])
          -(rk[2][0]*Wpk[3][7][2])));
        Vpk[3][7][2] = (((Cik[7][2][2]*VWri[3][7][2])+((Cik[7][0][2]*
          VWri[3][7][0])+(Cik[7][1][2]*VWri[3][7][1])))+((rk[2][0]*Wpk[3][7][1])
          -(rk[2][1]*Wpk[3][7][0])));
        VWri[3][8][0] = (Vpk[3][7][0]+((ri[3][2]*Wpk[3][7][1])-(ri[3][1]*
          Wpk[3][7][2])));
        VWri[3][8][1] = (Vpk[3][7][1]+((ri[3][0]*Wpk[3][7][2])-(ri[3][2]*
          Wpk[3][7][0])));
        VWri[3][8][2] = (Vpk[3][7][2]+((ri[3][1]*Wpk[3][7][0])-(ri[3][0]*
          Wpk[3][7][1])));
        Vpk[3][8][0] = (((Cik[8][2][0]*VWri[3][8][2])+((Cik[8][0][0]*
          VWri[3][8][0])+(Cik[8][1][0]*VWri[3][8][1])))+((rk[3][1]*Wpk[3][8][2])
          -(rk[3][2]*Wpk[3][8][1])));
        Vpk[3][8][1] = (((Cik[8][2][1]*VWri[3][8][2])+((Cik[8][0][1]*
          VWri[3][8][0])+(Cik[8][1][1]*VWri[3][8][1])))+((rk[3][2]*Wpk[3][8][0])
          -(rk[3][0]*Wpk[3][8][2])));
        Vpk[3][8][2] = (((Cik[8][2][2]*VWri[3][8][2])+((Cik[8][0][2]*
          VWri[3][8][0])+(Cik[8][1][2]*VWri[3][8][1])))+((rk[3][0]*Wpk[3][8][1])
          -(rk[3][1]*Wpk[3][8][0])));
        VWri[3][9][0] = (Vpk[3][8][0]+((ri[4][2]*Wpk[3][8][1])-(ri[4][1]*
          Wpk[3][8][2])));
        VWri[3][9][1] = (Vpk[3][8][1]+((ri[4][0]*Wpk[3][8][2])-(ri[4][2]*
          Wpk[3][8][0])));
        VWri[3][9][2] = (Vpk[3][8][2]+((ri[4][1]*Wpk[3][8][0])-(ri[4][0]*
          Wpk[3][8][1])));
        Vpk[3][9][0] = (((Cik[9][2][0]*VWri[3][9][2])+((Cik[9][0][0]*
          VWri[3][9][0])+(Cik[9][1][0]*VWri[3][9][1])))+((psrk[9][1]*
          Wpk[3][9][2])-(psrk[9][2]*Wpk[3][9][1])));
        Vpk[3][9][1] = (((Cik[9][2][1]*VWri[3][9][2])+((Cik[9][0][1]*
          VWri[3][9][0])+(Cik[9][1][1]*VWri[3][9][1])))+((psrk[9][2]*
          Wpk[3][9][0])-(psrk[9][0]*Wpk[3][9][2])));
        Vpk[3][9][2] = (((Cik[9][2][2]*VWri[3][9][2])+((Cik[9][0][2]*
          VWri[3][9][0])+(Cik[9][1][2]*VWri[3][9][1])))+((psrk[9][0]*
          Wpk[3][9][1])-(psrk[9][1]*Wpk[3][9][0])));
        VWri[3][10][1] = (rk[0][2]-ri[6][2]);
        VWri[3][10][2] = (ri[6][1]-rk[0][1]);
        Vpk[3][10][0] = (((Cik[10][0][2]*rk[6][1])-(Cik[10][0][1]*rk[6][2]))+((
          Cik[10][1][0]*VWri[3][10][1])+(Cik[10][2][0]*VWri[3][10][2])));
        Vpk[3][10][1] = (((Cik[10][0][0]*rk[6][2])-(Cik[10][0][2]*rk[6][0]))+((
          Cik[10][1][1]*VWri[3][10][1])+(Cik[10][2][1]*VWri[3][10][2])));
        Vpk[3][10][2] = (((Cik[10][0][1]*rk[6][0])-(Cik[10][0][0]*rk[6][1]))+((
          Cik[10][1][2]*VWri[3][10][1])+(Cik[10][2][2]*VWri[3][10][2])));
        VWri[3][11][0] = (Vpk[3][10][0]+((Cik[10][0][1]*ri[7][2])-(Cik[10][0][2]
          *ri[7][1])));
        VWri[3][11][1] = (Vpk[3][10][1]+((Cik[10][0][2]*ri[7][0])-(Cik[10][0][0]
          *ri[7][2])));
        VWri[3][11][2] = (Vpk[3][10][2]+((Cik[10][0][0]*ri[7][1])-(Cik[10][0][1]
          *ri[7][0])));
        Vpk[3][11][0] = (((Cik[11][2][0]*VWri[3][11][2])+((Cik[11][0][0]*
          VWri[3][11][0])+(Cik[11][1][0]*VWri[3][11][1])))+((rk[7][1]*
          Wpk[3][11][2])-(rk[7][2]*Wpk[3][11][1])));
        Vpk[3][11][1] = (((Cik[11][2][1]*VWri[3][11][2])+((Cik[11][0][1]*
          VWri[3][11][0])+(Cik[11][1][1]*VWri[3][11][1])))+((rk[7][2]*
          Wpk[3][11][0])-(rk[7][0]*Wpk[3][11][2])));
        Vpk[3][11][2] = (((Cik[11][2][2]*VWri[3][11][2])+((Cik[11][0][2]*
          VWri[3][11][0])+(Cik[11][1][2]*VWri[3][11][1])))+((rk[7][0]*
          Wpk[3][11][1])-(rk[7][1]*Wpk[3][11][0])));
        VWri[3][12][0] = (Vpk[3][11][0]+((ri[8][2]*Wpk[3][11][1])-(ri[8][1]*
          Wpk[3][11][2])));
        VWri[3][12][1] = (Vpk[3][11][1]+((ri[8][0]*Wpk[3][11][2])-(ri[8][2]*
          Wpk[3][11][0])));
        VWri[3][12][2] = (Vpk[3][11][2]+((ri[8][1]*Wpk[3][11][0])-(ri[8][0]*
          Wpk[3][11][1])));
        Vpk[3][12][0] = (((Cik[12][2][0]*VWri[3][12][2])+((Cik[12][0][0]*
          VWri[3][12][0])+(Cik[12][1][0]*VWri[3][12][1])))+((rk[8][1]*
          Wpk[3][12][2])-(rk[8][2]*Wpk[3][12][1])));
        Vpk[3][12][1] = (((Cik[12][2][1]*VWri[3][12][2])+((Cik[12][0][1]*
          VWri[3][12][0])+(Cik[12][1][1]*VWri[3][12][1])))+((rk[8][2]*
          Wpk[3][12][0])-(rk[8][0]*Wpk[3][12][2])));
        Vpk[3][12][2] = (((Cik[12][2][2]*VWri[3][12][2])+((Cik[12][0][2]*
          VWri[3][12][0])+(Cik[12][1][2]*VWri[3][12][1])))+((rk[8][0]*
          Wpk[3][12][1])-(rk[8][1]*Wpk[3][12][0])));
        VWri[3][13][0] = (Vpk[3][12][0]+((ri[9][2]*Wpk[3][12][1])-(ri[9][1]*
          Wpk[3][12][2])));
        VWri[3][13][1] = (Vpk[3][12][1]+((ri[9][0]*Wpk[3][12][2])-(ri[9][2]*
          Wpk[3][12][0])));
        VWri[3][13][2] = (Vpk[3][12][2]+((ri[9][1]*Wpk[3][12][0])-(ri[9][0]*
          Wpk[3][12][1])));
        Vpk[3][13][0] = (((Cik[13][2][0]*VWri[3][13][2])+((Cik[13][0][0]*
          VWri[3][13][0])+(Cik[13][1][0]*VWri[3][13][1])))+((psrk[13][1]*
          Wpk[3][13][2])-(psrk[13][2]*Wpk[3][13][1])));
        Vpk[3][13][1] = (((Cik[13][2][1]*VWri[3][13][2])+((Cik[13][0][1]*
          VWri[3][13][0])+(Cik[13][1][1]*VWri[3][13][1])))+((psrk[13][2]*
          Wpk[3][13][0])-(psrk[13][0]*Wpk[3][13][2])));
        Vpk[3][13][2] = (((Cik[13][2][2]*VWri[3][13][2])+((Cik[13][0][2]*
          VWri[3][13][0])+(Cik[13][1][2]*VWri[3][13][1])))+((psrk[13][0]*
          Wpk[3][13][1])-(psrk[13][1]*Wpk[3][13][0])));
        VWri[3][14][1] = (rk[0][2]-ri[11][2]);
        VWri[3][14][2] = (ri[11][1]-rk[0][1]);
        Vpk[3][14][0] = (((Cik[14][0][2]*rk[11][1])-(Cik[14][0][1]*rk[11][2]))+(
          (Cik[14][1][0]*VWri[3][14][1])+(Cik[14][2][0]*VWri[3][14][2])));
        Vpk[3][14][1] = (((Cik[14][0][0]*rk[11][2])-(Cik[14][0][2]*rk[11][0]))+(
          (Cik[14][1][1]*VWri[3][14][1])+(Cik[14][2][1]*VWri[3][14][2])));
        Vpk[3][14][2] = (((Cik[14][0][1]*rk[11][0])-(Cik[14][0][0]*rk[11][1]))+(
          (Cik[14][1][2]*VWri[3][14][1])+(Cik[14][2][2]*VWri[3][14][2])));
        VWri[3][15][0] = (Vpk[3][14][0]+((Cik[14][0][1]*ri[12][2])-(
          Cik[14][0][2]*ri[12][1])));
        VWri[3][15][1] = (Vpk[3][14][1]+((Cik[14][0][2]*ri[12][0])-(
          Cik[14][0][0]*ri[12][2])));
        VWri[3][15][2] = (Vpk[3][14][2]+((Cik[14][0][0]*ri[12][1])-(
          Cik[14][0][1]*ri[12][0])));
        Vpk[3][15][0] = (((Cik[15][2][0]*VWri[3][15][2])+((Cik[15][0][0]*
          VWri[3][15][0])+(Cik[15][1][0]*VWri[3][15][1])))+((rk[12][1]*
          Wpk[3][15][2])-(rk[12][2]*Wpk[3][15][1])));
        Vpk[3][15][1] = (((Cik[15][2][1]*VWri[3][15][2])+((Cik[15][0][1]*
          VWri[3][15][0])+(Cik[15][1][1]*VWri[3][15][1])))+((rk[12][2]*
          Wpk[3][15][0])-(rk[12][0]*Wpk[3][15][2])));
        Vpk[3][15][2] = (((Cik[15][2][2]*VWri[3][15][2])+((Cik[15][0][2]*
          VWri[3][15][0])+(Cik[15][1][2]*VWri[3][15][1])))+((rk[12][0]*
          Wpk[3][15][1])-(rk[12][1]*Wpk[3][15][0])));
        VWri[3][16][0] = (Vpk[3][15][0]+((ri[13][2]*Wpk[3][15][1])-(ri[13][1]*
          Wpk[3][15][2])));
        VWri[3][16][1] = (Vpk[3][15][1]+((ri[13][0]*Wpk[3][15][2])-(ri[13][2]*
          Wpk[3][15][0])));
        VWri[3][16][2] = (Vpk[3][15][2]+((ri[13][1]*Wpk[3][15][0])-(ri[13][0]*
          Wpk[3][15][1])));
        Vpk[3][16][0] = (((Cik[16][2][0]*VWri[3][16][2])+((Cik[16][0][0]*
          VWri[3][16][0])+(Cik[16][1][0]*VWri[3][16][1])))+((rk[13][1]*
          Wpk[3][16][2])-(rk[13][2]*Wpk[3][16][1])));
        Vpk[3][16][1] = (((Cik[16][2][1]*VWri[3][16][2])+((Cik[16][0][1]*
          VWri[3][16][0])+(Cik[16][1][1]*VWri[3][16][1])))+((rk[13][2]*
          Wpk[3][16][0])-(rk[13][0]*Wpk[3][16][2])));
        Vpk[3][16][2] = (((Cik[16][2][2]*VWri[3][16][2])+((Cik[16][0][2]*
          VWri[3][16][0])+(Cik[16][1][2]*VWri[3][16][1])))+((rk[13][0]*
          Wpk[3][16][1])-(rk[13][1]*Wpk[3][16][0])));
        VWri[3][17][0] = (Vpk[3][16][0]+((ri[14][2]*Wpk[3][16][1])-(ri[14][1]*
          Wpk[3][16][2])));
        VWri[3][17][1] = (Vpk[3][16][1]+((ri[14][0]*Wpk[3][16][2])-(ri[14][2]*
          Wpk[3][16][0])));
        VWri[3][17][2] = (Vpk[3][16][2]+((ri[14][1]*Wpk[3][16][0])-(ri[14][0]*
          Wpk[3][16][1])));
        Vpk[3][17][0] = (((Cik[17][2][0]*VWri[3][17][2])+((Cik[17][0][0]*
          VWri[3][17][0])+(Cik[17][1][0]*VWri[3][17][1])))+((psrk[17][1]*
          Wpk[3][17][2])-(psrk[17][2]*Wpk[3][17][1])));
        Vpk[3][17][1] = (((Cik[17][2][1]*VWri[3][17][2])+((Cik[17][0][1]*
          VWri[3][17][0])+(Cik[17][1][1]*VWri[3][17][1])))+((psrk[17][2]*
          Wpk[3][17][0])-(psrk[17][0]*Wpk[3][17][2])));
        Vpk[3][17][2] = (((Cik[17][2][2]*VWri[3][17][2])+((Cik[17][0][2]*
          VWri[3][17][0])+(Cik[17][1][2]*VWri[3][17][1])))+((psrk[17][0]*
          Wpk[3][17][1])-(psrk[17][1]*Wpk[3][17][0])));
        VWri[3][18][1] = (rk[0][2]-ri[16][2]);
        VWri[3][18][2] = (ri[16][1]-rk[0][1]);
        Vpk[3][18][0] = (((Cik[18][0][2]*rk[16][1])-(Cik[18][0][1]*rk[16][2]))+(
          (Cik[18][1][0]*VWri[3][18][1])+(Cik[18][2][0]*VWri[3][18][2])));
        Vpk[3][18][1] = (((Cik[18][0][0]*rk[16][2])-(Cik[18][0][2]*rk[16][0]))+(
          (Cik[18][1][1]*VWri[3][18][1])+(Cik[18][2][1]*VWri[3][18][2])));
        Vpk[3][18][2] = (((Cik[18][0][1]*rk[16][0])-(Cik[18][0][0]*rk[16][1]))+(
          (Cik[18][1][2]*VWri[3][18][1])+(Cik[18][2][2]*VWri[3][18][2])));
        VWri[3][19][0] = (Vpk[3][18][0]+((Cik[18][0][1]*ri[17][2])-(
          Cik[18][0][2]*ri[17][1])));
        VWri[3][19][1] = (Vpk[3][18][1]+((Cik[18][0][2]*ri[17][0])-(
          Cik[18][0][0]*ri[17][2])));
        VWri[3][19][2] = (Vpk[3][18][2]+((Cik[18][0][0]*ri[17][1])-(
          Cik[18][0][1]*ri[17][0])));
        Vpk[3][19][0] = (((Cik[19][2][0]*VWri[3][19][2])+((Cik[19][0][0]*
          VWri[3][19][0])+(Cik[19][1][0]*VWri[3][19][1])))+((rk[17][1]*
          Wpk[3][19][2])-(rk[17][2]*Wpk[3][19][1])));
        Vpk[3][19][1] = (((Cik[19][2][1]*VWri[3][19][2])+((Cik[19][0][1]*
          VWri[3][19][0])+(Cik[19][1][1]*VWri[3][19][1])))+((rk[17][2]*
          Wpk[3][19][0])-(rk[17][0]*Wpk[3][19][2])));
        Vpk[3][19][2] = (((Cik[19][2][2]*VWri[3][19][2])+((Cik[19][0][2]*
          VWri[3][19][0])+(Cik[19][1][2]*VWri[3][19][1])))+((rk[17][0]*
          Wpk[3][19][1])-(rk[17][1]*Wpk[3][19][0])));
        VWri[3][20][0] = (Vpk[3][19][0]+((ri[18][2]*Wpk[3][19][1])-(ri[18][1]*
          Wpk[3][19][2])));
        VWri[3][20][1] = (Vpk[3][19][1]+((ri[18][0]*Wpk[3][19][2])-(ri[18][2]*
          Wpk[3][19][0])));
        VWri[3][20][2] = (Vpk[3][19][2]+((ri[18][1]*Wpk[3][19][0])-(ri[18][0]*
          Wpk[3][19][1])));
        Vpk[3][20][0] = (((Cik[20][2][0]*VWri[3][20][2])+((Cik[20][0][0]*
          VWri[3][20][0])+(Cik[20][1][0]*VWri[3][20][1])))+((rk[18][1]*
          Wpk[3][20][2])-(rk[18][2]*Wpk[3][20][1])));
        Vpk[3][20][1] = (((Cik[20][2][1]*VWri[3][20][2])+((Cik[20][0][1]*
          VWri[3][20][0])+(Cik[20][1][1]*VWri[3][20][1])))+((rk[18][2]*
          Wpk[3][20][0])-(rk[18][0]*Wpk[3][20][2])));
        Vpk[3][20][2] = (((Cik[20][2][2]*VWri[3][20][2])+((Cik[20][0][2]*
          VWri[3][20][0])+(Cik[20][1][2]*VWri[3][20][1])))+((rk[18][0]*
          Wpk[3][20][1])-(rk[18][1]*Wpk[3][20][0])));
        VWri[3][21][0] = (Vpk[3][20][0]+((ri[19][2]*Wpk[3][20][1])-(ri[19][1]*
          Wpk[3][20][2])));
        VWri[3][21][1] = (Vpk[3][20][1]+((ri[19][0]*Wpk[3][20][2])-(ri[19][2]*
          Wpk[3][20][0])));
        VWri[3][21][2] = (Vpk[3][20][2]+((ri[19][1]*Wpk[3][20][0])-(ri[19][0]*
          Wpk[3][20][1])));
        Vpk[3][21][0] = (((Cik[21][2][0]*VWri[3][21][2])+((Cik[21][0][0]*
          VWri[3][21][0])+(Cik[21][1][0]*VWri[3][21][1])))+((psrk[21][1]*
          Wpk[3][21][2])-(psrk[21][2]*Wpk[3][21][1])));
        Vpk[3][21][1] = (((Cik[21][2][1]*VWri[3][21][2])+((Cik[21][0][1]*
          VWri[3][21][0])+(Cik[21][1][1]*VWri[3][21][1])))+((psrk[21][2]*
          Wpk[3][21][0])-(psrk[21][0]*Wpk[3][21][2])));
        Vpk[3][21][2] = (((Cik[21][2][2]*VWri[3][21][2])+((Cik[21][0][2]*
          VWri[3][21][0])+(Cik[21][1][2]*VWri[3][21][1])))+((psrk[21][0]*
          Wpk[3][21][1])-(psrk[21][1]*Wpk[3][21][0])));
        Vpk[4][5][0] = -rk[0][2];
        Vpk[4][5][2] = rk[0][0];
        VWri[4][6][0] = (ri[1][2]-rk[0][2]);
        VWri[4][6][2] = (rk[0][0]-ri[1][0]);
        Vpk[4][6][0] = (((Cik[6][0][0]*VWri[4][6][0])+(Cik[6][2][0]*
          VWri[4][6][2]))+((Cik[6][1][2]*rk[1][1])-(Cik[6][1][1]*rk[1][2])));
        Vpk[4][6][1] = (((Cik[6][0][1]*VWri[4][6][0])+(Cik[6][2][1]*
          VWri[4][6][2]))+((Cik[6][1][0]*rk[1][2])-(Cik[6][1][2]*rk[1][0])));
        Vpk[4][6][2] = (((Cik[6][0][2]*VWri[4][6][0])+(Cik[6][2][2]*
          VWri[4][6][2]))+((Cik[6][1][1]*rk[1][0])-(Cik[6][1][0]*rk[1][1])));
        VWri[4][7][0] = (Vpk[4][6][0]+((Cik[6][1][1]*ri[2][2])-(Cik[6][1][2]*
          ri[2][1])));
        VWri[4][7][1] = (Vpk[4][6][1]+((Cik[6][1][2]*ri[2][0])-(Cik[6][1][0]*
          ri[2][2])));
        VWri[4][7][2] = (Vpk[4][6][2]+((Cik[6][1][0]*ri[2][1])-(Cik[6][1][1]*
          ri[2][0])));
        Vpk[4][7][0] = (((Cik[7][2][0]*VWri[4][7][2])+((Cik[7][0][0]*
          VWri[4][7][0])+(Cik[7][1][0]*VWri[4][7][1])))+((rk[2][1]*Wpk[4][7][2])
          -(rk[2][2]*Wpk[4][7][1])));
        Vpk[4][7][1] = (((Cik[7][2][1]*VWri[4][7][2])+((Cik[7][0][1]*
          VWri[4][7][0])+(Cik[7][1][1]*VWri[4][7][1])))+((rk[2][2]*Wpk[4][7][0])
          -(rk[2][0]*Wpk[4][7][2])));
        Vpk[4][7][2] = (((Cik[7][2][2]*VWri[4][7][2])+((Cik[7][0][2]*
          VWri[4][7][0])+(Cik[7][1][2]*VWri[4][7][1])))+((rk[2][0]*Wpk[4][7][1])
          -(rk[2][1]*Wpk[4][7][0])));
        VWri[4][8][0] = (Vpk[4][7][0]+((ri[3][2]*Wpk[4][7][1])-(ri[3][1]*
          Wpk[4][7][2])));
        VWri[4][8][1] = (Vpk[4][7][1]+((ri[3][0]*Wpk[4][7][2])-(ri[3][2]*
          Wpk[4][7][0])));
        VWri[4][8][2] = (Vpk[4][7][2]+((ri[3][1]*Wpk[4][7][0])-(ri[3][0]*
          Wpk[4][7][1])));
        Vpk[4][8][0] = (((Cik[8][2][0]*VWri[4][8][2])+((Cik[8][0][0]*
          VWri[4][8][0])+(Cik[8][1][0]*VWri[4][8][1])))+((rk[3][1]*Wpk[4][8][2])
          -(rk[3][2]*Wpk[4][8][1])));
        Vpk[4][8][1] = (((Cik[8][2][1]*VWri[4][8][2])+((Cik[8][0][1]*
          VWri[4][8][0])+(Cik[8][1][1]*VWri[4][8][1])))+((rk[3][2]*Wpk[4][8][0])
          -(rk[3][0]*Wpk[4][8][2])));
        Vpk[4][8][2] = (((Cik[8][2][2]*VWri[4][8][2])+((Cik[8][0][2]*
          VWri[4][8][0])+(Cik[8][1][2]*VWri[4][8][1])))+((rk[3][0]*Wpk[4][8][1])
          -(rk[3][1]*Wpk[4][8][0])));
        VWri[4][9][0] = (Vpk[4][8][0]+((ri[4][2]*Wpk[4][8][1])-(ri[4][1]*
          Wpk[4][8][2])));
        VWri[4][9][1] = (Vpk[4][8][1]+((ri[4][0]*Wpk[4][8][2])-(ri[4][2]*
          Wpk[4][8][0])));
        VWri[4][9][2] = (Vpk[4][8][2]+((ri[4][1]*Wpk[4][8][0])-(ri[4][0]*
          Wpk[4][8][1])));
        Vpk[4][9][0] = (((Cik[9][2][0]*VWri[4][9][2])+((Cik[9][0][0]*
          VWri[4][9][0])+(Cik[9][1][0]*VWri[4][9][1])))+((psrk[9][1]*
          Wpk[4][9][2])-(psrk[9][2]*Wpk[4][9][1])));
        Vpk[4][9][1] = (((Cik[9][2][1]*VWri[4][9][2])+((Cik[9][0][1]*
          VWri[4][9][0])+(Cik[9][1][1]*VWri[4][9][1])))+((psrk[9][2]*
          Wpk[4][9][0])-(psrk[9][0]*Wpk[4][9][2])));
        Vpk[4][9][2] = (((Cik[9][2][2]*VWri[4][9][2])+((Cik[9][0][2]*
          VWri[4][9][0])+(Cik[9][1][2]*VWri[4][9][1])))+((psrk[9][0]*
          Wpk[4][9][1])-(psrk[9][1]*Wpk[4][9][0])));
        VWri[4][10][0] = (ri[6][2]-rk[0][2]);
        VWri[4][10][2] = (rk[0][0]-ri[6][0]);
        Vpk[4][10][0] = (((Cik[10][0][0]*VWri[4][10][0])+(Cik[10][2][0]*
          VWri[4][10][2]))+((Cik[10][1][2]*rk[6][1])-(Cik[10][1][1]*rk[6][2])));
        Vpk[4][10][1] = (((Cik[10][0][1]*VWri[4][10][0])+(Cik[10][2][1]*
          VWri[4][10][2]))+((Cik[10][1][0]*rk[6][2])-(Cik[10][1][2]*rk[6][0])));
        Vpk[4][10][2] = (((Cik[10][0][2]*VWri[4][10][0])+(Cik[10][2][2]*
          VWri[4][10][2]))+((Cik[10][1][1]*rk[6][0])-(Cik[10][1][0]*rk[6][1])));
        VWri[4][11][0] = (Vpk[4][10][0]+((Cik[10][1][1]*ri[7][2])-(Cik[10][1][2]
          *ri[7][1])));
        VWri[4][11][1] = (Vpk[4][10][1]+((Cik[10][1][2]*ri[7][0])-(Cik[10][1][0]
          *ri[7][2])));
        VWri[4][11][2] = (Vpk[4][10][2]+((Cik[10][1][0]*ri[7][1])-(Cik[10][1][1]
          *ri[7][0])));
        Vpk[4][11][0] = (((Cik[11][2][0]*VWri[4][11][2])+((Cik[11][0][0]*
          VWri[4][11][0])+(Cik[11][1][0]*VWri[4][11][1])))+((rk[7][1]*
          Wpk[4][11][2])-(rk[7][2]*Wpk[4][11][1])));
        Vpk[4][11][1] = (((Cik[11][2][1]*VWri[4][11][2])+((Cik[11][0][1]*
          VWri[4][11][0])+(Cik[11][1][1]*VWri[4][11][1])))+((rk[7][2]*
          Wpk[4][11][0])-(rk[7][0]*Wpk[4][11][2])));
        Vpk[4][11][2] = (((Cik[11][2][2]*VWri[4][11][2])+((Cik[11][0][2]*
          VWri[4][11][0])+(Cik[11][1][2]*VWri[4][11][1])))+((rk[7][0]*
          Wpk[4][11][1])-(rk[7][1]*Wpk[4][11][0])));
        VWri[4][12][0] = (Vpk[4][11][0]+((ri[8][2]*Wpk[4][11][1])-(ri[8][1]*
          Wpk[4][11][2])));
        VWri[4][12][1] = (Vpk[4][11][1]+((ri[8][0]*Wpk[4][11][2])-(ri[8][2]*
          Wpk[4][11][0])));
        VWri[4][12][2] = (Vpk[4][11][2]+((ri[8][1]*Wpk[4][11][0])-(ri[8][0]*
          Wpk[4][11][1])));
        Vpk[4][12][0] = (((Cik[12][2][0]*VWri[4][12][2])+((Cik[12][0][0]*
          VWri[4][12][0])+(Cik[12][1][0]*VWri[4][12][1])))+((rk[8][1]*
          Wpk[4][12][2])-(rk[8][2]*Wpk[4][12][1])));
        Vpk[4][12][1] = (((Cik[12][2][1]*VWri[4][12][2])+((Cik[12][0][1]*
          VWri[4][12][0])+(Cik[12][1][1]*VWri[4][12][1])))+((rk[8][2]*
          Wpk[4][12][0])-(rk[8][0]*Wpk[4][12][2])));
        Vpk[4][12][2] = (((Cik[12][2][2]*VWri[4][12][2])+((Cik[12][0][2]*
          VWri[4][12][0])+(Cik[12][1][2]*VWri[4][12][1])))+((rk[8][0]*
          Wpk[4][12][1])-(rk[8][1]*Wpk[4][12][0])));
        VWri[4][13][0] = (Vpk[4][12][0]+((ri[9][2]*Wpk[4][12][1])-(ri[9][1]*
          Wpk[4][12][2])));
        VWri[4][13][1] = (Vpk[4][12][1]+((ri[9][0]*Wpk[4][12][2])-(ri[9][2]*
          Wpk[4][12][0])));
        VWri[4][13][2] = (Vpk[4][12][2]+((ri[9][1]*Wpk[4][12][0])-(ri[9][0]*
          Wpk[4][12][1])));
        Vpk[4][13][0] = (((Cik[13][2][0]*VWri[4][13][2])+((Cik[13][0][0]*
          VWri[4][13][0])+(Cik[13][1][0]*VWri[4][13][1])))+((psrk[13][1]*
          Wpk[4][13][2])-(psrk[13][2]*Wpk[4][13][1])));
        Vpk[4][13][1] = (((Cik[13][2][1]*VWri[4][13][2])+((Cik[13][0][1]*
          VWri[4][13][0])+(Cik[13][1][1]*VWri[4][13][1])))+((psrk[13][2]*
          Wpk[4][13][0])-(psrk[13][0]*Wpk[4][13][2])));
        Vpk[4][13][2] = (((Cik[13][2][2]*VWri[4][13][2])+((Cik[13][0][2]*
          VWri[4][13][0])+(Cik[13][1][2]*VWri[4][13][1])))+((psrk[13][0]*
          Wpk[4][13][1])-(psrk[13][1]*Wpk[4][13][0])));
        VWri[4][14][0] = (ri[11][2]-rk[0][2]);
        VWri[4][14][2] = (rk[0][0]-ri[11][0]);
        Vpk[4][14][0] = (((Cik[14][0][0]*VWri[4][14][0])+(Cik[14][2][0]*
          VWri[4][14][2]))+((Cik[14][1][2]*rk[11][1])-(Cik[14][1][1]*rk[11][2]))
          );
        Vpk[4][14][1] = (((Cik[14][0][1]*VWri[4][14][0])+(Cik[14][2][1]*
          VWri[4][14][2]))+((Cik[14][1][0]*rk[11][2])-(Cik[14][1][2]*rk[11][0]))
          );
        Vpk[4][14][2] = (((Cik[14][0][2]*VWri[4][14][0])+(Cik[14][2][2]*
          VWri[4][14][2]))+((Cik[14][1][1]*rk[11][0])-(Cik[14][1][0]*rk[11][1]))
          );
        VWri[4][15][0] = (Vpk[4][14][0]+((Cik[14][1][1]*ri[12][2])-(
          Cik[14][1][2]*ri[12][1])));
        VWri[4][15][1] = (Vpk[4][14][1]+((Cik[14][1][2]*ri[12][0])-(
          Cik[14][1][0]*ri[12][2])));
        VWri[4][15][2] = (Vpk[4][14][2]+((Cik[14][1][0]*ri[12][1])-(
          Cik[14][1][1]*ri[12][0])));
        Vpk[4][15][0] = (((Cik[15][2][0]*VWri[4][15][2])+((Cik[15][0][0]*
          VWri[4][15][0])+(Cik[15][1][0]*VWri[4][15][1])))+((rk[12][1]*
          Wpk[4][15][2])-(rk[12][2]*Wpk[4][15][1])));
        Vpk[4][15][1] = (((Cik[15][2][1]*VWri[4][15][2])+((Cik[15][0][1]*
          VWri[4][15][0])+(Cik[15][1][1]*VWri[4][15][1])))+((rk[12][2]*
          Wpk[4][15][0])-(rk[12][0]*Wpk[4][15][2])));
        Vpk[4][15][2] = (((Cik[15][2][2]*VWri[4][15][2])+((Cik[15][0][2]*
          VWri[4][15][0])+(Cik[15][1][2]*VWri[4][15][1])))+((rk[12][0]*
          Wpk[4][15][1])-(rk[12][1]*Wpk[4][15][0])));
        VWri[4][16][0] = (Vpk[4][15][0]+((ri[13][2]*Wpk[4][15][1])-(ri[13][1]*
          Wpk[4][15][2])));
        VWri[4][16][1] = (Vpk[4][15][1]+((ri[13][0]*Wpk[4][15][2])-(ri[13][2]*
          Wpk[4][15][0])));
        VWri[4][16][2] = (Vpk[4][15][2]+((ri[13][1]*Wpk[4][15][0])-(ri[13][0]*
          Wpk[4][15][1])));
        Vpk[4][16][0] = (((Cik[16][2][0]*VWri[4][16][2])+((Cik[16][0][0]*
          VWri[4][16][0])+(Cik[16][1][0]*VWri[4][16][1])))+((rk[13][1]*
          Wpk[4][16][2])-(rk[13][2]*Wpk[4][16][1])));
        Vpk[4][16][1] = (((Cik[16][2][1]*VWri[4][16][2])+((Cik[16][0][1]*
          VWri[4][16][0])+(Cik[16][1][1]*VWri[4][16][1])))+((rk[13][2]*
          Wpk[4][16][0])-(rk[13][0]*Wpk[4][16][2])));
        Vpk[4][16][2] = (((Cik[16][2][2]*VWri[4][16][2])+((Cik[16][0][2]*
          VWri[4][16][0])+(Cik[16][1][2]*VWri[4][16][1])))+((rk[13][0]*
          Wpk[4][16][1])-(rk[13][1]*Wpk[4][16][0])));
        VWri[4][17][0] = (Vpk[4][16][0]+((ri[14][2]*Wpk[4][16][1])-(ri[14][1]*
          Wpk[4][16][2])));
        VWri[4][17][1] = (Vpk[4][16][1]+((ri[14][0]*Wpk[4][16][2])-(ri[14][2]*
          Wpk[4][16][0])));
        VWri[4][17][2] = (Vpk[4][16][2]+((ri[14][1]*Wpk[4][16][0])-(ri[14][0]*
          Wpk[4][16][1])));
        Vpk[4][17][0] = (((Cik[17][2][0]*VWri[4][17][2])+((Cik[17][0][0]*
          VWri[4][17][0])+(Cik[17][1][0]*VWri[4][17][1])))+((psrk[17][1]*
          Wpk[4][17][2])-(psrk[17][2]*Wpk[4][17][1])));
        Vpk[4][17][1] = (((Cik[17][2][1]*VWri[4][17][2])+((Cik[17][0][1]*
          VWri[4][17][0])+(Cik[17][1][1]*VWri[4][17][1])))+((psrk[17][2]*
          Wpk[4][17][0])-(psrk[17][0]*Wpk[4][17][2])));
        Vpk[4][17][2] = (((Cik[17][2][2]*VWri[4][17][2])+((Cik[17][0][2]*
          VWri[4][17][0])+(Cik[17][1][2]*VWri[4][17][1])))+((psrk[17][0]*
          Wpk[4][17][1])-(psrk[17][1]*Wpk[4][17][0])));
        VWri[4][18][0] = (ri[16][2]-rk[0][2]);
        VWri[4][18][2] = (rk[0][0]-ri[16][0]);
        Vpk[4][18][0] = (((Cik[18][0][0]*VWri[4][18][0])+(Cik[18][2][0]*
          VWri[4][18][2]))+((Cik[18][1][2]*rk[16][1])-(Cik[18][1][1]*rk[16][2]))
          );
        Vpk[4][18][1] = (((Cik[18][0][1]*VWri[4][18][0])+(Cik[18][2][1]*
          VWri[4][18][2]))+((Cik[18][1][0]*rk[16][2])-(Cik[18][1][2]*rk[16][0]))
          );
        Vpk[4][18][2] = (((Cik[18][0][2]*VWri[4][18][0])+(Cik[18][2][2]*
          VWri[4][18][2]))+((Cik[18][1][1]*rk[16][0])-(Cik[18][1][0]*rk[16][1]))
          );
        VWri[4][19][0] = (Vpk[4][18][0]+((Cik[18][1][1]*ri[17][2])-(
          Cik[18][1][2]*ri[17][1])));
        VWri[4][19][1] = (Vpk[4][18][1]+((Cik[18][1][2]*ri[17][0])-(
          Cik[18][1][0]*ri[17][2])));
        VWri[4][19][2] = (Vpk[4][18][2]+((Cik[18][1][0]*ri[17][1])-(
          Cik[18][1][1]*ri[17][0])));
        Vpk[4][19][0] = (((Cik[19][2][0]*VWri[4][19][2])+((Cik[19][0][0]*
          VWri[4][19][0])+(Cik[19][1][0]*VWri[4][19][1])))+((rk[17][1]*
          Wpk[4][19][2])-(rk[17][2]*Wpk[4][19][1])));
        Vpk[4][19][1] = (((Cik[19][2][1]*VWri[4][19][2])+((Cik[19][0][1]*
          VWri[4][19][0])+(Cik[19][1][1]*VWri[4][19][1])))+((rk[17][2]*
          Wpk[4][19][0])-(rk[17][0]*Wpk[4][19][2])));
        Vpk[4][19][2] = (((Cik[19][2][2]*VWri[4][19][2])+((Cik[19][0][2]*
          VWri[4][19][0])+(Cik[19][1][2]*VWri[4][19][1])))+((rk[17][0]*
          Wpk[4][19][1])-(rk[17][1]*Wpk[4][19][0])));
        VWri[4][20][0] = (Vpk[4][19][0]+((ri[18][2]*Wpk[4][19][1])-(ri[18][1]*
          Wpk[4][19][2])));
        VWri[4][20][1] = (Vpk[4][19][1]+((ri[18][0]*Wpk[4][19][2])-(ri[18][2]*
          Wpk[4][19][0])));
        VWri[4][20][2] = (Vpk[4][19][2]+((ri[18][1]*Wpk[4][19][0])-(ri[18][0]*
          Wpk[4][19][1])));
        Vpk[4][20][0] = (((Cik[20][2][0]*VWri[4][20][2])+((Cik[20][0][0]*
          VWri[4][20][0])+(Cik[20][1][0]*VWri[4][20][1])))+((rk[18][1]*
          Wpk[4][20][2])-(rk[18][2]*Wpk[4][20][1])));
        Vpk[4][20][1] = (((Cik[20][2][1]*VWri[4][20][2])+((Cik[20][0][1]*
          VWri[4][20][0])+(Cik[20][1][1]*VWri[4][20][1])))+((rk[18][2]*
          Wpk[4][20][0])-(rk[18][0]*Wpk[4][20][2])));
        Vpk[4][20][2] = (((Cik[20][2][2]*VWri[4][20][2])+((Cik[20][0][2]*
          VWri[4][20][0])+(Cik[20][1][2]*VWri[4][20][1])))+((rk[18][0]*
          Wpk[4][20][1])-(rk[18][1]*Wpk[4][20][0])));
        VWri[4][21][0] = (Vpk[4][20][0]+((ri[19][2]*Wpk[4][20][1])-(ri[19][1]*
          Wpk[4][20][2])));
        VWri[4][21][1] = (Vpk[4][20][1]+((ri[19][0]*Wpk[4][20][2])-(ri[19][2]*
          Wpk[4][20][0])));
        VWri[4][21][2] = (Vpk[4][20][2]+((ri[19][1]*Wpk[4][20][0])-(ri[19][0]*
          Wpk[4][20][1])));
        Vpk[4][21][0] = (((Cik[21][2][0]*VWri[4][21][2])+((Cik[21][0][0]*
          VWri[4][21][0])+(Cik[21][1][0]*VWri[4][21][1])))+((psrk[21][1]*
          Wpk[4][21][2])-(psrk[21][2]*Wpk[4][21][1])));
        Vpk[4][21][1] = (((Cik[21][2][1]*VWri[4][21][2])+((Cik[21][0][1]*
          VWri[4][21][0])+(Cik[21][1][1]*VWri[4][21][1])))+((psrk[21][2]*
          Wpk[4][21][0])-(psrk[21][0]*Wpk[4][21][2])));
        Vpk[4][21][2] = (((Cik[21][2][2]*VWri[4][21][2])+((Cik[21][0][2]*
          VWri[4][21][0])+(Cik[21][1][2]*VWri[4][21][1])))+((psrk[21][0]*
          Wpk[4][21][1])-(psrk[21][1]*Wpk[4][21][0])));
        Vpk[5][5][0] = rk[0][1];
        Vpk[5][5][1] = -rk[0][0];
        VWri[5][6][0] = (rk[0][1]-ri[1][1]);
        VWri[5][6][1] = (ri[1][0]-rk[0][0]);
        Vpk[5][6][0] = (((Cik[6][0][0]*VWri[5][6][0])+(Cik[6][1][0]*
          VWri[5][6][1]))+((Cik[6][2][2]*rk[1][1])-(Cik[6][2][1]*rk[1][2])));
        Vpk[5][6][1] = (((Cik[6][0][1]*VWri[5][6][0])+(Cik[6][1][1]*
          VWri[5][6][1]))+((Cik[6][2][0]*rk[1][2])-(Cik[6][2][2]*rk[1][0])));
        Vpk[5][6][2] = (((Cik[6][0][2]*VWri[5][6][0])+(Cik[6][1][2]*
          VWri[5][6][1]))+((Cik[6][2][1]*rk[1][0])-(Cik[6][2][0]*rk[1][1])));
        VWri[5][7][0] = (Vpk[5][6][0]+((Cik[6][2][1]*ri[2][2])-(Cik[6][2][2]*
          ri[2][1])));
        VWri[5][7][1] = (Vpk[5][6][1]+((Cik[6][2][2]*ri[2][0])-(Cik[6][2][0]*
          ri[2][2])));
        VWri[5][7][2] = (Vpk[5][6][2]+((Cik[6][2][0]*ri[2][1])-(Cik[6][2][1]*
          ri[2][0])));
        Vpk[5][7][0] = (((Cik[7][2][0]*VWri[5][7][2])+((Cik[7][0][0]*
          VWri[5][7][0])+(Cik[7][1][0]*VWri[5][7][1])))+((rk[2][1]*Wpk[5][7][2])
          -(rk[2][2]*Wpk[5][7][1])));
        Vpk[5][7][1] = (((Cik[7][2][1]*VWri[5][7][2])+((Cik[7][0][1]*
          VWri[5][7][0])+(Cik[7][1][1]*VWri[5][7][1])))+((rk[2][2]*Wpk[5][7][0])
          -(rk[2][0]*Wpk[5][7][2])));
        Vpk[5][7][2] = (((Cik[7][2][2]*VWri[5][7][2])+((Cik[7][0][2]*
          VWri[5][7][0])+(Cik[7][1][2]*VWri[5][7][1])))+((rk[2][0]*Wpk[5][7][1])
          -(rk[2][1]*Wpk[5][7][0])));
        VWri[5][8][0] = (Vpk[5][7][0]+((ri[3][2]*Wpk[5][7][1])-(ri[3][1]*
          Wpk[5][7][2])));
        VWri[5][8][1] = (Vpk[5][7][1]+((ri[3][0]*Wpk[5][7][2])-(ri[3][2]*
          Wpk[5][7][0])));
        VWri[5][8][2] = (Vpk[5][7][2]+((ri[3][1]*Wpk[5][7][0])-(ri[3][0]*
          Wpk[5][7][1])));
        Vpk[5][8][0] = (((Cik[8][2][0]*VWri[5][8][2])+((Cik[8][0][0]*
          VWri[5][8][0])+(Cik[8][1][0]*VWri[5][8][1])))+((rk[3][1]*Wpk[5][8][2])
          -(rk[3][2]*Wpk[5][8][1])));
        Vpk[5][8][1] = (((Cik[8][2][1]*VWri[5][8][2])+((Cik[8][0][1]*
          VWri[5][8][0])+(Cik[8][1][1]*VWri[5][8][1])))+((rk[3][2]*Wpk[5][8][0])
          -(rk[3][0]*Wpk[5][8][2])));
        Vpk[5][8][2] = (((Cik[8][2][2]*VWri[5][8][2])+((Cik[8][0][2]*
          VWri[5][8][0])+(Cik[8][1][2]*VWri[5][8][1])))+((rk[3][0]*Wpk[5][8][1])
          -(rk[3][1]*Wpk[5][8][0])));
        VWri[5][9][0] = (Vpk[5][8][0]+((ri[4][2]*Wpk[5][8][1])-(ri[4][1]*
          Wpk[5][8][2])));
        VWri[5][9][1] = (Vpk[5][8][1]+((ri[4][0]*Wpk[5][8][2])-(ri[4][2]*
          Wpk[5][8][0])));
        VWri[5][9][2] = (Vpk[5][8][2]+((ri[4][1]*Wpk[5][8][0])-(ri[4][0]*
          Wpk[5][8][1])));
        Vpk[5][9][0] = (((Cik[9][2][0]*VWri[5][9][2])+((Cik[9][0][0]*
          VWri[5][9][0])+(Cik[9][1][0]*VWri[5][9][1])))+((psrk[9][1]*
          Wpk[5][9][2])-(psrk[9][2]*Wpk[5][9][1])));
        Vpk[5][9][1] = (((Cik[9][2][1]*VWri[5][9][2])+((Cik[9][0][1]*
          VWri[5][9][0])+(Cik[9][1][1]*VWri[5][9][1])))+((psrk[9][2]*
          Wpk[5][9][0])-(psrk[9][0]*Wpk[5][9][2])));
        Vpk[5][9][2] = (((Cik[9][2][2]*VWri[5][9][2])+((Cik[9][0][2]*
          VWri[5][9][0])+(Cik[9][1][2]*VWri[5][9][1])))+((psrk[9][0]*
          Wpk[5][9][1])-(psrk[9][1]*Wpk[5][9][0])));
        VWri[5][10][0] = (rk[0][1]-ri[6][1]);
        VWri[5][10][1] = (ri[6][0]-rk[0][0]);
        Vpk[5][10][0] = (((Cik[10][0][0]*VWri[5][10][0])+(Cik[10][1][0]*
          VWri[5][10][1]))+((Cik[10][2][2]*rk[6][1])-(Cik[10][2][1]*rk[6][2])));
        Vpk[5][10][1] = (((Cik[10][0][1]*VWri[5][10][0])+(Cik[10][1][1]*
          VWri[5][10][1]))+((Cik[10][2][0]*rk[6][2])-(Cik[10][2][2]*rk[6][0])));
        Vpk[5][10][2] = (((Cik[10][0][2]*VWri[5][10][0])+(Cik[10][1][2]*
          VWri[5][10][1]))+((Cik[10][2][1]*rk[6][0])-(Cik[10][2][0]*rk[6][1])));
        VWri[5][11][0] = (Vpk[5][10][0]+((Cik[10][2][1]*ri[7][2])-(Cik[10][2][2]
          *ri[7][1])));
        VWri[5][11][1] = (Vpk[5][10][1]+((Cik[10][2][2]*ri[7][0])-(Cik[10][2][0]
          *ri[7][2])));
        VWri[5][11][2] = (Vpk[5][10][2]+((Cik[10][2][0]*ri[7][1])-(Cik[10][2][1]
          *ri[7][0])));
        Vpk[5][11][0] = (((Cik[11][2][0]*VWri[5][11][2])+((Cik[11][0][0]*
          VWri[5][11][0])+(Cik[11][1][0]*VWri[5][11][1])))+((rk[7][1]*
          Wpk[5][11][2])-(rk[7][2]*Wpk[5][11][1])));
        Vpk[5][11][1] = (((Cik[11][2][1]*VWri[5][11][2])+((Cik[11][0][1]*
          VWri[5][11][0])+(Cik[11][1][1]*VWri[5][11][1])))+((rk[7][2]*
          Wpk[5][11][0])-(rk[7][0]*Wpk[5][11][2])));
        Vpk[5][11][2] = (((Cik[11][2][2]*VWri[5][11][2])+((Cik[11][0][2]*
          VWri[5][11][0])+(Cik[11][1][2]*VWri[5][11][1])))+((rk[7][0]*
          Wpk[5][11][1])-(rk[7][1]*Wpk[5][11][0])));
        VWri[5][12][0] = (Vpk[5][11][0]+((ri[8][2]*Wpk[5][11][1])-(ri[8][1]*
          Wpk[5][11][2])));
        VWri[5][12][1] = (Vpk[5][11][1]+((ri[8][0]*Wpk[5][11][2])-(ri[8][2]*
          Wpk[5][11][0])));
        VWri[5][12][2] = (Vpk[5][11][2]+((ri[8][1]*Wpk[5][11][0])-(ri[8][0]*
          Wpk[5][11][1])));
        Vpk[5][12][0] = (((Cik[12][2][0]*VWri[5][12][2])+((Cik[12][0][0]*
          VWri[5][12][0])+(Cik[12][1][0]*VWri[5][12][1])))+((rk[8][1]*
          Wpk[5][12][2])-(rk[8][2]*Wpk[5][12][1])));
        Vpk[5][12][1] = (((Cik[12][2][1]*VWri[5][12][2])+((Cik[12][0][1]*
          VWri[5][12][0])+(Cik[12][1][1]*VWri[5][12][1])))+((rk[8][2]*
          Wpk[5][12][0])-(rk[8][0]*Wpk[5][12][2])));
        Vpk[5][12][2] = (((Cik[12][2][2]*VWri[5][12][2])+((Cik[12][0][2]*
          VWri[5][12][0])+(Cik[12][1][2]*VWri[5][12][1])))+((rk[8][0]*
          Wpk[5][12][1])-(rk[8][1]*Wpk[5][12][0])));
        VWri[5][13][0] = (Vpk[5][12][0]+((ri[9][2]*Wpk[5][12][1])-(ri[9][1]*
          Wpk[5][12][2])));
        VWri[5][13][1] = (Vpk[5][12][1]+((ri[9][0]*Wpk[5][12][2])-(ri[9][2]*
          Wpk[5][12][0])));
        VWri[5][13][2] = (Vpk[5][12][2]+((ri[9][1]*Wpk[5][12][0])-(ri[9][0]*
          Wpk[5][12][1])));
        Vpk[5][13][0] = (((Cik[13][2][0]*VWri[5][13][2])+((Cik[13][0][0]*
          VWri[5][13][0])+(Cik[13][1][0]*VWri[5][13][1])))+((psrk[13][1]*
          Wpk[5][13][2])-(psrk[13][2]*Wpk[5][13][1])));
        Vpk[5][13][1] = (((Cik[13][2][1]*VWri[5][13][2])+((Cik[13][0][1]*
          VWri[5][13][0])+(Cik[13][1][1]*VWri[5][13][1])))+((psrk[13][2]*
          Wpk[5][13][0])-(psrk[13][0]*Wpk[5][13][2])));
        Vpk[5][13][2] = (((Cik[13][2][2]*VWri[5][13][2])+((Cik[13][0][2]*
          VWri[5][13][0])+(Cik[13][1][2]*VWri[5][13][1])))+((psrk[13][0]*
          Wpk[5][13][1])-(psrk[13][1]*Wpk[5][13][0])));
        VWri[5][14][0] = (rk[0][1]-ri[11][1]);
        VWri[5][14][1] = (ri[11][0]-rk[0][0]);
        Vpk[5][14][0] = (((Cik[14][0][0]*VWri[5][14][0])+(Cik[14][1][0]*
          VWri[5][14][1]))+((Cik[14][2][2]*rk[11][1])-(Cik[14][2][1]*rk[11][2]))
          );
        Vpk[5][14][1] = (((Cik[14][0][1]*VWri[5][14][0])+(Cik[14][1][1]*
          VWri[5][14][1]))+((Cik[14][2][0]*rk[11][2])-(Cik[14][2][2]*rk[11][0]))
          );
        Vpk[5][14][2] = (((Cik[14][0][2]*VWri[5][14][0])+(Cik[14][1][2]*
          VWri[5][14][1]))+((Cik[14][2][1]*rk[11][0])-(Cik[14][2][0]*rk[11][1]))
          );
        VWri[5][15][0] = (Vpk[5][14][0]+((Cik[14][2][1]*ri[12][2])-(
          Cik[14][2][2]*ri[12][1])));
        VWri[5][15][1] = (Vpk[5][14][1]+((Cik[14][2][2]*ri[12][0])-(
          Cik[14][2][0]*ri[12][2])));
        VWri[5][15][2] = (Vpk[5][14][2]+((Cik[14][2][0]*ri[12][1])-(
          Cik[14][2][1]*ri[12][0])));
        Vpk[5][15][0] = (((Cik[15][2][0]*VWri[5][15][2])+((Cik[15][0][0]*
          VWri[5][15][0])+(Cik[15][1][0]*VWri[5][15][1])))+((rk[12][1]*
          Wpk[5][15][2])-(rk[12][2]*Wpk[5][15][1])));
        Vpk[5][15][1] = (((Cik[15][2][1]*VWri[5][15][2])+((Cik[15][0][1]*
          VWri[5][15][0])+(Cik[15][1][1]*VWri[5][15][1])))+((rk[12][2]*
          Wpk[5][15][0])-(rk[12][0]*Wpk[5][15][2])));
        Vpk[5][15][2] = (((Cik[15][2][2]*VWri[5][15][2])+((Cik[15][0][2]*
          VWri[5][15][0])+(Cik[15][1][2]*VWri[5][15][1])))+((rk[12][0]*
          Wpk[5][15][1])-(rk[12][1]*Wpk[5][15][0])));
        VWri[5][16][0] = (Vpk[5][15][0]+((ri[13][2]*Wpk[5][15][1])-(ri[13][1]*
          Wpk[5][15][2])));
        VWri[5][16][1] = (Vpk[5][15][1]+((ri[13][0]*Wpk[5][15][2])-(ri[13][2]*
          Wpk[5][15][0])));
        VWri[5][16][2] = (Vpk[5][15][2]+((ri[13][1]*Wpk[5][15][0])-(ri[13][0]*
          Wpk[5][15][1])));
        Vpk[5][16][0] = (((Cik[16][2][0]*VWri[5][16][2])+((Cik[16][0][0]*
          VWri[5][16][0])+(Cik[16][1][0]*VWri[5][16][1])))+((rk[13][1]*
          Wpk[5][16][2])-(rk[13][2]*Wpk[5][16][1])));
        Vpk[5][16][1] = (((Cik[16][2][1]*VWri[5][16][2])+((Cik[16][0][1]*
          VWri[5][16][0])+(Cik[16][1][1]*VWri[5][16][1])))+((rk[13][2]*
          Wpk[5][16][0])-(rk[13][0]*Wpk[5][16][2])));
        Vpk[5][16][2] = (((Cik[16][2][2]*VWri[5][16][2])+((Cik[16][0][2]*
          VWri[5][16][0])+(Cik[16][1][2]*VWri[5][16][1])))+((rk[13][0]*
          Wpk[5][16][1])-(rk[13][1]*Wpk[5][16][0])));
        VWri[5][17][0] = (Vpk[5][16][0]+((ri[14][2]*Wpk[5][16][1])-(ri[14][1]*
          Wpk[5][16][2])));
        VWri[5][17][1] = (Vpk[5][16][1]+((ri[14][0]*Wpk[5][16][2])-(ri[14][2]*
          Wpk[5][16][0])));
        VWri[5][17][2] = (Vpk[5][16][2]+((ri[14][1]*Wpk[5][16][0])-(ri[14][0]*
          Wpk[5][16][1])));
        Vpk[5][17][0] = (((Cik[17][2][0]*VWri[5][17][2])+((Cik[17][0][0]*
          VWri[5][17][0])+(Cik[17][1][0]*VWri[5][17][1])))+((psrk[17][1]*
          Wpk[5][17][2])-(psrk[17][2]*Wpk[5][17][1])));
        Vpk[5][17][1] = (((Cik[17][2][1]*VWri[5][17][2])+((Cik[17][0][1]*
          VWri[5][17][0])+(Cik[17][1][1]*VWri[5][17][1])))+((psrk[17][2]*
          Wpk[5][17][0])-(psrk[17][0]*Wpk[5][17][2])));
        Vpk[5][17][2] = (((Cik[17][2][2]*VWri[5][17][2])+((Cik[17][0][2]*
          VWri[5][17][0])+(Cik[17][1][2]*VWri[5][17][1])))+((psrk[17][0]*
          Wpk[5][17][1])-(psrk[17][1]*Wpk[5][17][0])));
        VWri[5][18][0] = (rk[0][1]-ri[16][1]);
        VWri[5][18][1] = (ri[16][0]-rk[0][0]);
        Vpk[5][18][0] = (((Cik[18][0][0]*VWri[5][18][0])+(Cik[18][1][0]*
          VWri[5][18][1]))+((Cik[18][2][2]*rk[16][1])-(Cik[18][2][1]*rk[16][2]))
          );
        Vpk[5][18][1] = (((Cik[18][0][1]*VWri[5][18][0])+(Cik[18][1][1]*
          VWri[5][18][1]))+((Cik[18][2][0]*rk[16][2])-(Cik[18][2][2]*rk[16][0]))
          );
        Vpk[5][18][2] = (((Cik[18][0][2]*VWri[5][18][0])+(Cik[18][1][2]*
          VWri[5][18][1]))+((Cik[18][2][1]*rk[16][0])-(Cik[18][2][0]*rk[16][1]))
          );
        VWri[5][19][0] = (Vpk[5][18][0]+((Cik[18][2][1]*ri[17][2])-(
          Cik[18][2][2]*ri[17][1])));
        VWri[5][19][1] = (Vpk[5][18][1]+((Cik[18][2][2]*ri[17][0])-(
          Cik[18][2][0]*ri[17][2])));
        VWri[5][19][2] = (Vpk[5][18][2]+((Cik[18][2][0]*ri[17][1])-(
          Cik[18][2][1]*ri[17][0])));
        Vpk[5][19][0] = (((Cik[19][2][0]*VWri[5][19][2])+((Cik[19][0][0]*
          VWri[5][19][0])+(Cik[19][1][0]*VWri[5][19][1])))+((rk[17][1]*
          Wpk[5][19][2])-(rk[17][2]*Wpk[5][19][1])));
        Vpk[5][19][1] = (((Cik[19][2][1]*VWri[5][19][2])+((Cik[19][0][1]*
          VWri[5][19][0])+(Cik[19][1][1]*VWri[5][19][1])))+((rk[17][2]*
          Wpk[5][19][0])-(rk[17][0]*Wpk[5][19][2])));
        Vpk[5][19][2] = (((Cik[19][2][2]*VWri[5][19][2])+((Cik[19][0][2]*
          VWri[5][19][0])+(Cik[19][1][2]*VWri[5][19][1])))+((rk[17][0]*
          Wpk[5][19][1])-(rk[17][1]*Wpk[5][19][0])));
        VWri[5][20][0] = (Vpk[5][19][0]+((ri[18][2]*Wpk[5][19][1])-(ri[18][1]*
          Wpk[5][19][2])));
        VWri[5][20][1] = (Vpk[5][19][1]+((ri[18][0]*Wpk[5][19][2])-(ri[18][2]*
          Wpk[5][19][0])));
        VWri[5][20][2] = (Vpk[5][19][2]+((ri[18][1]*Wpk[5][19][0])-(ri[18][0]*
          Wpk[5][19][1])));
        Vpk[5][20][0] = (((Cik[20][2][0]*VWri[5][20][2])+((Cik[20][0][0]*
          VWri[5][20][0])+(Cik[20][1][0]*VWri[5][20][1])))+((rk[18][1]*
          Wpk[5][20][2])-(rk[18][2]*Wpk[5][20][1])));
        Vpk[5][20][1] = (((Cik[20][2][1]*VWri[5][20][2])+((Cik[20][0][1]*
          VWri[5][20][0])+(Cik[20][1][1]*VWri[5][20][1])))+((rk[18][2]*
          Wpk[5][20][0])-(rk[18][0]*Wpk[5][20][2])));
        Vpk[5][20][2] = (((Cik[20][2][2]*VWri[5][20][2])+((Cik[20][0][2]*
          VWri[5][20][0])+(Cik[20][1][2]*VWri[5][20][1])))+((rk[18][0]*
          Wpk[5][20][1])-(rk[18][1]*Wpk[5][20][0])));
        VWri[5][21][0] = (Vpk[5][20][0]+((ri[19][2]*Wpk[5][20][1])-(ri[19][1]*
          Wpk[5][20][2])));
        VWri[5][21][1] = (Vpk[5][20][1]+((ri[19][0]*Wpk[5][20][2])-(ri[19][2]*
          Wpk[5][20][0])));
        VWri[5][21][2] = (Vpk[5][20][2]+((ri[19][1]*Wpk[5][20][0])-(ri[19][0]*
          Wpk[5][20][1])));
        Vpk[5][21][0] = (((Cik[21][2][0]*VWri[5][21][2])+((Cik[21][0][0]*
          VWri[5][21][0])+(Cik[21][1][0]*VWri[5][21][1])))+((psrk[21][1]*
          Wpk[5][21][2])-(psrk[21][2]*Wpk[5][21][1])));
        Vpk[5][21][1] = (((Cik[21][2][1]*VWri[5][21][2])+((Cik[21][0][1]*
          VWri[5][21][0])+(Cik[21][1][1]*VWri[5][21][1])))+((psrk[21][2]*
          Wpk[5][21][0])-(psrk[21][0]*Wpk[5][21][2])));
        Vpk[5][21][2] = (((Cik[21][2][2]*VWri[5][21][2])+((Cik[21][0][2]*
          VWri[5][21][0])+(Cik[21][1][2]*VWri[5][21][1])))+((psrk[21][0]*
          Wpk[5][21][1])-(psrk[21][1]*Wpk[5][21][0])));
        Vpk[6][6][0] = ((pin[6][2]*rk[1][1])-(pin[6][1]*rk[1][2]));
        Vpk[6][6][1] = ((pin[6][0]*rk[1][2])-(pin[6][2]*rk[1][0]));
        Vpk[6][6][2] = ((pin[6][1]*rk[1][0])-(pin[6][0]*rk[1][1]));
        VWri[6][7][0] = (Vpk[6][6][0]+((pin[6][1]*ri[2][2])-(pin[6][2]*ri[2][1])
          ));
        VWri[6][7][1] = (Vpk[6][6][1]+((pin[6][2]*ri[2][0])-(pin[6][0]*ri[2][2])
          ));
        VWri[6][7][2] = (Vpk[6][6][2]+((pin[6][0]*ri[2][1])-(pin[6][1]*ri[2][0])
          ));
        Vpk[6][7][0] = (((Cik[7][2][0]*VWri[6][7][2])+((Cik[7][0][0]*
          VWri[6][7][0])+(Cik[7][1][0]*VWri[6][7][1])))+((rk[2][1]*Wpk[6][7][2])
          -(rk[2][2]*Wpk[6][7][1])));
        Vpk[6][7][1] = (((Cik[7][2][1]*VWri[6][7][2])+((Cik[7][0][1]*
          VWri[6][7][0])+(Cik[7][1][1]*VWri[6][7][1])))+((rk[2][2]*Wpk[6][7][0])
          -(rk[2][0]*Wpk[6][7][2])));
        Vpk[6][7][2] = (((Cik[7][2][2]*VWri[6][7][2])+((Cik[7][0][2]*
          VWri[6][7][0])+(Cik[7][1][2]*VWri[6][7][1])))+((rk[2][0]*Wpk[6][7][1])
          -(rk[2][1]*Wpk[6][7][0])));
        VWri[6][8][0] = (Vpk[6][7][0]+((ri[3][2]*Wpk[6][7][1])-(ri[3][1]*
          Wpk[6][7][2])));
        VWri[6][8][1] = (Vpk[6][7][1]+((ri[3][0]*Wpk[6][7][2])-(ri[3][2]*
          Wpk[6][7][0])));
        VWri[6][8][2] = (Vpk[6][7][2]+((ri[3][1]*Wpk[6][7][0])-(ri[3][0]*
          Wpk[6][7][1])));
        Vpk[6][8][0] = (((Cik[8][2][0]*VWri[6][8][2])+((Cik[8][0][0]*
          VWri[6][8][0])+(Cik[8][1][0]*VWri[6][8][1])))+((rk[3][1]*Wpk[6][8][2])
          -(rk[3][2]*Wpk[6][8][1])));
        Vpk[6][8][1] = (((Cik[8][2][1]*VWri[6][8][2])+((Cik[8][0][1]*
          VWri[6][8][0])+(Cik[8][1][1]*VWri[6][8][1])))+((rk[3][2]*Wpk[6][8][0])
          -(rk[3][0]*Wpk[6][8][2])));
        Vpk[6][8][2] = (((Cik[8][2][2]*VWri[6][8][2])+((Cik[8][0][2]*
          VWri[6][8][0])+(Cik[8][1][2]*VWri[6][8][1])))+((rk[3][0]*Wpk[6][8][1])
          -(rk[3][1]*Wpk[6][8][0])));
        VWri[6][9][0] = (Vpk[6][8][0]+((ri[4][2]*Wpk[6][8][1])-(ri[4][1]*
          Wpk[6][8][2])));
        VWri[6][9][1] = (Vpk[6][8][1]+((ri[4][0]*Wpk[6][8][2])-(ri[4][2]*
          Wpk[6][8][0])));
        VWri[6][9][2] = (Vpk[6][8][2]+((ri[4][1]*Wpk[6][8][0])-(ri[4][0]*
          Wpk[6][8][1])));
        Vpk[6][9][0] = (((Cik[9][2][0]*VWri[6][9][2])+((Cik[9][0][0]*
          VWri[6][9][0])+(Cik[9][1][0]*VWri[6][9][1])))+((psrk[9][1]*
          Wpk[6][9][2])-(psrk[9][2]*Wpk[6][9][1])));
        Vpk[6][9][1] = (((Cik[9][2][1]*VWri[6][9][2])+((Cik[9][0][1]*
          VWri[6][9][0])+(Cik[9][1][1]*VWri[6][9][1])))+((psrk[9][2]*
          Wpk[6][9][0])-(psrk[9][0]*Wpk[6][9][2])));
        Vpk[6][9][2] = (((Cik[9][2][2]*VWri[6][9][2])+((Cik[9][0][2]*
          VWri[6][9][0])+(Cik[9][1][2]*VWri[6][9][1])))+((psrk[9][0]*
          Wpk[6][9][1])-(psrk[9][1]*Wpk[6][9][0])));
        Vpk[7][7][0] = ((pin[7][2]*rk[2][1])-(pin[7][1]*rk[2][2]));
        Vpk[7][7][1] = ((pin[7][0]*rk[2][2])-(pin[7][2]*rk[2][0]));
        Vpk[7][7][2] = ((pin[7][1]*rk[2][0])-(pin[7][0]*rk[2][1]));
        VWri[7][8][0] = (Vpk[7][7][0]+((pin[7][1]*ri[3][2])-(pin[7][2]*ri[3][1])
          ));
        VWri[7][8][1] = (Vpk[7][7][1]+((pin[7][2]*ri[3][0])-(pin[7][0]*ri[3][2])
          ));
        VWri[7][8][2] = (Vpk[7][7][2]+((pin[7][0]*ri[3][1])-(pin[7][1]*ri[3][0])
          ));
        Vpk[7][8][0] = (((Cik[8][2][0]*VWri[7][8][2])+((Cik[8][0][0]*
          VWri[7][8][0])+(Cik[8][1][0]*VWri[7][8][1])))+((rk[3][1]*Wpk[7][8][2])
          -(rk[3][2]*Wpk[7][8][1])));
        Vpk[7][8][1] = (((Cik[8][2][1]*VWri[7][8][2])+((Cik[8][0][1]*
          VWri[7][8][0])+(Cik[8][1][1]*VWri[7][8][1])))+((rk[3][2]*Wpk[7][8][0])
          -(rk[3][0]*Wpk[7][8][2])));
        Vpk[7][8][2] = (((Cik[8][2][2]*VWri[7][8][2])+((Cik[8][0][2]*
          VWri[7][8][0])+(Cik[8][1][2]*VWri[7][8][1])))+((rk[3][0]*Wpk[7][8][1])
          -(rk[3][1]*Wpk[7][8][0])));
        VWri[7][9][0] = (Vpk[7][8][0]+((ri[4][2]*Wpk[7][8][1])-(ri[4][1]*
          Wpk[7][8][2])));
        VWri[7][9][1] = (Vpk[7][8][1]+((ri[4][0]*Wpk[7][8][2])-(ri[4][2]*
          Wpk[7][8][0])));
        VWri[7][9][2] = (Vpk[7][8][2]+((ri[4][1]*Wpk[7][8][0])-(ri[4][0]*
          Wpk[7][8][1])));
        Vpk[7][9][0] = (((Cik[9][2][0]*VWri[7][9][2])+((Cik[9][0][0]*
          VWri[7][9][0])+(Cik[9][1][0]*VWri[7][9][1])))+((psrk[9][1]*
          Wpk[7][9][2])-(psrk[9][2]*Wpk[7][9][1])));
        Vpk[7][9][1] = (((Cik[9][2][1]*VWri[7][9][2])+((Cik[9][0][1]*
          VWri[7][9][0])+(Cik[9][1][1]*VWri[7][9][1])))+((psrk[9][2]*
          Wpk[7][9][0])-(psrk[9][0]*Wpk[7][9][2])));
        Vpk[7][9][2] = (((Cik[9][2][2]*VWri[7][9][2])+((Cik[9][0][2]*
          VWri[7][9][0])+(Cik[9][1][2]*VWri[7][9][1])))+((psrk[9][0]*
          Wpk[7][9][1])-(psrk[9][1]*Wpk[7][9][0])));
        Vpk[8][8][0] = ((pin[8][2]*rk[3][1])-(pin[8][1]*rk[3][2]));
        Vpk[8][8][1] = ((pin[8][0]*rk[3][2])-(pin[8][2]*rk[3][0]));
        Vpk[8][8][2] = ((pin[8][1]*rk[3][0])-(pin[8][0]*rk[3][1]));
        VWri[8][9][0] = (Vpk[8][8][0]+((pin[8][1]*ri[4][2])-(pin[8][2]*ri[4][1])
          ));
        VWri[8][9][1] = (Vpk[8][8][1]+((pin[8][2]*ri[4][0])-(pin[8][0]*ri[4][2])
          ));
        VWri[8][9][2] = (Vpk[8][8][2]+((pin[8][0]*ri[4][1])-(pin[8][1]*ri[4][0])
          ));
        Vpk[8][9][0] = (((Cik[9][2][0]*VWri[8][9][2])+((Cik[9][0][0]*
          VWri[8][9][0])+(Cik[9][1][0]*VWri[8][9][1])))+((psrk[9][1]*
          Wpk[8][9][2])-(psrk[9][2]*Wpk[8][9][1])));
        Vpk[8][9][1] = (((Cik[9][2][1]*VWri[8][9][2])+((Cik[9][0][1]*
          VWri[8][9][0])+(Cik[9][1][1]*VWri[8][9][1])))+((psrk[9][2]*
          Wpk[8][9][0])-(psrk[9][0]*Wpk[8][9][2])));
        Vpk[8][9][2] = (((Cik[9][2][2]*VWri[8][9][2])+((Cik[9][0][2]*
          VWri[8][9][0])+(Cik[9][1][2]*VWri[8][9][1])))+((psrk[9][0]*
          Wpk[8][9][1])-(psrk[9][1]*Wpk[8][9][0])));
        Vpk[9][9][0] = ((pin[9][2]*psrk[9][1])-(pin[9][1]*psrk[9][2]));
        Vpk[9][9][1] = ((pin[9][0]*psrk[9][2])-(pin[9][2]*psrk[9][0]));
        Vpk[9][9][2] = ((pin[9][1]*psrk[9][0])-(pin[9][0]*psrk[9][1]));
        Vpk[10][10][0] = ((pin[10][2]*rk[6][1])-(pin[10][1]*rk[6][2]));
        Vpk[10][10][1] = ((pin[10][0]*rk[6][2])-(pin[10][2]*rk[6][0]));
        Vpk[10][10][2] = ((pin[10][1]*rk[6][0])-(pin[10][0]*rk[6][1]));
        VWri[10][11][0] = (Vpk[10][10][0]+((pin[10][1]*ri[7][2])-(pin[10][2]*
          ri[7][1])));
        VWri[10][11][1] = (Vpk[10][10][1]+((pin[10][2]*ri[7][0])-(pin[10][0]*
          ri[7][2])));
        VWri[10][11][2] = (Vpk[10][10][2]+((pin[10][0]*ri[7][1])-(pin[10][1]*
          ri[7][0])));
        Vpk[10][11][0] = (((Cik[11][2][0]*VWri[10][11][2])+((Cik[11][0][0]*
          VWri[10][11][0])+(Cik[11][1][0]*VWri[10][11][1])))+((rk[7][1]*
          Wpk[10][11][2])-(rk[7][2]*Wpk[10][11][1])));
        Vpk[10][11][1] = (((Cik[11][2][1]*VWri[10][11][2])+((Cik[11][0][1]*
          VWri[10][11][0])+(Cik[11][1][1]*VWri[10][11][1])))+((rk[7][2]*
          Wpk[10][11][0])-(rk[7][0]*Wpk[10][11][2])));
        Vpk[10][11][2] = (((Cik[11][2][2]*VWri[10][11][2])+((Cik[11][0][2]*
          VWri[10][11][0])+(Cik[11][1][2]*VWri[10][11][1])))+((rk[7][0]*
          Wpk[10][11][1])-(rk[7][1]*Wpk[10][11][0])));
        VWri[10][12][0] = (Vpk[10][11][0]+((ri[8][2]*Wpk[10][11][1])-(ri[8][1]*
          Wpk[10][11][2])));
        VWri[10][12][1] = (Vpk[10][11][1]+((ri[8][0]*Wpk[10][11][2])-(ri[8][2]*
          Wpk[10][11][0])));
        VWri[10][12][2] = (Vpk[10][11][2]+((ri[8][1]*Wpk[10][11][0])-(ri[8][0]*
          Wpk[10][11][1])));
        Vpk[10][12][0] = (((Cik[12][2][0]*VWri[10][12][2])+((Cik[12][0][0]*
          VWri[10][12][0])+(Cik[12][1][0]*VWri[10][12][1])))+((rk[8][1]*
          Wpk[10][12][2])-(rk[8][2]*Wpk[10][12][1])));
        Vpk[10][12][1] = (((Cik[12][2][1]*VWri[10][12][2])+((Cik[12][0][1]*
          VWri[10][12][0])+(Cik[12][1][1]*VWri[10][12][1])))+((rk[8][2]*
          Wpk[10][12][0])-(rk[8][0]*Wpk[10][12][2])));
        Vpk[10][12][2] = (((Cik[12][2][2]*VWri[10][12][2])+((Cik[12][0][2]*
          VWri[10][12][0])+(Cik[12][1][2]*VWri[10][12][1])))+((rk[8][0]*
          Wpk[10][12][1])-(rk[8][1]*Wpk[10][12][0])));
        VWri[10][13][0] = (Vpk[10][12][0]+((ri[9][2]*Wpk[10][12][1])-(ri[9][1]*
          Wpk[10][12][2])));
        VWri[10][13][1] = (Vpk[10][12][1]+((ri[9][0]*Wpk[10][12][2])-(ri[9][2]*
          Wpk[10][12][0])));
        VWri[10][13][2] = (Vpk[10][12][2]+((ri[9][1]*Wpk[10][12][0])-(ri[9][0]*
          Wpk[10][12][1])));
        Vpk[10][13][0] = (((Cik[13][2][0]*VWri[10][13][2])+((Cik[13][0][0]*
          VWri[10][13][0])+(Cik[13][1][0]*VWri[10][13][1])))+((psrk[13][1]*
          Wpk[10][13][2])-(psrk[13][2]*Wpk[10][13][1])));
        Vpk[10][13][1] = (((Cik[13][2][1]*VWri[10][13][2])+((Cik[13][0][1]*
          VWri[10][13][0])+(Cik[13][1][1]*VWri[10][13][1])))+((psrk[13][2]*
          Wpk[10][13][0])-(psrk[13][0]*Wpk[10][13][2])));
        Vpk[10][13][2] = (((Cik[13][2][2]*VWri[10][13][2])+((Cik[13][0][2]*
          VWri[10][13][0])+(Cik[13][1][2]*VWri[10][13][1])))+((psrk[13][0]*
          Wpk[10][13][1])-(psrk[13][1]*Wpk[10][13][0])));
        Vpk[11][11][0] = ((pin[11][2]*rk[7][1])-(pin[11][1]*rk[7][2]));
        Vpk[11][11][1] = ((pin[11][0]*rk[7][2])-(pin[11][2]*rk[7][0]));
        Vpk[11][11][2] = ((pin[11][1]*rk[7][0])-(pin[11][0]*rk[7][1]));
        VWri[11][12][0] = (Vpk[11][11][0]+((pin[11][1]*ri[8][2])-(pin[11][2]*
          ri[8][1])));
        VWri[11][12][1] = (Vpk[11][11][1]+((pin[11][2]*ri[8][0])-(pin[11][0]*
          ri[8][2])));
        VWri[11][12][2] = (Vpk[11][11][2]+((pin[11][0]*ri[8][1])-(pin[11][1]*
          ri[8][0])));
        Vpk[11][12][0] = (((Cik[12][2][0]*VWri[11][12][2])+((Cik[12][0][0]*
          VWri[11][12][0])+(Cik[12][1][0]*VWri[11][12][1])))+((rk[8][1]*
          Wpk[11][12][2])-(rk[8][2]*Wpk[11][12][1])));
        Vpk[11][12][1] = (((Cik[12][2][1]*VWri[11][12][2])+((Cik[12][0][1]*
          VWri[11][12][0])+(Cik[12][1][1]*VWri[11][12][1])))+((rk[8][2]*
          Wpk[11][12][0])-(rk[8][0]*Wpk[11][12][2])));
        Vpk[11][12][2] = (((Cik[12][2][2]*VWri[11][12][2])+((Cik[12][0][2]*
          VWri[11][12][0])+(Cik[12][1][2]*VWri[11][12][1])))+((rk[8][0]*
          Wpk[11][12][1])-(rk[8][1]*Wpk[11][12][0])));
        VWri[11][13][0] = (Vpk[11][12][0]+((ri[9][2]*Wpk[11][12][1])-(ri[9][1]*
          Wpk[11][12][2])));
        VWri[11][13][1] = (Vpk[11][12][1]+((ri[9][0]*Wpk[11][12][2])-(ri[9][2]*
          Wpk[11][12][0])));
        VWri[11][13][2] = (Vpk[11][12][2]+((ri[9][1]*Wpk[11][12][0])-(ri[9][0]*
          Wpk[11][12][1])));
        Vpk[11][13][0] = (((Cik[13][2][0]*VWri[11][13][2])+((Cik[13][0][0]*
          VWri[11][13][0])+(Cik[13][1][0]*VWri[11][13][1])))+((psrk[13][1]*
          Wpk[11][13][2])-(psrk[13][2]*Wpk[11][13][1])));
        Vpk[11][13][1] = (((Cik[13][2][1]*VWri[11][13][2])+((Cik[13][0][1]*
          VWri[11][13][0])+(Cik[13][1][1]*VWri[11][13][1])))+((psrk[13][2]*
          Wpk[11][13][0])-(psrk[13][0]*Wpk[11][13][2])));
        Vpk[11][13][2] = (((Cik[13][2][2]*VWri[11][13][2])+((Cik[13][0][2]*
          VWri[11][13][0])+(Cik[13][1][2]*VWri[11][13][1])))+((psrk[13][0]*
          Wpk[11][13][1])-(psrk[13][1]*Wpk[11][13][0])));
        Vpk[12][12][0] = ((pin[12][2]*rk[8][1])-(pin[12][1]*rk[8][2]));
        Vpk[12][12][1] = ((pin[12][0]*rk[8][2])-(pin[12][2]*rk[8][0]));
        Vpk[12][12][2] = ((pin[12][1]*rk[8][0])-(pin[12][0]*rk[8][1]));
        VWri[12][13][0] = (Vpk[12][12][0]+((pin[12][1]*ri[9][2])-(pin[12][2]*
          ri[9][1])));
        VWri[12][13][1] = (Vpk[12][12][1]+((pin[12][2]*ri[9][0])-(pin[12][0]*
          ri[9][2])));
        VWri[12][13][2] = (Vpk[12][12][2]+((pin[12][0]*ri[9][1])-(pin[12][1]*
          ri[9][0])));
        Vpk[12][13][0] = (((Cik[13][2][0]*VWri[12][13][2])+((Cik[13][0][0]*
          VWri[12][13][0])+(Cik[13][1][0]*VWri[12][13][1])))+((psrk[13][1]*
          Wpk[12][13][2])-(psrk[13][2]*Wpk[12][13][1])));
        Vpk[12][13][1] = (((Cik[13][2][1]*VWri[12][13][2])+((Cik[13][0][1]*
          VWri[12][13][0])+(Cik[13][1][1]*VWri[12][13][1])))+((psrk[13][2]*
          Wpk[12][13][0])-(psrk[13][0]*Wpk[12][13][2])));
        Vpk[12][13][2] = (((Cik[13][2][2]*VWri[12][13][2])+((Cik[13][0][2]*
          VWri[12][13][0])+(Cik[13][1][2]*VWri[12][13][1])))+((psrk[13][0]*
          Wpk[12][13][1])-(psrk[13][1]*Wpk[12][13][0])));
        Vpk[13][13][0] = ((pin[13][2]*psrk[13][1])-(pin[13][1]*psrk[13][2]));
        Vpk[13][13][1] = ((pin[13][0]*psrk[13][2])-(pin[13][2]*psrk[13][0]));
        Vpk[13][13][2] = ((pin[13][1]*psrk[13][0])-(pin[13][0]*psrk[13][1]));
        Vpk[14][14][0] = ((pin[14][2]*rk[11][1])-(pin[14][1]*rk[11][2]));
        Vpk[14][14][1] = ((pin[14][0]*rk[11][2])-(pin[14][2]*rk[11][0]));
        Vpk[14][14][2] = ((pin[14][1]*rk[11][0])-(pin[14][0]*rk[11][1]));
        VWri[14][15][0] = (Vpk[14][14][0]+((pin[14][1]*ri[12][2])-(pin[14][2]*
          ri[12][1])));
        VWri[14][15][1] = (Vpk[14][14][1]+((pin[14][2]*ri[12][0])-(pin[14][0]*
          ri[12][2])));
        VWri[14][15][2] = (Vpk[14][14][2]+((pin[14][0]*ri[12][1])-(pin[14][1]*
          ri[12][0])));
        Vpk[14][15][0] = (((Cik[15][2][0]*VWri[14][15][2])+((Cik[15][0][0]*
          VWri[14][15][0])+(Cik[15][1][0]*VWri[14][15][1])))+((rk[12][1]*
          Wpk[14][15][2])-(rk[12][2]*Wpk[14][15][1])));
        Vpk[14][15][1] = (((Cik[15][2][1]*VWri[14][15][2])+((Cik[15][0][1]*
          VWri[14][15][0])+(Cik[15][1][1]*VWri[14][15][1])))+((rk[12][2]*
          Wpk[14][15][0])-(rk[12][0]*Wpk[14][15][2])));
        Vpk[14][15][2] = (((Cik[15][2][2]*VWri[14][15][2])+((Cik[15][0][2]*
          VWri[14][15][0])+(Cik[15][1][2]*VWri[14][15][1])))+((rk[12][0]*
          Wpk[14][15][1])-(rk[12][1]*Wpk[14][15][0])));
        VWri[14][16][0] = (Vpk[14][15][0]+((ri[13][2]*Wpk[14][15][1])-(ri[13][1]
          *Wpk[14][15][2])));
        VWri[14][16][1] = (Vpk[14][15][1]+((ri[13][0]*Wpk[14][15][2])-(ri[13][2]
          *Wpk[14][15][0])));
        VWri[14][16][2] = (Vpk[14][15][2]+((ri[13][1]*Wpk[14][15][0])-(ri[13][0]
          *Wpk[14][15][1])));
        Vpk[14][16][0] = (((Cik[16][2][0]*VWri[14][16][2])+((Cik[16][0][0]*
          VWri[14][16][0])+(Cik[16][1][0]*VWri[14][16][1])))+((rk[13][1]*
          Wpk[14][16][2])-(rk[13][2]*Wpk[14][16][1])));
        Vpk[14][16][1] = (((Cik[16][2][1]*VWri[14][16][2])+((Cik[16][0][1]*
          VWri[14][16][0])+(Cik[16][1][1]*VWri[14][16][1])))+((rk[13][2]*
          Wpk[14][16][0])-(rk[13][0]*Wpk[14][16][2])));
        Vpk[14][16][2] = (((Cik[16][2][2]*VWri[14][16][2])+((Cik[16][0][2]*
          VWri[14][16][0])+(Cik[16][1][2]*VWri[14][16][1])))+((rk[13][0]*
          Wpk[14][16][1])-(rk[13][1]*Wpk[14][16][0])));
        VWri[14][17][0] = (Vpk[14][16][0]+((ri[14][2]*Wpk[14][16][1])-(ri[14][1]
          *Wpk[14][16][2])));
        VWri[14][17][1] = (Vpk[14][16][1]+((ri[14][0]*Wpk[14][16][2])-(ri[14][2]
          *Wpk[14][16][0])));
        VWri[14][17][2] = (Vpk[14][16][2]+((ri[14][1]*Wpk[14][16][0])-(ri[14][0]
          *Wpk[14][16][1])));
        Vpk[14][17][0] = (((Cik[17][2][0]*VWri[14][17][2])+((Cik[17][0][0]*
          VWri[14][17][0])+(Cik[17][1][0]*VWri[14][17][1])))+((psrk[17][1]*
          Wpk[14][17][2])-(psrk[17][2]*Wpk[14][17][1])));
        Vpk[14][17][1] = (((Cik[17][2][1]*VWri[14][17][2])+((Cik[17][0][1]*
          VWri[14][17][0])+(Cik[17][1][1]*VWri[14][17][1])))+((psrk[17][2]*
          Wpk[14][17][0])-(psrk[17][0]*Wpk[14][17][2])));
        Vpk[14][17][2] = (((Cik[17][2][2]*VWri[14][17][2])+((Cik[17][0][2]*
          VWri[14][17][0])+(Cik[17][1][2]*VWri[14][17][1])))+((psrk[17][0]*
          Wpk[14][17][1])-(psrk[17][1]*Wpk[14][17][0])));
        Vpk[15][15][0] = ((pin[15][2]*rk[12][1])-(pin[15][1]*rk[12][2]));
        Vpk[15][15][1] = ((pin[15][0]*rk[12][2])-(pin[15][2]*rk[12][0]));
        Vpk[15][15][2] = ((pin[15][1]*rk[12][0])-(pin[15][0]*rk[12][1]));
        VWri[15][16][0] = (Vpk[15][15][0]+((pin[15][1]*ri[13][2])-(pin[15][2]*
          ri[13][1])));
        VWri[15][16][1] = (Vpk[15][15][1]+((pin[15][2]*ri[13][0])-(pin[15][0]*
          ri[13][2])));
        VWri[15][16][2] = (Vpk[15][15][2]+((pin[15][0]*ri[13][1])-(pin[15][1]*
          ri[13][0])));
        Vpk[15][16][0] = (((Cik[16][2][0]*VWri[15][16][2])+((Cik[16][0][0]*
          VWri[15][16][0])+(Cik[16][1][0]*VWri[15][16][1])))+((rk[13][1]*
          Wpk[15][16][2])-(rk[13][2]*Wpk[15][16][1])));
        Vpk[15][16][1] = (((Cik[16][2][1]*VWri[15][16][2])+((Cik[16][0][1]*
          VWri[15][16][0])+(Cik[16][1][1]*VWri[15][16][1])))+((rk[13][2]*
          Wpk[15][16][0])-(rk[13][0]*Wpk[15][16][2])));
        Vpk[15][16][2] = (((Cik[16][2][2]*VWri[15][16][2])+((Cik[16][0][2]*
          VWri[15][16][0])+(Cik[16][1][2]*VWri[15][16][1])))+((rk[13][0]*
          Wpk[15][16][1])-(rk[13][1]*Wpk[15][16][0])));
        VWri[15][17][0] = (Vpk[15][16][0]+((ri[14][2]*Wpk[15][16][1])-(ri[14][1]
          *Wpk[15][16][2])));
        VWri[15][17][1] = (Vpk[15][16][1]+((ri[14][0]*Wpk[15][16][2])-(ri[14][2]
          *Wpk[15][16][0])));
        VWri[15][17][2] = (Vpk[15][16][2]+((ri[14][1]*Wpk[15][16][0])-(ri[14][0]
          *Wpk[15][16][1])));
        Vpk[15][17][0] = (((Cik[17][2][0]*VWri[15][17][2])+((Cik[17][0][0]*
          VWri[15][17][0])+(Cik[17][1][0]*VWri[15][17][1])))+((psrk[17][1]*
          Wpk[15][17][2])-(psrk[17][2]*Wpk[15][17][1])));
        Vpk[15][17][1] = (((Cik[17][2][1]*VWri[15][17][2])+((Cik[17][0][1]*
          VWri[15][17][0])+(Cik[17][1][1]*VWri[15][17][1])))+((psrk[17][2]*
          Wpk[15][17][0])-(psrk[17][0]*Wpk[15][17][2])));
        Vpk[15][17][2] = (((Cik[17][2][2]*VWri[15][17][2])+((Cik[17][0][2]*
          VWri[15][17][0])+(Cik[17][1][2]*VWri[15][17][1])))+((psrk[17][0]*
          Wpk[15][17][1])-(psrk[17][1]*Wpk[15][17][0])));
        Vpk[16][16][0] = ((pin[16][2]*rk[13][1])-(pin[16][1]*rk[13][2]));
        Vpk[16][16][1] = ((pin[16][0]*rk[13][2])-(pin[16][2]*rk[13][0]));
        Vpk[16][16][2] = ((pin[16][1]*rk[13][0])-(pin[16][0]*rk[13][1]));
        VWri[16][17][0] = (Vpk[16][16][0]+((pin[16][1]*ri[14][2])-(pin[16][2]*
          ri[14][1])));
        VWri[16][17][1] = (Vpk[16][16][1]+((pin[16][2]*ri[14][0])-(pin[16][0]*
          ri[14][2])));
        VWri[16][17][2] = (Vpk[16][16][2]+((pin[16][0]*ri[14][1])-(pin[16][1]*
          ri[14][0])));
        Vpk[16][17][0] = (((Cik[17][2][0]*VWri[16][17][2])+((Cik[17][0][0]*
          VWri[16][17][0])+(Cik[17][1][0]*VWri[16][17][1])))+((psrk[17][1]*
          Wpk[16][17][2])-(psrk[17][2]*Wpk[16][17][1])));
        Vpk[16][17][1] = (((Cik[17][2][1]*VWri[16][17][2])+((Cik[17][0][1]*
          VWri[16][17][0])+(Cik[17][1][1]*VWri[16][17][1])))+((psrk[17][2]*
          Wpk[16][17][0])-(psrk[17][0]*Wpk[16][17][2])));
        Vpk[16][17][2] = (((Cik[17][2][2]*VWri[16][17][2])+((Cik[17][0][2]*
          VWri[16][17][0])+(Cik[17][1][2]*VWri[16][17][1])))+((psrk[17][0]*
          Wpk[16][17][1])-(psrk[17][1]*Wpk[16][17][0])));
        Vpk[17][17][0] = ((pin[17][2]*psrk[17][1])-(pin[17][1]*psrk[17][2]));
        Vpk[17][17][1] = ((pin[17][0]*psrk[17][2])-(pin[17][2]*psrk[17][0]));
        Vpk[17][17][2] = ((pin[17][1]*psrk[17][0])-(pin[17][0]*psrk[17][1]));
        Vpk[18][18][0] = ((pin[18][2]*rk[16][1])-(pin[18][1]*rk[16][2]));
        Vpk[18][18][1] = ((pin[18][0]*rk[16][2])-(pin[18][2]*rk[16][0]));
        Vpk[18][18][2] = ((pin[18][1]*rk[16][0])-(pin[18][0]*rk[16][1]));
        VWri[18][19][0] = (Vpk[18][18][0]+((pin[18][1]*ri[17][2])-(pin[18][2]*
          ri[17][1])));
        VWri[18][19][1] = (Vpk[18][18][1]+((pin[18][2]*ri[17][0])-(pin[18][0]*
          ri[17][2])));
        VWri[18][19][2] = (Vpk[18][18][2]+((pin[18][0]*ri[17][1])-(pin[18][1]*
          ri[17][0])));
        Vpk[18][19][0] = (((Cik[19][2][0]*VWri[18][19][2])+((Cik[19][0][0]*
          VWri[18][19][0])+(Cik[19][1][0]*VWri[18][19][1])))+((rk[17][1]*
          Wpk[18][19][2])-(rk[17][2]*Wpk[18][19][1])));
        Vpk[18][19][1] = (((Cik[19][2][1]*VWri[18][19][2])+((Cik[19][0][1]*
          VWri[18][19][0])+(Cik[19][1][1]*VWri[18][19][1])))+((rk[17][2]*
          Wpk[18][19][0])-(rk[17][0]*Wpk[18][19][2])));
        Vpk[18][19][2] = (((Cik[19][2][2]*VWri[18][19][2])+((Cik[19][0][2]*
          VWri[18][19][0])+(Cik[19][1][2]*VWri[18][19][1])))+((rk[17][0]*
          Wpk[18][19][1])-(rk[17][1]*Wpk[18][19][0])));
        VWri[18][20][0] = (Vpk[18][19][0]+((ri[18][2]*Wpk[18][19][1])-(ri[18][1]
          *Wpk[18][19][2])));
        VWri[18][20][1] = (Vpk[18][19][1]+((ri[18][0]*Wpk[18][19][2])-(ri[18][2]
          *Wpk[18][19][0])));
        VWri[18][20][2] = (Vpk[18][19][2]+((ri[18][1]*Wpk[18][19][0])-(ri[18][0]
          *Wpk[18][19][1])));
        Vpk[18][20][0] = (((Cik[20][2][0]*VWri[18][20][2])+((Cik[20][0][0]*
          VWri[18][20][0])+(Cik[20][1][0]*VWri[18][20][1])))+((rk[18][1]*
          Wpk[18][20][2])-(rk[18][2]*Wpk[18][20][1])));
        Vpk[18][20][1] = (((Cik[20][2][1]*VWri[18][20][2])+((Cik[20][0][1]*
          VWri[18][20][0])+(Cik[20][1][1]*VWri[18][20][1])))+((rk[18][2]*
          Wpk[18][20][0])-(rk[18][0]*Wpk[18][20][2])));
        Vpk[18][20][2] = (((Cik[20][2][2]*VWri[18][20][2])+((Cik[20][0][2]*
          VWri[18][20][0])+(Cik[20][1][2]*VWri[18][20][1])))+((rk[18][0]*
          Wpk[18][20][1])-(rk[18][1]*Wpk[18][20][0])));
        VWri[18][21][0] = (Vpk[18][20][0]+((ri[19][2]*Wpk[18][20][1])-(ri[19][1]
          *Wpk[18][20][2])));
        VWri[18][21][1] = (Vpk[18][20][1]+((ri[19][0]*Wpk[18][20][2])-(ri[19][2]
          *Wpk[18][20][0])));
        VWri[18][21][2] = (Vpk[18][20][2]+((ri[19][1]*Wpk[18][20][0])-(ri[19][0]
          *Wpk[18][20][1])));
        Vpk[18][21][0] = (((Cik[21][2][0]*VWri[18][21][2])+((Cik[21][0][0]*
          VWri[18][21][0])+(Cik[21][1][0]*VWri[18][21][1])))+((psrk[21][1]*
          Wpk[18][21][2])-(psrk[21][2]*Wpk[18][21][1])));
        Vpk[18][21][1] = (((Cik[21][2][1]*VWri[18][21][2])+((Cik[21][0][1]*
          VWri[18][21][0])+(Cik[21][1][1]*VWri[18][21][1])))+((psrk[21][2]*
          Wpk[18][21][0])-(psrk[21][0]*Wpk[18][21][2])));
        Vpk[18][21][2] = (((Cik[21][2][2]*VWri[18][21][2])+((Cik[21][0][2]*
          VWri[18][21][0])+(Cik[21][1][2]*VWri[18][21][1])))+((psrk[21][0]*
          Wpk[18][21][1])-(psrk[21][1]*Wpk[18][21][0])));
        Vpk[19][19][0] = ((pin[19][2]*rk[17][1])-(pin[19][1]*rk[17][2]));
        Vpk[19][19][1] = ((pin[19][0]*rk[17][2])-(pin[19][2]*rk[17][0]));
        Vpk[19][19][2] = ((pin[19][1]*rk[17][0])-(pin[19][0]*rk[17][1]));
        VWri[19][20][0] = (Vpk[19][19][0]+((pin[19][1]*ri[18][2])-(pin[19][2]*
          ri[18][1])));
        VWri[19][20][1] = (Vpk[19][19][1]+((pin[19][2]*ri[18][0])-(pin[19][0]*
          ri[18][2])));
        VWri[19][20][2] = (Vpk[19][19][2]+((pin[19][0]*ri[18][1])-(pin[19][1]*
          ri[18][0])));
        Vpk[19][20][0] = (((Cik[20][2][0]*VWri[19][20][2])+((Cik[20][0][0]*
          VWri[19][20][0])+(Cik[20][1][0]*VWri[19][20][1])))+((rk[18][1]*
          Wpk[19][20][2])-(rk[18][2]*Wpk[19][20][1])));
        Vpk[19][20][1] = (((Cik[20][2][1]*VWri[19][20][2])+((Cik[20][0][1]*
          VWri[19][20][0])+(Cik[20][1][1]*VWri[19][20][1])))+((rk[18][2]*
          Wpk[19][20][0])-(rk[18][0]*Wpk[19][20][2])));
        Vpk[19][20][2] = (((Cik[20][2][2]*VWri[19][20][2])+((Cik[20][0][2]*
          VWri[19][20][0])+(Cik[20][1][2]*VWri[19][20][1])))+((rk[18][0]*
          Wpk[19][20][1])-(rk[18][1]*Wpk[19][20][0])));
        VWri[19][21][0] = (Vpk[19][20][0]+((ri[19][2]*Wpk[19][20][1])-(ri[19][1]
          *Wpk[19][20][2])));
        VWri[19][21][1] = (Vpk[19][20][1]+((ri[19][0]*Wpk[19][20][2])-(ri[19][2]
          *Wpk[19][20][0])));
        VWri[19][21][2] = (Vpk[19][20][2]+((ri[19][1]*Wpk[19][20][0])-(ri[19][0]
          *Wpk[19][20][1])));
        Vpk[19][21][0] = (((Cik[21][2][0]*VWri[19][21][2])+((Cik[21][0][0]*
          VWri[19][21][0])+(Cik[21][1][0]*VWri[19][21][1])))+((psrk[21][1]*
          Wpk[19][21][2])-(psrk[21][2]*Wpk[19][21][1])));
        Vpk[19][21][1] = (((Cik[21][2][1]*VWri[19][21][2])+((Cik[21][0][1]*
          VWri[19][21][0])+(Cik[21][1][1]*VWri[19][21][1])))+((psrk[21][2]*
          Wpk[19][21][0])-(psrk[21][0]*Wpk[19][21][2])));
        Vpk[19][21][2] = (((Cik[21][2][2]*VWri[19][21][2])+((Cik[21][0][2]*
          VWri[19][21][0])+(Cik[21][1][2]*VWri[19][21][1])))+((psrk[21][0]*
          Wpk[19][21][1])-(psrk[21][1]*Wpk[19][21][0])));
        Vpk[20][20][0] = ((pin[20][2]*rk[18][1])-(pin[20][1]*rk[18][2]));
        Vpk[20][20][1] = ((pin[20][0]*rk[18][2])-(pin[20][2]*rk[18][0]));
        Vpk[20][20][2] = ((pin[20][1]*rk[18][0])-(pin[20][0]*rk[18][1]));
        VWri[20][21][0] = (Vpk[20][20][0]+((pin[20][1]*ri[19][2])-(pin[20][2]*
          ri[19][1])));
        VWri[20][21][1] = (Vpk[20][20][1]+((pin[20][2]*ri[19][0])-(pin[20][0]*
          ri[19][2])));
        VWri[20][21][2] = (Vpk[20][20][2]+((pin[20][0]*ri[19][1])-(pin[20][1]*
          ri[19][0])));
        Vpk[20][21][0] = (((Cik[21][2][0]*VWri[20][21][2])+((Cik[21][0][0]*
          VWri[20][21][0])+(Cik[21][1][0]*VWri[20][21][1])))+((psrk[21][1]*
          Wpk[20][21][2])-(psrk[21][2]*Wpk[20][21][1])));
        Vpk[20][21][1] = (((Cik[21][2][1]*VWri[20][21][2])+((Cik[21][0][1]*
          VWri[20][21][0])+(Cik[21][1][1]*VWri[20][21][1])))+((psrk[21][2]*
          Wpk[20][21][0])-(psrk[21][0]*Wpk[20][21][2])));
        Vpk[20][21][2] = (((Cik[21][2][2]*VWri[20][21][2])+((Cik[21][0][2]*
          VWri[20][21][0])+(Cik[21][1][2]*VWri[20][21][1])))+((psrk[21][0]*
          Wpk[20][21][1])-(psrk[21][1]*Wpk[20][21][0])));
        Vpk[21][21][0] = ((pin[21][2]*psrk[21][1])-(pin[21][1]*psrk[21][2]));
        Vpk[21][21][1] = ((pin[21][0]*psrk[21][2])-(pin[21][2]*psrk[21][0]));
        Vpk[21][21][2] = ((pin[21][1]*psrk[21][0])-(pin[21][0]*psrk[21][1]));
        vpkflg = 1;
    }
/*
 Used 0.01 seconds CPU time,
 0 additional bytes of memory.
 Equations contain 1929 adds/subtracts/negates
                   2499 multiplies
                      0 divides
                    933 assignments
*/
}

void allegro_air_doltau(void)
{

/*
Compute effect of loop hinge torques
*/
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                      0 assignments
*/
}

void allegro_air_doiner(void)
{

/*
Compute inertial accelerations and related temps
*/
    if (inerflg == 0) {
/*
Compute Otk (inertial angular acceleration)
*/
        Otk[6][0] = ((Wik[6][2]*wk[6][1])-(Wik[6][1]*wk[6][2]));
        Otk[6][1] = ((Wik[6][0]*wk[6][2])-(Wik[6][2]*wk[6][0]));
        Otk[6][2] = ((Wik[6][1]*wk[6][0])-(Wik[6][0]*wk[6][1]));
        Otk[7][0] = (((Cik[7][2][0]*Otk[6][2])+((Cik[7][0][0]*Otk[6][0])+(
          Cik[7][1][0]*Otk[6][1])))+((Wik[7][2]*wk[7][1])-(Wik[7][1]*wk[7][2])))
          ;
        Otk[7][1] = (((Cik[7][2][1]*Otk[6][2])+((Cik[7][0][1]*Otk[6][0])+(
          Cik[7][1][1]*Otk[6][1])))+((Wik[7][0]*wk[7][2])-(Wik[7][2]*wk[7][0])))
          ;
        Otk[7][2] = (((Cik[7][2][2]*Otk[6][2])+((Cik[7][0][2]*Otk[6][0])+(
          Cik[7][1][2]*Otk[6][1])))+((Wik[7][1]*wk[7][0])-(Wik[7][0]*wk[7][1])))
          ;
        Otk[8][0] = (((Cik[8][2][0]*Otk[7][2])+((Cik[8][0][0]*Otk[7][0])+(
          Cik[8][1][0]*Otk[7][1])))+((Wik[8][2]*wk[8][1])-(Wik[8][1]*wk[8][2])))
          ;
        Otk[8][1] = (((Cik[8][2][1]*Otk[7][2])+((Cik[8][0][1]*Otk[7][0])+(
          Cik[8][1][1]*Otk[7][1])))+((Wik[8][0]*wk[8][2])-(Wik[8][2]*wk[8][0])))
          ;
        Otk[8][2] = (((Cik[8][2][2]*Otk[7][2])+((Cik[8][0][2]*Otk[7][0])+(
          Cik[8][1][2]*Otk[7][1])))+((Wik[8][1]*wk[8][0])-(Wik[8][0]*wk[8][1])))
          ;
        Otk[9][0] = (((Cik[9][2][0]*Otk[8][2])+((Cik[9][0][0]*Otk[8][0])+(
          Cik[9][1][0]*Otk[8][1])))+((Wik[9][2]*wk[9][1])-(Wik[9][1]*wk[9][2])))
          ;
        Otk[9][1] = (((Cik[9][2][1]*Otk[8][2])+((Cik[9][0][1]*Otk[8][0])+(
          Cik[9][1][1]*Otk[8][1])))+((Wik[9][0]*wk[9][2])-(Wik[9][2]*wk[9][0])))
          ;
        Otk[9][2] = (((Cik[9][2][2]*Otk[8][2])+((Cik[9][0][2]*Otk[8][0])+(
          Cik[9][1][2]*Otk[8][1])))+((Wik[9][1]*wk[9][0])-(Wik[9][0]*wk[9][1])))
          ;
        Otk[10][0] = ((Wik[10][2]*wk[10][1])-(Wik[10][1]*wk[10][2]));
        Otk[10][1] = ((Wik[10][0]*wk[10][2])-(Wik[10][2]*wk[10][0]));
        Otk[10][2] = ((Wik[10][1]*wk[10][0])-(Wik[10][0]*wk[10][1]));
        Otk[11][0] = (((Cik[11][2][0]*Otk[10][2])+((Cik[11][0][0]*Otk[10][0])+(
          Cik[11][1][0]*Otk[10][1])))+((Wik[11][2]*wk[11][1])-(Wik[11][1]*
          wk[11][2])));
        Otk[11][1] = (((Cik[11][2][1]*Otk[10][2])+((Cik[11][0][1]*Otk[10][0])+(
          Cik[11][1][1]*Otk[10][1])))+((Wik[11][0]*wk[11][2])-(Wik[11][2]*
          wk[11][0])));
        Otk[11][2] = (((Cik[11][2][2]*Otk[10][2])+((Cik[11][0][2]*Otk[10][0])+(
          Cik[11][1][2]*Otk[10][1])))+((Wik[11][1]*wk[11][0])-(Wik[11][0]*
          wk[11][1])));
        Otk[12][0] = (((Cik[12][2][0]*Otk[11][2])+((Cik[12][0][0]*Otk[11][0])+(
          Cik[12][1][0]*Otk[11][1])))+((Wik[12][2]*wk[12][1])-(Wik[12][1]*
          wk[12][2])));
        Otk[12][1] = (((Cik[12][2][1]*Otk[11][2])+((Cik[12][0][1]*Otk[11][0])+(
          Cik[12][1][1]*Otk[11][1])))+((Wik[12][0]*wk[12][2])-(Wik[12][2]*
          wk[12][0])));
        Otk[12][2] = (((Cik[12][2][2]*Otk[11][2])+((Cik[12][0][2]*Otk[11][0])+(
          Cik[12][1][2]*Otk[11][1])))+((Wik[12][1]*wk[12][0])-(Wik[12][0]*
          wk[12][1])));
        Otk[13][0] = (((Cik[13][2][0]*Otk[12][2])+((Cik[13][0][0]*Otk[12][0])+(
          Cik[13][1][0]*Otk[12][1])))+((Wik[13][2]*wk[13][1])-(Wik[13][1]*
          wk[13][2])));
        Otk[13][1] = (((Cik[13][2][1]*Otk[12][2])+((Cik[13][0][1]*Otk[12][0])+(
          Cik[13][1][1]*Otk[12][1])))+((Wik[13][0]*wk[13][2])-(Wik[13][2]*
          wk[13][0])));
        Otk[13][2] = (((Cik[13][2][2]*Otk[12][2])+((Cik[13][0][2]*Otk[12][0])+(
          Cik[13][1][2]*Otk[12][1])))+((Wik[13][1]*wk[13][0])-(Wik[13][0]*
          wk[13][1])));
        Otk[14][0] = ((Wik[14][2]*wk[14][1])-(Wik[14][1]*wk[14][2]));
        Otk[14][1] = ((Wik[14][0]*wk[14][2])-(Wik[14][2]*wk[14][0]));
        Otk[14][2] = ((Wik[14][1]*wk[14][0])-(Wik[14][0]*wk[14][1]));
        Otk[15][0] = (((Cik[15][2][0]*Otk[14][2])+((Cik[15][0][0]*Otk[14][0])+(
          Cik[15][1][0]*Otk[14][1])))+((Wik[15][2]*wk[15][1])-(Wik[15][1]*
          wk[15][2])));
        Otk[15][1] = (((Cik[15][2][1]*Otk[14][2])+((Cik[15][0][1]*Otk[14][0])+(
          Cik[15][1][1]*Otk[14][1])))+((Wik[15][0]*wk[15][2])-(Wik[15][2]*
          wk[15][0])));
        Otk[15][2] = (((Cik[15][2][2]*Otk[14][2])+((Cik[15][0][2]*Otk[14][0])+(
          Cik[15][1][2]*Otk[14][1])))+((Wik[15][1]*wk[15][0])-(Wik[15][0]*
          wk[15][1])));
        Otk[16][0] = (((Cik[16][2][0]*Otk[15][2])+((Cik[16][0][0]*Otk[15][0])+(
          Cik[16][1][0]*Otk[15][1])))+((Wik[16][2]*wk[16][1])-(Wik[16][1]*
          wk[16][2])));
        Otk[16][1] = (((Cik[16][2][1]*Otk[15][2])+((Cik[16][0][1]*Otk[15][0])+(
          Cik[16][1][1]*Otk[15][1])))+((Wik[16][0]*wk[16][2])-(Wik[16][2]*
          wk[16][0])));
        Otk[16][2] = (((Cik[16][2][2]*Otk[15][2])+((Cik[16][0][2]*Otk[15][0])+(
          Cik[16][1][2]*Otk[15][1])))+((Wik[16][1]*wk[16][0])-(Wik[16][0]*
          wk[16][1])));
        Otk[17][0] = (((Cik[17][2][0]*Otk[16][2])+((Cik[17][0][0]*Otk[16][0])+(
          Cik[17][1][0]*Otk[16][1])))+((Wik[17][2]*wk[17][1])-(Wik[17][1]*
          wk[17][2])));
        Otk[17][1] = (((Cik[17][2][1]*Otk[16][2])+((Cik[17][0][1]*Otk[16][0])+(
          Cik[17][1][1]*Otk[16][1])))+((Wik[17][0]*wk[17][2])-(Wik[17][2]*
          wk[17][0])));
        Otk[17][2] = (((Cik[17][2][2]*Otk[16][2])+((Cik[17][0][2]*Otk[16][0])+(
          Cik[17][1][2]*Otk[16][1])))+((Wik[17][1]*wk[17][0])-(Wik[17][0]*
          wk[17][1])));
        Otk[18][0] = ((Wik[18][2]*wk[18][1])-(Wik[18][1]*wk[18][2]));
        Otk[18][1] = ((Wik[18][0]*wk[18][2])-(Wik[18][2]*wk[18][0]));
        Otk[18][2] = ((Wik[18][1]*wk[18][0])-(Wik[18][0]*wk[18][1]));
        Otk[19][0] = (((Cik[19][2][0]*Otk[18][2])+((Cik[19][0][0]*Otk[18][0])+(
          Cik[19][1][0]*Otk[18][1])))+((Wik[19][2]*wk[19][1])-(Wik[19][1]*
          wk[19][2])));
        Otk[19][1] = (((Cik[19][2][1]*Otk[18][2])+((Cik[19][0][1]*Otk[18][0])+(
          Cik[19][1][1]*Otk[18][1])))+((Wik[19][0]*wk[19][2])-(Wik[19][2]*
          wk[19][0])));
        Otk[19][2] = (((Cik[19][2][2]*Otk[18][2])+((Cik[19][0][2]*Otk[18][0])+(
          Cik[19][1][2]*Otk[18][1])))+((Wik[19][1]*wk[19][0])-(Wik[19][0]*
          wk[19][1])));
        Otk[20][0] = (((Cik[20][2][0]*Otk[19][2])+((Cik[20][0][0]*Otk[19][0])+(
          Cik[20][1][0]*Otk[19][1])))+((Wik[20][2]*wk[20][1])-(Wik[20][1]*
          wk[20][2])));
        Otk[20][1] = (((Cik[20][2][1]*Otk[19][2])+((Cik[20][0][1]*Otk[19][0])+(
          Cik[20][1][1]*Otk[19][1])))+((Wik[20][0]*wk[20][2])-(Wik[20][2]*
          wk[20][0])));
        Otk[20][2] = (((Cik[20][2][2]*Otk[19][2])+((Cik[20][0][2]*Otk[19][0])+(
          Cik[20][1][2]*Otk[19][1])))+((Wik[20][1]*wk[20][0])-(Wik[20][0]*
          wk[20][1])));
        Otk[21][0] = (((Cik[21][2][0]*Otk[20][2])+((Cik[21][0][0]*Otk[20][0])+(
          Cik[21][1][0]*Otk[20][1])))+((Wik[21][2]*wk[21][1])-(Wik[21][1]*
          wk[21][2])));
        Otk[21][1] = (((Cik[21][2][1]*Otk[20][2])+((Cik[21][0][1]*Otk[20][0])+(
          Cik[21][1][1]*Otk[20][1])))+((Wik[21][0]*wk[21][2])-(Wik[21][2]*
          wk[21][0])));
        Otk[21][2] = (((Cik[21][2][2]*Otk[20][2])+((Cik[21][0][2]*Otk[20][0])+(
          Cik[21][1][2]*Otk[20][1])))+((Wik[21][1]*wk[21][0])-(Wik[21][0]*
          wk[21][1])));
/*
Compute Atk (inertial linear acceleration)
*/
        Atk[5][0] = ((u[4]*Wkrpk[5][2])-(u[5]*Wkrpk[5][1]));
        Atk[5][1] = ((u[5]*Wkrpk[5][0])-(u[3]*Wkrpk[5][2]));
        Atk[5][2] = ((u[3]*Wkrpk[5][1])-(u[4]*Wkrpk[5][0]));
        AiOiWi[6][0] = (Atk[5][0]+((u[4]*Wirk[6][2])-(u[5]*Wirk[6][1])));
        AiOiWi[6][1] = (Atk[5][1]+((u[5]*Wirk[6][0])-(u[3]*Wirk[6][2])));
        AiOiWi[6][2] = (Atk[5][2]+((u[3]*Wirk[6][1])-(u[4]*Wirk[6][0])));
        Atk[6][0] = (((AiOiWi[6][2]*Cik[6][2][0])+((AiOiWi[6][0]*Cik[6][0][0])+(
          AiOiWi[6][1]*Cik[6][1][0])))+(((Otk[6][2]*rk[1][1])-(Otk[6][1]*
          rk[1][2]))+((wk[6][1]*Wkrpk[6][2])-(wk[6][2]*Wkrpk[6][1]))));
        Atk[6][1] = (((AiOiWi[6][2]*Cik[6][2][1])+((AiOiWi[6][0]*Cik[6][0][1])+(
          AiOiWi[6][1]*Cik[6][1][1])))+(((Otk[6][0]*rk[1][2])-(Otk[6][2]*
          rk[1][0]))+((wk[6][2]*Wkrpk[6][0])-(wk[6][0]*Wkrpk[6][2]))));
        Atk[6][2] = (((AiOiWi[6][2]*Cik[6][2][2])+((AiOiWi[6][0]*Cik[6][0][2])+(
          AiOiWi[6][1]*Cik[6][1][2])))+(((Otk[6][1]*rk[1][0])-(Otk[6][0]*
          rk[1][1]))+((wk[6][0]*Wkrpk[6][1])-(wk[6][1]*Wkrpk[6][0]))));
        AiOiWi[7][0] = (Atk[6][0]+(((Otk[6][1]*ri[2][2])-(Otk[6][2]*ri[2][1]))+(
          (Wirk[7][2]*wk[6][1])-(Wirk[7][1]*wk[6][2]))));
        AiOiWi[7][1] = (Atk[6][1]+(((Otk[6][2]*ri[2][0])-(Otk[6][0]*ri[2][2]))+(
          (Wirk[7][0]*wk[6][2])-(Wirk[7][2]*wk[6][0]))));
        AiOiWi[7][2] = (Atk[6][2]+(((Otk[6][0]*ri[2][1])-(Otk[6][1]*ri[2][0]))+(
          (Wirk[7][1]*wk[6][0])-(Wirk[7][0]*wk[6][1]))));
        Atk[7][0] = (((AiOiWi[7][2]*Cik[7][2][0])+((AiOiWi[7][0]*Cik[7][0][0])+(
          AiOiWi[7][1]*Cik[7][1][0])))+(((Otk[7][2]*rk[2][1])-(Otk[7][1]*
          rk[2][2]))+((wk[7][1]*Wkrpk[7][2])-(wk[7][2]*Wkrpk[7][1]))));
        Atk[7][1] = (((AiOiWi[7][2]*Cik[7][2][1])+((AiOiWi[7][0]*Cik[7][0][1])+(
          AiOiWi[7][1]*Cik[7][1][1])))+(((Otk[7][0]*rk[2][2])-(Otk[7][2]*
          rk[2][0]))+((wk[7][2]*Wkrpk[7][0])-(wk[7][0]*Wkrpk[7][2]))));
        Atk[7][2] = (((AiOiWi[7][2]*Cik[7][2][2])+((AiOiWi[7][0]*Cik[7][0][2])+(
          AiOiWi[7][1]*Cik[7][1][2])))+(((Otk[7][1]*rk[2][0])-(Otk[7][0]*
          rk[2][1]))+((wk[7][0]*Wkrpk[7][1])-(wk[7][1]*Wkrpk[7][0]))));
        AiOiWi[8][0] = (Atk[7][0]+(((Otk[7][1]*ri[3][2])-(Otk[7][2]*ri[3][1]))+(
          (Wirk[8][2]*wk[7][1])-(Wirk[8][1]*wk[7][2]))));
        AiOiWi[8][1] = (Atk[7][1]+(((Otk[7][2]*ri[3][0])-(Otk[7][0]*ri[3][2]))+(
          (Wirk[8][0]*wk[7][2])-(Wirk[8][2]*wk[7][0]))));
        AiOiWi[8][2] = (Atk[7][2]+(((Otk[7][0]*ri[3][1])-(Otk[7][1]*ri[3][0]))+(
          (Wirk[8][1]*wk[7][0])-(Wirk[8][0]*wk[7][1]))));
        Atk[8][0] = (((AiOiWi[8][2]*Cik[8][2][0])+((AiOiWi[8][0]*Cik[8][0][0])+(
          AiOiWi[8][1]*Cik[8][1][0])))+(((Otk[8][2]*rk[3][1])-(Otk[8][1]*
          rk[3][2]))+((wk[8][1]*Wkrpk[8][2])-(wk[8][2]*Wkrpk[8][1]))));
        Atk[8][1] = (((AiOiWi[8][2]*Cik[8][2][1])+((AiOiWi[8][0]*Cik[8][0][1])+(
          AiOiWi[8][1]*Cik[8][1][1])))+(((Otk[8][0]*rk[3][2])-(Otk[8][2]*
          rk[3][0]))+((wk[8][2]*Wkrpk[8][0])-(wk[8][0]*Wkrpk[8][2]))));
        Atk[8][2] = (((AiOiWi[8][2]*Cik[8][2][2])+((AiOiWi[8][0]*Cik[8][0][2])+(
          AiOiWi[8][1]*Cik[8][1][2])))+(((Otk[8][1]*rk[3][0])-(Otk[8][0]*
          rk[3][1]))+((wk[8][0]*Wkrpk[8][1])-(wk[8][1]*Wkrpk[8][0]))));
        AiOiWi[9][0] = (Atk[8][0]+(((Otk[8][1]*ri[4][2])-(Otk[8][2]*ri[4][1]))+(
          (Wirk[9][2]*wk[8][1])-(Wirk[9][1]*wk[8][2]))));
        AiOiWi[9][1] = (Atk[8][1]+(((Otk[8][2]*ri[4][0])-(Otk[8][0]*ri[4][2]))+(
          (Wirk[9][0]*wk[8][2])-(Wirk[9][2]*wk[8][0]))));
        AiOiWi[9][2] = (Atk[8][2]+(((Otk[8][0]*ri[4][1])-(Otk[8][1]*ri[4][0]))+(
          (Wirk[9][1]*wk[8][0])-(Wirk[9][0]*wk[8][1]))));
        Atk[9][0] = (((AiOiWi[9][2]*Cik[9][2][0])+((AiOiWi[9][0]*Cik[9][0][0])+(
          AiOiWi[9][1]*Cik[9][1][0])))+(((Otk[9][2]*psrk[9][1])-(Otk[9][1]*
          psrk[9][2]))+((wk[9][1]*Wkrpk[9][2])-(wk[9][2]*Wkrpk[9][1]))));
        Atk[9][1] = (((AiOiWi[9][2]*Cik[9][2][1])+((AiOiWi[9][0]*Cik[9][0][1])+(
          AiOiWi[9][1]*Cik[9][1][1])))+(((Otk[9][0]*psrk[9][2])-(Otk[9][2]*
          psrk[9][0]))+((wk[9][2]*Wkrpk[9][0])-(wk[9][0]*Wkrpk[9][2]))));
        Atk[9][2] = (((AiOiWi[9][2]*Cik[9][2][2])+((AiOiWi[9][0]*Cik[9][0][2])+(
          AiOiWi[9][1]*Cik[9][1][2])))+(((Otk[9][1]*psrk[9][0])-(Otk[9][0]*
          psrk[9][1]))+((wk[9][0]*Wkrpk[9][1])-(wk[9][1]*Wkrpk[9][0]))));
        AiOiWi[10][0] = (Atk[5][0]+((u[4]*Wirk[10][2])-(u[5]*Wirk[10][1])));
        AiOiWi[10][1] = (Atk[5][1]+((u[5]*Wirk[10][0])-(u[3]*Wirk[10][2])));
        AiOiWi[10][2] = (Atk[5][2]+((u[3]*Wirk[10][1])-(u[4]*Wirk[10][0])));
        Atk[10][0] = (((AiOiWi[10][2]*Cik[10][2][0])+((AiOiWi[10][0]*
          Cik[10][0][0])+(AiOiWi[10][1]*Cik[10][1][0])))+(((Otk[10][2]*rk[6][1])
          -(Otk[10][1]*rk[6][2]))+((wk[10][1]*Wkrpk[10][2])-(wk[10][2]*
          Wkrpk[10][1]))));
        Atk[10][1] = (((AiOiWi[10][2]*Cik[10][2][1])+((AiOiWi[10][0]*
          Cik[10][0][1])+(AiOiWi[10][1]*Cik[10][1][1])))+(((Otk[10][0]*rk[6][2])
          -(Otk[10][2]*rk[6][0]))+((wk[10][2]*Wkrpk[10][0])-(wk[10][0]*
          Wkrpk[10][2]))));
        Atk[10][2] = (((AiOiWi[10][2]*Cik[10][2][2])+((AiOiWi[10][0]*
          Cik[10][0][2])+(AiOiWi[10][1]*Cik[10][1][2])))+(((Otk[10][1]*rk[6][0])
          -(Otk[10][0]*rk[6][1]))+((wk[10][0]*Wkrpk[10][1])-(wk[10][1]*
          Wkrpk[10][0]))));
        AiOiWi[11][0] = (Atk[10][0]+(((Otk[10][1]*ri[7][2])-(Otk[10][2]*ri[7][1]
          ))+((Wirk[11][2]*wk[10][1])-(Wirk[11][1]*wk[10][2]))));
        AiOiWi[11][1] = (Atk[10][1]+(((Otk[10][2]*ri[7][0])-(Otk[10][0]*ri[7][2]
          ))+((Wirk[11][0]*wk[10][2])-(Wirk[11][2]*wk[10][0]))));
        AiOiWi[11][2] = (Atk[10][2]+(((Otk[10][0]*ri[7][1])-(Otk[10][1]*ri[7][0]
          ))+((Wirk[11][1]*wk[10][0])-(Wirk[11][0]*wk[10][1]))));
        Atk[11][0] = (((AiOiWi[11][2]*Cik[11][2][0])+((AiOiWi[11][0]*
          Cik[11][0][0])+(AiOiWi[11][1]*Cik[11][1][0])))+(((Otk[11][2]*rk[7][1])
          -(Otk[11][1]*rk[7][2]))+((wk[11][1]*Wkrpk[11][2])-(wk[11][2]*
          Wkrpk[11][1]))));
        Atk[11][1] = (((AiOiWi[11][2]*Cik[11][2][1])+((AiOiWi[11][0]*
          Cik[11][0][1])+(AiOiWi[11][1]*Cik[11][1][1])))+(((Otk[11][0]*rk[7][2])
          -(Otk[11][2]*rk[7][0]))+((wk[11][2]*Wkrpk[11][0])-(wk[11][0]*
          Wkrpk[11][2]))));
        Atk[11][2] = (((AiOiWi[11][2]*Cik[11][2][2])+((AiOiWi[11][0]*
          Cik[11][0][2])+(AiOiWi[11][1]*Cik[11][1][2])))+(((Otk[11][1]*rk[7][0])
          -(Otk[11][0]*rk[7][1]))+((wk[11][0]*Wkrpk[11][1])-(wk[11][1]*
          Wkrpk[11][0]))));
        AiOiWi[12][0] = (Atk[11][0]+(((Otk[11][1]*ri[8][2])-(Otk[11][2]*ri[8][1]
          ))+((Wirk[12][2]*wk[11][1])-(Wirk[12][1]*wk[11][2]))));
        AiOiWi[12][1] = (Atk[11][1]+(((Otk[11][2]*ri[8][0])-(Otk[11][0]*ri[8][2]
          ))+((Wirk[12][0]*wk[11][2])-(Wirk[12][2]*wk[11][0]))));
        AiOiWi[12][2] = (Atk[11][2]+(((Otk[11][0]*ri[8][1])-(Otk[11][1]*ri[8][0]
          ))+((Wirk[12][1]*wk[11][0])-(Wirk[12][0]*wk[11][1]))));
        Atk[12][0] = (((AiOiWi[12][2]*Cik[12][2][0])+((AiOiWi[12][0]*
          Cik[12][0][0])+(AiOiWi[12][1]*Cik[12][1][0])))+(((Otk[12][2]*rk[8][1])
          -(Otk[12][1]*rk[8][2]))+((wk[12][1]*Wkrpk[12][2])-(wk[12][2]*
          Wkrpk[12][1]))));
        Atk[12][1] = (((AiOiWi[12][2]*Cik[12][2][1])+((AiOiWi[12][0]*
          Cik[12][0][1])+(AiOiWi[12][1]*Cik[12][1][1])))+(((Otk[12][0]*rk[8][2])
          -(Otk[12][2]*rk[8][0]))+((wk[12][2]*Wkrpk[12][0])-(wk[12][0]*
          Wkrpk[12][2]))));
        Atk[12][2] = (((AiOiWi[12][2]*Cik[12][2][2])+((AiOiWi[12][0]*
          Cik[12][0][2])+(AiOiWi[12][1]*Cik[12][1][2])))+(((Otk[12][1]*rk[8][0])
          -(Otk[12][0]*rk[8][1]))+((wk[12][0]*Wkrpk[12][1])-(wk[12][1]*
          Wkrpk[12][0]))));
        AiOiWi[13][0] = (Atk[12][0]+(((Otk[12][1]*ri[9][2])-(Otk[12][2]*ri[9][1]
          ))+((Wirk[13][2]*wk[12][1])-(Wirk[13][1]*wk[12][2]))));
        AiOiWi[13][1] = (Atk[12][1]+(((Otk[12][2]*ri[9][0])-(Otk[12][0]*ri[9][2]
          ))+((Wirk[13][0]*wk[12][2])-(Wirk[13][2]*wk[12][0]))));
        AiOiWi[13][2] = (Atk[12][2]+(((Otk[12][0]*ri[9][1])-(Otk[12][1]*ri[9][0]
          ))+((Wirk[13][1]*wk[12][0])-(Wirk[13][0]*wk[12][1]))));
        Atk[13][0] = (((AiOiWi[13][2]*Cik[13][2][0])+((AiOiWi[13][0]*
          Cik[13][0][0])+(AiOiWi[13][1]*Cik[13][1][0])))+(((Otk[13][2]*
          psrk[13][1])-(Otk[13][1]*psrk[13][2]))+((wk[13][1]*Wkrpk[13][2])-(
          wk[13][2]*Wkrpk[13][1]))));
        Atk[13][1] = (((AiOiWi[13][2]*Cik[13][2][1])+((AiOiWi[13][0]*
          Cik[13][0][1])+(AiOiWi[13][1]*Cik[13][1][1])))+(((Otk[13][0]*
          psrk[13][2])-(Otk[13][2]*psrk[13][0]))+((wk[13][2]*Wkrpk[13][0])-(
          wk[13][0]*Wkrpk[13][2]))));
        Atk[13][2] = (((AiOiWi[13][2]*Cik[13][2][2])+((AiOiWi[13][0]*
          Cik[13][0][2])+(AiOiWi[13][1]*Cik[13][1][2])))+(((Otk[13][1]*
          psrk[13][0])-(Otk[13][0]*psrk[13][1]))+((wk[13][0]*Wkrpk[13][1])-(
          wk[13][1]*Wkrpk[13][0]))));
        AiOiWi[14][0] = (Atk[5][0]+((u[4]*Wirk[14][2])-(u[5]*Wirk[14][1])));
        AiOiWi[14][1] = (Atk[5][1]+((u[5]*Wirk[14][0])-(u[3]*Wirk[14][2])));
        AiOiWi[14][2] = (Atk[5][2]+((u[3]*Wirk[14][1])-(u[4]*Wirk[14][0])));
        Atk[14][0] = (((AiOiWi[14][2]*Cik[14][2][0])+((AiOiWi[14][0]*
          Cik[14][0][0])+(AiOiWi[14][1]*Cik[14][1][0])))+(((Otk[14][2]*rk[11][1]
          )-(Otk[14][1]*rk[11][2]))+((wk[14][1]*Wkrpk[14][2])-(wk[14][2]*
          Wkrpk[14][1]))));
        Atk[14][1] = (((AiOiWi[14][2]*Cik[14][2][1])+((AiOiWi[14][0]*
          Cik[14][0][1])+(AiOiWi[14][1]*Cik[14][1][1])))+(((Otk[14][0]*rk[11][2]
          )-(Otk[14][2]*rk[11][0]))+((wk[14][2]*Wkrpk[14][0])-(wk[14][0]*
          Wkrpk[14][2]))));
        Atk[14][2] = (((AiOiWi[14][2]*Cik[14][2][2])+((AiOiWi[14][0]*
          Cik[14][0][2])+(AiOiWi[14][1]*Cik[14][1][2])))+(((Otk[14][1]*rk[11][0]
          )-(Otk[14][0]*rk[11][1]))+((wk[14][0]*Wkrpk[14][1])-(wk[14][1]*
          Wkrpk[14][0]))));
        AiOiWi[15][0] = (Atk[14][0]+(((Otk[14][1]*ri[12][2])-(Otk[14][2]*
          ri[12][1]))+((Wirk[15][2]*wk[14][1])-(Wirk[15][1]*wk[14][2]))));
        AiOiWi[15][1] = (Atk[14][1]+(((Otk[14][2]*ri[12][0])-(Otk[14][0]*
          ri[12][2]))+((Wirk[15][0]*wk[14][2])-(Wirk[15][2]*wk[14][0]))));
        AiOiWi[15][2] = (Atk[14][2]+(((Otk[14][0]*ri[12][1])-(Otk[14][1]*
          ri[12][0]))+((Wirk[15][1]*wk[14][0])-(Wirk[15][0]*wk[14][1]))));
        Atk[15][0] = (((AiOiWi[15][2]*Cik[15][2][0])+((AiOiWi[15][0]*
          Cik[15][0][0])+(AiOiWi[15][1]*Cik[15][1][0])))+(((Otk[15][2]*rk[12][1]
          )-(Otk[15][1]*rk[12][2]))+((wk[15][1]*Wkrpk[15][2])-(wk[15][2]*
          Wkrpk[15][1]))));
        Atk[15][1] = (((AiOiWi[15][2]*Cik[15][2][1])+((AiOiWi[15][0]*
          Cik[15][0][1])+(AiOiWi[15][1]*Cik[15][1][1])))+(((Otk[15][0]*rk[12][2]
          )-(Otk[15][2]*rk[12][0]))+((wk[15][2]*Wkrpk[15][0])-(wk[15][0]*
          Wkrpk[15][2]))));
        Atk[15][2] = (((AiOiWi[15][2]*Cik[15][2][2])+((AiOiWi[15][0]*
          Cik[15][0][2])+(AiOiWi[15][1]*Cik[15][1][2])))+(((Otk[15][1]*rk[12][0]
          )-(Otk[15][0]*rk[12][1]))+((wk[15][0]*Wkrpk[15][1])-(wk[15][1]*
          Wkrpk[15][0]))));
        AiOiWi[16][0] = (Atk[15][0]+(((Otk[15][1]*ri[13][2])-(Otk[15][2]*
          ri[13][1]))+((Wirk[16][2]*wk[15][1])-(Wirk[16][1]*wk[15][2]))));
        AiOiWi[16][1] = (Atk[15][1]+(((Otk[15][2]*ri[13][0])-(Otk[15][0]*
          ri[13][2]))+((Wirk[16][0]*wk[15][2])-(Wirk[16][2]*wk[15][0]))));
        AiOiWi[16][2] = (Atk[15][2]+(((Otk[15][0]*ri[13][1])-(Otk[15][1]*
          ri[13][0]))+((Wirk[16][1]*wk[15][0])-(Wirk[16][0]*wk[15][1]))));
        Atk[16][0] = (((AiOiWi[16][2]*Cik[16][2][0])+((AiOiWi[16][0]*
          Cik[16][0][0])+(AiOiWi[16][1]*Cik[16][1][0])))+(((Otk[16][2]*rk[13][1]
          )-(Otk[16][1]*rk[13][2]))+((wk[16][1]*Wkrpk[16][2])-(wk[16][2]*
          Wkrpk[16][1]))));
        Atk[16][1] = (((AiOiWi[16][2]*Cik[16][2][1])+((AiOiWi[16][0]*
          Cik[16][0][1])+(AiOiWi[16][1]*Cik[16][1][1])))+(((Otk[16][0]*rk[13][2]
          )-(Otk[16][2]*rk[13][0]))+((wk[16][2]*Wkrpk[16][0])-(wk[16][0]*
          Wkrpk[16][2]))));
        Atk[16][2] = (((AiOiWi[16][2]*Cik[16][2][2])+((AiOiWi[16][0]*
          Cik[16][0][2])+(AiOiWi[16][1]*Cik[16][1][2])))+(((Otk[16][1]*rk[13][0]
          )-(Otk[16][0]*rk[13][1]))+((wk[16][0]*Wkrpk[16][1])-(wk[16][1]*
          Wkrpk[16][0]))));
        AiOiWi[17][0] = (Atk[16][0]+(((Otk[16][1]*ri[14][2])-(Otk[16][2]*
          ri[14][1]))+((Wirk[17][2]*wk[16][1])-(Wirk[17][1]*wk[16][2]))));
        AiOiWi[17][1] = (Atk[16][1]+(((Otk[16][2]*ri[14][0])-(Otk[16][0]*
          ri[14][2]))+((Wirk[17][0]*wk[16][2])-(Wirk[17][2]*wk[16][0]))));
        AiOiWi[17][2] = (Atk[16][2]+(((Otk[16][0]*ri[14][1])-(Otk[16][1]*
          ri[14][0]))+((Wirk[17][1]*wk[16][0])-(Wirk[17][0]*wk[16][1]))));
        Atk[17][0] = (((AiOiWi[17][2]*Cik[17][2][0])+((AiOiWi[17][0]*
          Cik[17][0][0])+(AiOiWi[17][1]*Cik[17][1][0])))+(((Otk[17][2]*
          psrk[17][1])-(Otk[17][1]*psrk[17][2]))+((wk[17][1]*Wkrpk[17][2])-(
          wk[17][2]*Wkrpk[17][1]))));
        Atk[17][1] = (((AiOiWi[17][2]*Cik[17][2][1])+((AiOiWi[17][0]*
          Cik[17][0][1])+(AiOiWi[17][1]*Cik[17][1][1])))+(((Otk[17][0]*
          psrk[17][2])-(Otk[17][2]*psrk[17][0]))+((wk[17][2]*Wkrpk[17][0])-(
          wk[17][0]*Wkrpk[17][2]))));
        Atk[17][2] = (((AiOiWi[17][2]*Cik[17][2][2])+((AiOiWi[17][0]*
          Cik[17][0][2])+(AiOiWi[17][1]*Cik[17][1][2])))+(((Otk[17][1]*
          psrk[17][0])-(Otk[17][0]*psrk[17][1]))+((wk[17][0]*Wkrpk[17][1])-(
          wk[17][1]*Wkrpk[17][0]))));
        AiOiWi[18][0] = (Atk[5][0]+((u[4]*Wirk[18][2])-(u[5]*Wirk[18][1])));
        AiOiWi[18][1] = (Atk[5][1]+((u[5]*Wirk[18][0])-(u[3]*Wirk[18][2])));
        AiOiWi[18][2] = (Atk[5][2]+((u[3]*Wirk[18][1])-(u[4]*Wirk[18][0])));
        Atk[18][0] = (((AiOiWi[18][2]*Cik[18][2][0])+((AiOiWi[18][0]*
          Cik[18][0][0])+(AiOiWi[18][1]*Cik[18][1][0])))+(((Otk[18][2]*rk[16][1]
          )-(Otk[18][1]*rk[16][2]))+((wk[18][1]*Wkrpk[18][2])-(wk[18][2]*
          Wkrpk[18][1]))));
        Atk[18][1] = (((AiOiWi[18][2]*Cik[18][2][1])+((AiOiWi[18][0]*
          Cik[18][0][1])+(AiOiWi[18][1]*Cik[18][1][1])))+(((Otk[18][0]*rk[16][2]
          )-(Otk[18][2]*rk[16][0]))+((wk[18][2]*Wkrpk[18][0])-(wk[18][0]*
          Wkrpk[18][2]))));
        Atk[18][2] = (((AiOiWi[18][2]*Cik[18][2][2])+((AiOiWi[18][0]*
          Cik[18][0][2])+(AiOiWi[18][1]*Cik[18][1][2])))+(((Otk[18][1]*rk[16][0]
          )-(Otk[18][0]*rk[16][1]))+((wk[18][0]*Wkrpk[18][1])-(wk[18][1]*
          Wkrpk[18][0]))));
        AiOiWi[19][0] = (Atk[18][0]+(((Otk[18][1]*ri[17][2])-(Otk[18][2]*
          ri[17][1]))+((Wirk[19][2]*wk[18][1])-(Wirk[19][1]*wk[18][2]))));
        AiOiWi[19][1] = (Atk[18][1]+(((Otk[18][2]*ri[17][0])-(Otk[18][0]*
          ri[17][2]))+((Wirk[19][0]*wk[18][2])-(Wirk[19][2]*wk[18][0]))));
        AiOiWi[19][2] = (Atk[18][2]+(((Otk[18][0]*ri[17][1])-(Otk[18][1]*
          ri[17][0]))+((Wirk[19][1]*wk[18][0])-(Wirk[19][0]*wk[18][1]))));
        Atk[19][0] = (((AiOiWi[19][2]*Cik[19][2][0])+((AiOiWi[19][0]*
          Cik[19][0][0])+(AiOiWi[19][1]*Cik[19][1][0])))+(((Otk[19][2]*rk[17][1]
          )-(Otk[19][1]*rk[17][2]))+((wk[19][1]*Wkrpk[19][2])-(wk[19][2]*
          Wkrpk[19][1]))));
        Atk[19][1] = (((AiOiWi[19][2]*Cik[19][2][1])+((AiOiWi[19][0]*
          Cik[19][0][1])+(AiOiWi[19][1]*Cik[19][1][1])))+(((Otk[19][0]*rk[17][2]
          )-(Otk[19][2]*rk[17][0]))+((wk[19][2]*Wkrpk[19][0])-(wk[19][0]*
          Wkrpk[19][2]))));
        Atk[19][2] = (((AiOiWi[19][2]*Cik[19][2][2])+((AiOiWi[19][0]*
          Cik[19][0][2])+(AiOiWi[19][1]*Cik[19][1][2])))+(((Otk[19][1]*rk[17][0]
          )-(Otk[19][0]*rk[17][1]))+((wk[19][0]*Wkrpk[19][1])-(wk[19][1]*
          Wkrpk[19][0]))));
        AiOiWi[20][0] = (Atk[19][0]+(((Otk[19][1]*ri[18][2])-(Otk[19][2]*
          ri[18][1]))+((Wirk[20][2]*wk[19][1])-(Wirk[20][1]*wk[19][2]))));
        AiOiWi[20][1] = (Atk[19][1]+(((Otk[19][2]*ri[18][0])-(Otk[19][0]*
          ri[18][2]))+((Wirk[20][0]*wk[19][2])-(Wirk[20][2]*wk[19][0]))));
        AiOiWi[20][2] = (Atk[19][2]+(((Otk[19][0]*ri[18][1])-(Otk[19][1]*
          ri[18][0]))+((Wirk[20][1]*wk[19][0])-(Wirk[20][0]*wk[19][1]))));
        Atk[20][0] = (((AiOiWi[20][2]*Cik[20][2][0])+((AiOiWi[20][0]*
          Cik[20][0][0])+(AiOiWi[20][1]*Cik[20][1][0])))+(((Otk[20][2]*rk[18][1]
          )-(Otk[20][1]*rk[18][2]))+((wk[20][1]*Wkrpk[20][2])-(wk[20][2]*
          Wkrpk[20][1]))));
        Atk[20][1] = (((AiOiWi[20][2]*Cik[20][2][1])+((AiOiWi[20][0]*
          Cik[20][0][1])+(AiOiWi[20][1]*Cik[20][1][1])))+(((Otk[20][0]*rk[18][2]
          )-(Otk[20][2]*rk[18][0]))+((wk[20][2]*Wkrpk[20][0])-(wk[20][0]*
          Wkrpk[20][2]))));
        Atk[20][2] = (((AiOiWi[20][2]*Cik[20][2][2])+((AiOiWi[20][0]*
          Cik[20][0][2])+(AiOiWi[20][1]*Cik[20][1][2])))+(((Otk[20][1]*rk[18][0]
          )-(Otk[20][0]*rk[18][1]))+((wk[20][0]*Wkrpk[20][1])-(wk[20][1]*
          Wkrpk[20][0]))));
        AiOiWi[21][0] = (Atk[20][0]+(((Otk[20][1]*ri[19][2])-(Otk[20][2]*
          ri[19][1]))+((Wirk[21][2]*wk[20][1])-(Wirk[21][1]*wk[20][2]))));
        AiOiWi[21][1] = (Atk[20][1]+(((Otk[20][2]*ri[19][0])-(Otk[20][0]*
          ri[19][2]))+((Wirk[21][0]*wk[20][2])-(Wirk[21][2]*wk[20][0]))));
        AiOiWi[21][2] = (Atk[20][2]+(((Otk[20][0]*ri[19][1])-(Otk[20][1]*
          ri[19][0]))+((Wirk[21][1]*wk[20][0])-(Wirk[21][0]*wk[20][1]))));
        Atk[21][0] = (((AiOiWi[21][2]*Cik[21][2][0])+((AiOiWi[21][0]*
          Cik[21][0][0])+(AiOiWi[21][1]*Cik[21][1][0])))+(((Otk[21][2]*
          psrk[21][1])-(Otk[21][1]*psrk[21][2]))+((wk[21][1]*Wkrpk[21][2])-(
          wk[21][2]*Wkrpk[21][1]))));
        Atk[21][1] = (((AiOiWi[21][2]*Cik[21][2][1])+((AiOiWi[21][0]*
          Cik[21][0][1])+(AiOiWi[21][1]*Cik[21][1][1])))+(((Otk[21][0]*
          psrk[21][2])-(Otk[21][2]*psrk[21][0]))+((wk[21][2]*Wkrpk[21][0])-(
          wk[21][0]*Wkrpk[21][2]))));
        Atk[21][2] = (((AiOiWi[21][2]*Cik[21][2][2])+((AiOiWi[21][0]*
          Cik[21][0][2])+(AiOiWi[21][1]*Cik[21][1][2])))+(((Otk[21][1]*
          psrk[21][0])-(Otk[21][0]*psrk[21][1]))+((wk[21][0]*Wkrpk[21][1])-(
          wk[21][1]*Wkrpk[21][0]))));
        inerflg = 1;
    }
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  615 adds/subtracts/negates
                    714 multiplies
                      0 divides
                    147 assignments
*/
}

void allegro_air_dofs0(void)
{

/*
Compute effect of all applied loads
*/
    if (fs0flg == 0) {
        allegro_air_doltau();
        allegro_air_doiner();
/*
Compute Fstar (forces)
*/
        Fstar[5][0] = ((mk[0]*(Atk[5][0]-gk[3][0]))-ufk[0][0]);
        Fstar[5][1] = ((mk[0]*(Atk[5][1]-gk[3][1]))-ufk[0][1]);
        Fstar[5][2] = ((mk[0]*(Atk[5][2]-gk[3][2]))-ufk[0][2]);
        Fstar[6][0] = ((mk[1]*(Atk[6][0]-gk[6][0]))-ufk[1][0]);
        Fstar[6][1] = ((mk[1]*(Atk[6][1]-gk[6][1]))-ufk[1][1]);
        Fstar[6][2] = ((mk[1]*(Atk[6][2]-gk[6][2]))-ufk[1][2]);
        Fstar[7][0] = ((mk[2]*(Atk[7][0]-gk[7][0]))-ufk[2][0]);
        Fstar[7][1] = ((mk[2]*(Atk[7][1]-gk[7][1]))-ufk[2][1]);
        Fstar[7][2] = ((mk[2]*(Atk[7][2]-gk[7][2]))-ufk[2][2]);
        Fstar[8][0] = ((mk[3]*(Atk[8][0]-gk[8][0]))-ufk[3][0]);
        Fstar[8][1] = ((mk[3]*(Atk[8][1]-gk[8][1]))-ufk[3][1]);
        Fstar[8][2] = ((mk[3]*(Atk[8][2]-gk[8][2]))-ufk[3][2]);
        Fstar[9][0] = (((psmk[9]*(Atk[9][0]-gk[9][0]))-ufk[4][0])-ufk[5][0]);
        Fstar[9][1] = (((psmk[9]*(Atk[9][1]-gk[9][1]))-ufk[4][1])-ufk[5][1]);
        Fstar[9][2] = (((psmk[9]*(Atk[9][2]-gk[9][2]))-ufk[4][2])-ufk[5][2]);
        Fstar[10][0] = ((mk[6]*(Atk[10][0]-gk[10][0]))-ufk[6][0]);
        Fstar[10][1] = ((mk[6]*(Atk[10][1]-gk[10][1]))-ufk[6][1]);
        Fstar[10][2] = ((mk[6]*(Atk[10][2]-gk[10][2]))-ufk[6][2]);
        Fstar[11][0] = ((mk[7]*(Atk[11][0]-gk[11][0]))-ufk[7][0]);
        Fstar[11][1] = ((mk[7]*(Atk[11][1]-gk[11][1]))-ufk[7][1]);
        Fstar[11][2] = ((mk[7]*(Atk[11][2]-gk[11][2]))-ufk[7][2]);
        Fstar[12][0] = ((mk[8]*(Atk[12][0]-gk[12][0]))-ufk[8][0]);
        Fstar[12][1] = ((mk[8]*(Atk[12][1]-gk[12][1]))-ufk[8][1]);
        Fstar[12][2] = ((mk[8]*(Atk[12][2]-gk[12][2]))-ufk[8][2]);
        Fstar[13][0] = (((psmk[13]*(Atk[13][0]-gk[13][0]))-ufk[9][0])-ufk[10][0]
          );
        Fstar[13][1] = (((psmk[13]*(Atk[13][1]-gk[13][1]))-ufk[9][1])-ufk[10][1]
          );
        Fstar[13][2] = (((psmk[13]*(Atk[13][2]-gk[13][2]))-ufk[9][2])-ufk[10][2]
          );
        Fstar[14][0] = ((mk[11]*(Atk[14][0]-gk[14][0]))-ufk[11][0]);
        Fstar[14][1] = ((mk[11]*(Atk[14][1]-gk[14][1]))-ufk[11][1]);
        Fstar[14][2] = ((mk[11]*(Atk[14][2]-gk[14][2]))-ufk[11][2]);
        Fstar[15][0] = ((mk[12]*(Atk[15][0]-gk[15][0]))-ufk[12][0]);
        Fstar[15][1] = ((mk[12]*(Atk[15][1]-gk[15][1]))-ufk[12][1]);
        Fstar[15][2] = ((mk[12]*(Atk[15][2]-gk[15][2]))-ufk[12][2]);
        Fstar[16][0] = ((mk[13]*(Atk[16][0]-gk[16][0]))-ufk[13][0]);
        Fstar[16][1] = ((mk[13]*(Atk[16][1]-gk[16][1]))-ufk[13][1]);
        Fstar[16][2] = ((mk[13]*(Atk[16][2]-gk[16][2]))-ufk[13][2]);
        Fstar[17][0] = (((psmk[17]*(Atk[17][0]-gk[17][0]))-ufk[14][0])-
          ufk[15][0]);
        Fstar[17][1] = (((psmk[17]*(Atk[17][1]-gk[17][1]))-ufk[14][1])-
          ufk[15][1]);
        Fstar[17][2] = (((psmk[17]*(Atk[17][2]-gk[17][2]))-ufk[14][2])-
          ufk[15][2]);
        Fstar[18][0] = ((mk[16]*(Atk[18][0]-gk[18][0]))-ufk[16][0]);
        Fstar[18][1] = ((mk[16]*(Atk[18][1]-gk[18][1]))-ufk[16][1]);
        Fstar[18][2] = ((mk[16]*(Atk[18][2]-gk[18][2]))-ufk[16][2]);
        Fstar[19][0] = ((mk[17]*(Atk[19][0]-gk[19][0]))-ufk[17][0]);
        Fstar[19][1] = ((mk[17]*(Atk[19][1]-gk[19][1]))-ufk[17][1]);
        Fstar[19][2] = ((mk[17]*(Atk[19][2]-gk[19][2]))-ufk[17][2]);
        Fstar[20][0] = ((mk[18]*(Atk[20][0]-gk[20][0]))-ufk[18][0]);
        Fstar[20][1] = ((mk[18]*(Atk[20][1]-gk[20][1]))-ufk[18][1]);
        Fstar[20][2] = ((mk[18]*(Atk[20][2]-gk[20][2]))-ufk[18][2]);
        Fstar[21][0] = (((psmk[21]*(Atk[21][0]-gk[21][0]))-ufk[19][0])-
          ufk[20][0]);
        Fstar[21][1] = (((psmk[21]*(Atk[21][1]-gk[21][1]))-ufk[19][1])-
          ufk[20][1]);
        Fstar[21][2] = (((psmk[21]*(Atk[21][2]-gk[21][2]))-ufk[19][2])-
          ufk[20][2]);
/*
Compute Tstar (torques)
*/
        Tstar[5][0] = (WkIkWk[5][0]-utk[0][0]);
        Tstar[5][1] = (WkIkWk[5][1]-utk[0][1]);
        Tstar[5][2] = (WkIkWk[5][2]-utk[0][2]);
        Tstar[6][0] = ((WkIkWk[6][0]+((ik[1][0][2]*Otk[6][2])+((ik[1][0][0]*
          Otk[6][0])+(ik[1][0][1]*Otk[6][1]))))-utk[1][0]);
        Tstar[6][1] = ((WkIkWk[6][1]+((ik[1][1][2]*Otk[6][2])+((ik[1][1][0]*
          Otk[6][0])+(ik[1][1][1]*Otk[6][1]))))-utk[1][1]);
        Tstar[6][2] = ((WkIkWk[6][2]+((ik[1][2][2]*Otk[6][2])+((ik[1][2][0]*
          Otk[6][0])+(ik[1][2][1]*Otk[6][1]))))-utk[1][2]);
        Tstar[7][0] = ((WkIkWk[7][0]+((ik[2][0][2]*Otk[7][2])+((ik[2][0][0]*
          Otk[7][0])+(ik[2][0][1]*Otk[7][1]))))-utk[2][0]);
        Tstar[7][1] = ((WkIkWk[7][1]+((ik[2][1][2]*Otk[7][2])+((ik[2][1][0]*
          Otk[7][0])+(ik[2][1][1]*Otk[7][1]))))-utk[2][1]);
        Tstar[7][2] = ((WkIkWk[7][2]+((ik[2][2][2]*Otk[7][2])+((ik[2][2][0]*
          Otk[7][0])+(ik[2][2][1]*Otk[7][1]))))-utk[2][2]);
        Tstar[8][0] = ((WkIkWk[8][0]+((ik[3][0][2]*Otk[8][2])+((ik[3][0][0]*
          Otk[8][0])+(ik[3][0][1]*Otk[8][1]))))-utk[3][0]);
        Tstar[8][1] = ((WkIkWk[8][1]+((ik[3][1][2]*Otk[8][2])+((ik[3][1][0]*
          Otk[8][0])+(ik[3][1][1]*Otk[8][1]))))-utk[3][1]);
        Tstar[8][2] = ((WkIkWk[8][2]+((ik[3][2][2]*Otk[8][2])+((ik[3][2][0]*
          Otk[8][0])+(ik[3][2][1]*Otk[8][1]))))-utk[3][2]);
        Tstar[9][0] = (((WkIkWk[9][0]+((Otk[9][2]*psik[9][0][2])+((Otk[9][0]*
          psik[9][0][0])+(Otk[9][1]*psik[9][0][1]))))-(utk[4][0]+((rcom[4][1]*
          ufk[4][2])-(rcom[4][2]*ufk[4][1]))))-(utk[5][0]+((rcom[5][1]*ufk[5][2]
          )-(rcom[5][2]*ufk[5][1]))));
        Tstar[9][1] = (((WkIkWk[9][1]+((Otk[9][2]*psik[9][1][2])+((Otk[9][0]*
          psik[9][1][0])+(Otk[9][1]*psik[9][1][1]))))-(utk[4][1]+((rcom[4][2]*
          ufk[4][0])-(rcom[4][0]*ufk[4][2]))))-(utk[5][1]+((rcom[5][2]*ufk[5][0]
          )-(rcom[5][0]*ufk[5][2]))));
        Tstar[9][2] = (((WkIkWk[9][2]+((Otk[9][2]*psik[9][2][2])+((Otk[9][0]*
          psik[9][2][0])+(Otk[9][1]*psik[9][2][1]))))-(utk[4][2]+((rcom[4][0]*
          ufk[4][1])-(rcom[4][1]*ufk[4][0]))))-(utk[5][2]+((rcom[5][0]*ufk[5][1]
          )-(rcom[5][1]*ufk[5][0]))));
        Tstar[10][0] = ((WkIkWk[10][0]+((ik[6][0][2]*Otk[10][2])+((ik[6][0][0]*
          Otk[10][0])+(ik[6][0][1]*Otk[10][1]))))-utk[6][0]);
        Tstar[10][1] = ((WkIkWk[10][1]+((ik[6][1][2]*Otk[10][2])+((ik[6][1][0]*
          Otk[10][0])+(ik[6][1][1]*Otk[10][1]))))-utk[6][1]);
        Tstar[10][2] = ((WkIkWk[10][2]+((ik[6][2][2]*Otk[10][2])+((ik[6][2][0]*
          Otk[10][0])+(ik[6][2][1]*Otk[10][1]))))-utk[6][2]);
        Tstar[11][0] = ((WkIkWk[11][0]+((ik[7][0][2]*Otk[11][2])+((ik[7][0][0]*
          Otk[11][0])+(ik[7][0][1]*Otk[11][1]))))-utk[7][0]);
        Tstar[11][1] = ((WkIkWk[11][1]+((ik[7][1][2]*Otk[11][2])+((ik[7][1][0]*
          Otk[11][0])+(ik[7][1][1]*Otk[11][1]))))-utk[7][1]);
        Tstar[11][2] = ((WkIkWk[11][2]+((ik[7][2][2]*Otk[11][2])+((ik[7][2][0]*
          Otk[11][0])+(ik[7][2][1]*Otk[11][1]))))-utk[7][2]);
        Tstar[12][0] = ((WkIkWk[12][0]+((ik[8][0][2]*Otk[12][2])+((ik[8][0][0]*
          Otk[12][0])+(ik[8][0][1]*Otk[12][1]))))-utk[8][0]);
        Tstar[12][1] = ((WkIkWk[12][1]+((ik[8][1][2]*Otk[12][2])+((ik[8][1][0]*
          Otk[12][0])+(ik[8][1][1]*Otk[12][1]))))-utk[8][1]);
        Tstar[12][2] = ((WkIkWk[12][2]+((ik[8][2][2]*Otk[12][2])+((ik[8][2][0]*
          Otk[12][0])+(ik[8][2][1]*Otk[12][1]))))-utk[8][2]);
        Tstar[13][0] = (((WkIkWk[13][0]+((Otk[13][2]*psik[13][0][2])+((
          Otk[13][0]*psik[13][0][0])+(Otk[13][1]*psik[13][0][1]))))-(utk[9][0]+(
          (rcom[9][1]*ufk[9][2])-(rcom[9][2]*ufk[9][1]))))-(utk[10][0]+((
          rcom[10][1]*ufk[10][2])-(rcom[10][2]*ufk[10][1]))));
        Tstar[13][1] = (((WkIkWk[13][1]+((Otk[13][2]*psik[13][1][2])+((
          Otk[13][0]*psik[13][1][0])+(Otk[13][1]*psik[13][1][1]))))-(utk[9][1]+(
          (rcom[9][2]*ufk[9][0])-(rcom[9][0]*ufk[9][2]))))-(utk[10][1]+((
          rcom[10][2]*ufk[10][0])-(rcom[10][0]*ufk[10][2]))));
        Tstar[13][2] = (((WkIkWk[13][2]+((Otk[13][2]*psik[13][2][2])+((
          Otk[13][0]*psik[13][2][0])+(Otk[13][1]*psik[13][2][1]))))-(utk[9][2]+(
          (rcom[9][0]*ufk[9][1])-(rcom[9][1]*ufk[9][0]))))-(utk[10][2]+((
          rcom[10][0]*ufk[10][1])-(rcom[10][1]*ufk[10][0]))));
        Tstar[14][0] = ((WkIkWk[14][0]+((ik[11][0][2]*Otk[14][2])+((ik[11][0][0]
          *Otk[14][0])+(ik[11][0][1]*Otk[14][1]))))-utk[11][0]);
        Tstar[14][1] = ((WkIkWk[14][1]+((ik[11][1][2]*Otk[14][2])+((ik[11][1][0]
          *Otk[14][0])+(ik[11][1][1]*Otk[14][1]))))-utk[11][1]);
        Tstar[14][2] = ((WkIkWk[14][2]+((ik[11][2][2]*Otk[14][2])+((ik[11][2][0]
          *Otk[14][0])+(ik[11][2][1]*Otk[14][1]))))-utk[11][2]);
        Tstar[15][0] = ((WkIkWk[15][0]+((ik[12][0][2]*Otk[15][2])+((ik[12][0][0]
          *Otk[15][0])+(ik[12][0][1]*Otk[15][1]))))-utk[12][0]);
        Tstar[15][1] = ((WkIkWk[15][1]+((ik[12][1][2]*Otk[15][2])+((ik[12][1][0]
          *Otk[15][0])+(ik[12][1][1]*Otk[15][1]))))-utk[12][1]);
        Tstar[15][2] = ((WkIkWk[15][2]+((ik[12][2][2]*Otk[15][2])+((ik[12][2][0]
          *Otk[15][0])+(ik[12][2][1]*Otk[15][1]))))-utk[12][2]);
        Tstar[16][0] = ((WkIkWk[16][0]+((ik[13][0][2]*Otk[16][2])+((ik[13][0][0]
          *Otk[16][0])+(ik[13][0][1]*Otk[16][1]))))-utk[13][0]);
        Tstar[16][1] = ((WkIkWk[16][1]+((ik[13][1][2]*Otk[16][2])+((ik[13][1][0]
          *Otk[16][0])+(ik[13][1][1]*Otk[16][1]))))-utk[13][1]);
        Tstar[16][2] = ((WkIkWk[16][2]+((ik[13][2][2]*Otk[16][2])+((ik[13][2][0]
          *Otk[16][0])+(ik[13][2][1]*Otk[16][1]))))-utk[13][2]);
        Tstar[17][0] = (((WkIkWk[17][0]+((Otk[17][2]*psik[17][0][2])+((
          Otk[17][0]*psik[17][0][0])+(Otk[17][1]*psik[17][0][1]))))-(utk[14][0]+
          ((rcom[14][1]*ufk[14][2])-(rcom[14][2]*ufk[14][1]))))-(utk[15][0]+((
          rcom[15][1]*ufk[15][2])-(rcom[15][2]*ufk[15][1]))));
        Tstar[17][1] = (((WkIkWk[17][1]+((Otk[17][2]*psik[17][1][2])+((
          Otk[17][0]*psik[17][1][0])+(Otk[17][1]*psik[17][1][1]))))-(utk[14][1]+
          ((rcom[14][2]*ufk[14][0])-(rcom[14][0]*ufk[14][2]))))-(utk[15][1]+((
          rcom[15][2]*ufk[15][0])-(rcom[15][0]*ufk[15][2]))));
        Tstar[17][2] = (((WkIkWk[17][2]+((Otk[17][2]*psik[17][2][2])+((
          Otk[17][0]*psik[17][2][0])+(Otk[17][1]*psik[17][2][1]))))-(utk[14][2]+
          ((rcom[14][0]*ufk[14][1])-(rcom[14][1]*ufk[14][0]))))-(utk[15][2]+((
          rcom[15][0]*ufk[15][1])-(rcom[15][1]*ufk[15][0]))));
        Tstar[18][0] = ((WkIkWk[18][0]+((ik[16][0][2]*Otk[18][2])+((ik[16][0][0]
          *Otk[18][0])+(ik[16][0][1]*Otk[18][1]))))-utk[16][0]);
        Tstar[18][1] = ((WkIkWk[18][1]+((ik[16][1][2]*Otk[18][2])+((ik[16][1][0]
          *Otk[18][0])+(ik[16][1][1]*Otk[18][1]))))-utk[16][1]);
        Tstar[18][2] = ((WkIkWk[18][2]+((ik[16][2][2]*Otk[18][2])+((ik[16][2][0]
          *Otk[18][0])+(ik[16][2][1]*Otk[18][1]))))-utk[16][2]);
        Tstar[19][0] = ((WkIkWk[19][0]+((ik[17][0][2]*Otk[19][2])+((ik[17][0][0]
          *Otk[19][0])+(ik[17][0][1]*Otk[19][1]))))-utk[17][0]);
        Tstar[19][1] = ((WkIkWk[19][1]+((ik[17][1][2]*Otk[19][2])+((ik[17][1][0]
          *Otk[19][0])+(ik[17][1][1]*Otk[19][1]))))-utk[17][1]);
        Tstar[19][2] = ((WkIkWk[19][2]+((ik[17][2][2]*Otk[19][2])+((ik[17][2][0]
          *Otk[19][0])+(ik[17][2][1]*Otk[19][1]))))-utk[17][2]);
        Tstar[20][0] = ((WkIkWk[20][0]+((ik[18][0][2]*Otk[20][2])+((ik[18][0][0]
          *Otk[20][0])+(ik[18][0][1]*Otk[20][1]))))-utk[18][0]);
        Tstar[20][1] = ((WkIkWk[20][1]+((ik[18][1][2]*Otk[20][2])+((ik[18][1][0]
          *Otk[20][0])+(ik[18][1][1]*Otk[20][1]))))-utk[18][1]);
        Tstar[20][2] = ((WkIkWk[20][2]+((ik[18][2][2]*Otk[20][2])+((ik[18][2][0]
          *Otk[20][0])+(ik[18][2][1]*Otk[20][1]))))-utk[18][2]);
        Tstar[21][0] = (((WkIkWk[21][0]+((Otk[21][2]*psik[21][0][2])+((
          Otk[21][0]*psik[21][0][0])+(Otk[21][1]*psik[21][0][1]))))-(utk[19][0]+
          ((rcom[19][1]*ufk[19][2])-(rcom[19][2]*ufk[19][1]))))-(utk[20][0]+((
          rcom[20][1]*ufk[20][2])-(rcom[20][2]*ufk[20][1]))));
        Tstar[21][1] = (((WkIkWk[21][1]+((Otk[21][2]*psik[21][1][2])+((
          Otk[21][0]*psik[21][1][0])+(Otk[21][1]*psik[21][1][1]))))-(utk[19][1]+
          ((rcom[19][2]*ufk[19][0])-(rcom[19][0]*ufk[19][2]))))-(utk[20][1]+((
          rcom[20][2]*ufk[20][0])-(rcom[20][0]*ufk[20][2]))));
        Tstar[21][2] = (((WkIkWk[21][2]+((Otk[21][2]*psik[21][2][2])+((
          Otk[21][0]*psik[21][2][0])+(Otk[21][1]*psik[21][2][1]))))-(utk[19][2]+
          ((rcom[19][0]*ufk[19][1])-(rcom[19][1]*ufk[19][0]))))-(utk[20][2]+((
          rcom[20][0]*ufk[20][1])-(rcom[20][1]*ufk[20][0]))));
/*
Compute fs0 (RHS ignoring constraints)
*/
        allegro_air_dovpk();
        temp[0] = (((Fstar[8][2]*Vpk[0][8][2])+((Fstar[8][0]*Vpk[0][8][0])+(
          Fstar[8][1]*Vpk[0][8][1])))+(((Fstar[7][2]*Vpk[0][7][2])+((Fstar[7][0]
          *Vpk[0][7][0])+(Fstar[7][1]*Vpk[0][7][1])))+(((Fstar[5][2]*
          Vpk[0][3][2])+((Fstar[5][0]*Vpk[0][3][0])+(Fstar[5][1]*Vpk[0][3][1])))
          +((Fstar[6][2]*Vpk[0][6][2])+((Fstar[6][0]*Vpk[0][6][0])+(Fstar[6][1]*
          Vpk[0][6][1]))))));
        temp[1] = (((Fstar[12][2]*Vpk[0][12][2])+((Fstar[12][0]*Vpk[0][12][0])+(
          Fstar[12][1]*Vpk[0][12][1])))+(((Fstar[11][2]*Vpk[0][11][2])+((
          Fstar[11][0]*Vpk[0][11][0])+(Fstar[11][1]*Vpk[0][11][1])))+(((
          Fstar[10][2]*Vpk[0][10][2])+((Fstar[10][0]*Vpk[0][10][0])+(
          Fstar[10][1]*Vpk[0][10][1])))+(((Fstar[9][2]*Vpk[0][9][2])+((
          Fstar[9][0]*Vpk[0][9][0])+(Fstar[9][1]*Vpk[0][9][1])))+temp[0]))));
        temp[2] = (((Fstar[16][2]*Vpk[0][16][2])+((Fstar[16][0]*Vpk[0][16][0])+(
          Fstar[16][1]*Vpk[0][16][1])))+(((Fstar[15][2]*Vpk[0][15][2])+((
          Fstar[15][0]*Vpk[0][15][0])+(Fstar[15][1]*Vpk[0][15][1])))+(((
          Fstar[14][2]*Vpk[0][14][2])+((Fstar[14][0]*Vpk[0][14][0])+(
          Fstar[14][1]*Vpk[0][14][1])))+(((Fstar[13][2]*Vpk[0][13][2])+((
          Fstar[13][0]*Vpk[0][13][0])+(Fstar[13][1]*Vpk[0][13][1])))+temp[1]))))
          ;
        temp[3] = (((Fstar[20][2]*Vpk[0][20][2])+((Fstar[20][0]*Vpk[0][20][0])+(
          Fstar[20][1]*Vpk[0][20][1])))+(((Fstar[19][2]*Vpk[0][19][2])+((
          Fstar[19][0]*Vpk[0][19][0])+(Fstar[19][1]*Vpk[0][19][1])))+(((
          Fstar[18][2]*Vpk[0][18][2])+((Fstar[18][0]*Vpk[0][18][0])+(
          Fstar[18][1]*Vpk[0][18][1])))+(((Fstar[17][2]*Vpk[0][17][2])+((
          Fstar[17][0]*Vpk[0][17][0])+(Fstar[17][1]*Vpk[0][17][1])))+temp[2]))))
          ;
        fs0[0] = (utau[0]-(((Fstar[21][2]*Vpk[0][21][2])+((Fstar[21][0]*
          Vpk[0][21][0])+(Fstar[21][1]*Vpk[0][21][1])))+temp[3]));
        temp[0] = (((Fstar[8][2]*Vpk[1][8][2])+((Fstar[8][0]*Vpk[1][8][0])+(
          Fstar[8][1]*Vpk[1][8][1])))+(((Fstar[7][2]*Vpk[1][7][2])+((Fstar[7][0]
          *Vpk[1][7][0])+(Fstar[7][1]*Vpk[1][7][1])))+(((Fstar[5][2]*
          Vpk[1][3][2])+((Fstar[5][0]*Vpk[1][3][0])+(Fstar[5][1]*Vpk[1][3][1])))
          +((Fstar[6][2]*Vpk[1][6][2])+((Fstar[6][0]*Vpk[1][6][0])+(Fstar[6][1]*
          Vpk[1][6][1]))))));
        temp[1] = (((Fstar[12][2]*Vpk[1][12][2])+((Fstar[12][0]*Vpk[1][12][0])+(
          Fstar[12][1]*Vpk[1][12][1])))+(((Fstar[11][2]*Vpk[1][11][2])+((
          Fstar[11][0]*Vpk[1][11][0])+(Fstar[11][1]*Vpk[1][11][1])))+(((
          Fstar[10][2]*Vpk[1][10][2])+((Fstar[10][0]*Vpk[1][10][0])+(
          Fstar[10][1]*Vpk[1][10][1])))+(((Fstar[9][2]*Vpk[1][9][2])+((
          Fstar[9][0]*Vpk[1][9][0])+(Fstar[9][1]*Vpk[1][9][1])))+temp[0]))));
        temp[2] = (((Fstar[16][2]*Vpk[1][16][2])+((Fstar[16][0]*Vpk[1][16][0])+(
          Fstar[16][1]*Vpk[1][16][1])))+(((Fstar[15][2]*Vpk[1][15][2])+((
          Fstar[15][0]*Vpk[1][15][0])+(Fstar[15][1]*Vpk[1][15][1])))+(((
          Fstar[14][2]*Vpk[1][14][2])+((Fstar[14][0]*Vpk[1][14][0])+(
          Fstar[14][1]*Vpk[1][14][1])))+(((Fstar[13][2]*Vpk[1][13][2])+((
          Fstar[13][0]*Vpk[1][13][0])+(Fstar[13][1]*Vpk[1][13][1])))+temp[1]))))
          ;
        temp[3] = (((Fstar[20][2]*Vpk[1][20][2])+((Fstar[20][0]*Vpk[1][20][0])+(
          Fstar[20][1]*Vpk[1][20][1])))+(((Fstar[19][2]*Vpk[1][19][2])+((
          Fstar[19][0]*Vpk[1][19][0])+(Fstar[19][1]*Vpk[1][19][1])))+(((
          Fstar[18][2]*Vpk[1][18][2])+((Fstar[18][0]*Vpk[1][18][0])+(
          Fstar[18][1]*Vpk[1][18][1])))+(((Fstar[17][2]*Vpk[1][17][2])+((
          Fstar[17][0]*Vpk[1][17][0])+(Fstar[17][1]*Vpk[1][17][1])))+temp[2]))))
          ;
        fs0[1] = (utau[1]-(((Fstar[21][2]*Vpk[1][21][2])+((Fstar[21][0]*
          Vpk[1][21][0])+(Fstar[21][1]*Vpk[1][21][1])))+temp[3]));
        temp[0] = (((Fstar[8][2]*Vpk[2][8][2])+((Fstar[8][0]*Vpk[2][8][0])+(
          Fstar[8][1]*Vpk[2][8][1])))+(((Fstar[7][2]*Vpk[2][7][2])+((Fstar[7][0]
          *Vpk[2][7][0])+(Fstar[7][1]*Vpk[2][7][1])))+(((Fstar[5][2]*
          Vpk[2][3][2])+((Fstar[5][0]*Vpk[2][3][0])+(Fstar[5][1]*Vpk[2][3][1])))
          +((Fstar[6][2]*Vpk[2][6][2])+((Fstar[6][0]*Vpk[2][6][0])+(Fstar[6][1]*
          Vpk[2][6][1]))))));
        temp[1] = (((Fstar[12][2]*Vpk[2][12][2])+((Fstar[12][0]*Vpk[2][12][0])+(
          Fstar[12][1]*Vpk[2][12][1])))+(((Fstar[11][2]*Vpk[2][11][2])+((
          Fstar[11][0]*Vpk[2][11][0])+(Fstar[11][1]*Vpk[2][11][1])))+(((
          Fstar[10][2]*Vpk[2][10][2])+((Fstar[10][0]*Vpk[2][10][0])+(
          Fstar[10][1]*Vpk[2][10][1])))+(((Fstar[9][2]*Vpk[2][9][2])+((
          Fstar[9][0]*Vpk[2][9][0])+(Fstar[9][1]*Vpk[2][9][1])))+temp[0]))));
        temp[2] = (((Fstar[16][2]*Vpk[2][16][2])+((Fstar[16][0]*Vpk[2][16][0])+(
          Fstar[16][1]*Vpk[2][16][1])))+(((Fstar[15][2]*Vpk[2][15][2])+((
          Fstar[15][0]*Vpk[2][15][0])+(Fstar[15][1]*Vpk[2][15][1])))+(((
          Fstar[14][2]*Vpk[2][14][2])+((Fstar[14][0]*Vpk[2][14][0])+(
          Fstar[14][1]*Vpk[2][14][1])))+(((Fstar[13][2]*Vpk[2][13][2])+((
          Fstar[13][0]*Vpk[2][13][0])+(Fstar[13][1]*Vpk[2][13][1])))+temp[1]))))
          ;
        temp[3] = (((Fstar[20][2]*Vpk[2][20][2])+((Fstar[20][0]*Vpk[2][20][0])+(
          Fstar[20][1]*Vpk[2][20][1])))+(((Fstar[19][2]*Vpk[2][19][2])+((
          Fstar[19][0]*Vpk[2][19][0])+(Fstar[19][1]*Vpk[2][19][1])))+(((
          Fstar[18][2]*Vpk[2][18][2])+((Fstar[18][0]*Vpk[2][18][0])+(
          Fstar[18][1]*Vpk[2][18][1])))+(((Fstar[17][2]*Vpk[2][17][2])+((
          Fstar[17][0]*Vpk[2][17][0])+(Fstar[17][1]*Vpk[2][17][1])))+temp[2]))))
          ;
        fs0[2] = (utau[2]-(((Fstar[21][2]*Vpk[2][21][2])+((Fstar[21][0]*
          Vpk[2][21][0])+(Fstar[21][1]*Vpk[2][21][1])))+temp[3]));
        temp[0] = (((Tstar[5][0]+((Fstar[5][1]*rk[0][2])-(Fstar[5][2]*rk[0][1]))
          )+(((Cik[6][0][2]*Tstar[6][2])+((Cik[6][0][0]*Tstar[6][0])+(
          Cik[6][0][1]*Tstar[6][1])))+((Fstar[6][2]*Vpk[3][6][2])+((Fstar[6][0]*
          Vpk[3][6][0])+(Fstar[6][1]*Vpk[3][6][1])))))+(((Fstar[7][2]*
          Vpk[3][7][2])+((Fstar[7][0]*Vpk[3][7][0])+(Fstar[7][1]*Vpk[3][7][1])))
          +((Tstar[7][2]*Wpk[3][7][2])+((Tstar[7][0]*Wpk[3][7][0])+(Tstar[7][1]*
          Wpk[3][7][1])))));
        temp[1] = ((((Fstar[9][2]*Vpk[3][9][2])+((Fstar[9][0]*Vpk[3][9][0])+(
          Fstar[9][1]*Vpk[3][9][1])))+((Tstar[9][2]*Wpk[3][9][2])+((Tstar[9][0]*
          Wpk[3][9][0])+(Tstar[9][1]*Wpk[3][9][1]))))+((((Fstar[8][2]*
          Vpk[3][8][2])+((Fstar[8][0]*Vpk[3][8][0])+(Fstar[8][1]*Vpk[3][8][1])))
          +((Tstar[8][2]*Wpk[3][8][2])+((Tstar[8][0]*Wpk[3][8][0])+(Tstar[8][1]*
          Wpk[3][8][1]))))+temp[0]));
        temp[2] = ((((Fstar[11][2]*Vpk[3][11][2])+((Fstar[11][0]*Vpk[3][11][0])+
          (Fstar[11][1]*Vpk[3][11][1])))+((Tstar[11][2]*Wpk[3][11][2])+((
          Tstar[11][0]*Wpk[3][11][0])+(Tstar[11][1]*Wpk[3][11][1]))))+((((
          Cik[10][0][2]*Tstar[10][2])+((Cik[10][0][0]*Tstar[10][0])+(
          Cik[10][0][1]*Tstar[10][1])))+((Fstar[10][2]*Vpk[3][10][2])+((
          Fstar[10][0]*Vpk[3][10][0])+(Fstar[10][1]*Vpk[3][10][1]))))+temp[1]));
        temp[3] = ((((Fstar[13][2]*Vpk[3][13][2])+((Fstar[13][0]*Vpk[3][13][0])+
          (Fstar[13][1]*Vpk[3][13][1])))+((Tstar[13][2]*Wpk[3][13][2])+((
          Tstar[13][0]*Wpk[3][13][0])+(Tstar[13][1]*Wpk[3][13][1]))))+((((
          Fstar[12][2]*Vpk[3][12][2])+((Fstar[12][0]*Vpk[3][12][0])+(
          Fstar[12][1]*Vpk[3][12][1])))+((Tstar[12][2]*Wpk[3][12][2])+((
          Tstar[12][0]*Wpk[3][12][0])+(Tstar[12][1]*Wpk[3][12][1]))))+temp[2]));
        temp[4] = ((((Fstar[15][2]*Vpk[3][15][2])+((Fstar[15][0]*Vpk[3][15][0])+
          (Fstar[15][1]*Vpk[3][15][1])))+((Tstar[15][2]*Wpk[3][15][2])+((
          Tstar[15][0]*Wpk[3][15][0])+(Tstar[15][1]*Wpk[3][15][1]))))+((((
          Cik[14][0][2]*Tstar[14][2])+((Cik[14][0][0]*Tstar[14][0])+(
          Cik[14][0][1]*Tstar[14][1])))+((Fstar[14][2]*Vpk[3][14][2])+((
          Fstar[14][0]*Vpk[3][14][0])+(Fstar[14][1]*Vpk[3][14][1]))))+temp[3]));
        temp[5] = ((((Fstar[17][2]*Vpk[3][17][2])+((Fstar[17][0]*Vpk[3][17][0])+
          (Fstar[17][1]*Vpk[3][17][1])))+((Tstar[17][2]*Wpk[3][17][2])+((
          Tstar[17][0]*Wpk[3][17][0])+(Tstar[17][1]*Wpk[3][17][1]))))+((((
          Fstar[16][2]*Vpk[3][16][2])+((Fstar[16][0]*Vpk[3][16][0])+(
          Fstar[16][1]*Vpk[3][16][1])))+((Tstar[16][2]*Wpk[3][16][2])+((
          Tstar[16][0]*Wpk[3][16][0])+(Tstar[16][1]*Wpk[3][16][1]))))+temp[4]));
        temp[6] = ((((Fstar[19][2]*Vpk[3][19][2])+((Fstar[19][0]*Vpk[3][19][0])+
          (Fstar[19][1]*Vpk[3][19][1])))+((Tstar[19][2]*Wpk[3][19][2])+((
          Tstar[19][0]*Wpk[3][19][0])+(Tstar[19][1]*Wpk[3][19][1]))))+((((
          Cik[18][0][2]*Tstar[18][2])+((Cik[18][0][0]*Tstar[18][0])+(
          Cik[18][0][1]*Tstar[18][1])))+((Fstar[18][2]*Vpk[3][18][2])+((
          Fstar[18][0]*Vpk[3][18][0])+(Fstar[18][1]*Vpk[3][18][1]))))+temp[5]));
        fs0[3] = (utau[3]-((((Fstar[21][2]*Vpk[3][21][2])+((Fstar[21][0]*
          Vpk[3][21][0])+(Fstar[21][1]*Vpk[3][21][1])))+((Tstar[21][2]*
          Wpk[3][21][2])+((Tstar[21][0]*Wpk[3][21][0])+(Tstar[21][1]*
          Wpk[3][21][1]))))+((((Fstar[20][2]*Vpk[3][20][2])+((Fstar[20][0]*
          Vpk[3][20][0])+(Fstar[20][1]*Vpk[3][20][1])))+((Tstar[20][2]*
          Wpk[3][20][2])+((Tstar[20][0]*Wpk[3][20][0])+(Tstar[20][1]*
          Wpk[3][20][1]))))+temp[6])));
        temp[0] = (((Tstar[5][1]+((Fstar[5][2]*rk[0][0])-(Fstar[5][0]*rk[0][2]))
          )+(((Cik[6][1][2]*Tstar[6][2])+((Cik[6][1][0]*Tstar[6][0])+(
          Cik[6][1][1]*Tstar[6][1])))+((Fstar[6][2]*Vpk[4][6][2])+((Fstar[6][0]*
          Vpk[4][6][0])+(Fstar[6][1]*Vpk[4][6][1])))))+(((Fstar[7][2]*
          Vpk[4][7][2])+((Fstar[7][0]*Vpk[4][7][0])+(Fstar[7][1]*Vpk[4][7][1])))
          +((Tstar[7][2]*Wpk[4][7][2])+((Tstar[7][0]*Wpk[4][7][0])+(Tstar[7][1]*
          Wpk[4][7][1])))));
        temp[1] = ((((Fstar[9][2]*Vpk[4][9][2])+((Fstar[9][0]*Vpk[4][9][0])+(
          Fstar[9][1]*Vpk[4][9][1])))+((Tstar[9][2]*Wpk[4][9][2])+((Tstar[9][0]*
          Wpk[4][9][0])+(Tstar[9][1]*Wpk[4][9][1]))))+((((Fstar[8][2]*
          Vpk[4][8][2])+((Fstar[8][0]*Vpk[4][8][0])+(Fstar[8][1]*Vpk[4][8][1])))
          +((Tstar[8][2]*Wpk[4][8][2])+((Tstar[8][0]*Wpk[4][8][0])+(Tstar[8][1]*
          Wpk[4][8][1]))))+temp[0]));
        temp[2] = ((((Fstar[11][2]*Vpk[4][11][2])+((Fstar[11][0]*Vpk[4][11][0])+
          (Fstar[11][1]*Vpk[4][11][1])))+((Tstar[11][2]*Wpk[4][11][2])+((
          Tstar[11][0]*Wpk[4][11][0])+(Tstar[11][1]*Wpk[4][11][1]))))+((((
          Cik[10][1][2]*Tstar[10][2])+((Cik[10][1][0]*Tstar[10][0])+(
          Cik[10][1][1]*Tstar[10][1])))+((Fstar[10][2]*Vpk[4][10][2])+((
          Fstar[10][0]*Vpk[4][10][0])+(Fstar[10][1]*Vpk[4][10][1]))))+temp[1]));
        temp[3] = ((((Fstar[13][2]*Vpk[4][13][2])+((Fstar[13][0]*Vpk[4][13][0])+
          (Fstar[13][1]*Vpk[4][13][1])))+((Tstar[13][2]*Wpk[4][13][2])+((
          Tstar[13][0]*Wpk[4][13][0])+(Tstar[13][1]*Wpk[4][13][1]))))+((((
          Fstar[12][2]*Vpk[4][12][2])+((Fstar[12][0]*Vpk[4][12][0])+(
          Fstar[12][1]*Vpk[4][12][1])))+((Tstar[12][2]*Wpk[4][12][2])+((
          Tstar[12][0]*Wpk[4][12][0])+(Tstar[12][1]*Wpk[4][12][1]))))+temp[2]));
        temp[4] = ((((Fstar[15][2]*Vpk[4][15][2])+((Fstar[15][0]*Vpk[4][15][0])+
          (Fstar[15][1]*Vpk[4][15][1])))+((Tstar[15][2]*Wpk[4][15][2])+((
          Tstar[15][0]*Wpk[4][15][0])+(Tstar[15][1]*Wpk[4][15][1]))))+((((
          Cik[14][1][2]*Tstar[14][2])+((Cik[14][1][0]*Tstar[14][0])+(
          Cik[14][1][1]*Tstar[14][1])))+((Fstar[14][2]*Vpk[4][14][2])+((
          Fstar[14][0]*Vpk[4][14][0])+(Fstar[14][1]*Vpk[4][14][1]))))+temp[3]));
        temp[5] = ((((Fstar[17][2]*Vpk[4][17][2])+((Fstar[17][0]*Vpk[4][17][0])+
          (Fstar[17][1]*Vpk[4][17][1])))+((Tstar[17][2]*Wpk[4][17][2])+((
          Tstar[17][0]*Wpk[4][17][0])+(Tstar[17][1]*Wpk[4][17][1]))))+((((
          Fstar[16][2]*Vpk[4][16][2])+((Fstar[16][0]*Vpk[4][16][0])+(
          Fstar[16][1]*Vpk[4][16][1])))+((Tstar[16][2]*Wpk[4][16][2])+((
          Tstar[16][0]*Wpk[4][16][0])+(Tstar[16][1]*Wpk[4][16][1]))))+temp[4]));
        temp[6] = ((((Fstar[19][2]*Vpk[4][19][2])+((Fstar[19][0]*Vpk[4][19][0])+
          (Fstar[19][1]*Vpk[4][19][1])))+((Tstar[19][2]*Wpk[4][19][2])+((
          Tstar[19][0]*Wpk[4][19][0])+(Tstar[19][1]*Wpk[4][19][1]))))+((((
          Cik[18][1][2]*Tstar[18][2])+((Cik[18][1][0]*Tstar[18][0])+(
          Cik[18][1][1]*Tstar[18][1])))+((Fstar[18][2]*Vpk[4][18][2])+((
          Fstar[18][0]*Vpk[4][18][0])+(Fstar[18][1]*Vpk[4][18][1]))))+temp[5]));
        fs0[4] = (utau[4]-((((Fstar[21][2]*Vpk[4][21][2])+((Fstar[21][0]*
          Vpk[4][21][0])+(Fstar[21][1]*Vpk[4][21][1])))+((Tstar[21][2]*
          Wpk[4][21][2])+((Tstar[21][0]*Wpk[4][21][0])+(Tstar[21][1]*
          Wpk[4][21][1]))))+((((Fstar[20][2]*Vpk[4][20][2])+((Fstar[20][0]*
          Vpk[4][20][0])+(Fstar[20][1]*Vpk[4][20][1])))+((Tstar[20][2]*
          Wpk[4][20][2])+((Tstar[20][0]*Wpk[4][20][0])+(Tstar[20][1]*
          Wpk[4][20][1]))))+temp[6])));
        temp[0] = (((Tstar[5][2]+((Fstar[5][0]*rk[0][1])-(Fstar[5][1]*rk[0][0]))
          )+(((Cik[6][2][2]*Tstar[6][2])+((Cik[6][2][0]*Tstar[6][0])+(
          Cik[6][2][1]*Tstar[6][1])))+((Fstar[6][2]*Vpk[5][6][2])+((Fstar[6][0]*
          Vpk[5][6][0])+(Fstar[6][1]*Vpk[5][6][1])))))+(((Fstar[7][2]*
          Vpk[5][7][2])+((Fstar[7][0]*Vpk[5][7][0])+(Fstar[7][1]*Vpk[5][7][1])))
          +((Tstar[7][2]*Wpk[5][7][2])+((Tstar[7][0]*Wpk[5][7][0])+(Tstar[7][1]*
          Wpk[5][7][1])))));
        temp[1] = ((((Fstar[9][2]*Vpk[5][9][2])+((Fstar[9][0]*Vpk[5][9][0])+(
          Fstar[9][1]*Vpk[5][9][1])))+((Tstar[9][2]*Wpk[5][9][2])+((Tstar[9][0]*
          Wpk[5][9][0])+(Tstar[9][1]*Wpk[5][9][1]))))+((((Fstar[8][2]*
          Vpk[5][8][2])+((Fstar[8][0]*Vpk[5][8][0])+(Fstar[8][1]*Vpk[5][8][1])))
          +((Tstar[8][2]*Wpk[5][8][2])+((Tstar[8][0]*Wpk[5][8][0])+(Tstar[8][1]*
          Wpk[5][8][1]))))+temp[0]));
        temp[2] = ((((Fstar[11][2]*Vpk[5][11][2])+((Fstar[11][0]*Vpk[5][11][0])+
          (Fstar[11][1]*Vpk[5][11][1])))+((Tstar[11][2]*Wpk[5][11][2])+((
          Tstar[11][0]*Wpk[5][11][0])+(Tstar[11][1]*Wpk[5][11][1]))))+((((
          Cik[10][2][2]*Tstar[10][2])+((Cik[10][2][0]*Tstar[10][0])+(
          Cik[10][2][1]*Tstar[10][1])))+((Fstar[10][2]*Vpk[5][10][2])+((
          Fstar[10][0]*Vpk[5][10][0])+(Fstar[10][1]*Vpk[5][10][1]))))+temp[1]));
        temp[3] = ((((Fstar[13][2]*Vpk[5][13][2])+((Fstar[13][0]*Vpk[5][13][0])+
          (Fstar[13][1]*Vpk[5][13][1])))+((Tstar[13][2]*Wpk[5][13][2])+((
          Tstar[13][0]*Wpk[5][13][0])+(Tstar[13][1]*Wpk[5][13][1]))))+((((
          Fstar[12][2]*Vpk[5][12][2])+((Fstar[12][0]*Vpk[5][12][0])+(
          Fstar[12][1]*Vpk[5][12][1])))+((Tstar[12][2]*Wpk[5][12][2])+((
          Tstar[12][0]*Wpk[5][12][0])+(Tstar[12][1]*Wpk[5][12][1]))))+temp[2]));
        temp[4] = ((((Fstar[15][2]*Vpk[5][15][2])+((Fstar[15][0]*Vpk[5][15][0])+
          (Fstar[15][1]*Vpk[5][15][1])))+((Tstar[15][2]*Wpk[5][15][2])+((
          Tstar[15][0]*Wpk[5][15][0])+(Tstar[15][1]*Wpk[5][15][1]))))+((((
          Cik[14][2][2]*Tstar[14][2])+((Cik[14][2][0]*Tstar[14][0])+(
          Cik[14][2][1]*Tstar[14][1])))+((Fstar[14][2]*Vpk[5][14][2])+((
          Fstar[14][0]*Vpk[5][14][0])+(Fstar[14][1]*Vpk[5][14][1]))))+temp[3]));
        temp[5] = ((((Fstar[17][2]*Vpk[5][17][2])+((Fstar[17][0]*Vpk[5][17][0])+
          (Fstar[17][1]*Vpk[5][17][1])))+((Tstar[17][2]*Wpk[5][17][2])+((
          Tstar[17][0]*Wpk[5][17][0])+(Tstar[17][1]*Wpk[5][17][1]))))+((((
          Fstar[16][2]*Vpk[5][16][2])+((Fstar[16][0]*Vpk[5][16][0])+(
          Fstar[16][1]*Vpk[5][16][1])))+((Tstar[16][2]*Wpk[5][16][2])+((
          Tstar[16][0]*Wpk[5][16][0])+(Tstar[16][1]*Wpk[5][16][1]))))+temp[4]));
        temp[6] = ((((Fstar[19][2]*Vpk[5][19][2])+((Fstar[19][0]*Vpk[5][19][0])+
          (Fstar[19][1]*Vpk[5][19][1])))+((Tstar[19][2]*Wpk[5][19][2])+((
          Tstar[19][0]*Wpk[5][19][0])+(Tstar[19][1]*Wpk[5][19][1]))))+((((
          Cik[18][2][2]*Tstar[18][2])+((Cik[18][2][0]*Tstar[18][0])+(
          Cik[18][2][1]*Tstar[18][1])))+((Fstar[18][2]*Vpk[5][18][2])+((
          Fstar[18][0]*Vpk[5][18][0])+(Fstar[18][1]*Vpk[5][18][1]))))+temp[5]));
        fs0[5] = (utau[5]-((((Fstar[21][2]*Vpk[5][21][2])+((Fstar[21][0]*
          Vpk[5][21][0])+(Fstar[21][1]*Vpk[5][21][1])))+((Tstar[21][2]*
          Wpk[5][21][2])+((Tstar[21][0]*Wpk[5][21][0])+(Tstar[21][1]*
          Wpk[5][21][1]))))+((((Fstar[20][2]*Vpk[5][20][2])+((Fstar[20][0]*
          Vpk[5][20][0])+(Fstar[20][1]*Vpk[5][20][1])))+((Tstar[20][2]*
          Wpk[5][20][2])+((Tstar[20][0]*Wpk[5][20][0])+(Tstar[20][1]*
          Wpk[5][20][1]))))+temp[6])));
        temp[0] = ((((Fstar[6][2]*Vpk[6][6][2])+((Fstar[6][0]*Vpk[6][6][0])+(
          Fstar[6][1]*Vpk[6][6][1])))+((pin[6][2]*Tstar[6][2])+((pin[6][0]*
          Tstar[6][0])+(pin[6][1]*Tstar[6][1]))))+(((Fstar[7][2]*Vpk[6][7][2])+(
          (Fstar[7][0]*Vpk[6][7][0])+(Fstar[7][1]*Vpk[6][7][1])))+((Tstar[7][2]*
          Wpk[6][7][2])+((Tstar[7][0]*Wpk[6][7][0])+(Tstar[7][1]*Wpk[6][7][1])))
          ));
        fs0[6] = (utau[6]-((((Fstar[9][2]*Vpk[6][9][2])+((Fstar[9][0]*
          Vpk[6][9][0])+(Fstar[9][1]*Vpk[6][9][1])))+((Tstar[9][2]*Wpk[6][9][2])
          +((Tstar[9][0]*Wpk[6][9][0])+(Tstar[9][1]*Wpk[6][9][1]))))+((((
          Fstar[8][2]*Vpk[6][8][2])+((Fstar[8][0]*Vpk[6][8][0])+(Fstar[8][1]*
          Vpk[6][8][1])))+((Tstar[8][2]*Wpk[6][8][2])+((Tstar[8][0]*Wpk[6][8][0]
          )+(Tstar[8][1]*Wpk[6][8][1]))))+temp[0])));
        temp[0] = ((((Fstar[7][2]*Vpk[7][7][2])+((Fstar[7][0]*Vpk[7][7][0])+(
          Fstar[7][1]*Vpk[7][7][1])))+((pin[7][2]*Tstar[7][2])+((pin[7][0]*
          Tstar[7][0])+(pin[7][1]*Tstar[7][1]))))+(((Fstar[8][2]*Vpk[7][8][2])+(
          (Fstar[8][0]*Vpk[7][8][0])+(Fstar[8][1]*Vpk[7][8][1])))+((Tstar[8][2]*
          Wpk[7][8][2])+((Tstar[8][0]*Wpk[7][8][0])+(Tstar[8][1]*Wpk[7][8][1])))
          ));
        fs0[7] = (utau[7]-((((Fstar[9][2]*Vpk[7][9][2])+((Fstar[9][0]*
          Vpk[7][9][0])+(Fstar[9][1]*Vpk[7][9][1])))+((Tstar[9][2]*Wpk[7][9][2])
          +((Tstar[9][0]*Wpk[7][9][0])+(Tstar[9][1]*Wpk[7][9][1]))))+temp[0]));
        fs0[8] = (utau[8]-((((Fstar[8][2]*Vpk[8][8][2])+((Fstar[8][0]*
          Vpk[8][8][0])+(Fstar[8][1]*Vpk[8][8][1])))+((pin[8][2]*Tstar[8][2])+((
          pin[8][0]*Tstar[8][0])+(pin[8][1]*Tstar[8][1]))))+(((Fstar[9][2]*
          Vpk[8][9][2])+((Fstar[9][0]*Vpk[8][9][0])+(Fstar[9][1]*Vpk[8][9][1])))
          +((Tstar[9][2]*Wpk[8][9][2])+((Tstar[9][0]*Wpk[8][9][0])+(Tstar[9][1]*
          Wpk[8][9][1]))))));
        fs0[9] = (utau[9]-(((Fstar[9][2]*Vpk[9][9][2])+((Fstar[9][0]*
          Vpk[9][9][0])+(Fstar[9][1]*Vpk[9][9][1])))+((pin[9][2]*Tstar[9][2])+((
          pin[9][0]*Tstar[9][0])+(pin[9][1]*Tstar[9][1])))));
        temp[0] = ((((Fstar[10][2]*Vpk[10][10][2])+((Fstar[10][0]*Vpk[10][10][0]
          )+(Fstar[10][1]*Vpk[10][10][1])))+((pin[10][2]*Tstar[10][2])+((
          pin[10][0]*Tstar[10][0])+(pin[10][1]*Tstar[10][1]))))+(((Fstar[11][2]*
          Vpk[10][11][2])+((Fstar[11][0]*Vpk[10][11][0])+(Fstar[11][1]*
          Vpk[10][11][1])))+((Tstar[11][2]*Wpk[10][11][2])+((Tstar[11][0]*
          Wpk[10][11][0])+(Tstar[11][1]*Wpk[10][11][1])))));
        fs0[10] = (utau[10]-((((Fstar[13][2]*Vpk[10][13][2])+((Fstar[13][0]*
          Vpk[10][13][0])+(Fstar[13][1]*Vpk[10][13][1])))+((Tstar[13][2]*
          Wpk[10][13][2])+((Tstar[13][0]*Wpk[10][13][0])+(Tstar[13][1]*
          Wpk[10][13][1]))))+((((Fstar[12][2]*Vpk[10][12][2])+((Fstar[12][0]*
          Vpk[10][12][0])+(Fstar[12][1]*Vpk[10][12][1])))+((Tstar[12][2]*
          Wpk[10][12][2])+((Tstar[12][0]*Wpk[10][12][0])+(Tstar[12][1]*
          Wpk[10][12][1]))))+temp[0])));
        temp[0] = ((((Fstar[11][2]*Vpk[11][11][2])+((Fstar[11][0]*Vpk[11][11][0]
          )+(Fstar[11][1]*Vpk[11][11][1])))+((pin[11][2]*Tstar[11][2])+((
          pin[11][0]*Tstar[11][0])+(pin[11][1]*Tstar[11][1]))))+(((Fstar[12][2]*
          Vpk[11][12][2])+((Fstar[12][0]*Vpk[11][12][0])+(Fstar[12][1]*
          Vpk[11][12][1])))+((Tstar[12][2]*Wpk[11][12][2])+((Tstar[12][0]*
          Wpk[11][12][0])+(Tstar[12][1]*Wpk[11][12][1])))));
        fs0[11] = (utau[11]-((((Fstar[13][2]*Vpk[11][13][2])+((Fstar[13][0]*
          Vpk[11][13][0])+(Fstar[13][1]*Vpk[11][13][1])))+((Tstar[13][2]*
          Wpk[11][13][2])+((Tstar[13][0]*Wpk[11][13][0])+(Tstar[13][1]*
          Wpk[11][13][1]))))+temp[0]));
        fs0[12] = (utau[12]-((((Fstar[12][2]*Vpk[12][12][2])+((Fstar[12][0]*
          Vpk[12][12][0])+(Fstar[12][1]*Vpk[12][12][1])))+((pin[12][2]*
          Tstar[12][2])+((pin[12][0]*Tstar[12][0])+(pin[12][1]*Tstar[12][1]))))+
          (((Fstar[13][2]*Vpk[12][13][2])+((Fstar[13][0]*Vpk[12][13][0])+(
          Fstar[13][1]*Vpk[12][13][1])))+((Tstar[13][2]*Wpk[12][13][2])+((
          Tstar[13][0]*Wpk[12][13][0])+(Tstar[13][1]*Wpk[12][13][1]))))));
        fs0[13] = (utau[13]-(((Fstar[13][2]*Vpk[13][13][2])+((Fstar[13][0]*
          Vpk[13][13][0])+(Fstar[13][1]*Vpk[13][13][1])))+((pin[13][2]*
          Tstar[13][2])+((pin[13][0]*Tstar[13][0])+(pin[13][1]*Tstar[13][1])))))
          ;
        temp[0] = ((((Fstar[14][2]*Vpk[14][14][2])+((Fstar[14][0]*Vpk[14][14][0]
          )+(Fstar[14][1]*Vpk[14][14][1])))+((pin[14][2]*Tstar[14][2])+((
          pin[14][0]*Tstar[14][0])+(pin[14][1]*Tstar[14][1]))))+(((Fstar[15][2]*
          Vpk[14][15][2])+((Fstar[15][0]*Vpk[14][15][0])+(Fstar[15][1]*
          Vpk[14][15][1])))+((Tstar[15][2]*Wpk[14][15][2])+((Tstar[15][0]*
          Wpk[14][15][0])+(Tstar[15][1]*Wpk[14][15][1])))));
        fs0[14] = (utau[14]-((((Fstar[17][2]*Vpk[14][17][2])+((Fstar[17][0]*
          Vpk[14][17][0])+(Fstar[17][1]*Vpk[14][17][1])))+((Tstar[17][2]*
          Wpk[14][17][2])+((Tstar[17][0]*Wpk[14][17][0])+(Tstar[17][1]*
          Wpk[14][17][1]))))+((((Fstar[16][2]*Vpk[14][16][2])+((Fstar[16][0]*
          Vpk[14][16][0])+(Fstar[16][1]*Vpk[14][16][1])))+((Tstar[16][2]*
          Wpk[14][16][2])+((Tstar[16][0]*Wpk[14][16][0])+(Tstar[16][1]*
          Wpk[14][16][1]))))+temp[0])));
        temp[0] = ((((Fstar[15][2]*Vpk[15][15][2])+((Fstar[15][0]*Vpk[15][15][0]
          )+(Fstar[15][1]*Vpk[15][15][1])))+((pin[15][2]*Tstar[15][2])+((
          pin[15][0]*Tstar[15][0])+(pin[15][1]*Tstar[15][1]))))+(((Fstar[16][2]*
          Vpk[15][16][2])+((Fstar[16][0]*Vpk[15][16][0])+(Fstar[16][1]*
          Vpk[15][16][1])))+((Tstar[16][2]*Wpk[15][16][2])+((Tstar[16][0]*
          Wpk[15][16][0])+(Tstar[16][1]*Wpk[15][16][1])))));
        fs0[15] = (utau[15]-((((Fstar[17][2]*Vpk[15][17][2])+((Fstar[17][0]*
          Vpk[15][17][0])+(Fstar[17][1]*Vpk[15][17][1])))+((Tstar[17][2]*
          Wpk[15][17][2])+((Tstar[17][0]*Wpk[15][17][0])+(Tstar[17][1]*
          Wpk[15][17][1]))))+temp[0]));
        fs0[16] = (utau[16]-((((Fstar[16][2]*Vpk[16][16][2])+((Fstar[16][0]*
          Vpk[16][16][0])+(Fstar[16][1]*Vpk[16][16][1])))+((pin[16][2]*
          Tstar[16][2])+((pin[16][0]*Tstar[16][0])+(pin[16][1]*Tstar[16][1]))))+
          (((Fstar[17][2]*Vpk[16][17][2])+((Fstar[17][0]*Vpk[16][17][0])+(
          Fstar[17][1]*Vpk[16][17][1])))+((Tstar[17][2]*Wpk[16][17][2])+((
          Tstar[17][0]*Wpk[16][17][0])+(Tstar[17][1]*Wpk[16][17][1]))))));
        fs0[17] = (utau[17]-(((Fstar[17][2]*Vpk[17][17][2])+((Fstar[17][0]*
          Vpk[17][17][0])+(Fstar[17][1]*Vpk[17][17][1])))+((pin[17][2]*
          Tstar[17][2])+((pin[17][0]*Tstar[17][0])+(pin[17][1]*Tstar[17][1])))))
          ;
        temp[0] = ((((Fstar[18][2]*Vpk[18][18][2])+((Fstar[18][0]*Vpk[18][18][0]
          )+(Fstar[18][1]*Vpk[18][18][1])))+((pin[18][2]*Tstar[18][2])+((
          pin[18][0]*Tstar[18][0])+(pin[18][1]*Tstar[18][1]))))+(((Fstar[19][2]*
          Vpk[18][19][2])+((Fstar[19][0]*Vpk[18][19][0])+(Fstar[19][1]*
          Vpk[18][19][1])))+((Tstar[19][2]*Wpk[18][19][2])+((Tstar[19][0]*
          Wpk[18][19][0])+(Tstar[19][1]*Wpk[18][19][1])))));
        fs0[18] = (utau[18]-((((Fstar[21][2]*Vpk[18][21][2])+((Fstar[21][0]*
          Vpk[18][21][0])+(Fstar[21][1]*Vpk[18][21][1])))+((Tstar[21][2]*
          Wpk[18][21][2])+((Tstar[21][0]*Wpk[18][21][0])+(Tstar[21][1]*
          Wpk[18][21][1]))))+((((Fstar[20][2]*Vpk[18][20][2])+((Fstar[20][0]*
          Vpk[18][20][0])+(Fstar[20][1]*Vpk[18][20][1])))+((Tstar[20][2]*
          Wpk[18][20][2])+((Tstar[20][0]*Wpk[18][20][0])+(Tstar[20][1]*
          Wpk[18][20][1]))))+temp[0])));
        temp[0] = ((((Fstar[19][2]*Vpk[19][19][2])+((Fstar[19][0]*Vpk[19][19][0]
          )+(Fstar[19][1]*Vpk[19][19][1])))+((pin[19][2]*Tstar[19][2])+((
          pin[19][0]*Tstar[19][0])+(pin[19][1]*Tstar[19][1]))))+(((Fstar[20][2]*
          Vpk[19][20][2])+((Fstar[20][0]*Vpk[19][20][0])+(Fstar[20][1]*
          Vpk[19][20][1])))+((Tstar[20][2]*Wpk[19][20][2])+((Tstar[20][0]*
          Wpk[19][20][0])+(Tstar[20][1]*Wpk[19][20][1])))));
        fs0[19] = (utau[19]-((((Fstar[21][2]*Vpk[19][21][2])+((Fstar[21][0]*
          Vpk[19][21][0])+(Fstar[21][1]*Vpk[19][21][1])))+((Tstar[21][2]*
          Wpk[19][21][2])+((Tstar[21][0]*Wpk[19][21][0])+(Tstar[21][1]*
          Wpk[19][21][1]))))+temp[0]));
        fs0[20] = (utau[20]-((((Fstar[20][2]*Vpk[20][20][2])+((Fstar[20][0]*
          Vpk[20][20][0])+(Fstar[20][1]*Vpk[20][20][1])))+((pin[20][2]*
          Tstar[20][2])+((pin[20][0]*Tstar[20][0])+(pin[20][1]*Tstar[20][1]))))+
          (((Fstar[21][2]*Vpk[20][21][2])+((Fstar[21][0]*Vpk[20][21][0])+(
          Fstar[21][1]*Vpk[20][21][1])))+((Tstar[21][2]*Wpk[20][21][2])+((
          Tstar[21][0]*Wpk[20][21][0])+(Tstar[21][1]*Wpk[20][21][1]))))));
        fs0[21] = (utau[21]-(((Fstar[21][2]*Vpk[21][21][2])+((Fstar[21][0]*
          Vpk[21][21][0])+(Fstar[21][1]*Vpk[21][21][1])))+((pin[21][2]*
          Tstar[21][2])+((pin[21][0]*Tstar[21][0])+(pin[21][1]*Tstar[21][1])))))
          ;
        fs0flg = 1;
    }
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain 1059 adds/subtracts/negates
                    930 multiplies
                      0 divides
                    165 assignments
*/
}

void allegro_air_domm(int routine)
{
    int dumroutine,errnum;
    int i;

    if (mmflg == 0) {
/*
Compute mass matrix (MM)
*/
        allegro_air_dovpk();
        IkWpk[3][6][0] = ((Cik[6][0][2]*ik[1][0][2])+((Cik[6][0][0]*ik[1][0][0])
          +(Cik[6][0][1]*ik[1][0][1])));
        IkWpk[3][6][1] = ((Cik[6][0][2]*ik[1][1][2])+((Cik[6][0][0]*ik[1][1][0])
          +(Cik[6][0][1]*ik[1][1][1])));
        IkWpk[3][6][2] = ((Cik[6][0][2]*ik[1][2][2])+((Cik[6][0][0]*ik[1][2][0])
          +(Cik[6][0][1]*ik[1][2][1])));
        IkWpk[3][7][0] = ((ik[2][0][2]*Wpk[3][7][2])+((ik[2][0][0]*Wpk[3][7][0])
          +(ik[2][0][1]*Wpk[3][7][1])));
        IkWpk[3][7][1] = ((ik[2][1][2]*Wpk[3][7][2])+((ik[2][1][0]*Wpk[3][7][0])
          +(ik[2][1][1]*Wpk[3][7][1])));
        IkWpk[3][7][2] = ((ik[2][2][2]*Wpk[3][7][2])+((ik[2][2][0]*Wpk[3][7][0])
          +(ik[2][2][1]*Wpk[3][7][1])));
        IkWpk[3][8][0] = ((ik[3][0][2]*Wpk[3][8][2])+((ik[3][0][0]*Wpk[3][8][0])
          +(ik[3][0][1]*Wpk[3][8][1])));
        IkWpk[3][8][1] = ((ik[3][1][2]*Wpk[3][8][2])+((ik[3][1][0]*Wpk[3][8][0])
          +(ik[3][1][1]*Wpk[3][8][1])));
        IkWpk[3][8][2] = ((ik[3][2][2]*Wpk[3][8][2])+((ik[3][2][0]*Wpk[3][8][0])
          +(ik[3][2][1]*Wpk[3][8][1])));
        IkWpk[3][9][0] = ((psik[9][0][2]*Wpk[3][9][2])+((psik[9][0][0]*
          Wpk[3][9][0])+(psik[9][0][1]*Wpk[3][9][1])));
        IkWpk[3][9][1] = ((psik[9][1][2]*Wpk[3][9][2])+((psik[9][1][0]*
          Wpk[3][9][0])+(psik[9][1][1]*Wpk[3][9][1])));
        IkWpk[3][9][2] = ((psik[9][2][2]*Wpk[3][9][2])+((psik[9][2][0]*
          Wpk[3][9][0])+(psik[9][2][1]*Wpk[3][9][1])));
        IkWpk[3][10][0] = ((Cik[10][0][2]*ik[6][0][2])+((Cik[10][0][0]*
          ik[6][0][0])+(Cik[10][0][1]*ik[6][0][1])));
        IkWpk[3][10][1] = ((Cik[10][0][2]*ik[6][1][2])+((Cik[10][0][0]*
          ik[6][1][0])+(Cik[10][0][1]*ik[6][1][1])));
        IkWpk[3][10][2] = ((Cik[10][0][2]*ik[6][2][2])+((Cik[10][0][0]*
          ik[6][2][0])+(Cik[10][0][1]*ik[6][2][1])));
        IkWpk[3][11][0] = ((ik[7][0][2]*Wpk[3][11][2])+((ik[7][0][0]*
          Wpk[3][11][0])+(ik[7][0][1]*Wpk[3][11][1])));
        IkWpk[3][11][1] = ((ik[7][1][2]*Wpk[3][11][2])+((ik[7][1][0]*
          Wpk[3][11][0])+(ik[7][1][1]*Wpk[3][11][1])));
        IkWpk[3][11][2] = ((ik[7][2][2]*Wpk[3][11][2])+((ik[7][2][0]*
          Wpk[3][11][0])+(ik[7][2][1]*Wpk[3][11][1])));
        IkWpk[3][12][0] = ((ik[8][0][2]*Wpk[3][12][2])+((ik[8][0][0]*
          Wpk[3][12][0])+(ik[8][0][1]*Wpk[3][12][1])));
        IkWpk[3][12][1] = ((ik[8][1][2]*Wpk[3][12][2])+((ik[8][1][0]*
          Wpk[3][12][0])+(ik[8][1][1]*Wpk[3][12][1])));
        IkWpk[3][12][2] = ((ik[8][2][2]*Wpk[3][12][2])+((ik[8][2][0]*
          Wpk[3][12][0])+(ik[8][2][1]*Wpk[3][12][1])));
        IkWpk[3][13][0] = ((psik[13][0][2]*Wpk[3][13][2])+((psik[13][0][0]*
          Wpk[3][13][0])+(psik[13][0][1]*Wpk[3][13][1])));
        IkWpk[3][13][1] = ((psik[13][1][2]*Wpk[3][13][2])+((psik[13][1][0]*
          Wpk[3][13][0])+(psik[13][1][1]*Wpk[3][13][1])));
        IkWpk[3][13][2] = ((psik[13][2][2]*Wpk[3][13][2])+((psik[13][2][0]*
          Wpk[3][13][0])+(psik[13][2][1]*Wpk[3][13][1])));
        IkWpk[3][14][0] = ((Cik[14][0][2]*ik[11][0][2])+((Cik[14][0][0]*
          ik[11][0][0])+(Cik[14][0][1]*ik[11][0][1])));
        IkWpk[3][14][1] = ((Cik[14][0][2]*ik[11][1][2])+((Cik[14][0][0]*
          ik[11][1][0])+(Cik[14][0][1]*ik[11][1][1])));
        IkWpk[3][14][2] = ((Cik[14][0][2]*ik[11][2][2])+((Cik[14][0][0]*
          ik[11][2][0])+(Cik[14][0][1]*ik[11][2][1])));
        IkWpk[3][15][0] = ((ik[12][0][2]*Wpk[3][15][2])+((ik[12][0][0]*
          Wpk[3][15][0])+(ik[12][0][1]*Wpk[3][15][1])));
        IkWpk[3][15][1] = ((ik[12][1][2]*Wpk[3][15][2])+((ik[12][1][0]*
          Wpk[3][15][0])+(ik[12][1][1]*Wpk[3][15][1])));
        IkWpk[3][15][2] = ((ik[12][2][2]*Wpk[3][15][2])+((ik[12][2][0]*
          Wpk[3][15][0])+(ik[12][2][1]*Wpk[3][15][1])));
        IkWpk[3][16][0] = ((ik[13][0][2]*Wpk[3][16][2])+((ik[13][0][0]*
          Wpk[3][16][0])+(ik[13][0][1]*Wpk[3][16][1])));
        IkWpk[3][16][1] = ((ik[13][1][2]*Wpk[3][16][2])+((ik[13][1][0]*
          Wpk[3][16][0])+(ik[13][1][1]*Wpk[3][16][1])));
        IkWpk[3][16][2] = ((ik[13][2][2]*Wpk[3][16][2])+((ik[13][2][0]*
          Wpk[3][16][0])+(ik[13][2][1]*Wpk[3][16][1])));
        IkWpk[3][17][0] = ((psik[17][0][2]*Wpk[3][17][2])+((psik[17][0][0]*
          Wpk[3][17][0])+(psik[17][0][1]*Wpk[3][17][1])));
        IkWpk[3][17][1] = ((psik[17][1][2]*Wpk[3][17][2])+((psik[17][1][0]*
          Wpk[3][17][0])+(psik[17][1][1]*Wpk[3][17][1])));
        IkWpk[3][17][2] = ((psik[17][2][2]*Wpk[3][17][2])+((psik[17][2][0]*
          Wpk[3][17][0])+(psik[17][2][1]*Wpk[3][17][1])));
        IkWpk[3][18][0] = ((Cik[18][0][2]*ik[16][0][2])+((Cik[18][0][0]*
          ik[16][0][0])+(Cik[18][0][1]*ik[16][0][1])));
        IkWpk[3][18][1] = ((Cik[18][0][2]*ik[16][1][2])+((Cik[18][0][0]*
          ik[16][1][0])+(Cik[18][0][1]*ik[16][1][1])));
        IkWpk[3][18][2] = ((Cik[18][0][2]*ik[16][2][2])+((Cik[18][0][0]*
          ik[16][2][0])+(Cik[18][0][1]*ik[16][2][1])));
        IkWpk[3][19][0] = ((ik[17][0][2]*Wpk[3][19][2])+((ik[17][0][0]*
          Wpk[3][19][0])+(ik[17][0][1]*Wpk[3][19][1])));
        IkWpk[3][19][1] = ((ik[17][1][2]*Wpk[3][19][2])+((ik[17][1][0]*
          Wpk[3][19][0])+(ik[17][1][1]*Wpk[3][19][1])));
        IkWpk[3][19][2] = ((ik[17][2][2]*Wpk[3][19][2])+((ik[17][2][0]*
          Wpk[3][19][0])+(ik[17][2][1]*Wpk[3][19][1])));
        IkWpk[3][20][0] = ((ik[18][0][2]*Wpk[3][20][2])+((ik[18][0][0]*
          Wpk[3][20][0])+(ik[18][0][1]*Wpk[3][20][1])));
        IkWpk[3][20][1] = ((ik[18][1][2]*Wpk[3][20][2])+((ik[18][1][0]*
          Wpk[3][20][0])+(ik[18][1][1]*Wpk[3][20][1])));
        IkWpk[3][20][2] = ((ik[18][2][2]*Wpk[3][20][2])+((ik[18][2][0]*
          Wpk[3][20][0])+(ik[18][2][1]*Wpk[3][20][1])));
        IkWpk[3][21][0] = ((psik[21][0][2]*Wpk[3][21][2])+((psik[21][0][0]*
          Wpk[3][21][0])+(psik[21][0][1]*Wpk[3][21][1])));
        IkWpk[3][21][1] = ((psik[21][1][2]*Wpk[3][21][2])+((psik[21][1][0]*
          Wpk[3][21][0])+(psik[21][1][1]*Wpk[3][21][1])));
        IkWpk[3][21][2] = ((psik[21][2][2]*Wpk[3][21][2])+((psik[21][2][0]*
          Wpk[3][21][0])+(psik[21][2][1]*Wpk[3][21][1])));
        IkWpk[4][6][0] = ((Cik[6][1][2]*ik[1][0][2])+((Cik[6][1][0]*ik[1][0][0])
          +(Cik[6][1][1]*ik[1][0][1])));
        IkWpk[4][6][1] = ((Cik[6][1][2]*ik[1][1][2])+((Cik[6][1][0]*ik[1][1][0])
          +(Cik[6][1][1]*ik[1][1][1])));
        IkWpk[4][6][2] = ((Cik[6][1][2]*ik[1][2][2])+((Cik[6][1][0]*ik[1][2][0])
          +(Cik[6][1][1]*ik[1][2][1])));
        IkWpk[4][7][0] = ((ik[2][0][2]*Wpk[4][7][2])+((ik[2][0][0]*Wpk[4][7][0])
          +(ik[2][0][1]*Wpk[4][7][1])));
        IkWpk[4][7][1] = ((ik[2][1][2]*Wpk[4][7][2])+((ik[2][1][0]*Wpk[4][7][0])
          +(ik[2][1][1]*Wpk[4][7][1])));
        IkWpk[4][7][2] = ((ik[2][2][2]*Wpk[4][7][2])+((ik[2][2][0]*Wpk[4][7][0])
          +(ik[2][2][1]*Wpk[4][7][1])));
        IkWpk[4][8][0] = ((ik[3][0][2]*Wpk[4][8][2])+((ik[3][0][0]*Wpk[4][8][0])
          +(ik[3][0][1]*Wpk[4][8][1])));
        IkWpk[4][8][1] = ((ik[3][1][2]*Wpk[4][8][2])+((ik[3][1][0]*Wpk[4][8][0])
          +(ik[3][1][1]*Wpk[4][8][1])));
        IkWpk[4][8][2] = ((ik[3][2][2]*Wpk[4][8][2])+((ik[3][2][0]*Wpk[4][8][0])
          +(ik[3][2][1]*Wpk[4][8][1])));
        IkWpk[4][9][0] = ((psik[9][0][2]*Wpk[4][9][2])+((psik[9][0][0]*
          Wpk[4][9][0])+(psik[9][0][1]*Wpk[4][9][1])));
        IkWpk[4][9][1] = ((psik[9][1][2]*Wpk[4][9][2])+((psik[9][1][0]*
          Wpk[4][9][0])+(psik[9][1][1]*Wpk[4][9][1])));
        IkWpk[4][9][2] = ((psik[9][2][2]*Wpk[4][9][2])+((psik[9][2][0]*
          Wpk[4][9][0])+(psik[9][2][1]*Wpk[4][9][1])));
        IkWpk[4][10][0] = ((Cik[10][1][2]*ik[6][0][2])+((Cik[10][1][0]*
          ik[6][0][0])+(Cik[10][1][1]*ik[6][0][1])));
        IkWpk[4][10][1] = ((Cik[10][1][2]*ik[6][1][2])+((Cik[10][1][0]*
          ik[6][1][0])+(Cik[10][1][1]*ik[6][1][1])));
        IkWpk[4][10][2] = ((Cik[10][1][2]*ik[6][2][2])+((Cik[10][1][0]*
          ik[6][2][0])+(Cik[10][1][1]*ik[6][2][1])));
        IkWpk[4][11][0] = ((ik[7][0][2]*Wpk[4][11][2])+((ik[7][0][0]*
          Wpk[4][11][0])+(ik[7][0][1]*Wpk[4][11][1])));
        IkWpk[4][11][1] = ((ik[7][1][2]*Wpk[4][11][2])+((ik[7][1][0]*
          Wpk[4][11][0])+(ik[7][1][1]*Wpk[4][11][1])));
        IkWpk[4][11][2] = ((ik[7][2][2]*Wpk[4][11][2])+((ik[7][2][0]*
          Wpk[4][11][0])+(ik[7][2][1]*Wpk[4][11][1])));
        IkWpk[4][12][0] = ((ik[8][0][2]*Wpk[4][12][2])+((ik[8][0][0]*
          Wpk[4][12][0])+(ik[8][0][1]*Wpk[4][12][1])));
        IkWpk[4][12][1] = ((ik[8][1][2]*Wpk[4][12][2])+((ik[8][1][0]*
          Wpk[4][12][0])+(ik[8][1][1]*Wpk[4][12][1])));
        IkWpk[4][12][2] = ((ik[8][2][2]*Wpk[4][12][2])+((ik[8][2][0]*
          Wpk[4][12][0])+(ik[8][2][1]*Wpk[4][12][1])));
        IkWpk[4][13][0] = ((psik[13][0][2]*Wpk[4][13][2])+((psik[13][0][0]*
          Wpk[4][13][0])+(psik[13][0][1]*Wpk[4][13][1])));
        IkWpk[4][13][1] = ((psik[13][1][2]*Wpk[4][13][2])+((psik[13][1][0]*
          Wpk[4][13][0])+(psik[13][1][1]*Wpk[4][13][1])));
        IkWpk[4][13][2] = ((psik[13][2][2]*Wpk[4][13][2])+((psik[13][2][0]*
          Wpk[4][13][0])+(psik[13][2][1]*Wpk[4][13][1])));
        IkWpk[4][14][0] = ((Cik[14][1][2]*ik[11][0][2])+((Cik[14][1][0]*
          ik[11][0][0])+(Cik[14][1][1]*ik[11][0][1])));
        IkWpk[4][14][1] = ((Cik[14][1][2]*ik[11][1][2])+((Cik[14][1][0]*
          ik[11][1][0])+(Cik[14][1][1]*ik[11][1][1])));
        IkWpk[4][14][2] = ((Cik[14][1][2]*ik[11][2][2])+((Cik[14][1][0]*
          ik[11][2][0])+(Cik[14][1][1]*ik[11][2][1])));
        IkWpk[4][15][0] = ((ik[12][0][2]*Wpk[4][15][2])+((ik[12][0][0]*
          Wpk[4][15][0])+(ik[12][0][1]*Wpk[4][15][1])));
        IkWpk[4][15][1] = ((ik[12][1][2]*Wpk[4][15][2])+((ik[12][1][0]*
          Wpk[4][15][0])+(ik[12][1][1]*Wpk[4][15][1])));
        IkWpk[4][15][2] = ((ik[12][2][2]*Wpk[4][15][2])+((ik[12][2][0]*
          Wpk[4][15][0])+(ik[12][2][1]*Wpk[4][15][1])));
        IkWpk[4][16][0] = ((ik[13][0][2]*Wpk[4][16][2])+((ik[13][0][0]*
          Wpk[4][16][0])+(ik[13][0][1]*Wpk[4][16][1])));
        IkWpk[4][16][1] = ((ik[13][1][2]*Wpk[4][16][2])+((ik[13][1][0]*
          Wpk[4][16][0])+(ik[13][1][1]*Wpk[4][16][1])));
        IkWpk[4][16][2] = ((ik[13][2][2]*Wpk[4][16][2])+((ik[13][2][0]*
          Wpk[4][16][0])+(ik[13][2][1]*Wpk[4][16][1])));
        IkWpk[4][17][0] = ((psik[17][0][2]*Wpk[4][17][2])+((psik[17][0][0]*
          Wpk[4][17][0])+(psik[17][0][1]*Wpk[4][17][1])));
        IkWpk[4][17][1] = ((psik[17][1][2]*Wpk[4][17][2])+((psik[17][1][0]*
          Wpk[4][17][0])+(psik[17][1][1]*Wpk[4][17][1])));
        IkWpk[4][17][2] = ((psik[17][2][2]*Wpk[4][17][2])+((psik[17][2][0]*
          Wpk[4][17][0])+(psik[17][2][1]*Wpk[4][17][1])));
        IkWpk[4][18][0] = ((Cik[18][1][2]*ik[16][0][2])+((Cik[18][1][0]*
          ik[16][0][0])+(Cik[18][1][1]*ik[16][0][1])));
        IkWpk[4][18][1] = ((Cik[18][1][2]*ik[16][1][2])+((Cik[18][1][0]*
          ik[16][1][0])+(Cik[18][1][1]*ik[16][1][1])));
        IkWpk[4][18][2] = ((Cik[18][1][2]*ik[16][2][2])+((Cik[18][1][0]*
          ik[16][2][0])+(Cik[18][1][1]*ik[16][2][1])));
        IkWpk[4][19][0] = ((ik[17][0][2]*Wpk[4][19][2])+((ik[17][0][0]*
          Wpk[4][19][0])+(ik[17][0][1]*Wpk[4][19][1])));
        IkWpk[4][19][1] = ((ik[17][1][2]*Wpk[4][19][2])+((ik[17][1][0]*
          Wpk[4][19][0])+(ik[17][1][1]*Wpk[4][19][1])));
        IkWpk[4][19][2] = ((ik[17][2][2]*Wpk[4][19][2])+((ik[17][2][0]*
          Wpk[4][19][0])+(ik[17][2][1]*Wpk[4][19][1])));
        IkWpk[4][20][0] = ((ik[18][0][2]*Wpk[4][20][2])+((ik[18][0][0]*
          Wpk[4][20][0])+(ik[18][0][1]*Wpk[4][20][1])));
        IkWpk[4][20][1] = ((ik[18][1][2]*Wpk[4][20][2])+((ik[18][1][0]*
          Wpk[4][20][0])+(ik[18][1][1]*Wpk[4][20][1])));
        IkWpk[4][20][2] = ((ik[18][2][2]*Wpk[4][20][2])+((ik[18][2][0]*
          Wpk[4][20][0])+(ik[18][2][1]*Wpk[4][20][1])));
        IkWpk[4][21][0] = ((psik[21][0][2]*Wpk[4][21][2])+((psik[21][0][0]*
          Wpk[4][21][0])+(psik[21][0][1]*Wpk[4][21][1])));
        IkWpk[4][21][1] = ((psik[21][1][2]*Wpk[4][21][2])+((psik[21][1][0]*
          Wpk[4][21][0])+(psik[21][1][1]*Wpk[4][21][1])));
        IkWpk[4][21][2] = ((psik[21][2][2]*Wpk[4][21][2])+((psik[21][2][0]*
          Wpk[4][21][0])+(psik[21][2][1]*Wpk[4][21][1])));
        IkWpk[5][6][0] = ((Cik[6][2][2]*ik[1][0][2])+((Cik[6][2][0]*ik[1][0][0])
          +(Cik[6][2][1]*ik[1][0][1])));
        IkWpk[5][6][1] = ((Cik[6][2][2]*ik[1][1][2])+((Cik[6][2][0]*ik[1][1][0])
          +(Cik[6][2][1]*ik[1][1][1])));
        IkWpk[5][6][2] = ((Cik[6][2][2]*ik[1][2][2])+((Cik[6][2][0]*ik[1][2][0])
          +(Cik[6][2][1]*ik[1][2][1])));
        IkWpk[5][7][0] = ((ik[2][0][2]*Wpk[5][7][2])+((ik[2][0][0]*Wpk[5][7][0])
          +(ik[2][0][1]*Wpk[5][7][1])));
        IkWpk[5][7][1] = ((ik[2][1][2]*Wpk[5][7][2])+((ik[2][1][0]*Wpk[5][7][0])
          +(ik[2][1][1]*Wpk[5][7][1])));
        IkWpk[5][7][2] = ((ik[2][2][2]*Wpk[5][7][2])+((ik[2][2][0]*Wpk[5][7][0])
          +(ik[2][2][1]*Wpk[5][7][1])));
        IkWpk[5][8][0] = ((ik[3][0][2]*Wpk[5][8][2])+((ik[3][0][0]*Wpk[5][8][0])
          +(ik[3][0][1]*Wpk[5][8][1])));
        IkWpk[5][8][1] = ((ik[3][1][2]*Wpk[5][8][2])+((ik[3][1][0]*Wpk[5][8][0])
          +(ik[3][1][1]*Wpk[5][8][1])));
        IkWpk[5][8][2] = ((ik[3][2][2]*Wpk[5][8][2])+((ik[3][2][0]*Wpk[5][8][0])
          +(ik[3][2][1]*Wpk[5][8][1])));
        IkWpk[5][9][0] = ((psik[9][0][2]*Wpk[5][9][2])+((psik[9][0][0]*
          Wpk[5][9][0])+(psik[9][0][1]*Wpk[5][9][1])));
        IkWpk[5][9][1] = ((psik[9][1][2]*Wpk[5][9][2])+((psik[9][1][0]*
          Wpk[5][9][0])+(psik[9][1][1]*Wpk[5][9][1])));
        IkWpk[5][9][2] = ((psik[9][2][2]*Wpk[5][9][2])+((psik[9][2][0]*
          Wpk[5][9][0])+(psik[9][2][1]*Wpk[5][9][1])));
        IkWpk[5][10][0] = ((Cik[10][2][2]*ik[6][0][2])+((Cik[10][2][0]*
          ik[6][0][0])+(Cik[10][2][1]*ik[6][0][1])));
        IkWpk[5][10][1] = ((Cik[10][2][2]*ik[6][1][2])+((Cik[10][2][0]*
          ik[6][1][0])+(Cik[10][2][1]*ik[6][1][1])));
        IkWpk[5][10][2] = ((Cik[10][2][2]*ik[6][2][2])+((Cik[10][2][0]*
          ik[6][2][0])+(Cik[10][2][1]*ik[6][2][1])));
        IkWpk[5][11][0] = ((ik[7][0][2]*Wpk[5][11][2])+((ik[7][0][0]*
          Wpk[5][11][0])+(ik[7][0][1]*Wpk[5][11][1])));
        IkWpk[5][11][1] = ((ik[7][1][2]*Wpk[5][11][2])+((ik[7][1][0]*
          Wpk[5][11][0])+(ik[7][1][1]*Wpk[5][11][1])));
        IkWpk[5][11][2] = ((ik[7][2][2]*Wpk[5][11][2])+((ik[7][2][0]*
          Wpk[5][11][0])+(ik[7][2][1]*Wpk[5][11][1])));
        IkWpk[5][12][0] = ((ik[8][0][2]*Wpk[5][12][2])+((ik[8][0][0]*
          Wpk[5][12][0])+(ik[8][0][1]*Wpk[5][12][1])));
        IkWpk[5][12][1] = ((ik[8][1][2]*Wpk[5][12][2])+((ik[8][1][0]*
          Wpk[5][12][0])+(ik[8][1][1]*Wpk[5][12][1])));
        IkWpk[5][12][2] = ((ik[8][2][2]*Wpk[5][12][2])+((ik[8][2][0]*
          Wpk[5][12][0])+(ik[8][2][1]*Wpk[5][12][1])));
        IkWpk[5][13][0] = ((psik[13][0][2]*Wpk[5][13][2])+((psik[13][0][0]*
          Wpk[5][13][0])+(psik[13][0][1]*Wpk[5][13][1])));
        IkWpk[5][13][1] = ((psik[13][1][2]*Wpk[5][13][2])+((psik[13][1][0]*
          Wpk[5][13][0])+(psik[13][1][1]*Wpk[5][13][1])));
        IkWpk[5][13][2] = ((psik[13][2][2]*Wpk[5][13][2])+((psik[13][2][0]*
          Wpk[5][13][0])+(psik[13][2][1]*Wpk[5][13][1])));
        IkWpk[5][14][0] = ((Cik[14][2][2]*ik[11][0][2])+((Cik[14][2][0]*
          ik[11][0][0])+(Cik[14][2][1]*ik[11][0][1])));
        IkWpk[5][14][1] = ((Cik[14][2][2]*ik[11][1][2])+((Cik[14][2][0]*
          ik[11][1][0])+(Cik[14][2][1]*ik[11][1][1])));
        IkWpk[5][14][2] = ((Cik[14][2][2]*ik[11][2][2])+((Cik[14][2][0]*
          ik[11][2][0])+(Cik[14][2][1]*ik[11][2][1])));
        IkWpk[5][15][0] = ((ik[12][0][2]*Wpk[5][15][2])+((ik[12][0][0]*
          Wpk[5][15][0])+(ik[12][0][1]*Wpk[5][15][1])));
        IkWpk[5][15][1] = ((ik[12][1][2]*Wpk[5][15][2])+((ik[12][1][0]*
          Wpk[5][15][0])+(ik[12][1][1]*Wpk[5][15][1])));
        IkWpk[5][15][2] = ((ik[12][2][2]*Wpk[5][15][2])+((ik[12][2][0]*
          Wpk[5][15][0])+(ik[12][2][1]*Wpk[5][15][1])));
        IkWpk[5][16][0] = ((ik[13][0][2]*Wpk[5][16][2])+((ik[13][0][0]*
          Wpk[5][16][0])+(ik[13][0][1]*Wpk[5][16][1])));
        IkWpk[5][16][1] = ((ik[13][1][2]*Wpk[5][16][2])+((ik[13][1][0]*
          Wpk[5][16][0])+(ik[13][1][1]*Wpk[5][16][1])));
        IkWpk[5][16][2] = ((ik[13][2][2]*Wpk[5][16][2])+((ik[13][2][0]*
          Wpk[5][16][0])+(ik[13][2][1]*Wpk[5][16][1])));
        IkWpk[5][17][0] = ((psik[17][0][2]*Wpk[5][17][2])+((psik[17][0][0]*
          Wpk[5][17][0])+(psik[17][0][1]*Wpk[5][17][1])));
        IkWpk[5][17][1] = ((psik[17][1][2]*Wpk[5][17][2])+((psik[17][1][0]*
          Wpk[5][17][0])+(psik[17][1][1]*Wpk[5][17][1])));
        IkWpk[5][17][2] = ((psik[17][2][2]*Wpk[5][17][2])+((psik[17][2][0]*
          Wpk[5][17][0])+(psik[17][2][1]*Wpk[5][17][1])));
        IkWpk[5][18][0] = ((Cik[18][2][2]*ik[16][0][2])+((Cik[18][2][0]*
          ik[16][0][0])+(Cik[18][2][1]*ik[16][0][1])));
        IkWpk[5][18][1] = ((Cik[18][2][2]*ik[16][1][2])+((Cik[18][2][0]*
          ik[16][1][0])+(Cik[18][2][1]*ik[16][1][1])));
        IkWpk[5][18][2] = ((Cik[18][2][2]*ik[16][2][2])+((Cik[18][2][0]*
          ik[16][2][0])+(Cik[18][2][1]*ik[16][2][1])));
        IkWpk[5][19][0] = ((ik[17][0][2]*Wpk[5][19][2])+((ik[17][0][0]*
          Wpk[5][19][0])+(ik[17][0][1]*Wpk[5][19][1])));
        IkWpk[5][19][1] = ((ik[17][1][2]*Wpk[5][19][2])+((ik[17][1][0]*
          Wpk[5][19][0])+(ik[17][1][1]*Wpk[5][19][1])));
        IkWpk[5][19][2] = ((ik[17][2][2]*Wpk[5][19][2])+((ik[17][2][0]*
          Wpk[5][19][0])+(ik[17][2][1]*Wpk[5][19][1])));
        IkWpk[5][20][0] = ((ik[18][0][2]*Wpk[5][20][2])+((ik[18][0][0]*
          Wpk[5][20][0])+(ik[18][0][1]*Wpk[5][20][1])));
        IkWpk[5][20][1] = ((ik[18][1][2]*Wpk[5][20][2])+((ik[18][1][0]*
          Wpk[5][20][0])+(ik[18][1][1]*Wpk[5][20][1])));
        IkWpk[5][20][2] = ((ik[18][2][2]*Wpk[5][20][2])+((ik[18][2][0]*
          Wpk[5][20][0])+(ik[18][2][1]*Wpk[5][20][1])));
        IkWpk[5][21][0] = ((psik[21][0][2]*Wpk[5][21][2])+((psik[21][0][0]*
          Wpk[5][21][0])+(psik[21][0][1]*Wpk[5][21][1])));
        IkWpk[5][21][1] = ((psik[21][1][2]*Wpk[5][21][2])+((psik[21][1][0]*
          Wpk[5][21][0])+(psik[21][1][1]*Wpk[5][21][1])));
        IkWpk[5][21][2] = ((psik[21][2][2]*Wpk[5][21][2])+((psik[21][2][0]*
          Wpk[5][21][0])+(psik[21][2][1]*Wpk[5][21][1])));
        IkWpk[6][6][0] = ((ik[1][0][2]*pin[6][2])+((ik[1][0][0]*pin[6][0])+(
          ik[1][0][1]*pin[6][1])));
        IkWpk[6][6][1] = ((ik[1][1][2]*pin[6][2])+((ik[1][1][0]*pin[6][0])+(
          ik[1][1][1]*pin[6][1])));
        IkWpk[6][6][2] = ((ik[1][2][2]*pin[6][2])+((ik[1][2][0]*pin[6][0])+(
          ik[1][2][1]*pin[6][1])));
        IkWpk[6][7][0] = ((ik[2][0][2]*Wpk[6][7][2])+((ik[2][0][0]*Wpk[6][7][0])
          +(ik[2][0][1]*Wpk[6][7][1])));
        IkWpk[6][7][1] = ((ik[2][1][2]*Wpk[6][7][2])+((ik[2][1][0]*Wpk[6][7][0])
          +(ik[2][1][1]*Wpk[6][7][1])));
        IkWpk[6][7][2] = ((ik[2][2][2]*Wpk[6][7][2])+((ik[2][2][0]*Wpk[6][7][0])
          +(ik[2][2][1]*Wpk[6][7][1])));
        IkWpk[6][8][0] = ((ik[3][0][2]*Wpk[6][8][2])+((ik[3][0][0]*Wpk[6][8][0])
          +(ik[3][0][1]*Wpk[6][8][1])));
        IkWpk[6][8][1] = ((ik[3][1][2]*Wpk[6][8][2])+((ik[3][1][0]*Wpk[6][8][0])
          +(ik[3][1][1]*Wpk[6][8][1])));
        IkWpk[6][8][2] = ((ik[3][2][2]*Wpk[6][8][2])+((ik[3][2][0]*Wpk[6][8][0])
          +(ik[3][2][1]*Wpk[6][8][1])));
        IkWpk[6][9][0] = ((psik[9][0][2]*Wpk[6][9][2])+((psik[9][0][0]*
          Wpk[6][9][0])+(psik[9][0][1]*Wpk[6][9][1])));
        IkWpk[6][9][1] = ((psik[9][1][2]*Wpk[6][9][2])+((psik[9][1][0]*
          Wpk[6][9][0])+(psik[9][1][1]*Wpk[6][9][1])));
        IkWpk[6][9][2] = ((psik[9][2][2]*Wpk[6][9][2])+((psik[9][2][0]*
          Wpk[6][9][0])+(psik[9][2][1]*Wpk[6][9][1])));
        IkWpk[7][7][0] = ((ik[2][0][2]*pin[7][2])+((ik[2][0][0]*pin[7][0])+(
          ik[2][0][1]*pin[7][1])));
        IkWpk[7][7][1] = ((ik[2][1][2]*pin[7][2])+((ik[2][1][0]*pin[7][0])+(
          ik[2][1][1]*pin[7][1])));
        IkWpk[7][7][2] = ((ik[2][2][2]*pin[7][2])+((ik[2][2][0]*pin[7][0])+(
          ik[2][2][1]*pin[7][1])));
        IkWpk[7][8][0] = ((ik[3][0][2]*Wpk[7][8][2])+((ik[3][0][0]*Wpk[7][8][0])
          +(ik[3][0][1]*Wpk[7][8][1])));
        IkWpk[7][8][1] = ((ik[3][1][2]*Wpk[7][8][2])+((ik[3][1][0]*Wpk[7][8][0])
          +(ik[3][1][1]*Wpk[7][8][1])));
        IkWpk[7][8][2] = ((ik[3][2][2]*Wpk[7][8][2])+((ik[3][2][0]*Wpk[7][8][0])
          +(ik[3][2][1]*Wpk[7][8][1])));
        IkWpk[7][9][0] = ((psik[9][0][2]*Wpk[7][9][2])+((psik[9][0][0]*
          Wpk[7][9][0])+(psik[9][0][1]*Wpk[7][9][1])));
        IkWpk[7][9][1] = ((psik[9][1][2]*Wpk[7][9][2])+((psik[9][1][0]*
          Wpk[7][9][0])+(psik[9][1][1]*Wpk[7][9][1])));
        IkWpk[7][9][2] = ((psik[9][2][2]*Wpk[7][9][2])+((psik[9][2][0]*
          Wpk[7][9][0])+(psik[9][2][1]*Wpk[7][9][1])));
        IkWpk[8][8][0] = ((ik[3][0][2]*pin[8][2])+((ik[3][0][0]*pin[8][0])+(
          ik[3][0][1]*pin[8][1])));
        IkWpk[8][8][1] = ((ik[3][1][2]*pin[8][2])+((ik[3][1][0]*pin[8][0])+(
          ik[3][1][1]*pin[8][1])));
        IkWpk[8][8][2] = ((ik[3][2][2]*pin[8][2])+((ik[3][2][0]*pin[8][0])+(
          ik[3][2][1]*pin[8][1])));
        IkWpk[8][9][0] = ((psik[9][0][2]*Wpk[8][9][2])+((psik[9][0][0]*
          Wpk[8][9][0])+(psik[9][0][1]*Wpk[8][9][1])));
        IkWpk[8][9][1] = ((psik[9][1][2]*Wpk[8][9][2])+((psik[9][1][0]*
          Wpk[8][9][0])+(psik[9][1][1]*Wpk[8][9][1])));
        IkWpk[8][9][2] = ((psik[9][2][2]*Wpk[8][9][2])+((psik[9][2][0]*
          Wpk[8][9][0])+(psik[9][2][1]*Wpk[8][9][1])));
        IkWpk[9][9][0] = ((pin[9][2]*psik[9][0][2])+((pin[9][0]*psik[9][0][0])+(
          pin[9][1]*psik[9][0][1])));
        IkWpk[9][9][1] = ((pin[9][2]*psik[9][1][2])+((pin[9][0]*psik[9][1][0])+(
          pin[9][1]*psik[9][1][1])));
        IkWpk[9][9][2] = ((pin[9][2]*psik[9][2][2])+((pin[9][0]*psik[9][2][0])+(
          pin[9][1]*psik[9][2][1])));
        IkWpk[10][10][0] = ((ik[6][0][2]*pin[10][2])+((ik[6][0][0]*pin[10][0])+(
          ik[6][0][1]*pin[10][1])));
        IkWpk[10][10][1] = ((ik[6][1][2]*pin[10][2])+((ik[6][1][0]*pin[10][0])+(
          ik[6][1][1]*pin[10][1])));
        IkWpk[10][10][2] = ((ik[6][2][2]*pin[10][2])+((ik[6][2][0]*pin[10][0])+(
          ik[6][2][1]*pin[10][1])));
        IkWpk[10][11][0] = ((ik[7][0][2]*Wpk[10][11][2])+((ik[7][0][0]*
          Wpk[10][11][0])+(ik[7][0][1]*Wpk[10][11][1])));
        IkWpk[10][11][1] = ((ik[7][1][2]*Wpk[10][11][2])+((ik[7][1][0]*
          Wpk[10][11][0])+(ik[7][1][1]*Wpk[10][11][1])));
        IkWpk[10][11][2] = ((ik[7][2][2]*Wpk[10][11][2])+((ik[7][2][0]*
          Wpk[10][11][0])+(ik[7][2][1]*Wpk[10][11][1])));
        IkWpk[10][12][0] = ((ik[8][0][2]*Wpk[10][12][2])+((ik[8][0][0]*
          Wpk[10][12][0])+(ik[8][0][1]*Wpk[10][12][1])));
        IkWpk[10][12][1] = ((ik[8][1][2]*Wpk[10][12][2])+((ik[8][1][0]*
          Wpk[10][12][0])+(ik[8][1][1]*Wpk[10][12][1])));
        IkWpk[10][12][2] = ((ik[8][2][2]*Wpk[10][12][2])+((ik[8][2][0]*
          Wpk[10][12][0])+(ik[8][2][1]*Wpk[10][12][1])));
        IkWpk[10][13][0] = ((psik[13][0][2]*Wpk[10][13][2])+((psik[13][0][0]*
          Wpk[10][13][0])+(psik[13][0][1]*Wpk[10][13][1])));
        IkWpk[10][13][1] = ((psik[13][1][2]*Wpk[10][13][2])+((psik[13][1][0]*
          Wpk[10][13][0])+(psik[13][1][1]*Wpk[10][13][1])));
        IkWpk[10][13][2] = ((psik[13][2][2]*Wpk[10][13][2])+((psik[13][2][0]*
          Wpk[10][13][0])+(psik[13][2][1]*Wpk[10][13][1])));
        IkWpk[11][11][0] = ((ik[7][0][2]*pin[11][2])+((ik[7][0][0]*pin[11][0])+(
          ik[7][0][1]*pin[11][1])));
        IkWpk[11][11][1] = ((ik[7][1][2]*pin[11][2])+((ik[7][1][0]*pin[11][0])+(
          ik[7][1][1]*pin[11][1])));
        IkWpk[11][11][2] = ((ik[7][2][2]*pin[11][2])+((ik[7][2][0]*pin[11][0])+(
          ik[7][2][1]*pin[11][1])));
        IkWpk[11][12][0] = ((ik[8][0][2]*Wpk[11][12][2])+((ik[8][0][0]*
          Wpk[11][12][0])+(ik[8][0][1]*Wpk[11][12][1])));
        IkWpk[11][12][1] = ((ik[8][1][2]*Wpk[11][12][2])+((ik[8][1][0]*
          Wpk[11][12][0])+(ik[8][1][1]*Wpk[11][12][1])));
        IkWpk[11][12][2] = ((ik[8][2][2]*Wpk[11][12][2])+((ik[8][2][0]*
          Wpk[11][12][0])+(ik[8][2][1]*Wpk[11][12][1])));
        IkWpk[11][13][0] = ((psik[13][0][2]*Wpk[11][13][2])+((psik[13][0][0]*
          Wpk[11][13][0])+(psik[13][0][1]*Wpk[11][13][1])));
        IkWpk[11][13][1] = ((psik[13][1][2]*Wpk[11][13][2])+((psik[13][1][0]*
          Wpk[11][13][0])+(psik[13][1][1]*Wpk[11][13][1])));
        IkWpk[11][13][2] = ((psik[13][2][2]*Wpk[11][13][2])+((psik[13][2][0]*
          Wpk[11][13][0])+(psik[13][2][1]*Wpk[11][13][1])));
        IkWpk[12][12][0] = ((ik[8][0][2]*pin[12][2])+((ik[8][0][0]*pin[12][0])+(
          ik[8][0][1]*pin[12][1])));
        IkWpk[12][12][1] = ((ik[8][1][2]*pin[12][2])+((ik[8][1][0]*pin[12][0])+(
          ik[8][1][1]*pin[12][1])));
        IkWpk[12][12][2] = ((ik[8][2][2]*pin[12][2])+((ik[8][2][0]*pin[12][0])+(
          ik[8][2][1]*pin[12][1])));
        IkWpk[12][13][0] = ((psik[13][0][2]*Wpk[12][13][2])+((psik[13][0][0]*
          Wpk[12][13][0])+(psik[13][0][1]*Wpk[12][13][1])));
        IkWpk[12][13][1] = ((psik[13][1][2]*Wpk[12][13][2])+((psik[13][1][0]*
          Wpk[12][13][0])+(psik[13][1][1]*Wpk[12][13][1])));
        IkWpk[12][13][2] = ((psik[13][2][2]*Wpk[12][13][2])+((psik[13][2][0]*
          Wpk[12][13][0])+(psik[13][2][1]*Wpk[12][13][1])));
        IkWpk[13][13][0] = ((pin[13][2]*psik[13][0][2])+((pin[13][0]*
          psik[13][0][0])+(pin[13][1]*psik[13][0][1])));
        IkWpk[13][13][1] = ((pin[13][2]*psik[13][1][2])+((pin[13][0]*
          psik[13][1][0])+(pin[13][1]*psik[13][1][1])));
        IkWpk[13][13][2] = ((pin[13][2]*psik[13][2][2])+((pin[13][0]*
          psik[13][2][0])+(pin[13][1]*psik[13][2][1])));
        IkWpk[14][14][0] = ((ik[11][0][2]*pin[14][2])+((ik[11][0][0]*pin[14][0])
          +(ik[11][0][1]*pin[14][1])));
        IkWpk[14][14][1] = ((ik[11][1][2]*pin[14][2])+((ik[11][1][0]*pin[14][0])
          +(ik[11][1][1]*pin[14][1])));
        IkWpk[14][14][2] = ((ik[11][2][2]*pin[14][2])+((ik[11][2][0]*pin[14][0])
          +(ik[11][2][1]*pin[14][1])));
        IkWpk[14][15][0] = ((ik[12][0][2]*Wpk[14][15][2])+((ik[12][0][0]*
          Wpk[14][15][0])+(ik[12][0][1]*Wpk[14][15][1])));
        IkWpk[14][15][1] = ((ik[12][1][2]*Wpk[14][15][2])+((ik[12][1][0]*
          Wpk[14][15][0])+(ik[12][1][1]*Wpk[14][15][1])));
        IkWpk[14][15][2] = ((ik[12][2][2]*Wpk[14][15][2])+((ik[12][2][0]*
          Wpk[14][15][0])+(ik[12][2][1]*Wpk[14][15][1])));
        IkWpk[14][16][0] = ((ik[13][0][2]*Wpk[14][16][2])+((ik[13][0][0]*
          Wpk[14][16][0])+(ik[13][0][1]*Wpk[14][16][1])));
        IkWpk[14][16][1] = ((ik[13][1][2]*Wpk[14][16][2])+((ik[13][1][0]*
          Wpk[14][16][0])+(ik[13][1][1]*Wpk[14][16][1])));
        IkWpk[14][16][2] = ((ik[13][2][2]*Wpk[14][16][2])+((ik[13][2][0]*
          Wpk[14][16][0])+(ik[13][2][1]*Wpk[14][16][1])));
        IkWpk[14][17][0] = ((psik[17][0][2]*Wpk[14][17][2])+((psik[17][0][0]*
          Wpk[14][17][0])+(psik[17][0][1]*Wpk[14][17][1])));
        IkWpk[14][17][1] = ((psik[17][1][2]*Wpk[14][17][2])+((psik[17][1][0]*
          Wpk[14][17][0])+(psik[17][1][1]*Wpk[14][17][1])));
        IkWpk[14][17][2] = ((psik[17][2][2]*Wpk[14][17][2])+((psik[17][2][0]*
          Wpk[14][17][0])+(psik[17][2][1]*Wpk[14][17][1])));
        IkWpk[15][15][0] = ((ik[12][0][2]*pin[15][2])+((ik[12][0][0]*pin[15][0])
          +(ik[12][0][1]*pin[15][1])));
        IkWpk[15][15][1] = ((ik[12][1][2]*pin[15][2])+((ik[12][1][0]*pin[15][0])
          +(ik[12][1][1]*pin[15][1])));
        IkWpk[15][15][2] = ((ik[12][2][2]*pin[15][2])+((ik[12][2][0]*pin[15][0])
          +(ik[12][2][1]*pin[15][1])));
        IkWpk[15][16][0] = ((ik[13][0][2]*Wpk[15][16][2])+((ik[13][0][0]*
          Wpk[15][16][0])+(ik[13][0][1]*Wpk[15][16][1])));
        IkWpk[15][16][1] = ((ik[13][1][2]*Wpk[15][16][2])+((ik[13][1][0]*
          Wpk[15][16][0])+(ik[13][1][1]*Wpk[15][16][1])));
        IkWpk[15][16][2] = ((ik[13][2][2]*Wpk[15][16][2])+((ik[13][2][0]*
          Wpk[15][16][0])+(ik[13][2][1]*Wpk[15][16][1])));
        IkWpk[15][17][0] = ((psik[17][0][2]*Wpk[15][17][2])+((psik[17][0][0]*
          Wpk[15][17][0])+(psik[17][0][1]*Wpk[15][17][1])));
        IkWpk[15][17][1] = ((psik[17][1][2]*Wpk[15][17][2])+((psik[17][1][0]*
          Wpk[15][17][0])+(psik[17][1][1]*Wpk[15][17][1])));
        IkWpk[15][17][2] = ((psik[17][2][2]*Wpk[15][17][2])+((psik[17][2][0]*
          Wpk[15][17][0])+(psik[17][2][1]*Wpk[15][17][1])));
        IkWpk[16][16][0] = ((ik[13][0][2]*pin[16][2])+((ik[13][0][0]*pin[16][0])
          +(ik[13][0][1]*pin[16][1])));
        IkWpk[16][16][1] = ((ik[13][1][2]*pin[16][2])+((ik[13][1][0]*pin[16][0])
          +(ik[13][1][1]*pin[16][1])));
        IkWpk[16][16][2] = ((ik[13][2][2]*pin[16][2])+((ik[13][2][0]*pin[16][0])
          +(ik[13][2][1]*pin[16][1])));
        IkWpk[16][17][0] = ((psik[17][0][2]*Wpk[16][17][2])+((psik[17][0][0]*
          Wpk[16][17][0])+(psik[17][0][1]*Wpk[16][17][1])));
        IkWpk[16][17][1] = ((psik[17][1][2]*Wpk[16][17][2])+((psik[17][1][0]*
          Wpk[16][17][0])+(psik[17][1][1]*Wpk[16][17][1])));
        IkWpk[16][17][2] = ((psik[17][2][2]*Wpk[16][17][2])+((psik[17][2][0]*
          Wpk[16][17][0])+(psik[17][2][1]*Wpk[16][17][1])));
        IkWpk[17][17][0] = ((pin[17][2]*psik[17][0][2])+((pin[17][0]*
          psik[17][0][0])+(pin[17][1]*psik[17][0][1])));
        IkWpk[17][17][1] = ((pin[17][2]*psik[17][1][2])+((pin[17][0]*
          psik[17][1][0])+(pin[17][1]*psik[17][1][1])));
        IkWpk[17][17][2] = ((pin[17][2]*psik[17][2][2])+((pin[17][0]*
          psik[17][2][0])+(pin[17][1]*psik[17][2][1])));
        IkWpk[18][18][0] = ((ik[16][0][2]*pin[18][2])+((ik[16][0][0]*pin[18][0])
          +(ik[16][0][1]*pin[18][1])));
        IkWpk[18][18][1] = ((ik[16][1][2]*pin[18][2])+((ik[16][1][0]*pin[18][0])
          +(ik[16][1][1]*pin[18][1])));
        IkWpk[18][18][2] = ((ik[16][2][2]*pin[18][2])+((ik[16][2][0]*pin[18][0])
          +(ik[16][2][1]*pin[18][1])));
        IkWpk[18][19][0] = ((ik[17][0][2]*Wpk[18][19][2])+((ik[17][0][0]*
          Wpk[18][19][0])+(ik[17][0][1]*Wpk[18][19][1])));
        IkWpk[18][19][1] = ((ik[17][1][2]*Wpk[18][19][2])+((ik[17][1][0]*
          Wpk[18][19][0])+(ik[17][1][1]*Wpk[18][19][1])));
        IkWpk[18][19][2] = ((ik[17][2][2]*Wpk[18][19][2])+((ik[17][2][0]*
          Wpk[18][19][0])+(ik[17][2][1]*Wpk[18][19][1])));
        IkWpk[18][20][0] = ((ik[18][0][2]*Wpk[18][20][2])+((ik[18][0][0]*
          Wpk[18][20][0])+(ik[18][0][1]*Wpk[18][20][1])));
        IkWpk[18][20][1] = ((ik[18][1][2]*Wpk[18][20][2])+((ik[18][1][0]*
          Wpk[18][20][0])+(ik[18][1][1]*Wpk[18][20][1])));
        IkWpk[18][20][2] = ((ik[18][2][2]*Wpk[18][20][2])+((ik[18][2][0]*
          Wpk[18][20][0])+(ik[18][2][1]*Wpk[18][20][1])));
        IkWpk[18][21][0] = ((psik[21][0][2]*Wpk[18][21][2])+((psik[21][0][0]*
          Wpk[18][21][0])+(psik[21][0][1]*Wpk[18][21][1])));
        IkWpk[18][21][1] = ((psik[21][1][2]*Wpk[18][21][2])+((psik[21][1][0]*
          Wpk[18][21][0])+(psik[21][1][1]*Wpk[18][21][1])));
        IkWpk[18][21][2] = ((psik[21][2][2]*Wpk[18][21][2])+((psik[21][2][0]*
          Wpk[18][21][0])+(psik[21][2][1]*Wpk[18][21][1])));
        IkWpk[19][19][0] = ((ik[17][0][2]*pin[19][2])+((ik[17][0][0]*pin[19][0])
          +(ik[17][0][1]*pin[19][1])));
        IkWpk[19][19][1] = ((ik[17][1][2]*pin[19][2])+((ik[17][1][0]*pin[19][0])
          +(ik[17][1][1]*pin[19][1])));
        IkWpk[19][19][2] = ((ik[17][2][2]*pin[19][2])+((ik[17][2][0]*pin[19][0])
          +(ik[17][2][1]*pin[19][1])));
        IkWpk[19][20][0] = ((ik[18][0][2]*Wpk[19][20][2])+((ik[18][0][0]*
          Wpk[19][20][0])+(ik[18][0][1]*Wpk[19][20][1])));
        IkWpk[19][20][1] = ((ik[18][1][2]*Wpk[19][20][2])+((ik[18][1][0]*
          Wpk[19][20][0])+(ik[18][1][1]*Wpk[19][20][1])));
        IkWpk[19][20][2] = ((ik[18][2][2]*Wpk[19][20][2])+((ik[18][2][0]*
          Wpk[19][20][0])+(ik[18][2][1]*Wpk[19][20][1])));
        IkWpk[19][21][0] = ((psik[21][0][2]*Wpk[19][21][2])+((psik[21][0][0]*
          Wpk[19][21][0])+(psik[21][0][1]*Wpk[19][21][1])));
        IkWpk[19][21][1] = ((psik[21][1][2]*Wpk[19][21][2])+((psik[21][1][0]*
          Wpk[19][21][0])+(psik[21][1][1]*Wpk[19][21][1])));
        IkWpk[19][21][2] = ((psik[21][2][2]*Wpk[19][21][2])+((psik[21][2][0]*
          Wpk[19][21][0])+(psik[21][2][1]*Wpk[19][21][1])));
        IkWpk[20][20][0] = ((ik[18][0][2]*pin[20][2])+((ik[18][0][0]*pin[20][0])
          +(ik[18][0][1]*pin[20][1])));
        IkWpk[20][20][1] = ((ik[18][1][2]*pin[20][2])+((ik[18][1][0]*pin[20][0])
          +(ik[18][1][1]*pin[20][1])));
        IkWpk[20][20][2] = ((ik[18][2][2]*pin[20][2])+((ik[18][2][0]*pin[20][0])
          +(ik[18][2][1]*pin[20][1])));
        IkWpk[20][21][0] = ((psik[21][0][2]*Wpk[20][21][2])+((psik[21][0][0]*
          Wpk[20][21][0])+(psik[21][0][1]*Wpk[20][21][1])));
        IkWpk[20][21][1] = ((psik[21][1][2]*Wpk[20][21][2])+((psik[21][1][0]*
          Wpk[20][21][0])+(psik[21][1][1]*Wpk[20][21][1])));
        IkWpk[20][21][2] = ((psik[21][2][2]*Wpk[20][21][2])+((psik[21][2][0]*
          Wpk[20][21][0])+(psik[21][2][1]*Wpk[20][21][1])));
        IkWpk[21][21][0] = ((pin[21][2]*psik[21][0][2])+((pin[21][0]*
          psik[21][0][0])+(pin[21][1]*psik[21][0][1])));
        IkWpk[21][21][1] = ((pin[21][2]*psik[21][1][2])+((pin[21][0]*
          psik[21][1][0])+(pin[21][1]*psik[21][1][1])));
        IkWpk[21][21][2] = ((pin[21][2]*psik[21][2][2])+((pin[21][0]*
          psik[21][2][0])+(pin[21][1]*psik[21][2][1])));
        temp[0] = ((mk[2]*((Vpk[0][7][2]*Vpk[0][7][2])+((Vpk[0][7][0]*
          Vpk[0][7][0])+(Vpk[0][7][1]*Vpk[0][7][1]))))+((mk[0]*((Vpk[0][3][2]*
          Vpk[0][3][2])+((Vpk[0][3][0]*Vpk[0][3][0])+(Vpk[0][3][1]*Vpk[0][3][1])
          )))+(mk[1]*((Vpk[0][6][2]*Vpk[0][6][2])+((Vpk[0][6][0]*Vpk[0][6][0])+(
          Vpk[0][6][1]*Vpk[0][6][1]))))));
        temp[1] = ((mk[6]*((Vpk[0][10][2]*Vpk[0][10][2])+((Vpk[0][10][0]*
          Vpk[0][10][0])+(Vpk[0][10][1]*Vpk[0][10][1]))))+((psmk[9]*((
          Vpk[0][9][2]*Vpk[0][9][2])+((Vpk[0][9][0]*Vpk[0][9][0])+(Vpk[0][9][1]*
          Vpk[0][9][1]))))+((mk[3]*((Vpk[0][8][2]*Vpk[0][8][2])+((Vpk[0][8][0]*
          Vpk[0][8][0])+(Vpk[0][8][1]*Vpk[0][8][1]))))+temp[0])));
        temp[2] = ((psmk[13]*((Vpk[0][13][2]*Vpk[0][13][2])+((Vpk[0][13][0]*
          Vpk[0][13][0])+(Vpk[0][13][1]*Vpk[0][13][1]))))+((mk[8]*((
          Vpk[0][12][2]*Vpk[0][12][2])+((Vpk[0][12][0]*Vpk[0][12][0])+(
          Vpk[0][12][1]*Vpk[0][12][1]))))+((mk[7]*((Vpk[0][11][2]*Vpk[0][11][2])
          +((Vpk[0][11][0]*Vpk[0][11][0])+(Vpk[0][11][1]*Vpk[0][11][1]))))+
          temp[1])));
        temp[3] = ((mk[13]*((Vpk[0][16][2]*Vpk[0][16][2])+((Vpk[0][16][0]*
          Vpk[0][16][0])+(Vpk[0][16][1]*Vpk[0][16][1]))))+((mk[12]*((
          Vpk[0][15][2]*Vpk[0][15][2])+((Vpk[0][15][0]*Vpk[0][15][0])+(
          Vpk[0][15][1]*Vpk[0][15][1]))))+((mk[11]*((Vpk[0][14][2]*Vpk[0][14][2]
          )+((Vpk[0][14][0]*Vpk[0][14][0])+(Vpk[0][14][1]*Vpk[0][14][1]))))+
          temp[2])));
        temp[4] = ((mk[17]*((Vpk[0][19][2]*Vpk[0][19][2])+((Vpk[0][19][0]*
          Vpk[0][19][0])+(Vpk[0][19][1]*Vpk[0][19][1]))))+((mk[16]*((
          Vpk[0][18][2]*Vpk[0][18][2])+((Vpk[0][18][0]*Vpk[0][18][0])+(
          Vpk[0][18][1]*Vpk[0][18][1]))))+((psmk[17]*((Vpk[0][17][2]*
          Vpk[0][17][2])+((Vpk[0][17][0]*Vpk[0][17][0])+(Vpk[0][17][1]*
          Vpk[0][17][1]))))+temp[3])));
        mm[0][0] = ((psmk[21]*((Vpk[0][21][2]*Vpk[0][21][2])+((Vpk[0][21][0]*
          Vpk[0][21][0])+(Vpk[0][21][1]*Vpk[0][21][1]))))+((mk[18]*((
          Vpk[0][20][2]*Vpk[0][20][2])+((Vpk[0][20][0]*Vpk[0][20][0])+(
          Vpk[0][20][1]*Vpk[0][20][1]))))+temp[4]));
        temp[0] = ((mk[2]*((Vpk[0][7][2]*Vpk[1][7][2])+((Vpk[0][7][0]*
          Vpk[1][7][0])+(Vpk[0][7][1]*Vpk[1][7][1]))))+((mk[0]*((Vpk[0][3][2]*
          Vpk[1][3][2])+((Vpk[0][3][0]*Vpk[1][3][0])+(Vpk[0][3][1]*Vpk[1][3][1])
          )))+(mk[1]*((Vpk[0][6][2]*Vpk[1][6][2])+((Vpk[0][6][0]*Vpk[1][6][0])+(
          Vpk[0][6][1]*Vpk[1][6][1]))))));
        temp[1] = ((mk[6]*((Vpk[0][10][2]*Vpk[1][10][2])+((Vpk[0][10][0]*
          Vpk[1][10][0])+(Vpk[0][10][1]*Vpk[1][10][1]))))+((psmk[9]*((
          Vpk[0][9][2]*Vpk[1][9][2])+((Vpk[0][9][0]*Vpk[1][9][0])+(Vpk[0][9][1]*
          Vpk[1][9][1]))))+((mk[3]*((Vpk[0][8][2]*Vpk[1][8][2])+((Vpk[0][8][0]*
          Vpk[1][8][0])+(Vpk[0][8][1]*Vpk[1][8][1]))))+temp[0])));
        temp[2] = ((psmk[13]*((Vpk[0][13][2]*Vpk[1][13][2])+((Vpk[0][13][0]*
          Vpk[1][13][0])+(Vpk[0][13][1]*Vpk[1][13][1]))))+((mk[8]*((
          Vpk[0][12][2]*Vpk[1][12][2])+((Vpk[0][12][0]*Vpk[1][12][0])+(
          Vpk[0][12][1]*Vpk[1][12][1]))))+((mk[7]*((Vpk[0][11][2]*Vpk[1][11][2])
          +((Vpk[0][11][0]*Vpk[1][11][0])+(Vpk[0][11][1]*Vpk[1][11][1]))))+
          temp[1])));
        temp[3] = ((mk[13]*((Vpk[0][16][2]*Vpk[1][16][2])+((Vpk[0][16][0]*
          Vpk[1][16][0])+(Vpk[0][16][1]*Vpk[1][16][1]))))+((mk[12]*((
          Vpk[0][15][2]*Vpk[1][15][2])+((Vpk[0][15][0]*Vpk[1][15][0])+(
          Vpk[0][15][1]*Vpk[1][15][1]))))+((mk[11]*((Vpk[0][14][2]*Vpk[1][14][2]
          )+((Vpk[0][14][0]*Vpk[1][14][0])+(Vpk[0][14][1]*Vpk[1][14][1]))))+
          temp[2])));
        temp[4] = ((mk[17]*((Vpk[0][19][2]*Vpk[1][19][2])+((Vpk[0][19][0]*
          Vpk[1][19][0])+(Vpk[0][19][1]*Vpk[1][19][1]))))+((mk[16]*((
          Vpk[0][18][2]*Vpk[1][18][2])+((Vpk[0][18][0]*Vpk[1][18][0])+(
          Vpk[0][18][1]*Vpk[1][18][1]))))+((psmk[17]*((Vpk[0][17][2]*
          Vpk[1][17][2])+((Vpk[0][17][0]*Vpk[1][17][0])+(Vpk[0][17][1]*
          Vpk[1][17][1]))))+temp[3])));
        mm[0][1] = ((psmk[21]*((Vpk[0][21][2]*Vpk[1][21][2])+((Vpk[0][21][0]*
          Vpk[1][21][0])+(Vpk[0][21][1]*Vpk[1][21][1]))))+((mk[18]*((
          Vpk[0][20][2]*Vpk[1][20][2])+((Vpk[0][20][0]*Vpk[1][20][0])+(
          Vpk[0][20][1]*Vpk[1][20][1]))))+temp[4]));
        temp[0] = ((mk[2]*((Vpk[0][7][2]*Vpk[2][7][2])+((Vpk[0][7][0]*
          Vpk[2][7][0])+(Vpk[0][7][1]*Vpk[2][7][1]))))+((mk[0]*((Vpk[0][3][2]*
          Vpk[2][3][2])+((Vpk[0][3][0]*Vpk[2][3][0])+(Vpk[0][3][1]*Vpk[2][3][1])
          )))+(mk[1]*((Vpk[0][6][2]*Vpk[2][6][2])+((Vpk[0][6][0]*Vpk[2][6][0])+(
          Vpk[0][6][1]*Vpk[2][6][1]))))));
        temp[1] = ((mk[6]*((Vpk[0][10][2]*Vpk[2][10][2])+((Vpk[0][10][0]*
          Vpk[2][10][0])+(Vpk[0][10][1]*Vpk[2][10][1]))))+((psmk[9]*((
          Vpk[0][9][2]*Vpk[2][9][2])+((Vpk[0][9][0]*Vpk[2][9][0])+(Vpk[0][9][1]*
          Vpk[2][9][1]))))+((mk[3]*((Vpk[0][8][2]*Vpk[2][8][2])+((Vpk[0][8][0]*
          Vpk[2][8][0])+(Vpk[0][8][1]*Vpk[2][8][1]))))+temp[0])));
        temp[2] = ((psmk[13]*((Vpk[0][13][2]*Vpk[2][13][2])+((Vpk[0][13][0]*
          Vpk[2][13][0])+(Vpk[0][13][1]*Vpk[2][13][1]))))+((mk[8]*((
          Vpk[0][12][2]*Vpk[2][12][2])+((Vpk[0][12][0]*Vpk[2][12][0])+(
          Vpk[0][12][1]*Vpk[2][12][1]))))+((mk[7]*((Vpk[0][11][2]*Vpk[2][11][2])
          +((Vpk[0][11][0]*Vpk[2][11][0])+(Vpk[0][11][1]*Vpk[2][11][1]))))+
          temp[1])));
        temp[3] = ((mk[13]*((Vpk[0][16][2]*Vpk[2][16][2])+((Vpk[0][16][0]*
          Vpk[2][16][0])+(Vpk[0][16][1]*Vpk[2][16][1]))))+((mk[12]*((
          Vpk[0][15][2]*Vpk[2][15][2])+((Vpk[0][15][0]*Vpk[2][15][0])+(
          Vpk[0][15][1]*Vpk[2][15][1]))))+((mk[11]*((Vpk[0][14][2]*Vpk[2][14][2]
          )+((Vpk[0][14][0]*Vpk[2][14][0])+(Vpk[0][14][1]*Vpk[2][14][1]))))+
          temp[2])));
        temp[4] = ((mk[17]*((Vpk[0][19][2]*Vpk[2][19][2])+((Vpk[0][19][0]*
          Vpk[2][19][0])+(Vpk[0][19][1]*Vpk[2][19][1]))))+((mk[16]*((
          Vpk[0][18][2]*Vpk[2][18][2])+((Vpk[0][18][0]*Vpk[2][18][0])+(
          Vpk[0][18][1]*Vpk[2][18][1]))))+((psmk[17]*((Vpk[0][17][2]*
          Vpk[2][17][2])+((Vpk[0][17][0]*Vpk[2][17][0])+(Vpk[0][17][1]*
          Vpk[2][17][1]))))+temp[3])));
        mm[0][2] = ((psmk[21]*((Vpk[0][21][2]*Vpk[2][21][2])+((Vpk[0][21][0]*
          Vpk[2][21][0])+(Vpk[0][21][1]*Vpk[2][21][1]))))+((mk[18]*((
          Vpk[0][20][2]*Vpk[2][20][2])+((Vpk[0][20][0]*Vpk[2][20][0])+(
          Vpk[0][20][1]*Vpk[2][20][1]))))+temp[4]));
        temp[0] = ((mk[3]*((Vpk[0][8][2]*Vpk[3][8][2])+((Vpk[0][8][0]*
          Vpk[3][8][0])+(Vpk[0][8][1]*Vpk[3][8][1]))))+((mk[2]*((Vpk[0][7][2]*
          Vpk[3][7][2])+((Vpk[0][7][0]*Vpk[3][7][0])+(Vpk[0][7][1]*Vpk[3][7][1])
          )))+((mk[0]*((rk[0][2]*Vpk[0][3][1])-(rk[0][1]*Vpk[0][3][2])))+(mk[1]*
          ((Vpk[0][6][2]*Vpk[3][6][2])+((Vpk[0][6][0]*Vpk[3][6][0])+(
          Vpk[0][6][1]*Vpk[3][6][1])))))));
        temp[1] = ((mk[7]*((Vpk[0][11][2]*Vpk[3][11][2])+((Vpk[0][11][0]*
          Vpk[3][11][0])+(Vpk[0][11][1]*Vpk[3][11][1]))))+((mk[6]*((
          Vpk[0][10][2]*Vpk[3][10][2])+((Vpk[0][10][0]*Vpk[3][10][0])+(
          Vpk[0][10][1]*Vpk[3][10][1]))))+((psmk[9]*((Vpk[0][9][2]*Vpk[3][9][2])
          +((Vpk[0][9][0]*Vpk[3][9][0])+(Vpk[0][9][1]*Vpk[3][9][1]))))+temp[0]))
          );
        temp[2] = ((mk[11]*((Vpk[0][14][2]*Vpk[3][14][2])+((Vpk[0][14][0]*
          Vpk[3][14][0])+(Vpk[0][14][1]*Vpk[3][14][1]))))+((psmk[13]*((
          Vpk[0][13][2]*Vpk[3][13][2])+((Vpk[0][13][0]*Vpk[3][13][0])+(
          Vpk[0][13][1]*Vpk[3][13][1]))))+((mk[8]*((Vpk[0][12][2]*Vpk[3][12][2])
          +((Vpk[0][12][0]*Vpk[3][12][0])+(Vpk[0][12][1]*Vpk[3][12][1]))))+
          temp[1])));
        temp[3] = ((psmk[17]*((Vpk[0][17][2]*Vpk[3][17][2])+((Vpk[0][17][0]*
          Vpk[3][17][0])+(Vpk[0][17][1]*Vpk[3][17][1]))))+((mk[13]*((
          Vpk[0][16][2]*Vpk[3][16][2])+((Vpk[0][16][0]*Vpk[3][16][0])+(
          Vpk[0][16][1]*Vpk[3][16][1]))))+((mk[12]*((Vpk[0][15][2]*Vpk[3][15][2]
          )+((Vpk[0][15][0]*Vpk[3][15][0])+(Vpk[0][15][1]*Vpk[3][15][1]))))+
          temp[2])));
        temp[4] = ((mk[18]*((Vpk[0][20][2]*Vpk[3][20][2])+((Vpk[0][20][0]*
          Vpk[3][20][0])+(Vpk[0][20][1]*Vpk[3][20][1]))))+((mk[17]*((
          Vpk[0][19][2]*Vpk[3][19][2])+((Vpk[0][19][0]*Vpk[3][19][0])+(
          Vpk[0][19][1]*Vpk[3][19][1]))))+((mk[16]*((Vpk[0][18][2]*Vpk[3][18][2]
          )+((Vpk[0][18][0]*Vpk[3][18][0])+(Vpk[0][18][1]*Vpk[3][18][1]))))+
          temp[3])));
        mm[0][3] = ((psmk[21]*((Vpk[0][21][2]*Vpk[3][21][2])+((Vpk[0][21][0]*
          Vpk[3][21][0])+(Vpk[0][21][1]*Vpk[3][21][1]))))+temp[4]);
        temp[0] = ((mk[3]*((Vpk[0][8][2]*Vpk[4][8][2])+((Vpk[0][8][0]*
          Vpk[4][8][0])+(Vpk[0][8][1]*Vpk[4][8][1]))))+((mk[2]*((Vpk[0][7][2]*
          Vpk[4][7][2])+((Vpk[0][7][0]*Vpk[4][7][0])+(Vpk[0][7][1]*Vpk[4][7][1])
          )))+((mk[0]*((rk[0][0]*Vpk[0][3][2])-(rk[0][2]*Vpk[0][3][0])))+(mk[1]*
          ((Vpk[0][6][2]*Vpk[4][6][2])+((Vpk[0][6][0]*Vpk[4][6][0])+(
          Vpk[0][6][1]*Vpk[4][6][1])))))));
        temp[1] = ((mk[7]*((Vpk[0][11][2]*Vpk[4][11][2])+((Vpk[0][11][0]*
          Vpk[4][11][0])+(Vpk[0][11][1]*Vpk[4][11][1]))))+((mk[6]*((
          Vpk[0][10][2]*Vpk[4][10][2])+((Vpk[0][10][0]*Vpk[4][10][0])+(
          Vpk[0][10][1]*Vpk[4][10][1]))))+((psmk[9]*((Vpk[0][9][2]*Vpk[4][9][2])
          +((Vpk[0][9][0]*Vpk[4][9][0])+(Vpk[0][9][1]*Vpk[4][9][1]))))+temp[0]))
          );
        temp[2] = ((mk[11]*((Vpk[0][14][2]*Vpk[4][14][2])+((Vpk[0][14][0]*
          Vpk[4][14][0])+(Vpk[0][14][1]*Vpk[4][14][1]))))+((psmk[13]*((
          Vpk[0][13][2]*Vpk[4][13][2])+((Vpk[0][13][0]*Vpk[4][13][0])+(
          Vpk[0][13][1]*Vpk[4][13][1]))))+((mk[8]*((Vpk[0][12][2]*Vpk[4][12][2])
          +((Vpk[0][12][0]*Vpk[4][12][0])+(Vpk[0][12][1]*Vpk[4][12][1]))))+
          temp[1])));
        temp[3] = ((psmk[17]*((Vpk[0][17][2]*Vpk[4][17][2])+((Vpk[0][17][0]*
          Vpk[4][17][0])+(Vpk[0][17][1]*Vpk[4][17][1]))))+((mk[13]*((
          Vpk[0][16][2]*Vpk[4][16][2])+((Vpk[0][16][0]*Vpk[4][16][0])+(
          Vpk[0][16][1]*Vpk[4][16][1]))))+((mk[12]*((Vpk[0][15][2]*Vpk[4][15][2]
          )+((Vpk[0][15][0]*Vpk[4][15][0])+(Vpk[0][15][1]*Vpk[4][15][1]))))+
          temp[2])));
        temp[4] = ((mk[18]*((Vpk[0][20][2]*Vpk[4][20][2])+((Vpk[0][20][0]*
          Vpk[4][20][0])+(Vpk[0][20][1]*Vpk[4][20][1]))))+((mk[17]*((
          Vpk[0][19][2]*Vpk[4][19][2])+((Vpk[0][19][0]*Vpk[4][19][0])+(
          Vpk[0][19][1]*Vpk[4][19][1]))))+((mk[16]*((Vpk[0][18][2]*Vpk[4][18][2]
          )+((Vpk[0][18][0]*Vpk[4][18][0])+(Vpk[0][18][1]*Vpk[4][18][1]))))+
          temp[3])));
        mm[0][4] = ((psmk[21]*((Vpk[0][21][2]*Vpk[4][21][2])+((Vpk[0][21][0]*
          Vpk[4][21][0])+(Vpk[0][21][1]*Vpk[4][21][1]))))+temp[4]);
        temp[0] = ((mk[3]*((Vpk[0][8][2]*Vpk[5][8][2])+((Vpk[0][8][0]*
          Vpk[5][8][0])+(Vpk[0][8][1]*Vpk[5][8][1]))))+((mk[2]*((Vpk[0][7][2]*
          Vpk[5][7][2])+((Vpk[0][7][0]*Vpk[5][7][0])+(Vpk[0][7][1]*Vpk[5][7][1])
          )))+((mk[0]*((rk[0][1]*Vpk[0][3][0])-(rk[0][0]*Vpk[0][3][1])))+(mk[1]*
          ((Vpk[0][6][2]*Vpk[5][6][2])+((Vpk[0][6][0]*Vpk[5][6][0])+(
          Vpk[0][6][1]*Vpk[5][6][1])))))));
        temp[1] = ((mk[7]*((Vpk[0][11][2]*Vpk[5][11][2])+((Vpk[0][11][0]*
          Vpk[5][11][0])+(Vpk[0][11][1]*Vpk[5][11][1]))))+((mk[6]*((
          Vpk[0][10][2]*Vpk[5][10][2])+((Vpk[0][10][0]*Vpk[5][10][0])+(
          Vpk[0][10][1]*Vpk[5][10][1]))))+((psmk[9]*((Vpk[0][9][2]*Vpk[5][9][2])
          +((Vpk[0][9][0]*Vpk[5][9][0])+(Vpk[0][9][1]*Vpk[5][9][1]))))+temp[0]))
          );
        temp[2] = ((mk[11]*((Vpk[0][14][2]*Vpk[5][14][2])+((Vpk[0][14][0]*
          Vpk[5][14][0])+(Vpk[0][14][1]*Vpk[5][14][1]))))+((psmk[13]*((
          Vpk[0][13][2]*Vpk[5][13][2])+((Vpk[0][13][0]*Vpk[5][13][0])+(
          Vpk[0][13][1]*Vpk[5][13][1]))))+((mk[8]*((Vpk[0][12][2]*Vpk[5][12][2])
          +((Vpk[0][12][0]*Vpk[5][12][0])+(Vpk[0][12][1]*Vpk[5][12][1]))))+
          temp[1])));
        temp[3] = ((psmk[17]*((Vpk[0][17][2]*Vpk[5][17][2])+((Vpk[0][17][0]*
          Vpk[5][17][0])+(Vpk[0][17][1]*Vpk[5][17][1]))))+((mk[13]*((
          Vpk[0][16][2]*Vpk[5][16][2])+((Vpk[0][16][0]*Vpk[5][16][0])+(
          Vpk[0][16][1]*Vpk[5][16][1]))))+((mk[12]*((Vpk[0][15][2]*Vpk[5][15][2]
          )+((Vpk[0][15][0]*Vpk[5][15][0])+(Vpk[0][15][1]*Vpk[5][15][1]))))+
          temp[2])));
        temp[4] = ((mk[18]*((Vpk[0][20][2]*Vpk[5][20][2])+((Vpk[0][20][0]*
          Vpk[5][20][0])+(Vpk[0][20][1]*Vpk[5][20][1]))))+((mk[17]*((
          Vpk[0][19][2]*Vpk[5][19][2])+((Vpk[0][19][0]*Vpk[5][19][0])+(
          Vpk[0][19][1]*Vpk[5][19][1]))))+((mk[16]*((Vpk[0][18][2]*Vpk[5][18][2]
          )+((Vpk[0][18][0]*Vpk[5][18][0])+(Vpk[0][18][1]*Vpk[5][18][1]))))+
          temp[3])));
        mm[0][5] = ((psmk[21]*((Vpk[0][21][2]*Vpk[5][21][2])+((Vpk[0][21][0]*
          Vpk[5][21][0])+(Vpk[0][21][1]*Vpk[5][21][1]))))+temp[4]);
        temp[0] = ((mk[3]*((Vpk[0][8][2]*Vpk[6][8][2])+((Vpk[0][8][0]*
          Vpk[6][8][0])+(Vpk[0][8][1]*Vpk[6][8][1]))))+((mk[1]*((Vpk[0][6][2]*
          Vpk[6][6][2])+((Vpk[0][6][0]*Vpk[6][6][0])+(Vpk[0][6][1]*Vpk[6][6][1])
          )))+(mk[2]*((Vpk[0][7][2]*Vpk[6][7][2])+((Vpk[0][7][0]*Vpk[6][7][0])+(
          Vpk[0][7][1]*Vpk[6][7][1]))))));
        mm[0][6] = ((psmk[9]*((Vpk[0][9][2]*Vpk[6][9][2])+((Vpk[0][9][0]*
          Vpk[6][9][0])+(Vpk[0][9][1]*Vpk[6][9][1]))))+temp[0]);
        mm[0][7] = ((psmk[9]*((Vpk[0][9][2]*Vpk[7][9][2])+((Vpk[0][9][0]*
          Vpk[7][9][0])+(Vpk[0][9][1]*Vpk[7][9][1]))))+((mk[2]*((Vpk[0][7][2]*
          Vpk[7][7][2])+((Vpk[0][7][0]*Vpk[7][7][0])+(Vpk[0][7][1]*Vpk[7][7][1])
          )))+(mk[3]*((Vpk[0][8][2]*Vpk[7][8][2])+((Vpk[0][8][0]*Vpk[7][8][0])+(
          Vpk[0][8][1]*Vpk[7][8][1]))))));
        mm[0][8] = ((mk[3]*((Vpk[0][8][2]*Vpk[8][8][2])+((Vpk[0][8][0]*
          Vpk[8][8][0])+(Vpk[0][8][1]*Vpk[8][8][1]))))+(psmk[9]*((Vpk[0][9][2]*
          Vpk[8][9][2])+((Vpk[0][9][0]*Vpk[8][9][0])+(Vpk[0][9][1]*Vpk[8][9][1])
          ))));
        mm[0][9] = (psmk[9]*((Vpk[0][9][2]*Vpk[9][9][2])+((Vpk[0][9][0]*
          Vpk[9][9][0])+(Vpk[0][9][1]*Vpk[9][9][1]))));
        temp[0] = ((mk[8]*((Vpk[0][12][2]*Vpk[10][12][2])+((Vpk[0][12][0]*
          Vpk[10][12][0])+(Vpk[0][12][1]*Vpk[10][12][1]))))+((mk[6]*((
          Vpk[0][10][2]*Vpk[10][10][2])+((Vpk[0][10][0]*Vpk[10][10][0])+(
          Vpk[0][10][1]*Vpk[10][10][1]))))+(mk[7]*((Vpk[0][11][2]*Vpk[10][11][2]
          )+((Vpk[0][11][0]*Vpk[10][11][0])+(Vpk[0][11][1]*Vpk[10][11][1]))))));
        mm[0][10] = ((psmk[13]*((Vpk[0][13][2]*Vpk[10][13][2])+((Vpk[0][13][0]*
          Vpk[10][13][0])+(Vpk[0][13][1]*Vpk[10][13][1]))))+temp[0]);
        mm[0][11] = ((psmk[13]*((Vpk[0][13][2]*Vpk[11][13][2])+((Vpk[0][13][0]*
          Vpk[11][13][0])+(Vpk[0][13][1]*Vpk[11][13][1]))))+((mk[7]*((
          Vpk[0][11][2]*Vpk[11][11][2])+((Vpk[0][11][0]*Vpk[11][11][0])+(
          Vpk[0][11][1]*Vpk[11][11][1]))))+(mk[8]*((Vpk[0][12][2]*Vpk[11][12][2]
          )+((Vpk[0][12][0]*Vpk[11][12][0])+(Vpk[0][12][1]*Vpk[11][12][1]))))));
        mm[0][12] = ((mk[8]*((Vpk[0][12][2]*Vpk[12][12][2])+((Vpk[0][12][0]*
          Vpk[12][12][0])+(Vpk[0][12][1]*Vpk[12][12][1]))))+(psmk[13]*((
          Vpk[0][13][2]*Vpk[12][13][2])+((Vpk[0][13][0]*Vpk[12][13][0])+(
          Vpk[0][13][1]*Vpk[12][13][1])))));
        mm[0][13] = (psmk[13]*((Vpk[0][13][2]*Vpk[13][13][2])+((Vpk[0][13][0]*
          Vpk[13][13][0])+(Vpk[0][13][1]*Vpk[13][13][1]))));
        temp[0] = ((mk[13]*((Vpk[0][16][2]*Vpk[14][16][2])+((Vpk[0][16][0]*
          Vpk[14][16][0])+(Vpk[0][16][1]*Vpk[14][16][1]))))+((mk[11]*((
          Vpk[0][14][2]*Vpk[14][14][2])+((Vpk[0][14][0]*Vpk[14][14][0])+(
          Vpk[0][14][1]*Vpk[14][14][1]))))+(mk[12]*((Vpk[0][15][2]*
          Vpk[14][15][2])+((Vpk[0][15][0]*Vpk[14][15][0])+(Vpk[0][15][1]*
          Vpk[14][15][1]))))));
        mm[0][14] = ((psmk[17]*((Vpk[0][17][2]*Vpk[14][17][2])+((Vpk[0][17][0]*
          Vpk[14][17][0])+(Vpk[0][17][1]*Vpk[14][17][1]))))+temp[0]);
        mm[0][15] = ((psmk[17]*((Vpk[0][17][2]*Vpk[15][17][2])+((Vpk[0][17][0]*
          Vpk[15][17][0])+(Vpk[0][17][1]*Vpk[15][17][1]))))+((mk[12]*((
          Vpk[0][15][2]*Vpk[15][15][2])+((Vpk[0][15][0]*Vpk[15][15][0])+(
          Vpk[0][15][1]*Vpk[15][15][1]))))+(mk[13]*((Vpk[0][16][2]*
          Vpk[15][16][2])+((Vpk[0][16][0]*Vpk[15][16][0])+(Vpk[0][16][1]*
          Vpk[15][16][1]))))));
        mm[0][16] = ((mk[13]*((Vpk[0][16][2]*Vpk[16][16][2])+((Vpk[0][16][0]*
          Vpk[16][16][0])+(Vpk[0][16][1]*Vpk[16][16][1]))))+(psmk[17]*((
          Vpk[0][17][2]*Vpk[16][17][2])+((Vpk[0][17][0]*Vpk[16][17][0])+(
          Vpk[0][17][1]*Vpk[16][17][1])))));
        mm[0][17] = (psmk[17]*((Vpk[0][17][2]*Vpk[17][17][2])+((Vpk[0][17][0]*
          Vpk[17][17][0])+(Vpk[0][17][1]*Vpk[17][17][1]))));
        temp[0] = ((mk[18]*((Vpk[0][20][2]*Vpk[18][20][2])+((Vpk[0][20][0]*
          Vpk[18][20][0])+(Vpk[0][20][1]*Vpk[18][20][1]))))+((mk[16]*((
          Vpk[0][18][2]*Vpk[18][18][2])+((Vpk[0][18][0]*Vpk[18][18][0])+(
          Vpk[0][18][1]*Vpk[18][18][1]))))+(mk[17]*((Vpk[0][19][2]*
          Vpk[18][19][2])+((Vpk[0][19][0]*Vpk[18][19][0])+(Vpk[0][19][1]*
          Vpk[18][19][1]))))));
        mm[0][18] = ((psmk[21]*((Vpk[0][21][2]*Vpk[18][21][2])+((Vpk[0][21][0]*
          Vpk[18][21][0])+(Vpk[0][21][1]*Vpk[18][21][1]))))+temp[0]);
        mm[0][19] = ((psmk[21]*((Vpk[0][21][2]*Vpk[19][21][2])+((Vpk[0][21][0]*
          Vpk[19][21][0])+(Vpk[0][21][1]*Vpk[19][21][1]))))+((mk[17]*((
          Vpk[0][19][2]*Vpk[19][19][2])+((Vpk[0][19][0]*Vpk[19][19][0])+(
          Vpk[0][19][1]*Vpk[19][19][1]))))+(mk[18]*((Vpk[0][20][2]*
          Vpk[19][20][2])+((Vpk[0][20][0]*Vpk[19][20][0])+(Vpk[0][20][1]*
          Vpk[19][20][1]))))));
        mm[0][20] = ((mk[18]*((Vpk[0][20][2]*Vpk[20][20][2])+((Vpk[0][20][0]*
          Vpk[20][20][0])+(Vpk[0][20][1]*Vpk[20][20][1]))))+(psmk[21]*((
          Vpk[0][21][2]*Vpk[20][21][2])+((Vpk[0][21][0]*Vpk[20][21][0])+(
          Vpk[0][21][1]*Vpk[20][21][1])))));
        mm[0][21] = (psmk[21]*((Vpk[0][21][2]*Vpk[21][21][2])+((Vpk[0][21][0]*
          Vpk[21][21][0])+(Vpk[0][21][1]*Vpk[21][21][1]))));
        temp[0] = ((mk[2]*((Vpk[1][7][2]*Vpk[1][7][2])+((Vpk[1][7][0]*
          Vpk[1][7][0])+(Vpk[1][7][1]*Vpk[1][7][1]))))+((mk[0]*((Vpk[1][3][2]*
          Vpk[1][3][2])+((Vpk[1][3][0]*Vpk[1][3][0])+(Vpk[1][3][1]*Vpk[1][3][1])
          )))+(mk[1]*((Vpk[1][6][2]*Vpk[1][6][2])+((Vpk[1][6][0]*Vpk[1][6][0])+(
          Vpk[1][6][1]*Vpk[1][6][1]))))));
        temp[1] = ((mk[6]*((Vpk[1][10][2]*Vpk[1][10][2])+((Vpk[1][10][0]*
          Vpk[1][10][0])+(Vpk[1][10][1]*Vpk[1][10][1]))))+((psmk[9]*((
          Vpk[1][9][2]*Vpk[1][9][2])+((Vpk[1][9][0]*Vpk[1][9][0])+(Vpk[1][9][1]*
          Vpk[1][9][1]))))+((mk[3]*((Vpk[1][8][2]*Vpk[1][8][2])+((Vpk[1][8][0]*
          Vpk[1][8][0])+(Vpk[1][8][1]*Vpk[1][8][1]))))+temp[0])));
        temp[2] = ((psmk[13]*((Vpk[1][13][2]*Vpk[1][13][2])+((Vpk[1][13][0]*
          Vpk[1][13][0])+(Vpk[1][13][1]*Vpk[1][13][1]))))+((mk[8]*((
          Vpk[1][12][2]*Vpk[1][12][2])+((Vpk[1][12][0]*Vpk[1][12][0])+(
          Vpk[1][12][1]*Vpk[1][12][1]))))+((mk[7]*((Vpk[1][11][2]*Vpk[1][11][2])
          +((Vpk[1][11][0]*Vpk[1][11][0])+(Vpk[1][11][1]*Vpk[1][11][1]))))+
          temp[1])));
        temp[3] = ((mk[13]*((Vpk[1][16][2]*Vpk[1][16][2])+((Vpk[1][16][0]*
          Vpk[1][16][0])+(Vpk[1][16][1]*Vpk[1][16][1]))))+((mk[12]*((
          Vpk[1][15][2]*Vpk[1][15][2])+((Vpk[1][15][0]*Vpk[1][15][0])+(
          Vpk[1][15][1]*Vpk[1][15][1]))))+((mk[11]*((Vpk[1][14][2]*Vpk[1][14][2]
          )+((Vpk[1][14][0]*Vpk[1][14][0])+(Vpk[1][14][1]*Vpk[1][14][1]))))+
          temp[2])));
        temp[4] = ((mk[17]*((Vpk[1][19][2]*Vpk[1][19][2])+((Vpk[1][19][0]*
          Vpk[1][19][0])+(Vpk[1][19][1]*Vpk[1][19][1]))))+((mk[16]*((
          Vpk[1][18][2]*Vpk[1][18][2])+((Vpk[1][18][0]*Vpk[1][18][0])+(
          Vpk[1][18][1]*Vpk[1][18][1]))))+((psmk[17]*((Vpk[1][17][2]*
          Vpk[1][17][2])+((Vpk[1][17][0]*Vpk[1][17][0])+(Vpk[1][17][1]*
          Vpk[1][17][1]))))+temp[3])));
        mm[1][1] = ((psmk[21]*((Vpk[1][21][2]*Vpk[1][21][2])+((Vpk[1][21][0]*
          Vpk[1][21][0])+(Vpk[1][21][1]*Vpk[1][21][1]))))+((mk[18]*((
          Vpk[1][20][2]*Vpk[1][20][2])+((Vpk[1][20][0]*Vpk[1][20][0])+(
          Vpk[1][20][1]*Vpk[1][20][1]))))+temp[4]));
        temp[0] = ((mk[2]*((Vpk[1][7][2]*Vpk[2][7][2])+((Vpk[1][7][0]*
          Vpk[2][7][0])+(Vpk[1][7][1]*Vpk[2][7][1]))))+((mk[0]*((Vpk[1][3][2]*
          Vpk[2][3][2])+((Vpk[1][3][0]*Vpk[2][3][0])+(Vpk[1][3][1]*Vpk[2][3][1])
          )))+(mk[1]*((Vpk[1][6][2]*Vpk[2][6][2])+((Vpk[1][6][0]*Vpk[2][6][0])+(
          Vpk[1][6][1]*Vpk[2][6][1]))))));
        temp[1] = ((mk[6]*((Vpk[1][10][2]*Vpk[2][10][2])+((Vpk[1][10][0]*
          Vpk[2][10][0])+(Vpk[1][10][1]*Vpk[2][10][1]))))+((psmk[9]*((
          Vpk[1][9][2]*Vpk[2][9][2])+((Vpk[1][9][0]*Vpk[2][9][0])+(Vpk[1][9][1]*
          Vpk[2][9][1]))))+((mk[3]*((Vpk[1][8][2]*Vpk[2][8][2])+((Vpk[1][8][0]*
          Vpk[2][8][0])+(Vpk[1][8][1]*Vpk[2][8][1]))))+temp[0])));
        temp[2] = ((psmk[13]*((Vpk[1][13][2]*Vpk[2][13][2])+((Vpk[1][13][0]*
          Vpk[2][13][0])+(Vpk[1][13][1]*Vpk[2][13][1]))))+((mk[8]*((
          Vpk[1][12][2]*Vpk[2][12][2])+((Vpk[1][12][0]*Vpk[2][12][0])+(
          Vpk[1][12][1]*Vpk[2][12][1]))))+((mk[7]*((Vpk[1][11][2]*Vpk[2][11][2])
          +((Vpk[1][11][0]*Vpk[2][11][0])+(Vpk[1][11][1]*Vpk[2][11][1]))))+
          temp[1])));
        temp[3] = ((mk[13]*((Vpk[1][16][2]*Vpk[2][16][2])+((Vpk[1][16][0]*
          Vpk[2][16][0])+(Vpk[1][16][1]*Vpk[2][16][1]))))+((mk[12]*((
          Vpk[1][15][2]*Vpk[2][15][2])+((Vpk[1][15][0]*Vpk[2][15][0])+(
          Vpk[1][15][1]*Vpk[2][15][1]))))+((mk[11]*((Vpk[1][14][2]*Vpk[2][14][2]
          )+((Vpk[1][14][0]*Vpk[2][14][0])+(Vpk[1][14][1]*Vpk[2][14][1]))))+
          temp[2])));
        temp[4] = ((mk[17]*((Vpk[1][19][2]*Vpk[2][19][2])+((Vpk[1][19][0]*
          Vpk[2][19][0])+(Vpk[1][19][1]*Vpk[2][19][1]))))+((mk[16]*((
          Vpk[1][18][2]*Vpk[2][18][2])+((Vpk[1][18][0]*Vpk[2][18][0])+(
          Vpk[1][18][1]*Vpk[2][18][1]))))+((psmk[17]*((Vpk[1][17][2]*
          Vpk[2][17][2])+((Vpk[1][17][0]*Vpk[2][17][0])+(Vpk[1][17][1]*
          Vpk[2][17][1]))))+temp[3])));
        mm[1][2] = ((psmk[21]*((Vpk[1][21][2]*Vpk[2][21][2])+((Vpk[1][21][0]*
          Vpk[2][21][0])+(Vpk[1][21][1]*Vpk[2][21][1]))))+((mk[18]*((
          Vpk[1][20][2]*Vpk[2][20][2])+((Vpk[1][20][0]*Vpk[2][20][0])+(
          Vpk[1][20][1]*Vpk[2][20][1]))))+temp[4]));
        temp[0] = ((mk[3]*((Vpk[1][8][2]*Vpk[3][8][2])+((Vpk[1][8][0]*
          Vpk[3][8][0])+(Vpk[1][8][1]*Vpk[3][8][1]))))+((mk[2]*((Vpk[1][7][2]*
          Vpk[3][7][2])+((Vpk[1][7][0]*Vpk[3][7][0])+(Vpk[1][7][1]*Vpk[3][7][1])
          )))+((mk[0]*((rk[0][2]*Vpk[1][3][1])-(rk[0][1]*Vpk[1][3][2])))+(mk[1]*
          ((Vpk[1][6][2]*Vpk[3][6][2])+((Vpk[1][6][0]*Vpk[3][6][0])+(
          Vpk[1][6][1]*Vpk[3][6][1])))))));
        temp[1] = ((mk[7]*((Vpk[1][11][2]*Vpk[3][11][2])+((Vpk[1][11][0]*
          Vpk[3][11][0])+(Vpk[1][11][1]*Vpk[3][11][1]))))+((mk[6]*((
          Vpk[1][10][2]*Vpk[3][10][2])+((Vpk[1][10][0]*Vpk[3][10][0])+(
          Vpk[1][10][1]*Vpk[3][10][1]))))+((psmk[9]*((Vpk[1][9][2]*Vpk[3][9][2])
          +((Vpk[1][9][0]*Vpk[3][9][0])+(Vpk[1][9][1]*Vpk[3][9][1]))))+temp[0]))
          );
        temp[2] = ((mk[11]*((Vpk[1][14][2]*Vpk[3][14][2])+((Vpk[1][14][0]*
          Vpk[3][14][0])+(Vpk[1][14][1]*Vpk[3][14][1]))))+((psmk[13]*((
          Vpk[1][13][2]*Vpk[3][13][2])+((Vpk[1][13][0]*Vpk[3][13][0])+(
          Vpk[1][13][1]*Vpk[3][13][1]))))+((mk[8]*((Vpk[1][12][2]*Vpk[3][12][2])
          +((Vpk[1][12][0]*Vpk[3][12][0])+(Vpk[1][12][1]*Vpk[3][12][1]))))+
          temp[1])));
        temp[3] = ((psmk[17]*((Vpk[1][17][2]*Vpk[3][17][2])+((Vpk[1][17][0]*
          Vpk[3][17][0])+(Vpk[1][17][1]*Vpk[3][17][1]))))+((mk[13]*((
          Vpk[1][16][2]*Vpk[3][16][2])+((Vpk[1][16][0]*Vpk[3][16][0])+(
          Vpk[1][16][1]*Vpk[3][16][1]))))+((mk[12]*((Vpk[1][15][2]*Vpk[3][15][2]
          )+((Vpk[1][15][0]*Vpk[3][15][0])+(Vpk[1][15][1]*Vpk[3][15][1]))))+
          temp[2])));
        temp[4] = ((mk[18]*((Vpk[1][20][2]*Vpk[3][20][2])+((Vpk[1][20][0]*
          Vpk[3][20][0])+(Vpk[1][20][1]*Vpk[3][20][1]))))+((mk[17]*((
          Vpk[1][19][2]*Vpk[3][19][2])+((Vpk[1][19][0]*Vpk[3][19][0])+(
          Vpk[1][19][1]*Vpk[3][19][1]))))+((mk[16]*((Vpk[1][18][2]*Vpk[3][18][2]
          )+((Vpk[1][18][0]*Vpk[3][18][0])+(Vpk[1][18][1]*Vpk[3][18][1]))))+
          temp[3])));
        mm[1][3] = ((psmk[21]*((Vpk[1][21][2]*Vpk[3][21][2])+((Vpk[1][21][0]*
          Vpk[3][21][0])+(Vpk[1][21][1]*Vpk[3][21][1]))))+temp[4]);
        temp[0] = ((mk[3]*((Vpk[1][8][2]*Vpk[4][8][2])+((Vpk[1][8][0]*
          Vpk[4][8][0])+(Vpk[1][8][1]*Vpk[4][8][1]))))+((mk[2]*((Vpk[1][7][2]*
          Vpk[4][7][2])+((Vpk[1][7][0]*Vpk[4][7][0])+(Vpk[1][7][1]*Vpk[4][7][1])
          )))+((mk[0]*((rk[0][0]*Vpk[1][3][2])-(rk[0][2]*Vpk[1][3][0])))+(mk[1]*
          ((Vpk[1][6][2]*Vpk[4][6][2])+((Vpk[1][6][0]*Vpk[4][6][0])+(
          Vpk[1][6][1]*Vpk[4][6][1])))))));
        temp[1] = ((mk[7]*((Vpk[1][11][2]*Vpk[4][11][2])+((Vpk[1][11][0]*
          Vpk[4][11][0])+(Vpk[1][11][1]*Vpk[4][11][1]))))+((mk[6]*((
          Vpk[1][10][2]*Vpk[4][10][2])+((Vpk[1][10][0]*Vpk[4][10][0])+(
          Vpk[1][10][1]*Vpk[4][10][1]))))+((psmk[9]*((Vpk[1][9][2]*Vpk[4][9][2])
          +((Vpk[1][9][0]*Vpk[4][9][0])+(Vpk[1][9][1]*Vpk[4][9][1]))))+temp[0]))
          );
        temp[2] = ((mk[11]*((Vpk[1][14][2]*Vpk[4][14][2])+((Vpk[1][14][0]*
          Vpk[4][14][0])+(Vpk[1][14][1]*Vpk[4][14][1]))))+((psmk[13]*((
          Vpk[1][13][2]*Vpk[4][13][2])+((Vpk[1][13][0]*Vpk[4][13][0])+(
          Vpk[1][13][1]*Vpk[4][13][1]))))+((mk[8]*((Vpk[1][12][2]*Vpk[4][12][2])
          +((Vpk[1][12][0]*Vpk[4][12][0])+(Vpk[1][12][1]*Vpk[4][12][1]))))+
          temp[1])));
        temp[3] = ((psmk[17]*((Vpk[1][17][2]*Vpk[4][17][2])+((Vpk[1][17][0]*
          Vpk[4][17][0])+(Vpk[1][17][1]*Vpk[4][17][1]))))+((mk[13]*((
          Vpk[1][16][2]*Vpk[4][16][2])+((Vpk[1][16][0]*Vpk[4][16][0])+(
          Vpk[1][16][1]*Vpk[4][16][1]))))+((mk[12]*((Vpk[1][15][2]*Vpk[4][15][2]
          )+((Vpk[1][15][0]*Vpk[4][15][0])+(Vpk[1][15][1]*Vpk[4][15][1]))))+
          temp[2])));
        temp[4] = ((mk[18]*((Vpk[1][20][2]*Vpk[4][20][2])+((Vpk[1][20][0]*
          Vpk[4][20][0])+(Vpk[1][20][1]*Vpk[4][20][1]))))+((mk[17]*((
          Vpk[1][19][2]*Vpk[4][19][2])+((Vpk[1][19][0]*Vpk[4][19][0])+(
          Vpk[1][19][1]*Vpk[4][19][1]))))+((mk[16]*((Vpk[1][18][2]*Vpk[4][18][2]
          )+((Vpk[1][18][0]*Vpk[4][18][0])+(Vpk[1][18][1]*Vpk[4][18][1]))))+
          temp[3])));
        mm[1][4] = ((psmk[21]*((Vpk[1][21][2]*Vpk[4][21][2])+((Vpk[1][21][0]*
          Vpk[4][21][0])+(Vpk[1][21][1]*Vpk[4][21][1]))))+temp[4]);
        temp[0] = ((mk[3]*((Vpk[1][8][2]*Vpk[5][8][2])+((Vpk[1][8][0]*
          Vpk[5][8][0])+(Vpk[1][8][1]*Vpk[5][8][1]))))+((mk[2]*((Vpk[1][7][2]*
          Vpk[5][7][2])+((Vpk[1][7][0]*Vpk[5][7][0])+(Vpk[1][7][1]*Vpk[5][7][1])
          )))+((mk[0]*((rk[0][1]*Vpk[1][3][0])-(rk[0][0]*Vpk[1][3][1])))+(mk[1]*
          ((Vpk[1][6][2]*Vpk[5][6][2])+((Vpk[1][6][0]*Vpk[5][6][0])+(
          Vpk[1][6][1]*Vpk[5][6][1])))))));
        temp[1] = ((mk[7]*((Vpk[1][11][2]*Vpk[5][11][2])+((Vpk[1][11][0]*
          Vpk[5][11][0])+(Vpk[1][11][1]*Vpk[5][11][1]))))+((mk[6]*((
          Vpk[1][10][2]*Vpk[5][10][2])+((Vpk[1][10][0]*Vpk[5][10][0])+(
          Vpk[1][10][1]*Vpk[5][10][1]))))+((psmk[9]*((Vpk[1][9][2]*Vpk[5][9][2])
          +((Vpk[1][9][0]*Vpk[5][9][0])+(Vpk[1][9][1]*Vpk[5][9][1]))))+temp[0]))
          );
        temp[2] = ((mk[11]*((Vpk[1][14][2]*Vpk[5][14][2])+((Vpk[1][14][0]*
          Vpk[5][14][0])+(Vpk[1][14][1]*Vpk[5][14][1]))))+((psmk[13]*((
          Vpk[1][13][2]*Vpk[5][13][2])+((Vpk[1][13][0]*Vpk[5][13][0])+(
          Vpk[1][13][1]*Vpk[5][13][1]))))+((mk[8]*((Vpk[1][12][2]*Vpk[5][12][2])
          +((Vpk[1][12][0]*Vpk[5][12][0])+(Vpk[1][12][1]*Vpk[5][12][1]))))+
          temp[1])));
        temp[3] = ((psmk[17]*((Vpk[1][17][2]*Vpk[5][17][2])+((Vpk[1][17][0]*
          Vpk[5][17][0])+(Vpk[1][17][1]*Vpk[5][17][1]))))+((mk[13]*((
          Vpk[1][16][2]*Vpk[5][16][2])+((Vpk[1][16][0]*Vpk[5][16][0])+(
          Vpk[1][16][1]*Vpk[5][16][1]))))+((mk[12]*((Vpk[1][15][2]*Vpk[5][15][2]
          )+((Vpk[1][15][0]*Vpk[5][15][0])+(Vpk[1][15][1]*Vpk[5][15][1]))))+
          temp[2])));
        temp[4] = ((mk[18]*((Vpk[1][20][2]*Vpk[5][20][2])+((Vpk[1][20][0]*
          Vpk[5][20][0])+(Vpk[1][20][1]*Vpk[5][20][1]))))+((mk[17]*((
          Vpk[1][19][2]*Vpk[5][19][2])+((Vpk[1][19][0]*Vpk[5][19][0])+(
          Vpk[1][19][1]*Vpk[5][19][1]))))+((mk[16]*((Vpk[1][18][2]*Vpk[5][18][2]
          )+((Vpk[1][18][0]*Vpk[5][18][0])+(Vpk[1][18][1]*Vpk[5][18][1]))))+
          temp[3])));
        mm[1][5] = ((psmk[21]*((Vpk[1][21][2]*Vpk[5][21][2])+((Vpk[1][21][0]*
          Vpk[5][21][0])+(Vpk[1][21][1]*Vpk[5][21][1]))))+temp[4]);
        temp[0] = ((mk[3]*((Vpk[1][8][2]*Vpk[6][8][2])+((Vpk[1][8][0]*
          Vpk[6][8][0])+(Vpk[1][8][1]*Vpk[6][8][1]))))+((mk[1]*((Vpk[1][6][2]*
          Vpk[6][6][2])+((Vpk[1][6][0]*Vpk[6][6][0])+(Vpk[1][6][1]*Vpk[6][6][1])
          )))+(mk[2]*((Vpk[1][7][2]*Vpk[6][7][2])+((Vpk[1][7][0]*Vpk[6][7][0])+(
          Vpk[1][7][1]*Vpk[6][7][1]))))));
        mm[1][6] = ((psmk[9]*((Vpk[1][9][2]*Vpk[6][9][2])+((Vpk[1][9][0]*
          Vpk[6][9][0])+(Vpk[1][9][1]*Vpk[6][9][1]))))+temp[0]);
        mm[1][7] = ((psmk[9]*((Vpk[1][9][2]*Vpk[7][9][2])+((Vpk[1][9][0]*
          Vpk[7][9][0])+(Vpk[1][9][1]*Vpk[7][9][1]))))+((mk[2]*((Vpk[1][7][2]*
          Vpk[7][7][2])+((Vpk[1][7][0]*Vpk[7][7][0])+(Vpk[1][7][1]*Vpk[7][7][1])
          )))+(mk[3]*((Vpk[1][8][2]*Vpk[7][8][2])+((Vpk[1][8][0]*Vpk[7][8][0])+(
          Vpk[1][8][1]*Vpk[7][8][1]))))));
        mm[1][8] = ((mk[3]*((Vpk[1][8][2]*Vpk[8][8][2])+((Vpk[1][8][0]*
          Vpk[8][8][0])+(Vpk[1][8][1]*Vpk[8][8][1]))))+(psmk[9]*((Vpk[1][9][2]*
          Vpk[8][9][2])+((Vpk[1][9][0]*Vpk[8][9][0])+(Vpk[1][9][1]*Vpk[8][9][1])
          ))));
        mm[1][9] = (psmk[9]*((Vpk[1][9][2]*Vpk[9][9][2])+((Vpk[1][9][0]*
          Vpk[9][9][0])+(Vpk[1][9][1]*Vpk[9][9][1]))));
        temp[0] = ((mk[8]*((Vpk[1][12][2]*Vpk[10][12][2])+((Vpk[1][12][0]*
          Vpk[10][12][0])+(Vpk[1][12][1]*Vpk[10][12][1]))))+((mk[6]*((
          Vpk[1][10][2]*Vpk[10][10][2])+((Vpk[1][10][0]*Vpk[10][10][0])+(
          Vpk[1][10][1]*Vpk[10][10][1]))))+(mk[7]*((Vpk[1][11][2]*Vpk[10][11][2]
          )+((Vpk[1][11][0]*Vpk[10][11][0])+(Vpk[1][11][1]*Vpk[10][11][1]))))));
        mm[1][10] = ((psmk[13]*((Vpk[1][13][2]*Vpk[10][13][2])+((Vpk[1][13][0]*
          Vpk[10][13][0])+(Vpk[1][13][1]*Vpk[10][13][1]))))+temp[0]);
        mm[1][11] = ((psmk[13]*((Vpk[1][13][2]*Vpk[11][13][2])+((Vpk[1][13][0]*
          Vpk[11][13][0])+(Vpk[1][13][1]*Vpk[11][13][1]))))+((mk[7]*((
          Vpk[1][11][2]*Vpk[11][11][2])+((Vpk[1][11][0]*Vpk[11][11][0])+(
          Vpk[1][11][1]*Vpk[11][11][1]))))+(mk[8]*((Vpk[1][12][2]*Vpk[11][12][2]
          )+((Vpk[1][12][0]*Vpk[11][12][0])+(Vpk[1][12][1]*Vpk[11][12][1]))))));
        mm[1][12] = ((mk[8]*((Vpk[1][12][2]*Vpk[12][12][2])+((Vpk[1][12][0]*
          Vpk[12][12][0])+(Vpk[1][12][1]*Vpk[12][12][1]))))+(psmk[13]*((
          Vpk[1][13][2]*Vpk[12][13][2])+((Vpk[1][13][0]*Vpk[12][13][0])+(
          Vpk[1][13][1]*Vpk[12][13][1])))));
        mm[1][13] = (psmk[13]*((Vpk[1][13][2]*Vpk[13][13][2])+((Vpk[1][13][0]*
          Vpk[13][13][0])+(Vpk[1][13][1]*Vpk[13][13][1]))));
        temp[0] = ((mk[13]*((Vpk[1][16][2]*Vpk[14][16][2])+((Vpk[1][16][0]*
          Vpk[14][16][0])+(Vpk[1][16][1]*Vpk[14][16][1]))))+((mk[11]*((
          Vpk[1][14][2]*Vpk[14][14][2])+((Vpk[1][14][0]*Vpk[14][14][0])+(
          Vpk[1][14][1]*Vpk[14][14][1]))))+(mk[12]*((Vpk[1][15][2]*
          Vpk[14][15][2])+((Vpk[1][15][0]*Vpk[14][15][0])+(Vpk[1][15][1]*
          Vpk[14][15][1]))))));
        mm[1][14] = ((psmk[17]*((Vpk[1][17][2]*Vpk[14][17][2])+((Vpk[1][17][0]*
          Vpk[14][17][0])+(Vpk[1][17][1]*Vpk[14][17][1]))))+temp[0]);
        mm[1][15] = ((psmk[17]*((Vpk[1][17][2]*Vpk[15][17][2])+((Vpk[1][17][0]*
          Vpk[15][17][0])+(Vpk[1][17][1]*Vpk[15][17][1]))))+((mk[12]*((
          Vpk[1][15][2]*Vpk[15][15][2])+((Vpk[1][15][0]*Vpk[15][15][0])+(
          Vpk[1][15][1]*Vpk[15][15][1]))))+(mk[13]*((Vpk[1][16][2]*
          Vpk[15][16][2])+((Vpk[1][16][0]*Vpk[15][16][0])+(Vpk[1][16][1]*
          Vpk[15][16][1]))))));
        mm[1][16] = ((mk[13]*((Vpk[1][16][2]*Vpk[16][16][2])+((Vpk[1][16][0]*
          Vpk[16][16][0])+(Vpk[1][16][1]*Vpk[16][16][1]))))+(psmk[17]*((
          Vpk[1][17][2]*Vpk[16][17][2])+((Vpk[1][17][0]*Vpk[16][17][0])+(
          Vpk[1][17][1]*Vpk[16][17][1])))));
        mm[1][17] = (psmk[17]*((Vpk[1][17][2]*Vpk[17][17][2])+((Vpk[1][17][0]*
          Vpk[17][17][0])+(Vpk[1][17][1]*Vpk[17][17][1]))));
        temp[0] = ((mk[18]*((Vpk[1][20][2]*Vpk[18][20][2])+((Vpk[1][20][0]*
          Vpk[18][20][0])+(Vpk[1][20][1]*Vpk[18][20][1]))))+((mk[16]*((
          Vpk[1][18][2]*Vpk[18][18][2])+((Vpk[1][18][0]*Vpk[18][18][0])+(
          Vpk[1][18][1]*Vpk[18][18][1]))))+(mk[17]*((Vpk[1][19][2]*
          Vpk[18][19][2])+((Vpk[1][19][0]*Vpk[18][19][0])+(Vpk[1][19][1]*
          Vpk[18][19][1]))))));
        mm[1][18] = ((psmk[21]*((Vpk[1][21][2]*Vpk[18][21][2])+((Vpk[1][21][0]*
          Vpk[18][21][0])+(Vpk[1][21][1]*Vpk[18][21][1]))))+temp[0]);
        mm[1][19] = ((psmk[21]*((Vpk[1][21][2]*Vpk[19][21][2])+((Vpk[1][21][0]*
          Vpk[19][21][0])+(Vpk[1][21][1]*Vpk[19][21][1]))))+((mk[17]*((
          Vpk[1][19][2]*Vpk[19][19][2])+((Vpk[1][19][0]*Vpk[19][19][0])+(
          Vpk[1][19][1]*Vpk[19][19][1]))))+(mk[18]*((Vpk[1][20][2]*
          Vpk[19][20][2])+((Vpk[1][20][0]*Vpk[19][20][0])+(Vpk[1][20][1]*
          Vpk[19][20][1]))))));
        mm[1][20] = ((mk[18]*((Vpk[1][20][2]*Vpk[20][20][2])+((Vpk[1][20][0]*
          Vpk[20][20][0])+(Vpk[1][20][1]*Vpk[20][20][1]))))+(psmk[21]*((
          Vpk[1][21][2]*Vpk[20][21][2])+((Vpk[1][21][0]*Vpk[20][21][0])+(
          Vpk[1][21][1]*Vpk[20][21][1])))));
        mm[1][21] = (psmk[21]*((Vpk[1][21][2]*Vpk[21][21][2])+((Vpk[1][21][0]*
          Vpk[21][21][0])+(Vpk[1][21][1]*Vpk[21][21][1]))));
        temp[0] = ((mk[2]*((Vpk[2][7][2]*Vpk[2][7][2])+((Vpk[2][7][0]*
          Vpk[2][7][0])+(Vpk[2][7][1]*Vpk[2][7][1]))))+((mk[0]*((Vpk[2][3][2]*
          Vpk[2][3][2])+((Vpk[2][3][0]*Vpk[2][3][0])+(Vpk[2][3][1]*Vpk[2][3][1])
          )))+(mk[1]*((Vpk[2][6][2]*Vpk[2][6][2])+((Vpk[2][6][0]*Vpk[2][6][0])+(
          Vpk[2][6][1]*Vpk[2][6][1]))))));
        temp[1] = ((mk[6]*((Vpk[2][10][2]*Vpk[2][10][2])+((Vpk[2][10][0]*
          Vpk[2][10][0])+(Vpk[2][10][1]*Vpk[2][10][1]))))+((psmk[9]*((
          Vpk[2][9][2]*Vpk[2][9][2])+((Vpk[2][9][0]*Vpk[2][9][0])+(Vpk[2][9][1]*
          Vpk[2][9][1]))))+((mk[3]*((Vpk[2][8][2]*Vpk[2][8][2])+((Vpk[2][8][0]*
          Vpk[2][8][0])+(Vpk[2][8][1]*Vpk[2][8][1]))))+temp[0])));
        temp[2] = ((psmk[13]*((Vpk[2][13][2]*Vpk[2][13][2])+((Vpk[2][13][0]*
          Vpk[2][13][0])+(Vpk[2][13][1]*Vpk[2][13][1]))))+((mk[8]*((
          Vpk[2][12][2]*Vpk[2][12][2])+((Vpk[2][12][0]*Vpk[2][12][0])+(
          Vpk[2][12][1]*Vpk[2][12][1]))))+((mk[7]*((Vpk[2][11][2]*Vpk[2][11][2])
          +((Vpk[2][11][0]*Vpk[2][11][0])+(Vpk[2][11][1]*Vpk[2][11][1]))))+
          temp[1])));
        temp[3] = ((mk[13]*((Vpk[2][16][2]*Vpk[2][16][2])+((Vpk[2][16][0]*
          Vpk[2][16][0])+(Vpk[2][16][1]*Vpk[2][16][1]))))+((mk[12]*((
          Vpk[2][15][2]*Vpk[2][15][2])+((Vpk[2][15][0]*Vpk[2][15][0])+(
          Vpk[2][15][1]*Vpk[2][15][1]))))+((mk[11]*((Vpk[2][14][2]*Vpk[2][14][2]
          )+((Vpk[2][14][0]*Vpk[2][14][0])+(Vpk[2][14][1]*Vpk[2][14][1]))))+
          temp[2])));
        temp[4] = ((mk[17]*((Vpk[2][19][2]*Vpk[2][19][2])+((Vpk[2][19][0]*
          Vpk[2][19][0])+(Vpk[2][19][1]*Vpk[2][19][1]))))+((mk[16]*((
          Vpk[2][18][2]*Vpk[2][18][2])+((Vpk[2][18][0]*Vpk[2][18][0])+(
          Vpk[2][18][1]*Vpk[2][18][1]))))+((psmk[17]*((Vpk[2][17][2]*
          Vpk[2][17][2])+((Vpk[2][17][0]*Vpk[2][17][0])+(Vpk[2][17][1]*
          Vpk[2][17][1]))))+temp[3])));
        mm[2][2] = ((psmk[21]*((Vpk[2][21][2]*Vpk[2][21][2])+((Vpk[2][21][0]*
          Vpk[2][21][0])+(Vpk[2][21][1]*Vpk[2][21][1]))))+((mk[18]*((
          Vpk[2][20][2]*Vpk[2][20][2])+((Vpk[2][20][0]*Vpk[2][20][0])+(
          Vpk[2][20][1]*Vpk[2][20][1]))))+temp[4]));
        temp[0] = ((mk[3]*((Vpk[2][8][2]*Vpk[3][8][2])+((Vpk[2][8][0]*
          Vpk[3][8][0])+(Vpk[2][8][1]*Vpk[3][8][1]))))+((mk[2]*((Vpk[2][7][2]*
          Vpk[3][7][2])+((Vpk[2][7][0]*Vpk[3][7][0])+(Vpk[2][7][1]*Vpk[3][7][1])
          )))+((mk[0]*((rk[0][2]*Vpk[2][3][1])-(rk[0][1]*Vpk[2][3][2])))+(mk[1]*
          ((Vpk[2][6][2]*Vpk[3][6][2])+((Vpk[2][6][0]*Vpk[3][6][0])+(
          Vpk[2][6][1]*Vpk[3][6][1])))))));
        temp[1] = ((mk[7]*((Vpk[2][11][2]*Vpk[3][11][2])+((Vpk[2][11][0]*
          Vpk[3][11][0])+(Vpk[2][11][1]*Vpk[3][11][1]))))+((mk[6]*((
          Vpk[2][10][2]*Vpk[3][10][2])+((Vpk[2][10][0]*Vpk[3][10][0])+(
          Vpk[2][10][1]*Vpk[3][10][1]))))+((psmk[9]*((Vpk[2][9][2]*Vpk[3][9][2])
          +((Vpk[2][9][0]*Vpk[3][9][0])+(Vpk[2][9][1]*Vpk[3][9][1]))))+temp[0]))
          );
        temp[2] = ((mk[11]*((Vpk[2][14][2]*Vpk[3][14][2])+((Vpk[2][14][0]*
          Vpk[3][14][0])+(Vpk[2][14][1]*Vpk[3][14][1]))))+((psmk[13]*((
          Vpk[2][13][2]*Vpk[3][13][2])+((Vpk[2][13][0]*Vpk[3][13][0])+(
          Vpk[2][13][1]*Vpk[3][13][1]))))+((mk[8]*((Vpk[2][12][2]*Vpk[3][12][2])
          +((Vpk[2][12][0]*Vpk[3][12][0])+(Vpk[2][12][1]*Vpk[3][12][1]))))+
          temp[1])));
        temp[3] = ((psmk[17]*((Vpk[2][17][2]*Vpk[3][17][2])+((Vpk[2][17][0]*
          Vpk[3][17][0])+(Vpk[2][17][1]*Vpk[3][17][1]))))+((mk[13]*((
          Vpk[2][16][2]*Vpk[3][16][2])+((Vpk[2][16][0]*Vpk[3][16][0])+(
          Vpk[2][16][1]*Vpk[3][16][1]))))+((mk[12]*((Vpk[2][15][2]*Vpk[3][15][2]
          )+((Vpk[2][15][0]*Vpk[3][15][0])+(Vpk[2][15][1]*Vpk[3][15][1]))))+
          temp[2])));
        temp[4] = ((mk[18]*((Vpk[2][20][2]*Vpk[3][20][2])+((Vpk[2][20][0]*
          Vpk[3][20][0])+(Vpk[2][20][1]*Vpk[3][20][1]))))+((mk[17]*((
          Vpk[2][19][2]*Vpk[3][19][2])+((Vpk[2][19][0]*Vpk[3][19][0])+(
          Vpk[2][19][1]*Vpk[3][19][1]))))+((mk[16]*((Vpk[2][18][2]*Vpk[3][18][2]
          )+((Vpk[2][18][0]*Vpk[3][18][0])+(Vpk[2][18][1]*Vpk[3][18][1]))))+
          temp[3])));
        mm[2][3] = ((psmk[21]*((Vpk[2][21][2]*Vpk[3][21][2])+((Vpk[2][21][0]*
          Vpk[3][21][0])+(Vpk[2][21][1]*Vpk[3][21][1]))))+temp[4]);
        temp[0] = ((mk[3]*((Vpk[2][8][2]*Vpk[4][8][2])+((Vpk[2][8][0]*
          Vpk[4][8][0])+(Vpk[2][8][1]*Vpk[4][8][1]))))+((mk[2]*((Vpk[2][7][2]*
          Vpk[4][7][2])+((Vpk[2][7][0]*Vpk[4][7][0])+(Vpk[2][7][1]*Vpk[4][7][1])
          )))+((mk[0]*((rk[0][0]*Vpk[2][3][2])-(rk[0][2]*Vpk[2][3][0])))+(mk[1]*
          ((Vpk[2][6][2]*Vpk[4][6][2])+((Vpk[2][6][0]*Vpk[4][6][0])+(
          Vpk[2][6][1]*Vpk[4][6][1])))))));
        temp[1] = ((mk[7]*((Vpk[2][11][2]*Vpk[4][11][2])+((Vpk[2][11][0]*
          Vpk[4][11][0])+(Vpk[2][11][1]*Vpk[4][11][1]))))+((mk[6]*((
          Vpk[2][10][2]*Vpk[4][10][2])+((Vpk[2][10][0]*Vpk[4][10][0])+(
          Vpk[2][10][1]*Vpk[4][10][1]))))+((psmk[9]*((Vpk[2][9][2]*Vpk[4][9][2])
          +((Vpk[2][9][0]*Vpk[4][9][0])+(Vpk[2][9][1]*Vpk[4][9][1]))))+temp[0]))
          );
        temp[2] = ((mk[11]*((Vpk[2][14][2]*Vpk[4][14][2])+((Vpk[2][14][0]*
          Vpk[4][14][0])+(Vpk[2][14][1]*Vpk[4][14][1]))))+((psmk[13]*((
          Vpk[2][13][2]*Vpk[4][13][2])+((Vpk[2][13][0]*Vpk[4][13][0])+(
          Vpk[2][13][1]*Vpk[4][13][1]))))+((mk[8]*((Vpk[2][12][2]*Vpk[4][12][2])
          +((Vpk[2][12][0]*Vpk[4][12][0])+(Vpk[2][12][1]*Vpk[4][12][1]))))+
          temp[1])));
        temp[3] = ((psmk[17]*((Vpk[2][17][2]*Vpk[4][17][2])+((Vpk[2][17][0]*
          Vpk[4][17][0])+(Vpk[2][17][1]*Vpk[4][17][1]))))+((mk[13]*((
          Vpk[2][16][2]*Vpk[4][16][2])+((Vpk[2][16][0]*Vpk[4][16][0])+(
          Vpk[2][16][1]*Vpk[4][16][1]))))+((mk[12]*((Vpk[2][15][2]*Vpk[4][15][2]
          )+((Vpk[2][15][0]*Vpk[4][15][0])+(Vpk[2][15][1]*Vpk[4][15][1]))))+
          temp[2])));
        temp[4] = ((mk[18]*((Vpk[2][20][2]*Vpk[4][20][2])+((Vpk[2][20][0]*
          Vpk[4][20][0])+(Vpk[2][20][1]*Vpk[4][20][1]))))+((mk[17]*((
          Vpk[2][19][2]*Vpk[4][19][2])+((Vpk[2][19][0]*Vpk[4][19][0])+(
          Vpk[2][19][1]*Vpk[4][19][1]))))+((mk[16]*((Vpk[2][18][2]*Vpk[4][18][2]
          )+((Vpk[2][18][0]*Vpk[4][18][0])+(Vpk[2][18][1]*Vpk[4][18][1]))))+
          temp[3])));
        mm[2][4] = ((psmk[21]*((Vpk[2][21][2]*Vpk[4][21][2])+((Vpk[2][21][0]*
          Vpk[4][21][0])+(Vpk[2][21][1]*Vpk[4][21][1]))))+temp[4]);
        temp[0] = ((mk[3]*((Vpk[2][8][2]*Vpk[5][8][2])+((Vpk[2][8][0]*
          Vpk[5][8][0])+(Vpk[2][8][1]*Vpk[5][8][1]))))+((mk[2]*((Vpk[2][7][2]*
          Vpk[5][7][2])+((Vpk[2][7][0]*Vpk[5][7][0])+(Vpk[2][7][1]*Vpk[5][7][1])
          )))+((mk[0]*((rk[0][1]*Vpk[2][3][0])-(rk[0][0]*Vpk[2][3][1])))+(mk[1]*
          ((Vpk[2][6][2]*Vpk[5][6][2])+((Vpk[2][6][0]*Vpk[5][6][0])+(
          Vpk[2][6][1]*Vpk[5][6][1])))))));
        temp[1] = ((mk[7]*((Vpk[2][11][2]*Vpk[5][11][2])+((Vpk[2][11][0]*
          Vpk[5][11][0])+(Vpk[2][11][1]*Vpk[5][11][1]))))+((mk[6]*((
          Vpk[2][10][2]*Vpk[5][10][2])+((Vpk[2][10][0]*Vpk[5][10][0])+(
          Vpk[2][10][1]*Vpk[5][10][1]))))+((psmk[9]*((Vpk[2][9][2]*Vpk[5][9][2])
          +((Vpk[2][9][0]*Vpk[5][9][0])+(Vpk[2][9][1]*Vpk[5][9][1]))))+temp[0]))
          );
        temp[2] = ((mk[11]*((Vpk[2][14][2]*Vpk[5][14][2])+((Vpk[2][14][0]*
          Vpk[5][14][0])+(Vpk[2][14][1]*Vpk[5][14][1]))))+((psmk[13]*((
          Vpk[2][13][2]*Vpk[5][13][2])+((Vpk[2][13][0]*Vpk[5][13][0])+(
          Vpk[2][13][1]*Vpk[5][13][1]))))+((mk[8]*((Vpk[2][12][2]*Vpk[5][12][2])
          +((Vpk[2][12][0]*Vpk[5][12][0])+(Vpk[2][12][1]*Vpk[5][12][1]))))+
          temp[1])));
        temp[3] = ((psmk[17]*((Vpk[2][17][2]*Vpk[5][17][2])+((Vpk[2][17][0]*
          Vpk[5][17][0])+(Vpk[2][17][1]*Vpk[5][17][1]))))+((mk[13]*((
          Vpk[2][16][2]*Vpk[5][16][2])+((Vpk[2][16][0]*Vpk[5][16][0])+(
          Vpk[2][16][1]*Vpk[5][16][1]))))+((mk[12]*((Vpk[2][15][2]*Vpk[5][15][2]
          )+((Vpk[2][15][0]*Vpk[5][15][0])+(Vpk[2][15][1]*Vpk[5][15][1]))))+
          temp[2])));
        temp[4] = ((mk[18]*((Vpk[2][20][2]*Vpk[5][20][2])+((Vpk[2][20][0]*
          Vpk[5][20][0])+(Vpk[2][20][1]*Vpk[5][20][1]))))+((mk[17]*((
          Vpk[2][19][2]*Vpk[5][19][2])+((Vpk[2][19][0]*Vpk[5][19][0])+(
          Vpk[2][19][1]*Vpk[5][19][1]))))+((mk[16]*((Vpk[2][18][2]*Vpk[5][18][2]
          )+((Vpk[2][18][0]*Vpk[5][18][0])+(Vpk[2][18][1]*Vpk[5][18][1]))))+
          temp[3])));
        mm[2][5] = ((psmk[21]*((Vpk[2][21][2]*Vpk[5][21][2])+((Vpk[2][21][0]*
          Vpk[5][21][0])+(Vpk[2][21][1]*Vpk[5][21][1]))))+temp[4]);
        temp[0] = ((mk[3]*((Vpk[2][8][2]*Vpk[6][8][2])+((Vpk[2][8][0]*
          Vpk[6][8][0])+(Vpk[2][8][1]*Vpk[6][8][1]))))+((mk[1]*((Vpk[2][6][2]*
          Vpk[6][6][2])+((Vpk[2][6][0]*Vpk[6][6][0])+(Vpk[2][6][1]*Vpk[6][6][1])
          )))+(mk[2]*((Vpk[2][7][2]*Vpk[6][7][2])+((Vpk[2][7][0]*Vpk[6][7][0])+(
          Vpk[2][7][1]*Vpk[6][7][1]))))));
        mm[2][6] = ((psmk[9]*((Vpk[2][9][2]*Vpk[6][9][2])+((Vpk[2][9][0]*
          Vpk[6][9][0])+(Vpk[2][9][1]*Vpk[6][9][1]))))+temp[0]);
        mm[2][7] = ((psmk[9]*((Vpk[2][9][2]*Vpk[7][9][2])+((Vpk[2][9][0]*
          Vpk[7][9][0])+(Vpk[2][9][1]*Vpk[7][9][1]))))+((mk[2]*((Vpk[2][7][2]*
          Vpk[7][7][2])+((Vpk[2][7][0]*Vpk[7][7][0])+(Vpk[2][7][1]*Vpk[7][7][1])
          )))+(mk[3]*((Vpk[2][8][2]*Vpk[7][8][2])+((Vpk[2][8][0]*Vpk[7][8][0])+(
          Vpk[2][8][1]*Vpk[7][8][1]))))));
        mm[2][8] = ((mk[3]*((Vpk[2][8][2]*Vpk[8][8][2])+((Vpk[2][8][0]*
          Vpk[8][8][0])+(Vpk[2][8][1]*Vpk[8][8][1]))))+(psmk[9]*((Vpk[2][9][2]*
          Vpk[8][9][2])+((Vpk[2][9][0]*Vpk[8][9][0])+(Vpk[2][9][1]*Vpk[8][9][1])
          ))));
        mm[2][9] = (psmk[9]*((Vpk[2][9][2]*Vpk[9][9][2])+((Vpk[2][9][0]*
          Vpk[9][9][0])+(Vpk[2][9][1]*Vpk[9][9][1]))));
        temp[0] = ((mk[8]*((Vpk[2][12][2]*Vpk[10][12][2])+((Vpk[2][12][0]*
          Vpk[10][12][0])+(Vpk[2][12][1]*Vpk[10][12][1]))))+((mk[6]*((
          Vpk[2][10][2]*Vpk[10][10][2])+((Vpk[2][10][0]*Vpk[10][10][0])+(
          Vpk[2][10][1]*Vpk[10][10][1]))))+(mk[7]*((Vpk[2][11][2]*Vpk[10][11][2]
          )+((Vpk[2][11][0]*Vpk[10][11][0])+(Vpk[2][11][1]*Vpk[10][11][1]))))));
        mm[2][10] = ((psmk[13]*((Vpk[2][13][2]*Vpk[10][13][2])+((Vpk[2][13][0]*
          Vpk[10][13][0])+(Vpk[2][13][1]*Vpk[10][13][1]))))+temp[0]);
        mm[2][11] = ((psmk[13]*((Vpk[2][13][2]*Vpk[11][13][2])+((Vpk[2][13][0]*
          Vpk[11][13][0])+(Vpk[2][13][1]*Vpk[11][13][1]))))+((mk[7]*((
          Vpk[2][11][2]*Vpk[11][11][2])+((Vpk[2][11][0]*Vpk[11][11][0])+(
          Vpk[2][11][1]*Vpk[11][11][1]))))+(mk[8]*((Vpk[2][12][2]*Vpk[11][12][2]
          )+((Vpk[2][12][0]*Vpk[11][12][0])+(Vpk[2][12][1]*Vpk[11][12][1]))))));
        mm[2][12] = ((mk[8]*((Vpk[2][12][2]*Vpk[12][12][2])+((Vpk[2][12][0]*
          Vpk[12][12][0])+(Vpk[2][12][1]*Vpk[12][12][1]))))+(psmk[13]*((
          Vpk[2][13][2]*Vpk[12][13][2])+((Vpk[2][13][0]*Vpk[12][13][0])+(
          Vpk[2][13][1]*Vpk[12][13][1])))));
        mm[2][13] = (psmk[13]*((Vpk[2][13][2]*Vpk[13][13][2])+((Vpk[2][13][0]*
          Vpk[13][13][0])+(Vpk[2][13][1]*Vpk[13][13][1]))));
        temp[0] = ((mk[13]*((Vpk[2][16][2]*Vpk[14][16][2])+((Vpk[2][16][0]*
          Vpk[14][16][0])+(Vpk[2][16][1]*Vpk[14][16][1]))))+((mk[11]*((
          Vpk[2][14][2]*Vpk[14][14][2])+((Vpk[2][14][0]*Vpk[14][14][0])+(
          Vpk[2][14][1]*Vpk[14][14][1]))))+(mk[12]*((Vpk[2][15][2]*
          Vpk[14][15][2])+((Vpk[2][15][0]*Vpk[14][15][0])+(Vpk[2][15][1]*
          Vpk[14][15][1]))))));
        mm[2][14] = ((psmk[17]*((Vpk[2][17][2]*Vpk[14][17][2])+((Vpk[2][17][0]*
          Vpk[14][17][0])+(Vpk[2][17][1]*Vpk[14][17][1]))))+temp[0]);
        mm[2][15] = ((psmk[17]*((Vpk[2][17][2]*Vpk[15][17][2])+((Vpk[2][17][0]*
          Vpk[15][17][0])+(Vpk[2][17][1]*Vpk[15][17][1]))))+((mk[12]*((
          Vpk[2][15][2]*Vpk[15][15][2])+((Vpk[2][15][0]*Vpk[15][15][0])+(
          Vpk[2][15][1]*Vpk[15][15][1]))))+(mk[13]*((Vpk[2][16][2]*
          Vpk[15][16][2])+((Vpk[2][16][0]*Vpk[15][16][0])+(Vpk[2][16][1]*
          Vpk[15][16][1]))))));
        mm[2][16] = ((mk[13]*((Vpk[2][16][2]*Vpk[16][16][2])+((Vpk[2][16][0]*
          Vpk[16][16][0])+(Vpk[2][16][1]*Vpk[16][16][1]))))+(psmk[17]*((
          Vpk[2][17][2]*Vpk[16][17][2])+((Vpk[2][17][0]*Vpk[16][17][0])+(
          Vpk[2][17][1]*Vpk[16][17][1])))));
        mm[2][17] = (psmk[17]*((Vpk[2][17][2]*Vpk[17][17][2])+((Vpk[2][17][0]*
          Vpk[17][17][0])+(Vpk[2][17][1]*Vpk[17][17][1]))));
        temp[0] = ((mk[18]*((Vpk[2][20][2]*Vpk[18][20][2])+((Vpk[2][20][0]*
          Vpk[18][20][0])+(Vpk[2][20][1]*Vpk[18][20][1]))))+((mk[16]*((
          Vpk[2][18][2]*Vpk[18][18][2])+((Vpk[2][18][0]*Vpk[18][18][0])+(
          Vpk[2][18][1]*Vpk[18][18][1]))))+(mk[17]*((Vpk[2][19][2]*
          Vpk[18][19][2])+((Vpk[2][19][0]*Vpk[18][19][0])+(Vpk[2][19][1]*
          Vpk[18][19][1]))))));
        mm[2][18] = ((psmk[21]*((Vpk[2][21][2]*Vpk[18][21][2])+((Vpk[2][21][0]*
          Vpk[18][21][0])+(Vpk[2][21][1]*Vpk[18][21][1]))))+temp[0]);
        mm[2][19] = ((psmk[21]*((Vpk[2][21][2]*Vpk[19][21][2])+((Vpk[2][21][0]*
          Vpk[19][21][0])+(Vpk[2][21][1]*Vpk[19][21][1]))))+((mk[17]*((
          Vpk[2][19][2]*Vpk[19][19][2])+((Vpk[2][19][0]*Vpk[19][19][0])+(
          Vpk[2][19][1]*Vpk[19][19][1]))))+(mk[18]*((Vpk[2][20][2]*
          Vpk[19][20][2])+((Vpk[2][20][0]*Vpk[19][20][0])+(Vpk[2][20][1]*
          Vpk[19][20][1]))))));
        mm[2][20] = ((mk[18]*((Vpk[2][20][2]*Vpk[20][20][2])+((Vpk[2][20][0]*
          Vpk[20][20][0])+(Vpk[2][20][1]*Vpk[20][20][1]))))+(psmk[21]*((
          Vpk[2][21][2]*Vpk[20][21][2])+((Vpk[2][21][0]*Vpk[20][21][0])+(
          Vpk[2][21][1]*Vpk[20][21][1])))));
        mm[2][21] = (psmk[21]*((Vpk[2][21][2]*Vpk[21][21][2])+((Vpk[2][21][0]*
          Vpk[21][21][0])+(Vpk[2][21][1]*Vpk[21][21][1]))));
        temp[0] = ((ik[0][0][0]+(mk[0]*((rk[0][1]*rk[0][1])+(rk[0][2]*rk[0][2]))
          ))+((mk[1]*((Vpk[3][6][2]*Vpk[3][6][2])+((Vpk[3][6][0]*Vpk[3][6][0])+(
          Vpk[3][6][1]*Vpk[3][6][1]))))+((Cik[6][0][2]*IkWpk[3][6][2])+((
          Cik[6][0][0]*IkWpk[3][6][0])+(Cik[6][0][1]*IkWpk[3][6][1])))));
        temp[1] = (temp[0]+((mk[2]*((Vpk[3][7][2]*Vpk[3][7][2])+((Vpk[3][7][0]*
          Vpk[3][7][0])+(Vpk[3][7][1]*Vpk[3][7][1]))))+((IkWpk[3][7][2]*
          Wpk[3][7][2])+((IkWpk[3][7][0]*Wpk[3][7][0])+(IkWpk[3][7][1]*
          Wpk[3][7][1])))));
        temp[2] = (((mk[3]*((Vpk[3][8][2]*Vpk[3][8][2])+((Vpk[3][8][0]*
          Vpk[3][8][0])+(Vpk[3][8][1]*Vpk[3][8][1]))))+((IkWpk[3][8][2]*
          Wpk[3][8][2])+((IkWpk[3][8][0]*Wpk[3][8][0])+(IkWpk[3][8][1]*
          Wpk[3][8][1]))))+temp[1]);
        temp[3] = (((psmk[9]*((Vpk[3][9][2]*Vpk[3][9][2])+((Vpk[3][9][0]*
          Vpk[3][9][0])+(Vpk[3][9][1]*Vpk[3][9][1]))))+((IkWpk[3][9][2]*
          Wpk[3][9][2])+((IkWpk[3][9][0]*Wpk[3][9][0])+(IkWpk[3][9][1]*
          Wpk[3][9][1]))))+temp[2]);
        temp[4] = (((mk[6]*((Vpk[3][10][2]*Vpk[3][10][2])+((Vpk[3][10][0]*
          Vpk[3][10][0])+(Vpk[3][10][1]*Vpk[3][10][1]))))+((Cik[10][0][2]*
          IkWpk[3][10][2])+((Cik[10][0][0]*IkWpk[3][10][0])+(Cik[10][0][1]*
          IkWpk[3][10][1]))))+temp[3]);
        temp[5] = (((mk[7]*((Vpk[3][11][2]*Vpk[3][11][2])+((Vpk[3][11][0]*
          Vpk[3][11][0])+(Vpk[3][11][1]*Vpk[3][11][1]))))+((IkWpk[3][11][2]*
          Wpk[3][11][2])+((IkWpk[3][11][0]*Wpk[3][11][0])+(IkWpk[3][11][1]*
          Wpk[3][11][1]))))+temp[4]);
        temp[6] = (((mk[8]*((Vpk[3][12][2]*Vpk[3][12][2])+((Vpk[3][12][0]*
          Vpk[3][12][0])+(Vpk[3][12][1]*Vpk[3][12][1]))))+((IkWpk[3][12][2]*
          Wpk[3][12][2])+((IkWpk[3][12][0]*Wpk[3][12][0])+(IkWpk[3][12][1]*
          Wpk[3][12][1]))))+temp[5]);
        temp[7] = (((psmk[13]*((Vpk[3][13][2]*Vpk[3][13][2])+((Vpk[3][13][0]*
          Vpk[3][13][0])+(Vpk[3][13][1]*Vpk[3][13][1]))))+((IkWpk[3][13][2]*
          Wpk[3][13][2])+((IkWpk[3][13][0]*Wpk[3][13][0])+(IkWpk[3][13][1]*
          Wpk[3][13][1]))))+temp[6]);
        temp[8] = (((mk[11]*((Vpk[3][14][2]*Vpk[3][14][2])+((Vpk[3][14][0]*
          Vpk[3][14][0])+(Vpk[3][14][1]*Vpk[3][14][1]))))+((Cik[14][0][2]*
          IkWpk[3][14][2])+((Cik[14][0][0]*IkWpk[3][14][0])+(Cik[14][0][1]*
          IkWpk[3][14][1]))))+temp[7]);
        temp[9] = (((mk[12]*((Vpk[3][15][2]*Vpk[3][15][2])+((Vpk[3][15][0]*
          Vpk[3][15][0])+(Vpk[3][15][1]*Vpk[3][15][1]))))+((IkWpk[3][15][2]*
          Wpk[3][15][2])+((IkWpk[3][15][0]*Wpk[3][15][0])+(IkWpk[3][15][1]*
          Wpk[3][15][1]))))+temp[8]);
        temp[10] = (((mk[13]*((Vpk[3][16][2]*Vpk[3][16][2])+((Vpk[3][16][0]*
          Vpk[3][16][0])+(Vpk[3][16][1]*Vpk[3][16][1]))))+((IkWpk[3][16][2]*
          Wpk[3][16][2])+((IkWpk[3][16][0]*Wpk[3][16][0])+(IkWpk[3][16][1]*
          Wpk[3][16][1]))))+temp[9]);
        temp[11] = (((psmk[17]*((Vpk[3][17][2]*Vpk[3][17][2])+((Vpk[3][17][0]*
          Vpk[3][17][0])+(Vpk[3][17][1]*Vpk[3][17][1]))))+((IkWpk[3][17][2]*
          Wpk[3][17][2])+((IkWpk[3][17][0]*Wpk[3][17][0])+(IkWpk[3][17][1]*
          Wpk[3][17][1]))))+temp[10]);
        temp[12] = (((mk[16]*((Vpk[3][18][2]*Vpk[3][18][2])+((Vpk[3][18][0]*
          Vpk[3][18][0])+(Vpk[3][18][1]*Vpk[3][18][1]))))+((Cik[18][0][2]*
          IkWpk[3][18][2])+((Cik[18][0][0]*IkWpk[3][18][0])+(Cik[18][0][1]*
          IkWpk[3][18][1]))))+temp[11]);
        temp[13] = (((mk[17]*((Vpk[3][19][2]*Vpk[3][19][2])+((Vpk[3][19][0]*
          Vpk[3][19][0])+(Vpk[3][19][1]*Vpk[3][19][1]))))+((IkWpk[3][19][2]*
          Wpk[3][19][2])+((IkWpk[3][19][0]*Wpk[3][19][0])+(IkWpk[3][19][1]*
          Wpk[3][19][1]))))+temp[12]);
        temp[14] = (((mk[18]*((Vpk[3][20][2]*Vpk[3][20][2])+((Vpk[3][20][0]*
          Vpk[3][20][0])+(Vpk[3][20][1]*Vpk[3][20][1]))))+((IkWpk[3][20][2]*
          Wpk[3][20][2])+((IkWpk[3][20][0]*Wpk[3][20][0])+(IkWpk[3][20][1]*
          Wpk[3][20][1]))))+temp[13]);
        mm[3][3] = (((psmk[21]*((Vpk[3][21][2]*Vpk[3][21][2])+((Vpk[3][21][0]*
          Vpk[3][21][0])+(Vpk[3][21][1]*Vpk[3][21][1]))))+((IkWpk[3][21][2]*
          Wpk[3][21][2])+((IkWpk[3][21][0]*Wpk[3][21][0])+(IkWpk[3][21][1]*
          Wpk[3][21][1]))))+temp[14]);
        temp[0] = ((ik[0][0][1]-(mk[0]*(rk[0][0]*rk[0][1])))+((mk[1]*((
          Vpk[3][6][2]*Vpk[4][6][2])+((Vpk[3][6][0]*Vpk[4][6][0])+(Vpk[3][6][1]*
          Vpk[4][6][1]))))+((Cik[6][0][2]*IkWpk[4][6][2])+((Cik[6][0][0]*
          IkWpk[4][6][0])+(Cik[6][0][1]*IkWpk[4][6][1])))));
        temp[1] = (temp[0]+((mk[2]*((Vpk[3][7][2]*Vpk[4][7][2])+((Vpk[3][7][0]*
          Vpk[4][7][0])+(Vpk[3][7][1]*Vpk[4][7][1]))))+((IkWpk[4][7][2]*
          Wpk[3][7][2])+((IkWpk[4][7][0]*Wpk[3][7][0])+(IkWpk[4][7][1]*
          Wpk[3][7][1])))));
        temp[2] = (((mk[3]*((Vpk[3][8][2]*Vpk[4][8][2])+((Vpk[3][8][0]*
          Vpk[4][8][0])+(Vpk[3][8][1]*Vpk[4][8][1]))))+((IkWpk[4][8][2]*
          Wpk[3][8][2])+((IkWpk[4][8][0]*Wpk[3][8][0])+(IkWpk[4][8][1]*
          Wpk[3][8][1]))))+temp[1]);
        temp[3] = (((psmk[9]*((Vpk[3][9][2]*Vpk[4][9][2])+((Vpk[3][9][0]*
          Vpk[4][9][0])+(Vpk[3][9][1]*Vpk[4][9][1]))))+((IkWpk[4][9][2]*
          Wpk[3][9][2])+((IkWpk[4][9][0]*Wpk[3][9][0])+(IkWpk[4][9][1]*
          Wpk[3][9][1]))))+temp[2]);
        temp[4] = (((mk[6]*((Vpk[3][10][2]*Vpk[4][10][2])+((Vpk[3][10][0]*
          Vpk[4][10][0])+(Vpk[3][10][1]*Vpk[4][10][1]))))+((Cik[10][0][2]*
          IkWpk[4][10][2])+((Cik[10][0][0]*IkWpk[4][10][0])+(Cik[10][0][1]*
          IkWpk[4][10][1]))))+temp[3]);
        temp[5] = (((mk[7]*((Vpk[3][11][2]*Vpk[4][11][2])+((Vpk[3][11][0]*
          Vpk[4][11][0])+(Vpk[3][11][1]*Vpk[4][11][1]))))+((IkWpk[4][11][2]*
          Wpk[3][11][2])+((IkWpk[4][11][0]*Wpk[3][11][0])+(IkWpk[4][11][1]*
          Wpk[3][11][1]))))+temp[4]);
        temp[6] = (((mk[8]*((Vpk[3][12][2]*Vpk[4][12][2])+((Vpk[3][12][0]*
          Vpk[4][12][0])+(Vpk[3][12][1]*Vpk[4][12][1]))))+((IkWpk[4][12][2]*
          Wpk[3][12][2])+((IkWpk[4][12][0]*Wpk[3][12][0])+(IkWpk[4][12][1]*
          Wpk[3][12][1]))))+temp[5]);
        temp[7] = (((psmk[13]*((Vpk[3][13][2]*Vpk[4][13][2])+((Vpk[3][13][0]*
          Vpk[4][13][0])+(Vpk[3][13][1]*Vpk[4][13][1]))))+((IkWpk[4][13][2]*
          Wpk[3][13][2])+((IkWpk[4][13][0]*Wpk[3][13][0])+(IkWpk[4][13][1]*
          Wpk[3][13][1]))))+temp[6]);
        temp[8] = (((mk[11]*((Vpk[3][14][2]*Vpk[4][14][2])+((Vpk[3][14][0]*
          Vpk[4][14][0])+(Vpk[3][14][1]*Vpk[4][14][1]))))+((Cik[14][0][2]*
          IkWpk[4][14][2])+((Cik[14][0][0]*IkWpk[4][14][0])+(Cik[14][0][1]*
          IkWpk[4][14][1]))))+temp[7]);
        temp[9] = (((mk[12]*((Vpk[3][15][2]*Vpk[4][15][2])+((Vpk[3][15][0]*
          Vpk[4][15][0])+(Vpk[3][15][1]*Vpk[4][15][1]))))+((IkWpk[4][15][2]*
          Wpk[3][15][2])+((IkWpk[4][15][0]*Wpk[3][15][0])+(IkWpk[4][15][1]*
          Wpk[3][15][1]))))+temp[8]);
        temp[10] = (((mk[13]*((Vpk[3][16][2]*Vpk[4][16][2])+((Vpk[3][16][0]*
          Vpk[4][16][0])+(Vpk[3][16][1]*Vpk[4][16][1]))))+((IkWpk[4][16][2]*
          Wpk[3][16][2])+((IkWpk[4][16][0]*Wpk[3][16][0])+(IkWpk[4][16][1]*
          Wpk[3][16][1]))))+temp[9]);
        temp[11] = (((psmk[17]*((Vpk[3][17][2]*Vpk[4][17][2])+((Vpk[3][17][0]*
          Vpk[4][17][0])+(Vpk[3][17][1]*Vpk[4][17][1]))))+((IkWpk[4][17][2]*
          Wpk[3][17][2])+((IkWpk[4][17][0]*Wpk[3][17][0])+(IkWpk[4][17][1]*
          Wpk[3][17][1]))))+temp[10]);
        temp[12] = (((mk[16]*((Vpk[3][18][2]*Vpk[4][18][2])+((Vpk[3][18][0]*
          Vpk[4][18][0])+(Vpk[3][18][1]*Vpk[4][18][1]))))+((Cik[18][0][2]*
          IkWpk[4][18][2])+((Cik[18][0][0]*IkWpk[4][18][0])+(Cik[18][0][1]*
          IkWpk[4][18][1]))))+temp[11]);
        temp[13] = (((mk[17]*((Vpk[3][19][2]*Vpk[4][19][2])+((Vpk[3][19][0]*
          Vpk[4][19][0])+(Vpk[3][19][1]*Vpk[4][19][1]))))+((IkWpk[4][19][2]*
          Wpk[3][19][2])+((IkWpk[4][19][0]*Wpk[3][19][0])+(IkWpk[4][19][1]*
          Wpk[3][19][1]))))+temp[12]);
        temp[14] = (((mk[18]*((Vpk[3][20][2]*Vpk[4][20][2])+((Vpk[3][20][0]*
          Vpk[4][20][0])+(Vpk[3][20][1]*Vpk[4][20][1]))))+((IkWpk[4][20][2]*
          Wpk[3][20][2])+((IkWpk[4][20][0]*Wpk[3][20][0])+(IkWpk[4][20][1]*
          Wpk[3][20][1]))))+temp[13]);
        mm[3][4] = (((psmk[21]*((Vpk[3][21][2]*Vpk[4][21][2])+((Vpk[3][21][0]*
          Vpk[4][21][0])+(Vpk[3][21][1]*Vpk[4][21][1]))))+((IkWpk[4][21][2]*
          Wpk[3][21][2])+((IkWpk[4][21][0]*Wpk[3][21][0])+(IkWpk[4][21][1]*
          Wpk[3][21][1]))))+temp[14]);
        temp[0] = ((ik[0][0][2]-(mk[0]*(rk[0][0]*rk[0][2])))+((mk[1]*((
          Vpk[3][6][2]*Vpk[5][6][2])+((Vpk[3][6][0]*Vpk[5][6][0])+(Vpk[3][6][1]*
          Vpk[5][6][1]))))+((Cik[6][0][2]*IkWpk[5][6][2])+((Cik[6][0][0]*
          IkWpk[5][6][0])+(Cik[6][0][1]*IkWpk[5][6][1])))));
        temp[1] = (temp[0]+((mk[2]*((Vpk[3][7][2]*Vpk[5][7][2])+((Vpk[3][7][0]*
          Vpk[5][7][0])+(Vpk[3][7][1]*Vpk[5][7][1]))))+((IkWpk[5][7][2]*
          Wpk[3][7][2])+((IkWpk[5][7][0]*Wpk[3][7][0])+(IkWpk[5][7][1]*
          Wpk[3][7][1])))));
        temp[2] = (((mk[3]*((Vpk[3][8][2]*Vpk[5][8][2])+((Vpk[3][8][0]*
          Vpk[5][8][0])+(Vpk[3][8][1]*Vpk[5][8][1]))))+((IkWpk[5][8][2]*
          Wpk[3][8][2])+((IkWpk[5][8][0]*Wpk[3][8][0])+(IkWpk[5][8][1]*
          Wpk[3][8][1]))))+temp[1]);
        temp[3] = (((psmk[9]*((Vpk[3][9][2]*Vpk[5][9][2])+((Vpk[3][9][0]*
          Vpk[5][9][0])+(Vpk[3][9][1]*Vpk[5][9][1]))))+((IkWpk[5][9][2]*
          Wpk[3][9][2])+((IkWpk[5][9][0]*Wpk[3][9][0])+(IkWpk[5][9][1]*
          Wpk[3][9][1]))))+temp[2]);
        temp[4] = (((mk[6]*((Vpk[3][10][2]*Vpk[5][10][2])+((Vpk[3][10][0]*
          Vpk[5][10][0])+(Vpk[3][10][1]*Vpk[5][10][1]))))+((Cik[10][0][2]*
          IkWpk[5][10][2])+((Cik[10][0][0]*IkWpk[5][10][0])+(Cik[10][0][1]*
          IkWpk[5][10][1]))))+temp[3]);
        temp[5] = (((mk[7]*((Vpk[3][11][2]*Vpk[5][11][2])+((Vpk[3][11][0]*
          Vpk[5][11][0])+(Vpk[3][11][1]*Vpk[5][11][1]))))+((IkWpk[5][11][2]*
          Wpk[3][11][2])+((IkWpk[5][11][0]*Wpk[3][11][0])+(IkWpk[5][11][1]*
          Wpk[3][11][1]))))+temp[4]);
        temp[6] = (((mk[8]*((Vpk[3][12][2]*Vpk[5][12][2])+((Vpk[3][12][0]*
          Vpk[5][12][0])+(Vpk[3][12][1]*Vpk[5][12][1]))))+((IkWpk[5][12][2]*
          Wpk[3][12][2])+((IkWpk[5][12][0]*Wpk[3][12][0])+(IkWpk[5][12][1]*
          Wpk[3][12][1]))))+temp[5]);
        temp[7] = (((psmk[13]*((Vpk[3][13][2]*Vpk[5][13][2])+((Vpk[3][13][0]*
          Vpk[5][13][0])+(Vpk[3][13][1]*Vpk[5][13][1]))))+((IkWpk[5][13][2]*
          Wpk[3][13][2])+((IkWpk[5][13][0]*Wpk[3][13][0])+(IkWpk[5][13][1]*
          Wpk[3][13][1]))))+temp[6]);
        temp[8] = (((mk[11]*((Vpk[3][14][2]*Vpk[5][14][2])+((Vpk[3][14][0]*
          Vpk[5][14][0])+(Vpk[3][14][1]*Vpk[5][14][1]))))+((Cik[14][0][2]*
          IkWpk[5][14][2])+((Cik[14][0][0]*IkWpk[5][14][0])+(Cik[14][0][1]*
          IkWpk[5][14][1]))))+temp[7]);
        temp[9] = (((mk[12]*((Vpk[3][15][2]*Vpk[5][15][2])+((Vpk[3][15][0]*
          Vpk[5][15][0])+(Vpk[3][15][1]*Vpk[5][15][1]))))+((IkWpk[5][15][2]*
          Wpk[3][15][2])+((IkWpk[5][15][0]*Wpk[3][15][0])+(IkWpk[5][15][1]*
          Wpk[3][15][1]))))+temp[8]);
        temp[10] = (((mk[13]*((Vpk[3][16][2]*Vpk[5][16][2])+((Vpk[3][16][0]*
          Vpk[5][16][0])+(Vpk[3][16][1]*Vpk[5][16][1]))))+((IkWpk[5][16][2]*
          Wpk[3][16][2])+((IkWpk[5][16][0]*Wpk[3][16][0])+(IkWpk[5][16][1]*
          Wpk[3][16][1]))))+temp[9]);
        temp[11] = (((psmk[17]*((Vpk[3][17][2]*Vpk[5][17][2])+((Vpk[3][17][0]*
          Vpk[5][17][0])+(Vpk[3][17][1]*Vpk[5][17][1]))))+((IkWpk[5][17][2]*
          Wpk[3][17][2])+((IkWpk[5][17][0]*Wpk[3][17][0])+(IkWpk[5][17][1]*
          Wpk[3][17][1]))))+temp[10]);
        temp[12] = (((mk[16]*((Vpk[3][18][2]*Vpk[5][18][2])+((Vpk[3][18][0]*
          Vpk[5][18][0])+(Vpk[3][18][1]*Vpk[5][18][1]))))+((Cik[18][0][2]*
          IkWpk[5][18][2])+((Cik[18][0][0]*IkWpk[5][18][0])+(Cik[18][0][1]*
          IkWpk[5][18][1]))))+temp[11]);
        temp[13] = (((mk[17]*((Vpk[3][19][2]*Vpk[5][19][2])+((Vpk[3][19][0]*
          Vpk[5][19][0])+(Vpk[3][19][1]*Vpk[5][19][1]))))+((IkWpk[5][19][2]*
          Wpk[3][19][2])+((IkWpk[5][19][0]*Wpk[3][19][0])+(IkWpk[5][19][1]*
          Wpk[3][19][1]))))+temp[12]);
        temp[14] = (((mk[18]*((Vpk[3][20][2]*Vpk[5][20][2])+((Vpk[3][20][0]*
          Vpk[5][20][0])+(Vpk[3][20][1]*Vpk[5][20][1]))))+((IkWpk[5][20][2]*
          Wpk[3][20][2])+((IkWpk[5][20][0]*Wpk[3][20][0])+(IkWpk[5][20][1]*
          Wpk[3][20][1]))))+temp[13]);
        mm[3][5] = (((psmk[21]*((Vpk[3][21][2]*Vpk[5][21][2])+((Vpk[3][21][0]*
          Vpk[5][21][0])+(Vpk[3][21][1]*Vpk[5][21][1]))))+((IkWpk[5][21][2]*
          Wpk[3][21][2])+((IkWpk[5][21][0]*Wpk[3][21][0])+(IkWpk[5][21][1]*
          Wpk[3][21][1]))))+temp[14]);
        temp[0] = (((mk[1]*((Vpk[3][6][2]*Vpk[6][6][2])+((Vpk[3][6][0]*
          Vpk[6][6][0])+(Vpk[3][6][1]*Vpk[6][6][1]))))+((Cik[6][0][2]*
          IkWpk[6][6][2])+((Cik[6][0][0]*IkWpk[6][6][0])+(Cik[6][0][1]*
          IkWpk[6][6][1]))))+((mk[2]*((Vpk[3][7][2]*Vpk[6][7][2])+((Vpk[3][7][0]
          *Vpk[6][7][0])+(Vpk[3][7][1]*Vpk[6][7][1]))))+((IkWpk[6][7][2]*
          Wpk[3][7][2])+((IkWpk[6][7][0]*Wpk[3][7][0])+(IkWpk[6][7][1]*
          Wpk[3][7][1])))));
        temp[1] = (((mk[3]*((Vpk[3][8][2]*Vpk[6][8][2])+((Vpk[3][8][0]*
          Vpk[6][8][0])+(Vpk[3][8][1]*Vpk[6][8][1]))))+((IkWpk[6][8][2]*
          Wpk[3][8][2])+((IkWpk[6][8][0]*Wpk[3][8][0])+(IkWpk[6][8][1]*
          Wpk[3][8][1]))))+temp[0]);
        mm[3][6] = (((psmk[9]*((Vpk[3][9][2]*Vpk[6][9][2])+((Vpk[3][9][0]*
          Vpk[6][9][0])+(Vpk[3][9][1]*Vpk[6][9][1]))))+((IkWpk[6][9][2]*
          Wpk[3][9][2])+((IkWpk[6][9][0]*Wpk[3][9][0])+(IkWpk[6][9][1]*
          Wpk[3][9][1]))))+temp[1]);
        temp[0] = (((mk[2]*((Vpk[3][7][2]*Vpk[7][7][2])+((Vpk[3][7][0]*
          Vpk[7][7][0])+(Vpk[3][7][1]*Vpk[7][7][1]))))+((IkWpk[7][7][2]*
          Wpk[3][7][2])+((IkWpk[7][7][0]*Wpk[3][7][0])+(IkWpk[7][7][1]*
          Wpk[3][7][1]))))+((mk[3]*((Vpk[3][8][2]*Vpk[7][8][2])+((Vpk[3][8][0]*
          Vpk[7][8][0])+(Vpk[3][8][1]*Vpk[7][8][1]))))+((IkWpk[7][8][2]*
          Wpk[3][8][2])+((IkWpk[7][8][0]*Wpk[3][8][0])+(IkWpk[7][8][1]*
          Wpk[3][8][1])))));
        mm[3][7] = (((psmk[9]*((Vpk[3][9][2]*Vpk[7][9][2])+((Vpk[3][9][0]*
          Vpk[7][9][0])+(Vpk[3][9][1]*Vpk[7][9][1]))))+((IkWpk[7][9][2]*
          Wpk[3][9][2])+((IkWpk[7][9][0]*Wpk[3][9][0])+(IkWpk[7][9][1]*
          Wpk[3][9][1]))))+temp[0]);
        mm[3][8] = (((mk[3]*((Vpk[3][8][2]*Vpk[8][8][2])+((Vpk[3][8][0]*
          Vpk[8][8][0])+(Vpk[3][8][1]*Vpk[8][8][1]))))+((IkWpk[8][8][2]*
          Wpk[3][8][2])+((IkWpk[8][8][0]*Wpk[3][8][0])+(IkWpk[8][8][1]*
          Wpk[3][8][1]))))+((psmk[9]*((Vpk[3][9][2]*Vpk[8][9][2])+((Vpk[3][9][0]
          *Vpk[8][9][0])+(Vpk[3][9][1]*Vpk[8][9][1]))))+((IkWpk[8][9][2]*
          Wpk[3][9][2])+((IkWpk[8][9][0]*Wpk[3][9][0])+(IkWpk[8][9][1]*
          Wpk[3][9][1])))));
        mm[3][9] = ((psmk[9]*((Vpk[3][9][2]*Vpk[9][9][2])+((Vpk[3][9][0]*
          Vpk[9][9][0])+(Vpk[3][9][1]*Vpk[9][9][1]))))+((IkWpk[9][9][2]*
          Wpk[3][9][2])+((IkWpk[9][9][0]*Wpk[3][9][0])+(IkWpk[9][9][1]*
          Wpk[3][9][1]))));
        temp[0] = (((mk[6]*((Vpk[3][10][2]*Vpk[10][10][2])+((Vpk[3][10][0]*
          Vpk[10][10][0])+(Vpk[3][10][1]*Vpk[10][10][1]))))+((Cik[10][0][2]*
          IkWpk[10][10][2])+((Cik[10][0][0]*IkWpk[10][10][0])+(Cik[10][0][1]*
          IkWpk[10][10][1]))))+((mk[7]*((Vpk[3][11][2]*Vpk[10][11][2])+((
          Vpk[3][11][0]*Vpk[10][11][0])+(Vpk[3][11][1]*Vpk[10][11][1]))))+((
          IkWpk[10][11][2]*Wpk[3][11][2])+((IkWpk[10][11][0]*Wpk[3][11][0])+(
          IkWpk[10][11][1]*Wpk[3][11][1])))));
        temp[1] = (((mk[8]*((Vpk[3][12][2]*Vpk[10][12][2])+((Vpk[3][12][0]*
          Vpk[10][12][0])+(Vpk[3][12][1]*Vpk[10][12][1]))))+((IkWpk[10][12][2]*
          Wpk[3][12][2])+((IkWpk[10][12][0]*Wpk[3][12][0])+(IkWpk[10][12][1]*
          Wpk[3][12][1]))))+temp[0]);
        mm[3][10] = (((psmk[13]*((Vpk[3][13][2]*Vpk[10][13][2])+((Vpk[3][13][0]*
          Vpk[10][13][0])+(Vpk[3][13][1]*Vpk[10][13][1]))))+((IkWpk[10][13][2]*
          Wpk[3][13][2])+((IkWpk[10][13][0]*Wpk[3][13][0])+(IkWpk[10][13][1]*
          Wpk[3][13][1]))))+temp[1]);
        temp[0] = (((mk[7]*((Vpk[3][11][2]*Vpk[11][11][2])+((Vpk[3][11][0]*
          Vpk[11][11][0])+(Vpk[3][11][1]*Vpk[11][11][1]))))+((IkWpk[11][11][2]*
          Wpk[3][11][2])+((IkWpk[11][11][0]*Wpk[3][11][0])+(IkWpk[11][11][1]*
          Wpk[3][11][1]))))+((mk[8]*((Vpk[3][12][2]*Vpk[11][12][2])+((
          Vpk[3][12][0]*Vpk[11][12][0])+(Vpk[3][12][1]*Vpk[11][12][1]))))+((
          IkWpk[11][12][2]*Wpk[3][12][2])+((IkWpk[11][12][0]*Wpk[3][12][0])+(
          IkWpk[11][12][1]*Wpk[3][12][1])))));
        mm[3][11] = (((psmk[13]*((Vpk[3][13][2]*Vpk[11][13][2])+((Vpk[3][13][0]*
          Vpk[11][13][0])+(Vpk[3][13][1]*Vpk[11][13][1]))))+((IkWpk[11][13][2]*
          Wpk[3][13][2])+((IkWpk[11][13][0]*Wpk[3][13][0])+(IkWpk[11][13][1]*
          Wpk[3][13][1]))))+temp[0]);
        mm[3][12] = (((mk[8]*((Vpk[3][12][2]*Vpk[12][12][2])+((Vpk[3][12][0]*
          Vpk[12][12][0])+(Vpk[3][12][1]*Vpk[12][12][1]))))+((IkWpk[12][12][2]*
          Wpk[3][12][2])+((IkWpk[12][12][0]*Wpk[3][12][0])+(IkWpk[12][12][1]*
          Wpk[3][12][1]))))+((psmk[13]*((Vpk[3][13][2]*Vpk[12][13][2])+((
          Vpk[3][13][0]*Vpk[12][13][0])+(Vpk[3][13][1]*Vpk[12][13][1]))))+((
          IkWpk[12][13][2]*Wpk[3][13][2])+((IkWpk[12][13][0]*Wpk[3][13][0])+(
          IkWpk[12][13][1]*Wpk[3][13][1])))));
        mm[3][13] = ((psmk[13]*((Vpk[3][13][2]*Vpk[13][13][2])+((Vpk[3][13][0]*
          Vpk[13][13][0])+(Vpk[3][13][1]*Vpk[13][13][1]))))+((IkWpk[13][13][2]*
          Wpk[3][13][2])+((IkWpk[13][13][0]*Wpk[3][13][0])+(IkWpk[13][13][1]*
          Wpk[3][13][1]))));
        temp[0] = (((mk[11]*((Vpk[3][14][2]*Vpk[14][14][2])+((Vpk[3][14][0]*
          Vpk[14][14][0])+(Vpk[3][14][1]*Vpk[14][14][1]))))+((Cik[14][0][2]*
          IkWpk[14][14][2])+((Cik[14][0][0]*IkWpk[14][14][0])+(Cik[14][0][1]*
          IkWpk[14][14][1]))))+((mk[12]*((Vpk[3][15][2]*Vpk[14][15][2])+((
          Vpk[3][15][0]*Vpk[14][15][0])+(Vpk[3][15][1]*Vpk[14][15][1]))))+((
          IkWpk[14][15][2]*Wpk[3][15][2])+((IkWpk[14][15][0]*Wpk[3][15][0])+(
          IkWpk[14][15][1]*Wpk[3][15][1])))));
        temp[1] = (((mk[13]*((Vpk[3][16][2]*Vpk[14][16][2])+((Vpk[3][16][0]*
          Vpk[14][16][0])+(Vpk[3][16][1]*Vpk[14][16][1]))))+((IkWpk[14][16][2]*
          Wpk[3][16][2])+((IkWpk[14][16][0]*Wpk[3][16][0])+(IkWpk[14][16][1]*
          Wpk[3][16][1]))))+temp[0]);
        mm[3][14] = (((psmk[17]*((Vpk[3][17][2]*Vpk[14][17][2])+((Vpk[3][17][0]*
          Vpk[14][17][0])+(Vpk[3][17][1]*Vpk[14][17][1]))))+((IkWpk[14][17][2]*
          Wpk[3][17][2])+((IkWpk[14][17][0]*Wpk[3][17][0])+(IkWpk[14][17][1]*
          Wpk[3][17][1]))))+temp[1]);
        temp[0] = (((mk[12]*((Vpk[3][15][2]*Vpk[15][15][2])+((Vpk[3][15][0]*
          Vpk[15][15][0])+(Vpk[3][15][1]*Vpk[15][15][1]))))+((IkWpk[15][15][2]*
          Wpk[3][15][2])+((IkWpk[15][15][0]*Wpk[3][15][0])+(IkWpk[15][15][1]*
          Wpk[3][15][1]))))+((mk[13]*((Vpk[3][16][2]*Vpk[15][16][2])+((
          Vpk[3][16][0]*Vpk[15][16][0])+(Vpk[3][16][1]*Vpk[15][16][1]))))+((
          IkWpk[15][16][2]*Wpk[3][16][2])+((IkWpk[15][16][0]*Wpk[3][16][0])+(
          IkWpk[15][16][1]*Wpk[3][16][1])))));
        mm[3][15] = (((psmk[17]*((Vpk[3][17][2]*Vpk[15][17][2])+((Vpk[3][17][0]*
          Vpk[15][17][0])+(Vpk[3][17][1]*Vpk[15][17][1]))))+((IkWpk[15][17][2]*
          Wpk[3][17][2])+((IkWpk[15][17][0]*Wpk[3][17][0])+(IkWpk[15][17][1]*
          Wpk[3][17][1]))))+temp[0]);
        mm[3][16] = (((mk[13]*((Vpk[3][16][2]*Vpk[16][16][2])+((Vpk[3][16][0]*
          Vpk[16][16][0])+(Vpk[3][16][1]*Vpk[16][16][1]))))+((IkWpk[16][16][2]*
          Wpk[3][16][2])+((IkWpk[16][16][0]*Wpk[3][16][0])+(IkWpk[16][16][1]*
          Wpk[3][16][1]))))+((psmk[17]*((Vpk[3][17][2]*Vpk[16][17][2])+((
          Vpk[3][17][0]*Vpk[16][17][0])+(Vpk[3][17][1]*Vpk[16][17][1]))))+((
          IkWpk[16][17][2]*Wpk[3][17][2])+((IkWpk[16][17][0]*Wpk[3][17][0])+(
          IkWpk[16][17][1]*Wpk[3][17][1])))));
        mm[3][17] = ((psmk[17]*((Vpk[3][17][2]*Vpk[17][17][2])+((Vpk[3][17][0]*
          Vpk[17][17][0])+(Vpk[3][17][1]*Vpk[17][17][1]))))+((IkWpk[17][17][2]*
          Wpk[3][17][2])+((IkWpk[17][17][0]*Wpk[3][17][0])+(IkWpk[17][17][1]*
          Wpk[3][17][1]))));
        temp[0] = (((mk[16]*((Vpk[3][18][2]*Vpk[18][18][2])+((Vpk[3][18][0]*
          Vpk[18][18][0])+(Vpk[3][18][1]*Vpk[18][18][1]))))+((Cik[18][0][2]*
          IkWpk[18][18][2])+((Cik[18][0][0]*IkWpk[18][18][0])+(Cik[18][0][1]*
          IkWpk[18][18][1]))))+((mk[17]*((Vpk[3][19][2]*Vpk[18][19][2])+((
          Vpk[3][19][0]*Vpk[18][19][0])+(Vpk[3][19][1]*Vpk[18][19][1]))))+((
          IkWpk[18][19][2]*Wpk[3][19][2])+((IkWpk[18][19][0]*Wpk[3][19][0])+(
          IkWpk[18][19][1]*Wpk[3][19][1])))));
        temp[1] = (((mk[18]*((Vpk[3][20][2]*Vpk[18][20][2])+((Vpk[3][20][0]*
          Vpk[18][20][0])+(Vpk[3][20][1]*Vpk[18][20][1]))))+((IkWpk[18][20][2]*
          Wpk[3][20][2])+((IkWpk[18][20][0]*Wpk[3][20][0])+(IkWpk[18][20][1]*
          Wpk[3][20][1]))))+temp[0]);
        mm[3][18] = (((psmk[21]*((Vpk[3][21][2]*Vpk[18][21][2])+((Vpk[3][21][0]*
          Vpk[18][21][0])+(Vpk[3][21][1]*Vpk[18][21][1]))))+((IkWpk[18][21][2]*
          Wpk[3][21][2])+((IkWpk[18][21][0]*Wpk[3][21][0])+(IkWpk[18][21][1]*
          Wpk[3][21][1]))))+temp[1]);
        temp[0] = (((mk[17]*((Vpk[3][19][2]*Vpk[19][19][2])+((Vpk[3][19][0]*
          Vpk[19][19][0])+(Vpk[3][19][1]*Vpk[19][19][1]))))+((IkWpk[19][19][2]*
          Wpk[3][19][2])+((IkWpk[19][19][0]*Wpk[3][19][0])+(IkWpk[19][19][1]*
          Wpk[3][19][1]))))+((mk[18]*((Vpk[3][20][2]*Vpk[19][20][2])+((
          Vpk[3][20][0]*Vpk[19][20][0])+(Vpk[3][20][1]*Vpk[19][20][1]))))+((
          IkWpk[19][20][2]*Wpk[3][20][2])+((IkWpk[19][20][0]*Wpk[3][20][0])+(
          IkWpk[19][20][1]*Wpk[3][20][1])))));
        mm[3][19] = (((psmk[21]*((Vpk[3][21][2]*Vpk[19][21][2])+((Vpk[3][21][0]*
          Vpk[19][21][0])+(Vpk[3][21][1]*Vpk[19][21][1]))))+((IkWpk[19][21][2]*
          Wpk[3][21][2])+((IkWpk[19][21][0]*Wpk[3][21][0])+(IkWpk[19][21][1]*
          Wpk[3][21][1]))))+temp[0]);
        mm[3][20] = (((mk[18]*((Vpk[3][20][2]*Vpk[20][20][2])+((Vpk[3][20][0]*
          Vpk[20][20][0])+(Vpk[3][20][1]*Vpk[20][20][1]))))+((IkWpk[20][20][2]*
          Wpk[3][20][2])+((IkWpk[20][20][0]*Wpk[3][20][0])+(IkWpk[20][20][1]*
          Wpk[3][20][1]))))+((psmk[21]*((Vpk[3][21][2]*Vpk[20][21][2])+((
          Vpk[3][21][0]*Vpk[20][21][0])+(Vpk[3][21][1]*Vpk[20][21][1]))))+((
          IkWpk[20][21][2]*Wpk[3][21][2])+((IkWpk[20][21][0]*Wpk[3][21][0])+(
          IkWpk[20][21][1]*Wpk[3][21][1])))));
        mm[3][21] = ((psmk[21]*((Vpk[3][21][2]*Vpk[21][21][2])+((Vpk[3][21][0]*
          Vpk[21][21][0])+(Vpk[3][21][1]*Vpk[21][21][1]))))+((IkWpk[21][21][2]*
          Wpk[3][21][2])+((IkWpk[21][21][0]*Wpk[3][21][0])+(IkWpk[21][21][1]*
          Wpk[3][21][1]))));
        temp[0] = ((ik[0][1][1]+(mk[0]*((rk[0][0]*rk[0][0])+(rk[0][2]*rk[0][2]))
          ))+((mk[1]*((Vpk[4][6][2]*Vpk[4][6][2])+((Vpk[4][6][0]*Vpk[4][6][0])+(
          Vpk[4][6][1]*Vpk[4][6][1]))))+((Cik[6][1][2]*IkWpk[4][6][2])+((
          Cik[6][1][0]*IkWpk[4][6][0])+(Cik[6][1][1]*IkWpk[4][6][1])))));
        temp[1] = (temp[0]+((mk[2]*((Vpk[4][7][2]*Vpk[4][7][2])+((Vpk[4][7][0]*
          Vpk[4][7][0])+(Vpk[4][7][1]*Vpk[4][7][1]))))+((IkWpk[4][7][2]*
          Wpk[4][7][2])+((IkWpk[4][7][0]*Wpk[4][7][0])+(IkWpk[4][7][1]*
          Wpk[4][7][1])))));
        temp[2] = (((mk[3]*((Vpk[4][8][2]*Vpk[4][8][2])+((Vpk[4][8][0]*
          Vpk[4][8][0])+(Vpk[4][8][1]*Vpk[4][8][1]))))+((IkWpk[4][8][2]*
          Wpk[4][8][2])+((IkWpk[4][8][0]*Wpk[4][8][0])+(IkWpk[4][8][1]*
          Wpk[4][8][1]))))+temp[1]);
        temp[3] = (((psmk[9]*((Vpk[4][9][2]*Vpk[4][9][2])+((Vpk[4][9][0]*
          Vpk[4][9][0])+(Vpk[4][9][1]*Vpk[4][9][1]))))+((IkWpk[4][9][2]*
          Wpk[4][9][2])+((IkWpk[4][9][0]*Wpk[4][9][0])+(IkWpk[4][9][1]*
          Wpk[4][9][1]))))+temp[2]);
        temp[4] = (((mk[6]*((Vpk[4][10][2]*Vpk[4][10][2])+((Vpk[4][10][0]*
          Vpk[4][10][0])+(Vpk[4][10][1]*Vpk[4][10][1]))))+((Cik[10][1][2]*
          IkWpk[4][10][2])+((Cik[10][1][0]*IkWpk[4][10][0])+(Cik[10][1][1]*
          IkWpk[4][10][1]))))+temp[3]);
        temp[5] = (((mk[7]*((Vpk[4][11][2]*Vpk[4][11][2])+((Vpk[4][11][0]*
          Vpk[4][11][0])+(Vpk[4][11][1]*Vpk[4][11][1]))))+((IkWpk[4][11][2]*
          Wpk[4][11][2])+((IkWpk[4][11][0]*Wpk[4][11][0])+(IkWpk[4][11][1]*
          Wpk[4][11][1]))))+temp[4]);
        temp[6] = (((mk[8]*((Vpk[4][12][2]*Vpk[4][12][2])+((Vpk[4][12][0]*
          Vpk[4][12][0])+(Vpk[4][12][1]*Vpk[4][12][1]))))+((IkWpk[4][12][2]*
          Wpk[4][12][2])+((IkWpk[4][12][0]*Wpk[4][12][0])+(IkWpk[4][12][1]*
          Wpk[4][12][1]))))+temp[5]);
        temp[7] = (((psmk[13]*((Vpk[4][13][2]*Vpk[4][13][2])+((Vpk[4][13][0]*
          Vpk[4][13][0])+(Vpk[4][13][1]*Vpk[4][13][1]))))+((IkWpk[4][13][2]*
          Wpk[4][13][2])+((IkWpk[4][13][0]*Wpk[4][13][0])+(IkWpk[4][13][1]*
          Wpk[4][13][1]))))+temp[6]);
        temp[8] = (((mk[11]*((Vpk[4][14][2]*Vpk[4][14][2])+((Vpk[4][14][0]*
          Vpk[4][14][0])+(Vpk[4][14][1]*Vpk[4][14][1]))))+((Cik[14][1][2]*
          IkWpk[4][14][2])+((Cik[14][1][0]*IkWpk[4][14][0])+(Cik[14][1][1]*
          IkWpk[4][14][1]))))+temp[7]);
        temp[9] = (((mk[12]*((Vpk[4][15][2]*Vpk[4][15][2])+((Vpk[4][15][0]*
          Vpk[4][15][0])+(Vpk[4][15][1]*Vpk[4][15][1]))))+((IkWpk[4][15][2]*
          Wpk[4][15][2])+((IkWpk[4][15][0]*Wpk[4][15][0])+(IkWpk[4][15][1]*
          Wpk[4][15][1]))))+temp[8]);
        temp[10] = (((mk[13]*((Vpk[4][16][2]*Vpk[4][16][2])+((Vpk[4][16][0]*
          Vpk[4][16][0])+(Vpk[4][16][1]*Vpk[4][16][1]))))+((IkWpk[4][16][2]*
          Wpk[4][16][2])+((IkWpk[4][16][0]*Wpk[4][16][0])+(IkWpk[4][16][1]*
          Wpk[4][16][1]))))+temp[9]);
        temp[11] = (((psmk[17]*((Vpk[4][17][2]*Vpk[4][17][2])+((Vpk[4][17][0]*
          Vpk[4][17][0])+(Vpk[4][17][1]*Vpk[4][17][1]))))+((IkWpk[4][17][2]*
          Wpk[4][17][2])+((IkWpk[4][17][0]*Wpk[4][17][0])+(IkWpk[4][17][1]*
          Wpk[4][17][1]))))+temp[10]);
        temp[12] = (((mk[16]*((Vpk[4][18][2]*Vpk[4][18][2])+((Vpk[4][18][0]*
          Vpk[4][18][0])+(Vpk[4][18][1]*Vpk[4][18][1]))))+((Cik[18][1][2]*
          IkWpk[4][18][2])+((Cik[18][1][0]*IkWpk[4][18][0])+(Cik[18][1][1]*
          IkWpk[4][18][1]))))+temp[11]);
        temp[13] = (((mk[17]*((Vpk[4][19][2]*Vpk[4][19][2])+((Vpk[4][19][0]*
          Vpk[4][19][0])+(Vpk[4][19][1]*Vpk[4][19][1]))))+((IkWpk[4][19][2]*
          Wpk[4][19][2])+((IkWpk[4][19][0]*Wpk[4][19][0])+(IkWpk[4][19][1]*
          Wpk[4][19][1]))))+temp[12]);
        temp[14] = (((mk[18]*((Vpk[4][20][2]*Vpk[4][20][2])+((Vpk[4][20][0]*
          Vpk[4][20][0])+(Vpk[4][20][1]*Vpk[4][20][1]))))+((IkWpk[4][20][2]*
          Wpk[4][20][2])+((IkWpk[4][20][0]*Wpk[4][20][0])+(IkWpk[4][20][1]*
          Wpk[4][20][1]))))+temp[13]);
        mm[4][4] = (((psmk[21]*((Vpk[4][21][2]*Vpk[4][21][2])+((Vpk[4][21][0]*
          Vpk[4][21][0])+(Vpk[4][21][1]*Vpk[4][21][1]))))+((IkWpk[4][21][2]*
          Wpk[4][21][2])+((IkWpk[4][21][0]*Wpk[4][21][0])+(IkWpk[4][21][1]*
          Wpk[4][21][1]))))+temp[14]);
        temp[0] = ((ik[0][1][2]-(mk[0]*(rk[0][1]*rk[0][2])))+((mk[1]*((
          Vpk[4][6][2]*Vpk[5][6][2])+((Vpk[4][6][0]*Vpk[5][6][0])+(Vpk[4][6][1]*
          Vpk[5][6][1]))))+((Cik[6][1][2]*IkWpk[5][6][2])+((Cik[6][1][0]*
          IkWpk[5][6][0])+(Cik[6][1][1]*IkWpk[5][6][1])))));
        temp[1] = (temp[0]+((mk[2]*((Vpk[4][7][2]*Vpk[5][7][2])+((Vpk[4][7][0]*
          Vpk[5][7][0])+(Vpk[4][7][1]*Vpk[5][7][1]))))+((IkWpk[5][7][2]*
          Wpk[4][7][2])+((IkWpk[5][7][0]*Wpk[4][7][0])+(IkWpk[5][7][1]*
          Wpk[4][7][1])))));
        temp[2] = (((mk[3]*((Vpk[4][8][2]*Vpk[5][8][2])+((Vpk[4][8][0]*
          Vpk[5][8][0])+(Vpk[4][8][1]*Vpk[5][8][1]))))+((IkWpk[5][8][2]*
          Wpk[4][8][2])+((IkWpk[5][8][0]*Wpk[4][8][0])+(IkWpk[5][8][1]*
          Wpk[4][8][1]))))+temp[1]);
        temp[3] = (((psmk[9]*((Vpk[4][9][2]*Vpk[5][9][2])+((Vpk[4][9][0]*
          Vpk[5][9][0])+(Vpk[4][9][1]*Vpk[5][9][1]))))+((IkWpk[5][9][2]*
          Wpk[4][9][2])+((IkWpk[5][9][0]*Wpk[4][9][0])+(IkWpk[5][9][1]*
          Wpk[4][9][1]))))+temp[2]);
        temp[4] = (((mk[6]*((Vpk[4][10][2]*Vpk[5][10][2])+((Vpk[4][10][0]*
          Vpk[5][10][0])+(Vpk[4][10][1]*Vpk[5][10][1]))))+((Cik[10][1][2]*
          IkWpk[5][10][2])+((Cik[10][1][0]*IkWpk[5][10][0])+(Cik[10][1][1]*
          IkWpk[5][10][1]))))+temp[3]);
        temp[5] = (((mk[7]*((Vpk[4][11][2]*Vpk[5][11][2])+((Vpk[4][11][0]*
          Vpk[5][11][0])+(Vpk[4][11][1]*Vpk[5][11][1]))))+((IkWpk[5][11][2]*
          Wpk[4][11][2])+((IkWpk[5][11][0]*Wpk[4][11][0])+(IkWpk[5][11][1]*
          Wpk[4][11][1]))))+temp[4]);
        temp[6] = (((mk[8]*((Vpk[4][12][2]*Vpk[5][12][2])+((Vpk[4][12][0]*
          Vpk[5][12][0])+(Vpk[4][12][1]*Vpk[5][12][1]))))+((IkWpk[5][12][2]*
          Wpk[4][12][2])+((IkWpk[5][12][0]*Wpk[4][12][0])+(IkWpk[5][12][1]*
          Wpk[4][12][1]))))+temp[5]);
        temp[7] = (((psmk[13]*((Vpk[4][13][2]*Vpk[5][13][2])+((Vpk[4][13][0]*
          Vpk[5][13][0])+(Vpk[4][13][1]*Vpk[5][13][1]))))+((IkWpk[5][13][2]*
          Wpk[4][13][2])+((IkWpk[5][13][0]*Wpk[4][13][0])+(IkWpk[5][13][1]*
          Wpk[4][13][1]))))+temp[6]);
        temp[8] = (((mk[11]*((Vpk[4][14][2]*Vpk[5][14][2])+((Vpk[4][14][0]*
          Vpk[5][14][0])+(Vpk[4][14][1]*Vpk[5][14][1]))))+((Cik[14][1][2]*
          IkWpk[5][14][2])+((Cik[14][1][0]*IkWpk[5][14][0])+(Cik[14][1][1]*
          IkWpk[5][14][1]))))+temp[7]);
        temp[9] = (((mk[12]*((Vpk[4][15][2]*Vpk[5][15][2])+((Vpk[4][15][0]*
          Vpk[5][15][0])+(Vpk[4][15][1]*Vpk[5][15][1]))))+((IkWpk[5][15][2]*
          Wpk[4][15][2])+((IkWpk[5][15][0]*Wpk[4][15][0])+(IkWpk[5][15][1]*
          Wpk[4][15][1]))))+temp[8]);
        temp[10] = (((mk[13]*((Vpk[4][16][2]*Vpk[5][16][2])+((Vpk[4][16][0]*
          Vpk[5][16][0])+(Vpk[4][16][1]*Vpk[5][16][1]))))+((IkWpk[5][16][2]*
          Wpk[4][16][2])+((IkWpk[5][16][0]*Wpk[4][16][0])+(IkWpk[5][16][1]*
          Wpk[4][16][1]))))+temp[9]);
        temp[11] = (((psmk[17]*((Vpk[4][17][2]*Vpk[5][17][2])+((Vpk[4][17][0]*
          Vpk[5][17][0])+(Vpk[4][17][1]*Vpk[5][17][1]))))+((IkWpk[5][17][2]*
          Wpk[4][17][2])+((IkWpk[5][17][0]*Wpk[4][17][0])+(IkWpk[5][17][1]*
          Wpk[4][17][1]))))+temp[10]);
        temp[12] = (((mk[16]*((Vpk[4][18][2]*Vpk[5][18][2])+((Vpk[4][18][0]*
          Vpk[5][18][0])+(Vpk[4][18][1]*Vpk[5][18][1]))))+((Cik[18][1][2]*
          IkWpk[5][18][2])+((Cik[18][1][0]*IkWpk[5][18][0])+(Cik[18][1][1]*
          IkWpk[5][18][1]))))+temp[11]);
        temp[13] = (((mk[17]*((Vpk[4][19][2]*Vpk[5][19][2])+((Vpk[4][19][0]*
          Vpk[5][19][0])+(Vpk[4][19][1]*Vpk[5][19][1]))))+((IkWpk[5][19][2]*
          Wpk[4][19][2])+((IkWpk[5][19][0]*Wpk[4][19][0])+(IkWpk[5][19][1]*
          Wpk[4][19][1]))))+temp[12]);
        temp[14] = (((mk[18]*((Vpk[4][20][2]*Vpk[5][20][2])+((Vpk[4][20][0]*
          Vpk[5][20][0])+(Vpk[4][20][1]*Vpk[5][20][1]))))+((IkWpk[5][20][2]*
          Wpk[4][20][2])+((IkWpk[5][20][0]*Wpk[4][20][0])+(IkWpk[5][20][1]*
          Wpk[4][20][1]))))+temp[13]);
        mm[4][5] = (((psmk[21]*((Vpk[4][21][2]*Vpk[5][21][2])+((Vpk[4][21][0]*
          Vpk[5][21][0])+(Vpk[4][21][1]*Vpk[5][21][1]))))+((IkWpk[5][21][2]*
          Wpk[4][21][2])+((IkWpk[5][21][0]*Wpk[4][21][0])+(IkWpk[5][21][1]*
          Wpk[4][21][1]))))+temp[14]);
        temp[0] = (((mk[1]*((Vpk[4][6][2]*Vpk[6][6][2])+((Vpk[4][6][0]*
          Vpk[6][6][0])+(Vpk[4][6][1]*Vpk[6][6][1]))))+((Cik[6][1][2]*
          IkWpk[6][6][2])+((Cik[6][1][0]*IkWpk[6][6][0])+(Cik[6][1][1]*
          IkWpk[6][6][1]))))+((mk[2]*((Vpk[4][7][2]*Vpk[6][7][2])+((Vpk[4][7][0]
          *Vpk[6][7][0])+(Vpk[4][7][1]*Vpk[6][7][1]))))+((IkWpk[6][7][2]*
          Wpk[4][7][2])+((IkWpk[6][7][0]*Wpk[4][7][0])+(IkWpk[6][7][1]*
          Wpk[4][7][1])))));
        temp[1] = (((mk[3]*((Vpk[4][8][2]*Vpk[6][8][2])+((Vpk[4][8][0]*
          Vpk[6][8][0])+(Vpk[4][8][1]*Vpk[6][8][1]))))+((IkWpk[6][8][2]*
          Wpk[4][8][2])+((IkWpk[6][8][0]*Wpk[4][8][0])+(IkWpk[6][8][1]*
          Wpk[4][8][1]))))+temp[0]);
        mm[4][6] = (((psmk[9]*((Vpk[4][9][2]*Vpk[6][9][2])+((Vpk[4][9][0]*
          Vpk[6][9][0])+(Vpk[4][9][1]*Vpk[6][9][1]))))+((IkWpk[6][9][2]*
          Wpk[4][9][2])+((IkWpk[6][9][0]*Wpk[4][9][0])+(IkWpk[6][9][1]*
          Wpk[4][9][1]))))+temp[1]);
        temp[0] = (((mk[2]*((Vpk[4][7][2]*Vpk[7][7][2])+((Vpk[4][7][0]*
          Vpk[7][7][0])+(Vpk[4][7][1]*Vpk[7][7][1]))))+((IkWpk[7][7][2]*
          Wpk[4][7][2])+((IkWpk[7][7][0]*Wpk[4][7][0])+(IkWpk[7][7][1]*
          Wpk[4][7][1]))))+((mk[3]*((Vpk[4][8][2]*Vpk[7][8][2])+((Vpk[4][8][0]*
          Vpk[7][8][0])+(Vpk[4][8][1]*Vpk[7][8][1]))))+((IkWpk[7][8][2]*
          Wpk[4][8][2])+((IkWpk[7][8][0]*Wpk[4][8][0])+(IkWpk[7][8][1]*
          Wpk[4][8][1])))));
        mm[4][7] = (((psmk[9]*((Vpk[4][9][2]*Vpk[7][9][2])+((Vpk[4][9][0]*
          Vpk[7][9][0])+(Vpk[4][9][1]*Vpk[7][9][1]))))+((IkWpk[7][9][2]*
          Wpk[4][9][2])+((IkWpk[7][9][0]*Wpk[4][9][0])+(IkWpk[7][9][1]*
          Wpk[4][9][1]))))+temp[0]);
        mm[4][8] = (((mk[3]*((Vpk[4][8][2]*Vpk[8][8][2])+((Vpk[4][8][0]*
          Vpk[8][8][0])+(Vpk[4][8][1]*Vpk[8][8][1]))))+((IkWpk[8][8][2]*
          Wpk[4][8][2])+((IkWpk[8][8][0]*Wpk[4][8][0])+(IkWpk[8][8][1]*
          Wpk[4][8][1]))))+((psmk[9]*((Vpk[4][9][2]*Vpk[8][9][2])+((Vpk[4][9][0]
          *Vpk[8][9][0])+(Vpk[4][9][1]*Vpk[8][9][1]))))+((IkWpk[8][9][2]*
          Wpk[4][9][2])+((IkWpk[8][9][0]*Wpk[4][9][0])+(IkWpk[8][9][1]*
          Wpk[4][9][1])))));
        mm[4][9] = ((psmk[9]*((Vpk[4][9][2]*Vpk[9][9][2])+((Vpk[4][9][0]*
          Vpk[9][9][0])+(Vpk[4][9][1]*Vpk[9][9][1]))))+((IkWpk[9][9][2]*
          Wpk[4][9][2])+((IkWpk[9][9][0]*Wpk[4][9][0])+(IkWpk[9][9][1]*
          Wpk[4][9][1]))));
        temp[0] = (((mk[6]*((Vpk[4][10][2]*Vpk[10][10][2])+((Vpk[4][10][0]*
          Vpk[10][10][0])+(Vpk[4][10][1]*Vpk[10][10][1]))))+((Cik[10][1][2]*
          IkWpk[10][10][2])+((Cik[10][1][0]*IkWpk[10][10][0])+(Cik[10][1][1]*
          IkWpk[10][10][1]))))+((mk[7]*((Vpk[4][11][2]*Vpk[10][11][2])+((
          Vpk[4][11][0]*Vpk[10][11][0])+(Vpk[4][11][1]*Vpk[10][11][1]))))+((
          IkWpk[10][11][2]*Wpk[4][11][2])+((IkWpk[10][11][0]*Wpk[4][11][0])+(
          IkWpk[10][11][1]*Wpk[4][11][1])))));
        temp[1] = (((mk[8]*((Vpk[4][12][2]*Vpk[10][12][2])+((Vpk[4][12][0]*
          Vpk[10][12][0])+(Vpk[4][12][1]*Vpk[10][12][1]))))+((IkWpk[10][12][2]*
          Wpk[4][12][2])+((IkWpk[10][12][0]*Wpk[4][12][0])+(IkWpk[10][12][1]*
          Wpk[4][12][1]))))+temp[0]);
        mm[4][10] = (((psmk[13]*((Vpk[4][13][2]*Vpk[10][13][2])+((Vpk[4][13][0]*
          Vpk[10][13][0])+(Vpk[4][13][1]*Vpk[10][13][1]))))+((IkWpk[10][13][2]*
          Wpk[4][13][2])+((IkWpk[10][13][0]*Wpk[4][13][0])+(IkWpk[10][13][1]*
          Wpk[4][13][1]))))+temp[1]);
        temp[0] = (((mk[7]*((Vpk[4][11][2]*Vpk[11][11][2])+((Vpk[4][11][0]*
          Vpk[11][11][0])+(Vpk[4][11][1]*Vpk[11][11][1]))))+((IkWpk[11][11][2]*
          Wpk[4][11][2])+((IkWpk[11][11][0]*Wpk[4][11][0])+(IkWpk[11][11][1]*
          Wpk[4][11][1]))))+((mk[8]*((Vpk[4][12][2]*Vpk[11][12][2])+((
          Vpk[4][12][0]*Vpk[11][12][0])+(Vpk[4][12][1]*Vpk[11][12][1]))))+((
          IkWpk[11][12][2]*Wpk[4][12][2])+((IkWpk[11][12][0]*Wpk[4][12][0])+(
          IkWpk[11][12][1]*Wpk[4][12][1])))));
        mm[4][11] = (((psmk[13]*((Vpk[4][13][2]*Vpk[11][13][2])+((Vpk[4][13][0]*
          Vpk[11][13][0])+(Vpk[4][13][1]*Vpk[11][13][1]))))+((IkWpk[11][13][2]*
          Wpk[4][13][2])+((IkWpk[11][13][0]*Wpk[4][13][0])+(IkWpk[11][13][1]*
          Wpk[4][13][1]))))+temp[0]);
        mm[4][12] = (((mk[8]*((Vpk[4][12][2]*Vpk[12][12][2])+((Vpk[4][12][0]*
          Vpk[12][12][0])+(Vpk[4][12][1]*Vpk[12][12][1]))))+((IkWpk[12][12][2]*
          Wpk[4][12][2])+((IkWpk[12][12][0]*Wpk[4][12][0])+(IkWpk[12][12][1]*
          Wpk[4][12][1]))))+((psmk[13]*((Vpk[4][13][2]*Vpk[12][13][2])+((
          Vpk[4][13][0]*Vpk[12][13][0])+(Vpk[4][13][1]*Vpk[12][13][1]))))+((
          IkWpk[12][13][2]*Wpk[4][13][2])+((IkWpk[12][13][0]*Wpk[4][13][0])+(
          IkWpk[12][13][1]*Wpk[4][13][1])))));
        mm[4][13] = ((psmk[13]*((Vpk[4][13][2]*Vpk[13][13][2])+((Vpk[4][13][0]*
          Vpk[13][13][0])+(Vpk[4][13][1]*Vpk[13][13][1]))))+((IkWpk[13][13][2]*
          Wpk[4][13][2])+((IkWpk[13][13][0]*Wpk[4][13][0])+(IkWpk[13][13][1]*
          Wpk[4][13][1]))));
        temp[0] = (((mk[11]*((Vpk[4][14][2]*Vpk[14][14][2])+((Vpk[4][14][0]*
          Vpk[14][14][0])+(Vpk[4][14][1]*Vpk[14][14][1]))))+((Cik[14][1][2]*
          IkWpk[14][14][2])+((Cik[14][1][0]*IkWpk[14][14][0])+(Cik[14][1][1]*
          IkWpk[14][14][1]))))+((mk[12]*((Vpk[4][15][2]*Vpk[14][15][2])+((
          Vpk[4][15][0]*Vpk[14][15][0])+(Vpk[4][15][1]*Vpk[14][15][1]))))+((
          IkWpk[14][15][2]*Wpk[4][15][2])+((IkWpk[14][15][0]*Wpk[4][15][0])+(
          IkWpk[14][15][1]*Wpk[4][15][1])))));
        temp[1] = (((mk[13]*((Vpk[4][16][2]*Vpk[14][16][2])+((Vpk[4][16][0]*
          Vpk[14][16][0])+(Vpk[4][16][1]*Vpk[14][16][1]))))+((IkWpk[14][16][2]*
          Wpk[4][16][2])+((IkWpk[14][16][0]*Wpk[4][16][0])+(IkWpk[14][16][1]*
          Wpk[4][16][1]))))+temp[0]);
        mm[4][14] = (((psmk[17]*((Vpk[4][17][2]*Vpk[14][17][2])+((Vpk[4][17][0]*
          Vpk[14][17][0])+(Vpk[4][17][1]*Vpk[14][17][1]))))+((IkWpk[14][17][2]*
          Wpk[4][17][2])+((IkWpk[14][17][0]*Wpk[4][17][0])+(IkWpk[14][17][1]*
          Wpk[4][17][1]))))+temp[1]);
        temp[0] = (((mk[12]*((Vpk[4][15][2]*Vpk[15][15][2])+((Vpk[4][15][0]*
          Vpk[15][15][0])+(Vpk[4][15][1]*Vpk[15][15][1]))))+((IkWpk[15][15][2]*
          Wpk[4][15][2])+((IkWpk[15][15][0]*Wpk[4][15][0])+(IkWpk[15][15][1]*
          Wpk[4][15][1]))))+((mk[13]*((Vpk[4][16][2]*Vpk[15][16][2])+((
          Vpk[4][16][0]*Vpk[15][16][0])+(Vpk[4][16][1]*Vpk[15][16][1]))))+((
          IkWpk[15][16][2]*Wpk[4][16][2])+((IkWpk[15][16][0]*Wpk[4][16][0])+(
          IkWpk[15][16][1]*Wpk[4][16][1])))));
        mm[4][15] = (((psmk[17]*((Vpk[4][17][2]*Vpk[15][17][2])+((Vpk[4][17][0]*
          Vpk[15][17][0])+(Vpk[4][17][1]*Vpk[15][17][1]))))+((IkWpk[15][17][2]*
          Wpk[4][17][2])+((IkWpk[15][17][0]*Wpk[4][17][0])+(IkWpk[15][17][1]*
          Wpk[4][17][1]))))+temp[0]);
        mm[4][16] = (((mk[13]*((Vpk[4][16][2]*Vpk[16][16][2])+((Vpk[4][16][0]*
          Vpk[16][16][0])+(Vpk[4][16][1]*Vpk[16][16][1]))))+((IkWpk[16][16][2]*
          Wpk[4][16][2])+((IkWpk[16][16][0]*Wpk[4][16][0])+(IkWpk[16][16][1]*
          Wpk[4][16][1]))))+((psmk[17]*((Vpk[4][17][2]*Vpk[16][17][2])+((
          Vpk[4][17][0]*Vpk[16][17][0])+(Vpk[4][17][1]*Vpk[16][17][1]))))+((
          IkWpk[16][17][2]*Wpk[4][17][2])+((IkWpk[16][17][0]*Wpk[4][17][0])+(
          IkWpk[16][17][1]*Wpk[4][17][1])))));
        mm[4][17] = ((psmk[17]*((Vpk[4][17][2]*Vpk[17][17][2])+((Vpk[4][17][0]*
          Vpk[17][17][0])+(Vpk[4][17][1]*Vpk[17][17][1]))))+((IkWpk[17][17][2]*
          Wpk[4][17][2])+((IkWpk[17][17][0]*Wpk[4][17][0])+(IkWpk[17][17][1]*
          Wpk[4][17][1]))));
        temp[0] = (((mk[16]*((Vpk[4][18][2]*Vpk[18][18][2])+((Vpk[4][18][0]*
          Vpk[18][18][0])+(Vpk[4][18][1]*Vpk[18][18][1]))))+((Cik[18][1][2]*
          IkWpk[18][18][2])+((Cik[18][1][0]*IkWpk[18][18][0])+(Cik[18][1][1]*
          IkWpk[18][18][1]))))+((mk[17]*((Vpk[4][19][2]*Vpk[18][19][2])+((
          Vpk[4][19][0]*Vpk[18][19][0])+(Vpk[4][19][1]*Vpk[18][19][1]))))+((
          IkWpk[18][19][2]*Wpk[4][19][2])+((IkWpk[18][19][0]*Wpk[4][19][0])+(
          IkWpk[18][19][1]*Wpk[4][19][1])))));
        temp[1] = (((mk[18]*((Vpk[4][20][2]*Vpk[18][20][2])+((Vpk[4][20][0]*
          Vpk[18][20][0])+(Vpk[4][20][1]*Vpk[18][20][1]))))+((IkWpk[18][20][2]*
          Wpk[4][20][2])+((IkWpk[18][20][0]*Wpk[4][20][0])+(IkWpk[18][20][1]*
          Wpk[4][20][1]))))+temp[0]);
        mm[4][18] = (((psmk[21]*((Vpk[4][21][2]*Vpk[18][21][2])+((Vpk[4][21][0]*
          Vpk[18][21][0])+(Vpk[4][21][1]*Vpk[18][21][1]))))+((IkWpk[18][21][2]*
          Wpk[4][21][2])+((IkWpk[18][21][0]*Wpk[4][21][0])+(IkWpk[18][21][1]*
          Wpk[4][21][1]))))+temp[1]);
        temp[0] = (((mk[17]*((Vpk[4][19][2]*Vpk[19][19][2])+((Vpk[4][19][0]*
          Vpk[19][19][0])+(Vpk[4][19][1]*Vpk[19][19][1]))))+((IkWpk[19][19][2]*
          Wpk[4][19][2])+((IkWpk[19][19][0]*Wpk[4][19][0])+(IkWpk[19][19][1]*
          Wpk[4][19][1]))))+((mk[18]*((Vpk[4][20][2]*Vpk[19][20][2])+((
          Vpk[4][20][0]*Vpk[19][20][0])+(Vpk[4][20][1]*Vpk[19][20][1]))))+((
          IkWpk[19][20][2]*Wpk[4][20][2])+((IkWpk[19][20][0]*Wpk[4][20][0])+(
          IkWpk[19][20][1]*Wpk[4][20][1])))));
        mm[4][19] = (((psmk[21]*((Vpk[4][21][2]*Vpk[19][21][2])+((Vpk[4][21][0]*
          Vpk[19][21][0])+(Vpk[4][21][1]*Vpk[19][21][1]))))+((IkWpk[19][21][2]*
          Wpk[4][21][2])+((IkWpk[19][21][0]*Wpk[4][21][0])+(IkWpk[19][21][1]*
          Wpk[4][21][1]))))+temp[0]);
        mm[4][20] = (((mk[18]*((Vpk[4][20][2]*Vpk[20][20][2])+((Vpk[4][20][0]*
          Vpk[20][20][0])+(Vpk[4][20][1]*Vpk[20][20][1]))))+((IkWpk[20][20][2]*
          Wpk[4][20][2])+((IkWpk[20][20][0]*Wpk[4][20][0])+(IkWpk[20][20][1]*
          Wpk[4][20][1]))))+((psmk[21]*((Vpk[4][21][2]*Vpk[20][21][2])+((
          Vpk[4][21][0]*Vpk[20][21][0])+(Vpk[4][21][1]*Vpk[20][21][1]))))+((
          IkWpk[20][21][2]*Wpk[4][21][2])+((IkWpk[20][21][0]*Wpk[4][21][0])+(
          IkWpk[20][21][1]*Wpk[4][21][1])))));
        mm[4][21] = ((psmk[21]*((Vpk[4][21][2]*Vpk[21][21][2])+((Vpk[4][21][0]*
          Vpk[21][21][0])+(Vpk[4][21][1]*Vpk[21][21][1]))))+((IkWpk[21][21][2]*
          Wpk[4][21][2])+((IkWpk[21][21][0]*Wpk[4][21][0])+(IkWpk[21][21][1]*
          Wpk[4][21][1]))));
        temp[0] = ((ik[0][2][2]+(mk[0]*((rk[0][0]*rk[0][0])+(rk[0][1]*rk[0][1]))
          ))+((mk[1]*((Vpk[5][6][2]*Vpk[5][6][2])+((Vpk[5][6][0]*Vpk[5][6][0])+(
          Vpk[5][6][1]*Vpk[5][6][1]))))+((Cik[6][2][2]*IkWpk[5][6][2])+((
          Cik[6][2][0]*IkWpk[5][6][0])+(Cik[6][2][1]*IkWpk[5][6][1])))));
        temp[1] = (temp[0]+((mk[2]*((Vpk[5][7][2]*Vpk[5][7][2])+((Vpk[5][7][0]*
          Vpk[5][7][0])+(Vpk[5][7][1]*Vpk[5][7][1]))))+((IkWpk[5][7][2]*
          Wpk[5][7][2])+((IkWpk[5][7][0]*Wpk[5][7][0])+(IkWpk[5][7][1]*
          Wpk[5][7][1])))));
        temp[2] = (((mk[3]*((Vpk[5][8][2]*Vpk[5][8][2])+((Vpk[5][8][0]*
          Vpk[5][8][0])+(Vpk[5][8][1]*Vpk[5][8][1]))))+((IkWpk[5][8][2]*
          Wpk[5][8][2])+((IkWpk[5][8][0]*Wpk[5][8][0])+(IkWpk[5][8][1]*
          Wpk[5][8][1]))))+temp[1]);
        temp[3] = (((psmk[9]*((Vpk[5][9][2]*Vpk[5][9][2])+((Vpk[5][9][0]*
          Vpk[5][9][0])+(Vpk[5][9][1]*Vpk[5][9][1]))))+((IkWpk[5][9][2]*
          Wpk[5][9][2])+((IkWpk[5][9][0]*Wpk[5][9][0])+(IkWpk[5][9][1]*
          Wpk[5][9][1]))))+temp[2]);
        temp[4] = (((mk[6]*((Vpk[5][10][2]*Vpk[5][10][2])+((Vpk[5][10][0]*
          Vpk[5][10][0])+(Vpk[5][10][1]*Vpk[5][10][1]))))+((Cik[10][2][2]*
          IkWpk[5][10][2])+((Cik[10][2][0]*IkWpk[5][10][0])+(Cik[10][2][1]*
          IkWpk[5][10][1]))))+temp[3]);
        temp[5] = (((mk[7]*((Vpk[5][11][2]*Vpk[5][11][2])+((Vpk[5][11][0]*
          Vpk[5][11][0])+(Vpk[5][11][1]*Vpk[5][11][1]))))+((IkWpk[5][11][2]*
          Wpk[5][11][2])+((IkWpk[5][11][0]*Wpk[5][11][0])+(IkWpk[5][11][1]*
          Wpk[5][11][1]))))+temp[4]);
        temp[6] = (((mk[8]*((Vpk[5][12][2]*Vpk[5][12][2])+((Vpk[5][12][0]*
          Vpk[5][12][0])+(Vpk[5][12][1]*Vpk[5][12][1]))))+((IkWpk[5][12][2]*
          Wpk[5][12][2])+((IkWpk[5][12][0]*Wpk[5][12][0])+(IkWpk[5][12][1]*
          Wpk[5][12][1]))))+temp[5]);
        temp[7] = (((psmk[13]*((Vpk[5][13][2]*Vpk[5][13][2])+((Vpk[5][13][0]*
          Vpk[5][13][0])+(Vpk[5][13][1]*Vpk[5][13][1]))))+((IkWpk[5][13][2]*
          Wpk[5][13][2])+((IkWpk[5][13][0]*Wpk[5][13][0])+(IkWpk[5][13][1]*
          Wpk[5][13][1]))))+temp[6]);
        temp[8] = (((mk[11]*((Vpk[5][14][2]*Vpk[5][14][2])+((Vpk[5][14][0]*
          Vpk[5][14][0])+(Vpk[5][14][1]*Vpk[5][14][1]))))+((Cik[14][2][2]*
          IkWpk[5][14][2])+((Cik[14][2][0]*IkWpk[5][14][0])+(Cik[14][2][1]*
          IkWpk[5][14][1]))))+temp[7]);
        temp[9] = (((mk[12]*((Vpk[5][15][2]*Vpk[5][15][2])+((Vpk[5][15][0]*
          Vpk[5][15][0])+(Vpk[5][15][1]*Vpk[5][15][1]))))+((IkWpk[5][15][2]*
          Wpk[5][15][2])+((IkWpk[5][15][0]*Wpk[5][15][0])+(IkWpk[5][15][1]*
          Wpk[5][15][1]))))+temp[8]);
        temp[10] = (((mk[13]*((Vpk[5][16][2]*Vpk[5][16][2])+((Vpk[5][16][0]*
          Vpk[5][16][0])+(Vpk[5][16][1]*Vpk[5][16][1]))))+((IkWpk[5][16][2]*
          Wpk[5][16][2])+((IkWpk[5][16][0]*Wpk[5][16][0])+(IkWpk[5][16][1]*
          Wpk[5][16][1]))))+temp[9]);
        temp[11] = (((psmk[17]*((Vpk[5][17][2]*Vpk[5][17][2])+((Vpk[5][17][0]*
          Vpk[5][17][0])+(Vpk[5][17][1]*Vpk[5][17][1]))))+((IkWpk[5][17][2]*
          Wpk[5][17][2])+((IkWpk[5][17][0]*Wpk[5][17][0])+(IkWpk[5][17][1]*
          Wpk[5][17][1]))))+temp[10]);
        temp[12] = (((mk[16]*((Vpk[5][18][2]*Vpk[5][18][2])+((Vpk[5][18][0]*
          Vpk[5][18][0])+(Vpk[5][18][1]*Vpk[5][18][1]))))+((Cik[18][2][2]*
          IkWpk[5][18][2])+((Cik[18][2][0]*IkWpk[5][18][0])+(Cik[18][2][1]*
          IkWpk[5][18][1]))))+temp[11]);
        temp[13] = (((mk[17]*((Vpk[5][19][2]*Vpk[5][19][2])+((Vpk[5][19][0]*
          Vpk[5][19][0])+(Vpk[5][19][1]*Vpk[5][19][1]))))+((IkWpk[5][19][2]*
          Wpk[5][19][2])+((IkWpk[5][19][0]*Wpk[5][19][0])+(IkWpk[5][19][1]*
          Wpk[5][19][1]))))+temp[12]);
        temp[14] = (((mk[18]*((Vpk[5][20][2]*Vpk[5][20][2])+((Vpk[5][20][0]*
          Vpk[5][20][0])+(Vpk[5][20][1]*Vpk[5][20][1]))))+((IkWpk[5][20][2]*
          Wpk[5][20][2])+((IkWpk[5][20][0]*Wpk[5][20][0])+(IkWpk[5][20][1]*
          Wpk[5][20][1]))))+temp[13]);
        mm[5][5] = (((psmk[21]*((Vpk[5][21][2]*Vpk[5][21][2])+((Vpk[5][21][0]*
          Vpk[5][21][0])+(Vpk[5][21][1]*Vpk[5][21][1]))))+((IkWpk[5][21][2]*
          Wpk[5][21][2])+((IkWpk[5][21][0]*Wpk[5][21][0])+(IkWpk[5][21][1]*
          Wpk[5][21][1]))))+temp[14]);
        temp[0] = (((mk[1]*((Vpk[5][6][2]*Vpk[6][6][2])+((Vpk[5][6][0]*
          Vpk[6][6][0])+(Vpk[5][6][1]*Vpk[6][6][1]))))+((Cik[6][2][2]*
          IkWpk[6][6][2])+((Cik[6][2][0]*IkWpk[6][6][0])+(Cik[6][2][1]*
          IkWpk[6][6][1]))))+((mk[2]*((Vpk[5][7][2]*Vpk[6][7][2])+((Vpk[5][7][0]
          *Vpk[6][7][0])+(Vpk[5][7][1]*Vpk[6][7][1]))))+((IkWpk[6][7][2]*
          Wpk[5][7][2])+((IkWpk[6][7][0]*Wpk[5][7][0])+(IkWpk[6][7][1]*
          Wpk[5][7][1])))));
        temp[1] = (((mk[3]*((Vpk[5][8][2]*Vpk[6][8][2])+((Vpk[5][8][0]*
          Vpk[6][8][0])+(Vpk[5][8][1]*Vpk[6][8][1]))))+((IkWpk[6][8][2]*
          Wpk[5][8][2])+((IkWpk[6][8][0]*Wpk[5][8][0])+(IkWpk[6][8][1]*
          Wpk[5][8][1]))))+temp[0]);
        mm[5][6] = (((psmk[9]*((Vpk[5][9][2]*Vpk[6][9][2])+((Vpk[5][9][0]*
          Vpk[6][9][0])+(Vpk[5][9][1]*Vpk[6][9][1]))))+((IkWpk[6][9][2]*
          Wpk[5][9][2])+((IkWpk[6][9][0]*Wpk[5][9][0])+(IkWpk[6][9][1]*
          Wpk[5][9][1]))))+temp[1]);
        temp[0] = (((mk[2]*((Vpk[5][7][2]*Vpk[7][7][2])+((Vpk[5][7][0]*
          Vpk[7][7][0])+(Vpk[5][7][1]*Vpk[7][7][1]))))+((IkWpk[7][7][2]*
          Wpk[5][7][2])+((IkWpk[7][7][0]*Wpk[5][7][0])+(IkWpk[7][7][1]*
          Wpk[5][7][1]))))+((mk[3]*((Vpk[5][8][2]*Vpk[7][8][2])+((Vpk[5][8][0]*
          Vpk[7][8][0])+(Vpk[5][8][1]*Vpk[7][8][1]))))+((IkWpk[7][8][2]*
          Wpk[5][8][2])+((IkWpk[7][8][0]*Wpk[5][8][0])+(IkWpk[7][8][1]*
          Wpk[5][8][1])))));
        mm[5][7] = (((psmk[9]*((Vpk[5][9][2]*Vpk[7][9][2])+((Vpk[5][9][0]*
          Vpk[7][9][0])+(Vpk[5][9][1]*Vpk[7][9][1]))))+((IkWpk[7][9][2]*
          Wpk[5][9][2])+((IkWpk[7][9][0]*Wpk[5][9][0])+(IkWpk[7][9][1]*
          Wpk[5][9][1]))))+temp[0]);
        mm[5][8] = (((mk[3]*((Vpk[5][8][2]*Vpk[8][8][2])+((Vpk[5][8][0]*
          Vpk[8][8][0])+(Vpk[5][8][1]*Vpk[8][8][1]))))+((IkWpk[8][8][2]*
          Wpk[5][8][2])+((IkWpk[8][8][0]*Wpk[5][8][0])+(IkWpk[8][8][1]*
          Wpk[5][8][1]))))+((psmk[9]*((Vpk[5][9][2]*Vpk[8][9][2])+((Vpk[5][9][0]
          *Vpk[8][9][0])+(Vpk[5][9][1]*Vpk[8][9][1]))))+((IkWpk[8][9][2]*
          Wpk[5][9][2])+((IkWpk[8][9][0]*Wpk[5][9][0])+(IkWpk[8][9][1]*
          Wpk[5][9][1])))));
        mm[5][9] = ((psmk[9]*((Vpk[5][9][2]*Vpk[9][9][2])+((Vpk[5][9][0]*
          Vpk[9][9][0])+(Vpk[5][9][1]*Vpk[9][9][1]))))+((IkWpk[9][9][2]*
          Wpk[5][9][2])+((IkWpk[9][9][0]*Wpk[5][9][0])+(IkWpk[9][9][1]*
          Wpk[5][9][1]))));
        temp[0] = (((mk[6]*((Vpk[5][10][2]*Vpk[10][10][2])+((Vpk[5][10][0]*
          Vpk[10][10][0])+(Vpk[5][10][1]*Vpk[10][10][1]))))+((Cik[10][2][2]*
          IkWpk[10][10][2])+((Cik[10][2][0]*IkWpk[10][10][0])+(Cik[10][2][1]*
          IkWpk[10][10][1]))))+((mk[7]*((Vpk[5][11][2]*Vpk[10][11][2])+((
          Vpk[5][11][0]*Vpk[10][11][0])+(Vpk[5][11][1]*Vpk[10][11][1]))))+((
          IkWpk[10][11][2]*Wpk[5][11][2])+((IkWpk[10][11][0]*Wpk[5][11][0])+(
          IkWpk[10][11][1]*Wpk[5][11][1])))));
        temp[1] = (((mk[8]*((Vpk[5][12][2]*Vpk[10][12][2])+((Vpk[5][12][0]*
          Vpk[10][12][0])+(Vpk[5][12][1]*Vpk[10][12][1]))))+((IkWpk[10][12][2]*
          Wpk[5][12][2])+((IkWpk[10][12][0]*Wpk[5][12][0])+(IkWpk[10][12][1]*
          Wpk[5][12][1]))))+temp[0]);
        mm[5][10] = (((psmk[13]*((Vpk[5][13][2]*Vpk[10][13][2])+((Vpk[5][13][0]*
          Vpk[10][13][0])+(Vpk[5][13][1]*Vpk[10][13][1]))))+((IkWpk[10][13][2]*
          Wpk[5][13][2])+((IkWpk[10][13][0]*Wpk[5][13][0])+(IkWpk[10][13][1]*
          Wpk[5][13][1]))))+temp[1]);
        temp[0] = (((mk[7]*((Vpk[5][11][2]*Vpk[11][11][2])+((Vpk[5][11][0]*
          Vpk[11][11][0])+(Vpk[5][11][1]*Vpk[11][11][1]))))+((IkWpk[11][11][2]*
          Wpk[5][11][2])+((IkWpk[11][11][0]*Wpk[5][11][0])+(IkWpk[11][11][1]*
          Wpk[5][11][1]))))+((mk[8]*((Vpk[5][12][2]*Vpk[11][12][2])+((
          Vpk[5][12][0]*Vpk[11][12][0])+(Vpk[5][12][1]*Vpk[11][12][1]))))+((
          IkWpk[11][12][2]*Wpk[5][12][2])+((IkWpk[11][12][0]*Wpk[5][12][0])+(
          IkWpk[11][12][1]*Wpk[5][12][1])))));
        mm[5][11] = (((psmk[13]*((Vpk[5][13][2]*Vpk[11][13][2])+((Vpk[5][13][0]*
          Vpk[11][13][0])+(Vpk[5][13][1]*Vpk[11][13][1]))))+((IkWpk[11][13][2]*
          Wpk[5][13][2])+((IkWpk[11][13][0]*Wpk[5][13][0])+(IkWpk[11][13][1]*
          Wpk[5][13][1]))))+temp[0]);
        mm[5][12] = (((mk[8]*((Vpk[5][12][2]*Vpk[12][12][2])+((Vpk[5][12][0]*
          Vpk[12][12][0])+(Vpk[5][12][1]*Vpk[12][12][1]))))+((IkWpk[12][12][2]*
          Wpk[5][12][2])+((IkWpk[12][12][0]*Wpk[5][12][0])+(IkWpk[12][12][1]*
          Wpk[5][12][1]))))+((psmk[13]*((Vpk[5][13][2]*Vpk[12][13][2])+((
          Vpk[5][13][0]*Vpk[12][13][0])+(Vpk[5][13][1]*Vpk[12][13][1]))))+((
          IkWpk[12][13][2]*Wpk[5][13][2])+((IkWpk[12][13][0]*Wpk[5][13][0])+(
          IkWpk[12][13][1]*Wpk[5][13][1])))));
        mm[5][13] = ((psmk[13]*((Vpk[5][13][2]*Vpk[13][13][2])+((Vpk[5][13][0]*
          Vpk[13][13][0])+(Vpk[5][13][1]*Vpk[13][13][1]))))+((IkWpk[13][13][2]*
          Wpk[5][13][2])+((IkWpk[13][13][0]*Wpk[5][13][0])+(IkWpk[13][13][1]*
          Wpk[5][13][1]))));
        temp[0] = (((mk[11]*((Vpk[5][14][2]*Vpk[14][14][2])+((Vpk[5][14][0]*
          Vpk[14][14][0])+(Vpk[5][14][1]*Vpk[14][14][1]))))+((Cik[14][2][2]*
          IkWpk[14][14][2])+((Cik[14][2][0]*IkWpk[14][14][0])+(Cik[14][2][1]*
          IkWpk[14][14][1]))))+((mk[12]*((Vpk[5][15][2]*Vpk[14][15][2])+((
          Vpk[5][15][0]*Vpk[14][15][0])+(Vpk[5][15][1]*Vpk[14][15][1]))))+((
          IkWpk[14][15][2]*Wpk[5][15][2])+((IkWpk[14][15][0]*Wpk[5][15][0])+(
          IkWpk[14][15][1]*Wpk[5][15][1])))));
        temp[1] = (((mk[13]*((Vpk[5][16][2]*Vpk[14][16][2])+((Vpk[5][16][0]*
          Vpk[14][16][0])+(Vpk[5][16][1]*Vpk[14][16][1]))))+((IkWpk[14][16][2]*
          Wpk[5][16][2])+((IkWpk[14][16][0]*Wpk[5][16][0])+(IkWpk[14][16][1]*
          Wpk[5][16][1]))))+temp[0]);
        mm[5][14] = (((psmk[17]*((Vpk[5][17][2]*Vpk[14][17][2])+((Vpk[5][17][0]*
          Vpk[14][17][0])+(Vpk[5][17][1]*Vpk[14][17][1]))))+((IkWpk[14][17][2]*
          Wpk[5][17][2])+((IkWpk[14][17][0]*Wpk[5][17][0])+(IkWpk[14][17][1]*
          Wpk[5][17][1]))))+temp[1]);
        temp[0] = (((mk[12]*((Vpk[5][15][2]*Vpk[15][15][2])+((Vpk[5][15][0]*
          Vpk[15][15][0])+(Vpk[5][15][1]*Vpk[15][15][1]))))+((IkWpk[15][15][2]*
          Wpk[5][15][2])+((IkWpk[15][15][0]*Wpk[5][15][0])+(IkWpk[15][15][1]*
          Wpk[5][15][1]))))+((mk[13]*((Vpk[5][16][2]*Vpk[15][16][2])+((
          Vpk[5][16][0]*Vpk[15][16][0])+(Vpk[5][16][1]*Vpk[15][16][1]))))+((
          IkWpk[15][16][2]*Wpk[5][16][2])+((IkWpk[15][16][0]*Wpk[5][16][0])+(
          IkWpk[15][16][1]*Wpk[5][16][1])))));
        mm[5][15] = (((psmk[17]*((Vpk[5][17][2]*Vpk[15][17][2])+((Vpk[5][17][0]*
          Vpk[15][17][0])+(Vpk[5][17][1]*Vpk[15][17][1]))))+((IkWpk[15][17][2]*
          Wpk[5][17][2])+((IkWpk[15][17][0]*Wpk[5][17][0])+(IkWpk[15][17][1]*
          Wpk[5][17][1]))))+temp[0]);
        mm[5][16] = (((mk[13]*((Vpk[5][16][2]*Vpk[16][16][2])+((Vpk[5][16][0]*
          Vpk[16][16][0])+(Vpk[5][16][1]*Vpk[16][16][1]))))+((IkWpk[16][16][2]*
          Wpk[5][16][2])+((IkWpk[16][16][0]*Wpk[5][16][0])+(IkWpk[16][16][1]*
          Wpk[5][16][1]))))+((psmk[17]*((Vpk[5][17][2]*Vpk[16][17][2])+((
          Vpk[5][17][0]*Vpk[16][17][0])+(Vpk[5][17][1]*Vpk[16][17][1]))))+((
          IkWpk[16][17][2]*Wpk[5][17][2])+((IkWpk[16][17][0]*Wpk[5][17][0])+(
          IkWpk[16][17][1]*Wpk[5][17][1])))));
        mm[5][17] = ((psmk[17]*((Vpk[5][17][2]*Vpk[17][17][2])+((Vpk[5][17][0]*
          Vpk[17][17][0])+(Vpk[5][17][1]*Vpk[17][17][1]))))+((IkWpk[17][17][2]*
          Wpk[5][17][2])+((IkWpk[17][17][0]*Wpk[5][17][0])+(IkWpk[17][17][1]*
          Wpk[5][17][1]))));
        temp[0] = (((mk[16]*((Vpk[5][18][2]*Vpk[18][18][2])+((Vpk[5][18][0]*
          Vpk[18][18][0])+(Vpk[5][18][1]*Vpk[18][18][1]))))+((Cik[18][2][2]*
          IkWpk[18][18][2])+((Cik[18][2][0]*IkWpk[18][18][0])+(Cik[18][2][1]*
          IkWpk[18][18][1]))))+((mk[17]*((Vpk[5][19][2]*Vpk[18][19][2])+((
          Vpk[5][19][0]*Vpk[18][19][0])+(Vpk[5][19][1]*Vpk[18][19][1]))))+((
          IkWpk[18][19][2]*Wpk[5][19][2])+((IkWpk[18][19][0]*Wpk[5][19][0])+(
          IkWpk[18][19][1]*Wpk[5][19][1])))));
        temp[1] = (((mk[18]*((Vpk[5][20][2]*Vpk[18][20][2])+((Vpk[5][20][0]*
          Vpk[18][20][0])+(Vpk[5][20][1]*Vpk[18][20][1]))))+((IkWpk[18][20][2]*
          Wpk[5][20][2])+((IkWpk[18][20][0]*Wpk[5][20][0])+(IkWpk[18][20][1]*
          Wpk[5][20][1]))))+temp[0]);
        mm[5][18] = (((psmk[21]*((Vpk[5][21][2]*Vpk[18][21][2])+((Vpk[5][21][0]*
          Vpk[18][21][0])+(Vpk[5][21][1]*Vpk[18][21][1]))))+((IkWpk[18][21][2]*
          Wpk[5][21][2])+((IkWpk[18][21][0]*Wpk[5][21][0])+(IkWpk[18][21][1]*
          Wpk[5][21][1]))))+temp[1]);
        temp[0] = (((mk[17]*((Vpk[5][19][2]*Vpk[19][19][2])+((Vpk[5][19][0]*
          Vpk[19][19][0])+(Vpk[5][19][1]*Vpk[19][19][1]))))+((IkWpk[19][19][2]*
          Wpk[5][19][2])+((IkWpk[19][19][0]*Wpk[5][19][0])+(IkWpk[19][19][1]*
          Wpk[5][19][1]))))+((mk[18]*((Vpk[5][20][2]*Vpk[19][20][2])+((
          Vpk[5][20][0]*Vpk[19][20][0])+(Vpk[5][20][1]*Vpk[19][20][1]))))+((
          IkWpk[19][20][2]*Wpk[5][20][2])+((IkWpk[19][20][0]*Wpk[5][20][0])+(
          IkWpk[19][20][1]*Wpk[5][20][1])))));
        mm[5][19] = (((psmk[21]*((Vpk[5][21][2]*Vpk[19][21][2])+((Vpk[5][21][0]*
          Vpk[19][21][0])+(Vpk[5][21][1]*Vpk[19][21][1]))))+((IkWpk[19][21][2]*
          Wpk[5][21][2])+((IkWpk[19][21][0]*Wpk[5][21][0])+(IkWpk[19][21][1]*
          Wpk[5][21][1]))))+temp[0]);
        mm[5][20] = (((mk[18]*((Vpk[5][20][2]*Vpk[20][20][2])+((Vpk[5][20][0]*
          Vpk[20][20][0])+(Vpk[5][20][1]*Vpk[20][20][1]))))+((IkWpk[20][20][2]*
          Wpk[5][20][2])+((IkWpk[20][20][0]*Wpk[5][20][0])+(IkWpk[20][20][1]*
          Wpk[5][20][1]))))+((psmk[21]*((Vpk[5][21][2]*Vpk[20][21][2])+((
          Vpk[5][21][0]*Vpk[20][21][0])+(Vpk[5][21][1]*Vpk[20][21][1]))))+((
          IkWpk[20][21][2]*Wpk[5][21][2])+((IkWpk[20][21][0]*Wpk[5][21][0])+(
          IkWpk[20][21][1]*Wpk[5][21][1])))));
        mm[5][21] = ((psmk[21]*((Vpk[5][21][2]*Vpk[21][21][2])+((Vpk[5][21][0]*
          Vpk[21][21][0])+(Vpk[5][21][1]*Vpk[21][21][1]))))+((IkWpk[21][21][2]*
          Wpk[5][21][2])+((IkWpk[21][21][0]*Wpk[5][21][0])+(IkWpk[21][21][1]*
          Wpk[5][21][1]))));
        temp[0] = (((mk[1]*((Vpk[6][6][2]*Vpk[6][6][2])+((Vpk[6][6][0]*
          Vpk[6][6][0])+(Vpk[6][6][1]*Vpk[6][6][1]))))+((IkWpk[6][6][2]*
          pin[6][2])+((IkWpk[6][6][0]*pin[6][0])+(IkWpk[6][6][1]*pin[6][1]))))+(
          (mk[2]*((Vpk[6][7][2]*Vpk[6][7][2])+((Vpk[6][7][0]*Vpk[6][7][0])+(
          Vpk[6][7][1]*Vpk[6][7][1]))))+((IkWpk[6][7][2]*Wpk[6][7][2])+((
          IkWpk[6][7][0]*Wpk[6][7][0])+(IkWpk[6][7][1]*Wpk[6][7][1])))));
        temp[1] = (((mk[3]*((Vpk[6][8][2]*Vpk[6][8][2])+((Vpk[6][8][0]*
          Vpk[6][8][0])+(Vpk[6][8][1]*Vpk[6][8][1]))))+((IkWpk[6][8][2]*
          Wpk[6][8][2])+((IkWpk[6][8][0]*Wpk[6][8][0])+(IkWpk[6][8][1]*
          Wpk[6][8][1]))))+temp[0]);
        mm[6][6] = (((psmk[9]*((Vpk[6][9][2]*Vpk[6][9][2])+((Vpk[6][9][0]*
          Vpk[6][9][0])+(Vpk[6][9][1]*Vpk[6][9][1]))))+((IkWpk[6][9][2]*
          Wpk[6][9][2])+((IkWpk[6][9][0]*Wpk[6][9][0])+(IkWpk[6][9][1]*
          Wpk[6][9][1]))))+temp[1]);
        temp[0] = (((mk[2]*((Vpk[6][7][2]*Vpk[7][7][2])+((Vpk[6][7][0]*
          Vpk[7][7][0])+(Vpk[6][7][1]*Vpk[7][7][1]))))+((IkWpk[7][7][2]*
          Wpk[6][7][2])+((IkWpk[7][7][0]*Wpk[6][7][0])+(IkWpk[7][7][1]*
          Wpk[6][7][1]))))+((mk[3]*((Vpk[6][8][2]*Vpk[7][8][2])+((Vpk[6][8][0]*
          Vpk[7][8][0])+(Vpk[6][8][1]*Vpk[7][8][1]))))+((IkWpk[7][8][2]*
          Wpk[6][8][2])+((IkWpk[7][8][0]*Wpk[6][8][0])+(IkWpk[7][8][1]*
          Wpk[6][8][1])))));
        mm[6][7] = (((psmk[9]*((Vpk[6][9][2]*Vpk[7][9][2])+((Vpk[6][9][0]*
          Vpk[7][9][0])+(Vpk[6][9][1]*Vpk[7][9][1]))))+((IkWpk[7][9][2]*
          Wpk[6][9][2])+((IkWpk[7][9][0]*Wpk[6][9][0])+(IkWpk[7][9][1]*
          Wpk[6][9][1]))))+temp[0]);
        mm[6][8] = (((mk[3]*((Vpk[6][8][2]*Vpk[8][8][2])+((Vpk[6][8][0]*
          Vpk[8][8][0])+(Vpk[6][8][1]*Vpk[8][8][1]))))+((IkWpk[8][8][2]*
          Wpk[6][8][2])+((IkWpk[8][8][0]*Wpk[6][8][0])+(IkWpk[8][8][1]*
          Wpk[6][8][1]))))+((psmk[9]*((Vpk[6][9][2]*Vpk[8][9][2])+((Vpk[6][9][0]
          *Vpk[8][9][0])+(Vpk[6][9][1]*Vpk[8][9][1]))))+((IkWpk[8][9][2]*
          Wpk[6][9][2])+((IkWpk[8][9][0]*Wpk[6][9][0])+(IkWpk[8][9][1]*
          Wpk[6][9][1])))));
        mm[6][9] = ((psmk[9]*((Vpk[6][9][2]*Vpk[9][9][2])+((Vpk[6][9][0]*
          Vpk[9][9][0])+(Vpk[6][9][1]*Vpk[9][9][1]))))+((IkWpk[9][9][2]*
          Wpk[6][9][2])+((IkWpk[9][9][0]*Wpk[6][9][0])+(IkWpk[9][9][1]*
          Wpk[6][9][1]))));
        mm[6][10] = 0.;
        mm[6][11] = 0.;
        mm[6][12] = 0.;
        mm[6][13] = 0.;
        mm[6][14] = 0.;
        mm[6][15] = 0.;
        mm[6][16] = 0.;
        mm[6][17] = 0.;
        mm[6][18] = 0.;
        mm[6][19] = 0.;
        mm[6][20] = 0.;
        mm[6][21] = 0.;
        temp[0] = (((mk[2]*((Vpk[7][7][2]*Vpk[7][7][2])+((Vpk[7][7][0]*
          Vpk[7][7][0])+(Vpk[7][7][1]*Vpk[7][7][1]))))+((IkWpk[7][7][2]*
          pin[7][2])+((IkWpk[7][7][0]*pin[7][0])+(IkWpk[7][7][1]*pin[7][1]))))+(
          (mk[3]*((Vpk[7][8][2]*Vpk[7][8][2])+((Vpk[7][8][0]*Vpk[7][8][0])+(
          Vpk[7][8][1]*Vpk[7][8][1]))))+((IkWpk[7][8][2]*Wpk[7][8][2])+((
          IkWpk[7][8][0]*Wpk[7][8][0])+(IkWpk[7][8][1]*Wpk[7][8][1])))));
        mm[7][7] = (((psmk[9]*((Vpk[7][9][2]*Vpk[7][9][2])+((Vpk[7][9][0]*
          Vpk[7][9][0])+(Vpk[7][9][1]*Vpk[7][9][1]))))+((IkWpk[7][9][2]*
          Wpk[7][9][2])+((IkWpk[7][9][0]*Wpk[7][9][0])+(IkWpk[7][9][1]*
          Wpk[7][9][1]))))+temp[0]);
        mm[7][8] = (((mk[3]*((Vpk[7][8][2]*Vpk[8][8][2])+((Vpk[7][8][0]*
          Vpk[8][8][0])+(Vpk[7][8][1]*Vpk[8][8][1]))))+((IkWpk[8][8][2]*
          Wpk[7][8][2])+((IkWpk[8][8][0]*Wpk[7][8][0])+(IkWpk[8][8][1]*
          Wpk[7][8][1]))))+((psmk[9]*((Vpk[7][9][2]*Vpk[8][9][2])+((Vpk[7][9][0]
          *Vpk[8][9][0])+(Vpk[7][9][1]*Vpk[8][9][1]))))+((IkWpk[8][9][2]*
          Wpk[7][9][2])+((IkWpk[8][9][0]*Wpk[7][9][0])+(IkWpk[8][9][1]*
          Wpk[7][9][1])))));
        mm[7][9] = ((psmk[9]*((Vpk[7][9][2]*Vpk[9][9][2])+((Vpk[7][9][0]*
          Vpk[9][9][0])+(Vpk[7][9][1]*Vpk[9][9][1]))))+((IkWpk[9][9][2]*
          Wpk[7][9][2])+((IkWpk[9][9][0]*Wpk[7][9][0])+(IkWpk[9][9][1]*
          Wpk[7][9][1]))));
        mm[7][10] = 0.;
        mm[7][11] = 0.;
        mm[7][12] = 0.;
        mm[7][13] = 0.;
        mm[7][14] = 0.;
        mm[7][15] = 0.;
        mm[7][16] = 0.;
        mm[7][17] = 0.;
        mm[7][18] = 0.;
        mm[7][19] = 0.;
        mm[7][20] = 0.;
        mm[7][21] = 0.;
        mm[8][8] = (((mk[3]*((Vpk[8][8][2]*Vpk[8][8][2])+((Vpk[8][8][0]*
          Vpk[8][8][0])+(Vpk[8][8][1]*Vpk[8][8][1]))))+((IkWpk[8][8][2]*
          pin[8][2])+((IkWpk[8][8][0]*pin[8][0])+(IkWpk[8][8][1]*pin[8][1]))))+(
          (psmk[9]*((Vpk[8][9][2]*Vpk[8][9][2])+((Vpk[8][9][0]*Vpk[8][9][0])+(
          Vpk[8][9][1]*Vpk[8][9][1]))))+((IkWpk[8][9][2]*Wpk[8][9][2])+((
          IkWpk[8][9][0]*Wpk[8][9][0])+(IkWpk[8][9][1]*Wpk[8][9][1])))));
        mm[8][9] = ((psmk[9]*((Vpk[8][9][2]*Vpk[9][9][2])+((Vpk[8][9][0]*
          Vpk[9][9][0])+(Vpk[8][9][1]*Vpk[9][9][1]))))+((IkWpk[9][9][2]*
          Wpk[8][9][2])+((IkWpk[9][9][0]*Wpk[8][9][0])+(IkWpk[9][9][1]*
          Wpk[8][9][1]))));
        mm[8][10] = 0.;
        mm[8][11] = 0.;
        mm[8][12] = 0.;
        mm[8][13] = 0.;
        mm[8][14] = 0.;
        mm[8][15] = 0.;
        mm[8][16] = 0.;
        mm[8][17] = 0.;
        mm[8][18] = 0.;
        mm[8][19] = 0.;
        mm[8][20] = 0.;
        mm[8][21] = 0.;
        mm[9][9] = ((psmk[9]*((Vpk[9][9][2]*Vpk[9][9][2])+((Vpk[9][9][0]*
          Vpk[9][9][0])+(Vpk[9][9][1]*Vpk[9][9][1]))))+((IkWpk[9][9][2]*
          pin[9][2])+((IkWpk[9][9][0]*pin[9][0])+(IkWpk[9][9][1]*pin[9][1]))));
        mm[9][10] = 0.;
        mm[9][11] = 0.;
        mm[9][12] = 0.;
        mm[9][13] = 0.;
        mm[9][14] = 0.;
        mm[9][15] = 0.;
        mm[9][16] = 0.;
        mm[9][17] = 0.;
        mm[9][18] = 0.;
        mm[9][19] = 0.;
        mm[9][20] = 0.;
        mm[9][21] = 0.;
        temp[0] = (((mk[6]*((Vpk[10][10][2]*Vpk[10][10][2])+((Vpk[10][10][0]*
          Vpk[10][10][0])+(Vpk[10][10][1]*Vpk[10][10][1]))))+((IkWpk[10][10][2]*
          pin[10][2])+((IkWpk[10][10][0]*pin[10][0])+(IkWpk[10][10][1]*
          pin[10][1]))))+((mk[7]*((Vpk[10][11][2]*Vpk[10][11][2])+((
          Vpk[10][11][0]*Vpk[10][11][0])+(Vpk[10][11][1]*Vpk[10][11][1]))))+((
          IkWpk[10][11][2]*Wpk[10][11][2])+((IkWpk[10][11][0]*Wpk[10][11][0])+(
          IkWpk[10][11][1]*Wpk[10][11][1])))));
        temp[1] = (((mk[8]*((Vpk[10][12][2]*Vpk[10][12][2])+((Vpk[10][12][0]*
          Vpk[10][12][0])+(Vpk[10][12][1]*Vpk[10][12][1]))))+((IkWpk[10][12][2]*
          Wpk[10][12][2])+((IkWpk[10][12][0]*Wpk[10][12][0])+(IkWpk[10][12][1]*
          Wpk[10][12][1]))))+temp[0]);
        mm[10][10] = (((psmk[13]*((Vpk[10][13][2]*Vpk[10][13][2])+((
          Vpk[10][13][0]*Vpk[10][13][0])+(Vpk[10][13][1]*Vpk[10][13][1]))))+((
          IkWpk[10][13][2]*Wpk[10][13][2])+((IkWpk[10][13][0]*Wpk[10][13][0])+(
          IkWpk[10][13][1]*Wpk[10][13][1]))))+temp[1]);
        temp[0] = (((mk[7]*((Vpk[10][11][2]*Vpk[11][11][2])+((Vpk[10][11][0]*
          Vpk[11][11][0])+(Vpk[10][11][1]*Vpk[11][11][1]))))+((IkWpk[11][11][2]*
          Wpk[10][11][2])+((IkWpk[11][11][0]*Wpk[10][11][0])+(IkWpk[11][11][1]*
          Wpk[10][11][1]))))+((mk[8]*((Vpk[10][12][2]*Vpk[11][12][2])+((
          Vpk[10][12][0]*Vpk[11][12][0])+(Vpk[10][12][1]*Vpk[11][12][1]))))+((
          IkWpk[11][12][2]*Wpk[10][12][2])+((IkWpk[11][12][0]*Wpk[10][12][0])+(
          IkWpk[11][12][1]*Wpk[10][12][1])))));
        mm[10][11] = (((psmk[13]*((Vpk[10][13][2]*Vpk[11][13][2])+((
          Vpk[10][13][0]*Vpk[11][13][0])+(Vpk[10][13][1]*Vpk[11][13][1]))))+((
          IkWpk[11][13][2]*Wpk[10][13][2])+((IkWpk[11][13][0]*Wpk[10][13][0])+(
          IkWpk[11][13][1]*Wpk[10][13][1]))))+temp[0]);
        mm[10][12] = (((mk[8]*((Vpk[10][12][2]*Vpk[12][12][2])+((Vpk[10][12][0]*
          Vpk[12][12][0])+(Vpk[10][12][1]*Vpk[12][12][1]))))+((IkWpk[12][12][2]*
          Wpk[10][12][2])+((IkWpk[12][12][0]*Wpk[10][12][0])+(IkWpk[12][12][1]*
          Wpk[10][12][1]))))+((psmk[13]*((Vpk[10][13][2]*Vpk[12][13][2])+((
          Vpk[10][13][0]*Vpk[12][13][0])+(Vpk[10][13][1]*Vpk[12][13][1]))))+((
          IkWpk[12][13][2]*Wpk[10][13][2])+((IkWpk[12][13][0]*Wpk[10][13][0])+(
          IkWpk[12][13][1]*Wpk[10][13][1])))));
        mm[10][13] = ((psmk[13]*((Vpk[10][13][2]*Vpk[13][13][2])+((
          Vpk[10][13][0]*Vpk[13][13][0])+(Vpk[10][13][1]*Vpk[13][13][1]))))+((
          IkWpk[13][13][2]*Wpk[10][13][2])+((IkWpk[13][13][0]*Wpk[10][13][0])+(
          IkWpk[13][13][1]*Wpk[10][13][1]))));
        mm[10][14] = 0.;
        mm[10][15] = 0.;
        mm[10][16] = 0.;
        mm[10][17] = 0.;
        mm[10][18] = 0.;
        mm[10][19] = 0.;
        mm[10][20] = 0.;
        mm[10][21] = 0.;
        temp[0] = (((mk[7]*((Vpk[11][11][2]*Vpk[11][11][2])+((Vpk[11][11][0]*
          Vpk[11][11][0])+(Vpk[11][11][1]*Vpk[11][11][1]))))+((IkWpk[11][11][2]*
          pin[11][2])+((IkWpk[11][11][0]*pin[11][0])+(IkWpk[11][11][1]*
          pin[11][1]))))+((mk[8]*((Vpk[11][12][2]*Vpk[11][12][2])+((
          Vpk[11][12][0]*Vpk[11][12][0])+(Vpk[11][12][1]*Vpk[11][12][1]))))+((
          IkWpk[11][12][2]*Wpk[11][12][2])+((IkWpk[11][12][0]*Wpk[11][12][0])+(
          IkWpk[11][12][1]*Wpk[11][12][1])))));
        mm[11][11] = (((psmk[13]*((Vpk[11][13][2]*Vpk[11][13][2])+((
          Vpk[11][13][0]*Vpk[11][13][0])+(Vpk[11][13][1]*Vpk[11][13][1]))))+((
          IkWpk[11][13][2]*Wpk[11][13][2])+((IkWpk[11][13][0]*Wpk[11][13][0])+(
          IkWpk[11][13][1]*Wpk[11][13][1]))))+temp[0]);
        mm[11][12] = (((mk[8]*((Vpk[11][12][2]*Vpk[12][12][2])+((Vpk[11][12][0]*
          Vpk[12][12][0])+(Vpk[11][12][1]*Vpk[12][12][1]))))+((IkWpk[12][12][2]*
          Wpk[11][12][2])+((IkWpk[12][12][0]*Wpk[11][12][0])+(IkWpk[12][12][1]*
          Wpk[11][12][1]))))+((psmk[13]*((Vpk[11][13][2]*Vpk[12][13][2])+((
          Vpk[11][13][0]*Vpk[12][13][0])+(Vpk[11][13][1]*Vpk[12][13][1]))))+((
          IkWpk[12][13][2]*Wpk[11][13][2])+((IkWpk[12][13][0]*Wpk[11][13][0])+(
          IkWpk[12][13][1]*Wpk[11][13][1])))));
        mm[11][13] = ((psmk[13]*((Vpk[11][13][2]*Vpk[13][13][2])+((
          Vpk[11][13][0]*Vpk[13][13][0])+(Vpk[11][13][1]*Vpk[13][13][1]))))+((
          IkWpk[13][13][2]*Wpk[11][13][2])+((IkWpk[13][13][0]*Wpk[11][13][0])+(
          IkWpk[13][13][1]*Wpk[11][13][1]))));
        mm[11][14] = 0.;
        mm[11][15] = 0.;
        mm[11][16] = 0.;
        mm[11][17] = 0.;
        mm[11][18] = 0.;
        mm[11][19] = 0.;
        mm[11][20] = 0.;
        mm[11][21] = 0.;
        mm[12][12] = (((mk[8]*((Vpk[12][12][2]*Vpk[12][12][2])+((Vpk[12][12][0]*
          Vpk[12][12][0])+(Vpk[12][12][1]*Vpk[12][12][1]))))+((IkWpk[12][12][2]*
          pin[12][2])+((IkWpk[12][12][0]*pin[12][0])+(IkWpk[12][12][1]*
          pin[12][1]))))+((psmk[13]*((Vpk[12][13][2]*Vpk[12][13][2])+((
          Vpk[12][13][0]*Vpk[12][13][0])+(Vpk[12][13][1]*Vpk[12][13][1]))))+((
          IkWpk[12][13][2]*Wpk[12][13][2])+((IkWpk[12][13][0]*Wpk[12][13][0])+(
          IkWpk[12][13][1]*Wpk[12][13][1])))));
        mm[12][13] = ((psmk[13]*((Vpk[12][13][2]*Vpk[13][13][2])+((
          Vpk[12][13][0]*Vpk[13][13][0])+(Vpk[12][13][1]*Vpk[13][13][1]))))+((
          IkWpk[13][13][2]*Wpk[12][13][2])+((IkWpk[13][13][0]*Wpk[12][13][0])+(
          IkWpk[13][13][1]*Wpk[12][13][1]))));
        mm[12][14] = 0.;
        mm[12][15] = 0.;
        mm[12][16] = 0.;
        mm[12][17] = 0.;
        mm[12][18] = 0.;
        mm[12][19] = 0.;
        mm[12][20] = 0.;
        mm[12][21] = 0.;
        mm[13][13] = ((psmk[13]*((Vpk[13][13][2]*Vpk[13][13][2])+((
          Vpk[13][13][0]*Vpk[13][13][0])+(Vpk[13][13][1]*Vpk[13][13][1]))))+((
          IkWpk[13][13][2]*pin[13][2])+((IkWpk[13][13][0]*pin[13][0])+(
          IkWpk[13][13][1]*pin[13][1]))));
        mm[13][14] = 0.;
        mm[13][15] = 0.;
        mm[13][16] = 0.;
        mm[13][17] = 0.;
        mm[13][18] = 0.;
        mm[13][19] = 0.;
        mm[13][20] = 0.;
        mm[13][21] = 0.;
        temp[0] = (((mk[11]*((Vpk[14][14][2]*Vpk[14][14][2])+((Vpk[14][14][0]*
          Vpk[14][14][0])+(Vpk[14][14][1]*Vpk[14][14][1]))))+((IkWpk[14][14][2]*
          pin[14][2])+((IkWpk[14][14][0]*pin[14][0])+(IkWpk[14][14][1]*
          pin[14][1]))))+((mk[12]*((Vpk[14][15][2]*Vpk[14][15][2])+((
          Vpk[14][15][0]*Vpk[14][15][0])+(Vpk[14][15][1]*Vpk[14][15][1]))))+((
          IkWpk[14][15][2]*Wpk[14][15][2])+((IkWpk[14][15][0]*Wpk[14][15][0])+(
          IkWpk[14][15][1]*Wpk[14][15][1])))));
        temp[1] = (((mk[13]*((Vpk[14][16][2]*Vpk[14][16][2])+((Vpk[14][16][0]*
          Vpk[14][16][0])+(Vpk[14][16][1]*Vpk[14][16][1]))))+((IkWpk[14][16][2]*
          Wpk[14][16][2])+((IkWpk[14][16][0]*Wpk[14][16][0])+(IkWpk[14][16][1]*
          Wpk[14][16][1]))))+temp[0]);
        mm[14][14] = (((psmk[17]*((Vpk[14][17][2]*Vpk[14][17][2])+((
          Vpk[14][17][0]*Vpk[14][17][0])+(Vpk[14][17][1]*Vpk[14][17][1]))))+((
          IkWpk[14][17][2]*Wpk[14][17][2])+((IkWpk[14][17][0]*Wpk[14][17][0])+(
          IkWpk[14][17][1]*Wpk[14][17][1]))))+temp[1]);
        temp[0] = (((mk[12]*((Vpk[14][15][2]*Vpk[15][15][2])+((Vpk[14][15][0]*
          Vpk[15][15][0])+(Vpk[14][15][1]*Vpk[15][15][1]))))+((IkWpk[15][15][2]*
          Wpk[14][15][2])+((IkWpk[15][15][0]*Wpk[14][15][0])+(IkWpk[15][15][1]*
          Wpk[14][15][1]))))+((mk[13]*((Vpk[14][16][2]*Vpk[15][16][2])+((
          Vpk[14][16][0]*Vpk[15][16][0])+(Vpk[14][16][1]*Vpk[15][16][1]))))+((
          IkWpk[15][16][2]*Wpk[14][16][2])+((IkWpk[15][16][0]*Wpk[14][16][0])+(
          IkWpk[15][16][1]*Wpk[14][16][1])))));
        mm[14][15] = (((psmk[17]*((Vpk[14][17][2]*Vpk[15][17][2])+((
          Vpk[14][17][0]*Vpk[15][17][0])+(Vpk[14][17][1]*Vpk[15][17][1]))))+((
          IkWpk[15][17][2]*Wpk[14][17][2])+((IkWpk[15][17][0]*Wpk[14][17][0])+(
          IkWpk[15][17][1]*Wpk[14][17][1]))))+temp[0]);
        mm[14][16] = (((mk[13]*((Vpk[14][16][2]*Vpk[16][16][2])+((Vpk[14][16][0]
          *Vpk[16][16][0])+(Vpk[14][16][1]*Vpk[16][16][1]))))+((IkWpk[16][16][2]
          *Wpk[14][16][2])+((IkWpk[16][16][0]*Wpk[14][16][0])+(IkWpk[16][16][1]*
          Wpk[14][16][1]))))+((psmk[17]*((Vpk[14][17][2]*Vpk[16][17][2])+((
          Vpk[14][17][0]*Vpk[16][17][0])+(Vpk[14][17][1]*Vpk[16][17][1]))))+((
          IkWpk[16][17][2]*Wpk[14][17][2])+((IkWpk[16][17][0]*Wpk[14][17][0])+(
          IkWpk[16][17][1]*Wpk[14][17][1])))));
        mm[14][17] = ((psmk[17]*((Vpk[14][17][2]*Vpk[17][17][2])+((
          Vpk[14][17][0]*Vpk[17][17][0])+(Vpk[14][17][1]*Vpk[17][17][1]))))+((
          IkWpk[17][17][2]*Wpk[14][17][2])+((IkWpk[17][17][0]*Wpk[14][17][0])+(
          IkWpk[17][17][1]*Wpk[14][17][1]))));
        mm[14][18] = 0.;
        mm[14][19] = 0.;
        mm[14][20] = 0.;
        mm[14][21] = 0.;
        temp[0] = (((mk[12]*((Vpk[15][15][2]*Vpk[15][15][2])+((Vpk[15][15][0]*
          Vpk[15][15][0])+(Vpk[15][15][1]*Vpk[15][15][1]))))+((IkWpk[15][15][2]*
          pin[15][2])+((IkWpk[15][15][0]*pin[15][0])+(IkWpk[15][15][1]*
          pin[15][1]))))+((mk[13]*((Vpk[15][16][2]*Vpk[15][16][2])+((
          Vpk[15][16][0]*Vpk[15][16][0])+(Vpk[15][16][1]*Vpk[15][16][1]))))+((
          IkWpk[15][16][2]*Wpk[15][16][2])+((IkWpk[15][16][0]*Wpk[15][16][0])+(
          IkWpk[15][16][1]*Wpk[15][16][1])))));
        mm[15][15] = (((psmk[17]*((Vpk[15][17][2]*Vpk[15][17][2])+((
          Vpk[15][17][0]*Vpk[15][17][0])+(Vpk[15][17][1]*Vpk[15][17][1]))))+((
          IkWpk[15][17][2]*Wpk[15][17][2])+((IkWpk[15][17][0]*Wpk[15][17][0])+(
          IkWpk[15][17][1]*Wpk[15][17][1]))))+temp[0]);
        mm[15][16] = (((mk[13]*((Vpk[15][16][2]*Vpk[16][16][2])+((Vpk[15][16][0]
          *Vpk[16][16][0])+(Vpk[15][16][1]*Vpk[16][16][1]))))+((IkWpk[16][16][2]
          *Wpk[15][16][2])+((IkWpk[16][16][0]*Wpk[15][16][0])+(IkWpk[16][16][1]*
          Wpk[15][16][1]))))+((psmk[17]*((Vpk[15][17][2]*Vpk[16][17][2])+((
          Vpk[15][17][0]*Vpk[16][17][0])+(Vpk[15][17][1]*Vpk[16][17][1]))))+((
          IkWpk[16][17][2]*Wpk[15][17][2])+((IkWpk[16][17][0]*Wpk[15][17][0])+(
          IkWpk[16][17][1]*Wpk[15][17][1])))));
        mm[15][17] = ((psmk[17]*((Vpk[15][17][2]*Vpk[17][17][2])+((
          Vpk[15][17][0]*Vpk[17][17][0])+(Vpk[15][17][1]*Vpk[17][17][1]))))+((
          IkWpk[17][17][2]*Wpk[15][17][2])+((IkWpk[17][17][0]*Wpk[15][17][0])+(
          IkWpk[17][17][1]*Wpk[15][17][1]))));
        mm[15][18] = 0.;
        mm[15][19] = 0.;
        mm[15][20] = 0.;
        mm[15][21] = 0.;
        mm[16][16] = (((mk[13]*((Vpk[16][16][2]*Vpk[16][16][2])+((Vpk[16][16][0]
          *Vpk[16][16][0])+(Vpk[16][16][1]*Vpk[16][16][1]))))+((IkWpk[16][16][2]
          *pin[16][2])+((IkWpk[16][16][0]*pin[16][0])+(IkWpk[16][16][1]*
          pin[16][1]))))+((psmk[17]*((Vpk[16][17][2]*Vpk[16][17][2])+((
          Vpk[16][17][0]*Vpk[16][17][0])+(Vpk[16][17][1]*Vpk[16][17][1]))))+((
          IkWpk[16][17][2]*Wpk[16][17][2])+((IkWpk[16][17][0]*Wpk[16][17][0])+(
          IkWpk[16][17][1]*Wpk[16][17][1])))));
        mm[16][17] = ((psmk[17]*((Vpk[16][17][2]*Vpk[17][17][2])+((
          Vpk[16][17][0]*Vpk[17][17][0])+(Vpk[16][17][1]*Vpk[17][17][1]))))+((
          IkWpk[17][17][2]*Wpk[16][17][2])+((IkWpk[17][17][0]*Wpk[16][17][0])+(
          IkWpk[17][17][1]*Wpk[16][17][1]))));
        mm[16][18] = 0.;
        mm[16][19] = 0.;
        mm[16][20] = 0.;
        mm[16][21] = 0.;
        mm[17][17] = ((psmk[17]*((Vpk[17][17][2]*Vpk[17][17][2])+((
          Vpk[17][17][0]*Vpk[17][17][0])+(Vpk[17][17][1]*Vpk[17][17][1]))))+((
          IkWpk[17][17][2]*pin[17][2])+((IkWpk[17][17][0]*pin[17][0])+(
          IkWpk[17][17][1]*pin[17][1]))));
        mm[17][18] = 0.;
        mm[17][19] = 0.;
        mm[17][20] = 0.;
        mm[17][21] = 0.;
        temp[0] = (((mk[16]*((Vpk[18][18][2]*Vpk[18][18][2])+((Vpk[18][18][0]*
          Vpk[18][18][0])+(Vpk[18][18][1]*Vpk[18][18][1]))))+((IkWpk[18][18][2]*
          pin[18][2])+((IkWpk[18][18][0]*pin[18][0])+(IkWpk[18][18][1]*
          pin[18][1]))))+((mk[17]*((Vpk[18][19][2]*Vpk[18][19][2])+((
          Vpk[18][19][0]*Vpk[18][19][0])+(Vpk[18][19][1]*Vpk[18][19][1]))))+((
          IkWpk[18][19][2]*Wpk[18][19][2])+((IkWpk[18][19][0]*Wpk[18][19][0])+(
          IkWpk[18][19][1]*Wpk[18][19][1])))));
        temp[1] = (((mk[18]*((Vpk[18][20][2]*Vpk[18][20][2])+((Vpk[18][20][0]*
          Vpk[18][20][0])+(Vpk[18][20][1]*Vpk[18][20][1]))))+((IkWpk[18][20][2]*
          Wpk[18][20][2])+((IkWpk[18][20][0]*Wpk[18][20][0])+(IkWpk[18][20][1]*
          Wpk[18][20][1]))))+temp[0]);
        mm[18][18] = (((psmk[21]*((Vpk[18][21][2]*Vpk[18][21][2])+((
          Vpk[18][21][0]*Vpk[18][21][0])+(Vpk[18][21][1]*Vpk[18][21][1]))))+((
          IkWpk[18][21][2]*Wpk[18][21][2])+((IkWpk[18][21][0]*Wpk[18][21][0])+(
          IkWpk[18][21][1]*Wpk[18][21][1]))))+temp[1]);
        temp[0] = (((mk[17]*((Vpk[18][19][2]*Vpk[19][19][2])+((Vpk[18][19][0]*
          Vpk[19][19][0])+(Vpk[18][19][1]*Vpk[19][19][1]))))+((IkWpk[19][19][2]*
          Wpk[18][19][2])+((IkWpk[19][19][0]*Wpk[18][19][0])+(IkWpk[19][19][1]*
          Wpk[18][19][1]))))+((mk[18]*((Vpk[18][20][2]*Vpk[19][20][2])+((
          Vpk[18][20][0]*Vpk[19][20][0])+(Vpk[18][20][1]*Vpk[19][20][1]))))+((
          IkWpk[19][20][2]*Wpk[18][20][2])+((IkWpk[19][20][0]*Wpk[18][20][0])+(
          IkWpk[19][20][1]*Wpk[18][20][1])))));
        mm[18][19] = (((psmk[21]*((Vpk[18][21][2]*Vpk[19][21][2])+((
          Vpk[18][21][0]*Vpk[19][21][0])+(Vpk[18][21][1]*Vpk[19][21][1]))))+((
          IkWpk[19][21][2]*Wpk[18][21][2])+((IkWpk[19][21][0]*Wpk[18][21][0])+(
          IkWpk[19][21][1]*Wpk[18][21][1]))))+temp[0]);
        mm[18][20] = (((mk[18]*((Vpk[18][20][2]*Vpk[20][20][2])+((Vpk[18][20][0]
          *Vpk[20][20][0])+(Vpk[18][20][1]*Vpk[20][20][1]))))+((IkWpk[20][20][2]
          *Wpk[18][20][2])+((IkWpk[20][20][0]*Wpk[18][20][0])+(IkWpk[20][20][1]*
          Wpk[18][20][1]))))+((psmk[21]*((Vpk[18][21][2]*Vpk[20][21][2])+((
          Vpk[18][21][0]*Vpk[20][21][0])+(Vpk[18][21][1]*Vpk[20][21][1]))))+((
          IkWpk[20][21][2]*Wpk[18][21][2])+((IkWpk[20][21][0]*Wpk[18][21][0])+(
          IkWpk[20][21][1]*Wpk[18][21][1])))));
        mm[18][21] = ((psmk[21]*((Vpk[18][21][2]*Vpk[21][21][2])+((
          Vpk[18][21][0]*Vpk[21][21][0])+(Vpk[18][21][1]*Vpk[21][21][1]))))+((
          IkWpk[21][21][2]*Wpk[18][21][2])+((IkWpk[21][21][0]*Wpk[18][21][0])+(
          IkWpk[21][21][1]*Wpk[18][21][1]))));
        temp[0] = (((mk[17]*((Vpk[19][19][2]*Vpk[19][19][2])+((Vpk[19][19][0]*
          Vpk[19][19][0])+(Vpk[19][19][1]*Vpk[19][19][1]))))+((IkWpk[19][19][2]*
          pin[19][2])+((IkWpk[19][19][0]*pin[19][0])+(IkWpk[19][19][1]*
          pin[19][1]))))+((mk[18]*((Vpk[19][20][2]*Vpk[19][20][2])+((
          Vpk[19][20][0]*Vpk[19][20][0])+(Vpk[19][20][1]*Vpk[19][20][1]))))+((
          IkWpk[19][20][2]*Wpk[19][20][2])+((IkWpk[19][20][0]*Wpk[19][20][0])+(
          IkWpk[19][20][1]*Wpk[19][20][1])))));
        mm[19][19] = (((psmk[21]*((Vpk[19][21][2]*Vpk[19][21][2])+((
          Vpk[19][21][0]*Vpk[19][21][0])+(Vpk[19][21][1]*Vpk[19][21][1]))))+((
          IkWpk[19][21][2]*Wpk[19][21][2])+((IkWpk[19][21][0]*Wpk[19][21][0])+(
          IkWpk[19][21][1]*Wpk[19][21][1]))))+temp[0]);
        mm[19][20] = (((mk[18]*((Vpk[19][20][2]*Vpk[20][20][2])+((Vpk[19][20][0]
          *Vpk[20][20][0])+(Vpk[19][20][1]*Vpk[20][20][1]))))+((IkWpk[20][20][2]
          *Wpk[19][20][2])+((IkWpk[20][20][0]*Wpk[19][20][0])+(IkWpk[20][20][1]*
          Wpk[19][20][1]))))+((psmk[21]*((Vpk[19][21][2]*Vpk[20][21][2])+((
          Vpk[19][21][0]*Vpk[20][21][0])+(Vpk[19][21][1]*Vpk[20][21][1]))))+((
          IkWpk[20][21][2]*Wpk[19][21][2])+((IkWpk[20][21][0]*Wpk[19][21][0])+(
          IkWpk[20][21][1]*Wpk[19][21][1])))));
        mm[19][21] = ((psmk[21]*((Vpk[19][21][2]*Vpk[21][21][2])+((
          Vpk[19][21][0]*Vpk[21][21][0])+(Vpk[19][21][1]*Vpk[21][21][1]))))+((
          IkWpk[21][21][2]*Wpk[19][21][2])+((IkWpk[21][21][0]*Wpk[19][21][0])+(
          IkWpk[21][21][1]*Wpk[19][21][1]))));
        mm[20][20] = (((mk[18]*((Vpk[20][20][2]*Vpk[20][20][2])+((Vpk[20][20][0]
          *Vpk[20][20][0])+(Vpk[20][20][1]*Vpk[20][20][1]))))+((IkWpk[20][20][2]
          *pin[20][2])+((IkWpk[20][20][0]*pin[20][0])+(IkWpk[20][20][1]*
          pin[20][1]))))+((psmk[21]*((Vpk[20][21][2]*Vpk[20][21][2])+((
          Vpk[20][21][0]*Vpk[20][21][0])+(Vpk[20][21][1]*Vpk[20][21][1]))))+((
          IkWpk[20][21][2]*Wpk[20][21][2])+((IkWpk[20][21][0]*Wpk[20][21][0])+(
          IkWpk[20][21][1]*Wpk[20][21][1])))));
        mm[20][21] = ((psmk[21]*((Vpk[20][21][2]*Vpk[21][21][2])+((
          Vpk[20][21][0]*Vpk[21][21][0])+(Vpk[20][21][1]*Vpk[21][21][1]))))+((
          IkWpk[21][21][2]*Wpk[20][21][2])+((IkWpk[21][21][0]*Wpk[20][21][0])+(
          IkWpk[21][21][1]*Wpk[20][21][1]))));
        mm[21][21] = ((psmk[21]*((Vpk[21][21][2]*Vpk[21][21][2])+((
          Vpk[21][21][0]*Vpk[21][21][0])+(Vpk[21][21][1]*Vpk[21][21][1]))))+((
          IkWpk[21][21][2]*pin[21][2])+((IkWpk[21][21][0]*pin[21][0])+(
          IkWpk[21][21][1]*pin[21][1]))));
/*
Check for singular mass matrix
*/
        for (i = 0; i < 22; i++) {
            if (mm[i][i] < 1e-13) {
                allegro_air_seterr(routine,47);
            }
        }
        allegro_air_error(&dumroutine,&errnum);
        if (errnum == 0) {
            mmflg = 1;
        }
    }
/*
 Used 0.02 seconds CPU time,
 0 additional bytes of memory.
 Equations contain 3278 adds/subtracts/negates
                   4370 multiplies
                      0 divides
                    746 assignments
*/
}

void allegro_air_dommldu(int routine)
{
    int i;
    int dumroutine,errnum;

    if (mmlduflg == 0) {
        allegro_air_domm(routine);
/*
Numerically decompose the mass matrix
*/
        allegro_air_ldudcomp(22,22,mmap,1e-13,workss,works,mm,mlo,mdi);
/*
Check for singular mass matrix
*/
        for (i = 0; i < 22; i++) {
            if (mdi[i] <= 1e-13) {
                allegro_air_seterr(routine,47);
            }
        }
        allegro_air_error(&dumroutine,&errnum);
        if (errnum == 0) {
            mmlduflg = 1;
        }
    }
}

void allegro_air_lhs(int routine)
{
/* Compute all remaining state- and force-dependent quantities
*/

    roustate = 2;
    allegro_air_dommldu(routine);
    allegro_air_dofs0();
}

void allegro_air_mfrc(double imult[22])
{
/*
Calculate forces due to constraint multipliers.

*/

    if (pres[0]  !=  0.) {
        mtau[0] = imult[0];
    } else {
        mtau[0] = 0.;
    }
    if (pres[1]  !=  0.) {
        mtau[1] = imult[1];
    } else {
        mtau[1] = 0.;
    }
    if (pres[2]  !=  0.) {
        mtau[2] = imult[2];
    } else {
        mtau[2] = 0.;
    }
    if (pres[3]  !=  0.) {
        mtau[3] = imult[3];
    } else {
        mtau[3] = 0.;
    }
    if (pres[4]  !=  0.) {
        mtau[4] = imult[4];
    } else {
        mtau[4] = 0.;
    }
    if (pres[5]  !=  0.) {
        mtau[5] = imult[5];
    } else {
        mtau[5] = 0.;
    }
    if (pres[6]  !=  0.) {
        mtau[6] = imult[6];
    } else {
        mtau[6] = 0.;
    }
    if (pres[7]  !=  0.) {
        mtau[7] = imult[7];
    } else {
        mtau[7] = 0.;
    }
    if (pres[8]  !=  0.) {
        mtau[8] = imult[8];
    } else {
        mtau[8] = 0.;
    }
    if (pres[9]  !=  0.) {
        mtau[9] = imult[9];
    } else {
        mtau[9] = 0.;
    }
    if (pres[10]  !=  0.) {
        mtau[10] = imult[10];
    } else {
        mtau[10] = 0.;
    }
    if (pres[11]  !=  0.) {
        mtau[11] = imult[11];
    } else {
        mtau[11] = 0.;
    }
    if (pres[12]  !=  0.) {
        mtau[12] = imult[12];
    } else {
        mtau[12] = 0.;
    }
    if (pres[13]  !=  0.) {
        mtau[13] = imult[13];
    } else {
        mtau[13] = 0.;
    }
    if (pres[14]  !=  0.) {
        mtau[14] = imult[14];
    } else {
        mtau[14] = 0.;
    }
    if (pres[15]  !=  0.) {
        mtau[15] = imult[15];
    } else {
        mtau[15] = 0.;
    }
    if (pres[16]  !=  0.) {
        mtau[16] = imult[16];
    } else {
        mtau[16] = 0.;
    }
    if (pres[17]  !=  0.) {
        mtau[17] = imult[17];
    } else {
        mtau[17] = 0.;
    }
    if (pres[18]  !=  0.) {
        mtau[18] = imult[18];
    } else {
        mtau[18] = 0.;
    }
    if (pres[19]  !=  0.) {
        mtau[19] = imult[19];
    } else {
        mtau[19] = 0.;
    }
    if (pres[20]  !=  0.) {
        mtau[20] = imult[20];
    } else {
        mtau[20] = 0.;
    }
    if (pres[21]  !=  0.) {
        mtau[21] = imult[21];
    } else {
        mtau[21] = 0.;
    }
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     44 assignments
*/
}

void allegro_air_equivht(double tau[22])
{
/* Compute tree hinge torques to match effect of applied loads
*/
    double fstareq[22][3],tstareq[22][3];

    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(56,23);
        return;
    }
/*
Compute fstareq (forces)
*/
    fstareq[5][0] = -(ufk[0][0]+(gk[3][0]*mk[0]));
    fstareq[5][1] = -(ufk[0][1]+(gk[3][1]*mk[0]));
    fstareq[5][2] = -(ufk[0][2]+(gk[3][2]*mk[0]));
    fstareq[6][0] = -(ufk[1][0]+(gk[6][0]*mk[1]));
    fstareq[6][1] = -(ufk[1][1]+(gk[6][1]*mk[1]));
    fstareq[6][2] = -(ufk[1][2]+(gk[6][2]*mk[1]));
    fstareq[7][0] = -(ufk[2][0]+(gk[7][0]*mk[2]));
    fstareq[7][1] = -(ufk[2][1]+(gk[7][1]*mk[2]));
    fstareq[7][2] = -(ufk[2][2]+(gk[7][2]*mk[2]));
    fstareq[8][0] = -(ufk[3][0]+(gk[8][0]*mk[3]));
    fstareq[8][1] = -(ufk[3][1]+(gk[8][1]*mk[3]));
    fstareq[8][2] = -(ufk[3][2]+(gk[8][2]*mk[3]));
    fstareq[9][0] = -(ufk[5][0]+(ufk[4][0]+(gk[9][0]*psmk[9])));
    fstareq[9][1] = -(ufk[5][1]+(ufk[4][1]+(gk[9][1]*psmk[9])));
    fstareq[9][2] = -(ufk[5][2]+(ufk[4][2]+(gk[9][2]*psmk[9])));
    fstareq[10][0] = -(ufk[6][0]+(gk[10][0]*mk[6]));
    fstareq[10][1] = -(ufk[6][1]+(gk[10][1]*mk[6]));
    fstareq[10][2] = -(ufk[6][2]+(gk[10][2]*mk[6]));
    fstareq[11][0] = -(ufk[7][0]+(gk[11][0]*mk[7]));
    fstareq[11][1] = -(ufk[7][1]+(gk[11][1]*mk[7]));
    fstareq[11][2] = -(ufk[7][2]+(gk[11][2]*mk[7]));
    fstareq[12][0] = -(ufk[8][0]+(gk[12][0]*mk[8]));
    fstareq[12][1] = -(ufk[8][1]+(gk[12][1]*mk[8]));
    fstareq[12][2] = -(ufk[8][2]+(gk[12][2]*mk[8]));
    fstareq[13][0] = -(ufk[10][0]+(ufk[9][0]+(gk[13][0]*psmk[13])));
    fstareq[13][1] = -(ufk[10][1]+(ufk[9][1]+(gk[13][1]*psmk[13])));
    fstareq[13][2] = -(ufk[10][2]+(ufk[9][2]+(gk[13][2]*psmk[13])));
    fstareq[14][0] = -(ufk[11][0]+(gk[14][0]*mk[11]));
    fstareq[14][1] = -(ufk[11][1]+(gk[14][1]*mk[11]));
    fstareq[14][2] = -(ufk[11][2]+(gk[14][2]*mk[11]));
    fstareq[15][0] = -(ufk[12][0]+(gk[15][0]*mk[12]));
    fstareq[15][1] = -(ufk[12][1]+(gk[15][1]*mk[12]));
    fstareq[15][2] = -(ufk[12][2]+(gk[15][2]*mk[12]));
    fstareq[16][0] = -(ufk[13][0]+(gk[16][0]*mk[13]));
    fstareq[16][1] = -(ufk[13][1]+(gk[16][1]*mk[13]));
    fstareq[16][2] = -(ufk[13][2]+(gk[16][2]*mk[13]));
    fstareq[17][0] = -(ufk[15][0]+(ufk[14][0]+(gk[17][0]*psmk[17])));
    fstareq[17][1] = -(ufk[15][1]+(ufk[14][1]+(gk[17][1]*psmk[17])));
    fstareq[17][2] = -(ufk[15][2]+(ufk[14][2]+(gk[17][2]*psmk[17])));
    fstareq[18][0] = -(ufk[16][0]+(gk[18][0]*mk[16]));
    fstareq[18][1] = -(ufk[16][1]+(gk[18][1]*mk[16]));
    fstareq[18][2] = -(ufk[16][2]+(gk[18][2]*mk[16]));
    fstareq[19][0] = -(ufk[17][0]+(gk[19][0]*mk[17]));
    fstareq[19][1] = -(ufk[17][1]+(gk[19][1]*mk[17]));
    fstareq[19][2] = -(ufk[17][2]+(gk[19][2]*mk[17]));
    fstareq[20][0] = -(ufk[18][0]+(gk[20][0]*mk[18]));
    fstareq[20][1] = -(ufk[18][1]+(gk[20][1]*mk[18]));
    fstareq[20][2] = -(ufk[18][2]+(gk[20][2]*mk[18]));
    fstareq[21][0] = -(ufk[20][0]+(ufk[19][0]+(gk[21][0]*psmk[21])));
    fstareq[21][1] = -(ufk[20][1]+(ufk[19][1]+(gk[21][1]*psmk[21])));
    fstareq[21][2] = -(ufk[20][2]+(ufk[19][2]+(gk[21][2]*psmk[21])));
/*
Compute tstareq (torques)
*/
    tstareq[9][0] = -((utk[4][0]+((rcom[4][1]*ufk[4][2])-(rcom[4][2]*ufk[4][1]))
      )+(utk[5][0]+((rcom[5][1]*ufk[5][2])-(rcom[5][2]*ufk[5][1]))));
    tstareq[9][1] = -((utk[4][1]+((rcom[4][2]*ufk[4][0])-(rcom[4][0]*ufk[4][2]))
      )+(utk[5][1]+((rcom[5][2]*ufk[5][0])-(rcom[5][0]*ufk[5][2]))));
    tstareq[9][2] = -((utk[4][2]+((rcom[4][0]*ufk[4][1])-(rcom[4][1]*ufk[4][0]))
      )+(utk[5][2]+((rcom[5][0]*ufk[5][1])-(rcom[5][1]*ufk[5][0]))));
    tstareq[13][0] = -((utk[9][0]+((rcom[9][1]*ufk[9][2])-(rcom[9][2]*ufk[9][1])
      ))+(utk[10][0]+((rcom[10][1]*ufk[10][2])-(rcom[10][2]*ufk[10][1]))));
    tstareq[13][1] = -((utk[9][1]+((rcom[9][2]*ufk[9][0])-(rcom[9][0]*ufk[9][2])
      ))+(utk[10][1]+((rcom[10][2]*ufk[10][0])-(rcom[10][0]*ufk[10][2]))));
    tstareq[13][2] = -((utk[9][2]+((rcom[9][0]*ufk[9][1])-(rcom[9][1]*ufk[9][0])
      ))+(utk[10][2]+((rcom[10][0]*ufk[10][1])-(rcom[10][1]*ufk[10][0]))));
    tstareq[17][0] = -((utk[14][0]+((rcom[14][1]*ufk[14][2])-(rcom[14][2]*
      ufk[14][1])))+(utk[15][0]+((rcom[15][1]*ufk[15][2])-(rcom[15][2]*
      ufk[15][1]))));
    tstareq[17][1] = -((utk[14][1]+((rcom[14][2]*ufk[14][0])-(rcom[14][0]*
      ufk[14][2])))+(utk[15][1]+((rcom[15][2]*ufk[15][0])-(rcom[15][0]*
      ufk[15][2]))));
    tstareq[17][2] = -((utk[14][2]+((rcom[14][0]*ufk[14][1])-(rcom[14][1]*
      ufk[14][0])))+(utk[15][2]+((rcom[15][0]*ufk[15][1])-(rcom[15][1]*
      ufk[15][0]))));
    tstareq[21][0] = -((utk[19][0]+((rcom[19][1]*ufk[19][2])-(rcom[19][2]*
      ufk[19][1])))+(utk[20][0]+((rcom[20][1]*ufk[20][2])-(rcom[20][2]*
      ufk[20][1]))));
    tstareq[21][1] = -((utk[19][1]+((rcom[19][2]*ufk[19][0])-(rcom[19][0]*
      ufk[19][2])))+(utk[20][1]+((rcom[20][2]*ufk[20][0])-(rcom[20][0]*
      ufk[20][2]))));
    tstareq[21][2] = -((utk[19][2]+((rcom[19][0]*ufk[19][1])-(rcom[19][1]*
      ufk[19][0])))+(utk[20][2]+((rcom[20][0]*ufk[20][1])-(rcom[20][1]*
      ufk[20][0]))));
/*
Compute taus (RHS ignoring constraints and inertial forces)
*/
    allegro_air_dovpk();
    temp[0] = (((fstareq[8][2]*Vpk[0][8][2])+((fstareq[8][0]*Vpk[0][8][0])+(
      fstareq[8][1]*Vpk[0][8][1])))+(((fstareq[7][2]*Vpk[0][7][2])+((
      fstareq[7][0]*Vpk[0][7][0])+(fstareq[7][1]*Vpk[0][7][1])))+(((
      fstareq[5][2]*Vpk[0][3][2])+((fstareq[5][0]*Vpk[0][3][0])+(fstareq[5][1]*
      Vpk[0][3][1])))+((fstareq[6][2]*Vpk[0][6][2])+((fstareq[6][0]*Vpk[0][6][0]
      )+(fstareq[6][1]*Vpk[0][6][1]))))));
    temp[1] = (((fstareq[12][2]*Vpk[0][12][2])+((fstareq[12][0]*Vpk[0][12][0])+(
      fstareq[12][1]*Vpk[0][12][1])))+(((fstareq[11][2]*Vpk[0][11][2])+((
      fstareq[11][0]*Vpk[0][11][0])+(fstareq[11][1]*Vpk[0][11][1])))+(((
      fstareq[10][2]*Vpk[0][10][2])+((fstareq[10][0]*Vpk[0][10][0])+(
      fstareq[10][1]*Vpk[0][10][1])))+(((fstareq[9][2]*Vpk[0][9][2])+((
      fstareq[9][0]*Vpk[0][9][0])+(fstareq[9][1]*Vpk[0][9][1])))+temp[0]))));
    temp[2] = (((fstareq[16][2]*Vpk[0][16][2])+((fstareq[16][0]*Vpk[0][16][0])+(
      fstareq[16][1]*Vpk[0][16][1])))+(((fstareq[15][2]*Vpk[0][15][2])+((
      fstareq[15][0]*Vpk[0][15][0])+(fstareq[15][1]*Vpk[0][15][1])))+(((
      fstareq[14][2]*Vpk[0][14][2])+((fstareq[14][0]*Vpk[0][14][0])+(
      fstareq[14][1]*Vpk[0][14][1])))+(((fstareq[13][2]*Vpk[0][13][2])+((
      fstareq[13][0]*Vpk[0][13][0])+(fstareq[13][1]*Vpk[0][13][1])))+temp[1]))))
      ;
    temp[3] = (((fstareq[20][2]*Vpk[0][20][2])+((fstareq[20][0]*Vpk[0][20][0])+(
      fstareq[20][1]*Vpk[0][20][1])))+(((fstareq[19][2]*Vpk[0][19][2])+((
      fstareq[19][0]*Vpk[0][19][0])+(fstareq[19][1]*Vpk[0][19][1])))+(((
      fstareq[18][2]*Vpk[0][18][2])+((fstareq[18][0]*Vpk[0][18][0])+(
      fstareq[18][1]*Vpk[0][18][1])))+(((fstareq[17][2]*Vpk[0][17][2])+((
      fstareq[17][0]*Vpk[0][17][0])+(fstareq[17][1]*Vpk[0][17][1])))+temp[2]))))
      ;
    tau[0] = (utau[0]-(((fstareq[21][2]*Vpk[0][21][2])+((fstareq[21][0]*
      Vpk[0][21][0])+(fstareq[21][1]*Vpk[0][21][1])))+temp[3]));
    temp[0] = (((fstareq[8][2]*Vpk[1][8][2])+((fstareq[8][0]*Vpk[1][8][0])+(
      fstareq[8][1]*Vpk[1][8][1])))+(((fstareq[7][2]*Vpk[1][7][2])+((
      fstareq[7][0]*Vpk[1][7][0])+(fstareq[7][1]*Vpk[1][7][1])))+(((
      fstareq[5][2]*Vpk[1][3][2])+((fstareq[5][0]*Vpk[1][3][0])+(fstareq[5][1]*
      Vpk[1][3][1])))+((fstareq[6][2]*Vpk[1][6][2])+((fstareq[6][0]*Vpk[1][6][0]
      )+(fstareq[6][1]*Vpk[1][6][1]))))));
    temp[1] = (((fstareq[12][2]*Vpk[1][12][2])+((fstareq[12][0]*Vpk[1][12][0])+(
      fstareq[12][1]*Vpk[1][12][1])))+(((fstareq[11][2]*Vpk[1][11][2])+((
      fstareq[11][0]*Vpk[1][11][0])+(fstareq[11][1]*Vpk[1][11][1])))+(((
      fstareq[10][2]*Vpk[1][10][2])+((fstareq[10][0]*Vpk[1][10][0])+(
      fstareq[10][1]*Vpk[1][10][1])))+(((fstareq[9][2]*Vpk[1][9][2])+((
      fstareq[9][0]*Vpk[1][9][0])+(fstareq[9][1]*Vpk[1][9][1])))+temp[0]))));
    temp[2] = (((fstareq[16][2]*Vpk[1][16][2])+((fstareq[16][0]*Vpk[1][16][0])+(
      fstareq[16][1]*Vpk[1][16][1])))+(((fstareq[15][2]*Vpk[1][15][2])+((
      fstareq[15][0]*Vpk[1][15][0])+(fstareq[15][1]*Vpk[1][15][1])))+(((
      fstareq[14][2]*Vpk[1][14][2])+((fstareq[14][0]*Vpk[1][14][0])+(
      fstareq[14][1]*Vpk[1][14][1])))+(((fstareq[13][2]*Vpk[1][13][2])+((
      fstareq[13][0]*Vpk[1][13][0])+(fstareq[13][1]*Vpk[1][13][1])))+temp[1]))))
      ;
    temp[3] = (((fstareq[20][2]*Vpk[1][20][2])+((fstareq[20][0]*Vpk[1][20][0])+(
      fstareq[20][1]*Vpk[1][20][1])))+(((fstareq[19][2]*Vpk[1][19][2])+((
      fstareq[19][0]*Vpk[1][19][0])+(fstareq[19][1]*Vpk[1][19][1])))+(((
      fstareq[18][2]*Vpk[1][18][2])+((fstareq[18][0]*Vpk[1][18][0])+(
      fstareq[18][1]*Vpk[1][18][1])))+(((fstareq[17][2]*Vpk[1][17][2])+((
      fstareq[17][0]*Vpk[1][17][0])+(fstareq[17][1]*Vpk[1][17][1])))+temp[2]))))
      ;
    tau[1] = (utau[1]-(((fstareq[21][2]*Vpk[1][21][2])+((fstareq[21][0]*
      Vpk[1][21][0])+(fstareq[21][1]*Vpk[1][21][1])))+temp[3]));
    temp[0] = (((fstareq[8][2]*Vpk[2][8][2])+((fstareq[8][0]*Vpk[2][8][0])+(
      fstareq[8][1]*Vpk[2][8][1])))+(((fstareq[7][2]*Vpk[2][7][2])+((
      fstareq[7][0]*Vpk[2][7][0])+(fstareq[7][1]*Vpk[2][7][1])))+(((
      fstareq[5][2]*Vpk[2][3][2])+((fstareq[5][0]*Vpk[2][3][0])+(fstareq[5][1]*
      Vpk[2][3][1])))+((fstareq[6][2]*Vpk[2][6][2])+((fstareq[6][0]*Vpk[2][6][0]
      )+(fstareq[6][1]*Vpk[2][6][1]))))));
    temp[1] = (((fstareq[12][2]*Vpk[2][12][2])+((fstareq[12][0]*Vpk[2][12][0])+(
      fstareq[12][1]*Vpk[2][12][1])))+(((fstareq[11][2]*Vpk[2][11][2])+((
      fstareq[11][0]*Vpk[2][11][0])+(fstareq[11][1]*Vpk[2][11][1])))+(((
      fstareq[10][2]*Vpk[2][10][2])+((fstareq[10][0]*Vpk[2][10][0])+(
      fstareq[10][1]*Vpk[2][10][1])))+(((fstareq[9][2]*Vpk[2][9][2])+((
      fstareq[9][0]*Vpk[2][9][0])+(fstareq[9][1]*Vpk[2][9][1])))+temp[0]))));
    temp[2] = (((fstareq[16][2]*Vpk[2][16][2])+((fstareq[16][0]*Vpk[2][16][0])+(
      fstareq[16][1]*Vpk[2][16][1])))+(((fstareq[15][2]*Vpk[2][15][2])+((
      fstareq[15][0]*Vpk[2][15][0])+(fstareq[15][1]*Vpk[2][15][1])))+(((
      fstareq[14][2]*Vpk[2][14][2])+((fstareq[14][0]*Vpk[2][14][0])+(
      fstareq[14][1]*Vpk[2][14][1])))+(((fstareq[13][2]*Vpk[2][13][2])+((
      fstareq[13][0]*Vpk[2][13][0])+(fstareq[13][1]*Vpk[2][13][1])))+temp[1]))))
      ;
    temp[3] = (((fstareq[20][2]*Vpk[2][20][2])+((fstareq[20][0]*Vpk[2][20][0])+(
      fstareq[20][1]*Vpk[2][20][1])))+(((fstareq[19][2]*Vpk[2][19][2])+((
      fstareq[19][0]*Vpk[2][19][0])+(fstareq[19][1]*Vpk[2][19][1])))+(((
      fstareq[18][2]*Vpk[2][18][2])+((fstareq[18][0]*Vpk[2][18][0])+(
      fstareq[18][1]*Vpk[2][18][1])))+(((fstareq[17][2]*Vpk[2][17][2])+((
      fstareq[17][0]*Vpk[2][17][0])+(fstareq[17][1]*Vpk[2][17][1])))+temp[2]))))
      ;
    tau[2] = (utau[2]-(((fstareq[21][2]*Vpk[2][21][2])+((fstareq[21][0]*
      Vpk[2][21][0])+(fstareq[21][1]*Vpk[2][21][1])))+temp[3]));
    temp[0] = ((((fstareq[7][2]*Vpk[3][7][2])+((fstareq[7][0]*Vpk[3][7][0])+(
      fstareq[7][1]*Vpk[3][7][1])))-((utk[2][2]*Wpk[3][7][2])+((utk[2][0]*
      Wpk[3][7][0])+(utk[2][1]*Wpk[3][7][1]))))+((((fstareq[5][1]*rk[0][2])-(
      fstareq[5][2]*rk[0][1]))-utk[0][0])+(((fstareq[6][2]*Vpk[3][6][2])+((
      fstareq[6][0]*Vpk[3][6][0])+(fstareq[6][1]*Vpk[3][6][1])))-((Cik[6][0][2]*
      utk[1][2])+((Cik[6][0][0]*utk[1][0])+(Cik[6][0][1]*utk[1][1]))))));
    temp[1] = ((((fstareq[9][2]*Vpk[3][9][2])+((fstareq[9][0]*Vpk[3][9][0])+(
      fstareq[9][1]*Vpk[3][9][1])))+((tstareq[9][2]*Wpk[3][9][2])+((
      tstareq[9][0]*Wpk[3][9][0])+(tstareq[9][1]*Wpk[3][9][1]))))+((((
      fstareq[8][2]*Vpk[3][8][2])+((fstareq[8][0]*Vpk[3][8][0])+(fstareq[8][1]*
      Vpk[3][8][1])))-((utk[3][2]*Wpk[3][8][2])+((utk[3][0]*Wpk[3][8][0])+(
      utk[3][1]*Wpk[3][8][1]))))+temp[0]));
    temp[2] = ((((fstareq[11][2]*Vpk[3][11][2])+((fstareq[11][0]*Vpk[3][11][0])+
      (fstareq[11][1]*Vpk[3][11][1])))-((utk[7][2]*Wpk[3][11][2])+((utk[7][0]*
      Wpk[3][11][0])+(utk[7][1]*Wpk[3][11][1]))))+((((fstareq[10][2]*
      Vpk[3][10][2])+((fstareq[10][0]*Vpk[3][10][0])+(fstareq[10][1]*
      Vpk[3][10][1])))-((Cik[10][0][2]*utk[6][2])+((Cik[10][0][0]*utk[6][0])+(
      Cik[10][0][1]*utk[6][1]))))+temp[1]));
    temp[3] = ((((fstareq[13][2]*Vpk[3][13][2])+((fstareq[13][0]*Vpk[3][13][0])+
      (fstareq[13][1]*Vpk[3][13][1])))+((tstareq[13][2]*Wpk[3][13][2])+((
      tstareq[13][0]*Wpk[3][13][0])+(tstareq[13][1]*Wpk[3][13][1]))))+((((
      fstareq[12][2]*Vpk[3][12][2])+((fstareq[12][0]*Vpk[3][12][0])+(
      fstareq[12][1]*Vpk[3][12][1])))-((utk[8][2]*Wpk[3][12][2])+((utk[8][0]*
      Wpk[3][12][0])+(utk[8][1]*Wpk[3][12][1]))))+temp[2]));
    temp[4] = ((((fstareq[15][2]*Vpk[3][15][2])+((fstareq[15][0]*Vpk[3][15][0])+
      (fstareq[15][1]*Vpk[3][15][1])))-((utk[12][2]*Wpk[3][15][2])+((utk[12][0]*
      Wpk[3][15][0])+(utk[12][1]*Wpk[3][15][1]))))+((((fstareq[14][2]*
      Vpk[3][14][2])+((fstareq[14][0]*Vpk[3][14][0])+(fstareq[14][1]*
      Vpk[3][14][1])))-((Cik[14][0][2]*utk[11][2])+((Cik[14][0][0]*utk[11][0])+(
      Cik[14][0][1]*utk[11][1]))))+temp[3]));
    temp[5] = ((((fstareq[17][2]*Vpk[3][17][2])+((fstareq[17][0]*Vpk[3][17][0])+
      (fstareq[17][1]*Vpk[3][17][1])))+((tstareq[17][2]*Wpk[3][17][2])+((
      tstareq[17][0]*Wpk[3][17][0])+(tstareq[17][1]*Wpk[3][17][1]))))+((((
      fstareq[16][2]*Vpk[3][16][2])+((fstareq[16][0]*Vpk[3][16][0])+(
      fstareq[16][1]*Vpk[3][16][1])))-((utk[13][2]*Wpk[3][16][2])+((utk[13][0]*
      Wpk[3][16][0])+(utk[13][1]*Wpk[3][16][1]))))+temp[4]));
    temp[6] = ((((fstareq[19][2]*Vpk[3][19][2])+((fstareq[19][0]*Vpk[3][19][0])+
      (fstareq[19][1]*Vpk[3][19][1])))-((utk[17][2]*Wpk[3][19][2])+((utk[17][0]*
      Wpk[3][19][0])+(utk[17][1]*Wpk[3][19][1]))))+((((fstareq[18][2]*
      Vpk[3][18][2])+((fstareq[18][0]*Vpk[3][18][0])+(fstareq[18][1]*
      Vpk[3][18][1])))-((Cik[18][0][2]*utk[16][2])+((Cik[18][0][0]*utk[16][0])+(
      Cik[18][0][1]*utk[16][1]))))+temp[5]));
    tau[3] = (utau[3]-((((fstareq[21][2]*Vpk[3][21][2])+((fstareq[21][0]*
      Vpk[3][21][0])+(fstareq[21][1]*Vpk[3][21][1])))+((tstareq[21][2]*
      Wpk[3][21][2])+((tstareq[21][0]*Wpk[3][21][0])+(tstareq[21][1]*
      Wpk[3][21][1]))))+((((fstareq[20][2]*Vpk[3][20][2])+((fstareq[20][0]*
      Vpk[3][20][0])+(fstareq[20][1]*Vpk[3][20][1])))-((utk[18][2]*Wpk[3][20][2]
      )+((utk[18][0]*Wpk[3][20][0])+(utk[18][1]*Wpk[3][20][1]))))+temp[6])));
    temp[0] = ((((fstareq[7][2]*Vpk[4][7][2])+((fstareq[7][0]*Vpk[4][7][0])+(
      fstareq[7][1]*Vpk[4][7][1])))-((utk[2][2]*Wpk[4][7][2])+((utk[2][0]*
      Wpk[4][7][0])+(utk[2][1]*Wpk[4][7][1]))))+((((fstareq[5][2]*rk[0][0])-(
      fstareq[5][0]*rk[0][2]))-utk[0][1])+(((fstareq[6][2]*Vpk[4][6][2])+((
      fstareq[6][0]*Vpk[4][6][0])+(fstareq[6][1]*Vpk[4][6][1])))-((Cik[6][1][2]*
      utk[1][2])+((Cik[6][1][0]*utk[1][0])+(Cik[6][1][1]*utk[1][1]))))));
    temp[1] = ((((fstareq[9][2]*Vpk[4][9][2])+((fstareq[9][0]*Vpk[4][9][0])+(
      fstareq[9][1]*Vpk[4][9][1])))+((tstareq[9][2]*Wpk[4][9][2])+((
      tstareq[9][0]*Wpk[4][9][0])+(tstareq[9][1]*Wpk[4][9][1]))))+((((
      fstareq[8][2]*Vpk[4][8][2])+((fstareq[8][0]*Vpk[4][8][0])+(fstareq[8][1]*
      Vpk[4][8][1])))-((utk[3][2]*Wpk[4][8][2])+((utk[3][0]*Wpk[4][8][0])+(
      utk[3][1]*Wpk[4][8][1]))))+temp[0]));
    temp[2] = ((((fstareq[11][2]*Vpk[4][11][2])+((fstareq[11][0]*Vpk[4][11][0])+
      (fstareq[11][1]*Vpk[4][11][1])))-((utk[7][2]*Wpk[4][11][2])+((utk[7][0]*
      Wpk[4][11][0])+(utk[7][1]*Wpk[4][11][1]))))+((((fstareq[10][2]*
      Vpk[4][10][2])+((fstareq[10][0]*Vpk[4][10][0])+(fstareq[10][1]*
      Vpk[4][10][1])))-((Cik[10][1][2]*utk[6][2])+((Cik[10][1][0]*utk[6][0])+(
      Cik[10][1][1]*utk[6][1]))))+temp[1]));
    temp[3] = ((((fstareq[13][2]*Vpk[4][13][2])+((fstareq[13][0]*Vpk[4][13][0])+
      (fstareq[13][1]*Vpk[4][13][1])))+((tstareq[13][2]*Wpk[4][13][2])+((
      tstareq[13][0]*Wpk[4][13][0])+(tstareq[13][1]*Wpk[4][13][1]))))+((((
      fstareq[12][2]*Vpk[4][12][2])+((fstareq[12][0]*Vpk[4][12][0])+(
      fstareq[12][1]*Vpk[4][12][1])))-((utk[8][2]*Wpk[4][12][2])+((utk[8][0]*
      Wpk[4][12][0])+(utk[8][1]*Wpk[4][12][1]))))+temp[2]));
    temp[4] = ((((fstareq[15][2]*Vpk[4][15][2])+((fstareq[15][0]*Vpk[4][15][0])+
      (fstareq[15][1]*Vpk[4][15][1])))-((utk[12][2]*Wpk[4][15][2])+((utk[12][0]*
      Wpk[4][15][0])+(utk[12][1]*Wpk[4][15][1]))))+((((fstareq[14][2]*
      Vpk[4][14][2])+((fstareq[14][0]*Vpk[4][14][0])+(fstareq[14][1]*
      Vpk[4][14][1])))-((Cik[14][1][2]*utk[11][2])+((Cik[14][1][0]*utk[11][0])+(
      Cik[14][1][1]*utk[11][1]))))+temp[3]));
    temp[5] = ((((fstareq[17][2]*Vpk[4][17][2])+((fstareq[17][0]*Vpk[4][17][0])+
      (fstareq[17][1]*Vpk[4][17][1])))+((tstareq[17][2]*Wpk[4][17][2])+((
      tstareq[17][0]*Wpk[4][17][0])+(tstareq[17][1]*Wpk[4][17][1]))))+((((
      fstareq[16][2]*Vpk[4][16][2])+((fstareq[16][0]*Vpk[4][16][0])+(
      fstareq[16][1]*Vpk[4][16][1])))-((utk[13][2]*Wpk[4][16][2])+((utk[13][0]*
      Wpk[4][16][0])+(utk[13][1]*Wpk[4][16][1]))))+temp[4]));
    temp[6] = ((((fstareq[19][2]*Vpk[4][19][2])+((fstareq[19][0]*Vpk[4][19][0])+
      (fstareq[19][1]*Vpk[4][19][1])))-((utk[17][2]*Wpk[4][19][2])+((utk[17][0]*
      Wpk[4][19][0])+(utk[17][1]*Wpk[4][19][1]))))+((((fstareq[18][2]*
      Vpk[4][18][2])+((fstareq[18][0]*Vpk[4][18][0])+(fstareq[18][1]*
      Vpk[4][18][1])))-((Cik[18][1][2]*utk[16][2])+((Cik[18][1][0]*utk[16][0])+(
      Cik[18][1][1]*utk[16][1]))))+temp[5]));
    tau[4] = (utau[4]-((((fstareq[21][2]*Vpk[4][21][2])+((fstareq[21][0]*
      Vpk[4][21][0])+(fstareq[21][1]*Vpk[4][21][1])))+((tstareq[21][2]*
      Wpk[4][21][2])+((tstareq[21][0]*Wpk[4][21][0])+(tstareq[21][1]*
      Wpk[4][21][1]))))+((((fstareq[20][2]*Vpk[4][20][2])+((fstareq[20][0]*
      Vpk[4][20][0])+(fstareq[20][1]*Vpk[4][20][1])))-((utk[18][2]*Wpk[4][20][2]
      )+((utk[18][0]*Wpk[4][20][0])+(utk[18][1]*Wpk[4][20][1]))))+temp[6])));
    temp[0] = ((((fstareq[7][2]*Vpk[5][7][2])+((fstareq[7][0]*Vpk[5][7][0])+(
      fstareq[7][1]*Vpk[5][7][1])))-((utk[2][2]*Wpk[5][7][2])+((utk[2][0]*
      Wpk[5][7][0])+(utk[2][1]*Wpk[5][7][1]))))+((((fstareq[5][0]*rk[0][1])-(
      fstareq[5][1]*rk[0][0]))-utk[0][2])+(((fstareq[6][2]*Vpk[5][6][2])+((
      fstareq[6][0]*Vpk[5][6][0])+(fstareq[6][1]*Vpk[5][6][1])))-((Cik[6][2][2]*
      utk[1][2])+((Cik[6][2][0]*utk[1][0])+(Cik[6][2][1]*utk[1][1]))))));
    temp[1] = ((((fstareq[9][2]*Vpk[5][9][2])+((fstareq[9][0]*Vpk[5][9][0])+(
      fstareq[9][1]*Vpk[5][9][1])))+((tstareq[9][2]*Wpk[5][9][2])+((
      tstareq[9][0]*Wpk[5][9][0])+(tstareq[9][1]*Wpk[5][9][1]))))+((((
      fstareq[8][2]*Vpk[5][8][2])+((fstareq[8][0]*Vpk[5][8][0])+(fstareq[8][1]*
      Vpk[5][8][1])))-((utk[3][2]*Wpk[5][8][2])+((utk[3][0]*Wpk[5][8][0])+(
      utk[3][1]*Wpk[5][8][1]))))+temp[0]));
    temp[2] = ((((fstareq[11][2]*Vpk[5][11][2])+((fstareq[11][0]*Vpk[5][11][0])+
      (fstareq[11][1]*Vpk[5][11][1])))-((utk[7][2]*Wpk[5][11][2])+((utk[7][0]*
      Wpk[5][11][0])+(utk[7][1]*Wpk[5][11][1]))))+((((fstareq[10][2]*
      Vpk[5][10][2])+((fstareq[10][0]*Vpk[5][10][0])+(fstareq[10][1]*
      Vpk[5][10][1])))-((Cik[10][2][2]*utk[6][2])+((Cik[10][2][0]*utk[6][0])+(
      Cik[10][2][1]*utk[6][1]))))+temp[1]));
    temp[3] = ((((fstareq[13][2]*Vpk[5][13][2])+((fstareq[13][0]*Vpk[5][13][0])+
      (fstareq[13][1]*Vpk[5][13][1])))+((tstareq[13][2]*Wpk[5][13][2])+((
      tstareq[13][0]*Wpk[5][13][0])+(tstareq[13][1]*Wpk[5][13][1]))))+((((
      fstareq[12][2]*Vpk[5][12][2])+((fstareq[12][0]*Vpk[5][12][0])+(
      fstareq[12][1]*Vpk[5][12][1])))-((utk[8][2]*Wpk[5][12][2])+((utk[8][0]*
      Wpk[5][12][0])+(utk[8][1]*Wpk[5][12][1]))))+temp[2]));
    temp[4] = ((((fstareq[15][2]*Vpk[5][15][2])+((fstareq[15][0]*Vpk[5][15][0])+
      (fstareq[15][1]*Vpk[5][15][1])))-((utk[12][2]*Wpk[5][15][2])+((utk[12][0]*
      Wpk[5][15][0])+(utk[12][1]*Wpk[5][15][1]))))+((((fstareq[14][2]*
      Vpk[5][14][2])+((fstareq[14][0]*Vpk[5][14][0])+(fstareq[14][1]*
      Vpk[5][14][1])))-((Cik[14][2][2]*utk[11][2])+((Cik[14][2][0]*utk[11][0])+(
      Cik[14][2][1]*utk[11][1]))))+temp[3]));
    temp[5] = ((((fstareq[17][2]*Vpk[5][17][2])+((fstareq[17][0]*Vpk[5][17][0])+
      (fstareq[17][1]*Vpk[5][17][1])))+((tstareq[17][2]*Wpk[5][17][2])+((
      tstareq[17][0]*Wpk[5][17][0])+(tstareq[17][1]*Wpk[5][17][1]))))+((((
      fstareq[16][2]*Vpk[5][16][2])+((fstareq[16][0]*Vpk[5][16][0])+(
      fstareq[16][1]*Vpk[5][16][1])))-((utk[13][2]*Wpk[5][16][2])+((utk[13][0]*
      Wpk[5][16][0])+(utk[13][1]*Wpk[5][16][1]))))+temp[4]));
    temp[6] = ((((fstareq[19][2]*Vpk[5][19][2])+((fstareq[19][0]*Vpk[5][19][0])+
      (fstareq[19][1]*Vpk[5][19][1])))-((utk[17][2]*Wpk[5][19][2])+((utk[17][0]*
      Wpk[5][19][0])+(utk[17][1]*Wpk[5][19][1]))))+((((fstareq[18][2]*
      Vpk[5][18][2])+((fstareq[18][0]*Vpk[5][18][0])+(fstareq[18][1]*
      Vpk[5][18][1])))-((Cik[18][2][2]*utk[16][2])+((Cik[18][2][0]*utk[16][0])+(
      Cik[18][2][1]*utk[16][1]))))+temp[5]));
    tau[5] = (utau[5]-((((fstareq[21][2]*Vpk[5][21][2])+((fstareq[21][0]*
      Vpk[5][21][0])+(fstareq[21][1]*Vpk[5][21][1])))+((tstareq[21][2]*
      Wpk[5][21][2])+((tstareq[21][0]*Wpk[5][21][0])+(tstareq[21][1]*
      Wpk[5][21][1]))))+((((fstareq[20][2]*Vpk[5][20][2])+((fstareq[20][0]*
      Vpk[5][20][0])+(fstareq[20][1]*Vpk[5][20][1])))-((utk[18][2]*Wpk[5][20][2]
      )+((utk[18][0]*Wpk[5][20][0])+(utk[18][1]*Wpk[5][20][1]))))+temp[6])));
    temp[0] = ((((fstareq[6][2]*Vpk[6][6][2])+((fstareq[6][0]*Vpk[6][6][0])+(
      fstareq[6][1]*Vpk[6][6][1])))-((pin[6][2]*utk[1][2])+((pin[6][0]*utk[1][0]
      )+(pin[6][1]*utk[1][1]))))+(((fstareq[7][2]*Vpk[6][7][2])+((fstareq[7][0]*
      Vpk[6][7][0])+(fstareq[7][1]*Vpk[6][7][1])))-((utk[2][2]*Wpk[6][7][2])+((
      utk[2][0]*Wpk[6][7][0])+(utk[2][1]*Wpk[6][7][1])))));
    tau[6] = (utau[6]-((((fstareq[9][2]*Vpk[6][9][2])+((fstareq[9][0]*
      Vpk[6][9][0])+(fstareq[9][1]*Vpk[6][9][1])))+((tstareq[9][2]*Wpk[6][9][2])
      +((tstareq[9][0]*Wpk[6][9][0])+(tstareq[9][1]*Wpk[6][9][1]))))+((((
      fstareq[8][2]*Vpk[6][8][2])+((fstareq[8][0]*Vpk[6][8][0])+(fstareq[8][1]*
      Vpk[6][8][1])))-((utk[3][2]*Wpk[6][8][2])+((utk[3][0]*Wpk[6][8][0])+(
      utk[3][1]*Wpk[6][8][1]))))+temp[0])));
    temp[0] = ((((fstareq[7][2]*Vpk[7][7][2])+((fstareq[7][0]*Vpk[7][7][0])+(
      fstareq[7][1]*Vpk[7][7][1])))-((pin[7][2]*utk[2][2])+((pin[7][0]*utk[2][0]
      )+(pin[7][1]*utk[2][1]))))+(((fstareq[8][2]*Vpk[7][8][2])+((fstareq[8][0]*
      Vpk[7][8][0])+(fstareq[8][1]*Vpk[7][8][1])))-((utk[3][2]*Wpk[7][8][2])+((
      utk[3][0]*Wpk[7][8][0])+(utk[3][1]*Wpk[7][8][1])))));
    tau[7] = (utau[7]-((((fstareq[9][2]*Vpk[7][9][2])+((fstareq[9][0]*
      Vpk[7][9][0])+(fstareq[9][1]*Vpk[7][9][1])))+((tstareq[9][2]*Wpk[7][9][2])
      +((tstareq[9][0]*Wpk[7][9][0])+(tstareq[9][1]*Wpk[7][9][1]))))+temp[0]));
    tau[8] = (utau[8]-((((fstareq[8][2]*Vpk[8][8][2])+((fstareq[8][0]*
      Vpk[8][8][0])+(fstareq[8][1]*Vpk[8][8][1])))-((pin[8][2]*utk[3][2])+((
      pin[8][0]*utk[3][0])+(pin[8][1]*utk[3][1]))))+(((fstareq[9][2]*
      Vpk[8][9][2])+((fstareq[9][0]*Vpk[8][9][0])+(fstareq[9][1]*Vpk[8][9][1])))
      +((tstareq[9][2]*Wpk[8][9][2])+((tstareq[9][0]*Wpk[8][9][0])+(
      tstareq[9][1]*Wpk[8][9][1]))))));
    tau[9] = (utau[9]-(((fstareq[9][2]*Vpk[9][9][2])+((fstareq[9][0]*
      Vpk[9][9][0])+(fstareq[9][1]*Vpk[9][9][1])))+((pin[9][2]*tstareq[9][2])+((
      pin[9][0]*tstareq[9][0])+(pin[9][1]*tstareq[9][1])))));
    temp[0] = ((((fstareq[10][2]*Vpk[10][10][2])+((fstareq[10][0]*Vpk[10][10][0]
      )+(fstareq[10][1]*Vpk[10][10][1])))-((pin[10][2]*utk[6][2])+((pin[10][0]*
      utk[6][0])+(pin[10][1]*utk[6][1]))))+(((fstareq[11][2]*Vpk[10][11][2])+((
      fstareq[11][0]*Vpk[10][11][0])+(fstareq[11][1]*Vpk[10][11][1])))-((
      utk[7][2]*Wpk[10][11][2])+((utk[7][0]*Wpk[10][11][0])+(utk[7][1]*
      Wpk[10][11][1])))));
    tau[10] = (utau[10]-((((fstareq[13][2]*Vpk[10][13][2])+((fstareq[13][0]*
      Vpk[10][13][0])+(fstareq[13][1]*Vpk[10][13][1])))+((tstareq[13][2]*
      Wpk[10][13][2])+((tstareq[13][0]*Wpk[10][13][0])+(tstareq[13][1]*
      Wpk[10][13][1]))))+((((fstareq[12][2]*Vpk[10][12][2])+((fstareq[12][0]*
      Vpk[10][12][0])+(fstareq[12][1]*Vpk[10][12][1])))-((utk[8][2]*
      Wpk[10][12][2])+((utk[8][0]*Wpk[10][12][0])+(utk[8][1]*Wpk[10][12][1]))))+
      temp[0])));
    temp[0] = ((((fstareq[11][2]*Vpk[11][11][2])+((fstareq[11][0]*Vpk[11][11][0]
      )+(fstareq[11][1]*Vpk[11][11][1])))-((pin[11][2]*utk[7][2])+((pin[11][0]*
      utk[7][0])+(pin[11][1]*utk[7][1]))))+(((fstareq[12][2]*Vpk[11][12][2])+((
      fstareq[12][0]*Vpk[11][12][0])+(fstareq[12][1]*Vpk[11][12][1])))-((
      utk[8][2]*Wpk[11][12][2])+((utk[8][0]*Wpk[11][12][0])+(utk[8][1]*
      Wpk[11][12][1])))));
    tau[11] = (utau[11]-((((fstareq[13][2]*Vpk[11][13][2])+((fstareq[13][0]*
      Vpk[11][13][0])+(fstareq[13][1]*Vpk[11][13][1])))+((tstareq[13][2]*
      Wpk[11][13][2])+((tstareq[13][0]*Wpk[11][13][0])+(tstareq[13][1]*
      Wpk[11][13][1]))))+temp[0]));
    tau[12] = (utau[12]-((((fstareq[12][2]*Vpk[12][12][2])+((fstareq[12][0]*
      Vpk[12][12][0])+(fstareq[12][1]*Vpk[12][12][1])))-((pin[12][2]*utk[8][2])+
      ((pin[12][0]*utk[8][0])+(pin[12][1]*utk[8][1]))))+(((fstareq[13][2]*
      Vpk[12][13][2])+((fstareq[13][0]*Vpk[12][13][0])+(fstareq[13][1]*
      Vpk[12][13][1])))+((tstareq[13][2]*Wpk[12][13][2])+((tstareq[13][0]*
      Wpk[12][13][0])+(tstareq[13][1]*Wpk[12][13][1]))))));
    tau[13] = (utau[13]-(((fstareq[13][2]*Vpk[13][13][2])+((fstareq[13][0]*
      Vpk[13][13][0])+(fstareq[13][1]*Vpk[13][13][1])))+((pin[13][2]*
      tstareq[13][2])+((pin[13][0]*tstareq[13][0])+(pin[13][1]*tstareq[13][1])))
      ));
    temp[0] = ((((fstareq[14][2]*Vpk[14][14][2])+((fstareq[14][0]*Vpk[14][14][0]
      )+(fstareq[14][1]*Vpk[14][14][1])))-((pin[14][2]*utk[11][2])+((pin[14][0]*
      utk[11][0])+(pin[14][1]*utk[11][1]))))+(((fstareq[15][2]*Vpk[14][15][2])+(
      (fstareq[15][0]*Vpk[14][15][0])+(fstareq[15][1]*Vpk[14][15][1])))-((
      utk[12][2]*Wpk[14][15][2])+((utk[12][0]*Wpk[14][15][0])+(utk[12][1]*
      Wpk[14][15][1])))));
    tau[14] = (utau[14]-((((fstareq[17][2]*Vpk[14][17][2])+((fstareq[17][0]*
      Vpk[14][17][0])+(fstareq[17][1]*Vpk[14][17][1])))+((tstareq[17][2]*
      Wpk[14][17][2])+((tstareq[17][0]*Wpk[14][17][0])+(tstareq[17][1]*
      Wpk[14][17][1]))))+((((fstareq[16][2]*Vpk[14][16][2])+((fstareq[16][0]*
      Vpk[14][16][0])+(fstareq[16][1]*Vpk[14][16][1])))-((utk[13][2]*
      Wpk[14][16][2])+((utk[13][0]*Wpk[14][16][0])+(utk[13][1]*Wpk[14][16][1])))
      )+temp[0])));
    temp[0] = ((((fstareq[15][2]*Vpk[15][15][2])+((fstareq[15][0]*Vpk[15][15][0]
      )+(fstareq[15][1]*Vpk[15][15][1])))-((pin[15][2]*utk[12][2])+((pin[15][0]*
      utk[12][0])+(pin[15][1]*utk[12][1]))))+(((fstareq[16][2]*Vpk[15][16][2])+(
      (fstareq[16][0]*Vpk[15][16][0])+(fstareq[16][1]*Vpk[15][16][1])))-((
      utk[13][2]*Wpk[15][16][2])+((utk[13][0]*Wpk[15][16][0])+(utk[13][1]*
      Wpk[15][16][1])))));
    tau[15] = (utau[15]-((((fstareq[17][2]*Vpk[15][17][2])+((fstareq[17][0]*
      Vpk[15][17][0])+(fstareq[17][1]*Vpk[15][17][1])))+((tstareq[17][2]*
      Wpk[15][17][2])+((tstareq[17][0]*Wpk[15][17][0])+(tstareq[17][1]*
      Wpk[15][17][1]))))+temp[0]));
    tau[16] = (utau[16]-((((fstareq[16][2]*Vpk[16][16][2])+((fstareq[16][0]*
      Vpk[16][16][0])+(fstareq[16][1]*Vpk[16][16][1])))-((pin[16][2]*utk[13][2])
      +((pin[16][0]*utk[13][0])+(pin[16][1]*utk[13][1]))))+(((fstareq[17][2]*
      Vpk[16][17][2])+((fstareq[17][0]*Vpk[16][17][0])+(fstareq[17][1]*
      Vpk[16][17][1])))+((tstareq[17][2]*Wpk[16][17][2])+((tstareq[17][0]*
      Wpk[16][17][0])+(tstareq[17][1]*Wpk[16][17][1]))))));
    tau[17] = (utau[17]-(((fstareq[17][2]*Vpk[17][17][2])+((fstareq[17][0]*
      Vpk[17][17][0])+(fstareq[17][1]*Vpk[17][17][1])))+((pin[17][2]*
      tstareq[17][2])+((pin[17][0]*tstareq[17][0])+(pin[17][1]*tstareq[17][1])))
      ));
    temp[0] = ((((fstareq[18][2]*Vpk[18][18][2])+((fstareq[18][0]*Vpk[18][18][0]
      )+(fstareq[18][1]*Vpk[18][18][1])))-((pin[18][2]*utk[16][2])+((pin[18][0]*
      utk[16][0])+(pin[18][1]*utk[16][1]))))+(((fstareq[19][2]*Vpk[18][19][2])+(
      (fstareq[19][0]*Vpk[18][19][0])+(fstareq[19][1]*Vpk[18][19][1])))-((
      utk[17][2]*Wpk[18][19][2])+((utk[17][0]*Wpk[18][19][0])+(utk[17][1]*
      Wpk[18][19][1])))));
    tau[18] = (utau[18]-((((fstareq[21][2]*Vpk[18][21][2])+((fstareq[21][0]*
      Vpk[18][21][0])+(fstareq[21][1]*Vpk[18][21][1])))+((tstareq[21][2]*
      Wpk[18][21][2])+((tstareq[21][0]*Wpk[18][21][0])+(tstareq[21][1]*
      Wpk[18][21][1]))))+((((fstareq[20][2]*Vpk[18][20][2])+((fstareq[20][0]*
      Vpk[18][20][0])+(fstareq[20][1]*Vpk[18][20][1])))-((utk[18][2]*
      Wpk[18][20][2])+((utk[18][0]*Wpk[18][20][0])+(utk[18][1]*Wpk[18][20][1])))
      )+temp[0])));
    temp[0] = ((((fstareq[19][2]*Vpk[19][19][2])+((fstareq[19][0]*Vpk[19][19][0]
      )+(fstareq[19][1]*Vpk[19][19][1])))-((pin[19][2]*utk[17][2])+((pin[19][0]*
      utk[17][0])+(pin[19][1]*utk[17][1]))))+(((fstareq[20][2]*Vpk[19][20][2])+(
      (fstareq[20][0]*Vpk[19][20][0])+(fstareq[20][1]*Vpk[19][20][1])))-((
      utk[18][2]*Wpk[19][20][2])+((utk[18][0]*Wpk[19][20][0])+(utk[18][1]*
      Wpk[19][20][1])))));
    tau[19] = (utau[19]-((((fstareq[21][2]*Vpk[19][21][2])+((fstareq[21][0]*
      Vpk[19][21][0])+(fstareq[21][1]*Vpk[19][21][1])))+((tstareq[21][2]*
      Wpk[19][21][2])+((tstareq[21][0]*Wpk[19][21][0])+(tstareq[21][1]*
      Wpk[19][21][1]))))+temp[0]));
    tau[20] = (utau[20]-((((fstareq[20][2]*Vpk[20][20][2])+((fstareq[20][0]*
      Vpk[20][20][0])+(fstareq[20][1]*Vpk[20][20][1])))-((pin[20][2]*utk[18][2])
      +((pin[20][0]*utk[18][0])+(pin[20][1]*utk[18][1]))))+(((fstareq[21][2]*
      Vpk[20][21][2])+((fstareq[21][0]*Vpk[20][21][0])+(fstareq[21][1]*
      Vpk[20][21][1])))+((tstareq[21][2]*Wpk[20][21][2])+((tstareq[21][0]*
      Wpk[20][21][0])+(tstareq[21][1]*Wpk[20][21][1]))))));
    tau[21] = (utau[21]-(((fstareq[21][2]*Vpk[21][21][2])+((fstareq[21][0]*
      Vpk[21][21][0])+(fstareq[21][1]*Vpk[21][21][1])))+((pin[21][2]*
      tstareq[21][2])+((pin[21][0]*tstareq[21][0])+(pin[21][1]*tstareq[21][1])))
      ));
/*
Op counts below do not include called subroutines
*/
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  876 adds/subtracts/negates
                    786 multiplies
                      0 divides
                    126 assignments
*/
}

void allegro_air_fs0(void)
{

/*
Compute Fs (ignoring multiplier forces)
*/
    fs[0] = fs0[0];
    fs[1] = fs0[1];
    fs[2] = fs0[2];
    fs[3] = fs0[3];
    fs[4] = fs0[4];
    fs[5] = fs0[5];
    fs[6] = fs0[6];
    fs[7] = fs0[7];
    fs[8] = fs0[8];
    fs[9] = fs0[9];
    fs[10] = fs0[10];
    fs[11] = fs0[11];
    fs[12] = fs0[12];
    fs[13] = fs0[13];
    fs[14] = fs0[14];
    fs[15] = fs0[15];
    fs[16] = fs0[16];
    fs[17] = fs0[17];
    fs[18] = fs0[18];
    fs[19] = fs0[19];
    fs[20] = fs0[20];
    fs[21] = fs0[21];
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     22 assignments
*/
}

void allegro_air_fsmult(void)
{

/*
Compute Fs (multiplier-generated forces only)
*/
    allegro_air_dovpk();
    fs[0] = mtau[0];
    fs[1] = mtau[1];
    fs[2] = mtau[2];
    fs[3] = mtau[3];
    fs[4] = mtau[4];
    fs[5] = mtau[5];
    fs[6] = mtau[6];
    fs[7] = mtau[7];
    fs[8] = mtau[8];
    fs[9] = mtau[9];
    fs[10] = mtau[10];
    fs[11] = mtau[11];
    fs[12] = mtau[12];
    fs[13] = mtau[13];
    fs[14] = mtau[14];
    fs[15] = mtau[15];
    fs[16] = mtau[16];
    fs[17] = mtau[17];
    fs[18] = mtau[18];
    fs[19] = mtau[19];
    fs[20] = mtau[20];
    fs[21] = mtau[21];
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     22 assignments
*/
}

void allegro_air_fsfull(void)
{

/*
Compute Fs (including all forces)
*/
    allegro_air_fsmult();
    fs[0] = (fs[0]+fs0[0]);
    fs[1] = (fs[1]+fs0[1]);
    fs[2] = (fs[2]+fs0[2]);
    fs[3] = (fs[3]+fs0[3]);
    fs[4] = (fs[4]+fs0[4]);
    fs[5] = (fs[5]+fs0[5]);
    fs[6] = (fs[6]+fs0[6]);
    fs[7] = (fs[7]+fs0[7]);
    fs[8] = (fs[8]+fs0[8]);
    fs[9] = (fs[9]+fs0[9]);
    fs[10] = (fs[10]+fs0[10]);
    fs[11] = (fs[11]+fs0[11]);
    fs[12] = (fs[12]+fs0[12]);
    fs[13] = (fs[13]+fs0[13]);
    fs[14] = (fs[14]+fs0[14]);
    fs[15] = (fs[15]+fs0[15]);
    fs[16] = (fs[16]+fs0[16]);
    fs[17] = (fs[17]+fs0[17]);
    fs[18] = (fs[18]+fs0[18]);
    fs[19] = (fs[19]+fs0[19]);
    fs[20] = (fs[20]+fs0[20]);
    fs[21] = (fs[21]+fs0[21]);
/*
 Used -0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain   22 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     22 assignments
*/
}

void allegro_air_fsgenmult(void)
{

/*
Compute Fs (generic multiplier-generated forces)
*/
    allegro_air_dovpk();
    temp[0] = (((mfk[3][2]*Vpk[0][8][2])+((mfk[3][0]*Vpk[0][8][0])+(mfk[3][1]*
      Vpk[0][8][1])))+(((mfk[2][2]*Vpk[0][7][2])+((mfk[2][0]*Vpk[0][7][0])+(
      mfk[2][1]*Vpk[0][7][1])))+(((mfk[0][2]*Vpk[0][3][2])+((mfk[0][0]*
      Vpk[0][3][0])+(mfk[0][1]*Vpk[0][3][1])))+((mfk[1][2]*Vpk[0][6][2])+((
      mfk[1][0]*Vpk[0][6][0])+(mfk[1][1]*Vpk[0][6][1]))))));
    temp[1] = (((mfk[8][2]*Vpk[0][12][2])+((mfk[8][0]*Vpk[0][12][0])+(mfk[8][1]*
      Vpk[0][12][1])))+(((mfk[7][2]*Vpk[0][11][2])+((mfk[7][0]*Vpk[0][11][0])+(
      mfk[7][1]*Vpk[0][11][1])))+(((mfk[6][2]*Vpk[0][10][2])+((mfk[6][0]*
      Vpk[0][10][0])+(mfk[6][1]*Vpk[0][10][1])))+(((Vpk[0][9][2]*(mfk[4][2]+
      mfk[5][2]))+((Vpk[0][9][0]*(mfk[4][0]+mfk[5][0]))+(Vpk[0][9][1]*(mfk[4][1]
      +mfk[5][1]))))+temp[0]))));
    temp[2] = (((mfk[13][2]*Vpk[0][16][2])+((mfk[13][0]*Vpk[0][16][0])+(
      mfk[13][1]*Vpk[0][16][1])))+(((mfk[12][2]*Vpk[0][15][2])+((mfk[12][0]*
      Vpk[0][15][0])+(mfk[12][1]*Vpk[0][15][1])))+(((mfk[11][2]*Vpk[0][14][2])+(
      (mfk[11][0]*Vpk[0][14][0])+(mfk[11][1]*Vpk[0][14][1])))+(((Vpk[0][13][2]*(
      mfk[9][2]+mfk[10][2]))+((Vpk[0][13][0]*(mfk[9][0]+mfk[10][0]))+(
      Vpk[0][13][1]*(mfk[9][1]+mfk[10][1]))))+temp[1]))));
    temp[3] = (((mfk[18][2]*Vpk[0][20][2])+((mfk[18][0]*Vpk[0][20][0])+(
      mfk[18][1]*Vpk[0][20][1])))+(((mfk[17][2]*Vpk[0][19][2])+((mfk[17][0]*
      Vpk[0][19][0])+(mfk[17][1]*Vpk[0][19][1])))+(((mfk[16][2]*Vpk[0][18][2])+(
      (mfk[16][0]*Vpk[0][18][0])+(mfk[16][1]*Vpk[0][18][1])))+(((Vpk[0][17][2]*(
      mfk[14][2]+mfk[15][2]))+((Vpk[0][17][0]*(mfk[14][0]+mfk[15][0]))+(
      Vpk[0][17][1]*(mfk[14][1]+mfk[15][1]))))+temp[2]))));
    fs[0] = (mtau[0]+(((Vpk[0][21][2]*(mfk[19][2]+mfk[20][2]))+((Vpk[0][21][0]*(
      mfk[19][0]+mfk[20][0]))+(Vpk[0][21][1]*(mfk[19][1]+mfk[20][1]))))+temp[3])
      );
    temp[0] = (((mfk[3][2]*Vpk[1][8][2])+((mfk[3][0]*Vpk[1][8][0])+(mfk[3][1]*
      Vpk[1][8][1])))+(((mfk[2][2]*Vpk[1][7][2])+((mfk[2][0]*Vpk[1][7][0])+(
      mfk[2][1]*Vpk[1][7][1])))+(((mfk[0][2]*Vpk[1][3][2])+((mfk[0][0]*
      Vpk[1][3][0])+(mfk[0][1]*Vpk[1][3][1])))+((mfk[1][2]*Vpk[1][6][2])+((
      mfk[1][0]*Vpk[1][6][0])+(mfk[1][1]*Vpk[1][6][1]))))));
    temp[1] = (((mfk[8][2]*Vpk[1][12][2])+((mfk[8][0]*Vpk[1][12][0])+(mfk[8][1]*
      Vpk[1][12][1])))+(((mfk[7][2]*Vpk[1][11][2])+((mfk[7][0]*Vpk[1][11][0])+(
      mfk[7][1]*Vpk[1][11][1])))+(((mfk[6][2]*Vpk[1][10][2])+((mfk[6][0]*
      Vpk[1][10][0])+(mfk[6][1]*Vpk[1][10][1])))+(((Vpk[1][9][2]*(mfk[4][2]+
      mfk[5][2]))+((Vpk[1][9][0]*(mfk[4][0]+mfk[5][0]))+(Vpk[1][9][1]*(mfk[4][1]
      +mfk[5][1]))))+temp[0]))));
    temp[2] = (((mfk[13][2]*Vpk[1][16][2])+((mfk[13][0]*Vpk[1][16][0])+(
      mfk[13][1]*Vpk[1][16][1])))+(((mfk[12][2]*Vpk[1][15][2])+((mfk[12][0]*
      Vpk[1][15][0])+(mfk[12][1]*Vpk[1][15][1])))+(((mfk[11][2]*Vpk[1][14][2])+(
      (mfk[11][0]*Vpk[1][14][0])+(mfk[11][1]*Vpk[1][14][1])))+(((Vpk[1][13][2]*(
      mfk[9][2]+mfk[10][2]))+((Vpk[1][13][0]*(mfk[9][0]+mfk[10][0]))+(
      Vpk[1][13][1]*(mfk[9][1]+mfk[10][1]))))+temp[1]))));
    temp[3] = (((mfk[18][2]*Vpk[1][20][2])+((mfk[18][0]*Vpk[1][20][0])+(
      mfk[18][1]*Vpk[1][20][1])))+(((mfk[17][2]*Vpk[1][19][2])+((mfk[17][0]*
      Vpk[1][19][0])+(mfk[17][1]*Vpk[1][19][1])))+(((mfk[16][2]*Vpk[1][18][2])+(
      (mfk[16][0]*Vpk[1][18][0])+(mfk[16][1]*Vpk[1][18][1])))+(((Vpk[1][17][2]*(
      mfk[14][2]+mfk[15][2]))+((Vpk[1][17][0]*(mfk[14][0]+mfk[15][0]))+(
      Vpk[1][17][1]*(mfk[14][1]+mfk[15][1]))))+temp[2]))));
    fs[1] = (mtau[1]+(((Vpk[1][21][2]*(mfk[19][2]+mfk[20][2]))+((Vpk[1][21][0]*(
      mfk[19][0]+mfk[20][0]))+(Vpk[1][21][1]*(mfk[19][1]+mfk[20][1]))))+temp[3])
      );
    temp[0] = (((mfk[3][2]*Vpk[2][8][2])+((mfk[3][0]*Vpk[2][8][0])+(mfk[3][1]*
      Vpk[2][8][1])))+(((mfk[2][2]*Vpk[2][7][2])+((mfk[2][0]*Vpk[2][7][0])+(
      mfk[2][1]*Vpk[2][7][1])))+(((mfk[0][2]*Vpk[2][3][2])+((mfk[0][0]*
      Vpk[2][3][0])+(mfk[0][1]*Vpk[2][3][1])))+((mfk[1][2]*Vpk[2][6][2])+((
      mfk[1][0]*Vpk[2][6][0])+(mfk[1][1]*Vpk[2][6][1]))))));
    temp[1] = (((mfk[8][2]*Vpk[2][12][2])+((mfk[8][0]*Vpk[2][12][0])+(mfk[8][1]*
      Vpk[2][12][1])))+(((mfk[7][2]*Vpk[2][11][2])+((mfk[7][0]*Vpk[2][11][0])+(
      mfk[7][1]*Vpk[2][11][1])))+(((mfk[6][2]*Vpk[2][10][2])+((mfk[6][0]*
      Vpk[2][10][0])+(mfk[6][1]*Vpk[2][10][1])))+(((Vpk[2][9][2]*(mfk[4][2]+
      mfk[5][2]))+((Vpk[2][9][0]*(mfk[4][0]+mfk[5][0]))+(Vpk[2][9][1]*(mfk[4][1]
      +mfk[5][1]))))+temp[0]))));
    temp[2] = (((mfk[13][2]*Vpk[2][16][2])+((mfk[13][0]*Vpk[2][16][0])+(
      mfk[13][1]*Vpk[2][16][1])))+(((mfk[12][2]*Vpk[2][15][2])+((mfk[12][0]*
      Vpk[2][15][0])+(mfk[12][1]*Vpk[2][15][1])))+(((mfk[11][2]*Vpk[2][14][2])+(
      (mfk[11][0]*Vpk[2][14][0])+(mfk[11][1]*Vpk[2][14][1])))+(((Vpk[2][13][2]*(
      mfk[9][2]+mfk[10][2]))+((Vpk[2][13][0]*(mfk[9][0]+mfk[10][0]))+(
      Vpk[2][13][1]*(mfk[9][1]+mfk[10][1]))))+temp[1]))));
    temp[3] = (((mfk[18][2]*Vpk[2][20][2])+((mfk[18][0]*Vpk[2][20][0])+(
      mfk[18][1]*Vpk[2][20][1])))+(((mfk[17][2]*Vpk[2][19][2])+((mfk[17][0]*
      Vpk[2][19][0])+(mfk[17][1]*Vpk[2][19][1])))+(((mfk[16][2]*Vpk[2][18][2])+(
      (mfk[16][0]*Vpk[2][18][0])+(mfk[16][1]*Vpk[2][18][1])))+(((Vpk[2][17][2]*(
      mfk[14][2]+mfk[15][2]))+((Vpk[2][17][0]*(mfk[14][0]+mfk[15][0]))+(
      Vpk[2][17][1]*(mfk[14][1]+mfk[15][1]))))+temp[2]))));
    fs[2] = (mtau[2]+(((Vpk[2][21][2]*(mfk[19][2]+mfk[20][2]))+((Vpk[2][21][0]*(
      mfk[19][0]+mfk[20][0]))+(Vpk[2][21][1]*(mfk[19][1]+mfk[20][1]))))+temp[3])
      );
    temp[0] = (((((mfk[0][2]*rk[0][1])-(mfk[0][1]*rk[0][2]))-mtk[0][0])-(((
      Cik[6][0][2]*mtk[1][2])+((Cik[6][0][0]*mtk[1][0])+(Cik[6][0][1]*mtk[1][1])
      ))+((mfk[1][2]*Vpk[3][6][2])+((mfk[1][0]*Vpk[3][6][0])+(mfk[1][1]*
      Vpk[3][6][1])))))-(((mfk[2][2]*Vpk[3][7][2])+((mfk[2][0]*Vpk[3][7][0])+(
      mfk[2][1]*Vpk[3][7][1])))+((mtk[2][2]*Wpk[3][7][2])+((mtk[2][0]*
      Wpk[3][7][0])+(mtk[2][1]*Wpk[3][7][1])))));
    temp[1] = ((Wpk[3][9][0]*((mtk[4][0]+((mfk[4][2]*rcom[4][1])-(mfk[4][1]*
      rcom[4][2])))+(mtk[5][0]+((mfk[5][2]*rcom[5][1])-(mfk[5][1]*rcom[5][2]))))
      )+(Wpk[3][9][1]*((mtk[4][1]+((mfk[4][0]*rcom[4][2])-(mfk[4][2]*rcom[4][0])
      ))+(mtk[5][1]+((mfk[5][0]*rcom[5][2])-(mfk[5][2]*rcom[5][0]))))));
    temp[2] = (((Vpk[3][9][2]*(mfk[4][2]+mfk[5][2]))+((Vpk[3][9][0]*(mfk[4][0]+
      mfk[5][0]))+(Vpk[3][9][1]*(mfk[4][1]+mfk[5][1]))))+((Wpk[3][9][2]*((
      mtk[4][2]+((mfk[4][1]*rcom[4][0])-(mfk[4][0]*rcom[4][1])))+(mtk[5][2]+((
      mfk[5][1]*rcom[5][0])-(mfk[5][0]*rcom[5][1])))))+temp[1]));
    temp[3] = (((temp[0]-(((mfk[3][2]*Vpk[3][8][2])+((mfk[3][0]*Vpk[3][8][0])+(
      mfk[3][1]*Vpk[3][8][1])))+((mtk[3][2]*Wpk[3][8][2])+((mtk[3][0]*
      Wpk[3][8][0])+(mtk[3][1]*Wpk[3][8][1])))))-temp[2])-(((Cik[10][0][2]*
      mtk[6][2])+((Cik[10][0][0]*mtk[6][0])+(Cik[10][0][1]*mtk[6][1])))+((
      mfk[6][2]*Vpk[3][10][2])+((mfk[6][0]*Vpk[3][10][0])+(mfk[6][1]*
      Vpk[3][10][1])))));
    temp[4] = ((Wpk[3][13][0]*((mtk[9][0]+((mfk[9][2]*rcom[9][1])-(mfk[9][1]*
      rcom[9][2])))+(mtk[10][0]+((mfk[10][2]*rcom[10][1])-(mfk[10][1]*
      rcom[10][2])))))+(Wpk[3][13][1]*((mtk[9][1]+((mfk[9][0]*rcom[9][2])-(
      mfk[9][2]*rcom[9][0])))+(mtk[10][1]+((mfk[10][0]*rcom[10][2])-(mfk[10][2]*
      rcom[10][0]))))));
    temp[5] = ((temp[3]-(((mfk[7][2]*Vpk[3][11][2])+((mfk[7][0]*Vpk[3][11][0])+(
      mfk[7][1]*Vpk[3][11][1])))+((mtk[7][2]*Wpk[3][11][2])+((mtk[7][0]*
      Wpk[3][11][0])+(mtk[7][1]*Wpk[3][11][1])))))-(((mfk[8][2]*Vpk[3][12][2])+(
      (mfk[8][0]*Vpk[3][12][0])+(mfk[8][1]*Vpk[3][12][1])))+((mtk[8][2]*
      Wpk[3][12][2])+((mtk[8][0]*Wpk[3][12][0])+(mtk[8][1]*Wpk[3][12][1])))));
    temp[6] = (temp[5]-(((Vpk[3][13][2]*(mfk[9][2]+mfk[10][2]))+((Vpk[3][13][0]*
      (mfk[9][0]+mfk[10][0]))+(Vpk[3][13][1]*(mfk[9][1]+mfk[10][1]))))+((
      Wpk[3][13][2]*((mtk[9][2]+((mfk[9][1]*rcom[9][0])-(mfk[9][0]*rcom[9][1])))
      +(mtk[10][2]+((mfk[10][1]*rcom[10][0])-(mfk[10][0]*rcom[10][1])))))+
      temp[4])));
    temp[7] = ((temp[6]-(((Cik[14][0][2]*mtk[11][2])+((Cik[14][0][0]*mtk[11][0])
      +(Cik[14][0][1]*mtk[11][1])))+((mfk[11][2]*Vpk[3][14][2])+((mfk[11][0]*
      Vpk[3][14][0])+(mfk[11][1]*Vpk[3][14][1])))))-(((mfk[12][2]*Vpk[3][15][2])
      +((mfk[12][0]*Vpk[3][15][0])+(mfk[12][1]*Vpk[3][15][1])))+((mtk[12][2]*
      Wpk[3][15][2])+((mtk[12][0]*Wpk[3][15][0])+(mtk[12][1]*Wpk[3][15][1])))));
    temp[8] = ((Wpk[3][17][0]*((mtk[14][0]+((mfk[14][2]*rcom[14][1])-(mfk[14][1]
      *rcom[14][2])))+(mtk[15][0]+((mfk[15][2]*rcom[15][1])-(mfk[15][1]*
      rcom[15][2])))))+(Wpk[3][17][1]*((mtk[14][1]+((mfk[14][0]*rcom[14][2])-(
      mfk[14][2]*rcom[14][0])))+(mtk[15][1]+((mfk[15][0]*rcom[15][2])-(
      mfk[15][2]*rcom[15][0]))))));
    temp[9] = (((Vpk[3][17][2]*(mfk[14][2]+mfk[15][2]))+((Vpk[3][17][0]*(
      mfk[14][0]+mfk[15][0]))+(Vpk[3][17][1]*(mfk[14][1]+mfk[15][1]))))+((
      Wpk[3][17][2]*((mtk[14][2]+((mfk[14][1]*rcom[14][0])-(mfk[14][0]*
      rcom[14][1])))+(mtk[15][2]+((mfk[15][1]*rcom[15][0])-(mfk[15][0]*
      rcom[15][1])))))+temp[8]));
    temp[10] = (((temp[7]-(((mfk[13][2]*Vpk[3][16][2])+((mfk[13][0]*
      Vpk[3][16][0])+(mfk[13][1]*Vpk[3][16][1])))+((mtk[13][2]*Wpk[3][16][2])+((
      mtk[13][0]*Wpk[3][16][0])+(mtk[13][1]*Wpk[3][16][1])))))-temp[9])-(((
      Cik[18][0][2]*mtk[16][2])+((Cik[18][0][0]*mtk[16][0])+(Cik[18][0][1]*
      mtk[16][1])))+((mfk[16][2]*Vpk[3][18][2])+((mfk[16][0]*Vpk[3][18][0])+(
      mfk[16][1]*Vpk[3][18][1])))));
    temp[11] = ((Wpk[3][21][0]*((mtk[19][0]+((mfk[19][2]*rcom[19][1])-(
      mfk[19][1]*rcom[19][2])))+(mtk[20][0]+((mfk[20][2]*rcom[20][1])-(
      mfk[20][1]*rcom[20][2])))))+(Wpk[3][21][1]*((mtk[19][1]+((mfk[19][0]*
      rcom[19][2])-(mfk[19][2]*rcom[19][0])))+(mtk[20][1]+((mfk[20][0]*
      rcom[20][2])-(mfk[20][2]*rcom[20][0]))))));
    temp[12] = ((temp[10]-(((mfk[17][2]*Vpk[3][19][2])+((mfk[17][0]*
      Vpk[3][19][0])+(mfk[17][1]*Vpk[3][19][1])))+((mtk[17][2]*Wpk[3][19][2])+((
      mtk[17][0]*Wpk[3][19][0])+(mtk[17][1]*Wpk[3][19][1])))))-(((mfk[18][2]*
      Vpk[3][20][2])+((mfk[18][0]*Vpk[3][20][0])+(mfk[18][1]*Vpk[3][20][1])))+((
      mtk[18][2]*Wpk[3][20][2])+((mtk[18][0]*Wpk[3][20][0])+(mtk[18][1]*
      Wpk[3][20][1])))));
    fs[3] = (mtau[3]-(temp[12]-(((Vpk[3][21][2]*(mfk[19][2]+mfk[20][2]))+((
      Vpk[3][21][0]*(mfk[19][0]+mfk[20][0]))+(Vpk[3][21][1]*(mfk[19][1]+
      mfk[20][1]))))+((Wpk[3][21][2]*((mtk[19][2]+((mfk[19][1]*rcom[19][0])-(
      mfk[19][0]*rcom[19][1])))+(mtk[20][2]+((mfk[20][1]*rcom[20][0])-(
      mfk[20][0]*rcom[20][1])))))+temp[11]))));
    temp[0] = (((((mfk[0][0]*rk[0][2])-(mfk[0][2]*rk[0][0]))-mtk[0][1])-(((
      Cik[6][1][2]*mtk[1][2])+((Cik[6][1][0]*mtk[1][0])+(Cik[6][1][1]*mtk[1][1])
      ))+((mfk[1][2]*Vpk[4][6][2])+((mfk[1][0]*Vpk[4][6][0])+(mfk[1][1]*
      Vpk[4][6][1])))))-(((mfk[2][2]*Vpk[4][7][2])+((mfk[2][0]*Vpk[4][7][0])+(
      mfk[2][1]*Vpk[4][7][1])))+((mtk[2][2]*Wpk[4][7][2])+((mtk[2][0]*
      Wpk[4][7][0])+(mtk[2][1]*Wpk[4][7][1])))));
    temp[1] = ((Wpk[4][9][0]*((mtk[4][0]+((mfk[4][2]*rcom[4][1])-(mfk[4][1]*
      rcom[4][2])))+(mtk[5][0]+((mfk[5][2]*rcom[5][1])-(mfk[5][1]*rcom[5][2]))))
      )+(Wpk[4][9][1]*((mtk[4][1]+((mfk[4][0]*rcom[4][2])-(mfk[4][2]*rcom[4][0])
      ))+(mtk[5][1]+((mfk[5][0]*rcom[5][2])-(mfk[5][2]*rcom[5][0]))))));
    temp[2] = (((Vpk[4][9][2]*(mfk[4][2]+mfk[5][2]))+((Vpk[4][9][0]*(mfk[4][0]+
      mfk[5][0]))+(Vpk[4][9][1]*(mfk[4][1]+mfk[5][1]))))+((Wpk[4][9][2]*((
      mtk[4][2]+((mfk[4][1]*rcom[4][0])-(mfk[4][0]*rcom[4][1])))+(mtk[5][2]+((
      mfk[5][1]*rcom[5][0])-(mfk[5][0]*rcom[5][1])))))+temp[1]));
    temp[3] = (((temp[0]-(((mfk[3][2]*Vpk[4][8][2])+((mfk[3][0]*Vpk[4][8][0])+(
      mfk[3][1]*Vpk[4][8][1])))+((mtk[3][2]*Wpk[4][8][2])+((mtk[3][0]*
      Wpk[4][8][0])+(mtk[3][1]*Wpk[4][8][1])))))-temp[2])-(((Cik[10][1][2]*
      mtk[6][2])+((Cik[10][1][0]*mtk[6][0])+(Cik[10][1][1]*mtk[6][1])))+((
      mfk[6][2]*Vpk[4][10][2])+((mfk[6][0]*Vpk[4][10][0])+(mfk[6][1]*
      Vpk[4][10][1])))));
    temp[4] = ((Wpk[4][13][0]*((mtk[9][0]+((mfk[9][2]*rcom[9][1])-(mfk[9][1]*
      rcom[9][2])))+(mtk[10][0]+((mfk[10][2]*rcom[10][1])-(mfk[10][1]*
      rcom[10][2])))))+(Wpk[4][13][1]*((mtk[9][1]+((mfk[9][0]*rcom[9][2])-(
      mfk[9][2]*rcom[9][0])))+(mtk[10][1]+((mfk[10][0]*rcom[10][2])-(mfk[10][2]*
      rcom[10][0]))))));
    temp[5] = ((temp[3]-(((mfk[7][2]*Vpk[4][11][2])+((mfk[7][0]*Vpk[4][11][0])+(
      mfk[7][1]*Vpk[4][11][1])))+((mtk[7][2]*Wpk[4][11][2])+((mtk[7][0]*
      Wpk[4][11][0])+(mtk[7][1]*Wpk[4][11][1])))))-(((mfk[8][2]*Vpk[4][12][2])+(
      (mfk[8][0]*Vpk[4][12][0])+(mfk[8][1]*Vpk[4][12][1])))+((mtk[8][2]*
      Wpk[4][12][2])+((mtk[8][0]*Wpk[4][12][0])+(mtk[8][1]*Wpk[4][12][1])))));
    temp[6] = (temp[5]-(((Vpk[4][13][2]*(mfk[9][2]+mfk[10][2]))+((Vpk[4][13][0]*
      (mfk[9][0]+mfk[10][0]))+(Vpk[4][13][1]*(mfk[9][1]+mfk[10][1]))))+((
      Wpk[4][13][2]*((mtk[9][2]+((mfk[9][1]*rcom[9][0])-(mfk[9][0]*rcom[9][1])))
      +(mtk[10][2]+((mfk[10][1]*rcom[10][0])-(mfk[10][0]*rcom[10][1])))))+
      temp[4])));
    temp[7] = ((temp[6]-(((Cik[14][1][2]*mtk[11][2])+((Cik[14][1][0]*mtk[11][0])
      +(Cik[14][1][1]*mtk[11][1])))+((mfk[11][2]*Vpk[4][14][2])+((mfk[11][0]*
      Vpk[4][14][0])+(mfk[11][1]*Vpk[4][14][1])))))-(((mfk[12][2]*Vpk[4][15][2])
      +((mfk[12][0]*Vpk[4][15][0])+(mfk[12][1]*Vpk[4][15][1])))+((mtk[12][2]*
      Wpk[4][15][2])+((mtk[12][0]*Wpk[4][15][0])+(mtk[12][1]*Wpk[4][15][1])))));
    temp[8] = ((Wpk[4][17][0]*((mtk[14][0]+((mfk[14][2]*rcom[14][1])-(mfk[14][1]
      *rcom[14][2])))+(mtk[15][0]+((mfk[15][2]*rcom[15][1])-(mfk[15][1]*
      rcom[15][2])))))+(Wpk[4][17][1]*((mtk[14][1]+((mfk[14][0]*rcom[14][2])-(
      mfk[14][2]*rcom[14][0])))+(mtk[15][1]+((mfk[15][0]*rcom[15][2])-(
      mfk[15][2]*rcom[15][0]))))));
    temp[9] = (((Vpk[4][17][2]*(mfk[14][2]+mfk[15][2]))+((Vpk[4][17][0]*(
      mfk[14][0]+mfk[15][0]))+(Vpk[4][17][1]*(mfk[14][1]+mfk[15][1]))))+((
      Wpk[4][17][2]*((mtk[14][2]+((mfk[14][1]*rcom[14][0])-(mfk[14][0]*
      rcom[14][1])))+(mtk[15][2]+((mfk[15][1]*rcom[15][0])-(mfk[15][0]*
      rcom[15][1])))))+temp[8]));
    temp[10] = (((temp[7]-(((mfk[13][2]*Vpk[4][16][2])+((mfk[13][0]*
      Vpk[4][16][0])+(mfk[13][1]*Vpk[4][16][1])))+((mtk[13][2]*Wpk[4][16][2])+((
      mtk[13][0]*Wpk[4][16][0])+(mtk[13][1]*Wpk[4][16][1])))))-temp[9])-(((
      Cik[18][1][2]*mtk[16][2])+((Cik[18][1][0]*mtk[16][0])+(Cik[18][1][1]*
      mtk[16][1])))+((mfk[16][2]*Vpk[4][18][2])+((mfk[16][0]*Vpk[4][18][0])+(
      mfk[16][1]*Vpk[4][18][1])))));
    temp[11] = ((Wpk[4][21][0]*((mtk[19][0]+((mfk[19][2]*rcom[19][1])-(
      mfk[19][1]*rcom[19][2])))+(mtk[20][0]+((mfk[20][2]*rcom[20][1])-(
      mfk[20][1]*rcom[20][2])))))+(Wpk[4][21][1]*((mtk[19][1]+((mfk[19][0]*
      rcom[19][2])-(mfk[19][2]*rcom[19][0])))+(mtk[20][1]+((mfk[20][0]*
      rcom[20][2])-(mfk[20][2]*rcom[20][0]))))));
    temp[12] = ((temp[10]-(((mfk[17][2]*Vpk[4][19][2])+((mfk[17][0]*
      Vpk[4][19][0])+(mfk[17][1]*Vpk[4][19][1])))+((mtk[17][2]*Wpk[4][19][2])+((
      mtk[17][0]*Wpk[4][19][0])+(mtk[17][1]*Wpk[4][19][1])))))-(((mfk[18][2]*
      Vpk[4][20][2])+((mfk[18][0]*Vpk[4][20][0])+(mfk[18][1]*Vpk[4][20][1])))+((
      mtk[18][2]*Wpk[4][20][2])+((mtk[18][0]*Wpk[4][20][0])+(mtk[18][1]*
      Wpk[4][20][1])))));
    fs[4] = (mtau[4]-(temp[12]-(((Vpk[4][21][2]*(mfk[19][2]+mfk[20][2]))+((
      Vpk[4][21][0]*(mfk[19][0]+mfk[20][0]))+(Vpk[4][21][1]*(mfk[19][1]+
      mfk[20][1]))))+((Wpk[4][21][2]*((mtk[19][2]+((mfk[19][1]*rcom[19][0])-(
      mfk[19][0]*rcom[19][1])))+(mtk[20][2]+((mfk[20][1]*rcom[20][0])-(
      mfk[20][0]*rcom[20][1])))))+temp[11]))));
    temp[0] = (((((mfk[0][1]*rk[0][0])-(mfk[0][0]*rk[0][1]))-mtk[0][2])-(((
      Cik[6][2][2]*mtk[1][2])+((Cik[6][2][0]*mtk[1][0])+(Cik[6][2][1]*mtk[1][1])
      ))+((mfk[1][2]*Vpk[5][6][2])+((mfk[1][0]*Vpk[5][6][0])+(mfk[1][1]*
      Vpk[5][6][1])))))-(((mfk[2][2]*Vpk[5][7][2])+((mfk[2][0]*Vpk[5][7][0])+(
      mfk[2][1]*Vpk[5][7][1])))+((mtk[2][2]*Wpk[5][7][2])+((mtk[2][0]*
      Wpk[5][7][0])+(mtk[2][1]*Wpk[5][7][1])))));
    temp[1] = ((Wpk[5][9][0]*((mtk[4][0]+((mfk[4][2]*rcom[4][1])-(mfk[4][1]*
      rcom[4][2])))+(mtk[5][0]+((mfk[5][2]*rcom[5][1])-(mfk[5][1]*rcom[5][2]))))
      )+(Wpk[5][9][1]*((mtk[4][1]+((mfk[4][0]*rcom[4][2])-(mfk[4][2]*rcom[4][0])
      ))+(mtk[5][1]+((mfk[5][0]*rcom[5][2])-(mfk[5][2]*rcom[5][0]))))));
    temp[2] = (((Vpk[5][9][2]*(mfk[4][2]+mfk[5][2]))+((Vpk[5][9][0]*(mfk[4][0]+
      mfk[5][0]))+(Vpk[5][9][1]*(mfk[4][1]+mfk[5][1]))))+((Wpk[5][9][2]*((
      mtk[4][2]+((mfk[4][1]*rcom[4][0])-(mfk[4][0]*rcom[4][1])))+(mtk[5][2]+((
      mfk[5][1]*rcom[5][0])-(mfk[5][0]*rcom[5][1])))))+temp[1]));
    temp[3] = (((temp[0]-(((mfk[3][2]*Vpk[5][8][2])+((mfk[3][0]*Vpk[5][8][0])+(
      mfk[3][1]*Vpk[5][8][1])))+((mtk[3][2]*Wpk[5][8][2])+((mtk[3][0]*
      Wpk[5][8][0])+(mtk[3][1]*Wpk[5][8][1])))))-temp[2])-(((Cik[10][2][2]*
      mtk[6][2])+((Cik[10][2][0]*mtk[6][0])+(Cik[10][2][1]*mtk[6][1])))+((
      mfk[6][2]*Vpk[5][10][2])+((mfk[6][0]*Vpk[5][10][0])+(mfk[6][1]*
      Vpk[5][10][1])))));
    temp[4] = ((Wpk[5][13][0]*((mtk[9][0]+((mfk[9][2]*rcom[9][1])-(mfk[9][1]*
      rcom[9][2])))+(mtk[10][0]+((mfk[10][2]*rcom[10][1])-(mfk[10][1]*
      rcom[10][2])))))+(Wpk[5][13][1]*((mtk[9][1]+((mfk[9][0]*rcom[9][2])-(
      mfk[9][2]*rcom[9][0])))+(mtk[10][1]+((mfk[10][0]*rcom[10][2])-(mfk[10][2]*
      rcom[10][0]))))));
    temp[5] = ((temp[3]-(((mfk[7][2]*Vpk[5][11][2])+((mfk[7][0]*Vpk[5][11][0])+(
      mfk[7][1]*Vpk[5][11][1])))+((mtk[7][2]*Wpk[5][11][2])+((mtk[7][0]*
      Wpk[5][11][0])+(mtk[7][1]*Wpk[5][11][1])))))-(((mfk[8][2]*Vpk[5][12][2])+(
      (mfk[8][0]*Vpk[5][12][0])+(mfk[8][1]*Vpk[5][12][1])))+((mtk[8][2]*
      Wpk[5][12][2])+((mtk[8][0]*Wpk[5][12][0])+(mtk[8][1]*Wpk[5][12][1])))));
    temp[6] = (temp[5]-(((Vpk[5][13][2]*(mfk[9][2]+mfk[10][2]))+((Vpk[5][13][0]*
      (mfk[9][0]+mfk[10][0]))+(Vpk[5][13][1]*(mfk[9][1]+mfk[10][1]))))+((
      Wpk[5][13][2]*((mtk[9][2]+((mfk[9][1]*rcom[9][0])-(mfk[9][0]*rcom[9][1])))
      +(mtk[10][2]+((mfk[10][1]*rcom[10][0])-(mfk[10][0]*rcom[10][1])))))+
      temp[4])));
    temp[7] = ((temp[6]-(((Cik[14][2][2]*mtk[11][2])+((Cik[14][2][0]*mtk[11][0])
      +(Cik[14][2][1]*mtk[11][1])))+((mfk[11][2]*Vpk[5][14][2])+((mfk[11][0]*
      Vpk[5][14][0])+(mfk[11][1]*Vpk[5][14][1])))))-(((mfk[12][2]*Vpk[5][15][2])
      +((mfk[12][0]*Vpk[5][15][0])+(mfk[12][1]*Vpk[5][15][1])))+((mtk[12][2]*
      Wpk[5][15][2])+((mtk[12][0]*Wpk[5][15][0])+(mtk[12][1]*Wpk[5][15][1])))));
    temp[8] = ((Wpk[5][17][0]*((mtk[14][0]+((mfk[14][2]*rcom[14][1])-(mfk[14][1]
      *rcom[14][2])))+(mtk[15][0]+((mfk[15][2]*rcom[15][1])-(mfk[15][1]*
      rcom[15][2])))))+(Wpk[5][17][1]*((mtk[14][1]+((mfk[14][0]*rcom[14][2])-(
      mfk[14][2]*rcom[14][0])))+(mtk[15][1]+((mfk[15][0]*rcom[15][2])-(
      mfk[15][2]*rcom[15][0]))))));
    temp[9] = (((Vpk[5][17][2]*(mfk[14][2]+mfk[15][2]))+((Vpk[5][17][0]*(
      mfk[14][0]+mfk[15][0]))+(Vpk[5][17][1]*(mfk[14][1]+mfk[15][1]))))+((
      Wpk[5][17][2]*((mtk[14][2]+((mfk[14][1]*rcom[14][0])-(mfk[14][0]*
      rcom[14][1])))+(mtk[15][2]+((mfk[15][1]*rcom[15][0])-(mfk[15][0]*
      rcom[15][1])))))+temp[8]));
    temp[10] = (((temp[7]-(((mfk[13][2]*Vpk[5][16][2])+((mfk[13][0]*
      Vpk[5][16][0])+(mfk[13][1]*Vpk[5][16][1])))+((mtk[13][2]*Wpk[5][16][2])+((
      mtk[13][0]*Wpk[5][16][0])+(mtk[13][1]*Wpk[5][16][1])))))-temp[9])-(((
      Cik[18][2][2]*mtk[16][2])+((Cik[18][2][0]*mtk[16][0])+(Cik[18][2][1]*
      mtk[16][1])))+((mfk[16][2]*Vpk[5][18][2])+((mfk[16][0]*Vpk[5][18][0])+(
      mfk[16][1]*Vpk[5][18][1])))));
    temp[11] = ((Wpk[5][21][0]*((mtk[19][0]+((mfk[19][2]*rcom[19][1])-(
      mfk[19][1]*rcom[19][2])))+(mtk[20][0]+((mfk[20][2]*rcom[20][1])-(
      mfk[20][1]*rcom[20][2])))))+(Wpk[5][21][1]*((mtk[19][1]+((mfk[19][0]*
      rcom[19][2])-(mfk[19][2]*rcom[19][0])))+(mtk[20][1]+((mfk[20][0]*
      rcom[20][2])-(mfk[20][2]*rcom[20][0]))))));
    temp[12] = ((temp[10]-(((mfk[17][2]*Vpk[5][19][2])+((mfk[17][0]*
      Vpk[5][19][0])+(mfk[17][1]*Vpk[5][19][1])))+((mtk[17][2]*Wpk[5][19][2])+((
      mtk[17][0]*Wpk[5][19][0])+(mtk[17][1]*Wpk[5][19][1])))))-(((mfk[18][2]*
      Vpk[5][20][2])+((mfk[18][0]*Vpk[5][20][0])+(mfk[18][1]*Vpk[5][20][1])))+((
      mtk[18][2]*Wpk[5][20][2])+((mtk[18][0]*Wpk[5][20][0])+(mtk[18][1]*
      Wpk[5][20][1])))));
    fs[5] = (mtau[5]-(temp[12]-(((Vpk[5][21][2]*(mfk[19][2]+mfk[20][2]))+((
      Vpk[5][21][0]*(mfk[19][0]+mfk[20][0]))+(Vpk[5][21][1]*(mfk[19][1]+
      mfk[20][1]))))+((Wpk[5][21][2]*((mtk[19][2]+((mfk[19][1]*rcom[19][0])-(
      mfk[19][0]*rcom[19][1])))+(mtk[20][2]+((mfk[20][1]*rcom[20][0])-(
      mfk[20][0]*rcom[20][1])))))+temp[11]))));
    temp[0] = ((Wpk[6][9][0]*((mtk[4][0]+((mfk[4][2]*rcom[4][1])-(mfk[4][1]*
      rcom[4][2])))+(mtk[5][0]+((mfk[5][2]*rcom[5][1])-(mfk[5][1]*rcom[5][2]))))
      )+(Wpk[6][9][1]*((mtk[4][1]+((mfk[4][0]*rcom[4][2])-(mfk[4][2]*rcom[4][0])
      ))+(mtk[5][1]+((mfk[5][0]*rcom[5][2])-(mfk[5][2]*rcom[5][0]))))));
    temp[1] = ((((mfk[1][2]*Vpk[6][6][2])+((mfk[1][0]*Vpk[6][6][0])+(mfk[1][1]*
      Vpk[6][6][1])))+((mtk[1][2]*pin[6][2])+((mtk[1][0]*pin[6][0])+(mtk[1][1]*
      pin[6][1]))))+(((mfk[2][2]*Vpk[6][7][2])+((mfk[2][0]*Vpk[6][7][0])+(
      mfk[2][1]*Vpk[6][7][1])))+((mtk[2][2]*Wpk[6][7][2])+((mtk[2][0]*
      Wpk[6][7][0])+(mtk[2][1]*Wpk[6][7][1])))));
    temp[2] = (((Vpk[6][9][2]*(mfk[4][2]+mfk[5][2]))+((Vpk[6][9][0]*(mfk[4][0]+
      mfk[5][0]))+(Vpk[6][9][1]*(mfk[4][1]+mfk[5][1]))))+((Wpk[6][9][2]*((
      mtk[4][2]+((mfk[4][1]*rcom[4][0])-(mfk[4][0]*rcom[4][1])))+(mtk[5][2]+((
      mfk[5][1]*rcom[5][0])-(mfk[5][0]*rcom[5][1])))))+temp[0]));
    fs[6] = (mtau[6]+(temp[2]+((((mfk[3][2]*Vpk[6][8][2])+((mfk[3][0]*
      Vpk[6][8][0])+(mfk[3][1]*Vpk[6][8][1])))+((mtk[3][2]*Wpk[6][8][2])+((
      mtk[3][0]*Wpk[6][8][0])+(mtk[3][1]*Wpk[6][8][1]))))+temp[1])));
    temp[0] = ((Wpk[7][9][0]*((mtk[4][0]+((mfk[4][2]*rcom[4][1])-(mfk[4][1]*
      rcom[4][2])))+(mtk[5][0]+((mfk[5][2]*rcom[5][1])-(mfk[5][1]*rcom[5][2]))))
      )+(Wpk[7][9][1]*((mtk[4][1]+((mfk[4][0]*rcom[4][2])-(mfk[4][2]*rcom[4][0])
      ))+(mtk[5][1]+((mfk[5][0]*rcom[5][2])-(mfk[5][2]*rcom[5][0]))))));
    temp[1] = ((((mfk[2][2]*Vpk[7][7][2])+((mfk[2][0]*Vpk[7][7][0])+(mfk[2][1]*
      Vpk[7][7][1])))+((mtk[2][2]*pin[7][2])+((mtk[2][0]*pin[7][0])+(mtk[2][1]*
      pin[7][1]))))+(((mfk[3][2]*Vpk[7][8][2])+((mfk[3][0]*Vpk[7][8][0])+(
      mfk[3][1]*Vpk[7][8][1])))+((mtk[3][2]*Wpk[7][8][2])+((mtk[3][0]*
      Wpk[7][8][0])+(mtk[3][1]*Wpk[7][8][1])))));
    fs[7] = (mtau[7]+((((Vpk[7][9][2]*(mfk[4][2]+mfk[5][2]))+((Vpk[7][9][0]*(
      mfk[4][0]+mfk[5][0]))+(Vpk[7][9][1]*(mfk[4][1]+mfk[5][1]))))+((
      Wpk[7][9][2]*((mtk[4][2]+((mfk[4][1]*rcom[4][0])-(mfk[4][0]*rcom[4][1])))+
      (mtk[5][2]+((mfk[5][1]*rcom[5][0])-(mfk[5][0]*rcom[5][1])))))+temp[0]))+
      temp[1]));
    temp[0] = ((Wpk[8][9][0]*((mtk[4][0]+((mfk[4][2]*rcom[4][1])-(mfk[4][1]*
      rcom[4][2])))+(mtk[5][0]+((mfk[5][2]*rcom[5][1])-(mfk[5][1]*rcom[5][2]))))
      )+(Wpk[8][9][1]*((mtk[4][1]+((mfk[4][0]*rcom[4][2])-(mfk[4][2]*rcom[4][0])
      ))+(mtk[5][1]+((mfk[5][0]*rcom[5][2])-(mfk[5][2]*rcom[5][0]))))));
    temp[1] = (((Vpk[8][9][2]*(mfk[4][2]+mfk[5][2]))+((Vpk[8][9][0]*(mfk[4][0]+
      mfk[5][0]))+(Vpk[8][9][1]*(mfk[4][1]+mfk[5][1]))))+((Wpk[8][9][2]*((
      mtk[4][2]+((mfk[4][1]*rcom[4][0])-(mfk[4][0]*rcom[4][1])))+(mtk[5][2]+((
      mfk[5][1]*rcom[5][0])-(mfk[5][0]*rcom[5][1])))))+temp[0]));
    fs[8] = (mtau[8]+((((mfk[3][2]*Vpk[8][8][2])+((mfk[3][0]*Vpk[8][8][0])+(
      mfk[3][1]*Vpk[8][8][1])))+((mtk[3][2]*pin[8][2])+((mtk[3][0]*pin[8][0])+(
      mtk[3][1]*pin[8][1]))))+temp[1]));
    temp[0] = ((pin[9][2]*((mtk[4][2]+((mfk[4][1]*rcom[4][0])-(mfk[4][0]*
      rcom[4][1])))+(mtk[5][2]+((mfk[5][1]*rcom[5][0])-(mfk[5][0]*rcom[5][1]))))
      )+((pin[9][0]*((mtk[4][0]+((mfk[4][2]*rcom[4][1])-(mfk[4][1]*rcom[4][2])))
      +(mtk[5][0]+((mfk[5][2]*rcom[5][1])-(mfk[5][1]*rcom[5][2])))))+(pin[9][1]*
      ((mtk[4][1]+((mfk[4][0]*rcom[4][2])-(mfk[4][2]*rcom[4][0])))+(mtk[5][1]+((
      mfk[5][0]*rcom[5][2])-(mfk[5][2]*rcom[5][0])))))));
    fs[9] = (mtau[9]+(temp[0]+((Vpk[9][9][2]*(mfk[4][2]+mfk[5][2]))+((
      Vpk[9][9][0]*(mfk[4][0]+mfk[5][0]))+(Vpk[9][9][1]*(mfk[4][1]+mfk[5][1]))))
      ));
    temp[0] = ((Wpk[10][13][0]*((mtk[9][0]+((mfk[9][2]*rcom[9][1])-(mfk[9][1]*
      rcom[9][2])))+(mtk[10][0]+((mfk[10][2]*rcom[10][1])-(mfk[10][1]*
      rcom[10][2])))))+(Wpk[10][13][1]*((mtk[9][1]+((mfk[9][0]*rcom[9][2])-(
      mfk[9][2]*rcom[9][0])))+(mtk[10][1]+((mfk[10][0]*rcom[10][2])-(mfk[10][2]*
      rcom[10][0]))))));
    temp[1] = ((((mfk[6][2]*Vpk[10][10][2])+((mfk[6][0]*Vpk[10][10][0])+(
      mfk[6][1]*Vpk[10][10][1])))+((mtk[6][2]*pin[10][2])+((mtk[6][0]*pin[10][0]
      )+(mtk[6][1]*pin[10][1]))))+(((mfk[7][2]*Vpk[10][11][2])+((mfk[7][0]*
      Vpk[10][11][0])+(mfk[7][1]*Vpk[10][11][1])))+((mtk[7][2]*Wpk[10][11][2])+(
      (mtk[7][0]*Wpk[10][11][0])+(mtk[7][1]*Wpk[10][11][1])))));
    temp[2] = (((Vpk[10][13][2]*(mfk[9][2]+mfk[10][2]))+((Vpk[10][13][0]*(
      mfk[9][0]+mfk[10][0]))+(Vpk[10][13][1]*(mfk[9][1]+mfk[10][1]))))+((
      Wpk[10][13][2]*((mtk[9][2]+((mfk[9][1]*rcom[9][0])-(mfk[9][0]*rcom[9][1]))
      )+(mtk[10][2]+((mfk[10][1]*rcom[10][0])-(mfk[10][0]*rcom[10][1])))))+
      temp[0]));
    fs[10] = (mtau[10]+(temp[2]+((((mfk[8][2]*Vpk[10][12][2])+((mfk[8][0]*
      Vpk[10][12][0])+(mfk[8][1]*Vpk[10][12][1])))+((mtk[8][2]*Wpk[10][12][2])+(
      (mtk[8][0]*Wpk[10][12][0])+(mtk[8][1]*Wpk[10][12][1]))))+temp[1])));
    temp[0] = ((Wpk[11][13][0]*((mtk[9][0]+((mfk[9][2]*rcom[9][1])-(mfk[9][1]*
      rcom[9][2])))+(mtk[10][0]+((mfk[10][2]*rcom[10][1])-(mfk[10][1]*
      rcom[10][2])))))+(Wpk[11][13][1]*((mtk[9][1]+((mfk[9][0]*rcom[9][2])-(
      mfk[9][2]*rcom[9][0])))+(mtk[10][1]+((mfk[10][0]*rcom[10][2])-(mfk[10][2]*
      rcom[10][0]))))));
    temp[1] = ((((mfk[7][2]*Vpk[11][11][2])+((mfk[7][0]*Vpk[11][11][0])+(
      mfk[7][1]*Vpk[11][11][1])))+((mtk[7][2]*pin[11][2])+((mtk[7][0]*pin[11][0]
      )+(mtk[7][1]*pin[11][1]))))+(((mfk[8][2]*Vpk[11][12][2])+((mfk[8][0]*
      Vpk[11][12][0])+(mfk[8][1]*Vpk[11][12][1])))+((mtk[8][2]*Wpk[11][12][2])+(
      (mtk[8][0]*Wpk[11][12][0])+(mtk[8][1]*Wpk[11][12][1])))));
    fs[11] = (mtau[11]+((((Vpk[11][13][2]*(mfk[9][2]+mfk[10][2]))+((
      Vpk[11][13][0]*(mfk[9][0]+mfk[10][0]))+(Vpk[11][13][1]*(mfk[9][1]+
      mfk[10][1]))))+((Wpk[11][13][2]*((mtk[9][2]+((mfk[9][1]*rcom[9][0])-(
      mfk[9][0]*rcom[9][1])))+(mtk[10][2]+((mfk[10][1]*rcom[10][0])-(mfk[10][0]*
      rcom[10][1])))))+temp[0]))+temp[1]));
    temp[0] = ((Wpk[12][13][0]*((mtk[9][0]+((mfk[9][2]*rcom[9][1])-(mfk[9][1]*
      rcom[9][2])))+(mtk[10][0]+((mfk[10][2]*rcom[10][1])-(mfk[10][1]*
      rcom[10][2])))))+(Wpk[12][13][1]*((mtk[9][1]+((mfk[9][0]*rcom[9][2])-(
      mfk[9][2]*rcom[9][0])))+(mtk[10][1]+((mfk[10][0]*rcom[10][2])-(mfk[10][2]*
      rcom[10][0]))))));
    temp[1] = (((Vpk[12][13][2]*(mfk[9][2]+mfk[10][2]))+((Vpk[12][13][0]*(
      mfk[9][0]+mfk[10][0]))+(Vpk[12][13][1]*(mfk[9][1]+mfk[10][1]))))+((
      Wpk[12][13][2]*((mtk[9][2]+((mfk[9][1]*rcom[9][0])-(mfk[9][0]*rcom[9][1]))
      )+(mtk[10][2]+((mfk[10][1]*rcom[10][0])-(mfk[10][0]*rcom[10][1])))))+
      temp[0]));
    fs[12] = (mtau[12]+((((mfk[8][2]*Vpk[12][12][2])+((mfk[8][0]*Vpk[12][12][0])
      +(mfk[8][1]*Vpk[12][12][1])))+((mtk[8][2]*pin[12][2])+((mtk[8][0]*
      pin[12][0])+(mtk[8][1]*pin[12][1]))))+temp[1]));
    temp[0] = ((pin[13][2]*((mtk[9][2]+((mfk[9][1]*rcom[9][0])-(mfk[9][0]*
      rcom[9][1])))+(mtk[10][2]+((mfk[10][1]*rcom[10][0])-(mfk[10][0]*
      rcom[10][1])))))+((pin[13][0]*((mtk[9][0]+((mfk[9][2]*rcom[9][1])-(
      mfk[9][1]*rcom[9][2])))+(mtk[10][0]+((mfk[10][2]*rcom[10][1])-(mfk[10][1]*
      rcom[10][2])))))+(pin[13][1]*((mtk[9][1]+((mfk[9][0]*rcom[9][2])-(
      mfk[9][2]*rcom[9][0])))+(mtk[10][1]+((mfk[10][0]*rcom[10][2])-(mfk[10][2]*
      rcom[10][0])))))));
    fs[13] = (mtau[13]+(temp[0]+((Vpk[13][13][2]*(mfk[9][2]+mfk[10][2]))+((
      Vpk[13][13][0]*(mfk[9][0]+mfk[10][0]))+(Vpk[13][13][1]*(mfk[9][1]+
      mfk[10][1]))))));
    temp[0] = ((Wpk[14][17][0]*((mtk[14][0]+((mfk[14][2]*rcom[14][1])-(
      mfk[14][1]*rcom[14][2])))+(mtk[15][0]+((mfk[15][2]*rcom[15][1])-(
      mfk[15][1]*rcom[15][2])))))+(Wpk[14][17][1]*((mtk[14][1]+((mfk[14][0]*
      rcom[14][2])-(mfk[14][2]*rcom[14][0])))+(mtk[15][1]+((mfk[15][0]*
      rcom[15][2])-(mfk[15][2]*rcom[15][0]))))));
    temp[1] = ((((mfk[11][2]*Vpk[14][14][2])+((mfk[11][0]*Vpk[14][14][0])+(
      mfk[11][1]*Vpk[14][14][1])))+((mtk[11][2]*pin[14][2])+((mtk[11][0]*
      pin[14][0])+(mtk[11][1]*pin[14][1]))))+(((mfk[12][2]*Vpk[14][15][2])+((
      mfk[12][0]*Vpk[14][15][0])+(mfk[12][1]*Vpk[14][15][1])))+((mtk[12][2]*
      Wpk[14][15][2])+((mtk[12][0]*Wpk[14][15][0])+(mtk[12][1]*Wpk[14][15][1])))
      ));
    temp[2] = (((Vpk[14][17][2]*(mfk[14][2]+mfk[15][2]))+((Vpk[14][17][0]*(
      mfk[14][0]+mfk[15][0]))+(Vpk[14][17][1]*(mfk[14][1]+mfk[15][1]))))+((
      Wpk[14][17][2]*((mtk[14][2]+((mfk[14][1]*rcom[14][0])-(mfk[14][0]*
      rcom[14][1])))+(mtk[15][2]+((mfk[15][1]*rcom[15][0])-(mfk[15][0]*
      rcom[15][1])))))+temp[0]));
    fs[14] = (mtau[14]+(temp[2]+((((mfk[13][2]*Vpk[14][16][2])+((mfk[13][0]*
      Vpk[14][16][0])+(mfk[13][1]*Vpk[14][16][1])))+((mtk[13][2]*Wpk[14][16][2])
      +((mtk[13][0]*Wpk[14][16][0])+(mtk[13][1]*Wpk[14][16][1]))))+temp[1])));
    temp[0] = ((Wpk[15][17][0]*((mtk[14][0]+((mfk[14][2]*rcom[14][1])-(
      mfk[14][1]*rcom[14][2])))+(mtk[15][0]+((mfk[15][2]*rcom[15][1])-(
      mfk[15][1]*rcom[15][2])))))+(Wpk[15][17][1]*((mtk[14][1]+((mfk[14][0]*
      rcom[14][2])-(mfk[14][2]*rcom[14][0])))+(mtk[15][1]+((mfk[15][0]*
      rcom[15][2])-(mfk[15][2]*rcom[15][0]))))));
    temp[1] = ((((mfk[12][2]*Vpk[15][15][2])+((mfk[12][0]*Vpk[15][15][0])+(
      mfk[12][1]*Vpk[15][15][1])))+((mtk[12][2]*pin[15][2])+((mtk[12][0]*
      pin[15][0])+(mtk[12][1]*pin[15][1]))))+(((mfk[13][2]*Vpk[15][16][2])+((
      mfk[13][0]*Vpk[15][16][0])+(mfk[13][1]*Vpk[15][16][1])))+((mtk[13][2]*
      Wpk[15][16][2])+((mtk[13][0]*Wpk[15][16][0])+(mtk[13][1]*Wpk[15][16][1])))
      ));
    fs[15] = (mtau[15]+((((Vpk[15][17][2]*(mfk[14][2]+mfk[15][2]))+((
      Vpk[15][17][0]*(mfk[14][0]+mfk[15][0]))+(Vpk[15][17][1]*(mfk[14][1]+
      mfk[15][1]))))+((Wpk[15][17][2]*((mtk[14][2]+((mfk[14][1]*rcom[14][0])-(
      mfk[14][0]*rcom[14][1])))+(mtk[15][2]+((mfk[15][1]*rcom[15][0])-(
      mfk[15][0]*rcom[15][1])))))+temp[0]))+temp[1]));
    temp[0] = ((Wpk[16][17][0]*((mtk[14][0]+((mfk[14][2]*rcom[14][1])-(
      mfk[14][1]*rcom[14][2])))+(mtk[15][0]+((mfk[15][2]*rcom[15][1])-(
      mfk[15][1]*rcom[15][2])))))+(Wpk[16][17][1]*((mtk[14][1]+((mfk[14][0]*
      rcom[14][2])-(mfk[14][2]*rcom[14][0])))+(mtk[15][1]+((mfk[15][0]*
      rcom[15][2])-(mfk[15][2]*rcom[15][0]))))));
    temp[1] = (((Vpk[16][17][2]*(mfk[14][2]+mfk[15][2]))+((Vpk[16][17][0]*(
      mfk[14][0]+mfk[15][0]))+(Vpk[16][17][1]*(mfk[14][1]+mfk[15][1]))))+((
      Wpk[16][17][2]*((mtk[14][2]+((mfk[14][1]*rcom[14][0])-(mfk[14][0]*
      rcom[14][1])))+(mtk[15][2]+((mfk[15][1]*rcom[15][0])-(mfk[15][0]*
      rcom[15][1])))))+temp[0]));
    fs[16] = (mtau[16]+((((mfk[13][2]*Vpk[16][16][2])+((mfk[13][0]*
      Vpk[16][16][0])+(mfk[13][1]*Vpk[16][16][1])))+((mtk[13][2]*pin[16][2])+((
      mtk[13][0]*pin[16][0])+(mtk[13][1]*pin[16][1]))))+temp[1]));
    temp[0] = ((pin[17][2]*((mtk[14][2]+((mfk[14][1]*rcom[14][0])-(mfk[14][0]*
      rcom[14][1])))+(mtk[15][2]+((mfk[15][1]*rcom[15][0])-(mfk[15][0]*
      rcom[15][1])))))+((pin[17][0]*((mtk[14][0]+((mfk[14][2]*rcom[14][1])-(
      mfk[14][1]*rcom[14][2])))+(mtk[15][0]+((mfk[15][2]*rcom[15][1])-(
      mfk[15][1]*rcom[15][2])))))+(pin[17][1]*((mtk[14][1]+((mfk[14][0]*
      rcom[14][2])-(mfk[14][2]*rcom[14][0])))+(mtk[15][1]+((mfk[15][0]*
      rcom[15][2])-(mfk[15][2]*rcom[15][0])))))));
    fs[17] = (mtau[17]+(temp[0]+((Vpk[17][17][2]*(mfk[14][2]+mfk[15][2]))+((
      Vpk[17][17][0]*(mfk[14][0]+mfk[15][0]))+(Vpk[17][17][1]*(mfk[14][1]+
      mfk[15][1]))))));
    temp[0] = ((Wpk[18][21][0]*((mtk[19][0]+((mfk[19][2]*rcom[19][1])-(
      mfk[19][1]*rcom[19][2])))+(mtk[20][0]+((mfk[20][2]*rcom[20][1])-(
      mfk[20][1]*rcom[20][2])))))+(Wpk[18][21][1]*((mtk[19][1]+((mfk[19][0]*
      rcom[19][2])-(mfk[19][2]*rcom[19][0])))+(mtk[20][1]+((mfk[20][0]*
      rcom[20][2])-(mfk[20][2]*rcom[20][0]))))));
    temp[1] = ((((mfk[16][2]*Vpk[18][18][2])+((mfk[16][0]*Vpk[18][18][0])+(
      mfk[16][1]*Vpk[18][18][1])))+((mtk[16][2]*pin[18][2])+((mtk[16][0]*
      pin[18][0])+(mtk[16][1]*pin[18][1]))))+(((mfk[17][2]*Vpk[18][19][2])+((
      mfk[17][0]*Vpk[18][19][0])+(mfk[17][1]*Vpk[18][19][1])))+((mtk[17][2]*
      Wpk[18][19][2])+((mtk[17][0]*Wpk[18][19][0])+(mtk[17][1]*Wpk[18][19][1])))
      ));
    temp[2] = (((Vpk[18][21][2]*(mfk[19][2]+mfk[20][2]))+((Vpk[18][21][0]*(
      mfk[19][0]+mfk[20][0]))+(Vpk[18][21][1]*(mfk[19][1]+mfk[20][1]))))+((
      Wpk[18][21][2]*((mtk[19][2]+((mfk[19][1]*rcom[19][0])-(mfk[19][0]*
      rcom[19][1])))+(mtk[20][2]+((mfk[20][1]*rcom[20][0])-(mfk[20][0]*
      rcom[20][1])))))+temp[0]));
    fs[18] = (mtau[18]+(temp[2]+((((mfk[18][2]*Vpk[18][20][2])+((mfk[18][0]*
      Vpk[18][20][0])+(mfk[18][1]*Vpk[18][20][1])))+((mtk[18][2]*Wpk[18][20][2])
      +((mtk[18][0]*Wpk[18][20][0])+(mtk[18][1]*Wpk[18][20][1]))))+temp[1])));
    temp[0] = ((Wpk[19][21][0]*((mtk[19][0]+((mfk[19][2]*rcom[19][1])-(
      mfk[19][1]*rcom[19][2])))+(mtk[20][0]+((mfk[20][2]*rcom[20][1])-(
      mfk[20][1]*rcom[20][2])))))+(Wpk[19][21][1]*((mtk[19][1]+((mfk[19][0]*
      rcom[19][2])-(mfk[19][2]*rcom[19][0])))+(mtk[20][1]+((mfk[20][0]*
      rcom[20][2])-(mfk[20][2]*rcom[20][0]))))));
    temp[1] = ((((mfk[17][2]*Vpk[19][19][2])+((mfk[17][0]*Vpk[19][19][0])+(
      mfk[17][1]*Vpk[19][19][1])))+((mtk[17][2]*pin[19][2])+((mtk[17][0]*
      pin[19][0])+(mtk[17][1]*pin[19][1]))))+(((mfk[18][2]*Vpk[19][20][2])+((
      mfk[18][0]*Vpk[19][20][0])+(mfk[18][1]*Vpk[19][20][1])))+((mtk[18][2]*
      Wpk[19][20][2])+((mtk[18][0]*Wpk[19][20][0])+(mtk[18][1]*Wpk[19][20][1])))
      ));
    fs[19] = (mtau[19]+((((Vpk[19][21][2]*(mfk[19][2]+mfk[20][2]))+((
      Vpk[19][21][0]*(mfk[19][0]+mfk[20][0]))+(Vpk[19][21][1]*(mfk[19][1]+
      mfk[20][1]))))+((Wpk[19][21][2]*((mtk[19][2]+((mfk[19][1]*rcom[19][0])-(
      mfk[19][0]*rcom[19][1])))+(mtk[20][2]+((mfk[20][1]*rcom[20][0])-(
      mfk[20][0]*rcom[20][1])))))+temp[0]))+temp[1]));
    temp[0] = ((Wpk[20][21][0]*((mtk[19][0]+((mfk[19][2]*rcom[19][1])-(
      mfk[19][1]*rcom[19][2])))+(mtk[20][0]+((mfk[20][2]*rcom[20][1])-(
      mfk[20][1]*rcom[20][2])))))+(Wpk[20][21][1]*((mtk[19][1]+((mfk[19][0]*
      rcom[19][2])-(mfk[19][2]*rcom[19][0])))+(mtk[20][1]+((mfk[20][0]*
      rcom[20][2])-(mfk[20][2]*rcom[20][0]))))));
    temp[1] = (((Vpk[20][21][2]*(mfk[19][2]+mfk[20][2]))+((Vpk[20][21][0]*(
      mfk[19][0]+mfk[20][0]))+(Vpk[20][21][1]*(mfk[19][1]+mfk[20][1]))))+((
      Wpk[20][21][2]*((mtk[19][2]+((mfk[19][1]*rcom[19][0])-(mfk[19][0]*
      rcom[19][1])))+(mtk[20][2]+((mfk[20][1]*rcom[20][0])-(mfk[20][0]*
      rcom[20][1])))))+temp[0]));
    fs[20] = (mtau[20]+((((mfk[18][2]*Vpk[20][20][2])+((mfk[18][0]*
      Vpk[20][20][0])+(mfk[18][1]*Vpk[20][20][1])))+((mtk[18][2]*pin[20][2])+((
      mtk[18][0]*pin[20][0])+(mtk[18][1]*pin[20][1]))))+temp[1]));
    temp[0] = ((pin[21][2]*((mtk[19][2]+((mfk[19][1]*rcom[19][0])-(mfk[19][0]*
      rcom[19][1])))+(mtk[20][2]+((mfk[20][1]*rcom[20][0])-(mfk[20][0]*
      rcom[20][1])))))+((pin[21][0]*((mtk[19][0]+((mfk[19][2]*rcom[19][1])-(
      mfk[19][1]*rcom[19][2])))+(mtk[20][0]+((mfk[20][2]*rcom[20][1])-(
      mfk[20][1]*rcom[20][2])))))+(pin[21][1]*((mtk[19][1]+((mfk[19][0]*
      rcom[19][2])-(mfk[19][2]*rcom[19][0])))+(mtk[20][1]+((mfk[20][0]*
      rcom[20][2])-(mfk[20][2]*rcom[20][0])))))));
    fs[21] = (mtau[21]+(temp[0]+((Vpk[21][21][2]*(mfk[19][2]+mfk[20][2]))+((
      Vpk[21][21][0]*(mfk[19][0]+mfk[20][0]))+(Vpk[21][21][1]*(mfk[19][1]+
      mfk[20][1]))))));
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain 1230 adds/subtracts/negates
                   1023 multiplies
                      0 divides
                    105 assignments
*/
}

void allegro_air_fsgenfull(void)
{

/*
Compute Fs (incl generic mult & other forces)
*/
    allegro_air_fsgenmult();
    fs[0] = (fs[0]+fs0[0]);
    fs[1] = (fs[1]+fs0[1]);
    fs[2] = (fs[2]+fs0[2]);
    fs[3] = (fs[3]+fs0[3]);
    fs[4] = (fs[4]+fs0[4]);
    fs[5] = (fs[5]+fs0[5]);
    fs[6] = (fs[6]+fs0[6]);
    fs[7] = (fs[7]+fs0[7]);
    fs[8] = (fs[8]+fs0[8]);
    fs[9] = (fs[9]+fs0[9]);
    fs[10] = (fs[10]+fs0[10]);
    fs[11] = (fs[11]+fs0[11]);
    fs[12] = (fs[12]+fs0[12]);
    fs[13] = (fs[13]+fs0[13]);
    fs[14] = (fs[14]+fs0[14]);
    fs[15] = (fs[15]+fs0[15]);
    fs[16] = (fs[16]+fs0[16]);
    fs[17] = (fs[17]+fs0[17]);
    fs[18] = (fs[18]+fs0[18]);
    fs[19] = (fs[19]+fs0[19]);
    fs[20] = (fs[20]+fs0[20]);
    fs[21] = (fs[21]+fs0[21]);
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain   22 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     22 assignments
*/
}

void allegro_air_fulltrq(double udotin[22],
    double multin[22],
    double trqout[22])
{
/* Compute hinge torques which would produce indicated udots
*/
    double fstarr[22][3],tstarr[22][3],Otkr[22][3],Atir[22][3],Atkr[22][3];

    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(61,23);
        return;
    }
/*
Compute multiplier-generated forces
*/
    allegro_air_mfrc(multin);
/*
Account for inertial accelerations and supplied udots
*/
    Otkr[6][0] = (((Cik[6][2][0]*udotin[5])+((Cik[6][0][0]*udotin[3])+(
      Cik[6][1][0]*udotin[4])))+((pin[6][0]*udotin[6])+((Wik[6][2]*wk[6][1])-(
      Wik[6][1]*wk[6][2]))));
    Otkr[6][1] = (((Cik[6][2][1]*udotin[5])+((Cik[6][0][1]*udotin[3])+(
      Cik[6][1][1]*udotin[4])))+((pin[6][1]*udotin[6])+((Wik[6][0]*wk[6][2])-(
      Wik[6][2]*wk[6][0]))));
    Otkr[6][2] = (((Cik[6][2][2]*udotin[5])+((Cik[6][0][2]*udotin[3])+(
      Cik[6][1][2]*udotin[4])))+((pin[6][2]*udotin[6])+((Wik[6][1]*wk[6][0])-(
      Wik[6][0]*wk[6][1]))));
    Otkr[7][0] = (((Cik[7][2][0]*Otkr[6][2])+((Cik[7][0][0]*Otkr[6][0])+(
      Cik[7][1][0]*Otkr[6][1])))+((pin[7][0]*udotin[7])+((Wik[7][2]*wk[7][1])-(
      Wik[7][1]*wk[7][2]))));
    Otkr[7][1] = (((Cik[7][2][1]*Otkr[6][2])+((Cik[7][0][1]*Otkr[6][0])+(
      Cik[7][1][1]*Otkr[6][1])))+((pin[7][1]*udotin[7])+((Wik[7][0]*wk[7][2])-(
      Wik[7][2]*wk[7][0]))));
    Otkr[7][2] = (((Cik[7][2][2]*Otkr[6][2])+((Cik[7][0][2]*Otkr[6][0])+(
      Cik[7][1][2]*Otkr[6][1])))+((pin[7][2]*udotin[7])+((Wik[7][1]*wk[7][0])-(
      Wik[7][0]*wk[7][1]))));
    Otkr[8][0] = (((Cik[8][2][0]*Otkr[7][2])+((Cik[8][0][0]*Otkr[7][0])+(
      Cik[8][1][0]*Otkr[7][1])))+((pin[8][0]*udotin[8])+((Wik[8][2]*wk[8][1])-(
      Wik[8][1]*wk[8][2]))));
    Otkr[8][1] = (((Cik[8][2][1]*Otkr[7][2])+((Cik[8][0][1]*Otkr[7][0])+(
      Cik[8][1][1]*Otkr[7][1])))+((pin[8][1]*udotin[8])+((Wik[8][0]*wk[8][2])-(
      Wik[8][2]*wk[8][0]))));
    Otkr[8][2] = (((Cik[8][2][2]*Otkr[7][2])+((Cik[8][0][2]*Otkr[7][0])+(
      Cik[8][1][2]*Otkr[7][1])))+((pin[8][2]*udotin[8])+((Wik[8][1]*wk[8][0])-(
      Wik[8][0]*wk[8][1]))));
    Otkr[9][0] = (((Cik[9][2][0]*Otkr[8][2])+((Cik[9][0][0]*Otkr[8][0])+(
      Cik[9][1][0]*Otkr[8][1])))+((pin[9][0]*udotin[9])+((Wik[9][2]*wk[9][1])-(
      Wik[9][1]*wk[9][2]))));
    Otkr[9][1] = (((Cik[9][2][1]*Otkr[8][2])+((Cik[9][0][1]*Otkr[8][0])+(
      Cik[9][1][1]*Otkr[8][1])))+((pin[9][1]*udotin[9])+((Wik[9][0]*wk[9][2])-(
      Wik[9][2]*wk[9][0]))));
    Otkr[9][2] = (((Cik[9][2][2]*Otkr[8][2])+((Cik[9][0][2]*Otkr[8][0])+(
      Cik[9][1][2]*Otkr[8][1])))+((pin[9][2]*udotin[9])+((Wik[9][1]*wk[9][0])-(
      Wik[9][0]*wk[9][1]))));
    Otkr[10][0] = (((Cik[10][2][0]*udotin[5])+((Cik[10][0][0]*udotin[3])+(
      Cik[10][1][0]*udotin[4])))+((pin[10][0]*udotin[10])+((Wik[10][2]*wk[10][1]
      )-(Wik[10][1]*wk[10][2]))));
    Otkr[10][1] = (((Cik[10][2][1]*udotin[5])+((Cik[10][0][1]*udotin[3])+(
      Cik[10][1][1]*udotin[4])))+((pin[10][1]*udotin[10])+((Wik[10][0]*wk[10][2]
      )-(Wik[10][2]*wk[10][0]))));
    Otkr[10][2] = (((Cik[10][2][2]*udotin[5])+((Cik[10][0][2]*udotin[3])+(
      Cik[10][1][2]*udotin[4])))+((pin[10][2]*udotin[10])+((Wik[10][1]*wk[10][0]
      )-(Wik[10][0]*wk[10][1]))));
    Otkr[11][0] = (((Cik[11][2][0]*Otkr[10][2])+((Cik[11][0][0]*Otkr[10][0])+(
      Cik[11][1][0]*Otkr[10][1])))+((pin[11][0]*udotin[11])+((Wik[11][2]*
      wk[11][1])-(Wik[11][1]*wk[11][2]))));
    Otkr[11][1] = (((Cik[11][2][1]*Otkr[10][2])+((Cik[11][0][1]*Otkr[10][0])+(
      Cik[11][1][1]*Otkr[10][1])))+((pin[11][1]*udotin[11])+((Wik[11][0]*
      wk[11][2])-(Wik[11][2]*wk[11][0]))));
    Otkr[11][2] = (((Cik[11][2][2]*Otkr[10][2])+((Cik[11][0][2]*Otkr[10][0])+(
      Cik[11][1][2]*Otkr[10][1])))+((pin[11][2]*udotin[11])+((Wik[11][1]*
      wk[11][0])-(Wik[11][0]*wk[11][1]))));
    Otkr[12][0] = (((Cik[12][2][0]*Otkr[11][2])+((Cik[12][0][0]*Otkr[11][0])+(
      Cik[12][1][0]*Otkr[11][1])))+((pin[12][0]*udotin[12])+((Wik[12][2]*
      wk[12][1])-(Wik[12][1]*wk[12][2]))));
    Otkr[12][1] = (((Cik[12][2][1]*Otkr[11][2])+((Cik[12][0][1]*Otkr[11][0])+(
      Cik[12][1][1]*Otkr[11][1])))+((pin[12][1]*udotin[12])+((Wik[12][0]*
      wk[12][2])-(Wik[12][2]*wk[12][0]))));
    Otkr[12][2] = (((Cik[12][2][2]*Otkr[11][2])+((Cik[12][0][2]*Otkr[11][0])+(
      Cik[12][1][2]*Otkr[11][1])))+((pin[12][2]*udotin[12])+((Wik[12][1]*
      wk[12][0])-(Wik[12][0]*wk[12][1]))));
    Otkr[13][0] = (((Cik[13][2][0]*Otkr[12][2])+((Cik[13][0][0]*Otkr[12][0])+(
      Cik[13][1][0]*Otkr[12][1])))+((pin[13][0]*udotin[13])+((Wik[13][2]*
      wk[13][1])-(Wik[13][1]*wk[13][2]))));
    Otkr[13][1] = (((Cik[13][2][1]*Otkr[12][2])+((Cik[13][0][1]*Otkr[12][0])+(
      Cik[13][1][1]*Otkr[12][1])))+((pin[13][1]*udotin[13])+((Wik[13][0]*
      wk[13][2])-(Wik[13][2]*wk[13][0]))));
    Otkr[13][2] = (((Cik[13][2][2]*Otkr[12][2])+((Cik[13][0][2]*Otkr[12][0])+(
      Cik[13][1][2]*Otkr[12][1])))+((pin[13][2]*udotin[13])+((Wik[13][1]*
      wk[13][0])-(Wik[13][0]*wk[13][1]))));
    Otkr[14][0] = (((Cik[14][2][0]*udotin[5])+((Cik[14][0][0]*udotin[3])+(
      Cik[14][1][0]*udotin[4])))+((pin[14][0]*udotin[14])+((Wik[14][2]*wk[14][1]
      )-(Wik[14][1]*wk[14][2]))));
    Otkr[14][1] = (((Cik[14][2][1]*udotin[5])+((Cik[14][0][1]*udotin[3])+(
      Cik[14][1][1]*udotin[4])))+((pin[14][1]*udotin[14])+((Wik[14][0]*wk[14][2]
      )-(Wik[14][2]*wk[14][0]))));
    Otkr[14][2] = (((Cik[14][2][2]*udotin[5])+((Cik[14][0][2]*udotin[3])+(
      Cik[14][1][2]*udotin[4])))+((pin[14][2]*udotin[14])+((Wik[14][1]*wk[14][0]
      )-(Wik[14][0]*wk[14][1]))));
    Otkr[15][0] = (((Cik[15][2][0]*Otkr[14][2])+((Cik[15][0][0]*Otkr[14][0])+(
      Cik[15][1][0]*Otkr[14][1])))+((pin[15][0]*udotin[15])+((Wik[15][2]*
      wk[15][1])-(Wik[15][1]*wk[15][2]))));
    Otkr[15][1] = (((Cik[15][2][1]*Otkr[14][2])+((Cik[15][0][1]*Otkr[14][0])+(
      Cik[15][1][1]*Otkr[14][1])))+((pin[15][1]*udotin[15])+((Wik[15][0]*
      wk[15][2])-(Wik[15][2]*wk[15][0]))));
    Otkr[15][2] = (((Cik[15][2][2]*Otkr[14][2])+((Cik[15][0][2]*Otkr[14][0])+(
      Cik[15][1][2]*Otkr[14][1])))+((pin[15][2]*udotin[15])+((Wik[15][1]*
      wk[15][0])-(Wik[15][0]*wk[15][1]))));
    Otkr[16][0] = (((Cik[16][2][0]*Otkr[15][2])+((Cik[16][0][0]*Otkr[15][0])+(
      Cik[16][1][0]*Otkr[15][1])))+((pin[16][0]*udotin[16])+((Wik[16][2]*
      wk[16][1])-(Wik[16][1]*wk[16][2]))));
    Otkr[16][1] = (((Cik[16][2][1]*Otkr[15][2])+((Cik[16][0][1]*Otkr[15][0])+(
      Cik[16][1][1]*Otkr[15][1])))+((pin[16][1]*udotin[16])+((Wik[16][0]*
      wk[16][2])-(Wik[16][2]*wk[16][0]))));
    Otkr[16][2] = (((Cik[16][2][2]*Otkr[15][2])+((Cik[16][0][2]*Otkr[15][0])+(
      Cik[16][1][2]*Otkr[15][1])))+((pin[16][2]*udotin[16])+((Wik[16][1]*
      wk[16][0])-(Wik[16][0]*wk[16][1]))));
    Otkr[17][0] = (((Cik[17][2][0]*Otkr[16][2])+((Cik[17][0][0]*Otkr[16][0])+(
      Cik[17][1][0]*Otkr[16][1])))+((pin[17][0]*udotin[17])+((Wik[17][2]*
      wk[17][1])-(Wik[17][1]*wk[17][2]))));
    Otkr[17][1] = (((Cik[17][2][1]*Otkr[16][2])+((Cik[17][0][1]*Otkr[16][0])+(
      Cik[17][1][1]*Otkr[16][1])))+((pin[17][1]*udotin[17])+((Wik[17][0]*
      wk[17][2])-(Wik[17][2]*wk[17][0]))));
    Otkr[17][2] = (((Cik[17][2][2]*Otkr[16][2])+((Cik[17][0][2]*Otkr[16][0])+(
      Cik[17][1][2]*Otkr[16][1])))+((pin[17][2]*udotin[17])+((Wik[17][1]*
      wk[17][0])-(Wik[17][0]*wk[17][1]))));
    Otkr[18][0] = (((Cik[18][2][0]*udotin[5])+((Cik[18][0][0]*udotin[3])+(
      Cik[18][1][0]*udotin[4])))+((pin[18][0]*udotin[18])+((Wik[18][2]*wk[18][1]
      )-(Wik[18][1]*wk[18][2]))));
    Otkr[18][1] = (((Cik[18][2][1]*udotin[5])+((Cik[18][0][1]*udotin[3])+(
      Cik[18][1][1]*udotin[4])))+((pin[18][1]*udotin[18])+((Wik[18][0]*wk[18][2]
      )-(Wik[18][2]*wk[18][0]))));
    Otkr[18][2] = (((Cik[18][2][2]*udotin[5])+((Cik[18][0][2]*udotin[3])+(
      Cik[18][1][2]*udotin[4])))+((pin[18][2]*udotin[18])+((Wik[18][1]*wk[18][0]
      )-(Wik[18][0]*wk[18][1]))));
    Otkr[19][0] = (((Cik[19][2][0]*Otkr[18][2])+((Cik[19][0][0]*Otkr[18][0])+(
      Cik[19][1][0]*Otkr[18][1])))+((pin[19][0]*udotin[19])+((Wik[19][2]*
      wk[19][1])-(Wik[19][1]*wk[19][2]))));
    Otkr[19][1] = (((Cik[19][2][1]*Otkr[18][2])+((Cik[19][0][1]*Otkr[18][0])+(
      Cik[19][1][1]*Otkr[18][1])))+((pin[19][1]*udotin[19])+((Wik[19][0]*
      wk[19][2])-(Wik[19][2]*wk[19][0]))));
    Otkr[19][2] = (((Cik[19][2][2]*Otkr[18][2])+((Cik[19][0][2]*Otkr[18][0])+(
      Cik[19][1][2]*Otkr[18][1])))+((pin[19][2]*udotin[19])+((Wik[19][1]*
      wk[19][0])-(Wik[19][0]*wk[19][1]))));
    Otkr[20][0] = (((Cik[20][2][0]*Otkr[19][2])+((Cik[20][0][0]*Otkr[19][0])+(
      Cik[20][1][0]*Otkr[19][1])))+((pin[20][0]*udotin[20])+((Wik[20][2]*
      wk[20][1])-(Wik[20][1]*wk[20][2]))));
    Otkr[20][1] = (((Cik[20][2][1]*Otkr[19][2])+((Cik[20][0][1]*Otkr[19][0])+(
      Cik[20][1][1]*Otkr[19][1])))+((pin[20][1]*udotin[20])+((Wik[20][0]*
      wk[20][2])-(Wik[20][2]*wk[20][0]))));
    Otkr[20][2] = (((Cik[20][2][2]*Otkr[19][2])+((Cik[20][0][2]*Otkr[19][0])+(
      Cik[20][1][2]*Otkr[19][1])))+((pin[20][2]*udotin[20])+((Wik[20][1]*
      wk[20][0])-(Wik[20][0]*wk[20][1]))));
    Otkr[21][0] = (((Cik[21][2][0]*Otkr[20][2])+((Cik[21][0][0]*Otkr[20][0])+(
      Cik[21][1][0]*Otkr[20][1])))+((pin[21][0]*udotin[21])+((Wik[21][2]*
      wk[21][1])-(Wik[21][1]*wk[21][2]))));
    Otkr[21][1] = (((Cik[21][2][1]*Otkr[20][2])+((Cik[21][0][1]*Otkr[20][0])+(
      Cik[21][1][1]*Otkr[20][1])))+((pin[21][1]*udotin[21])+((Wik[21][0]*
      wk[21][2])-(Wik[21][2]*wk[21][0]))));
    Otkr[21][2] = (((Cik[21][2][2]*Otkr[20][2])+((Cik[21][0][2]*Otkr[20][0])+(
      Cik[21][1][2]*Otkr[20][1])))+((pin[21][2]*udotin[21])+((Wik[21][1]*
      wk[21][0])-(Wik[21][0]*wk[21][1]))));
    Atkr[0][0] = (pin[0][0]*udotin[0]);
    Atkr[0][1] = (pin[0][1]*udotin[0]);
    Atkr[0][2] = (pin[0][2]*udotin[0]);
    Atkr[1][0] = (Atkr[0][0]+(pin[1][0]*udotin[1]));
    Atkr[1][1] = (Atkr[0][1]+(pin[1][1]*udotin[1]));
    Atkr[1][2] = (Atkr[0][2]+(pin[1][2]*udotin[1]));
    Atkr[2][0] = (Atkr[1][0]+(pin[2][0]*udotin[2]));
    Atkr[2][1] = (Atkr[1][1]+(pin[2][1]*udotin[2]));
    Atkr[2][2] = (Atkr[1][2]+(pin[2][2]*udotin[2]));
    Atkr[3][0] = ((Atkr[2][2]*Cik[3][2][0])+((Atkr[2][0]*Cik[3][0][0])+(
      Atkr[2][1]*Cik[3][1][0])));
    Atkr[3][1] = ((Atkr[2][2]*Cik[3][2][1])+((Atkr[2][0]*Cik[3][0][1])+(
      Atkr[2][1]*Cik[3][1][1])));
    Atkr[3][2] = ((Atkr[2][2]*Cik[3][2][2])+((Atkr[2][0]*Cik[3][0][2])+(
      Atkr[2][1]*Cik[3][1][2])));
    Atkr[5][0] = (Atkr[3][0]+(((rk[0][1]*udotin[5])-(rk[0][2]*udotin[4]))+((u[4]
      *Wkrpk[5][2])-(u[5]*Wkrpk[5][1]))));
    Atkr[5][1] = (Atkr[3][1]+(((rk[0][2]*udotin[3])-(rk[0][0]*udotin[5]))+((u[5]
      *Wkrpk[5][0])-(u[3]*Wkrpk[5][2]))));
    Atkr[5][2] = (Atkr[3][2]+(((rk[0][0]*udotin[4])-(rk[0][1]*udotin[3]))+((u[3]
      *Wkrpk[5][1])-(u[4]*Wkrpk[5][0]))));
    Atir[6][0] = (Atkr[5][0]+(((ri[1][2]*udotin[4])-(ri[1][1]*udotin[5]))+((u[4]
      *Wirk[6][2])-(u[5]*Wirk[6][1]))));
    Atir[6][1] = (Atkr[5][1]+(((ri[1][0]*udotin[5])-(ri[1][2]*udotin[3]))+((u[5]
      *Wirk[6][0])-(u[3]*Wirk[6][2]))));
    Atir[6][2] = (Atkr[5][2]+(((ri[1][1]*udotin[3])-(ri[1][0]*udotin[4]))+((u[3]
      *Wirk[6][1])-(u[4]*Wirk[6][0]))));
    Atkr[6][0] = (((Atir[6][2]*Cik[6][2][0])+((Atir[6][0]*Cik[6][0][0])+(
      Atir[6][1]*Cik[6][1][0])))+(((Otkr[6][2]*rk[1][1])-(Otkr[6][1]*rk[1][2]))+
      ((wk[6][1]*Wkrpk[6][2])-(wk[6][2]*Wkrpk[6][1]))));
    Atkr[6][1] = (((Atir[6][2]*Cik[6][2][1])+((Atir[6][0]*Cik[6][0][1])+(
      Atir[6][1]*Cik[6][1][1])))+(((Otkr[6][0]*rk[1][2])-(Otkr[6][2]*rk[1][0]))+
      ((wk[6][2]*Wkrpk[6][0])-(wk[6][0]*Wkrpk[6][2]))));
    Atkr[6][2] = (((Atir[6][2]*Cik[6][2][2])+((Atir[6][0]*Cik[6][0][2])+(
      Atir[6][1]*Cik[6][1][2])))+(((Otkr[6][1]*rk[1][0])-(Otkr[6][0]*rk[1][1]))+
      ((wk[6][0]*Wkrpk[6][1])-(wk[6][1]*Wkrpk[6][0]))));
    Atir[7][0] = (Atkr[6][0]+(((Otkr[6][1]*ri[2][2])-(Otkr[6][2]*ri[2][1]))+((
      Wirk[7][2]*wk[6][1])-(Wirk[7][1]*wk[6][2]))));
    Atir[7][1] = (Atkr[6][1]+(((Otkr[6][2]*ri[2][0])-(Otkr[6][0]*ri[2][2]))+((
      Wirk[7][0]*wk[6][2])-(Wirk[7][2]*wk[6][0]))));
    Atir[7][2] = (Atkr[6][2]+(((Otkr[6][0]*ri[2][1])-(Otkr[6][1]*ri[2][0]))+((
      Wirk[7][1]*wk[6][0])-(Wirk[7][0]*wk[6][1]))));
    Atkr[7][0] = (((Atir[7][2]*Cik[7][2][0])+((Atir[7][0]*Cik[7][0][0])+(
      Atir[7][1]*Cik[7][1][0])))+(((Otkr[7][2]*rk[2][1])-(Otkr[7][1]*rk[2][2]))+
      ((wk[7][1]*Wkrpk[7][2])-(wk[7][2]*Wkrpk[7][1]))));
    Atkr[7][1] = (((Atir[7][2]*Cik[7][2][1])+((Atir[7][0]*Cik[7][0][1])+(
      Atir[7][1]*Cik[7][1][1])))+(((Otkr[7][0]*rk[2][2])-(Otkr[7][2]*rk[2][0]))+
      ((wk[7][2]*Wkrpk[7][0])-(wk[7][0]*Wkrpk[7][2]))));
    Atkr[7][2] = (((Atir[7][2]*Cik[7][2][2])+((Atir[7][0]*Cik[7][0][2])+(
      Atir[7][1]*Cik[7][1][2])))+(((Otkr[7][1]*rk[2][0])-(Otkr[7][0]*rk[2][1]))+
      ((wk[7][0]*Wkrpk[7][1])-(wk[7][1]*Wkrpk[7][0]))));
    Atir[8][0] = (Atkr[7][0]+(((Otkr[7][1]*ri[3][2])-(Otkr[7][2]*ri[3][1]))+((
      Wirk[8][2]*wk[7][1])-(Wirk[8][1]*wk[7][2]))));
    Atir[8][1] = (Atkr[7][1]+(((Otkr[7][2]*ri[3][0])-(Otkr[7][0]*ri[3][2]))+((
      Wirk[8][0]*wk[7][2])-(Wirk[8][2]*wk[7][0]))));
    Atir[8][2] = (Atkr[7][2]+(((Otkr[7][0]*ri[3][1])-(Otkr[7][1]*ri[3][0]))+((
      Wirk[8][1]*wk[7][0])-(Wirk[8][0]*wk[7][1]))));
    Atkr[8][0] = (((Atir[8][2]*Cik[8][2][0])+((Atir[8][0]*Cik[8][0][0])+(
      Atir[8][1]*Cik[8][1][0])))+(((Otkr[8][2]*rk[3][1])-(Otkr[8][1]*rk[3][2]))+
      ((wk[8][1]*Wkrpk[8][2])-(wk[8][2]*Wkrpk[8][1]))));
    Atkr[8][1] = (((Atir[8][2]*Cik[8][2][1])+((Atir[8][0]*Cik[8][0][1])+(
      Atir[8][1]*Cik[8][1][1])))+(((Otkr[8][0]*rk[3][2])-(Otkr[8][2]*rk[3][0]))+
      ((wk[8][2]*Wkrpk[8][0])-(wk[8][0]*Wkrpk[8][2]))));
    Atkr[8][2] = (((Atir[8][2]*Cik[8][2][2])+((Atir[8][0]*Cik[8][0][2])+(
      Atir[8][1]*Cik[8][1][2])))+(((Otkr[8][1]*rk[3][0])-(Otkr[8][0]*rk[3][1]))+
      ((wk[8][0]*Wkrpk[8][1])-(wk[8][1]*Wkrpk[8][0]))));
    Atir[9][0] = (Atkr[8][0]+(((Otkr[8][1]*ri[4][2])-(Otkr[8][2]*ri[4][1]))+((
      Wirk[9][2]*wk[8][1])-(Wirk[9][1]*wk[8][2]))));
    Atir[9][1] = (Atkr[8][1]+(((Otkr[8][2]*ri[4][0])-(Otkr[8][0]*ri[4][2]))+((
      Wirk[9][0]*wk[8][2])-(Wirk[9][2]*wk[8][0]))));
    Atir[9][2] = (Atkr[8][2]+(((Otkr[8][0]*ri[4][1])-(Otkr[8][1]*ri[4][0]))+((
      Wirk[9][1]*wk[8][0])-(Wirk[9][0]*wk[8][1]))));
    Atkr[9][0] = (((Atir[9][2]*Cik[9][2][0])+((Atir[9][0]*Cik[9][0][0])+(
      Atir[9][1]*Cik[9][1][0])))+(((Otkr[9][2]*psrk[9][1])-(Otkr[9][1]*
      psrk[9][2]))+((wk[9][1]*Wkrpk[9][2])-(wk[9][2]*Wkrpk[9][1]))));
    Atkr[9][1] = (((Atir[9][2]*Cik[9][2][1])+((Atir[9][0]*Cik[9][0][1])+(
      Atir[9][1]*Cik[9][1][1])))+(((Otkr[9][0]*psrk[9][2])-(Otkr[9][2]*
      psrk[9][0]))+((wk[9][2]*Wkrpk[9][0])-(wk[9][0]*Wkrpk[9][2]))));
    Atkr[9][2] = (((Atir[9][2]*Cik[9][2][2])+((Atir[9][0]*Cik[9][0][2])+(
      Atir[9][1]*Cik[9][1][2])))+(((Otkr[9][1]*psrk[9][0])-(Otkr[9][0]*
      psrk[9][1]))+((wk[9][0]*Wkrpk[9][1])-(wk[9][1]*Wkrpk[9][0]))));
    Atir[10][0] = (Atkr[5][0]+(((ri[6][2]*udotin[4])-(ri[6][1]*udotin[5]))+((
      u[4]*Wirk[10][2])-(u[5]*Wirk[10][1]))));
    Atir[10][1] = (Atkr[5][1]+(((ri[6][0]*udotin[5])-(ri[6][2]*udotin[3]))+((
      u[5]*Wirk[10][0])-(u[3]*Wirk[10][2]))));
    Atir[10][2] = (Atkr[5][2]+(((ri[6][1]*udotin[3])-(ri[6][0]*udotin[4]))+((
      u[3]*Wirk[10][1])-(u[4]*Wirk[10][0]))));
    Atkr[10][0] = (((Atir[10][2]*Cik[10][2][0])+((Atir[10][0]*Cik[10][0][0])+(
      Atir[10][1]*Cik[10][1][0])))+(((Otkr[10][2]*rk[6][1])-(Otkr[10][1]*
      rk[6][2]))+((wk[10][1]*Wkrpk[10][2])-(wk[10][2]*Wkrpk[10][1]))));
    Atkr[10][1] = (((Atir[10][2]*Cik[10][2][1])+((Atir[10][0]*Cik[10][0][1])+(
      Atir[10][1]*Cik[10][1][1])))+(((Otkr[10][0]*rk[6][2])-(Otkr[10][2]*
      rk[6][0]))+((wk[10][2]*Wkrpk[10][0])-(wk[10][0]*Wkrpk[10][2]))));
    Atkr[10][2] = (((Atir[10][2]*Cik[10][2][2])+((Atir[10][0]*Cik[10][0][2])+(
      Atir[10][1]*Cik[10][1][2])))+(((Otkr[10][1]*rk[6][0])-(Otkr[10][0]*
      rk[6][1]))+((wk[10][0]*Wkrpk[10][1])-(wk[10][1]*Wkrpk[10][0]))));
    Atir[11][0] = (Atkr[10][0]+(((Otkr[10][1]*ri[7][2])-(Otkr[10][2]*ri[7][1]))+
      ((Wirk[11][2]*wk[10][1])-(Wirk[11][1]*wk[10][2]))));
    Atir[11][1] = (Atkr[10][1]+(((Otkr[10][2]*ri[7][0])-(Otkr[10][0]*ri[7][2]))+
      ((Wirk[11][0]*wk[10][2])-(Wirk[11][2]*wk[10][0]))));
    Atir[11][2] = (Atkr[10][2]+(((Otkr[10][0]*ri[7][1])-(Otkr[10][1]*ri[7][0]))+
      ((Wirk[11][1]*wk[10][0])-(Wirk[11][0]*wk[10][1]))));
    Atkr[11][0] = (((Atir[11][2]*Cik[11][2][0])+((Atir[11][0]*Cik[11][0][0])+(
      Atir[11][1]*Cik[11][1][0])))+(((Otkr[11][2]*rk[7][1])-(Otkr[11][1]*
      rk[7][2]))+((wk[11][1]*Wkrpk[11][2])-(wk[11][2]*Wkrpk[11][1]))));
    Atkr[11][1] = (((Atir[11][2]*Cik[11][2][1])+((Atir[11][0]*Cik[11][0][1])+(
      Atir[11][1]*Cik[11][1][1])))+(((Otkr[11][0]*rk[7][2])-(Otkr[11][2]*
      rk[7][0]))+((wk[11][2]*Wkrpk[11][0])-(wk[11][0]*Wkrpk[11][2]))));
    Atkr[11][2] = (((Atir[11][2]*Cik[11][2][2])+((Atir[11][0]*Cik[11][0][2])+(
      Atir[11][1]*Cik[11][1][2])))+(((Otkr[11][1]*rk[7][0])-(Otkr[11][0]*
      rk[7][1]))+((wk[11][0]*Wkrpk[11][1])-(wk[11][1]*Wkrpk[11][0]))));
    Atir[12][0] = (Atkr[11][0]+(((Otkr[11][1]*ri[8][2])-(Otkr[11][2]*ri[8][1]))+
      ((Wirk[12][2]*wk[11][1])-(Wirk[12][1]*wk[11][2]))));
    Atir[12][1] = (Atkr[11][1]+(((Otkr[11][2]*ri[8][0])-(Otkr[11][0]*ri[8][2]))+
      ((Wirk[12][0]*wk[11][2])-(Wirk[12][2]*wk[11][0]))));
    Atir[12][2] = (Atkr[11][2]+(((Otkr[11][0]*ri[8][1])-(Otkr[11][1]*ri[8][0]))+
      ((Wirk[12][1]*wk[11][0])-(Wirk[12][0]*wk[11][1]))));
    Atkr[12][0] = (((Atir[12][2]*Cik[12][2][0])+((Atir[12][0]*Cik[12][0][0])+(
      Atir[12][1]*Cik[12][1][0])))+(((Otkr[12][2]*rk[8][1])-(Otkr[12][1]*
      rk[8][2]))+((wk[12][1]*Wkrpk[12][2])-(wk[12][2]*Wkrpk[12][1]))));
    Atkr[12][1] = (((Atir[12][2]*Cik[12][2][1])+((Atir[12][0]*Cik[12][0][1])+(
      Atir[12][1]*Cik[12][1][1])))+(((Otkr[12][0]*rk[8][2])-(Otkr[12][2]*
      rk[8][0]))+((wk[12][2]*Wkrpk[12][0])-(wk[12][0]*Wkrpk[12][2]))));
    Atkr[12][2] = (((Atir[12][2]*Cik[12][2][2])+((Atir[12][0]*Cik[12][0][2])+(
      Atir[12][1]*Cik[12][1][2])))+(((Otkr[12][1]*rk[8][0])-(Otkr[12][0]*
      rk[8][1]))+((wk[12][0]*Wkrpk[12][1])-(wk[12][1]*Wkrpk[12][0]))));
    Atir[13][0] = (Atkr[12][0]+(((Otkr[12][1]*ri[9][2])-(Otkr[12][2]*ri[9][1]))+
      ((Wirk[13][2]*wk[12][1])-(Wirk[13][1]*wk[12][2]))));
    Atir[13][1] = (Atkr[12][1]+(((Otkr[12][2]*ri[9][0])-(Otkr[12][0]*ri[9][2]))+
      ((Wirk[13][0]*wk[12][2])-(Wirk[13][2]*wk[12][0]))));
    Atir[13][2] = (Atkr[12][2]+(((Otkr[12][0]*ri[9][1])-(Otkr[12][1]*ri[9][0]))+
      ((Wirk[13][1]*wk[12][0])-(Wirk[13][0]*wk[12][1]))));
    Atkr[13][0] = (((Atir[13][2]*Cik[13][2][0])+((Atir[13][0]*Cik[13][0][0])+(
      Atir[13][1]*Cik[13][1][0])))+(((Otkr[13][2]*psrk[13][1])-(Otkr[13][1]*
      psrk[13][2]))+((wk[13][1]*Wkrpk[13][2])-(wk[13][2]*Wkrpk[13][1]))));
    Atkr[13][1] = (((Atir[13][2]*Cik[13][2][1])+((Atir[13][0]*Cik[13][0][1])+(
      Atir[13][1]*Cik[13][1][1])))+(((Otkr[13][0]*psrk[13][2])-(Otkr[13][2]*
      psrk[13][0]))+((wk[13][2]*Wkrpk[13][0])-(wk[13][0]*Wkrpk[13][2]))));
    Atkr[13][2] = (((Atir[13][2]*Cik[13][2][2])+((Atir[13][0]*Cik[13][0][2])+(
      Atir[13][1]*Cik[13][1][2])))+(((Otkr[13][1]*psrk[13][0])-(Otkr[13][0]*
      psrk[13][1]))+((wk[13][0]*Wkrpk[13][1])-(wk[13][1]*Wkrpk[13][0]))));
    Atir[14][0] = (Atkr[5][0]+(((ri[11][2]*udotin[4])-(ri[11][1]*udotin[5]))+((
      u[4]*Wirk[14][2])-(u[5]*Wirk[14][1]))));
    Atir[14][1] = (Atkr[5][1]+(((ri[11][0]*udotin[5])-(ri[11][2]*udotin[3]))+((
      u[5]*Wirk[14][0])-(u[3]*Wirk[14][2]))));
    Atir[14][2] = (Atkr[5][2]+(((ri[11][1]*udotin[3])-(ri[11][0]*udotin[4]))+((
      u[3]*Wirk[14][1])-(u[4]*Wirk[14][0]))));
    Atkr[14][0] = (((Atir[14][2]*Cik[14][2][0])+((Atir[14][0]*Cik[14][0][0])+(
      Atir[14][1]*Cik[14][1][0])))+(((Otkr[14][2]*rk[11][1])-(Otkr[14][1]*
      rk[11][2]))+((wk[14][1]*Wkrpk[14][2])-(wk[14][2]*Wkrpk[14][1]))));
    Atkr[14][1] = (((Atir[14][2]*Cik[14][2][1])+((Atir[14][0]*Cik[14][0][1])+(
      Atir[14][1]*Cik[14][1][1])))+(((Otkr[14][0]*rk[11][2])-(Otkr[14][2]*
      rk[11][0]))+((wk[14][2]*Wkrpk[14][0])-(wk[14][0]*Wkrpk[14][2]))));
    Atkr[14][2] = (((Atir[14][2]*Cik[14][2][2])+((Atir[14][0]*Cik[14][0][2])+(
      Atir[14][1]*Cik[14][1][2])))+(((Otkr[14][1]*rk[11][0])-(Otkr[14][0]*
      rk[11][1]))+((wk[14][0]*Wkrpk[14][1])-(wk[14][1]*Wkrpk[14][0]))));
    Atir[15][0] = (Atkr[14][0]+(((Otkr[14][1]*ri[12][2])-(Otkr[14][2]*ri[12][1])
      )+((Wirk[15][2]*wk[14][1])-(Wirk[15][1]*wk[14][2]))));
    Atir[15][1] = (Atkr[14][1]+(((Otkr[14][2]*ri[12][0])-(Otkr[14][0]*ri[12][2])
      )+((Wirk[15][0]*wk[14][2])-(Wirk[15][2]*wk[14][0]))));
    Atir[15][2] = (Atkr[14][2]+(((Otkr[14][0]*ri[12][1])-(Otkr[14][1]*ri[12][0])
      )+((Wirk[15][1]*wk[14][0])-(Wirk[15][0]*wk[14][1]))));
    Atkr[15][0] = (((Atir[15][2]*Cik[15][2][0])+((Atir[15][0]*Cik[15][0][0])+(
      Atir[15][1]*Cik[15][1][0])))+(((Otkr[15][2]*rk[12][1])-(Otkr[15][1]*
      rk[12][2]))+((wk[15][1]*Wkrpk[15][2])-(wk[15][2]*Wkrpk[15][1]))));
    Atkr[15][1] = (((Atir[15][2]*Cik[15][2][1])+((Atir[15][0]*Cik[15][0][1])+(
      Atir[15][1]*Cik[15][1][1])))+(((Otkr[15][0]*rk[12][2])-(Otkr[15][2]*
      rk[12][0]))+((wk[15][2]*Wkrpk[15][0])-(wk[15][0]*Wkrpk[15][2]))));
    Atkr[15][2] = (((Atir[15][2]*Cik[15][2][2])+((Atir[15][0]*Cik[15][0][2])+(
      Atir[15][1]*Cik[15][1][2])))+(((Otkr[15][1]*rk[12][0])-(Otkr[15][0]*
      rk[12][1]))+((wk[15][0]*Wkrpk[15][1])-(wk[15][1]*Wkrpk[15][0]))));
    Atir[16][0] = (Atkr[15][0]+(((Otkr[15][1]*ri[13][2])-(Otkr[15][2]*ri[13][1])
      )+((Wirk[16][2]*wk[15][1])-(Wirk[16][1]*wk[15][2]))));
    Atir[16][1] = (Atkr[15][1]+(((Otkr[15][2]*ri[13][0])-(Otkr[15][0]*ri[13][2])
      )+((Wirk[16][0]*wk[15][2])-(Wirk[16][2]*wk[15][0]))));
    Atir[16][2] = (Atkr[15][2]+(((Otkr[15][0]*ri[13][1])-(Otkr[15][1]*ri[13][0])
      )+((Wirk[16][1]*wk[15][0])-(Wirk[16][0]*wk[15][1]))));
    Atkr[16][0] = (((Atir[16][2]*Cik[16][2][0])+((Atir[16][0]*Cik[16][0][0])+(
      Atir[16][1]*Cik[16][1][0])))+(((Otkr[16][2]*rk[13][1])-(Otkr[16][1]*
      rk[13][2]))+((wk[16][1]*Wkrpk[16][2])-(wk[16][2]*Wkrpk[16][1]))));
    Atkr[16][1] = (((Atir[16][2]*Cik[16][2][1])+((Atir[16][0]*Cik[16][0][1])+(
      Atir[16][1]*Cik[16][1][1])))+(((Otkr[16][0]*rk[13][2])-(Otkr[16][2]*
      rk[13][0]))+((wk[16][2]*Wkrpk[16][0])-(wk[16][0]*Wkrpk[16][2]))));
    Atkr[16][2] = (((Atir[16][2]*Cik[16][2][2])+((Atir[16][0]*Cik[16][0][2])+(
      Atir[16][1]*Cik[16][1][2])))+(((Otkr[16][1]*rk[13][0])-(Otkr[16][0]*
      rk[13][1]))+((wk[16][0]*Wkrpk[16][1])-(wk[16][1]*Wkrpk[16][0]))));
    Atir[17][0] = (Atkr[16][0]+(((Otkr[16][1]*ri[14][2])-(Otkr[16][2]*ri[14][1])
      )+((Wirk[17][2]*wk[16][1])-(Wirk[17][1]*wk[16][2]))));
    Atir[17][1] = (Atkr[16][1]+(((Otkr[16][2]*ri[14][0])-(Otkr[16][0]*ri[14][2])
      )+((Wirk[17][0]*wk[16][2])-(Wirk[17][2]*wk[16][0]))));
    Atir[17][2] = (Atkr[16][2]+(((Otkr[16][0]*ri[14][1])-(Otkr[16][1]*ri[14][0])
      )+((Wirk[17][1]*wk[16][0])-(Wirk[17][0]*wk[16][1]))));
    Atkr[17][0] = (((Atir[17][2]*Cik[17][2][0])+((Atir[17][0]*Cik[17][0][0])+(
      Atir[17][1]*Cik[17][1][0])))+(((Otkr[17][2]*psrk[17][1])-(Otkr[17][1]*
      psrk[17][2]))+((wk[17][1]*Wkrpk[17][2])-(wk[17][2]*Wkrpk[17][1]))));
    Atkr[17][1] = (((Atir[17][2]*Cik[17][2][1])+((Atir[17][0]*Cik[17][0][1])+(
      Atir[17][1]*Cik[17][1][1])))+(((Otkr[17][0]*psrk[17][2])-(Otkr[17][2]*
      psrk[17][0]))+((wk[17][2]*Wkrpk[17][0])-(wk[17][0]*Wkrpk[17][2]))));
    Atkr[17][2] = (((Atir[17][2]*Cik[17][2][2])+((Atir[17][0]*Cik[17][0][2])+(
      Atir[17][1]*Cik[17][1][2])))+(((Otkr[17][1]*psrk[17][0])-(Otkr[17][0]*
      psrk[17][1]))+((wk[17][0]*Wkrpk[17][1])-(wk[17][1]*Wkrpk[17][0]))));
    Atir[18][0] = (Atkr[5][0]+(((ri[16][2]*udotin[4])-(ri[16][1]*udotin[5]))+((
      u[4]*Wirk[18][2])-(u[5]*Wirk[18][1]))));
    Atir[18][1] = (Atkr[5][1]+(((ri[16][0]*udotin[5])-(ri[16][2]*udotin[3]))+((
      u[5]*Wirk[18][0])-(u[3]*Wirk[18][2]))));
    Atir[18][2] = (Atkr[5][2]+(((ri[16][1]*udotin[3])-(ri[16][0]*udotin[4]))+((
      u[3]*Wirk[18][1])-(u[4]*Wirk[18][0]))));
    Atkr[18][0] = (((Atir[18][2]*Cik[18][2][0])+((Atir[18][0]*Cik[18][0][0])+(
      Atir[18][1]*Cik[18][1][0])))+(((Otkr[18][2]*rk[16][1])-(Otkr[18][1]*
      rk[16][2]))+((wk[18][1]*Wkrpk[18][2])-(wk[18][2]*Wkrpk[18][1]))));
    Atkr[18][1] = (((Atir[18][2]*Cik[18][2][1])+((Atir[18][0]*Cik[18][0][1])+(
      Atir[18][1]*Cik[18][1][1])))+(((Otkr[18][0]*rk[16][2])-(Otkr[18][2]*
      rk[16][0]))+((wk[18][2]*Wkrpk[18][0])-(wk[18][0]*Wkrpk[18][2]))));
    Atkr[18][2] = (((Atir[18][2]*Cik[18][2][2])+((Atir[18][0]*Cik[18][0][2])+(
      Atir[18][1]*Cik[18][1][2])))+(((Otkr[18][1]*rk[16][0])-(Otkr[18][0]*
      rk[16][1]))+((wk[18][0]*Wkrpk[18][1])-(wk[18][1]*Wkrpk[18][0]))));
    Atir[19][0] = (Atkr[18][0]+(((Otkr[18][1]*ri[17][2])-(Otkr[18][2]*ri[17][1])
      )+((Wirk[19][2]*wk[18][1])-(Wirk[19][1]*wk[18][2]))));
    Atir[19][1] = (Atkr[18][1]+(((Otkr[18][2]*ri[17][0])-(Otkr[18][0]*ri[17][2])
      )+((Wirk[19][0]*wk[18][2])-(Wirk[19][2]*wk[18][0]))));
    Atir[19][2] = (Atkr[18][2]+(((Otkr[18][0]*ri[17][1])-(Otkr[18][1]*ri[17][0])
      )+((Wirk[19][1]*wk[18][0])-(Wirk[19][0]*wk[18][1]))));
    Atkr[19][0] = (((Atir[19][2]*Cik[19][2][0])+((Atir[19][0]*Cik[19][0][0])+(
      Atir[19][1]*Cik[19][1][0])))+(((Otkr[19][2]*rk[17][1])-(Otkr[19][1]*
      rk[17][2]))+((wk[19][1]*Wkrpk[19][2])-(wk[19][2]*Wkrpk[19][1]))));
    Atkr[19][1] = (((Atir[19][2]*Cik[19][2][1])+((Atir[19][0]*Cik[19][0][1])+(
      Atir[19][1]*Cik[19][1][1])))+(((Otkr[19][0]*rk[17][2])-(Otkr[19][2]*
      rk[17][0]))+((wk[19][2]*Wkrpk[19][0])-(wk[19][0]*Wkrpk[19][2]))));
    Atkr[19][2] = (((Atir[19][2]*Cik[19][2][2])+((Atir[19][0]*Cik[19][0][2])+(
      Atir[19][1]*Cik[19][1][2])))+(((Otkr[19][1]*rk[17][0])-(Otkr[19][0]*
      rk[17][1]))+((wk[19][0]*Wkrpk[19][1])-(wk[19][1]*Wkrpk[19][0]))));
    Atir[20][0] = (Atkr[19][0]+(((Otkr[19][1]*ri[18][2])-(Otkr[19][2]*ri[18][1])
      )+((Wirk[20][2]*wk[19][1])-(Wirk[20][1]*wk[19][2]))));
    Atir[20][1] = (Atkr[19][1]+(((Otkr[19][2]*ri[18][0])-(Otkr[19][0]*ri[18][2])
      )+((Wirk[20][0]*wk[19][2])-(Wirk[20][2]*wk[19][0]))));
    Atir[20][2] = (Atkr[19][2]+(((Otkr[19][0]*ri[18][1])-(Otkr[19][1]*ri[18][0])
      )+((Wirk[20][1]*wk[19][0])-(Wirk[20][0]*wk[19][1]))));
    Atkr[20][0] = (((Atir[20][2]*Cik[20][2][0])+((Atir[20][0]*Cik[20][0][0])+(
      Atir[20][1]*Cik[20][1][0])))+(((Otkr[20][2]*rk[18][1])-(Otkr[20][1]*
      rk[18][2]))+((wk[20][1]*Wkrpk[20][2])-(wk[20][2]*Wkrpk[20][1]))));
    Atkr[20][1] = (((Atir[20][2]*Cik[20][2][1])+((Atir[20][0]*Cik[20][0][1])+(
      Atir[20][1]*Cik[20][1][1])))+(((Otkr[20][0]*rk[18][2])-(Otkr[20][2]*
      rk[18][0]))+((wk[20][2]*Wkrpk[20][0])-(wk[20][0]*Wkrpk[20][2]))));
    Atkr[20][2] = (((Atir[20][2]*Cik[20][2][2])+((Atir[20][0]*Cik[20][0][2])+(
      Atir[20][1]*Cik[20][1][2])))+(((Otkr[20][1]*rk[18][0])-(Otkr[20][0]*
      rk[18][1]))+((wk[20][0]*Wkrpk[20][1])-(wk[20][1]*Wkrpk[20][0]))));
    Atir[21][0] = (Atkr[20][0]+(((Otkr[20][1]*ri[19][2])-(Otkr[20][2]*ri[19][1])
      )+((Wirk[21][2]*wk[20][1])-(Wirk[21][1]*wk[20][2]))));
    Atir[21][1] = (Atkr[20][1]+(((Otkr[20][2]*ri[19][0])-(Otkr[20][0]*ri[19][2])
      )+((Wirk[21][0]*wk[20][2])-(Wirk[21][2]*wk[20][0]))));
    Atir[21][2] = (Atkr[20][2]+(((Otkr[20][0]*ri[19][1])-(Otkr[20][1]*ri[19][0])
      )+((Wirk[21][1]*wk[20][0])-(Wirk[21][0]*wk[20][1]))));
    Atkr[21][0] = (((Atir[21][2]*Cik[21][2][0])+((Atir[21][0]*Cik[21][0][0])+(
      Atir[21][1]*Cik[21][1][0])))+(((Otkr[21][2]*psrk[21][1])-(Otkr[21][1]*
      psrk[21][2]))+((wk[21][1]*Wkrpk[21][2])-(wk[21][2]*Wkrpk[21][1]))));
    Atkr[21][1] = (((Atir[21][2]*Cik[21][2][1])+((Atir[21][0]*Cik[21][0][1])+(
      Atir[21][1]*Cik[21][1][1])))+(((Otkr[21][0]*psrk[21][2])-(Otkr[21][2]*
      psrk[21][0]))+((wk[21][2]*Wkrpk[21][0])-(wk[21][0]*Wkrpk[21][2]))));
    Atkr[21][2] = (((Atir[21][2]*Cik[21][2][2])+((Atir[21][0]*Cik[21][0][2])+(
      Atir[21][1]*Cik[21][1][2])))+(((Otkr[21][1]*psrk[21][0])-(Otkr[21][0]*
      psrk[21][1]))+((wk[21][0]*Wkrpk[21][1])-(wk[21][1]*Wkrpk[21][0]))));
/*
Accumulate all forces and torques
*/
    fstarr[5][0] = (ufk[0][0]+(mk[0]*(gk[3][0]-Atkr[5][0])));
    fstarr[5][1] = (ufk[0][1]+(mk[0]*(gk[3][1]-Atkr[5][1])));
    fstarr[5][2] = (ufk[0][2]+(mk[0]*(gk[3][2]-Atkr[5][2])));
    fstarr[6][0] = (ufk[1][0]+(mk[1]*(gk[6][0]-Atkr[6][0])));
    fstarr[6][1] = (ufk[1][1]+(mk[1]*(gk[6][1]-Atkr[6][1])));
    fstarr[6][2] = (ufk[1][2]+(mk[1]*(gk[6][2]-Atkr[6][2])));
    fstarr[7][0] = (ufk[2][0]+(mk[2]*(gk[7][0]-Atkr[7][0])));
    fstarr[7][1] = (ufk[2][1]+(mk[2]*(gk[7][1]-Atkr[7][1])));
    fstarr[7][2] = (ufk[2][2]+(mk[2]*(gk[7][2]-Atkr[7][2])));
    fstarr[8][0] = (ufk[3][0]+(mk[3]*(gk[8][0]-Atkr[8][0])));
    fstarr[8][1] = (ufk[3][1]+(mk[3]*(gk[8][1]-Atkr[8][1])));
    fstarr[8][2] = (ufk[3][2]+(mk[3]*(gk[8][2]-Atkr[8][2])));
    fstarr[9][0] = (ufk[5][0]+(ufk[4][0]+(psmk[9]*(gk[9][0]-Atkr[9][0]))));
    fstarr[9][1] = (ufk[5][1]+(ufk[4][1]+(psmk[9]*(gk[9][1]-Atkr[9][1]))));
    fstarr[9][2] = (ufk[5][2]+(ufk[4][2]+(psmk[9]*(gk[9][2]-Atkr[9][2]))));
    fstarr[10][0] = (ufk[6][0]+(mk[6]*(gk[10][0]-Atkr[10][0])));
    fstarr[10][1] = (ufk[6][1]+(mk[6]*(gk[10][1]-Atkr[10][1])));
    fstarr[10][2] = (ufk[6][2]+(mk[6]*(gk[10][2]-Atkr[10][2])));
    fstarr[11][0] = (ufk[7][0]+(mk[7]*(gk[11][0]-Atkr[11][0])));
    fstarr[11][1] = (ufk[7][1]+(mk[7]*(gk[11][1]-Atkr[11][1])));
    fstarr[11][2] = (ufk[7][2]+(mk[7]*(gk[11][2]-Atkr[11][2])));
    fstarr[12][0] = (ufk[8][0]+(mk[8]*(gk[12][0]-Atkr[12][0])));
    fstarr[12][1] = (ufk[8][1]+(mk[8]*(gk[12][1]-Atkr[12][1])));
    fstarr[12][2] = (ufk[8][2]+(mk[8]*(gk[12][2]-Atkr[12][2])));
    fstarr[13][0] = (ufk[10][0]+(ufk[9][0]+(psmk[13]*(gk[13][0]-Atkr[13][0]))));
    fstarr[13][1] = (ufk[10][1]+(ufk[9][1]+(psmk[13]*(gk[13][1]-Atkr[13][1]))));
    fstarr[13][2] = (ufk[10][2]+(ufk[9][2]+(psmk[13]*(gk[13][2]-Atkr[13][2]))));
    fstarr[14][0] = (ufk[11][0]+(mk[11]*(gk[14][0]-Atkr[14][0])));
    fstarr[14][1] = (ufk[11][1]+(mk[11]*(gk[14][1]-Atkr[14][1])));
    fstarr[14][2] = (ufk[11][2]+(mk[11]*(gk[14][2]-Atkr[14][2])));
    fstarr[15][0] = (ufk[12][0]+(mk[12]*(gk[15][0]-Atkr[15][0])));
    fstarr[15][1] = (ufk[12][1]+(mk[12]*(gk[15][1]-Atkr[15][1])));
    fstarr[15][2] = (ufk[12][2]+(mk[12]*(gk[15][2]-Atkr[15][2])));
    fstarr[16][0] = (ufk[13][0]+(mk[13]*(gk[16][0]-Atkr[16][0])));
    fstarr[16][1] = (ufk[13][1]+(mk[13]*(gk[16][1]-Atkr[16][1])));
    fstarr[16][2] = (ufk[13][2]+(mk[13]*(gk[16][2]-Atkr[16][2])));
    fstarr[17][0] = (ufk[15][0]+(ufk[14][0]+(psmk[17]*(gk[17][0]-Atkr[17][0]))))
      ;
    fstarr[17][1] = (ufk[15][1]+(ufk[14][1]+(psmk[17]*(gk[17][1]-Atkr[17][1]))))
      ;
    fstarr[17][2] = (ufk[15][2]+(ufk[14][2]+(psmk[17]*(gk[17][2]-Atkr[17][2]))))
      ;
    fstarr[18][0] = (ufk[16][0]+(mk[16]*(gk[18][0]-Atkr[18][0])));
    fstarr[18][1] = (ufk[16][1]+(mk[16]*(gk[18][1]-Atkr[18][1])));
    fstarr[18][2] = (ufk[16][2]+(mk[16]*(gk[18][2]-Atkr[18][2])));
    fstarr[19][0] = (ufk[17][0]+(mk[17]*(gk[19][0]-Atkr[19][0])));
    fstarr[19][1] = (ufk[17][1]+(mk[17]*(gk[19][1]-Atkr[19][1])));
    fstarr[19][2] = (ufk[17][2]+(mk[17]*(gk[19][2]-Atkr[19][2])));
    fstarr[20][0] = (ufk[18][0]+(mk[18]*(gk[20][0]-Atkr[20][0])));
    fstarr[20][1] = (ufk[18][1]+(mk[18]*(gk[20][1]-Atkr[20][1])));
    fstarr[20][2] = (ufk[18][2]+(mk[18]*(gk[20][2]-Atkr[20][2])));
    fstarr[21][0] = (ufk[20][0]+(ufk[19][0]+(psmk[21]*(gk[21][0]-Atkr[21][0]))))
      ;
    fstarr[21][1] = (ufk[20][1]+(ufk[19][1]+(psmk[21]*(gk[21][1]-Atkr[21][1]))))
      ;
    fstarr[21][2] = (ufk[20][2]+(ufk[19][2]+(psmk[21]*(gk[21][2]-Atkr[21][2]))))
      ;
    tstarr[5][0] = (utk[0][0]-(WkIkWk[5][0]+((ik[0][0][2]*udotin[5])+((
      ik[0][0][0]*udotin[3])+(ik[0][0][1]*udotin[4])))));
    tstarr[5][1] = (utk[0][1]-(WkIkWk[5][1]+((ik[0][1][2]*udotin[5])+((
      ik[0][1][0]*udotin[3])+(ik[0][1][1]*udotin[4])))));
    tstarr[5][2] = (utk[0][2]-(WkIkWk[5][2]+((ik[0][2][2]*udotin[5])+((
      ik[0][2][0]*udotin[3])+(ik[0][2][1]*udotin[4])))));
    tstarr[6][0] = (utk[1][0]-(WkIkWk[6][0]+((ik[1][0][2]*Otkr[6][2])+((
      ik[1][0][0]*Otkr[6][0])+(ik[1][0][1]*Otkr[6][1])))));
    tstarr[6][1] = (utk[1][1]-(WkIkWk[6][1]+((ik[1][1][2]*Otkr[6][2])+((
      ik[1][1][0]*Otkr[6][0])+(ik[1][1][1]*Otkr[6][1])))));
    tstarr[6][2] = (utk[1][2]-(WkIkWk[6][2]+((ik[1][2][2]*Otkr[6][2])+((
      ik[1][2][0]*Otkr[6][0])+(ik[1][2][1]*Otkr[6][1])))));
    tstarr[7][0] = (utk[2][0]-(WkIkWk[7][0]+((ik[2][0][2]*Otkr[7][2])+((
      ik[2][0][0]*Otkr[7][0])+(ik[2][0][1]*Otkr[7][1])))));
    tstarr[7][1] = (utk[2][1]-(WkIkWk[7][1]+((ik[2][1][2]*Otkr[7][2])+((
      ik[2][1][0]*Otkr[7][0])+(ik[2][1][1]*Otkr[7][1])))));
    tstarr[7][2] = (utk[2][2]-(WkIkWk[7][2]+((ik[2][2][2]*Otkr[7][2])+((
      ik[2][2][0]*Otkr[7][0])+(ik[2][2][1]*Otkr[7][1])))));
    tstarr[8][0] = (utk[3][0]-(WkIkWk[8][0]+((ik[3][0][2]*Otkr[8][2])+((
      ik[3][0][0]*Otkr[8][0])+(ik[3][0][1]*Otkr[8][1])))));
    tstarr[8][1] = (utk[3][1]-(WkIkWk[8][1]+((ik[3][1][2]*Otkr[8][2])+((
      ik[3][1][0]*Otkr[8][0])+(ik[3][1][1]*Otkr[8][1])))));
    tstarr[8][2] = (utk[3][2]-(WkIkWk[8][2]+((ik[3][2][2]*Otkr[8][2])+((
      ik[3][2][0]*Otkr[8][0])+(ik[3][2][1]*Otkr[8][1])))));
    tstarr[9][0] = ((utk[5][0]+((rcom[5][1]*ufk[5][2])-(rcom[5][2]*ufk[5][1])))+
      ((utk[4][0]+((rcom[4][1]*ufk[4][2])-(rcom[4][2]*ufk[4][1])))-(WkIkWk[9][0]
      +((Otkr[9][2]*psik[9][0][2])+((Otkr[9][0]*psik[9][0][0])+(Otkr[9][1]*
      psik[9][0][1]))))));
    tstarr[9][1] = ((utk[5][1]+((rcom[5][2]*ufk[5][0])-(rcom[5][0]*ufk[5][2])))+
      ((utk[4][1]+((rcom[4][2]*ufk[4][0])-(rcom[4][0]*ufk[4][2])))-(WkIkWk[9][1]
      +((Otkr[9][2]*psik[9][1][2])+((Otkr[9][0]*psik[9][1][0])+(Otkr[9][1]*
      psik[9][1][1]))))));
    tstarr[9][2] = ((utk[5][2]+((rcom[5][0]*ufk[5][1])-(rcom[5][1]*ufk[5][0])))+
      ((utk[4][2]+((rcom[4][0]*ufk[4][1])-(rcom[4][1]*ufk[4][0])))-(WkIkWk[9][2]
      +((Otkr[9][2]*psik[9][2][2])+((Otkr[9][0]*psik[9][2][0])+(Otkr[9][1]*
      psik[9][2][1]))))));
    tstarr[10][0] = (utk[6][0]-(WkIkWk[10][0]+((ik[6][0][2]*Otkr[10][2])+((
      ik[6][0][0]*Otkr[10][0])+(ik[6][0][1]*Otkr[10][1])))));
    tstarr[10][1] = (utk[6][1]-(WkIkWk[10][1]+((ik[6][1][2]*Otkr[10][2])+((
      ik[6][1][0]*Otkr[10][0])+(ik[6][1][1]*Otkr[10][1])))));
    tstarr[10][2] = (utk[6][2]-(WkIkWk[10][2]+((ik[6][2][2]*Otkr[10][2])+((
      ik[6][2][0]*Otkr[10][0])+(ik[6][2][1]*Otkr[10][1])))));
    tstarr[11][0] = (utk[7][0]-(WkIkWk[11][0]+((ik[7][0][2]*Otkr[11][2])+((
      ik[7][0][0]*Otkr[11][0])+(ik[7][0][1]*Otkr[11][1])))));
    tstarr[11][1] = (utk[7][1]-(WkIkWk[11][1]+((ik[7][1][2]*Otkr[11][2])+((
      ik[7][1][0]*Otkr[11][0])+(ik[7][1][1]*Otkr[11][1])))));
    tstarr[11][2] = (utk[7][2]-(WkIkWk[11][2]+((ik[7][2][2]*Otkr[11][2])+((
      ik[7][2][0]*Otkr[11][0])+(ik[7][2][1]*Otkr[11][1])))));
    tstarr[12][0] = (utk[8][0]-(WkIkWk[12][0]+((ik[8][0][2]*Otkr[12][2])+((
      ik[8][0][0]*Otkr[12][0])+(ik[8][0][1]*Otkr[12][1])))));
    tstarr[12][1] = (utk[8][1]-(WkIkWk[12][1]+((ik[8][1][2]*Otkr[12][2])+((
      ik[8][1][0]*Otkr[12][0])+(ik[8][1][1]*Otkr[12][1])))));
    tstarr[12][2] = (utk[8][2]-(WkIkWk[12][2]+((ik[8][2][2]*Otkr[12][2])+((
      ik[8][2][0]*Otkr[12][0])+(ik[8][2][1]*Otkr[12][1])))));
    tstarr[13][0] = ((utk[10][0]+((rcom[10][1]*ufk[10][2])-(rcom[10][2]*
      ufk[10][1])))+((utk[9][0]+((rcom[9][1]*ufk[9][2])-(rcom[9][2]*ufk[9][1])))
      -(WkIkWk[13][0]+((Otkr[13][2]*psik[13][0][2])+((Otkr[13][0]*psik[13][0][0]
      )+(Otkr[13][1]*psik[13][0][1]))))));
    tstarr[13][1] = ((utk[10][1]+((rcom[10][2]*ufk[10][0])-(rcom[10][0]*
      ufk[10][2])))+((utk[9][1]+((rcom[9][2]*ufk[9][0])-(rcom[9][0]*ufk[9][2])))
      -(WkIkWk[13][1]+((Otkr[13][2]*psik[13][1][2])+((Otkr[13][0]*psik[13][1][0]
      )+(Otkr[13][1]*psik[13][1][1]))))));
    tstarr[13][2] = ((utk[10][2]+((rcom[10][0]*ufk[10][1])-(rcom[10][1]*
      ufk[10][0])))+((utk[9][2]+((rcom[9][0]*ufk[9][1])-(rcom[9][1]*ufk[9][0])))
      -(WkIkWk[13][2]+((Otkr[13][2]*psik[13][2][2])+((Otkr[13][0]*psik[13][2][0]
      )+(Otkr[13][1]*psik[13][2][1]))))));
    tstarr[14][0] = (utk[11][0]-(WkIkWk[14][0]+((ik[11][0][2]*Otkr[14][2])+((
      ik[11][0][0]*Otkr[14][0])+(ik[11][0][1]*Otkr[14][1])))));
    tstarr[14][1] = (utk[11][1]-(WkIkWk[14][1]+((ik[11][1][2]*Otkr[14][2])+((
      ik[11][1][0]*Otkr[14][0])+(ik[11][1][1]*Otkr[14][1])))));
    tstarr[14][2] = (utk[11][2]-(WkIkWk[14][2]+((ik[11][2][2]*Otkr[14][2])+((
      ik[11][2][0]*Otkr[14][0])+(ik[11][2][1]*Otkr[14][1])))));
    tstarr[15][0] = (utk[12][0]-(WkIkWk[15][0]+((ik[12][0][2]*Otkr[15][2])+((
      ik[12][0][0]*Otkr[15][0])+(ik[12][0][1]*Otkr[15][1])))));
    tstarr[15][1] = (utk[12][1]-(WkIkWk[15][1]+((ik[12][1][2]*Otkr[15][2])+((
      ik[12][1][0]*Otkr[15][0])+(ik[12][1][1]*Otkr[15][1])))));
    tstarr[15][2] = (utk[12][2]-(WkIkWk[15][2]+((ik[12][2][2]*Otkr[15][2])+((
      ik[12][2][0]*Otkr[15][0])+(ik[12][2][1]*Otkr[15][1])))));
    tstarr[16][0] = (utk[13][0]-(WkIkWk[16][0]+((ik[13][0][2]*Otkr[16][2])+((
      ik[13][0][0]*Otkr[16][0])+(ik[13][0][1]*Otkr[16][1])))));
    tstarr[16][1] = (utk[13][1]-(WkIkWk[16][1]+((ik[13][1][2]*Otkr[16][2])+((
      ik[13][1][0]*Otkr[16][0])+(ik[13][1][1]*Otkr[16][1])))));
    tstarr[16][2] = (utk[13][2]-(WkIkWk[16][2]+((ik[13][2][2]*Otkr[16][2])+((
      ik[13][2][0]*Otkr[16][0])+(ik[13][2][1]*Otkr[16][1])))));
    tstarr[17][0] = ((utk[15][0]+((rcom[15][1]*ufk[15][2])-(rcom[15][2]*
      ufk[15][1])))+((utk[14][0]+((rcom[14][1]*ufk[14][2])-(rcom[14][2]*
      ufk[14][1])))-(WkIkWk[17][0]+((Otkr[17][2]*psik[17][0][2])+((Otkr[17][0]*
      psik[17][0][0])+(Otkr[17][1]*psik[17][0][1]))))));
    tstarr[17][1] = ((utk[15][1]+((rcom[15][2]*ufk[15][0])-(rcom[15][0]*
      ufk[15][2])))+((utk[14][1]+((rcom[14][2]*ufk[14][0])-(rcom[14][0]*
      ufk[14][2])))-(WkIkWk[17][1]+((Otkr[17][2]*psik[17][1][2])+((Otkr[17][0]*
      psik[17][1][0])+(Otkr[17][1]*psik[17][1][1]))))));
    tstarr[17][2] = ((utk[15][2]+((rcom[15][0]*ufk[15][1])-(rcom[15][1]*
      ufk[15][0])))+((utk[14][2]+((rcom[14][0]*ufk[14][1])-(rcom[14][1]*
      ufk[14][0])))-(WkIkWk[17][2]+((Otkr[17][2]*psik[17][2][2])+((Otkr[17][0]*
      psik[17][2][0])+(Otkr[17][1]*psik[17][2][1]))))));
    tstarr[18][0] = (utk[16][0]-(WkIkWk[18][0]+((ik[16][0][2]*Otkr[18][2])+((
      ik[16][0][0]*Otkr[18][0])+(ik[16][0][1]*Otkr[18][1])))));
    tstarr[18][1] = (utk[16][1]-(WkIkWk[18][1]+((ik[16][1][2]*Otkr[18][2])+((
      ik[16][1][0]*Otkr[18][0])+(ik[16][1][1]*Otkr[18][1])))));
    tstarr[18][2] = (utk[16][2]-(WkIkWk[18][2]+((ik[16][2][2]*Otkr[18][2])+((
      ik[16][2][0]*Otkr[18][0])+(ik[16][2][1]*Otkr[18][1])))));
    tstarr[19][0] = (utk[17][0]-(WkIkWk[19][0]+((ik[17][0][2]*Otkr[19][2])+((
      ik[17][0][0]*Otkr[19][0])+(ik[17][0][1]*Otkr[19][1])))));
    tstarr[19][1] = (utk[17][1]-(WkIkWk[19][1]+((ik[17][1][2]*Otkr[19][2])+((
      ik[17][1][0]*Otkr[19][0])+(ik[17][1][1]*Otkr[19][1])))));
    tstarr[19][2] = (utk[17][2]-(WkIkWk[19][2]+((ik[17][2][2]*Otkr[19][2])+((
      ik[17][2][0]*Otkr[19][0])+(ik[17][2][1]*Otkr[19][1])))));
    tstarr[20][0] = (utk[18][0]-(WkIkWk[20][0]+((ik[18][0][2]*Otkr[20][2])+((
      ik[18][0][0]*Otkr[20][0])+(ik[18][0][1]*Otkr[20][1])))));
    tstarr[20][1] = (utk[18][1]-(WkIkWk[20][1]+((ik[18][1][2]*Otkr[20][2])+((
      ik[18][1][0]*Otkr[20][0])+(ik[18][1][1]*Otkr[20][1])))));
    tstarr[20][2] = (utk[18][2]-(WkIkWk[20][2]+((ik[18][2][2]*Otkr[20][2])+((
      ik[18][2][0]*Otkr[20][0])+(ik[18][2][1]*Otkr[20][1])))));
    tstarr[21][0] = ((utk[20][0]+((rcom[20][1]*ufk[20][2])-(rcom[20][2]*
      ufk[20][1])))+((utk[19][0]+((rcom[19][1]*ufk[19][2])-(rcom[19][2]*
      ufk[19][1])))-(WkIkWk[21][0]+((Otkr[21][2]*psik[21][0][2])+((Otkr[21][0]*
      psik[21][0][0])+(Otkr[21][1]*psik[21][0][1]))))));
    tstarr[21][1] = ((utk[20][1]+((rcom[20][2]*ufk[20][0])-(rcom[20][0]*
      ufk[20][2])))+((utk[19][1]+((rcom[19][2]*ufk[19][0])-(rcom[19][0]*
      ufk[19][2])))-(WkIkWk[21][1]+((Otkr[21][2]*psik[21][1][2])+((Otkr[21][0]*
      psik[21][1][0])+(Otkr[21][1]*psik[21][1][1]))))));
    tstarr[21][2] = ((utk[20][2]+((rcom[20][0]*ufk[20][1])-(rcom[20][1]*
      ufk[20][0])))+((utk[19][2]+((rcom[19][0]*ufk[19][1])-(rcom[19][1]*
      ufk[19][0])))-(WkIkWk[21][2]+((Otkr[21][2]*psik[21][2][2])+((Otkr[21][0]*
      psik[21][2][0])+(Otkr[21][1]*psik[21][2][1]))))));
/*
Now calculate the torques
*/
    allegro_air_dovpk();
    temp[0] = (((fstarr[8][2]*Vpk[0][8][2])+((fstarr[8][0]*Vpk[0][8][0])+(
      fstarr[8][1]*Vpk[0][8][1])))+(((fstarr[7][2]*Vpk[0][7][2])+((fstarr[7][0]*
      Vpk[0][7][0])+(fstarr[7][1]*Vpk[0][7][1])))+(((fstarr[5][2]*Vpk[0][3][2])+
      ((fstarr[5][0]*Vpk[0][3][0])+(fstarr[5][1]*Vpk[0][3][1])))+((fstarr[6][2]*
      Vpk[0][6][2])+((fstarr[6][0]*Vpk[0][6][0])+(fstarr[6][1]*Vpk[0][6][1])))))
      );
    temp[1] = (((fstarr[12][2]*Vpk[0][12][2])+((fstarr[12][0]*Vpk[0][12][0])+(
      fstarr[12][1]*Vpk[0][12][1])))+(((fstarr[11][2]*Vpk[0][11][2])+((
      fstarr[11][0]*Vpk[0][11][0])+(fstarr[11][1]*Vpk[0][11][1])))+(((
      fstarr[10][2]*Vpk[0][10][2])+((fstarr[10][0]*Vpk[0][10][0])+(fstarr[10][1]
      *Vpk[0][10][1])))+(((fstarr[9][2]*Vpk[0][9][2])+((fstarr[9][0]*
      Vpk[0][9][0])+(fstarr[9][1]*Vpk[0][9][1])))+temp[0]))));
    temp[2] = (((fstarr[16][2]*Vpk[0][16][2])+((fstarr[16][0]*Vpk[0][16][0])+(
      fstarr[16][1]*Vpk[0][16][1])))+(((fstarr[15][2]*Vpk[0][15][2])+((
      fstarr[15][0]*Vpk[0][15][0])+(fstarr[15][1]*Vpk[0][15][1])))+(((
      fstarr[14][2]*Vpk[0][14][2])+((fstarr[14][0]*Vpk[0][14][0])+(fstarr[14][1]
      *Vpk[0][14][1])))+(((fstarr[13][2]*Vpk[0][13][2])+((fstarr[13][0]*
      Vpk[0][13][0])+(fstarr[13][1]*Vpk[0][13][1])))+temp[1]))));
    temp[3] = (((fstarr[20][2]*Vpk[0][20][2])+((fstarr[20][0]*Vpk[0][20][0])+(
      fstarr[20][1]*Vpk[0][20][1])))+(((fstarr[19][2]*Vpk[0][19][2])+((
      fstarr[19][0]*Vpk[0][19][0])+(fstarr[19][1]*Vpk[0][19][1])))+(((
      fstarr[18][2]*Vpk[0][18][2])+((fstarr[18][0]*Vpk[0][18][0])+(fstarr[18][1]
      *Vpk[0][18][1])))+(((fstarr[17][2]*Vpk[0][17][2])+((fstarr[17][0]*
      Vpk[0][17][0])+(fstarr[17][1]*Vpk[0][17][1])))+temp[2]))));
    trqout[0] = -((mtau[0]+utau[0])+(((fstarr[21][2]*Vpk[0][21][2])+((
      fstarr[21][0]*Vpk[0][21][0])+(fstarr[21][1]*Vpk[0][21][1])))+temp[3]));
    temp[0] = (((fstarr[8][2]*Vpk[1][8][2])+((fstarr[8][0]*Vpk[1][8][0])+(
      fstarr[8][1]*Vpk[1][8][1])))+(((fstarr[7][2]*Vpk[1][7][2])+((fstarr[7][0]*
      Vpk[1][7][0])+(fstarr[7][1]*Vpk[1][7][1])))+(((fstarr[5][2]*Vpk[1][3][2])+
      ((fstarr[5][0]*Vpk[1][3][0])+(fstarr[5][1]*Vpk[1][3][1])))+((fstarr[6][2]*
      Vpk[1][6][2])+((fstarr[6][0]*Vpk[1][6][0])+(fstarr[6][1]*Vpk[1][6][1])))))
      );
    temp[1] = (((fstarr[12][2]*Vpk[1][12][2])+((fstarr[12][0]*Vpk[1][12][0])+(
      fstarr[12][1]*Vpk[1][12][1])))+(((fstarr[11][2]*Vpk[1][11][2])+((
      fstarr[11][0]*Vpk[1][11][0])+(fstarr[11][1]*Vpk[1][11][1])))+(((
      fstarr[10][2]*Vpk[1][10][2])+((fstarr[10][0]*Vpk[1][10][0])+(fstarr[10][1]
      *Vpk[1][10][1])))+(((fstarr[9][2]*Vpk[1][9][2])+((fstarr[9][0]*
      Vpk[1][9][0])+(fstarr[9][1]*Vpk[1][9][1])))+temp[0]))));
    temp[2] = (((fstarr[16][2]*Vpk[1][16][2])+((fstarr[16][0]*Vpk[1][16][0])+(
      fstarr[16][1]*Vpk[1][16][1])))+(((fstarr[15][2]*Vpk[1][15][2])+((
      fstarr[15][0]*Vpk[1][15][0])+(fstarr[15][1]*Vpk[1][15][1])))+(((
      fstarr[14][2]*Vpk[1][14][2])+((fstarr[14][0]*Vpk[1][14][0])+(fstarr[14][1]
      *Vpk[1][14][1])))+(((fstarr[13][2]*Vpk[1][13][2])+((fstarr[13][0]*
      Vpk[1][13][0])+(fstarr[13][1]*Vpk[1][13][1])))+temp[1]))));
    temp[3] = (((fstarr[20][2]*Vpk[1][20][2])+((fstarr[20][0]*Vpk[1][20][0])+(
      fstarr[20][1]*Vpk[1][20][1])))+(((fstarr[19][2]*Vpk[1][19][2])+((
      fstarr[19][0]*Vpk[1][19][0])+(fstarr[19][1]*Vpk[1][19][1])))+(((
      fstarr[18][2]*Vpk[1][18][2])+((fstarr[18][0]*Vpk[1][18][0])+(fstarr[18][1]
      *Vpk[1][18][1])))+(((fstarr[17][2]*Vpk[1][17][2])+((fstarr[17][0]*
      Vpk[1][17][0])+(fstarr[17][1]*Vpk[1][17][1])))+temp[2]))));
    trqout[1] = -((mtau[1]+utau[1])+(((fstarr[21][2]*Vpk[1][21][2])+((
      fstarr[21][0]*Vpk[1][21][0])+(fstarr[21][1]*Vpk[1][21][1])))+temp[3]));
    temp[0] = (((fstarr[8][2]*Vpk[2][8][2])+((fstarr[8][0]*Vpk[2][8][0])+(
      fstarr[8][1]*Vpk[2][8][1])))+(((fstarr[7][2]*Vpk[2][7][2])+((fstarr[7][0]*
      Vpk[2][7][0])+(fstarr[7][1]*Vpk[2][7][1])))+(((fstarr[5][2]*Vpk[2][3][2])+
      ((fstarr[5][0]*Vpk[2][3][0])+(fstarr[5][1]*Vpk[2][3][1])))+((fstarr[6][2]*
      Vpk[2][6][2])+((fstarr[6][0]*Vpk[2][6][0])+(fstarr[6][1]*Vpk[2][6][1])))))
      );
    temp[1] = (((fstarr[12][2]*Vpk[2][12][2])+((fstarr[12][0]*Vpk[2][12][0])+(
      fstarr[12][1]*Vpk[2][12][1])))+(((fstarr[11][2]*Vpk[2][11][2])+((
      fstarr[11][0]*Vpk[2][11][0])+(fstarr[11][1]*Vpk[2][11][1])))+(((
      fstarr[10][2]*Vpk[2][10][2])+((fstarr[10][0]*Vpk[2][10][0])+(fstarr[10][1]
      *Vpk[2][10][1])))+(((fstarr[9][2]*Vpk[2][9][2])+((fstarr[9][0]*
      Vpk[2][9][0])+(fstarr[9][1]*Vpk[2][9][1])))+temp[0]))));
    temp[2] = (((fstarr[16][2]*Vpk[2][16][2])+((fstarr[16][0]*Vpk[2][16][0])+(
      fstarr[16][1]*Vpk[2][16][1])))+(((fstarr[15][2]*Vpk[2][15][2])+((
      fstarr[15][0]*Vpk[2][15][0])+(fstarr[15][1]*Vpk[2][15][1])))+(((
      fstarr[14][2]*Vpk[2][14][2])+((fstarr[14][0]*Vpk[2][14][0])+(fstarr[14][1]
      *Vpk[2][14][1])))+(((fstarr[13][2]*Vpk[2][13][2])+((fstarr[13][0]*
      Vpk[2][13][0])+(fstarr[13][1]*Vpk[2][13][1])))+temp[1]))));
    temp[3] = (((fstarr[20][2]*Vpk[2][20][2])+((fstarr[20][0]*Vpk[2][20][0])+(
      fstarr[20][1]*Vpk[2][20][1])))+(((fstarr[19][2]*Vpk[2][19][2])+((
      fstarr[19][0]*Vpk[2][19][0])+(fstarr[19][1]*Vpk[2][19][1])))+(((
      fstarr[18][2]*Vpk[2][18][2])+((fstarr[18][0]*Vpk[2][18][0])+(fstarr[18][1]
      *Vpk[2][18][1])))+(((fstarr[17][2]*Vpk[2][17][2])+((fstarr[17][0]*
      Vpk[2][17][0])+(fstarr[17][1]*Vpk[2][17][1])))+temp[2]))));
    trqout[2] = -((mtau[2]+utau[2])+(((fstarr[21][2]*Vpk[2][21][2])+((
      fstarr[21][0]*Vpk[2][21][0])+(fstarr[21][1]*Vpk[2][21][1])))+temp[3]));
    temp[0] = (((tstarr[5][0]+((fstarr[5][1]*rk[0][2])-(fstarr[5][2]*rk[0][1])))
      +(((Cik[6][0][2]*tstarr[6][2])+((Cik[6][0][0]*tstarr[6][0])+(Cik[6][0][1]*
      tstarr[6][1])))+((fstarr[6][2]*Vpk[3][6][2])+((fstarr[6][0]*Vpk[3][6][0])+
      (fstarr[6][1]*Vpk[3][6][1])))))+(((fstarr[7][2]*Vpk[3][7][2])+((
      fstarr[7][0]*Vpk[3][7][0])+(fstarr[7][1]*Vpk[3][7][1])))+((tstarr[7][2]*
      Wpk[3][7][2])+((tstarr[7][0]*Wpk[3][7][0])+(tstarr[7][1]*Wpk[3][7][1])))))
      ;
    temp[1] = ((((fstarr[9][2]*Vpk[3][9][2])+((fstarr[9][0]*Vpk[3][9][0])+(
      fstarr[9][1]*Vpk[3][9][1])))+((tstarr[9][2]*Wpk[3][9][2])+((tstarr[9][0]*
      Wpk[3][9][0])+(tstarr[9][1]*Wpk[3][9][1]))))+((((fstarr[8][2]*Vpk[3][8][2]
      )+((fstarr[8][0]*Vpk[3][8][0])+(fstarr[8][1]*Vpk[3][8][1])))+((
      tstarr[8][2]*Wpk[3][8][2])+((tstarr[8][0]*Wpk[3][8][0])+(tstarr[8][1]*
      Wpk[3][8][1]))))+temp[0]));
    temp[2] = ((((fstarr[11][2]*Vpk[3][11][2])+((fstarr[11][0]*Vpk[3][11][0])+(
      fstarr[11][1]*Vpk[3][11][1])))+((tstarr[11][2]*Wpk[3][11][2])+((
      tstarr[11][0]*Wpk[3][11][0])+(tstarr[11][1]*Wpk[3][11][1]))))+((((
      Cik[10][0][2]*tstarr[10][2])+((Cik[10][0][0]*tstarr[10][0])+(Cik[10][0][1]
      *tstarr[10][1])))+((fstarr[10][2]*Vpk[3][10][2])+((fstarr[10][0]*
      Vpk[3][10][0])+(fstarr[10][1]*Vpk[3][10][1]))))+temp[1]));
    temp[3] = ((((fstarr[13][2]*Vpk[3][13][2])+((fstarr[13][0]*Vpk[3][13][0])+(
      fstarr[13][1]*Vpk[3][13][1])))+((tstarr[13][2]*Wpk[3][13][2])+((
      tstarr[13][0]*Wpk[3][13][0])+(tstarr[13][1]*Wpk[3][13][1]))))+((((
      fstarr[12][2]*Vpk[3][12][2])+((fstarr[12][0]*Vpk[3][12][0])+(fstarr[12][1]
      *Vpk[3][12][1])))+((tstarr[12][2]*Wpk[3][12][2])+((tstarr[12][0]*
      Wpk[3][12][0])+(tstarr[12][1]*Wpk[3][12][1]))))+temp[2]));
    temp[4] = ((((fstarr[15][2]*Vpk[3][15][2])+((fstarr[15][0]*Vpk[3][15][0])+(
      fstarr[15][1]*Vpk[3][15][1])))+((tstarr[15][2]*Wpk[3][15][2])+((
      tstarr[15][0]*Wpk[3][15][0])+(tstarr[15][1]*Wpk[3][15][1]))))+((((
      Cik[14][0][2]*tstarr[14][2])+((Cik[14][0][0]*tstarr[14][0])+(Cik[14][0][1]
      *tstarr[14][1])))+((fstarr[14][2]*Vpk[3][14][2])+((fstarr[14][0]*
      Vpk[3][14][0])+(fstarr[14][1]*Vpk[3][14][1]))))+temp[3]));
    temp[5] = ((((fstarr[17][2]*Vpk[3][17][2])+((fstarr[17][0]*Vpk[3][17][0])+(
      fstarr[17][1]*Vpk[3][17][1])))+((tstarr[17][2]*Wpk[3][17][2])+((
      tstarr[17][0]*Wpk[3][17][0])+(tstarr[17][1]*Wpk[3][17][1]))))+((((
      fstarr[16][2]*Vpk[3][16][2])+((fstarr[16][0]*Vpk[3][16][0])+(fstarr[16][1]
      *Vpk[3][16][1])))+((tstarr[16][2]*Wpk[3][16][2])+((tstarr[16][0]*
      Wpk[3][16][0])+(tstarr[16][1]*Wpk[3][16][1]))))+temp[4]));
    temp[6] = ((((fstarr[19][2]*Vpk[3][19][2])+((fstarr[19][0]*Vpk[3][19][0])+(
      fstarr[19][1]*Vpk[3][19][1])))+((tstarr[19][2]*Wpk[3][19][2])+((
      tstarr[19][0]*Wpk[3][19][0])+(tstarr[19][1]*Wpk[3][19][1]))))+((((
      Cik[18][0][2]*tstarr[18][2])+((Cik[18][0][0]*tstarr[18][0])+(Cik[18][0][1]
      *tstarr[18][1])))+((fstarr[18][2]*Vpk[3][18][2])+((fstarr[18][0]*
      Vpk[3][18][0])+(fstarr[18][1]*Vpk[3][18][1]))))+temp[5]));
    trqout[3] = -((mtau[3]+utau[3])+((((fstarr[21][2]*Vpk[3][21][2])+((
      fstarr[21][0]*Vpk[3][21][0])+(fstarr[21][1]*Vpk[3][21][1])))+((
      tstarr[21][2]*Wpk[3][21][2])+((tstarr[21][0]*Wpk[3][21][0])+(tstarr[21][1]
      *Wpk[3][21][1]))))+((((fstarr[20][2]*Vpk[3][20][2])+((fstarr[20][0]*
      Vpk[3][20][0])+(fstarr[20][1]*Vpk[3][20][1])))+((tstarr[20][2]*
      Wpk[3][20][2])+((tstarr[20][0]*Wpk[3][20][0])+(tstarr[20][1]*Wpk[3][20][1]
      ))))+temp[6])));
    temp[0] = (((tstarr[5][1]+((fstarr[5][2]*rk[0][0])-(fstarr[5][0]*rk[0][2])))
      +(((Cik[6][1][2]*tstarr[6][2])+((Cik[6][1][0]*tstarr[6][0])+(Cik[6][1][1]*
      tstarr[6][1])))+((fstarr[6][2]*Vpk[4][6][2])+((fstarr[6][0]*Vpk[4][6][0])+
      (fstarr[6][1]*Vpk[4][6][1])))))+(((fstarr[7][2]*Vpk[4][7][2])+((
      fstarr[7][0]*Vpk[4][7][0])+(fstarr[7][1]*Vpk[4][7][1])))+((tstarr[7][2]*
      Wpk[4][7][2])+((tstarr[7][0]*Wpk[4][7][0])+(tstarr[7][1]*Wpk[4][7][1])))))
      ;
    temp[1] = ((((fstarr[9][2]*Vpk[4][9][2])+((fstarr[9][0]*Vpk[4][9][0])+(
      fstarr[9][1]*Vpk[4][9][1])))+((tstarr[9][2]*Wpk[4][9][2])+((tstarr[9][0]*
      Wpk[4][9][0])+(tstarr[9][1]*Wpk[4][9][1]))))+((((fstarr[8][2]*Vpk[4][8][2]
      )+((fstarr[8][0]*Vpk[4][8][0])+(fstarr[8][1]*Vpk[4][8][1])))+((
      tstarr[8][2]*Wpk[4][8][2])+((tstarr[8][0]*Wpk[4][8][0])+(tstarr[8][1]*
      Wpk[4][8][1]))))+temp[0]));
    temp[2] = ((((fstarr[11][2]*Vpk[4][11][2])+((fstarr[11][0]*Vpk[4][11][0])+(
      fstarr[11][1]*Vpk[4][11][1])))+((tstarr[11][2]*Wpk[4][11][2])+((
      tstarr[11][0]*Wpk[4][11][0])+(tstarr[11][1]*Wpk[4][11][1]))))+((((
      Cik[10][1][2]*tstarr[10][2])+((Cik[10][1][0]*tstarr[10][0])+(Cik[10][1][1]
      *tstarr[10][1])))+((fstarr[10][2]*Vpk[4][10][2])+((fstarr[10][0]*
      Vpk[4][10][0])+(fstarr[10][1]*Vpk[4][10][1]))))+temp[1]));
    temp[3] = ((((fstarr[13][2]*Vpk[4][13][2])+((fstarr[13][0]*Vpk[4][13][0])+(
      fstarr[13][1]*Vpk[4][13][1])))+((tstarr[13][2]*Wpk[4][13][2])+((
      tstarr[13][0]*Wpk[4][13][0])+(tstarr[13][1]*Wpk[4][13][1]))))+((((
      fstarr[12][2]*Vpk[4][12][2])+((fstarr[12][0]*Vpk[4][12][0])+(fstarr[12][1]
      *Vpk[4][12][1])))+((tstarr[12][2]*Wpk[4][12][2])+((tstarr[12][0]*
      Wpk[4][12][0])+(tstarr[12][1]*Wpk[4][12][1]))))+temp[2]));
    temp[4] = ((((fstarr[15][2]*Vpk[4][15][2])+((fstarr[15][0]*Vpk[4][15][0])+(
      fstarr[15][1]*Vpk[4][15][1])))+((tstarr[15][2]*Wpk[4][15][2])+((
      tstarr[15][0]*Wpk[4][15][0])+(tstarr[15][1]*Wpk[4][15][1]))))+((((
      Cik[14][1][2]*tstarr[14][2])+((Cik[14][1][0]*tstarr[14][0])+(Cik[14][1][1]
      *tstarr[14][1])))+((fstarr[14][2]*Vpk[4][14][2])+((fstarr[14][0]*
      Vpk[4][14][0])+(fstarr[14][1]*Vpk[4][14][1]))))+temp[3]));
    temp[5] = ((((fstarr[17][2]*Vpk[4][17][2])+((fstarr[17][0]*Vpk[4][17][0])+(
      fstarr[17][1]*Vpk[4][17][1])))+((tstarr[17][2]*Wpk[4][17][2])+((
      tstarr[17][0]*Wpk[4][17][0])+(tstarr[17][1]*Wpk[4][17][1]))))+((((
      fstarr[16][2]*Vpk[4][16][2])+((fstarr[16][0]*Vpk[4][16][0])+(fstarr[16][1]
      *Vpk[4][16][1])))+((tstarr[16][2]*Wpk[4][16][2])+((tstarr[16][0]*
      Wpk[4][16][0])+(tstarr[16][1]*Wpk[4][16][1]))))+temp[4]));
    temp[6] = ((((fstarr[19][2]*Vpk[4][19][2])+((fstarr[19][0]*Vpk[4][19][0])+(
      fstarr[19][1]*Vpk[4][19][1])))+((tstarr[19][2]*Wpk[4][19][2])+((
      tstarr[19][0]*Wpk[4][19][0])+(tstarr[19][1]*Wpk[4][19][1]))))+((((
      Cik[18][1][2]*tstarr[18][2])+((Cik[18][1][0]*tstarr[18][0])+(Cik[18][1][1]
      *tstarr[18][1])))+((fstarr[18][2]*Vpk[4][18][2])+((fstarr[18][0]*
      Vpk[4][18][0])+(fstarr[18][1]*Vpk[4][18][1]))))+temp[5]));
    trqout[4] = -((mtau[4]+utau[4])+((((fstarr[21][2]*Vpk[4][21][2])+((
      fstarr[21][0]*Vpk[4][21][0])+(fstarr[21][1]*Vpk[4][21][1])))+((
      tstarr[21][2]*Wpk[4][21][2])+((tstarr[21][0]*Wpk[4][21][0])+(tstarr[21][1]
      *Wpk[4][21][1]))))+((((fstarr[20][2]*Vpk[4][20][2])+((fstarr[20][0]*
      Vpk[4][20][0])+(fstarr[20][1]*Vpk[4][20][1])))+((tstarr[20][2]*
      Wpk[4][20][2])+((tstarr[20][0]*Wpk[4][20][0])+(tstarr[20][1]*Wpk[4][20][1]
      ))))+temp[6])));
    temp[0] = (((tstarr[5][2]+((fstarr[5][0]*rk[0][1])-(fstarr[5][1]*rk[0][0])))
      +(((Cik[6][2][2]*tstarr[6][2])+((Cik[6][2][0]*tstarr[6][0])+(Cik[6][2][1]*
      tstarr[6][1])))+((fstarr[6][2]*Vpk[5][6][2])+((fstarr[6][0]*Vpk[5][6][0])+
      (fstarr[6][1]*Vpk[5][6][1])))))+(((fstarr[7][2]*Vpk[5][7][2])+((
      fstarr[7][0]*Vpk[5][7][0])+(fstarr[7][1]*Vpk[5][7][1])))+((tstarr[7][2]*
      Wpk[5][7][2])+((tstarr[7][0]*Wpk[5][7][0])+(tstarr[7][1]*Wpk[5][7][1])))))
      ;
    temp[1] = ((((fstarr[9][2]*Vpk[5][9][2])+((fstarr[9][0]*Vpk[5][9][0])+(
      fstarr[9][1]*Vpk[5][9][1])))+((tstarr[9][2]*Wpk[5][9][2])+((tstarr[9][0]*
      Wpk[5][9][0])+(tstarr[9][1]*Wpk[5][9][1]))))+((((fstarr[8][2]*Vpk[5][8][2]
      )+((fstarr[8][0]*Vpk[5][8][0])+(fstarr[8][1]*Vpk[5][8][1])))+((
      tstarr[8][2]*Wpk[5][8][2])+((tstarr[8][0]*Wpk[5][8][0])+(tstarr[8][1]*
      Wpk[5][8][1]))))+temp[0]));
    temp[2] = ((((fstarr[11][2]*Vpk[5][11][2])+((fstarr[11][0]*Vpk[5][11][0])+(
      fstarr[11][1]*Vpk[5][11][1])))+((tstarr[11][2]*Wpk[5][11][2])+((
      tstarr[11][0]*Wpk[5][11][0])+(tstarr[11][1]*Wpk[5][11][1]))))+((((
      Cik[10][2][2]*tstarr[10][2])+((Cik[10][2][0]*tstarr[10][0])+(Cik[10][2][1]
      *tstarr[10][1])))+((fstarr[10][2]*Vpk[5][10][2])+((fstarr[10][0]*
      Vpk[5][10][0])+(fstarr[10][1]*Vpk[5][10][1]))))+temp[1]));
    temp[3] = ((((fstarr[13][2]*Vpk[5][13][2])+((fstarr[13][0]*Vpk[5][13][0])+(
      fstarr[13][1]*Vpk[5][13][1])))+((tstarr[13][2]*Wpk[5][13][2])+((
      tstarr[13][0]*Wpk[5][13][0])+(tstarr[13][1]*Wpk[5][13][1]))))+((((
      fstarr[12][2]*Vpk[5][12][2])+((fstarr[12][0]*Vpk[5][12][0])+(fstarr[12][1]
      *Vpk[5][12][1])))+((tstarr[12][2]*Wpk[5][12][2])+((tstarr[12][0]*
      Wpk[5][12][0])+(tstarr[12][1]*Wpk[5][12][1]))))+temp[2]));
    temp[4] = ((((fstarr[15][2]*Vpk[5][15][2])+((fstarr[15][0]*Vpk[5][15][0])+(
      fstarr[15][1]*Vpk[5][15][1])))+((tstarr[15][2]*Wpk[5][15][2])+((
      tstarr[15][0]*Wpk[5][15][0])+(tstarr[15][1]*Wpk[5][15][1]))))+((((
      Cik[14][2][2]*tstarr[14][2])+((Cik[14][2][0]*tstarr[14][0])+(Cik[14][2][1]
      *tstarr[14][1])))+((fstarr[14][2]*Vpk[5][14][2])+((fstarr[14][0]*
      Vpk[5][14][0])+(fstarr[14][1]*Vpk[5][14][1]))))+temp[3]));
    temp[5] = ((((fstarr[17][2]*Vpk[5][17][2])+((fstarr[17][0]*Vpk[5][17][0])+(
      fstarr[17][1]*Vpk[5][17][1])))+((tstarr[17][2]*Wpk[5][17][2])+((
      tstarr[17][0]*Wpk[5][17][0])+(tstarr[17][1]*Wpk[5][17][1]))))+((((
      fstarr[16][2]*Vpk[5][16][2])+((fstarr[16][0]*Vpk[5][16][0])+(fstarr[16][1]
      *Vpk[5][16][1])))+((tstarr[16][2]*Wpk[5][16][2])+((tstarr[16][0]*
      Wpk[5][16][0])+(tstarr[16][1]*Wpk[5][16][1]))))+temp[4]));
    temp[6] = ((((fstarr[19][2]*Vpk[5][19][2])+((fstarr[19][0]*Vpk[5][19][0])+(
      fstarr[19][1]*Vpk[5][19][1])))+((tstarr[19][2]*Wpk[5][19][2])+((
      tstarr[19][0]*Wpk[5][19][0])+(tstarr[19][1]*Wpk[5][19][1]))))+((((
      Cik[18][2][2]*tstarr[18][2])+((Cik[18][2][0]*tstarr[18][0])+(Cik[18][2][1]
      *tstarr[18][1])))+((fstarr[18][2]*Vpk[5][18][2])+((fstarr[18][0]*
      Vpk[5][18][0])+(fstarr[18][1]*Vpk[5][18][1]))))+temp[5]));
    trqout[5] = -((mtau[5]+utau[5])+((((fstarr[21][2]*Vpk[5][21][2])+((
      fstarr[21][0]*Vpk[5][21][0])+(fstarr[21][1]*Vpk[5][21][1])))+((
      tstarr[21][2]*Wpk[5][21][2])+((tstarr[21][0]*Wpk[5][21][0])+(tstarr[21][1]
      *Wpk[5][21][1]))))+((((fstarr[20][2]*Vpk[5][20][2])+((fstarr[20][0]*
      Vpk[5][20][0])+(fstarr[20][1]*Vpk[5][20][1])))+((tstarr[20][2]*
      Wpk[5][20][2])+((tstarr[20][0]*Wpk[5][20][0])+(tstarr[20][1]*Wpk[5][20][1]
      ))))+temp[6])));
    temp[0] = ((((fstarr[6][2]*Vpk[6][6][2])+((fstarr[6][0]*Vpk[6][6][0])+(
      fstarr[6][1]*Vpk[6][6][1])))+((pin[6][2]*tstarr[6][2])+((pin[6][0]*
      tstarr[6][0])+(pin[6][1]*tstarr[6][1]))))+(((fstarr[7][2]*Vpk[6][7][2])+((
      fstarr[7][0]*Vpk[6][7][0])+(fstarr[7][1]*Vpk[6][7][1])))+((tstarr[7][2]*
      Wpk[6][7][2])+((tstarr[7][0]*Wpk[6][7][0])+(tstarr[7][1]*Wpk[6][7][1])))))
      ;
    trqout[6] = -((mtau[6]+utau[6])+((((fstarr[9][2]*Vpk[6][9][2])+((
      fstarr[9][0]*Vpk[6][9][0])+(fstarr[9][1]*Vpk[6][9][1])))+((tstarr[9][2]*
      Wpk[6][9][2])+((tstarr[9][0]*Wpk[6][9][0])+(tstarr[9][1]*Wpk[6][9][1]))))+
      ((((fstarr[8][2]*Vpk[6][8][2])+((fstarr[8][0]*Vpk[6][8][0])+(fstarr[8][1]*
      Vpk[6][8][1])))+((tstarr[8][2]*Wpk[6][8][2])+((tstarr[8][0]*Wpk[6][8][0])+
      (tstarr[8][1]*Wpk[6][8][1]))))+temp[0])));
    temp[0] = ((((fstarr[7][2]*Vpk[7][7][2])+((fstarr[7][0]*Vpk[7][7][0])+(
      fstarr[7][1]*Vpk[7][7][1])))+((pin[7][2]*tstarr[7][2])+((pin[7][0]*
      tstarr[7][0])+(pin[7][1]*tstarr[7][1]))))+(((fstarr[8][2]*Vpk[7][8][2])+((
      fstarr[8][0]*Vpk[7][8][0])+(fstarr[8][1]*Vpk[7][8][1])))+((tstarr[8][2]*
      Wpk[7][8][2])+((tstarr[8][0]*Wpk[7][8][0])+(tstarr[8][1]*Wpk[7][8][1])))))
      ;
    trqout[7] = -((mtau[7]+utau[7])+((((fstarr[9][2]*Vpk[7][9][2])+((
      fstarr[9][0]*Vpk[7][9][0])+(fstarr[9][1]*Vpk[7][9][1])))+((tstarr[9][2]*
      Wpk[7][9][2])+((tstarr[9][0]*Wpk[7][9][0])+(tstarr[9][1]*Wpk[7][9][1]))))+
      temp[0]));
    trqout[8] = -((mtau[8]+utau[8])+((((fstarr[8][2]*Vpk[8][8][2])+((
      fstarr[8][0]*Vpk[8][8][0])+(fstarr[8][1]*Vpk[8][8][1])))+((pin[8][2]*
      tstarr[8][2])+((pin[8][0]*tstarr[8][0])+(pin[8][1]*tstarr[8][1]))))+(((
      fstarr[9][2]*Vpk[8][9][2])+((fstarr[9][0]*Vpk[8][9][0])+(fstarr[9][1]*
      Vpk[8][9][1])))+((tstarr[9][2]*Wpk[8][9][2])+((tstarr[9][0]*Wpk[8][9][0])+
      (tstarr[9][1]*Wpk[8][9][1]))))));
    trqout[9] = -((mtau[9]+utau[9])+(((fstarr[9][2]*Vpk[9][9][2])+((fstarr[9][0]
      *Vpk[9][9][0])+(fstarr[9][1]*Vpk[9][9][1])))+((pin[9][2]*tstarr[9][2])+((
      pin[9][0]*tstarr[9][0])+(pin[9][1]*tstarr[9][1])))));
    temp[0] = ((((fstarr[10][2]*Vpk[10][10][2])+((fstarr[10][0]*Vpk[10][10][0])+
      (fstarr[10][1]*Vpk[10][10][1])))+((pin[10][2]*tstarr[10][2])+((pin[10][0]*
      tstarr[10][0])+(pin[10][1]*tstarr[10][1]))))+(((fstarr[11][2]*
      Vpk[10][11][2])+((fstarr[11][0]*Vpk[10][11][0])+(fstarr[11][1]*
      Vpk[10][11][1])))+((tstarr[11][2]*Wpk[10][11][2])+((tstarr[11][0]*
      Wpk[10][11][0])+(tstarr[11][1]*Wpk[10][11][1])))));
    trqout[10] = -((mtau[10]+utau[10])+((((fstarr[13][2]*Vpk[10][13][2])+((
      fstarr[13][0]*Vpk[10][13][0])+(fstarr[13][1]*Vpk[10][13][1])))+((
      tstarr[13][2]*Wpk[10][13][2])+((tstarr[13][0]*Wpk[10][13][0])+(
      tstarr[13][1]*Wpk[10][13][1]))))+((((fstarr[12][2]*Vpk[10][12][2])+((
      fstarr[12][0]*Vpk[10][12][0])+(fstarr[12][1]*Vpk[10][12][1])))+((
      tstarr[12][2]*Wpk[10][12][2])+((tstarr[12][0]*Wpk[10][12][0])+(
      tstarr[12][1]*Wpk[10][12][1]))))+temp[0])));
    temp[0] = ((((fstarr[11][2]*Vpk[11][11][2])+((fstarr[11][0]*Vpk[11][11][0])+
      (fstarr[11][1]*Vpk[11][11][1])))+((pin[11][2]*tstarr[11][2])+((pin[11][0]*
      tstarr[11][0])+(pin[11][1]*tstarr[11][1]))))+(((fstarr[12][2]*
      Vpk[11][12][2])+((fstarr[12][0]*Vpk[11][12][0])+(fstarr[12][1]*
      Vpk[11][12][1])))+((tstarr[12][2]*Wpk[11][12][2])+((tstarr[12][0]*
      Wpk[11][12][0])+(tstarr[12][1]*Wpk[11][12][1])))));
    trqout[11] = -((mtau[11]+utau[11])+((((fstarr[13][2]*Vpk[11][13][2])+((
      fstarr[13][0]*Vpk[11][13][0])+(fstarr[13][1]*Vpk[11][13][1])))+((
      tstarr[13][2]*Wpk[11][13][2])+((tstarr[13][0]*Wpk[11][13][0])+(
      tstarr[13][1]*Wpk[11][13][1]))))+temp[0]));
    trqout[12] = -((mtau[12]+utau[12])+((((fstarr[12][2]*Vpk[12][12][2])+((
      fstarr[12][0]*Vpk[12][12][0])+(fstarr[12][1]*Vpk[12][12][1])))+((
      pin[12][2]*tstarr[12][2])+((pin[12][0]*tstarr[12][0])+(pin[12][1]*
      tstarr[12][1]))))+(((fstarr[13][2]*Vpk[12][13][2])+((fstarr[13][0]*
      Vpk[12][13][0])+(fstarr[13][1]*Vpk[12][13][1])))+((tstarr[13][2]*
      Wpk[12][13][2])+((tstarr[13][0]*Wpk[12][13][0])+(tstarr[13][1]*
      Wpk[12][13][1]))))));
    trqout[13] = -((mtau[13]+utau[13])+(((fstarr[13][2]*Vpk[13][13][2])+((
      fstarr[13][0]*Vpk[13][13][0])+(fstarr[13][1]*Vpk[13][13][1])))+((
      pin[13][2]*tstarr[13][2])+((pin[13][0]*tstarr[13][0])+(pin[13][1]*
      tstarr[13][1])))));
    temp[0] = ((((fstarr[14][2]*Vpk[14][14][2])+((fstarr[14][0]*Vpk[14][14][0])+
      (fstarr[14][1]*Vpk[14][14][1])))+((pin[14][2]*tstarr[14][2])+((pin[14][0]*
      tstarr[14][0])+(pin[14][1]*tstarr[14][1]))))+(((fstarr[15][2]*
      Vpk[14][15][2])+((fstarr[15][0]*Vpk[14][15][0])+(fstarr[15][1]*
      Vpk[14][15][1])))+((tstarr[15][2]*Wpk[14][15][2])+((tstarr[15][0]*
      Wpk[14][15][0])+(tstarr[15][1]*Wpk[14][15][1])))));
    trqout[14] = -((mtau[14]+utau[14])+((((fstarr[17][2]*Vpk[14][17][2])+((
      fstarr[17][0]*Vpk[14][17][0])+(fstarr[17][1]*Vpk[14][17][1])))+((
      tstarr[17][2]*Wpk[14][17][2])+((tstarr[17][0]*Wpk[14][17][0])+(
      tstarr[17][1]*Wpk[14][17][1]))))+((((fstarr[16][2]*Vpk[14][16][2])+((
      fstarr[16][0]*Vpk[14][16][0])+(fstarr[16][1]*Vpk[14][16][1])))+((
      tstarr[16][2]*Wpk[14][16][2])+((tstarr[16][0]*Wpk[14][16][0])+(
      tstarr[16][1]*Wpk[14][16][1]))))+temp[0])));
    temp[0] = ((((fstarr[15][2]*Vpk[15][15][2])+((fstarr[15][0]*Vpk[15][15][0])+
      (fstarr[15][1]*Vpk[15][15][1])))+((pin[15][2]*tstarr[15][2])+((pin[15][0]*
      tstarr[15][0])+(pin[15][1]*tstarr[15][1]))))+(((fstarr[16][2]*
      Vpk[15][16][2])+((fstarr[16][0]*Vpk[15][16][0])+(fstarr[16][1]*
      Vpk[15][16][1])))+((tstarr[16][2]*Wpk[15][16][2])+((tstarr[16][0]*
      Wpk[15][16][0])+(tstarr[16][1]*Wpk[15][16][1])))));
    trqout[15] = -((mtau[15]+utau[15])+((((fstarr[17][2]*Vpk[15][17][2])+((
      fstarr[17][0]*Vpk[15][17][0])+(fstarr[17][1]*Vpk[15][17][1])))+((
      tstarr[17][2]*Wpk[15][17][2])+((tstarr[17][0]*Wpk[15][17][0])+(
      tstarr[17][1]*Wpk[15][17][1]))))+temp[0]));
    trqout[16] = -((mtau[16]+utau[16])+((((fstarr[16][2]*Vpk[16][16][2])+((
      fstarr[16][0]*Vpk[16][16][0])+(fstarr[16][1]*Vpk[16][16][1])))+((
      pin[16][2]*tstarr[16][2])+((pin[16][0]*tstarr[16][0])+(pin[16][1]*
      tstarr[16][1]))))+(((fstarr[17][2]*Vpk[16][17][2])+((fstarr[17][0]*
      Vpk[16][17][0])+(fstarr[17][1]*Vpk[16][17][1])))+((tstarr[17][2]*
      Wpk[16][17][2])+((tstarr[17][0]*Wpk[16][17][0])+(tstarr[17][1]*
      Wpk[16][17][1]))))));
    trqout[17] = -((mtau[17]+utau[17])+(((fstarr[17][2]*Vpk[17][17][2])+((
      fstarr[17][0]*Vpk[17][17][0])+(fstarr[17][1]*Vpk[17][17][1])))+((
      pin[17][2]*tstarr[17][2])+((pin[17][0]*tstarr[17][0])+(pin[17][1]*
      tstarr[17][1])))));
    temp[0] = ((((fstarr[18][2]*Vpk[18][18][2])+((fstarr[18][0]*Vpk[18][18][0])+
      (fstarr[18][1]*Vpk[18][18][1])))+((pin[18][2]*tstarr[18][2])+((pin[18][0]*
      tstarr[18][0])+(pin[18][1]*tstarr[18][1]))))+(((fstarr[19][2]*
      Vpk[18][19][2])+((fstarr[19][0]*Vpk[18][19][0])+(fstarr[19][1]*
      Vpk[18][19][1])))+((tstarr[19][2]*Wpk[18][19][2])+((tstarr[19][0]*
      Wpk[18][19][0])+(tstarr[19][1]*Wpk[18][19][1])))));
    trqout[18] = -((mtau[18]+utau[18])+((((fstarr[21][2]*Vpk[18][21][2])+((
      fstarr[21][0]*Vpk[18][21][0])+(fstarr[21][1]*Vpk[18][21][1])))+((
      tstarr[21][2]*Wpk[18][21][2])+((tstarr[21][0]*Wpk[18][21][0])+(
      tstarr[21][1]*Wpk[18][21][1]))))+((((fstarr[20][2]*Vpk[18][20][2])+((
      fstarr[20][0]*Vpk[18][20][0])+(fstarr[20][1]*Vpk[18][20][1])))+((
      tstarr[20][2]*Wpk[18][20][2])+((tstarr[20][0]*Wpk[18][20][0])+(
      tstarr[20][1]*Wpk[18][20][1]))))+temp[0])));
    temp[0] = ((((fstarr[19][2]*Vpk[19][19][2])+((fstarr[19][0]*Vpk[19][19][0])+
      (fstarr[19][1]*Vpk[19][19][1])))+((pin[19][2]*tstarr[19][2])+((pin[19][0]*
      tstarr[19][0])+(pin[19][1]*tstarr[19][1]))))+(((fstarr[20][2]*
      Vpk[19][20][2])+((fstarr[20][0]*Vpk[19][20][0])+(fstarr[20][1]*
      Vpk[19][20][1])))+((tstarr[20][2]*Wpk[19][20][2])+((tstarr[20][0]*
      Wpk[19][20][0])+(tstarr[20][1]*Wpk[19][20][1])))));
    trqout[19] = -((mtau[19]+utau[19])+((((fstarr[21][2]*Vpk[19][21][2])+((
      fstarr[21][0]*Vpk[19][21][0])+(fstarr[21][1]*Vpk[19][21][1])))+((
      tstarr[21][2]*Wpk[19][21][2])+((tstarr[21][0]*Wpk[19][21][0])+(
      tstarr[21][1]*Wpk[19][21][1]))))+temp[0]));
    trqout[20] = -((mtau[20]+utau[20])+((((fstarr[20][2]*Vpk[20][20][2])+((
      fstarr[20][0]*Vpk[20][20][0])+(fstarr[20][1]*Vpk[20][20][1])))+((
      pin[20][2]*tstarr[20][2])+((pin[20][0]*tstarr[20][0])+(pin[20][1]*
      tstarr[20][1]))))+(((fstarr[21][2]*Vpk[20][21][2])+((fstarr[21][0]*
      Vpk[20][21][0])+(fstarr[21][1]*Vpk[20][21][1])))+((tstarr[21][2]*
      Wpk[20][21][2])+((tstarr[21][0]*Wpk[20][21][0])+(tstarr[21][1]*
      Wpk[20][21][1]))))));
    trqout[21] = -((mtau[21]+utau[21])+(((fstarr[21][2]*Vpk[21][21][2])+((
      fstarr[21][0]*Vpk[21][21][0])+(fstarr[21][1]*Vpk[21][21][1])))+((
      pin[21][2]*tstarr[21][2])+((pin[21][0]*tstarr[21][0])+(pin[21][1]*
      tstarr[21][1])))));
/*
Op counts below do not include called subroutines
*/
/*
 Used 0.01 seconds CPU time,
 0 additional bytes of memory.
 Equations contain 1856 adds/subtracts/negates
                   1785 multiplies
                      0 divides
                    324 assignments
*/
}

void allegro_air_comptrq(double udotin[22],
    double trqout[22])
{
/* Compute hinge torques to produce these udots, ignoring constraints
*/
    int i;
    double multin[22];

    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(60,23);
        return;
    }
    for (i = 0; i < 22; i++) {
        multin[i] = 0.;
    }
    allegro_air_fulltrq(udotin,multin,trqout);
}

void allegro_air_multtrq(double multin[22],
    double trqout[22])
{
/* Compute hinge trqs which would be produced by these mults.
*/
    int i;

    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(65,23);
        return;
    }
    allegro_air_mfrc(multin);
    allegro_air_fsmult();
    for (i = 0; i < 22; i++) {
        trqout[i] = fs[i];
    }
}

void allegro_air_rhs(void)
{
/*
Generated 15-Apr-2019 14:28:10 by SD/FAST, Kane's formulation
(sdfast B.2.8 #30123) on machine ID unknown
Copyright (c) 1990-1997 Symbolic Dynamics, Inc.
Copyright (c) 1990-1997 Parametric Technology Corp.
RESTRICTED RIGHTS LEGEND: Use, duplication, or disclosure by the U.S.
Government is subject to restrictions as set forth in subparagraph
(c)(1)(ii) of the Rights in Technical Data and Computer Software
clause at DFARS 52.227-7013 and similar clauses in the FAR and NASA
FAR Supplement.  Symbolic Dynamics, Inc., Mountain View, CA 94041
*/

/*
Compute hinge torques for tree hinges
*/
    tauc[0] = (mtau[0]+utau[0]);
    tauc[1] = (mtau[1]+utau[1]);
    tauc[2] = (mtau[2]+utau[2]);
    tauc[3] = (mtau[3]+utau[3]);
    tauc[4] = (mtau[4]+utau[4]);
    tauc[5] = (mtau[5]+utau[5]);
    tauc[6] = (mtau[6]+utau[6]);
    tauc[7] = (mtau[7]+utau[7]);
    tauc[8] = (mtau[8]+utau[8]);
    tauc[9] = (mtau[9]+utau[9]);
    tauc[10] = (mtau[10]+utau[10]);
    tauc[11] = (mtau[11]+utau[11]);
    tauc[12] = (mtau[12]+utau[12]);
    tauc[13] = (mtau[13]+utau[13]);
    tauc[14] = (mtau[14]+utau[14]);
    tauc[15] = (mtau[15]+utau[15]);
    tauc[16] = (mtau[16]+utau[16]);
    tauc[17] = (mtau[17]+utau[17]);
    tauc[18] = (mtau[18]+utau[18]);
    tauc[19] = (mtau[19]+utau[19]);
    tauc[20] = (mtau[20]+utau[20]);
    tauc[21] = (mtau[21]+utau[21]);
    allegro_air_doiner();
/*
Compute onk & onb (angular accels in N)
*/
    Onkb[6][0] = ((pin[6][0]*udot[6])+((Cik[6][2][0]*udot[5])+((Cik[6][0][0]*
      udot[3])+(Cik[6][1][0]*udot[4]))));
    Onkb[6][1] = ((pin[6][1]*udot[6])+((Cik[6][2][1]*udot[5])+((Cik[6][0][1]*
      udot[3])+(Cik[6][1][1]*udot[4]))));
    Onkb[6][2] = ((pin[6][2]*udot[6])+((Cik[6][2][2]*udot[5])+((Cik[6][0][2]*
      udot[3])+(Cik[6][1][2]*udot[4]))));
    Onkb[7][0] = ((pin[7][0]*udot[7])+((Cik[7][2][0]*Onkb[6][2])+((Cik[7][0][0]*
      Onkb[6][0])+(Cik[7][1][0]*Onkb[6][1]))));
    Onkb[7][1] = ((pin[7][1]*udot[7])+((Cik[7][2][1]*Onkb[6][2])+((Cik[7][0][1]*
      Onkb[6][0])+(Cik[7][1][1]*Onkb[6][1]))));
    Onkb[7][2] = ((pin[7][2]*udot[7])+((Cik[7][2][2]*Onkb[6][2])+((Cik[7][0][2]*
      Onkb[6][0])+(Cik[7][1][2]*Onkb[6][1]))));
    Onkb[8][0] = ((pin[8][0]*udot[8])+((Cik[8][2][0]*Onkb[7][2])+((Cik[8][0][0]*
      Onkb[7][0])+(Cik[8][1][0]*Onkb[7][1]))));
    Onkb[8][1] = ((pin[8][1]*udot[8])+((Cik[8][2][1]*Onkb[7][2])+((Cik[8][0][1]*
      Onkb[7][0])+(Cik[8][1][1]*Onkb[7][1]))));
    Onkb[8][2] = ((pin[8][2]*udot[8])+((Cik[8][2][2]*Onkb[7][2])+((Cik[8][0][2]*
      Onkb[7][0])+(Cik[8][1][2]*Onkb[7][1]))));
    Onkb[9][0] = ((pin[9][0]*udot[9])+((Cik[9][2][0]*Onkb[8][2])+((Cik[9][0][0]*
      Onkb[8][0])+(Cik[9][1][0]*Onkb[8][1]))));
    Onkb[9][1] = ((pin[9][1]*udot[9])+((Cik[9][2][1]*Onkb[8][2])+((Cik[9][0][1]*
      Onkb[8][0])+(Cik[9][1][1]*Onkb[8][1]))));
    Onkb[9][2] = ((pin[9][2]*udot[9])+((Cik[9][2][2]*Onkb[8][2])+((Cik[9][0][2]*
      Onkb[8][0])+(Cik[9][1][2]*Onkb[8][1]))));
    Onkb[10][0] = ((pin[10][0]*udot[10])+((Cik[10][2][0]*udot[5])+((
      Cik[10][0][0]*udot[3])+(Cik[10][1][0]*udot[4]))));
    Onkb[10][1] = ((pin[10][1]*udot[10])+((Cik[10][2][1]*udot[5])+((
      Cik[10][0][1]*udot[3])+(Cik[10][1][1]*udot[4]))));
    Onkb[10][2] = ((pin[10][2]*udot[10])+((Cik[10][2][2]*udot[5])+((
      Cik[10][0][2]*udot[3])+(Cik[10][1][2]*udot[4]))));
    Onkb[11][0] = ((pin[11][0]*udot[11])+((Cik[11][2][0]*Onkb[10][2])+((
      Cik[11][0][0]*Onkb[10][0])+(Cik[11][1][0]*Onkb[10][1]))));
    Onkb[11][1] = ((pin[11][1]*udot[11])+((Cik[11][2][1]*Onkb[10][2])+((
      Cik[11][0][1]*Onkb[10][0])+(Cik[11][1][1]*Onkb[10][1]))));
    Onkb[11][2] = ((pin[11][2]*udot[11])+((Cik[11][2][2]*Onkb[10][2])+((
      Cik[11][0][2]*Onkb[10][0])+(Cik[11][1][2]*Onkb[10][1]))));
    Onkb[12][0] = ((pin[12][0]*udot[12])+((Cik[12][2][0]*Onkb[11][2])+((
      Cik[12][0][0]*Onkb[11][0])+(Cik[12][1][0]*Onkb[11][1]))));
    Onkb[12][1] = ((pin[12][1]*udot[12])+((Cik[12][2][1]*Onkb[11][2])+((
      Cik[12][0][1]*Onkb[11][0])+(Cik[12][1][1]*Onkb[11][1]))));
    Onkb[12][2] = ((pin[12][2]*udot[12])+((Cik[12][2][2]*Onkb[11][2])+((
      Cik[12][0][2]*Onkb[11][0])+(Cik[12][1][2]*Onkb[11][1]))));
    Onkb[13][0] = ((pin[13][0]*udot[13])+((Cik[13][2][0]*Onkb[12][2])+((
      Cik[13][0][0]*Onkb[12][0])+(Cik[13][1][0]*Onkb[12][1]))));
    Onkb[13][1] = ((pin[13][1]*udot[13])+((Cik[13][2][1]*Onkb[12][2])+((
      Cik[13][0][1]*Onkb[12][0])+(Cik[13][1][1]*Onkb[12][1]))));
    Onkb[13][2] = ((pin[13][2]*udot[13])+((Cik[13][2][2]*Onkb[12][2])+((
      Cik[13][0][2]*Onkb[12][0])+(Cik[13][1][2]*Onkb[12][1]))));
    Onkb[14][0] = ((pin[14][0]*udot[14])+((Cik[14][2][0]*udot[5])+((
      Cik[14][0][0]*udot[3])+(Cik[14][1][0]*udot[4]))));
    Onkb[14][1] = ((pin[14][1]*udot[14])+((Cik[14][2][1]*udot[5])+((
      Cik[14][0][1]*udot[3])+(Cik[14][1][1]*udot[4]))));
    Onkb[14][2] = ((pin[14][2]*udot[14])+((Cik[14][2][2]*udot[5])+((
      Cik[14][0][2]*udot[3])+(Cik[14][1][2]*udot[4]))));
    Onkb[15][0] = ((pin[15][0]*udot[15])+((Cik[15][2][0]*Onkb[14][2])+((
      Cik[15][0][0]*Onkb[14][0])+(Cik[15][1][0]*Onkb[14][1]))));
    Onkb[15][1] = ((pin[15][1]*udot[15])+((Cik[15][2][1]*Onkb[14][2])+((
      Cik[15][0][1]*Onkb[14][0])+(Cik[15][1][1]*Onkb[14][1]))));
    Onkb[15][2] = ((pin[15][2]*udot[15])+((Cik[15][2][2]*Onkb[14][2])+((
      Cik[15][0][2]*Onkb[14][0])+(Cik[15][1][2]*Onkb[14][1]))));
    Onkb[16][0] = ((pin[16][0]*udot[16])+((Cik[16][2][0]*Onkb[15][2])+((
      Cik[16][0][0]*Onkb[15][0])+(Cik[16][1][0]*Onkb[15][1]))));
    Onkb[16][1] = ((pin[16][1]*udot[16])+((Cik[16][2][1]*Onkb[15][2])+((
      Cik[16][0][1]*Onkb[15][0])+(Cik[16][1][1]*Onkb[15][1]))));
    Onkb[16][2] = ((pin[16][2]*udot[16])+((Cik[16][2][2]*Onkb[15][2])+((
      Cik[16][0][2]*Onkb[15][0])+(Cik[16][1][2]*Onkb[15][1]))));
    Onkb[17][0] = ((pin[17][0]*udot[17])+((Cik[17][2][0]*Onkb[16][2])+((
      Cik[17][0][0]*Onkb[16][0])+(Cik[17][1][0]*Onkb[16][1]))));
    Onkb[17][1] = ((pin[17][1]*udot[17])+((Cik[17][2][1]*Onkb[16][2])+((
      Cik[17][0][1]*Onkb[16][0])+(Cik[17][1][1]*Onkb[16][1]))));
    Onkb[17][2] = ((pin[17][2]*udot[17])+((Cik[17][2][2]*Onkb[16][2])+((
      Cik[17][0][2]*Onkb[16][0])+(Cik[17][1][2]*Onkb[16][1]))));
    Onkb[18][0] = ((pin[18][0]*udot[18])+((Cik[18][2][0]*udot[5])+((
      Cik[18][0][0]*udot[3])+(Cik[18][1][0]*udot[4]))));
    Onkb[18][1] = ((pin[18][1]*udot[18])+((Cik[18][2][1]*udot[5])+((
      Cik[18][0][1]*udot[3])+(Cik[18][1][1]*udot[4]))));
    Onkb[18][2] = ((pin[18][2]*udot[18])+((Cik[18][2][2]*udot[5])+((
      Cik[18][0][2]*udot[3])+(Cik[18][1][2]*udot[4]))));
    Onkb[19][0] = ((pin[19][0]*udot[19])+((Cik[19][2][0]*Onkb[18][2])+((
      Cik[19][0][0]*Onkb[18][0])+(Cik[19][1][0]*Onkb[18][1]))));
    Onkb[19][1] = ((pin[19][1]*udot[19])+((Cik[19][2][1]*Onkb[18][2])+((
      Cik[19][0][1]*Onkb[18][0])+(Cik[19][1][1]*Onkb[18][1]))));
    Onkb[19][2] = ((pin[19][2]*udot[19])+((Cik[19][2][2]*Onkb[18][2])+((
      Cik[19][0][2]*Onkb[18][0])+(Cik[19][1][2]*Onkb[18][1]))));
    Onkb[20][0] = ((pin[20][0]*udot[20])+((Cik[20][2][0]*Onkb[19][2])+((
      Cik[20][0][0]*Onkb[19][0])+(Cik[20][1][0]*Onkb[19][1]))));
    Onkb[20][1] = ((pin[20][1]*udot[20])+((Cik[20][2][1]*Onkb[19][2])+((
      Cik[20][0][1]*Onkb[19][0])+(Cik[20][1][1]*Onkb[19][1]))));
    Onkb[20][2] = ((pin[20][2]*udot[20])+((Cik[20][2][2]*Onkb[19][2])+((
      Cik[20][0][2]*Onkb[19][0])+(Cik[20][1][2]*Onkb[19][1]))));
    Onkb[21][0] = ((pin[21][0]*udot[21])+((Cik[21][2][0]*Onkb[20][2])+((
      Cik[21][0][0]*Onkb[20][0])+(Cik[21][1][0]*Onkb[20][1]))));
    Onkb[21][1] = ((pin[21][1]*udot[21])+((Cik[21][2][1]*Onkb[20][2])+((
      Cik[21][0][1]*Onkb[20][0])+(Cik[21][1][1]*Onkb[20][1]))));
    Onkb[21][2] = ((pin[21][2]*udot[21])+((Cik[21][2][2]*Onkb[20][2])+((
      Cik[21][0][2]*Onkb[20][0])+(Cik[21][1][2]*Onkb[20][1]))));
    onk[6][0] = (Onkb[6][0]+Otk[6][0]);
    onk[6][1] = (Onkb[6][1]+Otk[6][1]);
    onk[6][2] = (Onkb[6][2]+Otk[6][2]);
    onk[7][0] = (Onkb[7][0]+Otk[7][0]);
    onk[7][1] = (Onkb[7][1]+Otk[7][1]);
    onk[7][2] = (Onkb[7][2]+Otk[7][2]);
    onk[8][0] = (Onkb[8][0]+Otk[8][0]);
    onk[8][1] = (Onkb[8][1]+Otk[8][1]);
    onk[8][2] = (Onkb[8][2]+Otk[8][2]);
    onk[9][0] = (Onkb[9][0]+Otk[9][0]);
    onk[9][1] = (Onkb[9][1]+Otk[9][1]);
    onk[9][2] = (Onkb[9][2]+Otk[9][2]);
    onk[10][0] = (Onkb[10][0]+Otk[10][0]);
    onk[10][1] = (Onkb[10][1]+Otk[10][1]);
    onk[10][2] = (Onkb[10][2]+Otk[10][2]);
    onk[11][0] = (Onkb[11][0]+Otk[11][0]);
    onk[11][1] = (Onkb[11][1]+Otk[11][1]);
    onk[11][2] = (Onkb[11][2]+Otk[11][2]);
    onk[12][0] = (Onkb[12][0]+Otk[12][0]);
    onk[12][1] = (Onkb[12][1]+Otk[12][1]);
    onk[12][2] = (Onkb[12][2]+Otk[12][2]);
    onk[13][0] = (Onkb[13][0]+Otk[13][0]);
    onk[13][1] = (Onkb[13][1]+Otk[13][1]);
    onk[13][2] = (Onkb[13][2]+Otk[13][2]);
    onk[14][0] = (Onkb[14][0]+Otk[14][0]);
    onk[14][1] = (Onkb[14][1]+Otk[14][1]);
    onk[14][2] = (Onkb[14][2]+Otk[14][2]);
    onk[15][0] = (Onkb[15][0]+Otk[15][0]);
    onk[15][1] = (Onkb[15][1]+Otk[15][1]);
    onk[15][2] = (Onkb[15][2]+Otk[15][2]);
    onk[16][0] = (Onkb[16][0]+Otk[16][0]);
    onk[16][1] = (Onkb[16][1]+Otk[16][1]);
    onk[16][2] = (Onkb[16][2]+Otk[16][2]);
    onk[17][0] = (Onkb[17][0]+Otk[17][0]);
    onk[17][1] = (Onkb[17][1]+Otk[17][1]);
    onk[17][2] = (Onkb[17][2]+Otk[17][2]);
    onk[18][0] = (Onkb[18][0]+Otk[18][0]);
    onk[18][1] = (Onkb[18][1]+Otk[18][1]);
    onk[18][2] = (Onkb[18][2]+Otk[18][2]);
    onk[19][0] = (Onkb[19][0]+Otk[19][0]);
    onk[19][1] = (Onkb[19][1]+Otk[19][1]);
    onk[19][2] = (Onkb[19][2]+Otk[19][2]);
    onk[20][0] = (Onkb[20][0]+Otk[20][0]);
    onk[20][1] = (Onkb[20][1]+Otk[20][1]);
    onk[20][2] = (Onkb[20][2]+Otk[20][2]);
    onk[21][0] = (Onkb[21][0]+Otk[21][0]);
    onk[21][1] = (Onkb[21][1]+Otk[21][1]);
    onk[21][2] = (Onkb[21][2]+Otk[21][2]);
    onb[0][0] = udot[3];
    onb[0][1] = udot[4];
    onb[0][2] = udot[5];
    onb[1][0] = onk[6][0];
    onb[1][1] = onk[6][1];
    onb[1][2] = onk[6][2];
    onb[2][0] = onk[7][0];
    onb[2][1] = onk[7][1];
    onb[2][2] = onk[7][2];
    onb[3][0] = onk[8][0];
    onb[3][1] = onk[8][1];
    onb[3][2] = onk[8][2];
    onb[4][0] = onk[9][0];
    onb[4][1] = onk[9][1];
    onb[4][2] = onk[9][2];
    onb[5][0] = onk[9][0];
    onb[5][1] = onk[9][1];
    onb[5][2] = onk[9][2];
    onb[6][0] = onk[10][0];
    onb[6][1] = onk[10][1];
    onb[6][2] = onk[10][2];
    onb[7][0] = onk[11][0];
    onb[7][1] = onk[11][1];
    onb[7][2] = onk[11][2];
    onb[8][0] = onk[12][0];
    onb[8][1] = onk[12][1];
    onb[8][2] = onk[12][2];
    onb[9][0] = onk[13][0];
    onb[9][1] = onk[13][1];
    onb[9][2] = onk[13][2];
    onb[10][0] = onk[13][0];
    onb[10][1] = onk[13][1];
    onb[10][2] = onk[13][2];
    onb[11][0] = onk[14][0];
    onb[11][1] = onk[14][1];
    onb[11][2] = onk[14][2];
    onb[12][0] = onk[15][0];
    onb[12][1] = onk[15][1];
    onb[12][2] = onk[15][2];
    onb[13][0] = onk[16][0];
    onb[13][1] = onk[16][1];
    onb[13][2] = onk[16][2];
    onb[14][0] = onk[17][0];
    onb[14][1] = onk[17][1];
    onb[14][2] = onk[17][2];
    onb[15][0] = onk[17][0];
    onb[15][1] = onk[17][1];
    onb[15][2] = onk[17][2];
    onb[16][0] = onk[18][0];
    onb[16][1] = onk[18][1];
    onb[16][2] = onk[18][2];
    onb[17][0] = onk[19][0];
    onb[17][1] = onk[19][1];
    onb[17][2] = onk[19][2];
    onb[18][0] = onk[20][0];
    onb[18][1] = onk[20][1];
    onb[18][2] = onk[20][2];
    onb[19][0] = onk[21][0];
    onb[19][1] = onk[21][1];
    onb[19][2] = onk[21][2];
    onb[20][0] = onk[21][0];
    onb[20][1] = onk[21][1];
    onb[20][2] = onk[21][2];
/*
Compute acceleration dyadics
*/
    dyad[0][0][0] = w11w22[0];
    dyad[0][0][1] = (w0w1[0]-udot[5]);
    dyad[0][0][2] = (udot[4]+w0w2[0]);
    dyad[0][1][0] = (udot[5]+w0w1[0]);
    dyad[0][1][1] = w00w22[0];
    dyad[0][1][2] = (w1w2[0]-udot[3]);
    dyad[0][2][0] = (w0w2[0]-udot[4]);
    dyad[0][2][1] = (udot[3]+w1w2[0]);
    dyad[0][2][2] = w00w11[0];
    dyad[1][0][0] = w11w22[1];
    dyad[1][0][1] = (w0w1[1]-onk[6][2]);
    dyad[1][0][2] = (onk[6][1]+w0w2[1]);
    dyad[1][1][0] = (onk[6][2]+w0w1[1]);
    dyad[1][1][1] = w00w22[1];
    dyad[1][1][2] = (w1w2[1]-onk[6][0]);
    dyad[1][2][0] = (w0w2[1]-onk[6][1]);
    dyad[1][2][1] = (onk[6][0]+w1w2[1]);
    dyad[1][2][2] = w00w11[1];
    dyad[2][0][0] = w11w22[2];
    dyad[2][0][1] = (w0w1[2]-onk[7][2]);
    dyad[2][0][2] = (onk[7][1]+w0w2[2]);
    dyad[2][1][0] = (onk[7][2]+w0w1[2]);
    dyad[2][1][1] = w00w22[2];
    dyad[2][1][2] = (w1w2[2]-onk[7][0]);
    dyad[2][2][0] = (w0w2[2]-onk[7][1]);
    dyad[2][2][1] = (onk[7][0]+w1w2[2]);
    dyad[2][2][2] = w00w11[2];
    dyad[3][0][0] = w11w22[3];
    dyad[3][0][1] = (w0w1[3]-onk[8][2]);
    dyad[3][0][2] = (onk[8][1]+w0w2[3]);
    dyad[3][1][0] = (onk[8][2]+w0w1[3]);
    dyad[3][1][1] = w00w22[3];
    dyad[3][1][2] = (w1w2[3]-onk[8][0]);
    dyad[3][2][0] = (w0w2[3]-onk[8][1]);
    dyad[3][2][1] = (onk[8][0]+w1w2[3]);
    dyad[3][2][2] = w00w11[3];
    dyad[4][0][0] = w11w22[4];
    dyad[4][0][1] = (w0w1[4]-onk[9][2]);
    dyad[4][0][2] = (onk[9][1]+w0w2[4]);
    dyad[4][1][0] = (onk[9][2]+w0w1[4]);
    dyad[4][1][1] = w00w22[4];
    dyad[4][1][2] = (w1w2[4]-onk[9][0]);
    dyad[4][2][0] = (w0w2[4]-onk[9][1]);
    dyad[4][2][1] = (onk[9][0]+w1w2[4]);
    dyad[4][2][2] = w00w11[4];
    dyad[5][0][0] = w11w22[5];
    dyad[5][0][1] = (w0w1[5]-onk[9][2]);
    dyad[5][0][2] = (onk[9][1]+w0w2[5]);
    dyad[5][1][0] = (onk[9][2]+w0w1[5]);
    dyad[5][1][1] = w00w22[5];
    dyad[5][1][2] = (w1w2[5]-onk[9][0]);
    dyad[5][2][0] = (w0w2[5]-onk[9][1]);
    dyad[5][2][1] = (onk[9][0]+w1w2[5]);
    dyad[5][2][2] = w00w11[5];
    dyad[6][0][0] = w11w22[6];
    dyad[6][0][1] = (w0w1[6]-onk[10][2]);
    dyad[6][0][2] = (onk[10][1]+w0w2[6]);
    dyad[6][1][0] = (onk[10][2]+w0w1[6]);
    dyad[6][1][1] = w00w22[6];
    dyad[6][1][2] = (w1w2[6]-onk[10][0]);
    dyad[6][2][0] = (w0w2[6]-onk[10][1]);
    dyad[6][2][1] = (onk[10][0]+w1w2[6]);
    dyad[6][2][2] = w00w11[6];
    dyad[7][0][0] = w11w22[7];
    dyad[7][0][1] = (w0w1[7]-onk[11][2]);
    dyad[7][0][2] = (onk[11][1]+w0w2[7]);
    dyad[7][1][0] = (onk[11][2]+w0w1[7]);
    dyad[7][1][1] = w00w22[7];
    dyad[7][1][2] = (w1w2[7]-onk[11][0]);
    dyad[7][2][0] = (w0w2[7]-onk[11][1]);
    dyad[7][2][1] = (onk[11][0]+w1w2[7]);
    dyad[7][2][2] = w00w11[7];
    dyad[8][0][0] = w11w22[8];
    dyad[8][0][1] = (w0w1[8]-onk[12][2]);
    dyad[8][0][2] = (onk[12][1]+w0w2[8]);
    dyad[8][1][0] = (onk[12][2]+w0w1[8]);
    dyad[8][1][1] = w00w22[8];
    dyad[8][1][2] = (w1w2[8]-onk[12][0]);
    dyad[8][2][0] = (w0w2[8]-onk[12][1]);
    dyad[8][2][1] = (onk[12][0]+w1w2[8]);
    dyad[8][2][2] = w00w11[8];
    dyad[9][0][0] = w11w22[9];
    dyad[9][0][1] = (w0w1[9]-onk[13][2]);
    dyad[9][0][2] = (onk[13][1]+w0w2[9]);
    dyad[9][1][0] = (onk[13][2]+w0w1[9]);
    dyad[9][1][1] = w00w22[9];
    dyad[9][1][2] = (w1w2[9]-onk[13][0]);
    dyad[9][2][0] = (w0w2[9]-onk[13][1]);
    dyad[9][2][1] = (onk[13][0]+w1w2[9]);
    dyad[9][2][2] = w00w11[9];
    dyad[10][0][0] = w11w22[10];
    dyad[10][0][1] = (w0w1[10]-onk[13][2]);
    dyad[10][0][2] = (onk[13][1]+w0w2[10]);
    dyad[10][1][0] = (onk[13][2]+w0w1[10]);
    dyad[10][1][1] = w00w22[10];
    dyad[10][1][2] = (w1w2[10]-onk[13][0]);
    dyad[10][2][0] = (w0w2[10]-onk[13][1]);
    dyad[10][2][1] = (onk[13][0]+w1w2[10]);
    dyad[10][2][2] = w00w11[10];
    dyad[11][0][0] = w11w22[11];
    dyad[11][0][1] = (w0w1[11]-onk[14][2]);
    dyad[11][0][2] = (onk[14][1]+w0w2[11]);
    dyad[11][1][0] = (onk[14][2]+w0w1[11]);
    dyad[11][1][1] = w00w22[11];
    dyad[11][1][2] = (w1w2[11]-onk[14][0]);
    dyad[11][2][0] = (w0w2[11]-onk[14][1]);
    dyad[11][2][1] = (onk[14][0]+w1w2[11]);
    dyad[11][2][2] = w00w11[11];
    dyad[12][0][0] = w11w22[12];
    dyad[12][0][1] = (w0w1[12]-onk[15][2]);
    dyad[12][0][2] = (onk[15][1]+w0w2[12]);
    dyad[12][1][0] = (onk[15][2]+w0w1[12]);
    dyad[12][1][1] = w00w22[12];
    dyad[12][1][2] = (w1w2[12]-onk[15][0]);
    dyad[12][2][0] = (w0w2[12]-onk[15][1]);
    dyad[12][2][1] = (onk[15][0]+w1w2[12]);
    dyad[12][2][2] = w00w11[12];
    dyad[13][0][0] = w11w22[13];
    dyad[13][0][1] = (w0w1[13]-onk[16][2]);
    dyad[13][0][2] = (onk[16][1]+w0w2[13]);
    dyad[13][1][0] = (onk[16][2]+w0w1[13]);
    dyad[13][1][1] = w00w22[13];
    dyad[13][1][2] = (w1w2[13]-onk[16][0]);
    dyad[13][2][0] = (w0w2[13]-onk[16][1]);
    dyad[13][2][1] = (onk[16][0]+w1w2[13]);
    dyad[13][2][2] = w00w11[13];
    dyad[14][0][0] = w11w22[14];
    dyad[14][0][1] = (w0w1[14]-onk[17][2]);
    dyad[14][0][2] = (onk[17][1]+w0w2[14]);
    dyad[14][1][0] = (onk[17][2]+w0w1[14]);
    dyad[14][1][1] = w00w22[14];
    dyad[14][1][2] = (w1w2[14]-onk[17][0]);
    dyad[14][2][0] = (w0w2[14]-onk[17][1]);
    dyad[14][2][1] = (onk[17][0]+w1w2[14]);
    dyad[14][2][2] = w00w11[14];
    dyad[15][0][0] = w11w22[15];
    dyad[15][0][1] = (w0w1[15]-onk[17][2]);
    dyad[15][0][2] = (onk[17][1]+w0w2[15]);
    dyad[15][1][0] = (onk[17][2]+w0w1[15]);
    dyad[15][1][1] = w00w22[15];
    dyad[15][1][2] = (w1w2[15]-onk[17][0]);
    dyad[15][2][0] = (w0w2[15]-onk[17][1]);
    dyad[15][2][1] = (onk[17][0]+w1w2[15]);
    dyad[15][2][2] = w00w11[15];
    dyad[16][0][0] = w11w22[16];
    dyad[16][0][1] = (w0w1[16]-onk[18][2]);
    dyad[16][0][2] = (onk[18][1]+w0w2[16]);
    dyad[16][1][0] = (onk[18][2]+w0w1[16]);
    dyad[16][1][1] = w00w22[16];
    dyad[16][1][2] = (w1w2[16]-onk[18][0]);
    dyad[16][2][0] = (w0w2[16]-onk[18][1]);
    dyad[16][2][1] = (onk[18][0]+w1w2[16]);
    dyad[16][2][2] = w00w11[16];
    dyad[17][0][0] = w11w22[17];
    dyad[17][0][1] = (w0w1[17]-onk[19][2]);
    dyad[17][0][2] = (onk[19][1]+w0w2[17]);
    dyad[17][1][0] = (onk[19][2]+w0w1[17]);
    dyad[17][1][1] = w00w22[17];
    dyad[17][1][2] = (w1w2[17]-onk[19][0]);
    dyad[17][2][0] = (w0w2[17]-onk[19][1]);
    dyad[17][2][1] = (onk[19][0]+w1w2[17]);
    dyad[17][2][2] = w00w11[17];
    dyad[18][0][0] = w11w22[18];
    dyad[18][0][1] = (w0w1[18]-onk[20][2]);
    dyad[18][0][2] = (onk[20][1]+w0w2[18]);
    dyad[18][1][0] = (onk[20][2]+w0w1[18]);
    dyad[18][1][1] = w00w22[18];
    dyad[18][1][2] = (w1w2[18]-onk[20][0]);
    dyad[18][2][0] = (w0w2[18]-onk[20][1]);
    dyad[18][2][1] = (onk[20][0]+w1w2[18]);
    dyad[18][2][2] = w00w11[18];
    dyad[19][0][0] = w11w22[19];
    dyad[19][0][1] = (w0w1[19]-onk[21][2]);
    dyad[19][0][2] = (onk[21][1]+w0w2[19]);
    dyad[19][1][0] = (onk[21][2]+w0w1[19]);
    dyad[19][1][1] = w00w22[19];
    dyad[19][1][2] = (w1w2[19]-onk[21][0]);
    dyad[19][2][0] = (w0w2[19]-onk[21][1]);
    dyad[19][2][1] = (onk[21][0]+w1w2[19]);
    dyad[19][2][2] = w00w11[19];
    dyad[20][0][0] = w11w22[20];
    dyad[20][0][1] = (w0w1[20]-onk[21][2]);
    dyad[20][0][2] = (onk[21][1]+w0w2[20]);
    dyad[20][1][0] = (onk[21][2]+w0w1[20]);
    dyad[20][1][1] = w00w22[20];
    dyad[20][1][2] = (w1w2[20]-onk[21][0]);
    dyad[20][2][0] = (w0w2[20]-onk[21][1]);
    dyad[20][2][1] = (onk[21][0]+w1w2[20]);
    dyad[20][2][2] = w00w11[20];
/*
Compute ank & anb (mass center linear accels in N)
*/
    Ankb[0][0] = (pin[0][0]*udot[0]);
    Ankb[0][1] = (pin[0][1]*udot[0]);
    Ankb[0][2] = (pin[0][2]*udot[0]);
    Ankb[1][0] = (Ankb[0][0]+(pin[1][0]*udot[1]));
    Ankb[1][1] = (Ankb[0][1]+(pin[1][1]*udot[1]));
    Ankb[1][2] = (Ankb[0][2]+(pin[1][2]*udot[1]));
    Ankb[2][0] = (Ankb[1][0]+(pin[2][0]*udot[2]));
    Ankb[2][1] = (Ankb[1][1]+(pin[2][1]*udot[2]));
    Ankb[2][2] = (Ankb[1][2]+(pin[2][2]*udot[2]));
    Ankb[3][0] = ((Ankb[2][2]*Cik[3][2][0])+((Ankb[2][0]*Cik[3][0][0])+(
      Ankb[2][1]*Cik[3][1][0])));
    Ankb[3][1] = ((Ankb[2][2]*Cik[3][2][1])+((Ankb[2][0]*Cik[3][0][1])+(
      Ankb[2][1]*Cik[3][1][1])));
    Ankb[3][2] = ((Ankb[2][2]*Cik[3][2][2])+((Ankb[2][0]*Cik[3][0][2])+(
      Ankb[2][1]*Cik[3][1][2])));
    Ankb[5][0] = (Ankb[3][0]+((rk[0][1]*udot[5])-(rk[0][2]*udot[4])));
    Ankb[5][1] = (Ankb[3][1]+((rk[0][2]*udot[3])-(rk[0][0]*udot[5])));
    Ankb[5][2] = (Ankb[3][2]+((rk[0][0]*udot[4])-(rk[0][1]*udot[3])));
    AOnkri[6][0] = (Ankb[5][0]+((ri[1][2]*udot[4])-(ri[1][1]*udot[5])));
    AOnkri[6][1] = (Ankb[5][1]+((ri[1][0]*udot[5])-(ri[1][2]*udot[3])));
    AOnkri[6][2] = (Ankb[5][2]+((ri[1][1]*udot[3])-(ri[1][0]*udot[4])));
    Ankb[6][0] = (((AOnkri[6][2]*Cik[6][2][0])+((AOnkri[6][0]*Cik[6][0][0])+(
      AOnkri[6][1]*Cik[6][1][0])))+((Onkb[6][2]*rk[1][1])-(Onkb[6][1]*rk[1][2]))
      );
    Ankb[6][1] = (((AOnkri[6][2]*Cik[6][2][1])+((AOnkri[6][0]*Cik[6][0][1])+(
      AOnkri[6][1]*Cik[6][1][1])))+((Onkb[6][0]*rk[1][2])-(Onkb[6][2]*rk[1][0]))
      );
    Ankb[6][2] = (((AOnkri[6][2]*Cik[6][2][2])+((AOnkri[6][0]*Cik[6][0][2])+(
      AOnkri[6][1]*Cik[6][1][2])))+((Onkb[6][1]*rk[1][0])-(Onkb[6][0]*rk[1][1]))
      );
    AOnkri[7][0] = (Ankb[6][0]+((Onkb[6][1]*ri[2][2])-(Onkb[6][2]*ri[2][1])));
    AOnkri[7][1] = (Ankb[6][1]+((Onkb[6][2]*ri[2][0])-(Onkb[6][0]*ri[2][2])));
    AOnkri[7][2] = (Ankb[6][2]+((Onkb[6][0]*ri[2][1])-(Onkb[6][1]*ri[2][0])));
    Ankb[7][0] = (((AOnkri[7][2]*Cik[7][2][0])+((AOnkri[7][0]*Cik[7][0][0])+(
      AOnkri[7][1]*Cik[7][1][0])))+((Onkb[7][2]*rk[2][1])-(Onkb[7][1]*rk[2][2]))
      );
    Ankb[7][1] = (((AOnkri[7][2]*Cik[7][2][1])+((AOnkri[7][0]*Cik[7][0][1])+(
      AOnkri[7][1]*Cik[7][1][1])))+((Onkb[7][0]*rk[2][2])-(Onkb[7][2]*rk[2][0]))
      );
    Ankb[7][2] = (((AOnkri[7][2]*Cik[7][2][2])+((AOnkri[7][0]*Cik[7][0][2])+(
      AOnkri[7][1]*Cik[7][1][2])))+((Onkb[7][1]*rk[2][0])-(Onkb[7][0]*rk[2][1]))
      );
    AOnkri[8][0] = (Ankb[7][0]+((Onkb[7][1]*ri[3][2])-(Onkb[7][2]*ri[3][1])));
    AOnkri[8][1] = (Ankb[7][1]+((Onkb[7][2]*ri[3][0])-(Onkb[7][0]*ri[3][2])));
    AOnkri[8][2] = (Ankb[7][2]+((Onkb[7][0]*ri[3][1])-(Onkb[7][1]*ri[3][0])));
    Ankb[8][0] = (((AOnkri[8][2]*Cik[8][2][0])+((AOnkri[8][0]*Cik[8][0][0])+(
      AOnkri[8][1]*Cik[8][1][0])))+((Onkb[8][2]*rk[3][1])-(Onkb[8][1]*rk[3][2]))
      );
    Ankb[8][1] = (((AOnkri[8][2]*Cik[8][2][1])+((AOnkri[8][0]*Cik[8][0][1])+(
      AOnkri[8][1]*Cik[8][1][1])))+((Onkb[8][0]*rk[3][2])-(Onkb[8][2]*rk[3][0]))
      );
    Ankb[8][2] = (((AOnkri[8][2]*Cik[8][2][2])+((AOnkri[8][0]*Cik[8][0][2])+(
      AOnkri[8][1]*Cik[8][1][2])))+((Onkb[8][1]*rk[3][0])-(Onkb[8][0]*rk[3][1]))
      );
    AOnkri[9][0] = (Ankb[8][0]+((Onkb[8][1]*ri[4][2])-(Onkb[8][2]*ri[4][1])));
    AOnkri[9][1] = (Ankb[8][1]+((Onkb[8][2]*ri[4][0])-(Onkb[8][0]*ri[4][2])));
    AOnkri[9][2] = (Ankb[8][2]+((Onkb[8][0]*ri[4][1])-(Onkb[8][1]*ri[4][0])));
    Ankb[9][0] = (((AOnkri[9][2]*Cik[9][2][0])+((AOnkri[9][0]*Cik[9][0][0])+(
      AOnkri[9][1]*Cik[9][1][0])))+((Onkb[9][2]*psrk[9][1])-(Onkb[9][1]*
      psrk[9][2])));
    Ankb[9][1] = (((AOnkri[9][2]*Cik[9][2][1])+((AOnkri[9][0]*Cik[9][0][1])+(
      AOnkri[9][1]*Cik[9][1][1])))+((Onkb[9][0]*psrk[9][2])-(Onkb[9][2]*
      psrk[9][0])));
    Ankb[9][2] = (((AOnkri[9][2]*Cik[9][2][2])+((AOnkri[9][0]*Cik[9][0][2])+(
      AOnkri[9][1]*Cik[9][1][2])))+((Onkb[9][1]*psrk[9][0])-(Onkb[9][0]*
      psrk[9][1])));
    AOnkri[10][0] = (Ankb[5][0]+((ri[6][2]*udot[4])-(ri[6][1]*udot[5])));
    AOnkri[10][1] = (Ankb[5][1]+((ri[6][0]*udot[5])-(ri[6][2]*udot[3])));
    AOnkri[10][2] = (Ankb[5][2]+((ri[6][1]*udot[3])-(ri[6][0]*udot[4])));
    Ankb[10][0] = (((AOnkri[10][2]*Cik[10][2][0])+((AOnkri[10][0]*Cik[10][0][0])
      +(AOnkri[10][1]*Cik[10][1][0])))+((Onkb[10][2]*rk[6][1])-(Onkb[10][1]*
      rk[6][2])));
    Ankb[10][1] = (((AOnkri[10][2]*Cik[10][2][1])+((AOnkri[10][0]*Cik[10][0][1])
      +(AOnkri[10][1]*Cik[10][1][1])))+((Onkb[10][0]*rk[6][2])-(Onkb[10][2]*
      rk[6][0])));
    Ankb[10][2] = (((AOnkri[10][2]*Cik[10][2][2])+((AOnkri[10][0]*Cik[10][0][2])
      +(AOnkri[10][1]*Cik[10][1][2])))+((Onkb[10][1]*rk[6][0])-(Onkb[10][0]*
      rk[6][1])));
    AOnkri[11][0] = (Ankb[10][0]+((Onkb[10][1]*ri[7][2])-(Onkb[10][2]*ri[7][1]))
      );
    AOnkri[11][1] = (Ankb[10][1]+((Onkb[10][2]*ri[7][0])-(Onkb[10][0]*ri[7][2]))
      );
    AOnkri[11][2] = (Ankb[10][2]+((Onkb[10][0]*ri[7][1])-(Onkb[10][1]*ri[7][0]))
      );
    Ankb[11][0] = (((AOnkri[11][2]*Cik[11][2][0])+((AOnkri[11][0]*Cik[11][0][0])
      +(AOnkri[11][1]*Cik[11][1][0])))+((Onkb[11][2]*rk[7][1])-(Onkb[11][1]*
      rk[7][2])));
    Ankb[11][1] = (((AOnkri[11][2]*Cik[11][2][1])+((AOnkri[11][0]*Cik[11][0][1])
      +(AOnkri[11][1]*Cik[11][1][1])))+((Onkb[11][0]*rk[7][2])-(Onkb[11][2]*
      rk[7][0])));
    Ankb[11][2] = (((AOnkri[11][2]*Cik[11][2][2])+((AOnkri[11][0]*Cik[11][0][2])
      +(AOnkri[11][1]*Cik[11][1][2])))+((Onkb[11][1]*rk[7][0])-(Onkb[11][0]*
      rk[7][1])));
    AOnkri[12][0] = (Ankb[11][0]+((Onkb[11][1]*ri[8][2])-(Onkb[11][2]*ri[8][1]))
      );
    AOnkri[12][1] = (Ankb[11][1]+((Onkb[11][2]*ri[8][0])-(Onkb[11][0]*ri[8][2]))
      );
    AOnkri[12][2] = (Ankb[11][2]+((Onkb[11][0]*ri[8][1])-(Onkb[11][1]*ri[8][0]))
      );
    Ankb[12][0] = (((AOnkri[12][2]*Cik[12][2][0])+((AOnkri[12][0]*Cik[12][0][0])
      +(AOnkri[12][1]*Cik[12][1][0])))+((Onkb[12][2]*rk[8][1])-(Onkb[12][1]*
      rk[8][2])));
    Ankb[12][1] = (((AOnkri[12][2]*Cik[12][2][1])+((AOnkri[12][0]*Cik[12][0][1])
      +(AOnkri[12][1]*Cik[12][1][1])))+((Onkb[12][0]*rk[8][2])-(Onkb[12][2]*
      rk[8][0])));
    Ankb[12][2] = (((AOnkri[12][2]*Cik[12][2][2])+((AOnkri[12][0]*Cik[12][0][2])
      +(AOnkri[12][1]*Cik[12][1][2])))+((Onkb[12][1]*rk[8][0])-(Onkb[12][0]*
      rk[8][1])));
    AOnkri[13][0] = (Ankb[12][0]+((Onkb[12][1]*ri[9][2])-(Onkb[12][2]*ri[9][1]))
      );
    AOnkri[13][1] = (Ankb[12][1]+((Onkb[12][2]*ri[9][0])-(Onkb[12][0]*ri[9][2]))
      );
    AOnkri[13][2] = (Ankb[12][2]+((Onkb[12][0]*ri[9][1])-(Onkb[12][1]*ri[9][0]))
      );
    Ankb[13][0] = (((AOnkri[13][2]*Cik[13][2][0])+((AOnkri[13][0]*Cik[13][0][0])
      +(AOnkri[13][1]*Cik[13][1][0])))+((Onkb[13][2]*psrk[13][1])-(Onkb[13][1]*
      psrk[13][2])));
    Ankb[13][1] = (((AOnkri[13][2]*Cik[13][2][1])+((AOnkri[13][0]*Cik[13][0][1])
      +(AOnkri[13][1]*Cik[13][1][1])))+((Onkb[13][0]*psrk[13][2])-(Onkb[13][2]*
      psrk[13][0])));
    Ankb[13][2] = (((AOnkri[13][2]*Cik[13][2][2])+((AOnkri[13][0]*Cik[13][0][2])
      +(AOnkri[13][1]*Cik[13][1][2])))+((Onkb[13][1]*psrk[13][0])-(Onkb[13][0]*
      psrk[13][1])));
    AOnkri[14][0] = (Ankb[5][0]+((ri[11][2]*udot[4])-(ri[11][1]*udot[5])));
    AOnkri[14][1] = (Ankb[5][1]+((ri[11][0]*udot[5])-(ri[11][2]*udot[3])));
    AOnkri[14][2] = (Ankb[5][2]+((ri[11][1]*udot[3])-(ri[11][0]*udot[4])));
    Ankb[14][0] = (((AOnkri[14][2]*Cik[14][2][0])+((AOnkri[14][0]*Cik[14][0][0])
      +(AOnkri[14][1]*Cik[14][1][0])))+((Onkb[14][2]*rk[11][1])-(Onkb[14][1]*
      rk[11][2])));
    Ankb[14][1] = (((AOnkri[14][2]*Cik[14][2][1])+((AOnkri[14][0]*Cik[14][0][1])
      +(AOnkri[14][1]*Cik[14][1][1])))+((Onkb[14][0]*rk[11][2])-(Onkb[14][2]*
      rk[11][0])));
    Ankb[14][2] = (((AOnkri[14][2]*Cik[14][2][2])+((AOnkri[14][0]*Cik[14][0][2])
      +(AOnkri[14][1]*Cik[14][1][2])))+((Onkb[14][1]*rk[11][0])-(Onkb[14][0]*
      rk[11][1])));
    AOnkri[15][0] = (Ankb[14][0]+((Onkb[14][1]*ri[12][2])-(Onkb[14][2]*ri[12][1]
      )));
    AOnkri[15][1] = (Ankb[14][1]+((Onkb[14][2]*ri[12][0])-(Onkb[14][0]*ri[12][2]
      )));
    AOnkri[15][2] = (Ankb[14][2]+((Onkb[14][0]*ri[12][1])-(Onkb[14][1]*ri[12][0]
      )));
    Ankb[15][0] = (((AOnkri[15][2]*Cik[15][2][0])+((AOnkri[15][0]*Cik[15][0][0])
      +(AOnkri[15][1]*Cik[15][1][0])))+((Onkb[15][2]*rk[12][1])-(Onkb[15][1]*
      rk[12][2])));
    Ankb[15][1] = (((AOnkri[15][2]*Cik[15][2][1])+((AOnkri[15][0]*Cik[15][0][1])
      +(AOnkri[15][1]*Cik[15][1][1])))+((Onkb[15][0]*rk[12][2])-(Onkb[15][2]*
      rk[12][0])));
    Ankb[15][2] = (((AOnkri[15][2]*Cik[15][2][2])+((AOnkri[15][0]*Cik[15][0][2])
      +(AOnkri[15][1]*Cik[15][1][2])))+((Onkb[15][1]*rk[12][0])-(Onkb[15][0]*
      rk[12][1])));
    AOnkri[16][0] = (Ankb[15][0]+((Onkb[15][1]*ri[13][2])-(Onkb[15][2]*ri[13][1]
      )));
    AOnkri[16][1] = (Ankb[15][1]+((Onkb[15][2]*ri[13][0])-(Onkb[15][0]*ri[13][2]
      )));
    AOnkri[16][2] = (Ankb[15][2]+((Onkb[15][0]*ri[13][1])-(Onkb[15][1]*ri[13][0]
      )));
    Ankb[16][0] = (((AOnkri[16][2]*Cik[16][2][0])+((AOnkri[16][0]*Cik[16][0][0])
      +(AOnkri[16][1]*Cik[16][1][0])))+((Onkb[16][2]*rk[13][1])-(Onkb[16][1]*
      rk[13][2])));
    Ankb[16][1] = (((AOnkri[16][2]*Cik[16][2][1])+((AOnkri[16][0]*Cik[16][0][1])
      +(AOnkri[16][1]*Cik[16][1][1])))+((Onkb[16][0]*rk[13][2])-(Onkb[16][2]*
      rk[13][0])));
    Ankb[16][2] = (((AOnkri[16][2]*Cik[16][2][2])+((AOnkri[16][0]*Cik[16][0][2])
      +(AOnkri[16][1]*Cik[16][1][2])))+((Onkb[16][1]*rk[13][0])-(Onkb[16][0]*
      rk[13][1])));
    AOnkri[17][0] = (Ankb[16][0]+((Onkb[16][1]*ri[14][2])-(Onkb[16][2]*ri[14][1]
      )));
    AOnkri[17][1] = (Ankb[16][1]+((Onkb[16][2]*ri[14][0])-(Onkb[16][0]*ri[14][2]
      )));
    AOnkri[17][2] = (Ankb[16][2]+((Onkb[16][0]*ri[14][1])-(Onkb[16][1]*ri[14][0]
      )));
    Ankb[17][0] = (((AOnkri[17][2]*Cik[17][2][0])+((AOnkri[17][0]*Cik[17][0][0])
      +(AOnkri[17][1]*Cik[17][1][0])))+((Onkb[17][2]*psrk[17][1])-(Onkb[17][1]*
      psrk[17][2])));
    Ankb[17][1] = (((AOnkri[17][2]*Cik[17][2][1])+((AOnkri[17][0]*Cik[17][0][1])
      +(AOnkri[17][1]*Cik[17][1][1])))+((Onkb[17][0]*psrk[17][2])-(Onkb[17][2]*
      psrk[17][0])));
    Ankb[17][2] = (((AOnkri[17][2]*Cik[17][2][2])+((AOnkri[17][0]*Cik[17][0][2])
      +(AOnkri[17][1]*Cik[17][1][2])))+((Onkb[17][1]*psrk[17][0])-(Onkb[17][0]*
      psrk[17][1])));
    AOnkri[18][0] = (Ankb[5][0]+((ri[16][2]*udot[4])-(ri[16][1]*udot[5])));
    AOnkri[18][1] = (Ankb[5][1]+((ri[16][0]*udot[5])-(ri[16][2]*udot[3])));
    AOnkri[18][2] = (Ankb[5][2]+((ri[16][1]*udot[3])-(ri[16][0]*udot[4])));
    Ankb[18][0] = (((AOnkri[18][2]*Cik[18][2][0])+((AOnkri[18][0]*Cik[18][0][0])
      +(AOnkri[18][1]*Cik[18][1][0])))+((Onkb[18][2]*rk[16][1])-(Onkb[18][1]*
      rk[16][2])));
    Ankb[18][1] = (((AOnkri[18][2]*Cik[18][2][1])+((AOnkri[18][0]*Cik[18][0][1])
      +(AOnkri[18][1]*Cik[18][1][1])))+((Onkb[18][0]*rk[16][2])-(Onkb[18][2]*
      rk[16][0])));
    Ankb[18][2] = (((AOnkri[18][2]*Cik[18][2][2])+((AOnkri[18][0]*Cik[18][0][2])
      +(AOnkri[18][1]*Cik[18][1][2])))+((Onkb[18][1]*rk[16][0])-(Onkb[18][0]*
      rk[16][1])));
    AOnkri[19][0] = (Ankb[18][0]+((Onkb[18][1]*ri[17][2])-(Onkb[18][2]*ri[17][1]
      )));
    AOnkri[19][1] = (Ankb[18][1]+((Onkb[18][2]*ri[17][0])-(Onkb[18][0]*ri[17][2]
      )));
    AOnkri[19][2] = (Ankb[18][2]+((Onkb[18][0]*ri[17][1])-(Onkb[18][1]*ri[17][0]
      )));
    Ankb[19][0] = (((AOnkri[19][2]*Cik[19][2][0])+((AOnkri[19][0]*Cik[19][0][0])
      +(AOnkri[19][1]*Cik[19][1][0])))+((Onkb[19][2]*rk[17][1])-(Onkb[19][1]*
      rk[17][2])));
    Ankb[19][1] = (((AOnkri[19][2]*Cik[19][2][1])+((AOnkri[19][0]*Cik[19][0][1])
      +(AOnkri[19][1]*Cik[19][1][1])))+((Onkb[19][0]*rk[17][2])-(Onkb[19][2]*
      rk[17][0])));
    Ankb[19][2] = (((AOnkri[19][2]*Cik[19][2][2])+((AOnkri[19][0]*Cik[19][0][2])
      +(AOnkri[19][1]*Cik[19][1][2])))+((Onkb[19][1]*rk[17][0])-(Onkb[19][0]*
      rk[17][1])));
    AOnkri[20][0] = (Ankb[19][0]+((Onkb[19][1]*ri[18][2])-(Onkb[19][2]*ri[18][1]
      )));
    AOnkri[20][1] = (Ankb[19][1]+((Onkb[19][2]*ri[18][0])-(Onkb[19][0]*ri[18][2]
      )));
    AOnkri[20][2] = (Ankb[19][2]+((Onkb[19][0]*ri[18][1])-(Onkb[19][1]*ri[18][0]
      )));
    Ankb[20][0] = (((AOnkri[20][2]*Cik[20][2][0])+((AOnkri[20][0]*Cik[20][0][0])
      +(AOnkri[20][1]*Cik[20][1][0])))+((Onkb[20][2]*rk[18][1])-(Onkb[20][1]*
      rk[18][2])));
    Ankb[20][1] = (((AOnkri[20][2]*Cik[20][2][1])+((AOnkri[20][0]*Cik[20][0][1])
      +(AOnkri[20][1]*Cik[20][1][1])))+((Onkb[20][0]*rk[18][2])-(Onkb[20][2]*
      rk[18][0])));
    Ankb[20][2] = (((AOnkri[20][2]*Cik[20][2][2])+((AOnkri[20][0]*Cik[20][0][2])
      +(AOnkri[20][1]*Cik[20][1][2])))+((Onkb[20][1]*rk[18][0])-(Onkb[20][0]*
      rk[18][1])));
    AOnkri[21][0] = (Ankb[20][0]+((Onkb[20][1]*ri[19][2])-(Onkb[20][2]*ri[19][1]
      )));
    AOnkri[21][1] = (Ankb[20][1]+((Onkb[20][2]*ri[19][0])-(Onkb[20][0]*ri[19][2]
      )));
    AOnkri[21][2] = (Ankb[20][2]+((Onkb[20][0]*ri[19][1])-(Onkb[20][1]*ri[19][0]
      )));
    Ankb[21][0] = (((AOnkri[21][2]*Cik[21][2][0])+((AOnkri[21][0]*Cik[21][0][0])
      +(AOnkri[21][1]*Cik[21][1][0])))+((Onkb[21][2]*psrk[21][1])-(Onkb[21][1]*
      psrk[21][2])));
    Ankb[21][1] = (((AOnkri[21][2]*Cik[21][2][1])+((AOnkri[21][0]*Cik[21][0][1])
      +(AOnkri[21][1]*Cik[21][1][1])))+((Onkb[21][0]*psrk[21][2])-(Onkb[21][2]*
      psrk[21][0])));
    Ankb[21][2] = (((AOnkri[21][2]*Cik[21][2][2])+((AOnkri[21][0]*Cik[21][0][2])
      +(AOnkri[21][1]*Cik[21][1][2])))+((Onkb[21][1]*psrk[21][0])-(Onkb[21][0]*
      psrk[21][1])));
    AnkAtk[5][0] = (Ankb[5][0]+Atk[5][0]);
    AnkAtk[5][1] = (Ankb[5][1]+Atk[5][1]);
    AnkAtk[5][2] = (Ankb[5][2]+Atk[5][2]);
    ank[5][0] = ((AnkAtk[5][2]*Cik[3][0][2])+((AnkAtk[5][0]*Cik[3][0][0])+(
      AnkAtk[5][1]*Cik[3][0][1])));
    ank[5][1] = ((AnkAtk[5][2]*Cik[3][1][2])+((AnkAtk[5][0]*Cik[3][1][0])+(
      AnkAtk[5][1]*Cik[3][1][1])));
    ank[5][2] = ((AnkAtk[5][2]*Cik[3][2][2])+((AnkAtk[5][0]*Cik[3][2][0])+(
      AnkAtk[5][1]*Cik[3][2][1])));
    AnkAtk[6][0] = (Ankb[6][0]+Atk[6][0]);
    AnkAtk[6][1] = (Ankb[6][1]+Atk[6][1]);
    AnkAtk[6][2] = (Ankb[6][2]+Atk[6][2]);
    ank[6][0] = ((AnkAtk[6][2]*cnk[6][0][2])+((AnkAtk[6][0]*cnk[6][0][0])+(
      AnkAtk[6][1]*cnk[6][0][1])));
    ank[6][1] = ((AnkAtk[6][2]*cnk[6][1][2])+((AnkAtk[6][0]*cnk[6][1][0])+(
      AnkAtk[6][1]*cnk[6][1][1])));
    ank[6][2] = ((AnkAtk[6][2]*cnk[6][2][2])+((AnkAtk[6][0]*cnk[6][2][0])+(
      AnkAtk[6][1]*cnk[6][2][1])));
    AnkAtk[7][0] = (Ankb[7][0]+Atk[7][0]);
    AnkAtk[7][1] = (Ankb[7][1]+Atk[7][1]);
    AnkAtk[7][2] = (Ankb[7][2]+Atk[7][2]);
    ank[7][0] = ((AnkAtk[7][2]*cnk[7][0][2])+((AnkAtk[7][0]*cnk[7][0][0])+(
      AnkAtk[7][1]*cnk[7][0][1])));
    ank[7][1] = ((AnkAtk[7][2]*cnk[7][1][2])+((AnkAtk[7][0]*cnk[7][1][0])+(
      AnkAtk[7][1]*cnk[7][1][1])));
    ank[7][2] = ((AnkAtk[7][2]*cnk[7][2][2])+((AnkAtk[7][0]*cnk[7][2][0])+(
      AnkAtk[7][1]*cnk[7][2][1])));
    AnkAtk[8][0] = (Ankb[8][0]+Atk[8][0]);
    AnkAtk[8][1] = (Ankb[8][1]+Atk[8][1]);
    AnkAtk[8][2] = (Ankb[8][2]+Atk[8][2]);
    ank[8][0] = ((AnkAtk[8][2]*cnk[8][0][2])+((AnkAtk[8][0]*cnk[8][0][0])+(
      AnkAtk[8][1]*cnk[8][0][1])));
    ank[8][1] = ((AnkAtk[8][2]*cnk[8][1][2])+((AnkAtk[8][0]*cnk[8][1][0])+(
      AnkAtk[8][1]*cnk[8][1][1])));
    ank[8][2] = ((AnkAtk[8][2]*cnk[8][2][2])+((AnkAtk[8][0]*cnk[8][2][0])+(
      AnkAtk[8][1]*cnk[8][2][1])));
    AnkAtk[9][0] = (Ankb[9][0]+Atk[9][0]);
    AnkAtk[9][1] = (Ankb[9][1]+Atk[9][1]);
    AnkAtk[9][2] = (Ankb[9][2]+Atk[9][2]);
    ank[9][0] = ((AnkAtk[9][2]*cnk[9][0][2])+((AnkAtk[9][0]*cnk[9][0][0])+(
      AnkAtk[9][1]*cnk[9][0][1])));
    ank[9][1] = ((AnkAtk[9][2]*cnk[9][1][2])+((AnkAtk[9][0]*cnk[9][1][0])+(
      AnkAtk[9][1]*cnk[9][1][1])));
    ank[9][2] = ((AnkAtk[9][2]*cnk[9][2][2])+((AnkAtk[9][0]*cnk[9][2][0])+(
      AnkAtk[9][1]*cnk[9][2][1])));
    AnkAtk[10][0] = (Ankb[10][0]+Atk[10][0]);
    AnkAtk[10][1] = (Ankb[10][1]+Atk[10][1]);
    AnkAtk[10][2] = (Ankb[10][2]+Atk[10][2]);
    ank[10][0] = ((AnkAtk[10][2]*cnk[10][0][2])+((AnkAtk[10][0]*cnk[10][0][0])+(
      AnkAtk[10][1]*cnk[10][0][1])));
    ank[10][1] = ((AnkAtk[10][2]*cnk[10][1][2])+((AnkAtk[10][0]*cnk[10][1][0])+(
      AnkAtk[10][1]*cnk[10][1][1])));
    ank[10][2] = ((AnkAtk[10][2]*cnk[10][2][2])+((AnkAtk[10][0]*cnk[10][2][0])+(
      AnkAtk[10][1]*cnk[10][2][1])));
    AnkAtk[11][0] = (Ankb[11][0]+Atk[11][0]);
    AnkAtk[11][1] = (Ankb[11][1]+Atk[11][1]);
    AnkAtk[11][2] = (Ankb[11][2]+Atk[11][2]);
    ank[11][0] = ((AnkAtk[11][2]*cnk[11][0][2])+((AnkAtk[11][0]*cnk[11][0][0])+(
      AnkAtk[11][1]*cnk[11][0][1])));
    ank[11][1] = ((AnkAtk[11][2]*cnk[11][1][2])+((AnkAtk[11][0]*cnk[11][1][0])+(
      AnkAtk[11][1]*cnk[11][1][1])));
    ank[11][2] = ((AnkAtk[11][2]*cnk[11][2][2])+((AnkAtk[11][0]*cnk[11][2][0])+(
      AnkAtk[11][1]*cnk[11][2][1])));
    AnkAtk[12][0] = (Ankb[12][0]+Atk[12][0]);
    AnkAtk[12][1] = (Ankb[12][1]+Atk[12][1]);
    AnkAtk[12][2] = (Ankb[12][2]+Atk[12][2]);
    ank[12][0] = ((AnkAtk[12][2]*cnk[12][0][2])+((AnkAtk[12][0]*cnk[12][0][0])+(
      AnkAtk[12][1]*cnk[12][0][1])));
    ank[12][1] = ((AnkAtk[12][2]*cnk[12][1][2])+((AnkAtk[12][0]*cnk[12][1][0])+(
      AnkAtk[12][1]*cnk[12][1][1])));
    ank[12][2] = ((AnkAtk[12][2]*cnk[12][2][2])+((AnkAtk[12][0]*cnk[12][2][0])+(
      AnkAtk[12][1]*cnk[12][2][1])));
    AnkAtk[13][0] = (Ankb[13][0]+Atk[13][0]);
    AnkAtk[13][1] = (Ankb[13][1]+Atk[13][1]);
    AnkAtk[13][2] = (Ankb[13][2]+Atk[13][2]);
    ank[13][0] = ((AnkAtk[13][2]*cnk[13][0][2])+((AnkAtk[13][0]*cnk[13][0][0])+(
      AnkAtk[13][1]*cnk[13][0][1])));
    ank[13][1] = ((AnkAtk[13][2]*cnk[13][1][2])+((AnkAtk[13][0]*cnk[13][1][0])+(
      AnkAtk[13][1]*cnk[13][1][1])));
    ank[13][2] = ((AnkAtk[13][2]*cnk[13][2][2])+((AnkAtk[13][0]*cnk[13][2][0])+(
      AnkAtk[13][1]*cnk[13][2][1])));
    AnkAtk[14][0] = (Ankb[14][0]+Atk[14][0]);
    AnkAtk[14][1] = (Ankb[14][1]+Atk[14][1]);
    AnkAtk[14][2] = (Ankb[14][2]+Atk[14][2]);
    ank[14][0] = ((AnkAtk[14][2]*cnk[14][0][2])+((AnkAtk[14][0]*cnk[14][0][0])+(
      AnkAtk[14][1]*cnk[14][0][1])));
    ank[14][1] = ((AnkAtk[14][2]*cnk[14][1][2])+((AnkAtk[14][0]*cnk[14][1][0])+(
      AnkAtk[14][1]*cnk[14][1][1])));
    ank[14][2] = ((AnkAtk[14][2]*cnk[14][2][2])+((AnkAtk[14][0]*cnk[14][2][0])+(
      AnkAtk[14][1]*cnk[14][2][1])));
    AnkAtk[15][0] = (Ankb[15][0]+Atk[15][0]);
    AnkAtk[15][1] = (Ankb[15][1]+Atk[15][1]);
    AnkAtk[15][2] = (Ankb[15][2]+Atk[15][2]);
    ank[15][0] = ((AnkAtk[15][2]*cnk[15][0][2])+((AnkAtk[15][0]*cnk[15][0][0])+(
      AnkAtk[15][1]*cnk[15][0][1])));
    ank[15][1] = ((AnkAtk[15][2]*cnk[15][1][2])+((AnkAtk[15][0]*cnk[15][1][0])+(
      AnkAtk[15][1]*cnk[15][1][1])));
    ank[15][2] = ((AnkAtk[15][2]*cnk[15][2][2])+((AnkAtk[15][0]*cnk[15][2][0])+(
      AnkAtk[15][1]*cnk[15][2][1])));
    AnkAtk[16][0] = (Ankb[16][0]+Atk[16][0]);
    AnkAtk[16][1] = (Ankb[16][1]+Atk[16][1]);
    AnkAtk[16][2] = (Ankb[16][2]+Atk[16][2]);
    ank[16][0] = ((AnkAtk[16][2]*cnk[16][0][2])+((AnkAtk[16][0]*cnk[16][0][0])+(
      AnkAtk[16][1]*cnk[16][0][1])));
    ank[16][1] = ((AnkAtk[16][2]*cnk[16][1][2])+((AnkAtk[16][0]*cnk[16][1][0])+(
      AnkAtk[16][1]*cnk[16][1][1])));
    ank[16][2] = ((AnkAtk[16][2]*cnk[16][2][2])+((AnkAtk[16][0]*cnk[16][2][0])+(
      AnkAtk[16][1]*cnk[16][2][1])));
    AnkAtk[17][0] = (Ankb[17][0]+Atk[17][0]);
    AnkAtk[17][1] = (Ankb[17][1]+Atk[17][1]);
    AnkAtk[17][2] = (Ankb[17][2]+Atk[17][2]);
    ank[17][0] = ((AnkAtk[17][2]*cnk[17][0][2])+((AnkAtk[17][0]*cnk[17][0][0])+(
      AnkAtk[17][1]*cnk[17][0][1])));
    ank[17][1] = ((AnkAtk[17][2]*cnk[17][1][2])+((AnkAtk[17][0]*cnk[17][1][0])+(
      AnkAtk[17][1]*cnk[17][1][1])));
    ank[17][2] = ((AnkAtk[17][2]*cnk[17][2][2])+((AnkAtk[17][0]*cnk[17][2][0])+(
      AnkAtk[17][1]*cnk[17][2][1])));
    AnkAtk[18][0] = (Ankb[18][0]+Atk[18][0]);
    AnkAtk[18][1] = (Ankb[18][1]+Atk[18][1]);
    AnkAtk[18][2] = (Ankb[18][2]+Atk[18][2]);
    ank[18][0] = ((AnkAtk[18][2]*cnk[18][0][2])+((AnkAtk[18][0]*cnk[18][0][0])+(
      AnkAtk[18][1]*cnk[18][0][1])));
    ank[18][1] = ((AnkAtk[18][2]*cnk[18][1][2])+((AnkAtk[18][0]*cnk[18][1][0])+(
      AnkAtk[18][1]*cnk[18][1][1])));
    ank[18][2] = ((AnkAtk[18][2]*cnk[18][2][2])+((AnkAtk[18][0]*cnk[18][2][0])+(
      AnkAtk[18][1]*cnk[18][2][1])));
    AnkAtk[19][0] = (Ankb[19][0]+Atk[19][0]);
    AnkAtk[19][1] = (Ankb[19][1]+Atk[19][1]);
    AnkAtk[19][2] = (Ankb[19][2]+Atk[19][2]);
    ank[19][0] = ((AnkAtk[19][2]*cnk[19][0][2])+((AnkAtk[19][0]*cnk[19][0][0])+(
      AnkAtk[19][1]*cnk[19][0][1])));
    ank[19][1] = ((AnkAtk[19][2]*cnk[19][1][2])+((AnkAtk[19][0]*cnk[19][1][0])+(
      AnkAtk[19][1]*cnk[19][1][1])));
    ank[19][2] = ((AnkAtk[19][2]*cnk[19][2][2])+((AnkAtk[19][0]*cnk[19][2][0])+(
      AnkAtk[19][1]*cnk[19][2][1])));
    AnkAtk[20][0] = (Ankb[20][0]+Atk[20][0]);
    AnkAtk[20][1] = (Ankb[20][1]+Atk[20][1]);
    AnkAtk[20][2] = (Ankb[20][2]+Atk[20][2]);
    ank[20][0] = ((AnkAtk[20][2]*cnk[20][0][2])+((AnkAtk[20][0]*cnk[20][0][0])+(
      AnkAtk[20][1]*cnk[20][0][1])));
    ank[20][1] = ((AnkAtk[20][2]*cnk[20][1][2])+((AnkAtk[20][0]*cnk[20][1][0])+(
      AnkAtk[20][1]*cnk[20][1][1])));
    ank[20][2] = ((AnkAtk[20][2]*cnk[20][2][2])+((AnkAtk[20][0]*cnk[20][2][0])+(
      AnkAtk[20][1]*cnk[20][2][1])));
    AnkAtk[21][0] = (Ankb[21][0]+Atk[21][0]);
    AnkAtk[21][1] = (Ankb[21][1]+Atk[21][1]);
    AnkAtk[21][2] = (Ankb[21][2]+Atk[21][2]);
    ank[21][0] = ((AnkAtk[21][2]*cnk[21][0][2])+((AnkAtk[21][0]*cnk[21][0][0])+(
      AnkAtk[21][1]*cnk[21][0][1])));
    ank[21][1] = ((AnkAtk[21][2]*cnk[21][1][2])+((AnkAtk[21][0]*cnk[21][1][0])+(
      AnkAtk[21][1]*cnk[21][1][1])));
    ank[21][2] = ((AnkAtk[21][2]*cnk[21][2][2])+((AnkAtk[21][0]*cnk[21][2][0])+(
      AnkAtk[21][1]*cnk[21][2][1])));
    anb[0][0] = ank[5][0];
    anb[0][1] = ank[5][1];
    anb[0][2] = ank[5][2];
    anb[1][0] = ank[6][0];
    anb[1][1] = ank[6][1];
    anb[1][2] = ank[6][2];
    anb[2][0] = ank[7][0];
    anb[2][1] = ank[7][1];
    anb[2][2] = ank[7][2];
    anb[3][0] = ank[8][0];
    anb[3][1] = ank[8][1];
    anb[3][2] = ank[8][2];
    dyrcom[4][0] = ((dyad[4][0][2]*rcom[4][2])+((dyad[4][0][1]*rcom[4][1])+(
      rcom[4][0]*w11w22[4])));
    dyrcom[4][1] = ((dyad[4][1][2]*rcom[4][2])+((dyad[4][1][0]*rcom[4][0])+(
      rcom[4][1]*w00w22[4])));
    dyrcom[4][2] = ((rcom[4][2]*w00w11[4])+((dyad[4][2][0]*rcom[4][0])+(
      dyad[4][2][1]*rcom[4][1])));
    anb[4][0] = (ank[9][0]+((cnk[9][0][2]*dyrcom[4][2])+((cnk[9][0][0]*
      dyrcom[4][0])+(cnk[9][0][1]*dyrcom[4][1]))));
    anb[4][1] = (ank[9][1]+((cnk[9][1][2]*dyrcom[4][2])+((cnk[9][1][0]*
      dyrcom[4][0])+(cnk[9][1][1]*dyrcom[4][1]))));
    anb[4][2] = (ank[9][2]+((cnk[9][2][2]*dyrcom[4][2])+((cnk[9][2][0]*
      dyrcom[4][0])+(cnk[9][2][1]*dyrcom[4][1]))));
    dyrcom[5][0] = ((dyad[5][0][2]*rcom[5][2])+((dyad[5][0][1]*rcom[5][1])+(
      rcom[5][0]*w11w22[5])));
    dyrcom[5][1] = ((dyad[5][1][2]*rcom[5][2])+((dyad[5][1][0]*rcom[5][0])+(
      rcom[5][1]*w00w22[5])));
    dyrcom[5][2] = ((rcom[5][2]*w00w11[5])+((dyad[5][2][0]*rcom[5][0])+(
      dyad[5][2][1]*rcom[5][1])));
    anb[5][0] = (ank[9][0]+((cnk[9][0][2]*dyrcom[5][2])+((cnk[9][0][0]*
      dyrcom[5][0])+(cnk[9][0][1]*dyrcom[5][1]))));
    anb[5][1] = (ank[9][1]+((cnk[9][1][2]*dyrcom[5][2])+((cnk[9][1][0]*
      dyrcom[5][0])+(cnk[9][1][1]*dyrcom[5][1]))));
    anb[5][2] = (ank[9][2]+((cnk[9][2][2]*dyrcom[5][2])+((cnk[9][2][0]*
      dyrcom[5][0])+(cnk[9][2][1]*dyrcom[5][1]))));
    anb[6][0] = ank[10][0];
    anb[6][1] = ank[10][1];
    anb[6][2] = ank[10][2];
    anb[7][0] = ank[11][0];
    anb[7][1] = ank[11][1];
    anb[7][2] = ank[11][2];
    anb[8][0] = ank[12][0];
    anb[8][1] = ank[12][1];
    anb[8][2] = ank[12][2];
    dyrcom[9][0] = ((dyad[9][0][2]*rcom[9][2])+((dyad[9][0][1]*rcom[9][1])+(
      rcom[9][0]*w11w22[9])));
    dyrcom[9][1] = ((dyad[9][1][2]*rcom[9][2])+((dyad[9][1][0]*rcom[9][0])+(
      rcom[9][1]*w00w22[9])));
    dyrcom[9][2] = ((rcom[9][2]*w00w11[9])+((dyad[9][2][0]*rcom[9][0])+(
      dyad[9][2][1]*rcom[9][1])));
    anb[9][0] = (ank[13][0]+((cnk[13][0][2]*dyrcom[9][2])+((cnk[13][0][0]*
      dyrcom[9][0])+(cnk[13][0][1]*dyrcom[9][1]))));
    anb[9][1] = (ank[13][1]+((cnk[13][1][2]*dyrcom[9][2])+((cnk[13][1][0]*
      dyrcom[9][0])+(cnk[13][1][1]*dyrcom[9][1]))));
    anb[9][2] = (ank[13][2]+((cnk[13][2][2]*dyrcom[9][2])+((cnk[13][2][0]*
      dyrcom[9][0])+(cnk[13][2][1]*dyrcom[9][1]))));
    dyrcom[10][0] = ((dyad[10][0][2]*rcom[10][2])+((dyad[10][0][1]*rcom[10][1])+
      (rcom[10][0]*w11w22[10])));
    dyrcom[10][1] = ((dyad[10][1][2]*rcom[10][2])+((dyad[10][1][0]*rcom[10][0])+
      (rcom[10][1]*w00w22[10])));
    dyrcom[10][2] = ((rcom[10][2]*w00w11[10])+((dyad[10][2][0]*rcom[10][0])+(
      dyad[10][2][1]*rcom[10][1])));
    anb[10][0] = (ank[13][0]+((cnk[13][0][2]*dyrcom[10][2])+((cnk[13][0][0]*
      dyrcom[10][0])+(cnk[13][0][1]*dyrcom[10][1]))));
    anb[10][1] = (ank[13][1]+((cnk[13][1][2]*dyrcom[10][2])+((cnk[13][1][0]*
      dyrcom[10][0])+(cnk[13][1][1]*dyrcom[10][1]))));
    anb[10][2] = (ank[13][2]+((cnk[13][2][2]*dyrcom[10][2])+((cnk[13][2][0]*
      dyrcom[10][0])+(cnk[13][2][1]*dyrcom[10][1]))));
    anb[11][0] = ank[14][0];
    anb[11][1] = ank[14][1];
    anb[11][2] = ank[14][2];
    anb[12][0] = ank[15][0];
    anb[12][1] = ank[15][1];
    anb[12][2] = ank[15][2];
    anb[13][0] = ank[16][0];
    anb[13][1] = ank[16][1];
    anb[13][2] = ank[16][2];
    dyrcom[14][0] = ((dyad[14][0][2]*rcom[14][2])+((dyad[14][0][1]*rcom[14][1])+
      (rcom[14][0]*w11w22[14])));
    dyrcom[14][1] = ((dyad[14][1][2]*rcom[14][2])+((dyad[14][1][0]*rcom[14][0])+
      (rcom[14][1]*w00w22[14])));
    dyrcom[14][2] = ((rcom[14][2]*w00w11[14])+((dyad[14][2][0]*rcom[14][0])+(
      dyad[14][2][1]*rcom[14][1])));
    anb[14][0] = (ank[17][0]+((cnk[17][0][2]*dyrcom[14][2])+((cnk[17][0][0]*
      dyrcom[14][0])+(cnk[17][0][1]*dyrcom[14][1]))));
    anb[14][1] = (ank[17][1]+((cnk[17][1][2]*dyrcom[14][2])+((cnk[17][1][0]*
      dyrcom[14][0])+(cnk[17][1][1]*dyrcom[14][1]))));
    anb[14][2] = (ank[17][2]+((cnk[17][2][2]*dyrcom[14][2])+((cnk[17][2][0]*
      dyrcom[14][0])+(cnk[17][2][1]*dyrcom[14][1]))));
    dyrcom[15][0] = ((dyad[15][0][2]*rcom[15][2])+((dyad[15][0][1]*rcom[15][1])+
      (rcom[15][0]*w11w22[15])));
    dyrcom[15][1] = ((dyad[15][1][2]*rcom[15][2])+((dyad[15][1][0]*rcom[15][0])+
      (rcom[15][1]*w00w22[15])));
    dyrcom[15][2] = ((rcom[15][2]*w00w11[15])+((dyad[15][2][0]*rcom[15][0])+(
      dyad[15][2][1]*rcom[15][1])));
    anb[15][0] = (ank[17][0]+((cnk[17][0][2]*dyrcom[15][2])+((cnk[17][0][0]*
      dyrcom[15][0])+(cnk[17][0][1]*dyrcom[15][1]))));
    anb[15][1] = (ank[17][1]+((cnk[17][1][2]*dyrcom[15][2])+((cnk[17][1][0]*
      dyrcom[15][0])+(cnk[17][1][1]*dyrcom[15][1]))));
    anb[15][2] = (ank[17][2]+((cnk[17][2][2]*dyrcom[15][2])+((cnk[17][2][0]*
      dyrcom[15][0])+(cnk[17][2][1]*dyrcom[15][1]))));
    anb[16][0] = ank[18][0];
    anb[16][1] = ank[18][1];
    anb[16][2] = ank[18][2];
    anb[17][0] = ank[19][0];
    anb[17][1] = ank[19][1];
    anb[17][2] = ank[19][2];
    anb[18][0] = ank[20][0];
    anb[18][1] = ank[20][1];
    anb[18][2] = ank[20][2];
    dyrcom[19][0] = ((dyad[19][0][2]*rcom[19][2])+((dyad[19][0][1]*rcom[19][1])+
      (rcom[19][0]*w11w22[19])));
    dyrcom[19][1] = ((dyad[19][1][2]*rcom[19][2])+((dyad[19][1][0]*rcom[19][0])+
      (rcom[19][1]*w00w22[19])));
    dyrcom[19][2] = ((rcom[19][2]*w00w11[19])+((dyad[19][2][0]*rcom[19][0])+(
      dyad[19][2][1]*rcom[19][1])));
    anb[19][0] = (ank[21][0]+((cnk[21][0][2]*dyrcom[19][2])+((cnk[21][0][0]*
      dyrcom[19][0])+(cnk[21][0][1]*dyrcom[19][1]))));
    anb[19][1] = (ank[21][1]+((cnk[21][1][2]*dyrcom[19][2])+((cnk[21][1][0]*
      dyrcom[19][0])+(cnk[21][1][1]*dyrcom[19][1]))));
    anb[19][2] = (ank[21][2]+((cnk[21][2][2]*dyrcom[19][2])+((cnk[21][2][0]*
      dyrcom[19][0])+(cnk[21][2][1]*dyrcom[19][1]))));
    dyrcom[20][0] = ((dyad[20][0][2]*rcom[20][2])+((dyad[20][0][1]*rcom[20][1])+
      (rcom[20][0]*w11w22[20])));
    dyrcom[20][1] = ((dyad[20][1][2]*rcom[20][2])+((dyad[20][1][0]*rcom[20][0])+
      (rcom[20][1]*w00w22[20])));
    dyrcom[20][2] = ((rcom[20][2]*w00w11[20])+((dyad[20][2][0]*rcom[20][0])+(
      dyad[20][2][1]*rcom[20][1])));
    anb[20][0] = (ank[21][0]+((cnk[21][0][2]*dyrcom[20][2])+((cnk[21][0][0]*
      dyrcom[20][0])+(cnk[21][0][1]*dyrcom[20][1]))));
    anb[20][1] = (ank[21][1]+((cnk[21][1][2]*dyrcom[20][2])+((cnk[21][1][0]*
      dyrcom[20][0])+(cnk[21][1][1]*dyrcom[20][1]))));
    anb[20][2] = (ank[21][2]+((cnk[21][2][2]*dyrcom[20][2])+((cnk[21][2][0]*
      dyrcom[20][0])+(cnk[21][2][1]*dyrcom[20][1]))));
/*
Compute constraint acceleration errors
*/
    roustate = 3;
/*
 Used 0.01 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  919 adds/subtracts/negates
                    849 multiplies
                      0 divides
                    670 assignments
*/
}

void allegro_air_massmat(double mmat[22][22])
{
/* Return the system mass matrix (LHS)
*/
    int i,j;

    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(57,23);
        return;
    }
    allegro_air_domm(57);
    for (i = 0; i < 22; i++) {
        for (j = i; j <= 21; j++) {
            mmat[i][j] = mm[i][j];
            mmat[j][i] = mm[i][j];
        }
    }
}

void allegro_air_frcmat(double fmat[22])
{
/* Return the system force matrix (RHS), excluding constraints
*/
    int i;

    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(58,23);
        return;
    }
    allegro_air_dofs0();
    for (i = 0; i < 22; i++) {
        fmat[i] = fs0[i];
    }
}

void allegro_air_pseudo(double lqout[1],
    double luout[1])
{
/*
Return pseudo-coordinates for loop joints.

*/
/*
There are no loop joints in this system.

*/
}

void allegro_air_psqdot(double lqdout[1])
{
/*
Return pseudo-coordinate derivatives for loop joints.

*/
/*
There are no loop joints in this system.

*/
}

void allegro_air_psudot(double ludout[1])
{
/*
Return pseudo-coordinate accelerations for loop joints.

*/
/*
There are no loop joints in this system.

*/
}

void allegro_air_perr(double errs[22])
{
/*
Return position constraint errors.

*/

    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(26,23);
        return;
    }
    if (pres[0]  !=  0.) {
        perr[0] = (q[0]-upos[0]);
    } else {
        perr[0] = 0.;
    }
    if (pres[1]  !=  0.) {
        perr[1] = (q[1]-upos[1]);
    } else {
        perr[1] = 0.;
    }
    if (pres[2]  !=  0.) {
        perr[2] = (q[2]-upos[2]);
    } else {
        perr[2] = 0.;
    }
    if (pres[3]  !=  0.) {
        perr[3] = (q[3]-upos[3]);
    } else {
        perr[3] = 0.;
    }
    if (pres[4]  !=  0.) {
        perr[4] = (q[4]-upos[4]);
    } else {
        perr[4] = 0.;
    }
    if (pres[5]  !=  0.) {
        perr[5] = (q[5]-upos[5]);
    } else {
        perr[5] = 0.;
    }
    if (pres[6]  !=  0.) {
        perr[6] = (q[6]-upos[6]);
    } else {
        perr[6] = 0.;
    }
    if (pres[7]  !=  0.) {
        perr[7] = (q[7]-upos[7]);
    } else {
        perr[7] = 0.;
    }
    if (pres[8]  !=  0.) {
        perr[8] = (q[8]-upos[8]);
    } else {
        perr[8] = 0.;
    }
    if (pres[9]  !=  0.) {
        perr[9] = (q[9]-upos[9]);
    } else {
        perr[9] = 0.;
    }
    if (pres[10]  !=  0.) {
        perr[10] = (q[10]-upos[10]);
    } else {
        perr[10] = 0.;
    }
    if (pres[11]  !=  0.) {
        perr[11] = (q[11]-upos[11]);
    } else {
        perr[11] = 0.;
    }
    if (pres[12]  !=  0.) {
        perr[12] = (q[12]-upos[12]);
    } else {
        perr[12] = 0.;
    }
    if (pres[13]  !=  0.) {
        perr[13] = (q[13]-upos[13]);
    } else {
        perr[13] = 0.;
    }
    if (pres[14]  !=  0.) {
        perr[14] = (q[14]-upos[14]);
    } else {
        perr[14] = 0.;
    }
    if (pres[15]  !=  0.) {
        perr[15] = (q[15]-upos[15]);
    } else {
        perr[15] = 0.;
    }
    if (pres[16]  !=  0.) {
        perr[16] = (q[16]-upos[16]);
    } else {
        perr[16] = 0.;
    }
    if (pres[17]  !=  0.) {
        perr[17] = (q[17]-upos[17]);
    } else {
        perr[17] = 0.;
    }
    if (pres[18]  !=  0.) {
        perr[18] = (q[18]-upos[18]);
    } else {
        perr[18] = 0.;
    }
    if (pres[19]  !=  0.) {
        perr[19] = (q[19]-upos[19]);
    } else {
        perr[19] = 0.;
    }
    if (pres[20]  !=  0.) {
        perr[20] = (q[20]-upos[20]);
    } else {
        perr[20] = 0.;
    }
    if (pres[21]  !=  0.) {
        perr[21] = (q[21]-upos[21]);
    } else {
        perr[21] = 0.;
    }
    errs[0] = perr[0];
    errs[1] = perr[1];
    errs[2] = perr[2];
    errs[3] = perr[3];
    errs[4] = perr[4];
    errs[5] = perr[5];
    errs[6] = perr[6];
    errs[7] = perr[7];
    errs[8] = perr[8];
    errs[9] = perr[9];
    errs[10] = perr[10];
    errs[11] = perr[11];
    errs[12] = perr[12];
    errs[13] = perr[13];
    errs[14] = perr[14];
    errs[15] = perr[15];
    errs[16] = perr[16];
    errs[17] = perr[17];
    errs[18] = perr[18];
    errs[19] = perr[19];
    errs[20] = perr[20];
    errs[21] = perr[21];
}

void allegro_air_verr(double errs[22])
{
/*
Return velocity constraint errors.

*/

    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(27,23);
        return;
    }
    if (pres[0]  !=  0.) {
        verr[0] = (u[0]-uvel[0]);
    } else {
        verr[0] = 0.;
    }
    if (pres[1]  !=  0.) {
        verr[1] = (u[1]-uvel[1]);
    } else {
        verr[1] = 0.;
    }
    if (pres[2]  !=  0.) {
        verr[2] = (u[2]-uvel[2]);
    } else {
        verr[2] = 0.;
    }
    if (pres[3]  !=  0.) {
        verr[3] = (u[3]-uvel[3]);
    } else {
        verr[3] = 0.;
    }
    if (pres[4]  !=  0.) {
        verr[4] = (u[4]-uvel[4]);
    } else {
        verr[4] = 0.;
    }
    if (pres[5]  !=  0.) {
        verr[5] = (u[5]-uvel[5]);
    } else {
        verr[5] = 0.;
    }
    if (pres[6]  !=  0.) {
        verr[6] = (u[6]-uvel[6]);
    } else {
        verr[6] = 0.;
    }
    if (pres[7]  !=  0.) {
        verr[7] = (u[7]-uvel[7]);
    } else {
        verr[7] = 0.;
    }
    if (pres[8]  !=  0.) {
        verr[8] = (u[8]-uvel[8]);
    } else {
        verr[8] = 0.;
    }
    if (pres[9]  !=  0.) {
        verr[9] = (u[9]-uvel[9]);
    } else {
        verr[9] = 0.;
    }
    if (pres[10]  !=  0.) {
        verr[10] = (u[10]-uvel[10]);
    } else {
        verr[10] = 0.;
    }
    if (pres[11]  !=  0.) {
        verr[11] = (u[11]-uvel[11]);
    } else {
        verr[11] = 0.;
    }
    if (pres[12]  !=  0.) {
        verr[12] = (u[12]-uvel[12]);
    } else {
        verr[12] = 0.;
    }
    if (pres[13]  !=  0.) {
        verr[13] = (u[13]-uvel[13]);
    } else {
        verr[13] = 0.;
    }
    if (pres[14]  !=  0.) {
        verr[14] = (u[14]-uvel[14]);
    } else {
        verr[14] = 0.;
    }
    if (pres[15]  !=  0.) {
        verr[15] = (u[15]-uvel[15]);
    } else {
        verr[15] = 0.;
    }
    if (pres[16]  !=  0.) {
        verr[16] = (u[16]-uvel[16]);
    } else {
        verr[16] = 0.;
    }
    if (pres[17]  !=  0.) {
        verr[17] = (u[17]-uvel[17]);
    } else {
        verr[17] = 0.;
    }
    if (pres[18]  !=  0.) {
        verr[18] = (u[18]-uvel[18]);
    } else {
        verr[18] = 0.;
    }
    if (pres[19]  !=  0.) {
        verr[19] = (u[19]-uvel[19]);
    } else {
        verr[19] = 0.;
    }
    if (pres[20]  !=  0.) {
        verr[20] = (u[20]-uvel[20]);
    } else {
        verr[20] = 0.;
    }
    if (pres[21]  !=  0.) {
        verr[21] = (u[21]-uvel[21]);
    } else {
        verr[21] = 0.;
    }
    errs[0] = verr[0];
    errs[1] = verr[1];
    errs[2] = verr[2];
    errs[3] = verr[3];
    errs[4] = verr[4];
    errs[5] = verr[5];
    errs[6] = verr[6];
    errs[7] = verr[7];
    errs[8] = verr[8];
    errs[9] = verr[9];
    errs[10] = verr[10];
    errs[11] = verr[11];
    errs[12] = verr[12];
    errs[13] = verr[13];
    errs[14] = verr[14];
    errs[15] = verr[15];
    errs[16] = verr[16];
    errs[17] = verr[17];
    errs[18] = verr[18];
    errs[19] = verr[19];
    errs[20] = verr[20];
    errs[21] = verr[21];
}

void allegro_air_aerr(double errs[22])
{
/*
Return acceleration constraint errors.

*/

    if (roustate != 3) {
        allegro_air_seterr(35,24);
        return;
    }
    if (pres[0]  !=  0.) {
        aerr[0] = (udot[0]-uacc[0]);
    } else {
        aerr[0] = 0.;
    }
    if (pres[1]  !=  0.) {
        aerr[1] = (udot[1]-uacc[1]);
    } else {
        aerr[1] = 0.;
    }
    if (pres[2]  !=  0.) {
        aerr[2] = (udot[2]-uacc[2]);
    } else {
        aerr[2] = 0.;
    }
    if (pres[3]  !=  0.) {
        aerr[3] = (udot[3]-uacc[3]);
    } else {
        aerr[3] = 0.;
    }
    if (pres[4]  !=  0.) {
        aerr[4] = (udot[4]-uacc[4]);
    } else {
        aerr[4] = 0.;
    }
    if (pres[5]  !=  0.) {
        aerr[5] = (udot[5]-uacc[5]);
    } else {
        aerr[5] = 0.;
    }
    if (pres[6]  !=  0.) {
        aerr[6] = (udot[6]-uacc[6]);
    } else {
        aerr[6] = 0.;
    }
    if (pres[7]  !=  0.) {
        aerr[7] = (udot[7]-uacc[7]);
    } else {
        aerr[7] = 0.;
    }
    if (pres[8]  !=  0.) {
        aerr[8] = (udot[8]-uacc[8]);
    } else {
        aerr[8] = 0.;
    }
    if (pres[9]  !=  0.) {
        aerr[9] = (udot[9]-uacc[9]);
    } else {
        aerr[9] = 0.;
    }
    if (pres[10]  !=  0.) {
        aerr[10] = (udot[10]-uacc[10]);
    } else {
        aerr[10] = 0.;
    }
    if (pres[11]  !=  0.) {
        aerr[11] = (udot[11]-uacc[11]);
    } else {
        aerr[11] = 0.;
    }
    if (pres[12]  !=  0.) {
        aerr[12] = (udot[12]-uacc[12]);
    } else {
        aerr[12] = 0.;
    }
    if (pres[13]  !=  0.) {
        aerr[13] = (udot[13]-uacc[13]);
    } else {
        aerr[13] = 0.;
    }
    if (pres[14]  !=  0.) {
        aerr[14] = (udot[14]-uacc[14]);
    } else {
        aerr[14] = 0.;
    }
    if (pres[15]  !=  0.) {
        aerr[15] = (udot[15]-uacc[15]);
    } else {
        aerr[15] = 0.;
    }
    if (pres[16]  !=  0.) {
        aerr[16] = (udot[16]-uacc[16]);
    } else {
        aerr[16] = 0.;
    }
    if (pres[17]  !=  0.) {
        aerr[17] = (udot[17]-uacc[17]);
    } else {
        aerr[17] = 0.;
    }
    if (pres[18]  !=  0.) {
        aerr[18] = (udot[18]-uacc[18]);
    } else {
        aerr[18] = 0.;
    }
    if (pres[19]  !=  0.) {
        aerr[19] = (udot[19]-uacc[19]);
    } else {
        aerr[19] = 0.;
    }
    if (pres[20]  !=  0.) {
        aerr[20] = (udot[20]-uacc[20]);
    } else {
        aerr[20] = 0.;
    }
    if (pres[21]  !=  0.) {
        aerr[21] = (udot[21]-uacc[21]);
    } else {
        aerr[21] = 0.;
    }
    errs[0] = aerr[0];
    errs[1] = aerr[1];
    errs[2] = aerr[2];
    errs[3] = aerr[3];
    errs[4] = aerr[4];
    errs[5] = aerr[5];
    errs[6] = aerr[6];
    errs[7] = aerr[7];
    errs[8] = aerr[8];
    errs[9] = aerr[9];
    errs[10] = aerr[10];
    errs[11] = aerr[11];
    errs[12] = aerr[12];
    errs[13] = aerr[13];
    errs[14] = aerr[14];
    errs[15] = aerr[15];
    errs[16] = aerr[16];
    errs[17] = aerr[17];
    errs[18] = aerr[18];
    errs[19] = aerr[19];
    errs[20] = aerr[20];
    errs[21] = aerr[21];
}
int 
allegro_air_chkbnum(int routine,
    int bnum)
{

    if ((bnum < -1) || (bnum > 20)) {
        allegro_air_seterr(routine,15);
        return 1;
    }
    return 0;
}
int 
allegro_air_chkjnum(int routine,
    int jnum)
{

    if ((jnum < 0) || (jnum > 20)) {
        allegro_air_seterr(routine,16);
        return 1;
    }
    return 0;
}
int 
allegro_air_chkucnum(int routine,
    int ucnum)
{

    if ((ucnum < 0) || (ucnum > -1)) {
        allegro_air_seterr(routine,21);
        return 1;
    }
    return 0;
}
int 
allegro_air_chkjaxis(int routine,
    int jnum,
    int axnum)
{
    int maxax;

    if (allegro_air_chkjnum(routine,jnum) != 0) {
        return 1;
    }
    if ((axnum < 0) || (axnum > 6)) {
        allegro_air_seterr(routine,17);
        return 1;
    }
    maxax = njntdof[jnum]-1;
    if ((jtype[jnum] == 4) || (jtype[jnum] == 6) || (jtype[jnum] == 21)) {
        maxax = maxax+1;
    }
    if (axnum > maxax) {
        allegro_air_seterr(routine,18);
        return 1;
    }
    return 0;
}
int 
allegro_air_chkjpin(int routine,
    int jnum,
    int pinno)
{
    int maxax,pinok;

    if (allegro_air_chkjnum(routine,jnum) != 0) {
        return 1;
    }
    if ((pinno < 0) || (pinno > 5)) {
        allegro_air_seterr(routine,17);
        return 1;
    }
    if (njntdof[jnum] >= 3) {
        maxax = 2;
    } else {
        maxax = njntdof[jnum]-1;
    }
    if (jtype[jnum] == 4) {
        maxax = -1;
    }
    if (jtype[jnum] == 7) {
        maxax = 0;
    }
    pinok = 0;
    if (pinno <= maxax) {
        pinok = 1;
    }
    if (pinok == 0) {
        allegro_air_seterr(routine,18);
        return 1;
    }
    return 0;
}
int 
allegro_air_indx(int joint,
    int axis)
{
    int offs,gotit;

    if (allegro_air_chkjaxis(36,joint,axis) != 0) {
        return 0;
    }
    gotit = 0;
    if (jtype[joint] == 4) {
        if (axis == 3) {
            offs = ballq[joint];
            gotit = 1;
        }
    } else {
        if ((jtype[joint] == 6) || (jtype[joint] == 21)) {
            if (axis == 6) {
                offs = ballq[joint];
                gotit = 1;
            }
        }
    }
    if (gotit == 0) {
        offs = firstq[joint]+axis;
    }
    return offs;
}

void allegro_air_presacc(int joint,
    int axis,
    double prval)
{

    if (allegro_air_chkjaxis(13,joint,axis) != 0) {
        return;
    }
    if (roustate != 2) {
        allegro_air_seterr(13,23);
        return;
    }
    if (pres[allegro_air_indx(joint,axis)]  !=  0.) {
        uacc[allegro_air_indx(joint,axis)] = prval;
    }
}

void allegro_air_presvel(int joint,
    int axis,
    double prval)
{

    if (allegro_air_chkjaxis(14,joint,axis) != 0) {
        return;
    }
    if (roustate != 2) {
        allegro_air_seterr(14,23);
        return;
    }
    if (pres[allegro_air_indx(joint,axis)]  !=  0.) {
        uvel[allegro_air_indx(joint,axis)] = prval;
    }
}

void allegro_air_prespos(int joint,
    int axis,
    double prval)
{

    if (allegro_air_chkjaxis(15,joint,axis) != 0) {
        return;
    }
    if (roustate != 2) {
        allegro_air_seterr(15,23);
        return;
    }
    if (pres[allegro_air_indx(joint,axis)]  !=  0.) {
        upos[allegro_air_indx(joint,axis)] = prval;
    }
}

void allegro_air_getht(int joint,
    int axis,
    double *torque)
{

    if (allegro_air_chkjaxis(30,joint,axis) != 0) {
        return;
    }
    if (roustate != 3) {
        allegro_air_seterr(30,24);
        return;
    }
    *torque = tauc[allegro_air_indx(joint,axis)];
}

void allegro_air_hinget(int joint,
    int axis,
    double torque)
{

    if (allegro_air_chkjaxis(10,joint,axis) != 0) {
        return;
    }
    if (roustate != 2) {
        allegro_air_seterr(10,23);
        return;
    }
    if (mfrcflg != 0) {
        mtau[allegro_air_indx(joint,axis)] = mtau[allegro_air_indx(joint,axis)]
          +torque;
    } else {
        fs0flg = 0;
        utau[allegro_air_indx(joint,axis)] = utau[allegro_air_indx(joint,axis)]
          +torque;
    }
}

void allegro_air_pointf(int body,
    double point[3],
    double force[3])
{
    double torque[3];

    if (allegro_air_chkbnum(11,body) != 0) {
        return;
    }
    if (roustate != 2) {
        allegro_air_seterr(11,23);
        return;
    }
    if (body == -1) {
        return;
    }
    torque[0] = point[1]*force[2]-point[2]*force[1];
    torque[1] = point[2]*force[0]-point[0]*force[2];
    torque[2] = point[0]*force[1]-point[1]*force[0];
    if (mfrcflg != 0) {
        mfk[body][0] = mfk[body][0]+force[0];
        mtk[body][0] = mtk[body][0]+torque[0];
        mfk[body][1] = mfk[body][1]+force[1];
        mtk[body][1] = mtk[body][1]+torque[1];
        mfk[body][2] = mfk[body][2]+force[2];
        mtk[body][2] = mtk[body][2]+torque[2];
    } else {
        fs0flg = 0;
        ufk[body][0] = ufk[body][0]+force[0];
        utk[body][0] = utk[body][0]+torque[0];
        ufk[body][1] = ufk[body][1]+force[1];
        utk[body][1] = utk[body][1]+torque[1];
        ufk[body][2] = ufk[body][2]+force[2];
        utk[body][2] = utk[body][2]+torque[2];
    }
}

void allegro_air_bodyt(int body,
    double torque[3])
{

    if (allegro_air_chkbnum(12,body) != 0) {
        return;
    }
    if (roustate != 2) {
        allegro_air_seterr(12,23);
        return;
    }
    if (body == -1) {
        return;
    }
    if (mfrcflg != 0) {
        mtk[body][0] = mtk[body][0]+torque[0];
        mtk[body][1] = mtk[body][1]+torque[1];
        mtk[body][2] = mtk[body][2]+torque[2];
    } else {
        fs0flg = 0;
        utk[body][0] = utk[body][0]+torque[0];
        utk[body][1] = utk[body][1]+torque[1];
        utk[body][2] = utk[body][2]+torque[2];
    }
}

void allegro_air_doww(int routine)
{
    double pp[22][22],dpp[22][22];
    int i,j,c;
    double sum;
    double dfk[21][3],dtk[21][3],dtau[22],dltci[1][3],dltc[1][3],dlfci[1][3],
      dlfc[1][3];
    double dTinb[1][3],dToutb[1][3],dltaufi[1][3],dltaufo[1][3],dltauti[1][3],
      dltauto[1][3];
    double dfs[22],row[22],dinvrow[22];

    roustate = 2;
    if (wwflg == 0) {
/*
Compute constraint effects
*/
        allegro_air_dovpk();
        allegro_air_dommldu(routine);
/*
Constraint 0 (prescribed motion)
*/
        if (pres[0]  !=  0.) {
            dtau[0] = 1.;
        } else {
            dtau[0] = 0.;
        }
        dfs[0] = dtau[0];
        dfs[1] = 0.;
        dfs[2] = 0.;
        dfs[3] = 0.;
        dfs[4] = 0.;
        dfs[5] = 0.;
        dfs[6] = 0.;
        dfs[7] = 0.;
        dfs[8] = 0.;
        dfs[9] = 0.;
        dfs[10] = 0.;
        dfs[11] = 0.;
        dfs[12] = 0.;
        dfs[13] = 0.;
        dfs[14] = 0.;
        dfs[15] = 0.;
        dfs[16] = 0.;
        dfs[17] = 0.;
        dfs[18] = 0.;
        dfs[19] = 0.;
        dfs[20] = 0.;
        dfs[21] = 0.;
        allegro_air_ldubsl(22,22,mmap,mlo,dfs,row);
        allegro_air_ldubsd(22,22,mmap,mdi,row,dinvrow);
        for (i = 0; i <= 21; i++) {
            pp[0][i] = row[i];
            dpp[i][0] = dinvrow[i];
        }
        wmap[0] = 0;
/*
Constraint 1 (prescribed motion)
*/
        if (pres[1]  !=  0.) {
            dtau[1] = 1.;
        } else {
            dtau[1] = 0.;
        }
        dfs[1] = dtau[1];
        dfs[0] = 0.;
        dfs[2] = 0.;
        dfs[3] = 0.;
        dfs[4] = 0.;
        dfs[5] = 0.;
        dfs[6] = 0.;
        dfs[7] = 0.;
        dfs[8] = 0.;
        dfs[9] = 0.;
        dfs[10] = 0.;
        dfs[11] = 0.;
        dfs[12] = 0.;
        dfs[13] = 0.;
        dfs[14] = 0.;
        dfs[15] = 0.;
        dfs[16] = 0.;
        dfs[17] = 0.;
        dfs[18] = 0.;
        dfs[19] = 0.;
        dfs[20] = 0.;
        dfs[21] = 0.;
        allegro_air_ldubsl(22,22,mmap,mlo,dfs,row);
        allegro_air_ldubsd(22,22,mmap,mdi,row,dinvrow);
        for (i = 0; i <= 21; i++) {
            pp[1][i] = row[i];
            dpp[i][1] = dinvrow[i];
        }
        wmap[1] = 1;
/*
Constraint 2 (prescribed motion)
*/
        if (pres[2]  !=  0.) {
            dtau[2] = 1.;
        } else {
            dtau[2] = 0.;
        }
        dfs[2] = dtau[2];
        dfs[0] = 0.;
        dfs[1] = 0.;
        dfs[3] = 0.;
        dfs[4] = 0.;
        dfs[5] = 0.;
        dfs[6] = 0.;
        dfs[7] = 0.;
        dfs[8] = 0.;
        dfs[9] = 0.;
        dfs[10] = 0.;
        dfs[11] = 0.;
        dfs[12] = 0.;
        dfs[13] = 0.;
        dfs[14] = 0.;
        dfs[15] = 0.;
        dfs[16] = 0.;
        dfs[17] = 0.;
        dfs[18] = 0.;
        dfs[19] = 0.;
        dfs[20] = 0.;
        dfs[21] = 0.;
        allegro_air_ldubsl(22,22,mmap,mlo,dfs,row);
        allegro_air_ldubsd(22,22,mmap,mdi,row,dinvrow);
        for (i = 0; i <= 21; i++) {
            pp[2][i] = row[i];
            dpp[i][2] = dinvrow[i];
        }
        wmap[2] = 2;
/*
Constraint 3 (prescribed motion)
*/
        if (pres[3]  !=  0.) {
            dtau[3] = 1.;
        } else {
            dtau[3] = 0.;
        }
        dfs[3] = dtau[3];
        dfs[0] = 0.;
        dfs[1] = 0.;
        dfs[2] = 0.;
        dfs[4] = 0.;
        dfs[5] = 0.;
        dfs[6] = 0.;
        dfs[7] = 0.;
        dfs[8] = 0.;
        dfs[9] = 0.;
        dfs[10] = 0.;
        dfs[11] = 0.;
        dfs[12] = 0.;
        dfs[13] = 0.;
        dfs[14] = 0.;
        dfs[15] = 0.;
        dfs[16] = 0.;
        dfs[17] = 0.;
        dfs[18] = 0.;
        dfs[19] = 0.;
        dfs[20] = 0.;
        dfs[21] = 0.;
        allegro_air_ldubsl(22,22,mmap,mlo,dfs,row);
        allegro_air_ldubsd(22,22,mmap,mdi,row,dinvrow);
        for (i = 0; i <= 21; i++) {
            pp[3][i] = row[i];
            dpp[i][3] = dinvrow[i];
        }
        wmap[3] = 3;
/*
Constraint 4 (prescribed motion)
*/
        if (pres[4]  !=  0.) {
            dtau[4] = 1.;
        } else {
            dtau[4] = 0.;
        }
        dfs[4] = dtau[4];
        dfs[0] = 0.;
        dfs[1] = 0.;
        dfs[2] = 0.;
        dfs[3] = 0.;
        dfs[5] = 0.;
        dfs[6] = 0.;
        dfs[7] = 0.;
        dfs[8] = 0.;
        dfs[9] = 0.;
        dfs[10] = 0.;
        dfs[11] = 0.;
        dfs[12] = 0.;
        dfs[13] = 0.;
        dfs[14] = 0.;
        dfs[15] = 0.;
        dfs[16] = 0.;
        dfs[17] = 0.;
        dfs[18] = 0.;
        dfs[19] = 0.;
        dfs[20] = 0.;
        dfs[21] = 0.;
        allegro_air_ldubsl(22,22,mmap,mlo,dfs,row);
        allegro_air_ldubsd(22,22,mmap,mdi,row,dinvrow);
        for (i = 0; i <= 21; i++) {
            pp[4][i] = row[i];
            dpp[i][4] = dinvrow[i];
        }
        wmap[4] = 4;
/*
Constraint 5 (prescribed motion)
*/
        if (pres[5]  !=  0.) {
            dtau[5] = 1.;
        } else {
            dtau[5] = 0.;
        }
        dfs[5] = dtau[5];
        dfs[0] = 0.;
        dfs[1] = 0.;
        dfs[2] = 0.;
        dfs[3] = 0.;
        dfs[4] = 0.;
        dfs[6] = 0.;
        dfs[7] = 0.;
        dfs[8] = 0.;
        dfs[9] = 0.;
        dfs[10] = 0.;
        dfs[11] = 0.;
        dfs[12] = 0.;
        dfs[13] = 0.;
        dfs[14] = 0.;
        dfs[15] = 0.;
        dfs[16] = 0.;
        dfs[17] = 0.;
        dfs[18] = 0.;
        dfs[19] = 0.;
        dfs[20] = 0.;
        dfs[21] = 0.;
        allegro_air_ldubsl(22,22,mmap,mlo,dfs,row);
        allegro_air_ldubsd(22,22,mmap,mdi,row,dinvrow);
        for (i = 0; i <= 21; i++) {
            pp[5][i] = row[i];
            dpp[i][5] = dinvrow[i];
        }
        wmap[5] = 5;
/*
Constraint 6 (prescribed motion)
*/
        if (pres[6]  !=  0.) {
            dtau[6] = 1.;
        } else {
            dtau[6] = 0.;
        }
        dfs[6] = dtau[6];
        dfs[0] = 0.;
        dfs[1] = 0.;
        dfs[2] = 0.;
        dfs[3] = 0.;
        dfs[4] = 0.;
        dfs[5] = 0.;
        dfs[7] = 0.;
        dfs[8] = 0.;
        dfs[9] = 0.;
        dfs[10] = 0.;
        dfs[11] = 0.;
        dfs[12] = 0.;
        dfs[13] = 0.;
        dfs[14] = 0.;
        dfs[15] = 0.;
        dfs[16] = 0.;
        dfs[17] = 0.;
        dfs[18] = 0.;
        dfs[19] = 0.;
        dfs[20] = 0.;
        dfs[21] = 0.;
        allegro_air_ldubsl(22,22,mmap,mlo,dfs,row);
        allegro_air_ldubsd(22,22,mmap,mdi,row,dinvrow);
        for (i = 0; i <= 21; i++) {
            pp[6][i] = row[i];
            dpp[i][6] = dinvrow[i];
        }
        wmap[6] = 6;
/*
Constraint 7 (prescribed motion)
*/
        if (pres[7]  !=  0.) {
            dtau[7] = 1.;
        } else {
            dtau[7] = 0.;
        }
        dfs[7] = dtau[7];
        dfs[0] = 0.;
        dfs[1] = 0.;
        dfs[2] = 0.;
        dfs[3] = 0.;
        dfs[4] = 0.;
        dfs[5] = 0.;
        dfs[6] = 0.;
        dfs[8] = 0.;
        dfs[9] = 0.;
        dfs[10] = 0.;
        dfs[11] = 0.;
        dfs[12] = 0.;
        dfs[13] = 0.;
        dfs[14] = 0.;
        dfs[15] = 0.;
        dfs[16] = 0.;
        dfs[17] = 0.;
        dfs[18] = 0.;
        dfs[19] = 0.;
        dfs[20] = 0.;
        dfs[21] = 0.;
        allegro_air_ldubsl(22,22,mmap,mlo,dfs,row);
        allegro_air_ldubsd(22,22,mmap,mdi,row,dinvrow);
        for (i = 0; i <= 21; i++) {
            pp[7][i] = row[i];
            dpp[i][7] = dinvrow[i];
        }
        wmap[7] = 7;
/*
Constraint 8 (prescribed motion)
*/
        if (pres[8]  !=  0.) {
            dtau[8] = 1.;
        } else {
            dtau[8] = 0.;
        }
        dfs[8] = dtau[8];
        dfs[0] = 0.;
        dfs[1] = 0.;
        dfs[2] = 0.;
        dfs[3] = 0.;
        dfs[4] = 0.;
        dfs[5] = 0.;
        dfs[6] = 0.;
        dfs[7] = 0.;
        dfs[9] = 0.;
        dfs[10] = 0.;
        dfs[11] = 0.;
        dfs[12] = 0.;
        dfs[13] = 0.;
        dfs[14] = 0.;
        dfs[15] = 0.;
        dfs[16] = 0.;
        dfs[17] = 0.;
        dfs[18] = 0.;
        dfs[19] = 0.;
        dfs[20] = 0.;
        dfs[21] = 0.;
        allegro_air_ldubsl(22,22,mmap,mlo,dfs,row);
        allegro_air_ldubsd(22,22,mmap,mdi,row,dinvrow);
        for (i = 0; i <= 21; i++) {
            pp[8][i] = row[i];
            dpp[i][8] = dinvrow[i];
        }
        wmap[8] = 8;
/*
Constraint 9 (prescribed motion)
*/
        if (pres[9]  !=  0.) {
            dtau[9] = 1.;
        } else {
            dtau[9] = 0.;
        }
        dfs[9] = dtau[9];
        dfs[0] = 0.;
        dfs[1] = 0.;
        dfs[2] = 0.;
        dfs[3] = 0.;
        dfs[4] = 0.;
        dfs[5] = 0.;
        dfs[6] = 0.;
        dfs[7] = 0.;
        dfs[8] = 0.;
        dfs[10] = 0.;
        dfs[11] = 0.;
        dfs[12] = 0.;
        dfs[13] = 0.;
        dfs[14] = 0.;
        dfs[15] = 0.;
        dfs[16] = 0.;
        dfs[17] = 0.;
        dfs[18] = 0.;
        dfs[19] = 0.;
        dfs[20] = 0.;
        dfs[21] = 0.;
        allegro_air_ldubsl(22,22,mmap,mlo,dfs,row);
        allegro_air_ldubsd(22,22,mmap,mdi,row,dinvrow);
        for (i = 0; i <= 21; i++) {
            pp[9][i] = row[i];
            dpp[i][9] = dinvrow[i];
        }
        wmap[9] = 9;
/*
Constraint 10 (prescribed motion)
*/
        if (pres[10]  !=  0.) {
            dtau[10] = 1.;
        } else {
            dtau[10] = 0.;
        }
        dfs[10] = dtau[10];
        dfs[0] = 0.;
        dfs[1] = 0.;
        dfs[2] = 0.;
        dfs[3] = 0.;
        dfs[4] = 0.;
        dfs[5] = 0.;
        dfs[6] = 0.;
        dfs[7] = 0.;
        dfs[8] = 0.;
        dfs[9] = 0.;
        dfs[11] = 0.;
        dfs[12] = 0.;
        dfs[13] = 0.;
        dfs[14] = 0.;
        dfs[15] = 0.;
        dfs[16] = 0.;
        dfs[17] = 0.;
        dfs[18] = 0.;
        dfs[19] = 0.;
        dfs[20] = 0.;
        dfs[21] = 0.;
        allegro_air_ldubsl(22,22,mmap,mlo,dfs,row);
        allegro_air_ldubsd(22,22,mmap,mdi,row,dinvrow);
        for (i = 0; i <= 21; i++) {
            pp[10][i] = row[i];
            dpp[i][10] = dinvrow[i];
        }
        wmap[10] = 10;
/*
Constraint 11 (prescribed motion)
*/
        if (pres[11]  !=  0.) {
            dtau[11] = 1.;
        } else {
            dtau[11] = 0.;
        }
        dfs[11] = dtau[11];
        dfs[0] = 0.;
        dfs[1] = 0.;
        dfs[2] = 0.;
        dfs[3] = 0.;
        dfs[4] = 0.;
        dfs[5] = 0.;
        dfs[6] = 0.;
        dfs[7] = 0.;
        dfs[8] = 0.;
        dfs[9] = 0.;
        dfs[10] = 0.;
        dfs[12] = 0.;
        dfs[13] = 0.;
        dfs[14] = 0.;
        dfs[15] = 0.;
        dfs[16] = 0.;
        dfs[17] = 0.;
        dfs[18] = 0.;
        dfs[19] = 0.;
        dfs[20] = 0.;
        dfs[21] = 0.;
        allegro_air_ldubsl(22,22,mmap,mlo,dfs,row);
        allegro_air_ldubsd(22,22,mmap,mdi,row,dinvrow);
        for (i = 0; i <= 21; i++) {
            pp[11][i] = row[i];
            dpp[i][11] = dinvrow[i];
        }
        wmap[11] = 11;
/*
Constraint 12 (prescribed motion)
*/
        if (pres[12]  !=  0.) {
            dtau[12] = 1.;
        } else {
            dtau[12] = 0.;
        }
        dfs[12] = dtau[12];
        dfs[0] = 0.;
        dfs[1] = 0.;
        dfs[2] = 0.;
        dfs[3] = 0.;
        dfs[4] = 0.;
        dfs[5] = 0.;
        dfs[6] = 0.;
        dfs[7] = 0.;
        dfs[8] = 0.;
        dfs[9] = 0.;
        dfs[10] = 0.;
        dfs[11] = 0.;
        dfs[13] = 0.;
        dfs[14] = 0.;
        dfs[15] = 0.;
        dfs[16] = 0.;
        dfs[17] = 0.;
        dfs[18] = 0.;
        dfs[19] = 0.;
        dfs[20] = 0.;
        dfs[21] = 0.;
        allegro_air_ldubsl(22,22,mmap,mlo,dfs,row);
        allegro_air_ldubsd(22,22,mmap,mdi,row,dinvrow);
        for (i = 0; i <= 21; i++) {
            pp[12][i] = row[i];
            dpp[i][12] = dinvrow[i];
        }
        wmap[12] = 12;
/*
Constraint 13 (prescribed motion)
*/
        if (pres[13]  !=  0.) {
            dtau[13] = 1.;
        } else {
            dtau[13] = 0.;
        }
        dfs[13] = dtau[13];
        dfs[0] = 0.;
        dfs[1] = 0.;
        dfs[2] = 0.;
        dfs[3] = 0.;
        dfs[4] = 0.;
        dfs[5] = 0.;
        dfs[6] = 0.;
        dfs[7] = 0.;
        dfs[8] = 0.;
        dfs[9] = 0.;
        dfs[10] = 0.;
        dfs[11] = 0.;
        dfs[12] = 0.;
        dfs[14] = 0.;
        dfs[15] = 0.;
        dfs[16] = 0.;
        dfs[17] = 0.;
        dfs[18] = 0.;
        dfs[19] = 0.;
        dfs[20] = 0.;
        dfs[21] = 0.;
        allegro_air_ldubsl(22,22,mmap,mlo,dfs,row);
        allegro_air_ldubsd(22,22,mmap,mdi,row,dinvrow);
        for (i = 0; i <= 21; i++) {
            pp[13][i] = row[i];
            dpp[i][13] = dinvrow[i];
        }
        wmap[13] = 13;
/*
Constraint 14 (prescribed motion)
*/
        if (pres[14]  !=  0.) {
            dtau[14] = 1.;
        } else {
            dtau[14] = 0.;
        }
        dfs[14] = dtau[14];
        dfs[0] = 0.;
        dfs[1] = 0.;
        dfs[2] = 0.;
        dfs[3] = 0.;
        dfs[4] = 0.;
        dfs[5] = 0.;
        dfs[6] = 0.;
        dfs[7] = 0.;
        dfs[8] = 0.;
        dfs[9] = 0.;
        dfs[10] = 0.;
        dfs[11] = 0.;
        dfs[12] = 0.;
        dfs[13] = 0.;
        dfs[15] = 0.;
        dfs[16] = 0.;
        dfs[17] = 0.;
        dfs[18] = 0.;
        dfs[19] = 0.;
        dfs[20] = 0.;
        dfs[21] = 0.;
        allegro_air_ldubsl(22,22,mmap,mlo,dfs,row);
        allegro_air_ldubsd(22,22,mmap,mdi,row,dinvrow);
        for (i = 0; i <= 21; i++) {
            pp[14][i] = row[i];
            dpp[i][14] = dinvrow[i];
        }
        wmap[14] = 14;
/*
Constraint 15 (prescribed motion)
*/
        if (pres[15]  !=  0.) {
            dtau[15] = 1.;
        } else {
            dtau[15] = 0.;
        }
        dfs[15] = dtau[15];
        dfs[0] = 0.;
        dfs[1] = 0.;
        dfs[2] = 0.;
        dfs[3] = 0.;
        dfs[4] = 0.;
        dfs[5] = 0.;
        dfs[6] = 0.;
        dfs[7] = 0.;
        dfs[8] = 0.;
        dfs[9] = 0.;
        dfs[10] = 0.;
        dfs[11] = 0.;
        dfs[12] = 0.;
        dfs[13] = 0.;
        dfs[14] = 0.;
        dfs[16] = 0.;
        dfs[17] = 0.;
        dfs[18] = 0.;
        dfs[19] = 0.;
        dfs[20] = 0.;
        dfs[21] = 0.;
        allegro_air_ldubsl(22,22,mmap,mlo,dfs,row);
        allegro_air_ldubsd(22,22,mmap,mdi,row,dinvrow);
        for (i = 0; i <= 21; i++) {
            pp[15][i] = row[i];
            dpp[i][15] = dinvrow[i];
        }
        wmap[15] = 15;
/*
Constraint 16 (prescribed motion)
*/
        if (pres[16]  !=  0.) {
            dtau[16] = 1.;
        } else {
            dtau[16] = 0.;
        }
        dfs[16] = dtau[16];
        dfs[0] = 0.;
        dfs[1] = 0.;
        dfs[2] = 0.;
        dfs[3] = 0.;
        dfs[4] = 0.;
        dfs[5] = 0.;
        dfs[6] = 0.;
        dfs[7] = 0.;
        dfs[8] = 0.;
        dfs[9] = 0.;
        dfs[10] = 0.;
        dfs[11] = 0.;
        dfs[12] = 0.;
        dfs[13] = 0.;
        dfs[14] = 0.;
        dfs[15] = 0.;
        dfs[17] = 0.;
        dfs[18] = 0.;
        dfs[19] = 0.;
        dfs[20] = 0.;
        dfs[21] = 0.;
        allegro_air_ldubsl(22,22,mmap,mlo,dfs,row);
        allegro_air_ldubsd(22,22,mmap,mdi,row,dinvrow);
        for (i = 0; i <= 21; i++) {
            pp[16][i] = row[i];
            dpp[i][16] = dinvrow[i];
        }
        wmap[16] = 16;
/*
Constraint 17 (prescribed motion)
*/
        if (pres[17]  !=  0.) {
            dtau[17] = 1.;
        } else {
            dtau[17] = 0.;
        }
        dfs[17] = dtau[17];
        dfs[0] = 0.;
        dfs[1] = 0.;
        dfs[2] = 0.;
        dfs[3] = 0.;
        dfs[4] = 0.;
        dfs[5] = 0.;
        dfs[6] = 0.;
        dfs[7] = 0.;
        dfs[8] = 0.;
        dfs[9] = 0.;
        dfs[10] = 0.;
        dfs[11] = 0.;
        dfs[12] = 0.;
        dfs[13] = 0.;
        dfs[14] = 0.;
        dfs[15] = 0.;
        dfs[16] = 0.;
        dfs[18] = 0.;
        dfs[19] = 0.;
        dfs[20] = 0.;
        dfs[21] = 0.;
        allegro_air_ldubsl(22,22,mmap,mlo,dfs,row);
        allegro_air_ldubsd(22,22,mmap,mdi,row,dinvrow);
        for (i = 0; i <= 21; i++) {
            pp[17][i] = row[i];
            dpp[i][17] = dinvrow[i];
        }
        wmap[17] = 17;
/*
Constraint 18 (prescribed motion)
*/
        if (pres[18]  !=  0.) {
            dtau[18] = 1.;
        } else {
            dtau[18] = 0.;
        }
        dfs[18] = dtau[18];
        dfs[0] = 0.;
        dfs[1] = 0.;
        dfs[2] = 0.;
        dfs[3] = 0.;
        dfs[4] = 0.;
        dfs[5] = 0.;
        dfs[6] = 0.;
        dfs[7] = 0.;
        dfs[8] = 0.;
        dfs[9] = 0.;
        dfs[10] = 0.;
        dfs[11] = 0.;
        dfs[12] = 0.;
        dfs[13] = 0.;
        dfs[14] = 0.;
        dfs[15] = 0.;
        dfs[16] = 0.;
        dfs[17] = 0.;
        dfs[19] = 0.;
        dfs[20] = 0.;
        dfs[21] = 0.;
        allegro_air_ldubsl(22,22,mmap,mlo,dfs,row);
        allegro_air_ldubsd(22,22,mmap,mdi,row,dinvrow);
        for (i = 0; i <= 21; i++) {
            pp[18][i] = row[i];
            dpp[i][18] = dinvrow[i];
        }
        wmap[18] = 18;
/*
Constraint 19 (prescribed motion)
*/
        if (pres[19]  !=  0.) {
            dtau[19] = 1.;
        } else {
            dtau[19] = 0.;
        }
        dfs[19] = dtau[19];
        dfs[0] = 0.;
        dfs[1] = 0.;
        dfs[2] = 0.;
        dfs[3] = 0.;
        dfs[4] = 0.;
        dfs[5] = 0.;
        dfs[6] = 0.;
        dfs[7] = 0.;
        dfs[8] = 0.;
        dfs[9] = 0.;
        dfs[10] = 0.;
        dfs[11] = 0.;
        dfs[12] = 0.;
        dfs[13] = 0.;
        dfs[14] = 0.;
        dfs[15] = 0.;
        dfs[16] = 0.;
        dfs[17] = 0.;
        dfs[18] = 0.;
        dfs[20] = 0.;
        dfs[21] = 0.;
        allegro_air_ldubsl(22,22,mmap,mlo,dfs,row);
        allegro_air_ldubsd(22,22,mmap,mdi,row,dinvrow);
        for (i = 0; i <= 21; i++) {
            pp[19][i] = row[i];
            dpp[i][19] = dinvrow[i];
        }
        wmap[19] = 19;
/*
Constraint 20 (prescribed motion)
*/
        if (pres[20]  !=  0.) {
            dtau[20] = 1.;
        } else {
            dtau[20] = 0.;
        }
        dfs[20] = dtau[20];
        dfs[0] = 0.;
        dfs[1] = 0.;
        dfs[2] = 0.;
        dfs[3] = 0.;
        dfs[4] = 0.;
        dfs[5] = 0.;
        dfs[6] = 0.;
        dfs[7] = 0.;
        dfs[8] = 0.;
        dfs[9] = 0.;
        dfs[10] = 0.;
        dfs[11] = 0.;
        dfs[12] = 0.;
        dfs[13] = 0.;
        dfs[14] = 0.;
        dfs[15] = 0.;
        dfs[16] = 0.;
        dfs[17] = 0.;
        dfs[18] = 0.;
        dfs[19] = 0.;
        dfs[21] = 0.;
        allegro_air_ldubsl(22,22,mmap,mlo,dfs,row);
        allegro_air_ldubsd(22,22,mmap,mdi,row,dinvrow);
        for (i = 0; i <= 21; i++) {
            pp[20][i] = row[i];
            dpp[i][20] = dinvrow[i];
        }
        wmap[20] = 20;
/*
Constraint 21 (prescribed motion)
*/
        if (pres[21]  !=  0.) {
            dtau[21] = 1.;
        } else {
            dtau[21] = 0.;
        }
        dfs[21] = dtau[21];
        dfs[0] = 0.;
        dfs[1] = 0.;
        dfs[2] = 0.;
        dfs[3] = 0.;
        dfs[4] = 0.;
        dfs[5] = 0.;
        dfs[6] = 0.;
        dfs[7] = 0.;
        dfs[8] = 0.;
        dfs[9] = 0.;
        dfs[10] = 0.;
        dfs[11] = 0.;
        dfs[12] = 0.;
        dfs[13] = 0.;
        dfs[14] = 0.;
        dfs[15] = 0.;
        dfs[16] = 0.;
        dfs[17] = 0.;
        dfs[18] = 0.;
        dfs[19] = 0.;
        dfs[20] = 0.;
        allegro_air_ldubsl(22,22,mmap,mlo,dfs,row);
        allegro_air_ldubsd(22,22,mmap,mdi,row,dinvrow);
        for (i = 0; i <= 21; i++) {
            pp[21][i] = row[i];
            dpp[i][21] = dinvrow[i];
        }
        wmap[21] = 21;
/*
Produce constraint coefficient matrix WW
*/
        for (c = 0; c <= 21; c++) {
            for (i = c; i <= 21; i++) {
                sum = 0.;
                for (j = 0; j <= 21; j++) {
                    sum = sum+pp[wmap[c]][j]*dpp[j][wmap[i]];
                }
                ww[wmap[c]][wmap[i]] = sum;
                ww[wmap[i]][wmap[c]] = sum;
            }
        }
/*
Form QR decomposition of WW
*/
        allegro_air_qrdcomp(22,22,22,22,wmap,wmap,ww,qraux,jpvt);
        wwflg = 1;
    }
/*
 Used 0.02 seconds CPU time,
 0 additional bytes of memory.
 Equations contain 5566 adds/subtracts/negates
                   5566 multiplies
                      0 divides
                   7821 assignments
*/
}

void allegro_air_xudot0(int routine,
    double oudot0[22])
{
/*
Compute unconstrained equations
*/
    int i;

    allegro_air_lhs(routine);
/*
Solve equations ignoring constraints
*/
    allegro_air_fs0();
    allegro_air_ldubslv(22,22,mmap,works,mlo,mdi,fs,udot);
    for (i = 0; i <= 21; i++) {
        oudot0[i] = udot[i];
    }
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     22 assignments
*/
}

void allegro_air_udot0(double oudot0[22])
{

    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(66,23);
        return;
    }
    allegro_air_xudot0(66,oudot0);
}

void allegro_air_setudot(double iudot[22])
{
/*
Assign udots and advance to stage Dynamics Ready
*/
    int i;

    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(68,23);
        return;
    }
    for (i = 0; i <= 21; i++) {
        udot[i] = iudot[i];
    }
    allegro_air_rhs();
}

void allegro_air_xudotm(int routine,
    double imult[22],
    double oudotm[22])
{
/*
Compute udots due only to multipliers
*/
    int i;

    allegro_air_lhs(routine);
    allegro_air_mfrc(imult);
    allegro_air_fsmult();
    allegro_air_ldubslv(22,22,mmap,works,mlo,mdi,fs,udot);
    for (i = 0; i <= 21; i++) {
        oudotm[i] = udot[i];
    }
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain    0 adds/subtracts/negates
                      0 multiplies
                      0 divides
                     22 assignments
*/
}

void allegro_air_udotm(double imult[22],
    double oudotm[22])
{

    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(67,23);
        return;
    }
    allegro_air_xudotm(67,imult,oudotm);
}

void allegro_air_deriv(double oqdot[23],
    double oudot[22])
{
/*
This is the derivative section for a 21-body ground-based
system with 22 hinge degree(s) of freedom.
22 of the degrees of freedom may follow prescribed motion.
There are 22 constraints.
*/
    double workr[22],bb[22],b0[22],v0[22],p0[22];
    int iwork[22];
    int i,j;
    double udot0[22],udot1[22];

    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(17,23);
        return;
    }
    if (stabvelq == 1) {
        allegro_air_seterr(17,32);
    }
    if (stabposq == 1) {
        allegro_air_seterr(17,33);
    }
    wsiz = 22;
/*
Compute unconstrained equations
*/
    allegro_air_xudot0(17,udot0);
    allegro_air_rhs();
    allegro_air_aerr(b0);
    if (stabvel  !=  0.) {
        allegro_air_verr(v0);
    }
    if (stabpos  !=  0.) {
        allegro_air_perr(p0);
    }
/*
Stabilize constraints using Baumgarte's method
*/
    for (i = 0; i <= 21; i++) {
        bb[i] = -b0[i];
    }
    if (stabvel  !=  0.) {
        for (i = 0; i <= 21; i++) {
            bb[i] = bb[i]-stabvel*v0[i];
        }
    }
    if (stabpos  !=  0.) {
        for (i = 0; i <= 21; i++) {
            bb[i] = bb[i]-stabpos*p0[i];
        }
    }
/*
Compute and decompose constraint matrix WW
*/
    allegro_air_doww(17);
/*
Numerically solve for constraint multipliers
*/
    allegro_air_qrbslv(22,22,22,22,wmap,wmap,1e-13,workr,iwork,
      ww,qraux,jpvt,bb,mult,&wrank);
    for (i = 0; i <= 21; i++) {
        multmap[i] = 0;
    }
    for (i = 0; i < wrank; i++) {
        multmap[jpvt[i]] = 1;
    }
    j = 0;
    for (i = 0; i <= 21; i++) {
        if (multmap[i] != 0) {
            multmap[j] = wmap[i];
            j = j+1;
        }
    }
/*
Compute final udots
*/
    allegro_air_xudotm(17,mult,udot1);
    for (i = 0; i <= 21; i++) {
        udot[i] = udot0[i]+udot1[i];
    }
    allegro_air_rhs();
    for (i = 0; i <= 22; i++) {
        oqdot[i] = qdot[i];
    }
    for (i = 0; i <= 21; i++) {
        oudot[i] = udot[i];
    }
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain   88 adds/subtracts/negates
                     44 multiplies
                      0 divides
                    133 assignments
*/
}
/*
Compute residuals for use with DAE integrator
*/

void allegro_air_resid(double eqdot[23],
    double eudot[22],
    double emults[22],
    double resid[67])
{
    int i;
    double uderrs[22],p0[22];

    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(16,23);
        return;
    }
    if (stabposq == 1) {
        allegro_air_seterr(16,33);
    }
    allegro_air_fulltrq(eudot,emults,uderrs);
    for (i = 0; i < 23; i++) {
        resid[i] = eqdot[i]-qdot[i];
    }
    for (i = 0; i < 22; i++) {
        resid[23+i] = uderrs[i];
    }
    allegro_air_verr(&resid[45]);
    if (stabpos  !=  0.) {
        allegro_air_perr(p0);
        for (i = 0; i < 22; i++) {
            resid[45+i] = resid[45+i]+stabpos*p0[i];
        }
    }
    for (i = 0; i < 22; i++) {
        udot[i] = eudot[i];
    }
    for (i = 0; i < 22; i++) {
        mult[i] = emults[i];
    }
    allegro_air_rhs();
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain   45 adds/subtracts/negates
                     22 multiplies
                      0 divides
                    111 assignments
*/
}

void allegro_air_mult(double omults[22],
    int *owrank,
    int omultmap[22])
{
    int i;

    if (roustate != 3) {
        allegro_air_seterr(34,24);
        return;
    }
    for (i = 0; i < 22; i++) {
        omults[i] = mult[i];
        if (i <= wrank-1) {
            omultmap[i] = multmap[i];
        } else {
            omultmap[i] = -1;
        }
    }
    *owrank = wrank;
}

void allegro_air_reac(double force[21][3],
    double torque[21][3])
{
/*
Generated 15-Apr-2019 14:28:10 by SD/FAST, Kane's formulation
(sdfast B.2.8 #30123) on machine ID unknown
Copyright (c) 1990-1997 Symbolic Dynamics, Inc.
Copyright (c) 1990-1997 Parametric Technology Corp.
RESTRICTED RIGHTS LEGEND: Use, duplication, or disclosure by the U.S.
Government is subject to restrictions as set forth in subparagraph
(c)(1)(ii) of the Rights in Technical Data and Computer Software
clause at DFARS 52.227-7013 and similar clauses in the FAR and NASA
FAR Supplement.  Symbolic Dynamics, Inc., Mountain View, CA 94041
*/

    if (roustate != 3) {
        allegro_air_seterr(31,24);
        return;
    }
/*
Compute reaction forces for non-weld tree joints
*/
    ffk[9][0] = (ufk[4][0]+ufk[5][0]);
    ffk[9][1] = (ufk[4][1]+ufk[5][1]);
    ffk[9][2] = (ufk[4][2]+ufk[5][2]);
    ttk[9][0] = ((utk[4][0]+((rcom[4][1]*ufk[4][2])-(rcom[4][2]*ufk[4][1])))+(
      utk[5][0]+((rcom[5][1]*ufk[5][2])-(rcom[5][2]*ufk[5][1]))));
    ttk[9][1] = ((utk[4][1]+((rcom[4][2]*ufk[4][0])-(rcom[4][0]*ufk[4][2])))+(
      utk[5][1]+((rcom[5][2]*ufk[5][0])-(rcom[5][0]*ufk[5][2]))));
    ttk[9][2] = ((utk[4][2]+((rcom[4][0]*ufk[4][1])-(rcom[4][1]*ufk[4][0])))+(
      utk[5][2]+((rcom[5][0]*ufk[5][1])-(rcom[5][1]*ufk[5][0]))));
    ffk[13][0] = (ufk[9][0]+ufk[10][0]);
    ffk[13][1] = (ufk[9][1]+ufk[10][1]);
    ffk[13][2] = (ufk[9][2]+ufk[10][2]);
    ttk[13][0] = ((utk[9][0]+((rcom[9][1]*ufk[9][2])-(rcom[9][2]*ufk[9][1])))+(
      utk[10][0]+((rcom[10][1]*ufk[10][2])-(rcom[10][2]*ufk[10][1]))));
    ttk[13][1] = ((utk[9][1]+((rcom[9][2]*ufk[9][0])-(rcom[9][0]*ufk[9][2])))+(
      utk[10][1]+((rcom[10][2]*ufk[10][0])-(rcom[10][0]*ufk[10][2]))));
    ttk[13][2] = ((utk[9][2]+((rcom[9][0]*ufk[9][1])-(rcom[9][1]*ufk[9][0])))+(
      utk[10][2]+((rcom[10][0]*ufk[10][1])-(rcom[10][1]*ufk[10][0]))));
    ffk[17][0] = (ufk[14][0]+ufk[15][0]);
    ffk[17][1] = (ufk[14][1]+ufk[15][1]);
    ffk[17][2] = (ufk[14][2]+ufk[15][2]);
    ttk[17][0] = ((utk[14][0]+((rcom[14][1]*ufk[14][2])-(rcom[14][2]*ufk[14][1])
      ))+(utk[15][0]+((rcom[15][1]*ufk[15][2])-(rcom[15][2]*ufk[15][1]))));
    ttk[17][1] = ((utk[14][1]+((rcom[14][2]*ufk[14][0])-(rcom[14][0]*ufk[14][2])
      ))+(utk[15][1]+((rcom[15][2]*ufk[15][0])-(rcom[15][0]*ufk[15][2]))));
    ttk[17][2] = ((utk[14][2]+((rcom[14][0]*ufk[14][1])-(rcom[14][1]*ufk[14][0])
      ))+(utk[15][2]+((rcom[15][0]*ufk[15][1])-(rcom[15][1]*ufk[15][0]))));
    ffk[21][0] = (ufk[19][0]+ufk[20][0]);
    ffk[21][1] = (ufk[19][1]+ufk[20][1]);
    ffk[21][2] = (ufk[19][2]+ufk[20][2]);
    ttk[21][0] = ((utk[19][0]+((rcom[19][1]*ufk[19][2])-(rcom[19][2]*ufk[19][1])
      ))+(utk[20][0]+((rcom[20][1]*ufk[20][2])-(rcom[20][2]*ufk[20][1]))));
    ttk[21][1] = ((utk[19][1]+((rcom[19][2]*ufk[19][0])-(rcom[19][0]*ufk[19][2])
      ))+(utk[20][1]+((rcom[20][2]*ufk[20][0])-(rcom[20][0]*ufk[20][2]))));
    ttk[21][2] = ((utk[19][2]+((rcom[19][0]*ufk[19][1])-(rcom[19][1]*ufk[19][0])
      ))+(utk[20][2]+((rcom[20][0]*ufk[20][1])-(rcom[20][1]*ufk[20][0]))));
    fc[21][0] = ((psmk[21]*(AnkAtk[21][0]-gk[21][0]))-ffk[21][0]);
    fc[21][1] = ((psmk[21]*(AnkAtk[21][1]-gk[21][1]))-ffk[21][1]);
    fc[21][2] = ((psmk[21]*(AnkAtk[21][2]-gk[21][2]))-ffk[21][2]);
    tc[21][0] = ((WkIkWk[21][0]+((onk[21][2]*psik[21][0][2])+((onk[21][0]*
      psik[21][0][0])+(onk[21][1]*psik[21][0][1]))))-(ttk[21][0]+((fc[21][2]*
      psrk[21][1])-(fc[21][1]*psrk[21][2]))));
    tc[21][1] = ((WkIkWk[21][1]+((onk[21][2]*psik[21][1][2])+((onk[21][0]*
      psik[21][1][0])+(onk[21][1]*psik[21][1][1]))))-(ttk[21][1]+((fc[21][0]*
      psrk[21][2])-(fc[21][2]*psrk[21][0]))));
    tc[21][2] = ((WkIkWk[21][2]+((onk[21][2]*psik[21][2][2])+((onk[21][0]*
      psik[21][2][0])+(onk[21][1]*psik[21][2][1]))))-(ttk[21][2]+((fc[21][1]*
      psrk[21][0])-(fc[21][0]*psrk[21][1]))));
    fccikt[21][0] = ((Cik[21][0][2]*fc[21][2])+((Cik[21][0][0]*fc[21][0])+(
      Cik[21][0][1]*fc[21][1])));
    fccikt[21][1] = ((Cik[21][1][2]*fc[21][2])+((Cik[21][1][0]*fc[21][0])+(
      Cik[21][1][1]*fc[21][1])));
    fccikt[21][2] = ((Cik[21][2][2]*fc[21][2])+((Cik[21][2][0]*fc[21][0])+(
      Cik[21][2][1]*fc[21][1])));
    ffk[20][0] = (ufk[18][0]-fccikt[21][0]);
    ffk[20][1] = (ufk[18][1]-fccikt[21][1]);
    ffk[20][2] = (ufk[18][2]-fccikt[21][2]);
    ttk[20][0] = (utk[18][0]-(((Cik[21][0][2]*tc[21][2])+((Cik[21][0][0]*
      tc[21][0])+(Cik[21][0][1]*tc[21][1])))+((fccikt[21][2]*ri[19][1])-(
      fccikt[21][1]*ri[19][2]))));
    ttk[20][1] = (utk[18][1]-(((Cik[21][1][2]*tc[21][2])+((Cik[21][1][0]*
      tc[21][0])+(Cik[21][1][1]*tc[21][1])))+((fccikt[21][0]*ri[19][2])-(
      fccikt[21][2]*ri[19][0]))));
    ttk[20][2] = (utk[18][2]-(((Cik[21][2][2]*tc[21][2])+((Cik[21][2][0]*
      tc[21][0])+(Cik[21][2][1]*tc[21][1])))+((fccikt[21][1]*ri[19][0])-(
      fccikt[21][0]*ri[19][1]))));
    fc[20][0] = ((mk[18]*(AnkAtk[20][0]-gk[20][0]))-ffk[20][0]);
    fc[20][1] = ((mk[18]*(AnkAtk[20][1]-gk[20][1]))-ffk[20][1]);
    fc[20][2] = ((mk[18]*(AnkAtk[20][2]-gk[20][2]))-ffk[20][2]);
    tc[20][0] = ((WkIkWk[20][0]+((ik[18][0][2]*onk[20][2])+((ik[18][0][0]*
      onk[20][0])+(ik[18][0][1]*onk[20][1]))))-(ttk[20][0]+((fc[20][2]*rk[18][1]
      )-(fc[20][1]*rk[18][2]))));
    tc[20][1] = ((WkIkWk[20][1]+((ik[18][1][2]*onk[20][2])+((ik[18][1][0]*
      onk[20][0])+(ik[18][1][1]*onk[20][1]))))-(ttk[20][1]+((fc[20][0]*rk[18][2]
      )-(fc[20][2]*rk[18][0]))));
    tc[20][2] = ((WkIkWk[20][2]+((ik[18][2][2]*onk[20][2])+((ik[18][2][0]*
      onk[20][0])+(ik[18][2][1]*onk[20][1]))))-(ttk[20][2]+((fc[20][1]*rk[18][0]
      )-(fc[20][0]*rk[18][1]))));
    fccikt[20][0] = ((Cik[20][0][2]*fc[20][2])+((Cik[20][0][0]*fc[20][0])+(
      Cik[20][0][1]*fc[20][1])));
    fccikt[20][1] = ((Cik[20][1][2]*fc[20][2])+((Cik[20][1][0]*fc[20][0])+(
      Cik[20][1][1]*fc[20][1])));
    fccikt[20][2] = ((Cik[20][2][2]*fc[20][2])+((Cik[20][2][0]*fc[20][0])+(
      Cik[20][2][1]*fc[20][1])));
    ffk[19][0] = (ufk[17][0]-fccikt[20][0]);
    ffk[19][1] = (ufk[17][1]-fccikt[20][1]);
    ffk[19][2] = (ufk[17][2]-fccikt[20][2]);
    ttk[19][0] = (utk[17][0]-(((Cik[20][0][2]*tc[20][2])+((Cik[20][0][0]*
      tc[20][0])+(Cik[20][0][1]*tc[20][1])))+((fccikt[20][2]*ri[18][1])-(
      fccikt[20][1]*ri[18][2]))));
    ttk[19][1] = (utk[17][1]-(((Cik[20][1][2]*tc[20][2])+((Cik[20][1][0]*
      tc[20][0])+(Cik[20][1][1]*tc[20][1])))+((fccikt[20][0]*ri[18][2])-(
      fccikt[20][2]*ri[18][0]))));
    ttk[19][2] = (utk[17][2]-(((Cik[20][2][2]*tc[20][2])+((Cik[20][2][0]*
      tc[20][0])+(Cik[20][2][1]*tc[20][1])))+((fccikt[20][1]*ri[18][0])-(
      fccikt[20][0]*ri[18][1]))));
    fc[19][0] = ((mk[17]*(AnkAtk[19][0]-gk[19][0]))-ffk[19][0]);
    fc[19][1] = ((mk[17]*(AnkAtk[19][1]-gk[19][1]))-ffk[19][1]);
    fc[19][2] = ((mk[17]*(AnkAtk[19][2]-gk[19][2]))-ffk[19][2]);
    tc[19][0] = ((WkIkWk[19][0]+((ik[17][0][2]*onk[19][2])+((ik[17][0][0]*
      onk[19][0])+(ik[17][0][1]*onk[19][1]))))-(ttk[19][0]+((fc[19][2]*rk[17][1]
      )-(fc[19][1]*rk[17][2]))));
    tc[19][1] = ((WkIkWk[19][1]+((ik[17][1][2]*onk[19][2])+((ik[17][1][0]*
      onk[19][0])+(ik[17][1][1]*onk[19][1]))))-(ttk[19][1]+((fc[19][0]*rk[17][2]
      )-(fc[19][2]*rk[17][0]))));
    tc[19][2] = ((WkIkWk[19][2]+((ik[17][2][2]*onk[19][2])+((ik[17][2][0]*
      onk[19][0])+(ik[17][2][1]*onk[19][1]))))-(ttk[19][2]+((fc[19][1]*rk[17][0]
      )-(fc[19][0]*rk[17][1]))));
    fccikt[19][0] = ((Cik[19][0][2]*fc[19][2])+((Cik[19][0][0]*fc[19][0])+(
      Cik[19][0][1]*fc[19][1])));
    fccikt[19][1] = ((Cik[19][1][2]*fc[19][2])+((Cik[19][1][0]*fc[19][0])+(
      Cik[19][1][1]*fc[19][1])));
    fccikt[19][2] = ((Cik[19][2][2]*fc[19][2])+((Cik[19][2][0]*fc[19][0])+(
      Cik[19][2][1]*fc[19][1])));
    ffk[18][0] = (ufk[16][0]-fccikt[19][0]);
    ffk[18][1] = (ufk[16][1]-fccikt[19][1]);
    ffk[18][2] = (ufk[16][2]-fccikt[19][2]);
    ttk[18][0] = (utk[16][0]-(((Cik[19][0][2]*tc[19][2])+((Cik[19][0][0]*
      tc[19][0])+(Cik[19][0][1]*tc[19][1])))+((fccikt[19][2]*ri[17][1])-(
      fccikt[19][1]*ri[17][2]))));
    ttk[18][1] = (utk[16][1]-(((Cik[19][1][2]*tc[19][2])+((Cik[19][1][0]*
      tc[19][0])+(Cik[19][1][1]*tc[19][1])))+((fccikt[19][0]*ri[17][2])-(
      fccikt[19][2]*ri[17][0]))));
    ttk[18][2] = (utk[16][2]-(((Cik[19][2][2]*tc[19][2])+((Cik[19][2][0]*
      tc[19][0])+(Cik[19][2][1]*tc[19][1])))+((fccikt[19][1]*ri[17][0])-(
      fccikt[19][0]*ri[17][1]))));
    fc[18][0] = ((mk[16]*(AnkAtk[18][0]-gk[18][0]))-ffk[18][0]);
    fc[18][1] = ((mk[16]*(AnkAtk[18][1]-gk[18][1]))-ffk[18][1]);
    fc[18][2] = ((mk[16]*(AnkAtk[18][2]-gk[18][2]))-ffk[18][2]);
    tc[18][0] = ((WkIkWk[18][0]+((ik[16][0][2]*onk[18][2])+((ik[16][0][0]*
      onk[18][0])+(ik[16][0][1]*onk[18][1]))))-(ttk[18][0]+((fc[18][2]*rk[16][1]
      )-(fc[18][1]*rk[16][2]))));
    tc[18][1] = ((WkIkWk[18][1]+((ik[16][1][2]*onk[18][2])+((ik[16][1][0]*
      onk[18][0])+(ik[16][1][1]*onk[18][1]))))-(ttk[18][1]+((fc[18][0]*rk[16][2]
      )-(fc[18][2]*rk[16][0]))));
    tc[18][2] = ((WkIkWk[18][2]+((ik[16][2][2]*onk[18][2])+((ik[16][2][0]*
      onk[18][0])+(ik[16][2][1]*onk[18][1]))))-(ttk[18][2]+((fc[18][1]*rk[16][0]
      )-(fc[18][0]*rk[16][1]))));
    fccikt[18][0] = ((Cik[18][0][2]*fc[18][2])+((Cik[18][0][0]*fc[18][0])+(
      Cik[18][0][1]*fc[18][1])));
    fccikt[18][1] = ((Cik[18][1][2]*fc[18][2])+((Cik[18][1][0]*fc[18][0])+(
      Cik[18][1][1]*fc[18][1])));
    fccikt[18][2] = ((Cik[18][2][2]*fc[18][2])+((Cik[18][2][0]*fc[18][0])+(
      Cik[18][2][1]*fc[18][1])));
    ffk[5][0] = (ufk[0][0]-fccikt[18][0]);
    ffk[5][1] = (ufk[0][1]-fccikt[18][1]);
    ffk[5][2] = (ufk[0][2]-fccikt[18][2]);
    ttk[5][0] = (utk[0][0]-(((Cik[18][0][2]*tc[18][2])+((Cik[18][0][0]*tc[18][0]
      )+(Cik[18][0][1]*tc[18][1])))+((fccikt[18][2]*ri[16][1])-(fccikt[18][1]*
      ri[16][2]))));
    ttk[5][1] = (utk[0][1]-(((Cik[18][1][2]*tc[18][2])+((Cik[18][1][0]*tc[18][0]
      )+(Cik[18][1][1]*tc[18][1])))+((fccikt[18][0]*ri[16][2])-(fccikt[18][2]*
      ri[16][0]))));
    ttk[5][2] = (utk[0][2]-(((Cik[18][2][2]*tc[18][2])+((Cik[18][2][0]*tc[18][0]
      )+(Cik[18][2][1]*tc[18][1])))+((fccikt[18][1]*ri[16][0])-(fccikt[18][0]*
      ri[16][1]))));
    fc[17][0] = ((psmk[17]*(AnkAtk[17][0]-gk[17][0]))-ffk[17][0]);
    fc[17][1] = ((psmk[17]*(AnkAtk[17][1]-gk[17][1]))-ffk[17][1]);
    fc[17][2] = ((psmk[17]*(AnkAtk[17][2]-gk[17][2]))-ffk[17][2]);
    tc[17][0] = ((WkIkWk[17][0]+((onk[17][2]*psik[17][0][2])+((onk[17][0]*
      psik[17][0][0])+(onk[17][1]*psik[17][0][1]))))-(ttk[17][0]+((fc[17][2]*
      psrk[17][1])-(fc[17][1]*psrk[17][2]))));
    tc[17][1] = ((WkIkWk[17][1]+((onk[17][2]*psik[17][1][2])+((onk[17][0]*
      psik[17][1][0])+(onk[17][1]*psik[17][1][1]))))-(ttk[17][1]+((fc[17][0]*
      psrk[17][2])-(fc[17][2]*psrk[17][0]))));
    tc[17][2] = ((WkIkWk[17][2]+((onk[17][2]*psik[17][2][2])+((onk[17][0]*
      psik[17][2][0])+(onk[17][1]*psik[17][2][1]))))-(ttk[17][2]+((fc[17][1]*
      psrk[17][0])-(fc[17][0]*psrk[17][1]))));
    fccikt[17][0] = ((Cik[17][0][2]*fc[17][2])+((Cik[17][0][0]*fc[17][0])+(
      Cik[17][0][1]*fc[17][1])));
    fccikt[17][1] = ((Cik[17][1][2]*fc[17][2])+((Cik[17][1][0]*fc[17][0])+(
      Cik[17][1][1]*fc[17][1])));
    fccikt[17][2] = ((Cik[17][2][2]*fc[17][2])+((Cik[17][2][0]*fc[17][0])+(
      Cik[17][2][1]*fc[17][1])));
    ffk[16][0] = (ufk[13][0]-fccikt[17][0]);
    ffk[16][1] = (ufk[13][1]-fccikt[17][1]);
    ffk[16][2] = (ufk[13][2]-fccikt[17][2]);
    ttk[16][0] = (utk[13][0]-(((Cik[17][0][2]*tc[17][2])+((Cik[17][0][0]*
      tc[17][0])+(Cik[17][0][1]*tc[17][1])))+((fccikt[17][2]*ri[14][1])-(
      fccikt[17][1]*ri[14][2]))));
    ttk[16][1] = (utk[13][1]-(((Cik[17][1][2]*tc[17][2])+((Cik[17][1][0]*
      tc[17][0])+(Cik[17][1][1]*tc[17][1])))+((fccikt[17][0]*ri[14][2])-(
      fccikt[17][2]*ri[14][0]))));
    ttk[16][2] = (utk[13][2]-(((Cik[17][2][2]*tc[17][2])+((Cik[17][2][0]*
      tc[17][0])+(Cik[17][2][1]*tc[17][1])))+((fccikt[17][1]*ri[14][0])-(
      fccikt[17][0]*ri[14][1]))));
    fc[16][0] = ((mk[13]*(AnkAtk[16][0]-gk[16][0]))-ffk[16][0]);
    fc[16][1] = ((mk[13]*(AnkAtk[16][1]-gk[16][1]))-ffk[16][1]);
    fc[16][2] = ((mk[13]*(AnkAtk[16][2]-gk[16][2]))-ffk[16][2]);
    tc[16][0] = ((WkIkWk[16][0]+((ik[13][0][2]*onk[16][2])+((ik[13][0][0]*
      onk[16][0])+(ik[13][0][1]*onk[16][1]))))-(ttk[16][0]+((fc[16][2]*rk[13][1]
      )-(fc[16][1]*rk[13][2]))));
    tc[16][1] = ((WkIkWk[16][1]+((ik[13][1][2]*onk[16][2])+((ik[13][1][0]*
      onk[16][0])+(ik[13][1][1]*onk[16][1]))))-(ttk[16][1]+((fc[16][0]*rk[13][2]
      )-(fc[16][2]*rk[13][0]))));
    tc[16][2] = ((WkIkWk[16][2]+((ik[13][2][2]*onk[16][2])+((ik[13][2][0]*
      onk[16][0])+(ik[13][2][1]*onk[16][1]))))-(ttk[16][2]+((fc[16][1]*rk[13][0]
      )-(fc[16][0]*rk[13][1]))));
    fccikt[16][0] = ((Cik[16][0][2]*fc[16][2])+((Cik[16][0][0]*fc[16][0])+(
      Cik[16][0][1]*fc[16][1])));
    fccikt[16][1] = ((Cik[16][1][2]*fc[16][2])+((Cik[16][1][0]*fc[16][0])+(
      Cik[16][1][1]*fc[16][1])));
    fccikt[16][2] = ((Cik[16][2][2]*fc[16][2])+((Cik[16][2][0]*fc[16][0])+(
      Cik[16][2][1]*fc[16][1])));
    ffk[15][0] = (ufk[12][0]-fccikt[16][0]);
    ffk[15][1] = (ufk[12][1]-fccikt[16][1]);
    ffk[15][2] = (ufk[12][2]-fccikt[16][2]);
    ttk[15][0] = (utk[12][0]-(((Cik[16][0][2]*tc[16][2])+((Cik[16][0][0]*
      tc[16][0])+(Cik[16][0][1]*tc[16][1])))+((fccikt[16][2]*ri[13][1])-(
      fccikt[16][1]*ri[13][2]))));
    ttk[15][1] = (utk[12][1]-(((Cik[16][1][2]*tc[16][2])+((Cik[16][1][0]*
      tc[16][0])+(Cik[16][1][1]*tc[16][1])))+((fccikt[16][0]*ri[13][2])-(
      fccikt[16][2]*ri[13][0]))));
    ttk[15][2] = (utk[12][2]-(((Cik[16][2][2]*tc[16][2])+((Cik[16][2][0]*
      tc[16][0])+(Cik[16][2][1]*tc[16][1])))+((fccikt[16][1]*ri[13][0])-(
      fccikt[16][0]*ri[13][1]))));
    fc[15][0] = ((mk[12]*(AnkAtk[15][0]-gk[15][0]))-ffk[15][0]);
    fc[15][1] = ((mk[12]*(AnkAtk[15][1]-gk[15][1]))-ffk[15][1]);
    fc[15][2] = ((mk[12]*(AnkAtk[15][2]-gk[15][2]))-ffk[15][2]);
    tc[15][0] = ((WkIkWk[15][0]+((ik[12][0][2]*onk[15][2])+((ik[12][0][0]*
      onk[15][0])+(ik[12][0][1]*onk[15][1]))))-(ttk[15][0]+((fc[15][2]*rk[12][1]
      )-(fc[15][1]*rk[12][2]))));
    tc[15][1] = ((WkIkWk[15][1]+((ik[12][1][2]*onk[15][2])+((ik[12][1][0]*
      onk[15][0])+(ik[12][1][1]*onk[15][1]))))-(ttk[15][1]+((fc[15][0]*rk[12][2]
      )-(fc[15][2]*rk[12][0]))));
    tc[15][2] = ((WkIkWk[15][2]+((ik[12][2][2]*onk[15][2])+((ik[12][2][0]*
      onk[15][0])+(ik[12][2][1]*onk[15][1]))))-(ttk[15][2]+((fc[15][1]*rk[12][0]
      )-(fc[15][0]*rk[12][1]))));
    fccikt[15][0] = ((Cik[15][0][2]*fc[15][2])+((Cik[15][0][0]*fc[15][0])+(
      Cik[15][0][1]*fc[15][1])));
    fccikt[15][1] = ((Cik[15][1][2]*fc[15][2])+((Cik[15][1][0]*fc[15][0])+(
      Cik[15][1][1]*fc[15][1])));
    fccikt[15][2] = ((Cik[15][2][2]*fc[15][2])+((Cik[15][2][0]*fc[15][0])+(
      Cik[15][2][1]*fc[15][1])));
    ffk[14][0] = (ufk[11][0]-fccikt[15][0]);
    ffk[14][1] = (ufk[11][1]-fccikt[15][1]);
    ffk[14][2] = (ufk[11][2]-fccikt[15][2]);
    ttk[14][0] = (utk[11][0]-(((Cik[15][0][2]*tc[15][2])+((Cik[15][0][0]*
      tc[15][0])+(Cik[15][0][1]*tc[15][1])))+((fccikt[15][2]*ri[12][1])-(
      fccikt[15][1]*ri[12][2]))));
    ttk[14][1] = (utk[11][1]-(((Cik[15][1][2]*tc[15][2])+((Cik[15][1][0]*
      tc[15][0])+(Cik[15][1][1]*tc[15][1])))+((fccikt[15][0]*ri[12][2])-(
      fccikt[15][2]*ri[12][0]))));
    ttk[14][2] = (utk[11][2]-(((Cik[15][2][2]*tc[15][2])+((Cik[15][2][0]*
      tc[15][0])+(Cik[15][2][1]*tc[15][1])))+((fccikt[15][1]*ri[12][0])-(
      fccikt[15][0]*ri[12][1]))));
    fc[14][0] = ((mk[11]*(AnkAtk[14][0]-gk[14][0]))-ffk[14][0]);
    fc[14][1] = ((mk[11]*(AnkAtk[14][1]-gk[14][1]))-ffk[14][1]);
    fc[14][2] = ((mk[11]*(AnkAtk[14][2]-gk[14][2]))-ffk[14][2]);
    tc[14][0] = ((WkIkWk[14][0]+((ik[11][0][2]*onk[14][2])+((ik[11][0][0]*
      onk[14][0])+(ik[11][0][1]*onk[14][1]))))-(ttk[14][0]+((fc[14][2]*rk[11][1]
      )-(fc[14][1]*rk[11][2]))));
    tc[14][1] = ((WkIkWk[14][1]+((ik[11][1][2]*onk[14][2])+((ik[11][1][0]*
      onk[14][0])+(ik[11][1][1]*onk[14][1]))))-(ttk[14][1]+((fc[14][0]*rk[11][2]
      )-(fc[14][2]*rk[11][0]))));
    tc[14][2] = ((WkIkWk[14][2]+((ik[11][2][2]*onk[14][2])+((ik[11][2][0]*
      onk[14][0])+(ik[11][2][1]*onk[14][1]))))-(ttk[14][2]+((fc[14][1]*rk[11][0]
      )-(fc[14][0]*rk[11][1]))));
    fccikt[14][0] = ((Cik[14][0][2]*fc[14][2])+((Cik[14][0][0]*fc[14][0])+(
      Cik[14][0][1]*fc[14][1])));
    fccikt[14][1] = ((Cik[14][1][2]*fc[14][2])+((Cik[14][1][0]*fc[14][0])+(
      Cik[14][1][1]*fc[14][1])));
    fccikt[14][2] = ((Cik[14][2][2]*fc[14][2])+((Cik[14][2][0]*fc[14][0])+(
      Cik[14][2][1]*fc[14][1])));
    ffk[5][0] = (ffk[5][0]-fccikt[14][0]);
    ffk[5][1] = (ffk[5][1]-fccikt[14][1]);
    ffk[5][2] = (ffk[5][2]-fccikt[14][2]);
    ttk[5][0] = (ttk[5][0]-(((Cik[14][0][2]*tc[14][2])+((Cik[14][0][0]*tc[14][0]
      )+(Cik[14][0][1]*tc[14][1])))+((fccikt[14][2]*ri[11][1])-(fccikt[14][1]*
      ri[11][2]))));
    ttk[5][1] = (ttk[5][1]-(((Cik[14][1][2]*tc[14][2])+((Cik[14][1][0]*tc[14][0]
      )+(Cik[14][1][1]*tc[14][1])))+((fccikt[14][0]*ri[11][2])-(fccikt[14][2]*
      ri[11][0]))));
    ttk[5][2] = (ttk[5][2]-(((Cik[14][2][2]*tc[14][2])+((Cik[14][2][0]*tc[14][0]
      )+(Cik[14][2][1]*tc[14][1])))+((fccikt[14][1]*ri[11][0])-(fccikt[14][0]*
      ri[11][1]))));
    fc[13][0] = ((psmk[13]*(AnkAtk[13][0]-gk[13][0]))-ffk[13][0]);
    fc[13][1] = ((psmk[13]*(AnkAtk[13][1]-gk[13][1]))-ffk[13][1]);
    fc[13][2] = ((psmk[13]*(AnkAtk[13][2]-gk[13][2]))-ffk[13][2]);
    tc[13][0] = ((WkIkWk[13][0]+((onk[13][2]*psik[13][0][2])+((onk[13][0]*
      psik[13][0][0])+(onk[13][1]*psik[13][0][1]))))-(ttk[13][0]+((fc[13][2]*
      psrk[13][1])-(fc[13][1]*psrk[13][2]))));
    tc[13][1] = ((WkIkWk[13][1]+((onk[13][2]*psik[13][1][2])+((onk[13][0]*
      psik[13][1][0])+(onk[13][1]*psik[13][1][1]))))-(ttk[13][1]+((fc[13][0]*
      psrk[13][2])-(fc[13][2]*psrk[13][0]))));
    tc[13][2] = ((WkIkWk[13][2]+((onk[13][2]*psik[13][2][2])+((onk[13][0]*
      psik[13][2][0])+(onk[13][1]*psik[13][2][1]))))-(ttk[13][2]+((fc[13][1]*
      psrk[13][0])-(fc[13][0]*psrk[13][1]))));
    fccikt[13][0] = ((Cik[13][0][2]*fc[13][2])+((Cik[13][0][0]*fc[13][0])+(
      Cik[13][0][1]*fc[13][1])));
    fccikt[13][1] = ((Cik[13][1][2]*fc[13][2])+((Cik[13][1][0]*fc[13][0])+(
      Cik[13][1][1]*fc[13][1])));
    fccikt[13][2] = ((Cik[13][2][2]*fc[13][2])+((Cik[13][2][0]*fc[13][0])+(
      Cik[13][2][1]*fc[13][1])));
    ffk[12][0] = (ufk[8][0]-fccikt[13][0]);
    ffk[12][1] = (ufk[8][1]-fccikt[13][1]);
    ffk[12][2] = (ufk[8][2]-fccikt[13][2]);
    ttk[12][0] = (utk[8][0]-(((Cik[13][0][2]*tc[13][2])+((Cik[13][0][0]*
      tc[13][0])+(Cik[13][0][1]*tc[13][1])))+((fccikt[13][2]*ri[9][1])-(
      fccikt[13][1]*ri[9][2]))));
    ttk[12][1] = (utk[8][1]-(((Cik[13][1][2]*tc[13][2])+((Cik[13][1][0]*
      tc[13][0])+(Cik[13][1][1]*tc[13][1])))+((fccikt[13][0]*ri[9][2])-(
      fccikt[13][2]*ri[9][0]))));
    ttk[12][2] = (utk[8][2]-(((Cik[13][2][2]*tc[13][2])+((Cik[13][2][0]*
      tc[13][0])+(Cik[13][2][1]*tc[13][1])))+((fccikt[13][1]*ri[9][0])-(
      fccikt[13][0]*ri[9][1]))));
    fc[12][0] = ((mk[8]*(AnkAtk[12][0]-gk[12][0]))-ffk[12][0]);
    fc[12][1] = ((mk[8]*(AnkAtk[12][1]-gk[12][1]))-ffk[12][1]);
    fc[12][2] = ((mk[8]*(AnkAtk[12][2]-gk[12][2]))-ffk[12][2]);
    tc[12][0] = ((WkIkWk[12][0]+((ik[8][0][2]*onk[12][2])+((ik[8][0][0]*
      onk[12][0])+(ik[8][0][1]*onk[12][1]))))-(ttk[12][0]+((fc[12][2]*rk[8][1])-
      (fc[12][1]*rk[8][2]))));
    tc[12][1] = ((WkIkWk[12][1]+((ik[8][1][2]*onk[12][2])+((ik[8][1][0]*
      onk[12][0])+(ik[8][1][1]*onk[12][1]))))-(ttk[12][1]+((fc[12][0]*rk[8][2])-
      (fc[12][2]*rk[8][0]))));
    tc[12][2] = ((WkIkWk[12][2]+((ik[8][2][2]*onk[12][2])+((ik[8][2][0]*
      onk[12][0])+(ik[8][2][1]*onk[12][1]))))-(ttk[12][2]+((fc[12][1]*rk[8][0])-
      (fc[12][0]*rk[8][1]))));
    fccikt[12][0] = ((Cik[12][0][2]*fc[12][2])+((Cik[12][0][0]*fc[12][0])+(
      Cik[12][0][1]*fc[12][1])));
    fccikt[12][1] = ((Cik[12][1][2]*fc[12][2])+((Cik[12][1][0]*fc[12][0])+(
      Cik[12][1][1]*fc[12][1])));
    fccikt[12][2] = ((Cik[12][2][2]*fc[12][2])+((Cik[12][2][0]*fc[12][0])+(
      Cik[12][2][1]*fc[12][1])));
    ffk[11][0] = (ufk[7][0]-fccikt[12][0]);
    ffk[11][1] = (ufk[7][1]-fccikt[12][1]);
    ffk[11][2] = (ufk[7][2]-fccikt[12][2]);
    ttk[11][0] = (utk[7][0]-(((Cik[12][0][2]*tc[12][2])+((Cik[12][0][0]*
      tc[12][0])+(Cik[12][0][1]*tc[12][1])))+((fccikt[12][2]*ri[8][1])-(
      fccikt[12][1]*ri[8][2]))));
    ttk[11][1] = (utk[7][1]-(((Cik[12][1][2]*tc[12][2])+((Cik[12][1][0]*
      tc[12][0])+(Cik[12][1][1]*tc[12][1])))+((fccikt[12][0]*ri[8][2])-(
      fccikt[12][2]*ri[8][0]))));
    ttk[11][2] = (utk[7][2]-(((Cik[12][2][2]*tc[12][2])+((Cik[12][2][0]*
      tc[12][0])+(Cik[12][2][1]*tc[12][1])))+((fccikt[12][1]*ri[8][0])-(
      fccikt[12][0]*ri[8][1]))));
    fc[11][0] = ((mk[7]*(AnkAtk[11][0]-gk[11][0]))-ffk[11][0]);
    fc[11][1] = ((mk[7]*(AnkAtk[11][1]-gk[11][1]))-ffk[11][1]);
    fc[11][2] = ((mk[7]*(AnkAtk[11][2]-gk[11][2]))-ffk[11][2]);
    tc[11][0] = ((WkIkWk[11][0]+((ik[7][0][2]*onk[11][2])+((ik[7][0][0]*
      onk[11][0])+(ik[7][0][1]*onk[11][1]))))-(ttk[11][0]+((fc[11][2]*rk[7][1])-
      (fc[11][1]*rk[7][2]))));
    tc[11][1] = ((WkIkWk[11][1]+((ik[7][1][2]*onk[11][2])+((ik[7][1][0]*
      onk[11][0])+(ik[7][1][1]*onk[11][1]))))-(ttk[11][1]+((fc[11][0]*rk[7][2])-
      (fc[11][2]*rk[7][0]))));
    tc[11][2] = ((WkIkWk[11][2]+((ik[7][2][2]*onk[11][2])+((ik[7][2][0]*
      onk[11][0])+(ik[7][2][1]*onk[11][1]))))-(ttk[11][2]+((fc[11][1]*rk[7][0])-
      (fc[11][0]*rk[7][1]))));
    fccikt[11][0] = ((Cik[11][0][2]*fc[11][2])+((Cik[11][0][0]*fc[11][0])+(
      Cik[11][0][1]*fc[11][1])));
    fccikt[11][1] = ((Cik[11][1][2]*fc[11][2])+((Cik[11][1][0]*fc[11][0])+(
      Cik[11][1][1]*fc[11][1])));
    fccikt[11][2] = ((Cik[11][2][2]*fc[11][2])+((Cik[11][2][0]*fc[11][0])+(
      Cik[11][2][1]*fc[11][1])));
    ffk[10][0] = (ufk[6][0]-fccikt[11][0]);
    ffk[10][1] = (ufk[6][1]-fccikt[11][1]);
    ffk[10][2] = (ufk[6][2]-fccikt[11][2]);
    ttk[10][0] = (utk[6][0]-(((Cik[11][0][2]*tc[11][2])+((Cik[11][0][0]*
      tc[11][0])+(Cik[11][0][1]*tc[11][1])))+((fccikt[11][2]*ri[7][1])-(
      fccikt[11][1]*ri[7][2]))));
    ttk[10][1] = (utk[6][1]-(((Cik[11][1][2]*tc[11][2])+((Cik[11][1][0]*
      tc[11][0])+(Cik[11][1][1]*tc[11][1])))+((fccikt[11][0]*ri[7][2])-(
      fccikt[11][2]*ri[7][0]))));
    ttk[10][2] = (utk[6][2]-(((Cik[11][2][2]*tc[11][2])+((Cik[11][2][0]*
      tc[11][0])+(Cik[11][2][1]*tc[11][1])))+((fccikt[11][1]*ri[7][0])-(
      fccikt[11][0]*ri[7][1]))));
    fc[10][0] = ((mk[6]*(AnkAtk[10][0]-gk[10][0]))-ffk[10][0]);
    fc[10][1] = ((mk[6]*(AnkAtk[10][1]-gk[10][1]))-ffk[10][1]);
    fc[10][2] = ((mk[6]*(AnkAtk[10][2]-gk[10][2]))-ffk[10][2]);
    tc[10][0] = ((WkIkWk[10][0]+((ik[6][0][2]*onk[10][2])+((ik[6][0][0]*
      onk[10][0])+(ik[6][0][1]*onk[10][1]))))-(ttk[10][0]+((fc[10][2]*rk[6][1])-
      (fc[10][1]*rk[6][2]))));
    tc[10][1] = ((WkIkWk[10][1]+((ik[6][1][2]*onk[10][2])+((ik[6][1][0]*
      onk[10][0])+(ik[6][1][1]*onk[10][1]))))-(ttk[10][1]+((fc[10][0]*rk[6][2])-
      (fc[10][2]*rk[6][0]))));
    tc[10][2] = ((WkIkWk[10][2]+((ik[6][2][2]*onk[10][2])+((ik[6][2][0]*
      onk[10][0])+(ik[6][2][1]*onk[10][1]))))-(ttk[10][2]+((fc[10][1]*rk[6][0])-
      (fc[10][0]*rk[6][1]))));
    fccikt[10][0] = ((Cik[10][0][2]*fc[10][2])+((Cik[10][0][0]*fc[10][0])+(
      Cik[10][0][1]*fc[10][1])));
    fccikt[10][1] = ((Cik[10][1][2]*fc[10][2])+((Cik[10][1][0]*fc[10][0])+(
      Cik[10][1][1]*fc[10][1])));
    fccikt[10][2] = ((Cik[10][2][2]*fc[10][2])+((Cik[10][2][0]*fc[10][0])+(
      Cik[10][2][1]*fc[10][1])));
    ffk[5][0] = (ffk[5][0]-fccikt[10][0]);
    ffk[5][1] = (ffk[5][1]-fccikt[10][1]);
    ffk[5][2] = (ffk[5][2]-fccikt[10][2]);
    ttk[5][0] = (ttk[5][0]-(((Cik[10][0][2]*tc[10][2])+((Cik[10][0][0]*tc[10][0]
      )+(Cik[10][0][1]*tc[10][1])))+((fccikt[10][2]*ri[6][1])-(fccikt[10][1]*
      ri[6][2]))));
    ttk[5][1] = (ttk[5][1]-(((Cik[10][1][2]*tc[10][2])+((Cik[10][1][0]*tc[10][0]
      )+(Cik[10][1][1]*tc[10][1])))+((fccikt[10][0]*ri[6][2])-(fccikt[10][2]*
      ri[6][0]))));
    ttk[5][2] = (ttk[5][2]-(((Cik[10][2][2]*tc[10][2])+((Cik[10][2][0]*tc[10][0]
      )+(Cik[10][2][1]*tc[10][1])))+((fccikt[10][1]*ri[6][0])-(fccikt[10][0]*
      ri[6][1]))));
    fc[9][0] = ((psmk[9]*(AnkAtk[9][0]-gk[9][0]))-ffk[9][0]);
    fc[9][1] = ((psmk[9]*(AnkAtk[9][1]-gk[9][1]))-ffk[9][1]);
    fc[9][2] = ((psmk[9]*(AnkAtk[9][2]-gk[9][2]))-ffk[9][2]);
    tc[9][0] = ((WkIkWk[9][0]+((onk[9][2]*psik[9][0][2])+((onk[9][0]*
      psik[9][0][0])+(onk[9][1]*psik[9][0][1]))))-(ttk[9][0]+((fc[9][2]*
      psrk[9][1])-(fc[9][1]*psrk[9][2]))));
    tc[9][1] = ((WkIkWk[9][1]+((onk[9][2]*psik[9][1][2])+((onk[9][0]*
      psik[9][1][0])+(onk[9][1]*psik[9][1][1]))))-(ttk[9][1]+((fc[9][0]*
      psrk[9][2])-(fc[9][2]*psrk[9][0]))));
    tc[9][2] = ((WkIkWk[9][2]+((onk[9][2]*psik[9][2][2])+((onk[9][0]*
      psik[9][2][0])+(onk[9][1]*psik[9][2][1]))))-(ttk[9][2]+((fc[9][1]*
      psrk[9][0])-(fc[9][0]*psrk[9][1]))));
    fccikt[9][0] = ((Cik[9][0][2]*fc[9][2])+((Cik[9][0][0]*fc[9][0])+(
      Cik[9][0][1]*fc[9][1])));
    fccikt[9][1] = ((Cik[9][1][2]*fc[9][2])+((Cik[9][1][0]*fc[9][0])+(
      Cik[9][1][1]*fc[9][1])));
    fccikt[9][2] = ((Cik[9][2][2]*fc[9][2])+((Cik[9][2][0]*fc[9][0])+(
      Cik[9][2][1]*fc[9][1])));
    ffk[8][0] = (ufk[3][0]-fccikt[9][0]);
    ffk[8][1] = (ufk[3][1]-fccikt[9][1]);
    ffk[8][2] = (ufk[3][2]-fccikt[9][2]);
    ttk[8][0] = (utk[3][0]-(((Cik[9][0][2]*tc[9][2])+((Cik[9][0][0]*tc[9][0])+(
      Cik[9][0][1]*tc[9][1])))+((fccikt[9][2]*ri[4][1])-(fccikt[9][1]*ri[4][2]))
      ));
    ttk[8][1] = (utk[3][1]-(((Cik[9][1][2]*tc[9][2])+((Cik[9][1][0]*tc[9][0])+(
      Cik[9][1][1]*tc[9][1])))+((fccikt[9][0]*ri[4][2])-(fccikt[9][2]*ri[4][0]))
      ));
    ttk[8][2] = (utk[3][2]-(((Cik[9][2][2]*tc[9][2])+((Cik[9][2][0]*tc[9][0])+(
      Cik[9][2][1]*tc[9][1])))+((fccikt[9][1]*ri[4][0])-(fccikt[9][0]*ri[4][1]))
      ));
    fc[8][0] = ((mk[3]*(AnkAtk[8][0]-gk[8][0]))-ffk[8][0]);
    fc[8][1] = ((mk[3]*(AnkAtk[8][1]-gk[8][1]))-ffk[8][1]);
    fc[8][2] = ((mk[3]*(AnkAtk[8][2]-gk[8][2]))-ffk[8][2]);
    tc[8][0] = ((WkIkWk[8][0]+((ik[3][0][2]*onk[8][2])+((ik[3][0][0]*onk[8][0])+
      (ik[3][0][1]*onk[8][1]))))-(ttk[8][0]+((fc[8][2]*rk[3][1])-(fc[8][1]*
      rk[3][2]))));
    tc[8][1] = ((WkIkWk[8][1]+((ik[3][1][2]*onk[8][2])+((ik[3][1][0]*onk[8][0])+
      (ik[3][1][1]*onk[8][1]))))-(ttk[8][1]+((fc[8][0]*rk[3][2])-(fc[8][2]*
      rk[3][0]))));
    tc[8][2] = ((WkIkWk[8][2]+((ik[3][2][2]*onk[8][2])+((ik[3][2][0]*onk[8][0])+
      (ik[3][2][1]*onk[8][1]))))-(ttk[8][2]+((fc[8][1]*rk[3][0])-(fc[8][0]*
      rk[3][1]))));
    fccikt[8][0] = ((Cik[8][0][2]*fc[8][2])+((Cik[8][0][0]*fc[8][0])+(
      Cik[8][0][1]*fc[8][1])));
    fccikt[8][1] = ((Cik[8][1][2]*fc[8][2])+((Cik[8][1][0]*fc[8][0])+(
      Cik[8][1][1]*fc[8][1])));
    fccikt[8][2] = ((Cik[8][2][2]*fc[8][2])+((Cik[8][2][0]*fc[8][0])+(
      Cik[8][2][1]*fc[8][1])));
    ffk[7][0] = (ufk[2][0]-fccikt[8][0]);
    ffk[7][1] = (ufk[2][1]-fccikt[8][1]);
    ffk[7][2] = (ufk[2][2]-fccikt[8][2]);
    ttk[7][0] = (utk[2][0]-(((Cik[8][0][2]*tc[8][2])+((Cik[8][0][0]*tc[8][0])+(
      Cik[8][0][1]*tc[8][1])))+((fccikt[8][2]*ri[3][1])-(fccikt[8][1]*ri[3][2]))
      ));
    ttk[7][1] = (utk[2][1]-(((Cik[8][1][2]*tc[8][2])+((Cik[8][1][0]*tc[8][0])+(
      Cik[8][1][1]*tc[8][1])))+((fccikt[8][0]*ri[3][2])-(fccikt[8][2]*ri[3][0]))
      ));
    ttk[7][2] = (utk[2][2]-(((Cik[8][2][2]*tc[8][2])+((Cik[8][2][0]*tc[8][0])+(
      Cik[8][2][1]*tc[8][1])))+((fccikt[8][1]*ri[3][0])-(fccikt[8][0]*ri[3][1]))
      ));
    fc[7][0] = ((mk[2]*(AnkAtk[7][0]-gk[7][0]))-ffk[7][0]);
    fc[7][1] = ((mk[2]*(AnkAtk[7][1]-gk[7][1]))-ffk[7][1]);
    fc[7][2] = ((mk[2]*(AnkAtk[7][2]-gk[7][2]))-ffk[7][2]);
    tc[7][0] = ((WkIkWk[7][0]+((ik[2][0][2]*onk[7][2])+((ik[2][0][0]*onk[7][0])+
      (ik[2][0][1]*onk[7][1]))))-(ttk[7][0]+((fc[7][2]*rk[2][1])-(fc[7][1]*
      rk[2][2]))));
    tc[7][1] = ((WkIkWk[7][1]+((ik[2][1][2]*onk[7][2])+((ik[2][1][0]*onk[7][0])+
      (ik[2][1][1]*onk[7][1]))))-(ttk[7][1]+((fc[7][0]*rk[2][2])-(fc[7][2]*
      rk[2][0]))));
    tc[7][2] = ((WkIkWk[7][2]+((ik[2][2][2]*onk[7][2])+((ik[2][2][0]*onk[7][0])+
      (ik[2][2][1]*onk[7][1]))))-(ttk[7][2]+((fc[7][1]*rk[2][0])-(fc[7][0]*
      rk[2][1]))));
    fccikt[7][0] = ((Cik[7][0][2]*fc[7][2])+((Cik[7][0][0]*fc[7][0])+(
      Cik[7][0][1]*fc[7][1])));
    fccikt[7][1] = ((Cik[7][1][2]*fc[7][2])+((Cik[7][1][0]*fc[7][0])+(
      Cik[7][1][1]*fc[7][1])));
    fccikt[7][2] = ((Cik[7][2][2]*fc[7][2])+((Cik[7][2][0]*fc[7][0])+(
      Cik[7][2][1]*fc[7][1])));
    ffk[6][0] = (ufk[1][0]-fccikt[7][0]);
    ffk[6][1] = (ufk[1][1]-fccikt[7][1]);
    ffk[6][2] = (ufk[1][2]-fccikt[7][2]);
    ttk[6][0] = (utk[1][0]-(((Cik[7][0][2]*tc[7][2])+((Cik[7][0][0]*tc[7][0])+(
      Cik[7][0][1]*tc[7][1])))+((fccikt[7][2]*ri[2][1])-(fccikt[7][1]*ri[2][2]))
      ));
    ttk[6][1] = (utk[1][1]-(((Cik[7][1][2]*tc[7][2])+((Cik[7][1][0]*tc[7][0])+(
      Cik[7][1][1]*tc[7][1])))+((fccikt[7][0]*ri[2][2])-(fccikt[7][2]*ri[2][0]))
      ));
    ttk[6][2] = (utk[1][2]-(((Cik[7][2][2]*tc[7][2])+((Cik[7][2][0]*tc[7][0])+(
      Cik[7][2][1]*tc[7][1])))+((fccikt[7][1]*ri[2][0])-(fccikt[7][0]*ri[2][1]))
      ));
    fc[6][0] = ((mk[1]*(AnkAtk[6][0]-gk[6][0]))-ffk[6][0]);
    fc[6][1] = ((mk[1]*(AnkAtk[6][1]-gk[6][1]))-ffk[6][1]);
    fc[6][2] = ((mk[1]*(AnkAtk[6][2]-gk[6][2]))-ffk[6][2]);
    tc[6][0] = ((WkIkWk[6][0]+((ik[1][0][2]*onk[6][2])+((ik[1][0][0]*onk[6][0])+
      (ik[1][0][1]*onk[6][1]))))-(ttk[6][0]+((fc[6][2]*rk[1][1])-(fc[6][1]*
      rk[1][2]))));
    tc[6][1] = ((WkIkWk[6][1]+((ik[1][1][2]*onk[6][2])+((ik[1][1][0]*onk[6][0])+
      (ik[1][1][1]*onk[6][1]))))-(ttk[6][1]+((fc[6][0]*rk[1][2])-(fc[6][2]*
      rk[1][0]))));
    tc[6][2] = ((WkIkWk[6][2]+((ik[1][2][2]*onk[6][2])+((ik[1][2][0]*onk[6][0])+
      (ik[1][2][1]*onk[6][1]))))-(ttk[6][2]+((fc[6][1]*rk[1][0])-(fc[6][0]*
      rk[1][1]))));
    fccikt[6][0] = ((Cik[6][0][2]*fc[6][2])+((Cik[6][0][0]*fc[6][0])+(
      Cik[6][0][1]*fc[6][1])));
    fccikt[6][1] = ((Cik[6][1][2]*fc[6][2])+((Cik[6][1][0]*fc[6][0])+(
      Cik[6][1][1]*fc[6][1])));
    fccikt[6][2] = ((Cik[6][2][2]*fc[6][2])+((Cik[6][2][0]*fc[6][0])+(
      Cik[6][2][1]*fc[6][1])));
    ffk[5][0] = (ffk[5][0]-fccikt[6][0]);
    ffk[5][1] = (ffk[5][1]-fccikt[6][1]);
    ffk[5][2] = (ffk[5][2]-fccikt[6][2]);
    ttk[5][0] = (ttk[5][0]-(((Cik[6][0][2]*tc[6][2])+((Cik[6][0][0]*tc[6][0])+(
      Cik[6][0][1]*tc[6][1])))+((fccikt[6][2]*ri[1][1])-(fccikt[6][1]*ri[1][2]))
      ));
    ttk[5][1] = (ttk[5][1]-(((Cik[6][1][2]*tc[6][2])+((Cik[6][1][0]*tc[6][0])+(
      Cik[6][1][1]*tc[6][1])))+((fccikt[6][0]*ri[1][2])-(fccikt[6][2]*ri[1][0]))
      ));
    ttk[5][2] = (ttk[5][2]-(((Cik[6][2][2]*tc[6][2])+((Cik[6][2][0]*tc[6][0])+(
      Cik[6][2][1]*tc[6][1])))+((fccikt[6][1]*ri[1][0])-(fccikt[6][0]*ri[1][1]))
      ));
    fc[5][0] = ((mk[0]*(AnkAtk[5][0]-gk[3][0]))-ffk[5][0]);
    fc[5][1] = ((mk[0]*(AnkAtk[5][1]-gk[3][1]))-ffk[5][1]);
    fc[5][2] = ((mk[0]*(AnkAtk[5][2]-gk[3][2]))-ffk[5][2]);
    tc[5][0] = ((WkIkWk[5][0]+((ik[0][0][2]*udot[5])+((ik[0][0][0]*udot[3])+(
      ik[0][0][1]*udot[4]))))-(ttk[5][0]+((fc[5][2]*rk[0][1])-(fc[5][1]*rk[0][2]
      ))));
    tc[5][1] = ((WkIkWk[5][1]+((ik[0][1][2]*udot[5])+((ik[0][1][0]*udot[3])+(
      ik[0][1][1]*udot[4]))))-(ttk[5][1]+((fc[5][0]*rk[0][2])-(fc[5][2]*rk[0][0]
      ))));
    tc[5][2] = ((WkIkWk[5][2]+((ik[0][2][2]*udot[5])+((ik[0][2][0]*udot[3])+(
      ik[0][2][1]*udot[4]))))-(ttk[5][2]+((fc[5][1]*rk[0][0])-(fc[5][0]*rk[0][1]
      ))));
    fccikt[5][0] = fc[5][0];
    fccikt[5][1] = fc[5][1];
    fccikt[5][2] = fc[5][2];
    ffk[4][0] = -fccikt[5][0];
    ffk[4][1] = -fccikt[5][1];
    ffk[4][2] = -fccikt[5][2];
    ttk[4][0] = -tc[5][0];
    ttk[4][1] = -tc[5][1];
    ttk[4][2] = -tc[5][2];
    fc[4][0] = -ffk[4][0];
    fc[4][1] = -ffk[4][1];
    fc[4][2] = -ffk[4][2];
    tc[4][0] = -ttk[4][0];
    tc[4][1] = -ttk[4][1];
    tc[4][2] = -ttk[4][2];
    fccikt[4][0] = fc[4][0];
    fccikt[4][1] = fc[4][1];
    fccikt[4][2] = fc[4][2];
    ffk[3][0] = -fccikt[4][0];
    ffk[3][1] = -fccikt[4][1];
    ffk[3][2] = -fccikt[4][2];
    ttk[3][0] = -tc[4][0];
    ttk[3][1] = -tc[4][1];
    ttk[3][2] = -tc[4][2];
    fc[3][0] = -ffk[3][0];
    fc[3][1] = -ffk[3][1];
    fc[3][2] = -ffk[3][2];
    tc[3][0] = -ttk[3][0];
    tc[3][1] = -ttk[3][1];
    tc[3][2] = -ttk[3][2];
    fccikt[3][0] = ((Cik[3][0][2]*fc[3][2])+((Cik[3][0][0]*fc[3][0])+(
      Cik[3][0][1]*fc[3][1])));
    fccikt[3][1] = ((Cik[3][1][2]*fc[3][2])+((Cik[3][1][0]*fc[3][0])+(
      Cik[3][1][1]*fc[3][1])));
    fccikt[3][2] = ((Cik[3][2][2]*fc[3][2])+((Cik[3][2][0]*fc[3][0])+(
      Cik[3][2][1]*fc[3][1])));
    ffk[2][0] = -fccikt[3][0];
    ffk[2][1] = -fccikt[3][1];
    ffk[2][2] = -fccikt[3][2];
    ttk[2][0] = -((Cik[3][0][2]*tc[3][2])+((Cik[3][0][0]*tc[3][0])+(Cik[3][0][1]
      *tc[3][1])));
    ttk[2][1] = -((Cik[3][1][2]*tc[3][2])+((Cik[3][1][0]*tc[3][0])+(Cik[3][1][1]
      *tc[3][1])));
    ttk[2][2] = -((Cik[3][2][2]*tc[3][2])+((Cik[3][2][0]*tc[3][0])+(Cik[3][2][1]
      *tc[3][1])));
    fc[2][0] = -ffk[2][0];
    fc[2][1] = -ffk[2][1];
    fc[2][2] = -ffk[2][2];
    tc[2][0] = -ttk[2][0];
    tc[2][1] = -ttk[2][1];
    tc[2][2] = -ttk[2][2];
    fccikt[2][0] = fc[2][0];
    fccikt[2][1] = fc[2][1];
    fccikt[2][2] = fc[2][2];
    ffk[1][0] = -fccikt[2][0];
    ffk[1][1] = -fccikt[2][1];
    ffk[1][2] = -fccikt[2][2];
    ttk[1][0] = -(tc[2][0]+((fccikt[2][2]*rpp[2][1])-(fccikt[2][1]*rpp[2][2])));
    ttk[1][1] = -(tc[2][1]+((fccikt[2][0]*rpp[2][2])-(fccikt[2][2]*rpp[2][0])));
    ttk[1][2] = -(tc[2][2]+((fccikt[2][1]*rpp[2][0])-(fccikt[2][0]*rpp[2][1])));
    fc[1][0] = -ffk[1][0];
    fc[1][1] = -ffk[1][1];
    fc[1][2] = -ffk[1][2];
    tc[1][0] = -ttk[1][0];
    tc[1][1] = -ttk[1][1];
    tc[1][2] = -ttk[1][2];
    fccikt[1][0] = fc[1][0];
    fccikt[1][1] = fc[1][1];
    fccikt[1][2] = fc[1][2];
    ffk[0][0] = -fccikt[1][0];
    ffk[0][1] = -fccikt[1][1];
    ffk[0][2] = -fccikt[1][2];
    ttk[0][0] = -(tc[1][0]+((fccikt[1][2]*rpp[1][1])-(fccikt[1][1]*rpp[1][2])));
    ttk[0][1] = -(tc[1][1]+((fccikt[1][0]*rpp[1][2])-(fccikt[1][2]*rpp[1][0])));
    ttk[0][2] = -(tc[1][2]+((fccikt[1][1]*rpp[1][0])-(fccikt[1][0]*rpp[1][1])));
    fc[0][0] = -ffk[0][0];
    fc[0][1] = -ffk[0][1];
    fc[0][2] = -ffk[0][2];
    tc[0][0] = -ttk[0][0];
    tc[0][1] = -ttk[0][1];
    tc[0][2] = -ttk[0][2];
    force[0][0] = fc[5][0];
    torque[0][0] = tc[5][0];
    force[0][1] = fc[5][1];
    torque[0][1] = tc[5][1];
    force[0][2] = fc[5][2];
    torque[0][2] = tc[5][2];
    force[1][0] = fc[6][0];
    torque[1][0] = tc[6][0];
    force[1][1] = fc[6][1];
    torque[1][1] = tc[6][1];
    force[1][2] = fc[6][2];
    torque[1][2] = tc[6][2];
    force[2][0] = fc[7][0];
    torque[2][0] = tc[7][0];
    force[2][1] = fc[7][1];
    torque[2][1] = tc[7][1];
    force[2][2] = fc[7][2];
    torque[2][2] = tc[7][2];
    force[3][0] = fc[8][0];
    torque[3][0] = tc[8][0];
    force[3][1] = fc[8][1];
    torque[3][1] = tc[8][1];
    force[3][2] = fc[8][2];
    torque[3][2] = tc[8][2];
    force[4][0] = fc[9][0];
    torque[4][0] = tc[9][0];
    force[4][1] = fc[9][1];
    torque[4][1] = tc[9][1];
    force[4][2] = fc[9][2];
    torque[4][2] = tc[9][2];
    force[6][0] = fc[10][0];
    torque[6][0] = tc[10][0];
    force[6][1] = fc[10][1];
    torque[6][1] = tc[10][1];
    force[6][2] = fc[10][2];
    torque[6][2] = tc[10][2];
    force[7][0] = fc[11][0];
    torque[7][0] = tc[11][0];
    force[7][1] = fc[11][1];
    torque[7][1] = tc[11][1];
    force[7][2] = fc[11][2];
    torque[7][2] = tc[11][2];
    force[8][0] = fc[12][0];
    torque[8][0] = tc[12][0];
    force[8][1] = fc[12][1];
    torque[8][1] = tc[12][1];
    force[8][2] = fc[12][2];
    torque[8][2] = tc[12][2];
    force[9][0] = fc[13][0];
    torque[9][0] = tc[13][0];
    force[9][1] = fc[13][1];
    torque[9][1] = tc[13][1];
    force[9][2] = fc[13][2];
    torque[9][2] = tc[13][2];
    force[11][0] = fc[14][0];
    torque[11][0] = tc[14][0];
    force[11][1] = fc[14][1];
    torque[11][1] = tc[14][1];
    force[11][2] = fc[14][2];
    torque[11][2] = tc[14][2];
    force[12][0] = fc[15][0];
    torque[12][0] = tc[15][0];
    force[12][1] = fc[15][1];
    torque[12][1] = tc[15][1];
    force[12][2] = fc[15][2];
    torque[12][2] = tc[15][2];
    force[13][0] = fc[16][0];
    torque[13][0] = tc[16][0];
    force[13][1] = fc[16][1];
    torque[13][1] = tc[16][1];
    force[13][2] = fc[16][2];
    torque[13][2] = tc[16][2];
    force[14][0] = fc[17][0];
    torque[14][0] = tc[17][0];
    force[14][1] = fc[17][1];
    torque[14][1] = tc[17][1];
    force[14][2] = fc[17][2];
    torque[14][2] = tc[17][2];
    force[16][0] = fc[18][0];
    torque[16][0] = tc[18][0];
    force[16][1] = fc[18][1];
    torque[16][1] = tc[18][1];
    force[16][2] = fc[18][2];
    torque[16][2] = tc[18][2];
    force[17][0] = fc[19][0];
    torque[17][0] = tc[19][0];
    force[17][1] = fc[19][1];
    torque[17][1] = tc[19][1];
    force[17][2] = fc[19][2];
    torque[17][2] = tc[19][2];
    force[18][0] = fc[20][0];
    torque[18][0] = tc[20][0];
    force[18][1] = fc[20][1];
    torque[18][1] = tc[20][1];
    force[18][2] = fc[20][2];
    torque[18][2] = tc[20][2];
    force[19][0] = fc[21][0];
    torque[19][0] = tc[21][0];
    force[19][1] = fc[21][1];
    torque[19][1] = tc[21][1];
    force[19][2] = fc[21][2];
    torque[19][2] = tc[21][2];
/*
Compute reaction forces for tree weld joints
*/
    force[20][0] = ((mk[20]*(AnkAtk[21][0]+dyrcom[20][0]))-(ufk[20][0]+(
      gk[21][0]*mk[20])));
    torque[20][0] = (((rk[20][2]*((mk[20]*(AnkAtk[21][1]+dyrcom[20][1]))-(
      ufk[20][1]+(gk[21][1]*mk[20]))))-(rk[20][1]*((mk[20]*(AnkAtk[21][2]+
      dyrcom[20][2]))-(ufk[20][2]+(gk[21][2]*mk[20])))))+((WkIkbWk[20][0]+((
      ik[20][0][2]*onk[21][2])+((ik[20][0][0]*onk[21][0])+(ik[20][0][1]*
      onk[21][1]))))-utk[20][0]));
    force[20][1] = ((mk[20]*(AnkAtk[21][1]+dyrcom[20][1]))-(ufk[20][1]+(
      gk[21][1]*mk[20])));
    torque[20][1] = (((rk[20][0]*((mk[20]*(AnkAtk[21][2]+dyrcom[20][2]))-(
      ufk[20][2]+(gk[21][2]*mk[20]))))-(rk[20][2]*((mk[20]*(AnkAtk[21][0]+
      dyrcom[20][0]))-(ufk[20][0]+(gk[21][0]*mk[20])))))+((WkIkbWk[20][1]+((
      ik[20][1][2]*onk[21][2])+((ik[20][1][0]*onk[21][0])+(ik[20][1][1]*
      onk[21][1]))))-utk[20][1]));
    force[20][2] = ((mk[20]*(AnkAtk[21][2]+dyrcom[20][2]))-(ufk[20][2]+(
      gk[21][2]*mk[20])));
    torque[20][2] = (((rk[20][1]*((mk[20]*(AnkAtk[21][0]+dyrcom[20][0]))-(
      ufk[20][0]+(gk[21][0]*mk[20]))))-(rk[20][0]*((mk[20]*(AnkAtk[21][1]+
      dyrcom[20][1]))-(ufk[20][1]+(gk[21][1]*mk[20])))))+((WkIkbWk[20][2]+((
      ik[20][2][2]*onk[21][2])+((ik[20][2][0]*onk[21][0])+(ik[20][2][1]*
      onk[21][1]))))-utk[20][2]));
    force[15][0] = ((mk[15]*(AnkAtk[17][0]+dyrcom[15][0]))-(ufk[15][0]+(
      gk[17][0]*mk[15])));
    torque[15][0] = (((rk[15][2]*((mk[15]*(AnkAtk[17][1]+dyrcom[15][1]))-(
      ufk[15][1]+(gk[17][1]*mk[15]))))-(rk[15][1]*((mk[15]*(AnkAtk[17][2]+
      dyrcom[15][2]))-(ufk[15][2]+(gk[17][2]*mk[15])))))+((WkIkbWk[15][0]+((
      ik[15][0][2]*onk[17][2])+((ik[15][0][0]*onk[17][0])+(ik[15][0][1]*
      onk[17][1]))))-utk[15][0]));
    force[15][1] = ((mk[15]*(AnkAtk[17][1]+dyrcom[15][1]))-(ufk[15][1]+(
      gk[17][1]*mk[15])));
    torque[15][1] = (((rk[15][0]*((mk[15]*(AnkAtk[17][2]+dyrcom[15][2]))-(
      ufk[15][2]+(gk[17][2]*mk[15]))))-(rk[15][2]*((mk[15]*(AnkAtk[17][0]+
      dyrcom[15][0]))-(ufk[15][0]+(gk[17][0]*mk[15])))))+((WkIkbWk[15][1]+((
      ik[15][1][2]*onk[17][2])+((ik[15][1][0]*onk[17][0])+(ik[15][1][1]*
      onk[17][1]))))-utk[15][1]));
    force[15][2] = ((mk[15]*(AnkAtk[17][2]+dyrcom[15][2]))-(ufk[15][2]+(
      gk[17][2]*mk[15])));
    torque[15][2] = (((rk[15][1]*((mk[15]*(AnkAtk[17][0]+dyrcom[15][0]))-(
      ufk[15][0]+(gk[17][0]*mk[15]))))-(rk[15][0]*((mk[15]*(AnkAtk[17][1]+
      dyrcom[15][1]))-(ufk[15][1]+(gk[17][1]*mk[15])))))+((WkIkbWk[15][2]+((
      ik[15][2][2]*onk[17][2])+((ik[15][2][0]*onk[17][0])+(ik[15][2][1]*
      onk[17][1]))))-utk[15][2]));
    force[10][0] = ((mk[10]*(AnkAtk[13][0]+dyrcom[10][0]))-(ufk[10][0]+(
      gk[13][0]*mk[10])));
    torque[10][0] = (((rk[10][2]*((mk[10]*(AnkAtk[13][1]+dyrcom[10][1]))-(
      ufk[10][1]+(gk[13][1]*mk[10]))))-(rk[10][1]*((mk[10]*(AnkAtk[13][2]+
      dyrcom[10][2]))-(ufk[10][2]+(gk[13][2]*mk[10])))))+((WkIkbWk[10][0]+((
      ik[10][0][2]*onk[13][2])+((ik[10][0][0]*onk[13][0])+(ik[10][0][1]*
      onk[13][1]))))-utk[10][0]));
    force[10][1] = ((mk[10]*(AnkAtk[13][1]+dyrcom[10][1]))-(ufk[10][1]+(
      gk[13][1]*mk[10])));
    torque[10][1] = (((rk[10][0]*((mk[10]*(AnkAtk[13][2]+dyrcom[10][2]))-(
      ufk[10][2]+(gk[13][2]*mk[10]))))-(rk[10][2]*((mk[10]*(AnkAtk[13][0]+
      dyrcom[10][0]))-(ufk[10][0]+(gk[13][0]*mk[10])))))+((WkIkbWk[10][1]+((
      ik[10][1][2]*onk[13][2])+((ik[10][1][0]*onk[13][0])+(ik[10][1][1]*
      onk[13][1]))))-utk[10][1]));
    force[10][2] = ((mk[10]*(AnkAtk[13][2]+dyrcom[10][2]))-(ufk[10][2]+(
      gk[13][2]*mk[10])));
    torque[10][2] = (((rk[10][1]*((mk[10]*(AnkAtk[13][0]+dyrcom[10][0]))-(
      ufk[10][0]+(gk[13][0]*mk[10]))))-(rk[10][0]*((mk[10]*(AnkAtk[13][1]+
      dyrcom[10][1]))-(ufk[10][1]+(gk[13][1]*mk[10])))))+((WkIkbWk[10][2]+((
      ik[10][2][2]*onk[13][2])+((ik[10][2][0]*onk[13][0])+(ik[10][2][1]*
      onk[13][1]))))-utk[10][2]));
    force[5][0] = ((mk[5]*(AnkAtk[9][0]+dyrcom[5][0]))-(ufk[5][0]+(gk[9][0]*
      mk[5])));
    torque[5][0] = (((rk[5][2]*((mk[5]*(AnkAtk[9][1]+dyrcom[5][1]))-(ufk[5][1]+(
      gk[9][1]*mk[5]))))-(rk[5][1]*((mk[5]*(AnkAtk[9][2]+dyrcom[5][2]))-(
      ufk[5][2]+(gk[9][2]*mk[5])))))+((WkIkbWk[5][0]+((ik[5][0][2]*onk[9][2])+((
      ik[5][0][0]*onk[9][0])+(ik[5][0][1]*onk[9][1]))))-utk[5][0]));
    force[5][1] = ((mk[5]*(AnkAtk[9][1]+dyrcom[5][1]))-(ufk[5][1]+(gk[9][1]*
      mk[5])));
    torque[5][1] = (((rk[5][0]*((mk[5]*(AnkAtk[9][2]+dyrcom[5][2]))-(ufk[5][2]+(
      gk[9][2]*mk[5]))))-(rk[5][2]*((mk[5]*(AnkAtk[9][0]+dyrcom[5][0]))-(
      ufk[5][0]+(gk[9][0]*mk[5])))))+((WkIkbWk[5][1]+((ik[5][1][2]*onk[9][2])+((
      ik[5][1][0]*onk[9][0])+(ik[5][1][1]*onk[9][1]))))-utk[5][1]));
    force[5][2] = ((mk[5]*(AnkAtk[9][2]+dyrcom[5][2]))-(ufk[5][2]+(gk[9][2]*
      mk[5])));
    torque[5][2] = (((rk[5][1]*((mk[5]*(AnkAtk[9][0]+dyrcom[5][0]))-(ufk[5][0]+(
      gk[9][0]*mk[5]))))-(rk[5][0]*((mk[5]*(AnkAtk[9][1]+dyrcom[5][1]))-(
      ufk[5][1]+(gk[9][1]*mk[5])))))+((WkIkbWk[5][2]+((ik[5][2][2]*onk[9][2])+((
      ik[5][2][0]*onk[9][0])+(ik[5][2][1]*onk[9][1]))))-utk[5][2]));
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain 1128 adds/subtracts/negates
                    900 multiplies
                      0 divides
                    471 assignments
*/
}

void allegro_air_mom(double lm[3],
    double am[3],
    double *ke)
{
/*
Compute system linear and angular momentum, and kinetic energy.

Generated 15-Apr-2019 14:28:10 by SD/FAST, Kane's formulation
(sdfast B.2.8 #30123) on machine ID unknown
Copyright (c) 1990-1997 Symbolic Dynamics, Inc.
Copyright (c) 1990-1997 Parametric Technology Corp.
RESTRICTED RIGHTS LEGEND: Use, duplication, or disclosure by the U.S.
Government is subject to restrictions as set forth in subparagraph
(c)(1)(ii) of the Rights in Technical Data and Computer Software
clause at DFARS 52.227-7013 and similar clauses in the FAR and NASA
FAR Supplement.  Symbolic Dynamics, Inc., Mountain View, CA 94041
*/
    double lk[21][3],hnk[21][3];

    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(19,23);
        return;
    }
    lk[0][0] = (mk[0]*vnk[5][0]);
    lk[0][1] = (mk[0]*vnk[5][1]);
    lk[0][2] = (mk[0]*vnk[5][2]);
    lk[1][0] = (mk[1]*vnk[6][0]);
    lk[1][1] = (mk[1]*vnk[6][1]);
    lk[1][2] = (mk[1]*vnk[6][2]);
    lk[2][0] = (mk[2]*vnk[7][0]);
    lk[2][1] = (mk[2]*vnk[7][1]);
    lk[2][2] = (mk[2]*vnk[7][2]);
    lk[3][0] = (mk[3]*vnk[8][0]);
    lk[3][1] = (mk[3]*vnk[8][1]);
    lk[3][2] = (mk[3]*vnk[8][2]);
    lk[4][0] = (mk[4]*vnb[4][0]);
    lk[4][1] = (mk[4]*vnb[4][1]);
    lk[4][2] = (mk[4]*vnb[4][2]);
    lk[5][0] = (mk[5]*vnb[5][0]);
    lk[5][1] = (mk[5]*vnb[5][1]);
    lk[5][2] = (mk[5]*vnb[5][2]);
    lk[6][0] = (mk[6]*vnk[10][0]);
    lk[6][1] = (mk[6]*vnk[10][1]);
    lk[6][2] = (mk[6]*vnk[10][2]);
    lk[7][0] = (mk[7]*vnk[11][0]);
    lk[7][1] = (mk[7]*vnk[11][1]);
    lk[7][2] = (mk[7]*vnk[11][2]);
    lk[8][0] = (mk[8]*vnk[12][0]);
    lk[8][1] = (mk[8]*vnk[12][1]);
    lk[8][2] = (mk[8]*vnk[12][2]);
    lk[9][0] = (mk[9]*vnb[9][0]);
    lk[9][1] = (mk[9]*vnb[9][1]);
    lk[9][2] = (mk[9]*vnb[9][2]);
    lk[10][0] = (mk[10]*vnb[10][0]);
    lk[10][1] = (mk[10]*vnb[10][1]);
    lk[10][2] = (mk[10]*vnb[10][2]);
    lk[11][0] = (mk[11]*vnk[14][0]);
    lk[11][1] = (mk[11]*vnk[14][1]);
    lk[11][2] = (mk[11]*vnk[14][2]);
    lk[12][0] = (mk[12]*vnk[15][0]);
    lk[12][1] = (mk[12]*vnk[15][1]);
    lk[12][2] = (mk[12]*vnk[15][2]);
    lk[13][0] = (mk[13]*vnk[16][0]);
    lk[13][1] = (mk[13]*vnk[16][1]);
    lk[13][2] = (mk[13]*vnk[16][2]);
    lk[14][0] = (mk[14]*vnb[14][0]);
    lk[14][1] = (mk[14]*vnb[14][1]);
    lk[14][2] = (mk[14]*vnb[14][2]);
    lk[15][0] = (mk[15]*vnb[15][0]);
    lk[15][1] = (mk[15]*vnb[15][1]);
    lk[15][2] = (mk[15]*vnb[15][2]);
    lk[16][0] = (mk[16]*vnk[18][0]);
    lk[16][1] = (mk[16]*vnk[18][1]);
    lk[16][2] = (mk[16]*vnk[18][2]);
    lk[17][0] = (mk[17]*vnk[19][0]);
    lk[17][1] = (mk[17]*vnk[19][1]);
    lk[17][2] = (mk[17]*vnk[19][2]);
    lk[18][0] = (mk[18]*vnk[20][0]);
    lk[18][1] = (mk[18]*vnk[20][1]);
    lk[18][2] = (mk[18]*vnk[20][2]);
    lk[19][0] = (mk[19]*vnb[19][0]);
    lk[19][1] = (mk[19]*vnb[19][1]);
    lk[19][2] = (mk[19]*vnb[19][2]);
    lk[20][0] = (mk[20]*vnb[20][0]);
    lk[20][1] = (mk[20]*vnb[20][1]);
    lk[20][2] = (mk[20]*vnb[20][2]);
    hnk[0][0] = ((ik[0][0][2]*u[5])+((ik[0][0][0]*u[3])+(ik[0][0][1]*u[4])));
    hnk[0][1] = ((ik[0][1][2]*u[5])+((ik[0][1][0]*u[3])+(ik[0][1][1]*u[4])));
    hnk[0][2] = ((ik[0][2][2]*u[5])+((ik[0][2][0]*u[3])+(ik[0][2][1]*u[4])));
    hnk[1][0] = ((ik[1][0][2]*wk[6][2])+((ik[1][0][0]*wk[6][0])+(ik[1][0][1]*
      wk[6][1])));
    hnk[1][1] = ((ik[1][1][2]*wk[6][2])+((ik[1][1][0]*wk[6][0])+(ik[1][1][1]*
      wk[6][1])));
    hnk[1][2] = ((ik[1][2][2]*wk[6][2])+((ik[1][2][0]*wk[6][0])+(ik[1][2][1]*
      wk[6][1])));
    hnk[2][0] = ((ik[2][0][2]*wk[7][2])+((ik[2][0][0]*wk[7][0])+(ik[2][0][1]*
      wk[7][1])));
    hnk[2][1] = ((ik[2][1][2]*wk[7][2])+((ik[2][1][0]*wk[7][0])+(ik[2][1][1]*
      wk[7][1])));
    hnk[2][2] = ((ik[2][2][2]*wk[7][2])+((ik[2][2][0]*wk[7][0])+(ik[2][2][1]*
      wk[7][1])));
    hnk[3][0] = ((ik[3][0][2]*wk[8][2])+((ik[3][0][0]*wk[8][0])+(ik[3][0][1]*
      wk[8][1])));
    hnk[3][1] = ((ik[3][1][2]*wk[8][2])+((ik[3][1][0]*wk[8][0])+(ik[3][1][1]*
      wk[8][1])));
    hnk[3][2] = ((ik[3][2][2]*wk[8][2])+((ik[3][2][0]*wk[8][0])+(ik[3][2][1]*
      wk[8][1])));
    hnk[4][0] = ((ik[4][0][2]*wk[9][2])+((ik[4][0][0]*wk[9][0])+(ik[4][0][1]*
      wk[9][1])));
    hnk[4][1] = ((ik[4][1][2]*wk[9][2])+((ik[4][1][0]*wk[9][0])+(ik[4][1][1]*
      wk[9][1])));
    hnk[4][2] = ((ik[4][2][2]*wk[9][2])+((ik[4][2][0]*wk[9][0])+(ik[4][2][1]*
      wk[9][1])));
    hnk[5][0] = ((ik[5][0][2]*wk[9][2])+((ik[5][0][0]*wk[9][0])+(ik[5][0][1]*
      wk[9][1])));
    hnk[5][1] = ((ik[5][1][2]*wk[9][2])+((ik[5][1][0]*wk[9][0])+(ik[5][1][1]*
      wk[9][1])));
    hnk[5][2] = ((ik[5][2][2]*wk[9][2])+((ik[5][2][0]*wk[9][0])+(ik[5][2][1]*
      wk[9][1])));
    hnk[6][0] = ((ik[6][0][2]*wk[10][2])+((ik[6][0][0]*wk[10][0])+(ik[6][0][1]*
      wk[10][1])));
    hnk[6][1] = ((ik[6][1][2]*wk[10][2])+((ik[6][1][0]*wk[10][0])+(ik[6][1][1]*
      wk[10][1])));
    hnk[6][2] = ((ik[6][2][2]*wk[10][2])+((ik[6][2][0]*wk[10][0])+(ik[6][2][1]*
      wk[10][1])));
    hnk[7][0] = ((ik[7][0][2]*wk[11][2])+((ik[7][0][0]*wk[11][0])+(ik[7][0][1]*
      wk[11][1])));
    hnk[7][1] = ((ik[7][1][2]*wk[11][2])+((ik[7][1][0]*wk[11][0])+(ik[7][1][1]*
      wk[11][1])));
    hnk[7][2] = ((ik[7][2][2]*wk[11][2])+((ik[7][2][0]*wk[11][0])+(ik[7][2][1]*
      wk[11][1])));
    hnk[8][0] = ((ik[8][0][2]*wk[12][2])+((ik[8][0][0]*wk[12][0])+(ik[8][0][1]*
      wk[12][1])));
    hnk[8][1] = ((ik[8][1][2]*wk[12][2])+((ik[8][1][0]*wk[12][0])+(ik[8][1][1]*
      wk[12][1])));
    hnk[8][2] = ((ik[8][2][2]*wk[12][2])+((ik[8][2][0]*wk[12][0])+(ik[8][2][1]*
      wk[12][1])));
    hnk[9][0] = ((ik[9][0][2]*wk[13][2])+((ik[9][0][0]*wk[13][0])+(ik[9][0][1]*
      wk[13][1])));
    hnk[9][1] = ((ik[9][1][2]*wk[13][2])+((ik[9][1][0]*wk[13][0])+(ik[9][1][1]*
      wk[13][1])));
    hnk[9][2] = ((ik[9][2][2]*wk[13][2])+((ik[9][2][0]*wk[13][0])+(ik[9][2][1]*
      wk[13][1])));
    hnk[10][0] = ((ik[10][0][2]*wk[13][2])+((ik[10][0][0]*wk[13][0])+(
      ik[10][0][1]*wk[13][1])));
    hnk[10][1] = ((ik[10][1][2]*wk[13][2])+((ik[10][1][0]*wk[13][0])+(
      ik[10][1][1]*wk[13][1])));
    hnk[10][2] = ((ik[10][2][2]*wk[13][2])+((ik[10][2][0]*wk[13][0])+(
      ik[10][2][1]*wk[13][1])));
    hnk[11][0] = ((ik[11][0][2]*wk[14][2])+((ik[11][0][0]*wk[14][0])+(
      ik[11][0][1]*wk[14][1])));
    hnk[11][1] = ((ik[11][1][2]*wk[14][2])+((ik[11][1][0]*wk[14][0])+(
      ik[11][1][1]*wk[14][1])));
    hnk[11][2] = ((ik[11][2][2]*wk[14][2])+((ik[11][2][0]*wk[14][0])+(
      ik[11][2][1]*wk[14][1])));
    hnk[12][0] = ((ik[12][0][2]*wk[15][2])+((ik[12][0][0]*wk[15][0])+(
      ik[12][0][1]*wk[15][1])));
    hnk[12][1] = ((ik[12][1][2]*wk[15][2])+((ik[12][1][0]*wk[15][0])+(
      ik[12][1][1]*wk[15][1])));
    hnk[12][2] = ((ik[12][2][2]*wk[15][2])+((ik[12][2][0]*wk[15][0])+(
      ik[12][2][1]*wk[15][1])));
    hnk[13][0] = ((ik[13][0][2]*wk[16][2])+((ik[13][0][0]*wk[16][0])+(
      ik[13][0][1]*wk[16][1])));
    hnk[13][1] = ((ik[13][1][2]*wk[16][2])+((ik[13][1][0]*wk[16][0])+(
      ik[13][1][1]*wk[16][1])));
    hnk[13][2] = ((ik[13][2][2]*wk[16][2])+((ik[13][2][0]*wk[16][0])+(
      ik[13][2][1]*wk[16][1])));
    hnk[14][0] = ((ik[14][0][2]*wk[17][2])+((ik[14][0][0]*wk[17][0])+(
      ik[14][0][1]*wk[17][1])));
    hnk[14][1] = ((ik[14][1][2]*wk[17][2])+((ik[14][1][0]*wk[17][0])+(
      ik[14][1][1]*wk[17][1])));
    hnk[14][2] = ((ik[14][2][2]*wk[17][2])+((ik[14][2][0]*wk[17][0])+(
      ik[14][2][1]*wk[17][1])));
    hnk[15][0] = ((ik[15][0][2]*wk[17][2])+((ik[15][0][0]*wk[17][0])+(
      ik[15][0][1]*wk[17][1])));
    hnk[15][1] = ((ik[15][1][2]*wk[17][2])+((ik[15][1][0]*wk[17][0])+(
      ik[15][1][1]*wk[17][1])));
    hnk[15][2] = ((ik[15][2][2]*wk[17][2])+((ik[15][2][0]*wk[17][0])+(
      ik[15][2][1]*wk[17][1])));
    hnk[16][0] = ((ik[16][0][2]*wk[18][2])+((ik[16][0][0]*wk[18][0])+(
      ik[16][0][1]*wk[18][1])));
    hnk[16][1] = ((ik[16][1][2]*wk[18][2])+((ik[16][1][0]*wk[18][0])+(
      ik[16][1][1]*wk[18][1])));
    hnk[16][2] = ((ik[16][2][2]*wk[18][2])+((ik[16][2][0]*wk[18][0])+(
      ik[16][2][1]*wk[18][1])));
    hnk[17][0] = ((ik[17][0][2]*wk[19][2])+((ik[17][0][0]*wk[19][0])+(
      ik[17][0][1]*wk[19][1])));
    hnk[17][1] = ((ik[17][1][2]*wk[19][2])+((ik[17][1][0]*wk[19][0])+(
      ik[17][1][1]*wk[19][1])));
    hnk[17][2] = ((ik[17][2][2]*wk[19][2])+((ik[17][2][0]*wk[19][0])+(
      ik[17][2][1]*wk[19][1])));
    hnk[18][0] = ((ik[18][0][2]*wk[20][2])+((ik[18][0][0]*wk[20][0])+(
      ik[18][0][1]*wk[20][1])));
    hnk[18][1] = ((ik[18][1][2]*wk[20][2])+((ik[18][1][0]*wk[20][0])+(
      ik[18][1][1]*wk[20][1])));
    hnk[18][2] = ((ik[18][2][2]*wk[20][2])+((ik[18][2][0]*wk[20][0])+(
      ik[18][2][1]*wk[20][1])));
    hnk[19][0] = ((ik[19][0][2]*wk[21][2])+((ik[19][0][0]*wk[21][0])+(
      ik[19][0][1]*wk[21][1])));
    hnk[19][1] = ((ik[19][1][2]*wk[21][2])+((ik[19][1][0]*wk[21][0])+(
      ik[19][1][1]*wk[21][1])));
    hnk[19][2] = ((ik[19][2][2]*wk[21][2])+((ik[19][2][0]*wk[21][0])+(
      ik[19][2][1]*wk[21][1])));
    hnk[20][0] = ((ik[20][0][2]*wk[21][2])+((ik[20][0][0]*wk[21][0])+(
      ik[20][0][1]*wk[21][1])));
    hnk[20][1] = ((ik[20][1][2]*wk[21][2])+((ik[20][1][0]*wk[21][0])+(
      ik[20][1][1]*wk[21][1])));
    hnk[20][2] = ((ik[20][2][2]*wk[21][2])+((ik[20][2][0]*wk[21][0])+(
      ik[20][2][1]*wk[21][1])));
    lm[0] = (lk[20][0]+(lk[19][0]+(lk[18][0]+(lk[17][0]+(lk[16][0]+(lk[15][0]+(
      lk[14][0]+(lk[13][0]+(lk[12][0]+(lk[11][0]+(lk[10][0]+(lk[9][0]+(lk[8][0]+
      (lk[7][0]+(lk[6][0]+(lk[5][0]+(lk[4][0]+(lk[3][0]+(lk[2][0]+(lk[0][0]+
      lk[1][0]))))))))))))))))))));
    lm[1] = (lk[20][1]+(lk[19][1]+(lk[18][1]+(lk[17][1]+(lk[16][1]+(lk[15][1]+(
      lk[14][1]+(lk[13][1]+(lk[12][1]+(lk[11][1]+(lk[10][1]+(lk[9][1]+(lk[8][1]+
      (lk[7][1]+(lk[6][1]+(lk[5][1]+(lk[4][1]+(lk[3][1]+(lk[2][1]+(lk[0][1]+
      lk[1][1]))))))))))))))))))));
    lm[2] = (lk[20][2]+(lk[19][2]+(lk[18][2]+(lk[17][2]+(lk[16][2]+(lk[15][2]+(
      lk[14][2]+(lk[13][2]+(lk[12][2]+(lk[11][2]+(lk[10][2]+(lk[9][2]+(lk[8][2]+
      (lk[7][2]+(lk[6][2]+(lk[5][2]+(lk[4][2]+(lk[3][2]+(lk[2][2]+(lk[0][2]+
      lk[1][2]))))))))))))))))))));
    temp[0] = ((((cnk[7][0][2]*hnk[2][2])+((cnk[7][0][0]*hnk[2][0])+(
      cnk[7][0][1]*hnk[2][1])))+((lk[2][2]*rnk[7][1])-(lk[2][1]*rnk[7][2])))+(((
      (Cik[3][0][2]*hnk[0][2])+((Cik[3][0][0]*hnk[0][0])+(Cik[3][0][1]*hnk[0][1]
      )))+((lk[0][2]*rnk[5][1])-(lk[0][1]*rnk[5][2])))+(((cnk[6][0][2]*hnk[1][2]
      )+((cnk[6][0][0]*hnk[1][0])+(cnk[6][0][1]*hnk[1][1])))+((lk[1][2]*
      rnk[6][1])-(lk[1][1]*rnk[6][2])))));
    temp[1] = ((((cnk[9][0][2]*hnk[4][2])+((cnk[9][0][0]*hnk[4][0])+(
      cnk[9][0][1]*hnk[4][1])))+((lk[4][2]*rnb[4][1])-(lk[4][1]*rnb[4][2])))+(((
      (cnk[8][0][2]*hnk[3][2])+((cnk[8][0][0]*hnk[3][0])+(cnk[8][0][1]*hnk[3][1]
      )))+((lk[3][2]*rnk[8][1])-(lk[3][1]*rnk[8][2])))+temp[0]));
    temp[2] = ((((cnk[10][0][2]*hnk[6][2])+((cnk[10][0][0]*hnk[6][0])+(
      cnk[10][0][1]*hnk[6][1])))+((lk[6][2]*rnk[10][1])-(lk[6][1]*rnk[10][2])))+
      ((((cnk[9][0][2]*hnk[5][2])+((cnk[9][0][0]*hnk[5][0])+(cnk[9][0][1]*
      hnk[5][1])))+((lk[5][2]*rnb[5][1])-(lk[5][1]*rnb[5][2])))+temp[1]));
    temp[3] = ((((cnk[12][0][2]*hnk[8][2])+((cnk[12][0][0]*hnk[8][0])+(
      cnk[12][0][1]*hnk[8][1])))+((lk[8][2]*rnk[12][1])-(lk[8][1]*rnk[12][2])))+
      ((((cnk[11][0][2]*hnk[7][2])+((cnk[11][0][0]*hnk[7][0])+(cnk[11][0][1]*
      hnk[7][1])))+((lk[7][2]*rnk[11][1])-(lk[7][1]*rnk[11][2])))+temp[2]));
    temp[4] = ((((cnk[13][0][2]*hnk[10][2])+((cnk[13][0][0]*hnk[10][0])+(
      cnk[13][0][1]*hnk[10][1])))+((lk[10][2]*rnb[10][1])-(lk[10][1]*rnb[10][2])
      ))+((((cnk[13][0][2]*hnk[9][2])+((cnk[13][0][0]*hnk[9][0])+(cnk[13][0][1]*
      hnk[9][1])))+((lk[9][2]*rnb[9][1])-(lk[9][1]*rnb[9][2])))+temp[3]));
    temp[5] = ((((cnk[15][0][2]*hnk[12][2])+((cnk[15][0][0]*hnk[12][0])+(
      cnk[15][0][1]*hnk[12][1])))+((lk[12][2]*rnk[15][1])-(lk[12][1]*rnk[15][2])
      ))+((((cnk[14][0][2]*hnk[11][2])+((cnk[14][0][0]*hnk[11][0])+(
      cnk[14][0][1]*hnk[11][1])))+((lk[11][2]*rnk[14][1])-(lk[11][1]*rnk[14][2])
      ))+temp[4]));
    temp[6] = ((((cnk[17][0][2]*hnk[14][2])+((cnk[17][0][0]*hnk[14][0])+(
      cnk[17][0][1]*hnk[14][1])))+((lk[14][2]*rnb[14][1])-(lk[14][1]*rnb[14][2])
      ))+((((cnk[16][0][2]*hnk[13][2])+((cnk[16][0][0]*hnk[13][0])+(
      cnk[16][0][1]*hnk[13][1])))+((lk[13][2]*rnk[16][1])-(lk[13][1]*rnk[16][2])
      ))+temp[5]));
    temp[7] = ((((cnk[18][0][2]*hnk[16][2])+((cnk[18][0][0]*hnk[16][0])+(
      cnk[18][0][1]*hnk[16][1])))+((lk[16][2]*rnk[18][1])-(lk[16][1]*rnk[18][2])
      ))+((((cnk[17][0][2]*hnk[15][2])+((cnk[17][0][0]*hnk[15][0])+(
      cnk[17][0][1]*hnk[15][1])))+((lk[15][2]*rnb[15][1])-(lk[15][1]*rnb[15][2])
      ))+temp[6]));
    temp[8] = ((((cnk[20][0][2]*hnk[18][2])+((cnk[20][0][0]*hnk[18][0])+(
      cnk[20][0][1]*hnk[18][1])))+((lk[18][2]*rnk[20][1])-(lk[18][1]*rnk[20][2])
      ))+((((cnk[19][0][2]*hnk[17][2])+((cnk[19][0][0]*hnk[17][0])+(
      cnk[19][0][1]*hnk[17][1])))+((lk[17][2]*rnk[19][1])-(lk[17][1]*rnk[19][2])
      ))+temp[7]));
    am[0] = (((((cnk[21][0][2]*hnk[20][2])+((cnk[21][0][0]*hnk[20][0])+(
      cnk[21][0][1]*hnk[20][1])))+((lk[20][2]*rnb[20][1])-(lk[20][1]*rnb[20][2])
      ))+((((cnk[21][0][2]*hnk[19][2])+((cnk[21][0][0]*hnk[19][0])+(
      cnk[21][0][1]*hnk[19][1])))+((lk[19][2]*rnb[19][1])-(lk[19][1]*rnb[19][2])
      ))+temp[8]))-((com[1]*lm[2])-(com[2]*lm[1])));
    temp[0] = ((((cnk[7][1][2]*hnk[2][2])+((cnk[7][1][0]*hnk[2][0])+(
      cnk[7][1][1]*hnk[2][1])))+((lk[2][0]*rnk[7][2])-(lk[2][2]*rnk[7][0])))+(((
      (Cik[3][1][2]*hnk[0][2])+((Cik[3][1][0]*hnk[0][0])+(Cik[3][1][1]*hnk[0][1]
      )))+((lk[0][0]*rnk[5][2])-(lk[0][2]*rnk[5][0])))+(((cnk[6][1][2]*hnk[1][2]
      )+((cnk[6][1][0]*hnk[1][0])+(cnk[6][1][1]*hnk[1][1])))+((lk[1][0]*
      rnk[6][2])-(lk[1][2]*rnk[6][0])))));
    temp[1] = ((((cnk[9][1][2]*hnk[4][2])+((cnk[9][1][0]*hnk[4][0])+(
      cnk[9][1][1]*hnk[4][1])))+((lk[4][0]*rnb[4][2])-(lk[4][2]*rnb[4][0])))+(((
      (cnk[8][1][2]*hnk[3][2])+((cnk[8][1][0]*hnk[3][0])+(cnk[8][1][1]*hnk[3][1]
      )))+((lk[3][0]*rnk[8][2])-(lk[3][2]*rnk[8][0])))+temp[0]));
    temp[2] = ((((cnk[10][1][2]*hnk[6][2])+((cnk[10][1][0]*hnk[6][0])+(
      cnk[10][1][1]*hnk[6][1])))+((lk[6][0]*rnk[10][2])-(lk[6][2]*rnk[10][0])))+
      ((((cnk[9][1][2]*hnk[5][2])+((cnk[9][1][0]*hnk[5][0])+(cnk[9][1][1]*
      hnk[5][1])))+((lk[5][0]*rnb[5][2])-(lk[5][2]*rnb[5][0])))+temp[1]));
    temp[3] = ((((cnk[12][1][2]*hnk[8][2])+((cnk[12][1][0]*hnk[8][0])+(
      cnk[12][1][1]*hnk[8][1])))+((lk[8][0]*rnk[12][2])-(lk[8][2]*rnk[12][0])))+
      ((((cnk[11][1][2]*hnk[7][2])+((cnk[11][1][0]*hnk[7][0])+(cnk[11][1][1]*
      hnk[7][1])))+((lk[7][0]*rnk[11][2])-(lk[7][2]*rnk[11][0])))+temp[2]));
    temp[4] = ((((cnk[13][1][2]*hnk[10][2])+((cnk[13][1][0]*hnk[10][0])+(
      cnk[13][1][1]*hnk[10][1])))+((lk[10][0]*rnb[10][2])-(lk[10][2]*rnb[10][0])
      ))+((((cnk[13][1][2]*hnk[9][2])+((cnk[13][1][0]*hnk[9][0])+(cnk[13][1][1]*
      hnk[9][1])))+((lk[9][0]*rnb[9][2])-(lk[9][2]*rnb[9][0])))+temp[3]));
    temp[5] = ((((cnk[15][1][2]*hnk[12][2])+((cnk[15][1][0]*hnk[12][0])+(
      cnk[15][1][1]*hnk[12][1])))+((lk[12][0]*rnk[15][2])-(lk[12][2]*rnk[15][0])
      ))+((((cnk[14][1][2]*hnk[11][2])+((cnk[14][1][0]*hnk[11][0])+(
      cnk[14][1][1]*hnk[11][1])))+((lk[11][0]*rnk[14][2])-(lk[11][2]*rnk[14][0])
      ))+temp[4]));
    temp[6] = ((((cnk[17][1][2]*hnk[14][2])+((cnk[17][1][0]*hnk[14][0])+(
      cnk[17][1][1]*hnk[14][1])))+((lk[14][0]*rnb[14][2])-(lk[14][2]*rnb[14][0])
      ))+((((cnk[16][1][2]*hnk[13][2])+((cnk[16][1][0]*hnk[13][0])+(
      cnk[16][1][1]*hnk[13][1])))+((lk[13][0]*rnk[16][2])-(lk[13][2]*rnk[16][0])
      ))+temp[5]));
    temp[7] = ((((cnk[18][1][2]*hnk[16][2])+((cnk[18][1][0]*hnk[16][0])+(
      cnk[18][1][1]*hnk[16][1])))+((lk[16][0]*rnk[18][2])-(lk[16][2]*rnk[18][0])
      ))+((((cnk[17][1][2]*hnk[15][2])+((cnk[17][1][0]*hnk[15][0])+(
      cnk[17][1][1]*hnk[15][1])))+((lk[15][0]*rnb[15][2])-(lk[15][2]*rnb[15][0])
      ))+temp[6]));
    temp[8] = ((((cnk[20][1][2]*hnk[18][2])+((cnk[20][1][0]*hnk[18][0])+(
      cnk[20][1][1]*hnk[18][1])))+((lk[18][0]*rnk[20][2])-(lk[18][2]*rnk[20][0])
      ))+((((cnk[19][1][2]*hnk[17][2])+((cnk[19][1][0]*hnk[17][0])+(
      cnk[19][1][1]*hnk[17][1])))+((lk[17][0]*rnk[19][2])-(lk[17][2]*rnk[19][0])
      ))+temp[7]));
    am[1] = (((((cnk[21][1][2]*hnk[20][2])+((cnk[21][1][0]*hnk[20][0])+(
      cnk[21][1][1]*hnk[20][1])))+((lk[20][0]*rnb[20][2])-(lk[20][2]*rnb[20][0])
      ))+((((cnk[21][1][2]*hnk[19][2])+((cnk[21][1][0]*hnk[19][0])+(
      cnk[21][1][1]*hnk[19][1])))+((lk[19][0]*rnb[19][2])-(lk[19][2]*rnb[19][0])
      ))+temp[8]))-((com[2]*lm[0])-(com[0]*lm[2])));
    temp[0] = ((((cnk[7][2][2]*hnk[2][2])+((cnk[7][2][0]*hnk[2][0])+(
      cnk[7][2][1]*hnk[2][1])))+((lk[2][1]*rnk[7][0])-(lk[2][0]*rnk[7][1])))+(((
      (Cik[3][2][2]*hnk[0][2])+((Cik[3][2][0]*hnk[0][0])+(Cik[3][2][1]*hnk[0][1]
      )))+((lk[0][1]*rnk[5][0])-(lk[0][0]*rnk[5][1])))+(((cnk[6][2][2]*hnk[1][2]
      )+((cnk[6][2][0]*hnk[1][0])+(cnk[6][2][1]*hnk[1][1])))+((lk[1][1]*
      rnk[6][0])-(lk[1][0]*rnk[6][1])))));
    temp[1] = ((((cnk[9][2][2]*hnk[4][2])+((cnk[9][2][0]*hnk[4][0])+(
      cnk[9][2][1]*hnk[4][1])))+((lk[4][1]*rnb[4][0])-(lk[4][0]*rnb[4][1])))+(((
      (cnk[8][2][2]*hnk[3][2])+((cnk[8][2][0]*hnk[3][0])+(cnk[8][2][1]*hnk[3][1]
      )))+((lk[3][1]*rnk[8][0])-(lk[3][0]*rnk[8][1])))+temp[0]));
    temp[2] = ((((cnk[10][2][2]*hnk[6][2])+((cnk[10][2][0]*hnk[6][0])+(
      cnk[10][2][1]*hnk[6][1])))+((lk[6][1]*rnk[10][0])-(lk[6][0]*rnk[10][1])))+
      ((((cnk[9][2][2]*hnk[5][2])+((cnk[9][2][0]*hnk[5][0])+(cnk[9][2][1]*
      hnk[5][1])))+((lk[5][1]*rnb[5][0])-(lk[5][0]*rnb[5][1])))+temp[1]));
    temp[3] = ((((cnk[12][2][2]*hnk[8][2])+((cnk[12][2][0]*hnk[8][0])+(
      cnk[12][2][1]*hnk[8][1])))+((lk[8][1]*rnk[12][0])-(lk[8][0]*rnk[12][1])))+
      ((((cnk[11][2][2]*hnk[7][2])+((cnk[11][2][0]*hnk[7][0])+(cnk[11][2][1]*
      hnk[7][1])))+((lk[7][1]*rnk[11][0])-(lk[7][0]*rnk[11][1])))+temp[2]));
    temp[4] = ((((cnk[13][2][2]*hnk[10][2])+((cnk[13][2][0]*hnk[10][0])+(
      cnk[13][2][1]*hnk[10][1])))+((lk[10][1]*rnb[10][0])-(lk[10][0]*rnb[10][1])
      ))+((((cnk[13][2][2]*hnk[9][2])+((cnk[13][2][0]*hnk[9][0])+(cnk[13][2][1]*
      hnk[9][1])))+((lk[9][1]*rnb[9][0])-(lk[9][0]*rnb[9][1])))+temp[3]));
    temp[5] = ((((cnk[15][2][2]*hnk[12][2])+((cnk[15][2][0]*hnk[12][0])+(
      cnk[15][2][1]*hnk[12][1])))+((lk[12][1]*rnk[15][0])-(lk[12][0]*rnk[15][1])
      ))+((((cnk[14][2][2]*hnk[11][2])+((cnk[14][2][0]*hnk[11][0])+(
      cnk[14][2][1]*hnk[11][1])))+((lk[11][1]*rnk[14][0])-(lk[11][0]*rnk[14][1])
      ))+temp[4]));
    temp[6] = ((((cnk[17][2][2]*hnk[14][2])+((cnk[17][2][0]*hnk[14][0])+(
      cnk[17][2][1]*hnk[14][1])))+((lk[14][1]*rnb[14][0])-(lk[14][0]*rnb[14][1])
      ))+((((cnk[16][2][2]*hnk[13][2])+((cnk[16][2][0]*hnk[13][0])+(
      cnk[16][2][1]*hnk[13][1])))+((lk[13][1]*rnk[16][0])-(lk[13][0]*rnk[16][1])
      ))+temp[5]));
    temp[7] = ((((cnk[18][2][2]*hnk[16][2])+((cnk[18][2][0]*hnk[16][0])+(
      cnk[18][2][1]*hnk[16][1])))+((lk[16][1]*rnk[18][0])-(lk[16][0]*rnk[18][1])
      ))+((((cnk[17][2][2]*hnk[15][2])+((cnk[17][2][0]*hnk[15][0])+(
      cnk[17][2][1]*hnk[15][1])))+((lk[15][1]*rnb[15][0])-(lk[15][0]*rnb[15][1])
      ))+temp[6]));
    temp[8] = ((((cnk[20][2][2]*hnk[18][2])+((cnk[20][2][0]*hnk[18][0])+(
      cnk[20][2][1]*hnk[18][1])))+((lk[18][1]*rnk[20][0])-(lk[18][0]*rnk[20][1])
      ))+((((cnk[19][2][2]*hnk[17][2])+((cnk[19][2][0]*hnk[17][0])+(
      cnk[19][2][1]*hnk[17][1])))+((lk[17][1]*rnk[19][0])-(lk[17][0]*rnk[19][1])
      ))+temp[7]));
    am[2] = (((((cnk[21][2][2]*hnk[20][2])+((cnk[21][2][0]*hnk[20][0])+(
      cnk[21][2][1]*hnk[20][1])))+((lk[20][1]*rnb[20][0])-(lk[20][0]*rnb[20][1])
      ))+((((cnk[21][2][2]*hnk[19][2])+((cnk[21][2][0]*hnk[19][0])+(
      cnk[21][2][1]*hnk[19][1])))+((lk[19][1]*rnb[19][0])-(lk[19][0]*rnb[19][1])
      ))+temp[8]))-((com[0]*lm[1])-(com[1]*lm[0])));
    temp[0] = ((((hnk[0][2]*u[5])+((hnk[0][0]*u[3])+(hnk[0][1]*u[4])))+((
      lk[0][2]*vnk[5][2])+((lk[0][0]*vnk[5][0])+(lk[0][1]*vnk[5][1]))))+(((
      hnk[1][2]*wk[6][2])+((hnk[1][0]*wk[6][0])+(hnk[1][1]*wk[6][1])))+((
      lk[1][2]*vnk[6][2])+((lk[1][0]*vnk[6][0])+(lk[1][1]*vnk[6][1])))));
    temp[1] = ((((hnk[3][2]*wk[8][2])+((hnk[3][0]*wk[8][0])+(hnk[3][1]*wk[8][1])
      ))+((lk[3][2]*vnk[8][2])+((lk[3][0]*vnk[8][0])+(lk[3][1]*vnk[8][1]))))+(((
      (hnk[2][2]*wk[7][2])+((hnk[2][0]*wk[7][0])+(hnk[2][1]*wk[7][1])))+((
      lk[2][2]*vnk[7][2])+((lk[2][0]*vnk[7][0])+(lk[2][1]*vnk[7][1]))))+temp[0])
      );
    temp[2] = ((((hnk[5][2]*wk[9][2])+((hnk[5][0]*wk[9][0])+(hnk[5][1]*wk[9][1])
      ))+((lk[5][2]*vnb[5][2])+((lk[5][0]*vnb[5][0])+(lk[5][1]*vnb[5][1]))))+(((
      (hnk[4][2]*wk[9][2])+((hnk[4][0]*wk[9][0])+(hnk[4][1]*wk[9][1])))+((
      lk[4][2]*vnb[4][2])+((lk[4][0]*vnb[4][0])+(lk[4][1]*vnb[4][1]))))+temp[1])
      );
    temp[3] = ((((hnk[7][2]*wk[11][2])+((hnk[7][0]*wk[11][0])+(hnk[7][1]*
      wk[11][1])))+((lk[7][2]*vnk[11][2])+((lk[7][0]*vnk[11][0])+(lk[7][1]*
      vnk[11][1]))))+((((hnk[6][2]*wk[10][2])+((hnk[6][0]*wk[10][0])+(hnk[6][1]*
      wk[10][1])))+((lk[6][2]*vnk[10][2])+((lk[6][0]*vnk[10][0])+(lk[6][1]*
      vnk[10][1]))))+temp[2]));
    temp[4] = ((((hnk[9][2]*wk[13][2])+((hnk[9][0]*wk[13][0])+(hnk[9][1]*
      wk[13][1])))+((lk[9][2]*vnb[9][2])+((lk[9][0]*vnb[9][0])+(lk[9][1]*
      vnb[9][1]))))+((((hnk[8][2]*wk[12][2])+((hnk[8][0]*wk[12][0])+(hnk[8][1]*
      wk[12][1])))+((lk[8][2]*vnk[12][2])+((lk[8][0]*vnk[12][0])+(lk[8][1]*
      vnk[12][1]))))+temp[3]));
    temp[5] = ((((hnk[11][2]*wk[14][2])+((hnk[11][0]*wk[14][0])+(hnk[11][1]*
      wk[14][1])))+((lk[11][2]*vnk[14][2])+((lk[11][0]*vnk[14][0])+(lk[11][1]*
      vnk[14][1]))))+((((hnk[10][2]*wk[13][2])+((hnk[10][0]*wk[13][0])+(
      hnk[10][1]*wk[13][1])))+((lk[10][2]*vnb[10][2])+((lk[10][0]*vnb[10][0])+(
      lk[10][1]*vnb[10][1]))))+temp[4]));
    temp[6] = ((((hnk[13][2]*wk[16][2])+((hnk[13][0]*wk[16][0])+(hnk[13][1]*
      wk[16][1])))+((lk[13][2]*vnk[16][2])+((lk[13][0]*vnk[16][0])+(lk[13][1]*
      vnk[16][1]))))+((((hnk[12][2]*wk[15][2])+((hnk[12][0]*wk[15][0])+(
      hnk[12][1]*wk[15][1])))+((lk[12][2]*vnk[15][2])+((lk[12][0]*vnk[15][0])+(
      lk[12][1]*vnk[15][1]))))+temp[5]));
    temp[7] = ((((hnk[15][2]*wk[17][2])+((hnk[15][0]*wk[17][0])+(hnk[15][1]*
      wk[17][1])))+((lk[15][2]*vnb[15][2])+((lk[15][0]*vnb[15][0])+(lk[15][1]*
      vnb[15][1]))))+((((hnk[14][2]*wk[17][2])+((hnk[14][0]*wk[17][0])+(
      hnk[14][1]*wk[17][1])))+((lk[14][2]*vnb[14][2])+((lk[14][0]*vnb[14][0])+(
      lk[14][1]*vnb[14][1]))))+temp[6]));
    temp[8] = ((((hnk[17][2]*wk[19][2])+((hnk[17][0]*wk[19][0])+(hnk[17][1]*
      wk[19][1])))+((lk[17][2]*vnk[19][2])+((lk[17][0]*vnk[19][0])+(lk[17][1]*
      vnk[19][1]))))+((((hnk[16][2]*wk[18][2])+((hnk[16][0]*wk[18][0])+(
      hnk[16][1]*wk[18][1])))+((lk[16][2]*vnk[18][2])+((lk[16][0]*vnk[18][0])+(
      lk[16][1]*vnk[18][1]))))+temp[7]));
    temp[9] = ((((hnk[19][2]*wk[21][2])+((hnk[19][0]*wk[21][0])+(hnk[19][1]*
      wk[21][1])))+((lk[19][2]*vnb[19][2])+((lk[19][0]*vnb[19][0])+(lk[19][1]*
      vnb[19][1]))))+((((hnk[18][2]*wk[20][2])+((hnk[18][0]*wk[20][0])+(
      hnk[18][1]*wk[20][1])))+((lk[18][2]*vnk[20][2])+((lk[18][0]*vnk[20][0])+(
      lk[18][1]*vnk[20][1]))))+temp[8]));
    *ke = (.5*((((hnk[20][2]*wk[21][2])+((hnk[20][0]*wk[21][0])+(hnk[20][1]*
      wk[21][1])))+((lk[20][2]*vnb[20][2])+((lk[20][0]*vnb[20][0])+(lk[20][1]*
      vnb[20][1]))))+temp[9]));
/*
 Used 0.01 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  629 adds/subtracts/negates
                    700 multiplies
                      0 divides
                    170 assignments
*/
}

void allegro_air_sys(double *mtoto,
    double cm[3],
    double icm[3][3])
{
/*
Compute system total mass, and instantaneous center of mass and
inertia matrix.

Generated 15-Apr-2019 14:28:10 by SD/FAST, Kane's formulation
(sdfast B.2.8 #30123) on machine ID unknown
Copyright (c) 1990-1997 Symbolic Dynamics, Inc.
Copyright (c) 1990-1997 Parametric Technology Corp.
RESTRICTED RIGHTS LEGEND: Use, duplication, or disclosure by the U.S.
Government is subject to restrictions as set forth in subparagraph
(c)(1)(ii) of the Rights in Technical Data and Computer Software
clause at DFARS 52.227-7013 and similar clauses in the FAR and NASA
FAR Supplement.  Symbolic Dynamics, Inc., Mountain View, CA 94041
*/
    double ikcnkt[22][3][3];

    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(20,23);
        return;
    }
    *mtoto = mtot;
    cm[0] = com[0];
    cm[1] = com[1];
    cm[2] = com[2];
    ikcnkt[5][0][0] = ((Cik[3][0][2]*ik[0][0][2])+((Cik[3][0][0]*ik[0][0][0])+(
      Cik[3][0][1]*ik[0][0][1])));
    ikcnkt[5][0][1] = ((Cik[3][1][2]*ik[0][0][2])+((Cik[3][1][0]*ik[0][0][0])+(
      Cik[3][1][1]*ik[0][0][1])));
    ikcnkt[5][0][2] = ((Cik[3][2][2]*ik[0][0][2])+((Cik[3][2][0]*ik[0][0][0])+(
      Cik[3][2][1]*ik[0][0][1])));
    ikcnkt[5][1][0] = ((Cik[3][0][2]*ik[0][1][2])+((Cik[3][0][0]*ik[0][1][0])+(
      Cik[3][0][1]*ik[0][1][1])));
    ikcnkt[5][1][1] = ((Cik[3][1][2]*ik[0][1][2])+((Cik[3][1][0]*ik[0][1][0])+(
      Cik[3][1][1]*ik[0][1][1])));
    ikcnkt[5][1][2] = ((Cik[3][2][2]*ik[0][1][2])+((Cik[3][2][0]*ik[0][1][0])+(
      Cik[3][2][1]*ik[0][1][1])));
    ikcnkt[5][2][0] = ((Cik[3][0][2]*ik[0][2][2])+((Cik[3][0][0]*ik[0][2][0])+(
      Cik[3][0][1]*ik[0][2][1])));
    ikcnkt[5][2][1] = ((Cik[3][1][2]*ik[0][2][2])+((Cik[3][1][0]*ik[0][2][0])+(
      Cik[3][1][1]*ik[0][2][1])));
    ikcnkt[5][2][2] = ((Cik[3][2][2]*ik[0][2][2])+((Cik[3][2][0]*ik[0][2][0])+(
      Cik[3][2][1]*ik[0][2][1])));
    ikcnkt[6][0][0] = ((cnk[6][0][2]*ik[1][0][2])+((cnk[6][0][0]*ik[1][0][0])+(
      cnk[6][0][1]*ik[1][0][1])));
    ikcnkt[6][0][1] = ((cnk[6][1][2]*ik[1][0][2])+((cnk[6][1][0]*ik[1][0][0])+(
      cnk[6][1][1]*ik[1][0][1])));
    ikcnkt[6][0][2] = ((cnk[6][2][2]*ik[1][0][2])+((cnk[6][2][0]*ik[1][0][0])+(
      cnk[6][2][1]*ik[1][0][1])));
    ikcnkt[6][1][0] = ((cnk[6][0][2]*ik[1][1][2])+((cnk[6][0][0]*ik[1][1][0])+(
      cnk[6][0][1]*ik[1][1][1])));
    ikcnkt[6][1][1] = ((cnk[6][1][2]*ik[1][1][2])+((cnk[6][1][0]*ik[1][1][0])+(
      cnk[6][1][1]*ik[1][1][1])));
    ikcnkt[6][1][2] = ((cnk[6][2][2]*ik[1][1][2])+((cnk[6][2][0]*ik[1][1][0])+(
      cnk[6][2][1]*ik[1][1][1])));
    ikcnkt[6][2][0] = ((cnk[6][0][2]*ik[1][2][2])+((cnk[6][0][0]*ik[1][2][0])+(
      cnk[6][0][1]*ik[1][2][1])));
    ikcnkt[6][2][1] = ((cnk[6][1][2]*ik[1][2][2])+((cnk[6][1][0]*ik[1][2][0])+(
      cnk[6][1][1]*ik[1][2][1])));
    ikcnkt[6][2][2] = ((cnk[6][2][2]*ik[1][2][2])+((cnk[6][2][0]*ik[1][2][0])+(
      cnk[6][2][1]*ik[1][2][1])));
    ikcnkt[7][0][0] = ((cnk[7][0][2]*ik[2][0][2])+((cnk[7][0][0]*ik[2][0][0])+(
      cnk[7][0][1]*ik[2][0][1])));
    ikcnkt[7][0][1] = ((cnk[7][1][2]*ik[2][0][2])+((cnk[7][1][0]*ik[2][0][0])+(
      cnk[7][1][1]*ik[2][0][1])));
    ikcnkt[7][0][2] = ((cnk[7][2][2]*ik[2][0][2])+((cnk[7][2][0]*ik[2][0][0])+(
      cnk[7][2][1]*ik[2][0][1])));
    ikcnkt[7][1][0] = ((cnk[7][0][2]*ik[2][1][2])+((cnk[7][0][0]*ik[2][1][0])+(
      cnk[7][0][1]*ik[2][1][1])));
    ikcnkt[7][1][1] = ((cnk[7][1][2]*ik[2][1][2])+((cnk[7][1][0]*ik[2][1][0])+(
      cnk[7][1][1]*ik[2][1][1])));
    ikcnkt[7][1][2] = ((cnk[7][2][2]*ik[2][1][2])+((cnk[7][2][0]*ik[2][1][0])+(
      cnk[7][2][1]*ik[2][1][1])));
    ikcnkt[7][2][0] = ((cnk[7][0][2]*ik[2][2][2])+((cnk[7][0][0]*ik[2][2][0])+(
      cnk[7][0][1]*ik[2][2][1])));
    ikcnkt[7][2][1] = ((cnk[7][1][2]*ik[2][2][2])+((cnk[7][1][0]*ik[2][2][0])+(
      cnk[7][1][1]*ik[2][2][1])));
    ikcnkt[7][2][2] = ((cnk[7][2][2]*ik[2][2][2])+((cnk[7][2][0]*ik[2][2][0])+(
      cnk[7][2][1]*ik[2][2][1])));
    ikcnkt[8][0][0] = ((cnk[8][0][2]*ik[3][0][2])+((cnk[8][0][0]*ik[3][0][0])+(
      cnk[8][0][1]*ik[3][0][1])));
    ikcnkt[8][0][1] = ((cnk[8][1][2]*ik[3][0][2])+((cnk[8][1][0]*ik[3][0][0])+(
      cnk[8][1][1]*ik[3][0][1])));
    ikcnkt[8][0][2] = ((cnk[8][2][2]*ik[3][0][2])+((cnk[8][2][0]*ik[3][0][0])+(
      cnk[8][2][1]*ik[3][0][1])));
    ikcnkt[8][1][0] = ((cnk[8][0][2]*ik[3][1][2])+((cnk[8][0][0]*ik[3][1][0])+(
      cnk[8][0][1]*ik[3][1][1])));
    ikcnkt[8][1][1] = ((cnk[8][1][2]*ik[3][1][2])+((cnk[8][1][0]*ik[3][1][0])+(
      cnk[8][1][1]*ik[3][1][1])));
    ikcnkt[8][1][2] = ((cnk[8][2][2]*ik[3][1][2])+((cnk[8][2][0]*ik[3][1][0])+(
      cnk[8][2][1]*ik[3][1][1])));
    ikcnkt[8][2][0] = ((cnk[8][0][2]*ik[3][2][2])+((cnk[8][0][0]*ik[3][2][0])+(
      cnk[8][0][1]*ik[3][2][1])));
    ikcnkt[8][2][1] = ((cnk[8][1][2]*ik[3][2][2])+((cnk[8][1][0]*ik[3][2][0])+(
      cnk[8][1][1]*ik[3][2][1])));
    ikcnkt[8][2][2] = ((cnk[8][2][2]*ik[3][2][2])+((cnk[8][2][0]*ik[3][2][0])+(
      cnk[8][2][1]*ik[3][2][1])));
    ikcnkt[9][0][0] = ((cnk[9][0][2]*psik[9][0][2])+((cnk[9][0][0]*psik[9][0][0]
      )+(cnk[9][0][1]*psik[9][0][1])));
    ikcnkt[9][0][1] = ((cnk[9][1][2]*psik[9][0][2])+((cnk[9][1][0]*psik[9][0][0]
      )+(cnk[9][1][1]*psik[9][0][1])));
    ikcnkt[9][0][2] = ((cnk[9][2][2]*psik[9][0][2])+((cnk[9][2][0]*psik[9][0][0]
      )+(cnk[9][2][1]*psik[9][0][1])));
    ikcnkt[9][1][0] = ((cnk[9][0][2]*psik[9][1][2])+((cnk[9][0][0]*psik[9][1][0]
      )+(cnk[9][0][1]*psik[9][1][1])));
    ikcnkt[9][1][1] = ((cnk[9][1][2]*psik[9][1][2])+((cnk[9][1][0]*psik[9][1][0]
      )+(cnk[9][1][1]*psik[9][1][1])));
    ikcnkt[9][1][2] = ((cnk[9][2][2]*psik[9][1][2])+((cnk[9][2][0]*psik[9][1][0]
      )+(cnk[9][2][1]*psik[9][1][1])));
    ikcnkt[9][2][0] = ((cnk[9][0][2]*psik[9][2][2])+((cnk[9][0][0]*psik[9][2][0]
      )+(cnk[9][0][1]*psik[9][2][1])));
    ikcnkt[9][2][1] = ((cnk[9][1][2]*psik[9][2][2])+((cnk[9][1][0]*psik[9][2][0]
      )+(cnk[9][1][1]*psik[9][2][1])));
    ikcnkt[9][2][2] = ((cnk[9][2][2]*psik[9][2][2])+((cnk[9][2][0]*psik[9][2][0]
      )+(cnk[9][2][1]*psik[9][2][1])));
    ikcnkt[10][0][0] = ((cnk[10][0][2]*ik[6][0][2])+((cnk[10][0][0]*ik[6][0][0])
      +(cnk[10][0][1]*ik[6][0][1])));
    ikcnkt[10][0][1] = ((cnk[10][1][2]*ik[6][0][2])+((cnk[10][1][0]*ik[6][0][0])
      +(cnk[10][1][1]*ik[6][0][1])));
    ikcnkt[10][0][2] = ((cnk[10][2][2]*ik[6][0][2])+((cnk[10][2][0]*ik[6][0][0])
      +(cnk[10][2][1]*ik[6][0][1])));
    ikcnkt[10][1][0] = ((cnk[10][0][2]*ik[6][1][2])+((cnk[10][0][0]*ik[6][1][0])
      +(cnk[10][0][1]*ik[6][1][1])));
    ikcnkt[10][1][1] = ((cnk[10][1][2]*ik[6][1][2])+((cnk[10][1][0]*ik[6][1][0])
      +(cnk[10][1][1]*ik[6][1][1])));
    ikcnkt[10][1][2] = ((cnk[10][2][2]*ik[6][1][2])+((cnk[10][2][0]*ik[6][1][0])
      +(cnk[10][2][1]*ik[6][1][1])));
    ikcnkt[10][2][0] = ((cnk[10][0][2]*ik[6][2][2])+((cnk[10][0][0]*ik[6][2][0])
      +(cnk[10][0][1]*ik[6][2][1])));
    ikcnkt[10][2][1] = ((cnk[10][1][2]*ik[6][2][2])+((cnk[10][1][0]*ik[6][2][0])
      +(cnk[10][1][1]*ik[6][2][1])));
    ikcnkt[10][2][2] = ((cnk[10][2][2]*ik[6][2][2])+((cnk[10][2][0]*ik[6][2][0])
      +(cnk[10][2][1]*ik[6][2][1])));
    ikcnkt[11][0][0] = ((cnk[11][0][2]*ik[7][0][2])+((cnk[11][0][0]*ik[7][0][0])
      +(cnk[11][0][1]*ik[7][0][1])));
    ikcnkt[11][0][1] = ((cnk[11][1][2]*ik[7][0][2])+((cnk[11][1][0]*ik[7][0][0])
      +(cnk[11][1][1]*ik[7][0][1])));
    ikcnkt[11][0][2] = ((cnk[11][2][2]*ik[7][0][2])+((cnk[11][2][0]*ik[7][0][0])
      +(cnk[11][2][1]*ik[7][0][1])));
    ikcnkt[11][1][0] = ((cnk[11][0][2]*ik[7][1][2])+((cnk[11][0][0]*ik[7][1][0])
      +(cnk[11][0][1]*ik[7][1][1])));
    ikcnkt[11][1][1] = ((cnk[11][1][2]*ik[7][1][2])+((cnk[11][1][0]*ik[7][1][0])
      +(cnk[11][1][1]*ik[7][1][1])));
    ikcnkt[11][1][2] = ((cnk[11][2][2]*ik[7][1][2])+((cnk[11][2][0]*ik[7][1][0])
      +(cnk[11][2][1]*ik[7][1][1])));
    ikcnkt[11][2][0] = ((cnk[11][0][2]*ik[7][2][2])+((cnk[11][0][0]*ik[7][2][0])
      +(cnk[11][0][1]*ik[7][2][1])));
    ikcnkt[11][2][1] = ((cnk[11][1][2]*ik[7][2][2])+((cnk[11][1][0]*ik[7][2][0])
      +(cnk[11][1][1]*ik[7][2][1])));
    ikcnkt[11][2][2] = ((cnk[11][2][2]*ik[7][2][2])+((cnk[11][2][0]*ik[7][2][0])
      +(cnk[11][2][1]*ik[7][2][1])));
    ikcnkt[12][0][0] = ((cnk[12][0][2]*ik[8][0][2])+((cnk[12][0][0]*ik[8][0][0])
      +(cnk[12][0][1]*ik[8][0][1])));
    ikcnkt[12][0][1] = ((cnk[12][1][2]*ik[8][0][2])+((cnk[12][1][0]*ik[8][0][0])
      +(cnk[12][1][1]*ik[8][0][1])));
    ikcnkt[12][0][2] = ((cnk[12][2][2]*ik[8][0][2])+((cnk[12][2][0]*ik[8][0][0])
      +(cnk[12][2][1]*ik[8][0][1])));
    ikcnkt[12][1][0] = ((cnk[12][0][2]*ik[8][1][2])+((cnk[12][0][0]*ik[8][1][0])
      +(cnk[12][0][1]*ik[8][1][1])));
    ikcnkt[12][1][1] = ((cnk[12][1][2]*ik[8][1][2])+((cnk[12][1][0]*ik[8][1][0])
      +(cnk[12][1][1]*ik[8][1][1])));
    ikcnkt[12][1][2] = ((cnk[12][2][2]*ik[8][1][2])+((cnk[12][2][0]*ik[8][1][0])
      +(cnk[12][2][1]*ik[8][1][1])));
    ikcnkt[12][2][0] = ((cnk[12][0][2]*ik[8][2][2])+((cnk[12][0][0]*ik[8][2][0])
      +(cnk[12][0][1]*ik[8][2][1])));
    ikcnkt[12][2][1] = ((cnk[12][1][2]*ik[8][2][2])+((cnk[12][1][0]*ik[8][2][0])
      +(cnk[12][1][1]*ik[8][2][1])));
    ikcnkt[12][2][2] = ((cnk[12][2][2]*ik[8][2][2])+((cnk[12][2][0]*ik[8][2][0])
      +(cnk[12][2][1]*ik[8][2][1])));
    ikcnkt[13][0][0] = ((cnk[13][0][2]*psik[13][0][2])+((cnk[13][0][0]*
      psik[13][0][0])+(cnk[13][0][1]*psik[13][0][1])));
    ikcnkt[13][0][1] = ((cnk[13][1][2]*psik[13][0][2])+((cnk[13][1][0]*
      psik[13][0][0])+(cnk[13][1][1]*psik[13][0][1])));
    ikcnkt[13][0][2] = ((cnk[13][2][2]*psik[13][0][2])+((cnk[13][2][0]*
      psik[13][0][0])+(cnk[13][2][1]*psik[13][0][1])));
    ikcnkt[13][1][0] = ((cnk[13][0][2]*psik[13][1][2])+((cnk[13][0][0]*
      psik[13][1][0])+(cnk[13][0][1]*psik[13][1][1])));
    ikcnkt[13][1][1] = ((cnk[13][1][2]*psik[13][1][2])+((cnk[13][1][0]*
      psik[13][1][0])+(cnk[13][1][1]*psik[13][1][1])));
    ikcnkt[13][1][2] = ((cnk[13][2][2]*psik[13][1][2])+((cnk[13][2][0]*
      psik[13][1][0])+(cnk[13][2][1]*psik[13][1][1])));
    ikcnkt[13][2][0] = ((cnk[13][0][2]*psik[13][2][2])+((cnk[13][0][0]*
      psik[13][2][0])+(cnk[13][0][1]*psik[13][2][1])));
    ikcnkt[13][2][1] = ((cnk[13][1][2]*psik[13][2][2])+((cnk[13][1][0]*
      psik[13][2][0])+(cnk[13][1][1]*psik[13][2][1])));
    ikcnkt[13][2][2] = ((cnk[13][2][2]*psik[13][2][2])+((cnk[13][2][0]*
      psik[13][2][0])+(cnk[13][2][1]*psik[13][2][1])));
    ikcnkt[14][0][0] = ((cnk[14][0][2]*ik[11][0][2])+((cnk[14][0][0]*
      ik[11][0][0])+(cnk[14][0][1]*ik[11][0][1])));
    ikcnkt[14][0][1] = ((cnk[14][1][2]*ik[11][0][2])+((cnk[14][1][0]*
      ik[11][0][0])+(cnk[14][1][1]*ik[11][0][1])));
    ikcnkt[14][0][2] = ((cnk[14][2][2]*ik[11][0][2])+((cnk[14][2][0]*
      ik[11][0][0])+(cnk[14][2][1]*ik[11][0][1])));
    ikcnkt[14][1][0] = ((cnk[14][0][2]*ik[11][1][2])+((cnk[14][0][0]*
      ik[11][1][0])+(cnk[14][0][1]*ik[11][1][1])));
    ikcnkt[14][1][1] = ((cnk[14][1][2]*ik[11][1][2])+((cnk[14][1][0]*
      ik[11][1][0])+(cnk[14][1][1]*ik[11][1][1])));
    ikcnkt[14][1][2] = ((cnk[14][2][2]*ik[11][1][2])+((cnk[14][2][0]*
      ik[11][1][0])+(cnk[14][2][1]*ik[11][1][1])));
    ikcnkt[14][2][0] = ((cnk[14][0][2]*ik[11][2][2])+((cnk[14][0][0]*
      ik[11][2][0])+(cnk[14][0][1]*ik[11][2][1])));
    ikcnkt[14][2][1] = ((cnk[14][1][2]*ik[11][2][2])+((cnk[14][1][0]*
      ik[11][2][0])+(cnk[14][1][1]*ik[11][2][1])));
    ikcnkt[14][2][2] = ((cnk[14][2][2]*ik[11][2][2])+((cnk[14][2][0]*
      ik[11][2][0])+(cnk[14][2][1]*ik[11][2][1])));
    ikcnkt[15][0][0] = ((cnk[15][0][2]*ik[12][0][2])+((cnk[15][0][0]*
      ik[12][0][0])+(cnk[15][0][1]*ik[12][0][1])));
    ikcnkt[15][0][1] = ((cnk[15][1][2]*ik[12][0][2])+((cnk[15][1][0]*
      ik[12][0][0])+(cnk[15][1][1]*ik[12][0][1])));
    ikcnkt[15][0][2] = ((cnk[15][2][2]*ik[12][0][2])+((cnk[15][2][0]*
      ik[12][0][0])+(cnk[15][2][1]*ik[12][0][1])));
    ikcnkt[15][1][0] = ((cnk[15][0][2]*ik[12][1][2])+((cnk[15][0][0]*
      ik[12][1][0])+(cnk[15][0][1]*ik[12][1][1])));
    ikcnkt[15][1][1] = ((cnk[15][1][2]*ik[12][1][2])+((cnk[15][1][0]*
      ik[12][1][0])+(cnk[15][1][1]*ik[12][1][1])));
    ikcnkt[15][1][2] = ((cnk[15][2][2]*ik[12][1][2])+((cnk[15][2][0]*
      ik[12][1][0])+(cnk[15][2][1]*ik[12][1][1])));
    ikcnkt[15][2][0] = ((cnk[15][0][2]*ik[12][2][2])+((cnk[15][0][0]*
      ik[12][2][0])+(cnk[15][0][1]*ik[12][2][1])));
    ikcnkt[15][2][1] = ((cnk[15][1][2]*ik[12][2][2])+((cnk[15][1][0]*
      ik[12][2][0])+(cnk[15][1][1]*ik[12][2][1])));
    ikcnkt[15][2][2] = ((cnk[15][2][2]*ik[12][2][2])+((cnk[15][2][0]*
      ik[12][2][0])+(cnk[15][2][1]*ik[12][2][1])));
    ikcnkt[16][0][0] = ((cnk[16][0][2]*ik[13][0][2])+((cnk[16][0][0]*
      ik[13][0][0])+(cnk[16][0][1]*ik[13][0][1])));
    ikcnkt[16][0][1] = ((cnk[16][1][2]*ik[13][0][2])+((cnk[16][1][0]*
      ik[13][0][0])+(cnk[16][1][1]*ik[13][0][1])));
    ikcnkt[16][0][2] = ((cnk[16][2][2]*ik[13][0][2])+((cnk[16][2][0]*
      ik[13][0][0])+(cnk[16][2][1]*ik[13][0][1])));
    ikcnkt[16][1][0] = ((cnk[16][0][2]*ik[13][1][2])+((cnk[16][0][0]*
      ik[13][1][0])+(cnk[16][0][1]*ik[13][1][1])));
    ikcnkt[16][1][1] = ((cnk[16][1][2]*ik[13][1][2])+((cnk[16][1][0]*
      ik[13][1][0])+(cnk[16][1][1]*ik[13][1][1])));
    ikcnkt[16][1][2] = ((cnk[16][2][2]*ik[13][1][2])+((cnk[16][2][0]*
      ik[13][1][0])+(cnk[16][2][1]*ik[13][1][1])));
    ikcnkt[16][2][0] = ((cnk[16][0][2]*ik[13][2][2])+((cnk[16][0][0]*
      ik[13][2][0])+(cnk[16][0][1]*ik[13][2][1])));
    ikcnkt[16][2][1] = ((cnk[16][1][2]*ik[13][2][2])+((cnk[16][1][0]*
      ik[13][2][0])+(cnk[16][1][1]*ik[13][2][1])));
    ikcnkt[16][2][2] = ((cnk[16][2][2]*ik[13][2][2])+((cnk[16][2][0]*
      ik[13][2][0])+(cnk[16][2][1]*ik[13][2][1])));
    ikcnkt[17][0][0] = ((cnk[17][0][2]*psik[17][0][2])+((cnk[17][0][0]*
      psik[17][0][0])+(cnk[17][0][1]*psik[17][0][1])));
    ikcnkt[17][0][1] = ((cnk[17][1][2]*psik[17][0][2])+((cnk[17][1][0]*
      psik[17][0][0])+(cnk[17][1][1]*psik[17][0][1])));
    ikcnkt[17][0][2] = ((cnk[17][2][2]*psik[17][0][2])+((cnk[17][2][0]*
      psik[17][0][0])+(cnk[17][2][1]*psik[17][0][1])));
    ikcnkt[17][1][0] = ((cnk[17][0][2]*psik[17][1][2])+((cnk[17][0][0]*
      psik[17][1][0])+(cnk[17][0][1]*psik[17][1][1])));
    ikcnkt[17][1][1] = ((cnk[17][1][2]*psik[17][1][2])+((cnk[17][1][0]*
      psik[17][1][0])+(cnk[17][1][1]*psik[17][1][1])));
    ikcnkt[17][1][2] = ((cnk[17][2][2]*psik[17][1][2])+((cnk[17][2][0]*
      psik[17][1][0])+(cnk[17][2][1]*psik[17][1][1])));
    ikcnkt[17][2][0] = ((cnk[17][0][2]*psik[17][2][2])+((cnk[17][0][0]*
      psik[17][2][0])+(cnk[17][0][1]*psik[17][2][1])));
    ikcnkt[17][2][1] = ((cnk[17][1][2]*psik[17][2][2])+((cnk[17][1][0]*
      psik[17][2][0])+(cnk[17][1][1]*psik[17][2][1])));
    ikcnkt[17][2][2] = ((cnk[17][2][2]*psik[17][2][2])+((cnk[17][2][0]*
      psik[17][2][0])+(cnk[17][2][1]*psik[17][2][1])));
    ikcnkt[18][0][0] = ((cnk[18][0][2]*ik[16][0][2])+((cnk[18][0][0]*
      ik[16][0][0])+(cnk[18][0][1]*ik[16][0][1])));
    ikcnkt[18][0][1] = ((cnk[18][1][2]*ik[16][0][2])+((cnk[18][1][0]*
      ik[16][0][0])+(cnk[18][1][1]*ik[16][0][1])));
    ikcnkt[18][0][2] = ((cnk[18][2][2]*ik[16][0][2])+((cnk[18][2][0]*
      ik[16][0][0])+(cnk[18][2][1]*ik[16][0][1])));
    ikcnkt[18][1][0] = ((cnk[18][0][2]*ik[16][1][2])+((cnk[18][0][0]*
      ik[16][1][0])+(cnk[18][0][1]*ik[16][1][1])));
    ikcnkt[18][1][1] = ((cnk[18][1][2]*ik[16][1][2])+((cnk[18][1][0]*
      ik[16][1][0])+(cnk[18][1][1]*ik[16][1][1])));
    ikcnkt[18][1][2] = ((cnk[18][2][2]*ik[16][1][2])+((cnk[18][2][0]*
      ik[16][1][0])+(cnk[18][2][1]*ik[16][1][1])));
    ikcnkt[18][2][0] = ((cnk[18][0][2]*ik[16][2][2])+((cnk[18][0][0]*
      ik[16][2][0])+(cnk[18][0][1]*ik[16][2][1])));
    ikcnkt[18][2][1] = ((cnk[18][1][2]*ik[16][2][2])+((cnk[18][1][0]*
      ik[16][2][0])+(cnk[18][1][1]*ik[16][2][1])));
    ikcnkt[18][2][2] = ((cnk[18][2][2]*ik[16][2][2])+((cnk[18][2][0]*
      ik[16][2][0])+(cnk[18][2][1]*ik[16][2][1])));
    ikcnkt[19][0][0] = ((cnk[19][0][2]*ik[17][0][2])+((cnk[19][0][0]*
      ik[17][0][0])+(cnk[19][0][1]*ik[17][0][1])));
    ikcnkt[19][0][1] = ((cnk[19][1][2]*ik[17][0][2])+((cnk[19][1][0]*
      ik[17][0][0])+(cnk[19][1][1]*ik[17][0][1])));
    ikcnkt[19][0][2] = ((cnk[19][2][2]*ik[17][0][2])+((cnk[19][2][0]*
      ik[17][0][0])+(cnk[19][2][1]*ik[17][0][1])));
    ikcnkt[19][1][0] = ((cnk[19][0][2]*ik[17][1][2])+((cnk[19][0][0]*
      ik[17][1][0])+(cnk[19][0][1]*ik[17][1][1])));
    ikcnkt[19][1][1] = ((cnk[19][1][2]*ik[17][1][2])+((cnk[19][1][0]*
      ik[17][1][0])+(cnk[19][1][1]*ik[17][1][1])));
    ikcnkt[19][1][2] = ((cnk[19][2][2]*ik[17][1][2])+((cnk[19][2][0]*
      ik[17][1][0])+(cnk[19][2][1]*ik[17][1][1])));
    ikcnkt[19][2][0] = ((cnk[19][0][2]*ik[17][2][2])+((cnk[19][0][0]*
      ik[17][2][0])+(cnk[19][0][1]*ik[17][2][1])));
    ikcnkt[19][2][1] = ((cnk[19][1][2]*ik[17][2][2])+((cnk[19][1][0]*
      ik[17][2][0])+(cnk[19][1][1]*ik[17][2][1])));
    ikcnkt[19][2][2] = ((cnk[19][2][2]*ik[17][2][2])+((cnk[19][2][0]*
      ik[17][2][0])+(cnk[19][2][1]*ik[17][2][1])));
    ikcnkt[20][0][0] = ((cnk[20][0][2]*ik[18][0][2])+((cnk[20][0][0]*
      ik[18][0][0])+(cnk[20][0][1]*ik[18][0][1])));
    ikcnkt[20][0][1] = ((cnk[20][1][2]*ik[18][0][2])+((cnk[20][1][0]*
      ik[18][0][0])+(cnk[20][1][1]*ik[18][0][1])));
    ikcnkt[20][0][2] = ((cnk[20][2][2]*ik[18][0][2])+((cnk[20][2][0]*
      ik[18][0][0])+(cnk[20][2][1]*ik[18][0][1])));
    ikcnkt[20][1][0] = ((cnk[20][0][2]*ik[18][1][2])+((cnk[20][0][0]*
      ik[18][1][0])+(cnk[20][0][1]*ik[18][1][1])));
    ikcnkt[20][1][1] = ((cnk[20][1][2]*ik[18][1][2])+((cnk[20][1][0]*
      ik[18][1][0])+(cnk[20][1][1]*ik[18][1][1])));
    ikcnkt[20][1][2] = ((cnk[20][2][2]*ik[18][1][2])+((cnk[20][2][0]*
      ik[18][1][0])+(cnk[20][2][1]*ik[18][1][1])));
    ikcnkt[20][2][0] = ((cnk[20][0][2]*ik[18][2][2])+((cnk[20][0][0]*
      ik[18][2][0])+(cnk[20][0][1]*ik[18][2][1])));
    ikcnkt[20][2][1] = ((cnk[20][1][2]*ik[18][2][2])+((cnk[20][1][0]*
      ik[18][2][0])+(cnk[20][1][1]*ik[18][2][1])));
    ikcnkt[20][2][2] = ((cnk[20][2][2]*ik[18][2][2])+((cnk[20][2][0]*
      ik[18][2][0])+(cnk[20][2][1]*ik[18][2][1])));
    ikcnkt[21][0][0] = ((cnk[21][0][2]*psik[21][0][2])+((cnk[21][0][0]*
      psik[21][0][0])+(cnk[21][0][1]*psik[21][0][1])));
    ikcnkt[21][0][1] = ((cnk[21][1][2]*psik[21][0][2])+((cnk[21][1][0]*
      psik[21][0][0])+(cnk[21][1][1]*psik[21][0][1])));
    ikcnkt[21][0][2] = ((cnk[21][2][2]*psik[21][0][2])+((cnk[21][2][0]*
      psik[21][0][0])+(cnk[21][2][1]*psik[21][0][1])));
    ikcnkt[21][1][0] = ((cnk[21][0][2]*psik[21][1][2])+((cnk[21][0][0]*
      psik[21][1][0])+(cnk[21][0][1]*psik[21][1][1])));
    ikcnkt[21][1][1] = ((cnk[21][1][2]*psik[21][1][2])+((cnk[21][1][0]*
      psik[21][1][0])+(cnk[21][1][1]*psik[21][1][1])));
    ikcnkt[21][1][2] = ((cnk[21][2][2]*psik[21][1][2])+((cnk[21][2][0]*
      psik[21][1][0])+(cnk[21][2][1]*psik[21][1][1])));
    ikcnkt[21][2][0] = ((cnk[21][0][2]*psik[21][2][2])+((cnk[21][0][0]*
      psik[21][2][0])+(cnk[21][0][1]*psik[21][2][1])));
    ikcnkt[21][2][1] = ((cnk[21][1][2]*psik[21][2][2])+((cnk[21][1][0]*
      psik[21][2][0])+(cnk[21][1][1]*psik[21][2][1])));
    ikcnkt[21][2][2] = ((cnk[21][2][2]*psik[21][2][2])+((cnk[21][2][0]*
      psik[21][2][0])+(cnk[21][2][1]*psik[21][2][1])));
    temp[0] = (((mk[0]*((rnk[5][1]*rnk[5][1])+(rnk[5][2]*rnk[5][2])))+((
      Cik[3][0][2]*ikcnkt[5][2][0])+((Cik[3][0][0]*ikcnkt[5][0][0])+(
      Cik[3][0][1]*ikcnkt[5][1][0]))))+((mk[1]*((rnk[6][1]*rnk[6][1])+(rnk[6][2]
      *rnk[6][2])))+((cnk[6][0][2]*ikcnkt[6][2][0])+((cnk[6][0][0]*
      ikcnkt[6][0][0])+(cnk[6][0][1]*ikcnkt[6][1][0])))));
    temp[1] = (((mk[3]*((rnk[8][1]*rnk[8][1])+(rnk[8][2]*rnk[8][2])))+((
      cnk[8][0][2]*ikcnkt[8][2][0])+((cnk[8][0][0]*ikcnkt[8][0][0])+(
      cnk[8][0][1]*ikcnkt[8][1][0]))))+(((mk[2]*((rnk[7][1]*rnk[7][1])+(
      rnk[7][2]*rnk[7][2])))+((cnk[7][0][2]*ikcnkt[7][2][0])+((cnk[7][0][0]*
      ikcnkt[7][0][0])+(cnk[7][0][1]*ikcnkt[7][1][0]))))+temp[0]));
    temp[2] = (((mk[6]*((rnk[10][1]*rnk[10][1])+(rnk[10][2]*rnk[10][2])))+((
      cnk[10][0][2]*ikcnkt[10][2][0])+((cnk[10][0][0]*ikcnkt[10][0][0])+(
      cnk[10][0][1]*ikcnkt[10][1][0]))))+(((psmk[9]*((rnk[9][1]*rnk[9][1])+(
      rnk[9][2]*rnk[9][2])))+((cnk[9][0][2]*ikcnkt[9][2][0])+((cnk[9][0][0]*
      ikcnkt[9][0][0])+(cnk[9][0][1]*ikcnkt[9][1][0]))))+temp[1]));
    temp[3] = (((mk[8]*((rnk[12][1]*rnk[12][1])+(rnk[12][2]*rnk[12][2])))+((
      cnk[12][0][2]*ikcnkt[12][2][0])+((cnk[12][0][0]*ikcnkt[12][0][0])+(
      cnk[12][0][1]*ikcnkt[12][1][0]))))+(((mk[7]*((rnk[11][1]*rnk[11][1])+(
      rnk[11][2]*rnk[11][2])))+((cnk[11][0][2]*ikcnkt[11][2][0])+((cnk[11][0][0]
      *ikcnkt[11][0][0])+(cnk[11][0][1]*ikcnkt[11][1][0]))))+temp[2]));
    temp[4] = (((mk[11]*((rnk[14][1]*rnk[14][1])+(rnk[14][2]*rnk[14][2])))+((
      cnk[14][0][2]*ikcnkt[14][2][0])+((cnk[14][0][0]*ikcnkt[14][0][0])+(
      cnk[14][0][1]*ikcnkt[14][1][0]))))+(((psmk[13]*((rnk[13][1]*rnk[13][1])+(
      rnk[13][2]*rnk[13][2])))+((cnk[13][0][2]*ikcnkt[13][2][0])+((cnk[13][0][0]
      *ikcnkt[13][0][0])+(cnk[13][0][1]*ikcnkt[13][1][0]))))+temp[3]));
    temp[5] = (((mk[13]*((rnk[16][1]*rnk[16][1])+(rnk[16][2]*rnk[16][2])))+((
      cnk[16][0][2]*ikcnkt[16][2][0])+((cnk[16][0][0]*ikcnkt[16][0][0])+(
      cnk[16][0][1]*ikcnkt[16][1][0]))))+(((mk[12]*((rnk[15][1]*rnk[15][1])+(
      rnk[15][2]*rnk[15][2])))+((cnk[15][0][2]*ikcnkt[15][2][0])+((cnk[15][0][0]
      *ikcnkt[15][0][0])+(cnk[15][0][1]*ikcnkt[15][1][0]))))+temp[4]));
    temp[6] = (((mk[16]*((rnk[18][1]*rnk[18][1])+(rnk[18][2]*rnk[18][2])))+((
      cnk[18][0][2]*ikcnkt[18][2][0])+((cnk[18][0][0]*ikcnkt[18][0][0])+(
      cnk[18][0][1]*ikcnkt[18][1][0]))))+(((psmk[17]*((rnk[17][1]*rnk[17][1])+(
      rnk[17][2]*rnk[17][2])))+((cnk[17][0][2]*ikcnkt[17][2][0])+((cnk[17][0][0]
      *ikcnkt[17][0][0])+(cnk[17][0][1]*ikcnkt[17][1][0]))))+temp[5]));
    temp[7] = (((mk[18]*((rnk[20][1]*rnk[20][1])+(rnk[20][2]*rnk[20][2])))+((
      cnk[20][0][2]*ikcnkt[20][2][0])+((cnk[20][0][0]*ikcnkt[20][0][0])+(
      cnk[20][0][1]*ikcnkt[20][1][0]))))+(((mk[17]*((rnk[19][1]*rnk[19][1])+(
      rnk[19][2]*rnk[19][2])))+((cnk[19][0][2]*ikcnkt[19][2][0])+((cnk[19][0][0]
      *ikcnkt[19][0][0])+(cnk[19][0][1]*ikcnkt[19][1][0]))))+temp[6]));
    icm[0][0] = ((((psmk[21]*((rnk[21][1]*rnk[21][1])+(rnk[21][2]*rnk[21][2])))+
      ((cnk[21][0][2]*ikcnkt[21][2][0])+((cnk[21][0][0]*ikcnkt[21][0][0])+(
      cnk[21][0][1]*ikcnkt[21][1][0]))))+temp[7])-(mtot*((com[1]*com[1])+(com[2]
      *com[2]))));
    temp[0] = ((((cnk[7][0][2]*ikcnkt[7][2][1])+((cnk[7][0][0]*ikcnkt[7][0][1])+
      (cnk[7][0][1]*ikcnkt[7][1][1])))-(mk[2]*(rnk[7][0]*rnk[7][1])))+((((
      Cik[3][0][2]*ikcnkt[5][2][1])+((Cik[3][0][0]*ikcnkt[5][0][1])+(
      Cik[3][0][1]*ikcnkt[5][1][1])))-(mk[0]*(rnk[5][0]*rnk[5][1])))+(((
      cnk[6][0][2]*ikcnkt[6][2][1])+((cnk[6][0][0]*ikcnkt[6][0][1])+(
      cnk[6][0][1]*ikcnkt[6][1][1])))-(mk[1]*(rnk[6][0]*rnk[6][1])))));
    temp[1] = ((((cnk[10][0][2]*ikcnkt[10][2][1])+((cnk[10][0][0]*
      ikcnkt[10][0][1])+(cnk[10][0][1]*ikcnkt[10][1][1])))-(mk[6]*(rnk[10][0]*
      rnk[10][1])))+((((cnk[9][0][2]*ikcnkt[9][2][1])+((cnk[9][0][0]*
      ikcnkt[9][0][1])+(cnk[9][0][1]*ikcnkt[9][1][1])))-(psmk[9]*(rnk[9][0]*
      rnk[9][1])))+((((cnk[8][0][2]*ikcnkt[8][2][1])+((cnk[8][0][0]*
      ikcnkt[8][0][1])+(cnk[8][0][1]*ikcnkt[8][1][1])))-(mk[3]*(rnk[8][0]*
      rnk[8][1])))+temp[0])));
    temp[2] = ((((cnk[13][0][2]*ikcnkt[13][2][1])+((cnk[13][0][0]*
      ikcnkt[13][0][1])+(cnk[13][0][1]*ikcnkt[13][1][1])))-(psmk[13]*(rnk[13][0]
      *rnk[13][1])))+((((cnk[12][0][2]*ikcnkt[12][2][1])+((cnk[12][0][0]*
      ikcnkt[12][0][1])+(cnk[12][0][1]*ikcnkt[12][1][1])))-(mk[8]*(rnk[12][0]*
      rnk[12][1])))+((((cnk[11][0][2]*ikcnkt[11][2][1])+((cnk[11][0][0]*
      ikcnkt[11][0][1])+(cnk[11][0][1]*ikcnkt[11][1][1])))-(mk[7]*(rnk[11][0]*
      rnk[11][1])))+temp[1])));
    temp[3] = ((((cnk[16][0][2]*ikcnkt[16][2][1])+((cnk[16][0][0]*
      ikcnkt[16][0][1])+(cnk[16][0][1]*ikcnkt[16][1][1])))-(mk[13]*(rnk[16][0]*
      rnk[16][1])))+((((cnk[15][0][2]*ikcnkt[15][2][1])+((cnk[15][0][0]*
      ikcnkt[15][0][1])+(cnk[15][0][1]*ikcnkt[15][1][1])))-(mk[12]*(rnk[15][0]*
      rnk[15][1])))+((((cnk[14][0][2]*ikcnkt[14][2][1])+((cnk[14][0][0]*
      ikcnkt[14][0][1])+(cnk[14][0][1]*ikcnkt[14][1][1])))-(mk[11]*(rnk[14][0]*
      rnk[14][1])))+temp[2])));
    temp[4] = ((((cnk[19][0][2]*ikcnkt[19][2][1])+((cnk[19][0][0]*
      ikcnkt[19][0][1])+(cnk[19][0][1]*ikcnkt[19][1][1])))-(mk[17]*(rnk[19][0]*
      rnk[19][1])))+((((cnk[18][0][2]*ikcnkt[18][2][1])+((cnk[18][0][0]*
      ikcnkt[18][0][1])+(cnk[18][0][1]*ikcnkt[18][1][1])))-(mk[16]*(rnk[18][0]*
      rnk[18][1])))+((((cnk[17][0][2]*ikcnkt[17][2][1])+((cnk[17][0][0]*
      ikcnkt[17][0][1])+(cnk[17][0][1]*ikcnkt[17][1][1])))-(psmk[17]*(rnk[17][0]
      *rnk[17][1])))+temp[3])));
    icm[0][1] = ((mtot*(com[0]*com[1]))+((((cnk[21][0][2]*ikcnkt[21][2][1])+((
      cnk[21][0][0]*ikcnkt[21][0][1])+(cnk[21][0][1]*ikcnkt[21][1][1])))-(
      psmk[21]*(rnk[21][0]*rnk[21][1])))+((((cnk[20][0][2]*ikcnkt[20][2][1])+((
      cnk[20][0][0]*ikcnkt[20][0][1])+(cnk[20][0][1]*ikcnkt[20][1][1])))-(mk[18]
      *(rnk[20][0]*rnk[20][1])))+temp[4])));
    temp[0] = ((((cnk[7][0][2]*ikcnkt[7][2][2])+((cnk[7][0][0]*ikcnkt[7][0][2])+
      (cnk[7][0][1]*ikcnkt[7][1][2])))-(mk[2]*(rnk[7][0]*rnk[7][2])))+((((
      Cik[3][0][2]*ikcnkt[5][2][2])+((Cik[3][0][0]*ikcnkt[5][0][2])+(
      Cik[3][0][1]*ikcnkt[5][1][2])))-(mk[0]*(rnk[5][0]*rnk[5][2])))+(((
      cnk[6][0][2]*ikcnkt[6][2][2])+((cnk[6][0][0]*ikcnkt[6][0][2])+(
      cnk[6][0][1]*ikcnkt[6][1][2])))-(mk[1]*(rnk[6][0]*rnk[6][2])))));
    temp[1] = ((((cnk[10][0][2]*ikcnkt[10][2][2])+((cnk[10][0][0]*
      ikcnkt[10][0][2])+(cnk[10][0][1]*ikcnkt[10][1][2])))-(mk[6]*(rnk[10][0]*
      rnk[10][2])))+((((cnk[9][0][2]*ikcnkt[9][2][2])+((cnk[9][0][0]*
      ikcnkt[9][0][2])+(cnk[9][0][1]*ikcnkt[9][1][2])))-(psmk[9]*(rnk[9][0]*
      rnk[9][2])))+((((cnk[8][0][2]*ikcnkt[8][2][2])+((cnk[8][0][0]*
      ikcnkt[8][0][2])+(cnk[8][0][1]*ikcnkt[8][1][2])))-(mk[3]*(rnk[8][0]*
      rnk[8][2])))+temp[0])));
    temp[2] = ((((cnk[13][0][2]*ikcnkt[13][2][2])+((cnk[13][0][0]*
      ikcnkt[13][0][2])+(cnk[13][0][1]*ikcnkt[13][1][2])))-(psmk[13]*(rnk[13][0]
      *rnk[13][2])))+((((cnk[12][0][2]*ikcnkt[12][2][2])+((cnk[12][0][0]*
      ikcnkt[12][0][2])+(cnk[12][0][1]*ikcnkt[12][1][2])))-(mk[8]*(rnk[12][0]*
      rnk[12][2])))+((((cnk[11][0][2]*ikcnkt[11][2][2])+((cnk[11][0][0]*
      ikcnkt[11][0][2])+(cnk[11][0][1]*ikcnkt[11][1][2])))-(mk[7]*(rnk[11][0]*
      rnk[11][2])))+temp[1])));
    temp[3] = ((((cnk[16][0][2]*ikcnkt[16][2][2])+((cnk[16][0][0]*
      ikcnkt[16][0][2])+(cnk[16][0][1]*ikcnkt[16][1][2])))-(mk[13]*(rnk[16][0]*
      rnk[16][2])))+((((cnk[15][0][2]*ikcnkt[15][2][2])+((cnk[15][0][0]*
      ikcnkt[15][0][2])+(cnk[15][0][1]*ikcnkt[15][1][2])))-(mk[12]*(rnk[15][0]*
      rnk[15][2])))+((((cnk[14][0][2]*ikcnkt[14][2][2])+((cnk[14][0][0]*
      ikcnkt[14][0][2])+(cnk[14][0][1]*ikcnkt[14][1][2])))-(mk[11]*(rnk[14][0]*
      rnk[14][2])))+temp[2])));
    temp[4] = ((((cnk[19][0][2]*ikcnkt[19][2][2])+((cnk[19][0][0]*
      ikcnkt[19][0][2])+(cnk[19][0][1]*ikcnkt[19][1][2])))-(mk[17]*(rnk[19][0]*
      rnk[19][2])))+((((cnk[18][0][2]*ikcnkt[18][2][2])+((cnk[18][0][0]*
      ikcnkt[18][0][2])+(cnk[18][0][1]*ikcnkt[18][1][2])))-(mk[16]*(rnk[18][0]*
      rnk[18][2])))+((((cnk[17][0][2]*ikcnkt[17][2][2])+((cnk[17][0][0]*
      ikcnkt[17][0][2])+(cnk[17][0][1]*ikcnkt[17][1][2])))-(psmk[17]*(rnk[17][0]
      *rnk[17][2])))+temp[3])));
    icm[0][2] = ((mtot*(com[0]*com[2]))+((((cnk[21][0][2]*ikcnkt[21][2][2])+((
      cnk[21][0][0]*ikcnkt[21][0][2])+(cnk[21][0][1]*ikcnkt[21][1][2])))-(
      psmk[21]*(rnk[21][0]*rnk[21][2])))+((((cnk[20][0][2]*ikcnkt[20][2][2])+((
      cnk[20][0][0]*ikcnkt[20][0][2])+(cnk[20][0][1]*ikcnkt[20][1][2])))-(mk[18]
      *(rnk[20][0]*rnk[20][2])))+temp[4])));
    icm[1][0] = icm[0][1];
    temp[0] = (((mk[0]*((rnk[5][0]*rnk[5][0])+(rnk[5][2]*rnk[5][2])))+((
      Cik[3][1][2]*ikcnkt[5][2][1])+((Cik[3][1][0]*ikcnkt[5][0][1])+(
      Cik[3][1][1]*ikcnkt[5][1][1]))))+((mk[1]*((rnk[6][0]*rnk[6][0])+(rnk[6][2]
      *rnk[6][2])))+((cnk[6][1][2]*ikcnkt[6][2][1])+((cnk[6][1][0]*
      ikcnkt[6][0][1])+(cnk[6][1][1]*ikcnkt[6][1][1])))));
    temp[1] = (((mk[3]*((rnk[8][0]*rnk[8][0])+(rnk[8][2]*rnk[8][2])))+((
      cnk[8][1][2]*ikcnkt[8][2][1])+((cnk[8][1][0]*ikcnkt[8][0][1])+(
      cnk[8][1][1]*ikcnkt[8][1][1]))))+(((mk[2]*((rnk[7][0]*rnk[7][0])+(
      rnk[7][2]*rnk[7][2])))+((cnk[7][1][2]*ikcnkt[7][2][1])+((cnk[7][1][0]*
      ikcnkt[7][0][1])+(cnk[7][1][1]*ikcnkt[7][1][1]))))+temp[0]));
    temp[2] = (((mk[6]*((rnk[10][0]*rnk[10][0])+(rnk[10][2]*rnk[10][2])))+((
      cnk[10][1][2]*ikcnkt[10][2][1])+((cnk[10][1][0]*ikcnkt[10][0][1])+(
      cnk[10][1][1]*ikcnkt[10][1][1]))))+(((psmk[9]*((rnk[9][0]*rnk[9][0])+(
      rnk[9][2]*rnk[9][2])))+((cnk[9][1][2]*ikcnkt[9][2][1])+((cnk[9][1][0]*
      ikcnkt[9][0][1])+(cnk[9][1][1]*ikcnkt[9][1][1]))))+temp[1]));
    temp[3] = (((mk[8]*((rnk[12][0]*rnk[12][0])+(rnk[12][2]*rnk[12][2])))+((
      cnk[12][1][2]*ikcnkt[12][2][1])+((cnk[12][1][0]*ikcnkt[12][0][1])+(
      cnk[12][1][1]*ikcnkt[12][1][1]))))+(((mk[7]*((rnk[11][0]*rnk[11][0])+(
      rnk[11][2]*rnk[11][2])))+((cnk[11][1][2]*ikcnkt[11][2][1])+((cnk[11][1][0]
      *ikcnkt[11][0][1])+(cnk[11][1][1]*ikcnkt[11][1][1]))))+temp[2]));
    temp[4] = (((mk[11]*((rnk[14][0]*rnk[14][0])+(rnk[14][2]*rnk[14][2])))+((
      cnk[14][1][2]*ikcnkt[14][2][1])+((cnk[14][1][0]*ikcnkt[14][0][1])+(
      cnk[14][1][1]*ikcnkt[14][1][1]))))+(((psmk[13]*((rnk[13][0]*rnk[13][0])+(
      rnk[13][2]*rnk[13][2])))+((cnk[13][1][2]*ikcnkt[13][2][1])+((cnk[13][1][0]
      *ikcnkt[13][0][1])+(cnk[13][1][1]*ikcnkt[13][1][1]))))+temp[3]));
    temp[5] = (((mk[13]*((rnk[16][0]*rnk[16][0])+(rnk[16][2]*rnk[16][2])))+((
      cnk[16][1][2]*ikcnkt[16][2][1])+((cnk[16][1][0]*ikcnkt[16][0][1])+(
      cnk[16][1][1]*ikcnkt[16][1][1]))))+(((mk[12]*((rnk[15][0]*rnk[15][0])+(
      rnk[15][2]*rnk[15][2])))+((cnk[15][1][2]*ikcnkt[15][2][1])+((cnk[15][1][0]
      *ikcnkt[15][0][1])+(cnk[15][1][1]*ikcnkt[15][1][1]))))+temp[4]));
    temp[6] = (((mk[16]*((rnk[18][0]*rnk[18][0])+(rnk[18][2]*rnk[18][2])))+((
      cnk[18][1][2]*ikcnkt[18][2][1])+((cnk[18][1][0]*ikcnkt[18][0][1])+(
      cnk[18][1][1]*ikcnkt[18][1][1]))))+(((psmk[17]*((rnk[17][0]*rnk[17][0])+(
      rnk[17][2]*rnk[17][2])))+((cnk[17][1][2]*ikcnkt[17][2][1])+((cnk[17][1][0]
      *ikcnkt[17][0][1])+(cnk[17][1][1]*ikcnkt[17][1][1]))))+temp[5]));
    temp[7] = (((mk[18]*((rnk[20][0]*rnk[20][0])+(rnk[20][2]*rnk[20][2])))+((
      cnk[20][1][2]*ikcnkt[20][2][1])+((cnk[20][1][0]*ikcnkt[20][0][1])+(
      cnk[20][1][1]*ikcnkt[20][1][1]))))+(((mk[17]*((rnk[19][0]*rnk[19][0])+(
      rnk[19][2]*rnk[19][2])))+((cnk[19][1][2]*ikcnkt[19][2][1])+((cnk[19][1][0]
      *ikcnkt[19][0][1])+(cnk[19][1][1]*ikcnkt[19][1][1]))))+temp[6]));
    icm[1][1] = ((((psmk[21]*((rnk[21][0]*rnk[21][0])+(rnk[21][2]*rnk[21][2])))+
      ((cnk[21][1][2]*ikcnkt[21][2][1])+((cnk[21][1][0]*ikcnkt[21][0][1])+(
      cnk[21][1][1]*ikcnkt[21][1][1]))))+temp[7])-(mtot*((com[0]*com[0])+(com[2]
      *com[2]))));
    temp[0] = ((((cnk[7][1][2]*ikcnkt[7][2][2])+((cnk[7][1][0]*ikcnkt[7][0][2])+
      (cnk[7][1][1]*ikcnkt[7][1][2])))-(mk[2]*(rnk[7][1]*rnk[7][2])))+((((
      Cik[3][1][2]*ikcnkt[5][2][2])+((Cik[3][1][0]*ikcnkt[5][0][2])+(
      Cik[3][1][1]*ikcnkt[5][1][2])))-(mk[0]*(rnk[5][1]*rnk[5][2])))+(((
      cnk[6][1][2]*ikcnkt[6][2][2])+((cnk[6][1][0]*ikcnkt[6][0][2])+(
      cnk[6][1][1]*ikcnkt[6][1][2])))-(mk[1]*(rnk[6][1]*rnk[6][2])))));
    temp[1] = ((((cnk[10][1][2]*ikcnkt[10][2][2])+((cnk[10][1][0]*
      ikcnkt[10][0][2])+(cnk[10][1][1]*ikcnkt[10][1][2])))-(mk[6]*(rnk[10][1]*
      rnk[10][2])))+((((cnk[9][1][2]*ikcnkt[9][2][2])+((cnk[9][1][0]*
      ikcnkt[9][0][2])+(cnk[9][1][1]*ikcnkt[9][1][2])))-(psmk[9]*(rnk[9][1]*
      rnk[9][2])))+((((cnk[8][1][2]*ikcnkt[8][2][2])+((cnk[8][1][0]*
      ikcnkt[8][0][2])+(cnk[8][1][1]*ikcnkt[8][1][2])))-(mk[3]*(rnk[8][1]*
      rnk[8][2])))+temp[0])));
    temp[2] = ((((cnk[13][1][2]*ikcnkt[13][2][2])+((cnk[13][1][0]*
      ikcnkt[13][0][2])+(cnk[13][1][1]*ikcnkt[13][1][2])))-(psmk[13]*(rnk[13][1]
      *rnk[13][2])))+((((cnk[12][1][2]*ikcnkt[12][2][2])+((cnk[12][1][0]*
      ikcnkt[12][0][2])+(cnk[12][1][1]*ikcnkt[12][1][2])))-(mk[8]*(rnk[12][1]*
      rnk[12][2])))+((((cnk[11][1][2]*ikcnkt[11][2][2])+((cnk[11][1][0]*
      ikcnkt[11][0][2])+(cnk[11][1][1]*ikcnkt[11][1][2])))-(mk[7]*(rnk[11][1]*
      rnk[11][2])))+temp[1])));
    temp[3] = ((((cnk[16][1][2]*ikcnkt[16][2][2])+((cnk[16][1][0]*
      ikcnkt[16][0][2])+(cnk[16][1][1]*ikcnkt[16][1][2])))-(mk[13]*(rnk[16][1]*
      rnk[16][2])))+((((cnk[15][1][2]*ikcnkt[15][2][2])+((cnk[15][1][0]*
      ikcnkt[15][0][2])+(cnk[15][1][1]*ikcnkt[15][1][2])))-(mk[12]*(rnk[15][1]*
      rnk[15][2])))+((((cnk[14][1][2]*ikcnkt[14][2][2])+((cnk[14][1][0]*
      ikcnkt[14][0][2])+(cnk[14][1][1]*ikcnkt[14][1][2])))-(mk[11]*(rnk[14][1]*
      rnk[14][2])))+temp[2])));
    temp[4] = ((((cnk[19][1][2]*ikcnkt[19][2][2])+((cnk[19][1][0]*
      ikcnkt[19][0][2])+(cnk[19][1][1]*ikcnkt[19][1][2])))-(mk[17]*(rnk[19][1]*
      rnk[19][2])))+((((cnk[18][1][2]*ikcnkt[18][2][2])+((cnk[18][1][0]*
      ikcnkt[18][0][2])+(cnk[18][1][1]*ikcnkt[18][1][2])))-(mk[16]*(rnk[18][1]*
      rnk[18][2])))+((((cnk[17][1][2]*ikcnkt[17][2][2])+((cnk[17][1][0]*
      ikcnkt[17][0][2])+(cnk[17][1][1]*ikcnkt[17][1][2])))-(psmk[17]*(rnk[17][1]
      *rnk[17][2])))+temp[3])));
    icm[1][2] = ((mtot*(com[1]*com[2]))+((((cnk[21][1][2]*ikcnkt[21][2][2])+((
      cnk[21][1][0]*ikcnkt[21][0][2])+(cnk[21][1][1]*ikcnkt[21][1][2])))-(
      psmk[21]*(rnk[21][1]*rnk[21][2])))+((((cnk[20][1][2]*ikcnkt[20][2][2])+((
      cnk[20][1][0]*ikcnkt[20][0][2])+(cnk[20][1][1]*ikcnkt[20][1][2])))-(mk[18]
      *(rnk[20][1]*rnk[20][2])))+temp[4])));
    icm[2][0] = icm[0][2];
    icm[2][1] = icm[1][2];
    temp[0] = (((mk[0]*((rnk[5][0]*rnk[5][0])+(rnk[5][1]*rnk[5][1])))+((
      Cik[3][2][2]*ikcnkt[5][2][2])+((Cik[3][2][0]*ikcnkt[5][0][2])+(
      Cik[3][2][1]*ikcnkt[5][1][2]))))+((mk[1]*((rnk[6][0]*rnk[6][0])+(rnk[6][1]
      *rnk[6][1])))+((cnk[6][2][2]*ikcnkt[6][2][2])+((cnk[6][2][0]*
      ikcnkt[6][0][2])+(cnk[6][2][1]*ikcnkt[6][1][2])))));
    temp[1] = (((mk[3]*((rnk[8][0]*rnk[8][0])+(rnk[8][1]*rnk[8][1])))+((
      cnk[8][2][2]*ikcnkt[8][2][2])+((cnk[8][2][0]*ikcnkt[8][0][2])+(
      cnk[8][2][1]*ikcnkt[8][1][2]))))+(((mk[2]*((rnk[7][0]*rnk[7][0])+(
      rnk[7][1]*rnk[7][1])))+((cnk[7][2][2]*ikcnkt[7][2][2])+((cnk[7][2][0]*
      ikcnkt[7][0][2])+(cnk[7][2][1]*ikcnkt[7][1][2]))))+temp[0]));
    temp[2] = (((mk[6]*((rnk[10][0]*rnk[10][0])+(rnk[10][1]*rnk[10][1])))+((
      cnk[10][2][2]*ikcnkt[10][2][2])+((cnk[10][2][0]*ikcnkt[10][0][2])+(
      cnk[10][2][1]*ikcnkt[10][1][2]))))+(((psmk[9]*((rnk[9][0]*rnk[9][0])+(
      rnk[9][1]*rnk[9][1])))+((cnk[9][2][2]*ikcnkt[9][2][2])+((cnk[9][2][0]*
      ikcnkt[9][0][2])+(cnk[9][2][1]*ikcnkt[9][1][2]))))+temp[1]));
    temp[3] = (((mk[8]*((rnk[12][0]*rnk[12][0])+(rnk[12][1]*rnk[12][1])))+((
      cnk[12][2][2]*ikcnkt[12][2][2])+((cnk[12][2][0]*ikcnkt[12][0][2])+(
      cnk[12][2][1]*ikcnkt[12][1][2]))))+(((mk[7]*((rnk[11][0]*rnk[11][0])+(
      rnk[11][1]*rnk[11][1])))+((cnk[11][2][2]*ikcnkt[11][2][2])+((cnk[11][2][0]
      *ikcnkt[11][0][2])+(cnk[11][2][1]*ikcnkt[11][1][2]))))+temp[2]));
    temp[4] = (((mk[11]*((rnk[14][0]*rnk[14][0])+(rnk[14][1]*rnk[14][1])))+((
      cnk[14][2][2]*ikcnkt[14][2][2])+((cnk[14][2][0]*ikcnkt[14][0][2])+(
      cnk[14][2][1]*ikcnkt[14][1][2]))))+(((psmk[13]*((rnk[13][0]*rnk[13][0])+(
      rnk[13][1]*rnk[13][1])))+((cnk[13][2][2]*ikcnkt[13][2][2])+((cnk[13][2][0]
      *ikcnkt[13][0][2])+(cnk[13][2][1]*ikcnkt[13][1][2]))))+temp[3]));
    temp[5] = (((mk[13]*((rnk[16][0]*rnk[16][0])+(rnk[16][1]*rnk[16][1])))+((
      cnk[16][2][2]*ikcnkt[16][2][2])+((cnk[16][2][0]*ikcnkt[16][0][2])+(
      cnk[16][2][1]*ikcnkt[16][1][2]))))+(((mk[12]*((rnk[15][0]*rnk[15][0])+(
      rnk[15][1]*rnk[15][1])))+((cnk[15][2][2]*ikcnkt[15][2][2])+((cnk[15][2][0]
      *ikcnkt[15][0][2])+(cnk[15][2][1]*ikcnkt[15][1][2]))))+temp[4]));
    temp[6] = (((mk[16]*((rnk[18][0]*rnk[18][0])+(rnk[18][1]*rnk[18][1])))+((
      cnk[18][2][2]*ikcnkt[18][2][2])+((cnk[18][2][0]*ikcnkt[18][0][2])+(
      cnk[18][2][1]*ikcnkt[18][1][2]))))+(((psmk[17]*((rnk[17][0]*rnk[17][0])+(
      rnk[17][1]*rnk[17][1])))+((cnk[17][2][2]*ikcnkt[17][2][2])+((cnk[17][2][0]
      *ikcnkt[17][0][2])+(cnk[17][2][1]*ikcnkt[17][1][2]))))+temp[5]));
    temp[7] = (((mk[18]*((rnk[20][0]*rnk[20][0])+(rnk[20][1]*rnk[20][1])))+((
      cnk[20][2][2]*ikcnkt[20][2][2])+((cnk[20][2][0]*ikcnkt[20][0][2])+(
      cnk[20][2][1]*ikcnkt[20][1][2]))))+(((mk[17]*((rnk[19][0]*rnk[19][0])+(
      rnk[19][1]*rnk[19][1])))+((cnk[19][2][2]*ikcnkt[19][2][2])+((cnk[19][2][0]
      *ikcnkt[19][0][2])+(cnk[19][2][1]*ikcnkt[19][1][2]))))+temp[6]));
    icm[2][2] = ((((psmk[21]*((rnk[21][0]*rnk[21][0])+(rnk[21][1]*rnk[21][1])))+
      ((cnk[21][2][2]*ikcnkt[21][2][2])+((cnk[21][2][0]*ikcnkt[21][0][2])+(
      cnk[21][2][1]*ikcnkt[21][1][2]))))+temp[7])-(mtot*((com[0]*com[0])+(com[1]
      *com[1]))));
/*
 Used 0.00 seconds CPU time,
 0 additional bytes of memory.
 Equations contain  768 adds/subtracts/negates
                   1035 multiplies
                      0 divides
                    205 assignments
*/
}

void allegro_air_pos(int body,
    double pt[3],
    double loc[3])
{
/*
Return inertial frame location of a point on a body.

*/
    double pv[3];

    if (allegro_air_chkbnum(21,body) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(21,23);
        return;
    }
    if (body  ==  -1) {
        loc[0] = pt[0];
        loc[1] = pt[1];
        loc[2] = pt[2];
    } else {
        pv[0] = rnb[body][0]+pt[0]*cnb[body][0][0]+pt[1]*cnb[body][0][1]+pt[2]*
          cnb[body][0][2];
        pv[1] = rnb[body][1]+pt[0]*cnb[body][1][0]+pt[1]*cnb[body][1][1]+pt[2]*
          cnb[body][1][2];
        pv[2] = rnb[body][2]+pt[0]*cnb[body][2][0]+pt[1]*cnb[body][2][1]+pt[2]*
          cnb[body][2][2];
        loc[0] = pv[0];
        loc[1] = pv[1];
        loc[2] = pv[2];
    }
}

void allegro_air_vel(int body,
    double pt[3],
    double velo[3])
{
/*
Return inertial frame velocity of a point on a body.

*/
    double pv[3];

    if (allegro_air_chkbnum(22,body) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(22,23);
        return;
    }
    if (body  ==  -1) {
        velo[0] = 0.;
        velo[1] = 0.;
        velo[2] = 0.;
    } else {
        pv[0] = wb[body][1]*pt[2]-wb[body][2]*pt[1];
        pv[1] = wb[body][2]*pt[0]-wb[body][0]*pt[2];
        pv[2] = wb[body][0]*pt[1]-wb[body][1]*pt[0];
        velo[0] = vnb[body][0]+pv[0]*cnb[body][0][0]+pv[1]*cnb[body][0][1]+pv[2]
          *cnb[body][0][2];
        velo[1] = vnb[body][1]+pv[0]*cnb[body][1][0]+pv[1]*cnb[body][1][1]+pv[2]
          *cnb[body][1][2];
        velo[2] = vnb[body][2]+pv[0]*cnb[body][2][0]+pv[1]*cnb[body][2][1]+pv[2]
          *cnb[body][2][2];
    }
}

void allegro_air_orient(int body,
    double dircos[3][3])
{
/*
Return orientation of body w.r.t. ground frame.

*/

    if (allegro_air_chkbnum(23,body) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(23,23);
        return;
    }
    if (body == -1) {
        dircos[0][0] = 1.;
        dircos[0][1] = 0.;
        dircos[0][2] = 0.;
        dircos[1][0] = 0.;
        dircos[1][1] = 1.;
        dircos[1][2] = 0.;
        dircos[2][0] = 0.;
        dircos[2][1] = 0.;
        dircos[2][2] = 1.;
    } else {
        dircos[0][0] = cnb[body][0][0];
        dircos[0][1] = cnb[body][0][1];
        dircos[0][2] = cnb[body][0][2];
        dircos[1][0] = cnb[body][1][0];
        dircos[1][1] = cnb[body][1][1];
        dircos[1][2] = cnb[body][1][2];
        dircos[2][0] = cnb[body][2][0];
        dircos[2][1] = cnb[body][2][1];
        dircos[2][2] = cnb[body][2][2];
    }
}

void allegro_air_angvel(int body,
    double avel[3])
{
/*
Return angular velocity of the body.

*/

    if (allegro_air_chkbnum(24,body) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(24,23);
        return;
    }
    if (body == -1) {
        avel[0] = 0.;
        avel[1] = 0.;
        avel[2] = 0.;
    } else {
        avel[0] = wb[body][0];
        avel[1] = wb[body][1];
        avel[2] = wb[body][2];
    }
}

void allegro_air_trans(int frbod,
    double ivec[3],
    int tobod,
    double ovec[3])
{
/*
Transform ivec from frbod frame to tobod frame.

*/
    double pv[3];

    if (allegro_air_chkbnum(25,frbod) != 0) {
        return;
    }
    if (allegro_air_chkbnum(25,tobod) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(25,23);
        return;
    }
    if (frbod == tobod) {
        allegro_air_vcopy(ivec,ovec);
        return;
    }
    if (frbod == -1) {
        allegro_air_vcopy(ivec,pv);
        ovec[0] = pv[0]*cnb[tobod][0][0]+pv[1]*cnb[tobod][1][0]+pv[2]*cnb[tobod
          ][2][0];
        ovec[1] = pv[0]*cnb[tobod][0][1]+pv[1]*cnb[tobod][1][1]+pv[2]*cnb[tobod
          ][2][1];
        ovec[2] = pv[0]*cnb[tobod][0][2]+pv[1]*cnb[tobod][1][2]+pv[2]*cnb[tobod
          ][2][2];
        return;
    }
    if (tobod == -1) {
        allegro_air_vcopy(ivec,pv);
        ovec[0] = pv[0]*cnb[frbod][0][0]+pv[1]*cnb[frbod][0][1]+pv[2]*cnb[frbod
          ][0][2];
        ovec[1] = pv[0]*cnb[frbod][1][0]+pv[1]*cnb[frbod][1][1]+pv[2]*cnb[frbod
          ][1][2];
        ovec[2] = pv[0]*cnb[frbod][2][0]+pv[1]*cnb[frbod][2][1]+pv[2]*cnb[frbod
          ][2][2];
        return;
    }
    pv[0] = ivec[0]*cnb[frbod][0][0]+ivec[1]*cnb[frbod][0][1]+ivec[2]*cnb[frbod
      ][0][2];
    pv[1] = ivec[0]*cnb[frbod][1][0]+ivec[1]*cnb[frbod][1][1]+ivec[2]*cnb[frbod
      ][1][2];
    pv[2] = ivec[0]*cnb[frbod][2][0]+ivec[1]*cnb[frbod][2][1]+ivec[2]*cnb[frbod
      ][2][2];
    ovec[0] = pv[0]*cnb[tobod][0][0]+pv[1]*cnb[tobod][1][0]+pv[2]*cnb[tobod][2][
      0];
    ovec[1] = pv[0]*cnb[tobod][0][1]+pv[1]*cnb[tobod][1][1]+pv[2]*cnb[tobod][2][
      1];
    ovec[2] = pv[0]*cnb[tobod][0][2]+pv[1]*cnb[tobod][1][2]+pv[2]*cnb[tobod][2][
      2];
}

void allegro_air_rel2cart(int coord,
    int body,
    double point[3],
    double linchg[3],
    double rotchg[3])
{
/* Return derivative of pt loc and body orient w.r.t. hinge rate
*/
    int x,i,gnd;
    double lin[3],pv[3];

    if ((coord < 0) || (coord > 21)) {
        allegro_air_seterr(59,45);
        return;
    }
    if (allegro_air_chkbnum(59,body) != 0) {
        return;
    }
    if ((roustate != 2) && (roustate != 3)) {
        allegro_air_seterr(59,23);
        return;
    }
    gnd = -1;
    if (body == gnd) {
        x = -1;
    } else {
        x = firstq[body]+njntdof[body]-1;
    }
    if (x < coord) {
        allegro_air_vset(0.,0.,0.,linchg);
        allegro_air_vset(0.,0.,0.,rotchg);
        return;
    }
    allegro_air_dovpk();
    for (i = 0; i < 3; i++) {
        rotchg[i] = Wpk[coord][x][i];
        lin[i] = Vpk[coord][x][i];
    }
    if (body == gnd) {
        allegro_air_vcopy(point,pv);
    } else {
        pv[0] = rcom[body][0]+point[0];
        pv[1] = rcom[body][1]+point[1];
        pv[2] = rcom[body][2]+point[2];
    }
    allegro_air_vcross(rotchg,pv,linchg);
    allegro_air_vadd(linchg,lin,linchg);
}

void allegro_air_acc(int body,
    double pt[3],
    double accel[3])
{
/*
Return linear acceleration a point of the specified body.

*/
    double pv[3];

    if (allegro_air_chkbnum(32,body) != 0) {
        return;
    }
    if (roustate != 3) {
        allegro_air_seterr(32,24);
        return;
    }
    if (body  ==  -1) {
        accel[0] = 0.;
        accel[1] = 0.;
        accel[2] = 0.;
    } else {
        pv[0] = pt[0]*dyad[body][0][0]+pt[1]*dyad[body][0][1]+pt[2]*dyad[body][0
          ][2];
        pv[1] = pt[0]*dyad[body][1][0]+pt[1]*dyad[body][1][1]+pt[2]*dyad[body][1
          ][2];
        pv[2] = pt[0]*dyad[body][2][0]+pt[1]*dyad[body][2][1]+pt[2]*dyad[body][2
          ][2];
        accel[0] = anb[body][0]+pv[0]*cnb[body][0][0]+pv[1]*cnb[body][0][1]+pv[2
          ]*cnb[body][0][2];
        accel[1] = anb[body][1]+pv[0]*cnb[body][1][0]+pv[1]*cnb[body][1][1]+pv[2
          ]*cnb[body][1][2];
        accel[2] = anb[body][2]+pv[0]*cnb[body][2][0]+pv[1]*cnb[body][2][1]+pv[2
          ]*cnb[body][2][2];
    }
}

void allegro_air_angacc(int body,
    double aacc[3])
{
/*
Return angular acceleration of the body.

*/

    if (allegro_air_chkbnum(33,body) != 0) {
        return;
    }
    if (roustate != 3) {
        allegro_air_seterr(33,24);
        return;
    }
    if (body == -1) {
        aacc[0] = 0.;
        aacc[1] = 0.;
        aacc[2] = 0.;
    } else {
        aacc[0] = onb[body][0];
        aacc[1] = onb[body][1];
        aacc[2] = onb[body][2];
    }
}

void allegro_air_grav(double gravin[3])
{

    grav[0] = gravin[0];
    gravq[0] = 3;
    grav[1] = gravin[1];
    gravq[1] = 3;
    grav[2] = gravin[2];
    gravq[2] = 3;
    roustate = 0;
}

void allegro_air_mass(int body,
    double massin)
{

    if (allegro_air_chkbnum(2,body) != 0) {
        return;
    }
    if (body == -1) {
        allegro_air_seterr(2,15);
        return;
    }
    if (mkq[body] != 0) {
        mk[body] = massin;
        mkq[body] = 3;
    } else {
        allegro_air_seterr(2,19);
    }
    roustate = 0;
}

void allegro_air_iner(int body,
    double inerin[3][3])
{
    int anyques;

    if (allegro_air_chkbnum(3,body) != 0) {
        return;
    }
    if (body == -1) {
        allegro_air_seterr(3,15);
        return;
    }
    anyques = 0;
    if (ikq[body][0][0]  !=  0) {
        ik[body][0][0] = inerin[0][0];
        ikq[body][0][0] = 3;
        anyques = 1;
    }
    if (ikq[body][0][1]  !=  0) {
        ik[body][0][1] = inerin[0][1];
        ikq[body][0][1] = 3;
        ik[body][1][0] = inerin[0][1];
        ikq[body][1][0] = 3;
        anyques = 1;
    }
    if (ikq[body][0][2]  !=  0) {
        ik[body][0][2] = inerin[0][2];
        ikq[body][0][2] = 3;
        ik[body][2][0] = inerin[0][2];
        ikq[body][2][0] = 3;
        anyques = 1;
    }
    if (ikq[body][1][1]  !=  0) {
        ik[body][1][1] = inerin[1][1];
        ikq[body][1][1] = 3;
        anyques = 1;
    }
    if (ikq[body][1][2]  !=  0) {
        ik[body][1][2] = inerin[1][2];
        ikq[body][1][2] = 3;
        ik[body][2][1] = inerin[1][2];
        ikq[body][2][1] = 3;
        anyques = 1;
    }
    if (ikq[body][2][2]  !=  0) {
        ik[body][2][2] = inerin[2][2];
        ikq[body][2][2] = 3;
        anyques = 1;
    }
    if (anyques == 0) {
        allegro_air_seterr(3,19);
    }
    roustate = 0;
}

void allegro_air_btj(int joint,
    double btjin[3])
{
    int anyques;

    if (allegro_air_chkjnum(4,joint) != 0) {
        return;
    }
    anyques = 0;
    if (rkq[joint][0]  !=  0) {
        rk[joint][0] = btjin[0];
        rkq[joint][0] = 3;
        anyques = 1;
    }
    if (rkq[joint][1]  !=  0) {
        rk[joint][1] = btjin[1];
        rkq[joint][1] = 3;
        anyques = 1;
    }
    if (rkq[joint][2]  !=  0) {
        rk[joint][2] = btjin[2];
        rkq[joint][2] = 3;
        anyques = 1;
    }
    if (anyques == 0) {
        allegro_air_seterr(4,19);
    }
    roustate = 0;
}

void allegro_air_itj(int joint,
    double itjin[3])
{
    int anyques;

    if (allegro_air_chkjnum(5,joint) != 0) {
        return;
    }
    anyques = 0;
    if (riq[joint][0]  !=  0) {
        ri[joint][0] = itjin[0];
        riq[joint][0] = 3;
        anyques = 1;
    }
    if (riq[joint][1]  !=  0) {
        ri[joint][1] = itjin[1];
        riq[joint][1] = 3;
        anyques = 1;
    }
    if (riq[joint][2]  !=  0) {
        ri[joint][2] = itjin[2];
        riq[joint][2] = 3;
        anyques = 1;
    }
    if (anyques == 0) {
        allegro_air_seterr(5,19);
    }
    roustate = 0;
}

void allegro_air_pin(int joint,
    int pinno,
    double pinin[3])
{
    int anyques,offs;

    if (allegro_air_chkjpin(6,joint,pinno) != 0) {
        return;
    }
    anyques = 0;
    offs = firstq[joint]+pinno;
    if (jtype[joint] == 21) {
        offs = offs+3;
    }
    if (jtype[joint] == 11) {
        offs = offs+1;
    }
    if (pinq[offs][0]  !=  0) {
        pin[offs][0] = pinin[0];
        pinq[offs][0] = 3;
        anyques = 1;
    }
    if (pinq[offs][1]  !=  0) {
        pin[offs][1] = pinin[1];
        pinq[offs][1] = 3;
        anyques = 1;
    }
    if (pinq[offs][2]  !=  0) {
        pin[offs][2] = pinin[2];
        pinq[offs][2] = 3;
        anyques = 1;
    }
    if (anyques == 0) {
        allegro_air_seterr(6,19);
    }
    roustate = 0;
}

void allegro_air_pres(int joint,
    int axis,
    int presin)
{
    int anyques;

    if (allegro_air_chkjaxis(37,joint,axis) != 0) {
        return;
    }
    if ((presin != 0) && (presin != 1)) {
        allegro_air_seterr(37,20);
    }
    anyques = 0;
    if (presq[allegro_air_indx(joint,axis)]  !=  0) {
        if (presin  !=  0) {
            pres[allegro_air_indx(joint,axis)] = 1.;
        } else {
            pres[allegro_air_indx(joint,axis)] = 0.;
        }
        presq[allegro_air_indx(joint,axis)] = 3;
        anyques = 1;
    }
    if (anyques == 0) {
        allegro_air_seterr(37,19);
    }
    wwflg = 0;
}

void allegro_air_conschg(void)
{

    wwflg = 0;
}

void allegro_air_stab(double velin,
    double posin)
{

    stabvel = velin;
    stabvelq = 3;
    stabpos = posin;
    stabposq = 3;
}

void allegro_air_getgrav(double gravout[3])
{

    gravout[0] = grav[0];
    gravout[1] = grav[1];
    gravout[2] = grav[2];
}

void allegro_air_getmass(int body,
    double *massout)
{

    if (allegro_air_chkbnum(40,body) != 0) {
        return;
    }
    if (body == -1) {
        allegro_air_seterr(40,15);
        return;
    }
    *massout = mk[body];
}

void allegro_air_getiner(int body,
    double inerout[3][3])
{

    if (allegro_air_chkbnum(41,body) != 0) {
        return;
    }
    if (body == -1) {
        allegro_air_seterr(41,15);
        return;
    }
    inerout[0][0] = ik[body][0][0];
    inerout[0][1] = ik[body][0][1];
    inerout[0][2] = ik[body][0][2];
    inerout[1][0] = ik[body][1][0];
    inerout[1][1] = ik[body][1][1];
    inerout[1][2] = ik[body][1][2];
    inerout[2][0] = ik[body][2][0];
    inerout[2][1] = ik[body][2][1];
    inerout[2][2] = ik[body][2][2];
}

void allegro_air_getbtj(int joint,
    double btjout[3])
{

    if (allegro_air_chkjnum(42,joint) != 0) {
        return;
    }
    btjout[0] = rk[joint][0];
    btjout[1] = rk[joint][1];
    btjout[2] = rk[joint][2];
}

void allegro_air_getitj(int joint,
    double itjout[3])
{

    if (allegro_air_chkjnum(43,joint) != 0) {
        return;
    }
    itjout[0] = ri[joint][0];
    itjout[1] = ri[joint][1];
    itjout[2] = ri[joint][2];
}

void allegro_air_getpin(int joint,
    int pinno,
    double pinout[3])
{
    int offs;

    if (allegro_air_chkjpin(44,joint,pinno) != 0) {
        return;
    }
    offs = firstq[joint]+pinno;
    if (jtype[joint] == 21) {
        offs = offs+3;
    }
    if (jtype[joint] == 11) {
        offs = offs+1;
    }
    pinout[0] = pin[offs][0];
    pinout[1] = pin[offs][1];
    pinout[2] = pin[offs][2];
}

void allegro_air_getpres(int joint,
    int axis,
    int *presout)
{

    if (allegro_air_chkjaxis(45,joint,axis) != 0) {
        return;
    }
    if (pres[allegro_air_indx(joint,axis)]  !=  0.) {
        *presout = 1;
    } else {
        *presout = 0;
    }
}

void allegro_air_getstab(double *velout,
    double *posout)
{

    *velout = stabvel;
    *posout = stabpos;
}

void allegro_air_info(int info[50])
{

    info[0] = ground;
    info[1] = nbod;
    info[2] = ndof;
    info[3] = ncons;
    info[4] = nloop;
    info[5] = nldof;
    info[6] = nloopc;
    info[7] = nball;
    info[8] = nlball;
    info[9] = npres;
    info[10] = nuser;
    info[11] = 22;
/* info entries from 12-49 are reserved */
}

void allegro_air_jnt(int joint,
    int info[50],
    int tran[6])
{
    int i,offs;

    if (allegro_air_chkjnum(48,joint) != 0) {
        return;
    }
    info[0] = jtype[joint];
    info[1] = 0;
    offs = 0;
    info[2] = inb[joint];
    info[3] = outb[joint];
    info[4] = njntdof[joint];
    info[5] = njntc[joint];
    info[6] = njntp[joint];
    info[7] = firstq[joint];
    info[8] = ballq[joint];
    info[9] = firstm[joint];
    info[10] = firstp[joint];
/* info entries from 11-49 are reserved */

    for (i = 0; i <= 5; i++) {
        if (i  <  njntdof[joint]) {
            tran[i] = trans[offs+firstq[joint]+i];
        } else {
            tran[i] = -1;
        }
    }
}

void allegro_air_cons(int consno,
    int info[50])
{

    if (allegro_air_chkucnum(49,consno) != 0) {
        return;
    }
/* There are no user constraints in this problem. */
}

void allegro_air_gentime(int *gentm)
{

    *gentm = 142810;
}
/*
Done. CPU seconds used: 0.09  Memory used: 1687552 bytes.
Equation complexity:
  sdstate:  2240 adds  2998 multiplies     4 divides  1740 assignments
  sdderiv: 34648 adds 37002 multiplies   591 divides 37404 assignments
  sdresid:  4749 adds  5155 multiplies     0 divides  2082 assignments
  sdreac:   1128 adds   900 multiplies     0 divides   471 assignments
  sdmom:     629 adds   700 multiplies     0 divides   170 assignments
  sdsys:     768 adds  1035 multiplies     0 divides   205 assignments
*/
