<?php
defined('BASEPATH') OR exit('No direct script access allowed');
class Calculate extends CI_Controller {
        function __construct() {
                parent::__construct();
                $this->load->model('calculate_model');
        }
        
        function index() {
                $this->load->view('calculate_view');
        }
        function count() {
                $num1 = $this->input->post('num1');
                $op = $this->input->post('operate');
                $num2 = $this->input->post('num2');
                
                if (is_numeric($num1) && is_numeric($num2)) {
                        $result = $this->calculate_model->count($num1, $num2, $op);
                        $data = array('num1' => $num1, 'num2' => $num2, 'op' => $op, 'result' => $result);
                        $this->load->view('result_view', $data);
                }
        }
}
