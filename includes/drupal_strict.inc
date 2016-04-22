<?php

/**
 * Does nothing; used for exceptions to see if they are DrupalStrict exceptions.
 */
interface DrupalStrict {}

/**
 * @file 
 * Provides functions and classes for drupal_strict conformance checking.
 */

class DrupalStrictException extends Exception implements DrupalStrict {
  
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
class DrupalStrictHookException extends Exception implements DrupalStrict {
  
  protected $hook;
  protected $module;
  
  public function __construct($message, $module, $hook, $code = 0, Exception $previous = null) {
    $this->module = $module;
    $this->hook = $hook;
    parent::__construct($message, $code, $previous);
    $this->message = "Module '$module' hook '$hook': " . $this->message;
  }
  
  final public function getModule() {
    return $this->module;
  }
  
  final public function getHook() {
    return $this->hook;
  }
 
  // override the __toString method to include the module and hook names 
  public function __toString() {
    return $this->message;
  }
}
