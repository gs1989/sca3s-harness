/* Copyright (C) 2018 SCARV project <info@scarv.org>
 *
 * Use of this source code is restricted per the MIT license, a copy of which 
 * can be found at https://opensource.org/licenses/MIT (or should be included 
 * as LICENSE.txt within the associated archive or repository).
 */

#include "board_imp.h"

// ============================================================================

bool board_init() {
  return  true;
}

// ----------------------------------------------------------------------------

void board_trigger_wr( bool x ) {

}

bool board_trigger_rd() {
  return false;
}

// ----------------------------------------------------------------------------

void    board_uart_wr( uint8_t x ) {
  if     ( x == '\x0A' ) {
    putc( '\x0D', stdout );
    putc( '\x0A', stdout );
  }
  else if( x == '\x0D' ) {
    putc( '\x0D', stdout );
    putc( '\x0A', stdout );
  }
  else {
    putc( x,      stdout );
  }
}

uint8_t board_uart_rd() {
  int t = getc( stdin );

  if     ( t == '\x0A' ) {
    return '\x0D';
  }
  else if( t == '\x0D' ) {
    return '\x0D';
  }
  else {
    return t;
  }
}

// ----------------------------------------------------------------------------

void          board_cycle_wr( board_cycle_t x ) {

}

board_cycle_t board_cycle_rd() {
  return 0;
}

board_cycle_t board_cycle_diff( board_cycle_t x, board_cycle_t y ) {
  return 0;
}

// ============================================================================
