<?php
// ** Default wordpress configs ** //
define ( 'DB_NAME',	'wordpress');
define ( 'DB_USER',	'user42');
define ( 'DB_PASSWORD',	'user42');
define ( 'DB_HOST',	'localhost');
define ( 'DB_CHARSET',	'utf8');
define ( 'DB_COLLATE',	'');

// ** Security keys (basic values) ** //
define( 'AUTH_KEY',         'here is a key' );
define( 'SECURE_AUTH_KEY',  'here is a key' );
define( 'LOGGED_IN_KEY',    'here is a key' );
define( 'NONCE_KEY',        'here is a key' );
define( 'AUTH_SALT',        'here is a key' );
define( 'SECURE_AUTH_SALT', 'here is a key' );
define( 'LOGGED_IN_SALT',   'here is a key' );
define( 'NONCE_SALT',       'here is a key' );

// ** Table prefix ** //
$table_prefix = 'wp_';

// ** Debug mode ** //
define( 'WP_DEBUG', 'false');

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );

