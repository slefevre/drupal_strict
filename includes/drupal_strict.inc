<?php

/**
 * @file 
 * Provides functions and classes for drupal_strict conformance checking.
 */

class DrupalStrictException extends Exception {
  
  /**
   * Presently does nothing besides call the parent constructor.
   */
  public function __construct($message, $code = 0, Exception $previous = null) {
    parent::__construct($message, $code, $previous);
  }
}

/** 
 * Has extra parameters to record the module and hook whence the problem originates.
 */
class DrupalStrictHookException extends Exception {
  
  protected $hook;
  protected $module;
  
  public function __construct($message, $module, $hook, $code = 0, Exception $previous = null) {
    $this->module = $module;
    $this->hook = $hook;
    parent::__construct($message, $code, $previous);
  }
  
  final public function getModule() {
    return $this->module;
  }
  
  final public function getHook() {
    return $this->hook;
  }
  
  // I'd like to override __toString, 
  // but I'm not sure what all the original does ATM.
  // At least want to add the module and hook
}
