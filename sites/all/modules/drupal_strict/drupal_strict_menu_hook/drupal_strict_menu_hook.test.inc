<?

class DrupalStrictMenuHookUnitTestCase extends DrupalUnitTestCase {
  
  public static function getInfo() {
    return array(
      'name' => 'Drupal Strict Hook Menu unit tests',
      'description' => 'Tests that the Drupal Strict patch does appropriate error checking for hook_menu',
      'group' => 'Drupal Strict',
    );
  }
  
  function testDrupalStrictHookMenu() {
    // if the module drupal_strict_menu_hook is enabled, 
    // its hook won't return an array which should cause an exception

    parent::setUp(array('drupal_strict_hook_menu'));
    
  }
}
