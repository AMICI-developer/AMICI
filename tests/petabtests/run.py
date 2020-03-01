import os
import sys
import logging

import amici
from amici.petab_import import import_petab_problem
from amici.petab_objective import simulate_petab, rdatas_to_measurement_df
import petab
import petabtests

logger = logging.getLogger(__name__)
logger.setLevel(logging.INFO)
stream_handler = logging.StreamHandler() 
logger.addHandler(stream_handler) 

def run():
    for case in petabtests.CASES_LIST:
        logger.info(f"Case {case}")

        # load
        case_dir = os.path.join(petabtests.CASES_DIR, case)

        # import petab problem
        yaml_file = os.path.join(case_dir, f'_{case}.yaml')
        problem = petab.Problem.from_yaml(yaml_file)

        # compile amici model
        model_output_dir = f'amici_models/model_{case}'
        model = import_petab_problem(
            problem, model_output_dir=model_output_dir)

        # simulate
        ret = simulate_petab(problem, model)

        rdatas = ret['rdatas']
        chi2 = None
        llh = ret['llh']
        simulation_df = rdatas_to_measurement_df(rdatas, model, problem.measurement_df)
        simulation_df = simulation_df.rename(columns={petab.MEASUREMENT: petab.SIMULATION})
        simulation_df[petab.TIME] = simulation_df[petab.TIME].astype(int)

        solution = petabtests.load_solution(case)
        gt_chi2 = solution[petabtests.CHI2]
        gt_llh = solution[petabtests.LLH]
        gt_simulation_dfs = solution[petabtests.SIMULATION_DFS]
        tol_chi2 = solution[petabtests.TOL_CHI2]
        tol_llh = solution[petabtests.TOL_LLH]
        tol_simulations = solution[petabtests.TOL_SIMULATIONS]
        
        chi2s_match = petabtests.evaluate_chi2(chi2, solution, tol_chi2)
        llhs_match = petabtests.evaluate_llh(llh, gt_llh, tol_llh)
        simulations_match = petabtests.evaluate_simulations(
            [simulation_df], gt_simulation_dfs, tol_simulations)

        logger.info(f"CHI2: simulated {chi2}, expected {gt_chi2}, match = {chi2s_match}")
        logger.info(f"LLH: simulated {llh}, expected {gt_llh}, match = {llhs_match}")
        logger.info(f"Simulations: match = {simulations_match}")

if __name__ == '__main__':
    run()
